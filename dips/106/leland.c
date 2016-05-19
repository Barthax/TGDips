****************************************************************************

    To enter service mode in most games, press 1P start and then press
    the service switch (F2).

    For Redline Racer, hold the service switch down and reset the machine.

    For Super Offroad, press the blue nitro button (3P button 1) and then
    press the service switch.

***************************************************************************/
/*************************************
 *
 *  Port definitions
 *
 *************************************/

/* Helps document the input ports. */
#define IPT_SLAVEHALT 	IPT_SPECIAL
#define IPT_EEPROM_DATA	IPT_SPECIAL


INPUT_PORTS_START( cerberus )		/* complete, verified from code */
	PORT_START      /* 0x80 */
    PORT_BIT( 0x3f, IP_ACTIVE_LOW, IPT_SPECIAL ) PORT_PLAYER(1)
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_PLAYER(1)
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_BUTTON2 ) PORT_PLAYER(1)

	PORT_START      /* 0x81 */
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_SLAVEHALT )
	PORT_SERVICE_NO_TOGGLE( 0x02, IP_ACTIVE_LOW )
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_COIN2 )
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_COIN1 )
	PORT_BIT( 0xf0, IP_ACTIVE_LOW, IPT_UNUSED )

	PORT_START      /* 0x90 */
    PORT_BIT( 0x3f, IP_ACTIVE_LOW, IPT_SPECIAL ) PORT_PLAYER(2)
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_PLAYER(2)
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_BUTTON2 ) PORT_PLAYER(2)

	PORT_START      /* 0x91 */
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_EEPROM_DATA )
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_VBLANK )
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_START2 ) PORT_PLAYER(1)
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_START1 ) PORT_PLAYER(1)
	PORT_BIT( 0xf0, IP_ACTIVE_LOW, IPT_UNUSED )

	PORT_START      /* Analog joystick 1 */
    PORT_BIT( 0xff, 0, IPT_DIAL ) PORT_SENSITIVITY(50) PORT_KEYDELTA(10) PORT_PLAYER(1)
	PORT_START
    PORT_BIT( 0xff, 0, IPT_DIAL ) PORT_SENSITIVITY(50) PORT_KEYDELTA(10) PORT_PLAYER(2)
	PORT_START      /* Analog joystick 2 */
	PORT_START
	PORT_START      /* Analog joystick 3 */
	PORT_START
INPUT_PORTS_END


INPUT_PORTS_START( mayhem )		/* complete, verified from code */
	PORT_START      /* 0xC0 */
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_PLAYER(2)
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_BUTTON3 ) PORT_PLAYER(2)
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_BUTTON2 ) PORT_PLAYER(2)
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_PLAYER(1)
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_BUTTON3 ) PORT_PLAYER(1)
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_BUTTON2 ) PORT_PLAYER(1)

	PORT_START      /* 0xC1 */
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_SLAVEHALT )
	PORT_SERVICE_NO_TOGGLE( 0x02, IP_ACTIVE_LOW )
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_COIN2 )
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_COIN1 )
	PORT_BIT( 0xf0, IP_ACTIVE_LOW, IPT_UNUSED )

	PORT_START      /* 0xD0 */
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT ) PORT_8WAY PORT_PLAYER(2)
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT ) PORT_8WAY PORT_PLAYER(2)
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN ) PORT_8WAY PORT_PLAYER(2)
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_JOYSTICK_UP ) PORT_8WAY PORT_PLAYER(2)
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT ) PORT_8WAY PORT_PLAYER(1)
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT ) PORT_8WAY PORT_PLAYER(1)
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN ) PORT_8WAY PORT_PLAYER(1)
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_JOYSTICK_UP ) PORT_8WAY PORT_PLAYER(1)

	PORT_START      /* 0xD1 */
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_EEPROM_DATA )
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_VBLANK )
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_START2 )
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_START1 )
	PORT_BIT( 0xf0, IP_ACTIVE_LOW, IPT_UNUSED )

	PORT_START      /* Analog joystick 1 */
	PORT_START
	PORT_START      /* Analog joystick 2 */
	PORT_START
	PORT_START      /* Analog joystick 3 */
	PORT_START
