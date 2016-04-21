INPUT_PORTS_START( marble )
	PORT_START  /* F20000 */
    PORT_BIT( 0xff, 0x00, IPT_TRACKBALL_X ) PORT_SENSITIVITY(30) PORT_KEYDELTA(30) PORT_REVERSE PORT_PLAYER(1)

	PORT_START  /* F20002 */
    PORT_BIT( 0xff, 0x00, IPT_TRACKBALL_Y ) PORT_SENSITIVITY(30) PORT_KEYDELTA(30) PORT_PLAYER(1)

	PORT_START  /* F20004 */
    PORT_BIT( 0xff, 0x00, IPT_TRACKBALL_X ) PORT_SENSITIVITY(30) PORT_KEYDELTA(30) PORT_REVERSE PORT_PLAYER(2)

	PORT_START  /* F20006 */
    PORT_BIT( 0xff, 0x00, IPT_TRACKBALL_Y ) PORT_SENSITIVITY(30) PORT_KEYDELTA(30) PORT_PLAYER(2)

	PORT_START	/* F60000 */
	PORT_BIT( 0x0001, IP_ACTIVE_LOW, IPT_START1 )
	PORT_BIT( 0x0002, IP_ACTIVE_LOW, IPT_START2 )
	PORT_BIT( 0x0004, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x0008, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x0010, IP_ACTIVE_LOW, IPT_VBLANK )
	PORT_BIT( 0x0020, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_SERVICE( 0x0040, IP_ACTIVE_LOW )
	PORT_BIT( 0x0080, IP_ACTIVE_HIGH, IPT_SPECIAL )
	PORT_BIT( 0xff00, IP_ACTIVE_LOW, IPT_UNUSED )

	PORT_START	/* 1820 (sound) */
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_COIN1 )
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_COIN2 )
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_COIN3 )
	PORT_BIT( 0x08, IP_ACTIVE_HIGH, IPT_SPECIAL )
	PORT_BIT( 0x10, IP_ACTIVE_HIGH, IPT_SPECIAL )
	PORT_BIT( 0x60, IP_ACTIVE_HIGH, IPT_UNUSED )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_SPECIAL )
INPUT_PORTS_END


INPUT_PORTS_START( peterpak )
	PORT_START	/* F40000 */
	PORT_BIT( 0x0f, IP_ACTIVE_HIGH, IPT_UNUSED )
	PORT_BIT( 0x10, IP_ACTIVE_HIGH, IPT_JOYSTICK_UP )
	PORT_BIT( 0x20, IP_ACTIVE_HIGH, IPT_JOYSTICK_DOWN )
	PORT_BIT( 0x40, IP_ACTIVE_HIGH, IPT_JOYSTICK_LEFT )
	PORT_BIT( 0x80, IP_ACTIVE_HIGH, IPT_JOYSTICK_RIGHT )

	PORT_START	/* n/a */
	PORT_BIT( 0xff, IP_ACTIVE_HIGH, IPT_UNUSED )

	PORT_START	/* n/a */
	PORT_BIT( 0xff, IP_ACTIVE_HIGH, IPT_UNUSED )

	PORT_START	/* n/a */
	PORT_BIT( 0xff, IP_ACTIVE_HIGH, IPT_UNUSED )

	PORT_START	/* F60000 */
	PORT_BIT( 0x0001, IP_ACTIVE_LOW, IPT_START1 )
	PORT_BIT( 0x0001, IP_ACTIVE_LOW, IPT_BUTTON1 )
	PORT_BIT( 0x0002, IP_ACTIVE_LOW, IPT_START2 )
	PORT_BIT( 0x0004, IP_ACTIVE_LOW, IPT_BUTTON2 )
	PORT_BIT( 0x0008, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x0010, IP_ACTIVE_LOW, IPT_VBLANK )
	PORT_BIT( 0x0020, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_SERVICE( 0x0040, IP_ACTIVE_LOW )
	PORT_BIT( 0x0080, IP_ACTIVE_HIGH, IPT_SPECIAL )
	PORT_BIT( 0xff00, IP_ACTIVE_LOW, IPT_UNUSED )

	PORT_START	/* 1820 (sound) */
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_COIN1 )
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_COIN2 )
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_COIN3 )
	PORT_BIT( 0x08, IP_ACTIVE_HIGH, IPT_SPECIAL )
	PORT_BIT( 0x10, IP_ACTIVE_HIGH, IPT_SPECIAL )
	PORT_BIT( 0x60, IP_ACTIVE_HIGH, IPT_UNUSED )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_SPECIAL )
INPUT_PORTS_END


