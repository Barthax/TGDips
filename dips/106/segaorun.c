static INPUT_PORTS_START( outrun_generic )
	PORT_START_TAG("SERVICE")
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_SERVICE_NO_TOGGLE( 0x02, IP_ACTIVE_LOW )
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_SERVICE1 )
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_START1 )
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_COIN1 )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_COIN2 )

	PORT_START_TAG("UNKNOWN")
	PORT_BIT( 0xff, IP_ACTIVE_LOW, IPT_UNKNOWN )

	PORT_START_TAG("COINAGE")
	PORT_DIPNAME( 0x0f, 0x0f, DEF_STR( Coin_A ) )
	PORT_DIPSETTING(    0x07, DEF_STR( 4C_1C ) )
	PORT_DIPSETTING(    0x08, DEF_STR( 3C_1C ) )
	PORT_DIPSETTING(    0x09, DEF_STR( 2C_1C ) )
	PORT_DIPSETTING(    0x05, "2 Coins/1 Credit 5/3 6/4" )
	PORT_DIPSETTING(    0x04, "2 Coins/1 Credit 4/3" )
	PORT_DIPSETTING(    0x0f, DEF_STR( 1C_1C ) )
	PORT_DIPSETTING(    0x01, "1 Coin/1 Credit 2/3" )
	PORT_DIPSETTING(    0x02, "1 Coin/1 Credit 4/5" )
	PORT_DIPSETTING(    0x03, "1 Coin/1 Credit 5/6" )
	PORT_DIPSETTING(    0x06, DEF_STR( 2C_3C ) )
	PORT_DIPSETTING(    0x0e, DEF_STR( 1C_2C ) )
	PORT_DIPSETTING(    0x0d, DEF_STR( 1C_3C ) )
	PORT_DIPSETTING(    0x0c, DEF_STR( 1C_4C ) )
	PORT_DIPSETTING(    0x0b, DEF_STR( 1C_5C ) )
	PORT_DIPSETTING(    0x0a, DEF_STR( 1C_6C ) )
	PORT_DIPSETTING(    0x00, "Free Play (if Coin B too) or 1/1" )
	PORT_DIPNAME( 0xf0, 0xf0, DEF_STR( Coin_B ) )
	PORT_DIPSETTING(    0x70, DEF_STR( 4C_1C ) )
	PORT_DIPSETTING(    0x80, DEF_STR( 3C_1C ) )
	PORT_DIPSETTING(    0x90, DEF_STR( 2C_1C ) )
	PORT_DIPSETTING(    0x50, "2 Coins/1 Credit 5/3 6/4" )
	PORT_DIPSETTING(    0x40, "2 Coins/1 Credit 4/3" )
	PORT_DIPSETTING(    0xf0, DEF_STR( 1C_1C ) )
	PORT_DIPSETTING(    0x10, "1 Coin/1 Credit 2/3" )
	PORT_DIPSETTING(    0x20, "1 Coin/1 Credit 4/5" )
	PORT_DIPSETTING(    0x30, "1 Coin/1 Credit 5/6" )
	PORT_DIPSETTING(    0x60, DEF_STR( 2C_3C ) )
	PORT_DIPSETTING(    0xe0, DEF_STR( 1C_2C ) )
	PORT_DIPSETTING(    0xd0, DEF_STR( 1C_3C ) )
	PORT_DIPSETTING(    0xc0, DEF_STR( 1C_4C ) )
	PORT_DIPSETTING(    0xb0, DEF_STR( 1C_5C ) )
	PORT_DIPSETTING(    0xa0, DEF_STR( 1C_6C ) )
	PORT_DIPSETTING(    0x00, "Free Play (if Coin A too) or 1/1" )

	PORT_START_TAG("DSW")
	PORT_DIPNAME( 0x01, 0x01, DEF_STR( Unknown ) )
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
INPUT_PORTS_END

static INPUT_PORTS_START( outrun )
	PORT_INCLUDE( outrun_generic )

	PORT_MODIFY("SERVICE")
	PORT_BIT( 0x10, IP_ACTIVE_HIGH, IPT_BUTTON1 ) PORT_TOGGLE PORT_CODE(KEYCODE_SPACE)

	PORT_MODIFY("DSW")
	PORT_DIPNAME( 0x03, 0x02, DEF_STR( Cabinet ) )
	PORT_DIPSETTING(    0x02, "Up Cockpit" )
	PORT_DIPSETTING(    0x01, "Mini Up" )
	PORT_DIPSETTING(    0x03, "Moving" )
