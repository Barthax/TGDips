# MAME 0.133 source snippet


#include "driver.h"
#include "cpu/z80/z80.h"
#include "cpu/s2650/s2650.h"
#include "cpu/m6502/m6502.h"
#include "includes/dkong.h"
#include "machine/8257dma.h"
#include "machine/z80dma.h"
#include "machine/latch8.h"

/*************************************
 *
 *  Port definitions
 *
 *************************************/

static INPUT_PORTS_START( radarscp_in0_2 )
    PORT_START("IN0")      /* IN0 */
    PORT_BIT( 0x01, IP_ACTIVE_HIGH, IPT_JOYSTICK_RIGHT ) PORT_2WAY
    PORT_BIT( 0x02, IP_ACTIVE_HIGH, IPT_JOYSTICK_LEFT ) PORT_2WAY
    PORT_BIT( 0x04, IP_ACTIVE_HIGH, IPT_UNUSED ) /* not connected - held to high */
    PORT_BIT( 0x08, IP_ACTIVE_HIGH, IPT_UNUSED ) /* not connected - held to high */
    PORT_BIT( 0x10, IP_ACTIVE_HIGH, IPT_BUTTON1 )
    PORT_BIT( 0x20, IP_ACTIVE_HIGH, IPT_UNUSED ) /* not connected - held to high */
    PORT_BIT( 0x40, IP_ACTIVE_HIGH, IPT_UNUSED ) /* not connected - held to high */
    PORT_BIT( 0x80, IP_ACTIVE_HIGH, IPT_UNUSED ) /* not connected - held to high */
INPUT_PORTS_END

static INPUT_PORTS_START( radarscp_in1_2 )
    PORT_START("IN1")      /* IN1 */
    PORT_BIT( 0x01, IP_ACTIVE_HIGH, IPT_JOYSTICK_RIGHT ) PORT_2WAY PORT_COCKTAIL
    PORT_BIT( 0x02, IP_ACTIVE_HIGH, IPT_JOYSTICK_LEFT ) PORT_2WAY PORT_COCKTAIL
    PORT_BIT( 0x04, IP_ACTIVE_HIGH, IPT_UNUSED ) PORT_COCKTAIL /* not connected - held to high */
    PORT_BIT( 0x08, IP_ACTIVE_HIGH, IPT_UNUSED ) PORT_COCKTAIL /* not connected - held to high */
    PORT_BIT( 0x10, IP_ACTIVE_HIGH, IPT_BUTTON1 ) PORT_COCKTAIL
    PORT_BIT( 0x20, IP_ACTIVE_HIGH, IPT_UNKNOWN ) /* not connected - held to high */
    PORT_BIT( 0x40, IP_ACTIVE_HIGH, IPT_UNKNOWN ) /* not connected - held to high */
    PORT_BIT( 0x80, IP_ACTIVE_HIGH, IPT_UNKNOWN ) /* not connected - held to high */
INPUT_PORTS_END

static INPUT_PORTS_START( dkong_in0_4 )
    PORT_START("IN0")      /* IN0 */
    PORT_BIT( 0x01, IP_ACTIVE_HIGH, IPT_JOYSTICK_RIGHT ) PORT_4WAY
    PORT_BIT( 0x02, IP_ACTIVE_HIGH, IPT_JOYSTICK_LEFT ) PORT_4WAY
    PORT_BIT( 0x04, IP_ACTIVE_HIGH, IPT_JOYSTICK_UP ) PORT_4WAY
    PORT_BIT( 0x08, IP_ACTIVE_HIGH, IPT_JOYSTICK_DOWN ) PORT_4WAY
    PORT_BIT( 0x10, IP_ACTIVE_HIGH, IPT_BUTTON1 )
    PORT_BIT( 0x20, IP_ACTIVE_HIGH, IPT_UNKNOWN ) /* not connected - held to high */
    PORT_BIT( 0x40, IP_ACTIVE_HIGH, IPT_UNKNOWN ) /* not connected - held to high */
    PORT_BIT( 0x80, IP_ACTIVE_HIGH, IPT_UNKNOWN ) /* not connected - held to high */
INPUT_PORTS_END

static INPUT_PORTS_START( dkong_in1_4 )
    PORT_START("IN1")      /* IN1 */
    PORT_BIT( 0x01, IP_ACTIVE_HIGH, IPT_JOYSTICK_RIGHT ) PORT_4WAY PORT_COCKTAIL
    PORT_BIT( 0x02, IP_ACTIVE_HIGH, IPT_JOYSTICK_LEFT ) PORT_4WAY PORT_COCKTAIL
    PORT_BIT( 0x04, IP_ACTIVE_HIGH, IPT_JOYSTICK_UP ) PORT_4WAY PORT_COCKTAIL
    PORT_BIT( 0x08, IP_ACTIVE_HIGH, IPT_JOYSTICK_DOWN ) PORT_4WAY PORT_COCKTAIL
    PORT_BIT( 0x10, IP_ACTIVE_HIGH, IPT_BUTTON1 ) PORT_COCKTAIL
    PORT_BIT( 0x20, IP_ACTIVE_HIGH, IPT_UNKNOWN ) /* not connected - held to high */
    PORT_BIT( 0x40, IP_ACTIVE_HIGH, IPT_UNKNOWN ) /* not connected - held to high */
    PORT_BIT( 0x80, IP_ACTIVE_HIGH, IPT_UNKNOWN ) /* not connected - held to high */
INPUT_PORTS_END

static INPUT_PORTS_START( dkong_in0_8 )
    PORT_START("IN0")      /* IN0 */
    PORT_BIT( 0x01, IP_ACTIVE_HIGH, IPT_JOYSTICK_RIGHT ) PORT_8WAY
    PORT_BIT( 0x02, IP_ACTIVE_HIGH, IPT_JOYSTICK_LEFT ) PORT_8WAY
    PORT_BIT( 0x04, IP_ACTIVE_HIGH, IPT_JOYSTICK_UP ) PORT_8WAY
    PORT_BIT( 0x08, IP_ACTIVE_HIGH, IPT_JOYSTICK_DOWN ) PORT_8WAY
    PORT_BIT( 0x10, IP_ACTIVE_HIGH, IPT_BUTTON1 )
    PORT_BIT( 0x20, IP_ACTIVE_HIGH, IPT_UNKNOWN ) /* not connected - held to high */
    PORT_BIT( 0x40, IP_ACTIVE_HIGH, IPT_UNKNOWN ) /* not connected - held to high */
    PORT_BIT( 0x80, IP_ACTIVE_HIGH, IPT_UNKNOWN ) /* not connected - held to high */
INPUT_PORTS_END

