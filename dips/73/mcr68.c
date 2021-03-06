# MAME 0.73 source snippet


#include "driver.h"
#include "sndhrdw/mcr.h"
#include "sndhrdw/williams.h"
#include "vidhrdw/generic.h"
#include "mcr.h"


/*************************************
 *
 *	Port definitions
 *
 *************************************/

INPUT_PORTS_START( zwackery )
	PORT_START
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_START1 )
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_START2 )
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_COIN1 )
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_COIN2 )
	PORT_SERVICE( 0x0010, IP_ACTIVE_LOW )
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_COIN4 )
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_TILT )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_BUTTON1 )	/* sword */

	PORT_START
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT | IPF_8WAY )
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT | IPF_8WAY )
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN | IPF_8WAY )
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_JOYSTICK_UP | IPF_8WAY )
	PORT_BIT( 0xf0, IP_ACTIVE_HIGH, IPT_UNUSED )	/* sound communications */

	PORT_START
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_BUTTON3 )	/* spell up */
	PORT_BIT( 0x3e, IP_ACTIVE_HIGH, IPT_UNUSED )	/* encoder wheel */
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_BUTTON2 )	/* shield */
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_BUTTON4 )	/* spell down */

	PORT_START
	PORT_BIT( 0xff, IP_ACTIVE_LOW, IPT_UNUSED )

	PORT_START
	PORT_DIPNAME( 0x07, 0x00, DEF_STR( Coinage ) )
	PORT_DIPSETTING(    0x05, DEF_STR( 6C_1C ) )
	PORT_DIPSETTING(    0x04, DEF_STR( 5C_1C ) )
	PORT_DIPSETTING(    0x03, DEF_STR( 4C_1C ) )
	PORT_DIPSETTING(    0x02, DEF_STR( 3C_1C ) )
	PORT_DIPSETTING(    0x01, DEF_STR( 2C_1C ) )
	PORT_DIPSETTING(    0x00, DEF_STR( 1C_1C ) )
	PORT_DIPSETTING(    0x06, DEF_STR( 1C_2C ) )
	PORT_DIPSETTING(    0x07, DEF_STR( Free_Play ) )
	PORT_DIPNAME( 0x38, 0x00, "Buy-in" )
	PORT_DIPSETTING(    0x00, "1 coin" )
	PORT_DIPSETTING(    0x08, "2 coins" )
	PORT_DIPSETTING(    0x10, "3 coins" )
	PORT_DIPSETTING(    0x18, "4 coins" )
	PORT_DIPSETTING(    0x20, "5 coins" )
	PORT_DIPSETTING(    0x28, "6 coins" )
	PORT_DIPSETTING(    0x30, "7 coins" )
	PORT_DIPSETTING(    0x38, "None" )
	PORT_DIPNAME( 0xc0, 0x00, DEF_STR( Difficulty ) )
	PORT_DIPSETTING(    0xc0, "Easier" )
	PORT_DIPSETTING(    0x00, "Normal" )
	PORT_DIPSETTING(    0x40, "Harder" )
	PORT_DIPSETTING(    0x80, "Hardest" )

	PORT_START
	PORT_ANALOGX( 0xff, 0x00, IPT_DIAL | IPF_REVERSE, 50, 10, 0, 0, KEYCODE_Z, KEYCODE_X, 0, 0 )
INPUT_PORTS_END


