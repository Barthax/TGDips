# MAME 0.106 source snippet


#include "driver.h"
#include "vidhrdw/crtc6845.h"
#include "cpu/tms32010/tms32010.h"
#include "twincobr.h"
#include "sound/3812intf.h"


/*****************************************************************************
    Input Port definitions

    There is a test mode for button/switch tests. To enter Test mode,
    set the Cross Hatch Pattern DSW to on, restart and then press
    player 1 start button when in the cross-hatch screen.
*****************************************************************************/

#define  WARDNER_PLAYER_INPUT( player )										 \
	PORT_START 				/* Player 1 button 3 skips video RAM tests */	 \
	PORT_BIT( 0x01, IP_ACTIVE_HIGH, IPT_JOYSTICK_UP ) PORT_PLAYER(player) PORT_8WAY \
	PORT_BIT( 0x02, IP_ACTIVE_HIGH, IPT_JOYSTICK_DOWN ) PORT_PLAYER(player) PORT_8WAY \
	PORT_BIT( 0x04, IP_ACTIVE_HIGH, IPT_JOYSTICK_LEFT ) PORT_PLAYER(player) PORT_8WAY \
	PORT_BIT( 0x08, IP_ACTIVE_HIGH, IPT_JOYSTICK_RIGHT ) PORT_PLAYER(player) PORT_8WAY \
	PORT_BIT( 0x10, IP_ACTIVE_HIGH, IPT_BUTTON1 ) PORT_PLAYER(player)	/* Fire */		 \
	PORT_BIT( 0x20, IP_ACTIVE_HIGH, IPT_BUTTON2 ) PORT_PLAYER(player)	/* Jump */		 \
	PORT_BIT( 0x40, IP_ACTIVE_HIGH, IPT_BUTTON3 ) PORT_PLAYER(player)	/* Shot C */	 \
	PORT_BIT( 0x80, IP_ACTIVE_HIGH, IPT_BUTTON4 ) PORT_PLAYER(player)	/* Shot D */

#define  WARDNER_SYSTEM_INPUTS												\
	PORT_START				/* test button doesnt seem to do anything ? */	\
	PORT_BIT( 0x01, IP_ACTIVE_HIGH, IPT_COIN3 )		/* Service button */	\
	PORT_BIT( 0x02, IP_ACTIVE_HIGH, IPT_TILT )								\
	PORT_BIT( 0x04, IP_ACTIVE_HIGH, IPT_UNUSED )	/* Test button */		\
	PORT_BIT( 0x08, IP_ACTIVE_HIGH, IPT_COIN1 )								\
	PORT_BIT( 0x10, IP_ACTIVE_HIGH, IPT_COIN2 )								\
	PORT_BIT( 0x20, IP_ACTIVE_HIGH, IPT_START1 )							\
	PORT_BIT( 0x40, IP_ACTIVE_HIGH, IPT_START2 )							\
	PORT_BIT( 0x80, IP_ACTIVE_HIGH, IPT_VBLANK )	/* V-Blank */

