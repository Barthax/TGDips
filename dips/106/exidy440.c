#include "driver.h"
#include "exidy440.h"

/*************************************
 *
 *  Port definitions
 *
 *************************************/

#define COINAGE \
	PORT_DIPNAME( 0x0f, 0x0f, DEF_STR( Coinage ) ) \
	PORT_DIPSETTING(    0x03, DEF_STR( 4C_1C ) ) \
	PORT_DIPSETTING(    0x07, DEF_STR( 3C_1C ) ) \
	PORT_DIPSETTING(    0x02, DEF_STR( 4C_2C ) ) \
	PORT_DIPSETTING(    0x0b, DEF_STR( 2C_1C ) ) \
	PORT_DIPSETTING(    0x06, DEF_STR( 3C_2C ) ) \
	PORT_DIPSETTING(    0x01, DEF_STR( 4C_3C ) ) \
	PORT_DIPSETTING(    0x00, DEF_STR( 4C_4C ) ) \
	PORT_DIPSETTING(    0x05, DEF_STR( 3C_3C ) ) \
	PORT_DIPSETTING(    0x0a, DEF_STR( 2C_2C ) ) \
	PORT_DIPSETTING(    0x0f, DEF_STR( 1C_1C ) ) \
	PORT_DIPSETTING(    0x04, DEF_STR( 3C_4C ) ) \
	PORT_DIPSETTING(    0x09, DEF_STR( 2C_3C ) ) \
	PORT_DIPSETTING(    0x08, DEF_STR( 2C_4C ) ) \
	PORT_DIPSETTING(    0x0e, DEF_STR( 1C_2C ) ) \
	PORT_DIPSETTING(    0x0d, DEF_STR( 1C_3C ) ) \
	PORT_DIPSETTING(    0x0c, DEF_STR( 1C_4C ) )


INPUT_PORTS_START( crossbow )
	PORT_START				/* player inputs and logic board dips */
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_BUTTON1 )
	PORT_DIPNAME( 0x0c, 0x0c, DEF_STR( Lives ) )
	PORT_DIPSETTING(    0x08, "2" )
	PORT_DIPSETTING(    0x0c, "3" )
	PORT_DIPSETTING(    0x04, "4" )
	PORT_DIPSETTING(    0x00, "5" )
	PORT_DIPNAME( 0x30, 0x30, DEF_STR( Difficulty ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Easy ) )
	PORT_DIPSETTING(    0x30, DEF_STR( Normal ) )
	PORT_DIPSETTING(    0x20, DEF_STR( Hard ) )
	PORT_DIPSETTING(    0x10, DEF_STR( Hardest ) )
	PORT_BIT( 0xc0, IP_ACTIVE_LOW, IPT_UNKNOWN )

	PORT_START 				/* audio board dips */
	COINAGE
	PORT_BIT( 0x70, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_DIPNAME( 0x80, 0x80, DEF_STR( Free_Play ) )
	PORT_DIPSETTING(    0x80, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )

	PORT_START				/* start button */
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_START1 )
	PORT_BIT( 0xfe, IP_ACTIVE_LOW, IPT_UNKNOWN )

	PORT_START				/* coin counters */
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_COIN1 )
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_COIN2 )
	PORT_BIT( 0xfc, IP_ACTIVE_LOW, IPT_UNKNOWN )

	PORT_START				/* fake analog X */
	PORT_BIT( 0xff, 0x80, IPT_LIGHTGUN_X ) PORT_MINMAX(0,255) PORT_SENSITIVITY(50) PORT_KEYDELTA(10)

	PORT_START				/* fake analog Y */
	PORT_BIT( 0xff, 0x80, IPT_LIGHTGUN_Y ) PORT_MINMAX(0,255) PORT_SENSITIVITY(70) PORT_KEYDELTA(10)
INPUT_PORTS_END


