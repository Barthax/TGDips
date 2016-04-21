/*************************************
 *
 *  Generic port definitions
 *
 *************************************/

static INPUT_PORTS_START( system18_generic )
	PORT_START_TAG("P1")
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_BUTTON1 )
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_BUTTON2 )
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_BUTTON3 )
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN ) PORT_8WAY
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_JOYSTICK_UP ) PORT_8WAY
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT ) PORT_8WAY
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT ) PORT_8WAY

	PORT_START_TAG("P2")
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_COCKTAIL
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_BUTTON2 ) PORT_COCKTAIL
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_BUTTON3 ) PORT_COCKTAIL
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN ) PORT_8WAY PORT_COCKTAIL
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_JOYSTICK_UP ) PORT_8WAY PORT_COCKTAIL
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT ) PORT_8WAY PORT_COCKTAIL
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT ) PORT_8WAY PORT_COCKTAIL

	PORT_START_TAG("PORTC")
	PORT_BIT( 0xff, IP_ACTIVE_LOW, IPT_UNUSED )

	PORT_START_TAG("PORTD")
	PORT_BIT( 0xff, IP_ACTIVE_LOW, IPT_UNUSED )

	PORT_START_TAG("SERVICE")
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_COIN1 )
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_COIN2 )
	PORT_SERVICE_NO_TOGGLE( 0x04, IP_ACTIVE_LOW )
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_SERVICE1 )
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_START1 )
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_START2 )
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_SERVICE2 )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_UNKNOWN )

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

	PORT_START_TAG("PORTH")
	PORT_BIT( 0xff, IP_ACTIVE_LOW, IPT_UNUSED )
INPUT_PORTS_END



/*************************************
 *
 *  Game-specific port definitions
 *
 *************************************/

static INPUT_PORTS_START( astorm )
	PORT_INCLUDE( system18_generic )

	PORT_MODIFY("PORTC")
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_PLAYER(3)
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_BUTTON2 ) PORT_PLAYER(3)
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_BUTTON3 ) PORT_PLAYER(3)
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN ) PORT_8WAY PORT_PLAYER(3)
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_JOYSTICK_UP ) PORT_8WAY PORT_PLAYER(3)
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT ) PORT_8WAY PORT_PLAYER(3)
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT ) PORT_8WAY PORT_PLAYER(3)

	PORT_MODIFY("SERVICE")
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_COIN3 )
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_START3 )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_COIN1 )

	PORT_MODIFY("DSW")
	PORT_DIPNAME( 0x01, 0x01, "2 Credits to Start" )
	PORT_DIPSETTING(    0x01, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x02, 0x00, DEF_STR( Demo_Sounds ) )
	PORT_DIPSETTING(    0x02, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x1c, 0x1c, DEF_STR( Difficulty ) )
	PORT_DIPSETTING(    0x04, DEF_STR( Easiest ) )
	PORT_DIPSETTING(    0x08, DEF_STR( Easier ) )
	PORT_DIPSETTING(    0x0c, DEF_STR( Easy ) )
	PORT_DIPSETTING(    0x1c, DEF_STR( Normal ) )
	PORT_DIPSETTING(    0x10, DEF_STR( Hard ) )
	PORT_DIPSETTING(    0x14, DEF_STR( Harder ) )
	PORT_DIPSETTING(    0x18, DEF_STR( Hardest ) )
	PORT_DIPSETTING(    0x00, "Special" )
	PORT_DIPNAME( 0x20, 0x20, "Coin Chutes" )
	PORT_DIPSETTING(    0x20, "3" )
	PORT_DIPSETTING(    0x00, "1" )
	PORT_DIPNAME( 0x40, 0x40, DEF_STR( Unused ) )
	PORT_DIPSETTING(    0x40, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x80, 0x80, DEF_STR( Unused ) )
	PORT_DIPSETTING(    0x80, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )

INPUT_PORTS_END


