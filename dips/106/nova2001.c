INPUT_PORTS_START( nova2001 )
    PORT_START
    PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_JOYSTICK_UP ) PORT_8WAY
    PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN ) PORT_8WAY
    PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT ) PORT_8WAY
    PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT ) PORT_8WAY
    PORT_BIT( 0x30, IP_ACTIVE_LOW, IPT_UNUSED )
    PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_BUTTON2 )	// pause
    PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_BUTTON1 )	// fire

    PORT_START
    PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_JOYSTICK_UP ) PORT_8WAY PORT_COCKTAIL
    PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN ) PORT_8WAY PORT_COCKTAIL
    PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT ) PORT_8WAY PORT_COCKTAIL
    PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT ) PORT_8WAY PORT_COCKTAIL
    PORT_BIT( 0x30, IP_ACTIVE_LOW, IPT_UNUSED )
    PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_BUTTON2 ) PORT_COCKTAIL
    PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_COCKTAIL

    PORT_START
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_COIN1 ) PORT_IMPULSE(4)
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_START1 )
    PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_START2 )
    PORT_BIT( 0x78, IP_ACTIVE_LOW, IPT_UNUSED )
    PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_VBLANK )

    PORT_START  /* dsw0 */
    PORT_DIPNAME( 0x01, 0x00, DEF_STR( Cabinet ) )
    PORT_DIPSETTING(    0x00, DEF_STR( Upright ) )
    PORT_DIPSETTING(    0x01, DEF_STR( Cocktail ) )
    PORT_DIPNAME( 0x02, 0x02, DEF_STR( Lives ) )
    PORT_DIPSETTING(    0x02, "3" )
    PORT_DIPSETTING(    0x00, "4" )
    PORT_DIPNAME( 0x04, 0x04, "1st Bonus Life" )
    PORT_DIPSETTING(    0x04, "20K" )
    PORT_DIPSETTING(    0x00, "30K" )
    PORT_DIPNAME( 0x18, 0x18, "Extra Bonus Life" )
    PORT_DIPSETTING(    0x18, "60K" )
    PORT_DIPSETTING(    0x10, "70K" )
    PORT_DIPSETTING(    0x08, "90K" )
    PORT_DIPSETTING(    0x00, DEF_STR( None ) )
    PORT_DIPNAME( 0x60, 0x60, DEF_STR( Coinage ) )
    PORT_DIPSETTING(    0x40, DEF_STR( 2C_1C ) )
    PORT_DIPSETTING(    0x00, DEF_STR( 2C_2C ) )
    PORT_DIPSETTING(    0x60, DEF_STR( 1C_1C ) )
    PORT_DIPSETTING(    0x20, DEF_STR( 1C_2C ) )
    PORT_DIPNAME( 0x80, 0x80, DEF_STR( Free_Play ) )
    PORT_DIPSETTING(    0x80, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )

    PORT_START  /* dsw1 */
    PORT_DIPNAME( 0x03, 0x00, DEF_STR( Difficulty ) )
    PORT_DIPSETTING(    0x00, DEF_STR( Easy ) )
    PORT_DIPSETTING(    0x03, DEF_STR( Medium ) )
    PORT_DIPSETTING(    0x02, DEF_STR( Hard ) )
    PORT_DIPSETTING(    0x01, DEF_STR( Hardest ) )
    PORT_DIPNAME( 0x04, 0x00, DEF_STR( Demo_Sounds ) )
    PORT_DIPSETTING(    0x04, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x08, 0x08, "High Score Names" )
	PORT_DIPSETTING(    0x00, "3 Letters" )
	PORT_DIPSETTING(    0x08, "8 Letters" )
    PORT_BIT( 0x70, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_SERVICE( 0x80, IP_ACTIVE_LOW )
INPUT_PORTS_END



GAME( 1983, nova2001, 0,        nova2001, nova2001, 0, ROT0, "UPL", "Nova 2001 (Japan)", 0 )
GAME( 1983, nov2001u, nova2001, nova2001, nova2001, 0, ROT0, "UPL (Universal license)", "Nova 2001 (US)", 0 )