static INPUT_PORTS_START( dkong_in1_8 )
    PORT_START("IN1")      /* IN1 */
    PORT_BIT( 0x01, IP_ACTIVE_HIGH, IPT_JOYSTICK_RIGHT ) PORT_8WAY PORT_COCKTAIL
    PORT_BIT( 0x02, IP_ACTIVE_HIGH, IPT_JOYSTICK_LEFT ) PORT_8WAY PORT_COCKTAIL
    PORT_BIT( 0x04, IP_ACTIVE_HIGH, IPT_JOYSTICK_UP ) PORT_8WAY PORT_COCKTAIL
    PORT_BIT( 0x08, IP_ACTIVE_HIGH, IPT_JOYSTICK_DOWN ) PORT_8WAY PORT_COCKTAIL
    PORT_BIT( 0x10, IP_ACTIVE_HIGH, IPT_BUTTON1 ) PORT_COCKTAIL
    PORT_BIT( 0x20, IP_ACTIVE_HIGH, IPT_UNKNOWN ) /* not connected - held to high */
    PORT_BIT( 0x40, IP_ACTIVE_HIGH, IPT_UNKNOWN ) /* not connected - held to high */
    PORT_BIT( 0x80, IP_ACTIVE_HIGH, IPT_UNKNOWN ) /* not connected - held to high */
INPUT_PORTS_END

static INPUT_PORTS_START( dkong_in2 )
    /* Bit 0x80 is (SERVICE OR COIN) !
     * Bit 0x01 is going to the connector but it is not labeled
     * It should be a IPT_UNKNOWN. In fact, it will reset the game.
     */
    PORT_START("IN2")      /* IN2 */
    PORT_BIT( 0x01, IP_ACTIVE_HIGH, IPT_UNKNOWN  ) /* connection not labeled in schematics - reset */
    PORT_BIT( 0x02, IP_ACTIVE_HIGH, IPT_UNKNOWN ) /* connection not labeled in schematics - freeze or reset */
    PORT_BIT( 0x04, IP_ACTIVE_HIGH, IPT_START1 )
    PORT_BIT( 0x08, IP_ACTIVE_HIGH, IPT_START2 )
    PORT_BIT( 0x10, IP_ACTIVE_HIGH, IPT_SERVICE )   /* not connected - held to high - used as service */
    PORT_BIT( 0x20, IP_ACTIVE_HIGH, IPT_UNKNOWN )   /* not connected - held to high */
    PORT_BIT( 0x40, IP_ACTIVE_HIGH, IPT_SPECIAL )   /* status from sound cpu */
    PORT_BIT( 0x80, IP_ACTIVE_HIGH, IPT_COIN1 )
INPUT_PORTS_END

static INPUT_PORTS_START( dkong_dsw0 )
    PORT_START("DSW0")      /* DSW0 */
    PORT_DIPNAME( 0x03, 0x00, DEF_STR( Lives ) )        PORT_DIPLOCATION( "SW1:!1,!2" )
    PORT_DIPSETTING(    0x00, "3" )
    PORT_DIPSETTING(    0x01, "4" )
    PORT_DIPSETTING(    0x02, "5" )
    PORT_DIPSETTING(    0x03, "6" )
    PORT_DIPNAME( 0x0c, 0x00, DEF_STR( Bonus_Life ) )   PORT_DIPLOCATION( "SW1:!3,!4" )
    PORT_DIPSETTING(    0x00, "7000" )
    PORT_DIPSETTING(    0x04, "10000" )
    PORT_DIPSETTING(    0x08, "15000" )
    PORT_DIPSETTING(    0x0c, "20000" )
    PORT_DIPNAME( 0x70, 0x00, DEF_STR( Coinage ) )      PORT_DIPLOCATION( "SW1:!5,!6,!7" )
    PORT_DIPSETTING(    0x70, DEF_STR( 5C_1C ) )
    PORT_DIPSETTING(    0x50, DEF_STR( 4C_1C ) )
    PORT_DIPSETTING(    0x30, DEF_STR( 3C_1C ) )
    PORT_DIPSETTING(    0x10, DEF_STR( 2C_1C ) )
    PORT_DIPSETTING(    0x00, DEF_STR( 1C_1C ) )
    PORT_DIPSETTING(    0x20, DEF_STR( 1C_2C ) )
    PORT_DIPSETTING(    0x40, DEF_STR( 1C_3C ) )
    PORT_DIPSETTING(    0x60, DEF_STR( 1C_4C ) )
    PORT_DIPNAME( 0x80, 0x80, DEF_STR( Cabinet ) )      PORT_DIPLOCATION( "SW1:!8" )
    PORT_DIPSETTING(    0x80, DEF_STR( Upright ) )
    PORT_DIPSETTING(    0x00, DEF_STR( Cocktail ) )
INPUT_PORTS_END

static INPUT_PORTS_START( dkong_config )
    PORT_START("VR2")
    PORT_ADJUSTER( 90, "VR2 - DAC Volume" )

    PORT_START("VIDHW")
    PORT_CONFNAME( 0x01, 0x01, "Video Hardware" )
    PORT_CONFSETTING(    0x00, "TKG-02 (Radarscope Conversion)" )
    PORT_CONFSETTING(    0x01, "TKG-04 (Two board set)" )
INPUT_PORTS_END

static INPUT_PORTS_START( dkong )
    PORT_INCLUDE( dkong_in0_4 )
    PORT_INCLUDE( dkong_in1_4 )
    PORT_INCLUDE( dkong_in2 )
    PORT_INCLUDE( dkong_dsw0 )

    PORT_INCLUDE( dkong_config )
INPUT_PORTS_END

static INPUT_PORTS_START( dkongf )
    PORT_INCLUDE( dkong )

    PORT_MODIFY("DSW0")
    PORT_DIPNAME( 0x70, 0x00, DEF_STR( Coinage ) )      PORT_DIPLOCATION( "SW1:!5,!6,!7" )
    PORT_DIPSETTING(    0x70, DEF_STR( Free_Play ) )
    PORT_DIPSETTING(    0x50, DEF_STR( 4C_1C ) )
    PORT_DIPSETTING(    0x30, DEF_STR( 3C_1C ) )
    PORT_DIPSETTING(    0x10, DEF_STR( 2C_1C ) )
    PORT_DIPSETTING(    0x00, DEF_STR( 1C_1C ) )
    PORT_DIPSETTING(    0x20, DEF_STR( 1C_2C ) )
    PORT_DIPSETTING(    0x40, DEF_STR( 1C_3C ) )
    PORT_DIPSETTING(    0x60, DEF_STR( 1C_4C ) )
INPUT_PORTS_END

static INPUT_PORTS_START( radarscp )
    PORT_INCLUDE( radarscp_in0_2 )
    PORT_INCLUDE( radarscp_in1_2 )

    PORT_INCLUDE( dkong_in2 )

    PORT_INCLUDE( dkong_dsw0 )

    PORT_START("VR2")
    PORT_ADJUSTER( 35, "VR2 - DAC Volume" )

