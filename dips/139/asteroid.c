/*************************************
 *
 *  Port definitions
 *
 *************************************/

static CUSTOM_INPUT( clock_r )
{
	return (field->port->machine->device<cpu_device>("maincpu")->total_cycles() & 0x100) ? 1 : 0;
}

static INPUT_PORTS_START( asteroid )
	PORT_START("IN0")
	PORT_BIT( 0x01, IP_ACTIVE_HIGH, IPT_UNKNOWN )
	/* Bit 2 is the 3 KHz source and Bit 3 the VG_HALT bit    */
	PORT_BIT( 0x02, IP_ACTIVE_HIGH, IPT_SPECIAL ) PORT_CUSTOM(clock_r, NULL)
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_SPECIAL ) PORT_CUSTOM(avgdvg_done_r, NULL)
	PORT_BIT( 0x08, IP_ACTIVE_HIGH, IPT_BUTTON5 ) PORT_CODE(KEYCODE_SPACE) PORT_CODE(JOYCODE_BUTTON3)		/* hyperspace */
	PORT_BIT( 0x10, IP_ACTIVE_HIGH, IPT_BUTTON3 ) PORT_CODE(KEYCODE_LCONTROL) PORT_CODE(JOYCODE_BUTTON1)	/* fire */
	PORT_BIT( 0x20, IP_ACTIVE_HIGH, IPT_SERVICE ) PORT_NAME("Diagnostic Step") PORT_CODE(KEYCODE_F1)
	PORT_BIT( 0x40, IP_ACTIVE_HIGH, IPT_TILT )
	PORT_SERVICE( 0x80, IP_ACTIVE_HIGH )

	PORT_START("IN1")
	PORT_BIT( 0x01, IP_ACTIVE_HIGH, IPT_COIN1 )
	PORT_BIT( 0x02, IP_ACTIVE_HIGH, IPT_COIN2 )
	PORT_BIT( 0x04, IP_ACTIVE_HIGH, IPT_COIN3 )
	PORT_BIT( 0x08, IP_ACTIVE_HIGH, IPT_START1 )
	PORT_BIT( 0x10, IP_ACTIVE_HIGH, IPT_START2 )
	PORT_BIT( 0x20, IP_ACTIVE_HIGH, IPT_BUTTON4 ) PORT_CODE(KEYCODE_LALT) PORT_CODE(JOYCODE_BUTTON2)		/* thrust */
	PORT_BIT( 0x40, IP_ACTIVE_HIGH, IPT_BUTTON2 ) PORT_CODE(KEYCODE_RIGHT) PORT_CODE(JOYCODE_X_RIGHT_SWITCH)/* right */
	PORT_BIT( 0x80, IP_ACTIVE_HIGH, IPT_BUTTON1 ) PORT_CODE(KEYCODE_LEFT) PORT_CODE(JOYCODE_X_LEFT_SWITCH)	/* left */

	PORT_START("DSW1")
	PORT_DIPNAME( 0x03, 0x00, DEF_STR( Language ) )	PORT_DIPLOCATION("SW:1,2")
	PORT_DIPSETTING (	0x00, DEF_STR( English ) )
	PORT_DIPSETTING (	0x01, DEF_STR( German ) )
	PORT_DIPSETTING (	0x02, DEF_STR( French ) )
	PORT_DIPSETTING (	0x03, DEF_STR( Spanish ) )
	PORT_DIPNAME( 0x04, 0x04, DEF_STR( Lives ) )	PORT_DIPLOCATION("SW:3")
	PORT_DIPSETTING (	0x04, "3" )
	PORT_DIPSETTING (	0x00, "4" )
	PORT_DIPNAME( 0x08, 0x00, "Center Mech" )		PORT_DIPLOCATION("SW:4") /* Left/Center for 3-door mech */
	PORT_DIPSETTING (	0x00, "X 1" )
	PORT_DIPSETTING (	0x08, "X 2" )
	PORT_DIPNAME( 0x30, 0x00, "Right Mech" )		PORT_DIPLOCATION("SW:5,6")
	PORT_DIPSETTING (	0x00, "X 1" )
	PORT_DIPSETTING (	0x10, "X 4" )
	PORT_DIPSETTING (	0x20, "X 5" )
	PORT_DIPSETTING (	0x30, "X 6" )
	PORT_DIPNAME( 0xc0, 0x80, DEF_STR( Coinage ) )	PORT_DIPLOCATION("SW:7,8")
	PORT_DIPSETTING (	0xc0, DEF_STR( 2C_1C ) )
	PORT_DIPSETTING (	0x80, DEF_STR( 1C_1C ) )
	PORT_DIPSETTING (	0x40, DEF_STR( 1C_2C ) )
	PORT_DIPSETTING (	0x00, DEF_STR( Free_Play ) )
