
#include "driver.h"
#include "cpu/s2650/s2650.h"
#include "machine/atari_vg.h"
#include "centiped.h"
#include "sound/ay8910.h"
#include "sound/sn76496.h"
#include "sound/pokey.h"

/*************************************
 *
 *  Port definitions
 *
 *************************************/

/* The input ports are identical for the real one and the bootleg one, except
   that one of the languages is Italian in the bootleg one instead of Spanish */

#define PORTS(GAMENAME, FOURTH_LANGUAGE)										\
																				\
INPUT_PORTS_START( GAMENAME )													\
	PORT_START	/* IN0 */														\
	PORT_BIT( 0x0f, IP_ACTIVE_HIGH, IPT_SPECIAL )	/* trackball data */		\
	PORT_DIPNAME( 0x10, 0x00, DEF_STR( Cabinet ))								\
	PORT_DIPSETTING(    0x00, DEF_STR( Upright ))								\
	PORT_DIPSETTING(    0x10, DEF_STR( Cocktail ))								\
	PORT_SERVICE( 0x20, IP_ACTIVE_LOW )											\
	PORT_BIT( 0x40, IP_ACTIVE_HIGH, IPT_VBLANK )								\
	PORT_BIT( 0x80, IP_ACTIVE_HIGH, IPT_SPECIAL )	/* trackball sign bit */	\
																				\
	PORT_START	/* IN1 */														\
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_START1 )									\
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_START2 )									\
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_BUTTON1 )								\
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_COCKTAIL					\
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_TILT )									\
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_COIN1 )									\
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_COIN2 )									\
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_SERVICE1 )								\
																				\
	PORT_START	/* IN2 */														\
	PORT_BIT( 0x0f, IP_ACTIVE_HIGH, IPT_SPECIAL )	/* trackball data */		\
	PORT_BIT( 0x70, IP_ACTIVE_HIGH, IPT_UNKNOWN )								\
	PORT_BIT( 0x80, IP_ACTIVE_HIGH, IPT_SPECIAL )	/* trackball sign bit */	\
																				\
	PORT_START	/* IN3 */														\
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN ) PORT_8WAY PORT_COCKTAIL\
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_JOYSTICK_UP ) PORT_8WAY PORT_COCKTAIL	\
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT ) PORT_8WAY PORT_COCKTAIL\
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT ) PORT_8WAY PORT_COCKTAIL\
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_JOYSTICK_UP ) PORT_8WAY					\
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN ) PORT_8WAY				\
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT ) PORT_8WAY				\
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT ) PORT_8WAY				\
																				\
	PORT_START	/* IN4 */														\
	PORT_DIPNAME( 0x03, 0x00, DEF_STR( Language ) )										\
	PORT_DIPSETTING(    0x00, DEF_STR( English ) )										\
	PORT_DIPSETTING(    0x01, DEF_STR( German ) )										\
	PORT_DIPSETTING(    0x02, DEF_STR( French ) )										\
	PORT_DIPSETTING(    0x03, FOURTH_LANGUAGE )									\
	PORT_DIPNAME( 0x0c, 0x04, DEF_STR( Lives ))									\
	PORT_DIPSETTING(    0x00, "2" )												\
	PORT_DIPSETTING(    0x04, "3" )												\
	PORT_DIPSETTING(    0x08, "4" )												\
	PORT_DIPSETTING(    0x0c, "5" )												\
	PORT_DIPNAME( 0x30, 0x10, DEF_STR( Bonus_Life ))							\
	PORT_DIPSETTING(    0x00, "10000" )											\
	PORT_DIPSETTING(    0x10, "12000" )											\
	PORT_DIPSETTING(    0x20, "15000" )											\
	PORT_DIPSETTING(    0x30, "20000" )											\
	PORT_DIPNAME( 0x40, 0x40, DEF_STR( Difficulty ))							\
	PORT_DIPSETTING(    0x40, DEF_STR( Easy ) )											\
	PORT_DIPSETTING(    0x00, DEF_STR( Hard ) )											\
	PORT_DIPNAME( 0x80, 0x00, "Credit Minimum" )								\
	PORT_DIPSETTING(    0x00, "1" )												\
	PORT_DIPSETTING(    0x80, "2" )												\
																				\
	PORT_START	/* IN5 */														\
	PORT_DIPNAME( 0x03, 0x02, DEF_STR( Coinage ))								\
	PORT_DIPSETTING(    0x03, DEF_STR( 2C_1C ))									\
	PORT_DIPSETTING(    0x02, DEF_STR( 1C_1C ))									\
	PORT_DIPSETTING(    0x01, DEF_STR( 1C_2C ))									\
	PORT_DIPSETTING(    0x00, DEF_STR( Free_Play ))								\
	PORT_DIPNAME( 0x0c, 0x00, "Right Coin" )									\
	PORT_DIPSETTING(    0x00, "*1" )											\
	PORT_DIPSETTING(    0x04, "*4" )											\
	PORT_DIPSETTING(    0x08, "*5" )											\
	PORT_DIPSETTING(    0x0c, "*6" )											\
	PORT_DIPNAME( 0x10, 0x00, "Left Coin" )										\
	PORT_DIPSETTING(    0x00, "*1" )											\
	PORT_DIPSETTING(    0x10, "*2" )											\
	PORT_DIPNAME( 0xe0, 0x00, "Bonus Coins" )									\
	PORT_DIPSETTING(    0x00, DEF_STR( None ) )											\
	PORT_DIPSETTING(    0x20, "3 credits/2 coins" )								\
	PORT_DIPSETTING(    0x40, "5 credits/4 coins" )								\
	PORT_DIPSETTING(    0x60, "6 credits/4 coins" )								\
	PORT_DIPSETTING(    0x80, "6 credits/5 coins" )								\
	PORT_DIPSETTING(    0xa0, "4 credits/3 coins" )								\
																				\
	PORT_START	/* IN6, fake trackball input port. */							\
	PORT_BIT( 0xff, 0x00, IPT_TRACKBALL_X ) PORT_SENSITIVITY(50) PORT_KEYDELTA(10) PORT_REVERSE	\
																				\
	PORT_START	/* IN7, fake trackball input port. */							\
	PORT_BIT( 0xff, 0x00, IPT_TRACKBALL_Y ) PORT_SENSITIVITY(50) PORT_KEYDELTA(10) \
																				\
	PORT_START	/* IN8, fake trackball input port. */							\
	PORT_BIT( 0xff, 0x00, IPT_TRACKBALL_X ) PORT_SENSITIVITY(50) PORT_KEYDELTA(10) PORT_COCKTAIL	\
																				\
	PORT_START	/* IN9, fake trackball input port. */							\
	PORT_BIT( 0xff, 0x00, IPT_TRACKBALL_Y ) PORT_SENSITIVITY(50) PORT_KEYDELTA(10) PORT_REVERSE PORT_COCKTAIL	\
