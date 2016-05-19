#include "emu.h"
#include "cpu/z80/z80.h"
#include "includes/taitoipt.h"
#include "cpu/mcs48/mcs48.h"
#include "sound/2203intf.h"
#include "sound/dac.h"
#include "sound/samples.h"
#include "includes/tnzs.h"
#include "sound/2151intf.h"
#include "video/seta001.h"


#define COMMON_IN2\
	PORT_START("IN2")\
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_SERVICE1 )\
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_TILT )\
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_UNKNOWN )\
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_UNKNOWN )\
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_UNKNOWN )\
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_UNKNOWN )\
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_UNKNOWN )\
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_UNKNOWN )

#define COMMON_COIN1(coinstate)\
	PORT_START("COIN1")\
	PORT_BIT( 0x01, coinstate, IPT_COIN1 )\
	PORT_BIT( 0xfe, IP_ACTIVE_HIGH, IPT_UNUSED )

#define COMMON_COIN2(coinstate)\
	PORT_START("COIN2")\
	PORT_BIT( 0x01, coinstate, IPT_COIN2 )\
	PORT_BIT( 0xfe, IP_ACTIVE_HIGH, IPT_UNUSED )


static INPUT_PORTS_START( plumppop )
	/* 0xb001 (CPU1) port 0 -> 0xef0e (shared RAM) */
	PORT_START("DSWA")
	PORT_DIPNAME( 0x01, 0x01, DEF_STR( Unknown ) )               /* code at 0x6e99 - is it ever called ? */
	PORT_DIPSETTING(    0x01, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	TAITO_DSWA_BITS_1_TO_3
	TAITO_COINAGE_JAPAN_OLD

	/* 0xb001 (CPU1) port 1 -> 0xef0f (shared RAM) */
	PORT_START("DSWB")
	TAITO_DIFFICULTY
	PORT_DIPNAME( 0x0c, 0x0c, DEF_STR( Bonus_Life ) )            /* table at 0x2b86 */
	PORT_DIPSETTING(    0x08, "50k 200k 150k+" )
	PORT_DIPSETTING(    0x0c, "50k 250k 200k+" )
	PORT_DIPSETTING(    0x04, "100k 300k 200k+" )
	PORT_DIPSETTING(    0x00, "100k 400k 300k+" )
	PORT_DIPNAME( 0x30, 0x30, DEF_STR( Lives ) )
	PORT_DIPSETTING(    0x20, "2" )
	PORT_DIPSETTING(    0x30, "3" )
	PORT_DIPSETTING(    0x10, "4" )
	PORT_DIPSETTING(    0x00, "5" )
	PORT_DIPNAME( 0x40, 0x40, DEF_STR( Unknown ) )               /* code at 0x3dcc */
	PORT_DIPSETTING(    0x40, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x80, 0x80, DEF_STR( Allow_Continue ) )
	PORT_DIPSETTING(    0x00, DEF_STR( No ) )
	PORT_DIPSETTING(    0x80, DEF_STR( Yes ) )

	PORT_START("IN0")
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_PLAYER(1)
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_BUTTON2 ) PORT_PLAYER(1) PORT_NAME("P1 Button 2 (Cheat)")
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_START1 )

	PORT_START("IN1")
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_PLAYER(2)
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_BUTTON2 ) PORT_PLAYER(2) PORT_NAME("P2 Button 2 (Cheat)")    /* not working ? */
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_START2 )

	PORT_START("IN2")
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_SERVICE1 )
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_TILT )
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x10, IP_ACTIVE_HIGH, IPT_COIN1 )
	PORT_BIT( 0x20, IP_ACTIVE_HIGH, IPT_COIN2 )
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_UNKNOWN )

	COMMON_COIN1(IP_ACTIVE_HIGH)
	COMMON_COIN2(IP_ACTIVE_HIGH)

	PORT_START("AN1")		/* spinner 1 - read at f000/1 */
	PORT_BIT( 0xffff, 0x0000, IPT_DIAL ) PORT_SENSITIVITY(70) PORT_KEYDELTA(15) PORT_PLAYER(1)

	PORT_START("AN2")		/* spinner 2 - read at f002/3 */
	PORT_BIT( 0xffff, 0x0000, IPT_DIAL ) PORT_SENSITIVITY(70) PORT_KEYDELTA(15) PORT_PLAYER(2)
