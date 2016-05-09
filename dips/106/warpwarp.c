INPUT_PORTS_START( geebee )
	PORT_START_TAG("SW0")
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_COIN1   )
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_COIN2   )
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_START1  )
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_START2  )
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_BUTTON1 )
	PORT_SERVICE( 0x20, IP_ACTIVE_LOW )
	PORT_BIT( 0xc0, IP_ACTIVE_LOW, IPT_UNUSED )

	PORT_START_TAG("SW1")
	PORT_BIT( 0xff, IP_ACTIVE_LOW, IPT_UNUSED )

	PORT_START_TAG("DSW2")
	PORT_DIPNAME( 0x01, 0x00, DEF_STR( Cabinet ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Upright ) )
	PORT_DIPSETTING(    0x01, DEF_STR( Cocktail) )
	PORT_DIPNAME( 0x32, 0x10, "Lives/Bonus Life" )
	PORT_DIPSETTING(    0x10, "3/40k 80k" )
	PORT_DIPSETTING(    0x20, "3/70k 140k" )
	PORT_DIPSETTING(    0x30, "3/100k 200k" )
	PORT_DIPSETTING(    0x00, "3/None" )
	PORT_DIPSETTING(    0x12, "5/60k 120k" )
	PORT_DIPSETTING(    0x22, "5/100k 200k" )
	PORT_DIPSETTING(    0x32, "5/150k 300k" )
	PORT_DIPSETTING(    0x02, "5/None" )
	PORT_DIPNAME( 0x0c, 0x00, DEF_STR( Coinage ) )
	PORT_DIPSETTING(    0x08, DEF_STR( 2C_1C ) )
	PORT_DIPSETTING(    0x00, DEF_STR( 1C_1C ) )
	PORT_DIPSETTING(    0x04, DEF_STR( 1C_2C ) )
	PORT_DIPSETTING(    0x0c, DEF_STR( Free_Play ) )
	PORT_BIT( 0xc0, IP_ACTIVE_LOW, IPT_UNUSED )

	PORT_START_TAG("VOLIN")
	PORT_BIT( 0xff, 0x58, IPT_PADDLE ) PORT_MINMAX(0x10,0xa0) PORT_SENSITIVITY(30) PORT_KEYDELTA(15) PORT_CENTERDELTA(0) PORT_REVERSE

	PORT_START_TAG("VOLINC") //Cocktail
	PORT_BIT( 0xff, 0x58, IPT_PADDLE ) PORT_MINMAX(0x10,0xa0) PORT_SENSITIVITY(30) PORT_KEYDELTA(15) PORT_CENTERDELTA(0) PORT_REVERSE PORT_COCKTAIL
INPUT_PORTS_END

INPUT_PORTS_START( navarone )
	PORT_START_TAG("SW0")
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_COIN1   )
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_COCKTAIL
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_START1  )
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_START2  )
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_BUTTON1 )
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_SERVICE1 )
	PORT_BIT( 0xc0, IP_ACTIVE_LOW, IPT_UNUSED )

	PORT_START_TAG("SW1")
	PORT_BIT( 0xff, IP_ACTIVE_LOW, IPT_UNUSED )

	PORT_START_TAG("DSW2")
	PORT_DIPNAME( 0x01, 0x00, DEF_STR( Cabinet ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Upright ) )
	PORT_DIPSETTING(    0x01, DEF_STR( Cocktail) )
	PORT_DIPNAME( 0x0e, 0x06, "Lives/Bonus Life" )
	PORT_DIPSETTING(	0x04, "2/5000" )
	PORT_DIPSETTING(	0x08, "2/6000" )
	PORT_DIPSETTING(	0x0c, "2/7000" )
	PORT_DIPSETTING(	0x00, "2/None" )
	PORT_DIPSETTING(	0x06, "3/6000" )
	PORT_DIPSETTING(	0x0a, "3/7000" )
	PORT_DIPSETTING(	0x0e, "3/8000" )
	PORT_DIPSETTING(	0x02, "3/None" )
	PORT_DIPNAME( 0x30, 0x10, DEF_STR( Coinage ) )
	PORT_DIPSETTING(	0x30, DEF_STR( 2C_1C ) )
	PORT_DIPSETTING(    0x10, DEF_STR( 1C_1C ) )
	PORT_DIPSETTING(	0x20, DEF_STR( 1C_2C ) )
	PORT_DIPSETTING(	0x00, DEF_STR( Free_Play ) )
	PORT_BIT( 0xc0, IP_ACTIVE_LOW, IPT_UNUSED )

	PORT_START_TAG("FAKE1")	/* Fake input port to support digital joystick */
	PORT_BIT( 0x01, 0x00, IPT_JOYSTICK_RIGHT )
	PORT_BIT( 0x02, 0x00, IPT_JOYSTICK_LEFT )

	PORT_START_TAG("FAKE2")	/* Fake input port to support digital joystick */
	PORT_BIT( 0x01, 0x00, IPT_JOYSTICK_RIGHT ) PORT_COCKTAIL
	PORT_BIT( 0x02, 0x00, IPT_JOYSTICK_LEFT ) PORT_COCKTAIL