INPUT_PORTS_END


static INPUT_PORTS_START( asteroidb )
	PORT_INCLUDE( asteroid )

	PORT_MODIFY("IN0")
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_UNKNOWN )	/* resets */
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_UNKNOWN )	/* resets */
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_TILT )
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_UNKNOWN )
	/* Bit 7 is VG_HALT */
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_SPECIAL ) PORT_CUSTOM(avgdvg_done_r, NULL)

	PORT_MODIFY("IN1")
	PORT_BIT( 0x01, IP_ACTIVE_HIGH, IPT_START1 )
	PORT_BIT( 0x02, IP_ACTIVE_LOW,  IPT_COIN1 )
	PORT_BIT( 0x04, IP_ACTIVE_HIGH, IPT_BUTTON4 ) PORT_CODE(KEYCODE_LALT) PORT_CODE(JOYCODE_BUTTON2)			/* thrust */
	PORT_BIT( 0x08, IP_ACTIVE_LOW,  IPT_COIN2 )
	PORT_BIT( 0x20, IP_ACTIVE_HIGH, IPT_BUTTON3 ) PORT_CODE(KEYCODE_LCONTROL) PORT_CODE(JOYCODE_BUTTON1)		/* fire */

	PORT_MODIFY("DSW1")
	PORT_DIPUNKNOWN_DIPLOC( 0x08, 0x08, "SW:4" )
	PORT_DIPUNKNOWN_DIPLOC( 0x10, 0x10, "SW:5" )
	PORT_DIPUNKNOWN_DIPLOC( 0x20, 0x20, "SW:6" )

	PORT_START("HS") /* hyperspace */
	PORT_BIT( 0x7f, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_BUTTON5 ) PORT_CODE(KEYCODE_SPACE) PORT_CODE(JOYCODE_BUTTON3)			/* hyperspace */
INPUT_PORTS_END


