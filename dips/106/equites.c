/******************************************************************************/
// Common Port Map

#define EQUITES_PLAYER_INPUT_LSB( button1, button2, button3, start ) \
	PORT_BIT( 0x0001, IP_ACTIVE_HIGH, IPT_JOYSTICK_UP ) PORT_8WAY \
	PORT_BIT( 0x0002, IP_ACTIVE_HIGH, IPT_JOYSTICK_DOWN ) PORT_8WAY \
	PORT_BIT( 0x0004, IP_ACTIVE_HIGH, IPT_JOYSTICK_RIGHT ) PORT_8WAY \
	PORT_BIT( 0x0008, IP_ACTIVE_HIGH, IPT_JOYSTICK_LEFT ) PORT_8WAY \
	PORT_BIT( 0x0010, IP_ACTIVE_HIGH, button1 ) \
	PORT_BIT( 0x0020, IP_ACTIVE_HIGH, button2 ) \
	PORT_BIT( 0x0040, IP_ACTIVE_HIGH, button3 ) \
	PORT_BIT( 0x0080, IP_ACTIVE_HIGH, start )

#define EQUITES_PLAYER_INPUT_MSB( button1, button2, button3, start ) \
	PORT_BIT( 0x0100, IP_ACTIVE_HIGH, IPT_JOYSTICK_UP ) PORT_8WAY PORT_COCKTAIL \
	PORT_BIT( 0x0200, IP_ACTIVE_HIGH, IPT_JOYSTICK_DOWN ) PORT_8WAY PORT_COCKTAIL \
	PORT_BIT( 0x0400, IP_ACTIVE_HIGH, IPT_JOYSTICK_RIGHT ) PORT_8WAY PORT_COCKTAIL \
	PORT_BIT( 0x0800, IP_ACTIVE_HIGH, IPT_JOYSTICK_LEFT ) PORT_8WAY PORT_COCKTAIL \
	PORT_BIT( 0x1000, IP_ACTIVE_HIGH, button1 ) PORT_COCKTAIL \
	PORT_BIT( 0x2000, IP_ACTIVE_HIGH, button2 ) PORT_COCKTAIL \
	PORT_BIT( 0x4000, IP_ACTIVE_HIGH, button3 ) PORT_COCKTAIL \
	PORT_BIT( 0x8000, IP_ACTIVE_HIGH, start )

/******************************************************************************/
// Equites Port Map

INPUT_PORTS_START( equites )
	PORT_START
	EQUITES_PLAYER_INPUT_LSB( IPT_BUTTON1, IPT_BUTTON2, IPT_BUTTON3, IPT_START1 )
	EQUITES_PLAYER_INPUT_MSB( IPT_BUTTON1, IPT_BUTTON2, IPT_BUTTON3, IPT_START2 )

	PORT_START
	PORT_BIT( 0x0100, IP_ACTIVE_HIGH, IPT_COIN1 )
	PORT_BIT( 0x0200, IP_ACTIVE_HIGH, IPT_COIN2 )
#if EASY_TEST_MODE
	PORT_SERVICE( 0x0300, IP_ACTIVE_HIGH )
