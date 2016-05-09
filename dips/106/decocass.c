INPUT_PORTS_START( decocass )
	PORT_START		/* IN0 */
	PORT_BIT( 0x01, IP_ACTIVE_HIGH,IPT_JOYSTICK_RIGHT )
	PORT_BIT( 0x02, IP_ACTIVE_HIGH,IPT_JOYSTICK_LEFT )
	PORT_BIT( 0x04, IP_ACTIVE_HIGH,IPT_JOYSTICK_UP )
	PORT_BIT( 0x08, IP_ACTIVE_HIGH,IPT_JOYSTICK_DOWN )
	PORT_BIT( 0x10, IP_ACTIVE_HIGH,IPT_BUTTON1 )
	PORT_BIT( 0x20, IP_ACTIVE_HIGH,IPT_BUTTON2 )
	PORT_BIT( 0x40, IP_ACTIVE_HIGH,IPT_UNUSED )
	PORT_BIT( 0x80, IP_ACTIVE_HIGH,IPT_UNUSED )

	PORT_START		/* IN1 */
	PORT_BIT( 0x01, IP_ACTIVE_HIGH,IPT_JOYSTICK_RIGHT ) PORT_COCKTAIL
	PORT_BIT( 0x02, IP_ACTIVE_HIGH,IPT_JOYSTICK_LEFT ) PORT_COCKTAIL
	PORT_BIT( 0x04, IP_ACTIVE_HIGH,IPT_JOYSTICK_UP ) PORT_COCKTAIL
	PORT_BIT( 0x08, IP_ACTIVE_HIGH,IPT_JOYSTICK_DOWN ) PORT_COCKTAIL
	PORT_BIT( 0x10, IP_ACTIVE_HIGH,IPT_BUTTON1 ) PORT_COCKTAIL
	PORT_BIT( 0x20, IP_ACTIVE_HIGH,IPT_BUTTON2 ) PORT_COCKTAIL
	PORT_BIT( 0x40, IP_ACTIVE_HIGH,IPT_UNUSED )
	PORT_BIT( 0x80, IP_ACTIVE_HIGH,IPT_UNUSED )

	PORT_START		/* IN2 */
	PORT_BIT( 0x01, IP_ACTIVE_HIGH,IPT_UNKNOWN )
	PORT_BIT( 0x02, IP_ACTIVE_HIGH,IPT_UNKNOWN )
	PORT_BIT( 0x04, IP_ACTIVE_HIGH,IPT_UNKNOWN )
	PORT_BIT( 0x08, IP_ACTIVE_HIGH,IPT_START1 ) PORT_IMPULSE(1)
	PORT_BIT( 0x10, IP_ACTIVE_HIGH,IPT_START2 ) PORT_IMPULSE(1)
	PORT_BIT( 0x20, IP_ACTIVE_HIGH,IPT_UNKNOWN )
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_COIN2 ) PORT_IMPULSE(1)
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_COIN1 ) PORT_IMPULSE(1)

	PORT_START		/* IN3 */
	PORT_BIT( 0xff, 0x80, IPT_AD_STICK_X ) PORT_MINMAX(0x10,0xf0) PORT_SENSITIVITY(100) PORT_KEYDELTA(10) PORT_PLAYER(1)

	PORT_START		/* IN4 */
	PORT_BIT( 0xff, 0x80, IPT_AD_STICK_Y ) PORT_MINMAX(0x10,0xf0) PORT_SENSITIVITY(100) PORT_KEYDELTA(10) PORT_PLAYER(1)

	PORT_START		/* IN5 */
	PORT_BIT( 0xff, 0x80, IPT_AD_STICK_X ) PORT_MINMAX(0x10,0xf0) PORT_SENSITIVITY(100) PORT_KEYDELTA(10) PORT_PLAYER(2)

	PORT_START		/* IN6 */
	PORT_BIT( 0xff, 0x80, IPT_AD_STICK_Y ) PORT_MINMAX(0x10,0xf0) PORT_SENSITIVITY(100) PORT_KEYDELTA(10) PORT_PLAYER(2)

	PORT_START_TAG("DSW1")
	PORT_DIPNAME( 0x03, 0x03, DEF_STR( Coin_A ) )
	PORT_DIPSETTING(	0x00, DEF_STR( 2C_1C ) )
	PORT_DIPSETTING(	0x03, DEF_STR( 1C_1C ) )
	PORT_DIPSETTING(	0x02, DEF_STR( 1C_2C ) )
	PORT_DIPSETTING(	0x01, DEF_STR( 1C_3C ) )
	PORT_DIPNAME( 0x0c, 0x0c, DEF_STR( Coin_B ) )
	PORT_DIPSETTING(	0x00, DEF_STR( 2C_1C ) )
	PORT_DIPSETTING(	0x0c, DEF_STR( 1C_1C ) )
	PORT_DIPSETTING(	0x08, DEF_STR( 1C_2C ) )
	PORT_DIPSETTING(	0x04, DEF_STR( 1C_3C ) )
	PORT_DIPNAME( 0x30, 0x30, "Board type" )    /* used by the "bios" */
	PORT_DIPSETTING(	0x00, "old" )
	PORT_DIPSETTING(	0x10, "invalid?" )
	PORT_DIPSETTING(	0x20, "invalid?" )
	PORT_DIPSETTING(	0x30, "new" )
	PORT_DIPNAME( 0x40, 0x00, DEF_STR( Cabinet ) )
	PORT_DIPSETTING(	0x00, DEF_STR( Upright ) )
	PORT_DIPSETTING(	0x40, DEF_STR( Cocktail ) )
	PORT_BIT( 0x80, IP_ACTIVE_HIGH, IPT_VBLANK	)

	PORT_START_TAG("DSW2")
	PORT_DIPNAME( 0x01, 0x01, DEF_STR( Unknown ) )
	PORT_DIPSETTING(    0x01, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x02, 0x02, DEF_STR( Unknown ) )
	PORT_DIPSETTING(    0x02, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x04, 0x04, DEF_STR( Unknown ) )
	PORT_DIPSETTING(    0x04, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x08, 0x08, DEF_STR( Unknown ) )
	PORT_DIPSETTING(    0x08, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x10, 0x10, DEF_STR( Unknown ) )
	PORT_DIPSETTING(    0x10, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x20, 0x20, DEF_STR( Unknown ) )
	PORT_DIPSETTING(    0x20, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x40, 0x40, DEF_STR( Unknown ) )
	PORT_DIPSETTING(    0x40, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x80, 0x80, DEF_STR( Unknown ) )
	PORT_DIPSETTING(	0x00, DEF_STR( Off ) )
	PORT_DIPSETTING(	0x80, DEF_STR( On ) )