static INPUT_PORTS_START( asterock )
	PORT_INCLUDE( asteroid )

	PORT_MODIFY("IN0")
	/* Bit 0 is VG_HALT and Bit 2 is the 3 KHz source */
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_SPECIAL ) PORT_CUSTOM(avgdvg_done_r, NULL)
	PORT_BIT( 0x02, IP_ACTIVE_HIGH, IPT_UNKNOWN )
	PORT_BIT( 0x04, IP_ACTIVE_HIGH, IPT_SPECIAL ) PORT_CUSTOM(clock_r, NULL)
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_BUTTON5 ) PORT_CODE(KEYCODE_SPACE) PORT_CODE(JOYCODE_BUTTON3)		/* hyperspace */
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_BUTTON3 ) PORT_CODE(KEYCODE_LCONTROL) PORT_CODE(JOYCODE_BUTTON1)		/* fire */
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_SERVICE ) PORT_NAME("Diagnostic Step") PORT_CODE(KEYCODE_F1)
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_TILT )
	PORT_SERVICE( 0x80, IP_ACTIVE_LOW )

	PORT_MODIFY("DSW1")
	PORT_DIPNAME( 0x03, 0x03, DEF_STR( Language ) )					PORT_DIPLOCATION("SW:1,2")
	PORT_DIPSETTING(    0x00, DEF_STR( English ) )
	PORT_DIPSETTING(    0x01, DEF_STR( French ) )
	PORT_DIPSETTING(    0x02, DEF_STR( German ) )
	PORT_DIPSETTING(    0x03, DEF_STR( Italian ) )
	PORT_DIPNAME( 0x0c, 0x04, DEF_STR( Lives ) )					PORT_DIPLOCATION("SW:3,4")
	PORT_DIPSETTING(    0x00, "2" )
	PORT_DIPSETTING(    0x04, "3" )
	PORT_DIPSETTING(    0x08, "4" )
	PORT_DIPSETTING(    0x0c, "5" )
	PORT_DIPNAME( 0x10, 0x00, "Records Table" )						PORT_DIPLOCATION("SW:5")
	PORT_DIPSETTING(    0x00, DEF_STR( Normal ) )
	PORT_DIPSETTING(    0x10, "Special" )
	PORT_DIPNAME( 0x20, 0x00, "Coin Mode" )							PORT_DIPLOCATION("SW:6")
	PORT_DIPSETTING (	0x00, DEF_STR( Normal ) )
	PORT_DIPSETTING (	0x20, "Special" )
	PORT_DIPNAME( 0xc0, 0x80, DEF_STR( Coinage ) )					PORT_DIPLOCATION("SW:7,8")
	PORT_DIPSETTING (	0xc0, DEF_STR( 2C_1C ) )					PORT_CONDITION("DSW1",0x20,PORTCOND_EQUALS,0x00)
	PORT_DIPSETTING (	0x80, DEF_STR( 1C_1C ) )					PORT_CONDITION("DSW1",0x20,PORTCOND_EQUALS,0x00)
	PORT_DIPSETTING (	0x40, DEF_STR( 1C_2C ) )					PORT_CONDITION("DSW1",0x20,PORTCOND_EQUALS,0x00)
//  PORT_DIPSETTING (   0x00, DEF_STR( 1C_1C ) )                    PORT_CONDITION("DSW1",0x20,PORTCOND_EQUALS,0x00)
	PORT_DIPSETTING (	0xc0, "Coin A 2/1 Coin B 2/1 Coin C 1/1" )	PORT_CONDITION("DSW1",0x20,PORTCOND_NOTEQUALS,0x00)
	PORT_DIPSETTING (	0x80, "Coin A 1/1 Coin B 1/1 Coin C 1/2" )	PORT_CONDITION("DSW1",0x20,PORTCOND_NOTEQUALS,0x00)
	PORT_DIPSETTING (	0x40, "Coin A 1/2 Coin B 1/2 Coin C 1/4" )	PORT_CONDITION("DSW1",0x20,PORTCOND_NOTEQUALS,0x00)
//  PORT_DIPSETTING (   0x00, "Coin A 1/1 Coin B 1/1 Coin C 1/2" )  PORT_CONDITION("DSW1",0x20,PORTCOND_NOTEQUALS,0x00)
INPUT_PORTS_END


