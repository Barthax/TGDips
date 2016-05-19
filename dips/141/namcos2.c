/*************************************************************/
/*                                                           */
/*  NAMCO SYSTEM 2 PORT MACROS                               */
/*                                                           */
/*  Below are the port defintion macros that should be used  */
/*  as the basis for defining a port set for a Namco System2  */
/*  game.                                                    */
/*                                                           */
/*************************************************************/

#define NAMCOS2_MCU_PORT_B_DEFAULT \
	PORT_START("MCUB")		/* 63B05Z0 - PORT B */ \
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT ) PORT_PLAYER(2) \
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT ) \
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN ) PORT_PLAYER(2) \
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN ) \
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_JOYSTICK_UP ) PORT_PLAYER(2) \
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_JOYSTICK_UP ) \
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_START2 ) \
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_START1 )

#define NAMCOS2_MCU_PORT_C_DEFAULT \
	PORT_START("MCUC")		/* 63B05Z0 - PORT C & SCI */ \
	PORT_BIT( 0x0f, IP_ACTIVE_LOW, IPT_UNUSED ) \
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_COIN2 ) \
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_COIN1 ) \
	PORT_BIT(0x40, IP_ACTIVE_LOW, IPT_SERVICE ) PORT_NAME("Service Button") PORT_CODE(KEYCODE_0) /* Make it accessible by default*/ \
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_SERVICE1 )

#define NAMCOS2_MCU_ANALOG_PORT_DEFAULT \
	PORT_START("AN0")		/* 63B05Z0 - 8 CHANNEL ANALOG - CHANNEL 0 */ \
	PORT_BIT( 0xff, IP_ACTIVE_LOW, IPT_UNUSED ) \
	PORT_START("AN1")		/* 63B05Z0 - 8 CHANNEL ANALOG - CHANNEL 1 */ \
	PORT_BIT( 0xff, IP_ACTIVE_LOW, IPT_UNUSED ) \
	PORT_START("AN2")		/* 63B05Z0 - 8 CHANNEL ANALOG - CHANNEL 2 */ \
	PORT_BIT( 0xff, IP_ACTIVE_LOW, IPT_UNUSED ) \
	PORT_START("AN3")		/* 63B05Z0 - 8 CHANNEL ANALOG - CHANNEL 3 */ \
	PORT_BIT( 0xff, IP_ACTIVE_LOW, IPT_UNUSED ) \
	PORT_START("AN4")		/* 63B05Z0 - 8 CHANNEL ANALOG - CHANNEL 4 */ \
	PORT_BIT( 0xff, IP_ACTIVE_LOW, IPT_UNUSED ) \
	PORT_START("AN5")		/* 63B05Z0 - 8 CHANNEL ANALOG - CHANNEL 5 */ \
	PORT_BIT( 0xff, IP_ACTIVE_LOW, IPT_UNUSED ) \
	PORT_START("AN6")		/* 63B05Z0 - 8 CHANNEL ANALOG - CHANNEL 6 */ \
	PORT_BIT( 0xff, IP_ACTIVE_LOW, IPT_UNUSED ) \
	PORT_START("AN7")		/* 63B05Z0 - 8 CHANNEL ANALOG - CHANNEL 7 */ \
	PORT_BIT( 0xff, IP_ACTIVE_LOW, IPT_UNUSED )

#define NAMCOS2_MCU_PORT_H_DEFAULT \
	PORT_START("MCUH")		/* 63B05Z0 - PORT H */ \
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_BUTTON3 ) PORT_PLAYER(2) \
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_BUTTON3 ) \
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_BUTTON2 ) PORT_PLAYER(2) \
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_BUTTON2 ) \
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_PLAYER(2) \
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_BUTTON1 ) \
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT ) PORT_PLAYER(2) \
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT )

#define NAMCOS2_MCU_DIPSW_DEFAULT \
	PORT_START("DSW")		/* 63B05Z0 - $2000 DIP SW */ \
	PORT_DIPNAME( 0x01, 0x01, "Video Display") \
	PORT_DIPSETTING(	0x01, DEF_STR( Normal ) ) \
	PORT_DIPSETTING(	0x00, "Frozen" ) \
	PORT_DIPNAME( 0x02, 0x02, "$2000-1") \
	PORT_DIPSETTING(	0x02, "H" ) \
	PORT_DIPSETTING(	0x00, "L" ) \
	PORT_DIPNAME( 0x04, 0x04, "$2000-2") \
	PORT_DIPSETTING(	0x04, "H" ) \
	PORT_DIPSETTING(	0x00, "L" ) \
	PORT_DIPNAME( 0x08, 0x08, "$2000-3") \
	PORT_DIPSETTING(	0x08, "H" ) \
	PORT_DIPSETTING(	0x00, "L" ) \
	PORT_DIPNAME( 0x10, 0x10, "$2000-4") \
	PORT_DIPSETTING(	0x10, "H" ) \
	PORT_DIPSETTING(	0x00, "L" ) \
	PORT_DIPNAME( 0x20, 0x20, "$2000-5") \
	PORT_DIPSETTING(	0x20, "H" ) \
	PORT_DIPSETTING(	0x00, "L" ) \
	PORT_DIPNAME( 0x40, 0x40, "$2000-6") \
	PORT_DIPSETTING(	0x40, "H" ) \
	PORT_DIPSETTING(	0x00, "L" ) \
	PORT_SERVICE( 0x80, IP_ACTIVE_LOW )

#define NAMCOS2_MCU_DIAL_DEFAULT \
	PORT_START("MCUDI0")		/* 63B05Z0 - $3000 */ \
	PORT_BIT( 0xff, IP_ACTIVE_LOW, IPT_UNUSED ) \
	PORT_START("MCUDI1")		/* 63B05Z0 - $3001 */ \
	PORT_BIT( 0xff, IP_ACTIVE_LOW, IPT_UNUSED ) \
	PORT_START("MCUDI2")		/* 63B05Z0 - $3002 */ \
	PORT_BIT( 0xff, IP_ACTIVE_LOW, IPT_UNUSED ) \
	PORT_START("MCUDI3")		/* 63B05Z0 - $3003 */ \
	PORT_BIT( 0xff, IP_ACTIVE_LOW, IPT_UNUSED )