INPUT_PORTS_END


static INPUT_PORTS_START( extrmatn )
	/* 0xb001 (CPU1) port 0 -> 0xef0e (shared RAM) */
	PORT_START("DSWA")
	PORT_DIPUNUSED( 0x01, IP_ACTIVE_LOW )
	PORT_DIPNAME( 0x02, 0x02, DEF_STR( Flip_Screen ) )
	PORT_DIPSETTING(    0x02, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_SERVICE( 0x04, IP_ACTIVE_LOW )
	PORT_DIPUNUSED( 0x08, IP_ACTIVE_LOW )
	TAITO_COINAGE_JAPAN_OLD

	/* 0xb001 (CPU1) port 1 -> 0xef0f (shared RAM) */
	PORT_START("DSWB")
	TAITO_DIFFICULTY
	PORT_DIPUNUSED( 0x04, IP_ACTIVE_LOW )
	PORT_DIPUNUSED( 0x08, IP_ACTIVE_LOW )
	PORT_DIPUNUSED( 0x10, IP_ACTIVE_LOW )
	PORT_DIPUNUSED( 0x20, IP_ACTIVE_LOW )
	PORT_DIPNAME( 0xc0, 0xc0, "Damage Multiplier" )
	PORT_DIPSETTING(    0xc0, "*1" )
	PORT_DIPSETTING(    0x80, "*1.5" )
	PORT_DIPSETTING(    0x40, "*2" )
	PORT_DIPSETTING(    0x00, "*3" )

	PORT_START("IN0")
	TAITO_JOY_LRUD_2_BUTTONS_START( 1 )

	PORT_START("IN1")
	TAITO_JOY_LRUD_2_BUTTONS_START( 2 )

	COMMON_IN2
	COMMON_COIN1(IP_ACTIVE_HIGH)
	COMMON_COIN2(IP_ACTIVE_HIGH)
INPUT_PORTS_END


static INPUT_PORTS_START( arknoid2 )
	/* 0xb001 (CPU1) port 0 -> 0xe001 (shared RAM) */
	PORT_START("DSWA")
	TAITO_MACHINE_COCKTAIL
	TAITO_COINAGE_WORLD

	/* 0xb001 (CPU1) port 1 -> 0xe002 (shared RAM) */
	PORT_START("DSWB")
	TAITO_DIFFICULTY
	PORT_DIPNAME( 0x0c, 0x0c, DEF_STR( Bonus_Life ) )            /* table at 0x6f1e (W and J) or 0x6f1b (Romstar) */
	PORT_DIPSETTING(    0x00, "50k 150k 150k+" )
	PORT_DIPSETTING(    0x0c, "100k 200k 200k+" )
	PORT_DIPSETTING(    0x04, "50k only" )
	PORT_DIPSETTING(    0x08, "100k only" )
	PORT_DIPNAME( 0x30, 0x30, DEF_STR( Lives ) )
	PORT_DIPSETTING(    0x20, "2" )
	PORT_DIPSETTING(    0x30, "3" )
	PORT_DIPSETTING(    0x10, "4" )
	PORT_DIPSETTING(    0x00, "5" )
	PORT_DIPUNUSED( 0x40, IP_ACTIVE_LOW )
	PORT_DIPNAME( 0x80, 0x00, DEF_STR( Allow_Continue ) )
	PORT_DIPSETTING(    0x80, DEF_STR( No ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Yes ) )

	PORT_START("IN0")		/* read at c000 (sound cpu) */
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_PLAYER(2)
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_START2 )
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_BUTTON1 )
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_START1 )

	PORT_START("IN1")
	PORT_BIT( 0xff, IP_ACTIVE_LOW, IPT_UNUSED )

	COMMON_IN2
	COMMON_COIN1(IP_ACTIVE_HIGH)
	COMMON_COIN2(IP_ACTIVE_HIGH)

	PORT_START("AN1")		/* spinner 1 - read at f000/1 */
	PORT_BIT   ( 0x0fff, 0x0000, IPT_DIAL ) PORT_SENSITIVITY(70) PORT_KEYDELTA(15)
	PORT_BIT   ( 0x1000, IP_ACTIVE_LOW,  IPT_COIN2 )	/* Mirrored for service mode */
	PORT_BIT   ( 0x2000, IP_ACTIVE_HIGH, IPT_SERVICE1 )	/* Mirrored for service mode */
	PORT_BIT   ( 0x4000, IP_ACTIVE_LOW,  IPT_COIN1 )	/* Mirrored for service mode */
	PORT_BIT   ( 0x8000, IP_ACTIVE_LOW,  IPT_UNKNOWN )

	PORT_START("AN2")		/* spinner 2 - read at f002/3 */
	PORT_BIT   ( 0x0fff, 0x0000, IPT_DIAL ) PORT_SENSITIVITY(70) PORT_KEYDELTA(15) PORT_PLAYER(2)
	PORT_BIT   ( 0xf000, IP_ACTIVE_LOW,  IPT_UNKNOWN )
