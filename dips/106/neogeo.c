Most Neo-Geo games are entirely software-DIPs.  Standard text for use:
All relevant rules are covered by software-dips.  If not shown during playback, use F2 to access after playback completed.

/******************************************************************************/
#define NGIN0\
	PORT_START_TAG("IN0")\
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_JOYSTICK_UP )\
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN )\
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT )\
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT )\
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_BUTTON1 )\
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_BUTTON2 )\
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_BUTTON3 )\
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_BUTTON4 )\

#define NGIN1\
	PORT_START_TAG("IN1")\
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_JOYSTICK_UP ) PORT_PLAYER(2)\
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN ) PORT_PLAYER(2)\
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT ) PORT_PLAYER(2)\
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT ) PORT_PLAYER(2)\
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_PLAYER(2)\
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_BUTTON2 ) PORT_PLAYER(2)\
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_BUTTON3 ) PORT_PLAYER(2)\
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_BUTTON4 ) PORT_PLAYER(2)

#define NGIN2\
	PORT_START_TAG("IN2")\
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_START1 )   /* Player 1 Start */\
	PORT_BIT(0x02, IP_ACTIVE_LOW, IPT_OTHER ) PORT_NAME("Next Game") PORT_CODE(KEYCODE_7)\
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_START2 )   /* Player 2 Start */\
	PORT_BIT(0x08, IP_ACTIVE_LOW, IPT_OTHER ) PORT_NAME("Previous Game") PORT_CODE(KEYCODE_8)\
	PORT_BIT( 0x30, IP_ACTIVE_LOW, IPT_UNKNOWN ) /* memory card inserted */\
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_UNKNOWN ) /* memory card write protection */\
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_UNKNOWN )

#define NGIN3\
	PORT_START_TAG("DSW")\
	PORT_DIPNAME( 0x01, 0x01, "Test Switch" )\
	PORT_DIPSETTING(	0x01, DEF_STR( Off ) )\
	PORT_DIPSETTING(	0x00, DEF_STR( On ) )\
	PORT_DIPNAME( 0x02, 0x02, "Coin Chutes?" )\
	PORT_DIPSETTING(	0x00, "1?" )\
	PORT_DIPSETTING(	0x02, "2?" )\
	PORT_DIPNAME( 0x04, 0x04, "Autofire (in some games)" )\
	PORT_DIPSETTING(	0x04, DEF_STR( Off ) )\
	PORT_DIPSETTING(	0x00, DEF_STR( On ) )\
	PORT_DIPNAME( 0x38, 0x38, "COMM Setting" )\
	PORT_DIPSETTING(	0x38, DEF_STR( Off ) )\
	PORT_DIPSETTING(	0x30, "1" )\
	PORT_DIPSETTING(	0x20, "2" )\
	PORT_DIPSETTING(	0x10, "3" )\
	PORT_DIPSETTING(	0x00, "4" )\
	PORT_DIPNAME( 0x40, 0x40, DEF_STR( Free_Play ) )\
	PORT_DIPSETTING(	0x40, DEF_STR( Off ) )\
	PORT_DIPSETTING(	0x00, DEF_STR( On ) )\
	PORT_DIPNAME( 0x80, 0x80, "Freeze" )\
	PORT_DIPSETTING(	0x80, DEF_STR( Off ) )\
	PORT_DIPSETTING(	0x00, DEF_STR( On ) )

#define NGIN4\
	PORT_START_TAG("IN4")\
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_COIN1 )\
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_COIN2 )\
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_SERVICE1 )\
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_UNKNOWN ) /* having this ACTIVE_HIGH causes you to start with 2 credits using USA bios roms */\
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_UNKNOWN ) /* having this ACTIVE_HIGH causes you to start with 2 credits using USA bios roms */\
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_SPECIAL )  /* handled by fake IN5 */\
	PORT_BIT( 0x40, IP_ACTIVE_HIGH, IPT_UNKNOWN )\
	PORT_BIT( 0x80, IP_ACTIVE_HIGH, IPT_UNKNOWN )


#define NGIN6\
	PORT_START_TAG("IN6")		/* Test switch */\
	PORT_BIT( 0x01, IP_ACTIVE_HIGH, IPT_UNKNOWN )\
	PORT_BIT( 0x02, IP_ACTIVE_HIGH, IPT_UNKNOWN )\
	PORT_BIT( 0x04, IP_ACTIVE_HIGH, IPT_UNKNOWN )\
	PORT_BIT( 0x08, IP_ACTIVE_HIGH, IPT_UNKNOWN )\
	PORT_BIT( 0x10, IP_ACTIVE_HIGH, IPT_UNKNOWN )\
	PORT_BIT( 0x20, IP_ACTIVE_HIGH, IPT_UNKNOWN )\
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_SPECIAL )  /* handled by fake IN5 */\
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_OTHER ) PORT_NAME("Test Switch") PORT_CODE(KEYCODE_F2)

INPUT_PORTS_START( neogeo )
	NGIN0
	NGIN1
	NGIN2
	NGIN3
	NGIN4
	/* Fake*/
	PORT_START_TAG("IN5")

	NGIN6
INPUT_PORTS_END

INPUT_PORTS_START( svcpcb )
	NGIN0
	NGIN1
	NGIN2
	NGIN3
	NGIN4
	/* Fake*/
	PORT_START_TAG("IN5")

	NGIN6

	/* the rom banking is tied directly to the dipswitch?, or is there a bank write somewhere? */
	PORT_START_TAG("HARDDIP")
	PORT_DIPNAME( 0x01, 0x00, "Hard Dip 3 (Region)" )
	PORT_DIPSETTING(	0x00, DEF_STR( Asia ) )
	PORT_DIPSETTING(	0x01, DEF_STR( Japan ) )
INPUT_PORTS_END

INPUT_PORTS_START( kog )
	NGIN0
	NGIN1
	NGIN2
	NGIN3
	NGIN4
	/* Fake*/
	PORT_START_TAG("IN5")

	NGIN6

	/* a jumper on the pcb overlays a rom address, very strange but that's how it works. */
	PORT_START_TAG("JUMPER")
	PORT_DIPNAME( 0x01, 0x01, "Jumper (Title)" )
	PORT_DIPSETTING(	0x01, DEF_STR( English ) )
	PORT_DIPSETTING(	0x00, "Non-English" )
INPUT_PORTS_END