static INPUT_PORTS_START( astorm2p )
	PORT_INCLUDE( system18_generic )

	PORT_MODIFY("DSW")
	PORT_DIPNAME( 0x01, 0x01, "2 Credits to Start" )
	PORT_DIPSETTING(    0x01, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x02, 0x00, DEF_STR( Demo_Sounds ) )
	PORT_DIPSETTING(    0x02, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x1c, 0x1c, DEF_STR( Difficulty ) )
	PORT_DIPSETTING(    0x04, DEF_STR( Easiest ) )
	PORT_DIPSETTING(    0x08, DEF_STR( Easier ) )
	PORT_DIPSETTING(    0x0c, DEF_STR( Easy ) )
	PORT_DIPSETTING(    0x1c, DEF_STR( Normal ) )
	PORT_DIPSETTING(    0x10, DEF_STR( Hard ) )
	PORT_DIPSETTING(    0x14, DEF_STR( Harder ) )
	PORT_DIPSETTING(    0x18, DEF_STR( Hardest ) )
	PORT_DIPSETTING(    0x00, "Special" )
	PORT_DIPNAME( 0x20, 0x20, "Coin Chutes" )
	PORT_DIPSETTING(    0x20, "2" )
	PORT_DIPSETTING(    0x00, "1" )
	PORT_DIPNAME( 0x40, 0x40, DEF_STR( Unused ) )
	PORT_DIPSETTING(    0x40, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x80, 0x80, DEF_STR( Unused ) )
	PORT_DIPSETTING(    0x80, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )

INPUT_PORTS_END


static INPUT_PORTS_START( bloxeed )
	PORT_INCLUDE( system18_generic )

	PORT_MODIFY("SERVICE")
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_UNUSED )

	PORT_MODIFY("DSW")
	PORT_DIPNAME( 0x03, 0x03, "Price Type" ) /* Normal game | VS Mode */
	PORT_DIPSETTING(    0x03, "A" )	/* 1 Start / 1 Continue | 2 Start / 1 Continue */
	PORT_DIPSETTING(    0x02, "B" )	/* 1 Start / 1 Continue | 1 Start / 1 Continue */
	PORT_DIPSETTING(    0x01, "C" )	/* 2 Start / 1 Continue | 4 Start / 2 Continue */
	PORT_DIPSETTING(    0x00, "D" )	/* 2 Start / 1 Continue | 2 Start / 2 Continue */
	PORT_DIPNAME( 0x08, 0x00, DEF_STR( Demo_Sounds ) )
	PORT_DIPSETTING(    0x08, DEF_STR( Off ) )
 	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x30, 0x30, DEF_STR( Difficulty ) )
	PORT_DIPSETTING(    0x20, DEF_STR( Easy ) )
	PORT_DIPSETTING(    0x30, DEF_STR( Normal ) )
	PORT_DIPSETTING(    0x10, DEF_STR( Hard ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Hardest ) )
	PORT_DIPNAME( 0x80, 0x00, "High Speed Mode" )
	PORT_DIPSETTING(    0x00, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x80, DEF_STR( On ) )
	/* Switches 3 & 7 are listed as "NOT USED" */
INPUT_PORTS_END


