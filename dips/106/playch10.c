# MAME 0.106 source snippet


Dipswitches information:
------------------------
Steph 2000.09.07

The 6 first DSWA (A-F) are used for coinage (units of time given for coin A/coin B)
When bit 6 of DSWB (O) is ON, units of time given for coin B are divided by 2

The 6 first DSWB (I-N) are used to set timer speed :
    [0x80d5] = ( ( (IN A,02) | 0xc0 ) + 0x3c ) & 0xff

When bit 7 of DSWB (P) is ON, you're in 'Freeplay' mode with 9999 units of time ...
However, this is effective ONLY if 7 other DSWB (I-O) are OFF !

I add the 32 combinations for coinage.

As I don't know what is the default value for timer speed, and I don't want to write
the 64 combinaisons, I only put some values ... Feel free to add the other ones ...

 DSW A    DSW B
HGFEDCBA PONMLKJI    coin A  coin B

xx000000 x0xxxxxx      300       0
xx000001 x0xxxxxx      300     100
xx000010 x0xxxxxx      300     200
xx000011 x0xxxxxx      300     300
xx000100 x0xxxxxx      300     400
xx000101 x0xxxxxx      300     500
xx000110 x0xxxxxx      300     600
xx000111 x0xxxxxx      300     700
xx001000 x0xxxxxx      300     800
xx001001 x0xxxxxx      300     900
xx001010 x0xxxxxx      150       0
xx001011 x0xxxxxx      150     200
xx001100 x0xxxxxx      150     400
xx001101 x0xxxxxx      150     600
xx001110 x0xxxxxx      150     800
xx001111 x0xxxxxx      150     500
xx010000 x0xxxxxx      300    1000
xx010001 x0xxxxxx      300    1100
xx010010 x0xxxxxx      300    1200
xx010011 x0xxxxxx      300    1300
xx010100 x0xxxxxx      300    1400
xx010101 x0xxxxxx      300    1500
xx010110 x0xxxxxx      300    1600
xx010111 x0xxxxxx      300    1700
xx011000 x0xxxxxx      300    1800
xx011001 x0xxxxxx      300    1900
xx011010 x0xxxxxx      150    1000
xx011011 x0xxxxxx      150    1200
xx011100 x0xxxxxx      150    1400
xx011101 x0xxxxxx      150    1600
xx011110 x0xxxxxx      150    1800
xx011111 x0xxxxxx      150    1500
xx100000 x0xxxxxx      300    2000
xx100001 x0xxxxxx      300    2100
xx100010 x0xxxxxx      300    2200
xx100011 x0xxxxxx      300    2300
xx100100 x0xxxxxx      300    2400
xx100101 x0xxxxxx      300    2500
xx100110 x0xxxxxx      300    2600
xx100111 x0xxxxxx      300    2700
xx101000 x0xxxxxx      300    2800
xx101001 x0xxxxxx      300    2900
xx101010 x0xxxxxx      150    2000
xx101011 x0xxxxxx      150    2200
xx101100 x0xxxxxx      150    2400
xx101101 x0xxxxxx      150    2600
xx101110 x0xxxxxx      150    2800
xx101111 x0xxxxxx      150    2500
xx110000 x0xxxxxx      300    3000
xx110001 x0xxxxxx      300    3100
xx110010 x0xxxxxx      300    3200
xx110011 x0xxxxxx      300    3300
xx110100 x0xxxxxx      300    3400
xx110101 x0xxxxxx      300    3500
xx110110 x0xxxxxx      300    3600
xx110111 x0xxxxxx      300    3700
xx111000 x0xxxxxx      300    3800
xx111001 x0xxxxxx      300    3900
xx111010 x0xxxxxx      150    3000
xx111011 x0xxxxxx      150    3200
xx111100 x0xxxxxx      150    3400
xx111101 x0xxxxxx      150    3600
xx111110 x0xxxxxx      150    3800
xx111111 x0xxxxxx      150    3500

