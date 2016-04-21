# MAME 0.139 source snippet.

/*************************************
 *
 *  Port definitions
 *
 *************************************/

static INPUT_PORTS_START( spacewar )
	PORT_START("INPUTS")
	PORT_BIT( 0x0001, IP_ACTIVE_LOW, IPT_OTHER ) PORT_NAME("Option 3") PORT_CODE(KEYCODE_3_PAD)
	PORT_BIT( 0x0002, IP_ACTIVE_LOW, IPT_OTHER ) PORT_NAME("Option 8") PORT_CODE(KEYCODE_8_PAD)
	PORT_BIT( 0x0004, IP_ACTIVE_LOW, IPT_OTHER ) PORT_NAME("Option 4") PORT_CODE(KEYCODE_4_PAD)
	PORT_BIT( 0x0008, IP_ACTIVE_LOW, IPT_OTHER ) PORT_NAME("Option 9") PORT_CODE(KEYCODE_9_PAD)
	PORT_BIT( 0x0010, IP_ACTIVE_LOW, IPT_OTHER ) PORT_NAME("Option 1") PORT_CODE(KEYCODE_1_PAD)
	PORT_BIT( 0x0020, IP_ACTIVE_LOW, IPT_OTHER ) PORT_NAME("Option 6") PORT_CODE(KEYCODE_6_PAD)
	PORT_BIT( 0x0040, IP_ACTIVE_LOW, IPT_OTHER ) PORT_NAME("Option 2") PORT_CODE(KEYCODE_2_PAD)
	PORT_BIT( 0x0080, IP_ACTIVE_LOW, IPT_OTHER ) PORT_NAME("Option 7") PORT_CODE(KEYCODE_7_PAD)
	PORT_BIT( 0x0100, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT ) PORT_2WAY PORT_PLAYER(1)
	PORT_BIT( 0x0200, IP_ACTIVE_LOW, IPT_BUTTON2 ) PORT_PLAYER(2)
	PORT_BIT( 0x0400, IP_ACTIVE_LOW, IPT_OTHER ) PORT_NAME("Option 5") PORT_CODE(KEYCODE_5_PAD)
	PORT_BIT( 0x0800, IP_ACTIVE_LOW, IPT_OTHER ) PORT_NAME("Option 0") PORT_CODE(KEYCODE_0_PAD)
	PORT_BIT( 0x1000, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT ) PORT_2WAY PORT_PLAYER(2)
	PORT_BIT( 0x2000, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT ) PORT_2WAY PORT_PLAYER(1)
	PORT_BIT( 0x4000, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT ) PORT_2WAY PORT_PLAYER(2)
	PORT_BIT( 0x8000, IP_ACTIVE_LOW, IPT_BUTTON2 ) PORT_PLAYER(1)

	PORT_START("SWITCHES")
	PORT_DIPNAME( 0x03, 0x00,  "Time" )
	PORT_DIPSETTING(    0x03, "0:45/coin" )
	PORT_DIPSETTING(    0x00, "1:00/coin" )
	PORT_DIPSETTING(	0x01, "1:30/coin" )
	PORT_DIPSETTING(	0x02, "2:00/coin" )
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_PLAYER(2)
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_BUTTON3 ) PORT_PLAYER(2)
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_PLAYER(1)
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_BUTTON3 ) PORT_PLAYER(1)
	PORT_DIPNAME( 0x40, 0x40, DEF_STR( Unknown ) )
	PORT_DIPSETTING(	0x40, DEF_STR( Off ) )
	PORT_DIPSETTING(	0x00, DEF_STR( On ) )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_COIN1 ) PORT_CHANGED(coin_inserted, 0)
INPUT_PORTS_END


static INPUT_PORTS_START( spaceshp )
	PORT_INCLUDE(spacewar )

	PORT_MODIFY("SWITCHES")
	PORT_DIPNAME( 0x03, 0x00, "Time" ) PORT_DIPLOCATION("SW1:!4,!3")
	PORT_DIPSETTING(	0x00, "1:00/coin" )
	PORT_DIPSETTING(	0x01, "1:30/coin" )
	PORT_DIPSETTING(	0x02, "2:00/coin" )
	PORT_DIPSETTING(	0x03, "2:30/coin" )
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_DIPUNUSED_DIPLOC( 0x04, 0x04, "SW1:!1" )
	PORT_DIPUNUSED_DIPLOC( 0x08, 0x08, "SW1:!2" )
INPUT_PORTS_END


static INPUT_PORTS_START( barrier )
	PORT_START("INPUTS")
	PORT_BIT( 0x0001, IP_ACTIVE_LOW, IPT_OTHER ) PORT_NAME("Skill A") PORT_CODE(KEYCODE_A)
	PORT_BIT( 0x0002, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x0004, IP_ACTIVE_LOW, IPT_OTHER ) PORT_NAME("Skill B") PORT_CODE(KEYCODE_B)
	PORT_BIT( 0x0008, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN ) PORT_4WAY PORT_PLAYER(1)
	PORT_BIT( 0x0010, IP_ACTIVE_LOW, IPT_START2 )
	PORT_BIT( 0x0020, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x0040, IP_ACTIVE_LOW, IPT_OTHER ) PORT_NAME("Skill C") PORT_CODE(KEYCODE_C)
	PORT_BIT( 0x0080, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x0100, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT ) PORT_4WAY PORT_PLAYER(2)
	PORT_BIT( 0x0200, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT ) PORT_4WAY PORT_PLAYER(1)
	PORT_BIT( 0x0400, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN ) PORT_4WAY PORT_PLAYER(2)
	PORT_BIT( 0x0800, IP_ACTIVE_LOW, IPT_START1 )
	PORT_BIT( 0x1000, IP_ACTIVE_LOW, IPT_JOYSTICK_UP ) PORT_4WAY PORT_PLAYER(1)
	PORT_BIT( 0x2000, IP_ACTIVE_LOW, IPT_JOYSTICK_UP ) PORT_4WAY PORT_PLAYER(2)
	PORT_BIT( 0x4000, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT ) PORT_4WAY PORT_PLAYER(1)
	PORT_BIT( 0x8000, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT ) PORT_4WAY PORT_PLAYER(2)

	PORT_START("SWITCHES")
	PORT_DIPNAME( 0x01, 0x00, DEF_STR( Lives ) )
	PORT_DIPSETTING(    0x00, "3" )
	PORT_DIPSETTING(    0x01, "5" )
	PORT_DIPNAME( 0x02, 0x02, DEF_STR( Demo_Sounds ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x02, DEF_STR( On ) )
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
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_COIN1 ) PORT_CHANGED(coin_inserted, 0)
INPUT_PORTS_END