INPUT_PORTS_START( mjneogeo )
	NGIN0
	NGIN1
	NGIN2

	PORT_START_TAG("DSW")
	PORT_DIPNAME( 0x01, 0x01, "Test Switch" )
	PORT_DIPSETTING(	0x01, DEF_STR( Off ) )
	PORT_DIPSETTING(	0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x02, 0x02, "Coin Chutes?" )
	PORT_DIPSETTING(	0x00, "1?" )
	PORT_DIPSETTING(	0x02, "2?" )
	PORT_DIPNAME( 0x04, 0x00, "Mahjong Control Panel" )
	PORT_DIPSETTING(	0x04, DEF_STR( Off ) )
	PORT_DIPSETTING(	0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x38, 0x38, "COMM Setting" )
	PORT_DIPSETTING(	0x38, DEF_STR( Off ) )
	PORT_DIPSETTING(	0x30, "1" )
	PORT_DIPSETTING(	0x20, "2" )
	PORT_DIPSETTING(	0x10, "3" )
	PORT_DIPSETTING(	0x00, "4" )
	PORT_DIPNAME( 0x40, 0x40, DEF_STR( Free_Play ) )
	PORT_DIPSETTING(	0x40, DEF_STR( Off ) )
	PORT_DIPSETTING(	0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x80, 0x80, "Freeze" )
	PORT_DIPSETTING(	0x80, DEF_STR( Off ) )
	PORT_DIPSETTING(	0x00, DEF_STR( On ) )

	NGIN4
	/* Fake*/
	PORT_START_TAG("IN5")

	NGIN6

	PORT_START_TAG("IN7")
	PORT_BIT(0x01, IP_ACTIVE_LOW, IPT_MAHJONG_A )
	PORT_BIT(0x02, IP_ACTIVE_LOW, IPT_MAHJONG_B )
	PORT_BIT(0x04, IP_ACTIVE_LOW, IPT_MAHJONG_C )
	PORT_BIT(0x08, IP_ACTIVE_LOW, IPT_MAHJONG_D )
	PORT_BIT(0x10, IP_ACTIVE_LOW, IPT_MAHJONG_E )
	PORT_BIT(0x20, IP_ACTIVE_LOW, IPT_MAHJONG_F )
	PORT_BIT(0x40, IP_ACTIVE_LOW, IPT_MAHJONG_G )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_UNKNOWN )

	PORT_START_TAG("IN8")
	PORT_BIT(0x01, IP_ACTIVE_LOW, IPT_MAHJONG_H )
	PORT_BIT(0x02, IP_ACTIVE_LOW, IPT_MAHJONG_I )
	PORT_BIT(0x04, IP_ACTIVE_LOW, IPT_MAHJONG_J )
	PORT_BIT(0x08, IP_ACTIVE_LOW, IPT_MAHJONG_K )
	PORT_BIT(0x10, IP_ACTIVE_LOW, IPT_MAHJONG_L )
	PORT_BIT(0x20, IP_ACTIVE_LOW, IPT_MAHJONG_M )
	PORT_BIT(0x40, IP_ACTIVE_LOW, IPT_MAHJONG_N )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_UNKNOWN )

	PORT_START_TAG("IN9")
	PORT_BIT(0x01, IP_ACTIVE_LOW, IPT_MAHJONG_PON )
	PORT_BIT(0x02, IP_ACTIVE_LOW, IPT_MAHJONG_CHI )
	PORT_BIT(0x04, IP_ACTIVE_LOW, IPT_MAHJONG_KAN )
	PORT_BIT(0x08, IP_ACTIVE_LOW, IPT_MAHJONG_RON )
	PORT_BIT(0x10, IP_ACTIVE_LOW, IPT_MAHJONG_REACH )
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_UNKNOWN )
INPUT_PORTS_END


INPUT_PORTS_START( irrmaze )
	PORT_START_TAG("IN0")		/* IN0 multiplexed */
	PORT_BIT( 0xff, 0x7f, IPT_TRACKBALL_X ) PORT_SENSITIVITY(10) PORT_KEYDELTA(20) PORT_REVERSE

	PORT_START_TAG("IN1")
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_BUTTON1 )
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_BUTTON2 )
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_PLAYER(2)
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_BUTTON2 ) PORT_PLAYER(2)

	PORT_START_TAG("IN2")
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_START1 )   /* Player 1 Start */
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_START2 )   /* Player 2 Start */
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x30, IP_ACTIVE_LOW, IPT_UNKNOWN ) /* memory card inserted */
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_UNKNOWN ) /* memory card write protection */
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_UNKNOWN )

	NGIN3
	NGIN4

	/* Fake */
	PORT_START_TAG("IN5")

	PORT_START_TAG("IN6")
	PORT_BIT( 0x01, IP_ACTIVE_HIGH, IPT_UNKNOWN )
	PORT_BIT( 0x02, IP_ACTIVE_HIGH, IPT_UNKNOWN )
	PORT_BIT( 0x04, IP_ACTIVE_HIGH, IPT_UNKNOWN )
	PORT_BIT( 0x08, IP_ACTIVE_HIGH, IPT_UNKNOWN )
	PORT_BIT( 0x10, IP_ACTIVE_HIGH, IPT_UNKNOWN )
	PORT_BIT( 0x20, IP_ACTIVE_HIGH, IPT_UNKNOWN )
	PORT_BIT( 0x40, IP_ACTIVE_HIGH, IPT_UNKNOWN )  /* This bit is used.. */
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_OTHER ) PORT_NAME("Test Switch") PORT_CODE(KEYCODE_F2)

	PORT_START_TAG("IN7")		/* IN0 multiplexed */
	PORT_BIT( 0xff, 0x7f, IPT_TRACKBALL_Y ) PORT_SENSITIVITY(10) PORT_KEYDELTA(20) PORT_REVERSE
INPUT_PORTS_END

INPUT_PORTS_START( popbounc )
	PORT_START_TAG("IN0")
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_JOYSTICK_UP )
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN )
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT )
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT )
	PORT_BIT( 0x90, IP_ACTIVE_LOW, IPT_BUTTON1 ) // note it needs it from 0x80 when using paddle
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_BUTTON2 )
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_BUTTON3 )

	PORT_START_TAG("IN1")
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_JOYSTICK_UP ) PORT_PLAYER(2)
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN ) PORT_PLAYER(2)
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT ) PORT_PLAYER(2)
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT ) PORT_PLAYER(2)
	PORT_BIT( 0x90, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_PLAYER(2) // note it needs it from 0x80 when using paddle
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_BUTTON2 ) PORT_PLAYER(2)
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_BUTTON3 ) PORT_PLAYER(2)

	NGIN2
	NGIN3
	NGIN4

	/* Fake*/
	PORT_START_TAG("IN5")

	NGIN6

	PORT_START_TAG("IN7")		/* IN0 multiplexed */
	PORT_BIT( 0xff, 0x7f, IPT_DIAL ) PORT_SENSITIVITY(10) PORT_KEYDELTA(20)

	PORT_START_TAG("IN8")		/* IN1 multiplexed */
	PORT_BIT( 0xff, 0x7f, IPT_DIAL  ) PORT_SENSITIVITY(10) PORT_KEYDELTA(20) PORT_PLAYER(2)
INPUT_PORTS_END

INPUT_PORTS_START( vliner )
	PORT_START_TAG("IN0")
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_JOYSTICK_UP )
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN )
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT )
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT )
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_NAME("P1 Big")
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_BUTTON2 ) PORT_NAME("P1 Small")
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_BUTTON3 ) PORT_NAME("P1 Double Up")
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_BUTTON4 ) PORT_NAME("P1 Start/Collect")

	NGIN1 /* there is no player 2 in this game */

	PORT_START_TAG("IN2")
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_START1 ) PORT_NAME("Payout") /* to enable selection in Test Switch */
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_UNKNOWN ) /* This bit is used.. */
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_START2 )  /* there is no player 2 in this game */
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_UNKNOWN ) /* This bit is used.. */
	PORT_BIT( 0x30, IP_ACTIVE_LOW, IPT_UNKNOWN ) /* memory card inserted */
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_UNKNOWN ) /* memory card write protection */
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_UNKNOWN )

	NGIN3

	PORT_START_TAG("IN4")
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_COIN1 )
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_COIN2 )
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_OTHER ) PORT_NAME("Operator Menu") PORT_CODE(KEYCODE_F1)
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_BUTTON5 ) PORT_NAME("Clear Credit")
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_BUTTON6 ) PORT_NAME("Hopper Out")

	PORT_START_TAG("IN5")

	NGIN6
INPUT_PORTS_END

INPUT_PORTS_START( jockeygp )
	NGIN0
	NGIN1

	PORT_START_TAG("IN2")\
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_UNKNOWN ) /* game freezes with this bit enabled */
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_OTHER ) PORT_NAME("Next Game") PORT_CODE(KEYCODE_7)
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_UNKNOWN ) /* game freezes with this bit enabled */
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_OTHER ) PORT_NAME("Previous Game") PORT_CODE(KEYCODE_8)
	PORT_BIT( 0x30, IP_ACTIVE_LOW, IPT_UNKNOWN ) /* memory card inserted */
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_UNKNOWN ) /* memory card write protection */
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_UNKNOWN )

	NGIN3
	NGIN4
	/* Fake*/
	PORT_START_TAG("IN5")

	NGIN6
INPUT_PORTS_END

/*     YEAR  NAME      PARENT    BIOS    MACHINE INPUT    INIT      MONITOR  */