static INPUT_PORTS_START( cltchitr )
	PORT_INCLUDE( system18_generic )

	PORT_MODIFY("DSW")
	PORT_DIPNAME( 0x01, 0x01, "2 Credits to Start" )
	PORT_DIPSETTING(    0x01, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x02, 0x00, DEF_STR( Demo_Sounds ) )
	PORT_DIPSETTING(    0x02, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x0c, 0x0c, "Game Time P1" )
	PORT_DIPSETTING(    0x04, "2 Credits 18 Outcounts 14 Min." )
	PORT_DIPSETTING(    0x00, "1 Credit 6 Outcounts 7 Min." )
	PORT_DIPSETTING(    0x08, "1 Credit 12 Outcounts 12 Min." )
	PORT_DIPSETTING(    0x0c, "1Credit 6 Outcounts 8M./2Credits 18 Outcounts 14M." )
	PORT_DIPNAME( 0x30, 0x30, "Game Time P2" )
	PORT_DIPSETTING(    0x10, "4 Credits 18 Outcounts 16 Min." )
	PORT_DIPSETTING(    0x00, "2 Credits 6 Outcounts 8 Min." )
	PORT_DIPSETTING(    0x20, "2 Credits 12 Outcounts 14 Min." )
	PORT_DIPSETTING(    0x30, "2Credits 6 Outcounts 8M./4Credits 18 Outcounts 16M." )
	PORT_DIPNAME( 0xc0, 0xc0, DEF_STR( Difficulty ) )
	PORT_DIPSETTING(    0x40, DEF_STR( Easiest ) )
	PORT_DIPSETTING(    0x80, DEF_STR( Easy ) )
	PORT_DIPSETTING(    0xc0, DEF_STR( Normal ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Hard ) )
INPUT_PORTS_END


static INPUT_PORTS_START( ddcrew )
	PORT_INCLUDE( system18_generic )

	PORT_MODIFY("DSW")
	PORT_DIPNAME( 0x01, 0x01, "Credits needed" )
	PORT_DIPSETTING(    0x01, "1 to start, 1 to continue" )
	PORT_DIPSETTING(    0x00, "2 to start, 1 to continue" )
	PORT_DIPNAME( 0x02, 0x02, "Switch to Start" )
	PORT_DIPSETTING(    0x02, "Start" )
	PORT_DIPSETTING(    0x00, "Attack" )
	PORT_DIPNAME( 0x04, 0x04, "Coin Chute" )
	PORT_DIPSETTING(    0x04, "Common" )
	PORT_DIPSETTING(    0x00, "Individual" )
	PORT_DIPNAME( 0x08, 0x00, DEF_STR( Demo_Sounds ) )
	PORT_DIPSETTING(    0x08, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x30, 0x30, "Player Start/Continue" )
	PORT_DIPSETTING(    0x30, "3/3" )
	PORT_DIPSETTING(    0x20, "2/3" )
	PORT_DIPSETTING(    0x10, "2/2" )
	PORT_DIPSETTING(    0x00, "3/4" )
	PORT_DIPNAME( 0xc0, 0xc0, DEF_STR( Difficulty ) )
	PORT_DIPSETTING(    0x80, DEF_STR( Easy ) )
	PORT_DIPSETTING(    0xc0, DEF_STR( Normal ) )
	PORT_DIPSETTING(    0x40, DEF_STR( Hard ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Hardest ) )

	PORT_START_TAG("P3")
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_PLAYER(3)
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_BUTTON2 ) PORT_PLAYER(3)
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_BUTTON3 ) PORT_PLAYER(3)
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN ) PORT_8WAY PORT_PLAYER(3)
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_JOYSTICK_UP ) PORT_8WAY PORT_PLAYER(3)
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT ) PORT_8WAY PORT_PLAYER(3)
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT ) PORT_8WAY PORT_PLAYER(3)

	PORT_START_TAG("P4")
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_PLAYER(4)
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_BUTTON2 ) PORT_PLAYER(4)
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_BUTTON3 ) PORT_PLAYER(4)
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN ) PORT_8WAY PORT_PLAYER(4)
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_JOYSTICK_UP ) PORT_8WAY PORT_PLAYER(4)
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT ) PORT_8WAY PORT_PLAYER(4)
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT ) PORT_8WAY PORT_PLAYER(4)

	PORT_START_TAG("P34START")
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_START3 )
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_START4 )
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_COIN3 ) // individual mode
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_COIN4 ) // individual mode
	PORT_BIT( 0xf0, IP_ACTIVE_LOW, IPT_UNUSED )