INPUT_PORTS_END


INPUT_PORTS_START( wseries )		/* complete, verified from code */
	PORT_START      /* 0x80 */
	PORT_BIT( 0x3f, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT(0x40, IP_ACTIVE_LOW, IPT_BUTTON2 ) PORT_NAME("Extra Base") PORT_PLAYER(1)
	PORT_BIT(0x80, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_NAME("Go Back") PORT_PLAYER(1)

	PORT_START      /* 0x81 */
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_SLAVEHALT )
	PORT_SERVICE_NO_TOGGLE( 0x02, IP_ACTIVE_LOW )
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_COIN2 )
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_COIN1 )
	PORT_BIT( 0xf0, IP_ACTIVE_LOW, IPT_UNUSED )

	PORT_START      /* 0x90 */
	PORT_BIT( 0x7f, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT(0x80, IP_ACTIVE_LOW, IPT_BUTTON3 ) PORT_NAME("Aim") PORT_PLAYER(1)

	PORT_START      /* 0x91 */
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_EEPROM_DATA )
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_VBLANK )
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_START2 ) PORT_PLAYER(1)
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_START1 ) PORT_PLAYER(1)
	PORT_BIT( 0xf0, IP_ACTIVE_LOW, IPT_UNUSED )

	PORT_START      /* Analog joystick 1 */
	PORT_BIT( 0xff, 0x80, IPT_AD_STICK_Y ) PORT_MINMAX(0,255) PORT_SENSITIVITY(100) PORT_KEYDELTA(10) PORT_PLAYER(1)
	PORT_START
	PORT_BIT( 0xff, 0x80, IPT_AD_STICK_X ) PORT_MINMAX(0,255) PORT_SENSITIVITY(100) PORT_KEYDELTA(10) PORT_PLAYER(1)
	PORT_START      /* Analog joystick 2 */
	PORT_START
	PORT_START      /* Analog joystick 3 */
	PORT_BIT( 0xff, 0x80, IPT_AD_STICK_X ) PORT_MINMAX(0,255) PORT_SENSITIVITY(100) PORT_KEYDELTA(10) PORT_PLAYER(2)
	PORT_START
	PORT_BIT( 0xff, 0x80, IPT_AD_STICK_Y ) PORT_MINMAX(0,255) PORT_SENSITIVITY(100) PORT_KEYDELTA(10) PORT_PLAYER(2)
INPUT_PORTS_END


INPUT_PORTS_START( alleymas )		/* complete, verified from code */
	PORT_START      /* 0xC0 */
	PORT_BIT( 0x3f, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_BUTTON2 )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_BUTTON1 )

	PORT_START      /* 0xC1 */
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_SLAVEHALT )
	PORT_SERVICE_NO_TOGGLE( 0x02, IP_ACTIVE_LOW )
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_COIN2 )
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_COIN1 )
	PORT_BIT( 0xf0, IP_ACTIVE_LOW, IPT_UNUSED )

	PORT_START      /* 0xD0 */
	PORT_BIT( 0x3f, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_BUTTON1 )		/* redundant inputs */
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_BUTTON2 )		/* redundant inputs */

	PORT_START      /* 0xD1 */
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_EEPROM_DATA )
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_VBLANK )
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_START2 ) PORT_PLAYER(1)
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_START1 ) PORT_PLAYER(1)
	PORT_BIT( 0xf0, IP_ACTIVE_LOW, IPT_UNUSED )

	PORT_START      /* Analog joystick 1 */
	PORT_BIT( 0xff, 0x80, IPT_AD_STICK_Y ) PORT_MINMAX(0,255) PORT_SENSITIVITY(100) PORT_KEYDELTA(10) PORT_PLAYER(1)
	PORT_START
	PORT_BIT( 0xff, 0x80, IPT_AD_STICK_X ) PORT_MINMAX(0,224) PORT_SENSITIVITY(100) PORT_KEYDELTA(10) PORT_PLAYER(1)
	PORT_START      /* Analog joystick 2 */
	PORT_START
	PORT_START      /* Analog joystick 3 */
	PORT_START
INPUT_PORTS_END