static INPUT_PORTS_START( astdelux )
	PORT_START("IN0")
	PORT_BIT( 0x01, IP_ACTIVE_HIGH, IPT_UNUSED ) /* According to schematics */
	/* Bit 2 is the 3 KHz source and Bit 3 the VG_HALT bit    */
	PORT_BIT( 0x02, IP_ACTIVE_HIGH, IPT_SPECIAL ) PORT_CUSTOM(clock_r, NULL)
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_SPECIAL ) PORT_CUSTOM(avgdvg_done_r, NULL)
	PORT_BIT( 0x08, IP_ACTIVE_HIGH, IPT_BUTTON5 ) PORT_CODE(KEYCODE_SPACE) PORT_CODE(JOYCODE_BUTTON3)		/* hyperspace */
	PORT_BIT( 0x10, IP_ACTIVE_HIGH, IPT_BUTTON3 ) PORT_CODE(KEYCODE_LCONTROL) PORT_CODE(JOYCODE_BUTTON1)	/* fire */
	PORT_BIT( 0x20, IP_ACTIVE_HIGH, IPT_SERVICE ) PORT_NAME("Diagnostic Step") PORT_CODE(KEYCODE_F1)
	PORT_BIT( 0x40, IP_ACTIVE_HIGH, IPT_TILT )
	PORT_SERVICE( 0x80, IP_ACTIVE_HIGH )

	PORT_START("IN1")
	PORT_BIT( 0x01, IP_ACTIVE_HIGH, IPT_COIN1 ) /* Coin Left */
	PORT_BIT( 0x02, IP_ACTIVE_HIGH, IPT_COIN2 ) /* Coin Center */
	PORT_BIT( 0x04, IP_ACTIVE_HIGH, IPT_COIN3 ) /* Coin Right */
	PORT_BIT( 0x08, IP_ACTIVE_HIGH, IPT_START1 )
	PORT_BIT( 0x10, IP_ACTIVE_HIGH, IPT_START2 )
	PORT_BIT( 0x20, IP_ACTIVE_HIGH, IPT_BUTTON4 ) PORT_CODE(KEYCODE_LALT) PORT_CODE(JOYCODE_BUTTON2)		/* thrust */
	PORT_BIT( 0x40, IP_ACTIVE_HIGH, IPT_BUTTON2 ) PORT_CODE(KEYCODE_RIGHT) PORT_CODE(JOYCODE_X_RIGHT_SWITCH)/* right */
	PORT_BIT( 0x80, IP_ACTIVE_HIGH, IPT_BUTTON1 ) PORT_CODE(KEYCODE_LEFT) PORT_CODE(JOYCODE_X_LEFT_SWITCH)	/* left */

	PORT_START("DSW1")
	PORT_DIPNAME( 0x03, 0x00, DEF_STR( Language ) )		PORT_DIPLOCATION("R5:1,2")
	PORT_DIPSETTING (	0x00, DEF_STR( English ) )
	PORT_DIPSETTING (	0x01, DEF_STR( German ) )
	PORT_DIPSETTING (	0x02, DEF_STR( French ) )
	PORT_DIPSETTING (	0x03, DEF_STR( Spanish ) )
	/*  Default lives is 2,3,4,5. Values incremented by 1 if Bonus Life set to None or Coinage set to 2C_1C.
        Incremented by 2 if both are set at the same time. PORT_CONDITION() can only test for 1 switch at a time. */
	PORT_DIPNAME( 0x0c, 0x00, DEF_STR( Lives ) )		PORT_DIPLOCATION("R5:3,4") /* Default is 2 or 3 depending on manual version */
	PORT_DIPSETTING (	0x00, "2-4" )
	PORT_DIPSETTING (	0x04, "3-5" )
	PORT_DIPSETTING (	0x08, "4-6" )
	PORT_DIPSETTING (	0x0c, "5-7" )
	PORT_DIPNAME( 0x10, 0x00, "Minimum Plays" )			PORT_DIPLOCATION("R5:5")
	PORT_DIPSETTING (	0x00, "1" )
	PORT_DIPSETTING (	0x10, "2" )
	PORT_DIPNAME( 0x20, 0x00, DEF_STR( Difficulty ) )	PORT_DIPLOCATION("R5:6") /* Listed as "Unused" */
	PORT_DIPSETTING (	0x00, DEF_STR( Hard ) )
	PORT_DIPSETTING (	0x20, DEF_STR( Easy ) )
	PORT_DIPNAME( 0xc0, 0x00, DEF_STR( Bonus_Life ) )	PORT_DIPLOCATION("R5:7,8")
	PORT_DIPSETTING (	0x00, "10000" )
	PORT_DIPSETTING (	0x40, "12000" )
	PORT_DIPSETTING (	0x80, "15000" )
	PORT_DIPSETTING (	0xc0, DEF_STR( None ) )

	PORT_START("DSW2")
	PORT_DIPNAME( 0x03, 0x01, DEF_STR( Coinage ) )		PORT_DIPLOCATION("L8:1,2")
	PORT_DIPSETTING (	0x00, DEF_STR( 2C_1C ) )
	PORT_DIPSETTING (	0x01, DEF_STR( 1C_1C ) )
	PORT_DIPSETTING (	0x02, DEF_STR( 1C_2C ) )
	PORT_DIPSETTING (	0x03, DEF_STR( Free_Play ) )
	PORT_DIPNAME( 0x0c, 0x0c, "Right Coin" )			PORT_DIPLOCATION("L8:3,4")
	PORT_DIPSETTING (	0x00, "X 6" )
	PORT_DIPSETTING (	0x04, "X 5" )
	PORT_DIPSETTING (	0x08, "X 4" )
	PORT_DIPSETTING (	0x0c, "X 1" )
	PORT_DIPNAME( 0x10, 0x10, "Center Coin" )			PORT_DIPLOCATION("L8:5") /* "Left Coin" in a 2-mech door */
	PORT_DIPSETTING (	0x00, "X 2" )
	PORT_DIPSETTING (	0x10, "X 1" )
	PORT_DIPNAME( 0xe0, 0xe0, "Bonus Coins" )			PORT_DIPLOCATION("L8:6,7,8")
	PORT_DIPSETTING (	0x60, "1 Coin Each 5 Coins" )
	PORT_DIPSETTING (	0x80, "2 Coins Each 4 Coins" )
	PORT_DIPSETTING (	0xa0, "1 Coin Each 4 Coins" )
	PORT_DIPSETTING (	0xc0, "1 Coin Each 2 Coins" )
	PORT_DIPSETTING (	0xe0, DEF_STR( None ) )

	/* The manual includes a 3rd DIP controlling the number & configuration of coin counters, defined as:
    PORT_START("DSW3")                                  // 4-Toggle switch located on game PCB at M12
    PORT_DIPNAME( 0x03, 0x00, "Coin Counters" )             PORT_DIPLOCATION("M12:1,2")
    PORT_DIPSETTING (   0x00, "1=Left, Center & Right" )    // "For games having these coin doors: Thai 1Baht/1Baht, German 1DM/1DM, US 25c/25c,
                                                            // Belgian or French 5Fr/5Fr, Swiss or French 1Fr/1Fr, US 25c/25c/25c,
                                                            // Japanese 100Y/100Y, Swedish 1Kr/1Kr, UK 10P/10P, Australian 20c/20c, or Italian 100L/100L."
    PORT_DIPSETTING (   0x01, "1=Left & Center, 2=Right" )  // "For games having these coin doors: German 2DM/1DM, German 1DM/5DM, US 25c/25c/1$, or US 25c/1$."
    PORT_DIPSETTING (   0x02, "1=Left, 2=Center & Right" )  // "No coin door is currently designed for this configuration."
    PORT_DIPSETTING (   0x03, "1=Left, 2=Center, 3=Right" ) // "For games having these coin doors: German 1DM/2DM/5DM."
    PORT_DIPUNUSED_DIPLOC( 0x04, 0x04, "M12:3" )            // Listed as "Unused"
    PORT_DIPUNUSED_DIPLOC( 0x08, 0x08, "M12:4" )            // Listed as "Unused"
    */