INPUT_PORTS_END

static INPUT_PORTS_START( arknid2u )
	PORT_INCLUDE( arknoid2 )

	PORT_MODIFY("DSWA")
	TAITO_COINAGE_JAPAN_OLD
INPUT_PORTS_END


static INPUT_PORTS_START( drtoppel )
	/* 0xb001 (CPU1) port 0 -> 0xe042 (shared RAM) */
	PORT_START("DSWA")
	TAITO_MACHINE_COCKTAIL
	TAITO_COINAGE_WORLD

	/* 0xb001 (CPU1) port 1 -> 0xe043 (shared RAM) */
	PORT_START("DSWB")
	TAITO_DIFFICULTY
	PORT_DIPNAME( 0x0c, 0x0c, DEF_STR( Bonus_Life ) )            /* table at 0x256d (4 * 9 bytes) */
	PORT_DIPSETTING(    0x0c, "30k 100k 200k 100k+" )            /* 30k  100k  200k  300k  400k  500k  600k  700k */
	PORT_DIPSETTING(    0x00, "50k 100k 200k 200k+" )            /* 50k  100k  200k  400k  600k  800k 1000k 1200k */
	PORT_DIPSETTING(    0x04, "30k 100k" )
	PORT_DIPSETTING(    0x08, "30k only" )
	PORT_DIPNAME( 0x30, 0x30, DEF_STR( Lives ) )
	PORT_DIPSETTING(    0x20, "2" )
	PORT_DIPSETTING(    0x30, "3" )
	PORT_DIPSETTING(    0x10, "4" )
	PORT_DIPSETTING(    0x00, "5" )
	PORT_DIPUNUSED( 0x40, IP_ACTIVE_LOW )
	PORT_DIPUNUSED( 0x80, IP_ACTIVE_LOW )

	PORT_START("IN0")
	TAITO_JOY_LRUD_2_BUTTONS_START( 1 )

	PORT_START("IN1")
	TAITO_JOY_LRUD_2_BUTTONS_START( 2 )

	COMMON_IN2
	COMMON_COIN1(IP_ACTIVE_HIGH)
	COMMON_COIN2(IP_ACTIVE_HIGH)
INPUT_PORTS_END

static INPUT_PORTS_START( drtopplu )
	PORT_INCLUDE( drtoppel )

	PORT_MODIFY("DSWA")
	TAITO_COINAGE_JAPAN_OLD
INPUT_PORTS_END


static INPUT_PORTS_START( kageki )
	/* special (see kageki_csport_* handlers) -> 0xe03b (shared RAM) */
	PORT_START("DSWA")
	TAITO_MACHINE_NO_COCKTAIL                                    /* see notes */
	TAITO_COINAGE_JAPAN_OLD

	/* special (see kageki_csport_* handlers) -> 0xe03c (shared RAM) */
	PORT_START("DSWB")
	TAITO_DIFFICULTY
	PORT_DIPUNUSED( 0x04, IP_ACTIVE_LOW )
	PORT_DIPUNUSED( 0x08, IP_ACTIVE_LOW )
	PORT_DIPUNUSED( 0x10, IP_ACTIVE_LOW )
	PORT_DIPUNUSED( 0x20, IP_ACTIVE_LOW )
	PORT_DIPUNUSED( 0x40, IP_ACTIVE_LOW )
	PORT_DIPNAME( 0x80, 0x80, DEF_STR( Allow_Continue ) )
	PORT_DIPSETTING(    0x00, DEF_STR( No ) )
	PORT_DIPSETTING(    0x80, DEF_STR( Yes ) )

	PORT_START("IN0")
	TAITO_JOY_LRUD_2_BUTTONS_START( 1 )

	PORT_START("IN1")
	TAITO_JOY_LRUD_2_BUTTONS_START( 2 )

	PORT_START("IN2")
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_SERVICE1 )
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_TILT )
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_COIN1 )
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_COIN2 )
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_UNKNOWN )
INPUT_PORTS_END