INPUT_PORTS_END


static INPUT_PORTS_START( ddcrew2p )
	PORT_INCLUDE( system18_generic )

	PORT_MODIFY("DSW")
	PORT_DIPNAME( 0x01, 0x01, "Credits needed" )
	PORT_DIPSETTING(    0x01, "1 to start, 1 to continue" )
	PORT_DIPSETTING(    0x00, "2 to start, 1 to continue" )
	PORT_DIPNAME( 0x02, 0x02, "Switch to Start" )
	PORT_DIPSETTING(    0x02, "Start" )
	PORT_DIPSETTING(    0x00, "Attack" )
	PORT_DIPNAME( 0x04, 0x04, "Coin Chute" )
	PORT_DIPSETTING(    0x04, "Common" )
	PORT_DIPSETTING(    0x00, "Individual" )
	PORT_DIPNAME( 0x08, 0x00, DEF_STR( Demo_Sounds ) )
	PORT_DIPSETTING(    0x08, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x30, 0x30, "Player Start/Continue" )
	PORT_DIPSETTING(    0x30, "3/3" )
	PORT_DIPSETTING(    0x20, "2/3" )
	PORT_DIPSETTING(    0x10, "2/2" )
	PORT_DIPSETTING(    0x00, "3/4" )
	PORT_DIPNAME( 0xc0, 0xc0, DEF_STR( Difficulty ) )
	PORT_DIPSETTING(    0x80, DEF_STR( Easy ) )
	PORT_DIPSETTING(    0xc0, DEF_STR( Normal ) )
	PORT_DIPSETTING(    0x40, DEF_STR( Hard ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Hardest ) )

INPUT_PORTS_END


static INPUT_PORTS_START( desertbr )
	PORT_INCLUDE( system18_generic )

	PORT_MODIFY("PORTC")
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_PLAYER(3)
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_BUTTON2 ) PORT_PLAYER(3)
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_BUTTON3 ) PORT_PLAYER(3)
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_START3 )
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN ) PORT_8WAY PORT_PLAYER(3)
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_JOYSTICK_UP ) PORT_8WAY PORT_PLAYER(3)
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT ) PORT_8WAY PORT_PLAYER(3)
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT ) PORT_8WAY PORT_PLAYER(3)

	PORT_MODIFY("SERVICE")
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_COIN3 ) // individual mode
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_COIN2 )
	PORT_SERVICE_NO_TOGGLE( 0x04, IP_ACTIVE_LOW )
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_SERVICE1 )
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_START1 )
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_START2 )
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_SERVICE2 )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_COIN1 ) // individual mode

	PORT_MODIFY("DSW")
	PORT_DIPNAME( 0x01, 0x01, "Credits to Start" )
	PORT_DIPSETTING(    0x01, "1" )
	PORT_DIPSETTING(    0x00, "2" )
	PORT_DIPNAME( 0x02, 0x00, DEF_STR( Demo_Sounds ) )
	PORT_DIPSETTING(    0x02, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x04, 0x04, DEF_STR( Unused ) )
	PORT_DIPSETTING(    0x04, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x08, 0x08, "Play Mode" )
	PORT_DIPSETTING(    0x00, "2 players" )
	PORT_DIPSETTING(    0x08, "3 players" )
	PORT_DIPNAME( 0x10, 0x10, "Coin Chute" )
	PORT_DIPSETTING(    0x10, "Common" )
	PORT_DIPSETTING(    0x00, "Individual" )
	PORT_DIPNAME( 0x20, 0x20, "Start Button" )
	PORT_DIPSETTING(    0x20, "Use" )
	PORT_DIPSETTING(    0x00, DEF_STR( Unused ) )
	PORT_DIPNAME( 0xc0, 0xc0, DEF_STR( Difficulty ) )
	PORT_DIPSETTING(    0x40, DEF_STR( Hard ) )
	PORT_DIPSETTING(    0x80, DEF_STR( Easy ) )
	PORT_DIPSETTING(    0xc0, DEF_STR( Normal ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Hardest ) )