#endif
	PORT_DIPNAME( 0x0400, 0x0400, DEF_STR( Cabinet ) )
	PORT_DIPSETTING(      0x0400, DEF_STR( Upright ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( Cocktail ) )
	PORT_DIPNAME( 0x0800, 0x0800, "Buttons" )
	PORT_DIPSETTING(      0x0000, "2" )
	PORT_DIPSETTING(      0x0800, "3" )
	PORT_DIPNAME( 0x1000, 0x0000, DEF_STR ( Lives ) )
	PORT_DIPSETTING(      0x0000, "3" )
	PORT_DIPSETTING(      0x1000, "5" )
	PORT_DIPNAME( 0x2000, 0x0000, DEF_STR ( Difficulty ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( Normal ) )
	PORT_DIPSETTING(      0x2000, DEF_STR( Hard ) )
	PORT_DIPNAME( 0xc000, 0x0000, DEF_STR( Coinage ) )
	PORT_DIPSETTING(      0xc000, "A 2C/1C B 3C/1C" )
	PORT_DIPSETTING(      0x0000, "A 1C/1C B 2C/1C" )
	PORT_DIPSETTING(      0x8000, "A 1C/2C B 1C/4C" )
	PORT_DIPSETTING(      0x4000, "A 1C/3C B 1C/6C" )
INPUT_PORTS_END

/******************************************************************************/
// Bull Fighter Port Map

INPUT_PORTS_START( bullfgtr )
	PORT_START
	EQUITES_PLAYER_INPUT_LSB( IPT_BUTTON1, IPT_BUTTON2, IPT_BUTTON3, IPT_START1 )
	EQUITES_PLAYER_INPUT_MSB( IPT_BUTTON1, IPT_BUTTON2, IPT_BUTTON3, IPT_START2 )

	PORT_START
	PORT_BIT( 0x0100, IP_ACTIVE_HIGH, IPT_COIN1 )
	PORT_BIT( 0x0200, IP_ACTIVE_HIGH, IPT_COIN2 )
#if EASY_TEST_MODE
	PORT_SERVICE( 0x0300, IP_ACTIVE_HIGH )
#endif
	PORT_DIPNAME( 0x0c00, 0x0000, DEF_STR( Game_Time ) )
	PORT_DIPSETTING(      0x0c00, "3:00" )
	PORT_DIPSETTING(      0x0800, "2:00" )
	PORT_DIPSETTING(      0x0000, "1:30" )
	PORT_DIPSETTING(      0x0400, "1:00" )
	PORT_DIPNAME( 0x2000, 0x0000, DEF_STR ( Difficulty ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( Normal ) )
	PORT_DIPSETTING(      0x2000, DEF_STR( Hard ) )
	PORT_DIPNAME( 0x4000, 0x4000, DEF_STR( Demo_Sounds ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x4000, DEF_STR( On ) )
	PORT_DIPNAME( 0x9000, 0x0000, DEF_STR( Coinage ) )
//  PORT_DIPSETTING(      0x9000, "A 1C/1C B 1C/1C" )       // More than 1 credit per player needed
	PORT_DIPSETTING(      0x0000, "A 1C/1C B 1C/1C" )
	PORT_DIPSETTING(      0x8000, "A 1C/1C B 1C/4C" )
	PORT_DIPSETTING(      0x1000, "A 1C/2C B 1C/3C" )
INPUT_PORTS_END

/******************************************************************************/
// Koukouyakyuh Port Map

INPUT_PORTS_START( kouyakyu )
	PORT_START
	EQUITES_PLAYER_INPUT_LSB( IPT_BUTTON1, IPT_BUTTON2, IPT_BUTTON3, IPT_START1 )
	EQUITES_PLAYER_INPUT_MSB( IPT_BUTTON1, IPT_BUTTON2, IPT_BUTTON3, IPT_START2 )

	PORT_START
//  PORT_BIT( 0x0100, IP_ACTIVE_HIGH, IPT_COIN1 )
//  PORT_BIT( 0x0200, IP_ACTIVE_HIGH, IPT_UNUSED )
	PORT_BIT( 0x0300, IP_ACTIVE_HIGH, IPT_COIN1 )
#if EASY_TEST_MODE
	PORT_SERVICE( 0x0300, IP_ACTIVE_HIGH )
#endif
	PORT_DIPNAME( 0x0c00, 0x0000, "Game Points" )
	PORT_DIPSETTING(      0x0800, "3000" )
	PORT_DIPSETTING(      0x0400, "4000" )
	PORT_DIPSETTING(      0x0000, "5000" )
	PORT_DIPSETTING(      0x0c00, "7000" )
	PORT_DIPNAME( 0x2000, 0x0000, DEF_STR( Unused ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x2000, DEF_STR( On ) )
	PORT_DIPNAME( 0x4000, 0x4000, DEF_STR( Demo_Sounds ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x4000, DEF_STR( On ) )
	PORT_DIPNAME( 0x9000, 0x0000, DEF_STR( Coinage ) )
	PORT_DIPSETTING(      0x9000, "1C/1C (2C per player)" )
	PORT_DIPSETTING(      0x0000, "1C/1C (1C per player)" )
	PORT_DIPSETTING(      0x8000, "1C/1C (1C for 2 players)" )
	PORT_DIPSETTING(      0x1000, "1C/3C (1C per player)" )
INPUT_PORTS_END

/******************************************************************************/
// Splendor Blast Port Map

INPUT_PORTS_START( splndrbt )
	PORT_START
	EQUITES_PLAYER_INPUT_LSB( IPT_BUTTON1, IPT_BUTTON2, IPT_UNKNOWN, IPT_START1 )
	EQUITES_PLAYER_INPUT_MSB( IPT_BUTTON1, IPT_BUTTON2, IPT_UNKNOWN, IPT_START2 )

	PORT_START
	PORT_BIT( 0x0100, IP_ACTIVE_HIGH, IPT_COIN1 )
	PORT_BIT( 0x0200, IP_ACTIVE_HIGH, IPT_COIN2 )
#if EASY_TEST_MODE
	PORT_SERVICE( 0x0300, IP_ACTIVE_HIGH )
#endif
	PORT_DIPNAME( 0x0c00, 0x0000, DEF_STR ( Difficulty ) )
	PORT_DIPSETTING(      0x0400, DEF_STR( Easy ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( Normal ) )
	PORT_DIPSETTING(      0x0800, DEF_STR( Hard ) )
	PORT_DIPSETTING(      0x0c00, DEF_STR( Hardest ) )
	PORT_DIPNAME( 0x1000, 0x0000, DEF_STR( Demo_Sounds ) )
	PORT_DIPSETTING(      0x1000, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( On ) )
	PORT_DIPNAME( 0x2000, 0x2000, DEF_STR( Cabinet ) )
	PORT_DIPSETTING(      0x2000, DEF_STR( Upright ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( Cocktail ) )
	PORT_DIPNAME( 0xc000, 0x0000, DEF_STR( Coinage ) )
	PORT_DIPSETTING(      0xc000, "A 2C/1C B 3C/1C" )
	PORT_DIPSETTING(      0x0000, "A 1C/1C B 2C/1C" )
	PORT_DIPSETTING(      0x4000, "A 1C/2C B 1C/4C" )
	PORT_DIPSETTING(      0x8000, "A 1C/3C B 1C/6C" )
INPUT_PORTS_END

/******************************************************************************/
// High Voltage Port Map

INPUT_PORTS_START( hvoltage )
	PORT_START
	EQUITES_PLAYER_INPUT_LSB( IPT_BUTTON1, IPT_BUTTON2, IPT_UNKNOWN, IPT_START1 )
	EQUITES_PLAYER_INPUT_MSB( IPT_BUTTON1, IPT_BUTTON2, IPT_UNKNOWN, IPT_START2 )

	PORT_START
	PORT_BIT( 0x0100, IP_ACTIVE_HIGH, IPT_COIN1 )
	PORT_BIT( 0x0200, IP_ACTIVE_HIGH, IPT_COIN2 )
#if EASY_TEST_MODE
	PORT_SERVICE( 0x0300, IP_ACTIVE_HIGH )
#endif
#if HVOLTAGE_HACK
	PORT_DIPNAME( 0x0400, 0x0000, "Invulnerability" )
	PORT_DIPSETTING(      0x0000, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0400, DEF_STR( On ) )
	PORT_DIPNAME( 0x0800, 0x0000, "Need to kill Bosses" )
	PORT_DIPSETTING(      0x0800, DEF_STR( No ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( Yes ) )
#else
	PORT_DIPNAME( 0x0c00, 0x0000, DEF_STR ( Difficulty ) )
	PORT_DIPSETTING(      0x0400, DEF_STR( Easy ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( Normal ) )
	PORT_DIPSETTING(      0x0800, DEF_STR( Hard ) )
	PORT_DIPSETTING(      0x0c00, DEF_STR( Hardest ) )
#endif
	PORT_DIPNAME( 0x1000, 0x0000, DEF_STR ( Lives ) )			// See notes
	PORT_DIPSETTING(      0x0000, "3" )
	PORT_DIPSETTING(      0x1000, "5" )
	PORT_DIPNAME( 0x2000, 0x0000, DEF_STR ( Bonus_Life ) )
	PORT_DIPSETTING(      0x0000, "50k, 100k then every 100k" )
	PORT_DIPSETTING(      0x2000, "50k, 200k then every 100k" )
	PORT_DIPNAME( 0xc000, 0x0000, DEF_STR( Coinage ) )			// See notes
	PORT_DIPSETTING(      0xc000, "A 2C/1C B 3C/1C" )
	PORT_DIPSETTING(      0x0000, "A 1C/1C B 2C/1C" )
	PORT_DIPSETTING(      0x4000, "A 1C/2C B 1C/4C" )
	PORT_DIPSETTING(      0x8000, "A 1C/3C B 1C/6C" )

#if HVOLTAGE_HACK
	/* Fake port to handle debug mode */
	PORT_START
	PORT_DIPNAME( 0xffff, 0xffff, "Debug Mode" )
	PORT_DIPSETTING(      0xffff, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( On ) )
#endif
INPUT_PORTS_END

/******************************************************************************/

// Game Entries

// Equites Hardware
GAME( 1984, equites,  0,        equites,  equites,  equites,  ROT90, "Alpha Denshi Co.",                "Equites", GAME_UNEMULATED_PROTECTION | GAME_NO_COCKTAIL )
GAME( 1984, equitess, equites,  equites,  equites,  equites,  ROT90, "Alpha Denshi Co. (Sega license)", "Equites (Sega)", GAME_UNEMULATED_PROTECTION | GAME_NO_COCKTAIL )
GAME( 1985, gekisou,  0,        equites,  equites,  equites,  ROT90, "Eastern",                         "Gekisou (Japan)", GAME_UNEMULATED_PROTECTION | GAME_NO_COCKTAIL | GAME_NOT_WORKING )
GAME( 1984, bullfgtr, 0,        equites,  bullfgtr, bullfgtr, ROT90, "Alpha Denshi Co.",                "Bull Fighter", GAME_UNEMULATED_PROTECTION )
GAME( 1984, bullfgts, bullfgtr, equites,  bullfgtr, bullfgts, ROT90, "Alpha Denshi Co. (Sega license)", "Bull Fighter (Sega)", GAME_UNEMULATED_PROTECTION )
GAME( 1985, kouyakyu, 0,        equites,  kouyakyu, kouyakyu, ROT0,  "Alpha Denshi Co.",                "The Koukouyakyuh", GAME_UNEMULATED_PROTECTION )

// Splendor Blast Hardware
GAME( 1985, splndrbt, 0,        splndrbt, splndrbt, splndrbt, ROT0,  "Alpha Denshi Co.", "Splendor Blast", GAME_UNEMULATED_PROTECTION | GAME_NO_COCKTAIL )
GAME( 1985, hvoltage, 0,        splndrbt, hvoltage, hvoltage, ROT0,  "Alpha Denshi Co.", "High Voltage", GAME_UNEMULATED_PROTECTION )

/******************************************************************************/