INPUT_PORTS_START( xenophob )
	PORT_START
	PORT_BIT( 0x0001, IP_ACTIVE_LOW, IPT_COIN1 )
	PORT_BIT( 0x0002, IP_ACTIVE_LOW, IPT_COIN2 )
	PORT_BIT( 0x0004, IP_ACTIVE_LOW, IPT_COIN3 )
	PORT_BIT( 0x0018, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x0020, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x0040, IP_ACTIVE_LOW, IPT_TILT )
	PORT_SERVICE( 0x0080, IP_ACTIVE_LOW )
	PORT_BIT( 0x0100, IP_ACTIVE_LOW, IPT_JOYSTICK_UP | IPF_8WAY | IPF_PLAYER1 )
	PORT_BIT( 0x0200, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN | IPF_8WAY | IPF_PLAYER1 )
	PORT_BIT( 0x0400, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT | IPF_8WAY | IPF_PLAYER1 )
	PORT_BIT( 0x0800, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT | IPF_8WAY | IPF_PLAYER1 )
	PORT_BIT( 0x1000, IP_ACTIVE_LOW, IPT_BUTTON1 | IPF_PLAYER1 )
	PORT_BIT( 0x2000, IP_ACTIVE_LOW, IPT_BUTTON3 | IPF_PLAYER1 )
	PORT_BIT( 0x4000, IP_ACTIVE_LOW, IPT_BUTTON2 | IPF_PLAYER1 )
	PORT_BIT( 0x8000, IP_ACTIVE_LOW, IPT_UNUSED )

	PORT_START
	PORT_BIT( 0x0001, IP_ACTIVE_LOW, IPT_JOYSTICK_UP | IPF_8WAY | IPF_PLAYER3 )
	PORT_BIT( 0x0002, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN | IPF_8WAY | IPF_PLAYER3 )
	PORT_BIT( 0x0004, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT | IPF_8WAY | IPF_PLAYER3 )
	PORT_BIT( 0x0008, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT | IPF_8WAY | IPF_PLAYER3 )
	PORT_BIT( 0x0010, IP_ACTIVE_LOW, IPT_BUTTON1 | IPF_PLAYER3 )
	PORT_BIT( 0x0020, IP_ACTIVE_LOW, IPT_BUTTON3 | IPF_PLAYER3 )
	PORT_BIT( 0x0040, IP_ACTIVE_LOW, IPT_BUTTON2 | IPF_PLAYER3 )
	PORT_BIT( 0x0080, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x0100, IP_ACTIVE_LOW, IPT_JOYSTICK_UP | IPF_8WAY | IPF_PLAYER2 )
	PORT_BIT( 0x0200, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN | IPF_8WAY | IPF_PLAYER2 )
	PORT_BIT( 0x0400, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT | IPF_8WAY | IPF_PLAYER2 )
	PORT_BIT( 0x0800, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT | IPF_8WAY | IPF_PLAYER2 )
	PORT_BIT( 0x1000, IP_ACTIVE_LOW, IPT_BUTTON1 | IPF_PLAYER2 )
	PORT_BIT( 0x2000, IP_ACTIVE_LOW, IPT_BUTTON3 | IPF_PLAYER2 )
	PORT_BIT( 0x4000, IP_ACTIVE_LOW, IPT_BUTTON2 | IPF_PLAYER2 )
	PORT_BIT( 0x8000, IP_ACTIVE_LOW, IPT_UNUSED )

	PORT_START
	PORT_BIT( 0x0003, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_DIPNAME( 0x0004, 0x0004, DEF_STR( Free_Play ) )
	PORT_DIPSETTING(      0x0004, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( On ) )
	PORT_DIPNAME( 0x0008, 0x0008, "Coins per Life Unit" )
	PORT_DIPSETTING(      0x0008, "1" )
	PORT_DIPSETTING(      0x0000, "2" )
	PORT_DIPNAME( 0x0010, 0x0010, "Life Unit" )
	PORT_DIPSETTING(      0x0010, "1000" )
	PORT_DIPSETTING(      0x0000, "2000" )
	PORT_DIPNAME( 0x0020, 0x0020, DEF_STR( Demo_Sounds ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0020, DEF_STR( On ) )
	PORT_DIPNAME( 0x00c0, 0x0000, DEF_STR( Difficulty ) )
	PORT_DIPSETTING(      0x0040, "Easy" )
	PORT_DIPSETTING(      0x0000, "Medium" )
	PORT_DIPSETTING(      0x0080, "Hard" )
/*	PORT_DIPSETTING(      0x00c0, "Medium" )*/
	PORT_BIT( 0xff00, IP_ACTIVE_LOW, IPT_UNUSED )
INPUT_PORTS_END


INPUT_PORTS_START( spyhunt2 )
	PORT_START
	PORT_BIT( 0x0001, IP_ACTIVE_LOW, IPT_COIN1 )
	PORT_BIT( 0x0002, IP_ACTIVE_LOW, IPT_COIN2 )
	PORT_BIT( 0x0004, IP_ACTIVE_LOW, IPT_START1 )
	PORT_BIT( 0x0008, IP_ACTIVE_LOW, IPT_START2 )
	PORT_BIT( 0x0010, IP_ACTIVE_LOW, IPT_TILT )
	PORT_BIT( 0x0020, IP_ACTIVE_HIGH, IPT_UNKNOWN ) /* SG status */
	PORT_BIT( 0x0040, IP_ACTIVE_LOW, IPT_SERVICE )
	PORT_SERVICE( 0x0080, IP_ACTIVE_LOW )
	PORT_BIT( 0xff00, IP_ACTIVE_HIGH, IPT_UNKNOWN )

	PORT_START
	PORT_BIT( 0x0001, IP_ACTIVE_LOW, IPT_BUTTON5 | IPF_PLAYER2 ) /* 1st gear */
	PORT_BIT( 0x0002, IP_ACTIVE_LOW, IPT_BUTTON6 | IPF_PLAYER2 ) /* 2nd gear */
	PORT_BIT( 0x0004, IP_ACTIVE_LOW, IPT_BUTTON7 | IPF_PLAYER2 ) /* 3rd gear */
	PORT_BIT( 0x0008, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x0010, IP_ACTIVE_LOW, IPT_BUTTON5 | IPF_PLAYER1 ) /* 1st gear */
	PORT_BIT( 0x0020, IP_ACTIVE_LOW, IPT_BUTTON6 | IPF_PLAYER1 ) /* 2nd gear */
	PORT_BIT( 0x0040, IP_ACTIVE_LOW, IPT_BUTTON7 | IPF_PLAYER1 ) /* 3rd gear */
	PORT_BIT( 0x0080, IP_ACTIVE_HIGH, IPT_UNUSED )               /* TCS status */
	PORT_BIT( 0x0100, IP_ACTIVE_LOW, IPT_BUTTON3 | IPF_PLAYER2 ) /* Left Trigger */
	PORT_BIT( 0x0200, IP_ACTIVE_LOW, IPT_BUTTON2 | IPF_PLAYER2 ) /* Left Button */
	PORT_BIT( 0x0400, IP_ACTIVE_LOW, IPT_BUTTON1 | IPF_PLAYER2 ) /* Right Trigger */
	PORT_BIT( 0x0800, IP_ACTIVE_LOW, IPT_BUTTON4 | IPF_PLAYER2 ) /* Right Button */
	PORT_BIT( 0x1000, IP_ACTIVE_LOW, IPT_BUTTON3 | IPF_PLAYER1 ) /* Left Trigger */
	PORT_BIT( 0x2000, IP_ACTIVE_LOW, IPT_BUTTON2 | IPF_PLAYER1 ) /* Left Button */
	PORT_BIT( 0x4000, IP_ACTIVE_LOW, IPT_BUTTON1 | IPF_PLAYER1 ) /* Right Trigger */
	PORT_BIT( 0x8000, IP_ACTIVE_LOW, IPT_BUTTON4 | IPF_PLAYER1 ) /* Right Button */

	PORT_START	/* IN3 -- dipswitches */
	PORT_DIPNAME( 0x0003, 0x0003, DEF_STR( Coinage ) )
	PORT_DIPSETTING(      0x0002, DEF_STR( 2C_1C ) )
	PORT_DIPSETTING(      0x0003, DEF_STR( 1C_1C ) )
	PORT_DIPSETTING(      0x0001, DEF_STR( 1C_2C ) )
	/*PORT_DIPSETTING(      0x0000, DEF_STR( 1C_2C ) )*/
	PORT_DIPNAME( 0x0004, 0x0004, DEF_STR( Free_Play ) )
	PORT_DIPSETTING(      0x0004, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( On ) )
	PORT_DIPNAME( 0x0018, 0x0008, "Point Threshholds" )
	PORT_DIPSETTING(      0x0008, "Easy" )
	PORT_DIPSETTING(      0x0018, "Medium" )
	PORT_DIPSETTING(      0x0010, "Hard" )
	PORT_DIPSETTING(      0x0000, "Hardest" )
	PORT_DIPNAME( 0x0060, 0x0060, "Free Timer After" )
	PORT_DIPSETTING(      0x0000, "30 sec" )
	PORT_DIPSETTING(      0x0040, "45 sec" )
	PORT_DIPSETTING(      0x0060, "60 sec" )
	PORT_DIPSETTING(      0x0020, "90 sec" )
	PORT_BITX( 0x0080,    0x0080, IPT_DIPSWITCH_NAME | IPF_CHEAT, "Rack Advance", KEYCODE_F1, IP_JOY_NONE )
	PORT_DIPSETTING(      0x0080, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( On ) )
	PORT_BIT( 0xff00, IP_ACTIVE_LOW, IPT_UNUSED )

	PORT_START	/* analog ports for steering and pedals */
	PORT_ANALOG( 0xff, 0x30, IPT_PEDAL | IPF_PLAYER2 | IPF_REVERSE, 100, 10, 0x30, 0xff )

	PORT_START
	PORT_ANALOG( 0xff, 0x30, IPT_PEDAL | IPF_PLAYER1 | IPF_REVERSE, 100, 10, 0x30, 0xff )

	PORT_START
	PORT_ANALOG( 0xff, 0x80, IPT_PADDLE | IPF_PLAYER2 | IPF_REVERSE, 80, 10, 0x10, 0xf0 )

	PORT_START
	PORT_ANALOG( 0xff, 0x80, IPT_PADDLE | IPF_PLAYER1 | IPF_REVERSE, 80, 10, 0x10, 0xf0 )
INPUT_PORTS_END


INPUT_PORTS_START( blasted )
	PORT_START
	PORT_BIT( 0x0001, IP_ACTIVE_LOW, IPT_COIN1 )
	PORT_BIT( 0x0002, IP_ACTIVE_LOW, IPT_COIN2 )
	PORT_BIT( 0x0004, IP_ACTIVE_LOW, IPT_UNUSED/* credit w/bill */ )
	PORT_BIT( 0x0008, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x0010, IP_ACTIVE_LOW, IPT_TILT )
	PORT_BIT( 0x0020, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x0040, IP_ACTIVE_LOW, IPT_COIN4 )
	PORT_SERVICE( 0x0080, IP_ACTIVE_LOW )
	PORT_BIT( 0x0100, IP_ACTIVE_LOW, IPT_BUTTON1 | IPF_PLAYER1 )
	PORT_BIT( 0x0100, IP_ACTIVE_LOW, IPT_START1 )
	PORT_BIT( 0x0200, IP_ACTIVE_LOW, IPT_BUTTON1 | IPF_PLAYER2 )
	PORT_BIT( 0x0200, IP_ACTIVE_LOW, IPT_START2 )
	PORT_BIT( 0x0400, IP_ACTIVE_LOW, IPT_UNUSED/* credit 1 w/bill */ )
	PORT_BIT( 0x0800, IP_ACTIVE_LOW, IPT_UNUSED/* credit 2 w/bill */ )
	PORT_BIT( 0xf000, IP_ACTIVE_LOW, IPT_UNUSED )

	PORT_START
	PORT_BIT( 0x0001, IP_ACTIVE_LOW, IPT_JOYSTICK_UP | IPF_8WAY | IPF_PLAYER1 )
	PORT_BIT( 0x0002, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT | IPF_8WAY | IPF_PLAYER1 )
	PORT_BIT( 0x0004, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN | IPF_8WAY | IPF_PLAYER1 )
	PORT_BIT( 0x0008, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT | IPF_8WAY | IPF_PLAYER1 )
	PORT_BIT( 0x0010, IP_ACTIVE_LOW, IPT_JOYSTICK_UP | IPF_8WAY | IPF_PLAYER2 )
	PORT_BIT( 0x0020, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT | IPF_8WAY | IPF_PLAYER2 )
	PORT_BIT( 0x0040, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN | IPF_8WAY | IPF_PLAYER2 )
	PORT_BIT( 0x0080, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT | IPF_8WAY | IPF_PLAYER2 )
	PORT_BIT( 0xff00, IP_ACTIVE_LOW, IPT_UNUSED )

	PORT_START
	PORT_DIPNAME( 0x0003, 0x0003, DEF_STR( Coinage ) )
	PORT_DIPSETTING(      0x0002, DEF_STR( 2C_1C ) )
	PORT_DIPSETTING(      0x0003, DEF_STR( 1C_1C ) )
	PORT_DIPSETTING(      0x0001, DEF_STR( 1C_2C ) )
	/*PORT_DIPSETTING(      0x0000, DEF_STR( 1C_2C ) )*/
	PORT_DIPNAME( 0x000c, 0x0000, DEF_STR( Difficulty ) )
	PORT_DIPSETTING(      0x0008, "Easy" )
	PORT_DIPSETTING(      0x0000, "Medium" )
	PORT_DIPSETTING(      0x0004, "Hard" )
/*	PORT_DIPSETTING(      0x000c, "Medium" )*/
	PORT_DIPNAME( 0x0020, 0x0020, "Dollar Receptor" )
	PORT_DIPSETTING(      0x0020, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( On ) )
	PORT_DIPNAME( 0x0040, 0x0040, DEF_STR( Demo_Sounds ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0040, DEF_STR( On ) )
	PORT_BITX( 0x0080,    0x0080, IPT_DIPSWITCH_NAME | IPF_CHEAT, "Rack Advance", KEYCODE_F1, IP_JOY_NONE )
	PORT_DIPSETTING(      0x0080, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( On ) )
	PORT_BIT( 0xff00, IP_ACTIVE_LOW, IPT_UNUSED )
INPUT_PORTS_END


INPUT_PORTS_START( archrivl )
	PORT_START
	PORT_BIT( 0x0001, IP_ACTIVE_LOW, IPT_COIN1 )
	PORT_BIT( 0x0002, IP_ACTIVE_LOW, IPT_COIN2 )
	PORT_BIT( 0x000c, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x0010, IP_ACTIVE_LOW, IPT_TILT )
	PORT_BIT( 0x0020, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x0040, IP_ACTIVE_LOW, IPT_COIN4 )
	PORT_SERVICE( 0x0080, IP_ACTIVE_LOW )
	PORT_BIT( 0x0100, IP_ACTIVE_LOW, IPT_START1 )
	PORT_BIT( 0x0200, IP_ACTIVE_LOW, IPT_START2 )
	PORT_BIT( 0x0c00, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x1000, IP_ACTIVE_LOW, IPT_BUTTON1 | IPF_PLAYER1 )
	PORT_BIT( 0x2000, IP_ACTIVE_LOW, IPT_BUTTON2 | IPF_PLAYER1 )
	PORT_BIT( 0x4000, IP_ACTIVE_LOW, IPT_BUTTON1 | IPF_PLAYER2 )
	PORT_BIT( 0x8000, IP_ACTIVE_LOW, IPT_BUTTON2 | IPF_PLAYER2 )

	PORT_START
	PORT_BIT( 0xffff, IP_ACTIVE_HIGH, IPT_UNUSED )	/* player 1/2 joysticks go here */

	PORT_START
	PORT_DIPNAME( 0x0003, 0x0003, "Game Time" )
	PORT_DIPSETTING(      0x0003, "Preset Time" )
	PORT_DIPSETTING(      0x0002, "Preset + 10sec" )
	PORT_DIPSETTING(      0x0001, "Preset + 20sec" )
	PORT_DIPSETTING(      0x0000, "Preset + 30sec" )
	PORT_DIPNAME( 0x001c, 0x001c, DEF_STR( Coinage ) )
	PORT_DIPSETTING(      0x0014, DEF_STR( 3C_1C ) )
	PORT_DIPSETTING(      0x0018, DEF_STR( 2C_1C ) )
	PORT_DIPSETTING(      0x001c, DEF_STR( 1C_1C ) )
	PORT_DIPSETTING(      0x0010, DEF_STR( 2C_3C ) )
	PORT_DIPSETTING(      0x000c, DEF_STR( 1C_2C ) )
	PORT_DIPSETTING(      0x0008, DEF_STR( 1C_3C ) )
	PORT_DIPSETTING(      0x0004, DEF_STR( 1C_5C ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( 1C_6C ) )
	PORT_DIPNAME( 0x0020, 0x0020, "Team Names" )
	PORT_DIPSETTING(      0x0020, "Default" )
	PORT_DIPSETTING(      0x0000, "Hometown Heroes" )
	PORT_DIPNAME( 0x0040, 0x0040, DEF_STR( Demo_Sounds ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0040, DEF_STR( On ) )
	PORT_DIPNAME( 0x0080, 0x0080, DEF_STR( Free_Play ) )
	PORT_DIPSETTING(      0x0080, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( On ) )
	PORT_BIT( 0xff00, IP_ACTIVE_LOW, IPT_UNUSED )

	PORT_START	/* 49-way joystick simulator */
	PORT_BIT( 0x0001, IP_ACTIVE_HIGH, IPT_JOYSTICK_UP | IPF_8WAY | IPF_PLAYER1 )
	PORT_BIT( 0x0002, IP_ACTIVE_HIGH, IPT_JOYSTICK_DOWN | IPF_8WAY | IPF_PLAYER1 )
	PORT_BIT( 0x0004, IP_ACTIVE_HIGH, IPT_JOYSTICK_LEFT | IPF_8WAY | IPF_PLAYER1 )
	PORT_BIT( 0x0008, IP_ACTIVE_HIGH, IPT_JOYSTICK_RIGHT | IPF_8WAY | IPF_PLAYER1 )
	PORT_BIT( 0x0010, IP_ACTIVE_HIGH, IPT_JOYSTICK_UP | IPF_8WAY | IPF_PLAYER2 )
	PORT_BIT( 0x0020, IP_ACTIVE_HIGH, IPT_JOYSTICK_DOWN | IPF_8WAY | IPF_PLAYER2 )
	PORT_BIT( 0x0040, IP_ACTIVE_HIGH, IPT_JOYSTICK_LEFT | IPF_8WAY | IPF_PLAYER2 )
	PORT_BIT( 0x0080, IP_ACTIVE_HIGH, IPT_JOYSTICK_RIGHT | IPF_8WAY | IPF_PLAYER2 )
INPUT_PORTS_END


INPUT_PORTS_START( pigskin )
	PORT_START
	PORT_BIT( 0x0001, IP_ACTIVE_LOW, IPT_COIN1 )
	PORT_BIT( 0x0002, IP_ACTIVE_LOW, IPT_COIN2 )
	PORT_BIT( 0x0004, IP_ACTIVE_LOW, IPT_START1 )
	PORT_BIT( 0x0008, IP_ACTIVE_LOW, IPT_START2 )
	PORT_BIT( 0x0010, IP_ACTIVE_LOW, IPT_TILT )
	PORT_SERVICE( 0x0020, IP_ACTIVE_LOW )
	PORT_BIT( 0x0040, IP_ACTIVE_LOW, IPT_COIN4 )
	PORT_BIT( 0x0080, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x0100, IP_ACTIVE_LOW, IPT_JOYSTICK_UP | IPF_8WAY | IPF_PLAYER1 )
	PORT_BIT( 0x0200, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN | IPF_8WAY | IPF_PLAYER1 )
	PORT_BIT( 0x0400, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT | IPF_8WAY | IPF_PLAYER1 )
	PORT_BIT( 0x0800, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT | IPF_8WAY | IPF_PLAYER1 )
	PORT_BIT( 0x1000, IP_ACTIVE_LOW, IPT_BUTTON1 | IPF_PLAYER1 )
	PORT_BIT( 0x2000, IP_ACTIVE_LOW, IPT_BUTTON2 | IPF_PLAYER1 )
	PORT_BIT( 0x4000, IP_ACTIVE_LOW, IPT_BUTTON3 | IPF_PLAYER1 )
	PORT_BIT( 0x8000, IP_ACTIVE_LOW, IPT_UNUSED )

	PORT_START
	PORT_BIT( 0x000f, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x0010, IP_ACTIVE_LOW, IPT_BUTTON1 | IPF_PLAYER2 )
	PORT_BIT( 0x0020, IP_ACTIVE_LOW, IPT_BUTTON2 | IPF_PLAYER2 )
	PORT_BIT( 0x0040, IP_ACTIVE_LOW, IPT_BUTTON3 | IPF_PLAYER2 )
	PORT_BIT( 0x0080, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0xff00, IP_ACTIVE_HIGH, IPT_UNUSED )	/* player 1 joystick goes here */

	PORT_START
	PORT_DIPNAME( 0x0003, 0x0003, "Game Time" )
	PORT_DIPSETTING(      0x0000, "Shortest" )
	PORT_DIPSETTING(      0x0002, "Short" )
	PORT_DIPSETTING(      0x0003, "Medium" )
	PORT_DIPSETTING(      0x0001, "Long" )
	PORT_DIPNAME( 0x000c, 0x000c, DEF_STR( Coinage ) )
	PORT_DIPSETTING(      0x0008, DEF_STR( 2C_1C ) )
	PORT_DIPSETTING(      0x000c, DEF_STR( 1C_1C ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( Free_Play ) )
	PORT_DIPSETTING(      0x0004, "Set Your Own" )
	PORT_DIPNAME( 0x0010, 0x0010, DEF_STR( Demo_Sounds ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0010, DEF_STR( On ) )
	PORT_DIPNAME( 0x0020, 0x0020, "Test Switch" )
	PORT_DIPSETTING(      0x0020, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( On ) )
	PORT_DIPNAME( 0x0040, 0x0040, "Coin Chutes" )
	PORT_DIPSETTING(      0x0000, "Individual" )
	PORT_DIPSETTING(      0x0040, "Common" )
	PORT_DIPNAME( 0x0080, 0x0080, "Joystick" )
	PORT_DIPSETTING(      0x0080, "Standard" )
	PORT_DIPSETTING(      0x0000, "Rotated" )
	PORT_BIT( 0xff00, IP_ACTIVE_HIGH, IPT_UNUSED )	/* player 2 joystick goes here */

	PORT_START	/* 49-way joystick simulator */
	PORT_BIT( 0x0001, IP_ACTIVE_HIGH, IPT_JOYSTICK_RIGHT | IPF_8WAY | IPF_PLAYER1 )
	PORT_BIT( 0x0002, IP_ACTIVE_HIGH, IPT_JOYSTICK_LEFT | IPF_8WAY | IPF_PLAYER1 )
	PORT_BIT( 0x0004, IP_ACTIVE_HIGH, IPT_JOYSTICK_UP | IPF_8WAY | IPF_PLAYER1 )
	PORT_BIT( 0x0008, IP_ACTIVE_HIGH, IPT_JOYSTICK_DOWN | IPF_8WAY | IPF_PLAYER1 )
	PORT_BIT( 0x0010, IP_ACTIVE_HIGH, IPT_JOYSTICK_RIGHT | IPF_8WAY | IPF_PLAYER2 )
	PORT_BIT( 0x0020, IP_ACTIVE_HIGH, IPT_JOYSTICK_LEFT | IPF_8WAY | IPF_PLAYER2 )
	PORT_BIT( 0x0040, IP_ACTIVE_HIGH, IPT_JOYSTICK_UP | IPF_8WAY | IPF_PLAYER2 )
	PORT_BIT( 0x0080, IP_ACTIVE_HIGH, IPT_JOYSTICK_DOWN | IPF_8WAY | IPF_PLAYER2 )
INPUT_PORTS_END


INPUT_PORTS_START( trisport )
	PORT_START
	PORT_BIT( 0x0001, IP_ACTIVE_LOW, IPT_COIN1 )
	PORT_BIT( 0x0002, IP_ACTIVE_LOW, IPT_COIN2 )
	PORT_BIT( 0x000c, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x0010, IP_ACTIVE_LOW, IPT_TILT )
	PORT_SERVICE( 0x0020, IP_ACTIVE_LOW )
	PORT_BIT( 0x0040, IP_ACTIVE_LOW, IPT_COIN4 )
	PORT_BIT( 0x0080, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x0f00, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x1000, IP_ACTIVE_LOW, IPT_BUTTON1 | IPF_PLAYER1 )
	PORT_BIT( 0x1000, IP_ACTIVE_LOW, IPT_START1 )
	PORT_BIT( 0x2000, IP_ACTIVE_LOW, IPT_BUTTON2 | IPF_PLAYER1 )
	PORT_BIT( 0xc000, IP_ACTIVE_LOW, IPT_UNUSED )

	PORT_START
	PORT_BIT( 0x00ff, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0xff00, IP_ACTIVE_HIGH, IPT_UNUSED )	/* analog controls go here */

	PORT_START
	PORT_DIPNAME( 0x0007, 0x0007, DEF_STR( Coinage ) )
	PORT_DIPSETTING(      0x0002, DEF_STR( 4C_1C ) )
	PORT_DIPSETTING(      0x0003, DEF_STR( 3C_1C ) )
	PORT_DIPSETTING(      0x0006, DEF_STR( 2C_1C ) )
	PORT_DIPSETTING(      0x0007, DEF_STR( 1C_1C ) )
	PORT_DIPSETTING(      0x0005, DEF_STR( 1C_2C ) )
	PORT_DIPSETTING(      0x0004, DEF_STR( 1C_3C ) )
	PORT_DIPSETTING(      0x0001, DEF_STR( Free_Play ) )
	PORT_DIPSETTING(      0x0000, "Battery Options" )
	PORT_DIPNAME( 0x0018, 0x0018, "Pool Turns" )
	PORT_DIPSETTING(      0x0010, "5" )
	PORT_DIPSETTING(      0x0008, "6" )
	PORT_DIPSETTING(      0x0018, "7" )
	PORT_DIPSETTING(      0x0000, "8" )
	PORT_DIPNAME( 0x0020, 0x0020, "Bowling Difficulty" )
	PORT_DIPSETTING(      0x0020, "Standard" )
	PORT_DIPSETTING(      0x0000, "Advanced" )
	PORT_DIPNAME( 0x0040, 0x0040, "Shot Timer" )
	PORT_DIPSETTING(      0x0000, "Slower" )
	PORT_DIPSETTING(      0x0040, "Standard" )
	PORT_DIPNAME( 0x0080, 0x0080, "Golf Holes" )
	PORT_DIPSETTING(      0x0080, "3" )
	PORT_DIPSETTING(      0x0000, "4" )
	PORT_BIT( 0xff00, IP_ACTIVE_LOW, IPT_UNUSED )

	PORT_START
    PORT_ANALOG( 0xff, 0, IPT_TRACKBALL_X | IPF_PLAYER1, 100, 20, 0, 0 )

	PORT_START
    PORT_ANALOG( 0xff, 0, IPT_TRACKBALL_Y | IPF_REVERSE | IPF_PLAYER1, 100, 20, 0, 0 )
INPUT_PORTS_END



/*************************************
 *
 *	Game drivers
 *
 *************************************/

GAME( 1984, zwackery, 0,        zwackery, zwackery, zwackery, ROT0,   "Bally Midway", "Zwackery" )
GAME( 1987, xenophob, 0,        xenophob, xenophob, xenophob, ROT0,   "Bally Midway", "Xenophobe" )
GAME( 1987, spyhunt2, 0,        spyhunt2, spyhunt2, spyhunt2, ROT0,   "Bally Midway", "Spy Hunter 2 (rev 2)" )
GAME( 1987, spyhnt2a, spyhunt2, spyhunt2, spyhunt2, spyhunt2, ROT0,   "Bally Midway", "Spy Hunter 2 (rev 1)" )
GAME( 1988, blasted,  0,        xenophob, blasted,  blasted,  ROT0,   "Bally Midway", "Blasted" )
GAME( 1989, archrivl, 0,        archrivl, archrivl, archrivl, ROT0,   "Bally Midway", "Arch Rivals (rev 4.0)" )
GAME( 1989, archriv2, archrivl, archrivl, archrivl, archrivl, ROT0,   "Bally Midway", "Arch Rivals (rev 2.0)" )
GAME( 1989, trisport, 0,        trisport, trisport, trisport, ROT270, "Bally Midway", "Tri-Sports" )
GAME( 1990, pigskin,  0,        pigskin,  pigskin,  pigskin,  ROT0,   "Midway", "Pigskin 621AD" )