static INPUT_PORTS_START( kagekij )
	PORT_INCLUDE( kageki )

	PORT_MODIFY("DSWA")
	TAITO_MACHINE_COCKTAIL                                       /* see notes */
INPUT_PORTS_END


static INPUT_PORTS_START( chukatai )
	/* 0xb001 (CPU1) port 0 -> 0xe015 (shared RAM) */
	PORT_START("DSWA")
	TAITO_MACHINE_COCKTAIL
	TAITO_COINAGE_WORLD

	/* 0xb001 (CPU1) port 1 -> 0xe016 (shared RAM) */
	PORT_START("DSWB")
	TAITO_DIFFICULTY
	PORT_DIPNAME( 0x0c, 0x0c, DEF_STR( Bonus_Life ) )            /* tables : 1st at 0xb070 (bank = 0x02) and inc. at 0x09df */
	PORT_DIPSETTING(    0x08, "40k 240k 200k+" )
	PORT_DIPSETTING(    0x0c, "60k 360k 300k+" )
	PORT_DIPSETTING(    0x04, "100k 500k 400k+" )
	PORT_DIPSETTING(    0x00, "150k 650k 500k+" )
	PORT_DIPNAME( 0x30, 0x30, DEF_STR( Lives ) )
	PORT_DIPSETTING(    0x00, "1" )
	PORT_DIPSETTING(    0x10, "2" )
	PORT_DIPSETTING(    0x30, "3" )
	PORT_DIPSETTING(    0x20, "4" )
	PORT_DIPUNUSED( 0x40, IP_ACTIVE_LOW )
	PORT_DIPUNUSED( 0x80, IP_ACTIVE_LOW )

	PORT_START("IN0")
	TAITO_JOY_LRUD_2_BUTTONS_START( 1 )

	PORT_START("IN1")
	TAITO_JOY_LRUD_2_BUTTONS_START( 2 )

	COMMON_IN2
	COMMON_COIN1(IP_ACTIVE_HIGH)
	COMMON_COIN2(IP_ACTIVE_HIGH)
INPUT_PORTS_END

static INPUT_PORTS_START( chukatau )
	PORT_INCLUDE( chukatai )

	PORT_MODIFY("DSWA")
	TAITO_COINAGE_JAPAN_OLD
INPUT_PORTS_END


static INPUT_PORTS_START( tnzs )
	/* 0xb002 (CPU1) -> 0xef0e (shared RAM) */
	PORT_START("DSWA")
	PORT_DIPNAME( 0x01, 0x00, DEF_STR( Cabinet ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Upright ) )
	PORT_DIPSETTING(    0x01, DEF_STR( Cocktail ) )
	PORT_DIPNAME( 0x02, 0x02, DEF_STR( Flip_Screen ) )
	PORT_DIPSETTING(    0x02, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_SERVICE( 0x04, IP_ACTIVE_LOW )
	PORT_DIPNAME( 0x08, 0x08, "Invulnerability (Debug)" )        // see notes
	PORT_DIPSETTING(    0x08, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	TAITO_COINAGE_WORLD

	/* 0xb003 (CPU1) -> 0xef0f (shared RAM) */
	PORT_START("DSWB")
	TAITO_DIFFICULTY
	PORT_DIPNAME( 0x0c, 0x0c, DEF_STR( Bonus_Life ) )            /* table at 0x09c84 */
	PORT_DIPSETTING(    0x00, "50k 150k 150k+" )
	PORT_DIPSETTING(    0x0c, "70k 200k 200k+" )
	PORT_DIPSETTING(    0x04, "100k 250k 250k+" )
	PORT_DIPSETTING(    0x08, "200k 300k 300k+" )
	PORT_DIPNAME( 0x30, 0x30, DEF_STR( Lives ) )
	PORT_DIPSETTING(    0x20, "2" )
	PORT_DIPSETTING(    0x30, "3" )
	PORT_DIPSETTING(    0x00, "4" )
	PORT_DIPSETTING(    0x10, "5" )
	PORT_DIPNAME( 0x40, 0x40, DEF_STR( Allow_Continue ) )
	PORT_DIPSETTING(    0x00, DEF_STR( No ) )
	PORT_DIPSETTING(    0x40, DEF_STR( Yes ) )
	PORT_DIPUNUSED( 0x80, IP_ACTIVE_LOW )

	PORT_START("IN0")
	TAITO_JOY_LRUD_2_BUTTONS_START( 1 )

	PORT_START("IN1")
	TAITO_JOY_LRUD_2_BUTTONS_START( 2 )

	PORT_START("IN2")
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_SERVICE1 )
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_TILT )
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_COIN1 )
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_COIN2 )
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_UNKNOWN )
INPUT_PORTS_END