INPUT_PORTS_END


static INPUT_PORTS_START( llander )
	PORT_START("IN0")
	/* Bit 0 is VG_HALT */
	PORT_BIT( 0x01, IP_ACTIVE_HIGH, IPT_SPECIAL ) PORT_CUSTOM(avgdvg_done_r, NULL)
	PORT_SERVICE( 0x02, IP_ACTIVE_LOW )
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_TILT )
	/* Of the rest, Bit 6 is the 3KHz source. 3,4 and 5 are unknown */
	PORT_BIT( 0x38, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x40, IP_ACTIVE_HIGH, IPT_SPECIAL ) PORT_CUSTOM(clock_r, NULL)
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_SERVICE ) PORT_NAME("Diagnostic Step") PORT_CODE(KEYCODE_F1)

	PORT_START("IN1")
	PORT_BIT( 0x01, IP_ACTIVE_HIGH, IPT_START1 )
	PORT_BIT( 0x02, IP_ACTIVE_LOW,  IPT_COIN1 )
	PORT_BIT( 0x04, IP_ACTIVE_HIGH, IPT_COIN2 )
	PORT_BIT( 0x08, IP_ACTIVE_LOW,  IPT_COIN3 )
	PORT_BIT( 0x10, IP_ACTIVE_HIGH, IPT_START2 )  PORT_NAME("Select Game")
	PORT_BIT( 0x20, IP_ACTIVE_HIGH, IPT_BUTTON3 ) PORT_NAME("Abort")
	PORT_BIT( 0x40, IP_ACTIVE_HIGH, IPT_BUTTON2 ) PORT_CODE(KEYCODE_RIGHT) PORT_CODE(JOYCODE_X_RIGHT_SWITCH)	/* right */
	PORT_BIT( 0x80, IP_ACTIVE_HIGH, IPT_BUTTON1 ) PORT_CODE(KEYCODE_LEFT) PORT_CODE(JOYCODE_X_LEFT_SWITCH)		/* left */

	PORT_START("DSW1")
	PORT_DIPNAME( 0x03, 0x00, "Right Coin" )			PORT_DIPLOCATION("P8:1,2") /* "Left Coin Mech always registers X 1" */
	PORT_DIPSETTING (	0x00, "X 1" )
	PORT_DIPSETTING (	0x01, "X 4" )
	PORT_DIPSETTING (	0x02, "X 5" )
	PORT_DIPSETTING (	0x03, "X 6" )
	PORT_DIPNAME( 0x0c, 0x00, DEF_STR( Language ) )		PORT_DIPLOCATION("P8:3,4")
	PORT_DIPSETTING (	0x00, DEF_STR( English ) )
	PORT_DIPSETTING (	0x04, DEF_STR( French ) )
	PORT_DIPSETTING (	0x08, DEF_STR( Spanish ) )
	PORT_DIPSETTING (	0x0c, DEF_STR( German ) )
	PORT_DIPNAME( 0x20, 0x00, DEF_STR( Coinage ) )		PORT_DIPLOCATION("P8:6")
	PORT_DIPSETTING (	0x00, DEF_STR( Normal ) )
	PORT_DIPSETTING (	0x20, DEF_STR( Free_Play ) )
	PORT_DIPNAME( 0xd0, 0x80, "Fuel Units Per Coin" )	PORT_DIPLOCATION("P8:5,7,8")
	PORT_DIPSETTING (	0x00, "450" )
	PORT_DIPSETTING (	0x40, "600" )
	PORT_DIPSETTING (	0x80, "750" )
	PORT_DIPSETTING (	0xc0, "900" )
	PORT_DIPSETTING (	0x10, "1100" )
	PORT_DIPSETTING (	0x50, "1300" )
	PORT_DIPSETTING (	0x90, "1550" )
	PORT_DIPSETTING (	0xd0, "1800" )

	/* The next one is a potentiometer */
	/* The way the DAC/counter circuit always trys to self center at the voltage derived from the thrust control, */
	/* I don't think it ever expected to get to 0xff. We can not emulate the external DAC circuit exactly, */
	/* so changing the range to 0xfe seems to solve the problem. */
	/* The thrust control is basically a hand operated pedal. */
	/* so IPT_PEDAL is used because it more accurately emulates the control then using IPT_PADDLE */
	PORT_START("THRUST")
	PORT_BIT( 0xff, 0x00, IPT_PEDAL ) PORT_MINMAX(0,254) PORT_SENSITIVITY(100) PORT_KEYDELTA(10)