/* SNK */
GAMEB( 1990, nam1975,  neogeo,   neogeo, neogeo, neogeo,  neogeo,   ROT0, "SNK", "NAM-1975", 0 )
GAMEB( 1990, bstars,   neogeo,   neogeo, neogeo, neogeo,  neogeo,   ROT0, "SNK", "Baseball Stars Professional", 0 )
GAMEB( 1990, tpgolf,   neogeo,   neogeo, neogeo, neogeo,  neogeo,   ROT0, "SNK", "Top Player's Golf", 0 )
GAMEB( 1990, mahretsu, neogeo,   neogeo, neogeo, mjneogeo,mjneogeo, ROT0, "SNK", "Mahjong Kyoretsuden", 0 )
GAMEB( 1990, ridhero,  neogeo,   neogeo, neogeo, neogeo,  neogeo,   ROT0, "SNK", "Riding Hero (set 1)", 0 )
GAMEB( 1990, ridheroh, ridhero,  neogeo, neogeo, neogeo,  neogeo,   ROT0, "SNK", "Riding Hero (set 2)", 0 )
GAMEB( 1991, alpham2,  neogeo,   neogeo, neogeo, neogeo,  neogeo,   ROT0, "SNK", "Alpha Mission II / ASO II - Last Guardian", 0 )
GAMEB( 1990, cyberlip, neogeo,   neogeo, neogeo, neogeo,  neogeo,   ROT0, "SNK", "Cyber-Lip", 0 )
GAMEB( 1990, superspy, neogeo,   neogeo, neogeo, neogeo,  neogeo,   ROT0, "SNK", "The Super Spy", 0 )
GAMEB( 1992, mutnat,   neogeo,   neogeo, neogeo, neogeo,  neogeo,   ROT0, "SNK", "Mutation Nation", 0 )
GAMEB( 1991, kotm,     neogeo,   neogeo, neogeo, neogeo,  neogeo,   ROT0, "SNK", "King of the Monsters (set 1)", 0 )
GAMEB( 1991, kotmh,    kotm,     neogeo, neogeo, neogeo,  neogeo,   ROT0, "SNK", "King of the Monsters (set 2)", 0 )
GAMEB( 1991, sengoku,  neogeo,   neogeo, neogeo, neogeo,  neogeo,   ROT0, "SNK", "Sengoku / Sengoku Denshou (set 1)", 0 )
GAMEB( 1991, sengokh,  sengoku,  neogeo, neogeo, neogeo,  neogeo,   ROT0, "SNK", "Sengoku / Sengoku Denshou (set 2)", 0 )
GAMEB( 1991, burningf, neogeo,   neogeo, neogeo, neogeo,  neogeo,   ROT0, "SNK", "Burning Fight (set 1)", 0 )
GAMEB( 1991, burningh, burningf, neogeo, neogeo, neogeo,  neogeo,   ROT0, "SNK", "Burning Fight (set 2)", 0 )
GAMEB( 1990, lbowling, neogeo,   neogeo, neogeo, neogeo,  neogeo,   ROT0, "SNK", "League Bowling", 0 )
GAMEB( 1991, gpilots,  neogeo,   neogeo, neogeo, neogeo,  neogeo,   ROT0, "SNK", "Ghost Pilots", 0 )
GAMEB( 1990, joyjoy,   neogeo,   neogeo, neogeo, neogeo,  neogeo,   ROT0, "SNK", "Puzzled / Joy Joy Kid", 0 )
GAMEB( 1991, quizdais, neogeo,   neogeo, neogeo, neogeo,  neogeo,   ROT0, "SNK", "Quiz Daisousa Sen - The Last Count Down", 0 )
GAMEB( 1992, lresort,  neogeo,   neogeo, neogeo, neogeo,  neogeo,   ROT0, "SNK", "Last Resort", 0 )
GAMEB( 1991, eightman, neogeo,   neogeo, neogeo, neogeo,  neogeo,   ROT0, "SNK / Pallas", "Eight Man", 0 )
GAMEB( 1991, legendos, neogeo,   neogeo, neogeo, neogeo,  neogeo,   ROT0, "SNK", "Legend of Success Joe / Ashitano Joe Densetsu", 0 )
GAMEB( 1991, 2020bb,   neogeo,   neogeo, neogeo, neogeo,  neogeo,   ROT0, "SNK / Pallas", "2020 Super Baseball (set 1)", 0 )
GAMEB( 1991, 2020bba,  2020bb,   neogeo, neogeo, neogeo,  neogeo,   ROT0, "SNK / Pallas", "2020 Super Baseball (set 2)", 0 )
GAMEB( 1991, 2020bbh,  2020bb,   neogeo, neogeo, neogeo,  neogeo,   ROT0, "SNK / Pallas", "2020 Super Baseball (set 3)", 0 )
GAMEB( 1991, socbrawl, neogeo,   neogeo, neogeo, neogeo,  neogeo,   ROT0, "SNK", "Soccer Brawl", 0 )
GAMEB( 1991, fatfury1, neogeo,   neogeo, neogeo, neogeo,  neogeo,   ROT0, "SNK", "Fatal Fury - King of Fighters / Garou Densetsu - shukumei no tatakai", 0 )
GAMEB( 1991, roboarmy, neogeo,   neogeo, neogeo, neogeo,  neogeo,   ROT0, "SNK", "Robo Army (set 1)", 0 )
GAMEB( 1991, roboarma, roboarmy, neogeo, neogeo, neogeo,  neogeo,   ROT0, "SNK", "Robo Army (set 2)", 0 )
GAMEB( 1992, fbfrenzy, neogeo,   neogeo, neogeo, neogeo,  neogeo,   ROT0, "SNK", "Football Frenzy", 0 )
GAMEB( 1992, kotm2,    neogeo,   neogeo, neogeo, neogeo,  neogeo,   ROT0, "SNK", "King of the Monsters 2 - The Next Thing", 0 )
GAMEB( 1993, sengoku2, neogeo,   neogeo, neogeo, neogeo,  neogeo,   ROT0, "SNK", "Sengoku 2 / Sengoku Denshou 2", 0)
GAMEB( 1992, bstars2,  neogeo,   neogeo, neogeo, neogeo,  neogeo,   ROT0, "SNK", "Baseball Stars 2", 0 )
GAMEB( 1992, quizdai2, neogeo,   neogeo, neogeo, neogeo,  neogeo,   ROT0, "SNK", "Quiz Meitantei Neo & Geo - Quiz Daisousa Sen part 2", 0 )
GAMEB( 1993, 3countb,  neogeo,   neogeo, neogeo, neogeo,  neogeo,   ROT0, "SNK", "3 Count Bout / Fire Suplex", 0 )
GAMEB( 1992, aof,      neogeo,   neogeo, neogeo, neogeo,  neogeo,   ROT0, "SNK", "Art of Fighting / Ryuuko no Ken", 0 )
GAMEB( 1993, samsho,   neogeo,   neogeo, neogeo, neogeo,  neogeo,   ROT0, "SNK", "Samurai Shodown / Samurai Spirits", 0 )
GAMEB( 1994, tophuntr, neogeo,   neogeo, neogeo, neogeo,  neogeo,   ROT0, "SNK", "Top Hunter - Roddy & Cathy (set 1)", 0 )
GAMEB( 1994, tophunta, tophuntr, neogeo, neogeo, neogeo,  neogeo,   ROT0, "SNK", "Top Hunter - Roddy & Cathy (set 2)", 0 )
GAMEB( 1992, fatfury2, neogeo,   neogeo, neogeo, neogeo,  fatfury2, ROT0, "SNK", "Fatal Fury 2 / Garou Densetsu 2 - arata-naru tatakai", 0 )
GAMEB( 1992, ssideki,  neogeo,   neogeo, neogeo, neogeo,  fatfury2, ROT0, "SNK", "Super Sidekicks / Tokuten Ou", 0 )
GAMEB( 1994, kof94,    neogeo,   neogeo, neogeo, neogeo,  neogeo,   ROT0, "SNK", "The King of Fighters '94", 0 )
GAMEB( 1994, aof2,     neogeo,   neogeo, neogeo, neogeo,  neogeo,   ROT0, "SNK", "Art of Fighting 2 / Ryuuko no Ken 2 (set 1)", 0 )
GAMEB( 1994, aof2a,    aof2,     neogeo, neogeo, neogeo,  neogeo,   ROT0, "SNK", "Art of Fighting 2 / Ryuuko no Ken 2 (set 2)", 0 )
GAMEB( 1993, fatfursp, neogeo,   neogeo, neogeo, neogeo,  neogeo,   ROT0, "SNK", "Fatal Fury Special / Garou Densetsu Special (set 1)", 0 )
GAMEB( 1993, fatfursa, fatfursp, neogeo, neogeo, neogeo,  neogeo,   ROT0, "SNK", "Fatal Fury Special / Garou Densetsu Special (set 2)", 0 )
GAMEB( 1995, savagere, neogeo,   neogeo, neogeo, neogeo,  neogeo,   ROT0, "SNK", "Savage Reign / Fu'un Mokushiroku - kakutou sousei", 0 )
GAMEB( 1994, ssideki2, neogeo,   neogeo, neogeo, neogeo,  neogeo,   ROT0, "SNK", "Super Sidekicks 2 - The World Championship / Tokuten Ou 2 - real fight football", 0 )
GAMEB( 1994, samsho2,  neogeo,   neogeo, neogeo, neogeo,  neogeo,   ROT0, "SNK", "Samurai Shodown II / Shin Samurai Spirits - Haohmaru jigokuhen", 0 )
/* Jin Saulabi Tu Hon (Samurai shodown 2) - Korean censored version - http://www.kmrb.or.kr/Game_Image/1999/%EC%A0%9C1273%ED%98%B8.jpg */
GAMEB( 1995, fatfury3, neogeo,   neogeo, neogeo, neogeo,  neogeo,   ROT0, "SNK", "Fatal Fury 3 - Road to the Final Victory / Garou Densetsu 3 - haruka-naru tatakai", 0 )
GAMEB( 1995, ssideki3, neogeo,   neogeo, neogeo, neogeo,  neogeo,   ROT0, "SNK", "Super Sidekicks 3 - The Next Glory / Tokuten Ou 3 - eikoue no michi", 0 )
GAMEB( 1995, kof95,    neogeo,   neogeo, neogeo, neogeo,  neogeo,   ROT0, "SNK", "The King of Fighters '95 (set 1)", 0 )
GAMEB( 1995, kof95a,   kof95,    neogeo, neogeo, neogeo,  neogeo,   ROT0, "SNK", "The King of Fighters '95 (set 2)", 0 )
GAMEB( 1995, samsho3,  neogeo,   neogeo, neogeo, neogeo,  neogeo,   ROT0, "SNK", "Samurai Shodown III / Samurai Spirits - Zankurou Musouken (set 1)", 0 )
GAMEB( 1995, samsho3a, samsho3,  neogeo, neogeo, neogeo,  neogeo,   ROT0, "SNK", "Samurai Shodown III / Samurai Spirits - Zankurou Musouken (set 2)", 0 )
GAMEB( 1995, fswords,  samsho3,  neogeo, neogeo, neogeo,  neogeo,   ROT0, "SNK", "Fighters Swords (Korean release of Samurai Shodown III)", 0 )
GAMEB( 1995, rbff1,    neogeo,   neogeo, neogeo, neogeo,  neogeo,   ROT0, "SNK", "Real Bout Fatal Fury / Real Bout Garou Densetsu", 0 )
GAMEB( 1996, aof3,     neogeo,   neogeo, neogeo, neogeo,  neogeo,   ROT0, "SNK", "Art of Fighting 3 - The Path of the Warrior / Art of Fighting - Ryuuko no Ken Gaiden", 0 )
GAMEB( 1996, aof3k,    aof3,     neogeo, neogeo, neogeo,  neogeo,   ROT0, "SNK", "Art of Fighting 3 - The Path of the Warrior (Korean release)", 0 ) // no Japanese title / mode
GAMEB( 1996, kof96,    neogeo,   neogeo, neogeo, neogeo,  neogeo,   ROT0, "SNK", "The King of Fighters '96 (set 1)", 0 )
GAMEB( 1996, kof96h,   kof96,    neogeo, neogeo, neogeo,  neogeo,   ROT0, "SNK", "The King of Fighters '96 (set 2)", 0 )
GAMEB( 1996, ssideki4, neogeo,   neogeo, neogeo, neogeo,  neogeo,   ROT0, "SNK", "Ultimate 11 - The SNK Football Championship / Tokuten Ou - Honoo no Libero, The", 0 )
GAMEB( 1996, kizuna,   neogeo,   neogeo, neogeo, neogeo,  neogeo,   ROT0, "SNK", "Kizuna Encounter - Super Tag Battle / Fu'un Super Tag Battle", 0 )
GAMEB( 1996, samsho4,  neogeo,   neogeo, neogeo, neogeo,  neogeo,   ROT0, "SNK", "Samurai Shodown IV - Amakusa's Revenge / Samurai Spirits - Amakusa Kourin", 0 )
/* Pae Wang Jeon Seol / Legend of Warrior - Korean / Chinese censored version of SamSho4, see http://www.kmrb.or.kr/Game_Image/1999/%EC%A0%9C2064%ED%98%B8.jpg */
GAMEB( 1996, rbffspec, neogeo,   neogeo, neogeo, neogeo,  neogeo,   ROT0, "SNK", "Real Bout Fatal Fury Special / Real Bout Garou Densetsu Special", 0 )
GAMEB( 1997, kof97,    neogeo,   neogeo, neogeo, neogeo,  neogeo,   ROT0, "SNK", "The King of Fighters '97 (set 1)", 0 )
GAMEB( 1997, kof97a,   kof97,    neogeo, neogeo, neogeo,  neogeo,   ROT0, "SNK", "The King of Fighters '97 (set 2)", 0 )
GAMEB( 1997, kof97pls, kof97,    neogeo, neogeo, neogeo,  neogeo,   ROT0, "bootleg", "The King of Fighters '97 Plus (bootleg)", 0 )
GAMEB( 1997, kog,      kof97,    neogeo, neogeo, kog,     kog,      ROT0, "bootleg", "King of Gladiator (The King of Fighters '97 bootleg)", GAME_NOT_WORKING ) // protected bootleg
GAMEB( 1997, lastblad, neogeo,   neogeo, neogeo, neogeo,  neogeo,   ROT0, "SNK", "Last Blade / Bakumatsu Roman - Gekka no Kenshi, The (set 1)", 0 )
GAMEB( 1997, lastblda, lastblad, neogeo, neogeo, neogeo,  neogeo,   ROT0, "SNK", "Last Blade / Bakumatsu Roman - Gekka no Kenshi, The (set 2)", 0 )
GAMEB( 1997, lastsold, lastblad, neogeo, neogeo, neogeo,  neogeo,   ROT0, "SNK", "The Last Soldier (Korean release of The Last Blade)", 0 )
GAMEB( 1997, irrmaze,  neogeo,   neogeo, neogeo, irrmaze, neogeo,   ROT0, "SNK / Saurus", "The Irritating Maze / Ultra Denryu Iraira Bou", 0 )
GAMEB( 1998, rbff2,    neogeo,   neogeo, neogeo, neogeo,  neogeo,   ROT0, "SNK", "Real Bout Fatal Fury 2 - The Newcomers / Real Bout Garou Densetsu 2 - the newcomers (set 1)", 0 )
GAMEB( 1998, rbff2a,   rbff2,    neogeo, neogeo, neogeo,  neogeo,   ROT0, "SNK", "Real Bout Fatal Fury 2 - The Newcomers / Real Bout Garou Densetsu 2 - the newcomers (set 2)", 0 )
GAMEB( 1998, rbff2k,   rbff2,    neogeo, neogeo, neogeo,  neogeo,   ROT0, "SNK", "Real Bout Fatal Fury 2 - The Newcomers (Korean release)", 0 ) // no Japanese title / mode
GAMEB( 1998, mslug2,   neogeo,   neogeo, neogeo, neogeo,  neogeo,   ROT0, "SNK", "Metal Slug 2 - Super Vehicle-001/II", 0 )
GAMEB( 1998, kof98,    neogeo,   neogeo, neogeo, neogeo,  kof98,    ROT0, "SNK", "The King of Fighters '98 - The Slugfest / King of Fighters '98 - dream match never ends", 0 )
GAMEB( 1998, kof98k,   kof98,    neogeo, neogeo, neogeo,  kof98,    ROT0, "SNK", "The King of Fighters '98 - The Slugfest / King of Fighters '98 - dream match never ends (Korean board)", 0 )
GAMEB( 1998, kof98n,   kof98,    neogeo, neogeo, neogeo,  neogeo,   ROT0, "SNK", "The King of Fighters '98 - The Slugfest / King of Fighters '98 - dream match never ends (not encrypted)", 0 )
GAMEB( 1998, lastbld2, neogeo,   neogeo, neogeo, neogeo,  neogeo,   ROT0, "SNK", "Last Blade 2 / Bakumatsu Roman - Dai Ni Maku Gekka no Kenshi, The", 0 )
GAMEB( 1998, neocup98, neogeo,   neogeo, neogeo, neogeo,  neogeo,   ROT0, "SNK", "Neo-Geo Cup '98 - The Road to the Victory", 0 )
GAMEB( 1999, mslugx,   neogeo,   neogeo, neogeo, neogeo,  mslugx,   ROT0, "SNK", "Metal Slug X - Super Vehicle-001", 0 )
GAMEB( 1999, kof99,    neogeo,   neogeo, neogeo, neogeo,  kof99,    ROT0, "SNK", "The King of Fighters '99 - Millennium Battle (set 1)" , 0) /* Encrypted Code & GFX */
GAMEB( 1999, kof99a,   kof99,    neogeo, neogeo, neogeo,  kof99,    ROT0, "SNK", "The King of Fighters '99 - Millennium Battle (set 2)" , 0) /* Encrypted Code & GFX, crashes going into attract demo */
GAMEB( 1999, kof99e,   kof99,    neogeo, neogeo, neogeo,  kof99,    ROT0, "SNK", "The King of Fighters '99 - Millennium Battle (earlier)" , 0) /* Encrypted Code & GFX */
GAMEB( 1999, kof99n,   kof99,    neogeo, neogeo, neogeo,  kof99n,   ROT0, "SNK", "The King of Fighters '99 - Millennium Battle (not encrypted)" , 0)	/* Encrypted GFX */
GAMEB( 1999, kof99p,   kof99,    neogeo, neogeo, neogeo,  neogeo,   ROT0, "SNK", "The King of Fighters '99 - Millennium Battle (prototype)", 0 )
GAMEB( 1999, garou,    neogeo,   neogeo, neogeo, neogeo,  garou,    ROT0, "SNK", "Garou - Mark of the Wolves (set 1)" , 0) /* Encrypted Code & GFX */
GAMEB( 1999, garouo,   garou,    neogeo, neogeo, neogeo,  garouo,   ROT0, "SNK", "Garou - Mark of the Wolves (set 2)" , 0) /* Encrypted Code & GFX */
GAMEB( 1999, garoup,   garou,    neogeo, neogeo, neogeo,  neogeo,   ROT0, "SNK", "Garou - Mark of the Wolves (prototype)", 0 )
GAMEB( 2000, mslug3,   neogeo,   neogeo, neogeo, neogeo,  mslug3,   ROT0, "SNK", "Metal Slug 3" , 0) /* Encrypted Code & GFX */
GAMEB( 2000, mslug3n,  mslug3,   neogeo, neogeo, neogeo,  mslug3n,  ROT0, "SNK", "Metal Slug 3 (not encrypted)" , 0) /* Encrypted GFX */
GAMEB( 2000, mslug3b6, mslug3,   neogeo, neogeo, neogeo,  mslug3b6, ROT0, "bootleg", "Metal Slug 6 (Metal Slug 3 bootleg)", 0 ) /* real Metal Slug 6 is an Atomiswave HW game, see atomswav.c ;-) */
GAMEB( 2000, kof2000,  neogeo,   neogeo, neogeo, neogeo,  kof2000,  ROT0, "SNK", "The King of Fighters 2000" , 0) /* Encrypted Code & GFX */
GAMEB( 2000, kof2000n, kof2000,  neogeo, neogeo, neogeo,  kof2000n, ROT0, "SNK", "The King of Fighters 2000 (not encrypted)" , 0) /* Encrypted GFX */
GAMEB( 2001, zupapa,   neogeo,   neogeo, neogeo, neogeo,  zupapa,   ROT0, "SNK", "Zupapa!" , 0)	/* Encrypted GFX */
GAMEB( 2001, sengoku3, neogeo,   neogeo, neogeo, neogeo,  sengoku3, ROT0, "SNK", "Sengoku 3" , 0)	/* Encrypted GFX */
GAMEB( 2001, kof2001,  neogeo,   neogeo, neogeo, neogeo,  kof2001,  ROT0, "Eolith / SNK", "The King of Fighters 2001 (set 1)" , 0) /* Encrypted GFX */
GAMEB( 2001, kof2001h, kof2001,  neogeo, neogeo, neogeo,  kof2001,  ROT0, "Eolith / SNK", "The King of Fighters 2001 (set 2)" , 0) /* Encrypted GFX */
GAMEB( 2003, cthd2003, kof2001,  neogeo, neogeo, neogeo,  cthd2003, ROT0, "bootleg", "Crouching Tiger Hidden Dragon 2003 (The King of Fighters 2001 bootleg)", 0 ) /* Protected Hack / Bootleg of kof2001 */
GAMEB( 2003, ct2k3sp,  kof2001,  neogeo, neogeo, neogeo,  ct2k3sp,  ROT0, "bootleg", "Crouching Tiger Hidden Dragon 2003 Super Plus (The King of Fighters 2001 bootleg)", 0 ) /* Protected Hack / Bootleg of kof2001 */
GAMEB( 2002, kof2002,  neogeo,   neogeo, neogeo, neogeo,  kof2002,  ROT0, "Eolith / Playmore", "The King of Fighters 2002" , 0) /* Encrypted GFX */
GAMEB( 2002, kf2k2pls, kof2002,  neogeo, neogeo, neogeo,  kf2k2pls, ROT0, "bootleg", "The King of Fighters 2002 Plus (set 1, bootleg)" , 0) /* Encrypted GFX */
GAMEB( 2002, kf2k2pla, kof2002,  neogeo, neogeo, neogeo,  kf2k2pls, ROT0, "bootleg", "The King of Fighters 2002 Plus (set 2, bootleg)" , 0) /* Encrypted GFX */
GAMEB( 2002, kf2k2mp,  kof2002,  neogeo, neogeo, neogeo,  kf2k2mp,  ROT0, "bootleg", "The King of Fighters 2002 Magic Plus (bootleg)" , 0) /* Encrypted GFX */
GAMEB( 2002, kf2k2mp2, kof2002,  neogeo, neogeo, neogeo,  kof2km2,  ROT0, "bootleg", "The King of Fighters 2002 Magic Plus II (bootleg)" , 0) /* Encrypted GFX */
GAMEB( 2002, kof10th,  kof2002,  neogeo, neogeo, neogeo,  kof10th,  ROT0, "bootleg", "The King Of Fighters 10th Anniversary (The King of Fighters 2002 bootleg)", 0 ) // fake SNK copyright
GAMEB( 2004, kf2k5uni, kof2002,  neogeo, neogeo, neogeo,  kf2k5uni, ROT0, "bootleg", "The King of Fighters 10th Anniversary 2005 Unique (The King of Fighters 2002 bootleg)", 0 ) // fake SNK copyright
GAMEB( 2005, kf10thep, kof2002,  neogeo, neogeo, neogeo,  kf10thep, ROT0, "bootleg", "The King of Fighters 10th Anniversary Extra Plus (The King of Fighters 2002 bootleg)", 0 ) // fake SNK copyright
GAMEB( 2004, kof2k4se, kof2002,  neogeo, neogeo, neogeo,  kof2k4se, ROT0, "bootleg", "The King of Fighters Special Edition 2004 (The King of Fighters 2002 bootleg)", 0 ) /* Hack / Bootleg of kof2002 */
GAMEB( 2003, mslug5,   neogeo,   neogeo, neogeo, neogeo,  mslug5,   ROT0, "SNK Playmore", "Metal Slug 5", 0 )
GAME ( 2003, ms5pcb,   0,                neogeo, neogeo,  ms5pcb,   ROT0, "SNK Playmore", "Metal Slug 5 (JAMMA PCB)", 0 )
GAMEB( 2003, ms5plus,  mslug5,   neogeo, neogeo, neogeo,  ms5plus,  ROT0, "bootleg", "Metal Slug 5 Plus (bootleg)",0 )
GAME ( 2003, svcpcb,   0,                neogeo, svcpcb,  svcpcb,   ROT0, "Playmore", "SvC Chaos - SNK vs Capcom (JAMMA PCB)", 0 ) // not a clone of neogeo because it's NOT a neogeo cart.
GAME ( 2003, svcpcba,  svcpcb,           neogeo, svcpcb,  svcpcb,   ROT0, "Playmore", "SVC Chaos - SNK vs CAPCOM (JAMMA PCB, set 2)" , 0 ) /* Encrypted Code */
GAMEB( 2003, svc,      neogeo,   neogeo, neogeo, neogeo,  svchaosa, ROT0, "Playmore", "SvC Chaos - SNK vs Capcom (MVS)", 0 )
GAMEB( 2003, svcboot,  svc,      neogeo, neogeo, neogeo,  svcboot,  ROT0, "bootleg", "SvC Chaos - SNK vs Capcom (MVS) (bootleg)",0 )
GAMEB( 2003, svcplus,  svc,      neogeo, neogeo, neogeo,  svcplus,  ROT0, "bootleg", "SvC Chaos - SNK vs Capcom Plus (set 1, bootleg)",0 )
GAMEB( 2003, svcplusa, svc,      neogeo, neogeo, neogeo,  svcplusa, ROT0, "bootleg", "SvC Chaos - SNK vs Capcom Plus (set 2, bootleg)",0 )
GAMEB( 2003, svcsplus, svc,      neogeo, neogeo, neogeo,  svcsplus, ROT0, "bootleg", "SvC Chaos - SNK vs Capcom Super Plus (bootleg)",0 )
GAMEB( 2003, samsho5,  neogeo,   neogeo, neogeo, neogeo,  samsho5,  ROT0, "Yuki Enterprise / SNK Playmore", "Samurai Shodown V / Samurai Spirits Zero (set 1)", 0 )
GAMEB( 2003, samsho5h, samsho5,  neogeo, neogeo, neogeo,  samsho5,  ROT0, "Yuki Enterprise / SNK Playmore", "Samurai Shodown V / Samurai Spirits Zero (set 2)", 0 )
GAMEB( 2003, samsho5b, samsho5,  neogeo, neogeo, neogeo,  samsho5b, ROT0, "bootleg", "Samurai Shodown V / Samurai Spirits Zero (bootleg)", 0 ) // different program scrambling
GAME ( 2003, kf2k3pcb, 0,                neogeo, neogeo,  kf2k3pcb, ROT0, "SNK Playmore", "The King of Fighters 2003 (Japan, JAMMA PCB)", 0 ) // not a clone of neogeo because it's NOT a neogeo cart.
GAMEB( 2003, kof2003,  neogeo,   neogeo, neogeo, neogeo,  kof2003,  ROT0, "SNK Playmore", "The King of Fighters 2003 (World / US, MVS)", 0 )
GAMEB( 2003, kf2k3bl,  kof2003,  neogeo, neogeo, neogeo,  kof2003b, ROT0, "bootleg", "The King of Fighters 2003 (bootleg, set 1)",0 ) // zooming is wrong because its a bootleg of the pcb version on a cart (unless it was a bootleg pcb with the new bios?)
GAMEB( 2003, kf2k3bla, kof2003,  neogeo, neogeo, neogeo,  kof2k3pl, ROT0, "bootleg", "The King of Fighters 2003 (bootleg, set 2)",0 ) // zooming is wrong because its a bootleg of the pcb version on a cart
GAMEB( 2003, kf2k3pl,  kof2003,  neogeo, neogeo, neogeo,  kof2k3pl, ROT0, "bootleg", "The King of Fighters 2004 Plus / Hero (The King of Fighters 2003 bootleg)",0 ) // zooming is wrong because its a bootleg of the pcb version on a cart
GAMEB( 2003, kf2k3upl, kof2003,  neogeo, neogeo, neogeo,  kof2k3up, ROT0, "bootleg", "The King of Fighters 2004 Ultra Plus (The King of Fighters 2003 bootleg)",0 ) // zooming is wrong because its a bootleg of the pcb version on a cart
GAMEB( 2003, samsh5sp, neogeo,   neogeo, neogeo, neogeo,  samsh5sp, ROT0, "Yuki Enterprise / SNK Playmore", "Samurai Shodown V Special / Samurai Spirits Zero Special (set 1, uncensored)", 0 )
GAMEB( 2003, samsh5sh, samsh5sp, neogeo, neogeo, neogeo,  samsh5sp, ROT0, "Yuki Enterprise / SNK Playmore", "Samurai Shodown V Special / Samurai Spirits Zero Special (set 2, censored)", 0 )
GAMEB( 2003, samsh5sn, samsh5sp, neogeo, neogeo, neogeo,  samsh5sp, ROT0, "Yuki Enterprise / SNK Playmore", "Samurai Shodown V Special / Samurai Spirits Zero Special (set 3, less censored)", 0 )