static INPUT_PORTS_START( tnzsj )
	PORT_INCLUDE( tnzs )

	PORT_MODIFY("DSWA")
	TAITO_COINAGE_JAPAN_OLD
INPUT_PORTS_END

static INPUT_PORTS_START( tnzsjo )
	/* 0xb001 (CPU1) port 0 -> 0xef0e (shared RAM) */
	PORT_START("DSWA")
	PORT_DIPNAME( 0x01, 0x00, DEF_STR( Cabinet ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Upright ) )
	PORT_DIPSETTING(    0x01, DEF_STR( Cocktail ) )
	PORT_DIPNAME( 0x02, 0x02, DEF_STR( Flip_Screen ) )
	PORT_DIPSETTING(    0x02, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_SERVICE( 0x04, IP_ACTIVE_LOW )
	PORT_DIPNAME( 0x08, 0x08, "Invulnerability (Debug)" )	// see notes
	PORT_DIPSETTING(    0x08, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	TAITO_COINAGE_JAPAN_OLD

	/* 0xb001 (CPU1) port 1 -> 0xef0f (shared RAM) */
	PORT_START("DSWB")
	TAITO_DIFFICULTY
	PORT_DIPNAME( 0x0c, 0x0c, DEF_STR( Bonus_Life ) )            /* table at 0x09caf */
	PORT_DIPSETTING(    0x00, "50k 150k 150k+" )
	PORT_DIPSETTING(    0x0c, "70k 200k 200k+" )
	PORT_DIPSETTING(    0x04, "100k 250k 250k+" )
	PORT_DIPSETTING(    0x08, "200k 300k 300k+" )
	PORT_DIPNAME( 0x30, 0x30, DEF_STR( Lives ) )
	PORT_DIPSETTING(    0x20, "2" )
	PORT_DIPSETTING(    0x30, "3" )
	PORT_DIPSETTING(    0x00, "4" )
	PORT_DIPSETTING(    0x10, "5" )
	PORT_DIPNAME( 0x40, 0x40, DEF_STR( Allow_Continue ) )
	PORT_DIPSETTING(    0x00, DEF_STR( No ) )
	PORT_DIPSETTING(    0x40, DEF_STR( Yes ) )
	PORT_DIPUNUSED( 0x80, IP_ACTIVE_LOW )

	PORT_START("IN0")
	TAITO_JOY_LRUD_2_BUTTONS_START( 1 )

	PORT_START("IN1")
	TAITO_JOY_LRUD_2_BUTTONS_START( 2 )

	COMMON_IN2
	COMMON_COIN1(IP_ACTIVE_LOW)
	COMMON_COIN2(IP_ACTIVE_LOW)
INPUT_PORTS_END

static INPUT_PORTS_START( tnzsop )
	PORT_INCLUDE( tnzsjo )

	PORT_MODIFY("DSWA")
	PORT_DIPUNUSED( 0x08, IP_ACTIVE_LOW )                        /* value read at 0x356b but not tested nor stored elsewhere */
	TAITO_COINAGE_WORLD

	PORT_MODIFY("DSWB")
	PORT_DIPNAME( 0x0c, 0x0c, DEF_STR( Bonus_Life ) )            /* table at 0x09afb */
	PORT_DIPSETTING(    0x00, "10k 100k 100k+" )
	PORT_DIPSETTING(    0x0c, "10k 150k 150k+" )
	PORT_DIPSETTING(    0x04, "10k 200k 200k+" )
	PORT_DIPSETTING(    0x08, "10k 300k 300k+" )
INPUT_PORTS_END


static INPUT_PORTS_START( kabukiz )
	/* 0xb002 (CPU1) */
	PORT_START("DSWA")
	TAITO_MACHINE_COCKTAIL
	PORT_DIPUNUSED( 0x10, IP_ACTIVE_LOW )
	PORT_DIPUNUSED( 0x20, IP_ACTIVE_LOW )
	PORT_DIPUNUSED( 0x40, IP_ACTIVE_LOW )
	PORT_DIPNAME( 0x80, 0x80, DEF_STR( Allow_Continue ) )
	PORT_DIPSETTING(    0x00, DEF_STR( No ) )
	PORT_DIPSETTING(    0x80, DEF_STR( Yes ) )

	/* 0xb003 (CPU1) */
	PORT_START("DSWB")
	TAITO_DIFFICULTY
	PORT_DIPUNUSED( 0x04, IP_ACTIVE_LOW )
	PORT_DIPUNUSED( 0x08, IP_ACTIVE_LOW )
	TAITO_COINAGE_WORLD

	PORT_START("IN0")
	TAITO_JOY_LRUD_2_BUTTONS_START( 1 )

	PORT_START("IN1")
	TAITO_JOY_LRUD_2_BUTTONS_START( 2 )

	PORT_START("IN2")
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_SERVICE1 )
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_COIN1 )
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_COIN2 )
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_UNKNOWN )
INPUT_PORTS_END