/*************************************************************/
/*                                                           */
/*  NAMCO SYSTEM 2 PORT DEFINITIONS                          */
/*                                                           */
/*  There is a standard port definition defined that will    */
/*  work for most games, if you wish to produce a special    */
/*  definition for a particular game then see the assault    */
/*  and dirtfox definitions for examples of how to construct */
/*  a special port definition                                */
/*                                                           */
/*  The default definitions includes only the following list */
/*  of connections :                                         */
/*    2 Joysticks, 6 Buttons, 1 Service, 1 Advance           */
/*    2 Start                                                */
/*                                                           */
/*************************************************************/

static INPUT_PORTS_START( default )
	NAMCOS2_MCU_PORT_B_DEFAULT
	NAMCOS2_MCU_PORT_C_DEFAULT
	NAMCOS2_MCU_ANALOG_PORT_DEFAULT
	NAMCOS2_MCU_PORT_H_DEFAULT
	NAMCOS2_MCU_DIPSW_DEFAULT
	NAMCOS2_MCU_DIAL_DEFAULT
INPUT_PORTS_END

static INPUT_PORTS_START( kyukaidk )
	PORT_INCLUDE( default )

	PORT_MODIFY("DSW")
	/* Must be 'L' for correct C140 output */
	PORT_DIPNAME( 0x20, 0x00, "$2000-5" )
	PORT_DIPSETTING(	0x20, "H" )
	PORT_DIPSETTING(	0x00, "L" )
INPUT_PORTS_END

