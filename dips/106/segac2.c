# MAME 0.106 source snippet [segac2.c]


#include "driver.h"
#include "cpu/m68000/m68000.h"
#include "genesis.h"


INPUT_PORTS_START( systemc_generic )
    PORT_START_TAG("P1")
    PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_PLAYER(1)
    PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_BUTTON2 ) PORT_PLAYER(1)
    PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_BUTTON3 ) PORT_PLAYER(1)
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_UNKNOWN )
    PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN ) PORT_PLAYER(1)
    PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_JOYSTICK_UP ) PORT_PLAYER(1)
    PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT ) PORT_PLAYER(1)
    PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT ) PORT_PLAYER(1)

    PORT_START_TAG("P2")
    PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_PLAYER(2)
    PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_BUTTON2 ) PORT_PLAYER(2)
    PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_BUTTON3 ) PORT_PLAYER(2)
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_UNKNOWN )
    PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN ) PORT_PLAYER(2)
    PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_JOYSTICK_UP ) PORT_PLAYER(2)
    PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT ) PORT_PLAYER(2)
    PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT ) PORT_PLAYER(2)

	PORT_START_TAG("PORTC")
	PORT_BIT( 0x3f, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_SPECIAL )	/* From uPD7759 pin 18. (/BUSY output) */
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_SPECIAL )	/* From MB3773P pin 1. (/RESET output) */

	PORT_START_TAG("PORTD")
	PORT_BIT( 0xff, IP_ACTIVE_LOW, IPT_UNUSED )

	PORT_START_TAG("SERVICE")
    PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_COIN1 )
    PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_COIN2 )
	PORT_SERVICE_NO_TOGGLE( 0x04, IP_ACTIVE_LOW )
    PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_SERVICE1 )
    PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_START1 )
    PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_START2 )
    PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_UNKNOWN )
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


INPUT_PORTS_START( columns )
	PORT_INCLUDE( systemc_generic )

	PORT_MODIFY("P1")
    PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_UNUSED )		/* Button 2 Unused */
    PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_UNUSED )		/* Button 3 Unused */

	PORT_MODIFY("P2")
    PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_UNUSED )		/* Button 2 Unused */
    PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_UNUSED )		/* Button 3 Unused */

	PORT_MODIFY("DSW")
	PORT_DIPNAME( 0x02, 0x00, DEF_STR( Demo_Sounds ) )
	PORT_DIPSETTING(    0x02, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    /* The first level increase (from 0 to 1) is always after destroying
       35 jewels. Then, the level gets 1 level more every : */
    PORT_DIPNAME( 0x30, 0x30, DEF_STR( Difficulty ) )
    PORT_DIPSETTING(    0x00, DEF_STR( Easy ) )     // 50 jewels
    PORT_DIPSETTING(    0x10, DEF_STR( Medium ) )   // 40 jewels
    PORT_DIPSETTING(    0x30, DEF_STR( Hard ) )     // 35 jewels
    PORT_DIPSETTING(    0x20, DEF_STR( Hardest ) )  // 25 jewels
INPUT_PORTS_END

INPUT_PORTS_START( columnsu )
	PORT_INCLUDE( systemc_generic )

	PORT_MODIFY("P1")
    PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_UNUSED )		/* Button 2 Unused */
    PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_UNUSED )		/* Button 3 Unused */

	PORT_MODIFY("P2")
    PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_UNUSED )		/* Button 2 Unused */
    PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_UNUSED )		/* Button 3 Unused */

	PORT_MODIFY("DSW")
	PORT_DIPNAME( 0x01, 0x01, DEF_STR( Cabinet ) )
	PORT_DIPSETTING(    0x01, DEF_STR( Upright ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Cocktail ) )
	PORT_DIPNAME( 0x02, 0x00, DEF_STR( Demo_Sounds ) )
	PORT_DIPSETTING(    0x02, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    /* The first level increase (from 0 to 1) is always after destroying
       35 jewels. Then, the level gets 1 level more every : */
    PORT_DIPNAME( 0x30, 0x30, DEF_STR( Difficulty ) )
    PORT_DIPSETTING(    0x00, DEF_STR( Easy ) )     // 50 jewels
    PORT_DIPSETTING(    0x10, DEF_STR( Medium ) )   // 40 jewels
    PORT_DIPSETTING(    0x30, DEF_STR( Hard ) )     // 35 jewels
    PORT_DIPSETTING(    0x20, DEF_STR( Hardest ) )  // 25 jewels
INPUT_PORTS_END

INPUT_PORTS_START( columns2 )
	PORT_INCLUDE( systemc_generic )

	PORT_MODIFY("P1")
    PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_UNUSED )		/* Button 2 Unused */
    PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_UNUSED )		/* Button 3 Unused */

	PORT_MODIFY("P2")
    PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_UNUSED )		/* Button 2 Unused */
    PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_UNUSED )		/* Button 3 Unused */

	PORT_MODIFY("DSW")
	PORT_DIPNAME( 0x01, 0x01, DEF_STR( Cabinet ) )
	PORT_DIPSETTING(    0x01, DEF_STR( Upright ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Cocktail ) )
    PORT_DIPNAME( 0x02, 0x00, DEF_STR( Demo_Sounds ) )
	PORT_DIPSETTING(    0x02, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x0c, 0x0c, "VS. Mode Credits/Match" )
	PORT_DIPSETTING(    0x0c, "1" )
	PORT_DIPSETTING(    0x08, "2" )
	PORT_DIPSETTING(    0x04, "3" )
	PORT_DIPSETTING(    0x00, "4" )
	PORT_DIPNAME( 0x30, 0x30, "Flash Mode Difficulty" )
	PORT_DIPSETTING(    0x20, DEF_STR( Easy ) )
    PORT_DIPSETTING(    0x30, DEF_STR( Medium ) )
	PORT_DIPSETTING(    0x10, DEF_STR( Hard ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Hardest ) )
