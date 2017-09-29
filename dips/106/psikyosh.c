# MAME 0.106 source snippet

#include "driver.h"

#include "cpu/sh2/sh2.h"
#include "machine/eeprom.h"
#include "sound/ymf278b.h"

#include "psikyosh.h"


#define UNUSED_PORT \
	PORT_START_TAG("IN2")/* not read? */ \
	PORT_BIT(  0x01, IP_ACTIVE_LOW, IPT_UNKNOWN ) \
	PORT_BIT(  0x02, IP_ACTIVE_LOW, IPT_UNKNOWN ) \
	PORT_BIT(  0x04, IP_ACTIVE_LOW, IPT_UNKNOWN ) \
	PORT_BIT(  0x08, IP_ACTIVE_LOW, IPT_UNKNOWN ) \
	PORT_BIT(  0x10, IP_ACTIVE_LOW, IPT_UNKNOWN ) \
	PORT_BIT(  0x20, IP_ACTIVE_LOW, IPT_UNKNOWN ) \
	PORT_BIT(  0x40, IP_ACTIVE_LOW, IPT_UNKNOWN ) \
	PORT_BIT(  0x80, IP_ACTIVE_LOW, IPT_UNKNOWN )

#define PORT_COIN( debug ) \
	PORT_START_TAG("IN3") /* System inputs */ \
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_COIN1    ) \
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_COIN2    ) \
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_UNKNOWN  ) \
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_UNKNOWN  ) \
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_SERVICE1 ) \
	PORT_SERVICE_NO_TOGGLE(0x20, IP_ACTIVE_LOW) \
	PORT_DIPNAME( 0x40, debug ? 0x00 : 0x40, "Debug" ) /* Must be high for dragnblz, low for others (Resets EEPROM?). Debug stuff */ \
	PORT_DIPSETTING(    0x40, DEF_STR( Off ) ) \
	PORT_DIPSETTING(    0x00, DEF_STR( On ) ) \
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_UNKNOWN  )

#define PSIKYOSH_PORT_PLAYER( player, start, buttons ) \
	PORT_BIT(  0x01, IP_ACTIVE_LOW, start ) \
	PORT_BIT(  0x02, IP_ACTIVE_LOW, (buttons>=3)?(IPT_BUTTON3 ) :IPT_UNKNOWN ) PORT_PLAYER(player) \
	PORT_BIT(  0x04, IP_ACTIVE_LOW, (buttons>=2)?(IPT_BUTTON2 ) :IPT_UNKNOWN ) PORT_PLAYER(player) \
	PORT_BIT(  0x08, IP_ACTIVE_LOW, (buttons>=1)?(IPT_BUTTON1 ) :IPT_UNKNOWN ) PORT_PLAYER(player)\
	PORT_BIT(  0x10, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT  ) PORT_PLAYER(player) \
	PORT_BIT(  0x20, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT ) PORT_PLAYER(player) \
	PORT_BIT(  0x40, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN  ) PORT_PLAYER(player) \
	PORT_BIT(  0x80, IP_ACTIVE_LOW, IPT_JOYSTICK_UP    ) PORT_PLAYER(player)

INPUT_PORTS_START( s1945ii )
	PORT_START_TAG("IN0")
	PSIKYOSH_PORT_PLAYER( 1, IPT_START1, 2 )
	PORT_START_TAG("IN1")
	PSIKYOSH_PORT_PLAYER( 2, IPT_START2, 2 )

	UNUSED_PORT
	PORT_COIN( 0 )

	PORT_START_TAG("IN4") /* jumper pads on the PCB */
	PORT_DIPNAME( 0x01, 0x01, DEF_STR( Region ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Japan ) )
	PORT_DIPSETTING(    0x01, DEF_STR( World ) )
INPUT_PORTS_END

INPUT_PORTS_START( soldivid )
	PORT_START_TAG("IN0")
	PSIKYOSH_PORT_PLAYER( 1, IPT_START1, 3 )
	PORT_START_TAG("IN1")
	PSIKYOSH_PORT_PLAYER( 2, IPT_START2, 3 )

	UNUSED_PORT
	PORT_COIN( 0 )

	PORT_START_TAG("IN4")/* jumper pads on the PCB */
	PORT_DIPNAME( 0x01, 0x01, DEF_STR( Region ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Japan ) )
	PORT_DIPSETTING(    0x01, DEF_STR( World ) )