static INPUT_PORTS_START( gollygho )
	PORT_START("MCUB")
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_PLAYER(2)
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_BUTTON1 )
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_START2 )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_START1 )

	NAMCOS2_MCU_PORT_C_DEFAULT

	PORT_START("AN0")
	PORT_BIT( 0xff, 0x80, IPT_LIGHTGUN_X ) PORT_CROSSHAIR(X, 1.0, 0.0, 0) PORT_SENSITIVITY(50) PORT_KEYDELTA(8) PORT_REVERSE
	PORT_START("AN1")
	PORT_BIT( 0xff, 0x80, IPT_LIGHTGUN_Y ) PORT_CROSSHAIR(Y, 1.0, 0.0, 0) PORT_SENSITIVITY(50) PORT_KEYDELTA(8) PORT_REVERSE
	PORT_START("AN2")
	PORT_BIT( 0xff, 0x80, IPT_LIGHTGUN_X ) PORT_CROSSHAIR(X, 1.0, 0.0, 0) PORT_SENSITIVITY(50) PORT_KEYDELTA(8) PORT_PLAYER(2) PORT_REVERSE
	PORT_START("AN3")
	PORT_BIT( 0xff, 0x80, IPT_LIGHTGUN_Y ) PORT_CROSSHAIR(Y, 1.0, 0.0, 0) PORT_SENSITIVITY(50) PORT_KEYDELTA(8) PORT_PLAYER(2) PORT_REVERSE
	PORT_START("AN4")
	PORT_BIT( 0xff, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_START("AN5")
	PORT_BIT( 0xff, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_START("AN6")
	PORT_BIT( 0xff, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_START("AN7")
	PORT_BIT( 0xff, IP_ACTIVE_LOW, IPT_UNUSED )

	PORT_START("MCUH")		/* 63B05Z0 - PORT H */
	PORT_BIT( 0xff, IP_ACTIVE_LOW, IPT_UNKNOWN )

	NAMCOS2_MCU_DIPSW_DEFAULT
	NAMCOS2_MCU_DIAL_DEFAULT
INPUT_PORTS_END

static INPUT_PORTS_START( bubbletr )
	PORT_START("MCUB")
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_PLAYER(2)
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_BUTTON1 )
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_START2 )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_START1 )

	NAMCOS2_MCU_PORT_C_DEFAULT

	// crosshair is required for gun calibration (hold 9, press F2)
	PORT_START("AN0")
	PORT_BIT( 0xff, 0x80, IPT_LIGHTGUN_X ) PORT_CROSSHAIR(X, -1.0, 0.0, 0) PORT_SENSITIVITY(50) PORT_KEYDELTA(8)
	PORT_START("AN1")
	PORT_BIT( 0xff, 0x80, IPT_LIGHTGUN_Y ) PORT_CROSSHAIR(Y, -1.0, 0.0, 0) PORT_SENSITIVITY(50) PORT_KEYDELTA(8)
	PORT_START("AN2")
	PORT_BIT( 0xff, 0x80, IPT_LIGHTGUN_X ) PORT_CROSSHAIR(X, -1.0, 0.0, 0) PORT_SENSITIVITY(50) PORT_KEYDELTA(8) PORT_PLAYER(2)
	PORT_START("AN3")
	PORT_BIT( 0xff, 0x80, IPT_LIGHTGUN_Y ) PORT_CROSSHAIR(Y, -1.0, 0.0, 0) PORT_SENSITIVITY(50) PORT_KEYDELTA(8) PORT_PLAYER(2)
	PORT_START("AN4")
	PORT_BIT( 0xff, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_START("AN5")
	PORT_BIT( 0xff, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_START("AN6")
	PORT_BIT( 0xff, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_START("AN7")
	PORT_BIT( 0xff, IP_ACTIVE_LOW, IPT_UNUSED )

	PORT_START("MCUH")		/* 63B05Z0 - PORT H */
	PORT_BIT( 0xff, IP_ACTIVE_LOW, IPT_UNKNOWN )

	NAMCOS2_MCU_DIPSW_DEFAULT
	NAMCOS2_MCU_DIAL_DEFAULT
INPUT_PORTS_END

static INPUT_PORTS_START( finallap )
	PORT_START("MCUB")		/* 63B05Z0 - PORT B */
	PORT_DIPNAME( 0x01, 0x01, "PortB 0x01")
	PORT_DIPSETTING(	0x01, "H" )
	PORT_DIPSETTING(	0x00, "L" )
	/**
     * Each player can have one of four car types, selected by attaching a
     * particular special connector (included with the game) to the PCB.
     *
     * (see also Car Type(B) below in Port H)
     */
	PORT_DIPNAME( 0x02, 0x02, "Car Type(A)")
	PORT_DIPSETTING(	0x02, "McLaren/Williams" )
	PORT_DIPSETTING(	0x00, "Lotus/March" )
	PORT_BIT( 0xfc, IP_ACTIVE_LOW, IPT_UNKNOWN )

	PORT_START("MCUC")		/* 63B05Z0 - PORT C & SCI */
	PORT_BIT( 0x0f, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_COIN2 )
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_COIN1 )
	PORT_SERVICE(0x40, IP_ACTIVE_LOW)
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_SERVICE1 )

	PORT_START("AN0")		/* 63B05Z0 - 8 CHANNEL ANALOG - CHANNEL 0 */
	PORT_BIT( 0xff, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_START("AN1")		/* 63B05Z0 - 8 CHANNEL ANALOG - CHANNEL 1 */
	PORT_BIT( 0xff, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_START("AN2")		/* 63B05Z0 - 8 CHANNEL ANALOG - CHANNEL 2 */
	PORT_BIT( 0xff, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_START("AN3")		/* 63B05Z0 - 8 CHANNEL ANALOG - CHANNEL 3 */
	PORT_BIT( 0xff, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_START("AN4")		/* 63B05Z0 - 8 CHANNEL ANALOG - CHANNEL 4 */
	PORT_BIT( 0xff, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_START("AN5")		/* Steering Wheel */		/* sensitivity, delta, min, max */
	PORT_BIT( 0xff, 0x80, IPT_PADDLE ) PORT_SENSITIVITY(50) PORT_KEYDELTA(10)
	PORT_START("AN6")		/* Brake Pedal */
	PORT_BIT( 0xff, 0x00, IPT_PEDAL2 ) PORT_SENSITIVITY(100) PORT_KEYDELTA(30)
	PORT_START("AN7")		/* Accelerator Pedal */
	PORT_BIT( 0xff, 0x00, IPT_PEDAL ) PORT_SENSITIVITY(100) PORT_KEYDELTA(15)

	PORT_START("MCUH")		/* 63B05Z0 - PORT H */
	PORT_DIPNAME( 0x01, 0x01, "PortH 0x01")
	PORT_DIPSETTING(	0x01, "H" )
	PORT_DIPSETTING(	0x00, "L" )
	PORT_DIPNAME( 0x02, 0x02, "Automatic Car Select")
	PORT_DIPSETTING(	0x02, DEF_STR(No) )
	PORT_DIPSETTING(	0x00, DEF_STR(Yes) )
	PORT_DIPNAME( 0x04, 0x04, "PortH 0x04")
	PORT_DIPSETTING(	0x04, "H" )
	PORT_DIPSETTING(	0x00, "L" )
	PORT_DIPNAME( 0x08, 0x08, "Enable Onscreen Diagnostics")
	PORT_DIPSETTING(	0x08, DEF_STR(No) )
	PORT_DIPSETTING(	0x00, DEF_STR(Yes) )
	PORT_DIPNAME( 0x10, 0x10, "PortH 0x10")
	PORT_DIPSETTING(	0x10, "H" )
	PORT_DIPSETTING(	0x00, "L" )
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_TOGGLE PORT_NAME("Shift Gear")/* Gear Shift */
	PORT_DIPNAME( 0x40, 0x40, "PortH 0x40")
	PORT_DIPSETTING(	0x40, "H" )
	PORT_DIPSETTING(	0x00, "L" )
	PORT_DIPNAME( 0x80, 0x80, "Car Type(B)")
	PORT_DIPSETTING(	0x00, "McLaren/March" )
	PORT_DIPSETTING(	0x80, "Williams/Lotus" )

	NAMCOS2_MCU_DIPSW_DEFAULT /* 63B05Z0 - $2000 DIP SW */

	NAMCOS2_MCU_DIAL_DEFAULT  /* 63B05Z0 - $3000 */
INPUT_PORTS_END

static INPUT_PORTS_START( finalap3 )
	PORT_START("MCUB")		/* 63B05Z0 - PORT B */
	PORT_DIPNAME( 0x01, 0x01, "PortB 0x01")
	PORT_DIPSETTING(	0x01, "H" )
	PORT_DIPSETTING(	0x00, "L" )
	PORT_DIPNAME( 0x02, 0x02, "Car Type(A)")
	PORT_DIPSETTING(	0x02, "McLaren/Williams" )
	PORT_DIPSETTING(	0x00, "Lotus/March" )
	PORT_BIT( 0xfc, IP_ACTIVE_LOW, IPT_UNKNOWN )

	PORT_START("MCUC")		/* 63B05Z0 - PORT C & SCI */
	PORT_BIT( 0x0f, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_COIN2 )
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_COIN1 )
	PORT_SERVICE(0x40, IP_ACTIVE_LOW)
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_SERVICE1 )

	PORT_START("AN0")		/* 63B05Z0 - 8 CHANNEL ANALOG - CHANNEL 0 */
	PORT_BIT( 0xff, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_START("AN1")		/* 63B05Z0 - 8 CHANNEL ANALOG - CHANNEL 1 */
	PORT_BIT( 0xff, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_START("AN2")		/* 63B05Z0 - 8 CHANNEL ANALOG - CHANNEL 2 */
	PORT_BIT( 0xff, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_START("AN3")		/* 63B05Z0 - 8 CHANNEL ANALOG - CHANNEL 3 */
	PORT_BIT( 0xff, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_START("AN4")		/* 63B05Z0 - 8 CHANNEL ANALOG - CHANNEL 4 */
	PORT_BIT( 0xff, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_START("AN5")		/* Steering Wheel */		/* sensitivity, delta, min, max */
	PORT_BIT( 0xff, 0x80, IPT_PADDLE ) PORT_SENSITIVITY(50) PORT_KEYDELTA(10)
	PORT_START("AN6")		/* Brake Pedal */
	PORT_BIT( 0xff, 0x00, IPT_PEDAL2 ) PORT_SENSITIVITY(100) PORT_KEYDELTA(30)
	PORT_START("AN7")		/* Accelerator Pedal */
	PORT_BIT( 0xff, 0x00, IPT_PEDAL ) PORT_SENSITIVITY(100) PORT_KEYDELTA(15)

	PORT_START("MCUH")		/* 63B05Z0 - PORT H */
	PORT_DIPNAME( 0x01, 0x01, "PortH 0x01")
	PORT_DIPSETTING(	0x01, "H" )
	PORT_DIPSETTING(	0x00, "L" )
	PORT_DIPNAME( 0x02, 0x02, "Automatic Car Select")
	PORT_DIPSETTING(	0x02, DEF_STR(No) )
	PORT_DIPSETTING(	0x00, DEF_STR(Yes) )
	PORT_DIPNAME( 0x04, 0x04, "PortH 0x04")
	PORT_DIPSETTING(	0x04, "H" )
	PORT_DIPSETTING(	0x00, "L" )
	PORT_DIPNAME( 0x08, 0x08, "Enable Onscreen Diagnostics")
	PORT_DIPSETTING(	0x08, DEF_STR(No) )
	PORT_DIPSETTING(	0x00, DEF_STR(Yes) )
	PORT_DIPNAME( 0x10, 0x10, "PortH 0x10")
	PORT_DIPSETTING(	0x10, "H" )
	PORT_DIPSETTING(	0x00, "L" )
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_TOGGLE PORT_NAME("Shift Gear")/* Gear Shift */
	PORT_DIPNAME( 0x40, 0x40, "PortH 0x40")
	PORT_DIPSETTING(	0x40, "H" )
	PORT_DIPSETTING(	0x00, "L" )
	PORT_DIPNAME( 0x80, 0x80, "Car Type(B)")
	PORT_DIPSETTING(	0x00, "McLaren/March" )
	PORT_DIPSETTING(	0x80, "Williams/Lotus" )

	NAMCOS2_MCU_DIPSW_DEFAULT /* 63B05Z0 - $2000 DIP SW */

	NAMCOS2_MCU_DIAL_DEFAULT  /* 63B05Z0 - $3000 */
INPUT_PORTS_END

static INPUT_PORTS_START( fourtrax )
	PORT_START("MCUB")		/* 63B05Z0 - PORT B */
	PORT_DIPNAME( 0x01, 0x01, "PortB 0x01")
	PORT_DIPSETTING(	0x01, "H" )
	PORT_DIPSETTING(	0x00, "L" )
	PORT_DIPNAME( 0x02, 0x02, "PortB 0x02")
	PORT_DIPSETTING(	0x02, "H" )
	PORT_DIPSETTING(	0x00, "L" )
	PORT_DIPNAME( 0x04, 0x04, "PortB 0x04")
	PORT_DIPSETTING(	0x04, "H" )
	PORT_DIPSETTING(	0x00, "L" )
	PORT_DIPNAME( 0x08, 0x08, "PortB 0x08")
	PORT_DIPSETTING(	0x08, "H" )
	PORT_DIPSETTING(	0x00, "L" )
	PORT_DIPNAME( 0x10, 0x10, "PortB 0x10")
	PORT_DIPSETTING(	0x10, "H" )
	PORT_DIPSETTING(	0x00, "L" )
	PORT_DIPNAME( 0x20, 0x20, "PortB 0x20")
	PORT_DIPSETTING(	0x20, "H" )
	PORT_DIPSETTING(	0x00, "L" )
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_START2 )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_START1 )

	PORT_START("MCUC")		/* 63B05Z0 - PORT C & SCI */
	PORT_DIPNAME( 0x01, 0x01, "PortC 0x01")
	PORT_DIPSETTING(	0x01, "H" )
	PORT_DIPSETTING(	0x00, "L" )
	PORT_DIPNAME( 0x02, 0x02, "PortC 0x02")
	PORT_DIPSETTING(	0x02, "H" )
	PORT_DIPSETTING(	0x00, "L" )
	PORT_DIPNAME( 0x04, 0x04, "PortC 0x04")
	PORT_DIPSETTING(	0x04, "H" )
	PORT_DIPSETTING(	0x00, "L" )
	PORT_DIPNAME( 0x08, 0x08, "PortC 0x08")
	PORT_DIPSETTING(	0x08, "H" )
	PORT_DIPSETTING(	0x00, "L" )
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_COIN2 )
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_COIN1 )
	PORT_BIT(0x40, IP_ACTIVE_LOW, IPT_SERVICE ) PORT_NAME("Service Button") PORT_CODE(KEYCODE_0)
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_SERVICE1 )

	PORT_START("AN0")		/* 63B05Z0 - 8 CHANNEL ANALOG - CHANNEL 0 2 */
	PORT_BIT( 0xff, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_START("AN1")		/* 63B05Z0 - 8 CHANNEL ANALOG - CHANNEL 1 3 */
	PORT_BIT( 0xff, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_START("AN2")		/* 63B05Z0 - 8 CHANNEL ANALOG - CHANNEL 2 4 */
	PORT_BIT( 0xff, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_START("AN3")		/* 63B05Z0 - 8 CHANNEL ANALOG - CHANNEL 3 5 */
	PORT_BIT( 0xff, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_START("AN4")		/* 63B05Z0 - 8 CHANNEL ANALOG - CHANNEL 4 6 */
	PORT_BIT( 0xff, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_START("AN5")		/* Steering Wheel 7 */		/* sensitivity, delta, min, max */
	PORT_BIT( 0xff, 0x80, IPT_PADDLE ) PORT_SENSITIVITY(75) PORT_KEYDELTA(50)
	PORT_START("AN6")		/* Brake Pedal 8 */
	PORT_BIT( 0xff, 0x00, IPT_PEDAL2 ) PORT_SENSITIVITY(100) PORT_KEYDELTA(30)
	PORT_START("AN7")		/* Accelerator Pedal 9 */
	PORT_BIT( 0xff, 0x00, IPT_PEDAL ) PORT_SENSITIVITY(100) PORT_KEYDELTA(15)

	PORT_START("MCUH")		/* 63B05Z0 - PORT H */
	PORT_DIPNAME( 0x01, 0x01, "PortH 0x01")
	PORT_DIPSETTING(	0x01, "H" )
	PORT_DIPSETTING(	0x00, "L" )
	PORT_DIPNAME( 0x02, 0x02, "PortH 0x02")
	PORT_DIPSETTING(	0x02, "H" )
	PORT_DIPSETTING(	0x00, "L" )
	PORT_DIPNAME( 0x04, 0x04, "PortH 0x04")
	PORT_DIPSETTING(	0x04, "H" )
	PORT_DIPSETTING(	0x00, "L" )
	PORT_DIPNAME( 0x08, 0x08, "PortH 0x08 (onscreen diagnostics)")
	PORT_DIPSETTING(	0x08, "H" )
	PORT_DIPSETTING(	0x00, "L" )
	PORT_DIPNAME( 0x10, 0x10, "PortH 0x10")
	PORT_DIPSETTING(	0x10, "H" )
	PORT_DIPSETTING(	0x00, "L" )
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_TOGGLE
	PORT_DIPNAME( 0x40, 0x40, "PortH 0x40")
	PORT_DIPSETTING(	0x40, "H" )
	PORT_DIPSETTING(	0x00, "L" )
	PORT_DIPNAME( 0x80, 0x80, "PortH 0x80")
	PORT_DIPSETTING(	0x80, "H" )
	PORT_DIPSETTING(	0x00, "L" )

	NAMCOS2_MCU_DIPSW_DEFAULT
	NAMCOS2_MCU_DIAL_DEFAULT
INPUT_PORTS_END

static INPUT_PORTS_START( assault )
	PORT_START("MCUB")		/* 63B05Z0 - PORT B */
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_JOYSTICKLEFT_LEFT ) PORT_PLAYER(2)
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_JOYSTICKLEFT_LEFT )
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_JOYSTICKLEFT_DOWN ) PORT_PLAYER(2)
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_JOYSTICKLEFT_DOWN )
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_JOYSTICKLEFT_UP ) PORT_PLAYER(2)
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_JOYSTICKLEFT_UP )
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_START2 )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_START1 )

	NAMCOS2_MCU_PORT_C_DEFAULT
	NAMCOS2_MCU_ANALOG_PORT_DEFAULT

	PORT_START("MCUH")		/* 63B05Z0 - PORT H */
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_JOYSTICKRIGHT_DOWN ) PORT_PLAYER(2)
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_JOYSTICKRIGHT_DOWN )
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_JOYSTICKRIGHT_UP ) PORT_PLAYER(2)
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_JOYSTICKRIGHT_UP )
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_PLAYER(2)
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_BUTTON1 )
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_JOYSTICKLEFT_RIGHT ) PORT_PLAYER(2)
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_JOYSTICKLEFT_RIGHT )

	NAMCOS2_MCU_DIPSW_DEFAULT

	/* These are tagged this way to make easier reads by tag */
	PORT_START("MCUDI0")	/* 63B05Z0 - $3000 */
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_JOYSTICKRIGHT_RIGHT ) PORT_PLAYER(2)
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_JOYSTICKRIGHT_RIGHT )
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_JOYSTICKRIGHT_LEFT ) PORT_PLAYER(2)
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_JOYSTICKRIGHT_LEFT )
	PORT_START("MCUDI1")	/* 63B05Z0 - $3001 */
	PORT_BIT( 0xff, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_START("MCUDI2")	/* 63B05Z0 - $3002 */
	PORT_BIT( 0xff, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_START("MCUDI3")	/* 63B05Z0 - $3003 */
	PORT_BIT( 0xff, IP_ACTIVE_LOW, IPT_UNUSED )
INPUT_PORTS_END

static INPUT_PORTS_START( suzuka )
	PORT_START("MCUB")		/* 63B05Z0 - PORT B */
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_START2 )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_START1 )

	NAMCOS2_MCU_PORT_C_DEFAULT

	PORT_START("AN0")		/* 63B05Z0 - 8 CHANNEL ANALOG - CHANNEL 0 */
	PORT_BIT( 0xff, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_START("AN1")		/* 63B05Z0 - 8 CHANNEL ANALOG - CHANNEL 1 */
	PORT_BIT( 0xff, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_START("AN2")		/* 63B05Z0 - 8 CHANNEL ANALOG - CHANNEL 2 */
	PORT_BIT( 0xff, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_START("AN3")		/* 63B05Z0 - 8 CHANNEL ANALOG - CHANNEL 3 */
	PORT_BIT( 0xff, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_START("AN4")		/* 63B05Z0 - 8 CHANNEL ANALOG - CHANNEL 4 */
	PORT_BIT( 0xff, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_START("AN5") /* Steering Wheel */
	PORT_BIT( 0xff, 0x80, IPT_PADDLE ) PORT_SENSITIVITY(50) PORT_KEYDELTA(100)
	PORT_START("AN6")		/* Brake pedal */
	PORT_BIT( 0xff, 0x00, IPT_PEDAL2 ) PORT_MINMAX(0x00,0x7f) PORT_SENSITIVITY(100) PORT_KEYDELTA(30)
	PORT_START("AN7")		/* Accelerator pedal */
	PORT_BIT( 0xff, 0x00, IPT_PEDAL ) PORT_SENSITIVITY(100) PORT_KEYDELTA(15)

	PORT_START("MCUH")		/* 63B05Z0 - PORT H */
	PORT_BIT( 0xff, IP_ACTIVE_LOW, IPT_UNKNOWN )

	PORT_START("DSW")		/* 63B05Z0 - $2000 DIP SW */
	PORT_DIPNAME( 0x01, 0x01, "Video Display")
	PORT_DIPSETTING(	0x01, DEF_STR( Normal ) )
	PORT_DIPSETTING(	0x00, "Frozen" )
	PORT_DIPNAME( 0x02, 0x02, "$2000-1")
	PORT_DIPSETTING(	0x02, "H" )
	PORT_DIPSETTING(	0x00, "L" )
	PORT_DIPNAME( 0x04, 0x04, "$2000-2")
	PORT_DIPSETTING(	0x04, "H" )
	PORT_DIPSETTING(	0x00, "L" )
	PORT_DIPNAME( 0x08, 0x08, "$2000-3")
	PORT_DIPSETTING(	0x08, "H" )
	PORT_DIPSETTING(	0x00, "L" )
	PORT_DIPNAME( 0x10, 0x10, "$2000-4")
	PORT_DIPSETTING(	0x10, "H" )
	PORT_DIPSETTING(	0x00, "L" )
	PORT_DIPNAME( 0x20, 0x20, "$2000-5")
	PORT_DIPSETTING(	0x20, "H" )
	PORT_DIPSETTING(	0x00, "L" )
	PORT_DIPNAME( 0x40, 0x40, "System is Status Monitor")
	PORT_DIPSETTING(	0x40, DEF_STR( No ) )
	PORT_DIPSETTING(	0x00, DEF_STR( Yes ) )
	PORT_SERVICE( 0x80, IP_ACTIVE_LOW )

	NAMCOS2_MCU_DIAL_DEFAULT
INPUT_PORTS_END

/* note, even with perfectly calibrated gun settings the on-screen cursor won't align with the MAME cursor
   because the game assumes the screen space isn't a linear mapping to the gun.  This is especially noticeable
   with the P2 cursor.  You should turn off the MAME cursor using the 'Crosshair Options' in the MAME internal
   TAB menu.

   This game has a rather unique control setup, 2 lightguns, plus steering hardware.  Defaults have been set
   up to avoid a large number of duplicae buttons.  Using these settings (with -mouse) the following mapping is
   given

     Z, X - Steer Car
     Ctrl - Accelerate
     Alt - Brake
     Mouse - Aim Gun
     Left Shift - Fire Gun
 */

static INPUT_PORTS_START( luckywld )
	PORT_START("MCUB")		/* 63B05Z0 - PORT B */
	PORT_BIT( 0x3f, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_START2 )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_START1 )

	NAMCOS2_MCU_PORT_C_DEFAULT

	PORT_START("AN0")		/* 63B05Z0 - 8 CHANNEL ANALOG - CHANNEL 0 */
	PORT_BIT( 0xff, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_START("AN1")
	PORT_BIT( 0xff, 0x80, IPT_LIGHTGUN_Y ) PORT_CROSSHAIR(Y, 1.0, 0.0, 0) PORT_SENSITIVITY(50) PORT_KEYDELTA(8) PORT_PLAYER(2)
	PORT_START("AN2")
	PORT_BIT( 0xff, 0x80, IPT_LIGHTGUN_Y ) PORT_CROSSHAIR(Y, 1.0, 0.0, 0) PORT_SENSITIVITY(50) PORT_KEYDELTA(8)
	PORT_START("AN3")
	PORT_BIT( 0xff, 0x80, IPT_LIGHTGUN_X ) PORT_CROSSHAIR(X, 1.0, 0.0, 0) PORT_SENSITIVITY(50) PORT_KEYDELTA(8) PORT_PLAYER(2)
	PORT_START("AN4")
	PORT_BIT( 0xff, 0x80, IPT_LIGHTGUN_X ) PORT_CROSSHAIR(X, 1.0, 0.0, 0) PORT_SENSITIVITY(50) PORT_KEYDELTA(8)
	PORT_START("AN5")		/* Steering Wheel */
	PORT_BIT( 0xff, 0x80, IPT_PADDLE ) PORT_SENSITIVITY(100) PORT_KEYDELTA(20) PORT_CODE(0) PORT_CODE_DEC(KEYCODE_Z) PORT_CODE_INC(KEYCODE_X)
	PORT_START("AN6")		/* Brake pedal */
	PORT_BIT( 0xff, 0x00, IPT_PEDAL2 ) PORT_MINMAX(0x00,0x7f) PORT_SENSITIVITY(100) PORT_KEYDELTA(30)
	PORT_START("AN7")		/* Accelerator pedal */
	PORT_BIT( 0xff, 0x00, IPT_PEDAL ) PORT_MINMAX(0x00,0x7f) PORT_SENSITIVITY(100) PORT_KEYDELTA(15)

	PORT_START("MCUH")		/* 63B05Z0 - PORT H */
	PORT_BIT( 0x0f, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_NAME("P2 Fire") PORT_CODE(KEYCODE_RSHIFT) PORT_PLAYER(2)
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_NAME("P1 Fire") PORT_CODE(KEYCODE_LSHIFT)
	PORT_BIT( 0xc0, IP_ACTIVE_LOW, IPT_UNUSED )

	NAMCOS2_MCU_DIPSW_DEFAULT
	NAMCOS2_MCU_DIAL_DEFAULT
INPUT_PORTS_END

static INPUT_PORTS_START( sgunner )
	PORT_START("MCUB")		/* 63B05Z0 - PORT B */
	PORT_BIT( 0x3f, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_START2 )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_START1 )

	NAMCOS2_MCU_PORT_C_DEFAULT

	PORT_START("AN0")		/* 63B05Z0 - 8 CHANNEL ANALOG - CHANNEL 0 */
	PORT_BIT( 0xff, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_START("AN1")
	PORT_BIT( 0xff, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_START("AN2")
	PORT_BIT( 0xff, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_START("AN3")
	PORT_BIT( 0xff, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_START("AN4")
	PORT_BIT( 0xff, 0x80, IPT_LIGHTGUN_X ) PORT_CROSSHAIR(X, 1.0, 0.0, 0) PORT_SENSITIVITY(50) PORT_KEYDELTA(8)
	PORT_START("AN5")
	PORT_BIT( 0xff, 0x80, IPT_LIGHTGUN_X ) PORT_CROSSHAIR(X, 1.0, 0.0, 0) PORT_SENSITIVITY(50) PORT_KEYDELTA(8) PORT_PLAYER(2)
	PORT_START("AN6")
	PORT_BIT( 0xff, 0x80, IPT_LIGHTGUN_Y ) PORT_CROSSHAIR(Y, 1.0, 0.0, 0) PORT_SENSITIVITY(50) PORT_KEYDELTA(8)
	PORT_START("AN7")
	PORT_BIT( 0xff, 0x80, IPT_LIGHTGUN_Y ) PORT_CROSSHAIR(Y, 1.0, 0.0, 0) PORT_SENSITIVITY(50) PORT_KEYDELTA(8) PORT_PLAYER(2)

	PORT_START("MCUH")		/* 63B05Z0 - PORT H */
	PORT_BIT( 0x03, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_BUTTON2 ) PORT_PLAYER(2)
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_BUTTON2 )
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_PLAYER(2)
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_BUTTON1 )
	PORT_BIT( 0xc0, IP_ACTIVE_LOW, IPT_UNUSED )

	NAMCOS2_MCU_DIPSW_DEFAULT
	NAMCOS2_MCU_DIAL_DEFAULT
INPUT_PORTS_END

static INPUT_PORTS_START( dirtfox )
	PORT_START("MCUB")		/* 63B05Z0 - PORT B */
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_JOYSTICK_UP ) PORT_NAME("Gear Shift Up")	/* Gear shift up */
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN )	PORT_NAME("Gear Shift Down")/* Gear shift down */

	NAMCOS2_MCU_PORT_C_DEFAULT

	PORT_START("AN0")		/* 63B05Z0 - 8 CHANNEL ANALOG - CHANNEL 0 */
	PORT_BIT( 0xff, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_START("AN1")		/* 63B05Z0 - 8 CHANNEL ANALOG - CHANNEL 1 */
	PORT_BIT( 0xff, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_START("AN2")		/* 63B05Z0 - 8 CHANNEL ANALOG - CHANNEL 2 */
	PORT_BIT( 0xff, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_START("AN3")		/* 63B05Z0 - 8 CHANNEL ANALOG - CHANNEL 3 */
	PORT_BIT( 0xff, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_START("AN4")		/* 63B05Z0 - 8 CHANNEL ANALOG - CHANNEL 4 */
	PORT_BIT( 0xff, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_START("AN5")		/* Steering Wheel */
	PORT_BIT( 0xff,  0x80, IPT_PADDLE ) PORT_SENSITIVITY(70) PORT_KEYDELTA(50)
	PORT_START("AN6")		/* Brake pedal */
	PORT_BIT( 0xff, 0x00, IPT_PEDAL2 ) PORT_MINMAX(0x00,0x7f) PORT_SENSITIVITY(100) PORT_KEYDELTA(30)
	PORT_START("AN7")		/* Accelerator pedal */
	PORT_BIT( 0xff, 0x00, IPT_PEDAL ) PORT_MINMAX(0x00,0x7f) PORT_SENSITIVITY(100) PORT_KEYDELTA(15)

	PORT_START("MCUH")		/* 63B05Z0 - PORT H */
	PORT_BIT( 0xff, IP_ACTIVE_LOW, IPT_UNUSED )

	NAMCOS2_MCU_DIPSW_DEFAULT
	NAMCOS2_MCU_DIAL_DEFAULT
INPUT_PORTS_END

static INPUT_PORTS_START( metlhawk )
	PORT_START("MCUB")		/* 63B05Z0 - PORT B */
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_START2 )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_START1 )

	NAMCOS2_MCU_PORT_C_DEFAULT

	PORT_START("AN0")		/* 63B05Z0 - 8 CHANNEL ANALOG - CHANNEL 0 */
	PORT_BIT( 0xff, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_START("AN1")		/* 63B05Z0 - 8 CHANNEL ANALOG - CHANNEL 1 */
	PORT_BIT( 0xff, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_START("AN2")		/* 63B05Z0 - 8 CHANNEL ANALOG - CHANNEL 2 */
	PORT_BIT( 0xff, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_START("AN3")		/* 63B05Z0 - 8 CHANNEL ANALOG - CHANNEL 3 */
	PORT_BIT( 0xff, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_START("AN4")		/* 63B05Z0 - 8 CHANNEL ANALOG - CHANNEL 4 */
	PORT_BIT( 0xff, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_START("AN5")		/* Joystick Y */
	PORT_BIT( 0xff, 0x80, IPT_AD_STICK_Y ) PORT_MINMAX(0x20,0xe0) PORT_SENSITIVITY(100) PORT_KEYDELTA(16)
	PORT_START("AN6")		/* Joystick X */
	PORT_BIT( 0xff, 0x80, IPT_AD_STICK_X ) PORT_MINMAX(0x20,0xe0) PORT_SENSITIVITY(100) PORT_KEYDELTA(16)
	PORT_START("AN7")		/* Lever */
	PORT_BIT( 0xff, 0x80, IPT_AD_STICK_Y ) PORT_MINMAX(0x20,0xe0) PORT_SENSITIVITY(100) PORT_KEYDELTA(16) PORT_REVERSE PORT_PLAYER(2)

	PORT_START("MCUH")		/* 63B05Z0 - PORT H */
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_BUTTON1 )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_BUTTON2 )

	NAMCOS2_MCU_DIPSW_DEFAULT
	NAMCOS2_MCU_DIAL_DEFAULT
INPUT_PORTS_END


/* Based on the dumped BIOS versions it looks like Namco changed the BIOS rom */
/* from sys2c65b to sys2c65c sometime between 1988 and 1990 as mirai ninja    */
/* and metal hawk have the B version and dragon saber has the C version       */

/*    YEAR, NAME,     PARENT,   MACHINE,  INPUT,    INIT,     MONITOR, COMPANY, FULLNAME */
GAMEL(1987, finallap,  0,        finallap, finallap, finallap, ROT0,   "Namco", "Final Lap (Rev E)", GAME_IMPERFECT_GRAPHICS | GAME_IMPERFECT_SOUND, layout_finallap )
GAMEL(1987, finallapd, finallap, finallap, finallap, finallap, ROT0,   "Namco", "Final Lap (Rev D)", GAME_IMPERFECT_GRAPHICS | GAME_IMPERFECT_SOUND, layout_finallap )
GAMEL(1987, finallapc, finallap, finallap, finallap, finallap, ROT0,   "Namco", "Final Lap (Rev C)", GAME_IMPERFECT_GRAPHICS | GAME_IMPERFECT_SOUND, layout_finallap )
GAMEL(1987, finallapjc,finallap, finallap, finallap, finallap, ROT0,   "Namco", "Final Lap (Japan - Rev C)", GAME_IMPERFECT_GRAPHICS | GAME_IMPERFECT_SOUND, layout_finallap )
GAMEL(1987, finallapjb,finallap, finallap, finallap, finallap, ROT0,   "Namco", "Final Lap (Japan - Rev B)", GAME_IMPERFECT_GRAPHICS | GAME_IMPERFECT_SOUND, layout_finallap )

GAME( 1988, assault,   0,        default2, assault,  assault ,      ROT90, "Namco", "Assault" , 0)
GAME( 1988, assaultj,  assault,  default2, assault,  assaultj,      ROT90, "Namco", "Assault (Japan)" , 0)
GAME( 1988, assaultp,  assault,  assaultp, assault,  assaultp_hack, ROT90, "Namco", "Assault Plus (Japan)" , 0)

GAME( 1988, metlhawk,  0,        metlhawk, metlhawk, metlhawk, ROT90,  "Namco", "Metal Hawk", 0)
GAME( 1988, metlhawkj, metlhawk, metlhawk, metlhawk, metlhawk, ROT90,  "Namco", "Metal Hawk (Japan)", 0)

GAME( 1988, ordyne,    0,        default,  default,  ordyne,   ROT180, "Namco", "Ordyne (Japan, English Version)", 0 )
GAME( 1988, ordynej,   ordyne,   default,  default,  ordyne,   ROT180, "Namco", "Ordyne (Japan)", 0 )

GAME( 1988, mirninja,  0,        default,  default,  mirninja, ROT0,   "Namco", "Mirai Ninja (Japan)", 0 )

GAME( 1988, phelios,   0,        default2, default,  phelios , ROT90,  "Namco", "Phelios (Japan)" , 0)

GAME( 1989, dirtfoxj,  0,        default2, dirtfox,  dirtfoxj, ROT90,  "Namco", "Dirt Fox (Japan)" , 0 )

GAMEL(1989, fourtrax,  0,        finallap, fourtrax, fourtrax, ROT0,   "Namco", "Four Trax", GAME_IMPERFECT_GRAPHICS | GAME_IMPERFECT_SOUND, layout_finallap )

GAME( 1989, valkyrie,  0,        default3, default,  valkyrie, ROT90,  "Namco", "Valkyrie No Densetsu (Japan)", 0 )

GAME( 1989, finehour,  0,        default2, default,  finehour, ROT0,   "Namco", "Finest Hour (Japan)" , 0)

GAME( 1989, burnforc,  0,        default3, default,  burnforc, ROT0,   "Namco", "Burning Force (Japan new version)", 0 )
GAME( 1989, burnforco, burnforc, default3, default,  burnforc, ROT0,   "Namco", "Burning Force (Japan old version)", 0 )

GAME( 1989, marvland,  0,        default,  default,  marvland, ROT0,   "Namco", "Marvel Land (US)", 0 )
GAME( 1989, marvlandj, marvland, default,  default,  marvlanj, ROT0,   "Namco", "Marvel Land (Japan)", 0 )

GAME( 1990, kyukaidk,  0,        default,  kyukaidk, kyukaidk, ROT0,   "Namco", "Kyuukai Douchuuki (Japan new version)", 0 )
GAME( 1990, kyukaidko, kyukaidk, default,  kyukaidk, kyukaidk, ROT0,   "Namco", "Kyuukai Douchuuki (Japan old version)", 0 )

GAME( 1990, dsaber,    0,        default3, default,  dsaber,   ROT90,  "Namco", "Dragon Saber", 0 )
GAME( 1990, dsaberj,   dsaber,   default3, default,  dsaberj,  ROT90,  "Namco", "Dragon Saber (Japan)", 0 )

GAMEL(1990, finalap2,  0,        finallap, finallap, finalap2, ROT0,   "Namco", "Final Lap 2", GAME_IMPERFECT_GRAPHICS | GAME_IMPERFECT_SOUND, layout_finallap  )
GAMEL(1990, finalap2j, finalap2, finallap, finallap, finalap2, ROT0,   "Namco", "Final Lap 2 (Japan)", GAME_IMPERFECT_GRAPHICS | GAME_IMPERFECT_SOUND, layout_finallap  )

GAME( 1990, gollygho,  0,        gollygho, gollygho, gollygho, ROT180, "Namco", "Golly! Ghost!", 0 )

GAME( 1990, rthun2,    0,        default3, default,  rthun2,   ROT0,   "Namco", "Rolling Thunder 2", 0 )
GAME( 1990, rthun2j,   rthun2,   default3, default,  rthun2j,  ROT0,   "Namco", "Rolling Thunder 2 (Japan)", 0 )

GAME( 1990, sgunner,   0,        sgunner,  sgunner,  sgunner2, ROT0,   "Namco", "Steel Gunner", 0 )
GAME( 1990, sgunnerj,  sgunner,  sgunner,  sgunner,  sgunner2, ROT0,   "Namco", "Steel Gunner (Japan)", 0 )

GAME( 1991, sgunner2,  0,        sgunner,  sgunner,  sgunner2, ROT0,   "Namco", "Steel Gunner 2 (US)", 0 )
GAME( 1991, sgunner2j, sgunner2, sgunner,  sgunner,  sgunner2, ROT0,   "Namco", "Steel Gunner 2 (Japan)", 0 )

GAME( 1991, cosmogng,  0,        default,  default,  cosmogng, ROT90,  "Namco", "Cosmo Gang the Video (US)", 0 )
GAME( 1991, cosmogngj, cosmogng, default,  default,  cosmogng, ROT90,  "Namco", "Cosmo Gang the Video (Japan)", 0 )

GAME( 1992, bubbletr,  0,        gollygho, bubbletr, bubbletr, ROT180, "Namco", "Bubble Trouble (Japan)", GAME_IMPERFECT_GRAPHICS )	/* missing external artwork */

GAMEL(1992, finalap3,  0,        finallap, finalap3, finalap3, ROT0,   "Namco", "Final Lap 3 (World, set 1)", GAME_IMPERFECT_GRAPHICS | GAME_IMPERFECT_SOUND, layout_finallap  )
GAMEL(1992, finalap3a, finalap3, finallap, finalap3, finalap3, ROT0,   "Namco", "Final Lap 3 (World, set 2)", GAME_IMPERFECT_GRAPHICS | GAME_IMPERFECT_SOUND, layout_finallap  )
GAMEL(1992, finalap3j, finalap3, finallap, finalap3, finalap3, ROT0,   "Namco", "Final Lap 3 (Japan)", GAME_IMPERFECT_GRAPHICS | GAME_IMPERFECT_SOUND, layout_finallap  )
GAMEL(1992, finalap3jc,finalap3, finallap, finalap3, finalap3, ROT0,   "Namco", "Final Lap 3 (Japan - Rev C)", GAME_IMPERFECT_GRAPHICS | GAME_IMPERFECT_SOUND, layout_finallap  )

GAME( 1992, luckywld,  0,        luckywld, luckywld, luckywld, ROT0,   "Namco", "Lucky & Wild", 0 )
GAME( 1992, luckywldj, luckywld, luckywld, luckywld, luckywld, ROT0,   "Namco", "Lucky & Wild (Japan)", 0 )

GAME( 1992, suzuka8h,  0,        luckywld, suzuka,   suzuka8h, ROT0,   "Namco", "Suzuka 8 Hours (World)", GAME_IMPERFECT_GRAPHICS | GAME_IMPERFECT_SOUND)
GAME( 1992, suzuka8hj, suzuka8h, luckywld, suzuka,   suzuka8h, ROT0,   "Namco", "Suzuka 8 Hours (Japan)", GAME_IMPERFECT_GRAPHICS | GAME_IMPERFECT_SOUND )

GAME( 1992, sws,       0,        default,  default,  sws,      ROT0,   "Namco", "Super World Stadium (Japan)", 0 )

GAME( 1992, sws92,     0,        default,  default,  sws92,    ROT0,   "Namco", "Super World Stadium '92 (Japan)", 0 )
GAME( 1992, sws92g,    sws92,    default,  default,  sws92g,   ROT0,   "Namco", "Super World Stadium '92 Gekitouban (Japan)", 0 )

GAME( 1993, suzuk8h2,  0,        luckywld, suzuka,   suzuk8h2, ROT0,   "Namco", "Suzuka 8 Hours 2 (World)", GAME_IMPERFECT_GRAPHICS | GAME_IMPERFECT_SOUND )

GAME( 1993, sws93,     0,        default,  default,  sws93,    ROT0,   "Namco", "Super World Stadium '93 (Japan)", 0 )
