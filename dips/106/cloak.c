# MAME 0.106 source snippet

#include "driver.h"
#include "sound/pokey.h"

/*************************************
 *
 *  Port definitions
 *
 *************************************/

INPUT_PORTS_START( cloak )
	PORT_START	/* IN0 */
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_JOYSTICKRIGHT_DOWN ) PORT_8WAY
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_JOYSTICKRIGHT_UP ) PORT_8WAY
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_JOYSTICKRIGHT_RIGHT ) PORT_8WAY
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_JOYSTICKRIGHT_LEFT ) PORT_8WAY
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_JOYSTICKLEFT_DOWN ) PORT_8WAY
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_JOYSTICKLEFT_UP ) PORT_8WAY
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_JOYSTICKLEFT_RIGHT ) PORT_8WAY
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_JOYSTICKLEFT_LEFT ) PORT_8WAY

	PORT_START	/* IN1 */
	PORT_BIT( 0xff, IP_ACTIVE_LOW, IPT_UNUSED )		// player 2 controls, not used

	PORT_START	/* IN2 */
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_VBLANK )
	PORT_SERVICE( 0x02, IP_ACTIVE_LOW )
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_COIN2 )
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_COIN1 )
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_UNUSED )		// cocktail mode switch, not used
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_SERVICE1 )
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_UNUSED )		// player 2 button 1, not used
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_BUTTON1 )

	PORT_START	/* IN3 */
	PORT_BIT( 0x2f, IP_ACTIVE_LOW, IPT_UNUSED )		// not connected
	PORT_BIT( 0x30, IP_ACTIVE_HIGH, IPT_UNUSED )	// pulled high
	PORT_BIT( 0x40, IP_ACTIVE_HIGH, IPT_START2 )
	PORT_BIT( 0x80, IP_ACTIVE_HIGH, IPT_START1 )

	PORT_START      /* DSW0 */
	PORT_DIPNAME( 0x03, 0x02, "Credits" )
	PORT_DIPSETTING(    0x02, "1 Credit/1 Game" )
	PORT_DIPSETTING(    0x01, "1 Credit/2 Games" )
	PORT_DIPSETTING(    0x03, "2 Credits/1 Game" )
	PORT_DIPSETTING(    0x00, DEF_STR( Free_Play ) )
	PORT_DIPNAME( 0x0c, 0x00, DEF_STR( Coin_B ) )
	PORT_DIPSETTING(    0x00, DEF_STR( 1C_1C ) )
	PORT_DIPSETTING(    0x04, DEF_STR( 1C_4C ) )
	PORT_DIPSETTING(    0x08, DEF_STR( 1C_5C ) )
	PORT_DIPSETTING(    0x0c, DEF_STR( 1C_6C ) )
	PORT_DIPNAME( 0x10, 0x00, DEF_STR( Coin_A ) )
	PORT_DIPSETTING(    0x00, DEF_STR( 1C_1C ) )
	PORT_DIPSETTING(    0x10, DEF_STR( 1C_2C ) )
	PORT_BIT( 0x20, IP_ACTIVE_HIGH, IPT_UNUSED )
	PORT_DIPNAME( 0x40, 0x00, "Demo Freeze Mode" )	// when active, press button 1 to freeze
	PORT_DIPSETTING(    0x00, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x40, DEF_STR( On ) )
	PORT_BIT( 0x80, IP_ACTIVE_HIGH, IPT_UNUSED )
INPUT_PORTS_END

/*************************************
 *
 *  Game drivers
 *
 *************************************/

GAME( 1983, cloak,   0,     cloak, cloak, 0, ROT0, "Atari", "Cloak & Dagger (rev 5)", GAME_SUPPORTS_SAVE )
GAME( 1983, cloaksp, cloak, cloak, cloak, 0, ROT0, "Atari", "Cloak & Dagger (Spanish)", GAME_SUPPORTS_SAVE )
GAME( 1983, cloakfr, cloak, cloak, cloak, 0, ROT0, "Atari", "Cloak & Dagger (French)", GAME_SUPPORTS_SAVE )
GAME( 1983, cloakgr, cloak, cloak, cloak, 0, ROT0, "Atari", "Cloak & Dagger (German)", GAME_SUPPORTS_SAVE )