INPUT_PORTS_END

INPUT_PORTS_START( dc_btime )
	PORT_INCLUDE( decocass )

	PORT_MODIFY("DSW2")
	PORT_DIPNAME( 0x01, 0x01, DEF_STR( Lives ) )
	PORT_DIPSETTING(	0x01, "3" )
	PORT_DIPSETTING(	0x00, "5" )
	PORT_DIPNAME( 0x06, 0x06, DEF_STR( Bonus_Life ) )
	PORT_DIPSETTING(	0x06, "20000" )
	PORT_DIPSETTING(	0x04, "30000" )
	PORT_DIPSETTING(	0x02, "40000"  )
	PORT_DIPSETTING(	0x00, "50000"  )
	PORT_DIPNAME( 0x08, 0x08, "Enemies" )
	PORT_DIPSETTING(	0x08, "4" )
	PORT_DIPSETTING(	0x00, "6" )
	PORT_DIPNAME( 0x10, 0x10, "End of Level Pepper" )
	PORT_DIPSETTING(	0x10, DEF_STR( No ) )
	PORT_DIPSETTING(	0x00, DEF_STR( Yes ) )
	PORT_DIPNAME( 0x20, 0x20, DEF_STR( Unknown ) )
	PORT_DIPSETTING(	0x00, DEF_STR( Off ) )
	PORT_DIPSETTING(	0x20, DEF_STR( On ) )
	PORT_DIPNAME( 0x40, 0x00, DEF_STR( Unknown ) )
	PORT_DIPSETTING(	0x00, DEF_STR( Off ) )
	PORT_DIPSETTING(	0x40, DEF_STR( On ) )
	PORT_DIPNAME( 0x80, 0x80, DEF_STR( Unknown ) )
	PORT_DIPSETTING(	0x00, DEF_STR( Off ) )
	PORT_DIPSETTING(	0x80, DEF_STR( On ) )