static INPUT_PORTS_START( kabukizj )
	PORT_INCLUDE( kabukiz )

	PORT_MODIFY("DSWB")
	TAITO_COINAGE_JAPAN_OLD
INPUT_PORTS_END


static INPUT_PORTS_START( insectx )
	/* 0xb001 (CPU1) port 0 -> 0xec06 (shared RAM) */
	PORT_START("DSWA")
	TAITO_MACHINE_COCKTAIL
	TAITO_COINAGE_WORLD

	/* 0xb001 (CPU1) port 1 -> 0xec07 (shared RAM) */
	PORT_START("DSWB")
	PORT_DIPNAME( 0x03, 0x03, DEF_STR( Difficulty ) )            /* see notes */
	PORT_DIPSETTING(    0x01, DEF_STR( Easy ) )
	PORT_DIPSETTING(    0x03, DEF_STR( Medium ) )
	PORT_DIPSETTING(    0x02, DEF_STR( Hard ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Hardest ) )
	PORT_DIPNAME( 0x0c, 0x0c, DEF_STR( Bonus_Life ) )            /* code at 0xaacc - bank = 0x02 */
	PORT_DIPSETTING(    0x08, "40k 240k 200k+" )
	PORT_DIPSETTING(    0x0c, "60k 360k 300k+" )
	PORT_DIPSETTING(    0x04, "100k 500k 400k+" )
	PORT_DIPSETTING(    0x00, "150k 650k 500k+" )
	PORT_DIPNAME( 0x30, 0x30, DEF_STR( Lives ) )
	PORT_DIPSETTING(    0x00, "1" )
	PORT_DIPSETTING(    0x10, "2" )
	PORT_DIPSETTING(    0x30, "3" )
	PORT_DIPSETTING(    0x20, "4" )
	PORT_DIPUNUSED( 0x40, IP_ACTIVE_LOW )
	PORT_DIPUNUSED( 0x80, IP_ACTIVE_LOW )

	PORT_START("IN0")
	TAITO_JOY_LRUD_2_BUTTONS_START( 1 )

	PORT_START("IN1")
	TAITO_JOY_LRUD_2_BUTTONS_START( 2 )

	PORT_START("IN2")
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_SERVICE1 )
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_TILT )
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_COIN2 )
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_COIN1 )
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_UNKNOWN )
INPUT_PORTS_END

static INPUT_PORTS_START( insectxj )
	PORT_INCLUDE( insectx )

	PORT_MODIFY("DSWA")
	TAITO_COINAGE_JAPAN_OLD
INPUT_PORTS_END