INPUT_PORTS_START( upyoural )		/* complete, verified from code */
	PORT_START      /* 0xC0 */
	PORT_BIT( 0x3f, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_BUTTON4 )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_BUTTON1 )

	PORT_START      /* 0xC1 */
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_SLAVEHALT )
	PORT_SERVICE_NO_TOGGLE( 0x02, IP_ACTIVE_LOW )
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_COIN2 )
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_COIN1 )
	PORT_BIT( 0xf0, IP_ACTIVE_LOW, IPT_UNUSED )

	PORT_START      /* 0xD0 */
	PORT_BIT( 0x3f, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_BUTTON3 )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_BUTTON2 )

	PORT_START      /* 0xD1 */
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_EEPROM_DATA )
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_VBLANK )
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_START2 ) PORT_PLAYER(1)
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_START1 ) PORT_PLAYER(1)
	PORT_BIT( 0xf0, IP_ACTIVE_LOW, IPT_UNUSED )

	PORT_START      /* Analog joystick 1 */
	PORT_BIT( 0xff, 0x80, IPT_AD_STICK_Y ) PORT_MINMAX(0,255) PORT_SENSITIVITY(100) PORT_KEYDELTA(10) PORT_PLAYER(1)
	PORT_START
	PORT_BIT( 0xff, 0x80, IPT_AD_STICK_X ) PORT_MINMAX(0,224) PORT_SENSITIVITY(100) PORT_KEYDELTA(10) PORT_PLAYER(1)
	PORT_START      /* Analog joystick 2 */
	PORT_START
	PORT_START      /* Analog joystick 3 */
	PORT_START
INPUT_PORTS_END


INPUT_PORTS_START( dangerz )		/* complete, verified from code */
	PORT_START      /* 0x80 */
	PORT_BIT( 0x1f, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_BUTTON1 )
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_BUTTON2 )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_UNUSED )

	PORT_START      /* 0x81 */
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_SLAVEHALT )
	PORT_SERVICE_NO_TOGGLE( 0x02, IP_ACTIVE_LOW )
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_COIN2 )
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_COIN1 )
	PORT_BIT( 0xf0, IP_ACTIVE_LOW, IPT_UNUSED )

	PORT_START      /* 0x90 */
	PORT_BIT( 0xff, IP_ACTIVE_LOW, IPT_UNUSED )

	PORT_START      /* 0x91 */
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_EEPROM_DATA )
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_VBLANK )
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_START2 )
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_START1 )
	PORT_BIT( 0xf0, IP_ACTIVE_LOW, IPT_UNUSED )

	PORT_START      /* Analog 1 */
	PORT_BIT( 0xff, 0x00, IPT_TRACKBALL_Y ) PORT_MINMAX(0,255) PORT_SENSITIVITY(100) PORT_KEYDELTA(10) PORT_PLAYER(1)
	PORT_START      /* Analog 2 */
	PORT_BIT( 0xff, 0x00, IPT_TRACKBALL_X ) PORT_MINMAX(0,255) PORT_SENSITIVITY(100) PORT_KEYDELTA(10) PORT_PLAYER(1)
INPUT_PORTS_END


