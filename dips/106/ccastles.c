# MAME 0.106 source snippet.

/*************************************
 *
 *  Port definitions
 *
 *************************************/

INPUT_PORTS_START( ccastles )
	PORT_START	/* IN0 */
	PORT_BIT ( 0x01, IP_ACTIVE_LOW, IPT_COIN2 )
	PORT_BIT ( 0x02, IP_ACTIVE_LOW, IPT_COIN1 )
	PORT_BIT ( 0x04, IP_ACTIVE_LOW, IPT_COIN3 )
	PORT_BIT ( 0x08, IP_ACTIVE_LOW, IPT_TILT )
	PORT_SERVICE( 0x10, IP_ACTIVE_LOW )
	PORT_BIT ( 0x20, IP_ACTIVE_HIGH, IPT_VBLANK )
	PORT_BIT ( 0x40, IP_ACTIVE_LOW, IPT_BUTTON1 )				/* 1p Jump, non-cocktail start1 */
	PORT_BIT ( 0x80, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_PLAYER(2)		/* 2p Jump, non-cocktail start2 */

	PORT_START	/* IN1 */
	PORT_BIT ( 0x07, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT ( 0x08, IP_ACTIVE_LOW, IPT_START1 )				/* cocktail only */
	PORT_BIT ( 0x10, IP_ACTIVE_LOW, IPT_START2 )				/* cocktail only */
	PORT_DIPNAME( 0x20, 0x00, DEF_STR( Cabinet ) )
	PORT_DIPSETTING (   0x00, DEF_STR( Upright ) )
	PORT_DIPSETTING (   0x20, DEF_STR( Cocktail ) )
	PORT_BIT ( 0xc0, IP_ACTIVE_HIGH, IPT_UNKNOWN )

	PORT_START	/* IN2 */
	PORT_BIT( 0xff, 0x7f, IPT_TRACKBALL_Y ) PORT_SENSITIVITY(10) PORT_KEYDELTA(30) PORT_REVERSE

	PORT_START	/* IN3 */
	PORT_BIT( 0xff, 0x7f, IPT_TRACKBALL_X ) PORT_SENSITIVITY(10) PORT_KEYDELTA(30)
INPUT_PORTS_END



/*************************************
 *
 *  Game drivers
 *
 *************************************/

GAME( 1983, ccastles, 0,        ccastles, ccastles, 0, ROT0, "Atari", "Crystal Castles (version 4)", 0 )
GAME( 1983, ccastle3, ccastles, ccastles, ccastles, 0, ROT0, "Atari", "Crystal Castles (version 3)", 0 )
GAME( 1983, ccastle2, ccastles, ccastles, ccastles, 0, ROT0, "Atari", "Crystal Castles (version 2)", 0 )
