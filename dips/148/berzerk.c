/*************************************
 *
 *  Port definitions
 *
 *************************************/

#define BERZERK_COINAGE(CHUTE, DIPBANK) \
	PORT_DIPNAME( 0x0f, 0x00, "Coin "#CHUTE )  PORT_DIPLOCATION(#DIPBANK":1,2,3,4") \
	PORT_DIPSETTING(    0x09, DEF_STR( 2C_1C ) ) \
	PORT_DIPSETTING(    0x0d, DEF_STR( 4C_3C ) ) \
	PORT_DIPSETTING(    0x00, DEF_STR( 1C_1C ) ) \
	PORT_DIPSETTING(    0x0e, DEF_STR( 4C_5C ) ) \
	PORT_DIPSETTING(    0x0a, DEF_STR( 2C_3C ) ) \
	PORT_DIPSETTING(    0x0f, DEF_STR( 4C_7C ) ) \
	PORT_DIPSETTING(    0x01, DEF_STR( 1C_2C ) ) \
	PORT_DIPSETTING(    0x0b, DEF_STR( 2C_5C ) ) \
	PORT_DIPSETTING(    0x02, DEF_STR( 1C_3C ) ) \
	PORT_DIPSETTING(    0x0c, DEF_STR( 2C_7C ) ) \
	PORT_DIPSETTING(    0x03, DEF_STR( 1C_4C ) ) \
	PORT_DIPSETTING(    0x04, DEF_STR( 1C_5C ) ) \
	PORT_DIPSETTING(    0x05, DEF_STR( 1C_6C ) ) \
	PORT_DIPSETTING(    0x06, DEF_STR( 1C_7C ) ) \
	PORT_DIPSETTING(    0x07, "1 Coin/10 Credits" ) \
	PORT_DIPSETTING(    0x08, "1 Coin/14 Credits" )


static INPUT_PORTS_START( joystick ) // used on all games except moonwarp
	PORT_START("P1")
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT ) PORT_8WAY
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT ) PORT_8WAY
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_JOYSTICK_UP ) PORT_8WAY
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN ) PORT_8WAY
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_BUTTON1 )
	PORT_BIT( 0xe0, IP_ACTIVE_LOW, IPT_UNUSED )

	PORT_START("P2")
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT ) PORT_8WAY PORT_COCKTAIL
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT ) PORT_8WAY PORT_COCKTAIL
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_JOYSTICK_UP ) PORT_8WAY PORT_COCKTAIL
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN ) PORT_8WAY PORT_COCKTAIL
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_COCKTAIL
	PORT_BIT( 0x60, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_DIPNAME( 0x80, 0x80, DEF_STR( Cabinet ) )
	PORT_DIPSETTING(    0x80, DEF_STR( Upright ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Cocktail ) )
INPUT_PORTS_END

static INPUT_PORTS_START( common ) // used on all games
	PORT_START("SYSTEM")
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_START1 )
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_START2 )
	PORT_BIT( 0x1c, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_COIN3 )
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_COIN2 )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_COIN1 )

	/* fake port for monitor type */
	PORT_START(MONITOR_TYPE_PORT_TAG)
	PORT_CONFNAME( 0x01, 0x00, "Monitor Type" )
	PORT_CONFSETTING(    0x00, "Wells-Gardner" )
	PORT_CONFSETTING(    0x01, "Electrohome" )
	PORT_BIT( 0xfe, IP_ACTIVE_HIGH, IPT_UNUSED )

	PORT_START("SW2")
	/* port for the 'bookkeeping reset' and 'bookkeeping' buttons;
	 * The 'bookkeeping reset' button is an actual button on the zpu-1000 and
	 * zpu-1001 pcbs, labeled 'S2' or 'SW2'. It is wired to bit 0.
	 * * pressing it while high scores are displayed will give a free game
	 *   without adding any coin info to the bookkeeping info in nvram.
	 * The 'bookkeeping' button is wired to the control panel, usually hidden
	 * underneath or only accessible through the coin door. Wired to bit 7.
	 * * It displays various bookkeeping statistics when pressed sequentially.
	 *   Pressing P1 fire (according to the manual) when stats are displayed
	 *   will clear the stat shown on screen.
	 */
	PORT_BIT( 0x01, IP_ACTIVE_HIGH, IPT_SERVICE1 ) PORT_NAME("Free Game (not logged in bookkeeping)")
	PORT_BIT( 0x7e, IP_ACTIVE_LOW,  IPT_UNUSED )
	PORT_BIT( 0x80, IP_ACTIVE_HIGH, IPT_SERVICE2 ) PORT_NAME("Bookkeeping") PORT_CODE(KEYCODE_F1)