//  PORT_DIPSETTING(    0x00, "No Use" )
	PORT_DIPNAME( 0x04, 0x00, DEF_STR( Demo_Sounds ) )
	PORT_DIPSETTING(    0x04, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x30, 0x30, "Time" )
	PORT_DIPSETTING(    0x20, DEF_STR( Easy ) )
	PORT_DIPSETTING(    0x30, DEF_STR( Normal ) )
	PORT_DIPSETTING(    0x10, DEF_STR( Hard ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Hardest ) )
	PORT_DIPNAME( 0xc0, 0xc0, "Enemies" )
	PORT_DIPSETTING(    0x80, DEF_STR( Easy ) )
	PORT_DIPSETTING(    0xc0, DEF_STR( Normal ) )
	PORT_DIPSETTING(    0x40, DEF_STR( Hard ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Hardest ) )

	PORT_START_TAG("ADC0")	/* steering */
	PORT_BIT( 0xff, 0x7f, IPT_PADDLE ) PORT_MINMAX(0x01,0xff) PORT_SENSITIVITY(100) PORT_KEYDELTA(4)

	PORT_START_TAG("ADC1")	/* gas pedal */
	PORT_BIT( 0xff, 0x00, IPT_PEDAL ) PORT_MINMAX(0x00,0xff) PORT_SENSITIVITY(100) PORT_KEYDELTA(20)

	PORT_START_TAG("ADC2")	/* brake */
	PORT_BIT( 0xff, 0x00, IPT_PEDAL2 ) PORT_MINMAX(0x00,0xff) PORT_SENSITIVITY(100) PORT_KEYDELTA(40)
INPUT_PORTS_END


static INPUT_PORTS_START( outrundx )
	PORT_INCLUDE( outrun )

	PORT_MODIFY("DSW")
	PORT_DIPNAME( 0x01, 0x00, DEF_STR( Cabinet ) )
	PORT_DIPSETTING(    0x00, "Not Moving" )
	PORT_DIPSETTING(    0x01, "Moving" )
	PORT_DIPNAME( 0x02, 0x00, DEF_STR( Demo_Sounds ) )
	PORT_DIPSETTING(    0x02, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x30, 0x30, "Time" )
	PORT_DIPSETTING(    0x20, DEF_STR( Easy ) )
	PORT_DIPSETTING(    0x30, DEF_STR( Normal ) )
	PORT_DIPSETTING(    0x10, DEF_STR( Hard ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Hardest ) )
	PORT_DIPNAME( 0xc0, 0xc0, "Enemies" )
	PORT_DIPSETTING(    0x80, DEF_STR( Easy ) )
	PORT_DIPSETTING(    0xc0, DEF_STR( Normal ) )
	PORT_DIPSETTING(    0x40, DEF_STR( Hard ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Hardest ) )

	PORT_START_TAG("ADC0")	/* steering */
	PORT_BIT( 0xff, 0x7f, IPT_PADDLE ) PORT_MINMAX(0x01,0xff) PORT_SENSITIVITY(100) PORT_KEYDELTA(4)

	PORT_START_TAG("ADC1")	/* gas pedal */
	PORT_BIT( 0xff, 0x00, IPT_PEDAL ) PORT_MINMAX(0x00,0xff) PORT_SENSITIVITY(100) PORT_KEYDELTA(20)

	PORT_START_TAG("ADC2")	/* brake */
	PORT_BIT( 0xff, 0x00, IPT_PEDAL2 ) PORT_MINMAX(0x00,0xff) PORT_SENSITIVITY(100) PORT_KEYDELTA(40)
INPUT_PORTS_END


static INPUT_PORTS_START( toutrun )
	PORT_INCLUDE( outrun_generic )

	PORT_MODIFY("SERVICE")
	PORT_BIT( 0x10, IP_ACTIVE_HIGH, IPT_BUTTON1 ) PORT_TOGGLE PORT_CODE(KEYCODE_SPACE)
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_BUTTON2 ) PORT_CODE(KEYCODE_LSHIFT)

	PORT_MODIFY("DSW")
	PORT_DIPNAME( 0x03, 0x02, DEF_STR( Cabinet ) )
	PORT_DIPSETTING(    0x02, "Cockpit Conversion" )
	PORT_DIPSETTING(    0x01, "Mini Up" )
	PORT_DIPSETTING(    0x03, "Moving" )
	PORT_DIPSETTING(    0x00, "Cockpit" )
	PORT_DIPNAME( 0x04, 0x00, DEF_STR( Demo_Sounds ) )
	PORT_DIPSETTING(    0x04, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x08, 0x08, "Turbo" )
	PORT_DIPSETTING(    0x00, "Start Button" )
	PORT_DIPSETTING(    0x08, "Use Turbo Shifter" )
	PORT_DIPNAME( 0x30, 0x10, "Credits" )
	PORT_DIPSETTING(    0x20, "3 to Start/2 to Continue" )
	PORT_DIPSETTING(    0x30, "2 to Start/1 to Continue" )
	PORT_DIPSETTING(    0x10, "1 to Start/1 to Continue" )
	PORT_DIPSETTING(    0x00, "2 to Start/2 to Continue" )
	PORT_DIPNAME( 0xc0, 0xc0, DEF_STR( Difficulty ) )
	PORT_DIPSETTING(    0x80, DEF_STR( Easy ) )
	PORT_DIPSETTING(    0xc0, DEF_STR( Normal ) )
	PORT_DIPSETTING(    0x40, DEF_STR( Hard ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Hardest ) )

	PORT_START_TAG("ADC0")	/* steering */
	PORT_BIT( 0xff, 0x7f, IPT_PADDLE ) PORT_MINMAX(0x01,0xff) PORT_SENSITIVITY(100) PORT_KEYDELTA(4)

	PORT_START_TAG("ADC1")	/* gas pedal */
	PORT_BIT( 0xff, 0x00, IPT_PEDAL ) PORT_MINMAX(0x00,0xff) PORT_SENSITIVITY(100) PORT_KEYDELTA(20)

	PORT_START_TAG("ADC2")	/* brake */
	PORT_BIT( 0xff, 0x00, IPT_PEDAL2 ) PORT_MINMAX(0x00,0xff) PORT_SENSITIVITY(100) PORT_KEYDELTA(40)
