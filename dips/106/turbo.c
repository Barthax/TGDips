/*************************************
 *
 *  Port definitions
 *
 *************************************/

INPUT_PORTS_START( turbo )
	PORT_START		/* IN0 */
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_BUTTON2 )				/* ACCEL B */
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_BUTTON1 )				/* ACCEL A */
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_BUTTON3 ) PORT_TOGGLE	/* SHIFT */
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_START1 )
	PORT_SERVICE_NO_TOGGLE( 0x10, IP_ACTIVE_LOW )
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_SERVICE1 )
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_COIN2 )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_COIN1 )

	PORT_START	/* DSW 1 */
	PORT_DIPNAME( 0x03, 0x03, "Car On Extended Play" )
	PORT_DIPSETTING( 0x03, "1" )
	PORT_DIPSETTING( 0x02, "2" )
	PORT_DIPSETTING( 0x01, "3" )
	PORT_DIPSETTING( 0x00, "4" )
	PORT_DIPNAME( 0x04, 0x04, DEF_STR( Game_Time ) )
	PORT_DIPSETTING( 0x00, "Fixed (55 sec)" )
	PORT_DIPSETTING( 0x04, "Adjustable" )
	PORT_DIPNAME( 0x08, 0x00, DEF_STR( Difficulty ) )
	PORT_DIPSETTING( 0x00, DEF_STR( Easy ))
	PORT_DIPSETTING( 0x08, DEF_STR( Hard ))
	PORT_DIPNAME( 0x10, 0x00, "Game Mode" )
	PORT_DIPSETTING( 0x10, "No Collisions (cheat)" )
	PORT_DIPSETTING( 0x00, DEF_STR( Normal ) )
	PORT_DIPNAME( 0x20, 0x00, "Initial Entry" )
	PORT_DIPSETTING( 0x20, DEF_STR( Off ))
	PORT_DIPSETTING( 0x00, DEF_STR( On ))
	PORT_BIT( 0xc0, 0xc0, IPT_UNUSED )

	PORT_START	/* DSW 2 */
	PORT_DIPNAME( 0x03, 0x03, DEF_STR( Game_Time ) )
	PORT_DIPSETTING( 0x00, "60 seconds" )
	PORT_DIPSETTING( 0x01, "70 seconds" )
	PORT_DIPSETTING( 0x02, "80 seconds" )
	PORT_DIPSETTING( 0x03, "90 seconds" )
	PORT_DIPNAME( 0x1c, 0x1c, DEF_STR( Coin_B ))
	PORT_DIPSETTING(	0x18, DEF_STR( 4C_1C ))
	PORT_DIPSETTING(	0x14, DEF_STR( 3C_1C ))
	PORT_DIPSETTING(	0x10, DEF_STR( 2C_1C ))
/*  PORT_DIPSETTING(    0x00, DEF_STR( 1C_1C ))*/
	PORT_DIPSETTING(	0x1c, DEF_STR( 1C_1C ))
	PORT_DIPSETTING(	0x04, DEF_STR( 1C_2C ))
	PORT_DIPSETTING(	0x08, DEF_STR( 1C_3C ))
	PORT_DIPSETTING(	0x0c, DEF_STR( 1C_6C ))
	PORT_DIPNAME( 0xe0, 0xe0, DEF_STR( Coin_A ))
	PORT_DIPSETTING(	0xc0, DEF_STR( 4C_1C ))
	PORT_DIPSETTING(	0xa0, DEF_STR( 3C_1C ))
	PORT_DIPSETTING(	0x80, DEF_STR( 2C_1C ))
/*  PORT_DIPSETTING(    0x00, DEF_STR( 1C_1C ))*/
	PORT_DIPSETTING(	0xe0, DEF_STR( 1C_1C ))
	PORT_DIPSETTING(	0x20, DEF_STR( 1C_2C ))
	PORT_DIPSETTING(	0x40, DEF_STR( 1C_3C ))
	PORT_DIPSETTING(	0x60, DEF_STR( 1C_6C ))

	PORT_START	/* DSW 3 */
	PORT_BIT( 0x0f, 0x00, IPT_UNUSED )		/* Merged with collision bits */
	PORT_BIT( 0x30, 0x00, IPT_UNUSED )
	PORT_DIPNAME( 0x40, 0x40, "Tachometer" )
	PORT_DIPSETTING(	0x40, "Analog (Meter)")
	PORT_DIPSETTING(	0x00, "Digital (led)")
	PORT_DIPNAME( 0x80, 0x80, "Sound System" )
	PORT_DIPSETTING(	0x80, DEF_STR( Upright ) )
	PORT_DIPSETTING(	0x00, "Cockpit")

	PORT_START		/* IN0 */
	PORT_BIT( 0xff, 0, IPT_DIAL ) PORT_SENSITIVITY(10) PORT_KEYDELTA(30) PORT_RESET