/* there are other bootlegs kof2002b etc. kof96ep, matrimbl?, kf2k1pls -- work out which should be supported */

/* Alpha Denshi Co. / ADK (changed name in 1993) */
GAMEB( 1990, maglord,  neogeo,   neogeo, neogeo, neogeo,  neogeo,   ROT0, "Alpha Denshi Co.", "Magician Lord (set 1)", 0 )
GAMEB( 1990, maglordh, maglord,  neogeo, neogeo, neogeo,  neogeo,   ROT0, "Alpha Denshi Co.", "Magician Lord (set 2)", 0 )
GAMEB( 1990, ncombat,  neogeo,   neogeo, neogeo, neogeo,  neogeo,   ROT0, "Alpha Denshi Co.", "Ninja Combat (set 1)", 0 )
GAMEB( 1990, ncombata, ncombat,  neogeo, neogeo, neogeo,  neogeo,   ROT0, "Alpha Denshi Co.", "Ninja Combat (set 2)", 0 )
GAMEB( 1990, bjourney, neogeo,   neogeo, neogeo, neogeo,  neogeo,   ROT0, "Alpha Denshi Co.", "Blue's Journey / Raguy", 0 )
GAMEB( 1991, crsword,  neogeo,   neogeo, neogeo, neogeo,  neogeo,   ROT0, "Alpha Denshi Co.", "Crossed Swords", 0 )
GAMEB( 1991, trally,   neogeo,   neogeo, neogeo, neogeo,  neogeo,   ROT0, "Alpha Denshi Co.", "Thrash Rally", 0 )
GAMEB( 1992, ncommand, neogeo,   neogeo, neogeo, neogeo,  neogeo,   ROT0, "Alpha Denshi Co.", "Ninja Commando", 0 )
GAMEB( 1992, wh1,      neogeo,   neogeo, neogeo, neogeo,  neogeo,   ROT0, "Alpha Denshi Co.", "World Heroes (set 1)", 0 )
GAMEB( 1992, wh1h,     wh1,      neogeo, neogeo, neogeo,  neogeo,   ROT0, "Alpha Denshi Co.", "World Heroes (set 2)", 0 )
GAMEB( 1993, wh2,      neogeo,   neogeo, neogeo, neogeo,  neogeo,   ROT0, "ADK",              "World Heroes 2", 0 )
GAMEB( 1994, wh2j,     neogeo,   neogeo, neogeo, neogeo,  neogeo,   ROT0, "ADK / SNK",        "World Heroes 2 Jet", 0 )
GAMEB( 1994, aodk,     neogeo,   neogeo, neogeo, neogeo,  neogeo,   ROT0, "ADK / SNK",        "Aggressors of Dark Kombat / Tsuukai GANGAN Koushinkyoku", 0 )
GAMEB( 1995, whp,      neogeo,   neogeo, neogeo, neogeo,  neogeo,   ROT0, "ADK / SNK",        "World Heroes Perfect", 0 )
GAMEB( 1995, mosyougi, neogeo,   neogeo, neogeo, neogeo,  neogeo,   ROT0, "ADK / SNK",        "Syougi No Tatsujin - Master of Syougi", 0 )
GAMEB( 1996, overtop,  neogeo,   neogeo, neogeo, neogeo,  neogeo,   ROT0, "ADK",              "Over Top", 0 )
GAMEB( 1996, ninjamas, neogeo,   neogeo, neogeo, neogeo,  neogeo,   ROT0, "ADK / SNK",        "Ninja Master's - haoh-ninpo-cho", 0 )
GAMEB( 1996, twinspri, neogeo,   neogeo, neogeo, neogeo,  neogeo,   ROT0, "ADK",              "Twinkle Star Sprites", 0 )
GAMEB( 1996, zintrckb, neogeo,   neogeo, neogeo, neogeo,  neogeo,   ROT0, "hack / bootleg",   "Zintrick / Oshidashi Zentrix (hack / bootleg)", 0 )


