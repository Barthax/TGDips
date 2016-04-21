/***************************************************************************


                                Input Ports


***************************************************************************/

/* Fake input port to read the status of five buttons: used to
   implement the shift using 2 buttons, and the accelerator in
   f1gpstar */

/**************************************************************************
                                Big Run
**************************************************************************/

//  Input Ports:    [0] Fake: Buttons Status
//                  [1] Coins       [2] Controls    [3] Unknown
//                  [4] DSW 1 & 2   [5] DSW 3       [6] Driving Wheel

INPUT_PORTS_START( bigrun )
	PORT_START_TAG("FAKE")	// IN0 - Fake input port - Buttons status
	PORT_BIT( 0x01, IP_ACTIVE_HIGH, IPT_BUTTON1 ) PORT_NAME("P1 Accelerator")\
	PORT_BIT( 0x04, IP_ACTIVE_HIGH, IPT_BUTTON3 ) PORT_NAME("P1 Low Gear")\
	PORT_BIT( 0x08, IP_ACTIVE_HIGH, IPT_BUTTON4 ) PORT_NAME("P1 High Gear")\

	PORT_START_TAG("IN1")	// Coins - $80000.w
	PORT_BIT(  0x01, IP_ACTIVE_LOW, IPT_COIN1    )
	PORT_BIT(  0x02, IP_ACTIVE_LOW, IPT_COIN2    )
	PORT_BIT(  0x04, IP_ACTIVE_LOW, IPT_SERVICE1 )
	PORT_SERVICE_NO_TOGGLE( 0x08, IP_ACTIVE_LOW) 	// called "Test"
	PORT_BIT(  0x10, IP_ACTIVE_LOW, IPT_START1   )
	PORT_BIT(  0x20, IP_ACTIVE_LOW, IPT_START2   )
	PORT_BIT(  0x40, IP_ACTIVE_LOW, IPT_UNKNOWN  )
	PORT_BIT(  0x80, IP_ACTIVE_LOW, IPT_UNKNOWN  )

	PORT_START_TAG("IN2")	//Controls - $80002.w
	PORT_BIT(  0x01, IP_ACTIVE_LOW, IPT_BUTTON2 ) PORT_NAME("P1 Brake")	// Brake
