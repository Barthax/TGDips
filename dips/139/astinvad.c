# MAME 0.139 source snippet.

/*************************************
 *
 *  Port definitions
 *
 *************************************/

static INPUT_PORTS_START( kamikaze )
	PORT_START("IN0")
	PORT_BIT( 0x01, IP_ACTIVE_HIGH, IPT_COIN1 )
	PORT_BIT( 0x02, IP_ACTIVE_HIGH, IPT_START2 )
	PORT_BIT( 0x04, IP_ACTIVE_HIGH, IPT_START1 )
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x10, IP_ACTIVE_HIGH, IPT_BUTTON1 )
	PORT_BIT( 0x20, IP_ACTIVE_HIGH, IPT_JOYSTICK_LEFT )  PORT_2WAY
	PORT_BIT( 0x40, IP_ACTIVE_HIGH, IPT_JOYSTICK_RIGHT ) PORT_2WAY
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_UNUSED )

	PORT_START("IN1")
	PORT_DIPNAME( 0x03, 0x03, DEF_STR( Lives ) )
	PORT_DIPSETTING(    0x03, "3" )
	PORT_DIPSETTING(    0x01, "4" )
	PORT_DIPSETTING(    0x02, "5" )
	PORT_DIPSETTING(    0x00, "6" )
	PORT_BIT( 0x04, IP_ACTIVE_HIGH, IPT_UNUSED )
	PORT_DIPNAME( 0x88, 0x88, DEF_STR( Bonus_Life ) )
	PORT_DIPSETTING(    0x88, "5000" )
	PORT_DIPSETTING(    0x80, "10000" )
	PORT_DIPSETTING(    0x08, "15000" )
	PORT_DIPSETTING(    0x00, "20000" )
	PORT_BIT( 0x10, IP_ACTIVE_HIGH, IPT_BUTTON1 ) PORT_COCKTAIL
	PORT_BIT( 0x20, IP_ACTIVE_HIGH, IPT_JOYSTICK_LEFT )  PORT_2WAY PORT_COCKTAIL
	PORT_BIT( 0x40, IP_ACTIVE_HIGH, IPT_JOYSTICK_RIGHT ) PORT_2WAY PORT_COCKTAIL

	PORT_START("IN2")
	PORT_BIT( 0x01, IP_ACTIVE_HIGH, IPT_VBLANK )
	PORT_BIT( 0xfe, IP_ACTIVE_HIGH, IPT_UNKNOWN )

	PORT_START("CABINET")
	PORT_DIPNAME( 0xff, 0x00, DEF_STR( Cabinet ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Upright ) )
	PORT_DIPSETTING(    0xff, DEF_STR( Cocktail ) )
INPUT_PORTS_END

static INPUT_PORTS_START( astinvad )
	PORT_INCLUDE(kamikaze)

	PORT_MODIFY("IN1")
	PORT_DIPNAME( 0x01, 0x00, DEF_STR( Lives ) )            PORT_DIPLOCATION("SW:2")
	PORT_DIPSETTING(    0x00, "3" )
	PORT_DIPSETTING(    0x01, "4" )
	PORT_DIPNAME( 0x02, 0x02, DEF_STR( Bonus_Life ) )       PORT_DIPLOCATION("SW:1")
	PORT_DIPSETTING(    0x02, "10000" )
	PORT_DIPSETTING(    0x00, "20000" )
	PORT_DIPNAME( 0x88, 0x00, DEF_STR( Coinage ) )          PORT_DIPLOCATION("SW:3,4")
	PORT_DIPSETTING(    0x88, DEF_STR( 3C_1C ) )
	PORT_DIPSETTING(    0x80, DEF_STR( 2C_1C ) )
	PORT_DIPSETTING(    0x00, DEF_STR( 1C_1C ) )
	PORT_DIPSETTING(    0x08, DEF_STR( 1C_2C ) )
INPUT_PORTS_END