INPUT_PORTS_END

PORTS(centiped, DEF_STR( Spanish ))
PORTS(caterplr, DEF_STR( Italian ))


INPUT_PORTS_START( centtime )
	PORT_START	/* IN0 */
	PORT_BIT( 0x0f, IP_ACTIVE_HIGH, IPT_SPECIAL )	/* trackball data */
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_SERVICE( 0x20, IP_ACTIVE_LOW )
	PORT_BIT( 0x40, IP_ACTIVE_HIGH, IPT_VBLANK )
	PORT_BIT( 0x80, IP_ACTIVE_HIGH, IPT_SPECIAL )	/* trackball sign bit */

	PORT_START	/* IN1 */
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_START1 )
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_BUTTON1 )
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_TILT )
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_COIN1 )
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_COIN2 )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_SERVICE1 )

	PORT_START	/* IN2 */
	PORT_BIT( 0x0f, IP_ACTIVE_HIGH, IPT_SPECIAL )	/* trackball data */
	PORT_BIT( 0x70, IP_ACTIVE_HIGH, IPT_UNKNOWN )
	PORT_BIT( 0x80, IP_ACTIVE_HIGH, IPT_SPECIAL )	/* trackball sign bit */

	PORT_START	/* IN3 */
	PORT_BIT( 0x0f, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_JOYSTICK_UP ) PORT_8WAY
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN ) PORT_8WAY
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT ) PORT_8WAY
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT ) PORT_8WAY

	PORT_START	/* IN4 */
	PORT_DIPNAME( 0x03, 0x00, DEF_STR( Language ) )
	PORT_DIPSETTING(    0x00, DEF_STR( English ) )
	PORT_DIPSETTING(    0x01, DEF_STR( German ) )
	PORT_DIPSETTING(    0x02, DEF_STR( French ) )
	PORT_DIPSETTING(    0x03, DEF_STR( Spanish ) )
	PORT_DIPNAME( 0x0c, 0x04, DEF_STR( Lives ))
	PORT_DIPSETTING(    0x00, "2" )
	PORT_DIPSETTING(    0x04, "3" )
	PORT_DIPSETTING(    0x08, "4" )
	PORT_DIPSETTING(    0x0c, "5" )
	PORT_DIPNAME( 0x30, 0x10, DEF_STR( Bonus_Life ))
	PORT_DIPSETTING(    0x00, "10000" )
	PORT_DIPSETTING(    0x10, "12000" )
	PORT_DIPSETTING(    0x20, "15000" )
	PORT_DIPSETTING(    0x30, "20000" )
	PORT_DIPNAME( 0x40, 0x40, DEF_STR( Difficulty ))
	PORT_DIPSETTING(    0x40, DEF_STR( Easy ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Hard ) )
	PORT_DIPNAME( 0x80, 0x00, "Credit Minimum" )
	PORT_DIPSETTING(    0x00, "1" )
	PORT_DIPSETTING(    0x80, "2" )

	PORT_START	/* IN5 */
	PORT_DIPNAME( 0x03, 0x02, DEF_STR( Coinage ))
	PORT_DIPSETTING(    0x03, DEF_STR( 2C_1C ))
	PORT_DIPSETTING(    0x02, DEF_STR( 1C_1C ))
	PORT_DIPSETTING(    0x01, DEF_STR( 1C_2C ))
	PORT_DIPSETTING(    0x00, DEF_STR( Free_Play ))
	PORT_DIPNAME( 0x1c, 0x00, DEF_STR( Game_Time ) )
	PORT_DIPSETTING(    0x00, "Untimed" )
	PORT_DIPSETTING(    0x04, "1 Minute" )
	PORT_DIPSETTING(    0x08, "2 Minutes" )
	PORT_DIPSETTING(    0x0c, "3 Minutes" )
	PORT_DIPSETTING(    0x10, "4 Minutes" )
	PORT_DIPSETTING(    0x14, "5 Minutes" )
	PORT_DIPSETTING(    0x18, "6 Minutes" )
	PORT_DIPSETTING(    0x1c, "7 Minutes" )
	PORT_DIPNAME( 0xe0, 0x00, "Bonus Coins" )
	PORT_DIPSETTING(    0x00, DEF_STR( None ) )
	PORT_DIPSETTING(    0x20, "3 credits/2 coins" )
	PORT_DIPSETTING(    0x40, "5 credits/4 coins" )
	PORT_DIPSETTING(    0x60, "6 credits/4 coins" )
	PORT_DIPSETTING(    0x80, "6 credits/5 coins" )
	PORT_DIPSETTING(    0xa0, "4 credits/3 coins" )

	PORT_START	/* IN6, fake trackball input port. */
	PORT_BIT( 0xff, 0x00, IPT_TRACKBALL_X ) PORT_SENSITIVITY(50) PORT_KEYDELTA(10) PORT_REVERSE

	PORT_START	/* IN7, fake trackball input port. */
	PORT_BIT( 0xff, 0x00, IPT_TRACKBALL_Y ) PORT_SENSITIVITY(50) PORT_KEYDELTA(10)

	PORT_START	/* IN8, place for cocktail trackball (not used) */
	PORT_BIT( 0xff, IP_ACTIVE_LOW, IPT_UNUSED )

	PORT_START	/* IN9, place for cocktail trackball (not used) */
	PORT_BIT( 0xff, IP_ACTIVE_LOW, IPT_UNUSED )
