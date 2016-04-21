# MAME 0.141 source snippet

static INPUT_PORTS_START( decocass )
	PORT_START("IN0")
	PORT_BIT( 0x01, IP_ACTIVE_HIGH,IPT_JOYSTICK_RIGHT )
	PORT_BIT( 0x02, IP_ACTIVE_HIGH,IPT_JOYSTICK_LEFT )
	PORT_BIT( 0x04, IP_ACTIVE_HIGH,IPT_JOYSTICK_UP )
	PORT_BIT( 0x08, IP_ACTIVE_HIGH,IPT_JOYSTICK_DOWN )
	PORT_BIT( 0x10, IP_ACTIVE_HIGH,IPT_BUTTON1 )
	PORT_BIT( 0x20, IP_ACTIVE_HIGH,IPT_BUTTON2 )
	PORT_BIT( 0x40, IP_ACTIVE_HIGH,IPT_UNUSED )
	PORT_BIT( 0x80, IP_ACTIVE_HIGH,IPT_UNUSED )

	PORT_START("IN1")
	PORT_BIT( 0x01, IP_ACTIVE_HIGH,IPT_JOYSTICK_RIGHT ) PORT_COCKTAIL
	PORT_BIT( 0x02, IP_ACTIVE_HIGH,IPT_JOYSTICK_LEFT ) PORT_COCKTAIL
	PORT_BIT( 0x04, IP_ACTIVE_HIGH,IPT_JOYSTICK_UP ) PORT_COCKTAIL
	PORT_BIT( 0x08, IP_ACTIVE_HIGH,IPT_JOYSTICK_DOWN ) PORT_COCKTAIL
	PORT_BIT( 0x10, IP_ACTIVE_HIGH,IPT_BUTTON1 ) PORT_COCKTAIL
	PORT_BIT( 0x20, IP_ACTIVE_HIGH,IPT_BUTTON2 ) PORT_COCKTAIL
	PORT_BIT( 0x40, IP_ACTIVE_HIGH,IPT_UNUSED )
	PORT_BIT( 0x80, IP_ACTIVE_HIGH,IPT_UNUSED )

	PORT_START("IN2")
	PORT_BIT( 0x01, IP_ACTIVE_HIGH,IPT_UNKNOWN )
	PORT_BIT( 0x02, IP_ACTIVE_HIGH,IPT_UNKNOWN )
	PORT_BIT( 0x04, IP_ACTIVE_HIGH,IPT_UNKNOWN )
	PORT_BIT( 0x08, IP_ACTIVE_HIGH,IPT_START1 ) PORT_IMPULSE(1)
	PORT_BIT( 0x10, IP_ACTIVE_HIGH,IPT_START2 ) PORT_IMPULSE(1)
	PORT_BIT( 0x20, IP_ACTIVE_HIGH,IPT_UNKNOWN )
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_COIN2 ) PORT_IMPULSE(1)
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_COIN1 ) PORT_IMPULSE(1)

	PORT_START("AN0")
	PORT_BIT( 0xff, 0x80, IPT_AD_STICK_X ) PORT_MINMAX(0x10,0xf0) PORT_SENSITIVITY(100) PORT_KEYDELTA(10) PORT_PLAYER(1)

	PORT_START("AN1")
	PORT_BIT( 0xff, 0x80, IPT_AD_STICK_Y ) PORT_MINMAX(0x10,0xf0) PORT_SENSITIVITY(100) PORT_KEYDELTA(10) PORT_PLAYER(1)

	PORT_START("AN2")
	PORT_BIT( 0xff, 0x80, IPT_AD_STICK_X ) PORT_MINMAX(0x10,0xf0) PORT_SENSITIVITY(100) PORT_KEYDELTA(10) PORT_PLAYER(2)

	PORT_START("AN3")
	PORT_BIT( 0xff, 0x80, IPT_AD_STICK_Y ) PORT_MINMAX(0x10,0xf0) PORT_SENSITIVITY(100) PORT_KEYDELTA(10) PORT_PLAYER(2)

	PORT_START("DSW1")
	PORT_DIPNAME( 0x03, 0x03, DEF_STR( Coin_A ) )		PORT_DIPLOCATION("SW1:1,2")
	PORT_DIPSETTING(    0x00, DEF_STR( 2C_1C ) )
	PORT_DIPSETTING(    0x03, DEF_STR( 1C_1C ) )
	PORT_DIPSETTING(    0x02, DEF_STR( 1C_2C ) )
	PORT_DIPSETTING(    0x01, DEF_STR( 1C_3C ) )
	PORT_DIPNAME( 0x0c, 0x0c, DEF_STR( Coin_B ) )		PORT_DIPLOCATION("SW1:3,4")
	PORT_DIPSETTING(    0x00, DEF_STR( 2C_1C ) )
	PORT_DIPSETTING(    0x0c, DEF_STR( 1C_1C ) )
	PORT_DIPSETTING(    0x08, DEF_STR( 1C_2C ) )
	PORT_DIPSETTING(    0x04, DEF_STR( 1C_3C ) )
	PORT_DIPNAME( 0x30, 0x30, "Type of Tape" )		PORT_DIPLOCATION("SW1:5,6")   /* Used by the "bios" */
	PORT_DIPSETTING(    0x00, "MT (Big)" )			/* Was listed as "Board Type" with this being "OLD" */
	PORT_DIPSETTING(    0x10, "invalid?" )
	PORT_DIPSETTING(    0x20, "invalid?" )
	PORT_DIPSETTING(    0x30, "MD (Small)" )		/* Was listed as "Board Type" with this being "NEW" */
	PORT_DIPNAME( 0x40, 0x00, DEF_STR( Cabinet ) )		PORT_DIPLOCATION("SW1:7")
	PORT_DIPSETTING(    0x00, DEF_STR( Upright ) )
	PORT_DIPSETTING(    0x40, DEF_STR( Cocktail ) )
	PORT_BIT( 0x80, IP_ACTIVE_HIGH, IPT_VBLANK)

	PORT_START("DSW2") /* Start with all Unknown as each can change per game, except for Country Code */
	PORT_DIPUNKNOWN_DIPLOC( 0x01, 0x01, "SW2:1")		/* Most Dipswitch Settings sheets show this as "Number of Players" (Lives) */
	PORT_DIPUNKNOWN_DIPLOC( 0x02, 0x02, "SW2:2")		/* Most Dipswitch Settings sheets show 2 & 3 as "Bonus Players" */
	PORT_DIPUNKNOWN_DIPLOC( 0x04, 0x04, "SW2:3")
	PORT_DIPUNKNOWN_DIPLOC( 0x08, 0x08, "SW2:4")		/* Most Dipswitch Settings sheets show 4 (with/without 5) as some form of Diffculty */
	PORT_DIPUNKNOWN_DIPLOC( 0x10, 0x10, "SW2:5")
	PORT_DIPNAME( 0xe0, 0xe0, "Country Code" )		PORT_DIPLOCATION("SW2:6,7,8") /* Always Listed as "DON'T CHANGE" */
	PORT_DIPSETTING(    0xe0, "A" )
	PORT_DIPSETTING(    0xc0, "B" )
	PORT_DIPSETTING(    0xa0, "C" )
	PORT_DIPSETTING(    0x80, "D" )
	PORT_DIPSETTING(    0x60, "E" )
	PORT_DIPSETTING(    0x40, "F" )