static INPUT_PORTS_START( spcking2 )
	PORT_INCLUDE(kamikaze)

	PORT_MODIFY("IN1")
	PORT_DIPNAME( 0x03, 0x00, DEF_STR( Lives ) )
	PORT_DIPSETTING(    0x00, "3" )
	PORT_DIPSETTING(    0x01, "4" )
	PORT_DIPSETTING(    0x02, "5" )
	PORT_DIPSETTING(    0x03, "6" )
	PORT_DIPNAME( 0x08, 0x00, DEF_STR( Bonus_Life ) )
	PORT_DIPSETTING(    0x08, "1000" )
	PORT_DIPSETTING(    0x00, "2000" )
	PORT_DIPNAME( 0x80, 0x00, "Coin Info" )
	PORT_DIPSETTING(    0x80, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
INPUT_PORTS_END


static INPUT_PORTS_START( spaceint )
	PORT_START("IN0")
	PORT_BIT( 0x01, IP_ACTIVE_HIGH, IPT_START1 )
	PORT_BIT( 0x02, IP_ACTIVE_HIGH, IPT_START2 )
	PORT_BIT( 0x04, IP_ACTIVE_HIGH, IPT_JOYSTICK_RIGHT ) PORT_2WAY
	PORT_BIT( 0x08, IP_ACTIVE_HIGH, IPT_JOYSTICK_LEFT )  PORT_2WAY
	PORT_BIT( 0x10, IP_ACTIVE_HIGH, IPT_BUTTON1 )
	PORT_BIT( 0x20, IP_ACTIVE_HIGH, IPT_JOYSTICK_RIGHT ) PORT_2WAY PORT_COCKTAIL
	PORT_BIT( 0x40, IP_ACTIVE_HIGH, IPT_JOYSTICK_LEFT )  PORT_2WAY PORT_COCKTAIL
	PORT_BIT( 0x80, IP_ACTIVE_HIGH, IPT_BUTTON1 ) PORT_COCKTAIL

	PORT_START("IN1")
	PORT_DIPUNUSED( 0x01, IP_ACTIVE_HIGH )
	PORT_DIPNAME( 0x06, 0x00, DEF_STR( Lives ) )            /* code at 0x0d4a */
	PORT_DIPSETTING(    0x00, "3" )
	PORT_DIPSETTING(    0x04, "4" )
	PORT_DIPSETTING(    0x02, "5" )
//  PORT_DIPSETTING(    0x06, "5" )                         /* duplicate settings */
	PORT_DIPNAME( 0x08, 0x00, DEF_STR( Coinage ) )
	PORT_DIPSETTING(    0x00, DEF_STR( 1C_1C ) )
	PORT_DIPSETTING(    0x08, DEF_STR( 1C_2C ) )

	PORT_START("IN2")
	PORT_BIT( 0x01, IP_ACTIVE_HIGH, IPT_COIN1 ) PORT_CHANGED(spaceint_coin_inserted, 0)

	PORT_START("CABINET")
	PORT_DIPNAME( 0xff, 0x00, DEF_STR( Cabinet ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Upright ) )
	PORT_DIPSETTING(    0xff, DEF_STR( Cocktail ) )
INPUT_PORTS_END

static INPUT_PORTS_START( spaceintj )
	PORT_INCLUDE( spaceint )

	PORT_MODIFY("IN1")
	PORT_DIPNAME( 0x06, 0x00, DEF_STR( Lives ) )            /* code at 0x0d37 */
	PORT_DIPSETTING(    0x00, "3" )
	PORT_DIPSETTING(    0x02, "5" )
//  PORT_DIPSETTING(    0x04, "5" )                         /* duplicate settings */
//  PORT_DIPSETTING(    0x06, "5" )                         /* duplicate settings */
INPUT_PORTS_END



/*************************************
 *
 *  Game drivers
 *
 *************************************/

GAME( 1979, kamikaze, 0,        kamikaze, kamikaze, kamikaze, ROT270, "Leijac Corporation", "Kamikaze",      GAME_IMPERFECT_SOUND | GAME_SUPPORTS_SAVE )
GAME( 1980, astinvad, kamikaze, kamikaze, astinvad, kamikaze, ROT270, "Leijac Corporation (Stern Electronics license)", "Astro Invader", GAME_IMPERFECT_SOUND | GAME_SUPPORTS_SAVE )
GAME( 19??, kosmokil, kamikaze, kamikaze, kamikaze, kamikaze, ROT270, "bootleg",            "Kosmo Killer",  GAME_IMPERFECT_SOUND | GAME_SUPPORTS_SAVE ) // says >BEM< Mi Italy but it looks hacked in, dif revision of game tho.
GAME( 1979, spcking2, 0,        spcking2, spcking2, spcking2, ROT270, "Konami",             "Space King 2",  GAME_IMPERFECT_SOUND | GAME_SUPPORTS_SAVE )
GAME( 1980, spaceint, 0,        spaceint, spaceint, 0,        ROT90,  "Shoei",              "Space Intruder", GAME_IMPERFECT_SOUND | GAME_WRONG_COLORS | GAME_SUPPORTS_SAVE )
GAME( 1980, spaceintj,spaceint, spaceint, spaceintj,0,        ROT90,  "Shoei",              "Space Intruder (Japan)", GAME_IMPERFECT_SOUND | GAME_WRONG_COLORS | GAME_SUPPORTS_SAVE )
