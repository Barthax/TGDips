# MAME 0.106 source snippet


#include "driver.h"
#include "vidhrdw/vector.h"
#include "vidhrdw/avgdvg.h"
#include "machine/mathbox.h"
#include "machine/atari_vg.h"
#include "sound/pokey.h"
#include "sound/custom.h"
#include "artwork.h"
#include "bzone.h"

#define IN0_3KHZ (1<<7)
#define IN0_VG_HALT (1<<6)



#define BZONEIN0\
	PORT_START_TAG("IN0")\
	PORT_BIT ( 0x01, IP_ACTIVE_LOW, IPT_COIN1 )\
	PORT_BIT ( 0x02, IP_ACTIVE_LOW, IPT_COIN2 )\
	PORT_BIT ( 0x0c, IP_ACTIVE_LOW, IPT_UNUSED )\
	PORT_SERVICE( 0x10, IP_ACTIVE_LOW )\
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_SERVICE ) PORT_NAME("Diagnostic Step") PORT_CODE(KEYCODE_F1)\
 	/* bit 6 is the VG HALT bit. We set it to "low" */\
	/* per default (busy vector processor). */\
 	/* handled by bzone_IN0_r() */\
	PORT_BIT ( 0x40, IP_ACTIVE_HIGH, IPT_SPECIAL )\
	/* bit 7 is tied to a 3kHz clock */\
 	/* handled by bzone_IN0_r() */\
  	PORT_BIT ( 0x80, IP_ACTIVE_HIGH, IPT_SPECIAL )


#define BZONEDSW0\
	PORT_START_TAG("DSW0")\
	PORT_DIPNAME(0x03, 0x01, DEF_STR( Lives ) )\
	PORT_DIPSETTING (  0x00, "2" )\
	PORT_DIPSETTING (  0x01, "3" )\
	PORT_DIPSETTING (  0x02, "4" )\
	PORT_DIPSETTING (  0x03, "5" )\
	PORT_DIPNAME(0x0c, 0x04, "Missile appears at" )\
	PORT_DIPSETTING (  0x00, "5000" )\
	PORT_DIPSETTING (  0x04, "10000" )\
	PORT_DIPSETTING (  0x08, "20000" )\
	PORT_DIPSETTING (  0x0c, "30000" )\
	PORT_DIPNAME(0x30, 0x10, DEF_STR( Bonus_Life ) )\
	PORT_DIPSETTING (  0x10, "15k and 100k" )\
	PORT_DIPSETTING (  0x20, "20k and 100k" )\
	PORT_DIPSETTING (  0x30, "50k and 100k" )\
	PORT_DIPSETTING (  0x00, DEF_STR( None ) )\
	PORT_DIPNAME(0xc0, 0x00, DEF_STR( Language ) )\
	PORT_DIPSETTING (  0x00, DEF_STR( English ))\
	PORT_DIPSETTING (  0x40, DEF_STR( German ))\
	PORT_DIPSETTING (  0x80, DEF_STR( French ))\
  	PORT_DIPSETTING (  0xc0, DEF_STR( Spanish ))

#define BZONEDSW1\
	PORT_START_TAG("DSW1")\
	PORT_DIPNAME(0x03, 0x02, DEF_STR( Coinage ) )\
	PORT_DIPSETTING (  0x03, DEF_STR( 2C_1C ) )\
	PORT_DIPSETTING (  0x02, DEF_STR( 1C_1C ) )\
	PORT_DIPSETTING (  0x01, DEF_STR( 1C_2C ) )\
	PORT_DIPSETTING (  0x00, DEF_STR( Free_Play ) )\
	PORT_DIPNAME(0x0c, 0x00, DEF_STR( Coin_B ) )\
	PORT_DIPSETTING (  0x00, "*1" )\
	PORT_DIPSETTING (  0x04, "*4" )\
	PORT_DIPSETTING (  0x08, "*5" )\
	PORT_DIPSETTING (  0x0c, "*6" )\
	PORT_DIPNAME(0x10, 0x00, DEF_STR( Coin_A ) )\
	PORT_DIPSETTING (  0x00, "*1" )\
	PORT_DIPSETTING (  0x10, "*2" )\
	PORT_DIPNAME(0xe0, 0x00, "Bonus Coins" )\
	PORT_DIPSETTING (  0x00, DEF_STR( None ) )\
	PORT_DIPSETTING (  0x20, "3 credits/2 coins" )\
	PORT_DIPSETTING (  0x40, "5 credits/4 coins" )\
	PORT_DIPSETTING (  0x60, "6 credits/4 coins" )\
  	PORT_DIPSETTING (  0x80, "6 credits/5 coins" )

