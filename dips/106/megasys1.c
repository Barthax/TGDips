#include "megasys1.h"

/* from megasys1.h *********************************************************/

/* IN0 - COINS */
#define COINS \
	PORT_START_TAG("IN0")\
	PORT_BIT(  0x01, IP_ACTIVE_LOW, IPT_START1 )\
	PORT_BIT(  0x02, IP_ACTIVE_LOW, IPT_START2 )\
	PORT_BIT(  0x04, IP_ACTIVE_LOW, IPT_UNKNOWN )\
	PORT_BIT(  0x08, IP_ACTIVE_LOW, IPT_UNKNOWN )\
	PORT_BIT(  0x10, IP_ACTIVE_LOW, IPT_UNKNOWN )\
	PORT_BIT(  0x20, IP_ACTIVE_LOW, IPT_SERVICE1 )\
	PORT_BIT(  0x40, IP_ACTIVE_LOW, IPT_COIN1 )\
	PORT_BIT(  0x80, IP_ACTIVE_LOW, IPT_COIN2 )

/* IN1/3 - PLAYER 1/2 */
#define JOY_4BUTTONS(_flag_) \
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT) PORT_8WAY PORT_PLAYER(_flag_)\
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT) PORT_8WAY PORT_PLAYER(_flag_)\
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN) PORT_8WAY PORT_PLAYER(_flag_)\
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_JOYSTICK_UP) PORT_8WAY PORT_PLAYER(_flag_)\
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_BUTTON1) PORT_PLAYER(_flag_)\
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_BUTTON2) PORT_PLAYER(_flag_)\
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_BUTTON3) PORT_PLAYER(_flag_)\
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_BUTTON4) PORT_PLAYER(_flag_)

#define JOY_3BUTTONS(_flag_) \
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT) PORT_8WAY PORT_PLAYER(_flag_)\
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT) PORT_8WAY PORT_PLAYER(_flag_)\
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN) PORT_8WAY PORT_PLAYER(_flag_)\
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_JOYSTICK_UP) PORT_8WAY PORT_PLAYER(_flag_)\
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_BUTTON1) PORT_PLAYER(_flag_)\
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_BUTTON2) PORT_PLAYER(_flag_)\
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_BUTTON3) PORT_PLAYER(_flag_)\
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_UNKNOWN)

#define JOY_2BUTTONS(_flag_) \
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT) PORT_8WAY PORT_PLAYER(_flag_)\
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT) PORT_8WAY PORT_PLAYER(_flag_)\
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN) PORT_8WAY PORT_PLAYER(_flag_)\
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_JOYSTICK_UP) PORT_8WAY PORT_PLAYER(_flag_)\
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_BUTTON1) PORT_PLAYER(_flag_)\
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_BUTTON2) PORT_PLAYER(_flag_)\
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_UNKNOWN) \
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_UNKNOWN)

/* IN2 - RESERVE */
#define RESERVE \
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_UNKNOWN ) /* Reserve 1P */\
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_UNKNOWN )\
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_UNKNOWN )\
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_UNKNOWN )\
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_UNKNOWN ) /* Reserve 2P */\
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_UNKNOWN )\
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_UNKNOWN )\
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_UNKNOWN )

/* IN4 - Coinage DSWs */
//  1]  01-41 02-31 03-21 07-11 06-12 05-13 04-14 00-FC * 2
//  2]  04-31 02-21 07-11 03-12 05-13 01-14 06-15 00-FC
//      00-41 20-31 10-21 38-11 18-12 28-13 08-14 30-15


#define COINAGE_6BITS \
	PORT_DIPNAME( 0x07, 0x07, DEF_STR( Coin_A ) )\
	PORT_DIPSETTING(    0x04, DEF_STR( 3C_1C ) )\
	PORT_DIPSETTING(    0x02, DEF_STR( 2C_1C ) )\
	PORT_DIPSETTING(    0x07, DEF_STR( 1C_1C ) )\
	PORT_DIPSETTING(    0x03, DEF_STR( 1C_2C ) )\
	PORT_DIPSETTING(    0x05, DEF_STR( 1C_3C ) )\
	PORT_DIPSETTING(    0x01, DEF_STR( 1C_4C ) )\
	PORT_DIPSETTING(    0x06, DEF_STR( 1C_5C ) )\
	PORT_DIPSETTING(    0x00, DEF_STR( Free_Play ) )\
	PORT_DIPNAME( 0x38, 0x38, DEF_STR( Coin_B ) )\
	PORT_DIPSETTING(    0x00, DEF_STR( 4C_1C ) )\
	PORT_DIPSETTING(    0x20, DEF_STR( 3C_1C ) )\
	PORT_DIPSETTING(    0x10, DEF_STR( 2C_1C ) )\
	PORT_DIPSETTING(    0x38, DEF_STR( 1C_1C ) )\
	PORT_DIPSETTING(    0x18, DEF_STR( 1C_2C ) )\
	PORT_DIPSETTING(    0x28, DEF_STR( 1C_3C ) )\
	PORT_DIPSETTING(    0x08, DEF_STR( 1C_4C ) )\
	PORT_DIPSETTING(    0x30, DEF_STR( 1C_5C ) )\

#define COINAGE_6BITS_2 \
	PORT_DIPNAME( 0x07, 0x07, DEF_STR( Coin_A ) )\
	PORT_DIPSETTING(    0x01, DEF_STR( 4C_1C ) )\
	PORT_DIPSETTING(    0x02, DEF_STR( 3C_1C ) )\
	PORT_DIPSETTING(    0x03, DEF_STR( 2C_1C ) )\
	PORT_DIPSETTING(    0x07, DEF_STR( 1C_1C ) )\
	PORT_DIPSETTING(    0x06, DEF_STR( 1C_2C ) )\
	PORT_DIPSETTING(    0x05, DEF_STR( 1C_3C ) )\
	PORT_DIPSETTING(    0x04, DEF_STR( 1C_4C ) )\
	PORT_DIPSETTING(    0x00, DEF_STR( Free_Play ) )\
	PORT_DIPNAME( 0x38, 0x38, DEF_STR( Coin_B ) )\
	PORT_DIPSETTING(    0x08, DEF_STR( 4C_1C ) )\
	PORT_DIPSETTING(    0x10, DEF_STR( 3C_1C ) )\
	PORT_DIPSETTING(    0x18, DEF_STR( 2C_1C ) )\
	PORT_DIPSETTING(    0x38, DEF_STR( 1C_1C ) )\
	PORT_DIPSETTING(    0x30, DEF_STR( 1C_2C ) )\
	PORT_DIPSETTING(    0x28, DEF_STR( 1C_3C ) )\
	PORT_DIPSETTING(    0x20, DEF_STR( 1C_4C ) )\
	PORT_DIPSETTING(    0x00, DEF_STR( Free_Play ) )\

#define COINAGE_8BITS \
	PORT_DIPNAME( 0x0f, 0x0f, DEF_STR( Coin_A ) )\
	PORT_DIPSETTING(    0x07, DEF_STR( 4C_1C ) )\
	PORT_DIPSETTING(    0x08, DEF_STR( 3C_1C ) )\
	PORT_DIPSETTING(    0x09, DEF_STR( 2C_1C ) )\
	PORT_DIPSETTING(    0x0f, DEF_STR( 1C_1C ) )\
/*  PORT_DIPSETTING(    0x05, DEF_STR( 1C_1C ) )*/	\
/*  PORT_DIPSETTING(    0x04, DEF_STR( 1C_1C ) )*/	\
/*  PORT_DIPSETTING(    0x03, DEF_STR( 1C_1C ) )*/	\
/*  PORT_DIPSETTING(    0x02, DEF_STR( 1C_1C ) )*/	\
/*  PORT_DIPSETTING(    0x01, DEF_STR( 1C_1C ) )*/	\
	PORT_DIPSETTING(    0x06, DEF_STR( 2C_3C ) )\
	PORT_DIPSETTING(    0x0e, DEF_STR( 1C_2C ) )\
	PORT_DIPSETTING(    0x0d, DEF_STR( 1C_3C ) )\
	PORT_DIPSETTING(    0x0c, DEF_STR( 1C_4C ) )\
	PORT_DIPSETTING(    0x0b, DEF_STR( 1C_5C ) )\
	PORT_DIPSETTING(    0x0a, DEF_STR( 1C_6C ) )\
	PORT_DIPSETTING(    0x00, DEF_STR( Free_Play ) )\
	PORT_DIPNAME( 0xf0, 0xf0, DEF_STR( Coin_B ) )\
	PORT_DIPSETTING(    0x70, DEF_STR( 4C_1C ) )\
	PORT_DIPSETTING(    0x80, DEF_STR( 3C_1C ) )\
	PORT_DIPSETTING(    0x90, DEF_STR( 2C_1C ) )\
	PORT_DIPSETTING(    0xf0, DEF_STR( 1C_1C ) )\
/*  PORT_DIPSETTING(    0x50, DEF_STR( 1C_1C ) )*/	\
/*  PORT_DIPSETTING(    0x40, DEF_STR( 1C_1C ) )*/	\
/*  PORT_DIPSETTING(    0x30, DEF_STR( 1C_1C ) )*/	\
/*  PORT_DIPSETTING(    0x20, DEF_STR( 1C_1C ) )*/	\
/*  PORT_DIPSETTING(    0x10, DEF_STR( 1C_1C ) )*/	\
	PORT_DIPSETTING(    0x60, DEF_STR( 2C_3C ) )\
	PORT_DIPSETTING(    0xe0, DEF_STR( 1C_2C ) )\
	PORT_DIPSETTING(    0xd0, DEF_STR( 1C_3C ) )\
	PORT_DIPSETTING(    0xc0, DEF_STR( 1C_4C ) )\
	PORT_DIPSETTING(    0xb0, DEF_STR( 1C_5C ) )\
	PORT_DIPSETTING(    0xa0, DEF_STR( 1C_6C ) )\
	PORT_DIPSETTING(    0x00, DEF_STR( Free_Play ) )
/***************************************************************************/



INPUT_PORTS_START( 64street )
	COINS
