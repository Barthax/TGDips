# MAME 0.106 source snippet


#include "driver.h"
#include "cpu/z80/z80.h"
#include "sound/ay8910.h"
#include "sound/dac.h"

/*******************************************************************************/

#define TS_IN0\
	PORT_START_TAG("IN0")\
	PORT_BIT( 0x01, IP_ACTIVE_HIGH, IPT_JOYSTICK_RIGHT ) PORT_4WAY\
	PORT_BIT( 0x02, IP_ACTIVE_HIGH, IPT_JOYSTICK_LEFT ) PORT_4WAY\
	PORT_BIT( 0x04, IP_ACTIVE_HIGH, IPT_JOYSTICK_UP ) PORT_4WAY\
	PORT_BIT( 0x08, IP_ACTIVE_HIGH, IPT_JOYSTICK_DOWN ) PORT_4WAY\
	PORT_BIT( 0x10, IP_ACTIVE_HIGH, IPT_BUTTON1 )\
	PORT_BIT( 0x20, IP_ACTIVE_HIGH, IPT_BUTTON2 )\
	PORT_BIT( 0x40, IP_ACTIVE_HIGH, IPT_UNKNOWN )\
	PORT_BIT( 0x80, IP_ACTIVE_HIGH, IPT_UNKNOWN )

#define TS_IN1\
	PORT_START_TAG("IN1")\
	PORT_BIT( 0x01, IP_ACTIVE_HIGH, IPT_JOYSTICK_RIGHT ) PORT_4WAY PORT_COCKTAIL\
	PORT_BIT( 0x02, IP_ACTIVE_HIGH, IPT_JOYSTICK_LEFT ) PORT_4WAY PORT_COCKTAIL\
	PORT_BIT( 0x04, IP_ACTIVE_HIGH, IPT_JOYSTICK_UP ) PORT_4WAY PORT_COCKTAIL\
	PORT_BIT( 0x08, IP_ACTIVE_HIGH, IPT_JOYSTICK_DOWN ) PORT_4WAY PORT_COCKTAIL\
	PORT_BIT( 0x10, IP_ACTIVE_HIGH, IPT_BUTTON1 ) PORT_COCKTAIL\
	PORT_BIT( 0x20, IP_ACTIVE_HIGH, IPT_BUTTON2 ) PORT_COCKTAIL\
	PORT_BIT( 0x40, IP_ACTIVE_HIGH, IPT_UNKNOWN )\
	PORT_BIT( 0x80, IP_ACTIVE_HIGH, IPT_UNKNOWN )

#define TS_IN2\
	PORT_START_TAG("IN2")\
	PORT_BIT( 0x01, IP_ACTIVE_HIGH, IPT_COIN1 )\
	PORT_BIT( 0x02, IP_ACTIVE_HIGH, IPT_COIN2 )\
	PORT_BIT( 0x04, IP_ACTIVE_HIGH, IPT_SERVICE )\
	PORT_BIT( 0x08, IP_ACTIVE_HIGH, IPT_UNUSED )\
	PORT_BIT( 0x10, IP_ACTIVE_HIGH, IPT_START1 )\
	PORT_BIT( 0x20, IP_ACTIVE_HIGH, IPT_START2 )\
	PORT_BIT( 0x40, IP_ACTIVE_HIGH, IPT_UNKNOWN )\
	PORT_BIT( 0x80, IP_ACTIVE_HIGH, IPT_UNKNOWN )

#define TS_DSW1\
	PORT_START_TAG("DSW1")\
	PORT_DIPNAME( 0x07, 0x00, DEF_STR( Coin_A ) )\
	PORT_DIPSETTING(    0x07, DEF_STR( 6C_1C ) )\
	PORT_DIPSETTING(    0x06, DEF_STR( 3C_1C ) )\
	PORT_DIPSETTING(    0x04, DEF_STR( 2C_1C ) )\
	PORT_DIPSETTING(    0x00, DEF_STR( 1C_1C ) )\
	PORT_DIPSETTING(    0x05, DEF_STR( 2C_3C ) )\
	PORT_DIPSETTING(    0x01, DEF_STR( 1C_2C ) )\
	PORT_DIPSETTING(    0x02, DEF_STR( 1C_3C ) )\
	PORT_DIPSETTING(    0x03, DEF_STR( 1C_6C ) )\
	PORT_DIPNAME( 0x38, 0x00, DEF_STR( Coin_B ) )\
	PORT_DIPSETTING(    0x38, DEF_STR( 6C_1C ) )\
	PORT_DIPSETTING(    0x30, DEF_STR( 3C_1C ) )\
	PORT_DIPSETTING(    0x20, DEF_STR( 2C_1C ) )\
	PORT_DIPSETTING(    0x00, DEF_STR( 1C_1C ) )\
	PORT_DIPSETTING(    0x28, DEF_STR( 2C_3C ) )\
	PORT_DIPSETTING(    0x08, DEF_STR( 1C_2C ) )\
	PORT_DIPSETTING(    0x10, DEF_STR( 1C_3C ) )\
	PORT_DIPSETTING(    0x18, DEF_STR( 1C_6C ) )\
	PORT_DIPNAME( 0x40, 0x00, "Freeze" )\
	PORT_DIPSETTING(    0x00, DEF_STR( Off ) )\
	PORT_DIPSETTING(    0x40, DEF_STR( On ) )\
	PORT_DIPNAME( 0x80, 0x00, DEF_STR( Cabinet ) )\
	PORT_DIPSETTING(    0x00, DEF_STR( Upright ) )\
	PORT_DIPSETTING(    0x80, DEF_STR( Cocktail ) )