INPUT_PORTS_END



GAMEB( 1981, decocass, 0,        decocass, decocass, decocass, decocass, ROT270, "Data East Corporation", "Cassette System", NOT_A_DRIVER )
GAMEB( 1981, ctsttape, decocass, decocass, ctsttape, decocass, decocass, ROT270, "Data East Corporation", "Test Tape (Cassette)", 0 )
GAMEB( 1981, clocknch, decocass, decocass, clocknch, decocass, decocass, ROT270, "Data East Corporation", "Lock'n'Chase (Cassette)", 0 )
GAMEB( 1981, ctisland, decocass, decocass, ctisland, decocass, decocrom, ROT270, "Data East Corporation", "Treasure Island (Cassette, set 1)", 0 )
GAMEB( 1981, ctislnd2, ctisland, decocass, ctisland, decocass, decocrom, ROT270, "Data East Corporation", "Treasure Island (Cassette, set 2)", 0 )
GAMEB( 1981, ctislnd3, ctisland, decocass, ctisland, decocass, decocrom, ROT270, "Data East Corporation", "Treasure Island (Cassette, set 3)", GAME_NOT_WORKING ) /* Different Bitswap? */
GAMEB( 1981, csuperas, decocass, decocass, csuperas, decocass, decocass, ROT270, "Data East Corporation", "Super Astro Fighter (Cassette)", 0 )
GAMEB( 1981, castfant, decocass, decocass, castfant, decocass, decocass, ROT270, "Data East Corporation", "Astro Fantasia (Cassette)", 0 )
GAMEB( 1981, cluckypo, decocass, decocass, cluckypo, decocass, decocass, ROT270, "Data East Corporation", "Lucky Poker (Cassette)", 0 )
GAMEB( 1981, cterrani, decocass, decocass, cterrani, decocass, decocass, ROT270, "Data East Corporation", "Terranean (Cassette)", 0 )
GAMEB( 1982, cexplore, decocass, decocass, cexplore, decocass, decocass, ROT270, "Data East Corporation", "Explorer (Cassette)", GAME_NOT_WORKING )
GAMEB( 1981, cprogolf, decocass, decocass, cprogolf, decocass, decocass, ROT270, "Data East Corporation", "Pro Golf (Cassette)", 0 )
GAMEB( 1982, cmissnx,  decocass, decocass, cmissnx,  decocass, decocass, ROT270, "Data East Corporation", "Mission-X (Cassette)", 0 )
GAMEB( 1982, cdiscon1, decocass, decocass, cdiscon1, decocass, decocass, ROT270, "Data East Corporation", "Disco No.1 (Cassette)", 0 )
GAMEB( 1982, csweetht, cdiscon1, decocass, cdiscon1, decocass, decocass, ROT270, "Data East Corporation", "Sweet Heart (Cassette)", 0 )
GAMEB( 1982, cptennis, decocass, decocass, cptennis, decocass, decocass, ROT270, "Data East Corporation", "Pro Tennis (Cassette)", 0 )
GAMEB( 1982, ctornado, decocass, decocass, ctornado, decocass, decocass, ROT270, "Data East Corporation", "Tornado (Cassette)", 0 )
GAMEB( 1982, cburnrub, decocass, decocass, cburnrub, decocass, decocass, ROT270, "Data East Corporation", "Burnin' Rubber (Cassette, set 1)", 0 )
GAMEB( 1982, cburnrb2, cburnrub, decocass, cburnrub, decocass, decocass, ROT270, "Data East Corporation", "Burnin' Rubber (Cassette, set 2)", 0 )
GAMEB( 1982, cbnj,     cburnrub, decocass, cbnj,     decocass, decocass, ROT270, "Data East Corporation", "Bump N Jump (Cassette)", 0 )
GAMEB( 1983, cbtime,   decocass, decocass, cbtime,   dc_btime, decocass, ROT270, "Data East Corporation", "Burger Time (Cassette)", 0 )
GAMEB( 1983, cgraplop, decocass, decocass, cgraplop, decocass, decocass, ROT270, "Data East Corporation", "Graplop (aka Cluster Buster) (Cassette, set 1)", 0 )
GAMEB( 1983, cgraplp2, cgraplop, decocass, cgraplp2, decocass, decocass, ROT270, "Data East Corporation", "Graplop (aka Cluster Buster) (Cassette, set 2)", GAME_NOT_WORKING )
GAMEB( 1983, clapapa,  decocass, decocass, clapapa,  decocass, decocass, ROT270, "Data East Corporation", "Rootin' Tootin' (aka La.Pa.Pa) (Cassette)" , 0) /* Displays 'LaPaPa during attract */
GAMEB( 1983, clapapa2, clapapa,  decocass, clapapa,  decocass, decocass, ROT270, "Data East Corporation", "Rootin' Tootin' (Cassette)" , 0)				/* Displays 'Rootin' Tootin' during attract */
GAMEB( 1984, cfghtice, decocass, decocass, cfghtice, decocass, decocass, ROT270, "Data East Corporation", "Fighting Ice Hockey (Cassette)", 0 )
GAMEB( 1983, cprobowl, decocass, decocass, cprobowl, decocass, decocass, ROT270, "Data East Corporation", "Pro Bowling (Cassette)", 0 )
GAMEB( 1983, cnightst, decocass, decocass, cnightst, decocass, decocass, ROT270, "Data East Corporation", "Night Star (Cassette, set 1)", 0 )
GAMEB( 1983, cnights2, cnightst, decocass, cnightst, decocass, decocass, ROT270, "Data East Corporation", "Night Star (Cassette, set 2)", 0 )
GAMEB( 1983, cprosocc, decocass, decocass, cprosocc, decocass, decocass, ROT270, "Data East Corporation", "Pro Soccer (Cassette)", 0 )
GAMEB( 1983, czeroize, decocass, decocass, czeroize, decocass, decocass, ROT270, "Data East Corporation", "Zeroize (Cassette)", 0 )
GAMEB( 1984, cppicf,   decocass, decocass, cppicf,   decocass, decocass, ROT270, "Data East Corporation", "Peter Pepper's Ice Cream Factory (Cassette, set 1)", 0 )
GAMEB( 1984, cppicf2,  cppicf,   decocass, cppicf,   decocass, decocass, ROT270, "Data East Corporation", "Peter Pepper's Ice Cream Factory (Cassette, set 2)", 0 )
GAMEB( 1984, cscrtry,  decocass, decocass, cscrtry,  decocass, decocass, ROT270, "Data East Corporation", "Scrum Try (Cassette, set 1)", 0 )
GAMEB( 1984, cscrtry2, cscrtry,  decocass, cscrtry,  decocass, decocass, ROT270, "Data East Corporation", "Scrum Try (Cassette, set 2)", 0 )
GAMEB( 1985, cflyball, decocass, decocass, cflyball, decocass, decocass, ROT270, "Data East Corporation", "Flying Ball (Cassette)", GAME_NO_SOUND )
GAMEB( 1985, cbdash,   decocass, decocass, cbdash,   decocass, decocass, ROT270, "Data East Corporation", "Boulder Dash (Cassette)", 0 )

/* The following may be missing dongle data if they're not Type 1 */
GAMEB( 1985, chwy,     decocass, decocass, decocass, decocass, decocass, ROT270, "Data East Corporation", "Highway Chase? (Cassette)", GAME_NOT_WORKING )
