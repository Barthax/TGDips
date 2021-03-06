# MAME 0.106 source snippet

/*************************************
 *
 *  Port definitions
 *
 *************************************/

INPUT_PORTS_START( capbowl )
	PORT_START	/* IN0 */
	/* low 4 bits are for the trackball */
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_COCKTAIL
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_BUTTON2 ) PORT_COCKTAIL
	PORT_DIPNAME( 0x40, 0x40, DEF_STR( Cabinet ) ) /* This version of Bowl-O-Rama */
	PORT_DIPSETTING(    0x40, DEF_STR( Upright ) )			   /* is Upright only */
	PORT_DIPSETTING(    0x00, DEF_STR( Cocktail ) )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_COIN2 )

	PORT_START	/* IN1 */
	/* low 4 bits are for the trackball */
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_BUTTON1 )
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_BUTTON2 )
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_START1 )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_COIN1 )

	PORT_START	/* FAKE */
	PORT_BIT( 0xff, 0x00, IPT_TRACKBALL_Y ) PORT_SENSITIVITY(20) PORT_KEYDELTA(40) PORT_REVERSE

	PORT_START	/* FAKE */
	PORT_BIT( 0xff, 0x00, IPT_TRACKBALL_X ) PORT_SENSITIVITY(20) PORT_KEYDELTA(40)

	PORT_START	/* FAKE */
	/* This fake input port is used to get the status of the F2 key, */
	/* and activate the test mode, which is triggered by a NMI */
	PORT_BIT(0x01, IP_ACTIVE_HIGH, IPT_SERVICE ) PORT_NAME( DEF_STR( Service_Mode )) PORT_CODE(KEYCODE_F2)
INPUT_PORTS_END


/*************************************
 *
 *  Game drivers
 *
 *************************************/

GAME( 1988, capbowl,  0,       capbowl,  capbowl, capbowl, ROT270, "Incredible Technologies", "Capcom Bowling (set 1)", 0 )
GAME( 1988, capbowl2, capbowl, capbowl,  capbowl, capbowl, ROT270, "Incredible Technologies", "Capcom Bowling (set 2)", 0 )
GAME( 1988, capbowl3, capbowl, capbowl,  capbowl, capbowl, ROT270, "Incredible Technologies", "Capcom Bowling (set 3)", 0 )
GAME( 1988, capbowl4, capbowl, capbowl,  capbowl, capbowl, ROT270, "Incredible Technologies", "Capcom Bowling (set 4)", 0 )
GAME( 1989, clbowl,   capbowl, capbowl,  capbowl, capbowl, ROT270, "Incredible Technologies", "Coors Light Bowling", 0 )
GAME( 1991, bowlrama, 0,       bowlrama, capbowl, capbowl, ROT270, "P&P Marketing", "Bowl-O-Rama", 0 )