static INPUT_PORTS_START( jpopnics )
	/* 0xc600 (CPU1) -> 0xef0e (shared RAM) */
	PORT_START("DSWA")
	PORT_DIPNAME( 0x01, 0x01, DEF_STR( Unknown ) )               /* code at 0x6e99 - is it ever called ? */
	PORT_DIPSETTING(    0x01, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	TAITO_DSWA_BITS_1_TO_3
	PORT_DIPUNUSED( 0x10, IP_ACTIVE_LOW )                        /* see notes */
	PORT_DIPUNUSED( 0x20, IP_ACTIVE_LOW )                        /* see notes */
	PORT_DIPUNUSED( 0x40, IP_ACTIVE_LOW )                        /* see notes */
	PORT_DIPUNUSED( 0x80, IP_ACTIVE_LOW )                        /* see notes */

	/* 0xc601 (CPU1) -> 0xef0f (shared RAM) */
	PORT_START("DSWB")
	TAITO_DIFFICULTY
	PORT_DIPNAME( 0x0c, 0x0c, DEF_STR( Bonus_Life ) )            /* table at 0x2b86 */
	PORT_DIPSETTING(    0x08, "50k 200k 150k+" )
	PORT_DIPSETTING(    0x0c, "50k 250k 200k+" )
	PORT_DIPSETTING(    0x04, "100k 300k 200k+" )
	PORT_DIPSETTING(    0x00, "100k 400k 300k+" )
	PORT_DIPNAME( 0x30, 0x30, DEF_STR( Lives ) )
	PORT_DIPSETTING(    0x20, "2" )
	PORT_DIPSETTING(    0x30, "3" )
	PORT_DIPSETTING(    0x10, "4" )
	PORT_DIPSETTING(    0x00, "5" )
	PORT_DIPNAME( 0x40, 0x40, DEF_STR( Unknown ) )               /* code at 0x3dcc */
	PORT_DIPSETTING(    0x40, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x80, 0x80, DEF_STR( Allow_Continue ) )
	PORT_DIPSETTING(    0x00, DEF_STR( No ) )
	PORT_DIPSETTING(    0x80, DEF_STR( Yes ) )

	PORT_START("IN0")
	PORT_BIT( 0xff, IP_ACTIVE_LOW, IPT_UNUSED )

	PORT_START("IN1")
	PORT_BIT( 0x0f, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_PLAYER(1)
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_BUTTON2 ) PORT_PLAYER(1) PORT_NAME("P1 Button 2 (Cheat)")
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_COIN1 )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_START1 )

	PORT_START("IN2")
	PORT_BIT( 0x0f, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_PLAYER(2)
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_BUTTON2 ) PORT_PLAYER(2) PORT_NAME("P2 Button 2 (Cheat)")    /* not working ? */
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_COIN2 )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_START2 )

	PORT_START("COIN1")
	PORT_BIT( 0xff, IP_ACTIVE_LOW, IPT_UNUSED )

	PORT_START("COIN2")
	PORT_BIT( 0xff, IP_ACTIVE_LOW, IPT_UNUSED )

	PORT_START("AN1")		/* spinner 1 - read at f000/1 */
	PORT_BIT( 0xffff, 0x0000, IPT_DIAL ) PORT_SENSITIVITY(70) PORT_KEYDELTA(15) PORT_PLAYER(1)

	PORT_START("AN2")		/* spinner 2 - read at f002/3 */
	PORT_BIT( 0xffff, 0x0000, IPT_DIAL ) PORT_SENSITIVITY(70) PORT_KEYDELTA(15) PORT_PLAYER(2)
INPUT_PORTS_END