INPUT_PORTS_END

INPUT_PORTS_START( kaitei )
	PORT_START_TAG("SW0")
	PORT_BIT( 0x01, IP_ACTIVE_LOW,	IPT_COIN1 )
	PORT_BIT( 0x02, IP_ACTIVE_LOW,	IPT_BUTTON1 ) PORT_COCKTAIL
	PORT_BIT( 0x04, IP_ACTIVE_LOW,	IPT_START1 )
	PORT_BIT( 0x08, IP_ACTIVE_LOW,	IPT_START2 )
	PORT_BIT( 0x10, IP_ACTIVE_LOW,	IPT_BUTTON1 )
	PORT_BIT( 0x20, IP_ACTIVE_LOW,	IPT_SERVICE1 )
	PORT_BIT( 0xc0, IP_ACTIVE_LOW,	IPT_UNUSED )

	PORT_START_TAG("SW1")
	PORT_BIT( 0xff, IP_ACTIVE_LOW,	IPT_UNUSED )

	PORT_START_TAG("DSW2")
	PORT_DIPNAME( 0x03, 0x01, DEF_STR( Lives ) )
	PORT_DIPSETTING(	0x00, "2" )
	PORT_DIPSETTING(	0x01, "3" )
	PORT_DIPSETTING(	0x02, "4" )
	PORT_DIPSETTING(	0x03, "5" )
	PORT_DIPNAME( 0x0c, 0x04, DEF_STR( Bonus_Life ) )
	PORT_DIPSETTING(    0x04, "2000" )
	PORT_DIPSETTING(    0x08, "4000" )
	PORT_DIPSETTING(    0x0c, "6000" )
	PORT_DIPSETTING(    0x00, DEF_STR( None ) )
	PORT_DIPNAME( 0x30, 0x10, DEF_STR( Coinage ) )
	PORT_DIPSETTING(	0x30, DEF_STR( 2C_1C ) )
	PORT_DIPSETTING(    0x10, DEF_STR( 1C_1C ) )
	PORT_DIPSETTING(	0x20, DEF_STR( 1C_2C ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Free_Play ) )
	PORT_BIT( 0xc0, IP_ACTIVE_LOW,	IPT_UNUSED )

	PORT_START_TAG("FAKE1")	/* Fake input port to support digital joystick */
	PORT_BIT( 0x01, 0x00, IPT_JOYSTICK_RIGHT )
	PORT_BIT( 0x02, 0x00, IPT_JOYSTICK_LEFT )

	PORT_START_TAG("FAKE")	/* Fake input port to support digital joystick */
	PORT_BIT( 0x01, 0x00, IPT_JOYSTICK_RIGHT ) PORT_COCKTAIL
	PORT_BIT( 0x02, 0x00, IPT_JOYSTICK_LEFT ) PORT_COCKTAIL
INPUT_PORTS_END