INPUT_PORTS_END

static INPUT_PORTS_START( dkong3 )
    PORT_START("IN0")      /* IN0 */
    PORT_BIT( 0x01, IP_ACTIVE_HIGH, IPT_JOYSTICK_RIGHT ) PORT_4WAY
    PORT_BIT( 0x02, IP_ACTIVE_HIGH, IPT_JOYSTICK_LEFT ) PORT_4WAY
    PORT_BIT( 0x04, IP_ACTIVE_HIGH, IPT_JOYSTICK_UP ) PORT_4WAY
    PORT_BIT( 0x08, IP_ACTIVE_HIGH, IPT_JOYSTICK_DOWN ) PORT_4WAY
    PORT_BIT( 0x10, IP_ACTIVE_HIGH, IPT_BUTTON1 )
    PORT_BIT( 0x20, IP_ACTIVE_HIGH, IPT_START1 )
    PORT_BIT( 0x40, IP_ACTIVE_HIGH, IPT_START2 )
    PORT_BIT( 0x80, IP_ACTIVE_HIGH, IPT_COIN3 )

    PORT_START("IN1")      /* IN1 */
    PORT_BIT( 0x01, IP_ACTIVE_HIGH, IPT_JOYSTICK_RIGHT ) PORT_4WAY PORT_COCKTAIL
    PORT_BIT( 0x02, IP_ACTIVE_HIGH, IPT_JOYSTICK_LEFT ) PORT_4WAY PORT_COCKTAIL
    PORT_BIT( 0x04, IP_ACTIVE_HIGH, IPT_JOYSTICK_UP ) PORT_4WAY PORT_COCKTAIL
    PORT_BIT( 0x08, IP_ACTIVE_HIGH, IPT_JOYSTICK_DOWN ) PORT_4WAY PORT_COCKTAIL
    PORT_BIT( 0x10, IP_ACTIVE_HIGH, IPT_BUTTON1 ) PORT_COCKTAIL
    PORT_BIT( 0x20, IP_ACTIVE_HIGH, IPT_COIN1 ) PORT_IMPULSE(1)
    PORT_BIT( 0x40, IP_ACTIVE_HIGH, IPT_COIN2 ) PORT_IMPULSE(1)
    PORT_BIT( 0x80, IP_ACTIVE_HIGH, IPT_UNKNOWN )

    PORT_START("DSW0")      /* DSW0 */
    PORT_DIPNAME( 0x07, 0x00, DEF_STR( Coinage ) )          PORT_DIPLOCATION("SW2:!1,!2,!3")
    PORT_DIPSETTING(    0x02, DEF_STR( 3C_1C ) )
    PORT_DIPSETTING(    0x04, DEF_STR( 2C_1C ) )
    PORT_DIPSETTING(    0x00, DEF_STR( 1C_1C ) )
    PORT_DIPSETTING(    0x06, DEF_STR( 1C_2C ) )
    PORT_DIPSETTING(    0x01, DEF_STR( 1C_3C ) )
    PORT_DIPSETTING(    0x03, DEF_STR( 1C_4C ) )
    PORT_DIPSETTING(    0x05, DEF_STR( 1C_5C ) )
    PORT_DIPSETTING(    0x07, DEF_STR( 1C_6C ) )
    PORT_DIPUNKNOWN_DIPLOC( 0x08, 0x00, "SW2:!4" )
    PORT_DIPUNKNOWN_DIPLOC( 0x10, 0x00, "SW2:!5" )
    PORT_DIPUNKNOWN_DIPLOC( 0x20, 0x00, "SW2:!6" )
    PORT_SERVICE_DIPLOC( 0x40, IP_ACTIVE_HIGH, "SW2:!7" )
    PORT_DIPNAME( 0x80, 0x00, DEF_STR( Cabinet ) )          PORT_DIPLOCATION("SW2:!8")
    PORT_DIPSETTING(    0x00, DEF_STR( Upright ) )
    PORT_DIPSETTING(    0x80, DEF_STR( Cocktail ) )

    PORT_START("DSW1")      /* DSW1 */
    PORT_DIPNAME( 0x03, 0x00, DEF_STR( Lives ) )            PORT_DIPLOCATION("SW1:!1,!2")
    PORT_DIPSETTING(    0x00, "3" )
    PORT_DIPSETTING(    0x01, "4" )
    PORT_DIPSETTING(    0x02, "5" )
    PORT_DIPSETTING(    0x03, "6" )
    PORT_DIPNAME( 0x0c, 0x00, DEF_STR( Bonus_Life ) )       PORT_DIPLOCATION("SW1:!3,!4")
    PORT_DIPSETTING(    0x00, "30000" )
    PORT_DIPSETTING(    0x04, "40000" )
    PORT_DIPSETTING(    0x08, "50000" )
    PORT_DIPSETTING(    0x0c, DEF_STR( None ) )
    PORT_DIPNAME( 0x30, 0x00, "Additional Bonus" )          PORT_DIPLOCATION("SW1:!5,!6")
    PORT_DIPSETTING(    0x00, "30000" )
    PORT_DIPSETTING(    0x10, "40000" )
    PORT_DIPSETTING(    0x20, "50000" )
    PORT_DIPSETTING(    0x30, DEF_STR( None ) )
    PORT_DIPNAME( 0xc0, 0x00, DEF_STR( Difficulty ) )       PORT_DIPLOCATION("SW1:!7,!8")
    PORT_DIPSETTING(    0x00, DEF_STR( Easy ) )
    PORT_DIPSETTING(    0x40, DEF_STR( Medium ) )
    PORT_DIPSETTING(    0x80, DEF_STR( Hard ) )
    PORT_DIPSETTING(    0xc0, DEF_STR( Hardest ) )
INPUT_PORTS_END