INPUT_PORTS_START( indytemp )
	PORT_START	/* F40000 */
	PORT_BIT( 0x0f, IP_ACTIVE_HIGH, IPT_UNUSED )
	PORT_BIT( 0x10, IP_ACTIVE_HIGH, IPT_JOYSTICK_UP )
	PORT_BIT( 0x20, IP_ACTIVE_HIGH, IPT_JOYSTICK_DOWN )
	PORT_BIT( 0x40, IP_ACTIVE_HIGH, IPT_JOYSTICK_LEFT )
	PORT_BIT( 0x80, IP_ACTIVE_HIGH, IPT_JOYSTICK_RIGHT )

	PORT_START	/* n/a */
	PORT_BIT( 0xff, IP_ACTIVE_HIGH, IPT_UNUSED )

	PORT_START	/* n/a */
	PORT_BIT( 0xff, IP_ACTIVE_HIGH, IPT_UNUSED )

	PORT_START	/* n/a */
	PORT_BIT( 0xff, IP_ACTIVE_HIGH, IPT_UNUSED )

	PORT_START	/* F60000 */
	PORT_BIT( 0x0001, IP_ACTIVE_LOW, IPT_START1 )
	PORT_BIT( 0x0001, IP_ACTIVE_LOW, IPT_BUTTON1 )
	PORT_BIT( 0x0002, IP_ACTIVE_LOW, IPT_START2 )
	PORT_BIT( 0x0004, IP_ACTIVE_LOW, IPT_UNKNOWN )	/* freeze? */
	PORT_BIT( 0x0008, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x0010, IP_ACTIVE_LOW, IPT_VBLANK )
	PORT_BIT( 0x0020, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_SERVICE( 0x0040, IP_ACTIVE_LOW )
	PORT_BIT( 0x0080, IP_ACTIVE_HIGH, IPT_SPECIAL )
	PORT_BIT( 0xff00, IP_ACTIVE_LOW, IPT_UNUSED )

	PORT_START	/* 1820 (sound) */
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_COIN1 )
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_COIN2 )
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_COIN3 )
	PORT_BIT( 0x08, IP_ACTIVE_HIGH, IPT_SPECIAL )
	PORT_BIT( 0x10, IP_ACTIVE_HIGH, IPT_SPECIAL )
	PORT_BIT( 0x60, IP_ACTIVE_HIGH, IPT_UNUSED )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_SPECIAL )
INPUT_PORTS_END


INPUT_PORTS_START( roadrunn )
	PORT_START	/* F40000 */
	PORT_BIT( 0xff, 0x80, IPT_AD_STICK_Y ) PORT_MINMAX(0x10,0xf0) PORT_SENSITIVITY(100) PORT_KEYDELTA(10) PORT_PLAYER(1)

	PORT_START	/* F40002 */
	PORT_BIT( 0xff, 0x80, IPT_AD_STICK_X ) PORT_MINMAX(0x10,0xf0) PORT_SENSITIVITY(100) PORT_KEYDELTA(10) PORT_REVERSE PORT_PLAYER(1)

	PORT_START	/* n/a */
	PORT_BIT( 0xff, IP_ACTIVE_LOW, IPT_UNUSED )

	PORT_START	/* n/a */
	PORT_BIT( 0xff, IP_ACTIVE_LOW, IPT_UNUSED )

	PORT_START	/* F60000 */
	PORT_BIT( 0x0001, IP_ACTIVE_LOW, IPT_START1 )
	PORT_BIT( 0x0001, IP_ACTIVE_LOW, IPT_BUTTON1 )
	PORT_BIT( 0x0002, IP_ACTIVE_LOW, IPT_START2 )
	PORT_BIT( 0x0004, IP_ACTIVE_LOW, IPT_BUTTON2 )
	PORT_BIT( 0x0008, IP_ACTIVE_LOW, IPT_BUTTON3 )
	PORT_BIT( 0x0010, IP_ACTIVE_LOW, IPT_VBLANK )
	PORT_BIT( 0x0020, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_SERVICE( 0x0040, IP_ACTIVE_LOW )
	PORT_BIT( 0x0080, IP_ACTIVE_HIGH, IPT_SPECIAL )
	PORT_BIT( 0xff00, IP_ACTIVE_LOW, IPT_UNUSED )

	PORT_START	/* 1820 (sound) */
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_COIN1 )
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_COIN2 )
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_COIN3 )
	PORT_BIT( 0x08, IP_ACTIVE_HIGH, IPT_SPECIAL )
	PORT_BIT( 0x10, IP_ACTIVE_HIGH, IPT_SPECIAL )
	PORT_BIT( 0x60, IP_ACTIVE_HIGH, IPT_UNUSED )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_SPECIAL )
INPUT_PORTS_END


