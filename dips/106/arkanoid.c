/* Input Ports */
#define ARKNOI_IN0\
	PORT_START_TAG("IN0")\
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_START1 )\
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_START2 )\
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_SERVICE1 )\
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_TILT )\
	PORT_BIT( 0x10, IP_ACTIVE_HIGH, IPT_COIN1 )\
	PORT_BIT( 0x20, IP_ACTIVE_HIGH, IPT_COIN2 )\
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_SPECIAL )	/* input from the 68705, some bootlegs need it to be 1 */\
	PORT_BIT( 0x80, IP_ACTIVE_HIGH, IPT_SPECIAL )	/* input from the 68705 */

#define ARKNOI_IN1\
	PORT_START_TAG("IN1")\
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_BUTTON1 )\
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_UNKNOWN )\
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_COCKTAIL\
	PORT_BIT( 0xf8, IP_ACTIVE_LOW, IPT_UNKNOWN )

#define ARKNOI_SPINNERS\
	PORT_START_TAG("IN2")      /* Spinner Player 1 */\
	PORT_BIT( 0xff, 0x00, IPT_DIAL ) PORT_SENSITIVITY(30) PORT_KEYDELTA(15)\
	PORT_START_TAG("IN3")      /* Spinner Player 2  */\
	PORT_BIT( 0xff, 0x00, IPT_DIAL ) PORT_SENSITIVITY(30) PORT_KEYDELTA(15) PORT_COCKTAIL

INPUT_PORTS_START( arkanoid )
	ARKNOI_IN0
	ARKNOI_IN1
	ARKNOI_SPINNERS

	PORT_START_TAG("DSW")
	PORT_DIPNAME( 0x01, 0x00, DEF_STR( Allow_Continue ) )
	PORT_DIPSETTING(    0x01, DEF_STR( No ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Yes ) )
	PORT_DIPNAME( 0x02, 0x02, DEF_STR( Flip_Screen ) )
	PORT_DIPSETTING(    0x02, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_SERVICE( 0x04, IP_ACTIVE_LOW )
	PORT_DIPNAME( 0x08, 0x08, DEF_STR( Difficulty ) )
	PORT_DIPSETTING(    0x08, DEF_STR( Easy ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Hard ) )
	PORT_DIPNAME( 0x10, 0x10, DEF_STR( Bonus_Life ) )
	PORT_DIPSETTING(    0x10, "20K 60K 60K+" )
	PORT_DIPSETTING(    0x00, "20K" )
	PORT_DIPNAME( 0x20, 0x20, DEF_STR( Lives ) )
	PORT_DIPSETTING(    0x20, "3" )
	PORT_DIPSETTING(    0x00, "5" )
	PORT_DIPNAME( 0xc0, 0xc0, DEF_STR( Coinage ) )
	PORT_DIPSETTING(    0x40, DEF_STR( 2C_1C ) )
	PORT_DIPSETTING(    0xc0, DEF_STR( 1C_1C ) )
	PORT_DIPSETTING(    0x80, DEF_STR( 1C_2C ) )
	PORT_DIPSETTING(    0x00, DEF_STR( 1C_6C ) )
INPUT_PORTS_END

/* These are the input ports of the real Japanese ROM set                        */
/* 'Block' uses the these ones as well. The Tayto bootleg is different           */
/*  in coinage and # of lives.                                                   */

INPUT_PORTS_START( arknoidj )
	ARKNOI_IN0
	ARKNOI_IN1
	ARKNOI_SPINNERS

	PORT_START_TAG("DSW")
	PORT_DIPNAME( 0x01, 0x00, DEF_STR( Allow_Continue ) )
	PORT_DIPSETTING(    0x01, DEF_STR( No ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Yes ) )
	PORT_DIPNAME( 0x02, 0x02, DEF_STR( Flip_Screen ) )
	PORT_DIPSETTING(    0x02, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_SERVICE( 0x04, IP_ACTIVE_LOW )
	PORT_DIPNAME( 0x08, 0x08, DEF_STR( Difficulty ) )
	PORT_DIPSETTING(    0x08, DEF_STR( Easy ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Hard ) )
	PORT_DIPNAME( 0x10, 0x10, DEF_STR( Bonus_Life ) )
	PORT_DIPSETTING(    0x10, "20K 60K 60K+" )
	PORT_DIPSETTING(    0x00, "20K" )
	PORT_DIPNAME( 0x20, 0x20, DEF_STR( Lives ) )
	PORT_DIPSETTING(    0x20, "3" )
	PORT_DIPSETTING(    0x00, "5" )
	PORT_DIPNAME( 0x40, 0x40, DEF_STR( Coinage ) )
	PORT_DIPSETTING(    0x40, DEF_STR( 1C_1C ) )
	PORT_DIPSETTING(    0x00, DEF_STR( 1C_2C ) )
	PORT_DIPNAME( 0x80, 0x00, DEF_STR( Cabinet ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Upright ) )
	PORT_DIPSETTING(    0x80, DEF_STR( Cocktail ) )
INPUT_PORTS_END

/* Is the same as arkanoij, but the Coinage,
  Lives and Bonus_Life dips are different */
INPUT_PORTS_START( arkatayt )
	ARKNOI_IN0
	ARKNOI_IN1
	ARKNOI_SPINNERS

	PORT_START_TAG("DSW")
	PORT_DIPNAME( 0x01, 0x00, DEF_STR( Allow_Continue ) )
	PORT_DIPSETTING(    0x01, DEF_STR( No ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Yes ) )
	PORT_DIPNAME( 0x02, 0x02, DEF_STR( Flip_Screen ) )
	PORT_DIPSETTING(    0x02, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_SERVICE( 0x04, IP_ACTIVE_LOW )
	PORT_DIPNAME( 0x08, 0x08, DEF_STR( Difficulty ) )
	PORT_DIPSETTING(    0x08, DEF_STR( Easy ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Hard ) )
	PORT_DIPNAME( 0x10, 0x10, DEF_STR( Bonus_Life ) )
	PORT_DIPSETTING(    0x10, "60K 100K 60K+" )
	PORT_DIPSETTING(    0x00, "60K" )
	PORT_DIPNAME( 0x20, 0x00, DEF_STR( Lives ) )
	PORT_DIPSETTING(    0x20, "2" )
	PORT_DIPSETTING(    0x00, "3" )
	PORT_DIPNAME( 0x40, 0x40, DEF_STR( Coinage ) )
	PORT_DIPSETTING(    0x00, DEF_STR( 2C_1C ) )
	PORT_DIPSETTING(    0x40, DEF_STR( 1C_1C ) )
	PORT_DIPNAME( 0x80, 0x00, DEF_STR( Cabinet ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Upright ) )
	PORT_DIPSETTING(    0x80, DEF_STR( Cocktail ) )
INPUT_PORTS_END

INPUT_PORTS_START( tetrsark )
	/* most of these probably just aren't connected rather than being dipswitches */
	PORT_START_TAG("IN0")
	/*
    PORT_DIPNAME( 0x01, 0x01, "0" )
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
    PORT_DIPSETTING(    0x80, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    */
	PORT_START_TAG("IN1")

	PORT_START_TAG("IN2")

	PORT_START_TAG("IN3")

	PORT_START_TAG("IN4")
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN ) PORT_PLAYER(2)
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT ) PORT_PLAYER(2)
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT ) PORT_PLAYER(2)
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_PLAYER(2) // or up? it rotates the piece.
	/* coinage? */
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
    PORT_DIPSETTING(    0x80, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )

	PORT_START_TAG("IN5")
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN ) PORT_PLAYER(1)
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT ) PORT_PLAYER(1)
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT ) PORT_PLAYER(1)
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_PLAYER(1) // or up? it rotates the piece.
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_START1 )
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_START2 )
//  PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_COIN1 ) // WTF? it does't work
//  PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_COIN2 ) // WTF? it does't work
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_BUTTON2 ) PORT_PLAYER(1)
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_BUTTON2 ) PORT_PLAYER(2)
INPUT_PORTS_END