static INPUT_PORTS_START( dkong3b )
    PORT_INCLUDE( dkong_in0_4 )
    PORT_INCLUDE( dkong_in1_4 )

    PORT_INCLUDE( dkong_in2 )

    PORT_START("DSW0")      /* DSW0 */
    PORT_DIPNAME( 0x07, 0x00, DEF_STR( Coinage ) )          PORT_DIPLOCATION("SW1:!1,!2,!3")
    PORT_DIPSETTING(    0x02, DEF_STR( 3C_1C ) )
    PORT_DIPSETTING(    0x04, DEF_STR( 2C_1C ) )
    PORT_DIPSETTING(    0x00, DEF_STR( 1C_1C ) )
    PORT_DIPSETTING(    0x06, DEF_STR( 1C_2C ) )
    PORT_DIPSETTING(    0x01, DEF_STR( 1C_3C ) )
    PORT_DIPSETTING(    0x03, DEF_STR( 1C_4C ) )
    PORT_DIPSETTING(    0x05, DEF_STR( 1C_5C ) )
    PORT_DIPSETTING(    0x07, DEF_STR( 1C_6C ) )
    PORT_DIPNAME( 0x08, 0x00, DEF_STR( Cabinet ) )          PORT_DIPLOCATION("SW1:!4")
    PORT_DIPSETTING(    0x00, DEF_STR( Upright ) )
    PORT_DIPSETTING(    0x08, DEF_STR( Cocktail ) )
    PORT_DIPUNKNOWN_DIPLOC( 0x10, 0x00, "SW1:!5" )
    PORT_DIPUNKNOWN_DIPLOC( 0x20, 0x00, "SW1:!6" )
    PORT_DIPUNKNOWN_DIPLOC( 0x40, 0x00, "SW1:!7" )
    PORT_DIPUNKNOWN_DIPLOC( 0x80, 0x00, "SW1:!8" )
INPUT_PORTS_END

static INPUT_PORTS_START( dkongjr )
    PORT_INCLUDE( dkong_in0_4 )
    PORT_INCLUDE( dkong_in1_4 )
    PORT_INCLUDE( dkong_in2 )
    PORT_INCLUDE( dkong_dsw0 )

#if DEBUG_DISC_SOUND
    PORT_START("TST")      /* TST */
    PORT_BIT( 0x01, IP_ACTIVE_HIGH, IPT_SPECIAL ) PORT_CODE(KEYCODE_A)
    PORT_BIT( 0x02, IP_ACTIVE_HIGH, IPT_SPECIAL ) PORT_CODE(KEYCODE_B)
#endif
INPUT_PORTS_END

static INPUT_PORTS_START( hunchbkd )

    PORT_INCLUDE( dkong_in0_8 )
    PORT_INCLUDE( dkong_in1_8 )

    PORT_INCLUDE( dkong_in2 )
    PORT_MODIFY("IN2")
    PORT_DIPNAME( 0x01, 0x00, DEF_STR( Unknown ) )
    PORT_DIPSETTING(    0x00, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x01, DEF_STR( On ) )

    PORT_INCLUDE( dkong_dsw0 )
    PORT_MODIFY("DSW0")
    PORT_DIPNAME( 0x01, 0x00, DEF_STR( Unknown ) )      PORT_DIPLOCATION( "SW1:!1" )
    PORT_DIPSETTING(    0x00, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x01, DEF_STR( On ) )
    PORT_DIPNAME( 0x02, 0x00, DEF_STR( Lives ) )        PORT_DIPLOCATION( "SW1:!2" )
    PORT_DIPSETTING(    0x00, "3" )
    PORT_DIPSETTING(    0x02, "5" )
    PORT_DIPNAME( 0x0c, 0x00, DEF_STR( Bonus_Life ) )   PORT_DIPLOCATION( "SW1:!3,!4" )
    PORT_DIPSETTING(    0x00, "10000" )
    PORT_DIPSETTING(    0x04, "20000" )
    PORT_DIPSETTING(    0x08, "40000" )
    PORT_DIPSETTING(    0x0c, "80000" )

    PORT_START("SENSE") /* Sense */
    PORT_BIT( 0x80, IP_ACTIVE_HIGH, IPT_VBLANK )

    PORT_INCLUDE( dkong_config )
INPUT_PORTS_END

static INPUT_PORTS_START( shootgal )
    PORT_START("IN0")      /* IN0 */
    PORT_BIT( 0xff, 0x80, IPT_LIGHTGUN_X ) PORT_CROSSHAIR(X, 1.0, 0.0, 0) PORT_SENSITIVITY(50) PORT_KEYDELTA(4) PORT_REVERSE

    PORT_START("IN1")      /* IN1 */
    PORT_BIT( 0xff, 0x80, IPT_LIGHTGUN_Y ) PORT_CROSSHAIR(Y, 1.0, 0.0, 0) PORT_SENSITIVITY(50) PORT_KEYDELTA(4) PORT_REVERSE

    PORT_INCLUDE( dkong_in2 )
    PORT_MODIFY("IN2")
    PORT_BIT( 0x04, IP_ACTIVE_HIGH, IPT_BUTTON1 ) PORT_NAME("Start 1 / P1 Button 1") PORT_PLAYER(1)
    PORT_BIT( 0x08, IP_ACTIVE_HIGH, IPT_BUTTON2 ) PORT_NAME("Start 2 / P1 Button 2") PORT_PLAYER(1)
    /* PORT_BIT( 0x01, IP_ACTIVE_HIGH, IPT_UNKNOWN ) */
    /* PORT_BIT( 0x40, IP_ACTIVE_HIGH, IPT_UNKNOWN ) */

    PORT_START("DSW0")      /* DSW0 */
    PORT_DIPNAME( 0x01, 0x00, "1" )
    PORT_DIPSETTING(    0x00, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x01, DEF_STR( On ) )
    PORT_DIPNAME( 0x02, 0x00, DEF_STR( Unknown ) )
    PORT_DIPSETTING(    0x00, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x02, DEF_STR( On ) )
    PORT_DIPNAME( 0x04, 0x00, "Time" )
    PORT_DIPSETTING(    0x00, "60" )
    PORT_DIPSETTING(    0x04, "100" )
    PORT_DIPNAME( 0x08, 0x00, DEF_STR( Unknown ) )
    PORT_DIPSETTING(    0x00, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x08, DEF_STR( On ) )
    PORT_DIPNAME( 0x10, 0x00, DEF_STR( Unknown ) )
    PORT_DIPSETTING(    0x00, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x10, DEF_STR( On ) )
    PORT_DIPNAME( 0x20, 0x00, DEF_STR( Unknown ) )
    PORT_DIPSETTING(    0x00, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x20, DEF_STR( On ) )
    PORT_DIPNAME( 0x40, 0x00, DEF_STR( Unknown ) )
    PORT_DIPSETTING(    0x00, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x40, DEF_STR( On ) )
    PORT_SERVICE( 0x80, IP_ACTIVE_HIGH )

    PORT_START("SENSE") /* Sense */
    PORT_BIT( 0x80, IP_ACTIVE_HIGH, IPT_VBLANK )

    PORT_INCLUDE( dkong_config )
INPUT_PORTS_END