INPUT_PORTS_END

INPUT_PORTS_START( daraku )
	PORT_START_TAG("IN0")
	PSIKYOSH_PORT_PLAYER( 1, IPT_START1, 2 )
	PORT_START_TAG("IN1")
	PSIKYOSH_PORT_PLAYER( 2, IPT_START2, 2 )

	PORT_START_TAG("IN2")  /* more controls */
	PORT_BIT(  0x01, IP_ACTIVE_LOW, IPT_UNKNOWN                      )
	PORT_BIT(  0x02, IP_ACTIVE_LOW, IPT_UNKNOWN                      )
	PORT_BIT(  0x04, IP_ACTIVE_LOW, IPT_BUTTON4 ) PORT_PLAYER(2)
	PORT_BIT(  0x08, IP_ACTIVE_LOW, IPT_BUTTON3 ) PORT_PLAYER(2)
	PORT_BIT(  0x10, IP_ACTIVE_LOW, IPT_UNKNOWN                      )
	PORT_BIT(  0x20, IP_ACTIVE_LOW, IPT_UNKNOWN                      )
	PORT_BIT(  0x40, IP_ACTIVE_LOW, IPT_BUTTON4 ) PORT_PLAYER(1)
	PORT_BIT(  0x80, IP_ACTIVE_LOW, IPT_BUTTON3 ) PORT_PLAYER(1)

	PORT_COIN( 0 )

	PORT_START_TAG("IN4")/* jumper pads on the PCB */
	PORT_DIPNAME( 0x01, 0x01, DEF_STR( Region ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Japan ) )
	PORT_DIPSETTING(    0x01, DEF_STR( World ) ) /* Title screen is different, English is default now */
INPUT_PORTS_END

INPUT_PORTS_START( sbomberb )
	PORT_START_TAG("IN0")
	PSIKYOSH_PORT_PLAYER( 1, IPT_START1, 2 )
	PORT_START_TAG("IN1")
	PSIKYOSH_PORT_PLAYER( 2, IPT_START2, 2 )

	UNUSED_PORT
	PORT_COIN( 0 ) /* If HIGH then you can perform rom test, but EEPROM resets? */

	PORT_START_TAG("IN4")/* jumper pads on the PCB */
	PORT_DIPNAME( 0x01, 0x01, DEF_STR( Region ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Japan ) )
	PORT_DIPSETTING(    0x01, DEF_STR( World ) )
INPUT_PORTS_END

INPUT_PORTS_START( gunbird2 ) /* Different Region */
	PORT_START_TAG("IN0")
	PSIKYOSH_PORT_PLAYER( 1, IPT_START1, 3 )
	PORT_START_TAG("IN1")
	PSIKYOSH_PORT_PLAYER( 2, IPT_START2, 3 )

	UNUSED_PORT
	PORT_COIN( 0 ) /* If HIGH then you can perform rom test, but EEPROM resets */

	PORT_START_TAG("IN4")/* jumper pads on the PCB */
	PORT_DIPNAME( 0x03, 0x02, DEF_STR( Region ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Japan ) )
	PORT_DIPSETTING(    0x01, "International Ver A." )
	PORT_DIPSETTING(    0x02, "International Ver B." )
INPUT_PORTS_END

INPUT_PORTS_START( s1945iii ) /* Different Region again */
	PORT_START_TAG("IN0")
	PSIKYOSH_PORT_PLAYER( 1, IPT_START1, 3 )
	PORT_START_TAG("IN1")
	PSIKYOSH_PORT_PLAYER( 2, IPT_START2, 3 )

	UNUSED_PORT
	PORT_COIN( 0 ) /* If HIGH then you can perform rom test, EEPROM doesn't reset */

	PORT_START_TAG("IN4")/* IN4 jumper pads on the PCB */
	PORT_DIPNAME( 0x03, 0x01, DEF_STR( Region ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Japan ) )
	PORT_DIPSETTING(    0x02, "International Ver A." )
	PORT_DIPSETTING(    0x01, "International Ver B." )
INPUT_PORTS_END