INPUT_PORTS_START( cheyenne )
	PORT_START				/* player inputs and logic board dips */
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_BUTTON1 )
	PORT_DIPNAME( 0x0c, 0x0c, DEF_STR( Lives ) )
	PORT_DIPSETTING(    0x08, "2" )
	PORT_DIPSETTING(    0x0c, "3" )
	PORT_DIPSETTING(    0x04, "4" )
	PORT_DIPSETTING(    0x00, "5" )
	PORT_DIPNAME( 0x30, 0x30, DEF_STR( Difficulty ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Easy ) )
	PORT_DIPSETTING(    0x30, DEF_STR( Normal ) )
	PORT_DIPSETTING(    0x20, DEF_STR( Hard ) )
	PORT_DIPSETTING(    0x10, DEF_STR( Hardest ) )
	PORT_BIT( 0xc0, IP_ACTIVE_LOW, IPT_UNKNOWN )

	PORT_START 				/* audio board dips */
	COINAGE
	PORT_BIT( 0x70, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_DIPNAME( 0x80, 0x80, DEF_STR( Free_Play ) )
	PORT_DIPSETTING(    0x80, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )

	PORT_START				/* start button */
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_START1 )
	PORT_BIT( 0xfe, IP_ACTIVE_LOW, IPT_UNKNOWN )

	PORT_START				/* coin counters */
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_COIN1 )
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_COIN2 )
	PORT_BIT( 0xfc, IP_ACTIVE_LOW, IPT_UNKNOWN )

	PORT_START				/* fake analog X */
	PORT_BIT( 0xff, 0x80, IPT_LIGHTGUN_X ) PORT_MINMAX(0,255) PORT_SENSITIVITY(50) PORT_KEYDELTA(10)

	PORT_START				/* fake analog Y */
	PORT_BIT( 0xff, 0x80, IPT_LIGHTGUN_Y ) PORT_MINMAX(0,255) PORT_SENSITIVITY(70) PORT_KEYDELTA(10)
INPUT_PORTS_END


INPUT_PORTS_START( combat )
	PORT_START				/* player inputs and logic board dips */
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_BUTTON1 )
	PORT_DIPNAME( 0x0c, 0x0c, DEF_STR( Lives ) )
	PORT_DIPSETTING(    0x08, "2" )
	PORT_DIPSETTING(    0x0c, "3" )
	PORT_DIPSETTING(    0x04, "4" )
	PORT_DIPSETTING(    0x00, "5" )
	PORT_DIPNAME( 0x30, 0x30, DEF_STR( Difficulty ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Easy ) )
	PORT_DIPSETTING(    0x30, DEF_STR( Normal ) )
	PORT_DIPSETTING(    0x20, DEF_STR( Hard ) )
	PORT_DIPSETTING(    0x10, DEF_STR( Hardest ) )
	PORT_BIT( 0xc0, IP_ACTIVE_LOW, IPT_UNKNOWN )

	PORT_START 				/* audio board dips */
	COINAGE
	PORT_BIT( 0x70, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_DIPNAME( 0x80, 0x80, DEF_STR( Free_Play ) )
	PORT_DIPSETTING(    0x80, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )

	PORT_START				/* start button */
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_START1 )
	PORT_BIT( 0xfe, IP_ACTIVE_LOW, IPT_UNKNOWN )

	PORT_START				/* coin counters */
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_COIN1 )
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_COIN2 )
	PORT_BIT( 0xfc, IP_ACTIVE_LOW, IPT_UNKNOWN )

	PORT_START				/* fake analog X */
	PORT_BIT( 0xff, 0x80, IPT_LIGHTGUN_X ) PORT_MINMAX(0,255) PORT_SENSITIVITY(50) PORT_KEYDELTA(10)

	PORT_START				/* fake analog Y */
	PORT_BIT( 0xff, 0x80, IPT_LIGHTGUN_Y ) PORT_MINMAX(0,255) PORT_SENSITIVITY(70) PORT_KEYDELTA(10)
INPUT_PORTS_END


INPUT_PORTS_START( catch22 )
	PORT_START				/* player inputs and logic board dips */
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_BUTTON1 )
	PORT_DIPNAME( 0x0c, 0x0c, DEF_STR( Lives ) )
	PORT_DIPSETTING(    0x08, "4" )
	PORT_DIPSETTING(    0x0c, "5" )
	PORT_DIPSETTING(    0x04, "6" )
	PORT_DIPSETTING(    0x00, "7" )
	PORT_DIPNAME( 0x30, 0x30, DEF_STR( Difficulty ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Easy ) )
	PORT_DIPSETTING(    0x30, DEF_STR( Normal ) )
	PORT_DIPSETTING(    0x20, DEF_STR( Hard ) )
	PORT_DIPSETTING(    0x10, DEF_STR( Hardest ) )
	PORT_BIT( 0xc0, IP_ACTIVE_LOW, IPT_UNKNOWN )

	PORT_START 				/* audio board dips */
	COINAGE
	PORT_BIT( 0x70, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_DIPNAME( 0x80, 0x80, DEF_STR( Free_Play ) )
	PORT_DIPSETTING(    0x80, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )

	PORT_START				/* start button */
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_START1 )
	PORT_BIT( 0xfe, IP_ACTIVE_LOW, IPT_UNKNOWN )

	PORT_START				/* coin counters */
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_COIN1 )
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_COIN2 )
	PORT_BIT( 0xfc, IP_ACTIVE_LOW, IPT_UNKNOWN )

	PORT_START				/* fake analog X */
	PORT_BIT( 0xff, 0x80, IPT_LIGHTGUN_X ) PORT_MINMAX(0,255) PORT_SENSITIVITY(50) PORT_KEYDELTA(10)

	PORT_START				/* fake analog Y */
	PORT_BIT( 0xff, 0x80, IPT_LIGHTGUN_Y ) PORT_MINMAX(0,255) PORT_SENSITIVITY(70) PORT_KEYDELTA(10)