INPUT_PORTS_START( basebal2 )		/* complete, verified from code */
	PORT_START      /* 0x40/C0 */
	PORT_BIT( 0x0f, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x30, IP_ACTIVE_LOW, IPT_UNKNOWN )	/* read by strkzone, but never referenced */
	PORT_BIT(0x40, IP_ACTIVE_LOW, IPT_BUTTON2 ) PORT_NAME("Extra Base") PORT_PLAYER(1)
	PORT_BIT(0x80, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_NAME("Go Back") PORT_PLAYER(1)

	PORT_START      /* 0x41/C1 */
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_SLAVEHALT )
	PORT_SERVICE_NO_TOGGLE( 0x02, IP_ACTIVE_LOW )
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_COIN2 )
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_COIN1 )
	PORT_BIT( 0xf0, IP_ACTIVE_LOW, IPT_UNUSED )

	PORT_START      /* 0x50/D0 */
	PORT_BIT( 0x0f, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT(0x10, IP_ACTIVE_LOW, IPT_BUTTON4 ) PORT_NAME("R Run/Steal") PORT_PLAYER(1)
	PORT_BIT(0x20, IP_ACTIVE_LOW, IPT_BUTTON3 ) PORT_NAME("L Run/Steal") PORT_PLAYER(1)
	PORT_BIT(0x40, IP_ACTIVE_LOW, IPT_BUTTON6 ) PORT_NAME("Run/Aim") PORT_PLAYER(1)
	PORT_BIT(0x80, IP_ACTIVE_LOW, IPT_BUTTON5 ) PORT_NAME("Run/Cutoff") PORT_PLAYER(1)

	PORT_START      /* 0x51/D1 */
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_EEPROM_DATA )
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_VBLANK )
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_START2 ) PORT_PLAYER(1)
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_START1 ) PORT_PLAYER(1)
	PORT_BIT( 0xf0, IP_ACTIVE_LOW, IPT_UNUSED )

	PORT_START      /* Analog joystick 1 */
	PORT_BIT( 0xff, 0x80, IPT_AD_STICK_Y ) PORT_MINMAX(0,255) PORT_SENSITIVITY(100) PORT_KEYDELTA(10) PORT_PLAYER(1)
	PORT_START
	PORT_BIT( 0xff, 0x80, IPT_AD_STICK_X ) PORT_MINMAX(0,255) PORT_SENSITIVITY(100) PORT_KEYDELTA(10) PORT_PLAYER(1)
	PORT_START      /* Analog joystick 2 */
	PORT_START
	PORT_START      /* Analog joystick 3 */
	PORT_BIT( 0xff, 0x80, IPT_AD_STICK_X ) PORT_MINMAX(0,255) PORT_SENSITIVITY(100) PORT_KEYDELTA(10) PORT_PLAYER(2)
	PORT_START
	PORT_BIT( 0xff, 0x80, IPT_AD_STICK_Y ) PORT_MINMAX(0,255) PORT_SENSITIVITY(100) PORT_KEYDELTA(10) PORT_PLAYER(2)
INPUT_PORTS_END


INPUT_PORTS_START( redline )		/* complete, verified in code */
	PORT_START      /* 0xC0 */
	PORT_BIT( 0x1f, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0xe0, 0xe0, IPT_PEDAL ) PORT_MINMAX(0x00,0xff) PORT_SENSITIVITY(100) PORT_KEYDELTA(64) PORT_PLAYER(1)

	PORT_START      /* 0xC1 */
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_SLAVEHALT )
	PORT_SERVICE_NO_TOGGLE( 0x02, IP_ACTIVE_LOW )
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_COIN2 )
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_COIN1 )
	PORT_BIT( 0x70, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_UNKNOWN )	/* used, but for what purpose? */

	PORT_START      /* 0xD0 */
	PORT_BIT( 0x1f, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0xe0, 0xe0, IPT_PEDAL ) PORT_MINMAX(0x00,0xff) PORT_SENSITIVITY(100) PORT_KEYDELTA(64) PORT_PLAYER(2)

	PORT_START      /* 0xD1 */
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_EEPROM_DATA )
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_VBLANK )
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_START2 )
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_START1 )
	PORT_BIT( 0xf0, IP_ACTIVE_LOW, IPT_UNUSED )

	PORT_START      /* Analog wheel 1 */
	PORT_BIT( 0xff, 0x80, IPT_DIAL ) PORT_MINMAX(0,255) PORT_SENSITIVITY(100) PORT_KEYDELTA(10) PORT_PLAYER(1)
	PORT_START      /* Analog wheel 2 */
	PORT_BIT( 0xff, 0x80, IPT_DIAL ) PORT_MINMAX(0,255) PORT_SENSITIVITY(100) PORT_KEYDELTA(10) PORT_PLAYER(2)
INPUT_PORTS_END