INPUT_PORTS_START( dragnblz ) /* Security requires bit high */
	PORT_START_TAG("IN0")
	PSIKYOSH_PORT_PLAYER( 1, IPT_START1, 3 )
	PORT_START_TAG("IN1")
	PSIKYOSH_PORT_PLAYER( 2, IPT_START2, 3 )

	UNUSED_PORT

	PORT_COIN( 1 ) /* Must be HIGH (Or Security Error), so can perform test */

	PORT_START_TAG("IN4")/* jumper pads on the PCB */
	PORT_DIPNAME( 0x03, 0x01, DEF_STR( Region ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Japan ) )
	PORT_DIPSETTING(    0x02, "International Ver A." )
	PORT_DIPSETTING(    0x01, "International Ver B." )
INPUT_PORTS_END

INPUT_PORTS_START( gnbarich ) /* Same as S1945iii except only one button */
	PORT_START_TAG("IN0")
	PSIKYOSH_PORT_PLAYER( 1, IPT_START1, 3 )
	PORT_START_TAG("IN1")
	PSIKYOSH_PORT_PLAYER( 2, IPT_START2, 3 )

	UNUSED_PORT
	PORT_COIN( 0 ) /* If HIGH then you can perform rom test, but EEPROM resets? */

	PORT_START_TAG("IN4")/* jumper pads on the PCB */
	PORT_DIPNAME( 0x03, 0x01, DEF_STR( Region ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Japan ) )
	PORT_DIPSETTING(    0x02, "International Ver A." )
	PORT_DIPSETTING(    0x01, "International Ver B." )
INPUT_PORTS_END

INPUT_PORTS_START( mjgtaste ) /* This will need the Mahjong inputs */
	PORT_START_TAG("IN0")
	PSIKYOSH_PORT_PLAYER( 1, IPT_START1, 3 )
	PORT_START_TAG("IN1")
	PSIKYOSH_PORT_PLAYER( 2, IPT_START2, 3 )

	UNUSED_PORT
	PORT_COIN( 0 )

	PORT_START_TAG("IN4")/* jumper pads on the PCB */
//  PORT_DIPNAME( 0x03, 0x01, DEF_STR( Region ) )
//  PORT_DIPSETTING(    0x00, DEF_STR( Japan ) )
//  PORT_DIPSETTING(    0x02, "International Ver A." )
//  PORT_DIPSETTING(    0x01, "International Ver B." )
INPUT_PORTS_END


/*     YEAR  NAME      PARENT    MACHINE    INPUT     INIT      MONITOR COMPANY   FULLNAME FLAGS */

/* ps3-v1 */
GAME( 1997, soldivid, 0,        psikyo3v1,   soldivid, soldivid, ROT0,   "Psikyo", "Sol Divide - The Sword Of Darkness", GAME_IMPERFECT_SOUND ) // Music Tempo
GAME( 1997, s1945ii,  0,        psikyo3v1,   s1945ii,  s1945ii,  ROT270, "Psikyo", "Strikers 1945 II", GAME_IMPERFECT_GRAPHICS ) // linescroll/zoom
GAME( 1998, daraku,   0,        psikyo3v1,   daraku,   daraku,   ROT0,   "Psikyo", "Daraku Tenshi - The Fallen Angels", 0 )
GAME( 1998, sbomberb, 0,        psikyo3v1,   sbomberb, sbomberb, ROT270, "Psikyo", "Space Bomber (ver. B)", 0 )

/* ps5 */
GAME( 1998, gunbird2, 0,        psikyo5,     gunbird2, gunbird2, ROT270, "Psikyo", "Gunbird 2", 0 )
GAME( 1999, s1945iii, 0,        psikyo5,     s1945iii, s1945iii, ROT270, "Psikyo", "Strikers 1945 III (World) / Strikers 1999 (Japan)", GAME_IMPERFECT_GRAPHICS ) // linescroll/zoom

/* ps5v2 */
GAME( 2000, dragnblz, 0,        psikyo5,     dragnblz, dragnblz, ROT270, "Psikyo", "Dragon Blaze", 0 )
GAME( 2001, gnbarich, 0,        psikyo5,     gnbarich, gnbarich, ROT270, "Psikyo", "Gunbarich", 0 )
GAME( 2002, mjgtaste, 0,        psikyo5,     mjgtaste, mjgtaste, ROT0,   "Psikyo", "Mahjong G-Taste", GAME_NOT_WORKING )