INPUT_PORTS_END

static INPUT_PORTS_START( cbtime )
	PORT_INCLUDE( decocass )

	PORT_MODIFY("DSW2")
	PORT_DIPNAME( 0x01, 0x01, DEF_STR( Lives ) )		PORT_DIPLOCATION("SW2:1")
	PORT_DIPSETTING(    0x01, "3" )
	PORT_DIPSETTING(    0x00, "5" )
	PORT_DIPNAME( 0x06, 0x06, DEF_STR( Bonus_Life ) )	PORT_DIPLOCATION("SW2:2,3")
	PORT_DIPSETTING(    0x06, "20000" )
	PORT_DIPSETTING(    0x04, "30000" )
	PORT_DIPSETTING(    0x02, "40000" )
	PORT_DIPSETTING(    0x00, "50000" )
	PORT_DIPNAME( 0x08, 0x08, "Enemies" )			PORT_DIPLOCATION("SW2:4")
	PORT_DIPSETTING(    0x08, "4" )
	PORT_DIPSETTING(    0x00, "6" )
	PORT_DIPNAME( 0x10, 0x10, "End of Level Pepper" )	PORT_DIPLOCATION("SW2:5")
	PORT_DIPSETTING(    0x10, DEF_STR( No ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Yes ) )
INPUT_PORTS_END

