/* Standard Namco System 1 input port definition */
INPUT_PORTS_START( ns1 )
	PORT_START_TAG( "CONTROL0" )
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT )
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT )
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN )
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_JOYSTICK_UP )
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_BUTTON1 )
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_BUTTON2 )
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_BUTTON3 )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_START1 )

	PORT_START_TAG( "CONTROL1" )
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT ) PORT_PLAYER(2)
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT )  PORT_PLAYER(2)
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN )  PORT_PLAYER(2)
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_JOYSTICK_UP )    PORT_PLAYER(2)
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_BUTTON1 )        PORT_PLAYER(2)
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_BUTTON2 )        PORT_PLAYER(2)
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_BUTTON3 )        PORT_PLAYER(2)
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_START2 )

	PORT_START_TAG( "DIPSW" )
	PORT_SERVICE( 0x80, IP_ACTIVE_LOW )
	PORT_DIPNAME( 0x40, 0x40, DEF_STR( Unknown ) )
	PORT_DIPSETTING(    0x40, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x20, 0x20, DEF_STR( Unknown ) )
	PORT_DIPSETTING(    0x20, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x10, 0x10, DEF_STR( Unknown ) )
	PORT_DIPSETTING(    0x10, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x08, 0x08, DEF_STR( Unknown ) )
	PORT_DIPSETTING(    0x08, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x04, 0x04, DEF_STR( Unknown ) )
	PORT_DIPSETTING(    0x04, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x02, 0x02, DEF_STR( Unknown ) )
	PORT_DIPSETTING(    0x02, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x01, 0x01, DEF_STR( Unknown ) )
	PORT_DIPSETTING(    0x01, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )

	PORT_START_TAG( "COIN" )
	PORT_BIT( 0x01, IP_ACTIVE_HIGH, IPT_SPECIAL )   /* OUT:coin lockout */
	PORT_BIT( 0x02, IP_ACTIVE_HIGH, IPT_SPECIAL )   /* OUT:coin counter 1 */
	PORT_BIT( 0x04, IP_ACTIVE_HIGH, IPT_SPECIAL )   /* OUT:coin counter 2 */
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_COIN2 )
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_COIN1 )
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_SERVICE ) PORT_NAME("Service Button") PORT_CODE(KEYCODE_F1)	// service switch from the edge connector
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_SERVICE1 )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_UNUSED )
INPUT_PORTS_END



INPUT_PORTS_START( shadowld )
	PORT_INCLUDE( ns1 )

	PORT_MODIFY( "DIPSW" )
	PORT_DIPNAME( 0x40, 0x40, "Freeze" )
	PORT_DIPSETTING(    0x40, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x20, 0x20, "Alternate sound effects" )	// e.g. the red bird
	PORT_DIPSETTING(    0x20, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
INPUT_PORTS_END


INPUT_PORTS_START( dspirit )
	PORT_INCLUDE( ns1 )

	PORT_MODIFY( "DIPSW" )
	PORT_DIPNAME( 0x7f, 0x7f, "Life" )
	PORT_DIPSETTING(    0x7f, "2" )
	PORT_DIPSETTING(    0x16, "3" )
INPUT_PORTS_END


INPUT_PORTS_START( quester )
	PORT_INCLUDE( ns1 )

	PORT_MODIFY( "CONTROL0" )
	PORT_BIT( 0x0f, IP_ACTIVE_LOW, IPT_UNUSED )     /* paddle */
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_BUTTON1 )
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_START1 )

	PORT_MODIFY( "CONTROL1" )
	PORT_BIT( 0x0f, IP_ACTIVE_LOW, IPT_UNUSED )     /* paddle */
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_PLAYER(2)
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_START2 )

	PORT_MODIFY( "DIPSW" )
	PORT_DIPNAME( 0x40, 0x40, "Unk 1" )	// read @ fac7
	PORT_DIPSETTING(    0x40, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x10, 0x10, "Freeze" )
	PORT_DIPSETTING(    0x10, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x04, 0x00, "Brightness" )
	PORT_DIPSETTING(    0x04, DEF_STR( Low ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Normal ) )
	PORT_DIPNAME( 0x01, 0x01, DEF_STR( Level_Select ) )
	PORT_DIPSETTING(    0x01, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )

	PORT_START_TAG( "PADDLE0" )	/* fake input port for player 1 paddle */
	PORT_BIT( 0xff, 0x00, IPT_DIAL ) PORT_SENSITIVITY(30) PORT_KEYDELTA(15)

	PORT_START_TAG( "PADDLE1" )	/* fake input port for player 2 paddle */
	PORT_BIT( 0xff, 0x00, IPT_DIAL ) PORT_SENSITIVITY(30) PORT_KEYDELTA(15) PORT_PLAYER(2)