xx000000 x1xxxxxx      300       0
xx000001 x1xxxxxx      300      50
xx000010 x1xxxxxx      300     100
xx000011 x1xxxxxx      300     150
xx000100 x1xxxxxx      300     200
xx000101 x1xxxxxx      300     250
xx000110 x1xxxxxx      300     300
xx000111 x1xxxxxx      300     350
xx001000 x1xxxxxx      300     400
xx001001 x1xxxxxx      300     450
xx001010 x1xxxxxx      150       0
xx001011 x1xxxxxx      150     100
xx001100 x1xxxxxx      150     200
xx001101 x1xxxxxx      150     300
xx001110 x1xxxxxx      150     400
xx001111 x1xxxxxx      150     250
xx010000 x1xxxxxx      300     500
xx010001 x1xxxxxx      300     550
xx010010 x1xxxxxx      300     600
xx010011 x1xxxxxx      300     650
xx010100 x1xxxxxx      300     700
xx010101 x1xxxxxx      300     750
xx010110 x1xxxxxx      300     800
xx010111 x1xxxxxx      300     850
xx011000 x1xxxxxx      300     900
xx011001 x1xxxxxx      300     950
xx011010 x1xxxxxx      150     500
xx011011 x1xxxxxx      150     600
xx011100 x1xxxxxx      150     700
xx011101 x1xxxxxx      150     800
xx011110 x1xxxxxx      150     750
xx100000 x1xxxxxx      300    1000
xx100001 x1xxxxxx      300    1050
xx100010 x1xxxxxx      300    1100
xx100011 x1xxxxxx      300    1150
xx100100 x1xxxxxx      300    1200
xx100101 x1xxxxxx      300    1250
xx100110 x1xxxxxx      300    1300
xx100111 x1xxxxxx      300    1350
xx101000 x1xxxxxx      300    1400
xx101001 x1xxxxxx      300    1450
xx101010 x1xxxxxx      150    1000
xx101011 x1xxxxxx      150    1100
xx101100 x1xxxxxx      150    1200
xx101101 x1xxxxxx      150    1300
xx101110 x1xxxxxx      150    1400
xx101111 x1xxxxxx      150    1250
xx110000 x1xxxxxx      300    1500
xx110001 x1xxxxxx      300    1550
xx110010 x1xxxxxx      300    1600
xx110011 x1xxxxxx      300    1650
xx110100 x1xxxxxx      300    1700
xx110101 x1xxxxxx      300    1750
xx110110 x1xxxxxx      300    1800
xx110111 x1xxxxxx      300    1850
xx111000 x1xxxxxx      300    1900
xx111001 x1xxxxxx      300    1950
xx111010 x1xxxxxx      150    1500
xx111011 x1xxxxxx      150    1600
xx111100 x1xxxxxx      150    1700
xx111101 x1xxxxxx      150    1800
xx111110 x1xxxxxx      150    1750

I know that the way I code the DSW isn't correct, but I don't know how to link
O to A-F AND, at the same time, O to P ... Any help is appreciated ...

****************************************************************************


INPUT_PORTS_START( playch10 )
    PORT_START_TAG("BIOS")
    PORT_BIT( 0x01, IP_ACTIVE_HIGH, IPT_SERVICE ) PORT_NAME("Channel Select") PORT_CODE(KEYCODE_0)
    PORT_BIT( 0x02, IP_ACTIVE_HIGH, IPT_SERVICE ) PORT_NAME("Enter") PORT_CODE(KEYCODE_MINUS)
    PORT_BIT( 0x04, IP_ACTIVE_HIGH, IPT_SERVICE ) PORT_NAME("Reset") PORT_CODE(KEYCODE_EQUALS)
    PORT_BIT( 0x08, IP_ACTIVE_HIGH, IPT_SPECIAL ) // INT Detect
    PORT_BIT( 0x10, IP_ACTIVE_HIGH, IPT_UNUSED )
    PORT_BIT( 0x20, IP_ACTIVE_HIGH, IPT_COIN2 )
    PORT_BIT( 0x40, IP_ACTIVE_HIGH, IPT_SERVICE1 )
    PORT_BIT( 0x80, IP_ACTIVE_HIGH, IPT_COIN1 )