INPUT_PORTS_START( quarterb )		/* complete, verified in code */
	PORT_START      /* 0x80 */
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_PLAYER(2)
	PORT_BIT( 0x0e, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_PLAYER(1)
	PORT_BIT( 0xe0, IP_ACTIVE_LOW, IPT_UNUSED )

	PORT_START      /* 0x81 */
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_SLAVEHALT )
	PORT_SERVICE_NO_TOGGLE( 0x02, IP_ACTIVE_LOW )
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_COIN2 )
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_COIN1 )
	PORT_BIT( 0xf0, IP_ACTIVE_LOW, IPT_UNUSED )

	PORT_START      /* 0x90 */
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT ) PORT_PLAYER(2)
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT ) PORT_PLAYER(2)
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN ) PORT_PLAYER(2)
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_JOYSTICK_UP ) PORT_PLAYER(2)
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT ) PORT_PLAYER(1)
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT ) PORT_PLAYER(1)
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN ) PORT_PLAYER(1)
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_JOYSTICK_UP ) PORT_PLAYER(1)

	PORT_START      /* 0x91 */
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_EEPROM_DATA )
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_VBLANK )
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_START2 )
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_START1 )
	PORT_BIT( 0xf0, IP_ACTIVE_LOW, IPT_UNUSED )

	PORT_START      /* Analog spring stick 1 */
	PORT_BIT( 0xff, 0x80, IPT_AD_STICK_X ) PORT_MINMAX(0,255) PORT_SENSITIVITY(100) PORT_KEYDELTA(10) PORT_PLAYER(1)
	PORT_START      /* Analog spring stick 2 */
	PORT_BIT( 0xff, 0x80, IPT_AD_STICK_Y ) PORT_MINMAX(0,255) PORT_SENSITIVITY(100) PORT_KEYDELTA(10) PORT_PLAYER(1)
	PORT_START      /* Analog spring stick 3 */
	PORT_START      /* Analog spring stick 4 */
	PORT_START      /* Analog spring stick 5 */
	PORT_START      /* Analog spring stick 6 */
INPUT_PORTS_END


INPUT_PORTS_START( teamqb )		/* complete, verified in code */
	PORT_START      /* 0x80 */
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_PLAYER(2)
	PORT_BIT( 0x0e, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_PLAYER(1)
	PORT_BIT( 0xe0, IP_ACTIVE_LOW, IPT_UNUSED )

	PORT_START      /* 0x81 */
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_SLAVEHALT )
	PORT_SERVICE_NO_TOGGLE( 0x02, IP_ACTIVE_LOW )
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_COIN2 )
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_COIN1 )
	PORT_BIT( 0xf0, IP_ACTIVE_LOW, IPT_UNUSED )

	PORT_START      /* 0x90 */
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT ) PORT_PLAYER(2)
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT ) PORT_PLAYER(2)
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN ) PORT_PLAYER(2)
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_JOYSTICK_UP ) PORT_PLAYER(2)
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT ) PORT_PLAYER(1)
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT ) PORT_PLAYER(1)
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN ) PORT_PLAYER(1)
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_JOYSTICK_UP ) PORT_PLAYER(1)

	PORT_START      /* 0x91 */
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_EEPROM_DATA )
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_VBLANK )
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_START2 )
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_START1 )
	PORT_BIT( 0xf0, IP_ACTIVE_LOW, IPT_UNUSED )

	PORT_START      /* Analog spring stick 1 */
	PORT_BIT( 0xff, 0x80, IPT_AD_STICK_X ) PORT_MINMAX(0,255) PORT_SENSITIVITY(100) PORT_KEYDELTA(10) PORT_PLAYER(1)
	PORT_START      /* Analog spring stick 2 */
	PORT_BIT( 0xff, 0x80, IPT_AD_STICK_Y ) PORT_MINMAX(0,255) PORT_SENSITIVITY(100) PORT_KEYDELTA(10) PORT_PLAYER(1)
	PORT_START      /* Analog spring stick 3 */
	PORT_START      /* Analog spring stick 4 */
	PORT_START      /* Analog spring stick 5 */
	PORT_BIT( 0xff, 0x80, IPT_AD_STICK_Y ) PORT_MINMAX(0,255) PORT_SENSITIVITY(100) PORT_KEYDELTA(10) PORT_PLAYER(3)
	PORT_START      /* Analog spring stick 6 */
	PORT_BIT( 0xff, 0x80, IPT_AD_STICK_X ) PORT_MINMAX(0,255) PORT_SENSITIVITY(100) PORT_KEYDELTA(10) PORT_PLAYER(3)

	PORT_START      /* 0x7C */
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_PLAYER(4)
	PORT_BIT( 0x0e, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_PLAYER(3)
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_START3 )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_START4 )

	PORT_START      /* 0x7F */
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT ) PORT_PLAYER(4)
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT ) PORT_PLAYER(4)
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN ) PORT_PLAYER(4)
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_JOYSTICK_UP ) PORT_PLAYER(4)
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT ) PORT_PLAYER(3)
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT ) PORT_PLAYER(3)
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN ) PORT_PLAYER(3)
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_JOYSTICK_UP ) PORT_PLAYER(3)
INPUT_PORTS_END