INPUT_PORTS_START( kaiteik )
	PORT_START_TAG("SW0")
	PORT_BIT( 0x01, IP_ACTIVE_LOW,	IPT_COIN1 )
	PORT_BIT( 0x04, IP_ACTIVE_LOW,	IPT_START1 )
	PORT_BIT( 0x08, IP_ACTIVE_LOW,	IPT_START2 )
	PORT_BIT( 0xf2, 0xa0, IPT_UNKNOWN )	// game verifies these bits and freezes if they don't match

	PORT_START_TAG("SW1")
	PORT_BIT( 0x01, IP_ACTIVE_LOW,	IPT_JOYSTICK_RIGHT )
	PORT_BIT( 0x02, IP_ACTIVE_LOW,	IPT_JOYSTICK_LEFT )
	PORT_BIT( 0x04, IP_ACTIVE_LOW,	IPT_BUTTON1 )
	PORT_BIT( 0x08, IP_ACTIVE_LOW,	IPT_JOYSTICK_RIGHT ) PORT_COCKTAIL
	PORT_BIT( 0x10, IP_ACTIVE_LOW,	IPT_JOYSTICK_LEFT ) PORT_COCKTAIL
	PORT_BIT( 0x20, IP_ACTIVE_LOW,	IPT_BUTTON1 ) PORT_COCKTAIL
	PORT_BIT( 0xc0, 0x80, IPT_UNKNOWN )	// game verifies these two bits and freezes if they don't match

	PORT_START_TAG("DSW2")
	PORT_DIPNAME( 0x01, 0x01, DEF_STR( Cabinet ) )
	PORT_DIPSETTING(	0x01, DEF_STR( Upright ) )
	PORT_DIPSETTING(	0x00, DEF_STR( Cocktail ) )
	PORT_DIPNAME( 0x06, 0x06, DEF_STR( Lives ) )
	PORT_DIPSETTING(	0x06, "4" )
	PORT_DIPSETTING(    0x04, "5" )
	PORT_DIPSETTING(	0x02, "6" )
	PORT_DIPSETTING(    0x00, "7" )
	PORT_DIPNAME( 0x18, 0x18, DEF_STR( Bonus_Life ) )
	PORT_DIPSETTING(    0x18, "4000" )
	PORT_DIPSETTING(    0x10, "6000" )
	PORT_DIPSETTING(    0x08, "8000" )
	PORT_DIPSETTING(    0x00, "10000" )
	PORT_DIPNAME( 0x20, 0x00, DEF_STR( Unused ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Off ) )
	PORT_DIPSETTING(	0x20, DEF_STR( On ) )
	PORT_BIT( 0xc0, 0x80, IPT_UNKNOWN )	// game verifies these two bits and freezes if they don't match

	PORT_START_TAG("VOLIN1")
	PORT_BIT( 0x3f, 0x00, IPT_UNKNOWN )
	PORT_BIT( 0xc0, 0x80, IPT_UNKNOWN )	// game verifies these two bits and freezes if they don't match

	PORT_START_TAG("VOLIN2")
	PORT_BIT( 0x3f, 0x00, IPT_UNKNOWN )
	PORT_BIT( 0xc0, 0x80, IPT_UNKNOWN )	// game verifies these two bits and freezes if they don't match
INPUT_PORTS_END

INPUT_PORTS_START( sos )
	PORT_START_TAG("SW0")
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_COIN1   )
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_COCKTAIL
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_START1  )
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_START2  )
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_BUTTON1 )
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_SERVICE1   )
	PORT_BIT( 0xc0, IP_ACTIVE_LOW, IPT_UNUSED )

	PORT_START_TAG("SW1")
	PORT_BIT( 0xff, IP_ACTIVE_LOW, IPT_UNUSED )

	PORT_START_TAG("DSW2")
	PORT_DIPNAME( 0x01, 0x00, DEF_STR( Cabinet ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Upright ) )
	PORT_DIPSETTING(    0x01, DEF_STR( Cocktail) )
	PORT_DIPNAME( 0x06, 0x02, DEF_STR( Lives ) )
	PORT_DIPSETTING(    0x00, "2" )
	PORT_DIPSETTING(    0x02, "3" )
	PORT_DIPSETTING(    0x04, "4" )
	PORT_DIPSETTING(    0x06, "5" )
	PORT_DIPNAME( 0x18, 0x08, DEF_STR( Coinage ) )
	PORT_DIPSETTING(	0x18, DEF_STR( 2C_1C ) )
	PORT_DIPSETTING(    0x08, DEF_STR( 1C_1C ) )
	PORT_DIPSETTING(	0x10, DEF_STR( 1C_2C ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Free_Play ) )
	PORT_DIPNAME( 0x20, 0x20, "Nudity" )
	PORT_DIPSETTING(    0x00, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x20, DEF_STR( On ) )
	PORT_BIT( 0xc0, IP_ACTIVE_LOW, IPT_UNUSED )

	PORT_START_TAG("FAKE1")	/* Fake input port to support digital joystick */
	PORT_BIT( 0x01, 0x00, IPT_JOYSTICK_RIGHT )
	PORT_BIT( 0x02, 0x00, IPT_JOYSTICK_LEFT )

	PORT_START_TAG("FAKE2")	/* Fake input port to support digital joystick */
	PORT_BIT( 0x01, 0x00, IPT_JOYSTICK_RIGHT ) PORT_COCKTAIL
	PORT_BIT( 0x02, 0x00, IPT_JOYSTICK_LEFT ) PORT_COCKTAIL