static INPUT_PORTS_START( sbdk )
    PORT_INCLUDE( dkong_in0_8 )
    PORT_MODIFY("IN0")
    PORT_BIT( 0x10, IP_ACTIVE_HIGH, IPT_UNUSED ) /* not used by clone */

    PORT_INCLUDE( dkong_in1_8 )
    PORT_MODIFY("IN1")
    PORT_BIT( 0x01, IP_ACTIVE_HIGH, IPT_UNUSED ) /* not used by clone */
    PORT_BIT( 0x02, IP_ACTIVE_HIGH, IPT_UNUSED ) /* not used by clone */
    PORT_BIT( 0x04, IP_ACTIVE_HIGH, IPT_UNUSED ) /* not used by clone */
    PORT_BIT( 0x08, IP_ACTIVE_HIGH, IPT_UNUSED ) /* not used by clone */
    PORT_BIT( 0x10, IP_ACTIVE_HIGH, IPT_UNUSED ) /* not used by clone */

    PORT_INCLUDE( dkong_in2 )
    PORT_MODIFY("IN2")
    PORT_BIT( 0x04, IP_ACTIVE_HIGH, IPT_BUTTON1 ) PORT_NAME("Start 1 / P1 Button 1") PORT_PLAYER(1)
    PORT_BIT( 0x08, IP_ACTIVE_HIGH, IPT_BUTTON2 ) PORT_NAME("Start 2 / P1 Button 2") PORT_PLAYER(1)

    PORT_INCLUDE( dkong_dsw0 )
    PORT_MODIFY("DSW0")
    PORT_DIPUNKNOWN_DIPLOC( 0x01, 0x00, "SW1:!1" )
    PORT_DIPNAME( 0x02, 0x00, DEF_STR( Lives ) )        PORT_DIPLOCATION( "SW1:!2" )
    PORT_DIPSETTING(    0x00, "3" )
    PORT_DIPSETTING(    0x02, "5" )
    PORT_DIPUNKNOWN_DIPLOC( 0x04, 0x00, "SW1:!3" )
    PORT_DIPUNKNOWN_DIPLOC( 0x08, 0x00, "SW1:!4" )

    PORT_START("SENSE") /* Sense */
    PORT_BIT( 0x80, IP_ACTIVE_HIGH, IPT_VBLANK )

    PORT_INCLUDE( dkong_config )
INPUT_PORTS_END

static INPUT_PORTS_START( herbiedk )
    PORT_INCLUDE( dkong_in0_8 )
    PORT_INCLUDE( dkong_in1_8 )

    PORT_INCLUDE( dkong_in2 )

    PORT_INCLUDE( dkong_dsw0 )
    PORT_MODIFY("DSW0")
    PORT_DIPUNKNOWN_DIPLOC( 0x01, 0x00, "SW1:!1" )
    PORT_DIPUNKNOWN_DIPLOC( 0x02, 0x00, "SW1:!2" )
    PORT_DIPUNKNOWN_DIPLOC( 0x04, 0x00, "SW1:!3" )
    PORT_DIPUNKNOWN_DIPLOC( 0x08, 0x00, "SW1:!4" )

    PORT_START("SENSE") /* Sense */
    PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_VBLANK )

    PORT_INCLUDE( dkong_config )
INPUT_PORTS_END

/* Notes :
     - you ALWAYS get an extra life at 150000 points.
     - having more than 6 lives will reset the game.
*/

static INPUT_PORTS_START( herodk )
    PORT_INCLUDE( dkong_in0_8 )
    PORT_MODIFY("IN0")
    PORT_BIT( 0x20, IP_ACTIVE_HIGH, IPT_BUTTON2 )

    PORT_INCLUDE( dkong_in1_8 )
    PORT_MODIFY("IN1")
    PORT_BIT( 0x20, IP_ACTIVE_HIGH, IPT_BUTTON2 ) PORT_COCKTAIL

    PORT_INCLUDE( dkong_in2 )

    PORT_INCLUDE( dkong_dsw0 )
    PORT_MODIFY("DSW0")
    PORT_DIPUNUSED_DIPLOC( 0x01, 0x01, "SW1:!1" )
    PORT_DIPNAME( 0x02, 0x00, DEF_STR( Lives ) )        PORT_DIPLOCATION( "SW1:!2" )
    PORT_DIPSETTING(    0x00, "3" )
    PORT_DIPSETTING(    0x02, "5" )
    PORT_DIPNAME( 0x0c, 0x00, "Difficulty?" )           PORT_DIPLOCATION( "SW1:!3,!4" ) /* Stored at 0x1c99 */
    PORT_DIPSETTING(    0x00, "0" )
    PORT_DIPSETTING(    0x04, "1" )
    PORT_DIPSETTING(    0x08, "2" )
    PORT_DIPSETTING(    0x0c, "3" )

    PORT_START("SENSE") /* Sense */
    PORT_BIT( 0x80, IP_ACTIVE_HIGH, IPT_VBLANK )

    PORT_INCLUDE( dkong_config )
INPUT_PORTS_END


static INPUT_PORTS_START( pestplce )
    PORT_START("IN0")      /* IN0 */
    PORT_BIT( 0x01, IP_ACTIVE_HIGH, IPT_JOYSTICK_RIGHT ) PORT_4WAY PORT_PLAYER(1)
    PORT_BIT( 0x02, IP_ACTIVE_HIGH, IPT_JOYSTICK_LEFT ) PORT_4WAY PORT_PLAYER(1)
    PORT_BIT( 0x04, IP_ACTIVE_HIGH, IPT_JOYSTICK_UP ) PORT_4WAY PORT_PLAYER(1)
    PORT_BIT( 0x08, IP_ACTIVE_HIGH, IPT_JOYSTICK_DOWN ) PORT_4WAY PORT_PLAYER(1)
    PORT_BIT( 0x10, IP_ACTIVE_HIGH, IPT_BUTTON1 )
    PORT_BIT( 0x20, IP_ACTIVE_HIGH, IPT_UNKNOWN )
    PORT_BIT( 0x40, IP_ACTIVE_HIGH, IPT_UNKNOWN )
    PORT_BIT( 0x80, IP_ACTIVE_HIGH, IPT_UNKNOWN )

    PORT_START("IN1")      /* IN1 */
    PORT_BIT( 0x01, IP_ACTIVE_HIGH, IPT_JOYSTICK_RIGHT ) PORT_4WAY PORT_PLAYER(2)
    PORT_BIT( 0x02, IP_ACTIVE_HIGH, IPT_JOYSTICK_LEFT ) PORT_4WAY PORT_PLAYER(2)
    PORT_BIT( 0x04, IP_ACTIVE_HIGH, IPT_JOYSTICK_UP ) PORT_4WAY PORT_PLAYER(2)
    PORT_BIT( 0x08, IP_ACTIVE_HIGH, IPT_JOYSTICK_DOWN ) PORT_4WAY PORT_PLAYER(2)
    PORT_BIT( 0x10, IP_ACTIVE_HIGH, IPT_BUTTON1 ) PORT_COCKTAIL
    PORT_BIT( 0x20, IP_ACTIVE_HIGH, IPT_UNKNOWN )
    PORT_BIT( 0x40, IP_ACTIVE_HIGH, IPT_UNKNOWN )
    PORT_BIT( 0x80, IP_ACTIVE_HIGH, IPT_UNKNOWN )

    PORT_INCLUDE( dkong_in2 )

    PORT_START("DSW0")      /* DSW0 */
    PORT_DIPNAME( 0x03, 0x00, DEF_STR( Lives ) )
    PORT_DIPSETTING(    0x00, "3" )
    PORT_DIPSETTING(    0x01, "4" )
    PORT_DIPSETTING(    0x02, "5" )
    PORT_DIPSETTING(    0x03, "6" )
    PORT_DIPNAME( 0x1c, 0x00, DEF_STR( Coinage ) )
    PORT_DIPSETTING(    0x08, DEF_STR( 3C_1C ) )
    PORT_DIPSETTING(    0x10, DEF_STR( 2C_1C ) )
    PORT_DIPSETTING(    0x00, DEF_STR( 1C_1C ) )
    PORT_DIPSETTING(    0x18, DEF_STR( 1C_2C ) )
    PORT_DIPSETTING(    0x04, DEF_STR( 1C_3C ) )
    PORT_DIPSETTING(    0x0c, DEF_STR( 1C_4C ) )
    PORT_DIPSETTING(    0x14, DEF_STR( 1C_5C ) )
    PORT_DIPSETTING(    0x1c, DEF_STR( 1C_6C ) )
    PORT_DIPNAME( 0x20, 0x20, "2 Players Game" )
    PORT_DIPSETTING(    0x00, "1 Credit" )
    PORT_DIPSETTING(    0x20, "2 Credits" )
    PORT_DIPNAME( 0xc0, 0x00, DEF_STR( Bonus_Life ) )
    PORT_DIPSETTING(    0x00, "20000" )
    PORT_DIPSETTING(    0x40, "30000" )
    PORT_DIPSETTING(    0x80, "40000" )
    PORT_DIPSETTING(    0xc0, DEF_STR ( None ) )

    PORT_INCLUDE( dkong_config )