INPUT_PORTS_START( aafb2p )		/* complete, verified in code */
	PORT_START      /* 0x80 */
	PORT_BIT( 0x0f, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_PLAYER(1)
	PORT_BIT( 0xe0, IP_ACTIVE_LOW, IPT_UNUSED )

	PORT_START      /* 0x81 */
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_SLAVEHALT )
	PORT_SERVICE_NO_TOGGLE( 0x02, IP_ACTIVE_LOW )
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_COIN2 )
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_COIN1 )
	PORT_BIT( 0xf0, IP_ACTIVE_LOW, IPT_UNUSED )

	PORT_START      /* 0x90 */
	PORT_BIT( 0x0f, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT ) PORT_PLAYER(1)
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT ) PORT_PLAYER(1)
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN ) PORT_PLAYER(1)
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_JOYSTICK_UP ) PORT_PLAYER(1)

	PORT_START      /* 0x91 */
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_EEPROM_DATA )
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_VBLANK )
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_START1 )
	PORT_BIT( 0xf0, IP_ACTIVE_LOW, IPT_UNUSED )

	PORT_START      /* Analog spring stick 1 */
	PORT_BIT( 0xff, 0x80, IPT_AD_STICK_X ) PORT_MINMAX(0,255) PORT_SENSITIVITY(100) PORT_KEYDELTA(10) PORT_PLAYER(1)
	PORT_START      /* Analog spring stick 2 */
	PORT_BIT( 0xff, 0x80, IPT_AD_STICK_Y ) PORT_MINMAX(0,255) PORT_SENSITIVITY(100) PORT_KEYDELTA(10) PORT_PLAYER(1)
	PORT_START      /* Analog spring stick 3 */
	PORT_START      /* Analog spring stick 4 */
	PORT_START      /* Analog spring stick 5 */
	PORT_BIT( 0xff, 0x80, IPT_AD_STICK_Y ) PORT_MINMAX(0,255) PORT_SENSITIVITY(100) PORT_KEYDELTA(10) PORT_PLAYER(2)
	PORT_START      /* Analog spring stick 6 */
	PORT_BIT( 0xff, 0x80, IPT_AD_STICK_X ) PORT_MINMAX(0,255) PORT_SENSITIVITY(100) PORT_KEYDELTA(10) PORT_PLAYER(2)

	PORT_START      /* 0x7C */
	PORT_BIT( 0x0f, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_PLAYER(2)
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_START2 )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_UNUSED )

	PORT_START      /* 0x7F */
	PORT_BIT( 0x0f, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT ) PORT_PLAYER(2)
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT ) PORT_PLAYER(2)
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN ) PORT_PLAYER(2)
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_JOYSTICK_UP ) PORT_PLAYER(2)
INPUT_PORTS_END


