# MAME 0.139 source snippet

static INPUT_PORTS_START( common )
	PORT_START("SYSTEM")
	/* Start 1 & 2 also restarts and freezes the game with stop mode on
       and are used in test mode to enter and esc the various tests */
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_START1 )
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_START2 )
	/* service coin must be active for 19 frames to be consistently recognized */
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_SERVICE1 ) PORT_IMPULSE(19)
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_COIN1 )
	PORT_BIT( 0xf0, IP_ACTIVE_LOW, IPT_UNUSED )

	PORT_START("P1")
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT ) PORT_8WAY
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT ) PORT_8WAY
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN ) PORT_8WAY
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_JOYSTICK_UP ) PORT_8WAY
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_UNKNOWN ) /* probably unused */
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_BUTTON2 )
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_UNKNOWN ) /* probably unused */
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_BUTTON1 )

	PORT_START("P2")
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT ) PORT_8WAY PORT_COCKTAIL
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT ) PORT_8WAY PORT_COCKTAIL
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN ) PORT_8WAY PORT_COCKTAIL
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_JOYSTICK_UP ) PORT_8WAY PORT_COCKTAIL
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_COIN2 )
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_BUTTON2 ) PORT_COCKTAIL
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_UNKNOWN ) /* probably unused */
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_COCKTAIL

	PORT_START("DSW2")
	PORT_DIPNAME( 0x01, 0x01, DEF_STR( Flip_Screen ) ) PORT_DIPLOCATION("SW2:1")
	PORT_DIPSETTING(    0x01, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x02, 0x00, DEF_STR( Cabinet ) ) PORT_DIPLOCATION("SW2:2")
	PORT_DIPSETTING(    0x00, DEF_STR( Upright ) )
	PORT_DIPSETTING(    0x02, DEF_STR( Cocktail ) )
	PORT_DIPNAME( 0x04, 0x04, "Coin Mode" ) PORT_DIPLOCATION("SW2:3")
	PORT_DIPSETTING(    0x04, "Mode 1" )
	PORT_DIPSETTING(    0x00, "Mode 2" )
	/* Bits 4,5,6 are different in each game, see below */
	PORT_DIPUNUSED_DIPLOC( 0x38, 0x38, "SW2:4,5,6" )
	PORT_DIPNAME( 0x40, 0x40, "Invulnerability (Cheat)" ) PORT_DIPLOCATION("SW2:7")
	PORT_DIPSETTING(    0x40, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_SERVICE_DIPLOC( 0x80, IP_ACTIVE_LOW, "SW2:8" )
INPUT_PORTS_END


static INPUT_PORTS_START( kungfum )
	PORT_INCLUDE( common )

	PORT_MODIFY("P1")
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT ) PORT_4WAY
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT ) PORT_4WAY
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN ) PORT_4WAY
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_JOYSTICK_UP ) PORT_4WAY
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_UNKNOWN ) /* probably unused */
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_BUTTON2 )
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_UNKNOWN ) /* probably unused */
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_BUTTON1 )

	PORT_MODIFY("P2")
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT ) PORT_4WAY PORT_COCKTAIL
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT ) PORT_4WAY PORT_COCKTAIL
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN ) PORT_4WAY PORT_COCKTAIL
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_JOYSTICK_UP ) PORT_4WAY PORT_COCKTAIL
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_COIN2 )
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_BUTTON2 ) PORT_COCKTAIL
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_UNKNOWN ) /* probably unused */
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_COCKTAIL

	PORT_MODIFY("DSW2")
	/* In slowmo mode, press 2 to slow game speed */
	PORT_DIPNAME( 0x08, 0x08, "Slow Motion Mode (Cheat)" ) PORT_DIPLOCATION("SW2:4")
	PORT_DIPSETTING(    0x08, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	/* In freeze mode, press 2 to stop and 1 to restart */
	PORT_DIPNAME( 0x10, 0x10, "Freeze (Cheat)" ) PORT_DIPLOCATION("SW2:5")
	PORT_DIPSETTING(    0x10, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	/* In level selection mode, press 1 to select and 2 to restart */
	PORT_DIPNAME( 0x20, 0x20, "Level Selection Mode (Cheat)" ) PORT_DIPLOCATION("SW2:6")
	PORT_DIPSETTING(    0x20, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )

	PORT_START("DSW1")
	PORT_DIPNAME( 0x01, 0x01, DEF_STR( Difficulty ) ) PORT_DIPLOCATION("SW1:1")
	PORT_DIPSETTING(    0x01, DEF_STR( Easy ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Hard ) )
	PORT_DIPNAME( 0x02, 0x02, "Energy Loss" ) PORT_DIPLOCATION("SW1:2")
	PORT_DIPSETTING(    0x02, "Slow" )
	PORT_DIPSETTING(    0x00, "Fast" )
	PORT_DIPNAME( 0x0c, 0x0c, DEF_STR( Lives ) ) PORT_DIPLOCATION("SW1:3,4")
	PORT_DIPSETTING(    0x08, "2" )
	PORT_DIPSETTING(    0x0c, "3" )
	PORT_DIPSETTING(    0x04, "4" )
	PORT_DIPSETTING(    0x00, "5" )
	/* Manual says that only coin mode 1 is available and SW2:3 should be always OFF */
	/* However, coin mode 2 works perfectly. */
	IREM_Z80_COINAGE_TYPE_3_LOC(SW1)
INPUT_PORTS_END

static INPUT_PORTS_START( battroad )
	PORT_INCLUDE( common )

	PORT_MODIFY("DSW2")
	PORT_DIPUNKNOWN_DIPLOC( 0x08, 0x08, "SW2:4" )
	/* In stop mode, press 2 to stop and 1 to restart */
	PORT_DIPNAME( 0x10, 0x10, "Stop Mode (Cheat)" ) PORT_DIPLOCATION("SW2:5")
	PORT_DIPSETTING(    0x10, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x20, 0x20, DEF_STR( Unknown ) ) PORT_DIPLOCATION("SW2:6")
	PORT_DIPSETTING(    0x20, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )

	PORT_START("DSW1")
	PORT_DIPNAME( 0x03, 0x03, "Fuel Decrease" ) PORT_DIPLOCATION("SW1:1,2")
	PORT_DIPSETTING(    0x03, "Slow" )
	PORT_DIPSETTING(    0x02, DEF_STR( Medium ) )
	PORT_DIPSETTING(    0x01, "Fast" )
	PORT_DIPSETTING(    0x00, "Fastest" )
	PORT_DIPNAME( 0x04, 0x04, DEF_STR( Difficulty ) ) PORT_DIPLOCATION("SW1:3")
	PORT_DIPSETTING(    0x04, DEF_STR( Easy ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Hard ) )
	PORT_DIPUNKNOWN_DIPLOC( 0x08, 0x08, "SW1:4" )
	IREM_Z80_COINAGE_TYPE_3_LOC(SW1)
INPUT_PORTS_END

static INPUT_PORTS_START( ldrun )
	PORT_INCLUDE( common )

	PORT_MODIFY("DSW2")
	PORT_DIPUNKNOWN_DIPLOC( 0x08, 0x08, "SW2:4" )
	/* In stop mode, press 2 to stop and 1 to restart */
	PORT_DIPNAME( 0x10, 0x10, "Stop Mode (Cheat)" ) PORT_DIPLOCATION("SW2:5")
	PORT_DIPSETTING(    0x10, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	/* In level selection mode, press 1 to select and 2 to restart */
	PORT_DIPNAME( 0x20, 0x20, "Level Selection Mode (Cheat)" ) PORT_DIPLOCATION("SW2:6")
	PORT_DIPSETTING(    0x20, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )

	PORT_START("DSW1")
	PORT_DIPNAME( 0x03, 0x03, "Timer" ) PORT_DIPLOCATION("SW1:1,2")
	PORT_DIPSETTING(    0x03, "Slow" )
	PORT_DIPSETTING(    0x02, DEF_STR( Medium ) )
	PORT_DIPSETTING(    0x01, "Fast" )
	PORT_DIPSETTING(    0x00, "Fastest" )
	PORT_DIPNAME( 0x0c, 0x0c, DEF_STR( Lives ) ) PORT_DIPLOCATION("SW1:3,4")
	PORT_DIPSETTING(    0x08, "2" )
	PORT_DIPSETTING(    0x0c, "3" )
	PORT_DIPSETTING(    0x04, "4" )
	PORT_DIPSETTING(    0x00, "5" )
	IREM_Z80_COINAGE_TYPE_3_LOC(SW1)
INPUT_PORTS_END

static INPUT_PORTS_START( ldrun2 )
	PORT_INCLUDE( common )

	PORT_MODIFY("DSW2")
	PORT_DIPUNKNOWN_DIPLOC( 0x08, 0x08, "SW2:4" )
	/* In freeze mode, press 2 to stop and 1 to restart */
	PORT_DIPNAME( 0x10, 0x10, "Freeze (Cheat)" ) PORT_DIPLOCATION("SW2:5")
	PORT_DIPSETTING(    0x10, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	/* In level selection mode, press 1 to select and 2 to restart */
	PORT_DIPNAME( 0x20, 0x20, "Level Selection Mode (Cheat)" ) PORT_DIPLOCATION("SW2:6")
	PORT_DIPSETTING(    0x20, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )

	PORT_START("DSW1")
	PORT_DIPNAME( 0x01, 0x01, "Timer" ) PORT_DIPLOCATION("SW1:1")
	PORT_DIPSETTING(    0x01, "Slow" )
	PORT_DIPSETTING(    0x00, "Fast" )
	PORT_DIPNAME( 0x02, 0x02, "Game Speed" ) PORT_DIPLOCATION("SW1:2")
	PORT_DIPSETTING(    0x00, DEF_STR( Low ) )
	PORT_DIPSETTING(    0x02, DEF_STR( High ) )
	PORT_DIPNAME( 0x0c, 0x0c, DEF_STR( Lives ) ) PORT_DIPLOCATION("SW1:3,4")
	PORT_DIPSETTING(    0x08, "2" )
	PORT_DIPSETTING(    0x0c, "3" )
	PORT_DIPSETTING(    0x04, "4" )
	PORT_DIPSETTING(    0x00, "5" )
	IREM_Z80_COINAGE_TYPE_3_LOC(SW1)
INPUT_PORTS_END

static INPUT_PORTS_START( ldrun3 )
	PORT_INCLUDE( common )

	PORT_MODIFY("DSW2")
	PORT_DIPUNKNOWN_DIPLOC( 0x08, 0x08, "SW2:4" )
	/* In stop mode, press 2 to stop and 1 to restart */
	PORT_DIPNAME( 0x10, 0x10, "Stop Mode (Cheat)" ) PORT_DIPLOCATION("SW2:5")
	PORT_DIPSETTING(    0x10, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	/* In level selection mode, press 1 to select and 2 to restart */
	PORT_DIPNAME( 0x20, 0x20, "Level Selection Mode (Cheat)" ) PORT_DIPLOCATION("SW2:6")
	PORT_DIPSETTING(    0x20, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )

	PORT_START("DSW1")
	PORT_DIPNAME( 0x01, 0x01, "Timer" ) PORT_DIPLOCATION("SW1:1")
	PORT_DIPSETTING(    0x01, "Slow" )
	PORT_DIPSETTING(    0x00, "Fast" )
	PORT_DIPNAME( 0x02, 0x02, "Game Speed" ) PORT_DIPLOCATION("SW1:2")
	PORT_DIPSETTING(    0x00, DEF_STR( Low ) )
	PORT_DIPSETTING(    0x02, DEF_STR( High ) )
	PORT_DIPNAME( 0x0c, 0x0c, DEF_STR( Lives ) ) PORT_DIPLOCATION("SW1:3,4")
	PORT_DIPSETTING(    0x08, "2" )
	PORT_DIPSETTING(    0x0c, "3" )
	PORT_DIPSETTING(    0x04, "4" )
	PORT_DIPSETTING(    0x00, "5" )
	IREM_Z80_COINAGE_TYPE_3_LOC(SW1)
INPUT_PORTS_END

static INPUT_PORTS_START( ldrun4 )
	PORT_INCLUDE( common )

	PORT_MODIFY("DSW2")
	PORT_DIPNAME( 0x02, 0x02, "2 Players Lives" ) PORT_DIPLOCATION("SW2:2")
	PORT_DIPSETTING(    0x02, "5" )
	PORT_DIPSETTING(    0x00, "6" )
	PORT_DIPUNKNOWN_DIPLOC( 0x08, 0x08, "SW2:4" )
	PORT_DIPNAME( 0x10, 0x10, "Allow 2 Players Game" ) PORT_DIPLOCATION("SW2:5")
	PORT_DIPSETTING(    0x00, DEF_STR( No ) )
	PORT_DIPSETTING(    0x10, DEF_STR( Yes ) )
	/* In level selection mode, press 1 to select and 2 to restart */
	PORT_DIPNAME( 0x20, 0x20, "Level Selection Mode (Cheat)" ) PORT_DIPLOCATION("SW2:6")
	PORT_DIPSETTING(    0x20, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x80, 0x80, "Service Mode (must set 2P game to No)" ) PORT_TOGGLE PORT_CODE(KEYCODE_F2) PORT_DIPLOCATION("SW2:6")
	PORT_DIPSETTING(    0x80, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )

	PORT_START("DSW1")
	PORT_DIPNAME( 0x01, 0x01, "Timer" ) PORT_DIPLOCATION("SW1:1")
	PORT_DIPSETTING(    0x01, "Slow" )
	PORT_DIPSETTING(    0x00, "Fast" )
	PORT_DIPNAME( 0x02, 0x02, "2 Players Game" ) PORT_DIPLOCATION("SW1:2")
	PORT_DIPSETTING(    0x00, "1 Credit" )
	PORT_DIPSETTING(    0x02, "2 Credits" )
	PORT_DIPNAME( 0x0c, 0x0c, "1 Player Lives" ) PORT_DIPLOCATION("SW1:3,4")
	PORT_DIPSETTING(    0x08, "2" )
	PORT_DIPSETTING(    0x0c, "3" )
	PORT_DIPSETTING(    0x04, "4" )
	PORT_DIPSETTING(    0x00, "5" )
	IREM_Z80_COINAGE_TYPE_3_LOC(SW1)
INPUT_PORTS_END

static INPUT_PORTS_START( lotlot )
	PORT_INCLUDE( common )

	PORT_MODIFY("DSW2")
	PORT_DIPNAME( 0x08, 0x00, DEF_STR( Demo_Sounds ) ) PORT_DIPLOCATION("SW2:4")
	PORT_DIPSETTING(    0x08, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	/* In freeze mode, press 2 to stop and 1 to restart */
	PORT_DIPNAME( 0x10, 0x10, "Freeze (Cheat)" ) PORT_DIPLOCATION("SW2:5")
	PORT_DIPSETTING(    0x10, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPUNKNOWN_DIPLOC( 0x20, 0x20, "SW2:6" )

	PORT_START("DSW1")
	PORT_DIPNAME( 0x03, 0x03, "Speed" ) PORT_DIPLOCATION("SW1:1,2")
	PORT_DIPSETTING(    0x03, "Very Slow" )
	PORT_DIPSETTING(    0x02, "Slow" )
	PORT_DIPSETTING(    0x01, "Fast" )
	PORT_DIPSETTING(    0x00, "Very Fast" )
	PORT_DIPNAME( 0x0c, 0x0c, DEF_STR( Lives ) ) PORT_DIPLOCATION("SW1:3,4")
	PORT_DIPSETTING(    0x08, "1" )
	PORT_DIPSETTING(    0x04, "2" )
	PORT_DIPSETTING(    0x0c, "3" )
	PORT_DIPSETTING(    0x00, "4" )
	IREM_Z80_COINAGE_TYPE_4_LOC(SW1)
INPUT_PORTS_END

static INPUT_PORTS_START( kidniki )
	PORT_INCLUDE( common )

	PORT_MODIFY("DSW2")
	PORT_DIPNAME( 0x08, 0x08, "Game Repeats" ) PORT_DIPLOCATION("SW2:4")
	PORT_DIPSETTING(    0x08, DEF_STR( No ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Yes ) )
	PORT_DIPNAME( 0x10, 0x10, DEF_STR( Allow_Continue ) ) PORT_DIPLOCATION("SW2:5")
	PORT_DIPSETTING(    0x00, DEF_STR( No ) )
	PORT_DIPSETTING(    0x10, DEF_STR( Yes ) )
	/* In freeze mode, press 2 to stop and 1 to restart */
	PORT_DIPNAME( 0x20, 0x20, "Freeze (Cheat)" ) PORT_DIPLOCATION("SW2:6")
	PORT_DIPSETTING(    0x20, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )

	PORT_START("DSW1")
	PORT_DIPNAME( 0x03, 0x03, DEF_STR( Lives ) ) PORT_DIPLOCATION("SW1:1,2")
	PORT_DIPSETTING(    0x02, "2" )
	PORT_DIPSETTING(    0x03, "3" )
	PORT_DIPSETTING(    0x01, "4" )
	PORT_DIPSETTING(    0x00, "5" )
	PORT_DIPNAME( 0x04, 0x04, DEF_STR( Difficulty ) ) PORT_DIPLOCATION("SW1:3")
	PORT_DIPSETTING(    0x04, DEF_STR( Normal ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Hard ) )
	PORT_DIPNAME( 0x08, 0x08, DEF_STR( Bonus_Life ) ) PORT_DIPLOCATION("SW1:4")
	PORT_DIPSETTING(    0x08, "50000" )
	PORT_DIPSETTING(    0x00, "80000" )
	IREM_Z80_COINAGE_TYPE_4_LOC(SW1)
INPUT_PORTS_END

static INPUT_PORTS_START( spelunkr )
	PORT_INCLUDE( common )

	PORT_MODIFY("DSW2")
	PORT_DIPNAME( 0x08, 0x00, DEF_STR( Allow_Continue ) ) PORT_DIPLOCATION("SW2:4")
	PORT_DIPSETTING(    0x08, DEF_STR( No ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Yes ) )
	/* In teleport mode, keep 1 pressed and press up or down to move the character */
	PORT_DIPNAME( 0x10, 0x10, "Teleport (Cheat)" ) PORT_DIPLOCATION("SW2:5")
	PORT_DIPSETTING(    0x10, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	/* In freeze mode, press 2 to stop and 1 to restart */
	PORT_DIPNAME( 0x20, 0x20, "Freeze (Cheat)" ) PORT_DIPLOCATION("SW2:6")
	PORT_DIPSETTING(    0x20, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )

	PORT_START("DSW1")
	PORT_DIPNAME( 0x03, 0x03, "Energy Decrease" ) PORT_DIPLOCATION("SW1:1,2")
	PORT_DIPSETTING(    0x03, "Slow" )
	PORT_DIPSETTING(    0x02, DEF_STR( Medium ) )
	PORT_DIPSETTING(    0x01, "Fast" )
	PORT_DIPSETTING(    0x00, "Fastest" )
	PORT_DIPNAME( 0x0c, 0x0c, DEF_STR( Lives ) ) PORT_DIPLOCATION("SW1:3,4")
	PORT_DIPSETTING(    0x08, "2" )
	PORT_DIPSETTING(    0x0c, "3" )
	PORT_DIPSETTING(    0x04, "4" )
	PORT_DIPSETTING(    0x00, "5" )
	IREM_Z80_COINAGE_TYPE_4_LOC(SW1)
INPUT_PORTS_END

static INPUT_PORTS_START( spelunk2 )
	PORT_INCLUDE( common )

	/* Factory shipment setting is all OFF */
	PORT_MODIFY("DSW2")
	PORT_DIPNAME( 0x08, 0x08, DEF_STR( Allow_Continue ) ) PORT_DIPLOCATION("SW2:4")
	PORT_DIPSETTING(    0x00, DEF_STR( No ) )
	PORT_DIPSETTING(    0x08, DEF_STR( Yes ) )
	PORT_DIPNAME( 0x10, 0x10, DEF_STR( Demo_Sounds ) ) PORT_DIPLOCATION("SW2:5")
	PORT_DIPSETTING(    0x00, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x10, DEF_STR( On ) )
	/* In freeze mode, press 2 to stop and 1 to restart */
	PORT_DIPNAME( 0x20, 0x20, "Freeze (Cheat)" ) PORT_DIPLOCATION("SW2:6")
	PORT_DIPSETTING(    0x20, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )

	PORT_START("DSW1")
	PORT_DIPNAME( 0x03, 0x03, "Energy Decrease" ) PORT_DIPLOCATION("SW1:1,2")
	PORT_DIPSETTING(    0x03, "Slow" )
	PORT_DIPSETTING(    0x02, DEF_STR( Medium ) )
	PORT_DIPSETTING(    0x01, "Fast" )
	PORT_DIPSETTING(    0x00, "Fastest" )
	PORT_DIPNAME( 0x0c, 0x0c, DEF_STR( Lives ) ) PORT_DIPLOCATION("SW1:3,4")
	PORT_DIPSETTING(    0x08, "2" )
	PORT_DIPSETTING(    0x0c, "3" )
	PORT_DIPSETTING(    0x04, "4" )
	PORT_DIPSETTING(    0x00, "5" )
	IREM_Z80_COINAGE_TYPE_4_LOC(SW1)
INPUT_PORTS_END

static INPUT_PORTS_START( youjyudn )
	PORT_INCLUDE( common )

	PORT_MODIFY("DSW2")
	PORT_DIPNAME( 0x08, 0x08, DEF_STR( Bonus_Life ) ) PORT_DIPLOCATION("SW2:4")
	PORT_DIPSETTING(    0x08, "20000 60000" )
	PORT_DIPSETTING(    0x00, "40000 80000" )
	PORT_DIPNAME( 0x10, 0x10, DEF_STR( Demo_Sounds ) ) PORT_DIPLOCATION("SW2:5")
	PORT_DIPSETTING(    0x00, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x10, DEF_STR( On ) )
	/* In freeze mode, press 2 to stop and 1 to restart */
	PORT_DIPNAME( 0x20, 0x20, "Freeze (Cheat)" ) PORT_DIPLOCATION("SW2:6")
	PORT_DIPSETTING(    0x20, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )

	PORT_START("DSW1")
	PORT_DIPNAME( 0x03, 0x03, DEF_STR( Lives ) ) PORT_DIPLOCATION("SW1:1,2")
	PORT_DIPSETTING(    0x02, "2" )
	PORT_DIPSETTING(    0x03, "3" )
	PORT_DIPSETTING(    0x01, "4" )
	PORT_DIPSETTING(    0x00, "5" )
	PORT_DIPUNKNOWN_DIPLOC( 0x04, 0x04, "SW1:3" )
	PORT_DIPUNKNOWN_DIPLOC( 0x08, 0x08, "SW1:4" )
	IREM_Z80_COINAGE_TYPE_4_LOC(SW1)
INPUT_PORTS_END

static INPUT_PORTS_START( horizon )
	PORT_INCLUDE( common )

	PORT_MODIFY("DSW2")
	/* In freeze mode, press 2 to stop and 1 to restart */
	PORT_DIPNAME( 0x08, 0x08, "Freeze (Cheat)" ) PORT_DIPLOCATION("SW2:4")
	PORT_DIPSETTING(    0x08, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	/* In frame advance mode, press 1 then 2 to advance a frame */
	PORT_DIPNAME( 0x10, 0x10, "Frame Advance (Cheat)" ) PORT_DIPLOCATION("SW2:5")
	PORT_DIPSETTING(    0x10, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPUNKNOWN_DIPLOC( 0x20, 0x20, "SW2:6" )

	PORT_START("DSW1")
	PORT_DIPNAME( 0x03, 0x03, DEF_STR( Lives ) ) PORT_DIPLOCATION("SW1:1,2")
	PORT_DIPSETTING(    0x00, "2" )
	PORT_DIPSETTING(    0x03, "3" )
	PORT_DIPSETTING(    0x01, "4" )
	PORT_DIPSETTING(    0x02, "5" )
	PORT_DIPNAME( 0x0c, 0x0c, DEF_STR( Bonus_Life ) )  PORT_DIPLOCATION("SW1:3,4")	// as per the service mode
	PORT_DIPSETTING(    0x00, "100 and 80k" )										// this one is blank but verified manually
	PORT_DIPSETTING(    0x0c, "40k and every 80k" )
	PORT_DIPSETTING(    0x08, "60k and every 100k" )
	PORT_DIPSETTING(    0x04, "80k and every 120k" )
	IREM_Z80_COINAGE_TYPE_5_LOC(SW1)
INPUT_PORTS_END


GAME( 1984, kungfum,  0,        kungfum,  kungfum,  0,        ROT0,   "Irem", "Kung-Fu Master", GAME_SUPPORTS_SAVE )
GAME( 1984, kungfumd, kungfum,  kungfum,  kungfum,  0,        ROT0,   "Irem (Data East license)", "Kung-Fu Master (Data East)", GAME_SUPPORTS_SAVE )
GAME( 1984, spartanx, kungfum,  kungfum,  kungfum,  0,        ROT0,   "Irem", "Spartan X (Japan)", GAME_SUPPORTS_SAVE )
GAME( 1984, kungfub,  kungfum,  kungfum,  kungfum,  0,        ROT0,   "bootleg", "Kung-Fu Master (bootleg set 1)", GAME_SUPPORTS_SAVE )
GAME( 1984, kungfub2, kungfum,  kungfum,  kungfum,  0,        ROT0,   "bootleg", "Kung-Fu Master (bootleg set 2)", GAME_SUPPORTS_SAVE )
GAME( 1984, battroad, 0,        battroad, battroad, battroad, ROT90,  "Irem", "The Battle-Road", GAME_IMPERFECT_COLORS | GAME_SUPPORTS_SAVE )
GAME( 1984, ldrun,    0,        ldrun,    ldrun,    0,        ROT0,   "Irem (licensed from Broderbund)", "Lode Runner (set 1)", GAME_SUPPORTS_SAVE )
GAME( 1984, ldruna,   ldrun,    ldrun,    ldrun,    0,        ROT0,   "Irem (licensed from Broderbund)", "Lode Runner (set 2)", GAME_SUPPORTS_SAVE )
GAME( 1984, ldrun2,   0,        ldrun2,   ldrun2,   ldrun2,   ROT0,   "Irem (licensed from Broderbund)", "Lode Runner II - The Bungeling Strikes Back", GAME_SUPPORTS_SAVE )	/* Japanese version is called Bangeringu Teikoku No Gyakushuu */
GAME( 1985, ldrun3,   0,        ldrun3,   ldrun3,   0,        ROT0,   "Irem (licensed from Broderbund)", "Lode Runner III - The Golden Labyrinth", GAME_SUPPORTS_SAVE )
GAME( 1985, ldrun3j,  ldrun3,   ldrun3,   ldrun3,   0,        ROT0,   "Irem (licensed from Broderbund)", "Lode Runner III - Majin No Fukkatsu", GAME_SUPPORTS_SAVE )
GAME( 1986, ldrun4,   0,        ldrun4,   ldrun4,   ldrun4,   ROT0,   "Irem (licensed from Broderbund)", "Lode Runner IV - Teikoku Karano Dasshutsu", GAME_SUPPORTS_SAVE )
GAME( 1985, lotlot,   0,        lotlot,   lotlot,   0,        ROT0,   "Irem (licensed from Tokuma Shoten)", "Lot Lot", GAME_SUPPORTS_SAVE )
GAME( 1986, kidniki,  0,        kidniki,  kidniki,  kidniki,  ROT0,   "Irem", "Kid Niki - Radical Ninja (World)", GAME_IMPERFECT_SOUND | GAME_SUPPORTS_SAVE )
GAME( 1986, kidnikiu, kidniki,  kidniki,  kidniki,  kidniki,  ROT0,   "Irem (Data East USA license)", "Kid Niki - Radical Ninja (US)", GAME_IMPERFECT_SOUND | GAME_SUPPORTS_SAVE )
GAME( 1986, yanchamr, kidniki,  kidniki,  kidniki,  kidniki,  ROT0,   "Irem", "Kaiketsu Yanchamaru (Japan)", GAME_IMPERFECT_SOUND | GAME_SUPPORTS_SAVE )
GAME( 1987, lithero,  kidniki,  kidniki,  kidniki,  kidniki,  ROT0,   "bootleg", "Little Hero", GAME_IMPERFECT_SOUND | GAME_SUPPORTS_SAVE )
GAME( 1985, spelunkr, 0,        spelunkr, spelunkr, spelunkr, ROT0,   "Irem (licensed from Broderbund)", "Spelunker", GAME_SUPPORTS_SAVE )
GAME( 1985, spelunkrj,spelunkr, spelunkr, spelunkr, spelunkr, ROT0,   "Irem (licensed from Broderbund)", "Spelunker (Japan)", GAME_SUPPORTS_SAVE )
GAME( 1986, spelunk2, 0,        spelunk2, spelunk2, spelunk2, ROT0,   "Irem (licensed from Broderbund)", "Spelunker II", GAME_IMPERFECT_SOUND | GAME_SUPPORTS_SAVE )
GAME( 1986, youjyudn, 0,        youjyudn, youjyudn, youjyudn, ROT270, "Irem", "Youjyuden (Japan)", GAME_SUPPORTS_SAVE )
GAME( 1985, horizon,  0,        horizon,  horizon,  0,        ROT0,   "Irem", "Horizon", GAME_IMPERFECT_SOUND | GAME_SUPPORTS_SAVE )