/* Game Drivers */

GAME( 1986, arkanoid, 0,        arkanoid, arkanoid, 0,       ROT90, "Taito Corporation Japan", "Arkanoid (World)", GAME_SUPPORTS_SAVE )
GAME( 1986, arknoidu, arkanoid, arkanoid, arkanoid, 0,       ROT90, "Taito America Corporation (Romstar license)", "Arkanoid (US)", GAME_SUPPORTS_SAVE )
GAME( 1986, arknoiuo, arkanoid, arkanoid, arkanoid, 0,       ROT90, "Taito America Corporation (Romstar license)", "Arkanoid (US, older)", GAME_SUPPORTS_SAVE )
GAME( 1986, arknoidj, arkanoid, arkanoid, arknoidj, 0,       ROT90, "Taito Corporation", "Arkanoid (Japan)", GAME_SUPPORTS_SAVE )
GAME( 1986, arkbl2,   arkanoid, arkanoid, arknoidj, 0,       ROT90, "bootleg", "Arkanoid (Japanese bootleg Set 2)", GAME_NOT_WORKING )
GAME( 1986, arkbl3,   arkanoid, bootleg,  arknoidj, paddle2, ROT90, "bootleg", "Arkanoid (Japanese bootleg Set 3)", GAME_NOT_WORKING )
GAME( 1988, paddle2,  arkanoid, bootleg,  arknoidj, paddle2, ROT90, "bootleg", "Paddle 2", GAME_UNEMULATED_PROTECTION | GAME_SUPPORTS_SAVE )
GAME( 1986, arkatayt, arkanoid, bootleg,  arkatayt, 0,       ROT90, "bootleg", "Arkanoid (Tayto bootleg, Japanese)", GAME_SUPPORTS_SAVE )
GAME( 1986, arkblock, arkanoid, bootleg,  arknoidj, 0,       ROT90, "bootleg", "Block (bootleg, Japanese)", GAME_NOT_WORKING )
GAME( 1986, arkbloc2, arkanoid, bootleg,  arknoidj, 0,       ROT90, "bootleg", "Block (Game Corporation bootleg)", GAME_SUPPORTS_SAVE )
GAME( 1986, arkangc,  arkanoid, bootleg,  arknoidj, 0,       ROT90, "bootleg", "Arkanoid (Game Corporation bootleg)", GAME_SUPPORTS_SAVE )
GAME( 1987, arkatour, arkanoid, arkanoid, arkanoid, 0,       ROT90, "Taito America Corporation (Romstar license)", "Tournament Arkanoid (US)", GAME_SUPPORTS_SAVE )
GAME( 19??, tetrsark, 0,        bootleg,  tetrsark, tetrsark,ROT0,  "D.R. Korea", "Tetris (D.R. Korea)", GAME_SUPPORTS_SAVE | GAME_WRONG_COLORS )