INPUT_PORTS_START( tsamurai )
TS_IN0
TS_IN1
TS_IN2
TS_DSW1

	PORT_START_TAG("DSW2")
	PORT_DIPNAME( 0x03, 0x00, DEF_STR( Lives ) )
	PORT_DIPSETTING(    0x00, "3" )
	PORT_DIPSETTING(    0x01, "5" )
	PORT_DIPSETTING(    0x02, "7" )
	PORT_DIPSETTING(    0x03, "254 (Cheat)")
	PORT_DIPNAME( 0x0c, 0x0c, "DSW2 Unknown 1" )
	PORT_DIPSETTING(    0x00, "00" )
	PORT_DIPSETTING(    0x04, "30" )
	PORT_DIPSETTING(    0x08, "50" )
	PORT_DIPSETTING(    0x0c, "70" )
	PORT_DIPNAME( 0x30, 0x30, "DSW2 Unknown 2" )
	PORT_DIPSETTING(    0x00, "0x00" )
	PORT_DIPSETTING(    0x10, "0x01" )
	PORT_DIPSETTING(    0x20, "0x02" )
	PORT_DIPSETTING(    0x30, "0x03" )
	PORT_DIPNAME( 0x40, 0x40, DEF_STR( Demo_Sounds ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x40, DEF_STR( On ) )
	PORT_DIPNAME( 0x80, 0x80, "DSW2 Unknown 3" )
	PORT_DIPSETTING(    0x00, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x80, DEF_STR( On ) )
INPUT_PORTS_END

INPUT_PORTS_START( nunchaku )
TS_IN0
TS_IN1
TS_IN2
TS_DSW1

	PORT_START_TAG("DSW2")
	PORT_DIPNAME( 0x03, 0x00, DEF_STR( Lives ) )
	PORT_DIPSETTING(    0x00, "3" )
	PORT_DIPSETTING(    0x01, "5" )
	PORT_DIPSETTING(    0x02, "7" )
	PORT_DIPSETTING(    0x03, "255 (Cheat)")
	PORT_DIPNAME( 0x0c, 0x0c, "DSW2 Unknown 1" )
	PORT_DIPSETTING(    0x00, "00" )
	PORT_DIPSETTING(    0x04, "30" )
	PORT_DIPSETTING(    0x08, "50" )
	PORT_DIPSETTING(    0x0c, "70" )
	PORT_DIPNAME( 0x30, 0x30, "DSW2 Unknown 2" )
	PORT_DIPSETTING(    0x00, "0x00" )
	PORT_DIPSETTING(    0x10, "0x01" )
	PORT_DIPSETTING(    0x20, "0x02" )
	PORT_DIPSETTING(    0x30, "0x03" )
	PORT_DIPNAME( 0x40, 0x40, "DSW2 Unknown 3" )
	PORT_DIPSETTING(    0x00, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x40, DEF_STR( On ) )
	PORT_DIPNAME( 0x80, 0x80, "DSW2 Unknown 4" )
	PORT_DIPSETTING(    0x00, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x80, DEF_STR( On ) )
INPUT_PORTS_END

INPUT_PORTS_START( vsgongf )
TS_IN0
TS_IN1
TS_IN2
TS_DSW1

	PORT_START_TAG("DSW1")
	PORT_DIPNAME( 0x01, 0x00, DEF_STR( Unknown ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x01, DEF_STR( On ) )
	PORT_DIPNAME( 0x02, 0x00, DEF_STR( Unknown ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x02, DEF_STR( On ) )
	PORT_DIPNAME( 0x04, 0x00, DEF_STR( Unknown ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x04, DEF_STR( On ) )
	PORT_DIPNAME( 0x08, 0x00, DEF_STR( Unknown ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x08, DEF_STR( On ) )
	PORT_DIPNAME( 0x10, 0x00, DEF_STR( Unknown ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x10, DEF_STR( On ) )
	PORT_DIPNAME( 0x20, 0x00, DEF_STR( Unknown ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x20, DEF_STR( On ) )
	PORT_DIPNAME( 0x40, 0x00, DEF_STR( Unknown ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x40, DEF_STR( On ) )
	PORT_DIPNAME( 0x80, 0x00, DEF_STR( Unknown ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x80, DEF_STR( On ) )
INPUT_PORTS_END

#define YAMINS\
	PORT_START_TAG("IN0")\
	PORT_BIT( 0x01, IP_ACTIVE_HIGH, IPT_JOYSTICK_RIGHT ) PORT_8WAY\
	PORT_BIT( 0x02, IP_ACTIVE_HIGH, IPT_JOYSTICK_LEFT ) PORT_8WAY\
	PORT_BIT( 0x04, IP_ACTIVE_HIGH, IPT_JOYSTICK_UP ) PORT_8WAY\
	PORT_BIT( 0x08, IP_ACTIVE_HIGH, IPT_JOYSTICK_DOWN ) PORT_8WAY\
	PORT_BIT( 0x10, IP_ACTIVE_HIGH, IPT_BUTTON2 )\
	PORT_BIT( 0x20, IP_ACTIVE_HIGH, IPT_BUTTON1 )\
	PORT_BIT( 0x40, IP_ACTIVE_HIGH, IPT_UNKNOWN )\
	PORT_BIT( 0x80, IP_ACTIVE_HIGH, IPT_UNKNOWN )\
	PORT_START_TAG("IN1")\
	PORT_BIT( 0x01, IP_ACTIVE_HIGH, IPT_JOYSTICK_RIGHT ) PORT_8WAY PORT_COCKTAIL\
	PORT_BIT( 0x02, IP_ACTIVE_HIGH, IPT_JOYSTICK_LEFT ) PORT_8WAY PORT_COCKTAIL\
	PORT_BIT( 0x04, IP_ACTIVE_HIGH, IPT_JOYSTICK_UP ) PORT_8WAY PORT_COCKTAIL\
	PORT_BIT( 0x08, IP_ACTIVE_HIGH, IPT_JOYSTICK_DOWN ) PORT_8WAY PORT_COCKTAIL\
	PORT_BIT( 0x10, IP_ACTIVE_HIGH, IPT_BUTTON2 ) PORT_COCKTAIL\
	PORT_BIT( 0x20, IP_ACTIVE_HIGH, IPT_BUTTON1 ) PORT_COCKTAIL\
	PORT_BIT( 0x40, IP_ACTIVE_HIGH, IPT_UNKNOWN )\
	PORT_BIT( 0x80, IP_ACTIVE_HIGH, IPT_UNKNOWN )

INPUT_PORTS_START( yamagchi )
	YAMINS
	TS_IN2
	TS_DSW1

	PORT_START_TAG("DSW2")
	PORT_DIPNAME( 0x03, 0x00, DEF_STR( Lives ) )
	PORT_DIPSETTING(    0x00, "3" )
	PORT_DIPSETTING(    0x01, "5" )
	PORT_DIPSETTING(    0x02, "7" )
	PORT_DIPSETTING(    0x03, "255 (Cheat)")
	PORT_DIPNAME( 0x0c, 0x0c, "DSW2 Unknown 1" )
	PORT_DIPSETTING(    0x00, "00" )
	PORT_DIPSETTING(    0x04, "30" )
	PORT_DIPSETTING(    0x08, "50" )
	PORT_DIPSETTING(    0x0c, "70" )
	PORT_DIPNAME( 0x10, 0x10, DEF_STR( Language ) )
	PORT_DIPSETTING(    0x10, DEF_STR( English ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Japanese ) )
	PORT_DIPNAME( 0x20, 0x20, "DSW2 Unknown 2" )
	PORT_DIPSETTING(    0x00, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x20, DEF_STR( On ) )
	PORT_DIPNAME( 0x40, 0x40, DEF_STR( Demo_Sounds ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x40, DEF_STR( On ) )
	PORT_DIPNAME( 0x80, 0x80, "DSW2 Unknown 3" )
	PORT_DIPSETTING(    0x00, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x80, DEF_STR( On ) )
INPUT_PORTS_END

INPUT_PORTS_START( m660 )
	YAMINS
	TS_IN2

	PORT_START_TAG("DSW1")
	PORT_DIPNAME( 0x07, 0x00, DEF_STR( Coin_A ) )
	PORT_DIPSETTING(    0x04, DEF_STR( 5C_1C ) )
	PORT_DIPSETTING(    0x03, DEF_STR( 4C_1C ) )
	PORT_DIPSETTING(    0x02, DEF_STR( 3C_1C ) )
	PORT_DIPSETTING(    0x01, DEF_STR( 2C_1C ) )
	PORT_DIPSETTING(    0x00, DEF_STR( 1C_1C ) )
	PORT_DIPSETTING(    0x07, DEF_STR( 2C_3C ) )
	PORT_DIPSETTING(    0x05, DEF_STR( 1C_2C ) )
	PORT_DIPSETTING(    0x06, DEF_STR( 1C_3C ) )
	PORT_DIPNAME( 0x38, 0x00, DEF_STR( Coin_B ) )
	PORT_DIPSETTING(    0x20, DEF_STR( 5C_1C ) )
	PORT_DIPSETTING(    0x18, DEF_STR( 4C_1C ) )
	PORT_DIPSETTING(    0x10, DEF_STR( 3C_1C ) )
	PORT_DIPSETTING(    0x08, DEF_STR( 2C_1C ) )
	PORT_DIPSETTING(    0x00, DEF_STR( 1C_1C ) )
	PORT_DIPSETTING(    0x38, DEF_STR( 2C_3C ) )
	PORT_DIPSETTING(    0x28, DEF_STR( 1C_2C ) )
	PORT_DIPSETTING(    0x30, DEF_STR( 1C_3C ) )
	PORT_DIPNAME( 0x40, 0x00, "Freeze" )
	PORT_DIPSETTING(    0x00, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x40, DEF_STR( On ) )
	PORT_DIPNAME( 0x80, 0x00, DEF_STR( Continues ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x80, DEF_STR( On ) )

	PORT_START_TAG("DSW2")
	PORT_DIPNAME( 0x03, 0x00, DEF_STR( Lives ) )
	PORT_DIPSETTING(    0x00, "3" )
	PORT_DIPSETTING(    0x01, "4" )
	PORT_DIPSETTING(    0x02, "5" )
	PORT_DIPSETTING(    0x03, "6" )
	PORT_DIPNAME( 0x0c, 0x0c, "Bonus" )
	PORT_DIPSETTING(    0x00, "10,30,50" )
	PORT_DIPSETTING(    0x04, "20,50,80" )
	PORT_DIPSETTING(    0x08, "30,70,110" )
	PORT_DIPSETTING(    0x0c, "50,100,150" )
	PORT_DIPNAME( 0x30, 0x30, DEF_STR( Difficulty ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Easy ) )
	PORT_DIPSETTING(    0x10, DEF_STR( Normal ) )
	PORT_DIPSETTING(    0x20, DEF_STR( Hard ) )
	PORT_DIPSETTING(    0x30, DEF_STR( Very_Hard ) )
	PORT_DIPNAME( 0x40, 0x00, DEF_STR( Cabinet ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Upright ) )
	PORT_DIPSETTING(    0x40, DEF_STR( Cocktail ) )
	PORT_DIPNAME( 0x80, 0x80, DEF_STR( Unused ) ) /* listed as screen flip (hardware) */
	PORT_DIPSETTING(    0x00, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x80, DEF_STR( On ) )
INPUT_PORTS_END




GAME( 1984, vsgongf,  0,        vsgongf,  vsgongf,  0, ROT90, "Kaneko", "VS Gong Fight", GAME_IMPERFECT_COLORS )
GAME( 1984, ringfgt,  vsgongf,  vsgongf,  vsgongf,  0, ROT90, "Taito", "Ring Fighter (set 1)", 0 )
GAME( 1984, ringfgt2, vsgongf,  vsgongf,  vsgongf,  0, ROT90, "Taito", "Ring Fighter (set 2)", 0 )
GAME( 1985, tsamurai, 0,        tsamurai, tsamurai, 0, ROT90, "Taito", "Samurai Nihon-ichi (set 1)", 0 )
GAME( 1985, tsamura2, tsamurai, tsamurai, tsamurai, 0, ROT90, "Taito", "Samurai Nihon-ichi (set 2)", 0 )
GAME( 1985, nunchaku, 0,        tsamurai, nunchaku, 0, ROT90, "Taito", "Nunchackun", GAME_IMPERFECT_COLORS )
GAME( 1985, yamagchi, 0,        tsamurai, yamagchi, 0, ROT90, "Taito", "Go Go Mr. Yamaguchi / Yuke Yuke Yamaguchi-kun", GAME_IMPERFECT_COLORS )

GAME( 1986, m660,     0,        m660,     m660,     0, ROT90, "[Woodplace Inc.] Taito America Corporation", "Mission 660 (US)", 0 )
GAME( 1986, m660j,    m660,     m660,     m660,     0, ROT90, "[Woodplace Inc.] Taito Corporation", "Mission 660 (Japan)", 0 )
GAME( 1986, m660b,    m660,     m660,     m660,     0, ROT90, "bootleg", "Mission 660 (bootleg)", 0 )
GAME( 1986, alphaxz,  m660,     m660,     m660,     0, ROT90, "Ed / Woodplace Inc.", "The Alphax Z (Japan)", 0 )