//  fire    jump
	PORT_START_TAG("IN1")
	JOY_2BUTTONS(1)
	PORT_START_TAG("IN2")
	RESERVE				// Unused
	PORT_START_TAG("IN3")
	JOY_2BUTTONS(2)

	PORT_START_TAG("DSW1")
	COINAGE_8BITS

	PORT_START_TAG("DSW2")
	PORT_DIPNAME( 0x01, 0x01, DEF_STR( Flip_Screen ) )
	PORT_DIPSETTING(    0x01, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x02, 0x00, DEF_STR( Demo_Sounds ) )
	PORT_DIPSETTING(    0x02, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x04, 0x04, DEF_STR( Allow_Continue ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x04, DEF_STR( On ) )
	PORT_DIPNAME( 0x18, 0x18, DEF_STR( Difficulty ) )
	PORT_DIPSETTING(    0x10, DEF_STR( Easy ) )
	PORT_DIPSETTING(    0x18, DEF_STR( Normal ) )
	PORT_DIPSETTING(    0x08, DEF_STR( Hard ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Hardest ) )
	PORT_DIPNAME( 0x60, 0x20, DEF_STR( Lives ) )
	PORT_DIPSETTING(    0x40, "1" )
	PORT_DIPSETTING(    0x60, "2" )
	PORT_DIPSETTING(    0x20, "3" )
	PORT_DIPSETTING(    0x00, "5" )
	PORT_SERVICE( 0x80, IP_ACTIVE_LOW )

INPUT_PORTS_END

INPUT_PORTS_START( astyanax )
	COINS						/* IN0 0x80001.b */
//  fire    jump    magic
	PORT_START_TAG("IN1")
	JOY_3BUTTONS(1)	/* 0x80003.b */
	PORT_START_TAG("IN2")
	RESERVE						/* 0x80004.b */
	PORT_START_TAG("IN3")
	JOY_3BUTTONS(2)	/* 0x80005.b */

	PORT_START_TAG("DSW1") /* 0x80006.b */
	PORT_DIPNAME( 0x07, 0x07, DEF_STR( Coin_A ) )
	PORT_DIPSETTING(    0x00, DEF_STR( 4C_1C ) )
	PORT_DIPSETTING(    0x04, DEF_STR( 3C_1C ) )
	PORT_DIPSETTING(    0x02, DEF_STR( 2C_1C ) )
	PORT_DIPSETTING(    0x07, DEF_STR( 1C_1C ) )
//  PORT_DIPSETTING(    0x03, DEF_STR( 1C_1C ) )    // 1_2 shown in test mode
//  PORT_DIPSETTING(    0x05, DEF_STR( 1C_1C ) )    // 1_3
//  PORT_DIPSETTING(    0x01, DEF_STR( 1C_1C ) )    // 1_4
//  PORT_DIPSETTING(    0x06, DEF_STR( 1C_1C ) )    // 1_5
	PORT_DIPNAME( 0x38, 0x38, DEF_STR( Coin_B ) )
	PORT_DIPSETTING(    0x00, DEF_STR( 4C_1C ) )
	PORT_DIPSETTING(    0x20, DEF_STR( 3C_1C ) )
	PORT_DIPSETTING(    0x10, DEF_STR( 2C_1C ) )
	PORT_DIPSETTING(    0x38, DEF_STR( 1C_1C ) )
//  PORT_DIPSETTING(    0x18, DEF_STR( 1C_1C ) )    // 1_2 shown in test mode
//  PORT_DIPSETTING(    0x28, DEF_STR( 1C_1C ) )    // 1_3
//  PORT_DIPSETTING(    0x08, DEF_STR( 1C_1C ) )    // 1_4
//  PORT_DIPSETTING(    0x30, DEF_STR( 1C_1C ) )    // 1_5
	PORT_DIPNAME( 0x40, 0x00, DEF_STR( Demo_Sounds ) )
	PORT_DIPSETTING(    0x40, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x80, 0x80, "Test Mode" )
	PORT_DIPSETTING(    0x80, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )

	PORT_START_TAG("IN5")			/* 0x80007.b */
	PORT_DIPNAME( 0x01, 0x01, DEF_STR( Unknown ) ) // according to manual
	PORT_DIPSETTING(    0x01, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x02, 0x02, DEF_STR( Unknown ) ) // according to manual
	PORT_DIPSETTING(    0x02, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x04, 0x04, DEF_STR( Bonus_Life ) )
	PORT_DIPSETTING(    0x04, "30k 70k 110k then every 30k" )
	PORT_DIPSETTING(    0x00, "50k 100k then every 40k" )
	PORT_DIPNAME( 0x18, 0x18, DEF_STR( Lives ) )
	PORT_DIPSETTING(    0x08, "2" )
	PORT_DIPSETTING(    0x18, "3" )
	PORT_DIPSETTING(    0x10, "4" )
	PORT_DIPSETTING(    0x00, "5" )
	PORT_DIPNAME( 0x20, 0x20, DEF_STR( Difficulty ) )
	PORT_DIPSETTING(    0x20, DEF_STR( Normal ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Hard ) )
	PORT_DIPNAME( 0x40, 0x40, "Swap 1P/2P Controls" )
	PORT_DIPSETTING(    0x40, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x80, 0x80, DEF_STR( Flip_Screen ) )
	PORT_DIPSETTING(    0x80, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )

INPUT_PORTS_END

INPUT_PORTS_START( avspirit )
	COINS
	PORT_START_TAG("IN1")
	JOY_2BUTTONS(1)
	PORT_START_TAG("IN2")
	RESERVE
	PORT_START_TAG("IN3")
	JOY_2BUTTONS(2)

	PORT_START_TAG("DSW1")
	COINAGE_8BITS

	PORT_START_TAG("DSW2")
	PORT_DIPNAME( 0x01, 0x01, DEF_STR( Flip_Screen ) )
	PORT_DIPSETTING(    0x01, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x02, 0x00, DEF_STR( Demo_Sounds ) )
	PORT_DIPSETTING(    0x02, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x04, 0x04, DEF_STR( Allow_Continue ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x04, DEF_STR( On ) )
	PORT_DIPNAME( 0x18, 0x18, DEF_STR( Difficulty ) )
	PORT_DIPSETTING(    0x08, DEF_STR( Easy ) )
	PORT_DIPSETTING(    0x18, DEF_STR( Normal ) )
	PORT_DIPSETTING(    0x10, DEF_STR( Hard ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Hardest ) )
	PORT_DIPNAME( 0x20, 0x20, DEF_STR( Cabinet ) )
	PORT_DIPSETTING(    0x20, DEF_STR( Upright ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Cocktail ) )
	PORT_DIPNAME( 0x40, 0x40, "Test Mode" ) // freeze & slow motion via P1 + P2 start
	PORT_DIPSETTING(    0x40, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_SERVICE( 0x80, IP_ACTIVE_LOW )
INPUT_PORTS_END

INPUT_PORTS_START( bigstrik )
	COINS
//  pass    shoot   feint
	PORT_START_TAG("IN1")
	JOY_3BUTTONS(1)
	PORT_START_TAG("IN2")
	RESERVE
	PORT_START_TAG("IN3")
	JOY_3BUTTONS(2)

	PORT_START_TAG("DSW1")
	PORT_DIPNAME( 0x0f, 0x0f, DEF_STR( Coin_A ) )
	PORT_DIPSETTING(    0x07, DEF_STR( 4C_1C ) )
	PORT_DIPSETTING(    0x08, DEF_STR( 3C_1C ) )
	PORT_DIPSETTING(    0x09, DEF_STR( 2C_1C ) )
	PORT_DIPSETTING(    0x0f, DEF_STR( 1C_1C ) )
	PORT_DIPSETTING(    0x05, DEF_STR( 2C_3C ) )
//  PORT_DIPSETTING(    0x04, DEF_STR( 2C_3C ) )
//  PORT_DIPSETTING(    0x03, DEF_STR( 2C_3C ) )
//  PORT_DIPSETTING(    0x02, DEF_STR( 2C_3C ) )
//  PORT_DIPSETTING(    0x01, DEF_STR( 2C_3C ) )
//  PORT_DIPSETTING(    0x06, DEF_STR( 2C_3C ) )
	PORT_DIPSETTING(    0x0e, DEF_STR( 1C_2C ) )
	PORT_DIPSETTING(    0x0d, DEF_STR( 1C_3C ) )
	PORT_DIPSETTING(    0x0c, DEF_STR( 1C_4C ) )
	PORT_DIPSETTING(    0x0b, DEF_STR( 1C_5C ) )
	PORT_DIPSETTING(    0x0a, DEF_STR( 1C_6C ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Free_Play ) )
	PORT_DIPNAME( 0xf0, 0xf0, DEF_STR( Coin_B ) )
	PORT_DIPSETTING(    0x70, DEF_STR( 4C_1C ) )
	PORT_DIPSETTING(    0x80, DEF_STR( 3C_1C ) )
	PORT_DIPSETTING(    0x90, DEF_STR( 2C_1C ) )
	PORT_DIPSETTING(    0xf0, DEF_STR( 1C_1C ) )
	PORT_DIPSETTING(    0x50, DEF_STR( 2C_3C ) )
//  PORT_DIPSETTING(    0x40, DEF_STR( 2C_3C ) )
//  PORT_DIPSETTING(    0x30, DEF_STR( 2C_3C ) )
//  PORT_DIPSETTING(    0x20, DEF_STR( 2C_3C ) )
//  PORT_DIPSETTING(    0x10, DEF_STR( 2C_3C ) )
//  PORT_DIPSETTING(    0x60, DEF_STR( 2C_3C ) )
	PORT_DIPSETTING(    0xe0, DEF_STR( 1C_2C ) )
	PORT_DIPSETTING(    0xd0, DEF_STR( 1C_3C ) )
	PORT_DIPSETTING(    0xc0, DEF_STR( 1C_4C ) )
	PORT_DIPSETTING(    0xb0, DEF_STR( 1C_5C ) )
	PORT_DIPSETTING(    0xa0, DEF_STR( 1C_6C ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Free_Play ) )

	PORT_START_TAG("DSW2")
	PORT_DIPNAME( 0x01, 0x01, DEF_STR( Flip_Screen ) )
	PORT_DIPSETTING(    0x01, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x06, 0x06, DEF_STR( Difficulty ) )
	PORT_DIPSETTING(    0x02, DEF_STR( Easy )    )
	PORT_DIPSETTING(    0x06, DEF_STR( Normal )  )
	PORT_DIPSETTING(    0x04, DEF_STR( Hard )    )
	PORT_DIPSETTING(    0x00, DEF_STR( Hardest ) )
	PORT_DIPNAME( 0x18, 0x18, "Time" )
	PORT_DIPSETTING(    0x00, "Very Short" )
	PORT_DIPSETTING(    0x10, "Short" )
	PORT_DIPSETTING(    0x18, DEF_STR( Normal ) )
	PORT_DIPSETTING(    0x08, "Long" )
	PORT_DIPNAME( 0x20, 0x20, DEF_STR( Demo_Sounds ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x20, DEF_STR( On ) )
	PORT_DIPNAME( 0x40, 0x40, "1 Credit 2 Play" )
	PORT_DIPSETTING(    0x40, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_SERVICE( 0x80, IP_ACTIVE_LOW )

INPUT_PORTS_END

INPUT_PORTS_START( chimerab )

	COINS
//  fire    jump    unused?(shown in service mode, but not in instructions)
	PORT_START_TAG("IN1")
	JOY_2BUTTONS(1)
	PORT_START_TAG("IN2")
	RESERVE				// Unused
	PORT_START_TAG("IN3")
	JOY_2BUTTONS(2)

	PORT_START_TAG("DSW1")
	PORT_DIPNAME( 0x01, 0x01, DEF_STR( Flip_Screen ) )
	PORT_DIPSETTING(    0x01, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x02, 0x00, DEF_STR( Demo_Sounds ) )
	PORT_DIPSETTING(    0x02, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x04, 0x04, DEF_STR( Allow_Continue ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x04, DEF_STR( On ) )
	PORT_DIPNAME( 0x18, 0x18, DEF_STR( Difficulty ) )
	PORT_DIPSETTING(    0x10, DEF_STR( Easy ) )
	PORT_DIPSETTING(    0x18, DEF_STR( Normal ) )
	PORT_DIPSETTING(    0x08, DEF_STR( Hard ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Hardest ) )
	PORT_DIPNAME( 0x60, 0x20, DEF_STR( Lives ) )
	PORT_DIPSETTING(    0x40, "1" )
	PORT_DIPSETTING(    0x60, "2" )
	PORT_DIPSETTING(    0x20, "3" )
	PORT_DIPSETTING(    0x00, "4" )
	PORT_SERVICE( 0x80, IP_ACTIVE_LOW )

	PORT_START_TAG("DSW2")
	COINAGE_8BITS

INPUT_PORTS_END

INPUT_PORTS_START( cybattlr )

	COINS
//  fire    sword
	PORT_START_TAG("IN1")
	JOY_2BUTTONS(1)
	PORT_START_TAG("IN2")
	RESERVE				// Unused
	PORT_START_TAG("IN3")
	JOY_2BUTTONS(2)

	PORT_START_TAG("DSW1") /*1fd2d9.b, !1fd009.b */
	PORT_DIPNAME( 0x07, 0x07, DEF_STR( Coin_A ) )
	PORT_DIPSETTING(    0x00, DEF_STR( 4C_1C ) )
	PORT_DIPSETTING(    0x01, DEF_STR( 3C_1C ) )
	PORT_DIPSETTING(    0x03, DEF_STR( 2C_1C ) )
	PORT_DIPSETTING(    0x07, DEF_STR( 1C_1C ) )
	PORT_DIPSETTING(    0x02, DEF_STR( 2C_3C ) )
	PORT_DIPSETTING(    0x06, DEF_STR( 1C_2C ) )
	PORT_DIPSETTING(    0x05, DEF_STR( 1C_3C ) )
	PORT_DIPSETTING(    0x04, DEF_STR( 1C_4C ) )
	PORT_DIPNAME( 0x38, 0x38, DEF_STR( Coin_B ) )
	PORT_DIPSETTING(    0x00, DEF_STR( 4C_1C ) )
	PORT_DIPSETTING(    0x08, DEF_STR( 3C_1C ) )
	PORT_DIPSETTING(    0x18, DEF_STR( 2C_1C ) )
	PORT_DIPSETTING(    0x38, DEF_STR( 1C_1C ) )
	PORT_DIPSETTING(    0x10, DEF_STR( 2C_3C ) )
	PORT_DIPSETTING(    0x30, DEF_STR( 1C_2C ) )
	PORT_DIPSETTING(    0x28, DEF_STR( 1C_3C ) )
	PORT_DIPSETTING(    0x20, DEF_STR( 1C_4C ) )
	PORT_DIPNAME( 0x40, 0x40, DEF_STR( Free_Play ) )
	PORT_DIPSETTING(    0x40, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_SERVICE( 0x80, IP_ACTIVE_LOW )

	PORT_START_TAG("DSW2")			/* 1fd2d7.b, !1fd007.b */
	PORT_DIPNAME( 0x01, 0x01, "Unknown 2-0" )
	PORT_DIPSETTING(    0x01, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x02, 0x02, DEF_STR( Difficulty ) )
	PORT_DIPSETTING(    0x02, DEF_STR( Normal ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Hard ) )
	PORT_DIPNAME( 0x04, 0x04, "Disable Instruction Screen" )
	PORT_DIPSETTING(    0x04, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x08, 0x08, DEF_STR( Allow_Continue ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x08, DEF_STR( On ) )
	PORT_DIPNAME( 0x10, 0x10, "Unknown 2-4" )
	PORT_DIPSETTING(    0x10, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x20, 0x20, "Demo Sounds (Intro)" )
	PORT_DIPSETTING(    0x00, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x20, DEF_STR( On ) )
	PORT_DIPNAME( 0x40, 0x40, "Demo Sounds (Game Play)" )
	PORT_DIPSETTING(    0x40, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x80, 0x80, DEF_STR( Flip_Screen ) )
	PORT_DIPSETTING(    0x80, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )

INPUT_PORTS_END

INPUT_PORTS_START( edf )
	COINS
//  fire    unfold_weapons
	PORT_START_TAG("IN1")
	JOY_2BUTTONS(1)
	PORT_START_TAG("IN2")
	RESERVE
	PORT_START_TAG("IN3")
	JOY_2BUTTONS(2)

	PORT_START_TAG("DSW1")
	COINAGE_6BITS
	PORT_DIPNAME( 0x40, 0x40, DEF_STR( Demo_Sounds ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x40, DEF_STR( On ) )
	PORT_SERVICE( 0x80, IP_ACTIVE_LOW )

	PORT_START_TAG("DSW2")			/* 0x66007.b */
	PORT_DIPNAME( 0x07, 0x07, "DSW-B bits 2-0" )
	PORT_DIPSETTING(    0x00, "0" )
	PORT_DIPSETTING(    0x01, "1" )
	PORT_DIPSETTING(    0x02, "2" )
	PORT_DIPSETTING(    0x03, "3" )
	PORT_DIPSETTING(    0x04, "4" )
	PORT_DIPSETTING(    0x05, "5" )
	PORT_DIPSETTING(    0x06, "6" )
	PORT_DIPSETTING(    0x07, "7" )
	PORT_DIPNAME( 0x08, 0x08, DEF_STR( Lives ) )
	PORT_DIPSETTING(    0x08, "3" )
	PORT_DIPSETTING(    0x00, "4" )
	PORT_DIPNAME( 0x30, 0x30, DEF_STR( Difficulty ) )
	PORT_DIPSETTING(    0x00, "0" )
	PORT_DIPSETTING(    0x30, "1" )
	PORT_DIPSETTING(    0x10, "2" )
	PORT_DIPSETTING(    0x20, "3" )
	PORT_DIPNAME( 0x40, 0x40, "DSW-B bit 6" )
	PORT_DIPSETTING(    0x40, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x80, 0x80, DEF_STR( Flip_Screen ) )
	PORT_DIPSETTING(    0x80, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )

INPUT_PORTS_END

INPUT_PORTS_START( hachoo )
	COINS						/* 0x80001.b */
//  fire    jump
	PORT_START_TAG("IN1")
	JOY_2BUTTONS(1)	/* 0x80003.b */
	PORT_START_TAG("IN2")
	RESERVE						/* 0x80004.b */
	PORT_START_TAG("IN3")
	JOY_2BUTTONS(2)	/* 0x80005.b */

	PORT_START_TAG("DSW1")			/* 0x80006.b */
	COINAGE_6BITS
	PORT_DIPNAME( 0x40, 0x40, DEF_STR( Demo_Sounds ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x40, DEF_STR( On ) )
	PORT_DIPNAME( 0x80, 0x80, "Unknown 1-0" )	// unused?
	PORT_DIPSETTING(    0x80, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )

	PORT_START_TAG("DSW2")			/* 0x80007.b */
	PORT_DIPNAME( 0x01, 0x01, "Unknown 2-0" )	// unused?
	PORT_DIPSETTING(    0x01, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x02, 0x02, "Unknown 2-1" )	// unused?
	PORT_DIPSETTING(    0x02, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x04, 0x04, "Unknown 2-2" )	// unused?
	PORT_DIPSETTING(    0x04, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x08, 0x08, "Unknown 2-3" )	// unused?
	PORT_DIPSETTING(    0x08, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x30, 0x30, "?Difficulty?" )	// 4 & 5
	PORT_DIPSETTING(    0x30, "3" )
	PORT_DIPSETTING(    0x20, "2" )
	PORT_DIPSETTING(    0x10, "1" )
	PORT_DIPSETTING(    0x00, "0" )
	PORT_DIPNAME( 0x40, 0x40, "Unknown 2-6" )	// unused?
	PORT_DIPSETTING(    0x40, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x80, 0x80, DEF_STR( Flip_Screen ) )
	PORT_DIPSETTING(    0x80, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )

INPUT_PORTS_END

INPUT_PORTS_START( kazan )

	COINS						/* IN0 0x80001.b */
//  fire    jump
	PORT_START_TAG("IN1")
	JOY_2BUTTONS(1)	/* 0x80003.b */
	PORT_START_TAG("IN2")
	RESERVE						/* 0x80004.b */
	PORT_START_TAG("IN3")
	JOY_2BUTTONS(2)	/* 0x80005.b */

	PORT_START_TAG("DSW1") 			/* 0x80006.b */
	COINAGE_6BITS
	PORT_DIPNAME( 0x40, 0x00, DEF_STR( Demo_Sounds ) )
	PORT_DIPSETTING(    0x40, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x80, 0x80, "Freeze Screen (Cheat)")
	PORT_DIPSETTING(    0x80, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )

	PORT_START_TAG("DSW2")			/* 0x80007.b */
	PORT_DIPNAME( 0x03, 0x03, DEF_STR( Lives ) )
	PORT_DIPSETTING(    0x03, "2" )
	PORT_DIPSETTING(    0x01, "3" )
	PORT_DIPSETTING(    0x02, "4" )
	PORT_DIPSETTING(    0x00, "Infinite (Cheat)")
	PORT_DIPNAME( 0x04, 0x04, DEF_STR( Bonus_Life ) )
	PORT_DIPSETTING(    0x04, "50k" )
	PORT_DIPSETTING(    0x00, "200k" )
	PORT_DIPNAME( 0x08, 0x08, DEF_STR( Allow_Continue ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x08, DEF_STR( On ) )
	PORT_DIPNAME( 0x30, 0x30, "?Difficulty?" )
	PORT_DIPSETTING(    0x30, "3" )
	PORT_DIPSETTING(    0x20, "2" )
	PORT_DIPSETTING(    0x10, "1" )
	PORT_DIPSETTING(    0x00, "0" )
	PORT_DIPNAME( 0x40, 0x00, DEF_STR( Cabinet ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Upright ) )
	PORT_DIPSETTING(    0x40, DEF_STR( Cocktail ) )
	PORT_DIPNAME( 0x80, 0x80, DEF_STR( Flip_Screen ) )
	PORT_DIPSETTING(    0x80, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )

INPUT_PORTS_END

INPUT_PORTS_START( jitsupro )

	COINS						/* 0x80001.b */
	//  shoot   change view     change bat
	PORT_START_TAG("IN1")
	JOY_3BUTTONS(1)	/* 0x80003.b */
	PORT_START_TAG("IN2")
	RESERVE						/* 0x80004.b */
	PORT_START_TAG("IN3")
	JOY_3BUTTONS(2)	/* 0x80005.b */

	PORT_START_TAG("DSW1")			/* 0x80006.b */
	COINAGE_6BITS
	PORT_DIPNAME( 0x40, 0x00, DEF_STR( Demo_Sounds ) )
	PORT_DIPSETTING(    0x40, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x80, 0x80, "Unknown 1-7" )
	PORT_DIPSETTING(    0x80, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )

	PORT_START_TAG("DSW2")			/* 0x80007.b */
	PORT_DIPNAME( 0x01, 0x01, "Unknown 2-0*" )
	PORT_DIPSETTING(    0x01, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x02, 0x02, "Unknown 2-1*" )
	PORT_DIPSETTING(    0x02, DEF_STR( Off ) )	// $200-140
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )	// $400-140
	PORT_DIPNAME( 0x3c, 0x3c, "Unknown 2-2345*" )
	PORT_DIPSETTING(    0x3c, "0"  )
	PORT_DIPSETTING(    0x38, "1"  )
	PORT_DIPSETTING(    0x34, "2"  )
	PORT_DIPSETTING(    0x30, "3"  )
	PORT_DIPSETTING(    0x2c, "4"  )
	PORT_DIPSETTING(    0x28, "5"  )
	PORT_DIPSETTING(    0x24, "6"  )
	PORT_DIPSETTING(    0x20, "7"  )
	PORT_DIPSETTING(    0x1c, "8"  )
	PORT_DIPSETTING(    0x18, "9"  )
	PORT_DIPSETTING(    0x14, "10" )
	PORT_DIPSETTING(    0x10, "11" )
	PORT_DIPSETTING(    0x0c, "12" )
	PORT_DIPSETTING(    0x08, "13" )
	PORT_DIPSETTING(    0x04, "14" )
	PORT_DIPSETTING(    0x00, "15" )
	PORT_DIPNAME( 0x40, 0x40, "Unknown 2-6*" )
	PORT_DIPSETTING(    0x40, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x80, 0x80, DEF_STR( Flip_Screen ) )
	PORT_DIPSETTING(    0x80, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )

INPUT_PORTS_END

INPUT_PORTS_START( kickoff )
	COINS						/* 0x80001.b ->  !f0008/a.w  */
//  shoot   pass
	PORT_START_TAG("IN1")
	JOY_2BUTTONS(1)	/* 0x80003.b ->  !f000c/e.w  */
	PORT_START_TAG("IN2")
	RESERVE						/* 0x80004.b --> !f0010/11.w */
	PORT_START_TAG("IN3")
	JOY_2BUTTONS(2)	/* 0x80005.b */

	PORT_START_TAG("DSW1") /* 0x80006.b */
	PORT_DIPNAME( 0x07, 0x07, DEF_STR( Coin_A ) )
	PORT_DIPSETTING(    0x01, DEF_STR( 4C_1C ) )
	PORT_DIPSETTING(    0x02, DEF_STR( 3C_1C ) )
	PORT_DIPSETTING(    0x03, DEF_STR( 2C_1C ) )
	PORT_DIPSETTING(    0x07, DEF_STR( 1C_1C ) )
	PORT_DIPSETTING(    0x06, DEF_STR( 1C_2C ) )
	PORT_DIPSETTING(    0x05, DEF_STR( 1C_3C ) )
	PORT_DIPSETTING(    0x04, DEF_STR( 1C_4C ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Free_Play ) )
	PORT_DIPNAME( 0x08, 0x08, "Unknown 1-3" )	// unused?
	PORT_DIPSETTING(    0x08, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x10, 0x10, "Unknown 1-4" )	// unused?
	PORT_DIPSETTING(    0x10, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x20, 0x20, "Freeze Screen (Cheat)")
	PORT_DIPSETTING(    0x20, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x40, 0x00, DEF_STR( Demo_Sounds ) )
	PORT_DIPSETTING(    0x40, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x80, 0x80, "Text" )
	PORT_DIPSETTING(    0x80, DEF_STR( Japanese ) )
	PORT_DIPSETTING(    0x00, DEF_STR( English ) )	// show "Japan Only" warning

	PORT_START_TAG("DSW2")			/* 0x80007.b */
	PORT_DIPNAME( 0x03, 0x03, "Time" )	// -> !f0082.w
	PORT_DIPSETTING(    0x03, "3'" )
	PORT_DIPSETTING(    0x02, "4'" )
	PORT_DIPSETTING(    0x01, "5'" )
	PORT_DIPSETTING(    0x00, "6'" )
	PORT_DIPNAME( 0x04, 0x04, "Unknown 2-2" )	// unused?
	PORT_DIPSETTING(    0x04, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x08, 0x08, "Unknown 2-3" )	// unused?
	PORT_DIPSETTING(    0x08, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x30, 0x30, "?Difficulty?" )	// -> !f0084.w
	PORT_DIPSETTING(    0x30, "0" )
	PORT_DIPSETTING(    0x20, "1" )
	PORT_DIPSETTING(    0x10, "2" )
	PORT_DIPSETTING(    0x00, "3" )
	PORT_DIPNAME( 0x40, 0x00, DEF_STR( Controls ) )
	PORT_DIPSETTING(    0x40, DEF_STR( Unknown ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Joystick ) )
	PORT_DIPNAME( 0x80, 0x80, DEF_STR( Flip_Screen ) )
	PORT_DIPSETTING(    0x80, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )

INPUT_PORTS_END

INPUT_PORTS_START( lomakai )
	COINS						/* 0x80001.b */
//  fire    jump
	PORT_START_TAG("IN1")
	JOY_2BUTTONS(1)	/* 0x80003.b */
	PORT_START_TAG("IN2")
	RESERVE						/* 0x80004.b */
	PORT_START_TAG("IN3")
	JOY_2BUTTONS(2)	/* 0x80005.b */

	PORT_START_TAG("DSW1")			/* 0x80006.b */
	COINAGE_6BITS_2
	PORT_DIPNAME( 0x40, 0x00, DEF_STR( Demo_Sounds ) )
	PORT_DIPSETTING(    0x40, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x80, 0x80, "Invulnerability (Cheat)")
	PORT_DIPSETTING(    0x80, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )

	PORT_START_TAG("DSW2")			/* 0x80007.b */
	PORT_DIPNAME( 0x03, 0x03, DEF_STR( Lives ) )
	PORT_DIPSETTING(    0x00, "2" )
	PORT_DIPSETTING(    0x03, "3" )
	PORT_DIPSETTING(    0x02, "4" )
	PORT_DIPSETTING(    0x01, "5" )
	PORT_DIPNAME( 0x04, 0x04, DEF_STR( Unknown ) )
	PORT_DIPSETTING(    0x04, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x08, 0x08, DEF_STR( Unknown ) )
	PORT_DIPSETTING(    0x08, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x30, 0x30, DEF_STR( Difficulty ) ) // boss enemy damage bar
	PORT_DIPSETTING(    0x30, DEF_STR( Easy ) ) // 6 dots
	PORT_DIPSETTING(    0x20, DEF_STR( Normal ) ) // 8 dots
	PORT_DIPSETTING(    0x10, DEF_STR( Hard ) ) // 9 dots
	PORT_DIPSETTING(    0x00, DEF_STR( Hardest ) ) // 12 dots
	PORT_DIPNAME( 0x40, 0x00, DEF_STR( Cabinet ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Upright ) )
	PORT_DIPSETTING(    0x40, DEF_STR( Cocktail ) )
	PORT_DIPNAME( 0x80, 0x80, DEF_STR( Flip_Screen ) )
	PORT_DIPSETTING(    0x80, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )

INPUT_PORTS_END

INPUT_PORTS_START( p47 )

	COINS						/* 0x80001.b */
//  fire    bomb
	PORT_START_TAG("IN1")
	JOY_2BUTTONS(1)	/* 0x80003.b */
	PORT_START_TAG("IN2")
	RESERVE						/* 0x80004.b */
	PORT_START_TAG("IN3")
	JOY_2BUTTONS(2)	/* 0x80005.b */

	PORT_START_TAG("DSW1")			/* 0x80006.b */
	COINAGE_6BITS_2
	PORT_DIPNAME( 0x40, 0x40, DEF_STR( Demo_Sounds ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x40, DEF_STR( On ) )
	PORT_DIPNAME( 0x80, 0x80, "Invulnerability (Cheat)")
	PORT_DIPSETTING(    0x80, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )

	PORT_START_TAG("DSW2")			/* 0x80007.b */
	PORT_DIPNAME( 0x03, 0x03, DEF_STR( Lives ) )
	PORT_DIPSETTING(    0x02, "2" )
	PORT_DIPSETTING(    0x03, "3" )
	PORT_DIPSETTING(    0x01, "4" )
	PORT_DIPSETTING(    0x00, "5" )
	PORT_DIPNAME( 0x04, 0x04, DEF_STR( Unknown ) )
	PORT_DIPSETTING(    0x04, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x08, 0x08, DEF_STR( Unknown ) )
	PORT_DIPSETTING(    0x08, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x30, 0x30, DEF_STR( Difficulty ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Easy ) )
	PORT_DIPSETTING(    0x30, DEF_STR( Normal ) )
	PORT_DIPSETTING(    0x20, DEF_STR( Hard ) )
	PORT_DIPSETTING(    0x10, DEF_STR( Hardest ) )
	PORT_DIPNAME( 0x40, 0x40, DEF_STR( Unknown ) )
	PORT_DIPSETTING(    0x40, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x80, 0x80, DEF_STR( Flip_Screen ) )
	PORT_DIPSETTING(    0x80, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )

INPUT_PORTS_END




/***************************************************************************

                            [ Peek-a-Boo! ]

interrupts:
    1]      506>    rte
    2]      50a>    move.w  #$ffff, $1f0006.l
                    jsr     $46e0.l             rte
    3]      51c>    rte
    4]      520>    move.w  #$ffff, $1f000a.l   rte
    5-7]    53c>    rte

3832    Show error (d7 = ram segment where error occurred)
        1 after d8000 ok. 3 after e0000&d0000 ok. 4 after ram&rom ok

003E5E: 0000 3E72   [0] Color Ram
003E62: 0000 3E86   [1] Video Ram
003E66: 0000 3E9A   [2] Sprite Ram
003E6A: 0000 3EB0   [3] Work Ram
003E6E: 0000 3EC4   [4] ROM

000000-03ffff   rom (3f760 chksum)
1f0000-1fffff   ram
0d0000-0d3fff   text
0d8000-0d87ff   palette (+200 = text palette)
0e8000-0ebfff   layer
0e0000-0e0001   2 dips, 1f003a<-!
0f0000-0f0001   2 controls
0f8000-0f8001   ???

010000-010001   protection\watchdog;
    fb -> fb
    9x ->   0       watchdog reset?
            else    samples bank?
                    $1ff010 = sample
                    $1ff014 = bank = sample - $22 (33DC: 1 1 2 3 4 5 6 6 6 6)
                        samples:    bank:
                        $00-21      0
                        $22-2b      1-6
000000-01ffff
020000-03ffff   banked

    51 -> paddle p1
    52 -> paddle p2
    4bba waits for 1f000a to go !0, then clears 1f000a (int 4)
    4bca waits (100000) & FF == 3
    sequence $81, $71, $67 written


Scroll x,y,ctrl:
c2000<-1f0010       c2002<-1f0014       c2004<-1f000c

Scroll x,y,ctrl:
c2008<-1f0018       c200a<-1f001c       c200c<-1f000e

Layers ctrl:
c2208<-1f0024<<8 + 1f0026       c2308<-1f0022 | 1f002c

Sprite bank + ??
c2108<-1f005a + 1f0060 + 1f0062 + 1f0068

Sprite ctrl:
c2200<-0

1f0000.w    routine index, table at $fae:
    0: 4E40
    1: 4EC2
    2: 4F2C
    3: 4F70
    4: 4FBC
    5: 533A
    6: 5382
    7: 556E

1f003c/40   paddle p1/p2
1f0260/4.l  *** p1/p2 score/10 (BCD) ***
1f02e6/8.w  *** p1/p2 current lives ***
            Bonus lives:    20K  100K  250K  500K 1000K
1f02ee      current player (0/1)
1f0380      hi score


***************************************************************************/

ROM_START( peekaboo )
	ROM_REGION( 0x40000, REGION_CPU1, 0 )		/* 68000 CPU Code */
	ROM_LOAD16_BYTE( "j3", 0x000000, 0x020000, CRC(f5f4cf33) SHA1(f135f2b627347255bb0811e9a4a213e3b447c199) )
	ROM_LOAD16_BYTE( "j2", 0x000001, 0x020000, CRC(7b3d430d) SHA1(8b48101929da4938a61dfd0eda845368c4184831) )

	ROM_REGION( 0x080000, REGION_GFX1, ROMREGION_DISPOSE ) /* Scroll 0 */
	ROM_LOAD( "5",       0x000000, 0x080000, CRC(34fa07bb) SHA1(0f688acf302fd56701ee4fcc1d692adb7bf86ce4) )

	ROM_REGION( 0x080000, REGION_GFX2, ROMREGION_DISPOSE ) /* Scroll 1 */
	ROM_LOAD( "4",       0x000000, 0x020000, CRC(f037794b) SHA1(235c278121921b234a27835284be80c136e6409b) )

	ROM_REGION( 0x020000, REGION_GFX3, ROMREGION_DISPOSE ) /* Scroll 2 */
	// Unused

	ROM_REGION( 0x080000, REGION_GFX4, ROMREGION_DISPOSE ) /* Sprites */
	ROM_LOAD( "1",       0x000000, 0x080000, CRC(5a444ecf) SHA1(38a7a6e91d0635a7f82a1c9a04efe1586ed3d856) )

	ROM_REGION( 0x120000, REGION_SOUND1, 0 )		/* Samples */
	ROM_LOAD( "peeksamp.124", 0x000000, 0x020000, CRC(e1206fa8) SHA1(339d5a4fa2af7fb4ab2e9c6c66f4848fa8774832) )
	ROM_CONTINUE(             0x040000, 0x0e0000 )

	ROM_REGION( 0x0200, REGION_PROMS, 0 )		/* Priority PROM */
	ROM_LOAD( "priority.69",    0x000000, 0x200, CRC(b40bff56) SHA1(39c95eed79328ef2df754988db83e07909e848f8) )
ROM_END

INPUT_PORTS_START( peekaboo )

	PORT_START_TAG("IN0")		/* COINS + P1&P2 Buttons - .b */
	PORT_BIT(  0x0001, IP_ACTIVE_LOW, IPT_COIN3 )		// called "service"
	PORT_BIT(  0x0002, IP_ACTIVE_LOW, IPT_COIN4 )		// called "test"
	PORT_BIT(  0x0004, IP_ACTIVE_LOW, IPT_COIN1 )
	PORT_BIT(  0x0008, IP_ACTIVE_LOW, IPT_COIN2 )
	PORT_BIT(  0x0010, IP_ACTIVE_LOW, IPT_START1 )
	PORT_BIT(  0x0020, IP_ACTIVE_LOW, IPT_START2 )
	PORT_BIT(  0x0040, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT(  0x0080, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT(  0x0100, IP_ACTIVE_LOW, IPT_BUTTON1 )
	PORT_BIT(  0x0200, IP_ACTIVE_LOW, IPT_BUTTON2 )
	PORT_BIT(  0x0400, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_PLAYER(2)
	PORT_BIT(  0x0800, IP_ACTIVE_LOW, IPT_BUTTON2 ) PORT_PLAYER(2)
	PORT_BIT(  0x1000, IP_ACTIVE_LOW, IPT_BUTTON3 )		// called "stage clear"
	PORT_BIT(  0x2000, IP_ACTIVE_LOW, IPT_BUTTON4 )		// called "option"
	PORT_BIT(  0x4000, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT(  0x8000, IP_ACTIVE_LOW, IPT_UNKNOWN )

#define PEEKABOO_PADDLE(_FLAG_)	\
	PORT_BIT( 0x00ff, 0x0080, IPT_PADDLE ) PORT_PLAYER(_FLAG_) PORT_MINMAX(0x0018,0x00e0) PORT_SENSITIVITY(50) PORT_KEYDELTA(10) PORT_CENTERDELTA(0)

	PORT_START_TAG("IN1")      	/* paddle p1 */
	PEEKABOO_PADDLE(1)

	PORT_START_TAG("IN2")
	RESERVE				/* fake port */
	PORT_START_TAG("IN3")      	/* paddle p2 */
	PEEKABOO_PADDLE(2) PORT_COCKTAIL

	PORT_START_TAG("DSW1")			/* 1f003a.b<-e0000.b */
	COINAGE_6BITS_2
	PORT_DIPNAME( 0x40, 0x40, DEF_STR( Demo_Sounds ) )		// 1f0354<-
	PORT_DIPSETTING(    0x00, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x40, DEF_STR( On ) )
	PORT_DIPNAME( 0x80, 0x80, DEF_STR( Flip_Screen ) )		// 1f0022/6e<-!
	PORT_DIPSETTING(    0x80, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )

	PORT_START_TAG("DSW2")			/* 1f003b.b<-e0001.b */
	PORT_DIPNAME( 0x03, 0x03, DEF_STR( Difficulty ) )				// 1f0358<-!
	PORT_DIPSETTING(    0x00, DEF_STR( Easy ) )
	PORT_DIPSETTING(    0x03, DEF_STR( Normal ) )
	PORT_DIPSETTING(    0x02, DEF_STR( Hard ) )
	PORT_DIPSETTING(    0x01, DEF_STR( Hardest ) )

	PORT_SERVICE( 0x04, IP_ACTIVE_LOW )
	PORT_DIPNAME( 0x08, 0x08, "Movement" )					// 1f0392<-!
	PORT_DIPSETTING(    0x08, "Paddles" )
	PORT_DIPSETTING(    0x00, "Buttons" )
	PORT_DIPNAME( 0x30, 0x30, "Nudity" )					// 1f0356<-!
	PORT_DIPSETTING(    0x30, "Female and Male (Full)" )
	PORT_DIPSETTING(    0x20, "Female (Full)" )
	PORT_DIPSETTING(    0x10, "Female (Partial)" )
	PORT_DIPSETTING(    0x00, DEF_STR( None ) )
	PORT_DIPNAME( 0x40, 0x40, DEF_STR( Cabinet ) )			// 1f006a<-!
	PORT_DIPSETTING(    0x40, DEF_STR( Upright ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Cocktail ) )
	PORT_DIPNAME( 0x80, 0x80, "Number of controllers" )	// 1f0074<-!
	PORT_DIPSETTING(    0x80, "1" )
	PORT_DIPSETTING(    0x00, "2" )

INPUT_PORTS_END



static UINT16 protection_val;

/* Read the input ports, through a protection device */
static READ16_HANDLER( protection_peekaboo_r )
{
	switch (protection_val)
	{
		case 0x02:	return 0x03;
		case 0x51:	return player1_r(0,0);
		case 0x52:	return player2_r(0,0);
		default:	return protection_val;
	}
}

static WRITE16_HANDLER( protection_peekaboo_w )
{
	static int bank;

	COMBINE_DATA(&protection_val);

	if ((protection_val & 0x90) == 0x90)
	{
		unsigned char *RAM = memory_region(okim6295_interface_region_1.region);
		int new_bank = (protection_val & 0x7) % 7;

		if (bank != new_bank)
		{
			memcpy(&RAM[0x20000],&RAM[0x40000 + 0x20000*new_bank],0x20000);
			bank = new_bank;
		}
	}

	cpunum_set_input_line(0,4,HOLD_LINE);
}


/***************************************************************************

                            [ Plus Alpha ]
                          (aka Flight Alpha)

f2ef8.w     bombs
f309e.w     *** lives       ***
f30a4.l     *** score (BCD) ***

***************************************************************************/

ROM_START( plusalph )
	ROM_REGION( 0x60000, REGION_CPU1, 0 )		/* Main CPU Code */
	ROM_LOAD16_BYTE( "pa-rom2.bin", 0x000000, 0x020000, CRC(33244799) SHA1(686fb7fa8a6c25b5aff78bc509f35c69492d7d1e) )
	ROM_LOAD16_BYTE( "pa-rom1.bin", 0x000001, 0x020000, CRC(a32fdcae) SHA1(c2315a7142e5499e9325f5a8361cb25e83747a3e) )
	ROM_LOAD16_BYTE( "pa-rom3.bin", 0x040000, 0x010000, CRC(1b739835) SHA1(3aaa9545a7f578a9775311dcd44504870f3b1544) )
	ROM_LOAD16_BYTE( "pa-rom4.bin", 0x040001, 0x010000, CRC(ff760e80) SHA1(dd06306a516a2d5e49cf8f2343ddc26405b309a9) )

	ROM_REGION( 0x20000, REGION_CPU2, 0 )		/* Sound CPU Code */
	ROM_LOAD16_BYTE( "pa-rom5.bin", 0x000000, 0x010000, CRC(ddc2739b) SHA1(dee31660428baea44c73dec238ed7f39a6771fe6) )
	ROM_LOAD16_BYTE( "pa-rom6.bin", 0x000001, 0x010000, CRC(f6f8a167) SHA1(60d5c9db18d8f6704b68ccde5d026174679cec36) )

	ROM_REGION( 0x080000, REGION_GFX1, ROMREGION_DISPOSE ) /* Scroll 0 */
	ROM_LOAD( "pa-rom11.bin", 0x000000, 0x020000, CRC(eb709ae7) SHA1(434c9da3c79a97ddd9be77908ce65e9efe6c8106) )
	ROM_LOAD( "pa-rom12.bin", 0x020000, 0x020000, CRC(cacbc350) SHA1(328094a5d067775871f7d69b4c20c40e46b0eaba) )
	ROM_LOAD( "pa-rom13.bin", 0x040000, 0x020000, CRC(fad093dd) SHA1(98a42f91d66b990e18f845edc01c23568cbc7a83) )
	ROM_LOAD( "pa-rom14.bin", 0x060000, 0x020000, CRC(d3676cd1) SHA1(b805216af1a65c2f19a82aaf3775bbbceb065c7e) )

	ROM_REGION( 0x080000, REGION_GFX2, ROMREGION_DISPOSE ) /* Scroll 1 */
	ROM_LOAD( "pa-rom15.bin", 0x000000, 0x020000, CRC(8787735b) SHA1(9083061ce6de98a611558fc59d1ec37aefc2a2e0) )
	ROM_LOAD( "pa-rom16.bin", 0x020000, 0x020000, CRC(a06b813b) SHA1(de4fb0f92f9178c2b5f2750d17cfc3da126b23a4) )
	ROM_LOAD( "pa-rom17.bin", 0x040000, 0x020000, CRC(c6b38a4b) SHA1(2529ee47324edcdf4cd34c159524f37da08e1099) )
	/* empty place */

	ROM_REGION( 0x020000, REGION_GFX3, ROMREGION_DISPOSE ) /* Scroll 2 */
	ROM_LOAD( "pa-rom19.bin", 0x000000, 0x010000, CRC(39ef193c) SHA1(93f417a36732ca76d566f2ff2c9ff62e5679da08) )

	ROM_REGION( 0x080000, REGION_GFX4, ROMREGION_DISPOSE ) /* Sprites */
	ROM_LOAD( "pa-rom20.bin", 0x000000, 0x020000, CRC(86c557a8) SHA1(a6dfb2aeda07639448a4135d1336019214030fc9) )
	ROM_LOAD( "pa-rom21.bin", 0x020000, 0x020000, CRC(81140a88) SHA1(f31ae208623bdb152888e1ebdd2515f9bcc2fb44) )
	ROM_LOAD( "pa-rom22.bin", 0x040000, 0x020000, CRC(97e39886) SHA1(89161ae647c835ff24fcb8676f6e1228f9a1fa10) )
	ROM_LOAD( "pa-rom23.bin", 0x060000, 0x020000, CRC(0383fb65) SHA1(31fa9c9ba57bf3c9ee8e3f5b1b4e28c1a3591a4b) )

	ROM_REGION( 0x040000, REGION_SOUND1, 0 )		/* Samples */
	ROM_LOAD( "pa-rom9.bin",  0x000000, 0x020000, CRC(065364bd) SHA1(bacb268b1c76c286e89eb823d8c3477ec5f2516c) )
	ROM_LOAD( "pa-rom10.bin", 0x020000, 0x020000, CRC(395df3b2) SHA1(6f69b573e997ba4bb5aabf745843921f0866d209) )

	ROM_REGION( 0x040000, REGION_SOUND2, 0 )		/* Samples */
	ROM_LOAD( "pa-rom7.bin",  0x000000, 0x020000, CRC(9f5d800e) SHA1(c0a7bdedc8a1294b8d29f7f6007542ea006e70cb) )
	ROM_LOAD( "pa-rom8.bin",  0x020000, 0x020000, CRC(ae007750) SHA1(b48784fd6bcf205296e3e5b59c258f76da5c2d1b) )

	ROM_REGION( 0x0200, REGION_PROMS, 0 )		/* Priority PROM */
	ROM_LOAD( "prom.14m",     0x0000, 0x0200, CRC(1d877538) SHA1(a5be0dc65dcfc36fbba10d1fddbe155e24b6122f) )
ROM_END

INPUT_PORTS_START( plusalph )
	COINS						/* IN0 0x80001.b */
//  fire    bomb
	PORT_START_TAG("IN1")
	JOY_2BUTTONS(1)	/* 0x80003.b */
	PORT_START_TAG("IN2")
	RESERVE						/* 0x80004.b */
	PORT_START_TAG("IN3")
	JOY_2BUTTONS(2)	/* 0x80005.b */

	PORT_START_TAG("DSW1")			/* 0x80006.b */
	COINAGE_6BITS
	PORT_DIPNAME( 0x40, 0x40, DEF_STR( Demo_Sounds ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x40, DEF_STR( On ) )
	PORT_DIPNAME( 0x80, 0x80, "Freeze Screen (Cheat)")
	PORT_DIPSETTING(    0x80, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )

	PORT_START_TAG("DSW2")			/* 0x80007.b */
	PORT_DIPNAME( 0x03, 0x03, DEF_STR( Lives ) )
	PORT_DIPSETTING(    0x03, "3" )
	PORT_DIPSETTING(    0x02, "4" )
	PORT_DIPSETTING(    0x01, "5" )
	PORT_DIPSETTING(    0x00, "Infinite (Cheat)")
	PORT_DIPNAME( 0x04, 0x04, "Bombs" )
	PORT_DIPSETTING(    0x00, "2" )
	PORT_DIPSETTING(    0x04, "3" )
	PORT_DIPNAME( 0x08, 0x08, DEF_STR( Bonus_Life ) )
	PORT_DIPSETTING(    0x08, "70k and every 130k")
	PORT_DIPSETTING(    0x00, "100k and every 200k")
	PORT_DIPNAME( 0x30, 0x30, DEF_STR( Difficulty ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Easy ) )
	PORT_DIPSETTING(    0x30, DEF_STR( Normal ) )
	PORT_DIPSETTING(    0x10, DEF_STR( Hard ) )
	PORT_DIPSETTING(    0x20, DEF_STR( Hardest ) )
	PORT_DIPNAME( 0x40, 0x00, DEF_STR( Cabinet ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Upright ) )
	PORT_DIPSETTING(    0x40, DEF_STR( Cocktail ) )
	PORT_DIPNAME( 0x80, 0x80, DEF_STR( Flip_Screen ) )
	PORT_DIPSETTING(    0x80, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )

INPUT_PORTS_END


/***************************************************************************

                            [ RodLand ]

(World version)
interrupts: 1] 418->3864: rts   2] 420: move.w #-1,f0010; jsr 3866  3] rte

213da   print test error (20c12 = string address 0-4)

f0018->84200    f0020->84208    f0028->84008
f001c->84202    f0024->8420a    f002c->8400a
f0012->84204    f0014->8420c    f0016->8400c

7fe     d0.w -> 84000.w & f000e.w
81a     d0/d1/d2 & $D -> 84204 / 8420c /8400c

***************************************************************************/

ROM_START( rodland )
	ROM_REGION( 0x60000, REGION_CPU1, 0 )		/* Main CPU Code */
	ROM_LOAD16_BYTE( "rl_02.rom", 0x000000, 0x020000, CRC(c7e00593) SHA1(055b7bcabf90ed6d5edc2797d0f85a5d49b8693b) )
	ROM_LOAD16_BYTE( "rl_01.rom", 0x000001, 0x020000, CRC(2e748ca1) SHA1(285414af11aad36f3bd7020365ff90eb696d2de3) )
	ROM_LOAD16_BYTE( "rl_03.rom", 0x040000, 0x010000, CRC(62fdf6d7) SHA1(ffde7e7f5b3b548bc980b9dee767f693046ecab2) )
	ROM_LOAD16_BYTE( "rl_04.rom", 0x040001, 0x010000, CRC(44163c86) SHA1(1c56d79531af0312e7cd3dc66cf61b55dd1a6e51) )

	ROM_REGION( 0x20000, REGION_CPU2, 0 )		/* Sound CPU Code */
	ROM_LOAD16_BYTE( "rl_05.rom", 0x000000, 0x010000, CRC(c1617c28) SHA1(1b3440055c083b74270fe06b5f42e7d1337efeca) )
	ROM_LOAD16_BYTE( "rl_06.rom", 0x000001, 0x010000, CRC(663392b2) SHA1(99052639e934d1ca18888c9c7fa061c1d3508fd4) )

	ROM_REGION( 0x080000, REGION_GFX1, ROMREGION_DISPOSE ) /* Scroll 0 */
	ROM_LOAD( "rl_23.rom", 0x000000, 0x020000, CRC(ac60e771) SHA1(97c2ac1ed89c171a0db98befa6c3c10754d64880) )
	ROM_CONTINUE(          0x030000, 0x010000 )
	ROM_CONTINUE(          0x050000, 0x010000 )
	ROM_CONTINUE(          0x020000, 0x010000 )
	ROM_CONTINUE(          0x040000, 0x010000 )
	ROM_CONTINUE(          0x060000, 0x020000 )

	ROM_REGION( 0x080000, REGION_GFX2, ROMREGION_DISPOSE ) /* Scroll 1 */
	ROM_LOAD( "rl_18.rom", 0x000000, 0x080000, CRC(f3b30ca6) SHA1(f2f88c24a009b6695f7548aebd37b25d1fd19892) )

	ROM_REGION( 0x020000, REGION_GFX3, ROMREGION_DISPOSE ) /* Scroll 2 */
	ROM_LOAD( "rl_19.bin", 0x000000, 0x020000, CRC(124d7e8f) SHA1(d7885a10085cc3389bd0e26e9d54adb8929218c0) )

	ROM_REGION( 0x080000, REGION_GFX4, ROMREGION_DISPOSE ) /* Sprites */
	ROM_LOAD( "rl_14.rom", 0x000000, 0x080000, CRC(08d01bf4) SHA1(b9333d11572f46992cdd668908fbc1c33d841f8d) )

	ROM_REGION( 0x040000, REGION_SOUND1, 0 )		/* Samples */
	ROM_LOAD( "rl_10.rom", 0x000000, 0x040000, CRC(e1d1cd99) SHA1(6604111d37455c1bd59c1469d9ee7841e7dec913) )

	ROM_REGION( 0x040000, REGION_SOUND2, 0 )		/* Samples */
	ROM_LOAD( "rl_08.rom", 0x000000, 0x040000, CRC(8a49d3a7) SHA1(68cb8cf2753b39c253d0edaa8ef2c54fd1f6ebe5) )

	ROM_REGION( 0x0200, REGION_PROMS, 0 )		/* Priority PROM */
	ROM_LOAD( "rl.bin",    0x0000, 0x0200, CRC(8914e72d) SHA1(80a664471f14c8ed8544a5e226fdca425ab3c657) )
ROM_END

ROM_START( rodlandj )
	ROM_REGION( 0x60000, REGION_CPU1, 0 )		/* Main CPU Code */
	ROM_LOAD16_BYTE( "rl_2.bin", 0x000000, 0x020000, CRC(b1d2047e) SHA1(75d282b7614c5f4b76ab44e34fea9e87ab8b992c) )
	ROM_LOAD16_BYTE( "rl_1.bin", 0x000001, 0x020000, CRC(3c47c2a3) SHA1(62e66a2f53aeacf92551ba64ae4ce14c2e982bb0) )
	ROM_LOAD16_BYTE( "rl_3.bin", 0x040000, 0x010000, CRC(c5b1075f) SHA1(a8bcc0e9dbb4b731bc0b7e5a8e0efc3d142505b9) )
	ROM_LOAD16_BYTE( "rl_4.bin", 0x040001, 0x010000, CRC(9ec61048) SHA1(71b6af054a528af04e23affff635a9358537cd3b) )

	ROM_REGION( 0x20000, REGION_CPU2, 0 )		/* Sound CPU Code */
	ROM_LOAD16_BYTE( "rl_05.rom", 0x000000, 0x010000, CRC(c1617c28) SHA1(1b3440055c083b74270fe06b5f42e7d1337efeca) )
	ROM_LOAD16_BYTE( "rl_06.rom", 0x000001, 0x010000, CRC(663392b2) SHA1(99052639e934d1ca18888c9c7fa061c1d3508fd4) )

	ROM_REGION( 0x080000, REGION_GFX1, ROMREGION_DISPOSE ) /* Scroll 0 */
	/* address and data lines are mangled, but otherwise identical to rl_23.rom */
	ROM_LOAD( "rl_14.bin", 0x000000, 0x080000, CRC(8201e1bb) SHA1(3304100dcab7b67cee021869a50f4295c8635814) )

	ROM_REGION( 0x080000, REGION_GFX2, ROMREGION_DISPOSE ) /* Scroll 1 */
	ROM_LOAD( "rl_18.rom", 0x000000, 0x080000, CRC(f3b30ca6) SHA1(f2f88c24a009b6695f7548aebd37b25d1fd19892) )

	ROM_REGION( 0x020000, REGION_GFX3, ROMREGION_DISPOSE ) /* Scroll 2 */
	ROM_LOAD( "rl_19.bin", 0x000000, 0x020000, CRC(124d7e8f) SHA1(d7885a10085cc3389bd0e26e9d54adb8929218c0) )

	ROM_REGION( 0x080000, REGION_GFX4, ROMREGION_DISPOSE ) /* Sprites */
	/* was a bad dump (first and second half identical), reconstructed from rl_14.rom */
	ROM_LOAD( "rl_23.bin", 0x000000, 0x080000, CRC(936db174) SHA1(4dfb2c31bc4bbf659184fe18e320d19f326b3ec5) )

	ROM_REGION( 0x040000, REGION_SOUND1, 0 )		/* Samples */
	ROM_LOAD( "rl_10.rom", 0x000000, 0x040000, CRC(e1d1cd99) SHA1(6604111d37455c1bd59c1469d9ee7841e7dec913) )

	ROM_REGION( 0x040000, REGION_SOUND2, 0 )		/* Samples */
	ROM_LOAD( "rl_08.rom", 0x000000, 0x040000, CRC(8a49d3a7) SHA1(68cb8cf2753b39c253d0edaa8ef2c54fd1f6ebe5) )

	ROM_REGION( 0x0200, REGION_PROMS, 0 )		/* Priority PROM */
	ROM_LOAD( "rl.bin",    0x0000, 0x0200, CRC(8914e72d) SHA1(80a664471f14c8ed8544a5e226fdca425ab3c657) )
ROM_END

/* 100% identical to rodlandj, but not encrypted */
ROM_START( rodlndjb )
	ROM_REGION( 0x60000, REGION_CPU1, 0 )		/* Main CPU Code */
	ROM_LOAD16_BYTE( "rl19.bin", 0x000000, 0x010000, CRC(028de21f) SHA1(04c88a0138dd119655b4a8a965617781a9a6ff71) )
	ROM_LOAD16_BYTE( "rl17.bin", 0x000001, 0x010000, CRC(9c720046) SHA1(8543f0942863b4aa5329572dd1f374ea18c29851) )
	ROM_LOAD16_BYTE( "rl20.bin", 0x020000, 0x010000, CRC(3f536d07) SHA1(cfcf47c42677fae204b3a7d70786d157279ba6e5) )
	ROM_LOAD16_BYTE( "rl18.bin", 0x020001, 0x010000, CRC(5aa61717) SHA1(3292cdafc10b412c06addc3c6d4e39ee70ff06e8) )
	ROM_LOAD16_BYTE( "rl_3.bin", 0x040000, 0x010000, CRC(c5b1075f) SHA1(a8bcc0e9dbb4b731bc0b7e5a8e0efc3d142505b9) )
	ROM_LOAD16_BYTE( "rl_4.bin", 0x040001, 0x010000, CRC(9ec61048) SHA1(71b6af054a528af04e23affff635a9358537cd3b) )

	ROM_REGION( 0x20000, REGION_CPU2, 0 )		/* Sound CPU Code */
	ROM_LOAD16_BYTE( "rl02.bin", 0x000000, 0x010000, CRC(d26eae8f) SHA1(1c6d514e6d006f78fa7b24d18a3eb4c5a4c5cbce) )
	ROM_LOAD16_BYTE( "rl01.bin", 0x000001, 0x010000, CRC(04cf24bc) SHA1(e754cce3c83a7088daf90e753fbb0df9ef7fc9be) )

	ROM_REGION( 0x080000, REGION_GFX1, ROMREGION_DISPOSE ) /* Scroll 0 */
	ROM_LOAD( "rl_23.rom", 0x000000, 0x020000, CRC(ac60e771) SHA1(97c2ac1ed89c171a0db98befa6c3c10754d64880) )
	ROM_CONTINUE(          0x030000, 0x010000 )
	ROM_CONTINUE(          0x050000, 0x010000 )
	ROM_CONTINUE(          0x020000, 0x010000 )
	ROM_CONTINUE(          0x040000, 0x010000 )
	ROM_CONTINUE(          0x060000, 0x020000 )

	ROM_REGION( 0x080000, REGION_GFX2, ROMREGION_DISPOSE ) /* Scroll 1 */
	ROM_LOAD( "rl_18.rom", 0x000000, 0x080000, CRC(f3b30ca6) SHA1(f2f88c24a009b6695f7548aebd37b25d1fd19892) )

	ROM_REGION( 0x020000, REGION_GFX3, ROMREGION_DISPOSE ) /* Scroll 2 */
	ROM_LOAD( "rl_19.bin", 0x000000, 0x020000, CRC(124d7e8f) SHA1(d7885a10085cc3389bd0e26e9d54adb8929218c0) )

	ROM_REGION( 0x080000, REGION_GFX4, ROMREGION_DISPOSE ) /* Sprites */
	ROM_LOAD( "rl_14.rom", 0x000000, 0x080000, CRC(08d01bf4) SHA1(b9333d11572f46992cdd668908fbc1c33d841f8d) )

	ROM_REGION( 0x040000, REGION_SOUND1, 0 )		/* Samples */
	ROM_LOAD( "rl_10.rom", 0x000000, 0x040000, CRC(e1d1cd99) SHA1(6604111d37455c1bd59c1469d9ee7841e7dec913) )

	ROM_REGION( 0x040000, REGION_SOUND2, 0 )		/* Samples */
	ROM_LOAD( "rl_08.rom", 0x000000, 0x040000, CRC(8a49d3a7) SHA1(68cb8cf2753b39c253d0edaa8ef2c54fd1f6ebe5) )

	ROM_REGION( 0x0200, REGION_PROMS, 0 )		/* Priority PROM */
	ROM_LOAD( "rl.bin",    0x0000, 0x0200, CRC(8914e72d) SHA1(80a664471f14c8ed8544a5e226fdca425ab3c657) )
ROM_END


INPUT_PORTS_START( rodland )

	COINS						/* 0x80001.b */
//  fire    ladder
	PORT_START_TAG("IN1")
	JOY_2BUTTONS(1)	/* 0x80003.b */
	PORT_START_TAG("IN2")
	RESERVE						/* 0x80004.b */
	PORT_START_TAG("IN3")
	JOY_2BUTTONS(2)	/* 0x80005.b */

	PORT_START_TAG("DSW1")			/* 0x80006.b */
	COINAGE_6BITS
	PORT_DIPNAME( 0x40, 0x00, DEF_STR( Demo_Sounds ) )
	PORT_DIPSETTING(    0x40, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_SERVICE( 0x80, IP_ACTIVE_LOW )

	PORT_START_TAG("DSW2")			/* 0x80007.b */
	PORT_DIPNAME( 0x01, 0x01, DEF_STR( Unknown ) ) /* according to manual */
	PORT_DIPSETTING(    0x01, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x02, 0x02, DEF_STR( Unknown ) ) /* according to manual */
	PORT_DIPSETTING(    0x02, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x0c, 0x0c, DEF_STR( Lives ) )
	PORT_DIPSETTING(    0x04, "2" )
	PORT_DIPSETTING(    0x0c, "3" )
	PORT_DIPSETTING(    0x08, "4" )
	PORT_DIPSETTING(    0x00, "Infinite (Cheat)")
	PORT_DIPNAME( 0x10, 0x10, "Default episode" )
	PORT_DIPSETTING(    0x10, "1" )
	PORT_DIPSETTING(    0x00, "2" )
	PORT_DIPNAME( 0x60, 0x60, DEF_STR( Difficulty ) )
	PORT_DIPSETTING(    0x20, "Easy?" )
	PORT_DIPSETTING(    0x60, DEF_STR( Normal ) )
	PORT_DIPSETTING(    0x40, "Hard?" )
	PORT_DIPSETTING(    0x00, "Hardest?" )
	PORT_DIPNAME( 0x80, 0x80, DEF_STR( Flip_Screen ) )
	PORT_DIPSETTING(    0x80, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )

INPUT_PORTS_END


/***************************************************************************

                            [ Saint Dragon ]

            *** Press coin on startup to enter test mode ***

interrupts: 1] rte  2] 620  3] 5e6

***************************************************************************/

ROM_START( stdragon )
	ROM_REGION( 0x60000, REGION_CPU1, 0 )		/* Main CPU Code */
	ROM_LOAD16_BYTE( "jsd-02.bin", 0x000000, 0x020000, CRC(cc29ab19) SHA1(e145eeb01fad313e300f0c614c0e7a5c1d75d7d9) )
	ROM_LOAD16_BYTE( "jsd-01.bin", 0x000001, 0x020000, CRC(67429a57) SHA1(f3c20fabed97ac5c2fe3e891f9c8c86478453a6c) )

	ROM_REGION( 0x20000, REGION_CPU2, 0 )		/* Sound CPU Code */
	ROM_LOAD16_BYTE( "jsd-05.bin", 0x000000, 0x010000, CRC(8c04feaa) SHA1(57e86fd88dc72d123a41f0dee80a16be38ac2e81) )
	ROM_LOAD16_BYTE( "jsd-06.bin", 0x000001, 0x010000, CRC(0bb62f3a) SHA1(68d9f161ba2568f8e046b1a40127bbb973d7a884) )

	ROM_REGION( 0x080000, REGION_GFX1, ROMREGION_DISPOSE ) /* Scroll 0 */
	ROM_LOAD( "jsd-11.bin", 0x000000, 0x020000, CRC(2783b7b1) SHA1(4edde596cf26afb33b247cf5b1420d86f8f0c104) )
	ROM_LOAD( "jsd-12.bin", 0x020000, 0x020000, CRC(89466ab7) SHA1(8de42f2828e48e4fe3c6d078f6b9d48498933d72) )
	ROM_LOAD( "jsd-13.bin", 0x040000, 0x020000, CRC(9896ae82) SHA1(953e79558d66f7bfff893a7b69450ae23f8d16a4) )
	ROM_LOAD( "jsd-14.bin", 0x060000, 0x020000, CRC(7e8da371) SHA1(0bed102bdd4dfca23ca636c7de67da1a9107eb5a) )

	ROM_REGION( 0x080000, REGION_GFX2, ROMREGION_DISPOSE ) /* Scroll 1 */
	ROM_LOAD( "jsd-15.bin", 0x000000, 0x020000, CRC(e296bf59) SHA1(15361b2c2df391656e47b815731f5f03a6a8a7a6) )
	ROM_LOAD( "jsd-16.bin", 0x020000, 0x020000, CRC(d8919c06) SHA1(643f04911ea035db7ddb593f5bf1be364f645fe1) )
	ROM_LOAD( "jsd-17.bin", 0x040000, 0x020000, CRC(4f7ad563) SHA1(ef06e0c8dc29b75cc7c449a227576be442163a6e) )
	ROM_LOAD( "jsd-18.bin", 0x060000, 0x020000, CRC(1f4da822) SHA1(fe81fb93c1aa938425b6bfca2bb829dda2d86b4a) )

	ROM_REGION( 0x020000, REGION_GFX3, ROMREGION_DISPOSE ) /* Scroll 2 */
	ROM_LOAD( "jsd-19.bin", 0x000000, 0x010000, CRC(25ce807d) SHA1(64accb923e9727093790c8ae8296e9ff2d04af06) )

	ROM_REGION( 0x080000, REGION_GFX4, ROMREGION_DISPOSE ) /* Sprites */
	ROM_LOAD( "jsd-20.bin", 0x000000, 0x020000, CRC(2c6e93bb) SHA1(6130611a0a4067ced1b646438c49387d8cea0c98) )
	ROM_LOAD( "jsd-21.bin", 0x020000, 0x020000, CRC(864bcc61) SHA1(21420a4804311fb381a9b05068d60d518fdc67db) )
	ROM_LOAD( "jsd-22.bin", 0x040000, 0x020000, CRC(44fe2547) SHA1(193f487993e10e4a00e50d7febc9e43f3d217038) )
	ROM_LOAD( "jsd-23.bin", 0x060000, 0x020000, CRC(6b010e1a) SHA1(7d056330a16725999c7b6662eb6ddeea0a4e446c) )

	ROM_REGION( 0x040000, REGION_SOUND1, 0 )		/* Samples */
	ROM_LOAD( "jsd-09.bin", 0x000000, 0x020000, CRC(e366bc5a) SHA1(c97bc1f25357366b4ff1343dfc9d0808a2630b28) )
	ROM_LOAD( "jsd-10.bin", 0x020000, 0x020000, CRC(4a8f4fe6) SHA1(4f13f0149aa29b7cbddcd782f043bb71b3d27ede) )

	ROM_REGION( 0x040000, REGION_SOUND2, 0 )		/* Samples */
	ROM_LOAD( "jsd-07.bin", 0x000000, 0x020000, CRC(6a48e979) SHA1(617281d9fe3c3927f94bf2f66d0a08923a92a6ab) )
	ROM_LOAD( "jsd-08.bin", 0x020000, 0x020000, CRC(40704962) SHA1(4efd8c4d406600aa486c8b84b6f9882cca5970a4) )

	ROM_REGION( 0x0200, REGION_PROMS, 0 )		/* Priority PROM */
	ROM_LOAD( "prom.14m",    0x0000, 0x0200, CRC(1d877538) SHA1(a5be0dc65dcfc36fbba10d1fddbe155e24b6122f) )
ROM_END

INPUT_PORTS_START( stdragon )
	COINS						/* 0x80001.b */
//  fire    fire
	PORT_START_TAG("IN1")
	JOY_2BUTTONS(1)	/* 0x80003.b */
	PORT_START_TAG("IN2")
	RESERVE						/* 0x80004.b */
	PORT_START_TAG("IN3")
	JOY_2BUTTONS(2)	/* 0x80005.b */

	PORT_START_TAG("DSW1")			/* 0x80006.b */
	COINAGE_6BITS_2
	PORT_DIPNAME( 0x40, 0x40, DEF_STR( Demo_Sounds ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x40, DEF_STR( On ) )
	PORT_DIPNAME( 0x80, 0x80, "Unknown 1-7" )	// used?
	PORT_DIPSETTING(    0x80, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )

	PORT_START_TAG("DSW2")			/* 0x80007.b */
	PORT_DIPNAME( 0x03, 0x03, DEF_STR( Lives ) )
	PORT_DIPSETTING(    0x02, "2" )
	PORT_DIPSETTING(    0x03, "3" )
	PORT_DIPSETTING(    0x01, "4" )
	PORT_DIPSETTING(    0x00, "5" )
	PORT_DIPNAME( 0x04, 0x04, "Unknown 2-2" )	// unused?
	PORT_DIPSETTING(    0x04, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x08, 0x08, "Unknown 2-3" )	// unused?
	PORT_DIPSETTING(    0x08, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x30, 0x30, DEF_STR( Difficulty ) )
	PORT_DIPSETTING(    0x30, DEF_STR( Easy ) )
	PORT_DIPSETTING(    0x20, DEF_STR( Normal ) )
	PORT_DIPSETTING(    0x10, DEF_STR( Hard ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Hardest ) )
	PORT_DIPNAME( 0x40, 0x00, DEF_STR( Cabinet ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Upright ) )
	PORT_DIPSETTING(    0x40, DEF_STR( Cocktail ) )
	PORT_DIPNAME( 0x80, 0x80, DEF_STR( Flip_Screen ) )
	PORT_DIPSETTING(    0x80, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )

INPUT_PORTS_END


/***************************************************************************

                                [ Soldam ]

(Japan version)
f00c2.l *** score/10 (BCD) ***

The country code is at ROM address $3a9d, copied to RAM address
f0025: 0 = japan, 1 = USA. Change f0025 to 1 to have all the
text in english.

***************************************************************************/

ROM_START( soldamj )
	ROM_REGION( 0x60000, REGION_CPU1, 0 )		/* Main CPU Code */
	ROM_LOAD16_BYTE( "soldam2.bin", 0x000000, 0x020000, CRC(c73d29e4) SHA1(2a6bffd6835506a0a1449047dec69445d2242fca) )
	ROM_LOAD16_BYTE( "soldam1.bin", 0x000001, 0x020000, CRC(e7cb0c20) SHA1(7b1adf439cd4022ec110ec18359fb50ac137f253) )
	ROM_LOAD16_BYTE( "soldam3.bin", 0x040000, 0x010000, CRC(c5382a07) SHA1(5342775f2925772e23bb460e88cd2b7e524e57fa) )
	ROM_LOAD16_BYTE( "soldam4.bin", 0x040001, 0x010000, CRC(1df7816f) SHA1(7c069470ec0e884eae5a52581f2be17d9e692105) )

	ROM_REGION( 0x20000, REGION_CPU2, 0 )		/* Sound CPU Code */
	ROM_LOAD16_BYTE( "soldam5.bin", 0x000000, 0x010000, CRC(d1019a67) SHA1(32d77914a67c009bf1bb397772f195594f7cc03f) )
	ROM_LOAD16_BYTE( "soldam6.bin", 0x000001, 0x010000, CRC(3ed219b4) SHA1(afffa5596027181ae94488d54d6266f8a7ead180) )

	ROM_REGION( 0x080000, REGION_GFX1, ROMREGION_DISPOSE ) /* Scroll 0 */
	ROM_LOAD( "soldam14.bin", 0x000000, 0x080000, CRC(26cea54a) SHA1(00beb1fe2973daf8bab288a0cb9d5fff26a00415) )

	ROM_REGION( 0x080000, REGION_GFX2, ROMREGION_DISPOSE ) /* Scroll 1 */
	ROM_LOAD( "soldam18.bin", 0x000000, 0x080000, CRC(7d8e4712) SHA1(d16455648dcba467336e51daac8b23e463a74230) )

	ROM_REGION( 0x020000, REGION_GFX3, ROMREGION_DISPOSE ) /* Scroll 2 */
	ROM_LOAD( "soldam19.bin", 0x000000, 0x020000, CRC(38465da1) SHA1(461fc0d81b711d0646dc366c057da66d4b8c6e23) )

	ROM_REGION( 0x080000, REGION_GFX4, ROMREGION_DISPOSE ) /* Sprites */
	ROM_LOAD( "soldam23.bin", 0x000000, 0x080000, CRC(0ca09432) SHA1(c9b12d564032c2a668e18ba95fd71ab540e798ce) )

	ROM_REGION( 0x040000, REGION_SOUND1, 0 )		/* Samples */
	ROM_LOAD( "soldam10.bin", 0x000000, 0x040000, CRC(8d5613bf) SHA1(eee217dd2ab64d86b7f5eda55a3c331d862c079e) )

	ROM_REGION( 0x040000, REGION_SOUND2, 0 )		/* Samples */
	ROM_LOAD( "soldam8.bin",  0x000000, 0x040000, CRC(fcd36019) SHA1(f4edb55bd62b697c5a73c461008e764c2f16956b) )

	ROM_REGION( 0x0200, REGION_PROMS, 0 )		/* Priority PROM */
	ROM_LOAD( "soldam.m14",   0x0000, 0x0200, CRC(8914e72d) SHA1(80a664471f14c8ed8544a5e226fdca425ab3c657) )
ROM_END

INPUT_PORTS_START( soldamj )
	COINS						/* 0x80001.b */
	//  turn    turn    (3rd button is shown in service mode, but seems unused)
	PORT_START_TAG("IN1")
	JOY_2BUTTONS(1)	/* 0x80003.b */
	PORT_START_TAG("IN2")
	RESERVE						/* 0x80004.b */
	PORT_START_TAG("IN3")
	JOY_2BUTTONS(2)	/* 0x80005.b */

	PORT_START_TAG("DSW1")			/* 0x80006.b */
	COINAGE_6BITS_2
	PORT_DIPNAME( 0x40, 0x40, DEF_STR( Demo_Sounds ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x40, DEF_STR( On )  )
	PORT_SERVICE( 0x80, IP_ACTIVE_LOW )

	PORT_START_TAG("DSW2")			/* 0x80007.b */
	PORT_DIPNAME( 0x03, 0x03, DEF_STR( Difficulty ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Easy )   )
	PORT_DIPSETTING(    0x03, DEF_STR( Normal ) )
	PORT_DIPSETTING(    0x02, DEF_STR( Hard )   )
	PORT_DIPSETTING(    0x01, DEF_STR( Hardest ))
	PORT_DIPNAME( 0x0c, 0x0c, "Games To Play (Vs)" )
	PORT_DIPSETTING(    0x00, "1" )
	PORT_DIPSETTING(    0x0c, "2" )
	PORT_DIPSETTING(    0x08, "3" )
	PORT_DIPSETTING(    0x04, "4" )
	PORT_DIPNAME( 0x10, 0x10, DEF_STR( Allow_Continue ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x10, DEF_STR( On )  )
	PORT_DIPNAME( 0x20, 0x20, "Credits To Start (Vs)" )
	PORT_DIPSETTING(    0x20, "1" )
	PORT_DIPSETTING(    0x00, "2" )
	PORT_DIPNAME( 0x40, 0x40, "Credits To Continue (Vs)" )
	PORT_DIPSETTING(    0x40, "1" )
	PORT_DIPSETTING(    0x00, "2" )
	PORT_DIPNAME( 0x80, 0x80, DEF_STR( Flip_Screen ) )
	PORT_DIPSETTING(    0x80, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On )  )

INPUT_PORTS_END

READ16_HANDLER( soldamj_spriteram16_r )
{
	return spriteram16[offset];
}
WRITE16_HANDLER( soldamj_spriteram16_w )
{
	if (offset < 0x800/2)	COMBINE_DATA(&spriteram16[offset]);
}



/***************************************************************************

                            [ Takeda Shingen ]

***************************************************************************/

ROM_START( tshingen )
	ROM_REGION( 0x60000, REGION_CPU1, 0 )		/* Main CPU Code */
	ROM_LOAD16_BYTE( "takeda2.bin", 0x000000, 0x020000, CRC(6ddfc9f3) SHA1(0ce1b8eae31453db0b2081717d7dbda9ea7d5a60) )
	ROM_LOAD16_BYTE( "takeda1.bin", 0x000001, 0x020000, CRC(1afc6b7d) SHA1(b56da1b8c5b417a88a2952491c2d5472bb783945) )

	ROM_REGION( 0x20000, REGION_CPU2, 0 )		/* Sound CPU Code */
	ROM_LOAD16_BYTE( "takeda5.bin", 0x000000, 0x010000, CRC(fbdc51c0) SHA1(bc6036c556275f7eccd7741d23437a98b0aa13bb) )
	ROM_LOAD16_BYTE( "takeda6.bin", 0x000001, 0x010000, CRC(8fa65b69) SHA1(23a2d60435f235366f877ac79ac1506a99cfae9c) )

	ROM_REGION( 0x080000, REGION_GFX1, ROMREGION_DISPOSE ) /* Scroll 0 */
	ROM_LOAD( "takeda11.bin", 0x000000, 0x020000, CRC(bf0b40a6) SHA1(3634b8700b6cfb71d3796847eab50fd2714d4726) )
	ROM_LOAD( "takeda12.bin", 0x020000, 0x020000, CRC(07987d89) SHA1(54f0fcbac6ec9c27b70a04a192db2874d38e91d8) )

	ROM_REGION( 0x080000, REGION_GFX2, ROMREGION_DISPOSE ) /* Scroll 1 */
	ROM_LOAD( "takeda15.bin", 0x000000, 0x020000, CRC(4c316b79) SHA1(1e17cb061e3d06427bef3e8c222f2a7cc80743ff) )
	ROM_LOAD( "takeda16.bin", 0x020000, 0x020000, CRC(ceda9dd6) SHA1(2339cbb3d10fae6cba32b6455511aad60f4e481a) )
	ROM_LOAD( "takeda17.bin", 0x040000, 0x020000, CRC(3d4371dc) SHA1(2a6c34eb9952492f9554e5c810f015496ac205c1) )

	ROM_REGION( 0x020000, REGION_GFX3, ROMREGION_DISPOSE ) /* Scroll 2 */
	ROM_LOAD( "takeda19.bin", 0x000000, 0x010000, CRC(2ca2420d) SHA1(0e9f2f3d8ea2be07193e5a5fd37256a3887e7a2f) )

	ROM_REGION( 0x080000, REGION_GFX4, ROMREGION_DISPOSE ) /* Sprites */
	ROM_LOAD( "takeda20.bin", 0x000000, 0x020000, CRC(1bfd636f) SHA1(d56eb7538195930ea3cf16788e3128a6262675e3) )
	ROM_LOAD( "takeda21.bin", 0x020000, 0x020000, CRC(12fb006b) SHA1(1dae7f3bdbfefb3424d07572c398e4edd274a4ae) )
	ROM_LOAD( "takeda22.bin", 0x040000, 0x020000, CRC(b165b6ae) SHA1(b987cdb5a71882d2495ac449a78705ba996943a7) )
	ROM_LOAD( "takeda23.bin", 0x060000, 0x020000, CRC(37cb9214) SHA1(b98c361cd8b19b85cd16f040c415550b3750ab9e) )

	ROM_REGION( 0x040000, REGION_SOUND1, 0 )		/* Samples */
	ROM_LOAD( "takeda9.bin",  0x000000, 0x020000, CRC(db7f3f4f) SHA1(2667bab60abe49b3a9ce4ff63948e274578062b7) )
	ROM_LOAD( "takeda10.bin", 0x020000, 0x020000, CRC(c9959d71) SHA1(afbb756b3b4730262055f80995bd4ba5f9031d26) )

	ROM_REGION( 0x040000, REGION_SOUND2, 0 )		/* Samples */
	ROM_LOAD( "shing_07.rom",  0x000000, 0x020000, CRC(c37ecbdc) SHA1(fcae2bbc4a10ee0fa18c9a850ae451c0600ea98c) )
	ROM_LOAD( "shing_08.rom",  0x020000, 0x020000, CRC(36d56c8c) SHA1(391f8c6b3ee605ce846f1862b0d3b14694dbd556) )

	ROM_REGION( 0x0200, REGION_PROMS, 0 )		/* Priority PROM */
	ROM_LOAD( "ts.bpr",        0x0000, 0x0200, CRC(85b30ac4) SHA1(b03f577ceb0f26b67453ffa52ef61fea76a93184) )
ROM_END

ROM_START( tshingna )
	ROM_REGION( 0x60000, REGION_CPU1, 0 )		/* Main CPU Code */
	ROM_LOAD16_BYTE( "shing_02.rom", 0x000000, 0x020000, CRC(d9ab5b78) SHA1(c7622ec11a636dc7a6bcad02556a98aa0a9fb043) )
	ROM_LOAD16_BYTE( "shing_01.rom", 0x000001, 0x020000, CRC(a9d2de20) SHA1(b53205722ae19305a1c373abbbac4fbcbcb0b0f0) )

	ROM_REGION( 0x20000, REGION_CPU2, 0 )		/* Sound CPU Code */
	ROM_LOAD16_BYTE( "takeda5.bin", 0x000000, 0x010000, CRC(fbdc51c0) SHA1(bc6036c556275f7eccd7741d23437a98b0aa13bb) )
	ROM_LOAD16_BYTE( "takeda6.bin", 0x000001, 0x010000, CRC(8fa65b69) SHA1(23a2d60435f235366f877ac79ac1506a99cfae9c) )

	ROM_REGION( 0x080000, REGION_GFX1, ROMREGION_DISPOSE ) /* Scroll 0 */
	ROM_LOAD( "takeda11.bin", 0x000000, 0x020000, CRC(bf0b40a6) SHA1(3634b8700b6cfb71d3796847eab50fd2714d4726) )
	ROM_LOAD( "shing_12.rom", 0x020000, 0x020000, CRC(5e4adedb) SHA1(0b67af2913e1f15d0a9d81e7b22d26a1011fa160) )

	ROM_REGION( 0x080000, REGION_GFX2, ROMREGION_DISPOSE ) /* Scroll 1 */
	ROM_LOAD( "shing_15.rom", 0x000000, 0x020000, CRC(9db18233) SHA1(d323035505159e420430d178b4fa3a972aed80cd) )
	ROM_LOAD( "takeda16.bin", 0x020000, 0x020000, CRC(ceda9dd6) SHA1(2339cbb3d10fae6cba32b6455511aad60f4e481a) )
	ROM_LOAD( "takeda17.bin", 0x040000, 0x020000, CRC(3d4371dc) SHA1(2a6c34eb9952492f9554e5c810f015496ac205c1) )

	ROM_REGION( 0x020000, REGION_GFX3, ROMREGION_DISPOSE ) /* Scroll 2 */
	ROM_LOAD( "shing_19.rom", 0x000000, 0x010000, CRC(97282d9d) SHA1(c977fb6cebbb9f4097b3c25f2b7f5cb2440c191b) )

	ROM_REGION( 0x080000, REGION_GFX4, ROMREGION_DISPOSE ) /* Sprites */
	ROM_LOAD( "shing_20.rom", 0x000000, 0x020000, CRC(7f6f8384) SHA1(77ccd8ca3cf35040e9cc8c78b2489864f60be699) )
	ROM_LOAD( "takeda21.bin", 0x020000, 0x020000, CRC(12fb006b) SHA1(1dae7f3bdbfefb3424d07572c398e4edd274a4ae) )
	ROM_LOAD( "takeda22.bin", 0x040000, 0x020000, CRC(b165b6ae) SHA1(b987cdb5a71882d2495ac449a78705ba996943a7) )
	ROM_LOAD( "takeda23.bin", 0x060000, 0x020000, CRC(37cb9214) SHA1(b98c361cd8b19b85cd16f040c415550b3750ab9e) )

	ROM_REGION( 0x040000, REGION_SOUND1, 0 )		/* Samples */
	ROM_LOAD( "takeda9.bin",  0x000000, 0x020000, CRC(db7f3f4f) SHA1(2667bab60abe49b3a9ce4ff63948e274578062b7) )
	ROM_LOAD( "takeda10.bin", 0x020000, 0x020000, CRC(c9959d71) SHA1(afbb756b3b4730262055f80995bd4ba5f9031d26) )

	ROM_REGION( 0x040000, REGION_SOUND2, 0 )		/* Samples */
	ROM_LOAD( "shing_07.rom",  0x000000, 0x020000, CRC(c37ecbdc) SHA1(fcae2bbc4a10ee0fa18c9a850ae451c0600ea98c) )
	ROM_LOAD( "shing_08.rom",  0x020000, 0x020000, CRC(36d56c8c) SHA1(391f8c6b3ee605ce846f1862b0d3b14694dbd556) )

	ROM_REGION( 0x0200, REGION_PROMS, 0 )		/* Priority PROM */
	ROM_LOAD( "ts.bpr",        0x0000, 0x0200, CRC(85b30ac4) SHA1(b03f577ceb0f26b67453ffa52ef61fea76a93184) )
ROM_END

INPUT_PORTS_START( tshingen )
	COINS						/* 0x80001.b */
	// sword_left   sword_right     jump
	PORT_START_TAG("IN1")
	JOY_3BUTTONS(1)	/* 0x80003.b */
	PORT_START_TAG("IN2")
	RESERVE						/* 0x80004.b */
	PORT_START_TAG("IN3")
	JOY_3BUTTONS(2)	/* 0x80005.b */

	PORT_START_TAG("DSW1")			/* 0x80006.b */
	COINAGE_6BITS
	PORT_DIPNAME( 0x40, 0x40, DEF_STR( Demo_Sounds ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x40, DEF_STR( On )  )
	PORT_DIPNAME( 0x80, 0x80, DEF_STR( Unknown ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x80, DEF_STR( On )  )

	PORT_START_TAG("DSW2")			/* 0x80007.b */
	PORT_DIPNAME( 0x03, 0x01, DEF_STR( Lives ) )
	PORT_DIPSETTING(    0x03, "2" )
	PORT_DIPSETTING(    0x01, "3" )
	PORT_DIPSETTING(    0x02, "4" )
	PORT_DIPSETTING(    0x00, "Infinite (Cheat)")
	PORT_DIPNAME( 0x0c, 0x0c, DEF_STR( Bonus_Life ) )
	PORT_DIPSETTING(    0x0c, "20k" )
	PORT_DIPSETTING(    0x04, "30k" )
	PORT_DIPSETTING(    0x08, "40k" )
	PORT_DIPSETTING(    0x00, "50k" )
	PORT_DIPNAME( 0x30, 0x10, DEF_STR( Difficulty ) ) // damage when hit
	PORT_DIPSETTING(    0x30, DEF_STR( Easy )    ) // 0
	PORT_DIPSETTING(    0x10, DEF_STR( Normal )  ) // 1
	PORT_DIPSETTING(    0x20, DEF_STR( Hard )    ) // 2
	PORT_DIPSETTING(    0x00, DEF_STR( Hardest ) ) // 3
	PORT_DIPNAME( 0x40, 0x40, DEF_STR( Allow_Continue ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x40, DEF_STR( On )  )
	PORT_DIPNAME( 0x80, 0x80, DEF_STR( Flip_Screen ) )
	PORT_DIPSETTING(    0x80, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On )  )

INPUT_PORTS_END




/***************************************************************************

                             Code Decryption

***************************************************************************/

void phantasm_rom_decode(int cpu)
{
	UINT16	*RAM	=	(UINT16 *) memory_region(REGION_CPU1+cpu);
	int i,		size	=	memory_region_length(REGION_CPU1+cpu);
	if (size > 0x40000)	size = 0x40000;

	for (i = 0 ; i < size/2 ; i++)
	{
		UINT16 x,y;

		x = RAM[i];

// [0] def0 189a bc56 7234
// [1] fdb9 7531 eca8 6420
// [2] 0123 4567 ba98 fedc
#define BITSWAP_0	BITSWAP16(x,0xd,0xe,0xf,0x0,0x1,0x8,0x9,0xa,0xb,0xc,0x5,0x6,0x7,0x2,0x3,0x4)
#define BITSWAP_1	BITSWAP16(x,0xf,0xd,0xb,0x9,0x7,0x5,0x3,0x1,0xe,0xc,0xa,0x8,0x6,0x4,0x2,0x0)
#define BITSWAP_2	BITSWAP16(x,0x0,0x1,0x2,0x3,0x4,0x5,0x6,0x7,0xb,0xa,0x9,0x8,0xf,0xe,0xd,0xc)

		if		(i < 0x08000/2)	{ if ( (i | (0x248/2)) != i ) {y = BITSWAP_0;} else {y = BITSWAP_1;} }
		else if	(i < 0x10000/2)	{ y = BITSWAP_2; }
		else if	(i < 0x18000/2)	{ if ( (i | (0x248/2)) != i ) {y = BITSWAP_0;} else {y = BITSWAP_1;} }
		else if	(i < 0x20000/2)	{ y = BITSWAP_1; }
		else 					{ y = BITSWAP_2; }

#undef	BITSWAP_0
#undef	BITSWAP_1
#undef	BITSWAP_2

		RAM[i] = y;
	}

}

void astyanax_rom_decode(int cpu)
{
	UINT16	*RAM	=	(UINT16 *) memory_region(REGION_CPU1+cpu);
	int i,		size	=	memory_region_length(REGION_CPU1+cpu);
	if (size > 0x40000)	size = 0x40000;

	for (i = 0 ; i < size/2 ; i++)
	{
		UINT16 x,y;

		x = RAM[i];

// [0] def0 a981 65cb 7234
// [1] fdb9 7531 8ace 0246
// [2] 4567 0123 ba98 fedc

#define BITSWAP_0	BITSWAP16(x,0xd,0xe,0xf,0x0,0xa,0x9,0x8,0x1,0x6,0x5,0xc,0xb,0x7,0x2,0x3,0x4)
#define BITSWAP_1	BITSWAP16(x,0xf,0xd,0xb,0x9,0x7,0x5,0x3,0x1,0x8,0xa,0xc,0xe,0x0,0x2,0x4,0x6)
#define BITSWAP_2	BITSWAP16(x,0x4,0x5,0x6,0x7,0x0,0x1,0x2,0x3,0xb,0xa,0x9,0x8,0xf,0xe,0xd,0xc)

		if		(i < 0x08000/2)	{ if ( (i | (0x248/2)) != i ) {y = BITSWAP_0;} else {y = BITSWAP_1;} }
		else if	(i < 0x10000/2)	{ y = BITSWAP_2; }
		else if	(i < 0x18000/2)	{ if ( (i | (0x248/2)) != i ) {y = BITSWAP_0;} else {y = BITSWAP_1;} }
		else if	(i < 0x20000/2)	{ y = BITSWAP_1; }
		else 					{ y = BITSWAP_2; }

#undef	BITSWAP_0
#undef	BITSWAP_1
#undef	BITSWAP_2

		RAM[i] = y;
	}
}

void rodland_rom_decode(int cpu)
{
	UINT16	*RAM	=	(UINT16 *) memory_region(REGION_CPU1+cpu);
	int i,		size	=	memory_region_length(REGION_CPU1+cpu);
	if (size > 0x40000)	size = 0x40000;

	for (i = 0 ; i < size/2 ; i++)
	{
		UINT16 x,y;

		x = RAM[i];

// [0] d0a9 6ebf 5c72 3814  [1] 4567 0123 ba98 fedc
// [2] fdb9 ce07 5318 a246  [3] 4512 ed3b a967 08fc
#define BITSWAP_0	BITSWAP16(x,0xd,0x0,0xa,0x9,0x6,0xe,0xb,0xf,0x5,0xc,0x7,0x2,0x3,0x8,0x1,0x4);
#define BITSWAP_1	BITSWAP16(x,0x4,0x5,0x6,0x7,0x0,0x1,0x2,0x3,0xb,0xa,0x9,0x8,0xf,0xe,0xd,0xc);
#define	BITSWAP_2	BITSWAP16(x,0xf,0xd,0xb,0x9,0xc,0xe,0x0,0x7,0x5,0x3,0x1,0x8,0xa,0x2,0x4,0x6);
#define	BITSWAP_3	BITSWAP16(x,0x4,0x5,0x1,0x2,0xe,0xd,0x3,0xb,0xa,0x9,0x6,0x7,0x0,0x8,0xf,0xc);

		if		(i < 0x08000/2)	{	if ( (i | (0x248/2)) != i ) {y = BITSWAP_0;} else {y = BITSWAP_1;} }
		else if	(i < 0x10000/2)	{	if ( (i | (0x248/2)) != i ) {y = BITSWAP_2;} else {y = BITSWAP_3;} }
		else if	(i < 0x18000/2)	{	if ( (i | (0x248/2)) != i ) {y = BITSWAP_0;} else {y = BITSWAP_1;} }
		else if	(i < 0x20000/2)	{ y = BITSWAP_1; }
		else 					{ y = BITSWAP_3; }

#undef	BITSWAP_0
#undef	BITSWAP_1
#undef	BITSWAP_2
#undef	BITSWAP_3

		RAM[i] = y;
	}
}


static void rodlandj_gfx_unmangle(int region)
{
	UINT8 *rom = memory_region(REGION_GFX1+region);
	int size = memory_region_length(REGION_GFX1+region);
	UINT8 *buffer;
	int i;

	/* data lines swap: 76543210 -> 64537210 */
	for (i = 0;i < size;i++)
		rom[i] =   (rom[i] & 0x27)
				| ((rom[i] & 0x80) >> 4)
				| ((rom[i] & 0x48) << 1)
				| ((rom[i] & 0x10) << 2);

	buffer = malloc(size);
	if (!buffer) return;

	memcpy(buffer,rom,size);

	/* address lines swap: ..dcba9876543210 -> ..acb8937654d210 */
	for (i = 0;i < size;i++)
	{
		int a =    (i &~0x2508)
				| ((i & 0x2000) >> 10)
				| ((i & 0x0400) << 3)
				| ((i & 0x0100) << 2)
				| ((i & 0x0008) << 5);
		rom[i] = buffer[a];
	}

	free(buffer);
}

static void jitsupro_gfx_unmangle(int region)
{
	UINT8 *rom = memory_region(REGION_GFX1+region);
	int size = memory_region_length(REGION_GFX1+region);
	UINT8 *buffer;
	int i;

	/* data lines swap: 76543210 -> 43576210 */
	for (i = 0;i < size;i++)
		rom[i] =   BITSWAP8(rom[i],0x4,0x3,0x5,0x7,0x6,0x2,0x1,0x0);

	buffer = malloc(size);
	if (!buffer) return;

	memcpy(buffer,rom,size);

	/* address lines swap: fedcba9876543210 -> fe8cb39d7654a210 */
	for (i = 0;i < size;i++)
	{
		int a = (i & ~0xffff) |
	BITSWAP16(i,0xf,0xe,0x8,0xc,0xb,0x3,0x9,0xd,0x7,0x6,0x5,0x4,0xa,0x2,0x1,0x0);

		rom[i] = buffer[a];
	}

	free(buffer);
}




static DRIVER_INIT( 64street )
{
//  UINT16 *RAM = (UINT16 *) memory_region(REGION_CPU1);
//  RAM[0x006b8/2] = 0x6004;        // d8001 test
//  RAM[0x10EDE/2] = 0x6012;        // watchdog

	ip_select_values[0] = 0x57;
	ip_select_values[1] = 0x53;
	ip_select_values[2] = 0x54;
	ip_select_values[3] = 0x55;
	ip_select_values[4] = 0x56;
}

static DRIVER_INIT( astyanax )
{
	UINT16 *RAM;

	astyanax_rom_decode(0);

	RAM = (UINT16 *) memory_region(REGION_CPU1);
	RAM[0x0004e6/2] = 0x6040;	// protection
}

static DRIVER_INIT( avspirit )
{
	ip_select_values[0] = 0x37;
	ip_select_values[1] = 0x35;
	ip_select_values[2] = 0x36;
	ip_select_values[3] = 0x33;
	ip_select_values[4] = 0x34;

	/* kludge: avspirit has 0x10000 bytes of RAM while edf has 0x20000. The */
	/* following is needed to make vh_start() pick the correct address */
	/* for spriteram16. */
	megasys1_ram += 0x10000/2;
}

static DRIVER_INIT( bigstrik )
{
	ip_select_values[0] = 0x58;
	ip_select_values[1] = 0x54;
	ip_select_values[2] = 0x55;
	ip_select_values[3] = 0x56;
	ip_select_values[4] = 0x57;
}

static DRIVER_INIT( chimerab )
{
	/* same as cybattlr */
	ip_select_values[0] = 0x56;
	ip_select_values[1] = 0x52;
	ip_select_values[2] = 0x53;
	ip_select_values[3] = 0x54;
	ip_select_values[4] = 0x55;
}

static DRIVER_INIT( cybattlr )
{
	ip_select_values[0] = 0x56;
	ip_select_values[1] = 0x52;
	ip_select_values[2] = 0x53;
	ip_select_values[3] = 0x54;
	ip_select_values[4] = 0x55;
}

static DRIVER_INIT( edf )
{
	ip_select_values[0] = 0x20;
	ip_select_values[1] = 0x21;
	ip_select_values[2] = 0x22;
	ip_select_values[3] = 0x23;
	ip_select_values[4] = 0x24;
}

static DRIVER_INIT( hachoo )
{
	UINT16 *RAM;

	astyanax_rom_decode(0);

	RAM  = (UINT16 *) memory_region(REGION_CPU1);
	RAM[0x0006da/2] = 0x6000;	// protection
}

static DRIVER_INIT( iganinju )
{
	UINT16 *RAM;

	phantasm_rom_decode(0);

	RAM  = (UINT16 *) memory_region(REGION_CPU1);
	RAM[0x02f000/2] = 0x835d;	// protection

	RAM[0x00006e/2] = 0x0420;	// the only game that does
								// not like lev 3 interrupts
}

static WRITE16_HANDLER( OKIM6295_data_0_both_w )
{
	if (ACCESSING_LSB)	OKIM6295_data_0_w(0, (data >> 0) & 0xff );
	else				OKIM6295_data_0_w(0, (data >> 8) & 0xff );
}
static WRITE16_HANDLER( OKIM6295_data_1_both_w )
{
	if (ACCESSING_LSB)	OKIM6295_data_1_w(0, (data >> 0) & 0xff );
	else				OKIM6295_data_1_w(0, (data >> 8) & 0xff );
}

static DRIVER_INIT( jitsupro )
{
	UINT16 *RAM  = (UINT16 *) memory_region(REGION_CPU1);

	astyanax_rom_decode(0);		// Code

	jitsupro_gfx_unmangle(0);	// Gfx
	jitsupro_gfx_unmangle(3);

	RAM[0x436/2] = 0x4e71;	// protection
	RAM[0x438/2] = 0x4e71;	//

	/* the sound code writes oki commands to both the lsb and msb */
	memory_install_write16_handler(1, ADDRESS_SPACE_PROGRAM, 0xa0000, 0xa0003, 0, 0, OKIM6295_data_0_both_w);
	memory_install_write16_handler(1, ADDRESS_SPACE_PROGRAM, 0xc0000, 0xc0003, 0, 0, OKIM6295_data_1_both_w);
}

static DRIVER_INIT( peekaboo )
{
	memory_install_read16_handler(0, ADDRESS_SPACE_PROGRAM, 0x100000, 0x100001, 0, 0, protection_peekaboo_r);
	memory_install_write16_handler(0, ADDRESS_SPACE_PROGRAM, 0x100000, 0x100001, 0, 0, protection_peekaboo_w);
}

static DRIVER_INIT( phantasm )
{
	phantasm_rom_decode(0);
}

static DRIVER_INIT( plusalph )
{
	UINT16 *RAM;

	astyanax_rom_decode(0);

	RAM  = (UINT16 *) memory_region(REGION_CPU1);
	RAM[0x0012b6/2] = 0x0000;	// protection
}

static DRIVER_INIT( rodland )
{
	rodland_rom_decode(0);
}

static DRIVER_INIT( rodlandj )
{
	rodlandj_gfx_unmangle(0);
	rodlandj_gfx_unmangle(3);

	astyanax_rom_decode(0);
}

static DRIVER_INIT( soldam )
{
	astyanax_rom_decode(0);

	/* Sprite RAM is mirrored. Why? */
	memory_install_read16_handler(0, ADDRESS_SPACE_PROGRAM, 0x8c000, 0x8cfff, 0, 0, soldamj_spriteram16_r);
	memory_install_write16_handler(0, ADDRESS_SPACE_PROGRAM, 0x8c000, 0x8cfff, 0, 0, soldamj_spriteram16_w);
}

static DRIVER_INIT( stdragon )
{
	UINT16 *RAM;

	phantasm_rom_decode(0);

	RAM  = (UINT16 *) memory_region(REGION_CPU1);
	RAM[0x00045e/2] = 0x0098;	// protection
}



GAME( 1988, lomakai,  0,        system_Z,          lomakai,  0,        ROT0,   "Jaleco", "Legend of Makai (World)", 0 )
GAME( 1988, makaiden, lomakai,  system_Z,          lomakai,  0,        ROT0,   "Jaleco", "Makai Densetsu (Japan)", 0 )
GAME( 1988, p47,      0,        system_A,          p47,      0,        ROT0,   "Jaleco", "P-47 - The Phantom Fighter (World)", 0 )
GAME( 1988, p47j,     p47,      system_A,          p47,      0,        ROT0,   "Jaleco", "P-47 - The Freedom Fighter (Japan)", 0 )
GAME( 1988, kickoff,  0,        system_A,          kickoff,  0,        ROT0,   "Jaleco", "Kick Off (Japan)", 0 )
GAME( 1988, tshingen, 0,        system_A,          tshingen, phantasm, ROT0,   "Jaleco", "Takeda Shingen (Japan, Japanese)", 0 )
GAME( 1988, tshingna, tshingen, system_A,          tshingen, phantasm, ROT0,   "Jaleco", "Shingen Samurai-Fighter (Japan, English)", 0 )
GAME( 1988, kazan,    0,        system_A_iganinju, kazan,    iganinju, ROT0,   "Jaleco", "Ninja Kazan (World)", 0 )
GAME( 1988, iganinju, kazan,    system_A_iganinju, kazan,    iganinju, ROT0,   "Jaleco", "Iga Ninjyutsuden (Japan)", 0 )
GAME( 1989, astyanax, 0,        system_A,          astyanax, astyanax, ROT0,   "Jaleco", "The Astyanax", 0 )
GAME( 1989, lordofk,  astyanax, system_A,          astyanax, astyanax, ROT0,   "Jaleco", "The Lord of King (Japan)", 0 )
GAME( 1989, hachoo,   0,        system_A_hachoo,   hachoo,   hachoo,   ROT0,   "Jaleco", "Hachoo!", 0 )
GAME( 1989, jitsupro, 0,        system_A,          jitsupro, jitsupro, ROT0,   "Jaleco", "Jitsuryoku!! Pro Yakyuu (Japan)", 0 )
GAME( 1989, plusalph, 0,        system_A,          plusalph, plusalph, ROT270, "Jaleco", "Plus Alpha", 0 )
GAME( 1989, stdragon, 0,        system_A,          stdragon, stdragon, ROT0,   "Jaleco", "Saint Dragon", 0 )
GAME( 1990, rodland,  0,        system_A,          rodland,  rodland,  ROT0,   "Jaleco", "Rod-Land (World)", 0 )
GAME( 1990, rodlandj, rodland,  system_A,          rodland,  rodlandj, ROT0,   "Jaleco", "Rod-Land (Japan)", 0 )
GAME( 1990, rodlndjb, rodland,  system_A,          rodland,  0,        ROT0,   "Jaleco", "Rod-Land (Japan bootleg)", 0 )
GAME( 1991, avspirit, 0,        system_B,          avspirit, avspirit, ROT0,   "Jaleco", "Avenging Spirit", 0 )
GAME( 1990, phantasm, avspirit, system_A,          avspirit, phantasm, ROT0,   "Jaleco", "Phantasm (Japan)", 0 )
GAME( 1991, edf,      0,        system_B,          edf,      edf,      ROT0,   "Jaleco", "E.D.F. : Earth Defense Force", 0 )
GAME( 1991, edfu,     edf,      system_B,          edf,      edf,      ROT0,   "Jaleco", "E.D.F. : Earth Defense Force (North America)", 0 )
GAME( 1991, 64street, 0,        system_C,          64street, 64street, ROT0,   "Jaleco", "64th. Street - A Detective Story (World)", 0 )
GAME( 1991, 64streej, 64street, system_C,          64street, 64street, ROT0,   "Jaleco", "64th. Street - A Detective Story (Japan)", 0 )
GAME( 1992, soldamj,  0,        system_A,          soldamj,  soldam,   ROT0,   "Jaleco", "Soldam (Japan)", 0 )
GAME( 1992, bigstrik, 0,        system_C,          bigstrik, bigstrik, ROT0,   "Jaleco", "Big Striker", 0 )
GAME( 1993, chimerab, 0,        system_C,          chimerab, chimerab, ROT0,   "Jaleco", "Chimera Beast (prototype)", 0 )
GAME( 1993, cybattlr, 0,        system_C,          cybattlr, cybattlr, ROT90,  "Jaleco", "Cybattler", 0 )
GAME( 1993, peekaboo, 0,        system_D,          peekaboo, peekaboo, ROT0,   "Jaleco", "Peek-a-Boo!", 0 )