INPUT_PORTS_END


INPUT_PORTS_START( borench )
	PORT_INCLUDE( systemc_generic )

	PORT_MODIFY("P1")
    PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_UNUSED )		/* Button 3 Unused */

	PORT_MODIFY("P2")
    PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_UNUSED )		/* Button 3 Unused */

	PORT_MODIFY("DSW")
	PORT_DIPNAME( 0x01, 0x01, "Credits to Start" )
	PORT_DIPSETTING(    0x01, "1" )
	PORT_DIPSETTING(    0x00, "2" )
    PORT_DIPNAME( 0x02, 0x00, DEF_STR( Demo_Sounds ) )
	PORT_DIPSETTING(    0x02, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPNAME( 0x0c, 0x0c, "Lives 1P Mode" )
	PORT_DIPSETTING(    0x00, "1" )
	PORT_DIPSETTING(    0x0c, "2" )
	PORT_DIPSETTING(    0x08, "3" )
	PORT_DIPSETTING(    0x04, "4" )
    PORT_DIPNAME( 0x30, 0x30, "Lives 2P Mode" )
	PORT_DIPSETTING(    0x00, "2" )
	PORT_DIPSETTING(    0x30, "3" )
	PORT_DIPSETTING(    0x20, "4" )
	PORT_DIPSETTING(    0x10, "5" )
	PORT_DIPNAME( 0xc0, 0xc0, DEF_STR( Difficulty ) )
	PORT_DIPSETTING(    0x80, DEF_STR( Easy ) )
    PORT_DIPSETTING(    0xc0, DEF_STR( Medium ) )
	PORT_DIPSETTING(    0x40, DEF_STR( Hard ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Hardest ) )
INPUT_PORTS_END


INPUT_PORTS_START( tfrceac )
	PORT_INCLUDE( systemc_generic )

	PORT_MODIFY("DSW")
	PORT_DIPNAME( 0x01, 0x01, "Credits to Start" )
	PORT_DIPSETTING(    0x01, "1" )
	PORT_DIPSETTING(    0x00, "2" )
    PORT_DIPNAME( 0x02, 0x00, DEF_STR( Demo_Sounds ) )
	PORT_DIPSETTING(    0x02, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPNAME( 0x0c, 0x0c, DEF_STR( Lives ) )
	PORT_DIPSETTING(    0x00, "2" )
	PORT_DIPSETTING(    0x0c, "3" )
	PORT_DIPSETTING(    0x08, "4" )
	PORT_DIPSETTING(    0x04, "5" )
	PORT_DIPNAME( 0x30, 0x30,  DEF_STR( Bonus_Life ) )
    PORT_DIPSETTING(    0x10, "10k, 70k, 150k" )
    PORT_DIPSETTING(    0x30, "20k, 100k, 200k" )
    PORT_DIPSETTING(    0x20, "40k, 150k, 300k" )
    PORT_DIPSETTING(    0x00, DEF_STR( None ) )
	PORT_DIPNAME( 0xc0, 0xc0, DEF_STR( Difficulty ) )
	PORT_DIPSETTING(    0x80, DEF_STR( Easy ) )
    PORT_DIPSETTING(    0xc0, DEF_STR( Medium ) )
	PORT_DIPSETTING(    0x40, DEF_STR( Hard ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Hardest ) )
INPUT_PORTS_END


INPUT_PORTS_START( twinsqua )
	PORT_INCLUDE( systemc_generic )

	PORT_MODIFY("P1")
	PORT_BIT( 0xff, 0x00, IPT_DIAL ) PORT_SENSITIVITY(30) PORT_KEYDELTA(15) PORT_PLAYER(1)

	PORT_MODIFY("P2")
	PORT_BIT( 0xff, 0x00, IPT_DIAL ) PORT_SENSITIVITY(30) PORT_KEYDELTA(15) PORT_PLAYER(2)

	PORT_MODIFY("SERVICE")
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_PLAYER(1)
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_PLAYER(2)

	PORT_MODIFY("DSW")
	PORT_DIPNAME( 0x01, 0x01, "Credits to Start" )
	PORT_DIPSETTING(    0x01, "1" )
	PORT_DIPSETTING(    0x00, "2" )
    PORT_DIPNAME( 0x02, 0x00, DEF_STR( Demo_Sounds ) )
	PORT_DIPSETTING(    0x02, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPNAME( 0x04, 0x04, "Buy In" )
	PORT_DIPSETTING(    0x04, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x18, 0x18, DEF_STR( Difficulty ) )
	PORT_DIPSETTING(    0x10, DEF_STR( Easy ) )
    PORT_DIPSETTING(    0x18, DEF_STR( Medium ) )
	PORT_DIPSETTING(    0x08, DEF_STR( Hard ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Hardest ) )
    PORT_DIPNAME( 0x20, 0x20, "Seat Type" )
	PORT_DIPSETTING(    0x20, DEF_STR( Normal ) )
	PORT_DIPSETTING(    0x00, "Moving" )
INPUT_PORTS_END


INPUT_PORTS_START( ribbit )
	PORT_INCLUDE( systemc_generic )

	PORT_MODIFY("P1")
    PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_UNUSED )		/* Button 1 Unused */
    PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_UNUSED )		/* Button 2 Unused */
    PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_UNUSED )		/* Button 3 Unused */

	PORT_MODIFY("P2")
    PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_UNUSED )		/* Button 1 Unused */
    PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_UNUSED )		/* Button 2 Unused */
    PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_UNUSED )		/* Button 3 Unused */

	PORT_MODIFY("DSW")
	PORT_DIPNAME( 0x01, 0x01, "Credits to Start" )
	PORT_DIPSETTING(    0x01, "1" )
	PORT_DIPSETTING(    0x00, "2" )
    PORT_DIPNAME( 0x02, 0x00, DEF_STR( Demo_Sounds ) )
	PORT_DIPSETTING(    0x02, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPNAME( 0x0c, 0x04, DEF_STR( Lives ) )
	PORT_DIPSETTING(    0x08, "1" )
	PORT_DIPSETTING(    0x0c, "2" )
	PORT_DIPSETTING(    0x04, "3" )
	PORT_DIPSETTING(    0x00, "5" )
	PORT_DIPNAME( 0x30, 0x30, DEF_STR( Difficulty ) )
    PORT_DIPSETTING(    0x20, DEF_STR( Easy ) )
    PORT_DIPSETTING(    0x30, DEF_STR( Normal ) )
    PORT_DIPSETTING(    0x10, DEF_STR( Hard ) )
    PORT_DIPSETTING(    0x00, DEF_STR( Hardest ) )
INPUT_PORTS_END


INPUT_PORTS_START( puyo )
	PORT_INCLUDE( systemc_generic )

	PORT_MODIFY("P1")
    PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_UNUSED )		/* Button 2 Unused */
    PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_UNUSED )		/* Button 3 Unused */

	PORT_MODIFY("P2")
    PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_UNUSED )		/* Button 2 Unused */
    PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_UNUSED )		/* Button 3 Unused */

	PORT_MODIFY("DSW")
    PORT_DIPNAME( 0x02, 0x00, DEF_STR( Demo_Sounds ) )
	PORT_DIPSETTING(    0x02, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x04, 0x04, "VS. Mode Credits/Match" )
	PORT_DIPSETTING(    0x04, "1" )
	PORT_DIPSETTING(    0x00, "3" )
	PORT_DIPNAME( 0x18, 0x18, "1P Mode Difficulty" )
	PORT_DIPSETTING(    0x10, DEF_STR( Easy ) )
    PORT_DIPSETTING(    0x18, DEF_STR( Medium ) )
	PORT_DIPSETTING(    0x08, DEF_STR( Hard ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Hardest ) )
	PORT_DIPNAME( 0x80, 0x80, "Moving Seat" )
	PORT_DIPSETTING(    0x80, "No Use" )
	PORT_DIPSETTING(    0x00, "In Use" )