INPUT_PORTS_END


INPUT_PORTS_START( subroc3d )
	PORT_START
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN )
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_JOYSTICK_UP )

	PORT_START
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT )
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT )
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_BUTTON1 )
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_START1 )
	PORT_SERVICE_NO_TOGGLE( 0x10, 0x10 )
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_SERVICE1 )
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_COIN2 )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_COIN1 )

	PORT_START  /* DSW 2 */
	PORT_DIPNAME( 0x07, 0x00, DEF_STR( Coin_A ))
	PORT_DIPSETTING(    0x07, DEF_STR( 5C_1C ) )
	PORT_DIPSETTING(    0x06, DEF_STR( 4C_1C ) )
	PORT_DIPSETTING(    0x05, DEF_STR( 3C_1C ) )
	PORT_DIPSETTING(    0x04, DEF_STR( 2C_1C ) )
	PORT_DIPSETTING(    0x00, DEF_STR( 1C_1C ) )
	PORT_DIPSETTING(    0x01, DEF_STR( 1C_2C ) )
	PORT_DIPSETTING(    0x02, DEF_STR( 1C_3C ) )
	PORT_DIPSETTING(    0x03, DEF_STR( 1C_6C ) )
	PORT_DIPNAME( 0x38, 0x00, DEF_STR( Coin_B ) )
	PORT_DIPSETTING(    0x38, DEF_STR( 5C_1C ) )
	PORT_DIPSETTING(    0x30, DEF_STR( 4C_1C ) )
	PORT_DIPSETTING(    0x28, DEF_STR( 3C_1C ) )
	PORT_DIPSETTING(    0x20, DEF_STR( 2C_1C ) )
	PORT_DIPSETTING(    0x00, DEF_STR( 1C_1C ) )
	PORT_DIPSETTING(    0x08, DEF_STR( 1C_2C ) )
	PORT_DIPSETTING(    0x10, DEF_STR( 1C_3C ) )
	PORT_DIPSETTING(    0x18, DEF_STR( 1C_6C ) )
	PORT_DIPNAME( 0xc0, 0x40, "Ships" )
	PORT_DIPSETTING(    0x00, "2" )
	PORT_DIPSETTING(    0x40, "3" )
	PORT_DIPSETTING(    0x80, "4" )
	PORT_DIPSETTING(    0xc0, "5" )

	PORT_START  /* DSW 3 */
	PORT_DIPNAME( 0x03, 0x03, "Extra Ship" )
	PORT_DIPSETTING(    0x00, "20000" )
	PORT_DIPSETTING(    0x01, "40000" )
	PORT_DIPSETTING(    0x02, "60000" )
	PORT_DIPSETTING(    0x03, "80000" )
	PORT_DIPNAME( 0x04, 0x04, "Initial Input" )
	PORT_DIPSETTING(    0x00, "Disable" )
	PORT_DIPSETTING(    0x04, "Enable" )
	PORT_DIPNAME( 0x08, 0x08, DEF_STR( Difficulty ) )
	PORT_DIPSETTING(    0x00, "Difficult" )
	PORT_DIPSETTING(    0x08, DEF_STR( Normal ) )
	PORT_DIPNAME( 0x10, 0x10, "Play" )
	PORT_DIPSETTING(    0x00, "Free" )
	PORT_DIPSETTING(    0x10, DEF_STR( Normal ) )
	PORT_DIPNAME( 0x20, 0x20, "Motion" )
	PORT_DIPSETTING(    0x00, "Stop" )
	PORT_DIPSETTING(    0x20, DEF_STR( Normal ) )
	PORT_DIPNAME( 0x40, 0x00, "Screen" )
	PORT_DIPSETTING(    0x00, DEF_STR( Mono ) )
	PORT_DIPSETTING(    0x40, DEF_STR( Stereo ) )
	PORT_DIPNAME( 0x80, 0x80, "Game" )
	PORT_DIPSETTING(    0x00, "Endless" )
	PORT_DIPSETTING(    0x80, DEF_STR( Normal ) )

	PORT_START  /* DSW 1 */					/* Unused */
INPUT_PORTS_END


