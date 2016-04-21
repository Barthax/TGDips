/************************************************************************

  Inputs

************************************************************************/

INPUT_PORTS_START( quasar )
	PORT_START	/* Controls 0 */
    PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_START1 )
    PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_START2 )
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_COIN2 )
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_COIN1 )
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_COCKTAIL
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_BUTTON1 )
    PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_TILT )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_BUTTON3 )			/* switch collaudo */

	PORT_START	/* Controls 1 */
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_BUTTON4 )			/* tavalino */
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT ) PORT_COCKTAIL
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT )
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT ) PORT_COCKTAIL
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT )
    PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_BUTTON2 ) PORT_COCKTAIL
    PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_BUTTON2 )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_START3 )				/* count enable */

	PORT_START	/* DSW0 */
	PORT_DIPNAME( 0x0c, 0x04, DEF_STR( Coin_A ) )			/* confirmed */
	PORT_DIPSETTING(    0x00, DEF_STR( 2C_1C ) )
	PORT_DIPSETTING(    0x04, DEF_STR( 1C_1C ) )
	PORT_DIPSETTING(    0x08, DEF_STR( 1C_2C ) )
	PORT_DIPSETTING(    0x0c, DEF_STR( 1C_3C ) )
	PORT_DIPNAME( 0x03, 0x00, DEF_STR( Coin_B ) )			/* confirmed */
	PORT_DIPSETTING(    0x00, DEF_STR( 1C_1C ) )
	PORT_DIPSETTING(    0x01, DEF_STR( 1C_2C ) )
	PORT_DIPSETTING(    0x02, DEF_STR( 1C_3C ) )
	PORT_DIPSETTING(    0x03, DEF_STR( 1C_5C ) )
	PORT_DIPNAME( 0x30, 0x00, "Number of Rockets" )			/* confirmed */
	PORT_DIPSETTING(    0x00, "3" )
	PORT_DIPSETTING(    0x10, "4" )
	PORT_DIPSETTING(    0x20, "5" )
	PORT_DIPSETTING(    0x30, "6" )
	PORT_DIPNAME( 0x40, 0x40, DEF_STR( Free_Play ) )
	PORT_DIPSETTING(    0x40, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x80, 0x80, "Test Mode" )					/* confirmed */
	PORT_DIPSETTING(    0x00, "Collisions excluded" )
	PORT_DIPSETTING(    0x80, "Collisions included" )

	PORT_START	/* DSW1 */
	PORT_DIPNAME( 0x07, 0x01, "High Score" )
	PORT_DIPSETTING(    0x00, "No H.S." ) // this option only wants bit 0 OFF
	PORT_DIPSETTING(    0x01, "Normal H.S." )
	PORT_DIPSETTING(    0x03, "Low H.S." )
	PORT_DIPSETTING(    0x05, "Medium H.S." )
	PORT_DIPSETTING(    0x07, "High H.S." )
	PORT_DIPNAME( 0x18, 0x10, DEF_STR( Difficulty ) )
	PORT_DIPSETTING(    0x18, DEF_STR( Easy ) )
	PORT_DIPSETTING(    0x10, DEF_STR( Medium ) )
	PORT_DIPSETTING(    0x08, "Difficult" )
	PORT_DIPSETTING(    0x00, "Very Difficult" )
	PORT_DIPNAME( 0x60, 0x20, "Extended Play" )
	PORT_DIPSETTING(    0x20, "5500" )						/* confirmed */
	PORT_DIPSETTING(    0x40, "7500" )
	PORT_DIPSETTING(    0x60, "9500" )
	PORT_DIPSETTING(    0x00, "17500" )
	PORT_DIPNAME( 0x80, 0x80, "Full Screen Rocket" )		/* confirmed */
	PORT_DIPSETTING(    0x80, "Stop at edge" )
	PORT_DIPSETTING(    0x00, "Wrap Around" )

	PORT_START	/* SENSE */
	PORT_BIT( 0x80, IP_ACTIVE_HIGH, IPT_VBLANK )

	PORT_START	// Sound DIP switch
#if 0
	PORT_DIPNAME( 0x0f, 0x00, "Noise to play" )
	PORT_DIPSETTING(    0x00, "00" )
	PORT_DIPSETTING(    0x01, "01" )
	PORT_DIPSETTING(    0x02, "02" )
	PORT_DIPSETTING(    0x03, "03" )
	PORT_DIPSETTING(    0x04, "04" )
	PORT_DIPSETTING(    0x05, "05" )
	PORT_DIPSETTING(    0x06, "06" )
	PORT_DIPSETTING(    0x07, "07" )
	PORT_DIPSETTING(    0x08, "08" )
	PORT_DIPSETTING(    0x09, "09" )
	PORT_DIPSETTING(    0x0a, "0A" )
	PORT_DIPSETTING(    0x0b, "0B" )
	PORT_DIPSETTING(    0x0c, "0C" )
	PORT_DIPSETTING(    0x0d, "0D" )
	PORT_DIPSETTING(    0x0e, "0E" )
	PORT_DIPSETTING(    0x0f, "0F" )
#endif
	PORT_DIPNAME( 0x10, 0x10, "Sound Test" )
	PORT_DIPSETTING(    0x10, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x20, 0x20, DEF_STR( Unused ) )
	PORT_DIPSETTING(    0x20, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )

INPUT_PORTS_END


GAME( 1980, quasar,        0, quasar,   quasar,   0,		ROT90, "Zelco / Zaccaria",                         "Quasar",             GAME_IMPERFECT_GRAPHICS | GAME_IMPERFECT_SOUND )
GAME( 1980, quasara,  quasar, quasar,   quasar,   0,		ROT90, "Zelco / Zaccaria",                         "Quasar (Alternate)", GAME_IMPERFECT_GRAPHICS | GAME_IMPERFECT_SOUND )

