INPUT_PORTS_START( yard )
	PORT_START_TAG("IN0")
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_START1 )
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_START2 )
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_SERVICE1 ) PORT_IMPULSE(19) // coin input must be active for 19 frames to be consistently recognized
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_COIN1 )
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_UNKNOWN )

	PORT_START_TAG("IN1")
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT ) PORT_8WAY
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT  ) PORT_8WAY
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN  ) PORT_8WAY
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_JOYSTICK_UP    ) PORT_8WAY
	PORT_BIT( 0x10, IP_ACTIVE_HIGH, IPT_UNKNOWN )
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_BUTTON1 )
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_BUTTON2 )

	PORT_START_TAG("IN2")
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT ) PORT_8WAY PORT_COCKTAIL
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT  ) PORT_8WAY PORT_COCKTAIL
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN  ) PORT_8WAY PORT_COCKTAIL
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_JOYSTICK_UP    ) PORT_8WAY PORT_COCKTAIL
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_COIN2 )
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_COCKTAIL
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_BUTTON2 ) PORT_COCKTAIL

	PORT_START_TAG("DSW1")
	PORT_DIPNAME( 0x01, 0x00, DEF_STR( Allow_Continue ) )
	PORT_DIPSETTING(	0x01, DEF_STR( Off ) )
	PORT_DIPSETTING(	0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x02, 0x02, "Defensive Man Pause" )
	PORT_DIPSETTING(	0x02, DEF_STR( Off ) )
	PORT_DIPSETTING(	0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x0c, 0x0c, "Time Reduced by Ball Dead" )
	PORT_DIPSETTING(    0x0c, DEF_STR( Normal ) )
	PORT_DIPSETTING(    0x08, "x1.3" )
	PORT_DIPSETTING(    0x04, "x1.5" )
	PORT_DIPSETTING(    0x00, "x1.8" )
    // coin mode 1
    PORT_DIPNAME( 0xf0, 0xf0, DEF_STR( Coinage ) )      PORT_CONDITION("DSW2", 0x04, PORTCOND_NOTEQUALS, 0x00)
    PORT_DIPSETTING(    0xa0, DEF_STR( 6C_1C ) )        PORT_CONDITION("DSW2", 0x04, PORTCOND_NOTEQUALS, 0x00)
    PORT_DIPSETTING(    0xb0, DEF_STR( 5C_1C ) )        PORT_CONDITION("DSW2", 0x04, PORTCOND_NOTEQUALS, 0x00)
    PORT_DIPSETTING(    0xc0, DEF_STR( 4C_1C ) )        PORT_CONDITION("DSW2", 0x04, PORTCOND_NOTEQUALS, 0x00)
    PORT_DIPSETTING(    0xd0, DEF_STR( 3C_1C ) )        PORT_CONDITION("DSW2", 0x04, PORTCOND_NOTEQUALS, 0x00)
    PORT_DIPSETTING(    0xe0, DEF_STR( 2C_1C ) )        PORT_CONDITION("DSW2", 0x04, PORTCOND_NOTEQUALS, 0x00)
    PORT_DIPSETTING(    0xf0, DEF_STR( 1C_1C ) )        PORT_CONDITION("DSW2", 0x04, PORTCOND_NOTEQUALS, 0x00)
    PORT_DIPSETTING(    0x70, DEF_STR( 1C_2C ) )        PORT_CONDITION("DSW2", 0x04, PORTCOND_NOTEQUALS, 0x00)
    PORT_DIPSETTING(    0x60, DEF_STR( 1C_3C ) )        PORT_CONDITION("DSW2", 0x04, PORTCOND_NOTEQUALS, 0x00)
    PORT_DIPSETTING(    0x50, DEF_STR( 1C_4C ) )        PORT_CONDITION("DSW2", 0x04, PORTCOND_NOTEQUALS, 0x00)
    PORT_DIPSETTING(    0x40, DEF_STR( 1C_5C ) )        PORT_CONDITION("DSW2", 0x04, PORTCOND_NOTEQUALS, 0x00)
    PORT_DIPSETTING(    0x30, DEF_STR( 1C_6C ) )        PORT_CONDITION("DSW2", 0x04, PORTCOND_NOTEQUALS, 0x00)
    PORT_DIPSETTING(    0x00, DEF_STR( Free_Play ) )    PORT_CONDITION("DSW2", 0x04, PORTCOND_NOTEQUALS, 0x00)
    // coin mode 2
    PORT_DIPNAME( 0x30, 0x30, DEF_STR( Coin_A ) )       PORT_CONDITION("DSW2", 0x04, PORTCOND_EQUALS, 0x00)
    PORT_DIPSETTING(    0x10, DEF_STR( 3C_1C ) )        PORT_CONDITION("DSW2", 0x04, PORTCOND_EQUALS, 0x00)
    PORT_DIPSETTING(    0x20, DEF_STR( 2C_1C ) )        PORT_CONDITION("DSW2", 0x04, PORTCOND_EQUALS, 0x00)
    PORT_DIPSETTING(    0x30, DEF_STR( 1C_1C ) )        PORT_CONDITION("DSW2", 0x04, PORTCOND_EQUALS, 0x00)
    PORT_DIPSETTING(    0x00, DEF_STR( Free_Play ) )    PORT_CONDITION("DSW2", 0x04, PORTCOND_EQUALS, 0x00)
    PORT_DIPNAME( 0xc0, 0xc0, DEF_STR( Coin_B ) )       PORT_CONDITION("DSW2", 0x04, PORTCOND_EQUALS, 0x00)
    PORT_DIPSETTING(    0xc0, DEF_STR( 1C_2C ) )        PORT_CONDITION("DSW2", 0x04, PORTCOND_EQUALS, 0x00)
    PORT_DIPSETTING(    0x80, DEF_STR( 1C_3C ) )        PORT_CONDITION("DSW2", 0x04, PORTCOND_EQUALS, 0x00)
    PORT_DIPSETTING(    0x40, DEF_STR( 1C_5C ) )        PORT_CONDITION("DSW2", 0x04, PORTCOND_EQUALS, 0x00)
    PORT_DIPSETTING(    0x00, DEF_STR( 1C_6C ) )        PORT_CONDITION("DSW2", 0x04, PORTCOND_EQUALS, 0x00)

	PORT_START_TAG("DSW2")
	PORT_DIPNAME( 0x01, 0x01, DEF_STR( Flip_Screen ) )
	PORT_DIPSETTING(    0x01, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x02, 0x00, DEF_STR( Cabinet ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Upright ) )
	PORT_DIPSETTING(    0x02, DEF_STR( Cocktail ) )
	PORT_DIPNAME( 0x04, 0x04, "Coin Mode" )
	PORT_DIPSETTING(    0x04, "Mode 1" )
	PORT_DIPSETTING(    0x00, "Mode 2" )
	PORT_DIPNAME( 0x08, 0x08, "Slow Motion" )
	PORT_DIPSETTING(    0x08, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x10, 0x10, "Stop Mode" )
	PORT_DIPSETTING(    0x10, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x20, 0x20, DEF_STR( Level_Select ) )
	PORT_DIPSETTING(    0x20, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x40, 0x40, "Invulnerability" )
	PORT_DIPSETTING(    0x40, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_SERVICE( 0x80, IP_ACTIVE_LOW )
INPUT_PORTS_END

INPUT_PORTS_START( vsyard )
	PORT_INCLUDE(yard)

	PORT_MODIFY("DSW1")
	PORT_DIPNAME( 0x01, 0x00, "Allow Continue (Vs. Mode)" )
	PORT_DIPSETTING( 0x01, DEF_STR( No ) )
	PORT_DIPSETTING( 0x00, DEF_STR( Yes ) )
INPUT_PORTS_END


GAME( 1983, yard,    0,    yard, yard,   0, ROT0, "Irem", "10-Yard Fight (Japan)", 0 )
GAME( 1984, vsyard,  yard, yard, vsyard, 0, ROT0, "Irem", "Vs 10-Yard Fight (World, 11/05/84)", 0 )
GAME( 1984, vsyard2, yard, yard, vsyard, 0, ROT0, "Irem", "Vs 10-Yard Fight (Japan)", 0 )