INPUT_PORTS_START( roadblst )
	PORT_START	/* F20000 */
	PORT_BIT( 0xff, 0x40, IPT_DIAL ) PORT_MINMAX(0x00,0x7f) PORT_SENSITIVITY(25) PORT_KEYDELTA(10) PORT_REVERSE

	PORT_START	/* F40000 */
	PORT_BIT( 0xff, 0x00, IPT_PEDAL ) PORT_MINMAX(0x00,0xff) PORT_SENSITIVITY(100) PORT_KEYDELTA(64)

	PORT_START	/* n/a */
	PORT_BIT( 0xff, IP_ACTIVE_HIGH, IPT_UNUSED )

	PORT_START	/* n/a */
	PORT_BIT( 0xff, IP_ACTIVE_HIGH, IPT_UNUSED )

	PORT_START	/* F60000 */
	PORT_BIT( 0x0001, IP_ACTIVE_LOW, IPT_BUTTON3 )
	PORT_BIT( 0x0002, IP_ACTIVE_LOW, IPT_BUTTON2 )
	PORT_BIT( 0x0004, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x0008, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x0010, IP_ACTIVE_LOW, IPT_VBLANK )
	PORT_BIT( 0x0020, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_SERVICE( 0x0040, IP_ACTIVE_LOW )
	PORT_BIT( 0x0080, IP_ACTIVE_HIGH, IPT_SPECIAL )
	PORT_BIT( 0xff00, IP_ACTIVE_LOW, IPT_UNUSED )

	PORT_START	/* 1820 (sound) */
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_COIN1 )
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_COIN2 )
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_COIN3 )
	PORT_BIT( 0x08, IP_ACTIVE_HIGH, IPT_SPECIAL )
	PORT_BIT( 0x10, IP_ACTIVE_HIGH, IPT_SPECIAL )
	PORT_BIT( 0x60, IP_ACTIVE_HIGH, IPT_UNUSED )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_SPECIAL )
INPUT_PORTS_END



GAME( 1984, marble,   0,        atarisy1, marble,   marble,   ROT0, "Atari Games", "Marble Madness (set 1)", 0 )
GAME( 1984, marble2,  marble,   atarisy1, marble,   marble,   ROT0, "Atari Games", "Marble Madness (set 2)", 0 )
GAME( 1984, marble3,  marble,   atarisy1, marble,   marble,   ROT0, "Atari Games", "Marble Madness (set 3)", 0 )
GAME( 1984, marble4,  marble,   atarisy1, marble,   marble,   ROT0, "Atari Games", "Marble Madness (set 4)", 0 )

GAME( 1984, peterpak, 0,        atarisy1, peterpak, peterpak, ROT0, "Atari Games", "Peter Pack-Rat", 0 )

GAME( 1985, indytemp, 0,        atarisy1, indytemp, indytemp, ROT0, "Atari Games", "Indiana Jones and the Temple of Doom (set 1)", 0 )
GAME( 1985, indytem2, indytemp, atarisy1, indytemp, indytemp, ROT0, "Atari Games", "Indiana Jones and the Temple of Doom (set 2)", 0 )
GAME( 1985, indytem3, indytemp, atarisy1, indytemp, indytemp, ROT0, "Atari Games", "Indiana Jones and the Temple of Doom (set 3)", 0 )
GAME( 1985, indytem4, indytemp, atarisy1, indytemp, indytemp, ROT0, "Atari Games", "Indiana Jones and the Temple of Doom (set 4)", 0 )
GAME( 1985, indytemd, indytemp, atarisy1, indytemp, indytemp, ROT0, "Atari Games", "Indiana Jones and the Temple of Doom (German)", 0 )

GAME( 1985, roadrunn, 0,        atarisy1, roadrunn, roadrunn, ROT0, "Atari Games", "Road Runner (rev 2)", 0 )
GAME( 1985, roadrun2, roadrunn, atarisy1, roadrunn, roadrunn, ROT0, "Atari Games", "Road Runner (rev 1+)", 0 )
GAME( 1985, roadrun1, roadrunn, atarisy1, roadrunn, roadrunn, ROT0, "Atari Games", "Road Runner (rev 1)", 0 )

GAME( 1987, roadblst, 0,        atarisy1, roadblst, roadb110, ROT0, "Atari Games", "Road Blasters (upright, rev 4)", 0 )
GAME( 1987, roadblsg, roadblst, atarisy1, roadblst, roadb109, ROT0, "Atari Games", "Road Blasters (upright, German, rev 3)", 0 )
GAME( 1987, roadbls3, roadblst, atarisy1, roadblst, roadb109, ROT0, "Atari Games", "Road Blasters (upright, rev 3)", 0 )
GAME( 1987, roadblg2, roadblst, atarisy1, roadblst, roadb110, ROT0, "Atari Games", "Road Blasters (upright, German, rev 2)", 0 )
GAME( 1987, roadbls2, roadblst, atarisy1, roadblst, roadb110, ROT0, "Atari Games", "Road Blasters (upright, rev 2)", 0 )
GAME( 1987, roadblg1, roadblst, atarisy1, roadblst, roadb109, ROT0, "Atari Games", "Road Blasters (upright, German, rev 1)", 0 )
GAME( 1987, roadbls1, roadblst, atarisy1, roadblst, roadb109, ROT0, "Atari Games", "Road Blasters (upright, rev 1)", 0 )
GAME( 1987, roadblsc, roadblst, atarisy1, roadblst, roadb110, ROT0, "Atari Games", "Road Blasters (cockpit, rev 2)", 0 )
GAME( 1987, roadblcg, roadblst, atarisy1, roadblst, roadb109, ROT0, "Atari Games", "Road Blasters (cockpit, German, rev 1)", GAME_IMPERFECT_GRAPHICS )
GAME( 1987, roadblc1, roadblst, atarisy1, roadblst, roadb109, ROT0, "Atari Games", "Road Blasters (cockpit, rev 1)", GAME_IMPERFECT_GRAPHICS )
