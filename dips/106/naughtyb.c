# MAME 0.106 source snippet

}

INPUT_PORTS_START( naughtyb )
	PORT_START_TAG(	"IN0" )
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_START1 )
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_START2 )
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_BUTTON1 )
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_JOYSTICK_UP ) PORT_4WAY
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN ) PORT_4WAY
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT ) PORT_4WAY
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT ) PORT_4WAY

	PORT_START_TAG(	"IN0_COCKTAIL" )
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_UNKNOWN ) // IPT_START1
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_UNKNOWN ) // IPT_START2
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_COCKTAIL
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_JOYSTICK_UP ) PORT_4WAY PORT_COCKTAIL
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN ) PORT_4WAY PORT_COCKTAIL
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT ) PORT_4WAY PORT_COCKTAIL
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT ) PORT_4WAY PORT_COCKTAIL

	PORT_START_TAG( "DSW0" )
	PORT_DIPNAME( 0x03, 0x01, DEF_STR( Lives ) )
	PORT_DIPSETTING(	0x00, "2" )
	PORT_DIPSETTING(	0x01, "3" )
	PORT_DIPSETTING(	0x02, "4" )
	PORT_DIPSETTING(	0x03, "5" )
	PORT_DIPNAME( 0x0c, 0x04, DEF_STR( Bonus_Life ) )
	PORT_DIPSETTING(	0x00, "10000" )
	PORT_DIPSETTING(	0x04, "30000" )
	PORT_DIPSETTING(	0x08, "50000" )
	PORT_DIPSETTING(	0x0c, "70000" )
	PORT_DIPNAME( 0x30, 0x10, DEF_STR( Coinage ) )
	PORT_DIPSETTING(	0x00, DEF_STR( 2C_1C ) )
	PORT_DIPSETTING(	0x10, DEF_STR( 1C_1C ) )
	PORT_DIPSETTING(	0x20, DEF_STR( 1C_2C ) )
	PORT_DIPSETTING(	0x30, DEF_STR( 1C_3C ) )
	PORT_DIPNAME( 0x40, 0x00, DEF_STR( Difficulty ) )
	PORT_DIPSETTING(	0x00, DEF_STR( Easy ) )
	PORT_DIPSETTING(	0x40, DEF_STR( Hard ) )
	PORT_DIPNAME( 0x80, 0x00, DEF_STR( Cabinet ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Upright ) )
	PORT_DIPSETTING(    0x80, DEF_STR( Cocktail ) )

	PORT_START_TAG( "FAKE" )
	// The coin slots are not memory mapped.
	// This fake input port is used by the interrupt
	// handler to be notified of coin insertions. We use IMPULSE to
	// trigger exactly one interrupt, without having to check when the
	// user releases the key.
	PORT_BIT( 0x01, IP_ACTIVE_HIGH, IPT_COIN1 ) PORT_IMPULSE(1)
	// when reading DSW0, bit 7 doesn't read cabinet, but vblank
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_VBLANK )
INPUT_PORTS_END

INPUT_PORTS_START( trvmstr )
	PORT_START_TAG(	"IN0" )
	PORT_SERVICE(0x0f, IP_ACTIVE_LOW )
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_BUTTON4 )
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_BUTTON3 )
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_BUTTON2 )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_BUTTON1 )

	PORT_START_TAG(	"IN0_COCKTAIL" )
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_BUTTON4 ) PORT_COCKTAIL
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_BUTTON3 ) PORT_COCKTAIL
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_BUTTON2 ) PORT_COCKTAIL
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_COCKTAIL

	PORT_START_TAG( "DSW0" )
	PORT_DIPNAME( 0x03, 0x00, "Screen Orientation" )
	PORT_DIPSETTING(	0x00, "0'" )
	PORT_DIPSETTING(	0x02, "90'" )
	PORT_DIPSETTING(	0x01, "180'" )
	PORT_DIPSETTING(	0x03, "270'" )
	PORT_DIPNAME( 0x04, 0x04, DEF_STR( Unknown ) )
	PORT_DIPSETTING(	0x04, DEF_STR( Off ) )
	PORT_DIPSETTING(	0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x08, 0x00, "Show Correct Answer" )
	PORT_DIPSETTING(	0x08, DEF_STR( No ) )
	PORT_DIPSETTING(	0x00, DEF_STR( Yes ) )
	PORT_DIPNAME( 0x30, 0x00, DEF_STR( Coinage ) )
	PORT_DIPSETTING(	0x10, DEF_STR( 2C_1C ) )
	PORT_DIPSETTING(	0x00, DEF_STR( 1C_1C ) )
	PORT_DIPSETTING(	0x20, DEF_STR( 1C_2C ) )
	PORT_DIPSETTING(	0x30, DEF_STR( Free_Play ) )
	PORT_DIPNAME( 0x40, 0x40, "Number of Questions" )
	PORT_DIPSETTING(	0x00, "5" )
	PORT_DIPSETTING(	0x40, "7" )
	PORT_DIPNAME( 0x80, 0x00, DEF_STR( Cabinet ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Upright ) )
	PORT_DIPSETTING(    0x80, DEF_STR( Cocktail ) )

	PORT_START_TAG( "FAKE" )
	// The coin slots are not memory mapped.
	// This fake input port is used by the interrupt
	// handler to be notified of coin insertions. We use IMPULSE to
	// trigger exactly one interrupt, without having to check when the
	// user releases the key.
	PORT_BIT( 0x01, IP_ACTIVE_HIGH, IPT_COIN1 ) PORT_IMPULSE(1)
	// when reading DSW0, bit 7 doesn't read cabinet, but vblank
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_VBLANK )
INPUT_PORTS_END

GAME( 1982, naughtyb, 0,		naughtyb, naughtyb, 0,        ROT90, "Jaleco", "Naughty Boy", 0 )
GAME( 1982, naughtya, naughtyb, naughtyb, naughtyb, 0,        ROT90, "bootleg", "Naughty Boy (bootleg)", 0 )
GAME( 1982, naughtyc, naughtyb, naughtyb, naughtyb, 0,        ROT90, "Jaleco (Cinematronics license)", "Naughty Boy (Cinematronics)", 0 )
GAME( 1982, popflame, 0,		popflame, naughtyb, popflame, ROT90, "Jaleco", "Pop Flamer (protected)", 0 )
GAME( 1982, popflama, popflame, popflame, naughtyb, 0,        ROT90, "Jaleco", "Pop Flamer (not protected)", 0 )
GAME( 1982, popflamb, popflame, popflame, naughtyb, 0,        ROT90, "Jaleco", "Pop Flamer (hack?)", 0 )
GAME( 1985, trvmstr,  0,		naughtyb, trvmstr,  trvmstr,  ROT90, "Enerdyne Technologies Inc.", "Trivia Master (set 1)", 0 )
GAME( 1985, trvmstra, trvmstr,  naughtyb, trvmstr,  trvmstr,  ROT90, "Enerdyne Technologies Inc.", "Trivia Master (set 2)", 0 )
GAME( 198?, trvgns,   0,		naughtyb, trvmstr,  trvmstr,  ROT90, "Enerdyne Technologies Inc.", "Trivia Genius", GAME_WRONG_COLORS )