/* Aicom */
GAMEB( 1994, janshin,  neogeo,   neogeo, neogeo, mjneogeo,mjneogeo, ROT0, "Aicom", "Jyanshin Densetsu - Quest of Jongmaster", 0 )
GAMEB( 1995, pulstar,  neogeo,   neogeo, neogeo, neogeo,  neogeo,   ROT0, "Aicom", "Pulstar", 0 )

/* Data East Corporation */
GAMEB( 1993, spinmast, neogeo,   neogeo, neogeo, neogeo,  neogeo,   ROT0, "Data East Corporation", "Spin Master / Miracle Adventure", 0 )
GAMEB( 1994, wjammers, neogeo,   neogeo, neogeo, neogeo,  neogeo,   ROT0, "Data East Corporation", "Windjammers / Flying Power Disc", 0 )
GAMEB( 1994, karnovr,  neogeo,   neogeo, neogeo, neogeo,  neogeo,   ROT0, "Data East Corporation", "Karnov's Revenge / Fighter's History Dynamite", 0 )
GAMEB( 1994, strhoop,  neogeo,   neogeo, neogeo, neogeo,  neogeo,   ROT0, "Data East Corporation", "Street Hoop / Street Slam / Dunk Dream", 0 )
GAMEB( 1996, ghostlop, neogeo,   neogeo, neogeo, neogeo,  neogeo,   ROT0, "Data East Corporation", "Ghostlop (prototype)", 0 )
GAMEB( 1996, magdrop2, neogeo,   neogeo, neogeo, neogeo,  neogeo,   ROT0, "Data East Corporation", "Magical Drop II", 0 )
GAMEB( 1997, magdrop3, neogeo,   neogeo, neogeo, neogeo,  neogeo,   ROT0, "Data East Corporation", "Magical Drop III", 0 )