INPUT_PORTS_END


static INPUT_PORTS_START( llander1 )
	PORT_INCLUDE( llander )

	PORT_MODIFY("DSW1")
	PORT_DIPNAME( 0x10, 0x00, DEF_STR( Coinage ) )		PORT_DIPLOCATION("P8:5") /* "Left Coin Mech always registers X 1" */
	PORT_DIPSETTING (	0x00, DEF_STR( Normal ) )
	PORT_DIPSETTING (	0x10, DEF_STR( Free_Play ) )
	PORT_DIPUNUSED_DIPLOC( 0x20, 0x20, "P8:6" )			/* Listed as "Unused" */
	PORT_DIPNAME( 0xc0, 0x80, "Fuel units" )			PORT_DIPLOCATION("P8:7,8")
	PORT_DIPSETTING (	0x00, "450" )
	PORT_DIPSETTING (	0x40, "600" )
	PORT_DIPSETTING (	0x80, "750" )
	PORT_DIPSETTING (	0xc0, "900" )
INPUT_PORTS_END





/*************************************
 *
 *  Game drivers
 *
 *************************************/

GAME( 1979, asteroid, 0,        asteroid, asteroid, 0,        ROT0, "Atari",   "Asteroids (rev 4)",        GAME_SUPPORTS_SAVE )
GAME( 1979, asteroid2,asteroid, asteroid, asteroid, 0,        ROT0, "Atari",   "Asteroids (rev 2)",        GAME_SUPPORTS_SAVE )
GAME( 1979, asteroid1,asteroid, asteroid, asteroid, 0,        ROT0, "Atari",   "Asteroids (rev 1)",        GAME_SUPPORTS_SAVE )
GAME( 1979, asteroidb,asteroid, asteroid, asteroidb,asteroidb,ROT0, "bootleg", "Asteroids (bootleg on Lunar Lander hardware)", GAME_SUPPORTS_SAVE )
GAME( 1979, asterock, asteroid, asterock, asterock, asterock, ROT0, "bootleg (Sidam)", "Asterock",         GAME_SUPPORTS_SAVE )
GAME( 1979, meteorts, asteroid, asteroid, asteroid, 0,        ROT0, "bootleg (VGG)",   "Meteorites",       GAME_SUPPORTS_SAVE )
GAME( 1980, meteorho, asteroid, asteroid, asteroid, 0,        ROT0, "bootleg (Hoei)",  "Meteor",           GAME_SUPPORTS_SAVE )
GAMEL(1980, astdelux, 0,        astdelux, astdelux, 0,        ROT0, "Atari",   "Asteroids Deluxe (rev 3)", GAME_SUPPORTS_SAVE, layout_ho88ffff )
GAMEL(1980, astdelux2,astdelux, astdelux, astdelux, 0,        ROT0, "Atari",   "Asteroids Deluxe (rev 2)", GAME_SUPPORTS_SAVE, layout_ho88ffff )
GAMEL(1980, astdelux1,astdelux, astdelux, astdelux, 0,        ROT0, "Atari",   "Asteroids Deluxe (rev 1)", GAME_SUPPORTS_SAVE, layout_ho88ffff )
GAME( 1979, llander,  0,        llander,  llander,  0,        ROT0, "Atari",   "Lunar Lander (rev 2)",     GAME_SUPPORTS_SAVE )
GAME( 1979, llander1, llander,  llander,  llander1, 0,        ROT0, "Atari",   "Lunar Lander (rev 1)",     GAME_SUPPORTS_SAVE )