INPUT_PORTS_START( buckrog )
	PORT_START
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_START2 )
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_BUTTON3 ) // Accel Hi
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_BUTTON2 ) // Accel Lo
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_JOYSTICK_UP )

	PORT_START /* Inputs */
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT )
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT )
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_BUTTON1 )
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_START1 )
	PORT_SERVICE_NO_TOGGLE( 0x10, 0x10 )
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_SERVICE1 )
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_COIN2 )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_COIN1 )

	PORT_START  /* DSW 1 */
	PORT_DIPNAME( 0x07, 0x00, DEF_STR( Coin_A ))
	PORT_DIPSETTING(    0x07, DEF_STR( 5C_1C ) )
	PORT_DIPSETTING(    0x06, DEF_STR( 4C_1C ) )
	PORT_DIPSETTING(    0x05, DEF_STR( 3C_1C ) )
	PORT_DIPSETTING(    0x04, DEF_STR( 2C_1C ) )
	PORT_DIPSETTING(    0x00, DEF_STR( 1C_1C ) )
	PORT_DIPSETTING(    0x01, DEF_STR( 1C_2C ) )
	PORT_DIPSETTING(    0x02, DEF_STR( 1C_3C ) )
	PORT_DIPSETTING(    0x03, DEF_STR( 1C_6C ) )
	PORT_DIPNAME( 0x38, 0x00, DEF_STR( Coin_B ) )
	PORT_DIPSETTING(    0x38, DEF_STR( 5C_1C ) )
	PORT_DIPSETTING(    0x30, DEF_STR( 4C_1C ) )
	PORT_DIPSETTING(    0x28, DEF_STR( 3C_1C ) )
	PORT_DIPSETTING(    0x20, DEF_STR( 2C_1C ) )
	PORT_DIPSETTING(    0x00, DEF_STR( 1C_1C ) )
	PORT_DIPSETTING(    0x08, DEF_STR( 1C_2C ) )
	PORT_DIPSETTING(    0x10, DEF_STR( 1C_3C ) )
	PORT_DIPSETTING(    0x18, DEF_STR( 1C_6C ) )

	PORT_START  /* DSW 2 */
	PORT_DIPNAME( 0x01, 0x00, "Collisions" )
	PORT_DIPSETTING(    0x01, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x02, 0x02, "Accel by" )
	PORT_DIPSETTING(    0x00, "Pedal" )
	PORT_DIPSETTING(    0x02, "Button" )
	PORT_DIPNAME( 0x04, 0x00, "Best 5 Scores" )
	PORT_DIPSETTING(    0x04, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x08, 0x00, "Score Display" )
	PORT_DIPSETTING(    0x00, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x08, DEF_STR( On ) )
	PORT_DIPNAME( 0x10, 0x10, DEF_STR( Difficulty ) )
	PORT_DIPSETTING(    0x00, "Difficult" )
	PORT_DIPSETTING(    0x10, DEF_STR( Normal ) )
	PORT_DIPNAME( 0x60, 0x00, "Extra Ships" )
	PORT_DIPSETTING(    0x00, "3" )
	PORT_DIPSETTING(    0x20, "4" )
	PORT_DIPSETTING(    0x40, "5" )
	PORT_DIPSETTING(    0x60, "6" )
	PORT_DIPNAME( 0x80, 0x00, DEF_STR( Cabinet ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Upright ) )
	PORT_DIPSETTING(    0x80, "Cockpit" )
INPUT_PORTS_END


/*************************************
 *
 *  Game drivers
 *
 *************************************/

GAME( 1981, turbo,    0,       turbo,    turbo,    0,              ROT270,             "Sega", "Turbo", GAME_NO_COCKTAIL )
GAME( 1981, turboa,   turbo,   turbo,    turbo,    decode_turbo,   ROT270,             "Sega", "Turbo (encrypted set 1)", GAME_NO_COCKTAIL )
GAME( 1981, turbob,   turbo,   turbo,    turbo,    decode_turbo,   ROT270,             "Sega", "Turbo (encrypted set 2)", GAME_NO_COCKTAIL )
GAME( 1982, subroc3d, 0,       subroc3d, subroc3d, 0,              ORIENTATION_FLIP_X, "Sega", "Subroc-3D", 0 )
GAME( 1982, buckrog,  0,       buckrog,  buckrog,  decode_buckrog, ROT0,               "Sega", "Buck Rogers: Planet of Zoom", 0 )
GAME( 1982, zoom909,  buckrog, buckrog,  buckrog,  decode_buckrog, ROT0,               "Sega", "Zoom 909", 0 )
GAME( 1982, buckrogn, buckrog, buckrog,  buckrog,  0,              ROT0,               "Sega", "Buck Rogers: Planet of Zoom (not encrypted)", 0 )
