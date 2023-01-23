# MAME 0.106 source snippet

#include "driver.h"
#include "kyugo.h"
#include "sound/ay8910.h"

/*************************************
 *
 *  Port definitions
 *
 *************************************/

#define START_COINS \
	PORT_BIT( 0x01, IP_ACTIVE_HIGH, IPT_COIN1 ) 	\
	PORT_BIT( 0x02, IP_ACTIVE_HIGH, IPT_COIN2 ) 	\
	PORT_BIT( 0x04, IP_ACTIVE_HIGH, IPT_SERVICE1 )	\
	PORT_BIT( 0x08, IP_ACTIVE_HIGH, IPT_START1 )	\
	PORT_BIT( 0x10, IP_ACTIVE_HIGH, IPT_START2 )

#define JOYSTICK_1 \
	PORT_BIT( 0x01, IP_ACTIVE_HIGH, IPT_JOYSTICK_LEFT ) PORT_8WAY \
	PORT_BIT( 0x02, IP_ACTIVE_HIGH, IPT_JOYSTICK_RIGHT ) PORT_8WAY \
	PORT_BIT( 0x04, IP_ACTIVE_HIGH, IPT_JOYSTICK_UP ) PORT_8WAY \
	PORT_BIT( 0x08, IP_ACTIVE_HIGH, IPT_JOYSTICK_DOWN ) PORT_8WAY \
	PORT_BIT( 0x10, IP_ACTIVE_HIGH, IPT_BUTTON1 )					\
	PORT_BIT( 0x20, IP_ACTIVE_HIGH, IPT_BUTTON2 )

#define JOYSTICK_2 \
	PORT_BIT( 0x01, IP_ACTIVE_HIGH, IPT_JOYSTICK_LEFT ) PORT_8WAY PORT_COCKTAIL	\
	PORT_BIT( 0x02, IP_ACTIVE_HIGH, IPT_JOYSTICK_RIGHT ) PORT_8WAY PORT_COCKTAIL	\
	PORT_BIT( 0x04, IP_ACTIVE_HIGH, IPT_JOYSTICK_UP ) PORT_8WAY PORT_COCKTAIL	\
	PORT_BIT( 0x08, IP_ACTIVE_HIGH, IPT_JOYSTICK_DOWN ) PORT_8WAY PORT_COCKTAIL	\
	PORT_BIT( 0x10, IP_ACTIVE_HIGH, IPT_BUTTON1 ) PORT_COCKTAIL 					\
	PORT_BIT( 0x20, IP_ACTIVE_HIGH, IPT_BUTTON2 ) PORT_COCKTAIL

#define COIN_A_B \
	PORT_DIPNAME( 0x07, 0x07, DEF_STR( Coin_A ) )		\
	PORT_DIPSETTING(    0x02, DEF_STR( 2C_1C ) )		\
	PORT_DIPSETTING(    0x01, DEF_STR( 3C_2C ) )		\
	PORT_DIPSETTING(    0x07, DEF_STR( 1C_1C ) )		\
	PORT_DIPSETTING(    0x06, DEF_STR( 1C_2C ) )		\
	PORT_DIPSETTING(    0x05, DEF_STR( 1C_3C ) )		\
	PORT_DIPSETTING(    0x04, DEF_STR( 1C_4C ) )		\
	PORT_DIPSETTING(    0x03, DEF_STR( 1C_6C ) )		\
	PORT_DIPSETTING(    0x00, DEF_STR( Free_Play ) )	\
	PORT_DIPNAME( 0x38, 0x38, DEF_STR( Coin_B ) )		\
	PORT_DIPSETTING(    0x00, DEF_STR( 5C_1C ) )		\
	PORT_DIPSETTING(    0x08, DEF_STR( 4C_1C ) )		\
	PORT_DIPSETTING(    0x10, DEF_STR( 3C_1C ) )		\
	PORT_DIPSETTING(    0x18, DEF_STR( 2C_1C ) )		\
	PORT_DIPSETTING(    0x38, DEF_STR( 1C_1C ) )		\
	PORT_DIPSETTING(    0x20, DEF_STR( 3C_4C ) )		\
	PORT_DIPSETTING(    0x30, DEF_STR( 1C_2C ) )		\
	PORT_DIPSETTING(    0x28, DEF_STR( 1C_3C ) )

#define COMMON_DSW2 \
	PORT_START_TAG("DSW2")\
	COIN_A_B\
	PORT_DIPNAME( 0x40, 0x40, DEF_STR( Unused ) )\
	PORT_DIPSETTING(    0x40, DEF_STR( Off ) )\
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )\
	PORT_DIPNAME( 0x80, 0x80, DEF_STR( Unused ) )\
	PORT_DIPSETTING(    0x80, DEF_STR( Off ) )\
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )

#define COMMON_END \
	PORT_START_TAG("IN0")\
	START_COINS\
	PORT_BIT( 0x20, IP_ACTIVE_HIGH, IPT_UNKNOWN )\
	PORT_BIT( 0x40, IP_ACTIVE_HIGH, IPT_UNKNOWN )\
	PORT_BIT( 0x80, IP_ACTIVE_HIGH, IPT_UNKNOWN )\
	PORT_START_TAG("IN1")\
	JOYSTICK_1\
	PORT_BIT( 0x40, IP_ACTIVE_HIGH, IPT_UNKNOWN )\
	PORT_BIT( 0x80, IP_ACTIVE_HIGH, IPT_UNKNOWN )\
	PORT_START_TAG("IN2")\
	JOYSTICK_2\
	PORT_BIT( 0x40, IP_ACTIVE_HIGH, IPT_UNKNOWN )\
	PORT_BIT( 0x80, IP_ACTIVE_HIGH, IPT_UNKNOWN )

INPUT_PORTS_START( gyrodine )
	PORT_START_TAG("DSW1")
	PORT_DIPNAME( 0x03, 0x03, DEF_STR( Lives ) )
	PORT_DIPSETTING(    0x03, "3" )
	PORT_DIPSETTING(    0x02, "4" )
	PORT_DIPSETTING(    0x01, "5" )
	PORT_DIPSETTING(    0x00, "6" )
	PORT_DIPNAME( 0x04, 0x04, DEF_STR( Unused ) )
	PORT_DIPSETTING(    0x04, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x08, 0x08, DEF_STR( Unused ) )
	PORT_DIPSETTING(    0x08, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x10, 0x10, DEF_STR( Difficulty ) )
	PORT_DIPSETTING(    0x10, DEF_STR( Easy ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Hard ) )
	PORT_DIPNAME( 0x20, 0x20, DEF_STR( Bonus_Life ) )
	PORT_DIPSETTING(    0x20, "20000 50000" )
	PORT_DIPSETTING(    0x00, "40000 70000" )
	PORT_DIPNAME( 0x40, 0x00, DEF_STR( Cabinet ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Upright ) )
	PORT_DIPSETTING(    0x40, DEF_STR( Cocktail ) )
	PORT_DIPNAME( 0x80, 0x80, "Freeze" )
	PORT_DIPSETTING(    0x80, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )

COMMON_DSW2
COMMON_END

INPUT_PORTS_END