INPUT_PORTS_END


INPUT_PORTS_START( cracksht )
	PORT_START				/* player inputs and logic board dips */
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_BUTTON1 )
	PORT_DIPNAME( 0x0c, 0x0c, "Seconds" )
	PORT_DIPSETTING(    0x08, "20" )
	PORT_DIPSETTING(    0x0c, "30" )
	PORT_DIPSETTING(    0x04, "40" )
	PORT_DIPSETTING(    0x00, "50" )
	PORT_DIPNAME( 0x30, 0x30, DEF_STR( Difficulty ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Easy ) )
	PORT_DIPSETTING(    0x30, DEF_STR( Normal ) )
	PORT_DIPSETTING(    0x20, DEF_STR( Hard ) )
	PORT_DIPSETTING(    0x10, DEF_STR( Hardest ) )
	PORT_BIT( 0xc0, IP_ACTIVE_LOW, IPT_UNKNOWN )

	PORT_START 				/* audio board dips */
	COINAGE
	PORT_BIT( 0x70, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_DIPNAME( 0x80, 0x80, DEF_STR( Unknown ) )
	PORT_DIPSETTING(    0x80, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )

	PORT_START				/* start button */
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_START1 )
	PORT_BIT( 0xfe, IP_ACTIVE_LOW, IPT_UNKNOWN )

	PORT_START				/* coin counters */
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_COIN1 )
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_COIN2 )
	PORT_BIT( 0xfc, IP_ACTIVE_LOW, IPT_UNKNOWN )

	PORT_START				/* fake analog X */
	PORT_BIT( 0xff, 0x80, IPT_LIGHTGUN_X ) PORT_MINMAX(0,255) PORT_SENSITIVITY(50) PORT_KEYDELTA(10)

	PORT_START				/* fake analog Y */
	PORT_BIT( 0xff, 0x80, IPT_LIGHTGUN_Y ) PORT_MINMAX(0,255) PORT_SENSITIVITY(70) PORT_KEYDELTA(10)
INPUT_PORTS_END


INPUT_PORTS_START( claypign )
	PORT_START				/* player inputs and logic board dips */
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_BUTTON1 )
	PORT_BIT( 0x0c, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_DIPNAME( 0x30, 0x30, DEF_STR( Difficulty ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Easy ) )
	PORT_DIPSETTING(    0x30, DEF_STR( Normal ) )
	PORT_DIPSETTING(    0x20, DEF_STR( Hard ) )
	PORT_DIPSETTING(    0x10, DEF_STR( Hardest ) )
	PORT_BIT( 0xc0, IP_ACTIVE_LOW, IPT_UNKNOWN )

	PORT_START 				/* audio board dips */
	COINAGE
	PORT_BIT( 0x70, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_DIPNAME( 0x80, 0x80, DEF_STR( Unknown ) )
	PORT_DIPSETTING(    0x80, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )

	PORT_START				/* start button */
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_START1 )
	PORT_BIT( 0xfe, IP_ACTIVE_LOW, IPT_UNKNOWN )

	PORT_START				/* coin counters */
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_COIN1 )
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_COIN2 )
	PORT_BIT( 0xfc, IP_ACTIVE_LOW, IPT_UNKNOWN )

	PORT_START				/* fake analog X */
	PORT_BIT( 0xff, 0x80, IPT_LIGHTGUN_X ) PORT_MINMAX(0,255) PORT_SENSITIVITY(50) PORT_KEYDELTA(10)

	PORT_START				/* fake analog Y */
	PORT_BIT( 0xff, 0x80, IPT_LIGHTGUN_Y ) PORT_MINMAX(0,255) PORT_SENSITIVITY(70) PORT_KEYDELTA(10)