INPUT_PORTS_END

INPUT_PORTS_START( bombbee )
	PORT_START_TAG("IN0")
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_COIN1 )
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_COIN2 )
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_START1 )
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_START2 )
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_BUTTON1 )
	PORT_SERVICE( 0x20, IP_ACTIVE_LOW )
	PORT_DIPNAME( 0x40, 0x40, DEF_STR( Cabinet ) )
	PORT_DIPSETTING(	0x40, DEF_STR( Upright ) )
	PORT_DIPSETTING(	0x00, DEF_STR( Cocktail ) )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_SERVICE1 )

	PORT_START_TAG("DSW1")
	PORT_DIPNAME( 0x03, 0x03, DEF_STR( Coinage ) )
	PORT_DIPSETTING(	0x02, DEF_STR( 2C_1C ) )
	PORT_DIPSETTING(	0x03, DEF_STR( 1C_1C ) )
	PORT_DIPSETTING(	0x01, DEF_STR( 1C_2C ) )
	PORT_DIPSETTING(	0x00, DEF_STR( Free_Play ) )
	PORT_DIPNAME( 0x0c, 0x00, DEF_STR( Lives ) )
	PORT_DIPSETTING(	0x00, "3" )
	PORT_DIPSETTING(	0x04, "4" )
//  PORT_DIPSETTING(    0x08, "4" )             // duplicated setting
	PORT_DIPSETTING(	0x0c, "5" )
	PORT_DIPNAME( 0x10, 0x00, DEF_STR( Unused ) )
	PORT_DIPSETTING(	0x10, DEF_STR( Off ) )
	PORT_DIPSETTING(	0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0xe0, 0x00, "Replay" )		// awards 1 credit
	PORT_DIPSETTING(	0x00, "50000" )
	PORT_DIPSETTING(	0x20, "60000" )
	PORT_DIPSETTING(	0x40, "70000" )
	PORT_DIPSETTING(	0x60, "80000" )
	PORT_DIPSETTING(	0x80, "100000" )
	PORT_DIPSETTING(	0xa0, "120000" )
	PORT_DIPSETTING(	0xc0, "150000" )
	PORT_DIPSETTING(	0xe0, DEF_STR( None ) )

	PORT_START_TAG("VOLIN1")	/* Mux input - player 1 controller - handled by warpwarp_vol_r */
	PORT_BIT( 0xff, 0x60, IPT_PADDLE ) PORT_MINMAX(0x14,0xac) PORT_SENSITIVITY(30) PORT_KEYDELTA(10) PORT_CENTERDELTA(0) PORT_REVERSE

	PORT_START_TAG("VOLIN2")	/* Mux input - player 2 controller - handled by warpwarp_vol_r */
	PORT_BIT( 0xff, 0x60, IPT_PADDLE ) PORT_MINMAX(0x14,0xac) PORT_SENSITIVITY(30) PORT_KEYDELTA(10) PORT_CENTERDELTA(0) PORT_REVERSE PORT_COCKTAIL
INPUT_PORTS_END

INPUT_PORTS_START( cutieq )
	PORT_START_TAG("IN0")
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_COIN1 )
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_COIN2 )
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_START1 )
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_START2 )
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_BUTTON1 )
	PORT_SERVICE( 0x20, IP_ACTIVE_LOW )
	PORT_DIPNAME( 0x40, 0x40, DEF_STR( Cabinet ) )
	PORT_DIPSETTING(	0x40, DEF_STR( Upright ) )
	PORT_DIPSETTING(	0x00, DEF_STR( Cocktail ) )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_SERVICE1 )

	PORT_START_TAG("DSW1")
	PORT_DIPNAME( 0x03, 0x03, DEF_STR( Coinage ) )
	PORT_DIPSETTING(	0x02, DEF_STR( 2C_1C ) )
	PORT_DIPSETTING(	0x03, DEF_STR( 1C_1C ) )
	PORT_DIPSETTING(	0x01, DEF_STR( 1C_2C ) )
	PORT_DIPSETTING(	0x00, DEF_STR( Free_Play ) )
	PORT_DIPNAME( 0x0c, 0x00, DEF_STR( Lives ) )
	PORT_DIPSETTING(	0x00, "3" )
	PORT_DIPSETTING(	0x04, "4" )