INPUT_PORTS_END


INPUT_PORTS_START( stkclmns )
	PORT_INCLUDE( systemc_generic )

	PORT_MODIFY("P1")
    PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_UNUSED )		/* Button 3 Unused */

	PORT_MODIFY("P2")
    PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_UNUSED )		/* Button 3 Unused */

	PORT_MODIFY("DSW")
	PORT_DIPNAME( 0x03, 0x03, DEF_STR( Difficulty ) )
	PORT_DIPSETTING(    0x02, DEF_STR( Easy ) )
    PORT_DIPSETTING(    0x03, DEF_STR( Medium ) )
	PORT_DIPSETTING(    0x01, DEF_STR( Hard ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Hardest ) )
    PORT_DIPNAME( 0x04, 0x00, DEF_STR( Demo_Sounds ) )
	PORT_DIPSETTING(    0x04, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x08, 0x08, "Match Mode Price" )
	PORT_DIPSETTING(    0x08, "1" )
	PORT_DIPSETTING(    0x00, "2" )
INPUT_PORTS_END


INPUT_PORTS_START( potopoto )
	PORT_INCLUDE( systemc_generic )

	PORT_MODIFY("P1")
    PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_UNUSED )		/* Button 2 Unused */
    PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_UNUSED )		/* Button 3 Unused */

	PORT_MODIFY("P2")
    PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_UNUSED )		/* Button 2 Unused */
    PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_UNUSED )		/* Button 3 Unused */

	PORT_MODIFY("DSW")
	PORT_DIPNAME( 0x01, 0x01, "Credits to Start" )
	PORT_DIPSETTING(    0x01, "1" )
	PORT_DIPSETTING(    0x00, "2" )
    PORT_DIPNAME( 0x02, 0x00, DEF_STR( Demo_Sounds ) )
	PORT_DIPSETTING(    0x02, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x04, 0x04, "Coin Chute Type" )
	PORT_DIPSETTING(    0x04, "Common" )
	PORT_DIPSETTING(    0x00, "Individual" )
	PORT_DIPNAME( 0x08, 0x08, "Credits to Continue" )
	PORT_DIPSETTING(    0x08, "1" )
	PORT_DIPSETTING(    0x00, "2" )
	PORT_DIPNAME( 0x10, 0x10, "Buy-In" )
	PORT_DIPSETTING(    0x10, DEF_STR( No ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Yes ) )
	PORT_DIPNAME( 0x60, 0x60, DEF_STR( Difficulty ) )
	PORT_DIPSETTING(    0x40, DEF_STR( Easy ) )
    PORT_DIPSETTING(    0x60, DEF_STR( Medium ) )
	PORT_DIPSETTING(    0x20, DEF_STR( Hard ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Hardest ) )
	PORT_DIPNAME( 0x80, 0x80, "Moving Seat" )
	PORT_DIPSETTING(    0x80, "No Use" )
	PORT_DIPSETTING(    0x00, "In Use" )