INPUT_PORTS_END


INPUT_PORTS_START( magworm )
	PORT_START	/* IN0 */
	PORT_BIT( 0x0f, IP_ACTIVE_HIGH, IPT_SPECIAL )	/* trackball data */
	PORT_DIPNAME( 0x10, 0x00, DEF_STR( Cabinet ))
	PORT_DIPSETTING(    0x00, DEF_STR( Upright ))
	PORT_DIPSETTING(    0x10, DEF_STR( Cocktail ))
	PORT_SERVICE( 0x20, IP_ACTIVE_LOW )
	PORT_BIT( 0x40, IP_ACTIVE_HIGH, IPT_VBLANK )
	PORT_BIT( 0x80, IP_ACTIVE_HIGH, IPT_SPECIAL )	/* trackball sign bit */

	PORT_START	/* IN1 */
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_START1 )
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_START2 )
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_BUTTON1 )
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_COCKTAIL
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_TILT )
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_COIN2 )
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_COIN1 )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_SERVICE1 )

	PORT_START	/* IN2 */
	PORT_BIT( 0x0f, IP_ACTIVE_HIGH, IPT_SPECIAL )	/* trackball data */
	PORT_BIT( 0x70, IP_ACTIVE_HIGH, IPT_UNKNOWN )
	PORT_BIT( 0x80, IP_ACTIVE_HIGH, IPT_SPECIAL )	/* trackball sign bit */

	PORT_START	/* IN3 */
	PORT_BIT( 0xff, IP_ACTIVE_LOW, IPT_UNKNOWN )

	PORT_START	/* IN4 */
	PORT_DIPNAME( 0x03, 0x02, DEF_STR( Coinage ))
	PORT_DIPSETTING(    0x03, DEF_STR( 2C_1C ))
	PORT_DIPSETTING(    0x02, DEF_STR( 1C_1C ))
	PORT_DIPSETTING(    0x01, DEF_STR( 1C_2C ))
	PORT_DIPSETTING(    0x00, DEF_STR( Free_Play ))
	PORT_DIPNAME( 0x0c, 0x00, "Right Coin" )
	PORT_DIPSETTING(    0x00, "*3" )
	PORT_DIPSETTING(    0x04, "*7" )
	PORT_DIPSETTING(    0x08, "*1/2" )
	PORT_DIPSETTING(    0x0c, "*6" )
	PORT_DIPNAME( 0x30, 0x00, DEF_STR( Language ) )
	PORT_DIPSETTING(    0x00, DEF_STR( English ) )
	PORT_DIPSETTING(    0x10, DEF_STR( German ) )
	PORT_DIPSETTING(    0x20, DEF_STR( French ) )
	PORT_DIPSETTING(    0x30, DEF_STR( Spanish ) )
	PORT_DIPNAME( 0xc0, 0x40, DEF_STR( Lives ))
	PORT_DIPSETTING(    0x00, "2" )
	PORT_DIPSETTING(    0x40, "3" )
	PORT_DIPSETTING(    0x80, "4" )
	PORT_DIPSETTING(    0xc0, "5" )

	PORT_START	/* IN5 */
	PORT_DIPNAME( 0x01, 0x00, "Left Coin" )
	PORT_DIPSETTING(    0x00, "*1" )
	PORT_DIPSETTING(    0x01, "*2" )
	PORT_DIPNAME( 0x0e, 0x00, "Bonus Coins" )
	PORT_DIPSETTING(    0x00, DEF_STR( None ) )
	PORT_DIPSETTING(    0x02, "3 credits/2 coins" )
	PORT_DIPSETTING(    0x04, "5 credits/4 coins" )
	PORT_DIPSETTING(    0x06, "6 credits/4 coins" )
	PORT_DIPSETTING(    0x08, "6 credits/5 coins" )
	PORT_DIPSETTING(    0x0a, "4 credits/3 coins" )
	PORT_DIPNAME( 0x30, 0x10, DEF_STR( Bonus_Life ))
	PORT_DIPSETTING(    0x00, "10000" )
	PORT_DIPSETTING(    0x10, "12000" )
	PORT_DIPSETTING(    0x20, "15000" )
	PORT_DIPSETTING(    0x30, "20000" )
	PORT_DIPNAME( 0x40, 0x40, DEF_STR( Difficulty ))
	PORT_DIPSETTING(    0x40, DEF_STR( Easy ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Hard ) )
	PORT_DIPNAME( 0x80, 0x00, "Credit Minimum" )
	PORT_DIPSETTING(    0x00, "1" )
	PORT_DIPSETTING(    0x80, "2" )

	PORT_START	/* IN6, fake trackball input port. */
	PORT_BIT( 0xff, 0x00, IPT_TRACKBALL_X ) PORT_SENSITIVITY(50) PORT_KEYDELTA(10) PORT_REVERSE

	PORT_START	/* IN7, fake trackball input port. */
	PORT_BIT( 0xff, 0x00, IPT_TRACKBALL_Y ) PORT_SENSITIVITY(50) PORT_KEYDELTA(10)

	PORT_START	/* IN8, fake trackball input port. */
	PORT_BIT( 0xff, 0x00, IPT_TRACKBALL_X ) PORT_SENSITIVITY(50) PORT_KEYDELTA(10) PORT_COCKTAIL

	PORT_START	/* IN9, fake trackball input port. */
	PORT_BIT( 0xff, 0x00, IPT_TRACKBALL_Y ) PORT_SENSITIVITY(50) PORT_KEYDELTA(10) PORT_REVERSE PORT_COCKTAIL