/*

    The correct way to handle DIPs according to the manual.
    Doesn't work due to limitations of the conditional DIPs
    implementation in MAME.


    PORT_START_TAG("SW1")
    PORT_DIPNAME( 0x3f, 0x09, "Prime Time Bonus" )
    // STANDARD TIME (no bonus)
    PORT_DIPSETTING(    0x00, "0%" )    PORT_CONDITION("SW2", 0xc0, PORTCOND_EQUALS, 0xc0 )
    // PRIME TIME (bonus) for 2 COINS
    PORT_DIPSETTING(    0x07, "8%" )    PORT_CONDITION("SW2", 0xc0, PORTCOND_EQUALS, 0x80 )
    PORT_DIPSETTING(    0x08, "17%" )   PORT_CONDITION("SW2", 0xc0, PORTCOND_EQUALS, 0x80 )
    PORT_DIPSETTING(    0x09, "25%" )   PORT_CONDITION("SW2", 0xc0, PORTCOND_EQUALS, 0x80 )
    PORT_DIPSETTING(    0x10, "33%" )   PORT_CONDITION("SW2", 0xc0, PORTCOND_EQUALS, 0x80 )
    PORT_DIPSETTING(    0x11, "42%" )   PORT_CONDITION("SW2", 0xc0, PORTCOND_EQUALS, 0x80 )
    PORT_DIPSETTING(    0x12, "50%" )   PORT_CONDITION("SW2", 0xc0, PORTCOND_EQUALS, 0x80 )
    PORT_DIPSETTING(    0x13, "58%" )   PORT_CONDITION("SW2", 0xc0, PORTCOND_EQUALS, 0x80 )
    PORT_DIPSETTING(    0x14, "67%" )   PORT_CONDITION("SW2", 0xc0, PORTCOND_EQUALS, 0x80 )
    PORT_DIPSETTING(    0x15, "75%" )   PORT_CONDITION("SW2", 0xc0, PORTCOND_EQUALS, 0x80 )
    PORT_DIPSETTING(    0x16, "83%" )   PORT_CONDITION("SW2", 0xc0, PORTCOND_EQUALS, 0x80 )
    PORT_DIPSETTING(    0x17, "92%" )   PORT_CONDITION("SW2", 0xc0, PORTCOND_EQUALS, 0x80 )
    PORT_DIPSETTING(    0x18, "100%" )  PORT_CONDITION("SW2", 0xc0, PORTCOND_EQUALS, 0x80 )
    // PRIME TIME (bonus) for 4 COINS
    PORT_DIPSETTING(    0x04, "8%" )    PORT_CONDITION("SW2", 0xc0, PORTCOND_EQUALS, 0x00 )
    PORT_DIPSETTING(    0x05, "17%" )   PORT_CONDITION("SW2", 0xc0, PORTCOND_EQUALS, 0x00 )
    PORT_DIPSETTING(    0x06, "25%" )   PORT_CONDITION("SW2", 0xc0, PORTCOND_EQUALS, 0x00 )
    PORT_DIPSETTING(    0x07, "33%" )   PORT_CONDITION("SW2", 0xc0, PORTCOND_EQUALS, 0x00 )
    PORT_DIPSETTING(    0x08, "42%" )   PORT_CONDITION("SW2", 0xc0, PORTCOND_EQUALS, 0x00 )
    PORT_DIPSETTING(    0x09, "50%" )   PORT_CONDITION("SW2", 0xc0, PORTCOND_EQUALS, 0x00 )
    PORT_DIPSETTING(    0x10, "58%" )   PORT_CONDITION("SW2", 0xc0, PORTCOND_EQUALS, 0x00 )
    PORT_DIPSETTING(    0x11, "67%" )   PORT_CONDITION("SW2", 0xc0, PORTCOND_EQUALS, 0x00 )
    PORT_DIPSETTING(    0x12, "75%" )   PORT_CONDITION("SW2", 0xc0, PORTCOND_EQUALS, 0x00 )
    PORT_DIPSETTING(    0x13, "83%" )   PORT_CONDITION("SW2", 0xc0, PORTCOND_EQUALS, 0x00 )
    PORT_DIPSETTING(    0x14, "92%" )   PORT_CONDITION("SW2", 0xc0, PORTCOND_EQUALS, 0x00 )
    PORT_DIPSETTING(    0x15, "100%" )  PORT_CONDITION("SW2", 0xc0, PORTCOND_EQUALS, 0x00 )

    PORT_DIPNAME( 0x40, 0x40, DEF_STR( Demo_Sounds ) )
    PORT_DIPSETTING(    0x00, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x40, DEF_STR( On ) )
    PORT_SERVICE( 0x80, IP_ACTIVE_HIGH )

    PORT_START_TAG("SW2")
    PORT_DIPNAME( 0x3f, 0x28, "Play Time/Coin" )
    // STANDARD TIME (no bonus)
    PORT_DIPSETTING(    0x3f, DEF_STR( Free_Play ) )    PORT_CONDITION("SW2", 0xc0, PORTCOND_EQUALS, 0x80 )
    PORT_DIPSETTING(    0x23, "2:00 (120)" )    PORT_CONDITION("SW2", 0xc0, PORTCOND_EQUALS, 0xc0 )
    PORT_DIPSETTING(    0x21, "2:10 (130)" )    PORT_CONDITION("SW2", 0xc0, PORTCOND_EQUALS, 0xc0 )
    PORT_DIPSETTING(    0x1f, "2:20 (140)" )    PORT_CONDITION("SW2", 0xc0, PORTCOND_EQUALS, 0xc0 )
    PORT_DIPSETTING(    0x1d, "2:30 (150)" )    PORT_CONDITION("SW2", 0xc0, PORTCOND_EQUALS, 0xc0 )
    PORT_DIPSETTING(    0x1b, "2:40 (160)" )    PORT_CONDITION("SW2", 0xc0, PORTCOND_EQUALS, 0xc0 )
    PORT_DIPSETTING(    0x19, "2:50 (170)" )    PORT_CONDITION("SW2", 0xc0, PORTCOND_EQUALS, 0xc0 )
    PORT_DIPSETTING(    0x17, "3:00 (180)" )    PORT_CONDITION("SW2", 0xc0, PORTCOND_EQUALS, 0xc0 )
    PORT_DIPSETTING(    0x15, "3:10 (190)" )    PORT_CONDITION("SW2", 0xc0, PORTCOND_EQUALS, 0xc0 )
    PORT_DIPSETTING(    0x13, "3:20 (200)" )    PORT_CONDITION("SW2", 0xc0, PORTCOND_EQUALS, 0xc0 )
    PORT_DIPSETTING(    0x11, "3:30 (210)" )    PORT_CONDITION("SW2", 0xc0, PORTCOND_EQUALS, 0xc0 )
    PORT_DIPSETTING(    0x0f, "3:40 (220)" )    PORT_CONDITION("SW2", 0xc0, PORTCOND_EQUALS, 0xc0 )
    PORT_DIPSETTING(    0x0d, "3:50 (230)" )    PORT_CONDITION("SW2", 0xc0, PORTCOND_EQUALS, 0xc0 )
    PORT_DIPSETTING(    0x0b, "4:00 (240)" )    PORT_CONDITION("SW2", 0xc0, PORTCOND_EQUALS, 0xc0 )
    PORT_DIPSETTING(    0x09, "4:10 (250)" )    PORT_CONDITION("SW2", 0xc0, PORTCOND_EQUALS, 0xc0 )
    PORT_DIPSETTING(    0x07, "4:20 (260)" )    PORT_CONDITION("SW2", 0xc0, PORTCOND_EQUALS, 0xc0 )
    PORT_DIPSETTING(    0x05, "4:30 (270)" )    PORT_CONDITION("SW2", 0xc0, PORTCOND_EQUALS, 0xc0 )
    PORT_DIPSETTING(    0x03, "4:40 (280)" )    PORT_CONDITION("SW2", 0xc0, PORTCOND_EQUALS, 0xc0 )
    PORT_DIPSETTING(    0x01, "4:50 (290)" )    PORT_CONDITION("SW2", 0xc0, PORTCOND_EQUALS, 0xc0 )
    // PRIME TIME (bonus) for 2 COINS
    PORT_DIPSETTING(    0x1c, "2:00 (120)" )    PORT_CONDITION("SW2", 0xc0, PORTCOND_EQUALS, 0x80 )
    PORT_DIPSETTING(    0x1e, "2:10 (130)" )    PORT_CONDITION("SW2", 0xc0, PORTCOND_EQUALS, 0x80 )
    PORT_DIPSETTING(    0x20, "2:20 (140)" )    PORT_CONDITION("SW2", 0xc0, PORTCOND_EQUALS, 0x80 )
    PORT_DIPSETTING(    0x22, "2:30 (150)" )    PORT_CONDITION("SW2", 0xc0, PORTCOND_EQUALS, 0x80 )
    PORT_DIPSETTING(    0x24, "2:40 (160)" )    PORT_CONDITION("SW2", 0xc0, PORTCOND_EQUALS, 0x80 )
    PORT_DIPSETTING(    0x26, "2:50 (170)" )    PORT_CONDITION("SW2", 0xc0, PORTCOND_EQUALS, 0x80 )
    PORT_DIPSETTING(    0x28, "3:00 (180)" )    PORT_CONDITION("SW2", 0xc0, PORTCOND_EQUALS, 0x80 )
    PORT_DIPSETTING(    0x2a, "3:10 (190)" )    PORT_CONDITION("SW2", 0xc0, PORTCOND_EQUALS, 0x80 )
    PORT_DIPSETTING(    0x2c, "3:20 (200)" )    PORT_CONDITION("SW2", 0xc0, PORTCOND_EQUALS, 0x80 )
    PORT_DIPSETTING(    0x2e, "3:30 (210)" )    PORT_CONDITION("SW2", 0xc0, PORTCOND_EQUALS, 0x80 )
    PORT_DIPSETTING(    0x30, "3:40 (220)" )    PORT_CONDITION("SW2", 0xc0, PORTCOND_EQUALS, 0x80 )
    PORT_DIPSETTING(    0x32, "3:50 (230)" )    PORT_CONDITION("SW2", 0xc0, PORTCOND_EQUALS, 0x80 )
    PORT_DIPSETTING(    0x34, "4:00 (240)" )    PORT_CONDITION("SW2", 0xc0, PORTCOND_EQUALS, 0x80 )
    // PRIME TIME (bonus) for 4 COINS
    PORT_DIPSETTING(    0x1c, "2:00 (120)" )    PORT_CONDITION("SW2", 0xc0, PORTCOND_EQUALS, 0x00 )
    PORT_DIPSETTING(    0x1e, "2:10 (130)" )    PORT_CONDITION("SW2", 0xc0, PORTCOND_EQUALS, 0x00 )
    PORT_DIPSETTING(    0x20, "2:20 (140)" )    PORT_CONDITION("SW2", 0xc0, PORTCOND_EQUALS, 0x00 )
    PORT_DIPSETTING(    0x22, "2:30 (150)" )    PORT_CONDITION("SW2", 0xc0, PORTCOND_EQUALS, 0x00 )
    PORT_DIPSETTING(    0x24, "2:40 (160)" )    PORT_CONDITION("SW2", 0xc0, PORTCOND_EQUALS, 0x00 )
    PORT_DIPSETTING(    0x26, "2:50 (170)" )    PORT_CONDITION("SW2", 0xc0, PORTCOND_EQUALS, 0x00 )
    PORT_DIPSETTING(    0x28, "3:00 (180)" )    PORT_CONDITION("SW2", 0xc0, PORTCOND_EQUALS, 0x00 )
    PORT_DIPSETTING(    0x2a, "3:10 (190)" )    PORT_CONDITION("SW2", 0xc0, PORTCOND_EQUALS, 0x00 )
    PORT_DIPSETTING(    0x2c, "3:20 (200)" )    PORT_CONDITION("SW2", 0xc0, PORTCOND_EQUALS, 0x00 )
    PORT_DIPSETTING(    0x2e, "3:30 (210)" )    PORT_CONDITION("SW2", 0xc0, PORTCOND_EQUALS, 0x00 )
    PORT_DIPSETTING(    0x30, "3:40 (220)" )    PORT_CONDITION("SW2", 0xc0, PORTCOND_EQUALS, 0x00 )
    PORT_DIPSETTING(    0x32, "3:50 (230)" )    PORT_CONDITION("SW2", 0xc0, PORTCOND_EQUALS, 0x00 )
    PORT_DIPSETTING(    0x34, "4:00 (240)" )    PORT_CONDITION("SW2", 0xc0, PORTCOND_EQUALS, 0x00 )

    PORT_DIPNAME( 0xc0, 0x80, "Bonus" )
    PORT_DIPSETTING(    0xc0, "Standard Time" )
    PORT_DIPSETTING(    0x80, "Prime Time for 2 Coins" )
    PORT_DIPSETTING(    0x00, "Prime Time for 4 Coins" )
*/
	PORT_START_TAG("SW1")
	PORT_DIPNAME( 0x3f, 0x00, "Units of time (coin A/coin B)" )
	PORT_DIPSETTING(    0x00, "300/0" )
	PORT_DIPSETTING(    0x01, "300/100" )
	PORT_DIPSETTING(    0x02, "300/200" )
	PORT_DIPSETTING(    0x03, "300/300" )
	PORT_DIPSETTING(    0x04, "300/400" )
	PORT_DIPSETTING(    0x05, "300/500" )
	PORT_DIPSETTING(    0x06, "300/600" )
	PORT_DIPSETTING(    0x07, "300/700" )
	PORT_DIPSETTING(    0x08, "300/800" )
	PORT_DIPSETTING(    0x09, "300/900" )
	PORT_DIPSETTING(    0x0a, "150/0" )
	PORT_DIPSETTING(    0x0b, "150/200" )
	PORT_DIPSETTING(    0x0c, "150/400" )
	PORT_DIPSETTING(    0x0f, "150/500" )
	PORT_DIPSETTING(    0x0d, "150/600" )
	PORT_DIPSETTING(    0x0e, "150/800" )
	PORT_DIPSETTING(    0x10, "300/1000" )
	PORT_DIPSETTING(    0x11, "300/1100" )
	PORT_DIPSETTING(    0x12, "300/1200" )
	PORT_DIPSETTING(    0x13, "300/1300" )
	PORT_DIPSETTING(    0x14, "300/1400" )
	PORT_DIPSETTING(    0x15, "300/1500" )
	PORT_DIPSETTING(    0x16, "300/1600" )
	PORT_DIPSETTING(    0x17, "300/1700" )
	PORT_DIPSETTING(    0x18, "300/1800" )
	PORT_DIPSETTING(    0x19, "300/1900" )
	PORT_DIPSETTING(    0x1a, "150/1000" )
	PORT_DIPSETTING(    0x1b, "150/1200" )
	PORT_DIPSETTING(    0x1c, "150/1400" )
	PORT_DIPSETTING(    0x1f, "150/1500" )
	PORT_DIPSETTING(    0x1d, "150/1600" )
	PORT_DIPSETTING(    0x1e, "150/1800" )
	PORT_DIPSETTING(    0x20, "300/2000" )
	PORT_DIPSETTING(    0x21, "300/2100" )
	PORT_DIPSETTING(    0x22, "300/2200" )
	PORT_DIPSETTING(    0x23, "300/2300" )
	PORT_DIPSETTING(    0x24, "300/2400" )
	PORT_DIPSETTING(    0x25, "300/2500" )
	PORT_DIPSETTING(    0x26, "300/2600" )
	PORT_DIPSETTING(    0x27, "300/2700" )
	PORT_DIPSETTING(    0x28, "300/2800" )
	PORT_DIPSETTING(    0x29, "300/2900" )
	PORT_DIPSETTING(    0x2a, "150/2000" )
	PORT_DIPSETTING(    0x2b, "150/2200" )
	PORT_DIPSETTING(    0x2c, "150/2400" )
	PORT_DIPSETTING(    0x2f, "150/2500" )
	PORT_DIPSETTING(    0x2d, "150/2600" )
	PORT_DIPSETTING(    0x2e, "150/2800" )
	PORT_DIPSETTING(    0x30, "300/3000" )
	PORT_DIPSETTING(    0x31, "300/3100" )
	PORT_DIPSETTING(    0x32, "300/3200" )
	PORT_DIPSETTING(    0x33, "300/3300" )
	PORT_DIPSETTING(    0x34, "300/3400" )
	PORT_DIPSETTING(    0x35, "300/3500" )
	PORT_DIPSETTING(    0x36, "300/3600" )
	PORT_DIPSETTING(    0x37, "300/3700" )
	PORT_DIPSETTING(    0x38, "300/3800" )
	PORT_DIPSETTING(    0x39, "300/3900" )
	PORT_DIPSETTING(    0x3a, "150/3000" )
	PORT_DIPSETTING(    0x3b, "150/3200" )
	PORT_DIPSETTING(    0x3c, "150/3400" )
	PORT_DIPSETTING(    0x3f, "150/3500" )
	PORT_DIPSETTING(    0x3d, "150/3600" )
	PORT_DIPSETTING(    0x3e, "150/3800" )
	PORT_DIPNAME( 0x40, 0x40, DEF_STR( Demo_Sounds ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x40, DEF_STR( On ) )
	PORT_SERVICE( 0x80, IP_ACTIVE_HIGH )

	PORT_START_TAG("SW2")
	PORT_DIPNAME( 0x40, 0x00, "Coin Mode" )
	PORT_DIPSETTING(    0x00, "Mode 1" )
	PORT_DIPSETTING(    0x40, "Mode 2" )
	PORT_DIPNAME( 0xbf, 0x3f, "Timer speed" )
	PORT_DIPSETTING(    0x05, "60 units per second" )
	PORT_DIPSETTING(    0x06, "30 units per second" )
	PORT_DIPSETTING(    0x07, "20 units per second" )
	PORT_DIPSETTING(    0x08, "15 units per second" )
	PORT_DIPSETTING(    0x0a, "10 units per second" )
	PORT_DIPSETTING(    0x0e, "6 units per second" )
	PORT_DIPSETTING(    0x10, "5 units per second" )
	PORT_DIPSETTING(    0x13, "4 units per second" )
	PORT_DIPSETTING(    0x18, "3 units per second" )
	PORT_DIPSETTING(    0x22, "2 units per second" )
	PORT_DIPSETTING(    0x3f, "1 unit per second" )
	PORT_DIPSETTING(    0x00, "1 unit every 4 seconds" )
	PORT_DIPSETTING(    0x80, DEF_STR( Free_Play ) )

	PORT_START_TAG("IN0")
	PORT_BIT( 0x01, IP_ACTIVE_HIGH, IPT_BUTTON1 ) PORT_NAME("P1 Button A")
	PORT_BIT( 0x02, IP_ACTIVE_HIGH, IPT_BUTTON2 ) PORT_NAME("P1 Button B")
	PORT_BIT( 0x04, IP_ACTIVE_HIGH, IPT_START1 ) PORT_NAME("Game Select") PORT_CODE(KEYCODE_1)
	PORT_BIT( 0x08, IP_ACTIVE_HIGH, IPT_START2 ) PORT_NAME("Start") PORT_CODE(KEYCODE_2)
	PORT_BIT( 0x10, IP_ACTIVE_HIGH, IPT_JOYSTICK_UP    )
	PORT_BIT( 0x20, IP_ACTIVE_HIGH, IPT_JOYSTICK_DOWN  )
	PORT_BIT( 0x40, IP_ACTIVE_HIGH, IPT_JOYSTICK_LEFT  )
	PORT_BIT( 0x80, IP_ACTIVE_HIGH, IPT_JOYSTICK_RIGHT )

	PORT_START_TAG("IN1")
	PORT_BIT( 0x01, IP_ACTIVE_HIGH, IPT_BUTTON1 ) PORT_NAME("P2 Button A") PORT_PLAYER(2)
	PORT_BIT( 0x02, IP_ACTIVE_HIGH, IPT_BUTTON2 ) PORT_NAME("P2 Button B") PORT_PLAYER(2)
	PORT_BIT( 0x04, IP_ACTIVE_HIGH, IPT_UNUSED )	// wired to 1p select button
	PORT_BIT( 0x08, IP_ACTIVE_HIGH, IPT_UNUSED )	// wired to 1p start button
	PORT_BIT( 0x10, IP_ACTIVE_HIGH, IPT_JOYSTICK_UP    ) PORT_PLAYER(2)
	PORT_BIT( 0x20, IP_ACTIVE_HIGH, IPT_JOYSTICK_DOWN  ) PORT_PLAYER(2)
	PORT_BIT( 0x40, IP_ACTIVE_HIGH, IPT_JOYSTICK_LEFT  ) PORT_PLAYER(2)
	PORT_BIT( 0x80, IP_ACTIVE_HIGH, IPT_JOYSTICK_RIGHT ) PORT_PLAYER(2)
INPUT_PORTS_END

/*Input Ports for gun games*/
INPUT_PORTS_START( playc10g )
	PORT_INCLUDE(playch10)

	PORT_START	// IN2 - FAKE - Gun X pos
	PORT_BIT( 0xff, 0x80, IPT_LIGHTGUN_X ) PORT_MINMAX(0,255) PORT_SENSITIVITY(70) PORT_KEYDELTA(30)

	PORT_START	// IN3 - FAKE - Gun Y pos
	PORT_BIT( 0xff, 0x80, IPT_LIGHTGUN_Y ) PORT_MINMAX(0,255) PORT_SENSITIVITY(50) PORT_KEYDELTA(30)
INPUT_PORTS_END


/******************************************************************************/

/*     YEAR  NAME      PARENT    BIOS      MACHINE   INPUT     INIT      MONITOR  */

/* Standard Games */
GAMEB( 1983, pc_tenis, playch10, playch10, playch10, playch10, playch10, ROT0, "Nintendo",									"Tennis (PlayChoice-10)", 0 )
GAMEB( 1983, pc_mario, playch10, playch10, playch10, playch10, playch10, ROT0, "Nintendo",									"Mario Bros. (PlayChoice-10)", 0 )
GAMEB( 1984, pc_bball, playch10, playch10, playch10, playch10, playch10, ROT0, "Nintendo of America",						"Baseball (PlayChoice-10)", 0 )
GAMEB( 1984, pc_bfght, playch10, playch10, playch10, playch10, playch10, ROT0, "Nintendo",									"Balloon Fight (PlayChoice-10)", 0 )
GAMEB( 1984, pc_ebike, playch10, playch10, playch10, playch10, playch10, ROT0, "Nintendo",									"Excite Bike (PlayChoice-10)", 0 )
GAMEB( 1984, pc_golf,  playch10, playch10, playch10, playch10, playch10, ROT0, "Nintendo",									"Golf (PlayChoice-10)", 0 )
GAMEB( 1985, pc_kngfu, playch10, playch10, playch10, playch10, playch10, ROT0, "Irem (Nintendo license)",					"Kung Fu (PlayChoice-10)", 0 )
GAMEB( 1985, pc_smb,   playch10, playch10, playch10, playch10, playch10, ROT0, "Nintendo",									"Super Mario Bros. (PlayChoice-10)", 0 )
GAMEB( 1986, pc_vball, playch10, playch10, playch10, playch10, playch10, ROT0, "Nintendo",									"Volley Ball (PlayChoice-10)", 0 )
GAMEB( 1987, pc_1942,  playch10, playch10, playch10, playch10, pc_hrz,   ROT0, "Capcom",									"1942 (PlayChoice-10)", GAME_IMPERFECT_GRAPHICS )

/* Gun Games */
GAMEB( 1984, pc_duckh, playch10, playch10, playch10, playc10g, pc_gun,   ROT0, "Nintendo",									"Duck Hunt (PlayChoice-10)", 0 )
GAMEB( 1984, pc_hgaly, playch10, playch10, playch10, playc10g, pc_gun,   ROT0, "Nintendo",									"Hogan's Alley (PlayChoice-10)", 0 )
GAMEB( 1984, pc_wgnmn, playch10, playch10, playch10, playc10g, pc_gun,   ROT0, "Nintendo",									"Wild Gunman (PlayChoice-10)", 0 )

/* A-Board Games */
GAMEB( 1986, pc_grdus, playch10, playch10, playch10, playch10, pcaboard, ROT0, "Konami",									"Gradius (PlayChoice-10)" , 0) // date: 860917
GAMEB( 1986, pc_grdue, pc_grdus, playch10, playch10, playch10, pcaboard, ROT0, "Konami",									"Gradius (PlayChoice-10, older)" , 0) // date: 860219
GAMEB( 1987, pc_tkfld, playch10, playch10, playch10, playch10, pcaboard, ROT0, "Konami (Nintendo of America license)",		"Track & Field (PlayChoice-10)", 0 )

/* B-Board Games */
GAMEB( 1986, pc_pwrst, playch10, playch10, playch10, playch10, pcbboard, ROT0, "Nintendo",									"Pro Wrestling (PlayChoice-10)", 0 )
GAMEB( 1986, pc_trjan, playch10, playch10, playch10, playch10, pcbboard, ROT0, "Capcom USA (Nintendo of America license)", "Trojan (PlayChoice-10)", 0 )
GAMEB( 1987, pc_cvnia, playch10, playch10, playch10, playch10, pcbboard, ROT0, "Konami (Nintendo of America license)",		"Castlevania (PlayChoice-10)", 0 )
GAMEB( 1987, pc_dbldr, playch10, playch10, playch10, playch10, pcbboard, ROT0, "Konami (Nintendo of America license)",		"Double Dribble (PlayChoice-10)", 0 )
GAMEB( 1987, pc_rnatk, playch10, playch10, playch10, playch10, pcbboard, ROT0, "Konami (Nintendo of America license)",		"Rush'n Attack (PlayChoice-10)", 0 )
GAMEB( 1987, pc_rygar, playch10, playch10, playch10, playch10, pcbboard, ROT0, "Tecmo (Nintendo of America license)",		"Rygar (PlayChoice-10)", 0 )
GAMEB( 1988, pc_cntra, playch10, playch10, playch10, playch10, pcbboard, ROT0, "Konami (Nintendo of America license)",		"Contra (PlayChoice-10)", 0 )

/* C-Board Games */
GAMEB( 1986, pc_goons, playch10, playch10, playch10, playch10, pccboard, ROT0, "Konami",									"The Goonies (PlayChoice-10)", 0 )

/* D-Board Games */
GAMEB( 1986, pc_mtoid, playch10, playch10, playch10, playch10, pcdboard_2, ROT0, "Nintendo",									"Metroid (PlayChoice-10)", 0 )
GAMEB( 1987, pc_radrc, playch10, playch10, playch10, playch10, pcdboard, ROT0, "Square",									"Rad Racer (PlayChoice-10)", 0 )

/* E-Board Games */
GAMEB( 1987, pc_miket, playch10, playch10, playchnv, playch10, pceboard, ROT0, "Nintendo",									"Mike Tyson's Punch-Out!! (PlayChoice-10)", GAME_IMPERFECT_GRAPHICS )

/* F-Board Games */
GAMEB( 1987, pc_rcpam, playch10, playch10, playch10, playch10, pcfboard, ROT0, "Rare",										"R.C. Pro-Am (PlayChoice-10)", 0 )
GAMEB( 1987, pc_rrngr, playch10, playch10, playch10, playch10, pcfboard, ROT0, "Capcom USA (Nintendo of America license)", "Chip'n Dale: Rescue Rangers (PlayChoice-10)", 0 )
GAMEB( 1988, pc_ddrgn, playch10, playch10, playch10, playch10, pcfboard, ROT0, "Technos",									"Double Dragon (PlayChoice-10)", 0 )
GAMEB( 1989, pc_ngaid, playch10, playch10, playch10, playch10, pcfboard, ROT0, "Tecmo (Nintendo of America license)",		"Ninja Gaiden (PlayChoice-10)", 0 )
GAMEB( 1989, pc_tmnt,  playch10, playch10, playch10, playch10, pcfboard, ROT0, "Konami (Nintendo of America license)",		"Teenage Mutant Ninja Turtles (PlayChoice-10)", 0 )
GAMEB( 1989, pc_ftqst, playch10, playch10, playch10, playch10, pcfboard, ROT0, "Sunsoft (Nintendo of America license)",	"Uncle Fester's Quest: The Addams Family (PlayChoice-10)", 0 )
GAMEB( 1989, pc_bstar, playch10, playch10, playch10, playch10, pcfboard_2, ROT0, "SNK (Nintendo of America license)",		"Baseball Stars: Be a Champ! (PlayChoice-10)", GAME_IMPERFECT_GRAPHICS)
GAMEB( 1989, pc_tbowl, playch10, playch10, playch10, playch10, pcfboard, ROT0, "Tecmo (Nintendo of America license)",		"Tecmo Bowl (PlayChoice-10)", 0 )
GAMEB( 1990, pc_drmro, playch10, playch10, playch10, playch10, pcfboard, ROT0, "Nintendo",									"Dr. Mario (PlayChoice-10)", 0 )
GAMEB( 1990, pc_ynoid, playch10, playch10, playch10, playch10, pcfboard, ROT0, "Capcom USA (Nintendo of America license)", "Yo! Noid (PlayChoice-10)", 0 )

/* G-Board Games */
GAMEB( 1988, pc_smb2,  playch10, playch10, playch10, playch10, pcgboard, ROT0, "Nintendo",									"Super Mario Bros. 2 (PlayChoice-10)", 0 )
GAMEB( 1988, pc_smb3,  playch10, playch10, playch10, playch10, pcgboard, ROT0, "Nintendo",									"Super Mario Bros. 3 (PlayChoice-10)", 0 )
GAMEB( 1990, pc_mman3, playch10, playch10, playch10, playch10, pcgboard, ROT0, "Capcom USA (Nintendo of America license)",	"Mega Man III (PlayChoice-10)", 0 )
GAMEB( 1990, pc_suprc, playch10, playch10, playch10, playch10, pcgboard, ROT0, "Konami (Nintendo of America license)",		"Super C (PlayChoice-10)", 0 )
GAMEB( 1990, pc_tmnt2, playch10, playch10, playch10, playch10, pcgboard, ROT0, "Konami (Nintendo of America license)",		"Teenage Mutant Ninja Turtles II: The Arcade Game (PlayChoice-10)", 0 )
GAMEB( 1990, pc_wcup,  playch10, playch10, playch10, playch10, pcgboard, ROT0, "Technos (Nintendo license)",				"Nintendo World Cup (PlayChoice-10)", 0 )
GAMEB( 1990, pc_ngai2, playch10, playch10, playch10, playch10, pcgboard, ROT0, "Tecmo (Nintendo of America license)",		"Ninja Gaiden Episode II: The Dark Sword of Chaos (PlayChoice-10)", 0 )
GAMEB( 1991, pc_ngai3, playch10, playch10, playch10, playch10, pcgboard, ROT0, "Tecmo (Nintendo of America license)",		"Ninja Gaiden Episode III: The Ancient Ship of Doom (PlayChoice-10)", 0 )
GAMEB( 1991, pc_pwbld, playch10, playch10, playch10, playch10, pcgboard, ROT0, "Taito (Nintendo of America license)",		"Power Blade (PlayChoice-10)", 0 )
GAMEB( 1991, pc_rkats, playch10, playch10, playch10, playch10, pcgboard, ROT0, "Atlus (Nintendo of America license)",		"Rockin' Kats (PlayChoice-10)", 0 )
/* variant with 4 screen mirror */
GAMEB( 1990, pc_radr2, playch10, playch10, playch10, playch10, pcgboard_type2, ROT0, "Square (Nintendo of America license)",		"Rad Racer II (PlayChoice-10)", 0 )
GAMEB( 1985, pc_gntlt, playch10, playch10, playch10, playch10, pcgboard_type2, ROT0, "Atari/Tengen (Nintendo of America license)",	"Gauntlet (PlayChoice-10)", GAME_IMPERFECT_GRAPHICS )

/* H-Board Games */
GAMEB( 1988, pc_pinbt, playch10, playch10, playch10, playch10, pchboard, ROT0, "Rare (Nintendo of America license)",		"PinBot (PlayChoice-10)", GAME_IMPERFECT_GRAPHICS | GAME_NOT_WORKING )

/* i-Board Games */
GAMEB( 1989, pc_cshwk, playch10, playch10, playch10, playch10, pciboard, ROT0, "Rare (Nintendo of America license)",		"Captain Sky Hawk (PlayChoice-10)", 0 )
GAMEB( 1990, pc_sjetm, playch10, playch10, playch10, playch10, pciboard, ROT0, "Rare",										"Solar Jetman (PlayChoice-10)", 0 )

/* K-Board Games */
GAMEB( 1991, pc_moglf, playch10, playch10, playch10, playch10, pckboard, ROT0, "Nintendo",									"Mario's Open Golf (PlayChoice-10)", 0 )