INPUT_PORTS_END

static INPUT_PORTS_START( berzerk )
	PORT_INCLUDE( joystick )
	PORT_INCLUDE( common )

	PORT_START("F2")
	PORT_DIPNAME( 0x03, 0x00, "Color Test" ) PORT_CODE(KEYCODE_F5) PORT_TOGGLE PORT_DIPLOCATION("F2:1,2")
	PORT_DIPSETTING(    0x00, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x03, DEF_STR( On ) )
	PORT_BIT( 0x3c, IP_ACTIVE_LOW,  IPT_UNUSED )
	PORT_DIPNAME( 0xc0, 0xc0, DEF_STR( Bonus_Life ) ) PORT_DIPLOCATION("F2:7,8")
	PORT_DIPSETTING(    0xc0, "5000 and 10000" )
	PORT_DIPSETTING(    0x40, "5000" )
	PORT_DIPSETTING(    0x80, "10000" )
	PORT_DIPSETTING(    0x00, DEF_STR( None ) )

	PORT_START("F3")
	PORT_DIPNAME( 0x01, 0x00, "Input Test Mode" ) PORT_CODE(KEYCODE_F2) PORT_TOGGLE PORT_DIPLOCATION("F3:1")
	PORT_DIPSETTING(    0x00, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x01, DEF_STR( On ) )
	PORT_DIPNAME( 0x02, 0x00, "Crosshair Pattern" ) PORT_CODE(KEYCODE_F4) PORT_TOGGLE PORT_DIPLOCATION("F3:2")
	PORT_DIPSETTING(    0x00, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x02, DEF_STR( On ) )
	PORT_BIT( 0x3c, IP_ACTIVE_LOW,  IPT_UNUSED )
	PORT_DIPNAME( 0xc0, 0x00, DEF_STR( Language ) ) PORT_DIPLOCATION("F3:7,8")
	PORT_DIPSETTING(    0x00, DEF_STR( English ) )
	PORT_DIPSETTING(    0x40, DEF_STR( German ) )
	PORT_DIPSETTING(    0x80, DEF_STR( French ) )
	PORT_DIPSETTING(    0xc0, DEF_STR( Spanish ) )

	PORT_START("F4")
	BERZERK_COINAGE(1, F4)
	PORT_BIT( 0xf0, IP_ACTIVE_LOW,  IPT_UNUSED )

	PORT_START("F5")
	BERZERK_COINAGE(2, F5)
	PORT_BIT( 0xf0, IP_ACTIVE_LOW,  IPT_UNUSED )

	PORT_START("F6")
	BERZERK_COINAGE(3, F6)
	PORT_BIT( 0xf0, IP_ACTIVE_LOW,  IPT_UNUSED )
INPUT_PORTS_END

// this set has German speech roms, so default the language to German
static INPUT_PORTS_START( berzerkg )
	PORT_INCLUDE( berzerk )

	PORT_MODIFY("F3")
	PORT_DIPNAME( 0xc0, 0x40, DEF_STR( Language ) ) PORT_DIPLOCATION("F3:7,8")
	PORT_DIPSETTING(    0x00, DEF_STR( English ) )
	PORT_DIPSETTING(    0x40, DEF_STR( German ) )
	PORT_DIPSETTING(    0x80, DEF_STR( French ) )
	PORT_DIPSETTING(    0xc0, DEF_STR( Spanish ) )