INPUT_PORTS_START( sonofphx )
	PORT_START_TAG("DSW1")
	PORT_DIPNAME( 0x03, 0x03, DEF_STR( Lives ) )
	PORT_DIPSETTING(    0x03, "3" )
	PORT_DIPSETTING(    0x02, "4" )
	PORT_DIPSETTING(    0x01, "5" )
	PORT_DIPSETTING(    0x00, "6" )
	PORT_DIPNAME( 0x04, 0x04, DEF_STR( Bonus_Life ) )
	PORT_DIPSETTING(    0x04, "Every 50000" )
	PORT_DIPSETTING(    0x00, "Every 70000" )
	PORT_DIPNAME( 0x08, 0x08, "Slow Motion" )
	PORT_DIPSETTING(    0x08, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME(0x10,  0x10, "Invulnerability (Cheat)")
	PORT_DIPSETTING(    0x10, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x20, 0x20, "Sound Test" )
	PORT_DIPSETTING(    0x20, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x40, 0x00, DEF_STR( Cabinet ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Upright ) )
	PORT_DIPSETTING(    0x40, DEF_STR( Cocktail ) )
	PORT_DIPNAME( 0x80, 0x80, "Freeze" )
	PORT_DIPSETTING(    0x80, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )

	PORT_START_TAG("DSW2")
	COIN_A_B
	PORT_DIPNAME( 0xc0, 0x80, DEF_STR( Difficulty ) )
	PORT_DIPSETTING(    0xc0, DEF_STR( Easy ) )
	PORT_DIPSETTING(    0x80, DEF_STR( Normal ) )
	PORT_DIPSETTING(    0x40, DEF_STR( Hard ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Hardest ) )

COMMON_END
INPUT_PORTS_END

INPUT_PORTS_START( airwolf )
	PORT_START_TAG("DSW1")
	PORT_DIPNAME( 0x03, 0x03, DEF_STR( Lives ) )
	PORT_DIPSETTING(    0x03, "4" )
	PORT_DIPSETTING(    0x02, "5" )
	PORT_DIPSETTING(    0x01, "6" )
	PORT_DIPSETTING(    0x00, "7" )
	PORT_DIPNAME( 0x04, 0x00, DEF_STR( Allow_Continue ) )
	PORT_DIPSETTING(    0x04, DEF_STR( No ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Yes ) )
	PORT_DIPNAME( 0x08, 0x08, "Slow Motion" )
	PORT_DIPSETTING(    0x08, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x10, 0x10, "Invulnerability (Cheat)")
	PORT_DIPSETTING(    0x10, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x20, 0x20, "Sound Test" )
	PORT_DIPSETTING(    0x20, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x40, 0x00, DEF_STR( Cabinet ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Upright ) )
	PORT_DIPSETTING(    0x40, DEF_STR( Cocktail ) )
	PORT_DIPNAME( 0x80, 0x80, "Freeze" )
	PORT_DIPSETTING(    0x80, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )

COMMON_DSW2
COMMON_END
INPUT_PORTS_END

/* Same as 'airwolf', but different "Lives" Dip Switch */
INPUT_PORTS_START( skywolf )
	PORT_START_TAG("DSW1")
	PORT_DIPNAME( 0x03, 0x03, DEF_STR( Lives ) )
	PORT_DIPSETTING(    0x03, "3" )
	PORT_DIPSETTING(    0x02, "4" )
	PORT_DIPSETTING(    0x01, "5" )
	PORT_DIPSETTING(    0x00, "6" )
	PORT_DIPNAME( 0x04, 0x00, DEF_STR( Allow_Continue ) )
	PORT_DIPSETTING(    0x04, DEF_STR( No ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Yes ) )
	PORT_DIPNAME( 0x08, 0x08, "Slow Motion" )
	PORT_DIPSETTING(    0x08, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x10, 0x10, "Invulnerability (Cheat)")
	PORT_DIPSETTING(    0x10, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x20, 0x20, "Sound Test" )
	PORT_DIPSETTING(    0x20, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x40, 0x00, DEF_STR( Cabinet ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Upright ) )
	PORT_DIPSETTING(    0x40, DEF_STR( Cocktail ) )
	PORT_DIPNAME( 0x80, 0x80, "Freeze" )
	PORT_DIPSETTING(    0x80, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )

COMMON_DSW2
COMMON_END
INPUT_PORTS_END

INPUT_PORTS_START( flashgal )
	PORT_START_TAG("DSW1")
	PORT_DIPNAME( 0x03, 0x03, DEF_STR( Lives ) )
	PORT_DIPSETTING(    0x03, "3" )
	PORT_DIPSETTING(    0x02, "4" )
	PORT_DIPSETTING(    0x01, "5" )
	PORT_DIPSETTING(    0x00, "6" )
	PORT_DIPNAME( 0x04, 0x04, DEF_STR( Bonus_Life ) )
	PORT_DIPSETTING(    0x04, "Every 50000" )
	PORT_DIPSETTING(    0x00, "Every 70000" )
	PORT_DIPNAME( 0x08, 0x08, "Slow Motion" )
	PORT_DIPSETTING(    0x08, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x10, 0x00, DEF_STR( Allow_Continue ) )
	PORT_DIPSETTING(    0x10, DEF_STR( No ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Yes ) )
	PORT_DIPNAME( 0x20, 0x20, "Sound Test" )
	PORT_DIPSETTING(    0x20, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x40, 0x00, DEF_STR( Cabinet ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Upright ) )
	PORT_DIPSETTING(    0x40, DEF_STR( Cocktail ) )
	PORT_DIPNAME( 0x80, 0x80, "Freeze" )
	PORT_DIPSETTING(    0x80, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )

COMMON_DSW2
COMMON_END
INPUT_PORTS_END

INPUT_PORTS_START( srdmissn )
	PORT_START_TAG("DSW1")
	PORT_DIPNAME( 0x03, 0x03, DEF_STR( Lives ) )
	PORT_DIPSETTING(    0x03, "3" )
	PORT_DIPSETTING(    0x02, "4" )
	PORT_DIPSETTING(    0x01, "5" )
	PORT_DIPSETTING(    0x00, "6" )
	PORT_DIPNAME( 0x04, 0x04, "Bonus Life/Continue" )
	PORT_DIPSETTING(    0x04, "Every 50000/No" )
	PORT_DIPSETTING(    0x00, "Every 70000/Yes" )
	PORT_DIPNAME( 0x08, 0x08, "Slow Motion" )
	PORT_DIPSETTING(    0x08, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME(0x10,  0x10, "Invulnerability (Cheat)")
	PORT_DIPSETTING(    0x10, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x20, 0x20, "Sound Test" )
	PORT_DIPSETTING(    0x20, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x40, 0x00, DEF_STR( Cabinet ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Upright ) )
	PORT_DIPSETTING(    0x40, DEF_STR( Cocktail ) )
	PORT_DIPNAME( 0x80, 0x80, "Freeze" )
	PORT_DIPSETTING(    0x80, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )

COMMON_DSW2
COMMON_END
INPUT_PORTS_END

INPUT_PORTS_START( legend )
	PORT_START_TAG("DSW1")
	PORT_DIPNAME( 0x03, 0x03, DEF_STR( Lives ) )
	PORT_DIPSETTING(    0x03, "3" )
	PORT_DIPSETTING(    0x02, "4" )
	PORT_DIPSETTING(    0x01, "5" )
	PORT_DIPSETTING(    0x00, "6" )
	PORT_DIPNAME( 0x04, 0x04, "Bonus Life/Continue" )
	PORT_DIPSETTING(    0x04, "Every 50000/No" )
	PORT_DIPSETTING(    0x00, "Every 70000/Yes" )
	PORT_DIPNAME( 0x08, 0x08, "Slow Motion" )
	PORT_DIPSETTING(    0x08, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x10, 0x10, DEF_STR( Unknown ) )	/* probably unused */
	PORT_DIPSETTING(    0x10, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x20, 0x20, "Sound Test" )
	PORT_DIPSETTING(    0x20, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x40, 0x00, DEF_STR( Cabinet ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Upright ) )
	PORT_DIPSETTING(    0x40, DEF_STR( Cocktail ) )
	PORT_DIPNAME( 0x80, 0x80, "Freeze" )
	PORT_DIPSETTING(    0x80, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )

COMMON_DSW2
COMMON_END
INPUT_PORTS_END


/*************************************
 *
 *  Game drivers
 *
 *************************************/

GAME( 1984, gyrodine, 0,        gyrodine, gyrodine, gyrodine, ROT90, "Taito Corporation", "Gyrodine", 0 )
GAME( 1984, gyrodinc, gyrodine, gyrodine, gyrodine, gyrodine, ROT90, "Taito Corporation (Crux license)", "Gyrodine (Crux)", 0 )
GAME( 1985, sonofphx, 0,        sonofphx, sonofphx, 0,        ROT90, "Associated Overseas MFR, Inc", "Son of Phoenix", 0 )
GAME( 1985, repulse,  sonofphx, sonofphx, sonofphx, 0,        ROT90, "Sega", "Repulse", 0 )
GAME( 1985, 99lstwar, sonofphx, sonofphx, sonofphx, 0,        ROT90, "Proma", "'99: The Last War", 0 )
GAME( 1985, 99lstwra, sonofphx, sonofphx, sonofphx, 0,        ROT90, "Proma", "'99: The Last War (alternate)", 0 )
GAME( 1985, 99lstwrk, sonofphx, sonofphx, sonofphx, 0,        ROT90, "Kyugo", "'99: The Last War (Kyugo)", 0 )
GAME( 1985, flashgal, 0,        flashgal, flashgal, 0,        ROT0,  "Sega", "Flashgal (set 1)", 0 )
GAME( 1985, flashgla, flashgal, flashgla, flashgal, 0,        ROT0,  "Sega", "Flashgal (set 2)", 0 )
GAME( 1986, srdmissn, 0,        srdmissn, srdmissn, srdmissn, ROT90, "Taito Corporation", "S.R.D. Mission", 0 )
GAME( 1986, fx,       srdmissn, srdmissn, srdmissn, srdmissn, ROT90, "bootleg", "F-X", 0 )
GAME( 1986?,legend,   0,        legend,   legend,   srdmissn, ROT0,  "Sega / Coreland ?", "Legend", 0 )
GAME( 1987, airwolf,  0,        srdmissn, airwolf,  srdmissn, ROT0,  "Kyugo", "Airwolf", 0 )
GAME( 1987, skywolf,  airwolf,  srdmissn, skywolf,  srdmissn, ROT0,  "bootleg", "Sky Wolf (set 1)", 0 )
GAME( 1987, skywolf2, airwolf,  srdmissn, airwolf,  srdmissn, ROT0,  "bootleg", "Sky Wolf (set 2)", 0 )