static INPUT_PORTS_START( speedfrk )
	PORT_START("INPUTS")
	PORT_BIT( 0x000f, IP_ACTIVE_LOW, IPT_SPECIAL ) /* steering wheel, fake below */
	PORT_BIT( 0x0070, IP_ACTIVE_LOW, IPT_SPECIAL ) /* gear shift, fake below */
	PORT_BIT( 0x0080, IP_ACTIVE_LOW, IPT_START1 )
	PORT_BIT( 0x0100, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_PLAYER(1) /* gas */
	PORT_BIT( 0xfe00, IP_ACTIVE_LOW, IPT_UNUSED )

	PORT_START("SWITCHES")
	PORT_DIPNAME( 0x03, 0x02, "Extra Time" )
	PORT_DIPSETTING(    0x00, "69" )
	PORT_DIPSETTING(    0x01, "99" )
	PORT_DIPSETTING(    0x02, "129" )
	PORT_DIPSETTING(    0x03, "159" )
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
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_COIN1 ) PORT_CHANGED(coin_inserted, 0)

	PORT_START("WHEEL")
	PORT_BIT( 0xff, 0x00, IPT_DIAL ) PORT_SENSITIVITY(100) PORT_KEYDELTA(10) PORT_RESET

	PORT_START("GEAR")
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN ) PORT_NAME("1st gear") PORT_PLAYER(2)
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT ) PORT_NAME("2nd gear") PORT_PLAYER(2)
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT ) PORT_NAME("3rd gear") PORT_PLAYER(2)
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_JOYSTICK_UP ) PORT_NAME("4th gear") PORT_PLAYER(2)
INPUT_PORTS_END


/* TODO: 4way or 8way stick? */
static INPUT_PORTS_START( starhawk )
	PORT_START("INPUTS")
	PORT_BIT( 0x0001, IP_ACTIVE_LOW, IPT_JOYSTICK_UP ) PORT_8WAY PORT_PLAYER(1)
	PORT_BIT( 0x0002, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT ) PORT_8WAY PORT_PLAYER(1)
	PORT_BIT( 0x0004, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT ) PORT_8WAY PORT_PLAYER(1)
	PORT_BIT( 0x0008, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN ) PORT_8WAY PORT_PLAYER(1)
	PORT_BIT( 0x0010, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT ) PORT_8WAY PORT_PLAYER(2)
	PORT_BIT( 0x0020, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN ) PORT_8WAY PORT_PLAYER(2)
	PORT_BIT( 0x00c0, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x0100, IP_ACTIVE_LOW, IPT_BUTTON2 ) PORT_PLAYER(2)
	PORT_BIT( 0x0200, IP_ACTIVE_LOW, IPT_BUTTON4 ) PORT_PLAYER(1)
	PORT_BIT( 0x0400, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT ) PORT_8WAY PORT_PLAYER(2)
	PORT_BIT( 0x0800, IP_ACTIVE_LOW, IPT_JOYSTICK_UP ) PORT_8WAY PORT_PLAYER(2)
	PORT_BIT( 0x1000, IP_ACTIVE_LOW, IPT_BUTTON3 ) PORT_PLAYER(1)
	PORT_BIT( 0x2000, IP_ACTIVE_LOW, IPT_BUTTON3 ) PORT_PLAYER(2)
	PORT_BIT( 0x4000, IP_ACTIVE_LOW, IPT_BUTTON2 ) PORT_PLAYER(1)
	PORT_BIT( 0x8000, IP_ACTIVE_LOW, IPT_BUTTON4 ) PORT_PLAYER(2)

	PORT_START("SWITCHES")
	PORT_DIPNAME( 0x03, 0x03, DEF_STR( Game_Time ) )
	PORT_DIPSETTING(	0x03, "2:00/4:00" )
	PORT_DIPSETTING(	0x01, "1:30/3:00" )
	PORT_DIPSETTING(	0x02, "1:00/2:00" )
	PORT_DIPSETTING(	0x00, "0:45/1:30" )
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_START1 )
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_PLAYER(1)
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_START2 )
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_PLAYER(2)
	PORT_DIPNAME( 0x40,	0x40, DEF_STR( Unknown ) )
	PORT_DIPSETTING(	0x40, DEF_STR( Off ) )
	PORT_DIPSETTING(	0x00, DEF_STR( On ) )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_COIN1 ) PORT_CHANGED(coin_inserted, 0)
INPUT_PORTS_END