/*  ( YEAR  NAME      PARENT    MACHINE   INPUT     INIT      MONITOR COMPANY    FULLNAME     FLAGS ) */
GAME( 1987, plumppop, 0,        drtoppel, plumppop, plumpop,  ROT0,   "Taito Corporation", "Plump Pop (Japan)", 0 )
GAME( 1987, extrmatn, 0,        arknoid2, extrmatn, extrmatn, ROT270, "Taito Corporation Japan", "Extermination (World)", 0 )
GAME( 1987, extrmatnu,extrmatn, arknoid2, extrmatn, extrmatn, ROT270, "Taito (World Games license)", "Extermination (US)", 0 )
GAME( 1987, extrmatnj,extrmatn, arknoid2, extrmatn, extrmatn, ROT270, "Taito Corporation", "Extermination (Japan)", 0 )
GAME( 1987, arknoid2, 0,        arknoid2, arknoid2, arknoid2, ROT270, "Taito Corporation Japan", "Arkanoid - Revenge of DOH (World)", 0 )
GAME( 1987, arknoid2u,arknoid2, arknoid2, arknid2u, arknoid2, ROT270, "Taito America Corporation (Romstar license)", "Arkanoid - Revenge of DOH (US)", 0 )
GAME( 1987, arknoid2j,arknoid2, arknoid2, arknid2u, arknoid2, ROT270, "Taito Corporation", "Arkanoid - Revenge of DOH (Japan)", 0 )
GAME( 1987, drtoppel, 0,        drtoppel, drtoppel, drtoppel, ROT90,  "Kaneko / Taito Corporation Japan", "Dr. Toppel's Adventure (World)", 0 ) /* Possible region hack */
GAME( 1987, drtoppelu,drtoppel, drtoppel, drtopplu, drtoppel, ROT90,  "Kaneko / Taito America Corporation", "Dr. Toppel's Adventure (US)", 0 ) /* Possible region hack */
GAME( 1987, drtoppelj,drtoppel, drtoppel, drtopplu, drtoppel, ROT90,  "Kaneko / Taito Corporation", "Dr. Toppel's Tankentai (Japan)", 0 )
GAME( 1988, kageki,   0,        kageki,   kageki,   kageki,   ROT90,  "Kaneko / Taito America Corporation (Romstar license)", "Kageki (US)", 0 )
GAME( 1988, kagekij,  kageki,   kageki,   kagekij,  kageki,   ROT90,  "Kaneko / Taito Corporation", "Kageki (Japan)", 0 )
GAME( 1992, kagekih,  kageki,   kageki,   kageki,   kageki,   ROT90,  "hack", "Kageki (hack)", 0 ) // date is hacked at least, might also be a Japan set hacked to show english
GAME( 1988, chukatai, 0,        tnzs,     chukatai, chukatai, ROT0,   "Taito Corporation Japan", "Chuka Taisen (World)", 0 ) /* Possible region hack */
GAME( 1988, chukataiu,chukatai, tnzs,     chukatau, chukatai, ROT0,   "Taito America Corporation", "Chuka Taisen (US)", 0 ) /* Possible region hack */
GAME( 1988, chukataij,chukatai, tnzs,     chukatau, chukatai, ROT0,   "Taito Corporation", "Chuka Taisen (Japan)", 0 )
GAME( 1988, tnzs,     0,        tnzsb,    tnzs,     tnzsb,    ROT0,   "Taito Corporation Japan", "The NewZealand Story (World, new version) (newer PCB)", 0 )
GAME( 1988, tnzsj,    tnzs,     tnzsb,    tnzsj,    tnzsb,    ROT0,   "Taito Corporation", "The NewZealand Story (Japan, new version) (newer PCB)", 0 )
GAME( 1988, tnzsjo,   tnzs,     tnzs,     tnzsjo,   tnzs,     ROT0,   "Taito Corporation", "The NewZealand Story (Japan, old version) (older PCB)", 0 )
GAME( 1988, tnzso,    tnzs,     tnzs,     tnzsop,   tnzs,     ROT0,   "Taito Corporation Japan", "The NewZealand Story (World, old version) (older PCB)", 0 )
GAME( 1988, tnzsop,   tnzs,     tnzs,     tnzsop,   tnzs,     ROT0,   "Taito Corporation Japan", "The NewZealand Story (World, prototype?) (older PCB)", 0 )
GAME( 1988, kabukiz,  0,        kabukiz,  kabukiz,  kabukiz,  ROT0,   "Kaneko / Taito Corporation Japan", "Kabuki-Z (World)", 0 )
GAME( 1988, kabukizj, kabukiz,  kabukiz,  kabukizj, kabukiz,  ROT0,   "Kaneko / Taito Corporation", "Kabuki-Z (Japan)", 0 )
GAME( 1989, insectx,  0,        insectx,  insectx,  insectx,  ROT0,   "Taito Corporation Japan", "Insector X (World)", 0 )
GAME( 1989, insectxj, insectx,  insectx,  insectxj, insectx,  ROT0,   "Taito Corporation", "Insector X (Japan)", 0 )
GAME( 1992, jpopnics, 0,        jpopnics, jpopnics, 0,        ROT0,   "bootleg (Nics)", "Jumping Pop (Nics, Korean bootleg of Plump Pop)", GAME_IMPERFECT_GRAPHICS )
