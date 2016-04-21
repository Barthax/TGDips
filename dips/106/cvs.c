INPUT_PORTS_START( cvs )

	PORT_START	/* Matrix 0 */
    PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_START1 )				/* Confirmed */
    PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_START2 ) 		  	/* Confirmed */
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_COIN2 )				/* Confirmed */
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_COIN1 )				/* Confirmed */
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_COCKTAIL
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_BUTTON1 )			/* Confirmed */
    PORT_BIT( 0xC0, IP_ACTIVE_LOW, IPT_UNKNOWN )

	PORT_START	/* Dunno */
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_BUTTON2) PORT_COCKTAIL
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_BUTTON2 )			/* Confirmed */
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT )		/* Confirmed */
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT ) 		/* Confirmed */
    PORT_BIT( 0xcc, IP_ACTIVE_LOW, IPT_UNKNOWN )

	PORT_START	/* Dunno */
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_COIN2 )				/* Duplicate? */
    PORT_BIT( 0xfe, IP_ACTIVE_LOW, IPT_UNKNOWN )

	PORT_START	/* Dunno */
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_JOYSTICK_UP )		/* Confirmed */
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN )		/* Confirmed */
    PORT_BIT( 0xcf, IP_ACTIVE_LOW, IPT_UNKNOWN )

	PORT_START	/* SW BANK 3 */
	PORT_DIPNAME( 0x01, 0x00, "Colour" )
	PORT_DIPSETTING(    0x00, "option 1" )
	PORT_DIPSETTING(    0x01, "option 2" )
	PORT_DIPNAME( 0x02, 0x02, DEF_STR( Cabinet ))
	PORT_DIPSETTING(    0x02, DEF_STR( Upright ))
	PORT_DIPSETTING(    0x00, DEF_STR( Cocktail ))
    PORT_DIPNAME( 0x0C, 0x00, "Bonus" )
    PORT_DIPSETTING(    0x00, "10k only" )
    PORT_DIPSETTING(    0x04, "20k only" )
    PORT_DIPSETTING(    0x08, "30k and every 40k" )
    PORT_DIPSETTING(    0x0C, "40k and every 80k" )
	PORT_DIPNAME( 0x10, 0x00, "Registration Length" )
	PORT_DIPSETTING(    0x00, "3" )
	PORT_DIPSETTING(    0x10, "10" )
	PORT_DIPNAME( 0x20, 0x00, "Registration" )
	PORT_DIPSETTING(    0x20, DEF_STR( Off ))
	PORT_DIPSETTING(    0x00, DEF_STR( On ))

    PORT_START	/* SW BANK 2 */
	PORT_DIPNAME( 0x03, 0x00, "Coins for 1 Play" )			/* Confirmed */
	PORT_DIPSETTING(    0x00, "1" )
	PORT_DIPSETTING(    0x01, "2" )
    PORT_DIPSETTING(    0x02, "3" )
    PORT_DIPSETTING(    0x03, "4" )
    PORT_DIPNAME( 0x0C, 0x0C, "Plays for 1 Coin" )			/* Confirmed */
    PORT_DIPSETTING(    0x0C, "2" )
    PORT_DIPSETTING(    0x08, "3" )
    PORT_DIPSETTING(    0x04, "4" )
    PORT_DIPSETTING(    0x00, "5" )
	PORT_DIPNAME( 0x10, 0x00, DEF_STR( Lives ))				/* Confirmed */
	PORT_DIPSETTING(    0x00, "3" )
	PORT_DIPSETTING(    0x10, "5" )
	PORT_DIPNAME( 0x20, 0x00, "Meter Pulses" )
	PORT_DIPSETTING(    0x00, "2" )
	PORT_DIPSETTING(    0x20, "5" )

	PORT_START	/* SENSE */
	PORT_BIT( 0x80, IP_ACTIVE_HIGH, IPT_VBLANK )

INPUT_PORTS_END