INPUT_PORTS_END


static INPUT_PORTS_START( shangon )
	PORT_INCLUDE( outrun_generic )

	PORT_MODIFY("SERVICE")
	PORT_BIT( 0xff, IP_ACTIVE_LOW, IPT_UNKNOWN )

	PORT_MODIFY("UNKNOWN")
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_COIN1 )
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_COIN2 )
	PORT_SERVICE_NO_TOGGLE( 0x04, IP_ACTIVE_LOW )
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_SERVICE1 )
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_START1 )
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_BUTTON3 )	/* S.C. SW? */
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_UNUSED )

	PORT_MODIFY("DSW")
	PORT_DIPNAME( 0x01, 0x00, DEF_STR( Demo_Sounds ) )
	PORT_DIPSETTING(    0x01, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x06, 0x06, "Time" )
	PORT_DIPSETTING(    0x04, DEF_STR( Easy ) )
	PORT_DIPSETTING(    0x06, DEF_STR( Normal ) )
	PORT_DIPSETTING(    0x02, DEF_STR( Hard ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Hardest ) )
	PORT_DIPNAME( 0x18, 0x18, "Enemies" )
	PORT_DIPSETTING(    0x10, DEF_STR( Easy ) )
	PORT_DIPSETTING(    0x18, DEF_STR( Normal ) )
	PORT_DIPSETTING(    0x08, DEF_STR( Hard ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Hardest ) )

	PORT_START_TAG("ADC0")	/* steering */
	PORT_BIT( 0xff, 0x7f, IPT_PADDLE ) PORT_MINMAX(0x01,0xff) PORT_SENSITIVITY(100) PORT_KEYDELTA(4) PORT_REVERSE

	PORT_START_TAG("ADC1")	/* gas pedal */
	PORT_BIT( 0xff, 0x00, IPT_PEDAL ) PORT_MINMAX(0x00,0xff) PORT_SENSITIVITY(100) PORT_KEYDELTA(20)

	PORT_START_TAG("ADC2")	/* brake */
	PORT_BIT( 0xff, 0x00, IPT_PEDAL2 ) PORT_MINMAX(0x00,0xff) PORT_SENSITIVITY(100) PORT_KEYDELTA(40)
INPUT_PORTS_END


GAME( 1986, outrun,   0,        outrun,  outrun,   outrun,   ROT0, "Sega",    "Out Run (set 3)", 0 )
GAME( 1986, outrun2,  outrun,   outrun,  outrun,   outrun,   ROT0, "Sega",    "Out Run (set 2)", 0 )
GAME( 1986, outrun1,  outrun,   outrun,  outrundx, outrun,   ROT0, "Sega",    "Out Run (set 1, Deluxe?)", 0 )
GAME( 1986, outrunb,  outrun,   outrun,  outrun,   outrunb,  ROT0, "bootleg", "Out Run (bootleg)", 0 )
GAME( 1987, shangon,  0,        shangon, shangon,  shangon,  ROT0, "Sega",    "Super Hang-On (set 4, 68000)", 0 )
GAME( 1987, shangon3, shangon,  shangon, shangon,  shangon3, ROT0, "Sega",    "Super Hang-On (set 3, FD1089B 317-0034)", 0 )
GAME( 1987, shangon2, shangon,  shangon, shangon,  shangon3, ROT0, "Sega",    "Super Hang-On (set 2, FD1089B 317-0034)", 0 )
GAME( 1987, shangon1, shangon,  shangon, shangon,  shangon3, ROT0, "Sega",    "Super Hang-On (set 1, FD1089B 317-0034)", 0 )
GAME( 1991, shangnle, shangon,  shangon, shangon,  shangon,  ROT0, "Sega",    "Limited Edition Hang-On", 0 )
GAME( 1989, toutrun,  0,        outrun,  toutrun,  outrun,   ROT0, "Sega",    "Turbo Out Run (set 3, upgrade kit, FD1094 317-0118)" , 0 )
GAME( 1989, toutrun2, toutrun,  outrun,  toutrun,  outrun,   ROT0, "Sega",    "Turbo Out Run (set 2, upright, FD1094 317-unknown)", 0 )
GAME( 1989, toutrun1, toutrun,  outrun,  toutrun,  outrun,   ROT0, "Sega",    "Turbo Out Run (set 1, FD1094 317-unknown)", GAME_NOT_WORKING ) // not decrypted
