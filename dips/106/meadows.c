# MAME 0.106 source snippet


#include "driver.h"
#include "artwork.h"
#include "cpu/s2650/s2650.h"
#include "meadows.h"
#include "sound/dac.h"
#include "sound/samples.h"


INPUT_PORTS_START( meadows )
	PORT_START		/* IN0 buttons */
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_BUTTON1 )
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_START1  )
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_UNKNOWN )

	PORT_START		/* IN1 control 1 */
	PORT_BIT( 0xff, 0x80, IPT_AD_STICK_X ) PORT_MINMAX(0x10,0xf0) PORT_SENSITIVITY(100) PORT_KEYDELTA(10)

	PORT_START		/* IN2 dip switch */
	PORT_DIPNAME( 0x07, 0x01, DEF_STR( Lives ) )
	PORT_DIPSETTING(    0x00, "2" )
	PORT_DIPSETTING(    0x01, "3" )
	PORT_DIPSETTING(    0x02, "4" )
	PORT_DIPSETTING(    0x03, "5" )
	PORT_DIPSETTING(    0x04, "6" )
	PORT_DIPSETTING(    0x05, "7" )
	PORT_DIPSETTING(    0x06, "8" )
	PORT_DIPSETTING(    0x07, "9" )
	PORT_DIPNAME( 0x18, 0x00, DEF_STR( Coinage ) )
	PORT_DIPSETTING(    0x10, DEF_STR( 2C_1C ) )
	PORT_DIPSETTING(    0x00, DEF_STR( 1C_1C ) )
	PORT_DIPSETTING(    0x08, DEF_STR( 1C_2C ) )
	PORT_DIPSETTING(    0x18, DEF_STR( Free_Play ) )
	PORT_DIPNAME( 0x20, 0x20, DEF_STR( Demo_Sounds ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x20, DEF_STR( On ) )
	PORT_DIPNAME( 0xc0, 0x40, DEF_STR( Bonus_Life ) )
	PORT_DIPSETTING(    0x40, "5000")
	PORT_DIPSETTING(    0x80, "15000")
	PORT_DIPSETTING(    0xc0, "35000")
	PORT_DIPSETTING(    0x00, DEF_STR( None ))

	PORT_START		/* FAKE coinage */
	PORT_BIT( 0x01, IP_ACTIVE_HIGH, IPT_COIN1 )
	PORT_BIT( 0x8e, IP_ACTIVE_LOW, IPT_UNUSED )
INPUT_PORTS_END


INPUT_PORTS_START( minferno )
	PORT_START		/* IN0 left joystick */
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_JOYSTICK_UP ) PORT_PLAYER(1)
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN ) PORT_PLAYER(1)
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT ) PORT_PLAYER(1)
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT ) PORT_PLAYER(1)

	PORT_START		/* IN1 right joystick */
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_JOYSTICK_UP ) PORT_PLAYER(2)
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN ) PORT_PLAYER(2)
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT ) PORT_PLAYER(2)
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT ) PORT_PLAYER(2)

	PORT_START		/* IN2 buttons */
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_PLAYER(1)
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_PLAYER(2)
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_UNUSED )

	PORT_START		/* IN3 coinage */
	PORT_DIPNAME( 0x01, 0x01, "Coin Option" )
	PORT_DIPSETTING(    0x00, "1 Game/Coin" )
	PORT_DIPSETTING(    0x01, "1 Player/Coin" )
	PORT_DIPNAME( 0x02, 0x00, DEF_STR( Demo_Sounds ) )
	PORT_DIPSETTING(    0x02, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_START1 )
	PORT_BIT( 0x08, IP_ACTIVE_HIGH, IPT_COIN1 )

	PORT_START		/* IN4 dip switch */
	PORT_DIPNAME( 0x03, 0x00, DEF_STR( Game_Time ) )
	PORT_DIPSETTING(    0x00, "60s" )
	PORT_DIPSETTING(    0x01, "90s" )
	PORT_DIPSETTING(    0x02, "120s" )
	PORT_DIPSETTING(    0x03, "180s" )
	PORT_DIPNAME( 0x0c, 0x04, "Extended Play Score" )
	PORT_DIPSETTING(    0x00, "3000/6000" )
	PORT_DIPSETTING(    0x04, "4000/7000" )
	PORT_DIPSETTING(    0x08, "5000/8000" )
	PORT_DIPSETTING(    0x0c, "6000/9000" )
	PORT_DIPNAME( 0x30, 0x10, "Extended Play Time" )
	PORT_DIPSETTING(    0x00, DEF_STR( None ) )
	PORT_DIPSETTING(    0x10, "20s" )
	PORT_DIPSETTING(    0x20, "40s" )
	PORT_DIPSETTING(    0x30, "60s" )
	PORT_DIPNAME( 0x40, 0x00, DEF_STR( Unknown ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x40, DEF_STR( On ) )
	PORT_DIPNAME( 0x80, 0x00, DEF_STR( Unknown ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x80, DEF_STR( On ) )
INPUT_PORTS_END




GAME( 1978, deadeye,  0, meadows,  meadows,  deadeye,  ROT0, "Meadows", "Dead Eye", 0 )
GAME( 1978, gypsyjug, 0, meadows,  meadows,  gypsyjug, ROT0, "Meadows", "Gypsy Juggler", 0 )
GAME( 1978, minferno, 0, minferno, minferno, minferno, ROT0, "Meadows", "Inferno (S2650)", GAME_NO_SOUND )