INPUT_PORTS_END


INPUT_PORTS_START( zunkyou )
	PORT_INCLUDE( systemc_generic )

	PORT_MODIFY("P1")
    PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_UNUSED )		/* Button 3 Unused */

	PORT_MODIFY("P2")
    PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_UNUSED )		/* Button 3 Unused */

	PORT_MODIFY("DSW")
	PORT_DIPNAME( 0x01, 0x01, "Game Difficulty 1" )
    PORT_DIPSETTING(    0x01, DEF_STR( Medium ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Hard ) )
	PORT_DIPNAME( 0x02, 0x02, "Game Difficulty 2" )
    PORT_DIPSETTING(    0x02, DEF_STR( Medium ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Hard ) )
    PORT_DIPNAME( 0x0c, 0x0c, DEF_STR( Lives ) )
	PORT_DIPSETTING(    0x08, "1" )
	PORT_DIPSETTING(    0x04, "2" )
	PORT_DIPSETTING(    0x0c, "3" )
	PORT_DIPSETTING(    0x00, "5" )
    PORT_DIPNAME( 0x10, 0x00, DEF_STR( Demo_Sounds ) )
	PORT_DIPSETTING(    0x10, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
INPUT_PORTS_END


INPUT_PORTS_START( ichir )
	PORT_INCLUDE( systemc_generic )

	PORT_MODIFY("P1")
    PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_UNUSED )		/* Button 2 Unused */
    PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_UNUSED )		/* Button 3 Unused */

	PORT_MODIFY("P2")
    PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_UNUSED )		/* Button 2 Unused */
    PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_UNUSED )		/* Button 3 Unused */

	PORT_MODIFY("DSW")
    PORT_DIPNAME( 0x01, 0x00, DEF_STR( Demo_Sounds ) )
    PORT_DIPSETTING(    0x01, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPNAME( 0x06, 0x06, DEF_STR( Difficulty ) )
    PORT_DIPSETTING(    0x04, DEF_STR( Easy ) )
    PORT_DIPSETTING(    0x06, DEF_STR( Medium ) )
    PORT_DIPSETTING(    0x02, DEF_STR( Hard ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Hardest ) )
INPUT_PORTS_END


INPUT_PORTS_START( bloxeedc )
	PORT_INCLUDE( systemc_generic )

	PORT_MODIFY("P1")
    PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_UNUSED )		/* Button 2 Unused */
    PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_UNUSED )		/* Button 3 Unused */

	PORT_MODIFY("P2")
    PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_UNUSED )		/* Button 2 Unused */
    PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_UNUSED )		/* Button 3 Unused */

	PORT_MODIFY("DSW")
    PORT_DIPNAME( 0x01, 0x01, "VS Mode Price" )
    PORT_DIPSETTING(    0x00, "Same as Ordinary" )
    PORT_DIPSETTING(    0x01, "Double as Ordinary" )
    PORT_DIPNAME( 0x02, 0x02, "Credits to Start" )
    PORT_DIPSETTING(    0x02, "1" )
	PORT_DIPSETTING(    0x00, "2" )
    PORT_DIPNAME( 0x08, 0x00, DEF_STR( Demo_Sounds ) )
    PORT_DIPSETTING(    0x08, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
INPUT_PORTS_END


INPUT_PORTS_START( puyopuy2 )
	PORT_INCLUDE( systemc_generic )

	PORT_MODIFY("P1")
    PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_UNUSED )		/* Button 3 Unused */

	PORT_MODIFY("P2")
    PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_UNUSED )		/* Button 3 Unused */

	PORT_MODIFY("DSW")
    PORT_DIPNAME( 0x01, 0x01, "Rannyu Off Button" )
    PORT_DIPSETTING(    0x01, "Use" )
    PORT_DIPSETTING(    0x00, "No Use" )
    PORT_DIPNAME( 0x02, 0x00, DEF_STR( Demo_Sounds ) )
    PORT_DIPSETTING(    0x02, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPNAME( 0x04, 0x04, "Turn Direction" )
    PORT_DIPSETTING(    0x04, "1:Right  2:Left" )
    PORT_DIPSETTING(    0x00, "1:Left  2:Right")
    PORT_DIPNAME( 0x18, 0x18, DEF_STR( Difficulty ) )
    PORT_DIPSETTING(    0x10, DEF_STR( Easy ) )
    PORT_DIPSETTING(    0x18, DEF_STR( Medium ) )
    PORT_DIPSETTING(    0x08, DEF_STR( Hard ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Hardest ) )
    PORT_DIPNAME( 0x60, 0x60, "VS Mode Match/1 Play" )
    PORT_DIPSETTING(    0x60, "1" )
    PORT_DIPSETTING(    0x40, "2" )
    PORT_DIPSETTING(    0x20, "3" )
    PORT_DIPSETTING(    0x00, "4" )
    PORT_DIPNAME( 0x80, 0x80, "Battle Start credit" )
    PORT_DIPSETTING(    0x00, "1" )
    PORT_DIPSETTING(    0x80, "2" )
INPUT_PORTS_END


INPUT_PORTS_START( pclub )
	PORT_INCLUDE( systemc_generic )

	PORT_MODIFY("P1")
	PORT_BIT( 0x0f, IP_ACTIVE_LOW, IPT_UNKNOWN ) 	/* Probably Unused */
    PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_NAME("Ok")
    PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_BUTTON2 ) PORT_NAME("Cancel")
    PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT ) PORT_2WAY
    PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT ) PORT_2WAY

	PORT_MODIFY("P2")
	PORT_BIT( 0xff, IP_ACTIVE_LOW, IPT_UNKNOWN ) 	/* Probably Unused */

	PORT_MODIFY("SERVICE")
	PORT_BIT( 0xf0, IP_ACTIVE_LOW, IPT_UNKNOWN )	/* Probably Unused */

	PORT_MODIFY("COINAGE")
	PORT_DIPNAME( 0x07, 0x07, DEF_STR( Coinage ) )
	PORT_DIPSETTING(    0x00, DEF_STR( 7C_1C ) )
	PORT_DIPSETTING(    0x01, DEF_STR( 6C_1C ) )
	PORT_DIPSETTING(    0x02, DEF_STR( 5C_1C ) )
	PORT_DIPSETTING(    0x03, DEF_STR( 4C_1C ) )
    PORT_DIPSETTING(    0x07, DEF_STR( 3C_1C ) )
	PORT_DIPSETTING(    0x04, DEF_STR( 2C_1C ) )
	PORT_DIPSETTING(    0x05, DEF_STR( 1C_1C ) )
    PORT_DIPSETTING(    0x06, DEF_STR( Free_Play ) )
    PORT_DIPNAME( 0x08, 0x08, "Unknown 4-4" )
    PORT_DIPSETTING(    0x08, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPNAME( 0x10, 0x10, "Unknown 4-5" )
    PORT_DIPSETTING(    0x10, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPNAME( 0x20, 0x20, "Unknown 4-6" )
    PORT_DIPSETTING(    0x20, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPNAME( 0x40, 0x40, "Unknown 4-7" )
    PORT_DIPSETTING(    0x40, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPNAME( 0x80, 0x80, "Unknown 4-8" )
    PORT_DIPSETTING(    0x80, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )

	PORT_MODIFY("DSW")
    PORT_DIPNAME( 0x01, 0x01, "Unknown 5-1" )
    PORT_DIPSETTING(    0x01, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPNAME( 0x02, 0x02, "Unknown 5-2" )
    PORT_DIPSETTING(    0x02, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPNAME( 0x04, 0x04, "Unknown 5-3" )
    PORT_DIPSETTING(    0x04, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPNAME( 0x08, 0x08, "Unknown 5-4" )
    PORT_DIPSETTING(    0x08, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPNAME( 0x10, 0x10, "Unknown 5-5" )
    PORT_DIPSETTING(    0x10, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPNAME( 0x20, 0x20, DEF_STR( Demo_Sounds ))
    PORT_DIPSETTING(    0x00, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x20, DEF_STR( On ) )
    PORT_DIPNAME( 0x40, 0x40, "Unknown 5-7" )
    PORT_DIPSETTING(    0x40, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPNAME( 0x80, 0x80, "Unknown 5-8" )
    PORT_DIPSETTING(    0x80, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
INPUT_PORTS_END




/* System C Games */
GAME( 1989, bloxeedc, bloxeed,  segac,    bloxeedc, bloxeedc, ROT0, "Sega / Elorg",           "Bloxeed (World, C System)", 0 )
GAME( 1989, bloxeedu, bloxeed,  segac,    bloxeedc, bloxeedc, ROT0, "Sega / Elorg",           "Bloxeed (US, C System)", 0 )
GAME( 1990, columns,  0,        segac,    columns,  columns,  ROT0, "Sega",                   "Columns (World)", 0 )
GAME( 1990, columnsu, columns,  segac,    columnsu, columns,  ROT0, "Sega",                   "Columns (US, cocktail)", 0 ) // has cocktail mode dsw
GAME( 1990, columnsj, columns,  segac,    columns,  columns,  ROT0, "Sega",                   "Columns (Japan)", 0 )
GAME( 1990, columns2, 0,        segac,    columns2, columns2, ROT0, "Sega",                   "Columns II: The Voyage Through Time (World)", 0 )
GAME( 1990, column2j, columns2, segac,    columns2, columns2, ROT0, "Sega",                   "Columns II: The Voyage Through Time (Japan)", 0 )

/* System C-2 Games */
GAME( 1990, borench,  0,        segac2,   borench,  borench,  ROT0, "Sega",                   "Borench", 0 )
GAME( 1990, tfrceac,  0,        segac2,   tfrceac,  tfrceac,  ROT0, "Sega / Technosoft",      "ThunderForce AC", 0 )
GAME( 1990, tfrceacj, tfrceac,  segac2,   tfrceac,  tfrceac,  ROT0, "Sega / Technosoft",      "ThunderForce AC (Japan)", 0 )
GAME( 1990, tfrceacb, tfrceac,  segac2,   tfrceac,  tfrceacb, ROT0, "bootleg",                "ThunderForce AC (bootleg)", 0 )
GAME( 1991, twinsqua, 0,        segac2,   twinsqua, twinsqua, ROT0, "Sega",                   "Twin Squash", 0 )
GAME( 1991, ribbit,   0,        segac2,   ribbit,   ribbit,   ROT0, "Sega",                   "Ribbit!", 0 )
GAME( 1992, tantr,    0,        segac2,   ichir,    tantr,    ROT0, "Sega",                   "Puzzle & Action: Tant-R (Japan)", 0 )
GAME( 1993, tantrkor, tantr,    segac2,   ichir,    tantrkor, ROT0, "Sega",                   "Puzzle & Action: Tant-R (Korea)", 0 )
GAME( 1992, tantrbl,  tantr,    segac2,   ichir,    c2boot,   ROT0, "bootleg",                "Puzzle & Action: Tant-R (Japan) (bootleg set 1)", 0 )
GAME( 1994, tantrbl2, tantr,    segac,    ichir,    tantr,    ROT0, "bootleg",                "Puzzle & Action: Tant-R (Japan) (bootleg set 2)", 0 ) // Common bootleg in Europe, C board, no samples
GAME( 1992, puyo,     0,        segac2,   puyo,     puyo,     ROT0, "Sega / Compile",         "Puyo Puyo (World)", 0 )
GAME( 1992, puyobl,   puyo,     segac2,   puyo,     puyo,     ROT0, "bootleg",                "Puyo Puyo (World, bootleg)", 0 )
GAME( 1992, puyoj,    puyo,     segac2,   puyo,     puyo,     ROT0, "Sega / Compile",         "Puyo Puyo (Japan)", 0 )
GAME( 1992, puyoja,   puyo,     segac2,   puyo,     puyo,     ROT0, "Sega / Compile",         "Puyo Puyo (Japan, Rev A)", 0 )
GAME( 1994, ichir,    0,        segac2,   ichir,    ichir,    ROT0, "Sega",                   "Puzzle & Action: Ichidant-R (World)", 0 )
GAME( 1994, ichirk,   ichir,    segac2,   ichir,    ichirk,   ROT0, "Sega",                   "Puzzle & Action: Ichidant-R (Korea)", 0 )
GAME( 1994, ichirj,   ichir,    segac2,   ichir,    ichirj,   ROT0, "Sega",                   "Puzzle & Action: Ichidant-R (Japan)", 0 )
GAME( 1994, ichirjbl, ichir,    segac,    ichir,    ichirjbl, ROT0, "bootleg",                "Puzzle & Action: Ichidant-R (Japan) (bootleg)", 0 ) // C board, no samples
GAME( 1994, stkclmns, 0,        segac2,   stkclmns, stkclmns, ROT0, "Sega",                   "Stack Columns (World)", 0 )
GAME( 1994, stkclmnj, stkclmns, segac2,   stkclmns, stkclmnj, ROT0, "Sega",                   "Stack Columns (Japan)", 0 )
GAME( 1994, puyopuy2, 0,        segac2,   puyopuy2, puyopuy2, ROT0, "Compile (Sega license)", "Puyo Puyo 2 (Japan)", 0 )
GAME( 1994, potopoto, 0,        segac2,   potopoto, potopoto, ROT0, "Sega",                   "Poto Poto (Japan)", 0 )
GAME( 1994, zunkyou,  0,        segac2,   zunkyou,  zunkyou,  ROT0, "Sega",                   "Zunzunkyou No Yabou (Japan)", 0 )

/* Atlus Print Club 'Games' (C-2 Hardware, might not be possible to support them because they use camera + printer, really just put here for reference) */
GAME( 1995, pclubj,   0,        segac2,   pclub,    pclub,    ROT0, "Atlus",                  "Print Club (Japan Vol.1)", GAME_NOT_WORKING )
GAME( 1995, pclubjv2, pclubj,   segac2,   pclub,    pclubjv2, ROT0, "Atlus",                  "Print Club (Japan Vol.2)", GAME_NOT_WORKING )
GAME( 1996, pclubjv4, pclubj,   segac2,   pclub,    pclubjv4, ROT0, "Atlus",                  "Print Club (Japan Vol.4)", GAME_NOT_WORKING )
GAME( 1996, pclubjv5, pclubj,   segac2,   pclub,    pclubjv5, ROT0, "Atlus",                  "Print Club (Japan Vol.5)", GAME_NOT_WORKING )