INPUT_PORTS_END

static INPUT_PORTS_START( frenzy )
	PORT_INCLUDE( joystick )
	PORT_INCLUDE( common )

	PORT_MODIFY("SYSTEM")
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_UNUSED ) // frenzy lacks coin 3

	PORT_START("F2")
	/* Bit 0 does some more hardware tests. According to the manual, both bit 0 & 1 must be:
	   - ON for Signature Analysis (S.A.)
	   - OFF for game operation     */
	//PORT_BIT( 0x03, IP_ACTIVE_HIGH, IPT_UNUSED )  // F2:1,2
	PORT_DIPNAME( 0x03, 0x00, "Hardware Tests" ) PORT_DIPLOCATION("F2:1,2")
	PORT_DIPSETTING(    0x00, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x01, "Color test" )
	PORT_DIPSETTING(    0x02, DEF_STR( Unknown ) )
	PORT_DIPSETTING(    0x03, "Signature Analysis" )
	PORT_DIPNAME( 0x04, 0x00, "Input Test Mode" ) PORT_CODE(KEYCODE_F2) PORT_TOGGLE PORT_DIPLOCATION("F2:3")
	PORT_DIPSETTING(    0x00, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x04, DEF_STR( On ) )
	PORT_DIPNAME( 0x08, 0x00, "Crosshair Pattern" ) PORT_CODE(KEYCODE_F4) PORT_TOGGLE PORT_DIPLOCATION("F2:4")
	PORT_DIPSETTING(    0x00, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x08, DEF_STR( On ) )
	PORT_BIT( 0xf0, IP_ACTIVE_HIGH, IPT_UNUSED ) PORT_DIPLOCATION("F2:5,6,7,8")

	PORT_START("F3")
	PORT_DIPNAME( 0x0f, 0x03, DEF_STR( Bonus_Life ) ) PORT_DIPLOCATION("F3:1,2,3,4")
	PORT_DIPSETTING(    0x01, "1000" )
	PORT_DIPSETTING(    0x02, "2000" )
	PORT_DIPSETTING(    0x03, "3000" )
	PORT_DIPSETTING(    0x04, "4000" )
	PORT_DIPSETTING(    0x05, "5000" )
	PORT_DIPSETTING(    0x06, "6000" )
	PORT_DIPSETTING(    0x07, "7000" )
	PORT_DIPSETTING(    0x08, "8000" )
	PORT_DIPSETTING(    0x09, "9000" )
	PORT_DIPSETTING(    0x0a, "10000" )
	PORT_DIPSETTING(    0x0b, "11000" )
	PORT_DIPSETTING(    0x0c, "12000" )
	PORT_DIPSETTING(    0x0d, "13000" )
	PORT_DIPSETTING(    0x0e, "14000" )
	PORT_DIPSETTING(    0x0f, "15000" )
	PORT_DIPSETTING(    0x00, DEF_STR( None ) )
	PORT_BIT( 0x30, IP_ACTIVE_HIGH, IPT_UNUSED ) PORT_DIPLOCATION("F3:5,6")
	PORT_DIPNAME( 0xc0, 0x00, DEF_STR( Language ) ) PORT_DIPLOCATION("F3:7,8")
	PORT_DIPSETTING(    0x00, DEF_STR( English ) )
	PORT_DIPSETTING(    0x40, DEF_STR( German ) )
	PORT_DIPSETTING(    0x80, DEF_STR( French ) )
	PORT_DIPSETTING(    0xc0, DEF_STR( Spanish ) )

	/* The following 3 ports use all 8 bits, but I didn't feel like adding all 256 values :-) */
	PORT_START("F4")
	PORT_DIPNAME( 0xff, 0x01, "Coin Multiplier" ) PORT_DIPLOCATION("F4:1,2,3,4,5,6,7,8")
	PORT_DIPSETTING(    0x00, DEF_STR( Free_Play ) )
	PORT_DIPSETTING(    0x01, "1" )
	PORT_DIPSETTING(    0x02, "2" )
	PORT_DIPSETTING(    0x03, "3" )
	PORT_DIPSETTING(    0x04, "4" )
	PORT_DIPSETTING(    0x05, "5" )
	PORT_DIPSETTING(    0x06, "6" )
	PORT_DIPSETTING(    0x07, "7" )
	PORT_DIPSETTING(    0x08, "8" )
	PORT_DIPSETTING(    0x09, "9" )
	PORT_DIPSETTING(    0x0a, "10" )
	PORT_DIPSETTING(    0x0b, "11" )
	PORT_DIPSETTING(    0x0c, "12" )
	PORT_DIPSETTING(    0x0d, "13" )
	PORT_DIPSETTING(    0x0e, "14" )
	PORT_DIPSETTING(    0x0f, "15" )
	PORT_DIPSETTING(    0xff, "255" )

	PORT_START("F5")
	PORT_DIPNAME( 0xff, 0x01, "Coins/Credit A" ) PORT_DIPLOCATION("F5:1,2,3,4,5,6,7,8")
	PORT_DIPSETTING(    0x00, "0 (invalid)" ) //   Can't insert coins
	PORT_DIPSETTING(    0x01, "1" )
	PORT_DIPSETTING(    0x02, "2" )
	PORT_DIPSETTING(    0x03, "3" )
	PORT_DIPSETTING(    0x04, "4" )
	PORT_DIPSETTING(    0x05, "5" )
	PORT_DIPSETTING(    0x06, "6" )
	PORT_DIPSETTING(    0x07, "7" )
	PORT_DIPSETTING(    0x08, "8" )
	PORT_DIPSETTING(    0x09, "9" )
	PORT_DIPSETTING(    0x0a, "10" )
	PORT_DIPSETTING(    0x0b, "11" )
	PORT_DIPSETTING(    0x0c, "12" )
	PORT_DIPSETTING(    0x0d, "13" )
	PORT_DIPSETTING(    0x0e, "14" )
	PORT_DIPSETTING(    0x0f, "15" )
	PORT_DIPSETTING(    0xff, "255" )

	PORT_START("F6")
	PORT_DIPNAME( 0xff, 0x01, "Coins/Credit B" ) PORT_DIPLOCATION("F6:1,2,3,4,5,6,7,8")
	PORT_DIPSETTING(    0x00, "0 (invalid)" ) //   Can't insert coins
	PORT_DIPSETTING(    0x01, "1" )
	PORT_DIPSETTING(    0x02, "2" )
	PORT_DIPSETTING(    0x03, "3" )
	PORT_DIPSETTING(    0x04, "4" )
	PORT_DIPSETTING(    0x05, "5" )
	PORT_DIPSETTING(    0x06, "6" )
	PORT_DIPSETTING(    0x07, "7" )
	PORT_DIPSETTING(    0x08, "8" )
	PORT_DIPSETTING(    0x09, "9" )
	PORT_DIPSETTING(    0x0a, "10" )
	PORT_DIPSETTING(    0x0b, "11" )
	PORT_DIPSETTING(    0x0c, "12" )
	PORT_DIPSETTING(    0x0d, "13" )
	PORT_DIPSETTING(    0x0e, "14" )
	PORT_DIPSETTING(    0x0f, "15" )
	PORT_DIPSETTING(    0xff, "255" )