INPUT_PORTS_END


static INPUT_PORTS_START( lghost )
	PORT_INCLUDE( system18_generic )

	PORT_MODIFY("P1")
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_BUTTON1 )
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_BUTTON2 )
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_PLAYER(2)
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_BUTTON2 ) PORT_PLAYER(2)
	PORT_BIT( 0x30, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_BUTTON2 ) PORT_PLAYER(3)
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_PLAYER(3)

	PORT_MODIFY("SERVICE")
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_SERVICE1 )
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_SERVICE2 )
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_SERVICE3 )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_COIN3 )

	PORT_MODIFY("DSW")
	PORT_DIPNAME( 0x01, 0x01, "2 Credits to Start" )
	PORT_DIPSETTING(    0x01, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x02, 0x00, DEF_STR( Demo_Sounds ) )
	PORT_DIPSETTING(    0x02, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x1c, 0x1c, DEF_STR( Difficulty ) )
	PORT_DIPSETTING(    0x04, DEF_STR( Harder ) )
	PORT_DIPSETTING(    0x08, DEF_STR( Hardest ) )
	PORT_DIPSETTING(    0x0c, DEF_STR( Easiest ) )
 	PORT_DIPSETTING(    0x1c, DEF_STR( Normal ) )
	PORT_DIPSETTING(    0x10, DEF_STR( Hard ) )
	PORT_DIPSETTING(    0x14, DEF_STR( Easier ) )
 	PORT_DIPSETTING(    0x18, DEF_STR( Easy ) )
	PORT_DIPSETTING(    0x00, "Extra Hardest" )
	PORT_DIPNAME( 0x40, 0x40, "Coin Chute" )
	PORT_DIPSETTING(    0x00, "Common" )
	PORT_DIPSETTING(    0x40, "Individual" )
	PORT_DIPNAME( 0x80, 0x80, DEF_STR( Unused ) )
	PORT_DIPSETTING(    0x80, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )

	PORT_START_TAG("GUNX1")
	PORT_BIT( 0xff, 0x80, IPT_LIGHTGUN_X ) PORT_MINMAX(0,255) PORT_SENSITIVITY(50) PORT_KEYDELTA(5)

	PORT_START_TAG("GUNY1")
	PORT_BIT( 0xff, 0x80, IPT_LIGHTGUN_Y ) PORT_MINMAX(0,255) PORT_SENSITIVITY(50) PORT_KEYDELTA(5)

	PORT_START_TAG("GUNX2")
	PORT_BIT( 0xff, 0x80, IPT_LIGHTGUN_X ) PORT_MINMAX(0,255) PORT_SENSITIVITY(50) PORT_KEYDELTA(5) PORT_PLAYER(2)

	PORT_START_TAG("GUNY2")
	PORT_BIT( 0xff, 0x80, IPT_LIGHTGUN_Y ) PORT_MINMAX(0,255) PORT_SENSITIVITY(50) PORT_KEYDELTA(5) PORT_PLAYER(2)

	PORT_START_TAG("GUNX3")
	PORT_BIT( 0xff, 0x80, IPT_LIGHTGUN_X ) PORT_MINMAX(0,255) PORT_SENSITIVITY(50) PORT_KEYDELTA(5) PORT_PLAYER(3)

	PORT_START_TAG("GUNY3")
	PORT_BIT( 0xff, 0x80, IPT_LIGHTGUN_Y ) PORT_MINMAX(0,255) PORT_SENSITIVITY(50) PORT_KEYDELTA(5) PORT_PLAYER(3)
INPUT_PORTS_END