static INPUT_PORTS_START( sundance )
	PORT_START("INPUTS")
	PORT_BIT( 0x0001, IP_ACTIVE_LOW, IPT_SPECIAL ) /* P1 Pad */
	PORT_BIT( 0x0002, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_PLAYER(1)
	PORT_BIT( 0x0004, IP_ACTIVE_LOW, IPT_START1 )
	PORT_BIT( 0x0008, IP_ACTIVE_LOW, IPT_START2 )
	PORT_BIT( 0x0010, IP_ACTIVE_LOW, IPT_OTHER ) PORT_NAME("3 Suns") PORT_CODE(KEYCODE_STOP)
	PORT_BIT( 0x0020, IP_ACTIVE_LOW, IPT_OTHER ) PORT_NAME("Toggle Grid") PORT_CODE(KEYCODE_G)
	PORT_BIT( 0x0040, IP_ACTIVE_LOW, IPT_OTHER ) PORT_NAME("4 Suns") PORT_CODE(KEYCODE_SLASH)
	PORT_BIT( 0x0080, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_PLAYER(2)
	PORT_BIT( 0x0100, IP_ACTIVE_LOW, IPT_SPECIAL ) /* P2 Pad */
	PORT_BIT( 0x0200, IP_ACTIVE_LOW, IPT_SPECIAL ) /* P1 Pad */
	PORT_BIT( 0x0400, IP_ACTIVE_LOW, IPT_SPECIAL ) /* P2 Pad */
	PORT_BIT( 0x0800, IP_ACTIVE_LOW, IPT_OTHER ) PORT_NAME("2 Suns") PORT_CODE(KEYCODE_COMMA)
	PORT_BIT( 0x1000, IP_ACTIVE_LOW, IPT_SPECIAL ) /* P1 Pad */
	PORT_BIT( 0x2000, IP_ACTIVE_LOW, IPT_SPECIAL ) /* P2 Pad */
	PORT_BIT( 0x4000, IP_ACTIVE_LOW, IPT_SPECIAL ) /* P1 Pad */
	PORT_BIT( 0x8000, IP_ACTIVE_LOW, IPT_SPECIAL ) /* P2 Pad */

	PORT_START("SWITCHES")
	PORT_DIPNAME( 0x03, 0x02, "Time" )
	PORT_DIPSETTING(	0x00, "0:45/coin" )
	PORT_DIPSETTING(	0x02, "1:00/coin" )
	PORT_DIPSETTING(	0x01, "1:30/coin" )
	PORT_DIPSETTING(	0x03, "2:00/coin" )
	PORT_DIPNAME( 0x04,	0x00, DEF_STR( Language ) )
	PORT_DIPSETTING(	0x04, DEF_STR( Japanese ) )
	PORT_DIPSETTING(	0x00, DEF_STR( English ) )
	PORT_DIPNAME( 0x08, 0x08, DEF_STR( Unknown ) ) /* supposedly coinage, doesn't work */
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
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_COIN1 ) PORT_CHANGED(coin_inserted, 0)

	PORT_START("PAD1")
	PORT_BIT( 0x0001, IP_ACTIVE_HIGH, IPT_OTHER ) PORT_NAME("P1 Pad 1") PORT_CODE(KEYCODE_7_PAD) PORT_PLAYER(1)
	PORT_BIT( 0x0002, IP_ACTIVE_HIGH, IPT_OTHER ) PORT_NAME("P1 Pad 2") PORT_CODE(KEYCODE_8_PAD) PORT_PLAYER(1)
	PORT_BIT( 0x0004, IP_ACTIVE_HIGH, IPT_OTHER ) PORT_NAME("P1 Pad 3") PORT_CODE(KEYCODE_9_PAD) PORT_PLAYER(1)
	PORT_BIT( 0x0008, IP_ACTIVE_HIGH, IPT_OTHER ) PORT_NAME("P1 Pad 4") PORT_CODE(KEYCODE_4_PAD) PORT_PLAYER(1)
	PORT_BIT( 0x0010, IP_ACTIVE_HIGH, IPT_OTHER ) PORT_NAME("P1 Pad 5") PORT_CODE(KEYCODE_5_PAD) PORT_PLAYER(1)
	PORT_BIT( 0x0020, IP_ACTIVE_HIGH, IPT_OTHER ) PORT_NAME("P1 Pad 6") PORT_CODE(KEYCODE_6_PAD) PORT_PLAYER(1)
	PORT_BIT( 0x0040, IP_ACTIVE_HIGH, IPT_OTHER ) PORT_NAME("P1 Pad 7") PORT_CODE(KEYCODE_1_PAD) PORT_PLAYER(1)
	PORT_BIT( 0x0080, IP_ACTIVE_HIGH, IPT_OTHER ) PORT_NAME("P1 Pad 8") PORT_CODE(KEYCODE_2_PAD) PORT_PLAYER(1)
	PORT_BIT( 0x0100, IP_ACTIVE_HIGH, IPT_OTHER ) PORT_NAME("P1 Pad 9") PORT_CODE(KEYCODE_3_PAD) PORT_PLAYER(1)

	PORT_START("PAD2")
	PORT_BIT( 0x0001, IP_ACTIVE_HIGH, IPT_OTHER ) PORT_NAME("P2 Pad 1") PORT_CODE(KEYCODE_Q) PORT_PLAYER(2)
	PORT_BIT( 0x0002, IP_ACTIVE_HIGH, IPT_OTHER ) PORT_NAME("P2 Pad 2") PORT_CODE(KEYCODE_W) PORT_PLAYER(2)
	PORT_BIT( 0x0004, IP_ACTIVE_HIGH, IPT_OTHER ) PORT_NAME("P2 Pad 3") PORT_CODE(KEYCODE_E) PORT_PLAYER(2)
	PORT_BIT( 0x0008, IP_ACTIVE_HIGH, IPT_OTHER ) PORT_NAME("P2 Pad 4") PORT_CODE(KEYCODE_A) PORT_PLAYER(2)
	PORT_BIT( 0x0010, IP_ACTIVE_HIGH, IPT_OTHER ) PORT_NAME("P2 Pad 5") PORT_CODE(KEYCODE_S) PORT_PLAYER(2)
	PORT_BIT( 0x0020, IP_ACTIVE_HIGH, IPT_OTHER ) PORT_NAME("P2 Pad 6") PORT_CODE(KEYCODE_D) PORT_PLAYER(2)
	PORT_BIT( 0x0040, IP_ACTIVE_HIGH, IPT_OTHER ) PORT_NAME("P2 Pad 7") PORT_CODE(KEYCODE_Z) PORT_PLAYER(2)
	PORT_BIT( 0x0080, IP_ACTIVE_HIGH, IPT_OTHER ) PORT_NAME("P2 Pad 8") PORT_CODE(KEYCODE_X) PORT_PLAYER(2)
	PORT_BIT( 0x0100, IP_ACTIVE_HIGH, IPT_OTHER ) PORT_NAME("P2 Pad 9") PORT_CODE(KEYCODE_C) PORT_PLAYER(2)
INPUT_PORTS_END


static INPUT_PORTS_START( tailg )
	PORT_START("INPUTS")
	PORT_BIT( 0x001f, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x0020, IP_ACTIVE_LOW, IPT_BUTTON1 )
	PORT_BIT( 0x0040, IP_ACTIVE_LOW, IPT_BUTTON2 )
	PORT_BIT( 0x0080, IP_ACTIVE_LOW, IPT_START1 )
	PORT_BIT( 0xff00, IP_ACTIVE_LOW, IPT_UNUSED )

	PORT_START("SWITCHES")
	PORT_DIPNAME( 0x23, 0x23, "Shield Points" )
	PORT_DIPSETTING(	0x00, "15" )
	PORT_DIPSETTING(	0x02, "20" )
	PORT_DIPSETTING(	0x01, "30" )
	PORT_DIPSETTING(	0x03, "40" )
	PORT_DIPSETTING(	0x20, "50" )
	PORT_DIPSETTING(	0x22, "60" )
	PORT_DIPSETTING(	0x21, "70" )
	PORT_DIPSETTING(	0x23, "80" )
	PORT_DIPNAME( 0x04,	0x04, DEF_STR( Coinage ) )
	PORT_DIPSETTING(	0x00, DEF_STR( 2C_1C ) )
	PORT_DIPSETTING(	0x04, DEF_STR( 1C_1C ) )
	PORT_DIPNAME( 0x08, 0x08, DEF_STR( Unknown ) )
	PORT_DIPSETTING(    0x08, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x10, 0x10, DEF_STR( Unknown ) )
	PORT_DIPSETTING(    0x10, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x40, 0x40, DEF_STR( Unknown ) )
	PORT_DIPSETTING(    0x40, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_COIN1 ) PORT_CHANGED(coin_inserted, 0)

	PORT_START("ANALOGX")
	PORT_BIT( 0xfff, 0x800, IPT_AD_STICK_X ) PORT_MINMAX(0x200,0xe00) PORT_SENSITIVITY(100) PORT_KEYDELTA(50)

	PORT_START("ANALOGY")
	PORT_BIT( 0xfff, 0x800, IPT_AD_STICK_Y ) PORT_MINMAX(0x200,0xe00) PORT_SENSITIVITY(100) PORT_KEYDELTA(50)
INPUT_PORTS_END


static INPUT_PORTS_START( warrior )
	PORT_START("INPUTS")
	PORT_BIT( 0x0001, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT ) PORT_PLAYER(2)
	PORT_BIT( 0x0002, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT )  PORT_PLAYER(2)
	PORT_BIT( 0x0004, IP_ACTIVE_LOW, IPT_JOYSTICK_UP )    PORT_PLAYER(2)
	PORT_BIT( 0x0008, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN )  PORT_PLAYER(2)
	PORT_BIT( 0x0010, IP_ACTIVE_LOW, IPT_BUTTON1 )        PORT_PLAYER(2)
	PORT_BIT( 0x00e0, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x0100, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT ) PORT_PLAYER(1)
	PORT_BIT( 0x0200, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT )  PORT_PLAYER(1)
	PORT_BIT( 0x0400, IP_ACTIVE_LOW, IPT_JOYSTICK_UP )    PORT_PLAYER(1)
	PORT_BIT( 0x0800, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN )  PORT_PLAYER(1)
	PORT_BIT( 0x1000, IP_ACTIVE_LOW, IPT_BUTTON1 )        PORT_PLAYER(1)
	PORT_BIT( 0xe000, IP_ACTIVE_LOW, IPT_UNUSED )

	PORT_START("SWITCHES")
	PORT_DIPNAME( 0x01, 0x01, DEF_STR( Unknown ) )
	PORT_DIPSETTING(    0x01, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x02, 0x02, DEF_STR( Unknown ) )
	PORT_DIPSETTING(    0x02, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_SERVICE( 0x04, IP_ACTIVE_HIGH )
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
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_COIN1 ) PORT_CHANGED(coin_inserted, 0)
INPUT_PORTS_END


static INPUT_PORTS_START( armora )
	PORT_START("INPUTS")
	PORT_BIT( 0x0001, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT ) PORT_2WAY PORT_PLAYER(2)
	PORT_BIT( 0x0002, IP_ACTIVE_LOW, IPT_START1 )
	PORT_BIT( 0x0004, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT ) PORT_2WAY PORT_PLAYER(2)
	PORT_BIT( 0x0008, IP_ACTIVE_LOW, IPT_START2 )
	PORT_BIT( 0x0010, IP_ACTIVE_LOW, IPT_BUTTON2 ) PORT_PLAYER(2)
	PORT_BIT( 0x0020, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_PLAYER(2)
	PORT_BIT( 0x0fc0, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x1000, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT ) PORT_2WAY PORT_PLAYER(1)
	PORT_BIT( 0x2000, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_PLAYER(1)
	PORT_BIT( 0x4000, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT ) PORT_2WAY PORT_PLAYER(1)
	PORT_BIT( 0x8000, IP_ACTIVE_LOW, IPT_BUTTON2 ) PORT_PLAYER(1)

	PORT_START("SWITCHES")
	PORT_DIPNAME( 0x03, 0x03, DEF_STR( Lives ) )
	PORT_DIPSETTING(    0x00, "2" )
	PORT_DIPSETTING(    0x02, "3" )
	PORT_DIPSETTING(    0x01, "4" )
	PORT_DIPSETTING(    0x03, "5" )
	PORT_DIPNAME( 0x0c, 0x0c, DEF_STR( Coinage ) )
	PORT_DIPSETTING(    0x04, DEF_STR( 2C_1C ) )
	PORT_DIPSETTING(    0x00, DEF_STR( 4C_3C ) )
	PORT_DIPSETTING(    0x0c, DEF_STR( 1C_1C ) )
	PORT_DIPSETTING(    0x08, DEF_STR( 2C_3C ) )
	PORT_DIPNAME( 0x10, 0x00, DEF_STR( Demo_Sounds ) )
	PORT_DIPSETTING(    0x10, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x20, 0x20, DEF_STR( Unknown ) )
	PORT_DIPSETTING(    0x20, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_SERVICE( 0x40, IP_ACTIVE_HIGH )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_COIN1 ) PORT_CHANGED(coin_inserted, 0)
INPUT_PORTS_END


static INPUT_PORTS_START( ripoff )
	PORT_START("INPUTS")
	PORT_BIT( 0x0001, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT ) PORT_2WAY PORT_PLAYER(2)
	PORT_BIT( 0x0002, IP_ACTIVE_LOW, IPT_START1 )
	PORT_BIT( 0x0004, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT ) PORT_2WAY PORT_PLAYER(2)
	PORT_BIT( 0x0008, IP_ACTIVE_LOW, IPT_START2 )
	PORT_BIT( 0x0010, IP_ACTIVE_LOW, IPT_BUTTON2 ) PORT_PLAYER(2)
	PORT_BIT( 0x0020, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_PLAYER(2)
	PORT_BIT( 0x0fc0, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x1000, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT ) PORT_2WAY PORT_PLAYER(1)
	PORT_BIT( 0x2000, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_PLAYER(1)
	PORT_BIT( 0x4000, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT ) PORT_2WAY PORT_PLAYER(1)
	PORT_BIT( 0x8000, IP_ACTIVE_LOW, IPT_BUTTON2 ) PORT_PLAYER(1)

	PORT_START("SWITCHES")
	PORT_DIPNAME( 0x03, 0x03, DEF_STR( Lives ) )
	PORT_DIPSETTING(	0x01, "4" )
	PORT_DIPSETTING(	0x03, "8" )
	PORT_DIPSETTING(	0x00, "12" )
	PORT_DIPSETTING(	0x02, "16" )
	PORT_DIPNAME( 0x0c, 0x00, DEF_STR( Coinage ) )
	PORT_DIPSETTING(	0x04, DEF_STR( 2C_1C ) )
	PORT_DIPSETTING(	0x0c, DEF_STR( 4C_3C ) )
	PORT_DIPSETTING(	0x00, DEF_STR( 1C_1C ) )
	PORT_DIPSETTING(	0x08, DEF_STR( 2C_3C ) )
	PORT_DIPNAME( 0x10,	0x10, DEF_STR( Demo_Sounds ) )
	PORT_DIPSETTING(	0x00, DEF_STR( Off ) )
	PORT_DIPSETTING(	0x10, DEF_STR( On ) )
	PORT_DIPNAME( 0x20,	0x00, "Scores" )
	PORT_DIPSETTING(	0x00, "Individual" )
	PORT_DIPSETTING(	0x20, "Combined" )
	PORT_SERVICE( 0x40,	IP_ACTIVE_LOW )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_COIN1 ) PORT_CHANGED(coin_inserted, 0)
INPUT_PORTS_END


static INPUT_PORTS_START( starcas )
	PORT_START("INPUTS")
	PORT_BIT( 0x0001, IP_ACTIVE_LOW, IPT_START1 )
	PORT_BIT( 0x0002, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x0004, IP_ACTIVE_LOW, IPT_START2 )
	PORT_BIT( 0x0038, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x0040, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT ) PORT_2WAY
	PORT_BIT( 0x0080, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x0100, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT ) PORT_2WAY
	PORT_BIT( 0x0200, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x0400, IP_ACTIVE_LOW, IPT_BUTTON2 )
	PORT_BIT( 0x0800, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x1000, IP_ACTIVE_LOW, IPT_BUTTON1 )
	PORT_BIT( 0xe000, IP_ACTIVE_LOW, IPT_UNUSED )

	PORT_START("SWITCHES")
	PORT_DIPNAME( 0x03, 0x03, DEF_STR( Lives ) )
	PORT_DIPSETTING(    0x03, "3" )
	PORT_DIPSETTING(    0x01, "4" )
	PORT_DIPSETTING(    0x02, "5" )
	PORT_DIPSETTING(    0x00, "6" )
	PORT_DIPNAME( 0x0c, 0x0c, DEF_STR( Coinage ) )
	PORT_DIPSETTING(    0x04, DEF_STR( 2C_1C ) )
	PORT_DIPSETTING(    0x00, DEF_STR( 4C_3C ) )
	PORT_DIPSETTING(    0x0c, DEF_STR( 1C_1C ) )
	PORT_DIPSETTING(    0x08, DEF_STR( 2C_3C ) )
	PORT_DIPNAME( 0x10, 0x10, DEF_STR( Unknown ) )
	PORT_DIPSETTING(    0x10, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x20, 0x20, DEF_STR( Unknown ) )
	PORT_DIPSETTING(    0x20, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_SERVICE( 0x40, IP_ACTIVE_HIGH )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_COIN1 ) PORT_CHANGED(coin_inserted, 0)
INPUT_PORTS_END


static INPUT_PORTS_START( solarq )
	PORT_START("INPUTS")
	PORT_BIT( 0x0001, IP_ACTIVE_LOW, IPT_BUTTON4 ) PORT_PLAYER(1) /* nova */
	PORT_BIT( 0x0002, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_PLAYER(1) /* fire */
	PORT_BIT( 0x0004, IP_ACTIVE_LOW, IPT_BUTTON2 ) PORT_PLAYER(1) /* thrust */
	PORT_BIT( 0x0008, IP_ACTIVE_LOW, IPT_BUTTON3 ) PORT_PLAYER(1) /* hyperspace */
	PORT_BIT( 0x0010, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT ) PORT_2WAY PORT_PLAYER(1)
	PORT_BIT( 0x0020, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT ) PORT_2WAY PORT_PLAYER(1)
	PORT_BIT( 0xffc0, IP_ACTIVE_LOW, IPT_UNUSED )

	PORT_START("SWITCHES")
	PORT_DIPNAME( 0x05, 0x05, DEF_STR( Coinage ) )
	PORT_DIPSETTING(	0x01, DEF_STR( 2C_1C ) )
	PORT_DIPSETTING(	0x00, DEF_STR( 4C_3C ) )
	PORT_DIPSETTING(	0x05, DEF_STR( 1C_1C ) )
	PORT_DIPSETTING(	0x04, DEF_STR( 2C_3C ) )
	PORT_DIPNAME( 0x02,	0x02, DEF_STR( Bonus_Life ) )
	PORT_DIPSETTING(	0x02, "25 captures" )
	PORT_DIPSETTING(	0x00, "40 captures" )
	PORT_DIPNAME( 0x18, 0x10, DEF_STR( Lives ) )
	PORT_DIPSETTING(	0x18, "2" )
	PORT_DIPSETTING(	0x08, "3" )
	PORT_DIPSETTING(	0x10, "4" )
	PORT_DIPSETTING(	0x00, "5" )
	PORT_DIPNAME( 0x20,	0x20, DEF_STR( Free_Play ) )
	PORT_DIPSETTING(	0x20, DEF_STR( Off ) )
	PORT_DIPSETTING(	0x00, DEF_STR( On ) )
	PORT_SERVICE( 0x40,	IP_ACTIVE_HIGH )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_COIN1 ) PORT_CHANGED(coin_inserted, 0)
INPUT_PORTS_END


static INPUT_PORTS_START( boxingb )
	PORT_START("INPUTS")
	PORT_BIT( 0x0001, IP_ACTIVE_LOW,  IPT_BUTTON1 ) PORT_PLAYER(2)
	PORT_BIT( 0x0002, IP_ACTIVE_LOW,  IPT_BUTTON2 ) PORT_PLAYER(2)
	PORT_BIT( 0x0004, IP_ACTIVE_LOW,  IPT_BUTTON3 ) PORT_PLAYER(2)
	PORT_BIT( 0x0008, IP_ACTIVE_LOW,  IPT_BUTTON3 ) PORT_PLAYER(1)
	PORT_BIT( 0x0010, IP_ACTIVE_LOW,  IPT_BUTTON2 ) PORT_PLAYER(1)
	PORT_BIT( 0x0020, IP_ACTIVE_LOW,  IPT_BUTTON1 ) PORT_PLAYER(1)
	PORT_BIT( 0x0fc0, IP_ACTIVE_LOW,  IPT_UNUSED )
	PORT_BIT( 0xf000, IP_ACTIVE_HIGH, IPT_SPECIAL )	/* dial */

	PORT_START("SWITCHES")
	PORT_DIPNAME( 0x03, 0x03, DEF_STR( Coinage ) )
	PORT_DIPSETTING(	0x01, DEF_STR( 2C_1C ) )
	PORT_DIPSETTING(	0x00, DEF_STR( 4C_3C ) )
	PORT_DIPSETTING(	0x03, DEF_STR( 1C_1C ) )
	PORT_DIPSETTING(	0x02, DEF_STR( 2C_3C ) )
	PORT_DIPNAME( 0x04,	0x00, DEF_STR( Lives ) )
	PORT_DIPSETTING(	0x04, "3" )
	PORT_DIPSETTING(	0x00, "5" )
	PORT_DIPNAME( 0x08,	0x00, DEF_STR( Bonus_Life ) )
	PORT_DIPSETTING(	0x00, "30,000" )
	PORT_DIPSETTING(	0x08, "50,000" )
	PORT_DIPNAME( 0x10,	0x00, DEF_STR( Demo_Sounds ) )
	PORT_DIPSETTING(	0x10, DEF_STR( Off ) )
	PORT_DIPSETTING(	0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x20,	0x20, DEF_STR( Free_Play ) )
	PORT_DIPSETTING(	0x20, DEF_STR( Off ) )
	PORT_DIPSETTING(	0x00, DEF_STR( On ) )
	PORT_SERVICE( 0x40,	IP_ACTIVE_LOW )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_COIN1 ) PORT_CHANGED(coin_inserted, 0)

	PORT_START("DIAL")
	PORT_BIT( 0xff, 0x00, IPT_DIAL ) PORT_REVERSE PORT_SENSITIVITY(100) PORT_KEYDELTA(5)
INPUT_PORTS_END


static INPUT_PORTS_START( wotw )
	PORT_START("INPUTS")
	PORT_BIT( 0x0001, IP_ACTIVE_LOW, IPT_START1 )
	PORT_BIT( 0x0002, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x0004, IP_ACTIVE_LOW, IPT_START2 )
	PORT_BIT( 0x0038, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x0040, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT ) PORT_2WAY
	PORT_BIT( 0x0080, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x0100, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT ) PORT_2WAY
	PORT_BIT( 0x0200, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x0400, IP_ACTIVE_LOW, IPT_BUTTON2 )
	PORT_BIT( 0x0800, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x1000, IP_ACTIVE_LOW, IPT_BUTTON1 )
	PORT_BIT( 0xe000, IP_ACTIVE_LOW, IPT_UNUSED )

	PORT_START("SWITCHES")
	PORT_DIPNAME( 0x01, 0x01, DEF_STR( Unknown ) )
	PORT_DIPSETTING(    0x01, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x02, 0x00, DEF_STR( Lives ) )
	PORT_DIPSETTING(    0x00, "3" )
	PORT_DIPSETTING(    0x02, "5" )
	PORT_DIPNAME( 0x04, 0x04, DEF_STR( Unknown ) )
	PORT_DIPSETTING(    0x04, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x08, 0x08, DEF_STR( Coinage ) )
	PORT_DIPSETTING(    0x08, DEF_STR( 1C_1C ) )
	PORT_DIPSETTING(    0x00, DEF_STR( 2C_3C ) )
	PORT_DIPNAME( 0x10, 0x10, DEF_STR( Unknown ) )
	PORT_DIPSETTING(    0x10, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x20, 0x20, DEF_STR( Free_Play ) )
	PORT_DIPSETTING(    0x20, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_SERVICE( 0x40, IP_ACTIVE_LOW )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_COIN1 ) PORT_CHANGED(coin_inserted, 0)
INPUT_PORTS_END


static INPUT_PORTS_START( demon )
	PORT_START("INPUTS")
	PORT_BIT( 0x0001, IP_ACTIVE_LOW, IPT_START1 )
	PORT_BIT( 0x0002, IP_ACTIVE_LOW, IPT_START2 )
	PORT_BIT( 0x0004, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT ) PORT_2WAY PORT_PLAYER(1)
	PORT_BIT( 0x0008, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT ) PORT_2WAY PORT_PLAYER(1)
	PORT_BIT( 0x0010, IP_ACTIVE_LOW, IPT_BUTTON2 ) PORT_PLAYER(1)
	PORT_BIT( 0x0020, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_PLAYER(1)
	PORT_BIT( 0x0040, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_SERVICE( 0x0080, IP_ACTIVE_LOW )
	PORT_BIT( 0x0100, IP_ACTIVE_LOW, IPT_TILT )
	PORT_BIT( 0x0200, IP_ACTIVE_LOW, IPT_BUTTON3 ) PORT_PLAYER(1)
	PORT_BIT( 0x0400, IP_ACTIVE_LOW, IPT_BUTTON3 ) PORT_PLAYER(2)
	PORT_BIT( 0x0800, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT ) PORT_2WAY PORT_PLAYER(2)
	PORT_BIT( 0x1000, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT ) PORT_2WAY PORT_PLAYER(2)
	PORT_BIT( 0x2000, IP_ACTIVE_LOW, IPT_BUTTON2 ) PORT_PLAYER(2)
	PORT_BIT( 0x4000, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_PLAYER(2)
	PORT_BIT( 0x8000, IP_ACTIVE_LOW, IPT_UNKNOWN ) /* also mapped to Button 3, player 2 */

	PORT_START("SWITCHES")
	PORT_DIPNAME( 0x03, 0x03, DEF_STR( Coinage ) )
	PORT_DIPSETTING(    0x01, DEF_STR( 2C_1C ) )
	PORT_DIPSETTING(    0x00, DEF_STR( 4C_3C ) )
	PORT_DIPSETTING(    0x03, DEF_STR( 1C_1C ) )
	PORT_DIPSETTING(    0x02, DEF_STR( 2C_3C ) )
	PORT_DIPNAME( 0x0c, 0x00, DEF_STR( Lives ) )
	PORT_DIPSETTING(    0x00, "3")
	PORT_DIPSETTING(    0x04, "4" )
	PORT_DIPSETTING(    0x08, "5" )
	PORT_DIPSETTING(    0x0c, "6" )
	PORT_DIPNAME( 0x30, 0x30, "Starting Difficulty" )
	PORT_DIPSETTING(    0x30, "1" )
	PORT_DIPSETTING(    0x10, "5" )
	PORT_DIPSETTING(    0x00, "10" )
/*  PORT_DIPSETTING(    0x20, "1" )*/
	PORT_DIPNAME( 0x40, 0x40, DEF_STR( Free_Play ) )
	PORT_DIPSETTING(    0x40, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_COIN1 ) PORT_CHANGED(coin_inserted, 0)
INPUT_PORTS_END


static INPUT_PORTS_START( qb3 )
	PORT_START("INPUTS")
	PORT_BIT( 0x0001, IP_ACTIVE_LOW,  IPT_JOYSTICKLEFT_UP )
	PORT_BIT( 0x0002, IP_ACTIVE_LOW,  IPT_JOYSTICKLEFT_DOWN )
	PORT_BIT( 0x0004, IP_ACTIVE_LOW,  IPT_JOYSTICKRIGHT_LEFT )
	PORT_BIT( 0x0008, IP_ACTIVE_LOW,  IPT_JOYSTICKRIGHT_UP )
	PORT_BIT( 0x0010, IP_ACTIVE_LOW,  IPT_JOYSTICKRIGHT_RIGHT )
	PORT_BIT( 0x0020, IP_ACTIVE_LOW,  IPT_JOYSTICKRIGHT_DOWN )
	PORT_BIT( 0x0040, IP_ACTIVE_LOW,  IPT_START1 )
	PORT_BIT( 0x0080, IP_ACTIVE_LOW,  IPT_START2 )
	PORT_BIT( 0x0100, IP_ACTIVE_LOW,  IPT_BUTTON4 )					// read at $1a5; if 0 add 8 to $25
	PORT_DIPNAME( 0x0200, 0x0200, "Debug" )
	PORT_DIPSETTING(	  0x0200, DEF_STR( Off ) )
	PORT_DIPSETTING(	  0x0000, DEF_STR( On ) )
	PORT_BIT( 0x0400, IP_ACTIVE_LOW,  IPT_BUTTON2 )					// read at $c7; jmp to $3AF1 if 0
	PORT_BIT( 0x0800, IP_ACTIVE_LOW,  IPT_JOYSTICKLEFT_RIGHT )
	PORT_DIPNAME( 0x1000, 0x1000, "Infinite Lives" )
	PORT_DIPSETTING(	  0x1000, DEF_STR( Off ) )
	PORT_DIPSETTING(	  0x0000, DEF_STR( On ) )
	PORT_BIT( 0x2000, IP_ACTIVE_LOW,  IPT_JOYSTICKLEFT_LEFT )
	PORT_BIT( 0x4000, IP_ACTIVE_LOW,  IPT_BUTTON1 )
	PORT_BIT( 0x8000, IP_ACTIVE_LOW,  IPT_SPECIAL )

	PORT_START("SWITCHES")
	PORT_DIPNAME( 0x03, 0x02, DEF_STR( Lives ) )
	PORT_DIPSETTING(	0x00, "2" )
	PORT_DIPSETTING(	0x02, "3" )
	PORT_DIPSETTING(	0x01, "4" )
	PORT_DIPSETTING(	0x03, "5" )
	PORT_DIPNAME( 0x04,	0x00, DEF_STR( Unknown ) )
	PORT_DIPSETTING(	0x04, DEF_STR( Off ) )
	PORT_DIPSETTING(	0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x08,	0x08, DEF_STR( Free_Play ) )	// read at $244, $2c1
	PORT_DIPSETTING(	0x08, DEF_STR( Off ) )
	PORT_DIPSETTING(	0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x10,	0x00, DEF_STR( Unknown ) )	// read at $27d
	PORT_DIPSETTING(	0x10, DEF_STR( Off ) )
	PORT_DIPSETTING(	0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x20,	0x20, DEF_STR( Unknown ) )	 // read at $282
	PORT_DIPSETTING(	0x20, DEF_STR( Off ) )
	PORT_DIPSETTING(	0x00, DEF_STR( On ) )
	PORT_SERVICE( 0x40,	IP_ACTIVE_LOW )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_COIN1 ) PORT_CHANGED(coin_inserted, 0)
INPUT_PORTS_END




/*************************************
 *
 *  Game drivers
 *
 *************************************/

GAME( 1977, spacewar, 0,       spacewar, spacewar, 0,        ORIENTATION_FLIP_Y,   "Cinematronics", "Space Wars", GAME_IMPERFECT_SOUND | GAME_SUPPORTS_SAVE )
GAME( 1978, spaceshp, spacewar,spacewar, spaceshp, 0,        ORIENTATION_FLIP_Y,   "Cinematronics (Sega license)", "Space Ship", GAME_IMPERFECT_SOUND | GAME_SUPPORTS_SAVE )
GAME( 1979, barrier,  0,       barrier,  barrier,  0,        ORIENTATION_FLIP_X ^ ROT270, "Vectorbeam", "Barrier", GAME_IMPERFECT_SOUND | GAME_SUPPORTS_SAVE )
GAME( 1979, speedfrk, 0,       speedfrk, speedfrk, speedfrk, ORIENTATION_FLIP_Y,   "Vectorbeam", "Speed Freak", GAME_NO_SOUND | GAME_SUPPORTS_SAVE )
GAME( 1979, starhawk, 0,       starhawk, starhawk, 0,        ORIENTATION_FLIP_Y,   "Cinematronics", "Star Hawk", GAME_IMPERFECT_SOUND | GAME_SUPPORTS_SAVE )
GAMEL(1979, sundance, 0,       sundance, sundance, sundance, ORIENTATION_FLIP_X ^ ROT270, "Cinematronics", "Sundance", GAME_IMPERFECT_SOUND | GAME_SUPPORTS_SAVE, layout_voffff20 )
GAMEL(1979, tailg,    0,       tailg,    tailg,    tailg,    ORIENTATION_FLIP_Y,   "Cinematronics", "Tailgunner", GAME_IMPERFECT_SOUND | GAME_SUPPORTS_SAVE, layout_ho20ffff )
GAME( 1979, warrior,  0,       warrior,  warrior,  0,        ORIENTATION_FLIP_Y,   "Vectorbeam", "Warrior", GAME_IMPERFECT_SOUND | GAME_SUPPORTS_SAVE )
GAMEL(1980, armora,   0,       armora,   armora,   0,        ORIENTATION_FLIP_Y,   "Cinematronics", "Armor Attack", GAME_IMPERFECT_SOUND | GAME_SUPPORTS_SAVE, layout_armora )
GAMEL(1980, armorap,  armora,  armora,   armora,   0,        ORIENTATION_FLIP_Y,   "Cinematronics", "Armor Attack (prototype)", GAME_IMPERFECT_SOUND | GAME_SUPPORTS_SAVE, layout_armora )
GAMEL(1980, armorar,  armora,  armora,   armora,   0,        ORIENTATION_FLIP_Y,   "Cinematronics (Rock-Ola license)", "Armor Attack (Rock-Ola)", GAME_IMPERFECT_SOUND | GAME_SUPPORTS_SAVE, layout_armora )
GAME( 1980, ripoff,   0,       ripoff,   ripoff,   0,        ORIENTATION_FLIP_Y,   "Cinematronics", "Rip Off", GAME_IMPERFECT_SOUND | GAME_SUPPORTS_SAVE )
GAMEL(1980, starcas,  0,       starcas,  starcas,  0,        ORIENTATION_FLIP_Y,   "Cinematronics", "Star Castle (version 3)", GAME_IMPERFECT_SOUND | GAME_SUPPORTS_SAVE, layout_starcas )
GAMEL(1980, starcas1, starcas, starcas,  starcas,  0,        ORIENTATION_FLIP_Y,   "Cinematronics", "Star Castle (older)", GAME_IMPERFECT_SOUND | GAME_SUPPORTS_SAVE, layout_starcas )
GAMEL(1980, starcasp, starcas, starcas,  starcas,  0,        ORIENTATION_FLIP_Y,   "Cinematronics", "Star Castle (prototype)", GAME_IMPERFECT_SOUND | GAME_SUPPORTS_SAVE, layout_starcas )
GAMEL(1980, starcase, starcas, starcas,  starcas,  0,        ORIENTATION_FLIP_Y,   "Cinematronics (Mottoeis license)", "Star Castle (Mottoeis)", GAME_IMPERFECT_SOUND | GAME_SUPPORTS_SAVE, layout_starcas )
GAMEL(1980, stellcas, starcas, starcas,  starcas,  0,        ORIENTATION_FLIP_Y,   "bootleg (Elettronolo)", "Stellar Castle (Elettronolo)", GAME_IMPERFECT_SOUND | GAME_SUPPORTS_SAVE, layout_starcas )
GAMEL(1981, spaceftr, starcas, starcas,  starcas,  0,        ORIENTATION_FLIP_Y,   "Cinematronics (Zaccaria license)", "Space Fortress (Zaccaria)", GAME_IMPERFECT_SOUND | GAME_SUPPORTS_SAVE, layout_starcas )
GAMEL(1981, solarq,   0,       solarq,   solarq,   0,        ORIENTATION_FLIP_Y ^ ORIENTATION_FLIP_X, "Cinematronics", "Solar Quest", GAME_IMPERFECT_SOUND | GAME_SUPPORTS_SAVE, layout_solarq )
GAME( 1981, boxingb,  0,       boxingb,  boxingb,  boxingb,  ORIENTATION_FLIP_Y,   "Cinematronics", "Boxing Bugs", GAME_IMPERFECT_SOUND | GAME_SUPPORTS_SAVE )
GAME( 1981, wotw,     0,       wotw,     wotw,     0,        ORIENTATION_FLIP_Y,   "Cinematronics", "War of the Worlds", GAME_IMPERFECT_SOUND | GAME_SUPPORTS_SAVE )
GAME( 1981, wotwc,    wotw,    wotwc,    wotw,     0,        ORIENTATION_FLIP_Y,   "Cinematronics", "War of the Worlds (color)", GAME_IMPERFECT_SOUND | GAME_SUPPORTS_SAVE )
GAME( 1982, demon,    0,       demon,    demon,    0,        ORIENTATION_FLIP_Y,   "Rock-Ola", "Demon", GAME_SUPPORTS_SAVE )
GAME( 1982, qb3,      0,       qb3,      qb3,      qb3,      ORIENTATION_FLIP_Y,   "Rock-Ola", "QB-3 (prototype)", GAME_IMPERFECT_GRAPHICS | GAME_SUPPORTS_SAVE )