INPUT_PORTS_END


static INPUT_PORTS_START( spclforc )
    PORT_INCLUDE( dkong_in0_8 )
    PORT_MODIFY("IN0")
    PORT_BIT( 0x10, IP_ACTIVE_HIGH, IPT_UNKNOWN )

    PORT_INCLUDE( dkong_in1_8 )
    PORT_MODIFY("IN1")
    PORT_BIT( 0x10, IP_ACTIVE_HIGH, IPT_BUTTON2 ) PORT_COCKTAIL
    PORT_BIT( 0x20, IP_ACTIVE_HIGH, IPT_BUTTON1 ) PORT_COCKTAIL

    PORT_INCLUDE( dkong_in2 )
    PORT_MODIFY("IN2")
    PORT_BIT( 0x04, IP_ACTIVE_HIGH, IPT_BUTTON1 ) PORT_NAME("Start 1 / P1 Button 1") PORT_PLAYER(1)
    PORT_BIT( 0x08, IP_ACTIVE_HIGH, IPT_BUTTON2 ) PORT_NAME("Start 2 / P1 Button 2") PORT_PLAYER(1)

    PORT_START("DSW0")      /* DSW0 */
    PORT_DIPNAME( 0x01, 0x00, DEF_STR( Unknown ) )
    PORT_DIPSETTING(    0x00, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x01, DEF_STR( On ) )
    PORT_DIPNAME( 0x02, 0x00, DEF_STR( Unknown ) )
    PORT_DIPSETTING(    0x00, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x02, DEF_STR( On ) )
    PORT_DIPNAME( 0x04, 0x00, DEF_STR( Cabinet ) )
    PORT_DIPSETTING(    0x00, DEF_STR( Upright ) )
    PORT_DIPSETTING(    0x04, DEF_STR( Cocktail ) )
    PORT_DIPNAME( 0x18, 0x00, DEF_STR( Bonus_Life ) )
    PORT_DIPSETTING(    0x00, "40000" )
    PORT_DIPSETTING(    0x08, "50000" )
    PORT_DIPSETTING(    0x10, "60000" )
    PORT_DIPSETTING(    0x18, "70000" )
    PORT_DIPNAME( 0xe0, 0x00, DEF_STR( Coinage ) )
    PORT_DIPSETTING(    0xe0, DEF_STR( 5C_1C ) )
    PORT_DIPSETTING(    0xa0, DEF_STR( 4C_1C ) )
    PORT_DIPSETTING(    0x60, DEF_STR( 3C_1C ) )
    PORT_DIPSETTING(    0x20, DEF_STR( 2C_1C ) )
    PORT_DIPSETTING(    0x00, DEF_STR( 1C_1C ) )
    PORT_DIPSETTING(    0x40, DEF_STR( 1C_2C ) )
    PORT_DIPSETTING(    0x80, DEF_STR( 1C_3C ) )
    PORT_DIPSETTING(    0xc0, DEF_STR( 1C_4C ) )

    PORT_START("SENSE") /* Sense */
    PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_VBLANK )

    PORT_INCLUDE( dkong_config )
INPUT_PORTS_END


static INPUT_PORTS_START( 8ballact )
    PORT_INCLUDE( dkong_in0_8 )
    PORT_INCLUDE( dkong_in1_8 )

    PORT_INCLUDE( dkong_in2 )

    PORT_START("DSW0")      /* DSW0 */
    PORT_DIPUNUSED_DIPLOC( 0x01, 0x01, "SW1:!1" )
    PORT_DIPUNUSED_DIPLOC( 0x02, 0x02, "SW1:!2" )
    PORT_DIPNAME( 0x04, 0x00, DEF_STR( Cabinet ) ) PORT_DIPLOCATION( "SW1:!3" )
    PORT_DIPSETTING(    0x00, DEF_STR( Upright ) )
    PORT_DIPSETTING(    0x04, DEF_STR( Cocktail ) )
    PORT_DIPNAME( 0x08, 0x00, DEF_STR( Unknown ) ) PORT_DIPLOCATION( "SW1:!4" )
    PORT_DIPSETTING(    0x00, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x08, DEF_STR( On ) )
    PORT_DIPNAME( 0x70, 0x00, DEF_STR( Coinage ) ) PORT_DIPLOCATION( "SW1:!5,!6,!7" )
    PORT_DIPSETTING(    0x70, DEF_STR( 5C_1C ) )
    PORT_DIPSETTING(    0x50, DEF_STR( 4C_1C ) )
    PORT_DIPSETTING(    0x30, DEF_STR( 3C_1C ) )
    PORT_DIPSETTING(    0x10, DEF_STR( 2C_1C ) )
    PORT_DIPSETTING(    0x00, DEF_STR( 1C_1C ) )
    PORT_DIPSETTING(    0x20, DEF_STR( 1C_2C ) )
    PORT_DIPSETTING(    0x40, DEF_STR( 1C_3C ) )
    PORT_DIPSETTING(    0x60, DEF_STR( 1C_4C ) )
    PORT_DIPUNUSED_DIPLOC( 0x80, 0x80, "SW1:!8" )

    PORT_START("SENSE") /* Sense */
    PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_VBLANK )

    PORT_INCLUDE( dkong_config )