INPUT_PORTS_END


INPUT_PORTS_START( pacmania )
	PORT_INCLUDE( ns1 )

	PORT_MODIFY( "DIPSW" )
	PORT_DIPNAME( 0x40, 0x40, "Freeze" )
	PORT_DIPSETTING(    0x40, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	/* this doesn't seem to have much use... */
	PORT_DIPNAME( 0x20, 0x20, "Kick Watchdog in IRQ" )
	PORT_DIPSETTING(    0x20, DEF_STR( No ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Yes ) )
	/* to enter the A.D.S. menu, set the dip switch and reset with service coin pressed */
	PORT_DIPNAME( 0x08, 0x08, "Auto Data Sampling" )
	PORT_DIPSETTING(    0x08, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
INPUT_PORTS_END


INPUT_PORTS_START( galaga88 )
	PORT_INCLUDE( ns1 )

	PORT_MODIFY( "DIPSW" )
	PORT_DIPNAME( 0x7f, 0x7f, "Auto Data Sampling" )
	PORT_DIPSETTING(    0x7f, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x57, DEF_STR( On ) )
INPUT_PORTS_END


INPUT_PORTS_START( berabohm )
	PORT_INCLUDE( ns1 )

	PORT_MODIFY( "CONTROL0" )
	PORT_BIT( 0x70, IP_ACTIVE_LOW, IPT_UNUSED )

	PORT_MODIFY( "CONTROL1" )
	PORT_BIT( 0x70, IP_ACTIVE_LOW, IPT_SPECIAL )    /* timing from the buttons interface */

	PORT_MODIFY( "DIPSW" )
	PORT_DIPNAME( 0x20, 0x20, "Invulnerability" )
	PORT_DIPSETTING(    0x20, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x01, 0x01, "Freeze" )
	PORT_DIPSETTING(    0x01, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )

#ifdef PRESSURE_SENSITIVE
	/*
    buttons (pressure sensitive)
    each button has two switches: the first is closed as soon as the button is
    pressed, the second a little later, depending on how hard the button is
    pressed.
    bits 0-5 control strength (0x00 = max 0x3f = min)
    bit 6 indicates the button is pressed
    bit 7 is not actually read by the game but I use it to simulate the second
          switch
    */
	PORT_START_TAG( "IN0" )
	PORT_BIT( 0x3f, 0x00, IPT_SPECIAL )
	PORT_BIT( 0x40, IP_ACTIVE_HIGH, IPT_BUTTON3 )
	PORT_BIT( 0x80, IP_ACTIVE_HIGH, IPT_BUTTON4 )

	PORT_START_TAG( "IN1" )
	PORT_BIT( 0x3f, 0x00, IPT_SPECIAL )
	PORT_BIT( 0x40, IP_ACTIVE_HIGH, IPT_BUTTON1 )
	PORT_BIT( 0x80, IP_ACTIVE_HIGH, IPT_BUTTON2 )

	PORT_START_TAG( "IN2" )
	PORT_BIT( 0x3f, 0x00, IPT_SPECIAL )
	PORT_BIT( 0x40, IP_ACTIVE_HIGH, IPT_BUTTON3 ) PORT_PLAYER(2)
	PORT_BIT( 0x80, IP_ACTIVE_HIGH, IPT_BUTTON4 ) PORT_PLAYER(2)

	PORT_START_TAG( "IN3" )
	PORT_BIT( 0x3f, 0x00, IPT_SPECIAL )
	PORT_BIT( 0x40, IP_ACTIVE_HIGH, IPT_BUTTON1 ) PORT_PLAYER(2)
	PORT_BIT( 0x80, IP_ACTIVE_HIGH, IPT_BUTTON2 ) PORT_PLAYER(2)
#else
	PORT_START_TAG( "IN0" )
	PORT_BIT( 0x01, IP_ACTIVE_HIGH, IPT_BUTTON4 )
	PORT_BIT( 0x02, IP_ACTIVE_HIGH, IPT_BUTTON5 )
	PORT_BIT( 0x04, IP_ACTIVE_HIGH, IPT_BUTTON6 )

	PORT_START_TAG( "IN1" )
	PORT_BIT( 0x01, IP_ACTIVE_HIGH, IPT_BUTTON1 )
	PORT_BIT( 0x02, IP_ACTIVE_HIGH, IPT_BUTTON2 )
	PORT_BIT( 0x04, IP_ACTIVE_HIGH, IPT_BUTTON3 )

	PORT_START_TAG( "IN2" )
	PORT_BIT( 0x01, IP_ACTIVE_HIGH, IPT_BUTTON4 ) PORT_PLAYER(2)
	PORT_BIT( 0x02, IP_ACTIVE_HIGH, IPT_BUTTON5 ) PORT_PLAYER(2)
	PORT_BIT( 0x04, IP_ACTIVE_HIGH, IPT_BUTTON6 ) PORT_PLAYER(2)

	PORT_START_TAG( "IN3" )
	PORT_BIT( 0x01, IP_ACTIVE_HIGH, IPT_BUTTON1 ) PORT_PLAYER(2)
	PORT_BIT( 0x02, IP_ACTIVE_HIGH, IPT_BUTTON2 ) PORT_PLAYER(2)
	PORT_BIT( 0x04, IP_ACTIVE_HIGH, IPT_BUTTON3 ) PORT_PLAYER(2)
#endif
INPUT_PORTS_END


INPUT_PORTS_START( mmaze )
	PORT_INCLUDE( ns1 )

	PORT_MODIFY( "DIPSW" )
	PORT_DIPNAME( 0x10, 0x10, "Freeze" )
	PORT_DIPSETTING(    0x10, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x01, 0x01, DEF_STR( Level_Select ) )
	PORT_DIPSETTING(    0x01, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
INPUT_PORTS_END


INPUT_PORTS_START( bakutotu )
	PORT_INCLUDE( ns1 )

	PORT_MODIFY( "DIPSW" )
	PORT_DIPNAME( 0x20, 0x20, "Show Coordinates" )
	PORT_DIPSETTING(    0x20, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x08, 0x08, "Sprite Viewer" )
	PORT_DIPSETTING(    0x08, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x01, 0x01, "Freeze" )
	PORT_DIPSETTING(    0x01, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
INPUT_PORTS_END


INPUT_PORTS_START( wldcourt )
	PORT_INCLUDE( ns1 )

	PORT_MODIFY( "DIPSW" )
	/* see code @ e331. The lines this draws can't even be seen because they are erased afterwards */
	PORT_DIPNAME( 0x7e, 0x7e, "Draw Debug Lines" )
	PORT_DIPSETTING(    0x7e, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x5c, DEF_STR( On ) )
	PORT_DIPNAME( 0x01, 0x01, "Freeze" )
	PORT_DIPSETTING(    0x01, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
INPUT_PORTS_END


INPUT_PORTS_START( splatter )
	PORT_INCLUDE( ns1 )

	PORT_MODIFY( "DIPSW" )
	/* these two don't seem to have much use... */
	PORT_DIPNAME( 0x11, 0x11, "CPU #0 Kick Watchdog in IRQ" )
	PORT_DIPSETTING(    0x11, DEF_STR( No ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Yes ) )
	PORT_DIPNAME( 0x06, 0x06, "CPU #0&1 Kick Watchdog in IRQ" )
	PORT_DIPSETTING(    0x06, DEF_STR( No ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Yes ) )
INPUT_PORTS_END


INPUT_PORTS_START( faceoff )
	PORT_INCLUDE( ns1 )

	PORT_MODIFY( "CONTROL0" )
	PORT_BIT( 0x7f, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_START1 )

	PORT_MODIFY( "CONTROL1" )
	PORT_BIT( 0x7f, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_START2 )

	PORT_START_TAG( "IN0" )
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_JOYSTICKLEFT_RIGHT ) PORT_PLAYER(1)
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_JOYSTICKLEFT_LEFT ) PORT_PLAYER(1)
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_JOYSTICKLEFT_DOWN ) PORT_PLAYER(1)
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_JOYSTICKLEFT_UP ) PORT_PLAYER(1)
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_PLAYER(1)
	PORT_BIT( 0xe0, IP_ACTIVE_LOW, IPT_UNUSED )

	PORT_START_TAG( "IN1" )
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_JOYSTICKRIGHT_RIGHT ) PORT_PLAYER(1)
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_JOYSTICKRIGHT_LEFT ) PORT_PLAYER(1)
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_JOYSTICKRIGHT_DOWN ) PORT_PLAYER(1)
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_JOYSTICKRIGHT_UP ) PORT_PLAYER(1)
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_BUTTON2 ) PORT_PLAYER(1)
	PORT_BIT( 0xe0, IP_ACTIVE_LOW, IPT_UNUSED )

	PORT_START_TAG( "IN2" )
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_JOYSTICKLEFT_RIGHT ) PORT_PLAYER(2)
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_JOYSTICKLEFT_LEFT ) PORT_PLAYER(2)
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_JOYSTICKLEFT_DOWN ) PORT_PLAYER(2)
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_JOYSTICKLEFT_UP ) PORT_PLAYER(2)
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_PLAYER(2)
	PORT_BIT( 0xe0, IP_ACTIVE_LOW, IPT_UNUSED )

	PORT_START_TAG( "IN3" )
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_JOYSTICKRIGHT_RIGHT ) PORT_PLAYER(2)
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_JOYSTICKRIGHT_LEFT ) PORT_PLAYER(2)
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_JOYSTICKRIGHT_DOWN ) PORT_PLAYER(2)
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_JOYSTICKRIGHT_UP ) PORT_PLAYER(2)
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_BUTTON2 ) PORT_PLAYER(2)
	PORT_BIT( 0xe0, IP_ACTIVE_LOW, IPT_UNUSED )