/* Eleven */
GAMEB( 2000, nitd,     neogeo,   neogeo, neogeo, neogeo,  nitd,     ROT0, "Eleven / Gavaking", "Nightmare in the Dark" , 0) /* Encrypted GFX */

/* Face */
GAMEB( 1994, gururin,  neogeo,   neogeo, neogeo, neogeo,  neogeo,   ROT0, "Face", "Gururin", 0 )
GAMEB( 1997, miexchng, neogeo,   neogeo, neogeo, neogeo,  neogeo,   ROT0, "Face", "Money Puzzle Exchanger / Money Idol Exchanger", 0 )

/* Hudson Soft */
GAMEB( 1994, panicbom, neogeo,   neogeo, neogeo, neogeo,  neogeo,   ROT0, "Eighting / Hudson", "Panic Bomber", 0 )
GAMEB( 1995, kabukikl, neogeo,   neogeo, neogeo, neogeo,  neogeo,   ROT0, "Hudson", "Far East of Eden - Kabuki Klash / Tengai Makyou - Shin Den", 0 )
GAMEB( 1997, neobombe, neogeo,   neogeo, neogeo, neogeo,  neogeo,   ROT0, "Hudson", "Neo Bomberman", 0 )

/* Monolith Corp. */
GAMEB( 1990, minasan,  neogeo,   neogeo, neogeo, mjneogeo,mjneogeo, ROT0, "Monolith Corp.", "Minnasanno Okagesamadesu", 0 )
GAMEB( 1991, bakatono, neogeo,   neogeo, neogeo, mjneogeo,mjneogeo, ROT0, "Monolith Corp.", "Bakatonosama Mahjong Manyuki", 0 )