//  PORT_DIPSETTING(    0x08, "4" )             // duplicated setting
	PORT_DIPSETTING(	0x0c, "5" )
	PORT_DIPNAME( 0x10, 0x00, DEF_STR( Unused ) )
	PORT_DIPSETTING(	0x10, DEF_STR( Off ) )
	PORT_DIPSETTING(	0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0xe0, 0x00, DEF_STR( Bonus_Life ) )
	PORT_DIPSETTING(	0x00, "50000" )
	PORT_DIPSETTING(	0x20, "60000" )
	PORT_DIPSETTING(	0x40, "80000" )
	PORT_DIPSETTING(	0x60, "100000" )
	PORT_DIPSETTING(	0x80, "120000" )
	PORT_DIPSETTING(	0xa0, "150000" )
	PORT_DIPSETTING(	0xc0, "200000" )
	PORT_DIPSETTING(	0xe0, DEF_STR( None ) )

	PORT_START_TAG("VOLIN1")	/* Mux input - player 1 controller - handled by warpwarp_vol_r */
	PORT_BIT( 0xff, 0x60, IPT_PADDLE ) PORT_MINMAX(0x14,0xac) PORT_SENSITIVITY(30) PORT_KEYDELTA(10) PORT_CENTERDELTA(0) PORT_REVERSE

	PORT_START_TAG("VOLIN2")	/* Mux input - player 2 controller - handled by warpwarp_vol_r */
	PORT_BIT( 0xff, 0x60, IPT_PADDLE ) PORT_MINMAX(0x14,0xac) PORT_SENSITIVITY(30) PORT_KEYDELTA(10) PORT_CENTERDELTA(0) PORT_REVERSE PORT_COCKTAIL
INPUT_PORTS_END