static INPUT_PORTS_START( mwalk )
	PORT_INCLUDE( system18_generic )

	PORT_MODIFY("PORTC")
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_PLAYER(3)
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_BUTTON2 ) PORT_PLAYER(3)
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_BUTTON3 ) PORT_PLAYER(3)
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_START3 )
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN ) PORT_8WAY PORT_PLAYER(3)
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_JOYSTICK_UP ) PORT_8WAY PORT_PLAYER(3)
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT ) PORT_8WAY PORT_PLAYER(3)
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT ) PORT_8WAY PORT_PLAYER(3)

	PORT_MODIFY("SERVICE")
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_COIN3 ) // individual mode
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_COIN2 )
	PORT_SERVICE_NO_TOGGLE( 0x04, IP_ACTIVE_LOW )
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_SERVICE1 )
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_START1 )
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_START2 )
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_SERVICE2 )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_COIN1 ) // individual mode

	PORT_MODIFY("DSW")
	PORT_DIPNAME( 0x01, 0x01, "2 Credits to Start" )
	PORT_DIPSETTING(    0x01, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x02, 0x00, DEF_STR( Demo_Sounds ) )
	PORT_DIPSETTING(    0x02, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x04, 0x00, DEF_STR( Lives) )
	PORT_DIPSETTING(    0x04, "2" )
	PORT_DIPSETTING(    0x00, "3" )
	PORT_DIPNAME( 0x08, 0x00, "Player Vitality" )
	PORT_DIPSETTING(    0x08, DEF_STR( Low ) )
	PORT_DIPSETTING(    0x00, DEF_STR( High ) )
	PORT_DIPNAME( 0x10, 0x00, "Play Mode" )
	PORT_DIPSETTING(    0x10, "2 Players" )
	PORT_DIPSETTING(    0x00, "3 Players" )
	PORT_DIPNAME( 0x20, 0x00, "Coin Chute" )
	PORT_DIPSETTING(    0x20, "Common" )
	PORT_DIPSETTING(    0x00, "Individual" )
	PORT_DIPNAME( 0xc0, 0x40, DEF_STR( Difficulty ) )
	PORT_DIPSETTING(    0x80, DEF_STR( Easy ) )
	PORT_DIPSETTING(    0xc0, DEF_STR( Normal ) )
	PORT_DIPSETTING(    0x40, DEF_STR( Hard ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Hardest ) )
INPUT_PORTS_END

static INPUT_PORTS_START( mwalka )
	PORT_INCLUDE( mwalk )

	PORT_MODIFY("DSW")
	PORT_DIPNAME( 0x10, 0x10, "Play Mode" )
	PORT_DIPSETTING(    0x00, "2 Players" )
	PORT_DIPSETTING(    0x10, "3 Players" )
	PORT_DIPNAME( 0x20, 0x20, "Coin Chute" )
	PORT_DIPSETTING(    0x00, "Common" )
	PORT_DIPSETTING(    0x20, "Individual" )
INPUT_PORTS_END


static INPUT_PORTS_START( shdancer )
	PORT_INCLUDE( system18_generic )

	PORT_MODIFY("DSW")
	PORT_DIPNAME( 0x01, 0x01, "2 Credits to Start" )
	PORT_DIPSETTING(    0x01, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x02, 0x00, DEF_STR( Demo_Sounds ) )
	PORT_DIPSETTING(    0x02, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x0c, 0x0c, DEF_STR( Lives ) )
	PORT_DIPSETTING(    0x00, "2" )
	PORT_DIPSETTING(    0x0c, "3" )
	PORT_DIPSETTING(    0x08, "4" )
	PORT_DIPSETTING(    0x04, "5" )
	PORT_DIPNAME( 0x30, 0x30, DEF_STR( Difficulty ) )
	PORT_DIPSETTING(    0x20, DEF_STR( Easy ) )
	PORT_DIPSETTING(    0x30, DEF_STR( Normal ) )
	PORT_DIPSETTING(    0x10, DEF_STR( Hard ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Hardest ) )
	PORT_DIPNAME( 0xc0, 0xc0, "Time Adjust" )
	PORT_DIPSETTING(    0x00, "2.20" )
	PORT_DIPSETTING(    0x40, "2.40" )
	PORT_DIPSETTING(    0xc0, "3.00" )
	PORT_DIPSETTING(    0x80, "3.30" )
