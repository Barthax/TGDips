# MAME 0.106 source snippet

INPUT_PORTS_START( simpl156 )
	PORT_START	/* 16bit */
	PORT_BIT( 0x0001, IP_ACTIVE_LOW, IPT_COIN1 )
	PORT_BIT( 0x0002, IP_ACTIVE_LOW, IPT_COIN2 )
	PORT_BIT( 0x0004, IP_ACTIVE_LOW, IPT_SERVICE1 )
	PORT_BIT( 0x0008, IP_ACTIVE_LOW, IPT_SERVICE ) PORT_NAME( DEF_STR( Service_Mode )) PORT_CODE(KEYCODE_F2)
	PORT_BIT( 0x00f0, IP_ACTIVE_HIGH, IPT_VBLANK ) // all bits? check..
	PORT_BIT( 0x0100, IP_ACTIVE_HIGH, IPT_SPECIAL ) // eeprom?..


	PORT_START	/* 16bit */
	PORT_BIT( 0x0001, IP_ACTIVE_LOW, IPT_JOYSTICK_UP ) PORT_8WAY PORT_PLAYER(1)
	PORT_BIT( 0x0002, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN ) PORT_8WAY PORT_PLAYER(1)
	PORT_BIT( 0x0004, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT ) PORT_8WAY PORT_PLAYER(1)
	PORT_BIT( 0x0008, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT ) PORT_8WAY PORT_PLAYER(1)
	PORT_BIT( 0x0010, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_PLAYER(1)
	PORT_BIT( 0x0020, IP_ACTIVE_LOW, IPT_BUTTON2 ) PORT_PLAYER(1)
	PORT_BIT( 0x0040, IP_ACTIVE_LOW, IPT_BUTTON3 ) PORT_PLAYER(1)
	PORT_BIT( 0x0080, IP_ACTIVE_LOW, IPT_START1 )
	PORT_BIT( 0x0100, IP_ACTIVE_LOW, IPT_JOYSTICK_UP ) PORT_8WAY PORT_PLAYER(2)
	PORT_BIT( 0x0200, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN ) PORT_8WAY PORT_PLAYER(2)
	PORT_BIT( 0x0400, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT ) PORT_8WAY PORT_PLAYER(2)
	PORT_BIT( 0x0800, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT ) PORT_8WAY PORT_PLAYER(2)
	PORT_BIT( 0x1000, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_PLAYER(2)
	PORT_BIT( 0x2000, IP_ACTIVE_LOW, IPT_BUTTON2 ) PORT_PLAYER(2)
	PORT_BIT( 0x4000, IP_ACTIVE_LOW, IPT_BUTTON3 ) PORT_PLAYER(2)
	PORT_BIT( 0x8000, IP_ACTIVE_LOW, IPT_START2 )
INPUT_PORTS_END

GAME( 1996, osman,   0,        mitchell156,    simpl156, osman,         ROT0, "Mitchell", "Osman (World)", 0 )
GAME( 1996, candance,osman,    mitchell156,    simpl156, candance,      ROT0, "Mitchell (Atlus License)", "Cannon Dancer (Japan)", 0 )
GAME( 1995, chainrec,0,        chainrec,       simpl156, chainrec,      ROT0, "Data East","Chain Reaction (World, Version 2.2, 1995.09.25)", 0 )
GAME( 1995, magdrop, chainrec, magdrop,        simpl156, chainrec,      ROT0, "Data East","Magical Drop (Japan, Version 1.1, 1995.06.21)", 0 )
GAME( 1995, magdropp,chainrec, magdropp,       simpl156, chainrec,      ROT0, "Data East","Magical Drop Plus 1 (Japan, Version 2.1, 1995.09.12)", 0 )
GAME( 1995, charlien,0,        mitchell156,    simpl156, charlien,      ROT0, "Mitchell", "Charlie Ninja" , 0) // language in service mode
GAME( 1994, joemacr, 0,        joemacr,        simpl156, joemacr,       ROT0, "Data East", "Joe & Mac Returns (World, Version 1.1, 1994.05.27)", 0 )
GAME( 1994, joemacra,joemacr,  joemacr,        simpl156, joemacr,       ROT0, "Data East", "Joe & Mac Returns (World, Version 1.0, 1994.05.19)", 0 )
GAME( 1995, prtytime,0,        mitchell156,    simpl156, prtytime,      ROT90,"Mitchell", "Party Time: Gonta the Diver II / Ganbare! Gonta!! 2 (World Release)", 0) // language is in service mode
GAME( 1995, gangonta,prtytime, mitchell156,    simpl156, gangonta,      ROT90,"Mitchell", "Ganbare! Gonta!! 2 / Party Time: Gonta the Diver II (Japan Release)", 0) // language is in service mode