static INPUT_PORTS_START( cnightst )
	PORT_INCLUDE( decocass )

	PORT_MODIFY("DSW2")
	PORT_DIPNAME( 0x01, 0x01, DEF_STR( Lives ) )		PORT_DIPLOCATION("SW2:1")
	PORT_DIPSETTING(    0x01, "3" )
	PORT_DIPSETTING(    0x00, "5" )
	PORT_DIPNAME( 0x06, 0x06, DEF_STR( Bonus_Life ) )	PORT_DIPLOCATION("SW2:2,3")
	PORT_DIPSETTING(    0x06, "When Night Star Completed (First 2 Times)" )
	PORT_DIPSETTING(    0x04, "When Night Star Completed (First Time Only)" )
	PORT_DIPSETTING(    0x02, "Every 70000"  )
	PORT_DIPSETTING(    0x00, "30000 Only"  )
	PORT_DIPNAME( 0x08, 0x08, "Number of Missles" )		PORT_DIPLOCATION("SW2:4")
	PORT_DIPSETTING(    0x08, "Few" )
	PORT_DIPSETTING(    0x00, "Many" )
	PORT_DIPNAME( 0x10, 0x10, "Enemy's Speed" )		PORT_DIPLOCATION("SW2:5")
	PORT_DIPSETTING(    0x10, "Slow" )
	PORT_DIPSETTING(    0x00, "Fast" )
	/* Switches 6, 7 & 8 are listed as "Country Code" A through F and "Don't Change" */
INPUT_PORTS_END

static INPUT_PORTS_START( ctornado )
	PORT_INCLUDE( decocass )

	PORT_MODIFY("DSW2")
	PORT_DIPNAME( 0x01, 0x01, DEF_STR( Lives ) )		PORT_DIPLOCATION("SW2:1")
	PORT_DIPSETTING(    0x01, "3" )
	PORT_DIPSETTING(    0x00, "5" )
	PORT_DIPNAME( 0x06, 0x06, DEF_STR( Bonus_Life ) )	PORT_DIPLOCATION("SW2:2,3")
	PORT_DIPSETTING(    0x00, DEF_STR( None )  )
	PORT_DIPSETTING(    0x06, "10000" )
	PORT_DIPSETTING(    0x04, "20000" )
	PORT_DIPSETTING(    0x02, "30000" )
	PORT_DIPNAME( 0x08, 0x08, "Crash Bombs" )		PORT_DIPLOCATION("SW2:4") /* Printed English translation "Hero Destructor" */
	PORT_DIPSETTING(    0x08, "3" )
	PORT_DIPSETTING(    0x00, "5" )
	PORT_DIPNAME( 0x10, 0x10, "Alens' Speed" )		PORT_DIPLOCATION("SW2:5")
	PORT_DIPSETTING(    0x10, "Slow" )
	PORT_DIPSETTING(    0x00, "Fast" )
	/* Switches 6, 7 & 8 are listed as "Country Code" A through F and "Don't Change" */
INPUT_PORTS_END

static INPUT_PORTS_START( cbdash )
	PORT_INCLUDE( decocass )

	PORT_MODIFY("DSW2")
	PORT_DIPNAME( 0x01, 0x01, DEF_STR( Lives ) )		PORT_DIPLOCATION("SW2:1")
	PORT_DIPSETTING(    0x01, "3" )
	PORT_DIPSETTING(    0x00, "5" )
	PORT_DIPNAME( 0x06, 0x06, DEF_STR( Bonus_Life ) )	PORT_DIPLOCATION("SW2:2,3")
	PORT_DIPSETTING(    0x00, DEF_STR( None )  )
	PORT_DIPSETTING(    0x06, "20000" )
	PORT_DIPSETTING(    0x04, "30000" )
	PORT_DIPSETTING(    0x02, "40000" )
	PORT_DIPNAME( 0x18, 0x18, DEF_STR( Difficulty ) )	PORT_DIPLOCATION("SW2:4,5")
	PORT_DIPSETTING(    0x18, DEF_STR( Normal ) )		/* Number of Diamonds Little, Timer: Long */
	PORT_DIPSETTING(    0x10, DEF_STR( Hard ) )		/* Number of Diamonds Little, Timer: Long */
	PORT_DIPSETTING(    0x08, DEF_STR( Harder ) )		/* Number of Diamonds Many, Timer: Short */
	PORT_DIPSETTING(    0x00, DEF_STR( Hardest ) )		/* Number of Diamonds Many, Timer: Short */
	/* Switches 6, 7 & 8 are listed as "Country Code" A through F and "Don't Change" */