INPUT_PORTS_END


static INPUT_PORTS_START( wwally )
	PORT_INCLUDE( system18_generic )

	PORT_MODIFY("DSW")
	PORT_DIPNAME( 0x01, 0x01, "2 Credits to Start" )
	PORT_DIPSETTING(    0x01, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x02, 0x00, DEF_STR( Demo_Sounds ) )
	PORT_DIPSETTING(    0x02, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x04, 0x04, "Coin Chute" )
	PORT_DIPSETTING(    0x04, "Common" )
	PORT_DIPSETTING(    0x00, "Individual" )
	PORT_DIPNAME( 0x60, 0x60, DEF_STR( Difficulty ) )
	PORT_DIPSETTING(    0x40, DEF_STR( Easy ) )
	PORT_DIPSETTING(    0x60, DEF_STR( Normal ) )
	PORT_DIPSETTING(    0x20, DEF_STR( Hard ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Hardest ) )

	PORT_START_TAG("TRACKX1")
	PORT_BIT( 0xff, 0x80, IPT_TRACKBALL_X ) PORT_SENSITIVITY(75) PORT_KEYDELTA(5) PORT_REVERSE

	PORT_START_TAG("TRACKY1")
	PORT_BIT( 0xff, 0x80, IPT_TRACKBALL_Y ) PORT_SENSITIVITY(75) PORT_KEYDELTA(5)

	PORT_START_TAG("TRACKX2")
	PORT_BIT( 0xff, 0x80, IPT_TRACKBALL_X ) PORT_SENSITIVITY(75) PORT_KEYDELTA(5) PORT_PLAYER(2) PORT_REVERSE

	PORT_START_TAG("TRACKY2")
	PORT_BIT( 0xff, 0x80, IPT_TRACKBALL_Y ) PORT_SENSITIVITY(75) PORT_KEYDELTA(5) PORT_PLAYER(2)

	PORT_START_TAG("TRACKX3")
	PORT_BIT( 0xff, 0x80, IPT_TRACKBALL_X ) PORT_SENSITIVITY(75) PORT_KEYDELTA(5) PORT_PLAYER(3) PORT_REVERSE

	PORT_START_TAG("TRACKY3")
	PORT_BIT( 0xff, 0x80, IPT_TRACKBALL_Y ) PORT_SENSITIVITY(75) PORT_KEYDELTA(5) PORT_PLAYER(3)
INPUT_PORTS_END



/*************************************
 *
 *  Game driver(s)
 *
 *************************************/