INPUT_PORTS_END


INPUT_PORTS_START( milliped )
	PORT_START	/* IN0 $2000 */ /* see port 6 for x trackball */
	PORT_DIPNAME(0x03, 0x00, DEF_STR( Language ) )
	PORT_DIPSETTING(   0x00, DEF_STR( English ) )
	PORT_DIPSETTING(   0x01, DEF_STR( German ) )
	PORT_DIPSETTING(   0x02, DEF_STR( French ) )
	PORT_DIPSETTING(   0x03, DEF_STR( Spanish ) )
	PORT_DIPNAME(0x0c, 0x04, "Bonus" )
	PORT_DIPSETTING(   0x00, "0" )
	PORT_DIPSETTING(   0x04, "0 1x" )
	PORT_DIPSETTING(   0x08, "0 1x 2x" )
	PORT_DIPSETTING(   0x0c, "0 1x 2x 3x" )
	PORT_BIT ( 0x10, IP_ACTIVE_LOW, IPT_BUTTON1 )
	PORT_BIT ( 0x20, IP_ACTIVE_LOW, IPT_START1 )
	PORT_BIT ( 0x40, IP_ACTIVE_HIGH, IPT_VBLANK )
	PORT_BIT ( 0x80, IP_ACTIVE_HIGH, IPT_SPECIAL )	/* trackball sign bit */

	PORT_START	/* IN1 $2001 */ /* see port 7 for y trackball */
	PORT_DIPNAME(0x01, 0x00, DEF_STR( Unknown ))
	PORT_DIPSETTING(   0x00, DEF_STR( Off ))
	PORT_DIPSETTING(   0x01, DEF_STR( On ))
	PORT_DIPNAME(0x02, 0x00, DEF_STR( Unknown ))
	PORT_DIPSETTING(   0x00, DEF_STR( Off ))
	PORT_DIPSETTING(   0x02, DEF_STR( On ))
	PORT_DIPNAME(0x04, 0x00, "Credit Minimum" )
	PORT_DIPSETTING(   0x00, "1" )
	PORT_DIPSETTING(   0x04, "2" )
	PORT_DIPNAME(0x08, 0x00, "Coin Counters" )
	PORT_DIPSETTING(   0x00, "1" )
	PORT_DIPSETTING(   0x08, "2" )
	PORT_BIT ( 0x10, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_COCKTAIL
	PORT_BIT ( 0x20, IP_ACTIVE_LOW, IPT_START2 )
	PORT_BIT ( 0x40, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT ( 0x80, IP_ACTIVE_HIGH, IPT_SPECIAL )	/* trackball sign bit */

	PORT_START	/* IN2 $2010 */
	PORT_BIT ( 0x01, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT ) PORT_8WAY
	PORT_BIT ( 0x02, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT ) PORT_8WAY
	PORT_BIT ( 0x04, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN ) PORT_8WAY
	PORT_BIT ( 0x08, IP_ACTIVE_LOW, IPT_JOYSTICK_UP ) PORT_8WAY
	PORT_BIT ( 0x10, IP_ACTIVE_LOW, IPT_TILT )
	PORT_BIT ( 0x20, IP_ACTIVE_LOW, IPT_COIN1 )
	PORT_BIT ( 0x40, IP_ACTIVE_LOW, IPT_COIN2 )
	PORT_BIT ( 0x80, IP_ACTIVE_LOW, IPT_SERVICE1 )

	PORT_START	/* IN3 $2011 */
	PORT_BIT ( 0x01, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT ) PORT_8WAY PORT_COCKTAIL
	PORT_BIT ( 0x02, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT ) PORT_8WAY PORT_COCKTAIL
	PORT_BIT ( 0x04, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN ) PORT_8WAY PORT_COCKTAIL
	PORT_BIT ( 0x08, IP_ACTIVE_LOW, IPT_JOYSTICK_UP ) PORT_8WAY PORT_COCKTAIL
	PORT_BIT ( 0x10, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT ( 0x20, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT ( 0x40, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_SERVICE( 0x80, IP_ACTIVE_LOW )

	PORT_START	/* 4 */ /* DSW1 $0408 */
	PORT_DIPNAME(0x01, 0x00, "Millipede Head" )
	PORT_DIPSETTING(   0x00, DEF_STR( Easy ) )
	PORT_DIPSETTING(   0x01, DEF_STR( Hard ) )
	PORT_DIPNAME(0x02, 0x00, "Beetle" )
	PORT_DIPSETTING(   0x00, DEF_STR( Easy ) )
	PORT_DIPSETTING(   0x02, DEF_STR( Hard ) )
	PORT_DIPNAME(0x0c, 0x04, DEF_STR( Lives ))
	PORT_DIPSETTING(   0x00, "2" )
	PORT_DIPSETTING(   0x04, "3" )
	PORT_DIPSETTING(   0x08, "4" )
	PORT_DIPSETTING(   0x0c, "5" )
	PORT_DIPNAME(0x30, 0x10, DEF_STR( Bonus_Life ))
	PORT_DIPSETTING(   0x00, "12000" )
	PORT_DIPSETTING(   0x10, "15000" )
	PORT_DIPSETTING(   0x20, "20000" )
	PORT_DIPSETTING(   0x30, DEF_STR( None ) )
	PORT_DIPNAME(0x40, 0x00, "Spider" )
	PORT_DIPSETTING(   0x00, DEF_STR( Easy ) )
	PORT_DIPSETTING(   0x40, DEF_STR( Hard ) )
	PORT_DIPNAME(0x80, 0x00, "Starting Score Select" )
	PORT_DIPSETTING(   0x80, DEF_STR( Off ))
	PORT_DIPSETTING(   0x00, DEF_STR( On ))

	PORT_START	/* 5 */ /* DSW2 $0808 */
	PORT_DIPNAME(0x03, 0x02, DEF_STR( Coinage ))
	PORT_DIPSETTING(   0x03, DEF_STR( 2C_1C ))
	PORT_DIPSETTING(   0x02, DEF_STR( 1C_1C ))
	PORT_DIPSETTING(   0x01, DEF_STR( 1C_2C ))
	PORT_DIPSETTING(   0x00, DEF_STR( Free_Play ))
	PORT_DIPNAME(0x0c, 0x00, "Right Coin" )
	PORT_DIPSETTING(   0x00, "*1" )
	PORT_DIPSETTING(   0x04, "*4" )
	PORT_DIPSETTING(   0x08, "*5" )
	PORT_DIPSETTING(   0x0c, "*6" )
	PORT_DIPNAME(0x10, 0x00, "Left Coin" )
	PORT_DIPSETTING(   0x00, "*1" )
	PORT_DIPSETTING(   0x10, "*2" )
	PORT_DIPNAME(0xe0, 0x00, "Bonus Coins" )
	PORT_DIPSETTING(   0x00, DEF_STR( None ) )
	PORT_DIPSETTING(   0x20, "3 credits/2 coins" )
	PORT_DIPSETTING(   0x40, "5 credits/4 coins" )
	PORT_DIPSETTING(   0x60, "6 credits/4 coins" )
	PORT_DIPSETTING(   0x80, "6 credits/5 coins" )
	PORT_DIPSETTING(   0xa0, "4 credits/3 coins" )
	PORT_DIPSETTING(   0xc0, "Demo mode" )

	PORT_START	/* IN6, fake trackball input port. */
	PORT_BIT( 0xff, 0x00, IPT_TRACKBALL_X ) PORT_SENSITIVITY(50) PORT_KEYDELTA(10) PORT_REVERSE

	PORT_START	/* IN7, fake trackball input port. */
	PORT_BIT( 0xff, 0x00, IPT_TRACKBALL_Y ) PORT_SENSITIVITY(50) PORT_KEYDELTA(10)
INPUT_PORTS_END


INPUT_PORTS_START( warlords )
	PORT_START	/* IN0 */
	PORT_BIT( 0x0f, IP_ACTIVE_HIGH, IPT_UNUSED )
	PORT_DIPNAME( 0x10, 0x00, "Diag Step" )  /* Not referenced */
	PORT_DIPSETTING(    0x00, DEF_STR( Off ))
	PORT_DIPSETTING(    0x10, DEF_STR( On ))
	PORT_SERVICE( 0x20, IP_ACTIVE_LOW )
	PORT_BIT( 0x40, IP_ACTIVE_HIGH, IPT_VBLANK )
	PORT_DIPNAME( 0x80, 0x00, DEF_STR( Cabinet ))
	PORT_DIPSETTING(    0x80, "Upright (overlay)" )
	PORT_DIPSETTING(    0x00, "Cocktail (no overlay)" )

	PORT_START	/* IN1 */
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_PLAYER(1)
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_PLAYER(2)
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_PLAYER(3)
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_PLAYER(4)
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_TILT )
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_COIN1 )
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_COIN2 )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_SERVICE1 )

	PORT_START	/* IN2 */
	PORT_DIPNAME( 0x03, 0x00, DEF_STR( Language ) )
	PORT_DIPSETTING(    0x00, DEF_STR( English ) )
	PORT_DIPSETTING(    0x01, DEF_STR( French ) )
	PORT_DIPSETTING(    0x02, DEF_STR( Spanish ) )
	PORT_DIPSETTING(    0x03, DEF_STR( German ) )
	PORT_DIPNAME( 0x04, 0x00, "Music" )
	PORT_DIPSETTING(    0x00, "End of game" )
	PORT_DIPSETTING(    0x04, "High score only" )
	PORT_BIT( 0xc8, IP_ACTIVE_HIGH, IPT_UNUSED )
	PORT_DIPNAME( 0x30, 0x00, "Credits" )
	PORT_DIPSETTING(    0x00, "1p/2p = 1 credit" )
	PORT_DIPSETTING(    0x10, "1p = 1, 2p = 2" )
	PORT_DIPSETTING(    0x20, "1p/2p = 2 credits" )

	PORT_START	/* IN3 */
	PORT_DIPNAME( 0x03, 0x02, DEF_STR( Coinage ))
	PORT_DIPSETTING(    0x03, DEF_STR( 2C_1C ))
	PORT_DIPSETTING(    0x02, DEF_STR( 1C_1C ))
	PORT_DIPSETTING(    0x01, DEF_STR( 1C_2C ))
	PORT_DIPSETTING(    0x00, DEF_STR( Free_Play ))
	PORT_DIPNAME( 0x0c, 0x00, "Right Coin" )
	PORT_DIPSETTING(    0x00, "*1" )
	PORT_DIPSETTING(    0x04, "*4" )
	PORT_DIPSETTING(    0x08, "*5" )
	PORT_DIPSETTING(    0x0c, "*6" )
	PORT_DIPNAME( 0x10, 0x00, "Left Coin" )
	PORT_DIPSETTING(    0x00, "*1" )
	PORT_DIPSETTING(    0x10, "*2" )
	PORT_DIPNAME( 0xe0, 0x00, "Bonus Coins" )
	PORT_DIPSETTING(    0x00, DEF_STR( None ) )
	PORT_DIPSETTING(    0x20, "3 credits/2 coins" )
	PORT_DIPSETTING(    0x40, "5 credits/4 coins" )
	PORT_DIPSETTING(    0x60, "6 credits/4 coins" )
	PORT_DIPSETTING(    0x80, "6 credits/5 coins" )

	/* IN4-7 fake to control player paddles */
	PORT_START
	PORT_BIT( 0xff, 0x80, IPT_PADDLE ) PORT_MINMAX(0x1d,0xcb) PORT_SENSITIVITY(50) PORT_KEYDELTA(10) PORT_CENTERDELTA(0) PORT_PLAYER(1)

	PORT_START
	PORT_BIT( 0xff, 0x80, IPT_PADDLE ) PORT_MINMAX(0x1d,0xcb) PORT_SENSITIVITY(50) PORT_KEYDELTA(10) PORT_CENTERDELTA(0) PORT_PLAYER(2)

	PORT_START
	PORT_BIT( 0xff, 0x80, IPT_PADDLE ) PORT_MINMAX(0x1d,0xcb) PORT_SENSITIVITY(50) PORT_KEYDELTA(10) PORT_CENTERDELTA(0) PORT_PLAYER(3)

	PORT_START
	PORT_BIT( 0xff, 0x80, IPT_PADDLE ) PORT_MINMAX(0x1d,0xcb) PORT_SENSITIVITY(50) PORT_KEYDELTA(10) PORT_CENTERDELTA(0) PORT_PLAYER(4)
INPUT_PORTS_END


INPUT_PORTS_START( bullsdrt )
	PORT_START	/* IN0 */
	PORT_BIT( 0x0f, IP_ACTIVE_HIGH, IPT_SPECIAL )	/* trackball data */
	PORT_BIT( 0x30, IP_ACTIVE_LOW,  IPT_UNKNOWN )
	PORT_BIT( 0x40, IP_ACTIVE_HIGH, IPT_VBLANK )
	PORT_BIT( 0x80, IP_ACTIVE_HIGH, IPT_SPECIAL )	/* trackball sign bit */

	PORT_START	/* IN1 */
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_START1 )
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_START2 )
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_BUTTON1 )
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_COIN1 )
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_COIN2 )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_COIN3 )

	PORT_START	/* IN2 */
	PORT_BIT( 0x0f, IP_ACTIVE_HIGH, IPT_SPECIAL )	/* trackball data */
	PORT_BIT( 0x70, IP_ACTIVE_LOW,  IPT_UNKNOWN )
	PORT_BIT( 0x80, IP_ACTIVE_HIGH, IPT_SPECIAL )	/* trackball sign bit */

	PORT_START
	PORT_DIPNAME( 0x01, 0x01, DEF_STR( Unknown ) )
	PORT_DIPSETTING(    0x01, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x02, 0x02, "Award Free Game" )
	PORT_DIPSETTING(    0x02, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x04, 0x04, DEF_STR( Unknown ) )
	PORT_DIPSETTING(    0x04, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x08, 0x08, DEF_STR( Unknown ) )
	PORT_DIPSETTING(    0x08, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x10, 0x10, DEF_STR( Unknown ) )
	PORT_DIPSETTING(    0x10, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x20, 0x20, DEF_STR( Unknown ) )
	PORT_DIPSETTING(    0x20, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x40, 0x40, DEF_STR( Unknown ) )
	PORT_DIPSETTING(    0x40, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x80, 0x80, DEF_STR( Unknown ) )
	PORT_DIPSETTING(    0x80, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )

	PORT_START
	PORT_DIPNAME( 0x01, 0x01, DEF_STR( Unknown ) )
	PORT_DIPSETTING(    0x01, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x02, 0x02, DEF_STR( Unknown ) )
	PORT_DIPSETTING(    0x02, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x04, 0x04, DEF_STR( Unknown ) )
	PORT_DIPSETTING(    0x04, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x08, 0x08, DEF_STR( Unknown ) )
	PORT_DIPSETTING(    0x08, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x10, 0x10, DEF_STR( Unknown ) )
	PORT_DIPSETTING(    0x10, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x20, 0x20, DEF_STR( Unknown ) )
	PORT_DIPSETTING(    0x20, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x40, 0x40, DEF_STR( Unknown ) )
	PORT_DIPSETTING(    0x40, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x80, 0x80, DEF_STR( Unknown ) )
	PORT_DIPSETTING(    0x80, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )

	PORT_START
	/* not used */

	PORT_START	/* IN6, fake trackball input port. */
	PORT_BIT( 0xff, 0x80, IPT_TRACKBALL_X ) PORT_MINMAX(0x1d,0xcb) PORT_SENSITIVITY(50) PORT_KEYDELTA(10) PORT_REVERSE

	PORT_START	/* IN7, fake trackball input port. */
	PORT_BIT( 0xff, 0x80, IPT_TRACKBALL_Y ) PORT_MINMAX(0x1d,0xcb) PORT_SENSITIVITY(50) PORT_KEYDELTA(10)
