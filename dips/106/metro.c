# MAME 0.106 source snippet [metro.c]


#include "driver.h"
#include "vidhrdw/konamiic.h"
#include "cpu/upd7810/upd7810.h"
#include "machine/eeprom.h"
#include "sound/2610intf.h"
#include "sound/2151intf.h"
#include "sound/2413intf.h"
#include "sound/okim6295.h"
#include "sound/ymf278b.h"

/***************************************************************************


                                Input Ports


***************************************************************************/


#define JOY_LSB(_n_, _b1_, _b2_, _b3_, _b4_) \
	PORT_BIT(  0x0001, IP_ACTIVE_LOW, IPT_JOYSTICK_UP    ) PORT_PLAYER(_n_) \
	PORT_BIT(  0x0002, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN  ) PORT_PLAYER(_n_) \
	PORT_BIT(  0x0004, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT  ) PORT_PLAYER(_n_) \
	PORT_BIT(  0x0008, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT ) PORT_PLAYER(_n_) \
	PORT_BIT(  0x0010, IP_ACTIVE_LOW, IPT_##_b1_         ) PORT_PLAYER(_n_) \
	PORT_BIT(  0x0020, IP_ACTIVE_LOW, IPT_##_b2_         ) PORT_PLAYER(_n_) \
	PORT_BIT(  0x0040, IP_ACTIVE_LOW, IPT_##_b3_         ) PORT_PLAYER(_n_) \
	PORT_BIT(  0x0080, IP_ACTIVE_LOW, IPT_##_b4_         ) PORT_PLAYER(_n_) \


#define JOY_MSB(_n_, _b1_, _b2_, _b3_, _b4_) \
	PORT_BIT(  0x0100, IP_ACTIVE_LOW, IPT_JOYSTICK_UP    ) PORT_PLAYER(_n_) \
	PORT_BIT(  0x0200, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN  ) PORT_PLAYER(_n_) \
	PORT_BIT(  0x0400, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT  ) PORT_PLAYER(_n_) \
	PORT_BIT(  0x0800, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT ) PORT_PLAYER(_n_) \
	PORT_BIT(  0x1000, IP_ACTIVE_LOW, IPT_##_b1_         ) PORT_PLAYER(_n_) \
	PORT_BIT(  0x2000, IP_ACTIVE_LOW, IPT_##_b2_         ) PORT_PLAYER(_n_) \
	PORT_BIT(  0x4000, IP_ACTIVE_LOW, IPT_##_b3_         ) PORT_PLAYER(_n_) \
	PORT_BIT(  0x8000, IP_ACTIVE_LOW, IPT_##_b4_         ) PORT_PLAYER(_n_) \


#define COINS \
	PORT_BIT(  0x0001, IP_ACTIVE_LOW,  IPT_SERVICE1 ) \
	PORT_BIT(  0x0002, IP_ACTIVE_LOW,  IPT_TILT     ) \
	PORT_BIT(  0x0004, IP_ACTIVE_LOW,  IPT_COIN1 ) PORT_IMPULSE(2) \
	PORT_BIT(  0x0008, IP_ACTIVE_LOW,  IPT_COIN2 ) PORT_IMPULSE(2) \
	PORT_BIT(  0x0010, IP_ACTIVE_LOW,  IPT_START1   ) \
	PORT_BIT(  0x0020, IP_ACTIVE_LOW,  IPT_START2   ) \
	PORT_BIT(  0x0040, IP_ACTIVE_HIGH, IPT_UNKNOWN  ) \
	PORT_BIT(  0x0080, IP_ACTIVE_HIGH, IPT_SPECIAL  ) /* From Sound CPU in some games */


#define COINAGE_DSW \
	PORT_DIPNAME( 0x0007, 0x0007, DEF_STR( Coin_A ) ) \
	PORT_DIPSETTING(      0x0001, DEF_STR( 4C_1C ) ) \
	PORT_DIPSETTING(      0x0002, DEF_STR( 3C_1C ) ) \
	PORT_DIPSETTING(      0x0003, DEF_STR( 2C_1C ) ) \
	PORT_DIPSETTING(      0x0007, DEF_STR( 1C_1C ) ) \
	PORT_DIPSETTING(      0x0006, DEF_STR( 1C_2C ) ) \
	PORT_DIPSETTING(      0x0005, DEF_STR( 1C_3C ) ) \
	PORT_DIPSETTING(      0x0004, DEF_STR( 1C_4C ) ) \
	PORT_DIPSETTING(      0x0000, DEF_STR( Free_Play ) ) \
	PORT_DIPNAME( 0x0038, 0x0038, DEF_STR( Coin_B ) ) \
	PORT_DIPSETTING(      0x0008, DEF_STR( 4C_1C ) ) \
	PORT_DIPSETTING(      0x0010, DEF_STR( 3C_1C ) ) \
	PORT_DIPSETTING(      0x0018, DEF_STR( 2C_1C ) ) \
	PORT_DIPSETTING(      0x0038, DEF_STR( 1C_1C ) ) \
	PORT_DIPSETTING(      0x0030, DEF_STR( 1C_2C ) ) \
	PORT_DIPSETTING(      0x0028, DEF_STR( 1C_3C ) ) \
	PORT_DIPSETTING(      0x0020, DEF_STR( 1C_4C ) ) \
	PORT_DIPSETTING(      0x0000, DEF_STR( Free_Play ) ) \
	PORT_DIPNAME( 0x0040, 0x0040, DEF_STR( Flip_Screen ) ) \
	PORT_DIPSETTING(      0x0040, DEF_STR( Off ) ) \
	PORT_DIPSETTING(      0x0000, DEF_STR( On ) ) \
	PORT_SERVICE( 0x0080, IP_ACTIVE_LOW )



/***************************************************************************
                                    Bal Cube
***************************************************************************/

INPUT_PORTS_START( balcube )
	PORT_START_TAG("IN0")	// $500000
	COINS

	PORT_START_TAG("IN1")	// $500002
	JOY_LSB(1, BUTTON1, UNKNOWN, UNKNOWN, UNKNOWN)
	JOY_MSB(2, BUTTON1, UNKNOWN, UNKNOWN, UNKNOWN)

	PORT_START_TAG("IN2")	// Strangely mapped in the 0x400000-0x41ffff range
	COINAGE_DSW
	PORT_DIPNAME( 0x0300, 0x0300, "Difficulty?" )
	PORT_DIPSETTING(      0x0100, "0" )
	PORT_DIPSETTING(      0x0000, "1" )
	PORT_DIPSETTING(      0x0200, "2" )
	PORT_DIPSETTING(      0x0300, "3" )
	PORT_DIPNAME( 0x0400, 0x0400, "2 Players Game" )
	PORT_DIPSETTING(      0x0000, "1 Credit" )
	PORT_DIPSETTING(      0x0400, "2 Credits" )
	PORT_DIPNAME( 0x0800, 0x0800, DEF_STR( Lives ) )
	PORT_DIPSETTING(      0x0800, "2" )
	PORT_DIPSETTING(      0x0000, "3" )
	PORT_DIPNAME( 0x1000, 0x1000, DEF_STR( Allow_Continue ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( No ) )
	PORT_DIPSETTING(      0x1000, DEF_STR( Yes ) )
	PORT_DIPNAME( 0x2000, 0x2000, DEF_STR( Unknown ) )
	PORT_DIPSETTING(      0x2000, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( On ) )
	PORT_DIPNAME( 0x4000, 0x4000, DEF_STR( Unknown ) )
	PORT_DIPSETTING(      0x4000, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( On ) )
	PORT_DIPNAME( 0x8000, 0x8000, DEF_STR( Demo_Sounds ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x8000, DEF_STR( On ) )

	PORT_START_TAG("IN3")	// Strangely mapped in the 0x400000-0x41ffff range
	PORT_BIT(  0x00ff, IP_ACTIVE_LOW, IPT_UNKNOWN )	// unused
INPUT_PORTS_END


/***************************************************************************
                                Bang Bang Ball
***************************************************************************/

INPUT_PORTS_START( bangball )
	PORT_START_TAG("IN0")	// $d00000
	COINS

	PORT_START_TAG("IN1")	// $d00002
	JOY_LSB(1, BUTTON1, UNKNOWN, UNKNOWN, UNKNOWN)
	JOY_MSB(2, BUTTON1, UNKNOWN, UNKNOWN, UNKNOWN)

	PORT_START_TAG("IN2")	// Strangely mapped in the 0xc00000-0xc1ffff range
	COINAGE_DSW
	PORT_DIPNAME( 0x0300, 0x0300, DEF_STR( Difficulty ) )
	PORT_DIPSETTING(      0x0200, DEF_STR( Easy )    )
	PORT_DIPSETTING(      0x0300, DEF_STR( Normal )  )
	PORT_DIPSETTING(      0x0100, DEF_STR( Hard )    )
	PORT_DIPSETTING(      0x0000, DEF_STR( Hardest ) )
	PORT_DIPNAME( 0x0c00, 0x0c00, DEF_STR( Lives ) )
	PORT_DIPSETTING(      0x0800, "2" )
	PORT_DIPSETTING(      0x0400, "3" )
	PORT_DIPSETTING(      0x0c00, "4" )
	PORT_DIPSETTING(      0x0000, "5" )
	PORT_DIPNAME( 0x1000, 0x1000, DEF_STR( Allow_Continue ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( No ) )
	PORT_DIPSETTING(      0x1000, DEF_STR( Yes ) )
	PORT_DIPNAME( 0x2000, 0x2000, DEF_STR( Demo_Sounds ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x2000, DEF_STR( On ) )
	PORT_DIPNAME( 0x4000, 0x4000, DEF_STR( Unknown ) )
	PORT_DIPSETTING(      0x4000, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( On ) )
	PORT_DIPNAME( 0x8000, 0x0000, DEF_STR( Language ) )
	PORT_DIPSETTING(      0x8000, DEF_STR( Japanese ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( English ) )

	PORT_START_TAG("IN3")	// Strangely mapped in the 0xc00000-0xc1ffff range
	PORT_BIT(  0x00ff, IP_ACTIVE_LOW, IPT_UNKNOWN )	// used for debug
INPUT_PORTS_END

/***************************************************************************
                                Battle Bubble
***************************************************************************/

INPUT_PORTS_START( batlbubl )
	PORT_START_TAG("IN0")
	JOY_LSB(1, BUTTON1, UNKNOWN, UNKNOWN, UNKNOWN)
	JOY_MSB(2, BUTTON1, UNKNOWN, UNKNOWN, UNKNOWN)

	PORT_START_TAG("IN2")	// Strangely mapped in the 0xc00000-0xc1ffff range
	PORT_DIPNAME( 0x0003, 0x0003, DEF_STR( Difficulty ) )
	PORT_DIPSETTING(      0x0002, DEF_STR( Easy )    )
	PORT_DIPSETTING(      0x0003, DEF_STR( Normal )  )
	PORT_DIPSETTING(      0x0001, DEF_STR( Hard )    )
	PORT_DIPSETTING(      0x0000, DEF_STR( Hardest ) )
	PORT_DIPNAME( 0x000c, 0x000c, DEF_STR( Lives ) )
	PORT_DIPSETTING(      0x0008, "2" )
	PORT_DIPSETTING(      0x0004, "3" )
	PORT_DIPSETTING(      0x000c, "4" )
	PORT_DIPSETTING(      0x0000, "5" )
	PORT_DIPNAME( 0x0010, 0x0010, DEF_STR( Allow_Continue ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( No ) )
	PORT_DIPSETTING(      0x0010, DEF_STR( Yes ) )
	PORT_DIPNAME( 0x0020, 0x0020, DEF_STR( Demo_Sounds ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0020, DEF_STR( On ) )
	PORT_DIPNAME( 0x0040, 0x0040, DEF_STR( Unknown ) )
	PORT_DIPSETTING(      0x0040, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( On ) )
	PORT_DIPNAME( 0x0080, 0x0080, DEF_STR( Unknown ) )
	PORT_DIPSETTING(      0x0080, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( On ) )
	PORT_DIPNAME( 0x0700, 0x0700, DEF_STR( Coin_A ) )
	PORT_DIPSETTING(      0x0100, DEF_STR( 4C_1C ) )
	PORT_DIPSETTING(      0x0200, DEF_STR( 3C_1C ) )
	PORT_DIPSETTING(      0x0300, DEF_STR( 2C_1C ) )
	PORT_DIPSETTING(      0x0700, DEF_STR( 1C_1C ) )
	PORT_DIPSETTING(      0x0600, DEF_STR( 1C_2C ) )
	PORT_DIPSETTING(      0x0500, DEF_STR( 1C_3C ) )
	PORT_DIPSETTING(      0x0400, DEF_STR( 1C_4C ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( Free_Play ) )
	PORT_DIPNAME( 0x3800, 0x3800, DEF_STR( Coin_B ) )
	PORT_DIPSETTING(      0x0800, DEF_STR( 4C_1C ) )
	PORT_DIPSETTING(      0x1000, DEF_STR( 3C_1C ) )
	PORT_DIPSETTING(      0x1800, DEF_STR( 2C_1C ) )
	PORT_DIPSETTING(      0x3800, DEF_STR( 1C_1C ) )
	PORT_DIPSETTING(      0x3000, DEF_STR( 1C_2C ) )
	PORT_DIPSETTING(      0x2800, DEF_STR( 1C_3C ) )
	PORT_DIPSETTING(      0x2000, DEF_STR( 1C_4C ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( Free_Play ) )
	PORT_DIPNAME( 0x4000, 0x4000, DEF_STR( Flip_Screen ) )
	PORT_DIPSETTING(      0x4000, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( On ) )
	PORT_SERVICE( 0x8000, IP_ACTIVE_LOW )

	PORT_START_TAG("IN0")	// $d00000
	COINS

	PORT_START_TAG("IN3")	// Strangely mapped in the 0xc00000-0xc1ffff range
    PORT_DIPNAME( 0x0001, 0x0001, "0" )
    PORT_DIPSETTING(      0x0001, DEF_STR( Off ) )
    PORT_DIPSETTING(      0x0000, DEF_STR( On ) )
    PORT_DIPNAME( 0x0002, 0x0002, DEF_STR( Unknown ) )
    PORT_DIPSETTING(      0x0002, DEF_STR( Off ) )
    PORT_DIPSETTING(      0x0000, DEF_STR( On ) )
    PORT_DIPNAME( 0x0004, 0x0004, DEF_STR( Unknown ) )
    PORT_DIPSETTING(      0x0004, DEF_STR( Off ) )
    PORT_DIPSETTING(      0x0000, DEF_STR( On ) )
    PORT_DIPNAME( 0x0008, 0x0008, DEF_STR( Unknown ) )
    PORT_DIPSETTING(      0x0008, DEF_STR( Off ) )
    PORT_DIPSETTING(      0x0000, DEF_STR( On ) )
    PORT_DIPNAME( 0x0010, 0x0010, DEF_STR( Unknown ) )
    PORT_DIPSETTING(      0x0010, DEF_STR( Off ) )
    PORT_DIPSETTING(      0x0000, DEF_STR( On ) )
    PORT_DIPNAME( 0x0020, 0x0020, DEF_STR( Unknown ) )
    PORT_DIPSETTING(      0x0020, DEF_STR( Off ) )
    PORT_DIPSETTING(      0x0000, DEF_STR( On ) )
    PORT_DIPNAME( 0x0040, 0x0040, DEF_STR( Unknown ) )
    PORT_DIPSETTING(      0x0040, DEF_STR( Off ) )
    PORT_DIPSETTING(      0x0000, DEF_STR( On ) )
	PORT_DIPNAME( 0x0080, 0x0080, "Debug Mode?" )
	PORT_DIPSETTING(      0x0080, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( On ) )
    PORT_DIPNAME( 0x0100, 0x0100, DEF_STR( Unknown ) )
    PORT_DIPSETTING(      0x0100, DEF_STR( Off ) )
    PORT_DIPSETTING(      0x0000, DEF_STR( On ) )
    PORT_DIPNAME( 0x0200, 0x0200, DEF_STR( Unknown ) )
    PORT_DIPSETTING(      0x0200, DEF_STR( Off ) )
    PORT_DIPSETTING(      0x0000, DEF_STR( On ) )
    PORT_DIPNAME( 0x0400, 0x0400, DEF_STR( Unknown ) )
    PORT_DIPSETTING(      0x0400, DEF_STR( Off ) )
    PORT_DIPSETTING(      0x0000, DEF_STR( On ) )
    PORT_DIPNAME( 0x0800, 0x0800, DEF_STR( Unknown ) )
    PORT_DIPSETTING(      0x0800, DEF_STR( Off ) )
    PORT_DIPSETTING(      0x0000, DEF_STR( On ) )
    PORT_DIPNAME( 0x1000, 0x1000, DEF_STR( Unknown ) )
    PORT_DIPSETTING(      0x1000, DEF_STR( Off ) )
    PORT_DIPSETTING(      0x0000, DEF_STR( On ) )
    PORT_DIPNAME( 0x2000, 0x2000, DEF_STR( Unknown ) )
    PORT_DIPSETTING(      0x2000, DEF_STR( Off ) )
    PORT_DIPSETTING(      0x0000, DEF_STR( On ) )
    PORT_DIPNAME( 0x4000, 0x4000, DEF_STR( Unknown ) )
    PORT_DIPSETTING(      0x4000, DEF_STR( Off ) )
    PORT_DIPSETTING(      0x0000, DEF_STR( On ) )
    PORT_DIPNAME( 0x8000, 0x8000, DEF_STR( Unknown ) )
    PORT_DIPSETTING(      0x8000, DEF_STR( Off ) )
    PORT_DIPSETTING(      0x0000, DEF_STR( On ) )
INPUT_PORTS_END

/***************************************************************************
                            Blazing Tornado
***************************************************************************/

INPUT_PORTS_START( blzntrnd )
	PORT_START_TAG("IN0")
	PORT_DIPNAME( 0x0007, 0x0004, DEF_STR( Difficulty ) )
	PORT_DIPSETTING(      0x0007, "Beginner" )
	PORT_DIPSETTING(      0x0006, DEF_STR( Easiest ) )
	PORT_DIPSETTING(      0x0005, DEF_STR( Easy ) )
	PORT_DIPSETTING(      0x0004, DEF_STR( Normal ) )
	PORT_DIPSETTING(      0x0003, DEF_STR( Hard ) )
	PORT_DIPSETTING(      0x0002, DEF_STR( Hardest ) )
	PORT_DIPSETTING(      0x0001, "Expert" )
	PORT_DIPSETTING(      0x0000, "Master" )
	PORT_DIPNAME( 0x0008, 0x0008, DEF_STR( Flip_Screen ) )
	PORT_DIPSETTING(      0x0008, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( On ) )
	PORT_DIPNAME( 0x0010, 0x0000, DEF_STR( Demo_Sounds ) )
	PORT_DIPSETTING(      0x0010, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( On ) )
	PORT_DIPNAME( 0x0020, 0x0000, DEF_STR( Allow_Continue ) )
	PORT_DIPSETTING(      0x0020, DEF_STR( No ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( Yes ) )
	PORT_DIPNAME( 0x00c0, 0x0000, "Control Panel" )
	PORT_DIPSETTING(      0x0000, "4 Players" )
//  PORT_DIPSETTING(      0x0040, "4 Players" )
	PORT_DIPSETTING(      0x0080, "1P & 2P Tag only" )
	PORT_DIPSETTING(      0x00c0, "1P & 2P vs only" )
	PORT_DIPNAME( 0x0300, 0x0300, "Half Continue" )
	PORT_DIPSETTING(      0x0000, "6C to start, 3C to continue" )
	PORT_DIPSETTING(      0x0100, "4C to start, 2C to continue" )
	PORT_DIPSETTING(      0x0200, "2C to start, 1C to continue" )
	PORT_DIPSETTING(      0x0300, "Disabled" )
	PORT_DIPNAME( 0x0400, 0x0400, DEF_STR( Unused ) )
	PORT_DIPSETTING(      0x0400, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( On ) )
	PORT_DIPNAME( 0x0800, 0x0800, DEF_STR( Unused ) )
	PORT_DIPSETTING(      0x0800, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( On ) )
	PORT_DIPNAME( 0x1000, 0x1000, DEF_STR( Unused ) )
	PORT_DIPSETTING(      0x1000, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( On ) )
	PORT_DIPNAME( 0x2000, 0x2000, DEF_STR( Unused ) )
	PORT_DIPSETTING(      0x2000, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( On ) )
	PORT_DIPNAME( 0x4000, 0x4000, DEF_STR( Unused ) )
	PORT_DIPSETTING(      0x4000, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( On ) )
	PORT_DIPNAME( 0x8000, 0x8000, DEF_STR( Unused ) )
	PORT_DIPSETTING(      0x8000, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( On ) )

	PORT_START_TAG("IN1")
	PORT_DIPNAME( 0x0007, 0x0007, DEF_STR( Coin_A ) )
	PORT_DIPSETTING(      0x0004, DEF_STR( 4C_1C ) )
	PORT_DIPSETTING(      0x0005, DEF_STR( 3C_1C ) )
	PORT_DIPSETTING(      0x0006, DEF_STR( 2C_1C ) )
	PORT_DIPSETTING(      0x0007, DEF_STR( 1C_1C ) )
	PORT_DIPSETTING(      0x0003, DEF_STR( 1C_2C ) )
	PORT_DIPSETTING(      0x0002, DEF_STR( 1C_3C ) )
	PORT_DIPSETTING(      0x0001, DEF_STR( 1C_4C ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( 1C_5C ) )
	PORT_DIPNAME( 0x0038, 0x0038, DEF_STR( Coin_B ) )
	PORT_DIPSETTING(      0x0020, DEF_STR( 4C_1C ) )
	PORT_DIPSETTING(      0x0028, DEF_STR( 3C_1C ) )
	PORT_DIPSETTING(      0x0030, DEF_STR( 2C_1C ) )
	PORT_DIPSETTING(      0x0038, DEF_STR( 1C_1C ) )
	PORT_DIPSETTING(      0x0018, DEF_STR( 1C_2C ) )
	PORT_DIPSETTING(      0x0010, DEF_STR( 1C_3C ) )
	PORT_DIPSETTING(      0x0008, DEF_STR( 1C_4C ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( 1C_5C ) )
	PORT_DIPNAME( 0x0040, 0x0040, DEF_STR( Free_Play ) )
	PORT_DIPSETTING(      0x0040, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( On ) )
	PORT_SERVICE_NO_TOGGLE(0x0080, IP_ACTIVE_LOW)
	PORT_DIPNAME( 0x0300, 0x0300, "CP Single" )
	PORT_DIPSETTING(      0x0300, "2:00" )
	PORT_DIPSETTING(      0x0200, "2:30" )
	PORT_DIPSETTING(      0x0100, "3:00" )
	PORT_DIPSETTING(      0x0000, "3:30" )
	PORT_DIPNAME( 0x0c00, 0x0c00, "CP Tag" )
	PORT_DIPSETTING(      0x0c00, "2:00" )
	PORT_DIPSETTING(      0x0800, "2:30" )
	PORT_DIPSETTING(      0x0400, "3:00" )
	PORT_DIPSETTING(      0x0000, "3:30" )
	PORT_DIPNAME( 0x3000, 0x3000, "Vs Single" )
	PORT_DIPSETTING(      0x3000, "2:30" )
	PORT_DIPSETTING(      0x2000, "3:00" )
	PORT_DIPSETTING(      0x1000, "4:00" )
	PORT_DIPSETTING(      0x0000, "5:00" )
	PORT_DIPNAME( 0xc000, 0xc000, "Vs Tag" )
	PORT_DIPSETTING(      0xc000, "2:30" )
	PORT_DIPSETTING(      0x8000, "3:00" )
	PORT_DIPSETTING(      0x4000, "4:00" )
	PORT_DIPSETTING(      0x0000, "5:00" )

	PORT_START_TAG("IN2")
	JOY_LSB(1, BUTTON1, BUTTON2, BUTTON3, BUTTON4)
	JOY_MSB(2, BUTTON1, BUTTON2, BUTTON3, BUTTON4)

	PORT_START_TAG("IN3")
	JOY_LSB(3, BUTTON1, BUTTON2, BUTTON3, BUTTON4)
	JOY_MSB(4, BUTTON1, BUTTON2, BUTTON3, BUTTON4)

	PORT_START_TAG("IN4")
	PORT_BIT( 0x0001, IP_ACTIVE_LOW, IPT_SERVICE1 )
	PORT_SERVICE_NO_TOGGLE(0x0002, IP_ACTIVE_LOW)
	PORT_BIT(  0x0004, IP_ACTIVE_LOW, IPT_COIN1 ) PORT_IMPULSE(2)
	PORT_BIT(  0x0008, IP_ACTIVE_LOW, IPT_COIN2 ) PORT_IMPULSE(2)
	PORT_BIT( 0x0010, IP_ACTIVE_LOW, IPT_START1 )
	PORT_BIT( 0x0020, IP_ACTIVE_LOW, IPT_START2 )
	PORT_BIT( 0x0040, IP_ACTIVE_LOW, IPT_START3 )
	PORT_BIT( 0x0080, IP_ACTIVE_LOW, IPT_START4 )
INPUT_PORTS_END


/***************************************************************************
                            Grand Striker 2
***************************************************************************/

INPUT_PORTS_START( gstrik2 )
	PORT_START_TAG("IN0")
	PORT_DIPNAME( 0x0003, 0x0003, "Player Vs Com" )
	PORT_DIPSETTING(      0x0003, "1:00" )
	PORT_DIPSETTING(      0x0002, "1:30" )
	PORT_DIPSETTING(      0x0001, "2:00" )
	PORT_DIPSETTING(      0x0000, "2:30" )
	PORT_DIPNAME( 0x000c, 0x000c, "1P Vs 2P" )
	PORT_DIPSETTING(      0x000c, "0:45" )
	PORT_DIPSETTING(      0x0008, "1:00" )
	PORT_DIPSETTING(      0x0004, "1:30" )
	PORT_DIPSETTING(      0x0000, "2:00" )
	PORT_DIPNAME( 0x0030, 0x0030, "Extra Time" )
	PORT_DIPSETTING(      0x0030, "0:30" )
	PORT_DIPSETTING(      0x0020, "0:45" )
	PORT_DIPSETTING(      0x0010, "1:00" )
	PORT_DIPSETTING(      0x0000, DEF_STR( Off ) )
	PORT_DIPNAME( 0x0040, 0x0040, DEF_STR( Unknown ) )
	PORT_DIPSETTING(      0x0040, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( On ) )
	PORT_DIPNAME( 0x0080, 0x0080, "Extra Time" )
	PORT_DIPSETTING(      0x0080, "Sudden Death" )
	PORT_DIPSETTING(      0x0000, "Full" )
	PORT_DIPNAME( 0x0700, 0x0400, DEF_STR( Difficulty ) )
	PORT_DIPSETTING(      0x0700, DEF_STR( Very_Easy) )
	PORT_DIPSETTING(      0x0600, DEF_STR( Easier ) )
	PORT_DIPSETTING(      0x0500, DEF_STR( Easy ) )
	PORT_DIPSETTING(      0x0400, DEF_STR( Normal ) )
	PORT_DIPSETTING(      0x0300, DEF_STR( Medium ) )
	PORT_DIPSETTING(      0x0200, DEF_STR( Hard ) )
	PORT_DIPSETTING(      0x0100, DEF_STR( Hardest ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( Very_Hard ) )
	PORT_DIPNAME( 0x0800, 0x0800, DEF_STR( Demo_Sounds ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0800, DEF_STR( On ) )
	PORT_DIPNAME( 0x1000, 0x1000, DEF_STR( Unknown ) )
	PORT_DIPSETTING(      0x1000, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( On ) )
	PORT_DIPNAME( 0x2000, 0x2000, DEF_STR( Unknown ) )
	PORT_DIPSETTING(      0x2000, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( On ) )
	PORT_DIPNAME( 0x4000, 0x4000, DEF_STR( Flip_Screen ) )
	PORT_DIPSETTING(      0x4000, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( On ) )
	PORT_SERVICE_NO_TOGGLE(0x8000, IP_ACTIVE_LOW)

	PORT_START_TAG("IN1")
	PORT_DIPNAME( 0x001f, 0x001f, DEF_STR( Coin_A ) )
	PORT_DIPSETTING(      0x001c, DEF_STR( 4C_1C ) )
	PORT_DIPSETTING(      0x001d, DEF_STR( 3C_1C ) )
	PORT_DIPSETTING(      0x0018, DEF_STR( 4C_2C ) )
	PORT_DIPSETTING(      0x001e, DEF_STR( 2C_1C ) )
	PORT_DIPSETTING(      0x0019, DEF_STR( 3C_2C ) )
	PORT_DIPSETTING(      0x0014, DEF_STR( 4C_3C ) )
	PORT_DIPSETTING(      0x0010, DEF_STR( 4C_4C ) )
	PORT_DIPSETTING(      0x0015, DEF_STR( 3C_3C ) )
	PORT_DIPSETTING(      0x001a, DEF_STR( 2C_2C ) )
	PORT_DIPSETTING(      0x001f, DEF_STR( 1C_1C ) )
	PORT_DIPSETTING(      0x000c, DEF_STR( 4C_5C ) )
	PORT_DIPSETTING(      0x0011, DEF_STR( 3C_4C ) )
	PORT_DIPSETTING(      0x0008, "4 Coins/6 Credits" )
	PORT_DIPSETTING(      0x0016, DEF_STR( 2C_3C ) )
	PORT_DIPSETTING(      0x000d, "3 Coins/5 Credits" )
	PORT_DIPSETTING(      0x0004, DEF_STR( 4C_7C ) )
	PORT_DIPSETTING(      0x0000, "4 Coins/8 Credits" )
	PORT_DIPSETTING(      0x0009, "3 Coins/6 Credits" )
	PORT_DIPSETTING(      0x0012, DEF_STR( 2C_4C ) )
	PORT_DIPSETTING(      0x001b, DEF_STR( 1C_2C ) )
	PORT_DIPSETTING(      0x0005, "3 Coins/7 Credits" )
	PORT_DIPSETTING(      0x000e, DEF_STR( 2C_5C ) )
	PORT_DIPSETTING(      0x0001, "3 Coins/8 Credits" )
	PORT_DIPSETTING(      0x000a, DEF_STR( 2C_6C ) )
	PORT_DIPSETTING(      0x0017, DEF_STR( 1C_3C ) )
	PORT_DIPSETTING(      0x0006, DEF_STR( 2C_7C ) )
	PORT_DIPSETTING(      0x0002, DEF_STR( 2C_8C ) )
	PORT_DIPSETTING(      0x0013, DEF_STR( 1C_4C ) )
	PORT_DIPSETTING(      0x000f, DEF_STR( 1C_5C ) )
	PORT_DIPSETTING(      0x000b, DEF_STR( 1C_6C ) )
	PORT_DIPSETTING(      0x0007, DEF_STR( 1C_7C ) )
	PORT_DIPSETTING(      0x0003, DEF_STR( 1C_8C ) )
	PORT_DIPNAME( 0x00e0, 0x0000, DEF_STR( Coin_B ) )
	PORT_DIPSETTING(      0x00c0, DEF_STR( 1C_1C ) )
	PORT_DIPSETTING(      0x00a0, DEF_STR( 1C_2C ) )
	PORT_DIPSETTING(      0x0080, DEF_STR( 1C_3C ) )
	PORT_DIPSETTING(      0x0060, DEF_STR( 1C_4C ) )
	PORT_DIPSETTING(      0x0040, DEF_STR( 1C_5C ) )
	PORT_DIPSETTING(      0x0020, DEF_STR( 1C_6C ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( 1C_7C ) )
	PORT_DIPSETTING(      0x00e0, "Same as Coin A" )
	PORT_DIPNAME( 0x0300, 0x0300, "Credits to Start" )
	PORT_DIPSETTING(      0x0300, "1" )
	PORT_DIPSETTING(      0x0200, "2" )
	PORT_DIPSETTING(      0x0100, "3" )
	PORT_DIPSETTING(      0x0000, "4" )
	PORT_DIPNAME( 0x0c00, 0x0c00, "Credits to Continue" )
	PORT_DIPSETTING(      0x0c00, "1" )
	PORT_DIPSETTING(      0x0800, "2" )
	PORT_DIPSETTING(      0x0400, "3" )
	PORT_DIPSETTING(      0x0000, "4" )
	PORT_DIPNAME( 0x1000, 0x1000, "Continue" )
	PORT_DIPSETTING(      0x0000, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x1000, DEF_STR( On ) )
	PORT_DIPNAME( 0x2000, 0x2000, DEF_STR( Unknown ) )
	PORT_DIPSETTING(      0x2000, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( On ) )
	PORT_DIPNAME( 0x4000, 0x4000, "Playmode" )
	PORT_DIPSETTING(      0x4000, "1 Credit for 1 Player" )
	PORT_DIPSETTING(      0x0000, "1 Credit for 2 Players" )
	PORT_DIPNAME( 0x8000, 0x8000, DEF_STR( Free_Play ) )
	PORT_DIPSETTING(      0x8000, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( On ) )

	PORT_START_TAG("IN2")
	JOY_LSB(1, BUTTON1, BUTTON2, BUTTON3, UNUSED)
	JOY_MSB(2, BUTTON1, BUTTON2, BUTTON3, UNUSED)

	PORT_START_TAG("IN3")
	/* Not Used */

	PORT_START_TAG("IN4")
	PORT_BIT( 0x0001, IP_ACTIVE_LOW, IPT_SERVICE1 )
	PORT_SERVICE_NO_TOGGLE(0x0002, IP_ACTIVE_LOW )
	PORT_BIT(  0x0004, IP_ACTIVE_LOW, IPT_COIN1 ) PORT_IMPULSE(2)
	PORT_BIT(  0x0008, IP_ACTIVE_LOW, IPT_COIN2 ) PORT_IMPULSE(2)
	PORT_BIT( 0x0010, IP_ACTIVE_LOW, IPT_START1 )
	PORT_BIT( 0x0020, IP_ACTIVE_LOW, IPT_START2 )
	PORT_BIT( 0x0040, IP_ACTIVE_LOW, IPT_START3 )
	PORT_BIT( 0x0080, IP_ACTIVE_LOW, IPT_START4 )
INPUT_PORTS_END

/***************************************************************************
                                Dai Toride
***************************************************************************/

/* If only ONE of the "Coinage" is set to "Free Play", it is in fact "5C_1C".

   IN2 bits 12 and 13 are in fact "merged" :

     12  13    effect
     Off Off   Continue, Retry level
     On  Off   Continue, Ask player for retry
     Off On    No continue
     On  On    Continue, Retry level

*/
INPUT_PORTS_START( daitorid )
	PORT_START_TAG("IN0") // $c00000
	COINS

	PORT_START_TAG("IN1") // $c00002
	JOY_LSB(1, BUTTON1, UNKNOWN, UNKNOWN, UNKNOWN)		// BUTTON2 and BUTTON3 in "test mode" only
	JOY_MSB(2, BUTTON1, UNKNOWN, UNKNOWN, UNKNOWN)		// BUTTON2 and BUTTON3 in "test mode" only

	PORT_START_TAG("IN2") // $c00004
	COINAGE_DSW

	PORT_DIPNAME( 0x0300, 0x0300, DEF_STR( Difficulty ) )		// Timer speed
	PORT_DIPSETTING(      0x0200, DEF_STR( Easy ) )				//   Slow
	PORT_DIPSETTING(      0x0300, DEF_STR( Normal ) )				//   Normal
	PORT_DIPSETTING(      0x0100, DEF_STR( Hard ) )				//   Fast
	PORT_DIPSETTING(      0x0000, DEF_STR( Hardest ) )				//   Fastest
	PORT_DIPNAME( 0x0400, 0x0400, DEF_STR( Unused ) )
	PORT_DIPSETTING(      0x0400, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( On ) )
	PORT_DIPNAME( 0x0800, 0x0800, "Winning Rounds (Player VS Player)" )
	PORT_DIPSETTING(      0x0000, "1/1" )
	PORT_DIPSETTING(      0x0800, "2/3" )
	PORT_DIPNAME( 0x1000, 0x0000, "Retry Level On Continue" )
	PORT_DIPSETTING(      0x0000, "Ask Player" )
	PORT_DIPSETTING(      0x1000, DEF_STR( Yes ) )
	PORT_DIPNAME( 0x2000, 0x2000, DEF_STR( Allow_Continue ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( No ) )
	PORT_DIPSETTING(      0x2000, DEF_STR( Yes ) )
	PORT_DIPNAME( 0x4000, 0x4000, DEF_STR( Demo_Sounds ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x4000, DEF_STR( On ) )
	PORT_DIPNAME( 0x8000, 0x8000, DEF_STR( Unused ) )
	PORT_DIPSETTING(      0x8000, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( On ) )

	PORT_START_TAG("IN3") // $c00006
	PORT_BIT(  0xffff, IP_ACTIVE_LOW, IPT_UNKNOWN )
INPUT_PORTS_END


/***************************************************************************
                                Dharma Doujou
***************************************************************************/

/* I don't really know HOW to describe the effect of IN2 bits 8 and 9.
   All I can tell is that in "table 2" the values are smaller for the 2
   first levels (so the game is harder), but they vary less between the
   levels (so there is almost no increasing difficulty).

   Even if there are 4 "tables" the 2 first ones and the 2 last ones
   contains the same values for the timer. */
INPUT_PORTS_START( dharma )
	PORT_START_TAG("IN0") //$c00000
	COINS

	PORT_START_TAG("IN1") //$c00002
	JOY_LSB(1, BUTTON1, UNKNOWN, UNKNOWN, UNKNOWN)		// BUTTON2 and BUTTON3 in "test mode" only
	JOY_MSB(2, BUTTON1, UNKNOWN, UNKNOWN, UNKNOWN)		// BUTTON2 and BUTTON3 in "test mode" only

	PORT_START_TAG("IN2") //$c00004
	COINAGE_DSW

	PORT_DIPNAME( 0x0300, 0x0300, "Time" )				// Check code at 0x00da0a and see notes
	PORT_DIPSETTING(      0x0000, "Table 1" )				//   Table offset : 0x00e668
//  PORT_DIPSETTING(      0x0100, "Table 1" )               //   Table offset : 0x00e6c0
//  PORT_DIPSETTING(      0x0200, "Table 2" )               //   Table offset : 0x00e718
	PORT_DIPSETTING(      0x0300, "Table 2" )				//   Table offset : 0x00e770
	PORT_DIPNAME( 0x0c00, 0x0c00, DEF_STR( Difficulty ) )		// Timer (crab) speed
	PORT_DIPSETTING(      0x0800, DEF_STR( Easy ) )				//   Slow
	PORT_DIPSETTING(      0x0c00, DEF_STR( Normal ) )				//   Normal
	PORT_DIPSETTING(      0x0400, DEF_STR( Hard ) )				//   Fast
	PORT_DIPSETTING(      0x0000, DEF_STR( Hardest ) )				//   Fastest
	PORT_DIPNAME( 0x1000, 0x1000, "2 Players Game" )
	PORT_DIPSETTING(      0x1000, "2 Credits" )
	PORT_DIPSETTING(      0x0000, "1 Credit" )
	PORT_DIPNAME( 0x2000, 0x2000, DEF_STR( Allow_Continue ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( No ) )
	PORT_DIPSETTING(      0x2000, DEF_STR( Yes ) )
	PORT_DIPNAME( 0x4000, 0x4000, DEF_STR( Demo_Sounds ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x4000, DEF_STR( On ) )
	PORT_DIPNAME( 0x8000, 0x8000, "Freeze (Cheat)")
	PORT_DIPSETTING(      0x8000, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( On ) )

	PORT_START_TAG("IN3") // $c00006
	PORT_BIT(  0xffff, IP_ACTIVE_LOW, IPT_UNKNOWN )
INPUT_PORTS_END

/***************************************************************************
                                Gun Master
***************************************************************************/

INPUT_PORTS_START( gunmast )
	PORT_START_TAG("IN0") //$400000
	COINS

	PORT_START_TAG("IN1") //$400002
	JOY_LSB(1, BUTTON1, BUTTON2, BUTTON3, UNKNOWN)
	JOY_MSB(2, BUTTON1, BUTTON2, BUTTON3, UNKNOWN)

	PORT_START_TAG("IN2") //$400004
	COINAGE_DSW

	PORT_DIPNAME( 0x0300, 0x0300, DEF_STR( Difficulty ) )
	PORT_DIPSETTING(      0x0300, DEF_STR( Normal ) )
	PORT_DIPSETTING(      0x0200, DEF_STR( Hard ) )
	PORT_DIPSETTING(      0x0100, DEF_STR( Harder ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( Hardest ) )
	PORT_DIPNAME( 0x0400, 0x0400, DEF_STR( Allow_Continue ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( No ) )
	PORT_DIPSETTING(      0x0400, DEF_STR( Yes ) )
	PORT_DIPNAME( 0x0800, 0x0800, DEF_STR( Unknown ) )
	PORT_DIPSETTING(      0x0800, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( On ) )
	PORT_DIPNAME( 0x1000, 0x1000, DEF_STR( Demo_Sounds ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x1000, DEF_STR( On ) )
	PORT_DIPNAME( 0x2000, 0x2000, DEF_STR( Lives ) )
	PORT_DIPSETTING(      0x2000, "1" )
	PORT_DIPSETTING(      0x0000, "2" )
	PORT_DIPNAME( 0x4000, 0x4000, DEF_STR( Unknown ) )
	PORT_DIPSETTING(      0x4000, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( On ) )
	PORT_DIPNAME( 0x8000, 0x8000, DEF_STR( Unknown ) )
	PORT_DIPSETTING(      0x8000, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( On ) )

	PORT_START	// IN3 - $400006
	PORT_BIT(  0xffff, IP_ACTIVE_LOW, IPT_UNKNOWN )
INPUT_PORTS_END



/***************************************************************************
                                Karate Tournament
***************************************************************************/

INPUT_PORTS_START( karatour )
	PORT_START_TAG("IN0") // $400002
	JOY_LSB(2, BUTTON1, BUTTON2, UNKNOWN, UNKNOWN)

	PORT_START_TAG("IN1") //$400004
	COINS

	PORT_START_TAG("IN2") // $400006
	PORT_DIPNAME( 0x0003, 0x0003, DEF_STR( Lives ) )
	PORT_DIPSETTING(      0x0001, "1" )
	PORT_DIPSETTING(      0x0000, "2" )
	PORT_DIPSETTING(      0x0003, "3" )
	PORT_DIPSETTING(      0x0002, "4" )
	PORT_DIPNAME( 0x000c, 0x000c, DEF_STR( Unknown ) )
	PORT_DIPSETTING(      0x000c, "11 (0)" )
	PORT_DIPSETTING(      0x0008, "10 (1)" )
	PORT_DIPSETTING(      0x0004, "01 (2)" )
	PORT_DIPSETTING(      0x0000, "00 (3)" )
	PORT_DIPNAME( 0x0010, 0x0010, "Time" )
	PORT_DIPSETTING(      0x0010, "60" )
	PORT_DIPSETTING(      0x0000, "40" )
	PORT_DIPNAME( 0x0020, 0x0020, DEF_STR( Free_Play ) )
	PORT_DIPSETTING(      0x0020, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( On ) )
	PORT_DIPNAME( 0x0040, 0x0040, DEF_STR( Allow_Continue ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( No ) )
	PORT_DIPSETTING(      0x0040, DEF_STR( Yes ) )
	PORT_DIPNAME( 0x0080, 0x0000, DEF_STR( Demo_Sounds ) )
	PORT_DIPSETTING(      0x0080, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( On ) )

	PORT_START_TAG("IN3") // $40000a
	PORT_DIPNAME( 0x0007, 0x0007, DEF_STR( Coin_A ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( 3C_1C ) )
	PORT_DIPSETTING(      0x0001, DEF_STR( 2C_1C ) )
	PORT_DIPSETTING(      0x0007, DEF_STR( 1C_1C ) )
	PORT_DIPSETTING(      0x0006, DEF_STR( 1C_2C ) )
	PORT_DIPSETTING(      0x0005, DEF_STR( 1C_3C ) )
	PORT_DIPSETTING(      0x0004, DEF_STR( 1C_4C ) )
	PORT_DIPSETTING(      0x0003, DEF_STR( 1C_5C ) )
	PORT_DIPSETTING(      0x0002, DEF_STR( 1C_6C ) )
	PORT_DIPNAME( 0x0038, 0x0038, DEF_STR( Coin_B ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( 3C_1C ) )
	PORT_DIPSETTING(      0x0008, DEF_STR( 2C_1C ) )
	PORT_DIPSETTING(      0x0038, DEF_STR( 1C_1C ) )
	PORT_DIPSETTING(      0x0030, DEF_STR( 1C_2C ) )
	PORT_DIPSETTING(      0x0028, DEF_STR( 1C_3C ) )
	PORT_DIPSETTING(      0x0020, DEF_STR( 1C_4C ) )
	PORT_DIPSETTING(      0x0018, DEF_STR( 1C_5C ) )
	PORT_DIPSETTING(      0x0010, DEF_STR( 1C_6C ) )
	PORT_DIPNAME( 0x0040, 0x0040, DEF_STR( Flip_Screen ) )
	PORT_DIPSETTING(      0x0040, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( On ) )
	PORT_SERVICE( 0x0080, IP_ACTIVE_LOW )

	PORT_START_TAG("IN4") // $40000c
	JOY_LSB(1, BUTTON1, BUTTON2, UNKNOWN, UNKNOWN)
INPUT_PORTS_END


/***************************************************************************
                                Lady Killer
***************************************************************************/

#define LKILL_COMMON1\
	PORT_START_TAG("IN0") /*$400002*/\
	JOY_LSB(2, BUTTON1, BUTTON2, UNKNOWN, UNKNOWN)\
	PORT_START_TAG("IN1") /*$400004*/\
	COINS

#define LKILL_COMMON2\
	PORT_START_TAG("IN3") /*$40000a*/\
	PORT_DIPNAME( 0x0007, 0x0007, DEF_STR( Coin_A ) )\
	PORT_DIPSETTING(      0x0000, DEF_STR( 3C_1C ) )\
	PORT_DIPSETTING(      0x0001, DEF_STR( 2C_1C ) )\
	PORT_DIPSETTING(      0x0007, DEF_STR( 1C_1C ) )\
	PORT_DIPSETTING(      0x0006, DEF_STR( 1C_2C ) )\
	PORT_DIPSETTING(      0x0005, DEF_STR( 1C_3C ) )\
	PORT_DIPSETTING(      0x0004, DEF_STR( 1C_4C ) )\
	PORT_DIPSETTING(      0x0003, DEF_STR( 1C_5C ) )\
	PORT_DIPSETTING(      0x0002, DEF_STR( 1C_6C ) )\
	PORT_DIPNAME( 0x0038, 0x0038, DEF_STR( Coin_B ) )\
	PORT_DIPSETTING(      0x0000, DEF_STR( 3C_1C ) )\
	PORT_DIPSETTING(      0x0008, DEF_STR( 2C_1C ) )\
	PORT_DIPSETTING(      0x0038, DEF_STR( 1C_1C ) )\
	PORT_DIPSETTING(      0x0030, DEF_STR( 1C_2C ) )\
	PORT_DIPSETTING(      0x0028, DEF_STR( 1C_3C ) )\
	PORT_DIPSETTING(      0x0020, DEF_STR( 1C_4C ) )\
	PORT_DIPSETTING(      0x0018, DEF_STR( 1C_5C ) )\
	PORT_DIPSETTING(      0x0010, DEF_STR( 1C_6C ) )\
	PORT_DIPNAME( 0x0040, 0x0040, DEF_STR( Flip_Screen ) )\
	PORT_DIPSETTING(      0x0040, DEF_STR( Off ) )\
	PORT_DIPSETTING(      0x0000, DEF_STR( On ) )\
	PORT_DIPNAME( 0x0080, 0x0080, DEF_STR( Unused ) )\
	PORT_DIPSETTING(      0x0080, DEF_STR( Off ) )\
	PORT_DIPSETTING(      0x0000, DEF_STR( On ) )\
	PORT_START_TAG("IN4") /*$40000c*/\
	JOY_LSB(1, BUTTON1, BUTTON2, UNKNOWN, UNKNOWN)

INPUT_PORTS_START( ladykill )
	LKILL_COMMON1
	PORT_START_TAG("IN2") // $400006
	PORT_DIPNAME( 0x0003, 0x0003, DEF_STR( Lives ) )
	PORT_DIPSETTING(      0x0001, "1" )
	PORT_DIPSETTING(      0x0000, "2" )
	PORT_DIPSETTING(      0x0003, "3" )
	PORT_DIPSETTING(      0x0002, "4" )
	PORT_DIPNAME( 0x000c, 0x000c, DEF_STR( Difficulty ) )
	PORT_DIPSETTING(      0x0008, DEF_STR( Easy ) )
	PORT_DIPSETTING(      0x000c, DEF_STR( Normal ) )
	PORT_DIPSETTING(      0x0004, DEF_STR( Hard ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( Very_Hard ) )
	PORT_DIPNAME( 0x0010, 0x0000, "Nudity" )
	PORT_DIPSETTING(      0x0010, "Partial" )
	PORT_DIPSETTING(      0x0000, "Full" )
	PORT_SERVICE( 0x0020, IP_ACTIVE_LOW )
	PORT_DIPNAME( 0x0040, 0x0040, DEF_STR( Allow_Continue ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( No ) )
	PORT_DIPSETTING(      0x0040, DEF_STR( Yes ) )
	PORT_DIPNAME( 0x0080, 0x0000, DEF_STR( Demo_Sounds ) )
	PORT_DIPSETTING(      0x0080, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( On ) )
	LKILL_COMMON2

INPUT_PORTS_END

/* Same as 'ladykill' but NO "Nudity" Dip Switch */
INPUT_PORTS_START( moegonta )
	LKILL_COMMON1

	PORT_START_TAG("IN2")	// $400006
	PORT_DIPNAME( 0x0003, 0x0003, DEF_STR( Lives ) )
	PORT_DIPSETTING(      0x0001, "1" )
	PORT_DIPSETTING(      0x0000, "2" )
	PORT_DIPSETTING(      0x0003, "3" )
	PORT_DIPSETTING(      0x0002, "4" )
	PORT_DIPNAME( 0x000c, 0x000c, DEF_STR( Difficulty ) )
	PORT_DIPSETTING(      0x0008, DEF_STR( Easy ) )
	PORT_DIPSETTING(      0x000c, DEF_STR( Normal ) )
	PORT_DIPSETTING(      0x0004, DEF_STR( Hard ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( Very_Hard ) )
	PORT_DIPNAME( 0x0010, 0x0010, DEF_STR( Unused ) )
	PORT_DIPSETTING(      0x0010, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( On ) )
	PORT_SERVICE( 0x0020, IP_ACTIVE_LOW )
	PORT_DIPNAME( 0x0040, 0x0040, DEF_STR( Allow_Continue ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( No ) )
	PORT_DIPSETTING(      0x0040, DEF_STR( Yes ) )
	PORT_DIPNAME( 0x0080, 0x0000, DEF_STR( Demo_Sounds ) )
	PORT_DIPSETTING(      0x0080, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( On ) )

	LKILL_COMMON2
	INPUT_PORTS_END


/***************************************************************************
                                Last Fortress
***************************************************************************/

/* The code which tests IN4 bit 7 is the SAME as the one for 'lastfero'.
   So WHY can't the game display cards instead of mahjong tiles ?
   Is it due to different GFX ROMS or to an emulation bug ?
*/
#define LFORT_COMMON\
	PORT_START_TAG("IN0")/*$c00004*/\
	COINS\
	PORT_START_TAG("IN1")/*$c00006*/\
	JOY_LSB(1, BUTTON1, UNKNOWN, UNKNOWN, UNKNOWN)		/* BUTTON2 and BUTTON3 in "test mode" only*/\
	PORT_START_TAG("IN2")/*$c00008*/\
	JOY_LSB(2, BUTTON1, UNKNOWN, UNKNOWN, UNKNOWN)		/*BUTTON2 and BUTTON3 in "test mode" only*/\
	PORT_START_TAG("IN3")/*$c0000a*/\
	COINAGE_DSW\


INPUT_PORTS_START( lastfort )
	LFORT_COMMON

	PORT_START_TAG("IN4")// $c0000c
	PORT_DIPNAME( 0x0003, 0x0003, DEF_STR( Difficulty ) )		// Timer speed
	PORT_DIPSETTING(      0x0000, DEF_STR( Easiest ) )			//   Slowest
	PORT_DIPSETTING(      0x0001, DEF_STR( Easy ) )				//   Slow
	PORT_DIPSETTING(      0x0003, DEF_STR( Normal ) )			//   Normal
	PORT_DIPSETTING(      0x0002, DEF_STR( Hard ) )				//   Fast
	PORT_DIPNAME( 0x0004, 0x0004, DEF_STR( Unused ) )
	PORT_DIPSETTING(      0x0004, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( On ) )
	PORT_DIPNAME( 0x0008, 0x0008, "Retry Level On Continue" )
	PORT_DIPSETTING(      0x0008, "Ask Player" )
	PORT_DIPSETTING(      0x0000, DEF_STR( Yes ) )
	PORT_DIPNAME( 0x0010, 0x0010, "2 Players Game" )
	PORT_DIPSETTING(      0x0010, "2 Credits" )
	PORT_DIPSETTING(      0x0000, "1 Credit" )
	PORT_DIPNAME( 0x0020, 0x0020, DEF_STR( Allow_Continue ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( No ) )
	PORT_DIPSETTING(      0x0020, DEF_STR( Yes ) )
	PORT_DIPNAME( 0x0040, 0x0040, DEF_STR( Demo_Sounds ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0040, DEF_STR( On ) )
	PORT_DIPNAME( 0x0080, 0x0080, "Tiles" )
	PORT_DIPSETTING(      0x0080, "Mahjong" )
//  PORT_DIPSETTING(      0x0000, "Cards" )             // Not working - See notes

	PORT_START_TAG("IN5")// $c0000e
	PORT_BIT(  0xffff, IP_ACTIVE_LOW, IPT_UNKNOWN )
INPUT_PORTS_END


/***************************************************************************
                            Last Fortress (Erotic)
***************************************************************************/

/* Same as 'lastfort' but WORKING "Tiles" Dip Switch */
INPUT_PORTS_START( lastfero )
	LFORT_COMMON

	PORT_START	// IN4 - $c0000c
	PORT_DIPNAME( 0x0003, 0x0003, DEF_STR( Difficulty ) )		// Timer speed
	PORT_DIPSETTING(      0x0000, DEF_STR( Easiest ) )			//   Slowest
	PORT_DIPSETTING(      0x0001, DEF_STR( Easy ) )				//   Slow
	PORT_DIPSETTING(      0x0003, DEF_STR( Normal ) )			//   Normal
	PORT_DIPSETTING(      0x0002, DEF_STR( Hard ) )				//   Fast
	PORT_DIPNAME( 0x0004, 0x0004, DEF_STR( Unused ) )
	PORT_DIPSETTING(      0x0004, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( On ) )
	PORT_DIPNAME( 0x0008, 0x0008, "Retry Level On Continue" )
	PORT_DIPSETTING(      0x0008, "Ask Player" )
	PORT_DIPSETTING(      0x0000, DEF_STR( Yes ) )
	PORT_DIPNAME( 0x0010, 0x0010, "2 Players Game" )
	PORT_DIPSETTING(      0x0010, "2 Credits" )
	PORT_DIPSETTING(      0x0000, "1 Credit" )
	PORT_DIPNAME( 0x0020, 0x0020, DEF_STR( Allow_Continue ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( No ) )
	PORT_DIPSETTING(      0x0020, DEF_STR( Yes ) )
	PORT_DIPNAME( 0x0040, 0x0040, DEF_STR( Demo_Sounds ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0040, DEF_STR( On ) )
	PORT_DIPNAME( 0x0080, 0x0080, "Tiles" )
	PORT_DIPSETTING(      0x0080, "Mahjong" )
	PORT_DIPSETTING(      0x0000, "Cards" )

	PORT_START	// IN5 - $c0000e
	PORT_BIT(  0xffff, IP_ACTIVE_LOW, IPT_UNKNOWN )
INPUT_PORTS_END


/***************************************************************************
                            Mahjong Doukyuusei
***************************************************************************/

#define MAHJONG_PANEL\
	PORT_START_TAG("IN0")\
	PORT_BIT( 0x0001, IP_ACTIVE_LOW, IPT_UNKNOWN )\
	PORT_BIT(0x0002, IP_ACTIVE_LOW, IPT_MAHJONG_A )\
	PORT_BIT(0x0004, IP_ACTIVE_LOW, IPT_MAHJONG_E )\
	PORT_BIT(0x0008, IP_ACTIVE_LOW, IPT_MAHJONG_I )\
	PORT_BIT(0x0010, IP_ACTIVE_LOW, IPT_MAHJONG_M )\
	PORT_BIT(0x0020, IP_ACTIVE_LOW, IPT_MAHJONG_KAN )\
	PORT_BIT( 0x0040, IP_ACTIVE_LOW, IPT_START1  )\
	PORT_BIT( 0x0080, IP_ACTIVE_LOW, IPT_UNKNOWN )\
	PORT_BIT( 0xff00, IP_ACTIVE_LOW, IPT_UNKNOWN )\
	PORT_START_TAG("IN1")\
	PORT_BIT( 0x0001, IP_ACTIVE_LOW, IPT_UNKNOWN )\
	PORT_BIT(0x0002, IP_ACTIVE_LOW, IPT_MAHJONG_B )\
	PORT_BIT(0x0004, IP_ACTIVE_LOW, IPT_MAHJONG_F )\
	PORT_BIT(0x0008, IP_ACTIVE_LOW, IPT_MAHJONG_J )\
	PORT_BIT(0x0010, IP_ACTIVE_LOW, IPT_MAHJONG_N )\
	PORT_BIT(0x0020, IP_ACTIVE_LOW, IPT_MAHJONG_REACH )\
	PORT_BIT( 0x0040, IP_ACTIVE_LOW, IPT_UNKNOWN )\
	PORT_BIT( 0x0080, IP_ACTIVE_LOW, IPT_UNKNOWN )\
	PORT_BIT( 0xff00, IP_ACTIVE_LOW, IPT_UNKNOWN )\
	PORT_START_TAG("IN2")\
	PORT_BIT( 0x0001, IP_ACTIVE_LOW, IPT_UNKNOWN )\
	PORT_BIT(0x0002, IP_ACTIVE_LOW, IPT_MAHJONG_C )\
	PORT_BIT(0x0004, IP_ACTIVE_LOW, IPT_MAHJONG_G )\
	PORT_BIT(0x0008, IP_ACTIVE_LOW, IPT_MAHJONG_K )\
	PORT_BIT(0x0010, IP_ACTIVE_LOW, IPT_MAHJONG_CHI )\
	PORT_BIT(0x0020, IP_ACTIVE_LOW, IPT_MAHJONG_RON )\
	PORT_BIT( 0x0040, IP_ACTIVE_LOW, IPT_UNKNOWN )\
	PORT_BIT( 0x0080, IP_ACTIVE_LOW, IPT_UNKNOWN )\
	PORT_BIT( 0xff00, IP_ACTIVE_LOW, IPT_UNKNOWN )\
	PORT_START_TAG("IN3")\
	PORT_BIT( 0x0001, IP_ACTIVE_LOW, IPT_UNKNOWN )\
	PORT_BIT(0x0002, IP_ACTIVE_LOW, IPT_MAHJONG_D )\
	PORT_BIT(0x0004, IP_ACTIVE_LOW, IPT_MAHJONG_H )\
	PORT_BIT(0x0008, IP_ACTIVE_LOW, IPT_MAHJONG_L )\
	PORT_BIT(0x0010, IP_ACTIVE_LOW, IPT_MAHJONG_PON )\
	PORT_BIT( 0x0020, IP_ACTIVE_LOW, IPT_UNKNOWN )\
	PORT_BIT( 0x0040, IP_ACTIVE_LOW, IPT_UNKNOWN )\
	PORT_BIT( 0x0080, IP_ACTIVE_LOW, IPT_UNKNOWN )\
	PORT_BIT( 0xff00, IP_ACTIVE_LOW, IPT_UNKNOWN )\
	PORT_START_TAG("IN4")\
	PORT_BIT( 0xffff, IP_ACTIVE_LOW, IPT_UNKNOWN )\
	PORT_START_TAG("IN5")\
	PORT_BIT( 0x0001, IP_ACTIVE_LOW, IPT_UNKNOWN )\
	PORT_BIT(  0x0002, IP_ACTIVE_LOW, IPT_COIN1 ) PORT_IMPULSE(2)\
	PORT_BIT( 0x0004, IP_ACTIVE_LOW, IPT_SERVICE1 )\
	PORT_SERVICE_NO_TOGGLE(0x0008, IP_ACTIVE_LOW )\
	PORT_BIT( 0x0010, IP_ACTIVE_LOW, IPT_UNKNOWN )\
	PORT_BIT( 0x0020, IP_ACTIVE_LOW, IPT_UNKNOWN )\
	PORT_BIT( 0x0040, IP_ACTIVE_LOW, IPT_UNKNOWN )\
	PORT_BIT( 0x0080, IP_ACTIVE_LOW, IPT_UNKNOWN )\
	PORT_BIT( 0xff00, IP_ACTIVE_LOW, IPT_UNKNOWN )



INPUT_PORTS_START( dokyusei )
	MAHJONG_PANEL

	PORT_START_TAG("IN6")	// $478884.w
	PORT_DIPNAME( 0x0300, 0x0300, DEF_STR( Difficulty ) )
	PORT_DIPSETTING(      0x0300, DEF_STR( Easy ) )
	PORT_DIPSETTING(      0x0200, DEF_STR( Normal ) )
	PORT_DIPSETTING(      0x0100, DEF_STR( Hard ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( Hardest ) )
	PORT_DIPNAME( 0x1c00, 0x1c00, DEF_STR( Coinage ) )
	PORT_DIPSETTING(      0x0400, DEF_STR( 4C_1C ) )
	PORT_DIPSETTING(      0x0800, DEF_STR( 3C_1C ) )
	PORT_DIPSETTING(      0x0c00, DEF_STR( 2C_1C ) )
	PORT_DIPSETTING(      0x1c00, DEF_STR( 1C_1C ) )
	PORT_DIPSETTING(      0x1800, DEF_STR( 1C_2C ) )
	PORT_DIPSETTING(      0x1400, DEF_STR( 1C_3C ) )
	PORT_DIPSETTING(      0x1000, DEF_STR( 1C_4C ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( Free_Play ) )
	PORT_DIPNAME( 0x2000, 0x2000, DEF_STR( Demo_Sounds ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x2000, DEF_STR( On ) )
	PORT_DIPNAME( 0x4000, 0x4000, "Game Sound" )
	PORT_DIPSETTING(      0x0000, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x4000, DEF_STR( On ) )
	PORT_DIPNAME( 0x8000, 0x8000, "Auto TSUMO after REACH" )
	PORT_DIPSETTING(      0x8000, DEF_STR( No ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( Yes ) )

	PORT_START_TAG("IN7")	// $478886.w
	PORT_DIPNAME( 0x0100, 0x0100, DEF_STR( Flip_Screen ) )
	PORT_DIPSETTING(      0x0100, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( On ) )
	PORT_DIPNAME( 0x0200, 0x0200, "CPU wears clothes on RON" )
	PORT_DIPSETTING(      0x0000, DEF_STR( No ) )
	PORT_DIPSETTING(      0x0200, DEF_STR( Yes ) )
	PORT_DIPNAME( 0x0400, 0x0400, "CPU clothes on continue play" )
	PORT_DIPSETTING(      0x0400, "Return to default" )
	PORT_DIPSETTING(      0x0000, "Keep current status" )
	PORT_SERVICE( 0x0800, IP_ACTIVE_LOW )
	PORT_DIPNAME( 0x1000, 0x0000, "Self Test" ) //!
	PORT_DIPSETTING(      0x0000, DEF_STR( No ) )
	PORT_DIPSETTING(      0x1000, DEF_STR( Yes ) )
	PORT_DIPNAME( 0x2000, 0x2000, "Unknown 2-5" )
	PORT_DIPSETTING(      0x2000, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( On ) )
	PORT_DIPNAME( 0x4000, 0x4000, "Unknown 2-6" )
	PORT_DIPSETTING(      0x4000, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( On ) )
	PORT_DIPNAME( 0x8000, 0x8000, "Unknown 2-7" )
	PORT_DIPSETTING(      0x8000, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( On ) )
INPUT_PORTS_END


/***************************************************************************
                        Mahjong Gakuensai 1 & 2
***************************************************************************/

/* Same as dokyusei, without the DSWs (these games have an eeprom) */

INPUT_PORTS_START( gakusai )

MAHJONG_PANEL

INPUT_PORTS_END


/***************************************************************************
                                    Mouja
***************************************************************************/

INPUT_PORTS_START( mouja )
	PORT_START_TAG("IN0") //$478880
	PORT_BIT(  0x0001, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT(  0x0002, IP_ACTIVE_LOW, IPT_JOYSTICK_UP ) PORT_PLAYER(1)
	PORT_BIT(  0x0004, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN ) PORT_PLAYER(1)
	PORT_BIT(  0x0008, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT ) PORT_PLAYER(1)
	PORT_BIT(  0x0010, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT ) PORT_PLAYER(1)
	PORT_BIT(  0x0020, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_PLAYER(1)
	PORT_BIT(  0x0040, IP_ACTIVE_LOW, IPT_BUTTON2 ) PORT_PLAYER(1)
	PORT_BIT(  0x0080, IP_ACTIVE_LOW, IPT_BUTTON3 ) PORT_PLAYER(1)
	PORT_BIT(  0x0100, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT(  0x0200, IP_ACTIVE_LOW, IPT_JOYSTICK_UP ) PORT_PLAYER(2)
	PORT_BIT(  0x0400, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN ) PORT_PLAYER(2)
	PORT_BIT(  0x0800, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT ) PORT_PLAYER(2)
	PORT_BIT(  0x1000, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT ) PORT_PLAYER(2)
	PORT_BIT(  0x2000, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_PLAYER(2)
	PORT_BIT(  0x4000, IP_ACTIVE_LOW, IPT_BUTTON2 ) PORT_PLAYER(2)
	PORT_BIT(  0x8000, IP_ACTIVE_LOW, IPT_BUTTON3 ) PORT_PLAYER(2)

	PORT_START_TAG("IN1") //$478882
	PORT_BIT( 0x0001, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x0002, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x0004, IP_ACTIVE_LOW, IPT_START1 )
	PORT_BIT( 0x0008, IP_ACTIVE_LOW, IPT_START2 )
	PORT_BIT(  0x0010, IP_ACTIVE_LOW, IPT_COIN1 ) PORT_IMPULSE(2)
	PORT_BIT(  0x0020, IP_ACTIVE_LOW, IPT_COIN2 ) PORT_IMPULSE(2)
	PORT_BIT( 0x0040, IP_ACTIVE_LOW, IPT_SERVICE1 )
	PORT_SERVICE_NO_TOGGLE(0x0080, IP_ACTIVE_LOW)

	PORT_START_TAG("IN2") //$478884
	PORT_DIPNAME( 0x0001, 0x0001, DEF_STR( Free_Play ) )
	PORT_DIPSETTING(      0x0001, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( On ) )
	PORT_DIPNAME( 0x0002, 0x0002, DEF_STR( Flip_Screen ) )
	PORT_DIPSETTING(      0x0002, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( On ) )
	PORT_DIPNAME( 0x0004, 0x0004, DEF_STR( Service_Mode ) )
	PORT_DIPSETTING(      0x0004, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( On ) )
	PORT_DIPNAME( 0x0008, 0x0000, DEF_STR( Demo_Sounds ) )
	PORT_DIPSETTING(      0x0008, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( On ) )
	PORT_DIPNAME( 0x0030, 0x0030, DEF_STR( Coin_A ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( 3C_1C ) )
	PORT_DIPSETTING(      0x0010, DEF_STR( 2C_1C ) )
	PORT_DIPSETTING(      0x0030, DEF_STR( 1C_1C ) )
	PORT_DIPSETTING(      0x0020, DEF_STR( 1C_2C ) )
	PORT_DIPNAME( 0x00c0, 0x00c0, DEF_STR( Coin_B ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( 3C_1C ) )
	PORT_DIPSETTING(      0x0040, DEF_STR( 2C_1C ) )
	PORT_DIPSETTING(      0x00c0, DEF_STR( 1C_1C ) )
	PORT_DIPSETTING(      0x0080, DEF_STR( 1C_2C ) )
	PORT_DIPNAME( 0x0300, 0x0300, DEF_STR( Difficulty ) )
	PORT_DIPSETTING(      0x0200, DEF_STR( Easy ) )
	PORT_DIPSETTING(      0x0300, DEF_STR( Normal ) )
	PORT_DIPSETTING(      0x0100, DEF_STR( Hard ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( Hardest ) )
	PORT_DIPNAME( 0x0400, 0x0400, DEF_STR( Allow_Continue ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( No ) )
	PORT_DIPSETTING(      0x0400, DEF_STR( Yes ) )
	PORT_DIPNAME( 0x0800, 0x0000, "Winning Rounds (Player VS Computer)" )
	PORT_DIPSETTING(      0x0800, "1/1" )
	PORT_DIPSETTING(      0x0000, "2/3" )
	PORT_DIPNAME( 0x1000, 0x1000, "Winning Rounds (Player VS Player)" )
	PORT_DIPSETTING(      0x1000, "1/1" )
	PORT_DIPSETTING(      0x0000, "2/3" )
	PORT_DIPNAME( 0x2000, 0x2000, DEF_STR( Unused ) )
	PORT_DIPSETTING(      0x2000, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( On ) )
	PORT_DIPNAME( 0x4000, 0x4000, DEF_STR( Unused ) )
	PORT_DIPSETTING(      0x4000, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( On ) )
	PORT_DIPNAME( 0x8000, 0x8000, DEF_STR( Unused ) )
	PORT_DIPSETTING(      0x8000, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( On ) )

	PORT_START_TAG("IN3") //$478886
	PORT_BIT(  0xffff, IP_ACTIVE_LOW, IPT_UNKNOWN )
INPUT_PORTS_END


/***************************************************************************
                                Pang Poms
***************************************************************************/

INPUT_PORTS_START( pangpoms )
	PORT_START_TAG("IN0") //$800004
	COINS

	PORT_START_TAG("IN1") //$800006
	JOY_LSB(1, BUTTON1, BUTTON2, UNKNOWN, UNKNOWN)

	PORT_START_TAG("IN2") //$800008
	JOY_LSB(2, BUTTON1, BUTTON2, UNKNOWN, UNKNOWN)

	PORT_START_TAG("IN3") //$80000a
	COINAGE_DSW

	PORT_START_TAG("IN4") //$80000c
	PORT_DIPNAME( 0x0003, 0x0003, "Time Speed" )
	PORT_DIPSETTING(      0x0000, "Slowest" )	// 60 (1 game sec. lasts x/60 real sec.)
	PORT_DIPSETTING(      0x0001, "Slow"    )	// 90
	PORT_DIPSETTING(      0x0003, DEF_STR( Normal )  )	// 120
	PORT_DIPSETTING(      0x0002, "Fast"    )	// 150
	PORT_DIPNAME( 0x000c, 0x000c, DEF_STR( Lives ) )
	PORT_DIPSETTING(      0x0008, "1" )
	PORT_DIPSETTING(      0x0004, "2" )
	PORT_DIPSETTING(      0x000c, "3" )
	PORT_DIPSETTING(      0x0000, "4" )
	PORT_DIPNAME( 0x0030, 0x0020, DEF_STR( Bonus_Life ) )
	PORT_DIPSETTING(      0x0020, "400k and 800k" )
	PORT_DIPSETTING(      0x0030, "400k" )
	PORT_DIPSETTING(      0x0010, "800k" )
	PORT_DIPSETTING(      0x0000, DEF_STR( None ) )
	PORT_DIPNAME( 0x0040, 0x0040, DEF_STR( Allow_Continue ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( No ) )
	PORT_DIPSETTING(      0x0040, DEF_STR( Yes ) )
	PORT_DIPNAME( 0x0080, 0x0080, DEF_STR( Demo_Sounds ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0080, DEF_STR( On ) )

	PORT_START_TAG("IN5") //$80000e
	PORT_BIT(  0xffff, IP_ACTIVE_LOW, IPT_UNKNOWN )
INPUT_PORTS_END


/***************************************************************************
                                Poitto!
***************************************************************************/

INPUT_PORTS_START( poitto )
	PORT_START_TAG("IN0") //$800000
	COINS

	PORT_START_TAG("IN1") //$800002
	JOY_LSB(1, BUTTON1, UNKNOWN, UNKNOWN, UNKNOWN)		// BUTTON2 and BUTTON3 in "test mode" only
	JOY_MSB(2, BUTTON1, UNKNOWN, UNKNOWN, UNKNOWN)		// BUTTON2 and BUTTON3 in "test mode" only

	PORT_START_TAG("IN2") //$800004
	COINAGE_DSW

	PORT_DIPNAME( 0x0300, 0x0300, DEF_STR( Difficulty ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( Easy ) )
	PORT_DIPSETTING(      0x0300, DEF_STR( Normal ) )
	PORT_DIPSETTING(      0x0200, DEF_STR( Hard ) )
	PORT_DIPSETTING(      0x0100, DEF_STR( Hardest ) )
	PORT_DIPNAME( 0x0400, 0x0400, DEF_STR( Unused ) )
	PORT_DIPSETTING(      0x0400, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( On ) )
	PORT_DIPNAME( 0x0800, 0x0800, DEF_STR( Unused ) )
	PORT_DIPSETTING(      0x0800, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( On ) )
	PORT_DIPNAME( 0x1000, 0x1000, DEF_STR( Unused ) )
	PORT_DIPSETTING(      0x1000, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( On ) )
	PORT_DIPNAME( 0x2000, 0x2000, DEF_STR( Allow_Continue ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( No ) )
	PORT_DIPSETTING(      0x2000, DEF_STR( Yes ) )
	PORT_DIPNAME( 0x4000, 0x4000, DEF_STR( Demo_Sounds ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x4000, DEF_STR( On ) )
	PORT_DIPNAME( 0x8000, 0x8000, DEF_STR( Unused ) )
	PORT_DIPSETTING(      0x8000, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( On ) )

	PORT_START_TAG("IN3") //$800006
	PORT_BIT(  0xffff, IP_ACTIVE_LOW, IPT_UNKNOWN )
INPUT_PORTS_END


/***************************************************************************
                                Puzzli
***************************************************************************/

INPUT_PORTS_START( puzzli )
	PORT_START_TAG("IN0") //$c00000
	COINS

	PORT_START_TAG("IN1") //$c00002
	JOY_LSB(1, BUTTON1, BUTTON2, UNKNOWN, UNKNOWN)		// BUTTON3 in "test mode" only
	JOY_MSB(2, BUTTON1, BUTTON2, UNKNOWN, UNKNOWN)		// BUTTON3 in "test mode" only

	PORT_START_TAG("IN2") //$c00004
	COINAGE_DSW

	PORT_DIPNAME( 0x0300, 0x0300, DEF_STR( Difficulty ) )
	PORT_DIPSETTING(      0x0200, DEF_STR( Easy ) )
	PORT_DIPSETTING(      0x0300, DEF_STR( Normal ) )
//  PORT_DIPSETTING(      0x0100, DEF_STR( Normal ) )           // Duplicated setting
	PORT_DIPSETTING(      0x0000, DEF_STR( Hard ) )
	PORT_DIPNAME( 0x0400, 0x0400, "Join In" )
	PORT_DIPSETTING(      0x0000, DEF_STR( No ) )
	PORT_DIPSETTING(      0x0400, DEF_STR( Yes ) )
	PORT_DIPNAME( 0x0800, 0x0800, "2 Players Game" )
	PORT_DIPSETTING(      0x0000, "1 Credit" )
	PORT_DIPSETTING(      0x0800, "2 Credits" )
	PORT_DIPNAME( 0x1000, 0x1000, "Winning Rounds (Player VS Player)" )
	PORT_DIPSETTING(      0x0000, "1/1" )
	PORT_DIPSETTING(      0x1000, "2/3" )
	PORT_DIPNAME( 0x2000, 0x2000, DEF_STR( Allow_Continue ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( No ) )
	PORT_DIPSETTING(      0x2000, DEF_STR( Yes ) )
	PORT_DIPNAME( 0x4000, 0x4000, DEF_STR( Demo_Sounds ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x4000, DEF_STR( On ) )
	PORT_DIPNAME( 0x8000, 0x8000, DEF_STR( Unused ) )
	PORT_DIPSETTING(      0x8000, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( On ) )

	PORT_START_TAG("IN3") //$c00006
	PORT_BIT(  0xffff, IP_ACTIVE_LOW, IPT_UNKNOWN )
INPUT_PORTS_END


/***************************************************************************
                                Sankokushi
***************************************************************************/

INPUT_PORTS_START( 3kokushi )
	PORT_START_TAG("IN0") //$c00000
	COINS

	PORT_START_TAG("IN1") //$c00002
	JOY_LSB(1, BUTTON1, BUTTON2, UNKNOWN, UNKNOWN)
	JOY_MSB(2, BUTTON1, BUTTON2, UNKNOWN, UNKNOWN)

	PORT_START_TAG("IN2") //$c00004
	PORT_DIPNAME( 0x0007, 0x0007, DEF_STR( Coin_A ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( 3C_1C ) )
	PORT_DIPSETTING(      0x0001, DEF_STR( 2C_1C ) )
	PORT_DIPSETTING(      0x0007, DEF_STR( 1C_1C ) )
	PORT_DIPSETTING(      0x0006, DEF_STR( 1C_2C ) )
	PORT_DIPSETTING(      0x0005, DEF_STR( 1C_3C ) )
	PORT_DIPSETTING(      0x0004, DEF_STR( 1C_4C ) )
	PORT_DIPSETTING(      0x0003, DEF_STR( 1C_5C ) )
	PORT_DIPSETTING(      0x0002, DEF_STR( 1C_6C ) )
	PORT_DIPNAME( 0x0038, 0x0038, DEF_STR( Coin_B ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( 3C_1C ) )
	PORT_DIPSETTING(      0x0008, DEF_STR( 2C_1C ) )
	PORT_DIPSETTING(      0x0038, DEF_STR( 1C_1C ) )
	PORT_DIPSETTING(      0x0030, DEF_STR( 1C_2C ) )
	PORT_DIPSETTING(      0x0028, DEF_STR( 1C_3C ) )
	PORT_DIPSETTING(      0x0020, DEF_STR( 1C_4C ) )
	PORT_DIPSETTING(      0x0018, DEF_STR( 1C_5C ) )
	PORT_DIPSETTING(      0x0010, DEF_STR( 1C_6C ) )
	PORT_DIPNAME( 0x0040, 0x0040, DEF_STR( Flip_Screen ) )
	PORT_DIPSETTING(      0x0040, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( On ) )
	PORT_DIPNAME( 0x0080, 0x0080, DEF_STR( Demo_Sounds ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0080, DEF_STR( On ) )
	PORT_DIPNAME( 0x0300, 0x0300, DEF_STR( Difficulty ) )		// Timer speed
	PORT_DIPSETTING(      0x0200, DEF_STR( Easy ) )				//   Slow
	PORT_DIPSETTING(      0x0300, DEF_STR( Normal ) )				//   Normal
	PORT_DIPSETTING(      0x0100, DEF_STR( Hard ) )				//   Fast
	PORT_DIPSETTING(      0x0000, DEF_STR( Hardest ) )				//   Fastest
	PORT_DIPNAME( 0x0400, 0x0400, DEF_STR( Unused ) )
	PORT_DIPSETTING(      0x0400, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( On ) )
	PORT_DIPNAME( 0x0800, 0x0800, DEF_STR( Unused ) )
	PORT_DIPSETTING(      0x0800, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( On ) )
	PORT_DIPNAME( 0x1000, 0x1000, DEF_STR( Allow_Continue ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( No ) )
	PORT_DIPSETTING(      0x1000, DEF_STR( Yes ) )
	PORT_DIPNAME( 0x2000, 0x2000, DEF_STR( Free_Play ) )
	PORT_DIPSETTING(      0x2000, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( On ) )
	PORT_DIPNAME( 0xc000, 0xc000, "Helps" )
	PORT_DIPSETTING(      0x0000, "1" )
	PORT_DIPSETTING(      0x4000, "2" )
	PORT_DIPSETTING(      0xc000, "3" )
	PORT_DIPSETTING(      0x8000, "4" )
INPUT_PORTS_END


/***************************************************************************
                                Pururun
***************************************************************************/

INPUT_PORTS_START( pururun )
	PORT_START_TAG("IN0") //$400000
	COINS

	PORT_START_TAG("IN1") //$400002
	JOY_LSB(1, BUTTON1, BUTTON2, UNKNOWN, UNKNOWN)		// BUTTON3 in "test mode" only
	JOY_MSB(2, BUTTON1, BUTTON2, UNKNOWN, UNKNOWN)		// BUTTON3 in "test mode" only

	PORT_START_TAG("IN2") //$400004
	COINAGE_DSW

	PORT_DIPNAME( 0x0300, 0x0300, DEF_STR( Difficulty ) )		// Distance to goal
	PORT_DIPSETTING(      0x0200, DEF_STR( Easiest ) )
	PORT_DIPSETTING(      0x0100, DEF_STR( Easy ) )
	PORT_DIPSETTING(      0x0300, DEF_STR( Normal ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( Hard ) )
	PORT_DIPNAME( 0x0400, 0x0400, "Join In" )
	PORT_DIPSETTING(      0x0000, DEF_STR( No ) )
	PORT_DIPSETTING(      0x0400, DEF_STR( Yes ) )
	PORT_DIPNAME( 0x0800, 0x0800, "2 Players Game" )
	PORT_DIPSETTING(      0x0000, "1 Credit" )
	PORT_DIPSETTING(      0x0800, "2 Credits" )
	PORT_DIPNAME( 0x1000, 0x1000, "Bombs" )
	PORT_DIPSETTING(      0x1000, "1" )
	PORT_DIPSETTING(      0x0000, "2" )
	PORT_DIPNAME( 0x2000, 0x2000, DEF_STR( Allow_Continue ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( No ) )
	PORT_DIPSETTING(      0x2000, DEF_STR( Yes ) )
	PORT_DIPNAME( 0x4000, 0x4000, DEF_STR( Demo_Sounds ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x4000, DEF_STR( On ) )
	PORT_DIPNAME( 0x8000, 0x8000, DEF_STR( Unused ) )
	PORT_DIPSETTING(      0x8000, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( On ) )

	PORT_START	// IN3 - $400006
	PORT_BIT(  0xffff, IP_ACTIVE_LOW, IPT_UNKNOWN )
INPUT_PORTS_END


/***************************************************************************
                                Sky Alert
***************************************************************************/

/* The game shows wrong values on screen for the "Bonus Life" Dip Switch !
   The wrong values are text which is stored at 0x02671a, and to determine
   which text to display, the routine at 0x0022f2 is called.
   The REAL "Bonus Life" table is stored at 0x0097f6, and to determine what
   are the values, the routine at 0x00974e is called.

   Here is the correspondance between real and fake values :

        Real         Fake
     100K, 400K   100K, 400K
     200K, 400K    50K, 300K
     200K         150K, 500K
       "none"       "none"

*/
INPUT_PORTS_START( skyalert )
	PORT_START_TAG("IN0") //$400004
	COINS

	PORT_START_TAG("IN1") //$400006
	JOY_LSB(1, BUTTON1, BUTTON2, UNKNOWN, UNKNOWN)		// BUTTON3 in "test mode" only

	PORT_START_TAG("IN2") //$400008
	JOY_LSB(2, BUTTON1, BUTTON2, UNKNOWN, UNKNOWN)		// BUTTON3 in "test mode" only

	PORT_START_TAG("IN3") //$40000a
	COINAGE_DSW

	PORT_START_TAG("IN4") //$40000c
	PORT_DIPNAME( 0x0003, 0x0003, DEF_STR( Difficulty ) )
	PORT_DIPSETTING(      0x0002, DEF_STR( Easy ) )
	PORT_DIPSETTING(      0x0003, DEF_STR( Normal ) )
	PORT_DIPSETTING(      0x0001, DEF_STR( Hard ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( Hardest ) )
	PORT_DIPNAME( 0x000c, 0x000c, DEF_STR( Lives ) )
	PORT_DIPSETTING(      0x0008, "1" )
	PORT_DIPSETTING(      0x0004, "2" )
	PORT_DIPSETTING(      0x000c, "3" )
	PORT_DIPSETTING(      0x0000, "4" )
	PORT_DIPNAME( 0x0030, 0x0030, DEF_STR( Bonus_Life ) )		// See notes
	PORT_DIPSETTING(      0x0030, "100K, every 400K" )
	PORT_DIPSETTING(      0x0020, "200K, every 400K" )
	PORT_DIPSETTING(      0x0010, "200K" )
	PORT_DIPSETTING(      0x0000, DEF_STR( None ) )
	PORT_DIPNAME( 0x0040, 0x0040, DEF_STR( Allow_Continue ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( No ) )
	PORT_DIPSETTING(      0x0040, DEF_STR( Yes ) )
	PORT_DIPNAME( 0x0080, 0x0080, DEF_STR( Demo_Sounds ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0080, DEF_STR( On ) )

	PORT_START_TAG("IN5") //$40000e
	PORT_BIT(  0xffff, IP_ACTIVE_LOW, IPT_UNKNOWN )
INPUT_PORTS_END


/***************************************************************************
                            Toride II Adauchi Gaiden
***************************************************************************/

/* I don't really know HOW to describe the effect of IN2 bit 10.
   All I can tell is that is that it affects the levels which are
   proposed, but there is no evidence that one "table" is harder
   than another. */
INPUT_PORTS_START( toride2g )
	PORT_START_TAG("IN0") //$800000
	COINS

	PORT_START_TAG("IN1") //$800002
	JOY_LSB(1, BUTTON1, UNKNOWN, UNKNOWN, UNKNOWN)		// BUTTON2 and BUTTON3 in "test mode" only
	JOY_MSB(2, BUTTON1, UNKNOWN, UNKNOWN, UNKNOWN)		// BUTTON2 and BUTTON3 in "test mode" only

	PORT_START_TAG("IN2") //$800004
	COINAGE_DSW

	PORT_DIPNAME( 0x0300, 0x0300, DEF_STR( Difficulty ) )
	PORT_DIPSETTING(      0x0200, DEF_STR( Easy ) )
	PORT_DIPSETTING(      0x0300, DEF_STR( Normal ) )
	PORT_DIPSETTING(      0x0100, DEF_STR( Hard ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( Hardest ) )
	PORT_DIPNAME( 0x0400, 0x0400, "Levels" )				// See notes
	PORT_DIPSETTING(      0x0400, "Table 1" )
	PORT_DIPSETTING(      0x0000, "Table 2" )
	PORT_DIPNAME( 0x0800, 0x0000, "Retry Level On Continue" )
	PORT_DIPSETTING(      0x0000, "Ask Player" )
	PORT_DIPSETTING(      0x0800, DEF_STR( Yes ) )
	PORT_DIPNAME( 0x1000, 0x1000, "2 Players Game" )
	PORT_DIPSETTING(      0x1000, "2 Credits" )
	PORT_DIPSETTING(      0x0000, "1 Credit" )
	PORT_DIPNAME( 0x2000, 0x2000, DEF_STR( Allow_Continue ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( No ) )
	PORT_DIPSETTING(      0x2000, DEF_STR( Yes ) )
	PORT_DIPNAME( 0x4000, 0x4000, DEF_STR( Demo_Sounds ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x4000, DEF_STR( On ) )
	PORT_DIPNAME( 0x8000, 0x8000, DEF_STR( Unused ) )
	PORT_DIPSETTING(      0x8000, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( On ) )

	PORT_START_TAG("IN3") //$800006
	PORT_BIT(  0xffff, IP_ACTIVE_LOW, IPT_UNKNOWN )	// BIT 6 !?
INPUT_PORTS_END



/***************************************************************************


                                Game Drivers


***************************************************************************/

/*     year  rom       clone     machine   inputs    init */
GAME( 1992, karatour, 0,        karatour, karatour, karatour, ROT0,   "Mitchell",                   "The Karate Tournament",           GAME_IMPERFECT_GRAPHICS )
GAME( 1992, pangpoms, 0,        pangpoms, pangpoms, metro,    ROT0,   "Metro",                      "Pang Poms"                          , 0 )
GAME( 1992, pangpomm, pangpoms, pangpoms, pangpoms, metro,    ROT0,   "Metro (Mitchell license)",   "Pang Poms (Mitchell)"               , 0 )
GAME( 1992, skyalert, 0,        skyalert, skyalert, metro,    ROT270, "Metro",                      "Sky Alert"                          , 0 )
GAME( 1993?,ladykill, 0,        karatour, ladykill, karatour, ROT90,  "Yanyaka (Mitchell license)", "Lady Killer",                     GAME_IMPERFECT_GRAPHICS )
GAME( 1993?,moegonta, ladykill, karatour, moegonta, karatour, ROT90,  "Yanyaka",                    "Moeyo Gonta!! (Japan)",           GAME_IMPERFECT_GRAPHICS )
GAME( 1993, poitto,   0,        poitto,   poitto,   metro,    ROT0,   "Metro / Able Corp.",         "Poitto!"                            , 0 )
GAME( 1994, dharma,   0,        dharma,   dharma,   metro,    ROT0,   "Metro",                      "Dharma Doujou"                      , 0 )
GAME( 1994, lastfort, 0,        lastfort, lastfort, metro,    ROT0,   "Metro",                      "Last Fortress - Toride"             , 0 )
GAME( 1994, lastfero, lastfort, lastfort, lastfero, metro,    ROT0,   "Metro",                      "Last Fortress - Toride (Erotic)"    , 0 )
GAME( 1994, lastforg, lastfort, lastforg, ladykill, metro,    ROT0,   "Metro",                      "Last Fortress - Toride (German)"    , 0 )
GAME( 1994, toride2g, 0,        toride2g, toride2g, metro,    ROT0,   "Metro",                      "Toride II Adauchi Gaiden",        GAME_IMPERFECT_GRAPHICS )
GAME( 1994, torid2gg, toride2g, toride2g, toride2g, metro,    ROT0,   "Metro",                      "Toride II Adauchi Gaiden (German)", GAME_IMPERFECT_GRAPHICS )
GAME( 1994, gunmast,  0,        pururun,  gunmast,  daitorid, ROT0,   "Metro",                      "Gun Master"                      , 0 )
GAME( 1995, daitorid, 0,        daitorid, daitorid, daitorid, ROT0,   "Metro",                      "Daitoride",                       GAME_IMPERFECT_GRAPHICS )
GAME( 1995, dokyusei, 0,        dokyusei, dokyusei, gakusai,  ROT0,   "Make Software / Elf / Media Trading", "Mahjong Doukyuusei"        , 0 )
GAME( 1995, dokyusp,  0,        dokyusp,  gakusai,  gakusai,  ROT0,   "Make Software / Elf / Media Trading", "Mahjong Doukyuusei Special", 0 )
GAME( 1995, pururun,  0,        pururun,  pururun,  daitorid, ROT0,   "Metro / Banpresto",          "Pururun"                            , 0 )
GAME( 1995, puzzli,   0,        daitorid, puzzli,   daitorid, ROT0,   "Metro / Banpresto",          "Puzzli",                          GAME_IMPERFECT_GRAPHICS )
GAME( 1996, 3kokushi, 0,        3kokushi, 3kokushi, karatour, ROT0,   "Mitchell",                   "Sankokushi (Japan)",              GAME_IMPERFECT_GRAPHICS )
GAME( 1996, balcube,  0,        balcube,  balcube,  balcube,  ROT0,   "Metro",                      "Bal Cube"                           , 0 )
GAME( 1996, bangball, 0,        bangball, bangball, balcube,  ROT0,   "Banpresto / Kunihiko Tashiro+Goodhouse", "Bang Bang Ball (v1.05)" , 0 )
GAME( 1999, batlbubl, bangball, batlbubl, batlbubl, balcube,  ROT0,   "Limenko",                    "Battle Bubble (v2.00)" , 0 )
GAME( 1996, mouja,    0,        mouja,    mouja,    mouja,    ROT0,   "Etona",                      "Mouja (Japan)",                   GAME_NO_COCKTAIL )
GAME( 1997, gakusai,  0,        gakusai,  gakusai,  gakusai,  ROT0,   "MakeSoft",                   "Mahjong Gakuensai (Japan)",       GAME_IMPERFECT_GRAPHICS )
GAME( 1998, gakusai2, 0,        gakusai2, gakusai,  gakusai,  ROT0,   "MakeSoft",                   "Mahjong Gakuensai 2 (Japan)"        , 0 )

GAME( 1994, blzntrnd, 0,        blzntrnd, blzntrnd, blzntrnd, ROT0,   "Human Amusement",            "Blazing Tornado",                 GAME_IMPERFECT_GRAPHICS )
GAME( 1996, gstrik2,  0,        gstrik2,  gstrik2,  blzntrnd, ROT0,   "Human Amusement",            "Grand Striker 2 (Japan)",			GAME_IMPERFECT_GRAPHICS ) // priority between rounds
