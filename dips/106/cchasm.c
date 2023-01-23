# MAME 0.106 source snippet


#include "driver.h"
#include "vidhrdw/vector.h"
#include "machine/z80ctc.h"
#include "cchasm.h"
#include "sound/custom.h"
#include "sound/ay8910.h"
#include "cpu/z80/z80daisy.h"


/*************************************
 *
 *  Port definitions
 *
 *************************************/

INPUT_PORTS_START( cchasm )
	PORT_START /* DSW */
	PORT_DIPNAME( 0x01, 0x01, DEF_STR( Lives ) )
	PORT_DIPSETTING(    0x01, "3" )
	PORT_DIPSETTING(    0x00, "5" )
	PORT_DIPNAME( 0x06, 0x06, DEF_STR( Bonus_Life ) )
	PORT_DIPSETTING(    0x06, "40000" )
	PORT_DIPSETTING(    0x04, "60000" )
	PORT_DIPSETTING(    0x02, "80000" )
	PORT_DIPSETTING(    0x00, "100000" )
	PORT_DIPNAME( 0x08, 0x08, DEF_STR( Difficulty ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Easy ) )
	PORT_DIPSETTING(    0x08, DEF_STR( Hard ) )
	PORT_DIPNAME( 0x10, 0x10, DEF_STR( Bonus_Life ) )
	PORT_DIPSETTING(    0x00, "Once" )
	PORT_DIPSETTING(    0x10, "Every" )
	PORT_DIPNAME( 0x20, 0x00, DEF_STR( Demo_Sounds ) )
	PORT_DIPSETTING(    0x20, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x40, 0x40, DEF_STR( Coinage ) )
	PORT_DIPSETTING(    0x00, DEF_STR( 2C_1C ) )
	PORT_DIPSETTING(    0x40, DEF_STR( 1C_1C ) )
	PORT_SERVICE( 0x80, IP_ACTIVE_LOW )

	PORT_START /* IN1 */
	PORT_BIT( 0xff, 0, IPT_DIAL ) PORT_SENSITIVITY(100) PORT_KEYDELTA(10)

	PORT_START /* IN2 */
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_BUTTON1 )
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_BUTTON2 )
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_BUTTON3 )
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_START1 )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_START2 )

	PORT_START /* IN3 */
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_COIN1 )
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_COIN2 )
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_COIN3 )
	PORT_BIT(0x01, IP_ACTIVE_LOW, IPT_OTHER ) PORT_NAME("Test 1") PORT_CODE(KEYCODE_F1)
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_UNUSED ) /* Test 2, not used in cchasm */
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_UNUSED ) /* Test 3, not used in cchasm */
INPUT_PORTS_END



/*************************************
 *
 *  Game drivers
 *
 *************************************/

GAME( 1983, cchasm,  0,      cchasm, cchasm, 0, ROT270, "Cinematronics / GCE", "Cosmic Chasm (set 1)", 0 )
GAME( 1983, cchasm1, cchasm, cchasm, cchasm, 0, ROT270, "Cinematronics / GCE", "Cosmic Chasm (set 2)", 0 )