INPUT_PORTS_START( offroad )		/* complete, verified from code */
	PORT_START      /* 0xC0 */
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_UNKNOWN )	/* read */
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_UNKNOWN )	/* read */
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_UNKNOWN )	/* read */
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_PLAYER(1)
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_PLAYER(2)
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_PLAYER(3)
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_UNUSED )

	PORT_START      /* 0xC1 */
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_SLAVEHALT )
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_COIN3 )
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_COIN2 )
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_COIN1 )
	PORT_BIT( 0xf0, IP_ACTIVE_LOW, IPT_UNUSED )

	PORT_START      /* 0xD0 */
	PORT_BIT( 0xff, IP_ACTIVE_LOW, IPT_UNUSED )

	PORT_START      /* 0xD1 */
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_EEPROM_DATA )
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_VBLANK )
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_SERVICE_NO_TOGGLE( 0x08, IP_ACTIVE_LOW )
	PORT_BIT( 0xf0, IP_ACTIVE_LOW, IPT_UNUSED )

	PORT_START      /* Analog pedal 1 */
	PORT_BIT( 0xff, 0x00, IPT_PEDAL ) PORT_MINMAX(0,255) PORT_SENSITIVITY(100) PORT_KEYDELTA(10) PORT_PLAYER(1)
	PORT_START      /* Analog pedal 2 */
	PORT_BIT( 0xff, 0x00, IPT_PEDAL ) PORT_MINMAX(0,255) PORT_SENSITIVITY(100) PORT_KEYDELTA(10) PORT_PLAYER(2)
	PORT_START      /* Analog pedal 3 */
	PORT_BIT( 0xff, 0x00, IPT_PEDAL ) PORT_MINMAX(0,255) PORT_SENSITIVITY(100) PORT_KEYDELTA(10) PORT_PLAYER(3)
	PORT_START      /* Analog wheel 1 */
	PORT_BIT( 0xff, 0x80, IPT_DIAL ) PORT_MINMAX(0,255) PORT_SENSITIVITY(100) PORT_KEYDELTA(10) PORT_PLAYER(1)
	PORT_START      /* Analog wheel 2 */
	PORT_BIT( 0xff, 0x80, IPT_DIAL ) PORT_MINMAX(0,255) PORT_SENSITIVITY(100) PORT_KEYDELTA(10) PORT_PLAYER(2)
	PORT_START      /* Analog wheel 3 */
	PORT_BIT( 0xff, 0x80, IPT_DIAL ) PORT_MINMAX(0,255) PORT_SENSITIVITY(100) PORT_KEYDELTA(10) PORT_PLAYER(3)
INPUT_PORTS_END


INPUT_PORTS_START( pigout )		/* complete, verified from code */
	PORT_START      /* 0x40 */
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_BUTTON2 ) PORT_PLAYER(3)
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT ) PORT_8WAY PORT_PLAYER(3)
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN ) PORT_8WAY PORT_PLAYER(3)
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_BUTTON2 ) PORT_PLAYER(2)
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT ) PORT_8WAY PORT_PLAYER(2)
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_JOYSTICK_UP ) PORT_8WAY PORT_PLAYER(2)

	PORT_START      /* 0x41 */
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_SLAVEHALT )
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_COIN1 )
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_UNKNOWN )	/* read, but never referenced */
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_COIN2 )
	PORT_BIT( 0xf0, IP_ACTIVE_LOW, IPT_UNUSED )

	PORT_START      /* 0x50 */
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_START3 )
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_PLAYER(3)
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT ) PORT_8WAY PORT_PLAYER(3)
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_JOYSTICK_UP ) PORT_8WAY PORT_PLAYER(3)
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_START2 )
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_PLAYER(2)
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT ) PORT_8WAY PORT_PLAYER(2)
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN ) PORT_8WAY PORT_PLAYER(2)

	PORT_START      /* 0x51 */
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_EEPROM_DATA )
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_VBLANK )
	PORT_SERVICE_NO_TOGGLE( 0x04, IP_ACTIVE_LOW )
	PORT_BIT( 0xf8, IP_ACTIVE_LOW, IPT_UNUSED )

	PORT_START      /* 0x7F */
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_JOYSTICK_UP ) PORT_8WAY PORT_PLAYER(1)
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN ) PORT_8WAY PORT_PLAYER(1)
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT ) PORT_8WAY PORT_PLAYER(1)
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT ) PORT_8WAY PORT_PLAYER(1)
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_PLAYER(1)
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_BUTTON2 ) PORT_PLAYER(1)
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_START1 )
INPUT_PORTS_END

/*************************************
 *
 *  Game drivers
 *
 *************************************/