INPUT_PORTS_START( bzone )
BZONEIN0
BZONEDSW0
BZONEDSW1

	PORT_START_TAG("IN3")
  	PORT_BIT( 0x01, IP_ACTIVE_HIGH, IPT_JOYSTICKRIGHT_DOWN ) PORT_2WAY
  	PORT_BIT( 0x02, IP_ACTIVE_HIGH, IPT_JOYSTICKRIGHT_UP ) PORT_2WAY
  	PORT_BIT( 0x04, IP_ACTIVE_HIGH, IPT_JOYSTICKLEFT_DOWN ) PORT_2WAY
	PORT_BIT( 0x08, IP_ACTIVE_HIGH, IPT_JOYSTICKLEFT_UP ) PORT_2WAY
	PORT_BIT( 0x10, IP_ACTIVE_HIGH, IPT_BUTTON3 )
	PORT_BIT( 0x20, IP_ACTIVE_HIGH, IPT_START1 )
	PORT_BIT( 0x40, IP_ACTIVE_HIGH, IPT_START2 )
	PORT_BIT( 0x80, IP_ACTIVE_HIGH, IPT_UNUSED )
INPUT_PORTS_END


INPUT_PORTS_START( redbaron )
BZONEIN0
	PORT_START_TAG("DSW0")
	/* See the table above if you are really interested */
	PORT_DIPNAME(0xff, 0xfd, DEF_STR( Coinage ) )
	PORT_DIPSETTING (  0xfd, DEF_STR( Normal ) )

	PORT_START_TAG("DSW1")
	PORT_DIPNAME(0x03, 0x03, DEF_STR( Language ) )
	PORT_DIPSETTING (  0x00, DEF_STR( German ) )
	PORT_DIPSETTING (  0x01, DEF_STR( French ) )
	PORT_DIPSETTING (  0x02, DEF_STR( Spanish ) )
	PORT_DIPSETTING (  0x03, DEF_STR( English ) )
	PORT_DIPNAME(0x0c, 0x04, DEF_STR( Bonus_Life ) )
	PORT_DIPSETTING (  0x0c, "2k 10k 30k" )
	PORT_DIPSETTING (  0x08, "4k 15k 40k" )
	PORT_DIPSETTING (  0x04, "6k 20k 50k" )
	PORT_DIPSETTING (  0x00, DEF_STR( None ) )
	PORT_DIPNAME(0x30, 0x20, DEF_STR( Lives ) )
	PORT_DIPSETTING (  0x30, "2" )
	PORT_DIPSETTING (  0x20, "3" )
	PORT_DIPSETTING (  0x10, "4" )
	PORT_DIPSETTING (  0x00, "5" )
	PORT_DIPNAME(0x40, 0x40, "One Play Minimum" )
	PORT_DIPSETTING (  0x40, DEF_STR( Off ) )
	PORT_DIPSETTING (  0x00, DEF_STR( On ) )
	PORT_DIPNAME(0x80, 0x80, "Self Adjust Diff" )
	PORT_DIPSETTING (  0x80, DEF_STR( Off ) )
	PORT_DIPSETTING (  0x00, DEF_STR( On ) )

	/* IN3 - the real machine reads either the X or Y axis from this port */
	/* Instead, we use the two fake 5 & 6 ports and bank-switch the proper */
	/* value based on the lsb of the byte written to the sound port */
	PORT_START_TAG("IN3")
	PORT_BIT( 0x01, IP_ACTIVE_HIGH, IPT_JOYSTICK_LEFT ) PORT_4WAY
	PORT_BIT( 0x02, IP_ACTIVE_HIGH, IPT_JOYSTICK_RIGHT ) PORT_4WAY
	PORT_BIT( 0x04, IP_ACTIVE_HIGH, IPT_JOYSTICK_UP ) PORT_4WAY
	PORT_BIT( 0x08, IP_ACTIVE_HIGH, IPT_JOYSTICK_DOWN ) PORT_4WAY

	PORT_START_TAG("IN4")	/* Misc controls */
	PORT_BIT( 0x3f, IP_ACTIVE_HIGH, IPT_UNKNOWN )
	PORT_BIT( 0x40, IP_ACTIVE_HIGH, IPT_START1 )
	PORT_BIT( 0x80, IP_ACTIVE_HIGH, IPT_BUTTON1 )

	/* These 2 are fake - they are bank-switched from reads to IN3 */
	/* Red Baron doesn't seem to use the full 0-255 range. */
	PORT_START_TAG("FAKE1")	/* IN5 */
	PORT_BIT( 0xff, 0x80, IPT_AD_STICK_X ) PORT_MINMAX(64,192) PORT_SENSITIVITY(25) PORT_KEYDELTA(10)

	PORT_START_TAG("FAKE2")	/* IN6 */
	PORT_BIT( 0xff, 0x80, IPT_AD_STICK_Y ) PORT_MINMAX(64,192) PORT_SENSITIVITY(25) PORT_KEYDELTA(10)