Used across all the CVS games
GAME( 1981, cosmos,      cvs,      cvs,      cvs,    cosmos,     ROT90, "Century Electronics", "Cosmos", GAME_IMPERFECT_SOUND | GAME_NO_COCKTAIL )
GAME( 1981, darkwar,     cvs,      cvs,      cvs,    0,          ROT90, "Century Electronics", "Dark Warrior", GAME_IMPERFECT_SOUND | GAME_NO_COCKTAIL )
GAME( 1981, spacefrt,    cvs,      cvs,      cvs,    spacefrt,   ROT90, "Century Electronics", "Space Fortress", GAME_IMPERFECT_SOUND | GAME_NO_COCKTAIL )
GAME( 1982, 8ball,       cvs,      cvs,      cvs,    0,          ROT90, "Century Electronics", "Video Eight Ball", GAME_IMPERFECT_SOUND | GAME_NO_COCKTAIL )
GAME( 1982, 8ball1,      8ball,    cvs,      cvs,    0,          ROT90, "Century Electronics", "Video Eight Ball (Rev.1)", GAME_IMPERFECT_SOUND | GAME_NO_COCKTAIL )
GAME( 1982, logger,      cvs,      cvs,      cvs,    0,          ROT90, "Century Electronics", "Logger", GAME_IMPERFECT_SOUND | GAME_NO_COCKTAIL )
GAME( 1982, dazzler,     cvs,      cvs,      cvs,    0,          ROT90, "Century Electronics", "Dazzler", GAME_IMPERFECT_SOUND | GAME_NO_COCKTAIL )
GAME( 1982, wallst,      cvs,      cvs,      cvs,    0,          ROT90, "Century Electronics", "Wall Street", GAME_IMPERFECT_SOUND | GAME_NO_COCKTAIL )
GAME( 1982, radarzon,    cvs,      cvs,      cvs,    0,          ROT90, "Century Electronics", "Radar Zone", GAME_IMPERFECT_SOUND | GAME_NO_COCKTAIL )
GAME( 1982, radarzn1,    radarzon, cvs,      cvs,    0,          ROT90, "Century Electronics", "Radar Zone (Rev.1)", GAME_IMPERFECT_SOUND | GAME_NO_COCKTAIL )
GAME( 1982, radarznt,    radarzon, cvs,      cvs,    0,          ROT90, "Century Electronics (Tuni Electro Service Inc)", "Radar Zone (Tuni)", GAME_IMPERFECT_SOUND | GAME_NO_COCKTAIL )
GAME( 1982, outline,     radarzon, cvs,      cvs,    0,          ROT90, "Century Electronics", "Outline", GAME_IMPERFECT_SOUND | GAME_NO_COCKTAIL )
GAME( 1982, goldbug,     cvs,      cvs,      cvs,    goldbug,    ROT90, "Century Electronics", "Gold Bug", GAME_IMPERFECT_SOUND | GAME_NO_COCKTAIL )
GAME( 1982, diggerc,     cvs,      cvs,      cvs,    0,          ROT90, "Century Electronics", "Digger (CVS)", GAME_IMPERFECT_SOUND | GAME_NO_COCKTAIL )
GAME( 1983, heartatk,    cvs,      cvs,      cvs,    0,          ROT90, "Century Electronics", "Heart Attack", GAME_IMPERFECT_SOUND | GAME_NO_COCKTAIL )
GAME( 1983, hunchbak,    cvs,      cvs,      cvs,    0,          ROT90, "Century Electronics", "Hunchback", GAME_IMPERFECT_SOUND | GAME_NO_COCKTAIL )
GAME( 1983, superbik,    cvs,      cvs,      cvs,    superbik,   ROT90, "Century Electronics", "Superbike", GAME_IMPERFECT_SOUND | GAME_NO_COCKTAIL )
GAME( 1983, raiders,     cvs,      cvs,      cvs,    raiders,    ROT90, "Century Electronics", "Raiders", GAME_IMPERFECT_SOUND | GAME_NO_COCKTAIL )
GAME( 1983, hero,        cvs,      cvs,      cvs,    hero,       ROT90, "Seatongrove Ltd",     "Hero", GAME_IMPERFECT_SOUND | GAME_NO_COCKTAIL )
GAME( 1984, huncholy,    cvs,      cvs,      cvs,    huncholy,   ROT90, "Seatongrove Ltd",     "Hunchback Olympic", GAME_IMPERFECT_SOUND | GAME_NO_COCKTAIL )