INPUT_PORTS_END

READ8_MEMBER(berzerk_state::moonwarp_p1_r)
{
	// This seems to be the same type of dial as the later 'moon war 2' set uses
	// see http://www.cityofberwyn.com/schematics/stern/MoonWar_opto.tiff for schematic
	// I.e. a 74ls161 counts from 0 to 15 which is the absolute number of bars passed on the quadrature
	// one difference is it lacks the strobe input (does it?), which if not active causes
	// the dial input to go open bus. This is used in moon war 2 to switch between player 1
	// and player 2 dials, which share a single port. moonwarp uses separate ports for the dials.
	signed char dialread = ioport("P1_DIAL")->read();
	UINT8 ret;
	UINT8 buttons = (ioport("P1")->read()&0xe0);
	if (dialread < 0) m_p1_direction = 0;
	else if (dialread > 0) m_p1_direction = 0x10;
	m_p1_counter_74ls161 += abs(dialread);
	m_p1_counter_74ls161 &= 0xf;
	ret = m_p1_counter_74ls161 | m_p1_direction | buttons;
	//fprintf(stderr, "dialread1: %02x, p1_counter_74ls161: %02x, spinner ret is %02x\n", dialread, m_p1_counter_74ls161, ret);
	return ret;
}

READ8_MEMBER(berzerk_state::moonwarp_p2_r)
{
	// same as above, but for player 2 in cocktail mode
	signed char dialread = ioport("P2_DIAL")->read();
	UINT8 ret;
	UINT8 buttons = (ioport("P2")->read()&0xe0);
	if (dialread < 0) m_p2_direction = 0;
	else if (dialread > 0) m_p2_direction = 0x10;
	m_p2_counter_74ls161 += abs(dialread);
	m_p2_counter_74ls161 &= 0xf;
	ret = m_p2_counter_74ls161 | m_p2_direction | buttons;
	//fprintf(stderr, "dialread2: %02x, p2_counter_74ls161: %02x, spinner ret is %02x\n", dialread, m_p2_counter_74ls161, ret);
	return ret;
}