INPUT_PORTS_END


INPUT_PORTS_START( ws89 )
	PORT_INCLUDE( ns1 )

	PORT_MODIFY( "DIPSW" )
	/* see code @ e90c. The lines this draws can't even be seen because they are erased afterwards */
	PORT_DIPNAME( 0x02, 0x02, "Draw Debug Lines" )
	PORT_DIPSETTING(    0x02, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x01, 0x01, "Freeze" )
	PORT_DIPSETTING(    0x01, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
INPUT_PORTS_END


INPUT_PORTS_START( dangseed )
	PORT_INCLUDE( ns1 )

	PORT_MODIFY( "DIPSW" )
	PORT_DIPNAME( 0x40, 0x40, "Freeze" )
	PORT_DIPSETTING(    0x40, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	/* this doesn't seem to have much use... */
	PORT_DIPNAME( 0x20, 0x20, "Kick Watchdog in IRQ" )
	PORT_DIPSETTING(    0x20, DEF_STR( No ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Yes ) )
	/* to enter the A.D.S. menu, set the dip switch, keep 1p start pressed and press service coin */
	PORT_DIPNAME( 0x04, 0x04, "Auto Data Sampling" )
	PORT_DIPSETTING(    0x04, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
INPUT_PORTS_END


INPUT_PORTS_START( ws90 )
	PORT_INCLUDE( ns1 )

	PORT_MODIFY( "DIPSW" )
	/* see code @ e8ff. The lines this draws can't even be seen because they are erased afterwards */
	PORT_DIPNAME( 0x02, 0x02, "Draw Debug Lines" )
	PORT_DIPSETTING(    0x02, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x01, 0x01, "Freeze" )
	PORT_DIPSETTING(    0x01, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
INPUT_PORTS_END


INPUT_PORTS_START( boxyboy )
	PORT_INCLUDE( ns1 )

	PORT_MODIFY( "DIPSW" )
	PORT_DIPNAME( 0x40, 0x40, "Freeze" )
	PORT_DIPSETTING(    0x40, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
INPUT_PORTS_END


INPUT_PORTS_START( puzlclub )
	PORT_INCLUDE( ns1 )

	PORT_MODIFY( "DIPSW" )
	PORT_DIPNAME( 0x40, 0x40, "Auto Data Sampling" )
	PORT_DIPSETTING(    0x40, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
INPUT_PORTS_END



GAME( 1987, shadowld, 0,        ns1,     shadowld, shadowld, ROT180, "Namco", "Shadowland", 0 )
GAME( 1987, youkaidk, shadowld, ns1,     shadowld, shadowld, ROT180, "Namco", "Yokai Douchuuki (Japan new version)", 0 )
GAME( 1987, yokaidko, shadowld, ns1,     shadowld, shadowld, ROT180, "Namco", "Yokai Douchuuki (Japan old version)", 0 )
GAME( 1987, dspirit,  0,        ns1,     dspirit,  dspirit,  ROT90,  "Namco", "Dragon Spirit (new version)", 0 )
GAME( 1987, dspirito, dspirit,  ns1,     dspirit,  dspirit,  ROT90,  "Namco", "Dragon Spirit (old version)", 0 )
GAME( 1987, blazer,   0,        ns1,     ns1,      blazer,   ROT90,  "Namco", "Blazer (Japan)", 0 )
GAME( 1987, quester,  0,        ns1,     quester,  quester,  ROT90,  "Namco", "Quester (Japan)", 0 )
GAME( 1987, pacmania, 0,        ns1,     pacmania, pacmania, ROT270, "Namco", "Pac-Mania", 0 )
GAME( 1987, pacmanij, pacmania, ns1,     pacmania, pacmania, ROT90,  "Namco", "Pac-Mania (Japan)", 0 )
GAME( 1987, galaga88, 0,        ns1,     galaga88, galaga88, ROT270, "Namco", "Galaga '88", 0 )
GAME( 1987, galag88j, galaga88, ns1,     galaga88, galaga88, ROT90,  "Namco", "Galaga '88 (Japan)", 0 )
GAME( 1988, ws,       0,        ns1,     ns1,      ws,       ROT180, "Namco", "World Stadium (Japan)", 0 )
GAME( 1988, berabohm, 0,        ns1,     berabohm, berabohm, ROT180, "Namco", "Beraboh Man (Japan version C)", 0 )
GAME( 1988, beraboho, berabohm, ns1,     berabohm, berabohm, ROT180, "Namco", "Beraboh Man (Japan version B)", 0 )
GAME( 1988, mmaze,    0,        ns1,     mmaze,    alice,    ROT180, "Namco", "Marchen Maze (Japan)", 0 )
GAME( 1988, bakutotu, 0,        ns1,     bakutotu, bakutotu, ROT180, "Namco", "Bakutotsu Kijuutei", 0 )
GAME( 1988, wldcourt, 0,        ns1,     wldcourt, wldcourt, ROT180, "Namco", "World Court (Japan)", 0 )
GAME( 1988, splatter, 0,        ns1,     splatter, splatter, ROT180, "Namco", "Splatter House (World)", 0 )
GAME( 1988, splattej, splatter, ns1,     splatter, splatter, ROT180, "Namco", "Splatter House (Japan)", 0 )
GAME( 1988, faceoff,  0,        ns1,     faceoff,  faceoff,  ROT180, "Namco", "Face Off (Japan)", 0 )
GAME( 1989, rompers,  0,        ns1,     ns1,      rompers,  ROT90,  "Namco", "Rompers (Japan)", 0 )
GAME( 1989, romperso, rompers,  ns1,     ns1,      rompers,  ROT90,  "Namco", "Rompers (Japan old version)", 0 )
GAME( 1989, blastoff, 0,        ns1,     ns1,      blastoff, ROT90,  "Namco", "Blast Off (Japan)", 0 )
GAME( 1989, ws89,     ws,       ns1,     ws89,     ws89,     ROT180, "Namco", "World Stadium '89 (Japan)", 0 )
GAME( 1989, dangseed, 0,        ns1,     dangseed, dangseed, ROT90,  "Namco", "Dangerous Seed (Japan)", 0 )
GAME( 1990, ws90,     ws,       ns1,     ws90,     ws90,     ROT180, "Namco", "World Stadium '90 (Japan)", 0 )
GAME( 1990, pistoldm, 0,        ns1,     ns1,      pistoldm, ROT0,   "Namco", "Pistol Daimyo no Bouken (Japan)", 0 )
GAME( 1990, boxyboy,  0,        ns1,     boxyboy,  soukobdx, ROT0,   "Namco", "Boxy Boy (US)", 0 )
GAME( 1990, soukobdx, boxyboy,  ns1,     boxyboy,  soukobdx, ROT0,   "Namco", "Souko Ban Deluxe (Japan)", 0 )
GAME( 1990, puzlclub, 0,        ns1,     puzlclub, puzlclub, ROT90,  "Namco", "Puzzle Club (Japan prototype)", 0 )
GAME( 1991, tankfrce, 0,        ns1,     ns1,      tankfrce, ROT0,   "Namco", "Tank Force (US)", 0 )
GAME( 1991, tankfrcj, tankfrce, ns1,     ns1,      tankfrce, ROT0,   "Namco", "Tank Force (Japan)", 0 )

