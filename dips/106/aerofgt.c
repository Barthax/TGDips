INPUT_PORTS_START( pspikes )
	PORT_START_TAG("IN0")
	PORT_BIT( 0x0001, IP_ACTIVE_LOW, IPT_JOYSTICK_UP ) PORT_8WAY PORT_PLAYER(2)
	PORT_BIT( 0x0002, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN ) PORT_8WAY PORT_PLAYER(2)
	PORT_BIT( 0x0004, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT ) PORT_8WAY PORT_PLAYER(2)
	PORT_BIT( 0x0008, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT ) PORT_8WAY PORT_PLAYER(2)
	PORT_BIT( 0x0010, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_PLAYER(2)
	PORT_BIT( 0x0020, IP_ACTIVE_LOW, IPT_BUTTON2 ) PORT_PLAYER(2)
	PORT_BIT( 0x0040, IP_ACTIVE_LOW, IPT_BUTTON3 ) PORT_PLAYER(2)
	PORT_BIT( 0x0080, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x0100, IP_ACTIVE_LOW, IPT_COIN1 )
	PORT_BIT( 0x0200, IP_ACTIVE_LOW, IPT_COIN2 )
	PORT_BIT( 0x0400, IP_ACTIVE_LOW, IPT_START1 )
	PORT_BIT( 0x0800, IP_ACTIVE_LOW, IPT_START2 )
	PORT_BIT( 0x1000, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x2000, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x4000, IP_ACTIVE_LOW, IPT_COIN3 )
	PORT_BIT( 0x8000, IP_ACTIVE_LOW, IPT_UNKNOWN )

	PORT_START_TAG("IN1")
	PORT_BIT( 0x0001, IP_ACTIVE_LOW, IPT_JOYSTICK_UP ) PORT_8WAY
	PORT_BIT( 0x0002, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN ) PORT_8WAY
	PORT_BIT( 0x0004, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT ) PORT_8WAY
	PORT_BIT( 0x0008, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT ) PORT_8WAY
	PORT_BIT( 0x0010, IP_ACTIVE_LOW, IPT_BUTTON1 )
	PORT_BIT( 0x0020, IP_ACTIVE_LOW, IPT_BUTTON2 )
	PORT_BIT( 0x0040, IP_ACTIVE_LOW, IPT_BUTTON3 )
	PORT_BIT( 0x0080, IP_ACTIVE_LOW, IPT_UNKNOWN )

	PORT_START_TAG("DSW")
	PORT_DIPNAME( 0x0003, 0x0003, DEF_STR( Coin_A ) )
	PORT_DIPSETTING(      0x0001, DEF_STR( 3C_1C ) )
	PORT_DIPSETTING(      0x0002, DEF_STR( 2C_1C ) )
	PORT_DIPSETTING(      0x0003, DEF_STR( 1C_1C ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( 1C_2C ) )
	PORT_DIPNAME( 0x000c, 0x000c, DEF_STR( Coin_B ) )
	PORT_DIPSETTING(      0x0004, DEF_STR( 3C_1C ) )
	PORT_DIPSETTING(      0x0008, DEF_STR( 2C_1C ) )
	PORT_DIPSETTING(      0x000c, DEF_STR( 1C_1C ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( 1C_2C ) )
	/* the following two select country in the Chinese version (ROMs not available) */
	PORT_DIPNAME( 0x0010, 0x0010, DEF_STR( Unknown ) )
	PORT_DIPSETTING(      0x0010, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( On ) )
	PORT_DIPNAME( 0x0020, 0x0020, DEF_STR( Unknown ) )
	PORT_DIPSETTING(      0x0020, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( On ) )
	PORT_DIPNAME( 0x0040, 0x0000, DEF_STR( Demo_Sounds ) )
	PORT_DIPSETTING(      0x0040, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( On ) )
	PORT_DIPNAME( 0x0080, 0x0080, DEF_STR( Flip_Screen ) )
	PORT_DIPSETTING(      0x0080, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( On ) )
	PORT_SERVICE( 0x0100, IP_ACTIVE_LOW )
	PORT_DIPNAME( 0x0600, 0x0600, "1 Player Starting Score" )
	PORT_DIPSETTING(      0x0600, "12-12" )
	PORT_DIPSETTING(      0x0400, "11-11" )
	PORT_DIPSETTING(      0x0200, "11-12" )
	PORT_DIPSETTING(      0x0000, "10-12" )
	PORT_DIPNAME( 0x1800, 0x1800, "2 Players Starting Score" )
	PORT_DIPSETTING(      0x1800, "9-9" )
	PORT_DIPSETTING(      0x1000, "7-7" )
	PORT_DIPSETTING(      0x0800, "5-5" )
	PORT_DIPSETTING(      0x0000, "0-0" )
	PORT_DIPNAME( 0x2000, 0x2000, DEF_STR( Difficulty ) )
	PORT_DIPSETTING(      0x2000, DEF_STR( Normal ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( Hard ) )
	PORT_DIPNAME( 0x4000, 0x4000, "2 Players Time per Credit" )
	PORT_DIPSETTING(      0x4000, "3 min" )
	PORT_DIPSETTING(      0x0000, "2 min" )
	PORT_DIPNAME( 0x8000, 0x8000, "Debug" )
	PORT_DIPSETTING(      0x8000, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( On ) )
INPUT_PORTS_END

INPUT_PORTS_START( pspikesb )
	PORT_START_TAG("IN0")
	PORT_BIT( 0x0001, IP_ACTIVE_LOW, IPT_JOYSTICK_UP ) PORT_8WAY
	PORT_BIT( 0x0002, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN ) PORT_8WAY
	PORT_BIT( 0x0004, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT ) PORT_8WAY
	PORT_BIT( 0x0008, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT ) PORT_8WAY
	PORT_BIT( 0x0010, IP_ACTIVE_LOW, IPT_BUTTON1 )
	PORT_BIT( 0x0020, IP_ACTIVE_LOW, IPT_BUTTON2 )
	PORT_BIT( 0x0040, IP_ACTIVE_LOW, IPT_BUTTON3 )
	PORT_BIT( 0x0080, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x0100, IP_ACTIVE_LOW, IPT_COIN1 )
	PORT_BIT( 0x0200, IP_ACTIVE_LOW, IPT_COIN2 )
	PORT_BIT( 0x0400, IP_ACTIVE_LOW, IPT_START1 )
	PORT_BIT( 0x0800, IP_ACTIVE_LOW, IPT_START2 )
	PORT_BIT( 0x1000, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x2000, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x4000, IP_ACTIVE_LOW, IPT_COIN3 )
	PORT_BIT( 0x8000, IP_ACTIVE_LOW, IPT_UNKNOWN )

	PORT_START_TAG("IN1")
	PORT_BIT( 0x0001, IP_ACTIVE_LOW, IPT_JOYSTICK_UP ) PORT_8WAY PORT_PLAYER(2)
	PORT_BIT( 0x0002, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN ) PORT_8WAY PORT_PLAYER(2)
	PORT_BIT( 0x0004, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT ) PORT_8WAY PORT_PLAYER(2)
	PORT_BIT( 0x0008, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT ) PORT_8WAY PORT_PLAYER(2)
	PORT_BIT( 0x0010, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_PLAYER(2)
	PORT_BIT( 0x0020, IP_ACTIVE_LOW, IPT_BUTTON2 ) PORT_PLAYER(2)
	PORT_BIT( 0x0040, IP_ACTIVE_LOW, IPT_BUTTON3 ) PORT_PLAYER(2)
	PORT_BIT( 0x0080, IP_ACTIVE_LOW, IPT_UNKNOWN )

	PORT_START_TAG("DSW")
	PORT_DIPNAME( 0x0003, 0x0003, DEF_STR( Coin_A ) )
	PORT_DIPSETTING(      0x0001, DEF_STR( 3C_1C ) )
	PORT_DIPSETTING(      0x0002, DEF_STR( 2C_1C ) )
	PORT_DIPSETTING(      0x0003, DEF_STR( 1C_1C ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( 1C_2C ) )
	PORT_DIPNAME( 0x000c, 0x000c, DEF_STR( Coin_B ) )
	PORT_DIPSETTING(      0x0004, DEF_STR( 3C_1C ) )
	PORT_DIPSETTING(      0x0008, DEF_STR( 2C_1C ) )
	PORT_DIPSETTING(      0x000c, DEF_STR( 1C_1C ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( 1C_2C ) )
	/* the following two select country in the Chinese version (ROMs not available) */
	PORT_DIPNAME( 0x0010, 0x0010, DEF_STR( Unknown ) )
	PORT_DIPSETTING(      0x0010, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( On ) )
	PORT_DIPNAME( 0x0020, 0x0020, DEF_STR( Unknown ) )
	PORT_DIPSETTING(      0x0020, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( On ) )
	PORT_DIPNAME( 0x0040, 0x0000, DEF_STR( Demo_Sounds ) )
	PORT_DIPSETTING(      0x0040, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( On ) )
	PORT_DIPNAME( 0x0080, 0x0080, DEF_STR( Unused ) )
	PORT_DIPSETTING(      0x0080, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( On ) )
	PORT_DIPNAME( 0x0100, 0x0100, DEF_STR( Unused ) )
	PORT_DIPSETTING(      0x0100, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( On ) )
	PORT_DIPNAME( 0x0600, 0x0600, "1 Player Starting Score" )
	PORT_DIPSETTING(      0x0600, "12-12" )
	PORT_DIPSETTING(      0x0400, "11-11" )
	PORT_DIPSETTING(      0x0200, "11-12" )
	PORT_DIPSETTING(      0x0000, "10-12" )
	PORT_DIPNAME( 0x1800, 0x1800, "2 Players Starting Score" )
	PORT_DIPSETTING(      0x1800, "9-9" )
	PORT_DIPSETTING(      0x1000, "7-7" )
	PORT_DIPSETTING(      0x0800, "5-5" )
	PORT_DIPSETTING(      0x0000, "0-0" )
	PORT_DIPNAME( 0x2000, 0x2000, DEF_STR( Difficulty ) )
	PORT_DIPSETTING(      0x2000, DEF_STR( Normal ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( Hard ) )
	PORT_DIPNAME( 0x4000, 0x4000, "2 Players Time per Credit" )
	PORT_DIPSETTING(      0x4000, "3 min" )
	PORT_DIPSETTING(      0x0000, "2 min" )
	PORT_DIPNAME( 0x8000, 0x8000, "Debug" )
	PORT_DIPSETTING(      0x8000, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( On ) )
INPUT_PORTS_END

INPUT_PORTS_START( karatblz )
	PORT_START_TAG("IN0")
	PORT_BIT( 0x0001, IP_ACTIVE_LOW, IPT_JOYSTICK_UP ) PORT_8WAY
	PORT_BIT( 0x0002, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN ) PORT_8WAY
	PORT_BIT( 0x0004, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT ) PORT_8WAY
	PORT_BIT( 0x0008, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT ) PORT_8WAY
	PORT_BIT( 0x0010, IP_ACTIVE_LOW, IPT_BUTTON1 )
	PORT_BIT( 0x0020, IP_ACTIVE_LOW, IPT_BUTTON2 )
	PORT_BIT( 0x0040, IP_ACTIVE_LOW, IPT_BUTTON3 )
	PORT_BIT( 0x0080, IP_ACTIVE_LOW, IPT_BUTTON4 )
	PORT_BIT( 0x0100, IP_ACTIVE_LOW, IPT_COIN1 )
	PORT_BIT( 0x0200, IP_ACTIVE_LOW, IPT_COIN2 )
	PORT_BIT( 0x0400, IP_ACTIVE_LOW, IPT_START1 )
	PORT_BIT( 0x0800, IP_ACTIVE_LOW, IPT_START2 )
	PORT_BIT( 0x1000, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x2000, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x4000, IP_ACTIVE_LOW, IPT_SERVICE1 )
	PORT_BIT( 0x8000, IP_ACTIVE_LOW, IPT_UNKNOWN )

	PORT_START_TAG("IN1")
	PORT_BIT( 0x0001, IP_ACTIVE_LOW, IPT_JOYSTICK_UP ) PORT_8WAY PORT_PLAYER(2)
	PORT_BIT( 0x0002, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN ) PORT_8WAY PORT_PLAYER(2)
	PORT_BIT( 0x0004, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT ) PORT_8WAY PORT_PLAYER(2)
	PORT_BIT( 0x0008, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT ) PORT_8WAY PORT_PLAYER(2)
	PORT_BIT( 0x0010, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_PLAYER(2)
	PORT_BIT( 0x0020, IP_ACTIVE_LOW, IPT_BUTTON2 ) PORT_PLAYER(2)
	PORT_BIT( 0x0040, IP_ACTIVE_LOW, IPT_BUTTON3 ) PORT_PLAYER(2)
	PORT_BIT( 0x0080, IP_ACTIVE_LOW, IPT_BUTTON4 ) PORT_PLAYER(2)

	PORT_START_TAG("IN2")
	PORT_BIT( 0x0001, IP_ACTIVE_LOW, IPT_JOYSTICK_UP ) PORT_8WAY PORT_PLAYER(3)
	PORT_BIT( 0x0002, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN ) PORT_8WAY PORT_PLAYER(3)
	PORT_BIT( 0x0004, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT ) PORT_8WAY PORT_PLAYER(3)
	PORT_BIT( 0x0008, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT ) PORT_8WAY PORT_PLAYER(3)
	PORT_BIT( 0x0010, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_PLAYER(3)
	PORT_BIT( 0x0020, IP_ACTIVE_LOW, IPT_BUTTON2 ) PORT_PLAYER(3)
	PORT_BIT( 0x0040, IP_ACTIVE_LOW, IPT_BUTTON3 ) PORT_PLAYER(3)
	PORT_BIT( 0x0080, IP_ACTIVE_LOW, IPT_BUTTON4 ) PORT_PLAYER(3)
	PORT_BIT( 0x0100, IP_ACTIVE_LOW, IPT_COIN3 )
	PORT_BIT( 0x0200, IP_ACTIVE_LOW, IPT_COIN4 )
	PORT_BIT( 0x0400, IP_ACTIVE_LOW, IPT_START3 )
	PORT_BIT( 0x0800, IP_ACTIVE_LOW, IPT_START4 )
	PORT_BIT( 0x1000, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x2000, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x4000, IP_ACTIVE_LOW, IPT_SERVICE2 )
	PORT_BIT( 0x8000, IP_ACTIVE_LOW, IPT_UNKNOWN )

	PORT_START_TAG("IN3")
	PORT_BIT( 0x0001, IP_ACTIVE_LOW, IPT_JOYSTICK_UP ) PORT_8WAY PORT_PLAYER(4)
	PORT_BIT( 0x0002, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN ) PORT_8WAY PORT_PLAYER(4)
	PORT_BIT( 0x0004, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT ) PORT_8WAY PORT_PLAYER(4)
	PORT_BIT( 0x0008, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT ) PORT_8WAY PORT_PLAYER(4)
	PORT_BIT( 0x0010, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_PLAYER(4)
	PORT_BIT( 0x0020, IP_ACTIVE_LOW, IPT_BUTTON2 ) PORT_PLAYER(4)
	PORT_BIT( 0x0040, IP_ACTIVE_LOW, IPT_BUTTON3 ) PORT_PLAYER(4)
	PORT_BIT( 0x0080, IP_ACTIVE_LOW, IPT_BUTTON4 ) PORT_PLAYER(4)

	PORT_START_TAG("DSW")
	PORT_DIPNAME( 0x0007, 0x0007, DEF_STR( Coinage ) ) /* Coins 1, 2, 3 & 4 */
	PORT_DIPSETTING(      0x0004, DEF_STR( 4C_1C ) )
	PORT_DIPSETTING(      0x0005, DEF_STR( 3C_1C ) )
	PORT_DIPSETTING(      0x0006, DEF_STR( 2C_1C ) )
	PORT_DIPSETTING(      0x0007, DEF_STR( 1C_1C ) )
	PORT_DIPSETTING(      0x0003, DEF_STR( 1C_2C ) )
	PORT_DIPSETTING(      0x0002, DEF_STR( 1C_3C ) )
	PORT_DIPSETTING(      0x0001, DEF_STR( 1C_5C ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( 1C_6C ) )
	PORT_DIPNAME( 0x0008, 0x0008, "2 Coins to Start, 1 to Continue" )
	PORT_DIPSETTING(      0x0008, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( On ) )
	PORT_DIPNAME( 0x0010, 0x0010, DEF_STR( Lives ) )
	PORT_DIPSETTING(      0x0000, "1" )
	PORT_DIPSETTING(      0x0010, "2" )
	PORT_DIPNAME( 0x0060, 0x0060, DEF_STR( Cabinet ) )	/* Game Type */
	PORT_DIPSETTING(      0x0060, "2 Players" )		/* 1 Unit / 2 Players */
	PORT_DIPSETTING(      0x0040, "3 Players" )		/* 1 Unit / 3 Players */
	PORT_DIPSETTING(      0x0020, "4 Players" )		/* 1 Unit / 4 Players */
	PORT_DIPSETTING(      0x0000, "4 Players (Team)" )	/* 2 Units / 4 Players */
	/*  With 4 player (Team) selected and Same Coin Slot:
        Coin A & B credit together for use by _only_ player 1 or player 2
        Coin C & D credit together for use by _only_ player 3 or player 4
        Otherwise with Individual selected, everyone is seperate  */
	PORT_DIPNAME( 0x0080, 0x0080, "Coin Slot" )
	PORT_DIPSETTING(      0x0080, "Same" )
	PORT_DIPSETTING(      0x0000, "Individual" )
	PORT_SERVICE( 0x0100, IP_ACTIVE_LOW )
	PORT_DIPNAME( 0x0600, 0x0200, "Number of Enemies" ) /* Default is DEF_STR( Hard ) */
	PORT_DIPSETTING(      0x0400, DEF_STR( Easy ) )
	PORT_DIPSETTING(      0x0600, DEF_STR( Normal ) )
	PORT_DIPSETTING(      0x0200, DEF_STR( Hard ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( Hardest ) )
	PORT_DIPNAME( 0x1800, 0x0800, "Strength of Enemies" ) /* Default is DEF_STR( Hard ) */
	PORT_DIPSETTING(      0x1000, DEF_STR( Easy ) )
	PORT_DIPSETTING(      0x1800, DEF_STR( Normal ) )
	PORT_DIPSETTING(      0x0800, DEF_STR( Hard ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( Hardest ) )
	PORT_DIPNAME( 0x2000, 0x2000, "Freeze" )	/* Listed in manual as N.C. (aka No Connection) */
	PORT_DIPSETTING(      0x2000, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( On ) )
	PORT_DIPNAME( 0x4000, 0x0000, DEF_STR( Demo_Sounds ) )
	PORT_DIPSETTING(      0x4000, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( On ) )
	PORT_DIPNAME( 0x8000, 0x8000, DEF_STR( Flip_Screen ) )
	PORT_DIPSETTING(      0x8000, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( On ) )
INPUT_PORTS_END

INPUT_PORTS_START( spinlbrk )
	PORT_START_TAG("IN0")
	PORT_BIT( 0x0001, IP_ACTIVE_LOW, IPT_JOYSTICK_UP ) PORT_8WAY PORT_PLAYER(1)
	PORT_BIT( 0x0002, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN ) PORT_8WAY PORT_PLAYER(1)
	PORT_BIT( 0x0004, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT ) PORT_8WAY PORT_PLAYER(1)
	PORT_BIT( 0x0008, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT ) PORT_8WAY PORT_PLAYER(1)
	PORT_BIT( 0x0010, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_PLAYER(1)
	PORT_BIT( 0x0020, IP_ACTIVE_LOW, IPT_BUTTON2 ) PORT_PLAYER(1)
	PORT_BIT( 0x0040, IP_ACTIVE_LOW, IPT_BUTTON3 ) PORT_PLAYER(1)
	PORT_BIT( 0x0080, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x0100, IP_ACTIVE_LOW, IPT_COIN1 )
	PORT_BIT( 0x0200, IP_ACTIVE_LOW, IPT_COIN2 )
	PORT_BIT( 0x0400, IP_ACTIVE_LOW, IPT_START1 )
	PORT_BIT( 0x0800, IP_ACTIVE_LOW, IPT_START2 )
	PORT_BIT( 0x1000, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x2000, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x4000, IP_ACTIVE_LOW, IPT_SERVICE1 )
	PORT_BIT( 0x8000, IP_ACTIVE_LOW, IPT_UNKNOWN )

	PORT_START_TAG("IN1")
	PORT_BIT( 0x0001, IP_ACTIVE_LOW, IPT_JOYSTICK_UP ) PORT_8WAY PORT_PLAYER(2)
	PORT_BIT( 0x0002, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN ) PORT_8WAY PORT_PLAYER(2)
	PORT_BIT( 0x0004, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT ) PORT_8WAY PORT_PLAYER(2)
	PORT_BIT( 0x0008, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT ) PORT_8WAY PORT_PLAYER(2)
	PORT_BIT( 0x0010, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_PLAYER(2)
	PORT_BIT( 0x0020, IP_ACTIVE_LOW, IPT_BUTTON2 ) PORT_PLAYER(2)
	PORT_BIT( 0x0040, IP_ACTIVE_LOW, IPT_BUTTON3 ) PORT_PLAYER(2)
	PORT_BIT( 0x0080, IP_ACTIVE_LOW, IPT_UNKNOWN )

	PORT_START_TAG("DSW")
	PORT_DIPNAME( 0x000f, 0x000f, DEF_STR( Coin_A ) )
	PORT_DIPSETTING(      0x000f, "1 Credit 1 Health Pack" )	/* I chose "Health Packs" as the actual value can change */
	PORT_DIPSETTING(      0x000e, "1 Credit 2 Health Packs" )	/*  via dipswitch 2-7 (0x4000) see below */
	PORT_DIPSETTING(      0x000d, "1 Credit 3 Health Packs" )
	PORT_DIPSETTING(      0x000c, "1 Credit 4 Health Packs" )
	PORT_DIPSETTING(      0x000b, "1 Credit 5 Health Packs" )
	PORT_DIPSETTING(      0x000a, "1 Credit 6 Health Packs" )
	PORT_DIPSETTING(      0x0009, "2 Credits 1 Health Pack" )
	PORT_DIPSETTING(      0x0008, "3 Credits 1 Health Pack" )
	PORT_DIPSETTING(      0x0007, "4 Credits 1 Health Pack" )
	PORT_DIPSETTING(      0x0006, "5 Credits 1 Health Pack" )
	PORT_DIPSETTING(      0x0005, "2 Credits 2 Health Packs" )
	PORT_DIPSETTING(      0x0004, "2-1-1C  1-1-1 HPs" )
	PORT_DIPSETTING(      0x0003, "2-2C 1-2 HPs" )
	PORT_DIPSETTING(      0x0002, "1-1-1-1-1C 1-1-1-1-2 HPs" )
	PORT_DIPSETTING(      0x0001, "1-1-1-1C 1-1-1-2 HPs" )
	PORT_DIPSETTING(      0x0000, "1-1C 1-2 HPs" )
/* The last 5 Coin/Credit selections are cycles:
    Example: 0x0004 = 2-1-1C 1-1-1 HPs:
    2 Credits for the 1st Health Pack, 1 Credit for the 2nd Health Pack, 1 Credit
    for the 3rd Health Pack... Then back to 2 Credits agian for 1 HP, then 1 credit
    and 1 credit.... on and on.  With all Coin/Credit dips set to on, it's 1 Health
    Pack for odd credits, 2 Health Packs for even credits :p
    */
	PORT_DIPNAME( 0x00f0, 0x00f0, DEF_STR( Coin_B ) )
	PORT_DIPSETTING(      0x00f0, "1 Credit 1 Health Pack" )
	PORT_DIPSETTING(      0x00e0, "1 Credit 2 Health Packs" )
	PORT_DIPSETTING(      0x00d0, "1 Credit 3 Health Packs" )
	PORT_DIPSETTING(      0x00c0, "1 Credit 4 Health Packs" )
	PORT_DIPSETTING(      0x00b0, "1 Credit 5 Health Packs" )
	PORT_DIPSETTING(      0x00a0, "1 Credit 6 Health Packs" )
	PORT_DIPSETTING(      0x0090, "2 Credits 1 Health Pack" )
	PORT_DIPSETTING(      0x0080, "3 Credits 1 Health Pack" )
	PORT_DIPSETTING(      0x0070, "4 Credits 1 Health Pack" )
	PORT_DIPSETTING(      0x0060, "5 Credits 1 Health Pack" )
	PORT_DIPSETTING(      0x0050, "2 Credits 2 Health Packs" )
	PORT_DIPSETTING(      0x0040, "2-1-1C  1-1-1 HPs" )
	PORT_DIPSETTING(      0x0030, "2-2C 1-2 HPs" )
	PORT_DIPSETTING(      0x0020, "1-1-1-1-1C 1-1-1-1-2 HPs" )
	PORT_DIPSETTING(      0x0010, "1-1-1-1C 1-1-1-2 HPs" )
	PORT_DIPSETTING(      0x0000, "1-1C 1-2 HPs" )
	PORT_DIPNAME( 0x0300, 0x0300, DEF_STR( Difficulty ) )
	PORT_DIPSETTING(      0x0300, DEF_STR( Normal ) )
	PORT_DIPSETTING(      0x0200, DEF_STR( Easy ) )
	PORT_DIPSETTING(      0x0100, DEF_STR( Hard ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( Hardest ) )
	PORT_DIPNAME( 0x0400, 0x0400, "Coin Slot" )
	PORT_DIPSETTING(      0x0000, "Same" )
	PORT_DIPSETTING(      0x0400, "Individual" )
	PORT_DIPNAME( 0x0800, 0x0800, DEF_STR( Flip_Screen ) )
	PORT_DIPSETTING(      0x0800, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( On ) )
	PORT_DIPNAME( 0x1000, 0x1000, "Lever Type" )
	PORT_DIPSETTING(      0x1000, "Digital" )
	PORT_DIPSETTING(      0x0000, "Analog" )		/* This setting causes lever error??? */
	PORT_SERVICE( 0x2000, IP_ACTIVE_LOW )
	PORT_DIPNAME( 0x4000, 0x4000, "Health Pack" )
	PORT_DIPSETTING(      0x4000, "32 Hitpoints" )
	PORT_DIPSETTING(      0x0000, "40 Hitpoints" )
	PORT_DIPNAME( 0x8000, 0x8000, "Life Restoration" )
	PORT_DIPSETTING(      0x8000, "10 Points" )
	PORT_DIPSETTING(      0x0000, "5 Points" )
INPUT_PORTS_END

INPUT_PORTS_START( spinlbrj )
	PORT_INCLUDE(spinlbrk)

	PORT_MODIFY("DSW")
	PORT_DIPNAME( 0x0400, 0x0400, DEF_STR( Allow_Continue ) )
	PORT_DIPSETTING(      0x0400, "Unlimited" )
	PORT_DIPSETTING(      0x0000, "6 Times" )
INPUT_PORTS_END

INPUT_PORTS_START( spinlbru )
	PORT_INCLUDE(spinlbrk)

	PORT_MODIFY("DSW")
	PORT_DIPNAME( 0x4000, 0x4000, "Health Pack" )
	PORT_DIPSETTING(      0x4000, "20 Hitpoints" )
	PORT_DIPSETTING(      0x0000, "32 Hitpoints" )
INPUT_PORTS_END

INPUT_PORTS_START( turbofrc )
	PORT_START_TAG("IN0")
	PORT_BIT( 0x0001, IP_ACTIVE_LOW, IPT_JOYSTICK_UP ) PORT_8WAY PORT_PLAYER(1)
	PORT_BIT( 0x0002, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN ) PORT_8WAY PORT_PLAYER(1)
	PORT_BIT( 0x0004, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT ) PORT_8WAY PORT_PLAYER(1)
	PORT_BIT( 0x0008, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT ) PORT_8WAY PORT_PLAYER(1)
	PORT_BIT( 0x0010, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_PLAYER(1)
	PORT_BIT( 0x0020, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x0040, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x0080, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x0100, IP_ACTIVE_LOW, IPT_COIN1 )
	PORT_BIT( 0x0200, IP_ACTIVE_LOW, IPT_COIN2 )
	PORT_BIT( 0x0400, IP_ACTIVE_LOW, IPT_START1 )
	PORT_BIT( 0x0800, IP_ACTIVE_LOW, IPT_START2 )
	PORT_BIT( 0x1000, IP_ACTIVE_LOW, IPT_SERVICE )	/* "TEST" */
	PORT_BIT( 0x2000, IP_ACTIVE_LOW, IPT_TILT )
	PORT_BIT( 0x4000, IP_ACTIVE_LOW, IPT_COIN4 )
	PORT_BIT( 0x8000, IP_ACTIVE_LOW, IPT_COIN3 )

	PORT_START_TAG("IN1")
	PORT_BIT( 0x0001, IP_ACTIVE_LOW, IPT_JOYSTICK_UP ) PORT_8WAY PORT_PLAYER(2)
	PORT_BIT( 0x0002, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN ) PORT_8WAY PORT_PLAYER(2)
	PORT_BIT( 0x0004, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT ) PORT_8WAY PORT_PLAYER(2)
	PORT_BIT( 0x0008, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT ) PORT_8WAY PORT_PLAYER(2)
	PORT_BIT( 0x0010, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_PLAYER(2)
	PORT_BIT( 0x0020, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x0040, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x0080, IP_ACTIVE_LOW, IPT_UNKNOWN )//START1 )

	PORT_START_TAG("DSW")
	PORT_DIPNAME( 0x0007, 0x0007, DEF_STR( Coinage ) ) /* Coins 1, 2 & 3 */
	PORT_DIPSETTING(      0x0004, DEF_STR( 4C_1C ) )
	PORT_DIPSETTING(      0x0005, DEF_STR( 3C_1C ) )
	PORT_DIPSETTING(      0x0006, DEF_STR( 2C_1C ) )
	PORT_DIPSETTING(      0x0007, DEF_STR( 1C_1C ) )
	PORT_DIPSETTING(      0x0003, DEF_STR( 1C_2C ) )
	PORT_DIPSETTING(      0x0002, DEF_STR( 1C_3C ) )
	PORT_DIPSETTING(      0x0001, DEF_STR( 1C_5C ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( 1C_6C ) )
	PORT_DIPNAME( 0x0008, 0x0008, "2 Coins to Start, 1 to Continue" )
	PORT_DIPSETTING(      0x0008, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( On ) )
	PORT_DIPNAME( 0x0010, 0x0000, "Coin Slot" )
	PORT_DIPSETTING(      0x0010, "Same" )
	PORT_DIPSETTING(      0x0000, "Individual" )
	PORT_DIPNAME( 0x0020, 0x0000, "Play Mode" )
	PORT_DIPSETTING(      0x0020, "2 Players" )
	PORT_DIPSETTING(      0x0000, "3 Players" )
	PORT_DIPNAME( 0x0040, 0x0000, DEF_STR( Demo_Sounds ) )
	PORT_DIPSETTING(      0x0040, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( On ) )
	PORT_SERVICE( 0x0080, IP_ACTIVE_LOW )
	PORT_DIPNAME( 0x0100, 0x0100, DEF_STR( Flip_Screen ) )
	PORT_DIPSETTING(      0x0100, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( On ) )
	PORT_DIPNAME( 0x0e00, 0x0800, DEF_STR( Difficulty ) )
	PORT_DIPSETTING(      0x0e00, "1 (Easiest)")
	PORT_DIPSETTING(      0x0c00, "2" )
	PORT_DIPSETTING(      0x0a00, "3" )
	PORT_DIPSETTING(      0x0800, "4 (Normal)" )
	PORT_DIPSETTING(      0x0600, "5" )
	PORT_DIPSETTING(      0x0400, "6" )
	PORT_DIPSETTING(      0x0200, "7" )
	PORT_DIPSETTING(      0x0000, "8 (Hardest)" )
	PORT_DIPNAME( 0x1000, 0x1000, DEF_STR( Lives ) )
	PORT_DIPSETTING(      0x0000, "2" )
	PORT_DIPSETTING(      0x1000, "3" )
	PORT_DIPNAME( 0x2000, 0x2000, DEF_STR( Bonus_Life ) )
	PORT_DIPSETTING(      0x2000, "200000" )
	PORT_DIPSETTING(      0x0000, "300000" )

	PORT_START_TAG("IN2")
	PORT_BIT( 0x0001, IP_ACTIVE_LOW, IPT_JOYSTICK_UP ) PORT_8WAY PORT_PLAYER(3)
	PORT_BIT( 0x0002, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN ) PORT_8WAY PORT_PLAYER(3)
	PORT_BIT( 0x0004, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT ) PORT_8WAY PORT_PLAYER(3)
	PORT_BIT( 0x0008, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT ) PORT_8WAY PORT_PLAYER(3)
	PORT_BIT( 0x0010, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_PLAYER(3)
	PORT_BIT( 0x0020, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x0040, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x0080, IP_ACTIVE_LOW, IPT_START3 )
INPUT_PORTS_END

INPUT_PORTS_START( aerofgtb )
	PORT_START_TAG("IN0")
	PORT_BIT( 0x0001, IP_ACTIVE_LOW, IPT_JOYSTICK_UP ) PORT_8WAY
	PORT_BIT( 0x0002, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN ) PORT_8WAY
	PORT_BIT( 0x0004, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT ) PORT_8WAY
	PORT_BIT( 0x0008, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT ) PORT_8WAY
	PORT_BIT( 0x0010, IP_ACTIVE_LOW, IPT_BUTTON1 )
	PORT_BIT( 0x0020, IP_ACTIVE_LOW, IPT_BUTTON2 )
	PORT_BIT( 0x0040, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x0080, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x0100, IP_ACTIVE_LOW, IPT_COIN1 )
	PORT_BIT( 0x0200, IP_ACTIVE_LOW, IPT_COIN2 )
	PORT_BIT( 0x0400, IP_ACTIVE_LOW, IPT_START1 )
	PORT_BIT( 0x0800, IP_ACTIVE_LOW, IPT_START2 )
	PORT_BIT( 0x1000, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x2000, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x4000, IP_ACTIVE_LOW, IPT_COIN3 )
	PORT_BIT( 0x8000, IP_ACTIVE_LOW, IPT_UNKNOWN )

	PORT_START_TAG("IN1")
	PORT_BIT( 0x0001, IP_ACTIVE_LOW, IPT_JOYSTICK_UP ) PORT_8WAY PORT_PLAYER(2)
	PORT_BIT( 0x0002, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN ) PORT_8WAY PORT_PLAYER(2)
	PORT_BIT( 0x0004, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT ) PORT_8WAY PORT_PLAYER(2)
	PORT_BIT( 0x0008, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT ) PORT_8WAY PORT_PLAYER(2)
	PORT_BIT( 0x0010, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_PLAYER(2)
	PORT_BIT( 0x0020, IP_ACTIVE_LOW, IPT_BUTTON2 ) PORT_PLAYER(2)
	PORT_BIT( 0x0040, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x0080, IP_ACTIVE_LOW, IPT_UNKNOWN )

	PORT_START_TAG("DSW1")
	PORT_DIPNAME( 0x0001, 0x0001, "Coin Slot" )
	PORT_DIPSETTING(      0x0001, "Same" )
	PORT_DIPSETTING(      0x0000, "Individual" )
	PORT_DIPNAME( 0x000e, 0x000e, DEF_STR( Coin_A ) )
	PORT_DIPSETTING(      0x000a, DEF_STR( 3C_1C ) )
	PORT_DIPSETTING(      0x000c, DEF_STR( 2C_1C ) )
	PORT_DIPSETTING(      0x000e, DEF_STR( 1C_1C ) )
	PORT_DIPSETTING(      0x0008, DEF_STR( 1C_2C ) )
	PORT_DIPSETTING(      0x0006, DEF_STR( 1C_3C ) )
	PORT_DIPSETTING(      0x0004, DEF_STR( 1C_4C ) )
	PORT_DIPSETTING(      0x0002, DEF_STR( 1C_5C ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( 1C_6C ) )
	PORT_DIPNAME( 0x0070, 0x0070, DEF_STR( Coin_B ) )
	PORT_DIPSETTING(      0x0050, DEF_STR( 3C_1C ) )
	PORT_DIPSETTING(      0x0060, DEF_STR( 2C_1C ) )
	PORT_DIPSETTING(      0x0070, DEF_STR( 1C_1C ) )
	PORT_DIPSETTING(      0x0040, DEF_STR( 1C_2C ) )
	PORT_DIPSETTING(      0x0030, DEF_STR( 1C_3C ) )
	PORT_DIPSETTING(      0x0020, DEF_STR( 1C_4C ) )
	PORT_DIPSETTING(      0x0010, DEF_STR( 1C_5C ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( 1C_6C ) )
	PORT_DIPNAME( 0x0080, 0x0080, "2 Coins to Start, 1 to Continue" )
	PORT_DIPSETTING(      0x0080, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( On ) )
	PORT_DIPNAME( 0x0100, 0x0100, DEF_STR( Flip_Screen ) )
	PORT_DIPSETTING(      0x0100, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( On ) )
	PORT_DIPNAME( 0x0200, 0x0000, DEF_STR( Demo_Sounds ) )
	PORT_DIPSETTING(      0x0200, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( On ) )
	PORT_DIPNAME( 0x0c00, 0x0c00, DEF_STR( Difficulty ) )
	PORT_DIPSETTING(      0x0800, DEF_STR( Easy ) )
	PORT_DIPSETTING(      0x0c00, DEF_STR( Normal ) )
	PORT_DIPSETTING(      0x0400, DEF_STR( Hard ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( Hardest ) )
	PORT_DIPNAME( 0x3000, 0x3000, DEF_STR( Lives ) )
	PORT_DIPSETTING(      0x2000, "1" )
	PORT_DIPSETTING(      0x1000, "2" )
	PORT_DIPSETTING(      0x3000, "3" )
	PORT_DIPSETTING(      0x0000, "4" )
	PORT_DIPNAME( 0x4000, 0x4000, DEF_STR( Bonus_Life ) )
	PORT_DIPSETTING(      0x4000, "200000" )
	PORT_DIPSETTING(      0x0000, "300000" )
	PORT_SERVICE( 0x8000, IP_ACTIVE_LOW )

	PORT_START_TAG("DSW2")
	PORT_DIPNAME( 0x0001, 0x0000, "Country" )
	PORT_DIPSETTING(      0x0000, DEF_STR( Japan ) )
	PORT_DIPSETTING(      0x0001, "Taiwan" )
	/* TODO: there are others in the table at 11910 */
	/* this port is checked at 1b080 */
INPUT_PORTS_END

INPUT_PORTS_START( aerofgt )
	PORT_START_TAG("IN0")
	PORT_BIT( 0x0001, IP_ACTIVE_LOW, IPT_JOYSTICK_UP ) PORT_8WAY
	PORT_BIT( 0x0002, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN ) PORT_8WAY
	PORT_BIT( 0x0004, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT ) PORT_8WAY
	PORT_BIT( 0x0008, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT ) PORT_8WAY
	PORT_BIT( 0x0010, IP_ACTIVE_LOW, IPT_BUTTON1 )
	PORT_BIT( 0x0020, IP_ACTIVE_LOW, IPT_BUTTON2 )
	PORT_BIT( 0x0040, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x0080, IP_ACTIVE_LOW, IPT_UNKNOWN )

	PORT_START_TAG("IN1")
	PORT_BIT( 0x0001, IP_ACTIVE_LOW, IPT_JOYSTICK_UP ) PORT_8WAY PORT_PLAYER(2)
	PORT_BIT( 0x0002, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN ) PORT_8WAY PORT_PLAYER(2)
	PORT_BIT( 0x0004, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT ) PORT_8WAY PORT_PLAYER(2)
	PORT_BIT( 0x0008, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT ) PORT_8WAY PORT_PLAYER(2)
	PORT_BIT( 0x0010, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_PLAYER(2)
	PORT_BIT( 0x0020, IP_ACTIVE_LOW, IPT_BUTTON2 ) PORT_PLAYER(2)
	PORT_BIT( 0x0040, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x0080, IP_ACTIVE_LOW, IPT_UNKNOWN )

	PORT_START_TAG("IN2")
	PORT_BIT( 0x0001, IP_ACTIVE_LOW, IPT_COIN1 )
	PORT_BIT( 0x0002, IP_ACTIVE_LOW, IPT_COIN2 )
	PORT_BIT( 0x0004, IP_ACTIVE_LOW, IPT_START1 )
	PORT_BIT( 0x0008, IP_ACTIVE_LOW, IPT_START2 )
	PORT_BIT( 0x0010, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x0020, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x0040, IP_ACTIVE_LOW, IPT_COIN3 )
	PORT_BIT( 0x0080, IP_ACTIVE_LOW, IPT_UNKNOWN )

	PORT_START_TAG("DSW1")
	PORT_DIPNAME( 0x0001, 0x0001, "Coin Slot" )
	PORT_DIPSETTING(      0x0001, "Same" )
	PORT_DIPSETTING(      0x0000, "Individual" )
	PORT_DIPNAME( 0x000e, 0x000e, DEF_STR( Coin_A ) )
	PORT_DIPSETTING(      0x000a, DEF_STR( 3C_1C ) )
	PORT_DIPSETTING(      0x000c, DEF_STR( 2C_1C ) )
	PORT_DIPSETTING(      0x000e, DEF_STR( 1C_1C ) )
	PORT_DIPSETTING(      0x0008, DEF_STR( 1C_2C ) )
	PORT_DIPSETTING(      0x0006, DEF_STR( 1C_3C ) )
	PORT_DIPSETTING(      0x0004, DEF_STR( 1C_4C ) )
	PORT_DIPSETTING(      0x0002, DEF_STR( 1C_5C ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( 1C_6C ) )
	PORT_DIPNAME( 0x0070, 0x0070, DEF_STR( Coin_B ) )
	PORT_DIPSETTING(      0x0050, DEF_STR( 3C_1C ) )
	PORT_DIPSETTING(      0x0060, DEF_STR( 2C_1C ) )
	PORT_DIPSETTING(      0x0070, DEF_STR( 1C_1C ) )
	PORT_DIPSETTING(      0x0040, DEF_STR( 1C_2C ) )
	PORT_DIPSETTING(      0x0030, DEF_STR( 1C_3C ) )
	PORT_DIPSETTING(      0x0020, DEF_STR( 1C_4C ) )
	PORT_DIPSETTING(      0x0010, DEF_STR( 1C_5C ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( 1C_6C ) )
	PORT_DIPNAME( 0x0080, 0x0080, "2 Coins to Start, 1 to Continue" )
	PORT_DIPSETTING(      0x0080, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( On ) )

	PORT_START_TAG("DSW2")
	PORT_DIPNAME( 0x0001, 0x0001, DEF_STR( Flip_Screen ) )
	PORT_DIPSETTING(      0x0001, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( On ) )
	PORT_DIPNAME( 0x0002, 0x0000, DEF_STR( Demo_Sounds ) )
	PORT_DIPSETTING(      0x0002, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( On ) )
	PORT_DIPNAME( 0x000c, 0x000c, DEF_STR( Difficulty ) )
	PORT_DIPSETTING(      0x0008, DEF_STR( Easy ) )
	PORT_DIPSETTING(      0x000c, DEF_STR( Normal ) )
	PORT_DIPSETTING(      0x0004, DEF_STR( Hard ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( Hardest ) )
	PORT_DIPNAME( 0x0030, 0x0030, DEF_STR( Lives ) )
	PORT_DIPSETTING(      0x0020, "1" )
	PORT_DIPSETTING(      0x0010, "2" )
	PORT_DIPSETTING(      0x0030, "3" )
	PORT_DIPSETTING(      0x0000, "4" )
	PORT_DIPNAME( 0x0040, 0x0040, DEF_STR( Bonus_Life ) )
	PORT_DIPSETTING(      0x0040, "200000" )
	PORT_DIPSETTING(      0x0000, "300000" )
	PORT_SERVICE( 0x0080, IP_ACTIVE_LOW )

	PORT_START_TAG("DSW3")
	PORT_DIPNAME( 0x000f, 0x0000, "Country" )
	PORT_DIPSETTING(      0x0000, "Any" )
	PORT_DIPSETTING(      0x000f, DEF_STR( USA ) )
	PORT_DIPSETTING(      0x000e, "Korea" )
	PORT_DIPSETTING(      0x000d, "Hong Kong" )
	PORT_DIPSETTING(      0x000b, "Taiwan" )
INPUT_PORTS_END

INPUT_PORTS_START( wbbc97 )
	PORT_INCLUDE(pspikes)
	PORT_MODIFY("IN0")
	PORT_BIT( 0x4000, IP_ACTIVE_LOW, IPT_SERVICE1 )
INPUT_PORTS_END



GAME( 1990, spinlbrk, 0,        spinlbrk, spinlbrk, 0, ROT0,   "V-System Co.", "Spinal Breakers (World)", GAME_NO_COCKTAIL )
GAME( 1990, spinlbru, spinlbrk, spinlbrk, spinlbru, 0, ROT0,   "V-System Co.", "Spinal Breakers (US)", GAME_NO_COCKTAIL )
GAME( 1990, spinlbrj, spinlbrk, spinlbrk, spinlbrj, 0, ROT0,   "V-System Co.", "Spinal Breakers (Japan)", GAME_NO_COCKTAIL )
GAME( 1991, pspikes,  0,        pspikes,  pspikes,  0, ROT0,   "Video System Co.", "Power Spikes (World)", GAME_NO_COCKTAIL )
GAME( 1991, pspikesk, pspikes,  pspikes,  pspikes,  0, ROT0,   "Video System Co.", "Power Spikes (Korea)", GAME_NO_COCKTAIL )
GAME( 1991, svolly91, pspikes,  pspikes,  pspikes,  0, ROT0,   "Video System Co.", "Super Volley '91 (Japan)", GAME_NO_COCKTAIL )
GAME( 1991, pspikesb, pspikes,  pspikesb, pspikesb, 0, ROT0,   "bootleg",          "Power Spikes (bootleg)", GAME_NO_COCKTAIL )
GAME( 1991, karatblz, 0,        karatblz, karatblz, 0, ROT0,   "Video System Co.", "Karate Blazers (World?)", GAME_NO_COCKTAIL )
GAME( 1991, karatblu, karatblz, karatblz, karatblz, 0, ROT0,   "Video System Co.", "Karate Blazers (US)", GAME_NO_COCKTAIL )
GAME( 1991, karatblj, karatblz, karatblz, karatblz, 0, ROT0,   "Video System Co.", "Karate Blazers (Japan)", GAME_NO_COCKTAIL )
GAME( 1991, turbofrc, 0,        turbofrc, turbofrc, 0, ROT270, "Video System Co.", "Turbo Force", GAME_NO_COCKTAIL )
GAME( 1992, aerofgt,  0,        aerofgt,  aerofgt,  0, ROT270, "Video System Co.", "Aero Fighters", GAME_NO_COCKTAIL )
GAME( 1992, aerofgtb, aerofgt,  aerofgtb, aerofgtb, 0, ROT270, "Video System Co.", "Aero Fighters (Turbo Force hardware set 1)", GAME_NO_COCKTAIL )
GAME( 1992, aerofgtc, aerofgt,  aerofgtb, aerofgtb, 0, ROT270, "Video System Co.", "Aero Fighters (Turbo Force hardware set 2)", GAME_NO_COCKTAIL )
GAME( 1992, sonicwi,  aerofgt,  aerofgtb, aerofgtb, 0, ROT270, "Video System Co.", "Sonic Wings (Japan)", GAME_NO_COCKTAIL )
GAME( 1992, aerfboot, aerofgt,  aerfboot, aerofgtb, 0, ROT270, "bootleg",          "Aero Fighters (bootleg)", GAME_NO_COCKTAIL | GAME_NO_SOUND | GAME_NOT_WORKING )
GAME( 1997, wbbc97,   0,        wbbc97,   wbbc97,   0, ROT0,   "Comad",            "Beach Festival World Championship 1997", GAME_NO_COCKTAIL )