INPUT_PORTS_START( warpwarp )
	PORT_START_TAG("IN0")
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_COIN1 )
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_COCKTAIL
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_START1 )
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_START2 )
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_BUTTON1 )
	PORT_SERVICE( 0x20, IP_ACTIVE_LOW )
	PORT_DIPNAME( 0x40, 0x40, DEF_STR( Cabinet ) )
	PORT_DIPSETTING(	0x40, DEF_STR( Upright ) )
	PORT_DIPSETTING(	0x00, DEF_STR( Cocktail ) )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_SERVICE1 )

	PORT_START_TAG("DSW1")
	PORT_DIPNAME( 0x03, 0x01, DEF_STR( Coinage ) )
	PORT_DIPSETTING(	0x03, DEF_STR( 2C_1C ) )
	PORT_DIPSETTING(	0x01, DEF_STR( 1C_1C ) )
	PORT_DIPSETTING(	0x02, DEF_STR( 1C_2C ) )
	PORT_DIPSETTING(	0x00, DEF_STR( Free_Play ) )
	PORT_DIPNAME( 0x0c, 0x04, DEF_STR( Lives ) )
	PORT_DIPSETTING(	0x00, "2" )
	PORT_DIPSETTING(	0x04, "3" )
	PORT_DIPSETTING(	0x08, "4" )
	PORT_DIPSETTING(	0x0c, "5" )
	/* Bonus Lives when "Lives" Dip Switch is set to "2", "3" or "4" */
	PORT_DIPNAME( 0x30, 0x00, DEF_STR( Bonus_Life ) )
	PORT_DIPSETTING(	0x00, "8000 30000" )
	PORT_DIPSETTING(	0x10, "10000 40000" )
	PORT_DIPSETTING(	0x20, "15000 60000" )
	PORT_DIPSETTING(	0x30, DEF_STR( None ) )
	/* Bonus Lives when "Lives" Dip Switch is set to "5"
    PORT_DIPNAME( 0x30, 0x00, DEF_STR( Bonus_Life ) )
    PORT_DIPSETTING(    0x00, "30000" )
    PORT_DIPSETTING(    0x10, "40000" )
    PORT_DIPSETTING(    0x20, "60000" )
    PORT_DIPSETTING(    0x30, DEF_STR( None ) )
    */
	PORT_DIPNAME( 0x40, 0x00, DEF_STR( Demo_Sounds ) )
	PORT_DIPSETTING(	0x40, DEF_STR( Off ) )
	PORT_DIPSETTING(	0x00, DEF_STR( On ) )
	/* when level selection is On, press 1 to increase level */
	PORT_DIPNAME( 0x80, 0x80, "Level Selection (Cheat)")
	PORT_DIPSETTING(	0x80, DEF_STR( Off ) )
	PORT_DIPSETTING(	0x00, DEF_STR( On ) )

	PORT_START_TAG("VOLIN1")	/* FAKE - input port to simulate an analog stick - handled by warpwarp_vol_r */
	PORT_BIT( 0x01, IP_ACTIVE_HIGH, IPT_JOYSTICK_DOWN ) PORT_4WAY
	PORT_BIT( 0x02, IP_ACTIVE_HIGH, IPT_JOYSTICK_UP ) PORT_4WAY
	PORT_BIT( 0x04, IP_ACTIVE_HIGH, IPT_JOYSTICK_LEFT ) PORT_4WAY
	PORT_BIT( 0x08, IP_ACTIVE_HIGH, IPT_JOYSTICK_RIGHT ) PORT_4WAY

	PORT_START_TAG("VOLIN2")	/* FAKE - input port to simulate an analog stick - handled by warpwarp_vol_r */
	PORT_BIT( 0x01, IP_ACTIVE_HIGH, IPT_JOYSTICK_DOWN ) PORT_4WAY PORT_COCKTAIL
	PORT_BIT( 0x02, IP_ACTIVE_HIGH, IPT_JOYSTICK_UP ) PORT_4WAY PORT_COCKTAIL
	PORT_BIT( 0x04, IP_ACTIVE_HIGH, IPT_JOYSTICK_LEFT ) PORT_4WAY PORT_COCKTAIL
	PORT_BIT( 0x08, IP_ACTIVE_HIGH, IPT_JOYSTICK_RIGHT ) PORT_4WAY PORT_COCKTAIL
INPUT_PORTS_END

