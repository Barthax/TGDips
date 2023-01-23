# MAME 0.135 source snippet

#include "driver.h"
#include "cpu/z80/z80.h"
#include "cpu/konami/konami.h" /* for the callback and the firq irq definition */
#include "video/konamiic.h"
#include "sound/2151intf.h"
#include "konamipt.h"

###############################################################################
# from konamipt.h

#define KONAMI8_B123_START( player )	\
	KONAMI8_B123( player )	\
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_START##player )

#define KONAMI_COINAGE_LOC( STRING_A, STRING_B, DIPBANK )	\
	PORT_DIPNAME( 0x0f, 0x0f, DEF_STR( Coin_A ) )		PORT_DIPLOCATION(#DIPBANK":1,2,3,4")	\
	PORT_DIPSETTING(    0x02, DEF_STR( 4C_1C ) )	\
	PORT_DIPSETTING(    0x05, DEF_STR( 3C_1C ) )	\
	PORT_DIPSETTING(    0x08, DEF_STR( 2C_1C ) )	\
	PORT_DIPSETTING(    0x04, DEF_STR( 3C_2C ) )	\
	PORT_DIPSETTING(    0x01, DEF_STR( 4C_3C ) )	\
	PORT_DIPSETTING(    0x0f, DEF_STR( 1C_1C ) )	\
	PORT_DIPSETTING(    0x03, DEF_STR( 3C_4C ) )	\
	PORT_DIPSETTING(    0x07, DEF_STR( 2C_3C ) )	\
	PORT_DIPSETTING(    0x0e, DEF_STR( 1C_2C ) )	\
	PORT_DIPSETTING(    0x06, DEF_STR( 2C_5C ) )	\
	PORT_DIPSETTING(    0x0d, DEF_STR( 1C_3C ) )	\
	PORT_DIPSETTING(    0x0c, DEF_STR( 1C_4C ) )	\
	PORT_DIPSETTING(    0x0b, DEF_STR( 1C_5C ) )	\
	PORT_DIPSETTING(    0x0a, DEF_STR( 1C_6C ) )	\
	PORT_DIPSETTING(    0x09, DEF_STR( 1C_7C ) )	\
	PORT_DIPSETTING(    0x00, STRING_A )			\
	PORT_DIPNAME( 0xf0, 0xf0, DEF_STR( Coin_B ) )		PORT_DIPLOCATION(#DIPBANK":5,6,7,8")	\
	PORT_DIPSETTING(    0x20, DEF_STR( 4C_1C ) )	\
	PORT_DIPSETTING(    0x50, DEF_STR( 3C_1C ) )	\
	PORT_DIPSETTING(    0x80, DEF_STR( 2C_1C ) )	\
	PORT_DIPSETTING(    0x40, DEF_STR( 3C_2C ) )	\
	PORT_DIPSETTING(    0x10, DEF_STR( 4C_3C ) )	\
	PORT_DIPSETTING(    0xf0, DEF_STR( 1C_1C ) )	\
	PORT_DIPSETTING(    0x30, DEF_STR( 3C_4C ) )	\
	PORT_DIPSETTING(    0x70, DEF_STR( 2C_3C ) )	\
	PORT_DIPSETTING(    0xe0, DEF_STR( 1C_2C ) )	\
	PORT_DIPSETTING(    0x60, DEF_STR( 2C_5C ) )	\
	PORT_DIPSETTING(    0xd0, DEF_STR( 1C_3C ) )	\
	PORT_DIPSETTING(    0xc0, DEF_STR( 1C_4C ) )	\
	PORT_DIPSETTING(    0xb0, DEF_STR( 1C_5C ) )	\
	PORT_DIPSETTING(    0xa0, DEF_STR( 1C_6C ) )	\
	PORT_DIPSETTING(    0x90, DEF_STR( 1C_7C ) )	\
	PORT_DIPSETTING(    0x00, STRING_B )
###############################################################################

static INPUT_PORTS_START( blockhl )
	PORT_START("P1")
	KONAMI8_B123_START(1)

	PORT_START("P2")
	KONAMI8_B123_START(2)

	PORT_START("DSW1")
	KONAMI_COINAGE_LOC(DEF_STR( Free_Play ), "No Coin B", SW1)
	/* "No Coin B" = coins produce sound, but no effect on coin counter */

	PORT_START("DSW2")
	PORT_DIPNAME( 0x01, 0x01, DEF_STR( Lives ) )		PORT_DIPLOCATION("SW2:1")
	PORT_DIPSETTING(    0x01, "1" )
	PORT_DIPSETTING(    0x00, "2" )
	PORT_DIPUNUSED_DIPLOC( 0x02, 0x02, "SW2:2" )		/* Listed as "Unused" */
	PORT_DIPUNUSED_DIPLOC( 0x04, 0x04, "SW2:3" )		/* Listed as "Unused" */
	PORT_DIPUNUSED_DIPLOC( 0x08, 0x08, "SW2:4" )		/* Listed as "Unused" */
	PORT_DIPUNUSED_DIPLOC( 0x10, 0x10, "SW2:5" )		/* Listed as "Unused" */
	PORT_DIPNAME( 0x60, 0x40, DEF_STR( Difficulty ) )	PORT_DIPLOCATION("SW2:6,7")
	PORT_DIPSETTING(    0x60, DEF_STR( Easy ) )
	PORT_DIPSETTING(    0x40, DEF_STR( Normal ) )
	PORT_DIPSETTING(    0x20, DEF_STR( Difficult ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Very_Difficult ) )
	PORT_DIPNAME( 0x80, 0x00, DEF_STR( Demo_Sounds ) )	PORT_DIPLOCATION("SW2:8")
	PORT_DIPSETTING(    0x80, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )

	PORT_START("DSW3")
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_COIN1 )
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_COIN2 )
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_COIN3 )
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_DIPNAME( 0x10, 0x10, DEF_STR( Flip_Screen ) )	PORT_DIPLOCATION("SW3:1")
	PORT_DIPSETTING(    0x10, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPUNUSED_DIPLOC( 0x20, 0x20, "SW3:2" )		/* Listed as "Unused" */
	PORT_SERVICE_DIPLOC(0x40, IP_ACTIVE_LOW, "SW3:3" )
	PORT_DIPUNUSED_DIPLOC( 0x80, 0x80, "SW3:4" )		/* Listed as "Unused" */
INPUT_PORTS_END




GAME( 1989, blockhl, 0,       blockhl, blockhl, blockhl, ROT0, "Konami", "Block Hole", 0 )
GAME( 1989, quarth,  blockhl, blockhl, blockhl, blockhl, ROT0, "Konami", "Quarth (Japan)", 0 )