INPUT_PORTS_END


INPUT_PORTS_START( bradley )
BZONEIN0
BZONEDSW0
BZONEDSW1

	PORT_START_TAG("IN3")
	PORT_BIT( 0x1f, IP_ACTIVE_HIGH, IPT_UNUSED )
	PORT_BIT( 0x20, IP_ACTIVE_HIGH, IPT_START1 )
	PORT_BIT( 0xc0, IP_ACTIVE_HIGH, IPT_UNUSED )

	PORT_START_TAG("1808")
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_BUTTON1 )
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_BUTTON2 ) PORT_NAME("Armor Piercing (Single Shot)") PORT_CODE(KEYCODE_A)
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_BUTTON3 ) PORT_NAME("High Explosive (Single Shot)") PORT_CODE(KEYCODE_Z)
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_BUTTON4 ) PORT_NAME("Armor Piercing (Low Rate)") PORT_CODE(KEYCODE_S)
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_BUTTON5 ) PORT_NAME("High Explosive (Low Rate)") PORT_CODE(KEYCODE_X)
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_BUTTON6 ) PORT_NAME("Armor Piercing (High Rate)") PORT_CODE(KEYCODE_D)
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_BUTTON7 ) PORT_NAME("High Explosive (High Rate)") PORT_CODE(KEYCODE_C)

	PORT_START_TAG("1809")
	PORT_BIT( 0x03, IP_ACTIVE_HIGH, IPT_UNUSED )
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_BUTTON9 ) PORT_NAME("Select TOW Missiles") PORT_CODE(KEYCODE_T)
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_BUTTON8 ) PORT_NAME("7.62 mm Machine Gun") PORT_CODE(KEYCODE_V)
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_BUTTON10 ) PORT_NAME("Magnification Toggle") PORT_CODE(KEYCODE_M) PORT_TOGGLE
	PORT_BIT( 0xe0, IP_ACTIVE_HIGH, IPT_UNUSED )

	PORT_START_TAG("AN0")	/* analog 0 = turret rotation */
	PORT_BIT( 0xff, 0x88, IPT_AD_STICK_X ) PORT_MINMAX(0x48,0xc8) PORT_SENSITIVITY(25) PORT_KEYDELTA(10)

	PORT_START_TAG("AN1")	/* analog 1 = turret elevation */
	PORT_BIT( 0xff, 0x86, IPT_AD_STICK_Y ) PORT_MINMAX(0x46,0xc6) PORT_SENSITIVITY(25) PORT_KEYDELTA(10)

	PORT_START_TAG("AN2")	/* analog 2 = shell firing range hack removed, now uses Z */
	PORT_BIT( 0xff, 0x80, IPT_AD_STICK_Z ) PORT_MINMAX(0x10,0xf0) PORT_SENSITIVITY(25) PORT_KEYDELTA(10) PORT_CENTERDELTA(0) PORT_REVERSE
INPUT_PORTS_END



GAME( 1980, bzone,    0,     bzone,    bzone,    bzone,    ROT0, "Atari", "Battle Zone (set 1)", 0 )
GAME( 1980, bzone2,   bzone, bzone,    bzone,    bzone,    ROT0, "Atari", "Battle Zone (set 2)", 0 )
GAME( 1980, bzonec,   bzone, bzone,    bzone,    bzone,    ROT0, "Atari", "Battle Zone (cocktail)", GAME_NO_COCKTAIL )
GAME( 1980, bradley,  0,     bradley,  bradley,  bradley,  ROT0, "Atari", "Bradley Trainer", 0 )
GAME( 1980, redbaron, 0,     redbaron, redbaron, redbaron, ROT0, "Atari", "Red Baron", 0 )