GAME( 1990, astorm,   0,        system18,      astorm2p, generic_5874, ROT0,   "Sega",    "Alien Storm (set 4, 2 Players, FD1094 317-?)", GAME_NOT_WORKING ) // not decrypted
GAME( 1990, astorm3,  astorm,   system18,      astorm,   generic_5874, ROT0,   "Sega",    "Alien Storm (set 3, World, 3 Players, FD1094 317-0148)", 0 )
GAME( 1990, astormu,  astorm,   system18,      astorm,   generic_5874, ROT0,   "Sega",    "Alien Storm (set 2, US, 3 Players, FD1094 317-0147)", 0 )
GAME( 1990, astormj,  astorm,   system18,      astorm2p, generic_5874, ROT0,   "Sega",    "Alien Storm (set 1, Japan, 2 Players, FD1094 317-0146)", 0 )
GAME( 1990, bloxeed,  0,        system18,      bloxeed,  generic_5874, ROT0,   "Sega",    "Bloxeed (Japan, FD1094 317-0139)", 0 )
GAME( 1991, cltchitr, 0,        system18,      cltchitr, generic_5987, ROT0,   "Sega",    "Clutch Hitter (set 2, US, FD1094 317-0176)", 0 )
GAME( 1991, cltchtrj, cltchitr, system18,      cltchitr, generic_5987, ROT0,   "Sega",    "Clutch Hitter (set 1, Japan, FD1094 317-0175)", 0 )
GAME( 1992, desertbr, 0,        system18,      desertbr, generic_5987, ROT270, "Sega",    "Desert Breaker (FD1094 317-0196)", 0 )
GAME( 1991, ddcrew,   0,        system18,      ddcrew,   ddcrew,       ROT0,   "Sega",    "D. D. Crew (set 4, World, 3 Player, FD1094 317-0190)", 0 )
GAME( 1991, ddcrewu,  ddcrew,   system18,      ddcrew,   ddcrew,       ROT0,   "Sega",    "D. D. Crew (set 3, US, 4 Player, FD1094 317-0186)", 0 )
GAME( 1991, ddcrew2,  ddcrew,   system18,      ddcrew2p, ddcrew,       ROT0,   "Sega",    "D. D. Crew (set 2, World, 2 Player, FD1094 317-0184)", 0 )
GAME( 1991, ddcrew1,  ddcrew,   system18,      ddcrew,   ddcrew,       ROT0,   "Sega",    "D. D. Crew (set 1, World, 4 Player, FD1094 317-?)", 0 )
GAME( 1991, ddcrewj,  ddcrew,   system18,      ddcrew2p, ddcrew,       ROT0,   "Sega",    "D. D. Crew (set 5, Japan, 2 Player, FD1094 317-0182)", 0 )
GAME( 1990, lghost,   0,        lghost,        lghost,   lghost,       ROT0,   "Sega",    "Laser Ghost (set 2, World, 317-0166)", 0 )
GAME( 1990, lghostu,  lghost,   lghost,        lghost,   lghost,       ROT0,   "Sega",    "Laser Ghost (set 1, US, 317-0165)", 0 )
GAME( 1990, mwalk,    0,        system18_8751, mwalk,    generic_5874, ROT0,   "Sega",    "Michael Jackson's Moonwalker (set 3, World, FD1094/8751 317-0159)", 0 )
GAME( 1990, mwalku,   mwalk,    system18_8751, mwalka,   generic_5874, ROT0,   "Sega",    "Michael Jackson's Moonwalker (set 2, US, FD1094/8751 317-0158)", 0 )
GAME( 1990, mwalkj,   mwalk,    system18_8751, mwalk,    generic_5874, ROT0,   "Sega",    "Michael Jackson's Moonwalker (set 1, Japan, FD1094/8751 317-0157)", 0 )
GAME( 1989, pontoon,  0,        system18,      shdancer, generic_5874, ROT0,   "Sega",    "Pontoon", GAME_NOT_WORKING )
GAME( 1989, shdancer, 0,        system18,      shdancer, generic_shad, ROT0,   "Sega",    "Shadow Dancer (set 3, US)" , 0 )
GAME( 1989, shdancej, shdancer, system18,      shdancer, generic_shad, ROT0,   "Sega",    "Shadow Dancer (set 2, Japan)", 0 )
GAME( 1989, shdance1, shdancer, system18,      shdancer, generic_shad, ROT0,   "Sega",    "Shadow Dancer (set 1)", 0 )
GAME( 1992, wwallyj,  0,        system18,      wwally,   wwally,       ROT0,   "Sega",    "Wally wo Sagase! (rev B, Japan, FD1094 317-0197B)" , 0) /* the roms do contain an english logo so maybe there is a world / us set too */
GAME( 1992, wwallyja, wwallyj,  system18,      wwally,   wwally,       ROT0,   "Sega",    "Wally wo Sagase! (rev A, Japan, FD1094 317-0197A)", 0 )