INPUT_PORTS_END




/*************************************
 *
 *  Game drivers
 *
 *************************************/

GAME( 1980, centiped, 0,        centiped, centiped, 0,        ROT270, "Atari",   "Centipede (revision 3)", 0 )
GAME( 1980, centipd2, centiped, centiped, centiped, 0,        ROT270, "Atari",   "Centipede (revision 2)", 0 )
GAME( 1980, centtime, centiped, centiped, centtime, 0,        ROT270, "Atari",   "Centipede (1 player, timed)", 0 )
GAME( 1980, centipdb, centiped, centipdb, centiped, 0,        ROT270, "bootleg", "Centipede (bootleg)", 0 )
GAME( 1980, caterplr, centiped, caterplr, caterplr, caterplr, ROT270, "bootleg", "Caterpillar", 0 )
GAME( 1980, millpac,  centiped, centipdb, centiped, 0, 	      ROT270, "Valadon Automation", "Millpac", 0 )
GAME( 1980, magworm,  centiped, magworm,  magworm,  magworm,  ROT270, "bootleg", "Magic Worm (bootleg)", 0 )
GAME( 1982, milliped, 0,        milliped, milliped, 0,        ROT270, "Atari",   "Millipede", 0 )

GAME( 1980, warlords, 0,        warlords, warlords, 0,        ROT0,   "Atari",   "Warlords", 0 )

GAME( 1985, bullsdrt, 0,        bullsdrt, bullsdrt, bullsdrt, ROT270, "Shinkai Inc. (Magic Eletronics Inc. licence)", "Bulls Eye Darts", GAME_IMPERFECT_COLORS )