static INPUT_PORTS_START( moonwarp )
	PORT_INCLUDE( common )

	PORT_MODIFY("SYSTEM")
	PORT_BIT( 0x04, IP_ACTIVE_HIGH, IPT_UNUSED ) // is wired high for upright harness, low for cocktail; if high, cocktail dipswitch is ignored.
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_BUTTON4 ) // Hyper flip button is common for both players in cocktail mode.

	PORT_START("P1")
	//PORT_BIT( 0x1f, IP_ACTIVE_HIGH, IPT_SPECIAL ) // spinner/dial
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_BUTTON3 )
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_BUTTON2 )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_BUTTON1 )

	PORT_START("P1_DIAL")
	PORT_BIT( 0xff, 0x0, IPT_DIAL ) PORT_SENSITIVITY(25) PORT_KEYDELTA(4) PORT_RESET

	PORT_START("P2")
	//PORT_BIT( 0x1f, IP_ACTIVE_HIGH, IPT_SPECIAL ) PORT_COCKTAIL // spinner/dial
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_BUTTON3 ) PORT_COCKTAIL
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_BUTTON2 ) PORT_COCKTAIL
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_COCKTAIL

	PORT_START("P2_DIAL")
	PORT_BIT( 0xff, 0x0, IPT_DIAL ) PORT_SENSITIVITY(25) PORT_KEYDELTA(4) PORT_COCKTAIL PORT_RESET

	PORT_START("F2")
	PORT_DIPNAME( 0x03, 0x00, "Hardware Tests" ) PORT_DIPLOCATION("F2:1,2")
	PORT_DIPSETTING(    0x00, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x01, "Color test" )
	PORT_DIPSETTING(    0x02, DEF_STR( Unknown ) )
	PORT_DIPSETTING(    0x03, "Signature Analysis" )
	PORT_DIPNAME( 0x04, 0x00, DEF_STR( Unknown ) ) PORT_DIPLOCATION("F2:3")
	PORT_DIPSETTING(    0x04, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0xF8, 0x00, DEF_STR( Bonus_Life ) ) PORT_DIPLOCATION("F2:4,5,6,7,8")
	PORT_DIPSETTING(    0x00, "10000" )
	PORT_DIPSETTING(    0x08, "15000" )
	PORT_DIPSETTING(    0x10, "20000" )
	PORT_DIPSETTING(    0x20, "30000" )
	PORT_DIPSETTING(    0x40, "40000" )
	PORT_DIPSETTING(    0x80, "50000" )
	PORT_DIPSETTING(    0x18, "15000 (duplicate)" )
	PORT_DIPSETTING(    0x28, "15000 (duplicate)" )
	PORT_DIPSETTING(    0x30, "20000 (duplicate)" )
	PORT_DIPSETTING(    0x38, "15000 (duplicate)" )
	PORT_DIPSETTING(    0x48, "15000 (duplicate)" )
	PORT_DIPSETTING(    0x50, "20000 (duplicate)" )
	PORT_DIPSETTING(    0x58, "15000 (duplicate)" )
	PORT_DIPSETTING(    0x60, "30000 (duplicate)" )
	PORT_DIPSETTING(    0x68, "15000 (duplicate)" )
	PORT_DIPSETTING(    0x70, "20000 (duplicate)" )
	PORT_DIPSETTING(    0x78, "15000 (duplicate)" )
	PORT_DIPSETTING(    0x88, "15000 (duplicate)" )
	PORT_DIPSETTING(    0x90, "20000 (duplicate)" )
	PORT_DIPSETTING(    0x98, "15000 (duplicate)" )
	PORT_DIPSETTING(    0xa0, "30000 (duplicate)" )
	PORT_DIPSETTING(    0xa8, "15000 (duplicate)" )
	PORT_DIPSETTING(    0xb0, "20000 (duplicate)" )
	PORT_DIPSETTING(    0xb8, "15000 (duplicate)" )
	PORT_DIPSETTING(    0xc0, "40000 (duplicate)" )
	PORT_DIPSETTING(    0xc8, "15000 (duplicate)" )
	PORT_DIPSETTING(    0xd0, "20000 (duplicate)" )
	PORT_DIPSETTING(    0xd8, "15000 (duplicate)" )
	PORT_DIPSETTING(    0xe0, "30000 (duplicate)" )
	PORT_DIPSETTING(    0xe8, "15000 (duplicate)" )
	PORT_DIPSETTING(    0xf0, "20000 (duplicate)" )
	PORT_DIPSETTING(    0xf8, "15000 (duplicate)" )

	PORT_START("F3")
	PORT_DIPNAME( 0x01, 0x00, "Input Test Mode" ) PORT_CODE(KEYCODE_F2) PORT_TOGGLE PORT_DIPLOCATION("F3:1")
	PORT_DIPSETTING(    0x00, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x01, DEF_STR( On ) )
	PORT_DIPNAME( 0x02, 0x00, "Crosshair Pattern" ) PORT_CODE(KEYCODE_F4) PORT_TOGGLE PORT_DIPLOCATION("F3:2")
	PORT_DIPSETTING(    0x00, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x02, DEF_STR( On ) )
	PORT_DIPNAME( 0x04, 0x00, DEF_STR( Unknown ) ) PORT_DIPLOCATION("F3:3")
	PORT_DIPSETTING(    0x04, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x08, 0x00, "Spinner Orientation" ) PORT_DIPLOCATION("F3:4")
	PORT_DIPSETTING(    0x08, DEF_STR( Reverse ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Standard ) )
	PORT_DIPNAME( 0x10, 0x00, DEF_STR( Unknown ) ) PORT_DIPLOCATION("F3:5")
	PORT_DIPSETTING(    0x10, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x20, 0x00, DEF_STR( Unknown ) ) PORT_DIPLOCATION("F3:6")
	PORT_DIPSETTING(    0x20, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0xc0, 0x00, DEF_STR( Language ) ) PORT_DIPLOCATION("F3:7,8")
	PORT_DIPSETTING(    0x00, DEF_STR( English ) )
	PORT_DIPSETTING(    0x40, DEF_STR( German ) )
	PORT_DIPSETTING(    0x80, DEF_STR( French ) )
	PORT_DIPSETTING(    0xc0, DEF_STR( Spanish ) )

	PORT_START("F4")
	BERZERK_COINAGE(1, F4)
	PORT_DIPNAME( 0x10, 0x00, DEF_STR( Unknown ) ) PORT_DIPLOCATION("F4:5")
	PORT_DIPSETTING(    0x10, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x20, 0x00, DEF_STR( Unknown ) ) PORT_DIPLOCATION("F4:6")
	PORT_DIPSETTING(    0x20, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x40, 0x00, DEF_STR( Unknown ) ) PORT_DIPLOCATION("F4:7")
	PORT_DIPSETTING(    0x40, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x80, 0x00, DEF_STR( Unknown ) ) PORT_DIPLOCATION("F4:8")
	PORT_DIPSETTING(    0x80, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )

	PORT_START("F5")
	BERZERK_COINAGE(2, F5)
	PORT_DIPNAME( 0x10, 0x00, DEF_STR( Unknown ) ) PORT_DIPLOCATION("F5:5")
	PORT_DIPSETTING(    0x10, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x20, 0x00, DEF_STR( Unknown ) ) PORT_DIPLOCATION("F5:6")
	PORT_DIPSETTING(    0x20, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x40, 0x00, DEF_STR( Unknown ) ) PORT_DIPLOCATION("F5:7")
	PORT_DIPSETTING(    0x40, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x80, 0x00, DEF_STR( Cabinet ) ) PORT_DIPLOCATION("F5:8")
	PORT_DIPSETTING(    0x00, DEF_STR( Upright ) )
	PORT_DIPSETTING(    0x80, DEF_STR( Cocktail ) )

	PORT_START("F6")
	BERZERK_COINAGE(3, F6)
	PORT_DIPNAME( 0x10, 0x00, DEF_STR( Unknown ) ) PORT_DIPLOCATION("F6:5")
	PORT_DIPSETTING(    0x10, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x20, 0x00, DEF_STR( Unknown ) ) PORT_DIPLOCATION("F6:6") // enemy spawn rate?
	PORT_DIPSETTING(    0x20, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0xc0, 0x00, DEF_STR( Difficulty ) ) PORT_DIPLOCATION("F6:7,8") // Difficulty select effectively chooses what level to start on, level 1, 2, 3, or 4 for very easy, easy, normal, and hard. Number here is added to the current level count (base 1) at $43be.
	PORT_DIPSETTING(    0x00, DEF_STR( Very_Easy ) )
	PORT_DIPSETTING(    0x40, DEF_STR( Easy ) )
	PORT_DIPSETTING(    0x80, DEF_STR( Normal ) )
	PORT_DIPSETTING(    0xc0, DEF_STR( Hard ) )

INPUT_PORTS_END


/*************************************
 *
 *  Game drivers
 *
 *************************************/

GAME( 1980, berzerk,  0,       berzerk, berzerk, driver_device, 0, ROT0, "Stern Electronics", "Berzerk (set 1)", 0 )
GAME( 1980, berzerk1, berzerk, berzerk, berzerk, driver_device, 0, ROT0, "Stern Electronics", "Berzerk (set 2)", 0 )
GAME( 1980, berzerkg, berzerk, berzerk, berzerkg, driver_device,0, ROT0, "Stern Electronics", "Berzerk (German Speech)", 0 )
GAME( 1981, frenzy,   0,       frenzy,  frenzy, driver_device,  0, ROT0, "Stern Electronics", "Frenzy", 0 )
GAME( 1981, moonwarp, 0,       frenzy,  moonwarp, berzerk_state,moonwarp, ROT0, "Stern Electronics", "Moon War (prototype on Frenzy hardware)", 0)