/* has High Score Initials dip switch instead of rack test */
INPUT_PORTS_START( warpwarr )
	PORT_START_TAG("IN0")
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_COIN1 )
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_COCKTAIL
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_START1 )
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_START2 )
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_BUTTON1 )
	PORT_SERVICE( 0x20, IP_ACTIVE_LOW )
	PORT_DIPNAME( 0x40, 0x40, DEF_STR( Cabinet ) )
	PORT_DIPSETTING(	0x40, DEF_STR( Upright ) )
	PORT_DIPSETTING(	0x00, DEF_STR( Cocktail ) )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_SERVICE1 )

	PORT_START_TAG("DSW1")
	PORT_DIPNAME( 0x03, 0x01, DEF_STR( Coinage ) )
	PORT_DIPSETTING(	0x03, DEF_STR( 2C_1C ) )
	PORT_DIPSETTING(	0x01, DEF_STR( 1C_1C ) )
	PORT_DIPSETTING(	0x02, DEF_STR( 1C_2C ) )
	PORT_DIPSETTING(	0x00, DEF_STR( Free_Play ) )
	PORT_DIPNAME( 0x0c, 0x04, DEF_STR( Lives ) )
	PORT_DIPSETTING(	0x00, "2" )
	PORT_DIPSETTING(	0x04, "3" )
	PORT_DIPSETTING(	0x08, "4" )
	PORT_DIPSETTING(	0x0c, "5" )
	/* Bonus Lives when "Lives" Dip Switch is set to "2", "3" or "4" */
	PORT_DIPNAME( 0x30, 0x00, DEF_STR( Bonus_Life ) )
	PORT_DIPSETTING(	0x00, "8000 30000" )
	PORT_DIPSETTING(	0x10, "10000 40000" )
	PORT_DIPSETTING(	0x20, "15000 60000" )
	PORT_DIPSETTING(	0x30, DEF_STR( None ) )
	/* Bonus Lives when "Lives" Dip Switch is set to "5"
    PORT_DIPNAME( 0x30, 0x00, DEF_STR( Bonus_Life ) )
    PORT_DIPSETTING(    0x00, "30000" )
    PORT_DIPSETTING(    0x10, "40000" )
    PORT_DIPSETTING(    0x20, "60000" )
    PORT_DIPSETTING(    0x30, DEF_STR( None ) )
    */
	PORT_DIPNAME( 0x40, 0x00, DEF_STR( Demo_Sounds ) )
	PORT_DIPSETTING(	0x40, DEF_STR( Off ) )
	PORT_DIPSETTING(	0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x80, 0x00, "High Score Initials" )
	PORT_DIPSETTING(	0x80, DEF_STR( No ) )
	PORT_DIPSETTING(	0x00, DEF_STR( Yes ) )

	PORT_START_TAG("VOLIN1")	/* FAKE - input port to simulate an analog stick - handled by warpwarp_vol_r */
	PORT_BIT( 0x01, IP_ACTIVE_HIGH, IPT_JOYSTICK_DOWN ) PORT_4WAY
	PORT_BIT( 0x02, IP_ACTIVE_HIGH, IPT_JOYSTICK_UP ) PORT_4WAY
	PORT_BIT( 0x04, IP_ACTIVE_HIGH, IPT_JOYSTICK_LEFT ) PORT_4WAY
	PORT_BIT( 0x08, IP_ACTIVE_HIGH, IPT_JOYSTICK_RIGHT ) PORT_4WAY

	PORT_START_TAG("VOLIN2")	/* FAKE - input port to simulate an analog stick - handled by warpwarp_vol_r */
	PORT_BIT( 0x01, IP_ACTIVE_HIGH, IPT_JOYSTICK_DOWN ) PORT_4WAY PORT_COCKTAIL
	PORT_BIT( 0x02, IP_ACTIVE_HIGH, IPT_JOYSTICK_UP ) PORT_4WAY PORT_COCKTAIL
	PORT_BIT( 0x04, IP_ACTIVE_HIGH, IPT_JOYSTICK_LEFT ) PORT_4WAY PORT_COCKTAIL
	PORT_BIT( 0x08, IP_ACTIVE_HIGH, IPT_JOYSTICK_RIGHT ) PORT_4WAY PORT_COCKTAIL
INPUT_PORTS_END


/* B & W games */
GAME( 1978, geebee,   0,        geebee,   geebee,   geebee,   ROT90, "Namco", "Gee Bee", 0 )
GAME( 1978, geebeeg,  geebee,   geebee,   geebee,   geebee,   ROT90, "[Namco] (Gremlin license)", "Gee Bee (Gremlin)", 0 )
GAME( 1980, navarone, 0,        navarone, navarone, navarone, ROT90, "Namco", "Navarone", GAME_IMPERFECT_SOUND )
GAME( 1980, kaitei,   0,        navarone, kaitei,   kaitei,   ROT90, "Namco", "Kaitei Takara Sagashi", 0 )
GAME( 1980, kaiteik,  kaitei,   navarone, kaiteik,  kaiteik,  ROT90, "K.K. Tokki", "Kaitei Takara Sagashi (K'K-Tokki)", 0 )
GAME( 1980, sos,      0,        navarone, sos,      sos,      ROT90, "Namco", "SOS", GAME_IMPERFECT_SOUND )

/* Color games */
GAME( 1979, bombbee,  0,        bombbee,  bombbee,  bombbee,  ROT90, "Namco", "Bomb Bee", 0 )
GAME( 1979, cutieq,   0,        bombbee,  cutieq,   bombbee,  ROT90, "Namco", "Cutie Q", 0 )
GAME( 1981, warpwarp, 0,        warpwarp, warpwarp, warpwarp, ROT90, "Namco", "Warp & Warp", 0 )
GAME( 1981, warpwarr, warpwarp, warpwarp, warpwarr, warpwarp, ROT90, "[Namco] (Rock-ola license)", "Warp Warp (Rock-ola set 1)", 0 )
GAME( 1981, warpwar2, warpwarp, warpwarp, warpwarr, warpwarp, ROT90, "[Namco] (Rock-ola license)", "Warp Warp (Rock-ola set 2)", 0 )