/* Nazca */
GAMEB( 1996, turfmast, neogeo,   neogeo, neogeo, neogeo,  neogeo,   ROT0, "Nazca", "Neo Turf Masters / Big Tournament Golf", 0 )
GAMEB( 1996, mslug,    neogeo,   neogeo, neogeo, neogeo,  neogeo,   ROT0, "Nazca", "Metal Slug - Super Vehicle-001", 0 )

/* NMK */
GAMEB( 1994, zedblade, neogeo,   neogeo, neogeo, neogeo,  neogeo,   ROT0, "NMK", "Zed Blade / Operation Ragnarok", 0 )

/* Psikyo */
GAMEB( 1999, s1945p,   neogeo,   neogeo, neogeo, neogeo,  s1945p,   ROT0, "Psikyo", "Strikers 1945 Plus" , 0)	/* Encrypted GFX */

/* Sammy */
GAMEB( 1992, viewpoin, neogeo,   neogeo, neogeo, neogeo,  neogeo,   ROT0, "Sammy", "Viewpoint", 0 )

/* Saurus */
GAMEB( 1995, quizkof,  neogeo,   neogeo, neogeo, neogeo,  neogeo,   ROT0, "Saurus", "Quiz King of Fighters", 0 )
GAMEB( 1995, stakwin,  neogeo,   neogeo, neogeo, neogeo,  neogeo,   ROT0, "Saurus", "Stakes Winner / Stakes Winner - GI kinzen seihae no michi", 0 )
GAMEB( 1996, ragnagrd, neogeo,   neogeo, neogeo, neogeo,  neogeo,   ROT0, "Saurus", "Ragnagard / Shin-Oh-Ken", 0 )
GAMEB( 1996, pgoal,    neogeo,   neogeo, neogeo, neogeo,  neogeo,   ROT0, "Saurus", "Pleasure Goal / Futsal - 5 on 5 Mini Soccer", 0 )
GAMEB( 1996, stakwin2, neogeo,   neogeo, neogeo, neogeo,  neogeo,   ROT0, "Saurus", "Stakes Winner 2", 0 )
GAMEB( 1997, shocktro, neogeo,   neogeo, neogeo, neogeo,  neogeo,   ROT0, "Saurus", "Shock Troopers (set 1)", 0 )
GAMEB( 1997, shocktra, shocktro, neogeo, neogeo, neogeo,  neogeo,   ROT0, "Saurus", "Shock Troopers (set 2)", 0 )
GAMEB( 1998, shocktr2, neogeo,   neogeo, neogeo, neogeo,  neogeo,   ROT0, "Saurus", "Shock Troopers - 2nd Squad", 0 )
GAMEB( 1998, lans2004, shocktr2, neogeo, neogeo, neogeo,  lans2004, ROT0, "bootleg", "Lansquenet 2004 (Shock Troopers - 2nd Squad bootleg)", 0 )

