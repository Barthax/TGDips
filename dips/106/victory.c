/*************************************
 *
 *  Port definitions
 *
 *************************************/

INPUT_PORTS_START( victory )
	PORT_START	/* $00-$03 = SW2 */
	PORT_DIPNAME( 0x07, 0x00, "????" )
	PORT_DIPSETTING(    0x00, "0" )
	PORT_DIPSETTING(    0x01, "1" )
	PORT_DIPSETTING(    0x02, "2" )
	PORT_DIPSETTING(    0x03, "3" )
	PORT_DIPSETTING(    0x04, "4" )
	PORT_DIPSETTING(    0x05, "5" )
	PORT_DIPSETTING(    0x06, "6" )
	PORT_DIPSETTING(    0x07, "7" )
	PORT_BIT( 0x78, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_DIPNAME( 0x80, 0x00, "Refresh" )
	PORT_DIPSETTING(    0x00, "60 Hz" )
	PORT_DIPSETTING(    0x80, "50 Hz" )

	PORT_START	/* $04-$07 = SW1 */
	PORT_BIT( 0xff, IP_ACTIVE_LOW, IPT_UNUSED )

	PORT_START	/* $08-$09 = PIO K8 port A */
	PORT_BIT( 0xff, 0x80, IPT_DIAL ) PORT_MINMAX(0x00,0xff) PORT_SENSITIVITY(25) PORT_KEYDELTA(10) PORT_REVERSE

	PORT_START	/* $0A-$0B = PIO K8 port B */
	PORT_BIT( 0xf8, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_COIN1 )
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_COIN2 )
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_COIN3 )

	PORT_START	/* $0C-$0D = PIO L8 port A */
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_BUTTON1 )
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_BUTTON2 )
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_BUTTON4 )
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_BUTTON3 )
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_START1 )
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_START2 )
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_SERVICE1 )
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_UNKNOWN )

	PORT_START	/* $0E-$0F = PIO L8 port B */
	PORT_BIT( 0xff, IP_ACTIVE_LOW, IPT_UNUSED )
INPUT_PORTS_END


/*************************************
 *
 *  Game drivers
 *
 *************************************/

GAME( 1982, victory,  0,        victory, victory, 0,     ROT0, "Exidy", "Victory", 0 )
GAME( 1982, victorba, victory,  victory, victory, 0,     ROT0, "Exidy", "Victor Banana", 0 )