//  PORT_BIT(  0x02, IP_ACTIVE_LOW, IPT_BUTTON4 )   // Shift - We handle it using buttons 3&4
	PORT_BIT(  0x04, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT(  0x08, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT(  0x10, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT(  0x20, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT(  0x40, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT(  0x80, IP_ACTIVE_LOW, IPT_BUTTON5 ) PORT_NAME("P1 Horn")	// Horn

	PORT_START_TAG("IN3")	// Motor Control? - $80004.w
	PORT_DIPNAME( 0x01, 0x01, "Up Limit SW"  	)	// Limit the Cockpit movements?
	PORT_DIPSETTING(    0x01, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On )  )
	PORT_DIPNAME( 0x02, 0x02, "Down Limit SW"	)
	PORT_DIPSETTING(    0x02, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On )  )
	PORT_BIT(  0x04, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT(  0x08, IP_ACTIVE_LOW, IPT_UNKNOWN )
//  PORT_DIPNAME( 0x10, 0x10, "Right Limit SW"  )
//  PORT_DIPSETTING(    0x10, DEF_STR( Off ) )
//  PORT_DIPSETTING(    0x00, DEF_STR( On )  )
//  PORT_DIPNAME( 0x20, 0x20, "Left Limit SW"   )
//  PORT_DIPSETTING(    0x20, DEF_STR( Off ) )
//  PORT_DIPSETTING(    0x00, DEF_STR( On )  )
	PORT_BIT(  0x10, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT(  0x20, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT(  0x40, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT(  0x80, IP_ACTIVE_LOW, IPT_UNKNOWN )

	PORT_START_TAG("IN4")	// DSW 2 & 3 - $80006.w
	// DSW 3
	PORT_DIPNAME( 0x0003, 0x0003, "Unknown 3-0&1*" )
	PORT_DIPSETTING(      0x0003, "3" )
	PORT_DIPSETTING(      0x0002, "2" )
	PORT_DIPSETTING(      0x0001, "1" )
	PORT_DIPSETTING(      0x0000, "0" )
	PORT_DIPNAME( 0x0004, 0x0004, DEF_STR( Allow_Continue ) )
	PORT_DIPSETTING(      0x0004, DEF_STR( No )  )
	PORT_DIPSETTING(      0x0000, DEF_STR( Yes ) )
	PORT_DIPNAME( 0x0008, 0x0008, "Unknown 3-3" )
	PORT_DIPSETTING(      0x0008, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( On )  )
	PORT_DIPNAME( 0x0010, 0x0010, "Move Cabinet" )
	PORT_DIPSETTING(      0x0000, DEF_STR( No )  )
	PORT_DIPSETTING(      0x0010, DEF_STR( Yes ) )
	PORT_DIPNAME( 0x0060, 0x0060, DEF_STR( Difficulty ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( Easy ) )
	PORT_DIPSETTING(      0x0060, DEF_STR( Normal ) )
	PORT_DIPSETTING(      0x0020, DEF_STR( Hard ) )
	PORT_DIPSETTING(      0x0040, DEF_STR( Hardest ) )
	PORT_DIPNAME( 0x0080, 0x0080, "Automatic Game Start" )
	PORT_DIPSETTING(      0x0000, DEF_STR( No ) )
	PORT_DIPSETTING(      0x0080, "After 15 Seconds" )

	// DSW 2
	PORT_DIPNAME( 0x0100, 0x0100, DEF_STR( Free_Play ) )
	PORT_DIPSETTING(      0x0100, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( On )  )
	PORT_DIPNAME( 0x0200, 0x0200, DEF_STR( Demo_Sounds ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0200, DEF_STR( On )  )
	PORT_DIPNAME( 0x1c00, 0x1c00, DEF_STR( Coin_B ) )
	PORT_DIPSETTING(      0x1000, DEF_STR( 4C_1C ) )
	PORT_DIPSETTING(      0x0800, DEF_STR( 3C_1C ) )
	PORT_DIPSETTING(      0x1800, DEF_STR( 2C_1C ) )
	PORT_DIPSETTING(      0x1c00, DEF_STR( 1C_1C ) )
	PORT_DIPSETTING(      0x0c00, DEF_STR( 1C_2C ) )
	PORT_DIPSETTING(      0x1400, DEF_STR( 1C_3C ) )
	PORT_DIPSETTING(      0x0400, DEF_STR( 1C_4C ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( Free_Play ) )
	PORT_DIPNAME( 0xe000, 0xe000, DEF_STR( Coin_A ) )
	PORT_DIPSETTING(      0x8000, DEF_STR( 4C_1C ) )
	PORT_DIPSETTING(      0x4000, DEF_STR( 3C_1C ) )
	PORT_DIPSETTING(      0xc000, DEF_STR( 2C_1C ) )
	PORT_DIPSETTING(      0xe000, DEF_STR( 1C_1C ) )
	PORT_DIPSETTING(      0x6000, DEF_STR( 1C_2C ) )
	PORT_DIPSETTING(      0xa000, DEF_STR( 1C_3C ) )
	PORT_DIPSETTING(      0x2000, DEF_STR( 1C_4C ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( Free_Play ) )

	PORT_START_TAG("IN5")	// DSW 3 (4 bits, Cabinet Linking) - $82200.w
	PORT_BIT(  0x01, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_DIPNAME( 0x06, 0x00, "Unit ID"             )
	PORT_DIPSETTING(    0x00, "1 (Blue-White Car)"  )
	PORT_DIPSETTING(    0x02, "2 (Green-White Car)" )
	PORT_DIPSETTING(    0x04, "3 (Red-White Car)"   )
	PORT_DIPSETTING(    0x06, "4 (Yellow Car)"      )
	PORT_BIT(  0x08, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT(  0x10, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT(  0x20, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT(  0x40, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT(  0x80, IP_ACTIVE_LOW, IPT_UNKNOWN )

	PORT_START_TAG("IN6")	// Driving Wheel - $80010.w(0)
	PORT_BIT( 0xff, 0x80, IPT_PADDLE ) PORT_MINMAX(0,0xff) PORT_SENSITIVITY(30) PORT_KEYDELTA(30)
INPUT_PORTS_END


/**************************************************************************
                                Cisco Heat
**************************************************************************/

//  Input Ports:    [0] Fake: Buttons Status
//                  [1] Coins       [2] Controls    [3] Unknown
//                  [4] DSW 1 & 2   [5] DSW 3       [6] Driving Wheel

INPUT_PORTS_START( cischeat )
	PORT_START_TAG("IN0")	// Fake input port - Buttons status
	PORT_BIT( 0x04, IP_ACTIVE_HIGH, IPT_BUTTON3 ) PORT_NAME("P1 Low Gear")\
	PORT_BIT( 0x08, IP_ACTIVE_HIGH, IPT_BUTTON4 ) PORT_NAME("P1 High Gear")\

	PORT_START_TAG("IN1")	// Coins - $80000.w
	PORT_BIT(  0x01, IP_ACTIVE_LOW, IPT_COIN1    )
	PORT_BIT(  0x02, IP_ACTIVE_LOW, IPT_COIN2    )
	PORT_BIT(  0x04, IP_ACTIVE_LOW, IPT_SERVICE1 )
	PORT_SERVICE_NO_TOGGLE( 0x08, IP_ACTIVE_LOW) 	// called "Test"
	PORT_BIT(  0x10, IP_ACTIVE_LOW, IPT_START1   )
	PORT_BIT(  0x20, IP_ACTIVE_LOW, IPT_START2   )
	PORT_BIT(  0x40, IP_ACTIVE_LOW, IPT_UNKNOWN  )
	PORT_BIT(  0x80, IP_ACTIVE_LOW, IPT_UNKNOWN  )

	PORT_START_TAG("IN2")	// Controls - $80002.w
	PORT_BIT(  0x01, IP_ACTIVE_LOW, IPT_BUTTON2 ) PORT_NAME("P1 Brake")	// Brake
//  PORT_BIT(  0x02, IP_ACTIVE_LOW, IPT_BUTTON4 )   // Shift - We handle it using buttons 3&4
	PORT_BIT(  0x04, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT(  0x08, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT(  0x10, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_NAME("P1 Accelerator")	// Accel
	PORT_BIT(  0x20, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT(  0x40, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT(  0x80, IP_ACTIVE_LOW, IPT_BUTTON5 ) PORT_NAME("P1 Horn")	// Horn

	PORT_START_TAG("IN3")	// Motor Control? - $80004.w
	PORT_DIPNAME( 0x01, 0x01, "Up Limit SW"  	)	// Limit the Cockpit movements?
	PORT_DIPSETTING(    0x01, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On )  )
	PORT_DIPNAME( 0x02, 0x02, "Down Limit SW"	)
	PORT_DIPSETTING(    0x02, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On )  )
	PORT_BIT(  0x04, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT(  0x08, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_DIPNAME( 0x10, 0x10, "Right Limit SW"	)
	PORT_DIPSETTING(    0x10, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On )  )
	PORT_DIPNAME( 0x20, 0x20, "Left Limit SW"	)
	PORT_DIPSETTING(    0x20, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On )  )
	PORT_BIT(  0x40, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT(  0x80, IP_ACTIVE_LOW, IPT_UNKNOWN )

	PORT_START_TAG("IN4")	// DSW 1 & 2 - $80006.w -> !f000a.w(hi byte) !f0008.w(low byte)
	COINAGE_6BITS_2
	PORT_DIPNAME( 0x0040, 0x0040, DEF_STR( Unknown ) )	// unused?
	PORT_DIPSETTING(      0x0040, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( On )  )
	PORT_DIPNAME( 0x0080, 0x0080, DEF_STR( Unknown ) )	// unused?
	PORT_DIPSETTING(      0x0080, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( On )  )
	// DSW 2
	PORT_DIPNAME( 0x0300, 0x0300, "Unit ID"			)		// -> !f0020 (ID of this unit, when linked)
	PORT_DIPSETTING(      0x0300, "0 (Red Car)"    )
	PORT_DIPSETTING(      0x0200, "1 (Blue Car)"   )
	PORT_DIPSETTING(      0x0100, "2 (Yellow Car)" )
	PORT_DIPSETTING(      0x0000, "3 (Green Car)"  )
	PORT_DIPNAME( 0x0c00, 0x0c00, DEF_STR( Difficulty ) )	// -> !f0026
	PORT_DIPSETTING(      0x0000, DEF_STR( Easy )    )
	PORT_DIPSETTING(      0x0c00, DEF_STR( Normal )  )
	PORT_DIPSETTING(      0x0800, DEF_STR( Hard )    )
	PORT_DIPSETTING(      0x0400, DEF_STR( Hardest ) )
	PORT_DIPNAME( 0x1000, 0x1000, "Infinite Time (Cheat)")// -> !f0028
	PORT_DIPSETTING(      0x1000, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( On )  )
	PORT_DIPNAME( 0x2000, 0x2000, DEF_STR( Demo_Sounds ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x2000, DEF_STR( On )  )
	PORT_DIPNAME( 0x4000, 0x4000, "Country" )
	PORT_DIPSETTING(      0x4000, DEF_STR( Japan ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( USA )   )
	PORT_DIPNAME( 0x8000, 0x8000, DEF_STR( Allow_Continue ) )		// -> !f00c0
	PORT_DIPSETTING(      0x8000, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( On )  )

	PORT_START_TAG("IN5")	// DSW 3 (4 bits, Cabinet Linking) - $82200.w
	PORT_BIT(  0x01, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_DIPNAME( 0x06, 0x06, "Unit ID (2)" )	// -> f0020 (like DSW2 !!)
	PORT_DIPSETTING(    0x06, "Use other"      )
	PORT_DIPSETTING(    0x00, "0 (Red Car)"    )
	PORT_DIPSETTING(    0x02, "1 (Blue Car)"   )
	PORT_DIPSETTING(    0x04, "2 (Yellow Car)" )
	PORT_BIT(  0x08, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT(  0x10, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT(  0x20, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT(  0x40, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT(  0x80, IP_ACTIVE_LOW, IPT_UNKNOWN )

	PORT_START	// IN6 - Driving Wheel - $80010.w(0)
	PORT_BIT( 0xff, 0x80, IPT_PADDLE ) PORT_MINMAX(0,0xff) PORT_SENSITIVITY(30) PORT_KEYDELTA(30)
INPUT_PORTS_END


/**************************************************************************
                                F1 GrandPrix Star
**************************************************************************/

//  Input Ports:    [0] Fake: Buttons Status
//                  [1] DSW 1 & 2       [2] Controls        [3] Unknown
//                  [4] DSW 3           [5] Driving Wheel
//                  [6] Coinage JP&USA  [7] Coinage UK&FR

INPUT_PORTS_START( f1gpstar )
	PORT_START_TAG("IN0")	// Fake input port - Buttons status
    PORT_BIT( 0x01, IP_ACTIVE_HIGH, IPT_BUTTON1 ) PORT_NAME("P1 Accelerator")\
	PORT_BIT( 0x04, IP_ACTIVE_HIGH, IPT_BUTTON3 ) PORT_NAME("P1 Low Gear")\
	PORT_BIT( 0x08, IP_ACTIVE_HIGH, IPT_BUTTON4 ) PORT_NAME("P1 High Gear")\

/*  [Country]
    Japan       "race together" in Test Mode, Always Choose Race
                Japanese, Km/h, "handle shock"  , "(c)1991",
    USA         English,  Mph , "steering shock", "(c)1992 North America Only"
    England     English,  Mph , "steering shock", "(c)1992"
    France      French,   Km/h, "steering shock", "(c)1992" */

	PORT_START_TAG("IN1")	// DSW 1 & 2 - $80000.w -> !f9012
	// DSW 1 ( Coinage - it changes with Country: we use IN6 & IN7 )
	PORT_DIPNAME( 0x0040, 0x0040, "Free Play (UK FR)" )
	PORT_DIPSETTING(      0x0040, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( On )  )
	PORT_DIPNAME( 0x0080, 0x0080, DEF_STR( Unknown ) )	// unused?
	PORT_DIPSETTING(      0x0080, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( On )  )
	// DSW 2
	PORT_DIPNAME( 0x0300, 0x0100, "Country"  )	// -> !f901e
	PORT_DIPSETTING(      0x0300, DEF_STR( Japan )   )
	PORT_DIPSETTING(      0x0200, DEF_STR( USA )     )
	PORT_DIPSETTING(      0x0100, "UK"      )
	PORT_DIPSETTING(      0x0000, "France"  )
	PORT_DIPNAME( 0x0c00, 0x0c00, DEF_STR( Difficulty ) )	// -> !f9026
	PORT_DIPSETTING(      0x0000, DEF_STR( Easy )      )	// 58 <- Initial Time (seconds, Germany)
	PORT_DIPSETTING(      0x0c00, DEF_STR( Normal )    )	// 51
	PORT_DIPSETTING(      0x0800, DEF_STR( Hard )      )	// 48
	PORT_DIPSETTING(      0x0400, DEF_STR( Very_Hard ) )	// 46
	PORT_DIPNAME( 0x1000, 0x1000, "Infinite Time (Cheat)")
	PORT_DIPSETTING(      0x1000, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( On )  )
	PORT_DIPNAME( 0x2000, 0x2000, DEF_STR( Demo_Sounds ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x2000, DEF_STR( On )  )
	PORT_DIPNAME( 0x4000, 0x4000, "Choose Race (US UK FR)"  ) // -> f0020
	PORT_DIPSETTING(      0x0000, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x4000, DEF_STR( On )  )
	PORT_DIPNAME( 0x8000, 0x8000, "Vibrations" )
	PORT_DIPSETTING(      0x8000, "Torque" )
	PORT_DIPSETTING(      0x0000, "Shake"  )

	PORT_START_TAG("IN2")	// Controls - $80004.w -> !f9016
	PORT_BIT(  0x0001, IP_ACTIVE_LOW, IPT_COIN1    )
	PORT_BIT(  0x0002, IP_ACTIVE_LOW, IPT_COIN2    )
	PORT_BIT(  0x0004, IP_ACTIVE_LOW, IPT_SERVICE1 )
	PORT_SERVICE_NO_TOGGLE( 0x0008, IP_ACTIVE_LOW) // -> f0100 (called "Test")
	PORT_BIT(  0x0010, IP_ACTIVE_LOW, IPT_START1   )
//  PORT_BIT(  0x0020, IP_ACTIVE_LOW, IPT_BUTTON4  ) // Shift -> !f900e - We handle it with 2 buttons
	PORT_BIT(  0x0040, IP_ACTIVE_LOW, IPT_BUTTON2  ) PORT_NAME("P1 Brake")// Brake -> !f9010
	PORT_BIT(  0x0080, IP_ACTIVE_LOW, IPT_START2   ) // "Race Together"

	PORT_START_TAG("IN3")	// ? Read at boot only - $80006.w
	PORT_BIT(  0x0001, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT(  0x0002, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT(  0x0004, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT(  0x0008, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT(  0x0010, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT(  0x0020, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT(  0x0040, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT(  0x0080, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT(  0x0100, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT(  0x0200, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT(  0x0400, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT(  0x0800, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT(  0x1000, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT(  0x2000, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT(  0x4000, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT(  0x8000, IP_ACTIVE_LOW, IPT_UNKNOWN )

/*  DSW3-2&1 (Country: JP)  Effect
    OFF-OFF                 Red-White Car
    OFF- ON                 Red Car
    ON-OFF                  Blue-White Car
    ON- ON                  Blue Car, "equipped with communication link"    */

	PORT_START_TAG("IN4")	// DSW 3 (4 bits, Cabinet Linking) - $8000c.w -> !f9014
	PORT_DIPNAME( 0x01, 0x01, "This Unit Is" )
	PORT_DIPSETTING(    0x01, "Slave" )
	PORT_DIPSETTING(    0x00, "Master" )
	PORT_DIPNAME( 0x06, 0x06, "Unit ID" )			// -> !f901c
	PORT_DIPSETTING(    0x06, "0 (Red-White Car)" )
	PORT_DIPSETTING(    0x04, "1 (Red Car)" )
	PORT_DIPSETTING(    0x02, "2 (Blue-White Car)" )
	PORT_DIPSETTING(    0x00, "3 (Blue Car)" )
	PORT_BIT(  0x08, IP_ACTIVE_LOW, IPT_UNKNOWN )	// Redundant: Invert Unit ID
	PORT_BIT(  0x10, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT(  0x20, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT(  0x40, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT(  0x80, IP_ACTIVE_LOW, IPT_UNKNOWN )

				//       Accelerator   - $80010.b ->  !f9004.w
	PORT_START_TAG("IN5")	// Driving Wheel - $80011.b ->  !f9008.w
	PORT_BIT( 0xff, 0x80, IPT_PADDLE ) PORT_MINMAX(0,0xff) PORT_SENSITIVITY(30) PORT_KEYDELTA(30)

	PORT_START_TAG("IN6")	// Coinage Japan & USA (it changes with Country)
	PORT_DIPNAME( 0x0007, 0x0007, "Coin A (JP US)" )
	PORT_DIPSETTING(      0x0001, DEF_STR( 4C_1C ) )
	PORT_DIPSETTING(      0x0002, DEF_STR( 3C_1C ) )
	PORT_DIPSETTING(      0x0003, DEF_STR( 2C_1C ) )
	PORT_DIPSETTING(      0x0007, DEF_STR( 1C_1C ) )
	PORT_DIPSETTING(      0x0006, DEF_STR( 1C_2C ) )
	PORT_DIPSETTING(      0x0005, DEF_STR( 1C_3C ) )
	PORT_DIPSETTING(      0x0004, DEF_STR( 1C_4C ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( Free_Play ) )
	PORT_DIPNAME( 0x0038, 0x0038, "Coin B (JP US)" )
	PORT_DIPSETTING(      0x0008, DEF_STR( 4C_1C ) )
	PORT_DIPSETTING(      0x0010, DEF_STR( 3C_1C ) )
	PORT_DIPSETTING(      0x0018, DEF_STR( 2C_1C ) )
	PORT_DIPSETTING(      0x0038, DEF_STR( 1C_1C ) )
	PORT_DIPSETTING(      0x0030, DEF_STR( 1C_2C ) )
	PORT_DIPSETTING(      0x0028, DEF_STR( 1C_3C ) )
	PORT_DIPSETTING(      0x0020, DEF_STR( 1C_4C ) )

	PORT_START_TAG("IN7")	// Coinage UK & France (it changes with Country)
	PORT_DIPNAME( 0x0007, 0x0007, "Coin A (UK FR)" )
	PORT_DIPSETTING(      0x0007, DEF_STR( 1C_1C ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( 2C_3C ) )
	PORT_DIPSETTING(      0x0006, DEF_STR( 1C_2C ) )
	PORT_DIPSETTING(      0x0005, DEF_STR( 1C_3C ) )
	PORT_DIPSETTING(      0x0004, DEF_STR( 1C_4C ) )
	PORT_DIPSETTING(      0x0003, DEF_STR( 1C_5C ) )
	PORT_DIPSETTING(      0x0002, DEF_STR( 1C_6C ) )
	PORT_DIPSETTING(      0x0001, DEF_STR( 1C_7C ) )
	PORT_DIPNAME( 0x0038, 0x0038, "Coin B (UK FR)" )
	PORT_DIPSETTING(      0x0000, DEF_STR( 5C_1C ) )
	PORT_DIPSETTING(      0x0008, DEF_STR( 4C_1C ) )
	PORT_DIPSETTING(      0x0010, DEF_STR( 3C_1C ) )
	PORT_DIPSETTING(      0x0018, DEF_STR( 2C_1C ) )
	PORT_DIPSETTING(      0x0038, DEF_STR( 1C_1C ) )
	PORT_DIPSETTING(      0x0030, DEF_STR( 1C_2C ) )
	PORT_DIPSETTING(      0x0028, DEF_STR( 1C_3C ) )
	PORT_DIPSETTING(      0x0020, DEF_STR( 1C_4C ) )
INPUT_PORTS_END


/**************************************************************************
                                Wild Pilot
**************************************************************************/

INPUT_PORTS_START( wildplt )
	PORT_START_TAG("IN0")	// DSW 1 & 2
	PORT_DIPNAME( 0x0007, 0x0007, DEF_STR( Coinage ) )
	PORT_DIPSETTING(      0x0001, DEF_STR( 4C_1C ) )
	PORT_DIPSETTING(      0x0002, DEF_STR( 3C_1C ) )
	PORT_DIPSETTING(      0x0003, DEF_STR( 2C_1C ) )
	PORT_DIPSETTING(      0x0007, DEF_STR( 1C_1C ) )
	PORT_DIPSETTING(      0x0006, DEF_STR( 1C_2C ) )
	PORT_DIPSETTING(      0x0005, DEF_STR( 1C_3C ) )
	PORT_DIPSETTING(      0x0004, DEF_STR( 1C_4C ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( Free_Play ) )
	PORT_DIPNAME( 0x0008, 0x0008, DEF_STR( Unknown ) )
	PORT_DIPSETTING(      0x0008, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( On ) )
	PORT_DIPNAME( 0x0010, 0x0010, DEF_STR( Unknown ) )
	PORT_DIPSETTING(      0x0010, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( On ) )
	PORT_DIPNAME( 0x0020, 0x0020, DEF_STR( Unknown ) )
	PORT_DIPSETTING(      0x0020, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( On ) )
	PORT_DIPNAME( 0x0040, 0x0040, DEF_STR( Unknown ) )
	PORT_DIPSETTING(      0x0040, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( On ) )
	PORT_DIPNAME( 0x0080, 0x0080, DEF_STR( Unknown ) )
	PORT_DIPSETTING(      0x0080, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( On ) )
	PORT_DIPNAME( 0x0100, 0x0100, DEF_STR( Unknown ) )
	PORT_DIPSETTING(      0x0100, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( On ) )
	PORT_DIPNAME( 0x0200, 0x0200, DEF_STR( Unknown ) )
	PORT_DIPSETTING(      0x0200, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( On ) )
	PORT_DIPNAME( 0x0400, 0x0400, DEF_STR( Unknown ) )
	PORT_DIPSETTING(      0x0400, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( On ) )
	PORT_DIPNAME( 0x0800, 0x0800, DEF_STR( Unknown ) )
	PORT_DIPSETTING(      0x0800, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( On ) )
	PORT_DIPNAME( 0x1000, 0x1000, DEF_STR( Demo_Sounds ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x1000, DEF_STR( On ) )
	PORT_DIPNAME( 0x2000, 0x2000, DEF_STR( Unknown ) )
	PORT_DIPSETTING(      0x2000, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( On ) )
	PORT_DIPNAME( 0x4000, 0x4000, DEF_STR( Unknown ) )
	PORT_DIPSETTING(      0x4000, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( On ) )
	PORT_DIPNAME( 0x8000, 0x8000, DEF_STR( Unknown ) )
	PORT_DIPSETTING(      0x8000, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( On ) )

	PORT_START_TAG("IN1")
	PORT_BIT(  0x0001, IP_ACTIVE_LOW, IPT_COIN1 )
	PORT_BIT(  0x0002, IP_ACTIVE_LOW, IPT_BUTTON3 ) PORT_PLAYER(1)
	PORT_BIT(  0x0004, IP_ACTIVE_LOW, IPT_SERVICE1 ) //start 1 too
	PORT_SERVICE_NO_TOGGLE( 0x0008, IP_ACTIVE_LOW) //start 2 too
	PORT_BIT(  0x0010, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_PLAYER(2)
	PORT_BIT(  0x0020, IP_ACTIVE_LOW, IPT_BUTTON2 ) PORT_PLAYER(2)
	PORT_BIT(  0x0040, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_PLAYER(1)
	PORT_BIT(  0x0080, IP_ACTIVE_LOW, IPT_BUTTON2 ) PORT_PLAYER(1)
	PORT_BIT(  0x0100, IP_ACTIVE_LOW, IPT_BUTTON3 ) PORT_PLAYER(2)
	PORT_BIT(  0x0200, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT(  0x0400, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT(  0x0800, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT(  0x1000, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT(  0x2000, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT(  0x4000, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x8000, IP_ACTIVE_LOW, IPT_SERVICE2 ) PORT_NAME("Emergency Button") //E Stop for motors?

	PORT_START_TAG("IN2")
	PORT_BIT( 0xff, 0x80, IPT_LIGHTGUN_Y ) PORT_MINMAX(0,0xff) PORT_SENSITIVITY(35) PORT_KEYDELTA(15) PORT_REVERSE

	PORT_START_TAG("IN3")
	PORT_BIT( 0xff, 0x80, IPT_LIGHTGUN_X ) PORT_MINMAX(0,0xff) PORT_SENSITIVITY(35) PORT_KEYDELTA(15)
INPUT_PORTS_END


/**************************************************************************
                                Scud Hammer
**************************************************************************/

INPUT_PORTS_START( scudhamm )
	PORT_START_TAG("IN0")	// Buttons
	PORT_BIT( 0x0001, IP_ACTIVE_LOW, IPT_COIN1 ) PORT_IMPULSE(1)
	PORT_BIT(  0x0002, IP_ACTIVE_LOW, IPT_UNKNOWN  ) // GAME OVER if pressed on the selection screen
	PORT_BIT(  0x0004, IP_ACTIVE_LOW, IPT_SERVICE1 )
	PORT_SERVICE_NO_TOGGLE( 0x0008, IP_ACTIVE_LOW) 	// called "Test"
	PORT_BIT(  0x0010, IP_ACTIVE_LOW, IPT_START1   )
	PORT_BIT(  0x0020, IP_ACTIVE_LOW, IPT_BUTTON4  ) // Select
	PORT_BIT(  0x0040, IP_ACTIVE_LOW, IPT_UNKNOWN  )
	PORT_BIT(  0x0080, IP_ACTIVE_LOW, IPT_UNKNOWN  )

	PORT_BIT(  0x0100, IP_ACTIVE_HIGH, IPT_BUTTON1 ) // Gu
	PORT_BIT(  0x0200, IP_ACTIVE_HIGH, IPT_BUTTON2 ) // Choki
	PORT_BIT(  0x0400, IP_ACTIVE_HIGH, IPT_BUTTON3 ) // Pa
	PORT_BIT(  0x0800, IP_ACTIVE_LOW,  IPT_UNKNOWN )
	PORT_BIT(  0x1000, IP_ACTIVE_LOW,  IPT_UNKNOWN )
	PORT_BIT(  0x2000, IP_ACTIVE_LOW,  IPT_UNKNOWN )
	PORT_BIT(  0x4000, IP_ACTIVE_HIGH, IPT_TILT    )
	PORT_BIT(  0x8000, IP_ACTIVE_LOW,  IPT_UNKNOWN )

	PORT_START_TAG("IN1")	// A/D
	PORT_BIT( 0x00ff, 0x0000, IPT_PADDLE ) PORT_MINMAX(0x0000,0x00ff) PORT_SENSITIVITY(1) PORT_KEYDELTA(0)

	PORT_START_TAG("IN2")	// DSW
	PORT_DIPNAME( 0x0003, 0x0003, DEF_STR( Difficulty ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( Easy ) )
	PORT_DIPSETTING(      0x0003, DEF_STR( Normal ) )
	PORT_DIPSETTING(      0x0002, DEF_STR( Hard ) )
	PORT_DIPSETTING(      0x0001, DEF_STR( Hardest ) )
	PORT_DIPNAME( 0x000c, 0x000c, "Time To Hit" )
	PORT_DIPSETTING(      0x000c, "2 s" )
	PORT_DIPSETTING(      0x0008, "3 s" )
	PORT_DIPSETTING(      0x0004, "4 s" )
	PORT_DIPSETTING(      0x0000, "5 s" )
	PORT_DIPNAME( 0x0010, 0x0010, DEF_STR( Demo_Sounds ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0010, DEF_STR( On ) )
	PORT_DIPNAME( 0x0020, 0x0020, DEF_STR( Lives ) )
	PORT_DIPSETTING(      0x0020, "3" )
	PORT_DIPSETTING(      0x0000, "5" )
	PORT_DIPNAME( 0x0040, 0x0040, "Unknown 1-6" )
	PORT_DIPSETTING(      0x0040, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( On ) )
	PORT_DIPNAME( 0x0080, 0x0080, "Unknown 1-7" )
	PORT_DIPSETTING(      0x0080, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( On ) )

	PORT_DIPNAME( 0x0700, 0x0700, DEF_STR( Coinage ) )
	PORT_DIPSETTING(      0x0100, DEF_STR( 4C_1C ) )
	PORT_DIPSETTING(      0x0200, DEF_STR( 3C_1C ) )
	PORT_DIPSETTING(      0x0300, DEF_STR( 2C_1C ) )
	PORT_DIPSETTING(      0x0700, DEF_STR( 1C_1C ) )
	PORT_DIPSETTING(      0x0600, DEF_STR( 1C_2C ) )
	PORT_DIPSETTING(      0x0500, DEF_STR( 1C_3C ) )
	PORT_DIPSETTING(      0x0400, DEF_STR( 1C_4C ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( Free_Play ) )
	PORT_DIPNAME( 0x0800, 0x0800, "Unknown 2-3" )
	PORT_DIPSETTING(      0x0800, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( On ) )
	PORT_DIPNAME( 0x1000, 0x1000, "Unknown 2-4" )
	PORT_DIPSETTING(      0x1000, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( On ) )
	PORT_DIPNAME( 0x2000, 0x2000, "Unknown 2-5" )
	PORT_DIPSETTING(      0x2000, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( On ) )
	PORT_DIPNAME( 0x4000, 0x4000, "Unknown 2-6" )
	PORT_DIPSETTING(      0x4000, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( On ) )
	PORT_DIPNAME( 0x8000, 0x8000, "Unknown 2-7" )
	PORT_DIPSETTING(      0x8000, DEF_STR( Off ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( On ) )
INPUT_PORTS_END


/**************************************************************************
                            Arm Champs II
**************************************************************************/

INPUT_PORTS_START( armchmp2 )
	PORT_START_TAG("IN0")	// Buttons + Sensors
	PORT_BIT( 0x0001, IP_ACTIVE_LOW, IPT_SPECIAL  ) // left   sensor
	PORT_BIT( 0x0002, IP_ACTIVE_LOW, IPT_SPECIAL  ) // right  sensor
	PORT_BIT( 0x0004, IP_ACTIVE_LOW, IPT_SPECIAL  ) // center sensor
	PORT_BIT( 0x0008, IP_ACTIVE_LOW, IPT_SERVICE1 )
	PORT_SERVICE_NO_TOGGLE( 0x0010, IP_ACTIVE_LOW )
	PORT_BIT( 0x0020, IP_ACTIVE_LOW, IPT_COIN1    )
	PORT_BIT( 0x0040, IP_ACTIVE_LOW, IPT_COIN2    )
	PORT_BIT( 0x0080, IP_ACTIVE_LOW, IPT_UNKNOWN  )
	PORT_BIT( 0x0100, IP_ACTIVE_LOW, IPT_START1   )
	PORT_BIT( 0x0200, IP_ACTIVE_LOW, IPT_BUTTON1  ) // hard
	PORT_BIT( 0x0400, IP_ACTIVE_LOW, IPT_BUTTON2  ) // easy
	PORT_BIT( 0x0800, IP_ACTIVE_LOW, IPT_BUTTON3  ) // elbow (it always complains though)

	PORT_START_TAG("IN1")	// A/D
	PORT_BIT( 0x00ff, 0x0000, IPT_DIAL ) PORT_MINMAX(0x0000,0x00ff) PORT_SENSITIVITY(100) PORT_KEYDELTA(10)

	PORT_START_TAG("IN2")	// DSW
	PORT_DIPNAME( 0x0003, 0x0003, DEF_STR( Difficulty ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( Easy ) )
	PORT_DIPSETTING(      0x0003, DEF_STR( Normal ) )
	PORT_DIPSETTING(      0x0002, DEF_STR( Hard ) )
	PORT_DIPSETTING(      0x0001, DEF_STR( Hardest ) )
	PORT_DIPNAME( 0x000c, 0x000c, DEF_STR( Lives ) )
	PORT_DIPSETTING(      0x0000, "1" )
	PORT_DIPSETTING(      0x000c, "2" )
	PORT_DIPSETTING(      0x0008, "3" )
	PORT_DIPSETTING(      0x0004, "4" )
	PORT_DIPNAME( 0x0030, 0x0030, DEF_STR( Game_Time ) )
	PORT_DIPSETTING(      0x0000, "15 s" )
	PORT_DIPSETTING(      0x0030, "20 s" )
	PORT_DIPSETTING(      0x0020, "25 s" )
	PORT_DIPSETTING(      0x0010, "30 s" )
	PORT_DIPNAME( 0x00c0, 0x0000, DEF_STR( Region ) )	// some text is in japanese regardless!
	PORT_DIPSETTING(      0x00c0, DEF_STR( Japan ) )
	PORT_DIPSETTING(      0x0080, DEF_STR( USA ) )
	PORT_DIPSETTING(      0x0040, DEF_STR( Europe ) )
	PORT_DIPSETTING(      0x0000, DEF_STR( World ) )

	PORT_START_TAG("IN3")	// DSW
	PORT_DIPNAME( 0x07, 0x07, DEF_STR( Coin_A ) )
	PORT_DIPSETTING(    0x01, DEF_STR( 4C_1C ) )
	PORT_DIPSETTING(    0x02, DEF_STR( 3C_1C ) )
	PORT_DIPSETTING(    0x03, DEF_STR( 2C_1C ) )
	PORT_DIPSETTING(    0x07, DEF_STR( 1C_1C ) )
	PORT_DIPSETTING(    0x06, DEF_STR( 1C_2C ) )
	PORT_DIPSETTING(    0x05, DEF_STR( 1C_3C ) )
	PORT_DIPSETTING(    0x04, DEF_STR( 1C_4C ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Free_Play ) )
	PORT_DIPNAME( 0x38, 0x38, DEF_STR( Coin_B ) )
	PORT_DIPSETTING(    0x08, DEF_STR( 4C_1C ) )
	PORT_DIPSETTING(    0x10, DEF_STR( 3C_1C ) )
	PORT_DIPSETTING(    0x18, DEF_STR( 2C_1C ) )
	PORT_DIPSETTING(    0x38, DEF_STR( 1C_1C ) )
	PORT_DIPSETTING(    0x30, DEF_STR( 1C_2C ) )
	PORT_DIPSETTING(    0x28, DEF_STR( 1C_3C ) )
	PORT_DIPSETTING(    0x20, DEF_STR( 1C_4C ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Free_Play ) )
	PORT_DIPNAME( 0x40, 0x40, DEF_STR( Demo_Sounds ) )
	PORT_DIPSETTING(    0x00, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x40, DEF_STR( On ) )
	PORT_DIPNAME( 0x80, 0x80, "Demo Arm" )
	PORT_DIPSETTING(    0x80, "Center" )
	PORT_DIPSETTING(    0x00, "Side" )
INPUT_PORTS_END


/***************************************************************************


                                Game Drivers


***************************************************************************/

GAME( 1989, bigrun,   0, bigrun,   bigrun,   bigrun,   ROT0,   "Jaleco", "Big Run (11th Rallye version)", GAME_IMPERFECT_GRAPHICS )	// there's a 13th Rallye version (1991)
GAME( 1990, cischeat, 0, cischeat, cischeat, cischeat, ROT0,   "Jaleco", "Cisco Heat",                    GAME_IMPERFECT_GRAPHICS )
GAME( 1991, f1gpstar, 0, f1gpstar, f1gpstar, f1gpstar, ROT0,   "Jaleco", "Grand Prix Star",               GAME_IMPERFECT_GRAPHICS )
GAME( 1992, armchmp2, 0, armchmp2, armchmp2, 0,        ROT270, "Jaleco", "Arm Champs II",                 GAME_IMPERFECT_GRAPHICS )
GAME( 1992, wildplt,  0, f1gpstr2, wildplt,  wildplt,  ROT0,   "Jaleco", "Wild Pilot",                    GAME_IMPERFECT_GRAPHICS )
GAME( 1993, f1gpstr2, 0, f1gpstr2, f1gpstar, f1gpstar, ROT0,   "Jaleco", "F-1 Grand Prix Star II",        GAME_IMPERFECT_GRAPHICS )
GAME( 1994, scudhamm, 0, scudhamm, scudhamm, 0,        ROT270, "Jaleco", "Scud Hammer",                   GAME_IMPERFECT_GRAPHICS )