INPUT_PORTS_END


INPUT_PORTS_START( chiller )
	PORT_START				/* player inputs and logic board dips */
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_BUTTON1 )
	PORT_DIPNAME( 0x0c, 0x0c, "Seconds" )
	PORT_DIPSETTING(    0x08, "30" )
	PORT_DIPSETTING(    0x0c, "45" )
	PORT_DIPSETTING(    0x04, "60" )
	PORT_DIPSETTING(    0x00, "70" )
	PORT_DIPNAME( 0x30, 0x30, DEF_STR( Difficulty ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Easy ) )
	PORT_DIPSETTING(    0x30, DEF_STR( Normal ) )
	PORT_DIPSETTING(    0x20, DEF_STR( Hard ) )
	PORT_DIPSETTING(    0x10, DEF_STR( Hardest ) )
	PORT_BIT( 0xc0, IP_ACTIVE_LOW, IPT_UNKNOWN )

	PORT_START 				/* audio board dips */
	COINAGE
	PORT_BIT( 0xf0, IP_ACTIVE_LOW, IPT_UNKNOWN )

	PORT_START				/* start button */
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_START1 )
	PORT_BIT( 0xfe, IP_ACTIVE_LOW, IPT_UNKNOWN )

	PORT_START				/* coin counters */
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_COIN1 )
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_COIN2 )
	PORT_BIT( 0xfc, IP_ACTIVE_LOW, IPT_UNKNOWN )

	PORT_START				/* fake analog X */
	PORT_BIT( 0xff, 0x80, IPT_LIGHTGUN_X ) PORT_MINMAX(0,255) PORT_SENSITIVITY(50) PORT_KEYDELTA(10)

	PORT_START				/* fake analog Y */
	PORT_BIT( 0xff, 0x80, IPT_LIGHTGUN_Y ) PORT_MINMAX(0,255) PORT_SENSITIVITY(70) PORT_KEYDELTA(10)
INPUT_PORTS_END


INPUT_PORTS_START( topsecex )
	PORT_START				/* player inputs and logic board dips */
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_DIPNAME( 0x0c, 0x0c, DEF_STR( Lives ) )
	PORT_DIPSETTING(    0x08, "3" )
	PORT_DIPSETTING(    0x0c, "4" )
	PORT_DIPSETTING(    0x04, "5" )
	PORT_DIPSETTING(    0x00, "6" )
	PORT_DIPNAME( 0x30, 0x30, DEF_STR( Difficulty ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Easy ) )
	PORT_DIPSETTING(    0x30, DEF_STR( Normal ) )
	PORT_DIPSETTING(    0x20, DEF_STR( Hard ) )
	PORT_DIPSETTING(    0x10, DEF_STR( Hardest ) )
	PORT_BIT( 0xc0, IP_ACTIVE_LOW, IPT_UNKNOWN )

	PORT_START 				/* audio board dips */
	COINAGE
	PORT_BIT( 0xf0, IP_ACTIVE_LOW, IPT_UNKNOWN )

	PORT_START				/* start button */
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_BUTTON2 )
	PORT_BIT( 0xfe, IP_ACTIVE_LOW, IPT_UNKNOWN )

	PORT_START				/* coin counters */
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_COIN1 )
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_COIN2 )
	PORT_BIT( 0xfc, IP_ACTIVE_LOW, IPT_UNKNOWN )

	PORT_START				/* fake analog X */
	PORT_BIT( 0xff, 0x00, IPT_TRACKBALL_X ) PORT_MINMAX(-127,127) PORT_SENSITIVITY(50) PORT_KEYDELTA(10) PORT_REVERSE

	PORT_START				/* fake analog Y */
	PORT_BIT(  0xff, IP_ACTIVE_LOW, IPT_BUTTON1 )

	PORT_START				/* start button */
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_BUTTON3 ) PORT_NAME("Fireball")
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_BUTTON4 ) PORT_NAME("Laser")
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_BUTTON5 ) PORT_NAME("Missile")
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_BUTTON6 ) PORT_NAME("Oil")
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_BUTTON7 ) PORT_NAME("Turbo")
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_BUTTON8 ) PORT_NAME("Shield")
	PORT_BIT(  0x40, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_START1 ) PORT_NAME("Top Secret")
