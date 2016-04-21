/*************************************
 *
 *  Port definitions
 *
 *************************************/

INPUT_PORTS_START( timekill )
	PORT_START	/* 40000 */
	PORT_BIT( 0x0001, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_PLAYER(1)
	PORT_BIT( 0x0002, IP_ACTIVE_LOW, IPT_BUTTON2 ) PORT_PLAYER(1)
	PORT_BIT( 0x0004, IP_ACTIVE_LOW, IPT_BUTTON3 ) PORT_PLAYER(1)
	PORT_BIT( 0x0008, IP_ACTIVE_LOW, IPT_BUTTON4 ) PORT_PLAYER(1)
	PORT_BIT( 0x0010, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT ) PORT_PLAYER(1)
	PORT_BIT( 0x0020, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT ) PORT_PLAYER(1)
	PORT_BIT( 0x0040, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN ) PORT_PLAYER(1)
	PORT_BIT( 0x0080, IP_ACTIVE_LOW, IPT_JOYSTICK_UP ) PORT_PLAYER(1)

	PORT_START	/* 48000 */
	PORT_BIT( 0x0001, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_PLAYER(2)
	PORT_BIT( 0x0002, IP_ACTIVE_LOW, IPT_BUTTON2 ) PORT_PLAYER(2)
	PORT_BIT( 0x0004, IP_ACTIVE_LOW, IPT_BUTTON3 ) PORT_PLAYER(2)
	PORT_BIT( 0x0008, IP_ACTIVE_LOW, IPT_BUTTON4 ) PORT_PLAYER(2)
	PORT_BIT( 0x0010, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT ) PORT_PLAYER(2)
	PORT_BIT( 0x0020, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT ) PORT_PLAYER(2)
	PORT_BIT( 0x0040, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN ) PORT_PLAYER(2)
	PORT_BIT( 0x0080, IP_ACTIVE_LOW, IPT_JOYSTICK_UP ) PORT_PLAYER(2)

	PORT_START	/* 50000 */
	PORT_BIT( 0x0001, IP_ACTIVE_LOW, IPT_BUTTON5 ) PORT_PLAYER(1)
	PORT_BIT( 0x0002, IP_ACTIVE_LOW, IPT_COIN1 )
	PORT_BIT( 0x0004, IP_ACTIVE_LOW, IPT_START1 )
	PORT_BIT( 0x0008, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x0010, IP_ACTIVE_LOW, IPT_BUTTON5 ) PORT_PLAYER(2)
	PORT_BIT( 0x0020, IP_ACTIVE_LOW, IPT_COIN2 )
	PORT_BIT( 0x0040, IP_ACTIVE_LOW, IPT_START2 )
	PORT_BIT( 0x0080, IP_ACTIVE_LOW, IPT_UNUSED )

	PORT_START	/* 58000 */
	PORT_SERVICE_NO_TOGGLE( 0x0001, IP_ACTIVE_LOW )
	PORT_BIT( 0x0002, IP_ACTIVE_LOW, IPT_SERVICE1 )
	PORT_BIT( 0x0004, IP_ACTIVE_LOW, IPT_VBLANK )
	PORT_BIT( 0x0008, IP_ACTIVE_LOW, IPT_SPECIAL )
	PORT_DIPNAME( 0x0010, 0x0000, "Video Sync" )
	PORT_DIPSETTING(      0x0000, "-" )
	PORT_DIPSETTING(      0x0010, "+" )
	PORT_DIPNAME( 0x0020, 0x0000, DEF_STR( Flip_Screen ))
	PORT_DIPSETTING(      0x0000, DEF_STR( Off ))
	PORT_DIPSETTING(      0x0020, DEF_STR( On ))
	PORT_DIPNAME( 0x0040, 0x0000, "Violence" )
	PORT_DIPSETTING(      0x0040, DEF_STR( Off ))
	PORT_DIPSETTING(      0x0000, DEF_STR( On ))
	PORT_DIPNAME( 0x0080, 0x0000, DEF_STR( Service_Mode ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( Off ))
	PORT_DIPSETTING(      0x0080, DEF_STR( On ))
INPUT_PORTS_END


INPUT_PORTS_START( itech32_base )
	PORT_START_TAG("P1")	/* 080000 */
	PORT_BIT( 0x0001, IP_ACTIVE_LOW, IPT_COIN1 )
	PORT_BIT( 0x0002, IP_ACTIVE_LOW, IPT_START1 )
	PORT_BIT( 0x0004, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_PLAYER(1)
	PORT_BIT( 0x0008, IP_ACTIVE_LOW, IPT_BUTTON2 ) PORT_PLAYER(1)
	PORT_BIT( 0x0010, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT ) PORT_PLAYER(1)
	PORT_BIT( 0x0020, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT ) PORT_PLAYER(1)
	PORT_BIT( 0x0040, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN ) PORT_PLAYER(1)
	PORT_BIT( 0x0080, IP_ACTIVE_LOW, IPT_JOYSTICK_UP ) PORT_PLAYER(1)

	PORT_START_TAG("P2")	/* 100000 */
	PORT_BIT( 0x0001, IP_ACTIVE_LOW, IPT_COIN2 )
	PORT_BIT( 0x0002, IP_ACTIVE_LOW, IPT_START2 )
	PORT_BIT( 0x0004, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_PLAYER(2)
	PORT_BIT( 0x0008, IP_ACTIVE_LOW, IPT_BUTTON2 ) PORT_PLAYER(2)
	PORT_BIT( 0x0010, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT ) PORT_PLAYER(2)
	PORT_BIT( 0x0020, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT ) PORT_PLAYER(2)
	PORT_BIT( 0x0040, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN ) PORT_PLAYER(2)
	PORT_BIT( 0x0080, IP_ACTIVE_LOW, IPT_JOYSTICK_UP ) PORT_PLAYER(2)

	PORT_START_TAG("P3")	/* 180000 */
	PORT_BIT( 0x00ff, IP_ACTIVE_HIGH, IPT_UNUSED )

	PORT_START_TAG("P4")	/* 200000 */
	PORT_BIT( 0x00ff, IP_ACTIVE_LOW, IPT_UNUSED )

	PORT_START_TAG("DIPS")	/* 280000 */
	PORT_SERVICE_NO_TOGGLE( 0x0001, IP_ACTIVE_LOW )
	PORT_BIT( 0x0002, IP_ACTIVE_LOW, IPT_SERVICE1 )
	PORT_BIT( 0x0004, IP_ACTIVE_LOW, IPT_VBLANK )
	PORT_BIT( 0x0008, IP_ACTIVE_LOW, IPT_SPECIAL )
	PORT_DIPNAME( 0x0010, 0x0000, "Video Sync" )
	PORT_DIPSETTING(      0x0000, "-" )
	PORT_DIPSETTING(      0x0010, "+" )
	PORT_DIPNAME( 0x0020, 0x0000, DEF_STR( Flip_Screen ))
	PORT_DIPSETTING(      0x0000, DEF_STR( Off ))
	PORT_DIPSETTING(      0x0020, DEF_STR( On ))
	PORT_DIPNAME( 0x0040, 0x0000, DEF_STR( Unknown ))
	PORT_DIPSETTING(      0x0040, DEF_STR( Off ))
	PORT_DIPSETTING(      0x0000, DEF_STR( On ))
	PORT_DIPNAME( 0x0080, 0x0000, DEF_STR( Service_Mode ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( Off ))
	PORT_DIPSETTING(      0x0080, DEF_STR( On ))

	PORT_START_TAG("EXTRA")	/* 78000 */
	PORT_BIT( 0x00ff, IP_ACTIVE_LOW, IPT_UNUSED )
INPUT_PORTS_END


INPUT_PORTS_START( bloodstm )
	PORT_INCLUDE(itech32_base)

	PORT_MODIFY("P1")
	PORT_BIT( 0x0008, IP_ACTIVE_LOW, IPT_BUTTON3 ) PORT_PLAYER(1)

	PORT_MODIFY("P2")
	PORT_BIT( 0x0008, IP_ACTIVE_LOW, IPT_BUTTON3 ) PORT_PLAYER(2)

	PORT_MODIFY("DIPS")
	PORT_DIPNAME( 0x0040, 0x0000, "Violence" )
	PORT_DIPSETTING(      0x0040, DEF_STR( Off ))
	PORT_DIPSETTING(      0x0000, DEF_STR( On ))

	PORT_MODIFY("EXTRA")
	PORT_BIT( 0x0001, IP_ACTIVE_LOW, IPT_BUTTON2 ) PORT_PLAYER(1)
	PORT_BIT( 0x0002, IP_ACTIVE_LOW, IPT_BUTTON2 ) PORT_PLAYER(2)
	PORT_BIT( 0x0004, IP_ACTIVE_LOW, IPT_BUTTON4 ) PORT_PLAYER(1)
	PORT_BIT( 0x0008, IP_ACTIVE_LOW, IPT_BUTTON4 ) PORT_PLAYER(2)
	PORT_BIT( 0x0010, IP_ACTIVE_LOW, IPT_BUTTON5 ) PORT_PLAYER(1)
	PORT_BIT( 0x0020, IP_ACTIVE_LOW, IPT_BUTTON5 ) PORT_PLAYER(2)
	PORT_BIT( 0x00c0, IP_ACTIVE_LOW, IPT_UNUSED )
INPUT_PORTS_END


INPUT_PORTS_START( hardyard )
	PORT_INCLUDE(itech32_base)

	PORT_MODIFY("P3")
	PORT_BIT( 0x0001, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x0002, IP_ACTIVE_LOW, IPT_START3 )
	PORT_BIT( 0x0004, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_PLAYER(3)
	PORT_BIT( 0x0008, IP_ACTIVE_LOW, IPT_BUTTON2 ) PORT_PLAYER(3)
	PORT_BIT( 0x0010, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT ) PORT_PLAYER(3)
	PORT_BIT( 0x0020, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT ) PORT_PLAYER(3)
	PORT_BIT( 0x0040, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN ) PORT_PLAYER(3)
	PORT_BIT( 0x0080, IP_ACTIVE_LOW, IPT_JOYSTICK_UP ) PORT_PLAYER(3)

	PORT_MODIFY("P4")
	PORT_BIT( 0x0001, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x0002, IP_ACTIVE_LOW, IPT_START4 )
	PORT_BIT( 0x0004, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_PLAYER(4)
	PORT_BIT( 0x0008, IP_ACTIVE_LOW, IPT_BUTTON2 ) PORT_PLAYER(4)
	PORT_BIT( 0x0010, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT ) PORT_PLAYER(4)
	PORT_BIT( 0x0020, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT ) PORT_PLAYER(4)
	PORT_BIT( 0x0040, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN ) PORT_PLAYER(4)
	PORT_BIT( 0x0080, IP_ACTIVE_LOW, IPT_JOYSTICK_UP ) PORT_PLAYER(4)

	PORT_MODIFY("DIPS")	/* 280000 */
	PORT_DIPNAME( 0x0020, 0x0000, DEF_STR( Cabinet ))
	PORT_DIPSETTING(      0x0000, DEF_STR( Upright ))
	PORT_DIPNAME( 0x0040, 0x0000, DEF_STR( Players ) )
	PORT_DIPSETTING(      0x0000, "4" )
	PORT_DIPSETTING(      0x0040, "2" )
INPUT_PORTS_END


INPUT_PORTS_START( pairs )
	PORT_INCLUDE(itech32_base)

	PORT_MODIFY("P1")
	PORT_BIT( 0x0008, IP_ACTIVE_LOW, IPT_UNUSED )

	PORT_MODIFY("P2")
	PORT_BIT( 0x0008, IP_ACTIVE_LOW, IPT_UNUSED )

	PORT_MODIFY("DIPS")
	PORT_DIPNAME( 0x0040, 0x0000, "Modesty" )
	PORT_DIPSETTING(      0x0000, DEF_STR( Off ))
	PORT_DIPSETTING(      0x0040, DEF_STR( On ))
INPUT_PORTS_END


INPUT_PORTS_START( drivedge )
	PORT_START	/* 8C000 */
	PORT_BIT ( 0x0001, IP_ACTIVE_LOW, IPT_COIN1 )
	PORT_BIT ( 0x0002, IP_ACTIVE_LOW, IPT_COIN2 )
	PORT_BIT( 0x0004, IP_ACTIVE_LOW, IPT_BUTTON7 ) PORT_NAME("Gear 1") PORT_CODE(KEYCODE_Z) PORT_PLAYER(1)
	PORT_BIT( 0x0008, IP_ACTIVE_LOW, IPT_BUTTON8 ) PORT_NAME("Gear 2") PORT_CODE(KEYCODE_X) PORT_PLAYER(1)
	PORT_BIT( 0x0010, IP_ACTIVE_LOW, IPT_BUTTON9 ) PORT_NAME("Gear 3") PORT_CODE(KEYCODE_C) PORT_PLAYER(1)
	PORT_BIT( 0x0020, IP_ACTIVE_LOW, IPT_BUTTON10 ) PORT_NAME("Gear 4") PORT_CODE(KEYCODE_V) PORT_PLAYER(1)
	PORT_SERVICE_NO_TOGGLE( 0x0040, IP_ACTIVE_LOW )
	PORT_BIT ( 0x0080, IP_ACTIVE_LOW, IPT_UNUSED )

	PORT_START	/* 8E000 */
	PORT_BIT( 0x0001, IP_ACTIVE_LOW, IPT_BUTTON3 ) PORT_NAME("Fan") PORT_CODE(KEYCODE_F) PORT_PLAYER(1)
	PORT_BIT( 0x0002, IP_ACTIVE_LOW, IPT_BUTTON4 ) PORT_NAME("Tow Truck") PORT_CODE(KEYCODE_T) PORT_PLAYER(1)
	PORT_BIT( 0x0004, IP_ACTIVE_LOW, IPT_BUTTON5 ) PORT_NAME("Horn") PORT_CODE(KEYCODE_SPACE) PORT_PLAYER(1)
	PORT_BIT( 0x0008, IP_ACTIVE_LOW, IPT_BUTTON2 ) PORT_NAME("Turbo Boost") PORT_CODE(KEYCODE_B) PORT_PLAYER(1)
	PORT_BIT( 0x0010, IP_ACTIVE_LOW, IPT_BUTTON6 ) PORT_NAME("Network On") PORT_CODE(KEYCODE_N) PORT_PLAYER(1)
	PORT_BIT( 0x0020, IP_ACTIVE_LOW, IPT_START1 ) PORT_NAME("Key")
	PORT_BIT ( 0x0040, IP_ACTIVE_LOW, IPT_SERVICE1 )
	PORT_BIT ( 0x0080, IP_ACTIVE_LOW, IPT_UNUSED )

	PORT_START	/* 200000 */
	PORT_SERVICE_NO_TOGGLE( 0x0100, IP_ACTIVE_LOW )
	PORT_BIT( 0x0200, IP_ACTIVE_LOW, IPT_COIN3 )
	PORT_BIT( 0x0400, IP_ACTIVE_LOW, IPT_VBLANK )
	PORT_BIT( 0x0800, IP_ACTIVE_LOW, IPT_SPECIAL )
	PORT_DIPNAME( 0x7000, 0x0000, "Network Number" )
	PORT_DIPSETTING(      0x0000, "1" )
	PORT_DIPSETTING(      0x1000, "2" )
	PORT_DIPSETTING(      0x2000, "3" )
	PORT_DIPSETTING(      0x3000, "4" )
	PORT_DIPSETTING(      0x4000, "5" )
	PORT_DIPSETTING(      0x5000, "6" )
	PORT_DIPSETTING(      0x6000, "7" )
	PORT_DIPSETTING(      0x7000, "8" )
	PORT_DIPNAME( 0x8000, 0x0000, DEF_STR( Service_Mode ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x8000, DEF_STR( On ) )

	PORT_START	/* 80000 */
	PORT_BIT( 0xff, 0x00, IPT_PEDAL ) PORT_MINMAX(0x00,0x06) PORT_SENSITIVITY(2) PORT_KEYDELTA(100) PORT_PLAYER(3)

	PORT_START	/* 82000 */
	PORT_BIT( 0xff, 0x00, IPT_PEDAL ) PORT_MINMAX(0x00,0x06) PORT_SENSITIVITY(2) PORT_KEYDELTA(40) PORT_PLAYER(2)

	PORT_START	/* 88000 */
	PORT_BIT( 0xff, 0x80, IPT_PADDLE ) PORT_MINMAX(0x10,0xf0) PORT_SENSITIVITY(25) PORT_KEYDELTA(5)

	PORT_START	/* 8A000 */
	PORT_BIT( 0xff, 0x00, IPT_PEDAL ) PORT_MINMAX(0x00,0x0c) PORT_SENSITIVITY(1) PORT_KEYDELTA(20) PORT_PLAYER(1)
INPUT_PORTS_END


INPUT_PORTS_START( wcbowl )
	PORT_INCLUDE(itech32_base)

	PORT_MODIFY("P1")
	PORT_BIT( 0x00f0, IP_ACTIVE_LOW, IPT_UNUSED )

	PORT_MODIFY("P2")
	PORT_BIT( 0x00f0, IP_ACTIVE_LOW, IPT_UNUSED )

	PORT_START_TAG("TRACKX1")
    PORT_BIT( 0xff, 0x00, IPT_TRACKBALL_X ) PORT_MINMAX(0,255) PORT_SENSITIVITY(25) PORT_KEYDELTA(32) PORT_REVERSE PORT_PLAYER(1)

	PORT_START_TAG("TRACKY1")
    PORT_BIT( 0xff, 0x00, IPT_TRACKBALL_Y ) PORT_MINMAX(0,255) PORT_SENSITIVITY(25) PORT_KEYDELTA(32) PORT_PLAYER(1)
INPUT_PORTS_END


INPUT_PORTS_START( wcbowln ) /* WCB version 1.66 supports cocktail mode */
	PORT_INCLUDE(wcbowl)

	PORT_MODIFY("P3")
	PORT_BIT( 0x0004, IP_ACTIVE_LOW, IPT_COIN3 )
	PORT_BIT( 0x00fb, IP_ACTIVE_LOW, IPT_UNUSED )

	PORT_MODIFY("DIPS")
	PORT_DIPNAME( 0x0010, 0x0000, DEF_STR( Unknown ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0010, DEF_STR( On ) )
	PORT_DIPNAME( 0x0020, 0x0000, DEF_STR( Cabinet ) )	// v1.66 Rom sets support Cocktail mode (verified)
	PORT_DIPSETTING(      0x0000, DEF_STR( Upright ) )
	PORT_DIPSETTING(      0x0020, DEF_STR( Cocktail ) )
	PORT_DIPNAME( 0x0040, 0x0000, "Freeze Screen" )
	PORT_DIPSETTING(      0x0000, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0040, DEF_STR( On ) )

	PORT_START_TAG("TRACKX2")
    PORT_BIT( 0xff, 0x00, IPT_TRACKBALL_X ) PORT_MINMAX(0,255) PORT_SENSITIVITY(25) PORT_KEYDELTA(32) PORT_REVERSE PORT_COCKTAIL PORT_PLAYER(2)

	PORT_START_TAG("TRACKY2")
    PORT_BIT( 0xff, 0x00, IPT_TRACKBALL_Y ) PORT_MINMAX(0,255) PORT_SENSITIVITY(25) PORT_KEYDELTA(32) PORT_COCKTAIL PORT_PLAYER(2)
INPUT_PORTS_END


INPUT_PORTS_START( wcbowldx )
	PORT_INCLUDE(wcbowln)

	PORT_START	/* 280000 */
	PORT_DIPNAME( 0x0020, 0x0000, DEF_STR( Flip_Screen ) )	/* Verified */
	PORT_DIPSETTING(      0x0000, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0020, DEF_STR( On ) )
	PORT_DIPNAME( 0x0040, 0x0000, DEF_STR( Unknown ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0040, DEF_STR( On ) )
INPUT_PORTS_END


INPUT_PORTS_START( sftm )
	PORT_INCLUDE(itech32_base)

	PORT_MODIFY("P3")
	PORT_BIT( 0x0001, IP_ACTIVE_LOW, IPT_BUTTON3 ) PORT_PLAYER(1)
	PORT_BIT( 0x0002, IP_ACTIVE_LOW, IPT_BUTTON3 ) PORT_PLAYER(2)
	PORT_BIT( 0x0004, IP_ACTIVE_LOW, IPT_BUTTON4 ) PORT_PLAYER(1)
	PORT_BIT( 0x0008, IP_ACTIVE_LOW, IPT_BUTTON4 ) PORT_PLAYER(2)
	PORT_BIT( 0x0010, IP_ACTIVE_LOW, IPT_BUTTON5 ) PORT_PLAYER(1)
	PORT_BIT( 0x0020, IP_ACTIVE_LOW, IPT_BUTTON5 ) PORT_PLAYER(2)
	PORT_BIT( 0x0040, IP_ACTIVE_LOW, IPT_BUTTON6 ) PORT_PLAYER(1)
	PORT_BIT( 0x0080, IP_ACTIVE_LOW, IPT_BUTTON6 ) PORT_PLAYER(2)

	PORT_MODIFY("DIPS")
	PORT_DIPNAME( 0x0040, 0x0000, "Freeze Screen" )
	PORT_DIPSETTING(      0x0000, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0040, DEF_STR( On ) )
INPUT_PORTS_END


INPUT_PORTS_START( shufshot ) /* ShuffleShot v1.39 & v1.40 support cocktail mode */
	PORT_INCLUDE(itech32_base)

	PORT_MODIFY("P1")
	PORT_BIT( 0x00f0, IP_ACTIVE_LOW, IPT_UNUSED )

	PORT_MODIFY("P2")
	PORT_BIT( 0x00f0, IP_ACTIVE_LOW, IPT_UNUSED )

	PORT_MODIFY("P3")
	PORT_BIT( 0x0004, IP_ACTIVE_LOW, IPT_COIN3 )
	PORT_BIT( 0x00fb, IP_ACTIVE_LOW, IPT_UNUSED )

	PORT_MODIFY("DIPS")
	PORT_DIPNAME( 0x0020, 0x0000, DEF_STR( Cabinet ) )	/* Verified */
	PORT_DIPSETTING(      0x0000, DEF_STR( Upright ) )
	PORT_DIPSETTING(      0x0020, DEF_STR( Cocktail ) )

	PORT_START_TAG("TRACKX1")
    PORT_BIT( 0xff, 0x00, IPT_TRACKBALL_X ) PORT_MINMAX(0,255) PORT_SENSITIVITY(25) PORT_KEYDELTA(32) PORT_REVERSE PORT_PLAYER(1)

	PORT_START_TAG("TRACKY1")
    PORT_BIT( 0xff, 0x00, IPT_TRACKBALL_Y ) PORT_MINMAX(0,255) PORT_SENSITIVITY(25) PORT_KEYDELTA(32) PORT_PLAYER(1)

	PORT_START_TAG("TRACKX2")
    PORT_BIT( 0xff, 0x00, IPT_TRACKBALL_X ) PORT_MINMAX(0,255) PORT_SENSITIVITY(25) PORT_KEYDELTA(32) PORT_REVERSE PORT_COCKTAIL PORT_PLAYER(2)

	PORT_START_TAG("TRACKY2")
    PORT_BIT( 0xff, 0x00, IPT_TRACKBALL_Y ) PORT_MINMAX(0,255) PORT_SENSITIVITY(25) PORT_KEYDELTA(32) PORT_COCKTAIL PORT_PLAYER(2)
INPUT_PORTS_END


INPUT_PORTS_START( shufbowl )
	/*
    Earlier versions of Shuffleshot & World Class Bowling share the same input
    port set up. IE: "Freeze Screen" and no support for a cocktail mode
    */
	PORT_INCLUDE(itech32_base)

	PORT_MODIFY("P1")
	PORT_BIT( 0x00f0, IP_ACTIVE_LOW, IPT_UNUSED )

	PORT_MODIFY("P2")
	PORT_BIT( 0x00f0, IP_ACTIVE_LOW, IPT_UNUSED )

	PORT_MODIFY("P3")
	PORT_BIT( 0x0004, IP_ACTIVE_LOW, IPT_COIN3 )
	PORT_BIT( 0x00fb, IP_ACTIVE_LOW, IPT_UNUSED )

	PORT_MODIFY("DIPS")
	PORT_DIPNAME( 0x0040, 0x0000, "Freeze Screen" )
	PORT_DIPSETTING(      0x0000, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0040, DEF_STR( On ) )

	PORT_START_TAG("TRACKX1")
    PORT_BIT( 0xff, 0x00, IPT_TRACKBALL_X ) PORT_MINMAX(0,255) PORT_SENSITIVITY(25) PORT_KEYDELTA(32) PORT_REVERSE PORT_PLAYER(1)

	PORT_START_TAG("TRACKY1")
    PORT_BIT( 0xff, 0x00, IPT_TRACKBALL_Y ) PORT_MINMAX(0,255) PORT_SENSITIVITY(25) PORT_KEYDELTA(32) PORT_PLAYER(1)

	PORT_START_TAG("TRACKX2")
    PORT_BIT( 0xff, 0x00, IPT_TRACKBALL_X ) PORT_MINMAX(0,255) PORT_SENSITIVITY(25) PORT_KEYDELTA(32) PORT_REVERSE PORT_COCKTAIL PORT_PLAYER(2)

	PORT_START_TAG("TRACKY2")
    PORT_BIT( 0xff, 0x00, IPT_TRACKBALL_Y ) PORT_MINMAX(0,255) PORT_SENSITIVITY(25) PORT_KEYDELTA(32) PORT_COCKTAIL PORT_PLAYER(2)
INPUT_PORTS_END


INPUT_PORTS_START( gt3d )
	PORT_INCLUDE(itech32_base)

	PORT_MODIFY("P1")
	PORT_BIT( 0x00f0, IP_ACTIVE_LOW, IPT_UNUSED )

	PORT_MODIFY("P2")
	PORT_BIT( 0x00f0, IP_ACTIVE_LOW, IPT_UNUSED )

	PORT_MODIFY("P3")
	PORT_BIT( 0x0001, IP_ACTIVE_LOW, IPT_VOLUME_UP )
	PORT_BIT( 0x0002, IP_ACTIVE_LOW, IPT_VOLUME_DOWN )
	PORT_BIT( 0x0004, IP_ACTIVE_LOW, IPT_COIN3 )
	PORT_BIT( 0x00f8, IP_ACTIVE_LOW, IPT_UNUSED )

	PORT_MODIFY("DIPS")
	PORT_DIPNAME( 0x0010, 0x0000, DEF_STR( Unknown ))
	PORT_DIPSETTING(      0x0000, DEF_STR( Off ))
	PORT_DIPSETTING(      0x0010, DEF_STR( On ))
	PORT_DIPNAME( 0x0020, 0x0000, "Trackball Orientation" )
	PORT_DIPSETTING(      0x0000, "Normal Mount" )
	PORT_DIPSETTING(      0x0020, "45 Degree Angle" )
	PORT_DIPNAME( 0x0040, 0x0000, DEF_STR( Controls ))
	PORT_DIPSETTING(      0x0000, "One Trackball" )
	PORT_DIPSETTING(      0x0040, "Two Trackballs" )

	PORT_START_TAG("TRACKX1")
    PORT_BIT( 0xff, 0x00, IPT_TRACKBALL_X ) PORT_MINMAX(0,255) PORT_SENSITIVITY(25) PORT_KEYDELTA(32) PORT_REVERSE PORT_PLAYER(1)

	PORT_START_TAG("TRACKY1")
    PORT_BIT( 0xff, 0x00, IPT_TRACKBALL_Y ) PORT_MINMAX(0,255) PORT_SENSITIVITY(25) PORT_KEYDELTA(32) PORT_PLAYER(1)

	PORT_START_TAG("TRACKX2")
    PORT_BIT( 0xff, 0x00, IPT_TRACKBALL_X ) PORT_MINMAX(0,255) PORT_SENSITIVITY(25) PORT_KEYDELTA(32) PORT_REVERSE PORT_COCKTAIL PORT_PLAYER(2)

	PORT_START_TAG("TRACKY2")
    PORT_BIT( 0xff, 0x00, IPT_TRACKBALL_Y ) PORT_MINMAX(0,255) PORT_SENSITIVITY(25) PORT_KEYDELTA(32) PORT_COCKTAIL PORT_PLAYER(2)
INPUT_PORTS_END


INPUT_PORTS_START( gt97 ) /* v1.30 is the first known version of GT97 to support Cocktail mode! */
	PORT_INCLUDE(gt3d)

	PORT_MODIFY("DIPS")
	PORT_DIPNAME( 0x0010, 0x0000, "Freeze Screen" )
	PORT_DIPSETTING(      0x0000, DEF_STR( Off ))
	PORT_DIPSETTING(      0x0010, DEF_STR( On ))
	PORT_DIPNAME( 0x0020, 0x0000, DEF_STR( Unknown ))	/* Seem to have no effect on the game */
	PORT_DIPSETTING(      0x0000, DEF_STR( Off ))
	PORT_DIPSETTING(      0x0020, DEF_STR( On ))
	PORT_DIPNAME( 0x0040, 0x0000, DEF_STR( Cabinet ))
	PORT_DIPSETTING(      0x0000, DEF_STR( Upright ))
	PORT_DIPSETTING(      0x0040, DEF_STR( Cocktail ))
INPUT_PORTS_END


INPUT_PORTS_START( gt97o ) /* Older versions of GT97 do NOT support a cocktail mode */
	PORT_INCLUDE(gt3d)

	PORT_MODIFY("DIPS")
	PORT_DIPNAME( 0x0010, 0x0000, "Freeze Screen" )
	PORT_DIPSETTING(      0x0000, DEF_STR( Off ))
	PORT_DIPSETTING(      0x0010, DEF_STR( On ))
INPUT_PORTS_END


INPUT_PORTS_START( gt97s )
	PORT_INCLUDE(gt3d)

	PORT_MODIFY("DIPS")
	PORT_DIPNAME( 0x0010, 0x0000, "Freeze Screen" )
	PORT_DIPSETTING(      0x0000, DEF_STR( Off ))
	PORT_DIPSETTING(      0x0010, DEF_STR( On ))
	PORT_DIPNAME( 0x0040, 0x0000, DEF_STR( Unknown ))		/* Single controller version -  has no effect */
	PORT_DIPSETTING(      0x0000, DEF_STR( Off ))
	PORT_DIPSETTING(      0x0040, DEF_STR( On ))
INPUT_PORTS_END


INPUT_PORTS_START( gt98 )
	PORT_INCLUDE(gt3d)

	PORT_MODIFY("DIPS")
	PORT_DIPNAME( 0x0020, 0x0000, DEF_STR( Unknown ))	/* Seem to have no effect on the game */
	PORT_DIPSETTING(      0x0000, DEF_STR( Off ))
	PORT_DIPSETTING(      0x0020, DEF_STR( On ))
	PORT_DIPNAME( 0x0040, 0x0000, DEF_STR( Cabinet ))
	PORT_DIPSETTING(      0x0000, DEF_STR( Upright ))
	PORT_DIPSETTING(      0x0040, DEF_STR( Cocktail ))
INPUT_PORTS_END


INPUT_PORTS_START( gt98s )
	PORT_INCLUDE(gt3d)

	PORT_MODIFY("DIPS")
	PORT_DIPNAME( 0x0020, 0x0000, DEF_STR( Unknown ))	/* Seem to have no effect on the game */
	PORT_DIPSETTING(      0x0000, DEF_STR( Off ))
	PORT_DIPSETTING(      0x0020, DEF_STR( On ))
	PORT_DIPNAME( 0x0040, 0x0000, DEF_STR( Unknown ))	/* Single controller version -  has no effect */
	PORT_DIPSETTING(      0x0000, DEF_STR( Off ))
	PORT_DIPSETTING(      0x0040, DEF_STR( On ))
INPUT_PORTS_END


INPUT_PORTS_START( s_ver )
	PORT_INCLUDE(gt3d)

	PORT_MODIFY("DIPS")
	PORT_DIPNAME( 0x0010, 0x0000, "Trackball Orientation" )	/* Determined by actual use / trial & error */
	PORT_DIPSETTING(      0x0000, "Normal Mount" )			/* The manual says "Always on (defualt)" and "Off -- UNUSED --" */
	PORT_DIPSETTING(      0x0010, "45 Degree Angle" )
	PORT_DIPNAME( 0x0020, 0x0000, DEF_STR( Unknown ))		/* Single controller version -  has no effect */
	PORT_DIPSETTING(      0x0000, DEF_STR( Off ))
	PORT_DIPSETTING(      0x0020, DEF_STR( On ))
	PORT_DIPNAME( 0x0040, 0x0000, DEF_STR( Unknown ))		/* Single controller version -  has no effect */
	PORT_DIPSETTING(      0x0000, DEF_STR( Off ))
	PORT_DIPSETTING(      0x0040, DEF_STR( On ))
INPUT_PORTS_END


INPUT_PORTS_START( aama )
	PORT_INCLUDE(gt3d)

	PORT_MODIFY("DIPS")
	PORT_DIPNAME( 0x0010, 0x0000, "Trackball Orientation" )	/* Determined by actual use / trial & error */
	PORT_DIPSETTING(      0x0000, "Normal Mount" )			/* The manual says "Always on (defualt)" and "Off -- UNUSED --" */
	PORT_DIPSETTING(      0x0010, "45 Degree Angle" )
	PORT_DIPNAME( 0x0020, 0x0000, DEF_STR( Cabinet ))
	PORT_DIPSETTING(      0x0000, DEF_STR( Upright ))
	PORT_DIPSETTING(      0x0020, DEF_STR( Cocktail ))		/* Cocktail mode REQUIRES "Controls" to be set to "Two Trackballs" */
	PORT_DIPNAME( 0x0040, 0x0000, DEF_STR( Controls ))
	PORT_DIPSETTING(      0x0000, "One Trackball" )
	PORT_DIPSETTING(      0x0040, "Two Trackballs" )		/* Two Trackballs will work for Upright for "side by side" controls */
INPUT_PORTS_END



/*************************************
 *
 *  Game drivers
 *
 *************************************/

GAME( 1992, timekill, 0,        timekill, timekill, timekill, ROT0, "Strata/Incredible Technologies", "Time Killers (v1.32)", 0 )
GAME( 1992, timek131, timekill, timekill, timekill, timekill, ROT0, "Strata/Incredible Technologies", "Time Killers (v1.31)", 0 )
GAME( 1993, hardyard, 0,        bloodstm, hardyard, hardyard, ROT0, "Strata/Incredible Technologies", "Hard Yardage (v1.20)", 0 )
GAME( 1993, hardyd10, hardyard, bloodstm, hardyard, hardyard, ROT0, "Strata/Incredible Technologies", "Hard Yardage (v1.00)", 0 )
GAME( 1994, bloodstm, 0,        bloodstm, bloodstm, bloodstm, ROT0, "Strata/Incredible Technologies", "Blood Storm (v2.22)", 0 )
GAME( 1994, bloods22, bloodstm, bloodstm, bloodstm, bloodstm, ROT0, "Strata/Incredible Technologies", "Blood Storm (v2.20)", 0 )
GAME( 1994, bloods21, bloodstm, bloodstm, bloodstm, bloodstm, ROT0, "Strata/Incredible Technologies", "Blood Storm (v2.10)", 0 )
GAME( 1994, bloods11, bloodstm, bloodstm, bloodstm, bloodstm, ROT0, "Strata/Incredible Technologies", "Blood Storm (v1.10)", 0 )
GAME( 1994, pairs,    0,        bloodstm, pairs,    bloodstm, ROT0, "Strata/Incredible Technologies", "Pairs (V1.2, 09/30/94)", 0 )
GAME( 1994, pairsa,   pairs,    bloodstm, pairs,    bloodstm, ROT0, "Strata/Incredible Technologies", "Pairs (09/07/94)", 0 )
GAME( 1994, hotmemry, pairs,    bloodstm, pairs,    bloodstm, ROT0, "Tuning/Incredible Technologies", "Hot Memory (V1.2, Germany)", 0 )
GAME( 1994, drivedge, 0,        drivedge, drivedge, drivedge, ROT0, "Strata/Incredible Technologies", "Driver's Edge", GAME_IMPERFECT_GRAPHICS )
GAME( 1995, wcbowl,   0,        sftm,     wcbowln,  wcbowln,  ROT0, "Incredible Technologies",        "World Class Bowling (v1.66)" , 0) /* PIC 16C54 labeled as ITBWL-3 */
GAME( 1995, wcbwl165, wcbowl,   sftm,     shufbowl, wcbowln,  ROT0, "Incredible Technologies",        "World Class Bowling (v1.65)" , 0) /* PIC 16C54 labeled as ITBWL-3 */
GAME( 1995, wcbwl161, wcbowl,   sftm,     shufbowl, wcbowln,  ROT0, "Incredible Technologies",        "World Class Bowling (v1.61)" , 0) /* PIC 16C54 labeled as ITBWL-3 */
GAME( 1997, wcbwl140, wcbowldx, wcbowlt,  wcbowldx, wcbowlt,  ROT0, "Incredible Technologies",        "World Class Bowling Tournament (v1.40)" , 0) /* PIC 16C54 labeled as ITBWL-4 */
GAME( 1995, wcbwl12,  wcbowl,   wcbowl,   wcbowl,   wcbowl,   ROT0, "Incredible Technologies",        "World Class Bowling (v1.2)" , 0) /* PIC 16C54 labeled as ITBWL-1 */
GAME( 1995, sftm,     0,        sftm,     sftm,     sftm,     ROT0, "Capcom/Incredible Technologies", "Street Fighter: The Movie (v1.12)" , 0) /* PIC 16C54 labeled as ITSF-1 */
GAME( 1995, sftm111,  sftm,     sftm,     sftm,     sftm110,  ROT0, "Capcom/Incredible Technologies", "Street Fighter: The Movie (v1.11)" , 0) /* PIC 16C54 labeled as ITSF-1 */
GAME( 1995, sftm110,  sftm,     sftm,     sftm,     sftm110,  ROT0, "Capcom/Incredible Technologies", "Street Fighter: The Movie (v1.10)" , 0) /* PIC 16C54 labeled as ITSF-1 */
GAME( 1995, sftmj,    sftm,     sftm,     sftm,     sftm,     ROT0, "Capcom/Incredible Technologies", "Street Fighter: The Movie (v1.12N, Japan)" , 0) /* PIC 16C54 labeled as ITSF-1 */
GAME( 1997, shufshot, 0,        sftm,     shufshot, shufshot, ROT0, "Strata/Incredible Technologies", "Shuffleshot (v1.40)" , 0) /* PIC 16C54 labeled as ITSHF-1 */
GAME( 1997, sshot139, shufshot, sftm,     shufshot, shufshot, ROT0, "Strata/Incredible Technologies", "Shuffleshot (v1.39)" , 0) /* PIC 16C54 labeled as ITSHF-1 */
GAME( 1997, sshot137, shufshot, sftm,     shufbowl, shufshot, ROT0, "Strata/Incredible Technologies", "Shuffleshot (v1.37)" , 0) /* PIC 16C54 labeled as ITSHF-1 */
GAME( 1999, wcbowldx, 0,        sftm,     wcbowldx, shufshot, ROT0, "Incredible Technologies",        "World Class Bowling Deluxe (v2.00)" , 0) /* PIC 16C54 labeled as ITBWL-4 */

/*
    The following naming conventions are used:

    gt3d s 192
      ^^ ^ ^^^
    Game | Version
         |
    v = Version (AAMA 676266+ PCB P/N 1082 Rev 2)
    l = Long ROM board:
        Main  P/N 1064 Rev 1
        ROM   P/N 1080 Rev 5
        Sound P/N 1078 Rev 1
    s = Short ROM board:
        Main  P/N 1064 Rev 1
        ROM   P/N 1069 Rev 2 or P/N 1088 Rev 0 (1 Trackball Connector)
        Sound P/N 1078 Rev 1 or P/N 1066 Rev 2
    n = Non-tournament (AAMA 676266+) PCB P/N 1082 Rev 2 - Applies only for GT3D
    t = Tournament PCB P/N 1082 Rev 2, with necessary chips on board:
        Philips SCN68681 (DUART) & ST Timekeeper (M48T02-120PC1)

    NOTE: Due to various different upgrade packages from IT, the 3 tier boards can end up with any combination
        of rom boards and sound boards.  For historical reasons, GTG3 3 tier S versions will use the oldest
        sound file set up. Version L will use the newer Ensoniq sample rom and v2.X sound code, while gt97
        through gtclassic will use the lastest "NR" versions.

  GT Royal Edition Tournament is a Euro GT99
  GT Supreme Edition Tournament is a Euro GT2K with slightly different GROM2_0 through GROM2_3
     GT Supreme (on a real PCB with tournament data) comes up with a different title screen and is (c) 2002
     showing the title as GT Supreme Plus! and the Hole-In-One board shows an aditional course, Coconut Cove from GT99
     Current emulation does not reproduce this extra title screen.
  GT Diamond Edition Tournament is a Euro GT Classic (Not currently dumped)
     This would be the only known tournament version of Classic

    Parent set will always be gt(year) with the most recent version.  IE: gt97 is Golden Tee '97 v1.30

*/
GAME( 1995, gt3d,     0,        gt3d,    gt3d,  aama,     ROT0, "Incredible Technologies", "Golden Tee 3D Golf (v1.93N)" , 0) /* PIC 16C54 labeled as ITGF-2 */
GAME( 1995, gt3dl192, gt3d,     gt3d,    gt3d,  gt3dl,    ROT0, "Incredible Technologies", "Golden Tee 3D Golf (v1.92L)" , 0) /* PIC 16C54 labeled as ITGF-2 */
GAME( 1995, gt3dl191, gt3d,     gt3d,    gt3d,  gt3dl,    ROT0, "Incredible Technologies", "Golden Tee 3D Golf (v1.91L)" , 0) /* PIC 16C54 labeled as ITGF-2 */
GAME( 1995, gt3ds192, gt3d,     gt3d,    gt3d,  gt3d,     ROT0, "Incredible Technologies", "Golden Tee 3D Golf (v1.92S)" , 0) /* PIC 16C54 labeled as ITGF-1 */
GAME( 1995, gt3dv18,  gt3d,     gt3d,    gt3d,  gt3d,     ROT0, "Incredible Technologies", "Golden Tee 3D Golf (v1.8)" , 0) /* PIC 16C54 labeled as ITGF-1 */
GAME( 1995, gt3dv17,  gt3d,     gt3d,    gt3d,  gt3d,     ROT0, "Incredible Technologies", "Golden Tee 3D Golf (v1.7)" , 0) /* PIC 16C54 labeled as ITGF-1 */
GAME( 1995, gt3dv16,  gt3d,     gt3d,    gt3d,  gt3d,     ROT0, "Incredible Technologies", "Golden Tee 3D Golf (v1.6)" , 0) /* PIC 16C54 labeled as ITGF-1 */
GAME( 1995, gt3dv15,  gt3d,     gt3d,    gt3d,  gt3d,     ROT0, "Incredible Technologies", "Golden Tee 3D Golf (v1.5)" , 0) /* PIC 16C54 labeled as ITGF-1 */
GAME( 1995, gt3dv14,  gt3d,     gt3d,    gt3d,  gt3d,     ROT0, "Incredible Technologies", "Golden Tee 3D Golf (v1.4)" , 0) /* PIC 16C54 labeled as ITGF-1 */
GAME( 1995, gt3dt231, gt3d,     gt3dt,   gt3d,  aamat,    ROT0, "Incredible Technologies", "Golden Tee 3D Golf Tournament (v2.31)" , 0) /* PIC 16C54 labeled as ITGF-2 */
GAME( 1995, gt3dt211, gt3d,     gt3dt,   gt3d,  aamat,    ROT0, "Incredible Technologies", "Golden Tee 3D Golf Tournament (v2.11)" , 0) /* PIC 16C54 labeled as ITGF-2 */

GAME( 1997, gt97,     0,        gt3d,    gt97,  aama,     ROT0, "Incredible Technologies", "Golden Tee '97 (v1.30)" , 0) /* PIC 16C54 labeled as ITGFS-3 */
GAME( 1997, gt97v122, gt97,     gt3d,    gt97o, aama,     ROT0, "Incredible Technologies", "Golden Tee '97 (v1.22)" , 0) /* PIC 16C54 labeled as ITGFS-3 */
GAME( 1997, gt97v121, gt97,     gt3d,    gt97o, aama,     ROT0, "Incredible Technologies", "Golden Tee '97 (v1.21)" , 0) /* PIC 16C54 labeled as ITGFS-3 */
GAME( 1997, gt97s121, gt97,     gt3d,    gt97s, s_ver,    ROT0, "Incredible Technologies", "Golden Tee '97 (v1.21S)" , 0) /* PIC 16C54 labeled as ITGFM-3 */
GAME( 1997, gt97v120, gt97,     gt3d,    gt97o, aama,     ROT0, "Incredible Technologies", "Golden Tee '97 (v1.20)" , 0) /* PIC 16C54 labeled as ITGFS-3 */
GAME( 1997, gt97t240, gt97,     gt3dt,   gt97o, aamat,    ROT0, "Incredible Technologies", "Golden Tee '97 Tournament (v2.40)" , 0) /* PIC 16C54 labeled as ITGFS-3 */

GAME( 1998, gt98,     0,        gt3d,    aama,  aama,     ROT0, "Incredible Technologies", "Golden Tee '98 (v1.10)" , 0) /* PIC 16C54 labeled as ITGF98 */
GAME( 1998, gt98v100, gt98,     gt3d,    gt98,  aama,     ROT0, "Incredible Technologies", "Golden Tee '98 (v1.00)" , 0) /* PIC 16C54 labeled as ITGF98 */
GAME( 1998, gt98s100, gt98,     gt3d,    gt98s, s_ver,    ROT0, "Incredible Technologies", "Golden Tee '98 (v1.00S)" , 0) /* PIC 16C54 labeled as ITGF98-M */
GAME( 1998, gt98t303, gt98,     gt3dt,   gt98s, aamat,    ROT0, "Incredible Technologies", "Golden Tee '98 Tournament (v3.03)" , 0) /* PIC 16C54 labeled as ITGF98 */

GAME( 1999, gt99,     0,        gt3d,    aama,  aama,     ROT0, "Incredible Technologies", "Golden Tee '99 (v1.00)" , 0) /* PIC 16C54 labeled as ITGF99 */
GAME( 1999, gt99s100, gt99,     gt3d,    s_ver, s_ver,    ROT0, "Incredible Technologies", "Golden Tee '99 (v1.00S)" , 0) /* PIC 16C54 labeled as ITGF99-M */
GAME( 1999, gt99t400, gt99,     gt3dt,   gt98s, aamat,    ROT0, "Incredible Technologies", "Golden Tee '99 Tournament (v4.00)" , 0) /* PIC 16C54 labeled as ITGF99 */
GAME( 1999, gtroyal,  gt99,     gt3dt,   gt98s, aamat,    ROT0, "Incredible Technologies", "Golden Tee Royal Edition Tournament (v4.02)" , 0) /* PIC 16C54 labeled as ITGF99I */

GAME( 2000, gt2k,     0,        gt3d,    aama,  aama,     ROT0, "Incredible Technologies", "Golden Tee 2K (v1.00)" , 0) /* PIC 16C54 labeled as ITGF2K */
GAME( 2000, gt2ks100, gt2k,     gt3d,    s_ver, s_ver,    ROT0, "Incredible Technologies", "Golden Tee 2K (v1.00S)" , 0) /* PIC 16C54 labeled as ITGF2K-M */
GAME( 2000, gt2kt500, gt2k,     gt3dt,   gt98s, aamat,    ROT0, "Incredible Technologies", "Golden Tee 2K Tournament (v5.00)" , 0) /* PIC 16C54 labeled as ITGF2K */
GAME( 2002, gtsuprem, gt2k,     gt3dt,   gt98s, aamat,    ROT0, "Incredible Technologies", "Golden Tee Supreme Edition Tournament (v5.10)" , 0) /* PIC 16C54 labeled as ITGF2K-1 */

GAME( 2001, gtclassc, 0,        gt3d,    aama,  aama,     ROT0, "Incredible Technologies", "Golden Tee Classic (v1.00)" , 0) /* PIC 16C54 labeled as ITGFCL */
GAME( 2001, gtclassp, gtclassc, gt3d,    aama,  gtclassp, ROT0, "Incredible Technologies", "Golden Tee Classic (v1.00) Alt" , 0) /* PIC 16C54 labeled as ITGFCL */
GAME( 2001, gtcls100, gtclassc, gt3d,    s_ver, s_ver,    ROT0, "Incredible Technologies", "Golden Tee Classic (v1.00S)" , 0) /* PIC 16C54 labeled as ITGFCL-M */