INPUT_PORTS_END

static INPUT_PORTS_START( cprogolf )
	PORT_INCLUDE( decocass )

	PORT_MODIFY("DSW2")
	PORT_DIPNAME( 0x01, 0x01, DEF_STR( Lives ) )		PORT_DIPLOCATION("SW2:1")
	PORT_DIPSETTING(    0x01, "2" )
	PORT_DIPSETTING(    0x00, "3" )
	PORT_DIPNAME( 0x06, 0x06, DEF_STR( Bonus_Life ) )	PORT_DIPLOCATION("SW2:2,3") /* You must shoot equal to or under the listed value for a bonus */
	PORT_DIPSETTING(    0x00, DEF_STR( None )  )
	PORT_DIPSETTING(    0x02, "6 Under" )
	PORT_DIPSETTING(    0x04, "3 Under" )
	PORT_DIPSETTING(    0x06, "1 Under" )
	PORT_DIPNAME( 0x08, 0x08, "Number of Strokes" )		PORT_DIPLOCATION("SW2:4") /* You must shoot equal to or under to continue, else you loose a life */
	PORT_DIPSETTING(    0x00, "Par +2" )
	PORT_DIPSETTING(    0x08, "Par +3" )
	PORT_DIPNAME( 0x10, 0x10, "Show Stroke Power/Ball Direction" )		PORT_DIPLOCATION("SW2:5")
	PORT_DIPSETTING(    0x10, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	/* Switches 6, 7 & 8 are listed as "Country Code" A through F and "Don't Change" */
INPUT_PORTS_END

static INPUT_PORTS_START( csuperas )
	PORT_INCLUDE( decocass )

	PORT_MODIFY("DSW2")
	PORT_DIPNAME( 0x01, 0x01, DEF_STR( Lives ) )		PORT_DIPLOCATION("SW2:1")
	PORT_DIPSETTING(    0x01, "3" )
	PORT_DIPSETTING(    0x00, "5" )
	PORT_DIPNAME( 0x06, 0x06, DEF_STR( Bonus_Life ) )	PORT_DIPLOCATION("SW2:2,3")
	PORT_DIPSETTING(    0x00, DEF_STR( None )  )
	PORT_DIPSETTING(    0x06, "20000" )
	PORT_DIPSETTING(    0x04, "30000" )
	PORT_DIPSETTING(    0x02, "40000" )
	PORT_DIPNAME( 0x08, 0x08, "Alien Craft Movement" )	PORT_DIPLOCATION("SW2:4")
	PORT_DIPSETTING(    0x08, DEF_STR( Easy ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Difficult ) )
	/* Switches 6, 7 & 8 are listed as "Country Code" A through F and "Don't Change" */
INPUT_PORTS_END

static INPUT_PORTS_START( cscrtry )
	PORT_INCLUDE( decocass )

	PORT_MODIFY("DSW2")
	PORT_DIPNAME( 0x01, 0x01, DEF_STR( Lives ) )		PORT_DIPLOCATION("SW2:1")
	PORT_DIPSETTING(    0x01, "2" )
	PORT_DIPSETTING(    0x00, "4" )
	PORT_DIPNAME( 0x06, 0x06, DEF_STR( Bonus_Life ) )	PORT_DIPLOCATION("SW2:2,3")
	PORT_DIPSETTING(    0x00, DEF_STR( None )  )
	PORT_DIPSETTING(    0x06, "30000" )
	PORT_DIPSETTING(    0x04, "50000" )
	PORT_DIPSETTING(    0x02, "70000" )
	PORT_DIPNAME( 0x08, 0x08, DEF_STR( Difficulty ) )	PORT_DIPLOCATION("SW2:4")
	PORT_DIPSETTING(    0x08, DEF_STR( Easy ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Difficult ) )
	/* Switches 5, 6, 7 & 8 are listed as "Special Purpose" and "Don't Change" */
INPUT_PORTS_END

static INPUT_PORTS_START( cprosocc )
	PORT_INCLUDE( decocass )

	PORT_MODIFY("DSW2")
	PORT_DIPNAME( 0x01, 0x01, DEF_STR( Lives ) )		PORT_DIPLOCATION("SW2:1") /* Listed as "Number of Balls" */
	PORT_DIPSETTING(    0x01, "3" )
	PORT_DIPSETTING(    0x00, "5" )
	PORT_DIPNAME( 0x06, 0x06, "Number of Nice Goal" )	PORT_DIPLOCATION("SW2:2,3")
	PORT_DIPSETTING(    0x00, DEF_STR( None )  )
	PORT_DIPSETTING(    0x06, "5" )
	PORT_DIPSETTING(    0x04, "10" )
	PORT_DIPSETTING(    0x02, "20" )
	PORT_DIPNAME( 0x08, 0x08, DEF_STR( Demo_Sounds ) )	PORT_DIPLOCATION("SW2:4")
	PORT_DIPSETTING(    0x00, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x08, DEF_STR( On ) )
	PORT_DIPNAME( 0x10, 0x10, DEF_STR( Difficulty ) )	PORT_DIPLOCATION("SW2:4") /* Listed as "Class" */
	PORT_DIPSETTING(    0x10, DEF_STR( Easy ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Difficult ) )
	/* Switches 6, 7 & 8 are listed as "Country Code" A through F and "Don't Change" */
INPUT_PORTS_END

static INPUT_PORTS_START( cterrani )
	PORT_INCLUDE( decocass )

	PORT_MODIFY("DSW2")
	PORT_DIPNAME( 0x01, 0x01, DEF_STR( Lives ) )		PORT_DIPLOCATION("SW2:1")
	PORT_DIPSETTING(    0x01, "3" )
	PORT_DIPSETTING(    0x00, "5" )
	PORT_DIPNAME( 0x06, 0x06, DEF_STR( Bonus_Life ) )	PORT_DIPLOCATION("SW2:2,3")
	PORT_DIPSETTING(    0x00, DEF_STR( None )  )
	PORT_DIPSETTING(    0x06, "3000" )
	PORT_DIPSETTING(    0x04, "5000" )
	PORT_DIPSETTING(    0x02, "7000" )
	PORT_DIPNAME( 0x08, 0x08, "Player's Rocket Movement" )	PORT_DIPLOCATION("SW2:4")
	PORT_DIPSETTING(    0x08, DEF_STR( Easy ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Difficult ) )
	PORT_DIPNAME( 0x10, 0x10, "Alien Craft Movement" )	PORT_DIPLOCATION("SW2:5")
	PORT_DIPSETTING(    0x10, DEF_STR( Easy ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Difficult ) )
	/* Switches 6, 7 & 8 are shown as completly blank */
INPUT_PORTS_END

static INPUT_PORTS_START( cmissnx )
	PORT_INCLUDE( decocass )

	PORT_MODIFY("DSW2")
	PORT_DIPNAME( 0x01, 0x01, DEF_STR( Lives ) )		PORT_DIPLOCATION("SW2:1")
	PORT_DIPSETTING(    0x01, "3" )
	PORT_DIPSETTING(    0x00, "5" )
	PORT_DIPNAME( 0x06, 0x06, DEF_STR( Bonus_Life ) )	PORT_DIPLOCATION("SW2:2,3")
	PORT_DIPSETTING(    0x00, DEF_STR( None )  )
	PORT_DIPSETTING(    0x06, "5000" )
	PORT_DIPSETTING(    0x04, "10000" )
	PORT_DIPSETTING(    0x02, "15000" )
	PORT_DIPNAME( 0x18, 0x18, DEF_STR( Difficulty ) )	PORT_DIPLOCATION("SW2:4,5") /* Listed as "Game Level" */
	PORT_DIPSETTING(    0x18, DEF_STR( Easy ) )
	PORT_DIPSETTING(    0x10, DEF_STR( Normal ) )
	PORT_DIPSETTING(    0x08, DEF_STR( Hard ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Hardest ) )
	/* Switches 6, 7 & 8 are listed as "Country Code" A through F and "Don't Change" */
INPUT_PORTS_END

static INPUT_PORTS_START( cfghtice )
	PORT_INCLUDE( decocass )

	PORT_MODIFY("DSW2")
	PORT_DIPNAME( 0x01, 0x01, DEF_STR( Lives ) )		PORT_DIPLOCATION("SW2:1")
	PORT_DIPSETTING(    0x01, "3" )
	PORT_DIPSETTING(    0x00, "5" )
	PORT_DIPNAME( 0x06, 0x06, DEF_STR( Very_Difficult ) )	PORT_DIPLOCATION("SW2:2,3")
	PORT_DIPSETTING(    0x04, DEF_STR( Very_Easy )  )
	PORT_DIPSETTING(    0x06, DEF_STR( Easy ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Difficult ) )
	PORT_DIPSETTING(    0x02, DEF_STR( Very_Difficult ) )
	PORT_DIPNAME( 0x08, 0x08, "Enemy's Speed" )		PORT_DIPLOCATION("SW2:4")
	PORT_DIPSETTING(    0x08, DEF_STR( Normal ) )
	PORT_DIPSETTING(    0x00, "Fast" )
	PORT_SERVICE_DIPLOC(  0x10, IP_ACTIVE_LOW, "SW2:5" )	/* Listed as Test Mode, but doesn't seem to work??? */
	/* Switches 6, 7 & 8 are listed as "Country Code" A through F and "Don't Change" */
INPUT_PORTS_END

static INPUT_PORTS_START( clocknch )
	PORT_INCLUDE( decocass )

	PORT_MODIFY("DSW2")
	PORT_DIPNAME( 0x01, 0x01, DEF_STR( Lives ) )		PORT_DIPLOCATION("SW2:1")
	PORT_DIPSETTING(    0x01, "3" )
	PORT_DIPSETTING(    0x00, "5" )
	PORT_DIPNAME( 0x06, 0x06, DEF_STR( Bonus_Life ) )	PORT_DIPLOCATION("SW2:2,3")
	PORT_DIPSETTING(    0x00, DEF_STR( None )  )
	PORT_DIPSETTING(    0x06, "15000" )
	PORT_DIPSETTING(    0x04, "20000" )
	PORT_DIPSETTING(    0x02, "30000" )
	/* Switches 4, 5, 6, 7 & 8 are listed as "Not Used" and "Don't Change" */
INPUT_PORTS_END

static INPUT_PORTS_START( cgraplop )
	PORT_INCLUDE( decocass )

	PORT_MODIFY("DSW2")
	PORT_DIPNAME( 0x01, 0x01, DEF_STR( Lives ) )		PORT_DIPLOCATION("SW2:1")
	PORT_DIPSETTING(    0x01, "3" )
	PORT_DIPSETTING(    0x00, "5" )
	PORT_DIPNAME( 0x06, 0x06, DEF_STR( Bonus_Life ) )	PORT_DIPLOCATION("SW2:2,3")
	PORT_DIPSETTING(    0x00, DEF_STR( None )  )
	PORT_DIPSETTING(    0x06, "20000" )
	PORT_DIPSETTING(    0x04, "50000" )
	PORT_DIPSETTING(    0x02, "70000" )
	PORT_DIPNAME( 0x08, 0x08, "Number of UPs" )		PORT_DIPLOCATION("SW2:4")
	PORT_DIPSETTING(    0x08, "Few" )
	PORT_DIPSETTING(    0x00, "Many" )
	PORT_DIPNAME( 0x10, 0x10, DEF_STR( Difficulty ) )	PORT_DIPLOCATION("SW2:5") /* Listed as "Falling Speed" */
	PORT_DIPSETTING(    0x10, DEF_STR( Easy ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Difficult ) )
	/* Switches 6, 7 & 8 are listed as "Not Used" and "Don't Change" */
INPUT_PORTS_END

static INPUT_PORTS_START( cexplore )
	PORT_INCLUDE( decocass )

	PORT_MODIFY("DSW2")
	PORT_DIPNAME( 0x01, 0x01, DEF_STR( Lives ) )		PORT_DIPLOCATION("SW2:1")
	PORT_DIPSETTING(    0x01, "3" )
	PORT_DIPSETTING(    0x00, "5" )
	PORT_DIPNAME( 0x06, 0x06, DEF_STR( Bonus_Life ) )	PORT_DIPLOCATION("SW2:2,3")
	PORT_DIPSETTING(    0x00, DEF_STR( None )  )
	PORT_DIPSETTING(    0x06, "10000" )
	PORT_DIPSETTING(    0x04, "1500000" )
	PORT_DIPSETTING(    0x02, "30000" )
	PORT_DIPNAME( 0x08, 0x08, DEF_STR( Difficulty ) )	PORT_DIPLOCATION("SW2:4") /* Listed as "Missle" */
	PORT_DIPSETTING(    0x08, DEF_STR( Easy ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Difficult ) )
	PORT_DIPNAME( 0x10, 0x10, "Number of UFOs" )		PORT_DIPLOCATION("SW2:5")
	PORT_DIPSETTING(    0x10, "Few" )
	PORT_DIPSETTING(    0x00, "Many" )
	/* Switches 6, 7 & 8 are listed as "Country Code" A through F and "Don't Change" */
INPUT_PORTS_END


         GAME( 1981, decocass, 0, decocass, decocass, decocass, ROT270, "Data East Corporation", "DECO Cassette System", GAME_IS_BIOS_ROOT )
         GAME( 1981, ctsttape, decocass, ctsttape, decocass, decocass, ROT270, "Data East Corporation", "Test Tape (Cassette)", 0 )
/* 01 */ GAME( 1980, chwy,     decocass, chwy,     decocass, decocass, ROT270, "Data East Corporation", "Highway Chase (Cassette)", 0 )
/* 04 */ GAME( 1981, cterrani, decocass, cterrani, cterrani, decocass, ROT270, "Data East Corporation", "Terranean (Cassette)", 0 )
/* 07 */ GAME( 1981, castfant, decocass, castfant, decocass, decocass, ROT270, "Data East Corporation", "Astro Fantasia (Cassette)", 0 )
/* 09 */ GAME( 1981, csuperas, decocass, csuperas, csuperas, decocass, ROT270, "Data East Corporation", "Super Astro Fighter (Cassette)", 0 )
/* 11 */ GAME( 1981, clocknch, decocass, clocknch, clocknch, decocass, ROT270, "Data East Corporation", "Lock'n'Chase (Cassette)", 0 )
/* 13 */ GAME( 1981, cprogolf, decocass, cprogolf, cprogolf, decocass, ROT270, "Data East Corporation", "Tournament Pro Golf (Cassette)", 0 )
/* 15 */ GAME( 1981, cluckypo, decocass, cluckypo, decocass, decocass, ROT270, "Data East Corporation", "Lucky Poker (Cassette)", 0 )
/* 16 */ GAME( 1981, ctisland, decocass, ctisland, decocass, decocrom, ROT270, "Data East Corporation", "Treasure Island (Cassette, set 1)", 0 )
/* 16 */ GAME( 1981, ctisland2,ctisland, ctisland, decocass, decocrom, ROT270, "Data East Corporation", "Treasure Island (Cassette, set 2)", 0 )
/* 16 */ GAME( 1981, ctisland3,ctisland, ctisland, decocass, decocrom, ROT270, "Data East Corporation", "Treasure Island (Cassette, set 3)", GAME_NOT_WORKING ) /* Different Bitswap? */
/* 18 */ GAME( 1982, cexplore, decocass, cexplore, cexplore, decocass, ROT270, "Data East Corporation", "Explorer (Cassette)", GAME_NOT_WORKING )
/* 19 */ GAME( 1982, cdiscon1, decocass, cdiscon1, decocass, decocass, ROT270, "Data East Corporation", "Disco No.1 (Cassette)", 0 )
/* 19 */ GAME( 1982, csweetht, cdiscon1, cdiscon1, decocass, decocass, ROT270, "Data East Corporation", "Sweet Heart (Cassette)", 0 )
/* 20 */ GAME( 1982, ctornado, decocass, ctornado, ctornado, decocass, ROT270, "Data East Corporation", "Tornado (Cassette)", 0 )
/* 21 */ GAME( 1982, cmissnx,  decocass, cmissnx,  cmissnx,  decocass, ROT270, "Data East Corporation", "Mission-X (Cassette)", 0 )
/* 22 */ GAME( 1982, cptennis, decocass, cptennis, decocass, decocass, ROT270, "Data East Corporation", "Pro Tennis (Cassette)", 0 )
/* 26 */ GAME( 1983, cbtime,   decocass, cbtime,   cbtime,   decocass, ROT270, "Data East Corporation", "Burger Time (Cassette)", 0 )
/* 27 */ GAME( 1982, cburnrub, decocass, cburnrub, decocass, decocass, ROT270, "Data East Corporation", "Burnin' Rubber (Cassette, set 1)", 0 )
/* 27 */ GAME( 1982, cburnrub2,cburnrub, cburnrub, decocass, decocass, ROT270, "Data East Corporation", "Burnin' Rubber (Cassette, set 2)", 0 )
/* 27 */ GAME( 1982, cbnj,     cburnrub, cbnj,     decocass, decocass, ROT270, "Data East Corporation", "Bump 'n' Jump (Cassette)", 0 )
/* 28 */ GAME( 1983, cgraplop, decocass, cgraplop, cgraplop, decocass, ROT270, "Data East Corporation", "Cluster Buster / Graplop (Cassette, set 1)", 0 )
/* 28 */ GAME( 1983, cgraplop2,cgraplop, cgraplop2,cgraplop, decocass, ROT270, "Data East Corporation", "Cluster Buster / Graplop (Cassette, set 2)", GAME_NOT_WORKING )
/* 29 */ GAME( 1983, clapapa,  decocass, clapapa,  decocass, decocass, ROT270, "Data East Corporation", "Rootin' Tootin' / La-Pa-Pa (Cassette)" , 0) /* Displays 'La-Pa-Pa during attract */
/* 29 */ GAME( 1983, clapapa2, clapapa,  clapapa,  decocass, decocass, ROT270, "Data East Corporation", "Rootin' Tootin' (Cassette)" , 0) /* Displays 'Rootin' Tootin' during attract */
/* 31 */ GAME( 1983, cprobowl, decocass, cprobowl, decocass, decocass, ROT270, "Data East Corporation", "Pro Bowling (Cassette)", 0 )
/* 32 */ GAME( 1983, cnightst, decocass, cnightst, cnightst, decocass, ROT270, "Data East Corporation", "Night Star (Cassette, set 1)", 0 )
/* 32 */ GAME( 1983, cnightst2,cnightst, cnightst, cnightst, decocass, ROT270, "Data East Corporation", "Night Star (Cassette, set 2)", 0 )
/* 33 */ GAME( 1983, cprosocc, decocass, cprosocc, cprosocc, decocass, ROT270, "Data East Corporation", "Pro Soccer (Cassette)", 0 )
/* 37 */ GAME( 1983, czeroize, decocass, czeroize, decocass, decocass, ROT270, "Data East Corporation", "Zeroize (Cassette)", 0 )
/* 38 */ GAME( 1984, cscrtry,  decocass, cscrtry,  cscrtry,  decocass, ROT270, "Data East Corporation", "Scrum Try (Cassette, set 1)", 0 )
/* 38 */ GAME( 1984, cscrtry2, cscrtry,  cscrtry,  cscrtry,  decocass, ROT270, "Data East Corporation", "Scrum Try (Cassette, set 2)", 0 )
/* 39 */ GAME( 1984, cppicf,   decocass, cppicf,   decocass, decocass, ROT270, "Data East Corporation", "Peter Pepper's Ice Cream Factory (Cassette, set 1)", 0 )
/* 39 */ GAME( 1984, cppicf2,  cppicf,   cppicf,   decocass, decocass, ROT270, "Data East Corporation", "Peter Pepper's Ice Cream Factory (Cassette, set 2)", 0 )
/* 40 */ GAME( 1984, cfghtice, decocass, cfghtice, cfghtice, decocass, ROT270, "Data East Corporation", "Fighting Ice Hockey (Cassette)", 0 )
/* 44 */ GAME( 1985, cbdash,   decocass, cbdash,   cbdash,   decocass, ROT270, "Data East Corporation", "Boulder Dash (Cassette)", 0 )
         GAME( 1985, cflyball, decocass, cflyball, decocass, decocass, ROT270, "Data East Corporation", "Flying Ball (Cassette)", 0 )