INPUT_PORTS_END


INPUT_PORTS_START( hitnmiss )
	PORT_START				/* player inputs and logic board dips */
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_BUTTON1 )
	PORT_DIPNAME( 0x0c, 0x0c, "Seconds" )
	PORT_DIPSETTING(    0x08, "20" )
	PORT_DIPSETTING(    0x0c, "30" )
	PORT_DIPSETTING(    0x04, "40" )
	PORT_DIPSETTING(    0x00, "50" )
	PORT_DIPNAME( 0x30, 0x30, DEF_STR( Difficulty ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Easy ) )
	PORT_DIPSETTING(    0x30, DEF_STR( Normal ) )
	PORT_DIPSETTING(    0x20, DEF_STR( Hard ) )
	PORT_DIPSETTING(    0x10, DEF_STR( Hardest ) )
	PORT_BIT( 0xc0, IP_ACTIVE_LOW, IPT_UNKNOWN )

	PORT_START 				/* audio board dips */
	COINAGE
	PORT_BIT( 0x70, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_DIPNAME( 0x80, 0x80, DEF_STR( Free_Play ) )
	PORT_DIPSETTING(    0x80, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )

	PORT_START				/* start button */
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_START1 )
	PORT_BIT( 0xfe, IP_ACTIVE_LOW, IPT_UNKNOWN )

	PORT_START				/* coin counters */
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_COIN1 )
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_COIN2 )
	PORT_BIT( 0xfc, IP_ACTIVE_LOW, IPT_UNKNOWN )

	PORT_START				/* fake analog X */
	PORT_BIT( 0xff, 0x80, IPT_LIGHTGUN_X ) PORT_MINMAX(0,255) PORT_SENSITIVITY(50) PORT_KEYDELTA(10)

	PORT_START				/* fake analog Y */
	PORT_BIT( 0xff, 0x80, IPT_LIGHTGUN_Y ) PORT_MINMAX(0,255) PORT_SENSITIVITY(70) PORT_KEYDELTA(10)
INPUT_PORTS_END


INPUT_PORTS_START( whodunit )
	PORT_START				/* player inputs and logic board dips */
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_BUTTON1 )
	PORT_DIPNAME( 0x0c, 0x0c, DEF_STR( Lives ) )
	PORT_DIPSETTING(    0x08, "2" )
	PORT_DIPSETTING(    0x0c, "3" )
	PORT_DIPSETTING(    0x04, "4" )
	PORT_DIPSETTING(    0x00, "5" )
	PORT_DIPNAME( 0x30, 0x30, DEF_STR( Difficulty ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Easy ) )
	PORT_DIPSETTING(    0x30, DEF_STR( Normal ) )
	PORT_DIPSETTING(    0x20, DEF_STR( Hard ) )
	PORT_DIPSETTING(    0x10, DEF_STR( Hardest ) )
	PORT_BIT( 0xc0, IP_ACTIVE_LOW, IPT_UNKNOWN )

	PORT_START 				/* audio board dips */
	COINAGE
	PORT_BIT( 0xf0, IP_ACTIVE_LOW, IPT_UNKNOWN )

	PORT_START				/* start button */
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_START1 )
	PORT_BIT( 0xfe, IP_ACTIVE_LOW, IPT_UNKNOWN )

	PORT_START				/* coin counters */
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_COIN1 )
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_COIN2 )
	PORT_BIT( 0xfc, IP_ACTIVE_LOW, IPT_UNKNOWN )

	PORT_START				/* fake analog X */
	PORT_BIT( 0xff, 0x80, IPT_LIGHTGUN_X ) PORT_MINMAX(0,255) PORT_SENSITIVITY(50) PORT_KEYDELTA(10)

	PORT_START				/* fake analog Y */
	PORT_BIT( 0xff, 0x80, IPT_LIGHTGUN_Y ) PORT_MINMAX(0,255) PORT_SENSITIVITY(70) PORT_KEYDELTA(10)
INPUT_PORTS_END