INPUT_PORTS_END

static INPUT_PORTS_START( drakton )
    PORT_INCLUDE( dkong_in0_4 )
    PORT_INCLUDE( dkong_in1_4 )

    PORT_INCLUDE( dkong_in2 )

    PORT_START("DSW0")      /* DSW0 */
    PORT_DIPNAME( 0x01, 0x01, DEF_STR( Demo_Sounds ) )
    PORT_DIPSETTING(    0x00, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x01, DEF_STR( On ) )
    PORT_DIPNAME( 0x06, 0x04, DEF_STR( Lives ) )
    PORT_DIPSETTING(    0x00, "3" )
    PORT_DIPSETTING(    0x02, "4" )
    PORT_DIPSETTING(    0x04, "5" )
    PORT_DIPSETTING(    0x06, "6" )
    PORT_DIPNAME( 0x08, 0x08, DEF_STR( Difficulty ) )
    PORT_DIPSETTING(    0x00, DEF_STR( Easy ) )
    PORT_DIPSETTING(    0x08, DEF_STR( Normal ) )
    PORT_DIPNAME( 0x70, 0x10, DEF_STR( Bonus_Life ) )
    PORT_DIPSETTING(    0x00, "10000" )
    PORT_DIPSETTING(    0x10, "20000" )
    PORT_DIPSETTING(    0x20, "30000" )
    PORT_DIPSETTING(    0x30, "40000" )
    PORT_DIPSETTING(    0x40, "50000" )
    PORT_DIPSETTING(    0x50, "60000" )
    PORT_DIPSETTING(    0x60, "70000" )
    PORT_DIPSETTING(    0x70, "80000" )
    PORT_DIPNAME( 0x80, 0x00, DEF_STR( Cabinet ) )
    PORT_DIPSETTING(    0x00, DEF_STR( Upright ) )
    PORT_DIPSETTING(    0x80, DEF_STR( Cocktail ) )

    PORT_INCLUDE( dkong_config )
INPUT_PORTS_END


static INPUT_PORTS_START( strtheat )
    PORT_START("IN0")      /* IN0 */
    PORT_BIT( 0x01, IP_ACTIVE_HIGH, IPT_JOYSTICK_RIGHT ) PORT_2WAY
    PORT_BIT( 0x02, IP_ACTIVE_HIGH, IPT_JOYSTICK_LEFT ) PORT_2WAY
    PORT_BIT( 0x04, IP_ACTIVE_HIGH, IPT_BUTTON1 )
    PORT_BIT( 0x08, IP_ACTIVE_HIGH, IPT_BUTTON2 )
    PORT_BIT( 0x10, IP_ACTIVE_HIGH, IPT_BUTTON3 )
    PORT_BIT( 0x20, IP_ACTIVE_HIGH, IPT_UNKNOWN )
    PORT_BIT( 0x40, IP_ACTIVE_HIGH, IPT_UNKNOWN )
    PORT_BIT( 0x80, IP_ACTIVE_HIGH, IPT_UNKNOWN )

    PORT_START("IN1")      /* IN1 */
    PORT_BIT( 0x01, IP_ACTIVE_HIGH, IPT_JOYSTICK_RIGHT ) PORT_2WAY PORT_COCKTAIL
    PORT_BIT( 0x02, IP_ACTIVE_HIGH, IPT_JOYSTICK_LEFT ) PORT_2WAY PORT_COCKTAIL
    PORT_BIT( 0x04, IP_ACTIVE_HIGH, IPT_BUTTON1 ) PORT_COCKTAIL
    PORT_BIT( 0x08, IP_ACTIVE_HIGH, IPT_BUTTON2 ) PORT_COCKTAIL
    PORT_BIT( 0x10, IP_ACTIVE_HIGH, IPT_BUTTON3 ) PORT_COCKTAIL
    PORT_BIT( 0x20, IP_ACTIVE_HIGH, IPT_UNKNOWN )
    PORT_BIT( 0x40, IP_ACTIVE_HIGH, IPT_UNKNOWN )
    PORT_BIT( 0x80, IP_ACTIVE_HIGH, IPT_UNKNOWN )

    PORT_INCLUDE( dkong_in2 )

    PORT_START("DSW0")      /* DSW0 */
    PORT_DIPNAME( 0x01, 0x01, DEF_STR( Demo_Sounds ) )
    PORT_DIPSETTING(    0x00, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x01, DEF_STR( On ) )
    PORT_DIPNAME( 0x06, 0x00, DEF_STR( Lives ) )
    PORT_DIPSETTING(    0x00, "3" )
    PORT_DIPSETTING(    0x02, "4" )
    PORT_DIPSETTING(    0x04, "5" )
    PORT_DIPSETTING(    0x06, "6" )
    PORT_DIPNAME( 0x38, 0x00, DEF_STR( Bonus_Life ) )
    PORT_DIPSETTING(    0x00, "10000" )
    PORT_DIPSETTING(    0x08, "20000" )
    PORT_DIPSETTING(    0x10, "30000" )
    PORT_DIPSETTING(    0x18, "40000" )
    PORT_DIPSETTING(    0x20, "50000" )
    PORT_DIPSETTING(    0x28, "60000" )
    PORT_DIPSETTING(    0x30, "70000" )
    PORT_DIPSETTING(    0x38, "80000" )
    PORT_DIPNAME( 0x40, 0x00,"Control type" )
    PORT_DIPSETTING(    0x00, "Steering Wheel" )
    PORT_DIPSETTING(    0x40, DEF_STR ( Joystick ) )
    PORT_DIPNAME( 0x80, 0x00, DEF_STR( Cabinet ) )
    PORT_DIPSETTING(    0x00, DEF_STR( Upright ) )
    PORT_DIPSETTING(    0x80, DEF_STR( Cocktail ) )

    PORT_START("IN4")      /* IN4 */
    PORT_BIT( 0x03, 0x00, IPT_DIAL ) PORT_SENSITIVITY(40) PORT_KEYDELTA(10) PORT_REVERSE

    PORT_START("IN5")      /* IN5 */
    PORT_BIT( 0x03, 0x00, IPT_DIAL ) PORT_SENSITIVITY(40) PORT_KEYDELTA(10) PORT_REVERSE PORT_COCKTAIL

    PORT_INCLUDE( dkong_config )
INPUT_PORTS_END

/*************************************
 *
 *  Game drivers
 *
 *************************************/