/* Sunsoft */
GAMEB( 1995, galaxyfg, neogeo,   neogeo, neogeo, neogeo,  neogeo,   ROT0, "Sunsoft", "Galaxy Fight - Universal Warriors", 0 )
GAMEB( 1996, wakuwak7, neogeo,   neogeo, neogeo, neogeo,  neogeo,   ROT0, "Sunsoft", "Waku Waku 7", 0 )

/* Taito */
GAMEB( 1994, pbobblen, neogeo,   neogeo, neogeo, neogeo,  neogeo,   ROT0, "Taito", "Puzzle Bobble / Bust-A-Move (Neo-Geo) (set 1)", 0 )
GAMEB( 1994, pbobblna, pbobblen, neogeo, neogeo, neogeo,  neogeo,   ROT0, "Taito", "Puzzle Bobble / Bust-A-Move (Neo-Geo) (set 2)", 0 )
GAMEB( 1999, pbobbl2n, neogeo,   neogeo, neogeo, neogeo,  neogeo,   ROT0, "Taito (SNK license)", "Puzzle Bobble 2 / Bust-A-Move Again (Neo-Geo)", 0 )
GAMEB( 2003, pnyaa,    neogeo,   neogeo, neogeo, neogeo,  pnyaa,    ROT0, "Aiky / Taito", "Pochi and Nyaa", 0 )

/* Takara */
GAMEB( 1995, marukodq, neogeo,   neogeo, neogeo, neogeo,  neogeo,   ROT0, "Takara", "Chibi Marukochan Deluxe Quiz", 0 )

/* Technos */
GAMEB( 1995, doubledr, neogeo,   neogeo, neogeo, neogeo,  neogeo,   ROT0, "Technos", "Double Dragon (Neo-Geo)", 0 )
GAMEB( 1995, gowcaizr, neogeo,   neogeo, neogeo, neogeo,  neogeo,   ROT0, "Technos", "Voltage Fighter - Gowcaizer / Choujin Gakuen Gowcaizer", 0)
GAMEB( 1996, sdodgeb,  neogeo,   neogeo, neogeo, neogeo,  neogeo,   ROT0, "Technos", "Super Dodge Ball / Kunio no Nekketsu Toukyuu Densetsu", 0 )

/* Tecmo */
GAMEB( 1996, tws96,    neogeo,   neogeo, neogeo, neogeo,  neogeo,   ROT0, "Tecmo", "Tecmo World Soccer '96", 0 )

/* Yumekobo */
GAMEB( 1998, blazstar, neogeo,   neogeo, neogeo, neogeo,  neogeo,   ROT0, "Yumekobo", "Blazing Star", 0 )
GAMEB( 1999, preisle2, neogeo,   neogeo, neogeo, neogeo,  preisle2, ROT0, "Yumekobo", "Prehistoric Isle 2" , 0) /* Encrypted GFX */

/* Viccom */
GAMEB( 1994, fightfev, neogeo,   neogeo, neogeo, neogeo,  neogeo,   ROT0, "Viccom", "Fight Fever (set 1)", 0 )
GAMEB( 1994, fightfva, fightfev, neogeo, neogeo, neogeo,  neogeo,   ROT0, "Viccom", "Fight Fever (set 2)", 0 )

/* Video System Co. */
GAMEB( 1994, pspikes2, neogeo,   neogeo, neogeo, neogeo,  neogeo,   ROT0, "Video System Co.", "Power Spikes II", 0 )
GAMEB( 1994, sonicwi2, neogeo,   neogeo, neogeo, neogeo,  neogeo,   ROT0, "Video System Co.", "Aero Fighters 2 / Sonic Wings 2", 0 )
GAMEB( 1995, sonicwi3, neogeo,   neogeo, neogeo, neogeo,  neogeo,   ROT0, "Video System Co.", "Aero Fighters 3 / Sonic Wings 3", 0 )
GAMEB( 1997, popbounc, neogeo,   neogeo, neogeo, popbounc,popbounc, ROT0, "Video System Co.", "Pop 'n Bounce / Gapporin", 0 )

/* Visco */
GAMEB( 1992, androdun, neogeo,   neogeo, neogeo, neogeo,  neogeo,   ROT0, "Visco", "Andro Dunos", 0 )
GAMEB( 1995, puzzledp, neogeo,   neogeo, neogeo, neogeo,  neogeo,   ROT0, "Taito (Visco license)", "Puzzle De Pon!", 0 )
GAMEB( 1996, neomrdo,  neogeo,   neogeo, neogeo, neogeo,  neogeo,   ROT0, "Visco", "Neo Mr. Do!", 0 )
GAMEB( 1995, goalx3,   neogeo,   neogeo, neogeo, neogeo,  neogeo,   ROT0, "Visco", "Goal! Goal! Goal!", 0 )
GAMEB( 1996, neodrift, neogeo,   neogeo, neogeo, neogeo,  neogeo,   ROT0, "Visco", "Neo Drift Out - New Technology", 0 )
GAMEB( 1996, breakers, neogeo,   neogeo, neogeo, neogeo,  neogeo,   ROT0, "Visco", "Breakers", 0 )
GAMEB( 1997, puzzldpr, puzzledp, neogeo, neogeo, neogeo,  neogeo,   ROT0, "Taito (Visco license)", "Puzzle De Pon! R!", 0 )
GAMEB( 1998, breakrev, breakers, neogeo, neogeo, neogeo,  neogeo,   ROT0, "Visco", "Breakers Revenge", 0)
GAMEB( 1998, flipshot, neogeo,   neogeo, neogeo, neogeo,  neogeo,   ROT0, "Visco", "Battle Flip Shot", 0 )
GAMEB( 1999, ctomaday, neogeo,   neogeo, neogeo, neogeo,  neogeo,   ROT0, "Visco", "Captain Tomaday", 0 )
GAMEB( 1999, ganryu,   neogeo,   neogeo, neogeo, neogeo,  ganryu,   ROT0, "Visco", "Ganryu / Musashi Ganryuki" , 0)	/* Encrypted GFX */
GAMEB( 2000, bangbead, neogeo,   neogeo, neogeo, neogeo,  bangbead, ROT0, "Visco", "Bang Bead", 0 )
//GAMEB( 2000, bangbedp, bangbead, neogeo, neogeo, neogeo,  neogeo,   ROT0, "Visco", "Bang Bead (prototype)", 0 )

/* Mega Enterprise */
GAMEB( 2002, mslug4,   neogeo,   neogeo, neogeo, neogeo,  mslug4,   ROT0, "Mega", "Metal Slug 4", 0 )
GAMEB( 2002, ms4plus,  mslug4,   neogeo, neogeo, neogeo,  neogeo,   ROT0, "bootleg", "Metal Slug 4 Plus (bootleg)", 0 )

/* Evoga */
GAMEB( 2002, rotd,     neogeo,	 neogeo, neogeo, neogeo,  rotd,	    ROT0, "Evoga / Playmore", "Rage of the Dragons", 0 )

/* Atlus */
GAMEB( 2002, matrim,   neogeo,   neogeo, neogeo, neogeo,  matrim,   ROT0, "Noise Factory / Atlus", "Matrimelee / Shin Gouketsuji Ichizoku Toukon", 0 )

/* Breezasoft */
GAMEB( 2001, jockeygp, neogeo,   neogeo, neogeo, jockeygp,jockeygp, ROT0, "Sun Amusement / BrezzaSoft", "Jockey Grand Prix", 0 )
GAMEB( 2001, vliner,   neogeo,   neogeo, neogeo, vliner,  vliner,   ROT0, "Dyna / BreezaSoft", "V-Liner (set 1)", 0 )
GAMEB( 2001, vlinero,  vliner,   neogeo, neogeo, vliner,  vliner,   ROT0, "Dyna / BreezaSoft", "V-Liner (set 2)", 0 )