INPUT_PORTS_START( showdown )
	PORT_START				/* player inputs and logic board dips */
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_BUTTON1 )
	PORT_DIPNAME( 0x0c, 0x0c, "Hands" )
	PORT_DIPSETTING(    0x08, "1" )
	PORT_DIPSETTING(    0x0c, "2" )
	PORT_DIPSETTING(    0x04, "3" )
	PORT_DIPSETTING(    0x00, "4" )
	PORT_DIPNAME( 0x30, 0x30, DEF_STR( Difficulty ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Easy ) )
	PORT_DIPSETTING(    0x30, DEF_STR( Normal ) )
	PORT_DIPSETTING(    0x20, DEF_STR( Hard ) )
	PORT_DIPSETTING(    0x10, DEF_STR( Hardest ) )
	PORT_BIT( 0xc0, IP_ACTIVE_LOW, IPT_UNKNOWN )

	PORT_START 				/* audio board dips */
	COINAGE
	PORT_DIPNAME( 0x70, 0x70, DEF_STR( Unknown ) )
	PORT_DIPSETTING(    0x07, "1" )
	PORT_DIPSETTING(    0x06, "2" )
	PORT_DIPSETTING(    0x05, "3" )
	PORT_DIPSETTING(    0x04, "4" )
	PORT_DIPSETTING(    0x03, "5" )
	PORT_DIPSETTING(    0x02, "6" )
	PORT_DIPSETTING(    0x01, "7" )
	PORT_DIPSETTING(    0x00, "1/Freeplay" )
	PORT_DIPNAME( 0x80, 0x80, DEF_STR( Unknown ) )
	PORT_DIPSETTING(    0x80, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )

	PORT_START				/* start button */
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_START1 ) PORT_NAME("Action")
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_BUTTON4 ) PORT_NAME("Bet-All")
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_BUTTON5 ) PORT_NAME("Gold")
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_BUTTON6 ) PORT_NAME("Blue")
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_BUTTON7 ) PORT_NAME("Red")
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_BUTTON8 ) PORT_NAME("White")
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_UNKNOWN )

	PORT_START				/* coin counters */
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_COIN1 )
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_COIN2 )
	PORT_BIT( 0xfc, IP_ACTIVE_LOW, IPT_UNKNOWN )

	PORT_START				/* fake analog X */
	PORT_BIT( 0xff, 0x80, IPT_LIGHTGUN_X ) PORT_MINMAX(0,255) PORT_SENSITIVITY(50) PORT_KEYDELTA(10)

	PORT_START				/* fake analog Y */
	PORT_BIT( 0xff, 0x80, IPT_LIGHTGUN_Y ) PORT_MINMAX(0,255) PORT_SENSITIVITY(70) PORT_KEYDELTA(10)
INPUT_PORTS_END


/*************************************
 *
 *  Game drivers
 *
 *************************************/

GAME( 1983, crossbow, 0,        exidy440, crossbow, crossbow, ROT0, "Exidy", "Crossbow (version 2.0)", 0 )
GAME( 1984, cheyenne, 0,        exidy440, cheyenne, cheyenne, ROT0, "Exidy", "Cheyenne (version 1.0)", 0 )
GAME( 1985, combat,   0,        exidy440, combat,   combat,   ROT0, "Exidy", "Combat (version 3.0)", 0 )
GAME( 1985, catch22,  combat,   exidy440, catch22,  combat,   ROT0, "Exidy", "Catch-22 (version 8.0)", 0 )
GAME( 1985, cracksht, 0,        exidy440, cracksht, cracksht, ROT0, "Exidy", "Crackshot (version 2.0)", 0 )
GAME( 1986, claypign, 0,        exidy440, claypign, claypign, ROT0, "Exidy", "Clay Pigeon (version 2.0)", 0 )
GAME( 1986, chiller,  0,        exidy440, chiller,  chiller,  ROT0, "Exidy", "Chiller (version 3.0)", 0 )
GAME( 1986, topsecex, 0,        exidy440, topsecex, topsecex, ROT0, "Exidy", "Top Secret (Exidy) (version 1.0)", 0 )
GAME( 1987, hitnmiss, 0,        exidy440, hitnmiss, hitnmiss, ROT0, "Exidy", "Hit 'n Miss (version 3.0)", 0 )
GAME( 1987, hitnmis2, hitnmiss, exidy440, hitnmiss, hitnmiss, ROT0, "Exidy", "Hit 'n Miss (version 2.0)", 0 )
GAME( 1988, whodunit, 0,        exidy440, whodunit, whodunit, ROT0, "Exidy", "Who Dunit (version 8.0)", 0 )
GAME( 1988, showdown, 0,        exidy440, showdown, showdown, ROT0, "Exidy", "Showdown (version 5.0)", 0 )