GAME( 1980, radarscp, 0,        radarscp, radarscp,       0, ROT90, "Nintendo", "Radar Scope", GAME_SUPPORTS_SAVE )
GAME( 1980, radarsc1, radarscp, radarsc1, radarscp,       0, ROT90, "Nintendo", "Radar Scope (TRS01)", GAME_SUPPORTS_SAVE )

GAME( 1981, dkong,    0,        dkong2b,  dkong,          0,  ROT90, "Nintendo of America", "Donkey Kong (US set 1)", GAME_SUPPORTS_SAVE )
GAME( 1981, dkongo,   dkong,    dkong2b,  dkong,          0,  ROT90, "Nintendo", "Donkey Kong (US set 2)", GAME_SUPPORTS_SAVE )
GAME( 1981, dkongjp,  dkong,    dkong2b,  dkong,          0,  ROT90, "Nintendo", "Donkey Kong (Japan set 1)", GAME_SUPPORTS_SAVE )
GAME( 1981, dkongjo,  dkong,    dkong2b,  dkong,          0,  ROT90, "Nintendo", "Donkey Kong (Japan set 2)", GAME_SUPPORTS_SAVE )
GAME( 1981, dkongjo1, dkong,    dkong2b,  dkong,          0,  ROT90, "Nintendo", "Donkey Kong (Japan set 3) (bad dump?)", GAME_SUPPORTS_SAVE )
GAME( 2004, dkongf,   dkong,    dkong2b,  dkongf,         0,  ROT90, "hack", "Donkey Kong Foundry (hack)", GAME_SUPPORTS_SAVE ) /* from Jeff's Romhack */

GAME( 1982, dkongjr,  0,        dkongjr,  dkongjr,        0,  ROT90, "Nintendo of America", "Donkey Kong Junior (US)", GAME_SUPPORTS_SAVE )
GAME( 1982, dkongjrj, dkongjr,  dkongjr,  dkongjr,        0,  ROT90, "Nintendo", "Donkey Kong Jr. (Japan)", GAME_SUPPORTS_SAVE )
GAME( 1982, dkngjnrj, dkongjr,  dkongjr,  dkongjr,        0,  ROT90, "Nintendo", "Donkey Kong Junior (Japan?)", GAME_SUPPORTS_SAVE )
GAME( 1982, dkongjrb, dkongjr,  dkongjr,  dkongjr,        0,  ROT90, "bootleg", "Donkey Kong Jr. (bootleg)", GAME_SUPPORTS_SAVE )
GAME( 1982, dkongjre, dkongjr,  dkongjr,  dkongjr,        0,  ROT90, "Nintendo of America", "Donkey Kong Junior (Easy)", GAME_SUPPORTS_SAVE )
GAME( 1982, jrking,   dkongjr,  dkongjr,  dkongjr,        0,  ROT90, "bootleg", "Junior King (bootleg of Donkey Kong Jr.)", GAME_SUPPORTS_SAVE )

GAME( 1983, dkong3,   0,        dkong3,   dkong3,         0,  ROT90, "Nintendo of America", "Donkey Kong 3 (US)", GAME_SUPPORTS_SAVE )
GAME( 1983, dkong3j,  dkong3,   dkong3,   dkong3,         0,  ROT90, "Nintendo", "Donkey Kong 3 (Japan)", GAME_SUPPORTS_SAVE )
GAME( 1984, dkong3b,  dkong3,   dkong3b,  dkong3b,        0,  ROT90, "bootleg", "Donkey Kong 3 (bootleg on Donkey Kong Jr. hardware)", GAME_SUPPORTS_SAVE )

GAME( 1983, pestplce, mario,    pestplce, pestplce,       0,  ROT180, "bootleg", "Pest Place", GAME_WRONG_COLORS | GAME_IMPERFECT_SOUND | GAME_SUPPORTS_SAVE )

/* 2650 based */
GAME( 1984, herbiedk, huncholy, s2650,    herbiedk,       0,  ROT90, "CVS", "Herbie at the Olympics (DK conversion)", GAME_SUPPORTS_SAVE )
GAME( 1983, hunchbkd, hunchbak, s2650,    hunchbkd,       0,  ROT90, "Century Electronics", "Hunchback (DK conversion)", GAME_SUPPORTS_SAVE )
GAME( 1984, sbdk,     superbik, s2650,    sbdk,           0,  ROT90, "Century Electronics", "Super Bike (DK conversion)", GAME_SUPPORTS_SAVE )
GAME( 1984, herodk,   hero,     s2650,    herodk,    herodk,  ROT90, "Seatongrove Ltd (Crown license)", "Hero in the Castle of Doom (DK conversion)", GAME_SUPPORTS_SAVE )
GAME( 1984, herodku,  hero,     s2650,    herodk,         0,  ROT90, "Seatongrove Ltd (Crown license)", "Hero in the Castle of Doom (DK conversion not encrypted)", GAME_SUPPORTS_SAVE )
GAME( 1984, 8ballact, 0,        s2650,    8ballact,       0,  ROT90, "Seatongrove Ltd (Magic Eletronics USA licence)", "Eight Ball Action (DK conversion)", GAME_SUPPORTS_SAVE )
GAME( 1984, 8ballat2, 8ballact, s2650,    8ballact,       0,  ROT90, "Seatongrove Ltd (Magic Eletronics USA licence)", "Eight Ball Action (DKJr conversion)", GAME_SUPPORTS_SAVE )
GAME( 1984, shootgal, 0,        s2650,    shootgal,       0,  ROT180, "Seatongrove Ltd (Zaccaria licence)", "Shooting Gallery", GAME_IMPERFECT_SOUND | GAME_SUPPORTS_SAVE )
GAME( 1985, spclforc, 0,        spclforc, spclforc,       0,  ROT90, "Senko Industries (Magic Eletronics Inc. licence)", "Special Forces", GAME_NO_SOUND | GAME_SUPPORTS_SAVE )
GAME( 1985, spcfrcii, 0,        spclforc, spclforc,       0,  ROT90, "Senko Industries (Magic Eletronics Inc. licence)", "Special Forces II", GAME_NO_SOUND | GAME_SUPPORTS_SAVE )

/* EPOS */
GAME( 1984, drakton,  0,        drakton,  drakton,  drakton,  ROT90, "Epos Corporation", "Drakton (DK conversion)", GAME_SUPPORTS_SAVE )
GAME( 1984, drktnjr,  drakton,  drktnjr,  drakton,  drakton,  ROT90, "Epos Corporation", "Drakton (DKJr conversion)", GAME_SUPPORTS_SAVE )
GAME( 1985, strtheat, 0,        strtheat, strtheat, strtheat, ROT90, "Epos Corporation", "Street Heat - Cardinal Amusements", GAME_SUPPORTS_SAVE )