#define  PYROS_DSW_A									\
	PORT_START		/* DSW A */							\
	PORT_DIPNAME( 0x01, 0x01, DEF_STR( Cabinet ) )		\
	PORT_DIPSETTING(	0x01, DEF_STR( Upright ) )		\
	PORT_DIPSETTING(	0x00, DEF_STR( Cocktail ) )		\
	PORT_DIPNAME( 0x02, 0x00, DEF_STR( Flip_Screen ) )	\
	PORT_DIPSETTING(	0x00, DEF_STR( Off ) )			\
	PORT_DIPSETTING(	0x02, DEF_STR( On ) )			\
	PORT_DIPNAME( 0x04, 0x00, "Cross Hatch Pattern" )	\
	PORT_DIPSETTING(	0x00, DEF_STR( Off ) )			\
	PORT_DIPSETTING(	0x04, DEF_STR( On ) )			\
	PORT_DIPNAME( 0x08, 0x00, DEF_STR( Demo_Sounds ) )	\
	PORT_DIPSETTING(	0x08, DEF_STR( Off ) )			\
	PORT_DIPSETTING(	0x00, DEF_STR( On ) )			\
	PORT_DIPNAME( 0x30, 0x00, DEF_STR( Coin_A ) )		\
	PORT_DIPSETTING(	0x20, DEF_STR( 2C_1C ) )		\
	PORT_DIPSETTING(	0x00, DEF_STR( 1C_1C ) )		\
	PORT_DIPSETTING(	0x30, DEF_STR( 2C_3C ) )		\
	PORT_DIPSETTING(	0x10, DEF_STR( 1C_2C ) )		\
	PORT_DIPNAME( 0xc0, 0x00, DEF_STR( Coin_B ) )		\
	PORT_DIPSETTING(	0x80, DEF_STR( 2C_1C ) )		\
	PORT_DIPSETTING(	0x00, DEF_STR( 1C_1C ) )		\
	PORT_DIPSETTING(	0xc0, DEF_STR( 2C_3C ) )		\
	PORT_DIPSETTING(	0x40, DEF_STR( 1C_2C ) )

#define  WARDNER_DSW_B									\
	PORT_START		/* DSW B */							\
	PORT_DIPNAME( 0x03, 0x00, DEF_STR( Difficulty ) )	\
	PORT_DIPSETTING(	0x01, DEF_STR( Easy ) )					\
	PORT_DIPSETTING(	0x00, DEF_STR( Normal ) )				\
	PORT_DIPSETTING(	0x02, DEF_STR( Hard ) )					\
	PORT_DIPSETTING(	0x03, DEF_STR( Hardest ) )				\
	PORT_DIPNAME( 0x0c, 0x00, DEF_STR( Bonus_Life ) )	\
	PORT_DIPSETTING(	0x00, "30000 & 80000" )			\
	PORT_DIPSETTING(	0x04, "50000 & 100000" )		\
	PORT_DIPSETTING(	0x08, "30000" )					\
	PORT_DIPSETTING(	0x0c, "50000" )					\
	PORT_DIPNAME( 0x30, 0x00, DEF_STR( Lives ) )		\
	PORT_DIPSETTING(	0x30, "1" )						\
	PORT_DIPSETTING(	0x00, "3" )						\
	PORT_DIPSETTING(	0x10, "4" )						\
	PORT_DIPSETTING(	0x20, "5" )						\
	PORT_DIPNAME( 0x40, 0x00, DEF_STR( Unknown ) )		\
	PORT_DIPSETTING(	0x00, DEF_STR( Off ) )			\
	PORT_DIPSETTING(	0x40, DEF_STR( On ) )			\
	PORT_DIPNAME( 0x80, 0x00, DEF_STR( Unknown ) )		\
	PORT_DIPSETTING(	0x00, DEF_STR( Off ) )			\
	PORT_DIPSETTING(	0x80, DEF_STR( On ) )



