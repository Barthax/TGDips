# MAME 0.106 source snippet

#include "driver.h"
#include "arabian.h"
#include "sound/ay8910.h"

INPUT_PORTS_START( arabian )
	PORT_START_TAG("IN0")
	PORT_BIT( 0x01, IP_ACTIVE_HIGH, IPT_COIN1 )
	PORT_BIT( 0x02, IP_ACTIVE_HIGH, IPT_COIN2 )
	PORT_SERVICE( 0x04, IP_ACTIVE_HIGH )
	PORT_BIT( 0xf8, IP_ACTIVE_HIGH, IPT_UNKNOWN )

	PORT_START_TAG("DSW1")
	PORT_DIPNAME( 0x01, 0x00, DEF_STR( Lives ))
	PORT_DIPSETTING(    0x00, "3" )
	PORT_DIPSETTING(    0x01, "5" )
	PORT_DIPNAME( 0x02, 0x02, DEF_STR( Cabinet ))
	PORT_DIPSETTING(    0x02, DEF_STR( Upright ))
	PORT_DIPSETTING(    0x00, DEF_STR( Cocktail ))
	PORT_DIPNAME( 0x04, 0x04, DEF_STR( Flip_Screen ))
	PORT_DIPSETTING(    0x04, DEF_STR( Off ))
	PORT_DIPSETTING(    0x00, DEF_STR( On ))
	PORT_DIPNAME( 0x08, 0x00, "Carry Bowls to Next Life" )
	PORT_DIPSETTING(    0x08, DEF_STR( No ))
	PORT_DIPSETTING(    0x00, DEF_STR( Yes ))
	PORT_DIPNAME( 0xf0, 0x00, DEF_STR( Coinage ))
	PORT_DIPSETTING(    0x10, "A 2/1 B 2/1" )
	PORT_DIPSETTING(    0x20, "A 2/1 B 1/3" )
	PORT_DIPSETTING(    0x00, "A 1/1 B 1/1" )
	PORT_DIPSETTING(    0x30, "A 1/1 B 1/2" )
	PORT_DIPSETTING(    0x40, "A 1/1 B 1/3" )
	PORT_DIPSETTING(    0x50, "A 1/1 B 1/4" )
	PORT_DIPSETTING(    0x60, "A 1/1 B 1/5" )
	PORT_DIPSETTING(    0x70, "A 1/1 B 1/6" )
	PORT_DIPSETTING(    0x80, "A 1/2 B 1/2" )
	PORT_DIPSETTING(    0x90, "A 1/2 B 1/4" )
	PORT_DIPSETTING(    0xa0, "A 1/2 B 1/6" )
	PORT_DIPSETTING(    0xb0, "A 1/2 B 1/10" )
	PORT_DIPSETTING(    0xc0, "A 1/2 B 1/11" )
	PORT_DIPSETTING(    0xd0, "A 1/2 B 1/12" )
	PORT_DIPSETTING(    0xf0, DEF_STR( Free_Play ))
	/* 0xe0 gives A 1/2 B 1/6 */

	PORT_START_TAG("COM0")
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x02, IP_ACTIVE_HIGH, IPT_START1 )
	PORT_BIT( 0x04, IP_ACTIVE_HIGH, IPT_START2 )
	PORT_BIT( 0x08, IP_ACTIVE_HIGH, IPT_COIN3 )		/* IN3 */

	PORT_START_TAG("COM1")
	PORT_BIT( 0x01, IP_ACTIVE_HIGH, IPT_JOYSTICK_RIGHT ) PORT_8WAY
	PORT_BIT( 0x02, IP_ACTIVE_HIGH, IPT_JOYSTICK_LEFT ) PORT_8WAY
	PORT_BIT( 0x04, IP_ACTIVE_HIGH, IPT_JOYSTICK_UP ) PORT_8WAY
	PORT_BIT( 0x08, IP_ACTIVE_HIGH, IPT_JOYSTICK_DOWN ) PORT_8WAY

	PORT_START_TAG("COM2")
	PORT_BIT( 0x01, IP_ACTIVE_HIGH, IPT_BUTTON1 )
	PORT_BIT( 0x02, IP_ACTIVE_HIGH, IPT_UNKNOWN )	/* IN9 */
	PORT_BIT( 0x04, IP_ACTIVE_HIGH, IPT_UNKNOWN )	/* IN10 */
	PORT_BIT( 0x08, IP_ACTIVE_HIGH, IPT_UNKNOWN )	/* IN11 */

	PORT_START_TAG("COM3")
	PORT_BIT( 0x01, IP_ACTIVE_HIGH, IPT_JOYSTICK_RIGHT ) PORT_8WAY PORT_COCKTAIL
	PORT_BIT( 0x02, IP_ACTIVE_HIGH, IPT_JOYSTICK_LEFT ) PORT_8WAY PORT_COCKTAIL
	PORT_BIT( 0x04, IP_ACTIVE_HIGH, IPT_JOYSTICK_UP ) PORT_8WAY PORT_COCKTAIL
	PORT_BIT( 0x08, IP_ACTIVE_HIGH, IPT_JOYSTICK_DOWN ) PORT_8WAY PORT_COCKTAIL

	PORT_START_TAG("COM4")
	PORT_BIT( 0x01, IP_ACTIVE_HIGH, IPT_BUTTON1 ) PORT_COCKTAIL
	PORT_BIT( 0x02, IP_ACTIVE_HIGH, IPT_UNKNOWN )	/* IN17 */
	PORT_BIT( 0x04, IP_ACTIVE_HIGH, IPT_UNKNOWN )	/* IN18 */
	PORT_BIT( 0x08, IP_ACTIVE_HIGH, IPT_UNKNOWN )	/* IN19 */

	PORT_START_TAG("COM5")
	PORT_DIPNAME( 0x01, 0x00, "Coin Chutes" )
	PORT_DIPSETTING(    0x01, "1" )
	PORT_DIPSETTING(    0x00, "2" )
	PORT_DIPNAME( 0x02, 0x00, DEF_STR( Demo_Sounds ))
	PORT_DIPSETTING(    0x02, DEF_STR( Off ))
	PORT_DIPSETTING(    0x00, DEF_STR( On ))
	PORT_DIPNAME( 0x0c, 0x04, DEF_STR( Bonus_Life ))
	PORT_DIPSETTING(    0x04, "20000" )
	PORT_DIPSETTING(    0x08, "40000" )
	PORT_DIPSETTING(    0x0c, "20000 50000 +100K" )
	PORT_DIPSETTING(    0x00, DEF_STR( None ) )
INPUT_PORTS_END


GAME( 1983, arabian,  0,       arabian, arabian, arabian, ROT270, "Sun Electronics", "Arabian", 0 )
GAME( 1983, arabiana, arabian, arabian, arabian, arabian, ROT270, "[Sun Electronics] (Atari license)", "Arabian (Atari)", 0 )