/* small master banks, small slave banks */
GAME( 1985, cerberus, 0,       leland,  cerberus, cerberus, ROT0,   "Cinematronics", "Cerberus", 0 )
GAME( 1985, mayhem,   0,       leland,  mayhem,   mayhem,   ROT0,   "Cinematronics", "Mayhem 2002", 0 )
GAME( 1985, powrplay, 0,       leland,  mayhem,   powrplay, ROT0,   "Cinematronics", "Power Play", 0 )
GAME( 1985, wseries,  0,       leland,  wseries,  wseries,  ROT0,   "Cinematronics", "World Series: The Season", 0 )
GAME( 1986, alleymas, 0,       leland,  alleymas, alleymas, ROT270, "Cinematronics", "Alley Master", 0 )
GAME( 1987, upyoural, 0,       leland,  upyoural, upyoural, ROT270, "Cinematronics", "Up Your Alley", 0 )

/* odd master banks, small slave banks */
GAME( 1986, dangerz,  0,       leland,  dangerz,  dangerz,  ROT0,   "Cinematronics", "Danger Zone", 0 )

/* small master banks + extra top board, small slave banks */
GAME( 1987, basebal2, 0,       leland,  basebal2, basebal2, ROT0,   "Cinematronics", "Baseball The Season II", 0 )
GAME( 1987, dblplay,  0,       leland,  basebal2, dblplay,  ROT0,   "Leland Corp. / Tradewest", "Super Baseball Double Play Home Run Derby", 0 )
GAME( 1988, strkzone, 0,       leland,  basebal2, strkzone, ROT0,   "Leland Corp.", "Strike Zone Baseball", 0 )

/* large master banks, small slave banks, I86 sound */
GAME( 1987, redlin2p, 0,       redline, redline,  redlin2p, ROT270, "Cinematronics (Tradewest license)", "Redline Racer (2 players)", 0 )
GAME( 1987, quarterb, 0,       quarterb,quarterb, quarterb, ROT270, "Leland Corp.", "Quarterback", 0 )
GAME( 1987, quartrba, quarterb,quarterb,quarterb, quarterb, ROT270, "Leland Corp.", "Quarterback (set 2)", 0 )

/* large master banks, large slave banks, I86 sound */
GAME( 1988, viper,    0,       lelandi, dangerz,  viper,    ROT0,   "Leland Corp.", "Viper", 0 )
GAME( 1988, teamqb,   0,       lelandi, teamqb,   teamqb,   ROT270, "Leland Corp.", "John Elway's Team Quarterback", 0 )
GAME( 1988, teamqb2,  teamqb,  lelandi, teamqb,   teamqb,   ROT270, "Leland Corp.", "John Elway's Team Quarterback (set 2)", 0 )
GAME( 1989, aafb,     0,       lelandi, teamqb,   aafb,     ROT270, "Leland Corp.", "All American Football (rev E)", 0 )
GAME( 1989, aafbd2p,  aafb,    lelandi, aafb2p,   aafbd2p,  ROT270, "Leland Corp.", "All American Football (rev D, 2 Players)", 0 )
GAME( 1989, aafbc,    aafb,    lelandi, teamqb,   aafbb,    ROT270, "Leland Corp.", "All American Football (rev C)", 0 )
GAME( 1989, aafbb,    aafb,    lelandi, teamqb,   aafbb,    ROT270, "Leland Corp.", "All American Football (rev B)", 0 )

/* huge master banks, large slave banks, I86 sound */
GAME( 1989, offroad,  0,       lelandi, offroad,  offroad,  ROT0,   "Leland Corp.", "Ironman Stewart's Super Off-Road", 0 )
GAME( 1989, offroadt, 0,       lelandi, offroad,  offroadt, ROT0,   "Leland Corp.", "Ironman Stewart's Super Off-Road Track Pack", 0 )
GAME( 1990, pigout,   0,       lelandi, pigout,   pigout,   ROT0,   "Leland Corp.", "Pigout", 0 )
GAME( 1990, pigouta,  pigout,  lelandi, pigout,   pigout,   ROT0,   "Leland Corp.", "Pigout (alternate)", 0 )