INPUT_PORTS_START( wardner )
	WARDNER_SYSTEM_INPUTS
	WARDNER_PLAYER_INPUT( 1 )
	WARDNER_PLAYER_INPUT( 2 )

	PORT_START		/* DSW A */
	PORT_DIPNAME( 0x01, 0x01, DEF_STR( Cabinet ) )
	PORT_DIPSETTING(	0x01, DEF_STR( Upright ) )
	PORT_DIPSETTING(	0x00, DEF_STR( Cocktail ) )
	PORT_DIPNAME( 0x02, 0x00, DEF_STR( Flip_Screen ) )
	PORT_DIPSETTING(	0x00, DEF_STR( Off ) )
	PORT_DIPSETTING(	0x02, DEF_STR( On ) )
	PORT_DIPNAME( 0x04, 0x00, "Cross Hatch Pattern" )
	PORT_DIPSETTING(	0x00, DEF_STR( Off ) )
	PORT_DIPSETTING(	0x04, DEF_STR( On ) )
	PORT_DIPNAME( 0x08, 0x00, DEF_STR( Demo_Sounds ) )
	PORT_DIPSETTING(	0x08, DEF_STR( Off ) )
	PORT_DIPSETTING(	0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x30, 0x00, DEF_STR( Coin_A ) )
	PORT_DIPSETTING(	0x30, DEF_STR( 4C_1C ) )
	PORT_DIPSETTING(	0x20, DEF_STR( 3C_1C ) )
	PORT_DIPSETTING(	0x10, DEF_STR( 2C_1C ) )
	PORT_DIPSETTING(	0x00, DEF_STR( 1C_1C ) )
	PORT_DIPNAME( 0xc0, 0x00, DEF_STR( Coin_B ) )
	PORT_DIPSETTING(	0x00, DEF_STR( 1C_2C ) )
	PORT_DIPSETTING(	0x40, DEF_STR( 1C_3C ) )
	PORT_DIPSETTING(	0x80, DEF_STR( 1C_4C ) )
	PORT_DIPSETTING(	0xc0, DEF_STR( 1C_6C ) )

	WARDNER_DSW_B
INPUT_PORTS_END

INPUT_PORTS_START( pyros )
	WARDNER_SYSTEM_INPUTS
	WARDNER_PLAYER_INPUT( 1 )
	WARDNER_PLAYER_INPUT( 2 )
	PYROS_DSW_A

	PORT_START		/* DSW B */
	PORT_DIPNAME( 0x03, 0x00, DEF_STR( Difficulty ) )
	PORT_DIPSETTING(	0x01, DEF_STR( Easy ) )
	PORT_DIPSETTING(	0x00, DEF_STR( Normal ) )
	PORT_DIPSETTING(	0x02, DEF_STR( Hard ) )
	PORT_DIPSETTING(	0x03, DEF_STR( Hardest ) )
	PORT_DIPNAME( 0x0c, 0x00, DEF_STR( Bonus_Life ) )
	PORT_DIPSETTING(	0x00, "30000 & 80000" )
	PORT_DIPSETTING(	0x04, "50000 & 100000" )
	PORT_DIPSETTING(	0x08, "50000" )
	PORT_DIPSETTING(	0x0c, "100000" )
	PORT_DIPNAME( 0x30, 0x00, DEF_STR( Lives ) )
	PORT_DIPSETTING(	0x30, "1" )
	PORT_DIPSETTING(	0x00, "3" )
	PORT_DIPSETTING(	0x10, "4" )
	PORT_DIPSETTING(	0x20, "5" )
	PORT_DIPNAME( 0x40, 0x00, DEF_STR( Allow_Continue ) )
	PORT_DIPSETTING(	0x40, DEF_STR( No ) )
	PORT_DIPSETTING(	0x00, DEF_STR( Yes ) )
	PORT_DIPNAME( 0x80, 0x00, DEF_STR( Unknown ) )
	PORT_DIPSETTING(	0x00, DEF_STR( Off ) )
	PORT_DIPSETTING(	0x80, DEF_STR( On ) )
INPUT_PORTS_END

INPUT_PORTS_START( wardnerj )
	WARDNER_SYSTEM_INPUTS
	WARDNER_PLAYER_INPUT( 1 )
	WARDNER_PLAYER_INPUT( 2 )
	PYROS_DSW_A
	WARDNER_DSW_B
INPUT_PORTS_END



GAME( 1987, wardner,  0,       wardner, wardner,  wardner, ROT0, "[Toaplan] Taito Corporation Japan", "Wardner (World)", 0 )
GAME( 1987, pyros,    wardner, wardner, pyros,    wardner, ROT0, "[Toaplan] Taito America Corporation", "Pyros (US)", 0 )
GAME( 1987, wardnerj, wardner, wardner, wardnerj, wardner, ROT0, "[Toaplan] Taito Corporation", "Wardner no Mori (Japan)", 0 )
