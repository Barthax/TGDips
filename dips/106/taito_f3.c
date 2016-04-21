INPUT_PORTS_START( f3 )
	PORT_START
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_JOYSTICK_UP ) PORT_8WAY
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN ) PORT_8WAY
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT ) PORT_8WAY
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT ) PORT_8WAY
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_JOYSTICK_UP ) PORT_8WAY PORT_PLAYER(2)
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN ) PORT_8WAY PORT_PLAYER(2)
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT ) PORT_8WAY PORT_PLAYER(2)
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT ) PORT_8WAY PORT_PLAYER(2)

	PORT_START
	PORT_BIT( 0x0001, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_PLAYER(1)
	PORT_BIT( 0x0002, IP_ACTIVE_LOW, IPT_BUTTON2 ) PORT_PLAYER(1)
	PORT_BIT( 0x0004, IP_ACTIVE_LOW, IPT_BUTTON3 ) PORT_PLAYER(1)
	PORT_BIT( 0x0008, IP_ACTIVE_LOW, IPT_BUTTON4 ) PORT_PLAYER(1)
	PORT_BIT( 0x0010, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_PLAYER(2)
	PORT_BIT( 0x0020, IP_ACTIVE_LOW, IPT_BUTTON2 ) PORT_PLAYER(2)
	PORT_BIT( 0x0040, IP_ACTIVE_LOW, IPT_BUTTON3 ) PORT_PLAYER(2)
	PORT_BIT( 0x0080, IP_ACTIVE_LOW, IPT_BUTTON4 ) PORT_PLAYER(2)
	PORT_BIT( 0x0100, IP_ACTIVE_LOW, IPT_TILT )
	PORT_BIT( 0x0200, IP_ACTIVE_LOW, IPT_SERVICE1 ) /* Service */
	PORT_BIT( 0x0400, IP_ACTIVE_LOW, IPT_SERVICE2 ) /* Only on some games */
	PORT_BIT( 0x0800, IP_ACTIVE_LOW, IPT_SERVICE3 ) /* Only on some games */
	PORT_BIT( 0x1000, IP_ACTIVE_LOW, IPT_START1 )
	PORT_BIT( 0x2000, IP_ACTIVE_LOW, IPT_START2 )
	PORT_BIT( 0x4000, IP_ACTIVE_LOW, IPT_START3 )
	PORT_BIT( 0x8000, IP_ACTIVE_LOW, IPT_START4 )

	PORT_START
	PORT_BIT( 0x01, IP_ACTIVE_HIGH, IPT_SPECIAL ) /* Eprom data bit */
	PORT_BIT(0x02, IP_ACTIVE_LOW, IPT_SERVICE ) PORT_NAME( DEF_STR( Service_Mode )) PORT_CODE(KEYCODE_F2)
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_UNUSED ) /* Another service mode */
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_COIN1 )
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_COIN2 )
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_COIN3 )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_COIN4 )

	PORT_START
	PORT_BIT( 0xfff, 0x000, IPT_DIAL ) PORT_SENSITIVITY(25) PORT_KEYDELTA(25) PORT_CODE_DEC(KEYCODE_Z) PORT_CODE_INC(KEYCODE_X) PORT_PLAYER(1)

	PORT_START
	PORT_BIT( 0xfff, 0x000, IPT_DIAL ) PORT_SENSITIVITY(25) PORT_KEYDELTA(25) PORT_CODE_DEC(KEYCODE_N) PORT_CODE_INC(KEYCODE_M) PORT_PLAYER(2)

	PORT_START
	PORT_BIT( 0x0001, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_PLAYER(3)
	PORT_BIT( 0x0002, IP_ACTIVE_LOW, IPT_BUTTON2 ) PORT_PLAYER(3)
	PORT_BIT( 0x0004, IP_ACTIVE_LOW, IPT_BUTTON3 ) PORT_PLAYER(3)
	PORT_BIT( 0x0008, IP_ACTIVE_LOW, IPT_BUTTON4 ) PORT_PLAYER(3)
	PORT_BIT( 0x0010, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_PLAYER(4)
	PORT_BIT( 0x0020, IP_ACTIVE_LOW, IPT_BUTTON2 ) PORT_PLAYER(4)
	PORT_BIT( 0x0040, IP_ACTIVE_LOW, IPT_BUTTON3 ) PORT_PLAYER(4)
	PORT_BIT( 0x0080, IP_ACTIVE_LOW, IPT_BUTTON4 ) PORT_PLAYER(4)

	PORT_START
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_JOYSTICK_UP ) PORT_8WAY PORT_PLAYER(3)
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN ) PORT_8WAY PORT_PLAYER(3)
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT ) PORT_8WAY PORT_PLAYER(3)
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT ) PORT_8WAY PORT_PLAYER(3)
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_JOYSTICK_UP ) PORT_8WAY PORT_PLAYER(4)
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN ) PORT_8WAY PORT_PLAYER(4)
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT ) PORT_8WAY PORT_PLAYER(4)
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT ) PORT_8WAY PORT_PLAYER(4)
INPUT_PORTS_END

INPUT_PORTS_START( kn )
	PORT_START
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_JOYSTICK_UP ) PORT_8WAY
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN ) PORT_8WAY
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT ) PORT_8WAY
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT ) PORT_8WAY
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_JOYSTICK_UP ) PORT_8WAY PORT_PLAYER(2)
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN ) PORT_8WAY PORT_PLAYER(2)
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT ) PORT_8WAY PORT_PLAYER(2)
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT ) PORT_8WAY PORT_PLAYER(2)

	PORT_START
	PORT_BIT( 0x0001, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_PLAYER(1)
	PORT_BIT( 0x0002, IP_ACTIVE_LOW, IPT_BUTTON2 ) PORT_PLAYER(1)
	PORT_BIT( 0x0004, IP_ACTIVE_LOW, IPT_BUTTON3 ) PORT_PLAYER(1)
	PORT_BIT( 0x0008, IP_ACTIVE_LOW, IPT_BUTTON4 ) PORT_PLAYER(1)
	PORT_BIT( 0x0010, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_PLAYER(2)
	PORT_BIT( 0x0020, IP_ACTIVE_LOW, IPT_BUTTON2 ) PORT_PLAYER(2)
	PORT_BIT( 0x0040, IP_ACTIVE_LOW, IPT_BUTTON3 ) PORT_PLAYER(2)
	PORT_BIT( 0x0080, IP_ACTIVE_LOW, IPT_BUTTON4 ) PORT_PLAYER(2)
	PORT_BIT( 0x0100, IP_ACTIVE_LOW, IPT_TILT )
	PORT_BIT( 0x0200, IP_ACTIVE_LOW, IPT_SERVICE1 ) /* Service */
	PORT_BIT( 0x0400, IP_ACTIVE_LOW, IPT_SERVICE2 ) /* Only on some games */
	PORT_BIT( 0x0800, IP_ACTIVE_LOW, IPT_SERVICE3 )
	PORT_BIT( 0x1000, IP_ACTIVE_LOW, IPT_START1 )
	PORT_BIT( 0x2000, IP_ACTIVE_LOW, IPT_START2 )
	PORT_BIT( 0x4000, IP_ACTIVE_LOW, IPT_START3 )
	PORT_BIT( 0x8000, IP_ACTIVE_LOW, IPT_START4 )

	PORT_START
	PORT_BIT( 0x01, IP_ACTIVE_HIGH, IPT_SPECIAL ) /* Eprom data bit */
	PORT_BIT(0x02, IP_ACTIVE_LOW, IPT_SERVICE ) PORT_NAME( DEF_STR( Service_Mode )) PORT_CODE(KEYCODE_F2)
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_UNKNOWN )
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_UNUSED ) /* Another service mode */
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_COIN1 )
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_COIN2 )
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_COIN3 )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_COIN4 )

	PORT_START
	PORT_BIT( 0xfff, 0x000, IPT_DIAL ) PORT_SENSITIVITY(25) PORT_KEYDELTA(25) PORT_CODE_DEC(KEYCODE_Z) PORT_CODE_INC(KEYCODE_X) PORT_PLAYER(1)

	PORT_START
	PORT_BIT( 0xfff, 0x000, IPT_DIAL ) PORT_SENSITIVITY(25) PORT_KEYDELTA(25) PORT_CODE_DEC(KEYCODE_N) PORT_CODE_INC(KEYCODE_M) PORT_PLAYER(2)

	PORT_START
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_BUTTON4 ) PORT_PLAYER(2)
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_BUTTON5 ) PORT_PLAYER(2)
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_BUTTON6 ) PORT_PLAYER(2)
	PORT_BIT( 0xf8, IP_ACTIVE_LOW, IPT_UNUSED )

	PORT_START
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_BUTTON4 ) PORT_PLAYER(1)
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_BUTTON5 ) PORT_PLAYER(1)
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_BUTTON6 ) PORT_PLAYER(1)
	PORT_BIT( 0xf8, IP_ACTIVE_LOW, IPT_UNUSED )
INPUT_PORTS_END


GAME( 1992, ringrage, 0,        f3_224a, f3, ringrage, ROT0,   "Taito Corporation Japan",   "Ring Rage (Ver 2.3O 1992/08/09)", GAME_IMPERFECT_SOUND )
GAME( 1992, ringragj, ringrage, f3_224a, f3, ringrage, ROT0,   "Taito Corporation",         "Ring Rage (Ver 2.3J 1992/08/09)", GAME_IMPERFECT_SOUND )
GAME( 1992, ringragu, ringrage, f3_224a, f3, ringrage, ROT0,   "Taito America Corporation", "Ring Rage (Ver 2.3A 1992/08/09)", GAME_IMPERFECT_SOUND )
GAME( 1992, arabianm, 0,        f3_224a, f3, arabianm, ROT0,   "Taito Corporation Japan",   "Arabian Magic (Ver 1.0O 1992/07/06)", 0 )
GAME( 1992, arabiamj, arabianm, f3_224a, f3, arabianm, ROT0,   "Taito Corporation",         "Arabian Magic (Ver 1.0J 1992/07/06)", 0 )
GAME( 1992, arabiamu, arabianm, f3_224a, f3, arabianm, ROT0,   "Taito America Corporation", "Arabian Magic (Ver 1.0A 1992/07/06)", 0 )
GAME( 1992, ridingf,  0,        f3_224b, f3, ridingf,  ROT0,   "Taito Corporation Japan",   "Riding Fight (Ver 1.0O)", GAME_NO_SOUND )
GAME( 1992, ridefgtj, ridingf,  f3_224b, f3, ridingf,  ROT0,   "Taito Corporation",         "Riding Fight (Ver 1.0J)", GAME_NO_SOUND )
GAME( 1992, ridefgtu, ridingf,  f3_224b, f3, ridingf,  ROT0,   "Taito America Corporation", "Riding Fight (Ver 1.0A)", GAME_NO_SOUND )
GAME( 1992, gseeker,  0,        f3_224b, f3, gseeker,  ROT90,  "Taito Corporation Japan",   "Grid Seeker: Project Storm Hammer (Ver 1.3O)", 0 )
GAME( 1992, gseekerj, gseeker,  f3_224b, f3, gseeker,  ROT90,  "Taito Corporation",         "Grid Seeker: Project Storm Hammer (Ver 1.3J)", 0 )
GAME( 1992, gseekeru, gseeker,  f3_224b, f3, gseeker,  ROT90,  "Taito America Corporation", "Grid Seeker: Project Storm Hammer (Ver 1.3A)", 0 )
GAME( 1992, commandw, 0,        f3_224b, f3, commandw, ROT0,   "Taito Corporation",         "Command War - Super Special Battle & War Game (Ver 0.0J) (Prototype)", GAME_IMPERFECT_GRAPHICS )
/* Most of the football games share some GFX roms but shouldn't be considered clones unless they have the same Taito game code for the program roms */
GAME( 1993, cupfinal, 0,        f3_224a, f3, cupfinal, ROT0,   "Taito Corporation Japan",   "Taito Cup Finals (Ver 1.0O 1993/02/28)", 0 )
GAME( 1993, hthero93, cupfinal, f3_224a, f3, cupfinal, ROT0,   "Taito Corporation",         "Hat Trick Hero '93 (Ver 1.0J 1993/02/28)", 0 )
GAME( 1993, trstar,   0,        f3,      f3, trstaroj, ROT0,   "Taito Corporation Japan",   "Top Ranking Stars (Ver 2.1O 1993/05/21) (New Version)", 0 )
GAME( 1993, trstarj,  trstar,   f3,      f3, trstaroj, ROT0,   "Taito Corporation",         "Top Ranking Stars (Ver 2.1J 1993/05/21) (New Version)", 0 )
GAME( 1993, prmtmfgt, trstar,   f3,      f3, trstaroj, ROT0,   "Taito America Corporation", "Prime Time Fighter (Ver 2.1A 1993/05/21) (New Version)", 0 )
GAME( 1993, trstaro,  trstar,   f3,      f3, trstaroj, ROT0,   "Taito Corporation Japan",   "Top Ranking Stars (Ver 2.1O 1993/05/21) (Old Version)", 0 )
GAME( 1993, trstaroj, trstar,   f3,      f3, trstaroj, ROT0,   "Taito Corporation",         "Top Ranking Stars (Ver 2.1J 1993/05/21) (Old Version)", 0 )
GAME( 1993, prmtmfgo, trstar,   f3,      f3, trstaroj, ROT0,   "Taito America Corporation", "Prime Time Fighter (Ver 2.1A 1993/05/21) (Old Version)", 0 )
GAME( 1993, gunlock,  0,        f3_224a, f3, gunlock,  ROT90,  "Taito Corporation Japan",   "Gunlock (Ver 2.3O 1994/01/20)", 0 )
GAME( 1993, rayforcj, gunlock,  f3_224a, f3, gunlock,  ROT90,  "Taito Corporation",         "Ray Force (Ver 2.3J 1994/01/20)", 0 )
GAME( 1993, rayforce, gunlock,  f3_224a, f3, gunlock,  ROT90,  "Taito America Corporation", "Ray Force (Ver 2.3A 1994/01/20)", 0 )
GAME( 1993, scfinals, 0,        f3_224a, f3, scfinals, ROT0,   "Taito Corporation Japan",   "Super Cup Finals (Ver 2.1O 1993/11/19)", 0 )
GAME( 1993, dungeonm, 0,        f3_224a, f3, lightbr,  ROT0,   "Taito Corporation Japan",   "Dungeon Magic (Ver 2.1O 1994/02/18)", 0 )
GAME( 1993, lightbr,  dungeonm, f3_224a, f3, lightbr,  ROT0,   "Taito Corporation",         "Light Bringer (Ver 2.1J 1994/02/18)", 0 )
GAME( 1993, dungenmu, dungeonm, f3_224a, f3, lightbr,  ROT0,   "Taito America Corporation", "Dungeon Magic (Ver 2.1A 1994/02/18)", 0 )
GAME( 1994, intcup94, 0,        f3_224a, f3, intcup94, ROT0,   "Taito Corporation Japan",   "International Cup '94 (Ver 2.2O 1994/05/26)", 0 )
GAME( 1994, hthero94, intcup94, f3_224a, f3, intcup94, ROT0,   "Taito America Corporation", "Hat Trick Hero '94 (Ver 2.2A 1994/05/26)", 0 )
GAME( 1994, kaiserkn, 0,        f3_224a, kn, kaiserkn, ROT0,   "Taito Corporation Japan",   "Kaiser Knuckle (Ver 2.1O 1994/07/29)", 0 )
GAME( 1994, kaiserkj, kaiserkn, f3_224a, kn, kaiserkn, ROT0,   "Taito Corporation",         "Kaiser Knuckle (Ver 2.1J 1994/07/29)", 0 )
GAME( 1994, gblchmp,  kaiserkn, f3_224a, kn, kaiserkn, ROT0,   "Taito America Corporation", "Global Champion (Ver 2.1A 1994/07/29)", 0 )
GAME( 1994, dankuga,  kaiserkn, f3_224a, kn, kaiserkn, ROT0,   "Taito Corporation",         "Dan-Ku-Ga (Ver 0.0J 1994/12/13) (Prototype)", 0 )
GAME( 1994, dariusg,  0,        f3,      f3, dariusg,  ROT0,   "Taito Corporation Japan",   "Darius Gaiden - Silver Hawk (Ver 2.5O 1994/09/19)", 0 )
GAME( 1994, dariusgj, dariusg,  f3,      f3, dariusg,  ROT0,   "Taito Corporation",         "Darius Gaiden - Silver Hawk (Ver 2.5J 1994/09/19)", 0 )
GAME( 1994, dariusgu, dariusg,  f3,      f3, dariusg,  ROT0,   "Taito America Corporation", "Darius Gaiden - Silver Hawk (Ver 2.5A 1994/09/19)", 0 )
GAME( 1994, dariusgx, dariusg,  f3,      f3, dariusg,  ROT0,   "Taito Corporation",         "Darius Gaiden - Silver Hawk Extra Version (Ver 2.7J 1995/03/06) (Official Hack)", 0 )
GAME( 1994, bublbob2, 0,        f3_224a, f3, bubsymph, ROT0,   "Taito Corporation Japan",   "Bubble Bobble II (Ver 2.5O 1994/10/05)", 0 )
GAME( 1994, bubsympe, bublbob2, f3_224a, f3, bubsymph, ROT0,   "Taito Corporation Japan",   "Bubble Symphony (Ver 2.5O 1994/10/05)", 0 )
GAME( 1994, bubsympu, bublbob2, f3_224a, f3, bubsymph, ROT0,   "Taito America Corporation", "Bubble Symphony (Ver 2.5A 1994/10/05)", 0 )
GAME( 1994, bubsymph, bublbob2, f3_224a, f3, bubsymph, ROT0,   "Taito Corporation",         "Bubble Symphony (Ver 2.5J 1994/10/05)", 0 )
GAME( 1994, spcinvdj, spacedx,  f3,      f3, spcinvdj, ROT0,   "Taito Corporation",         "Space Invaders DX (Ver 2.6J 1994/09/14) (F3 Version)", 0 )
GAME( 1994, pwrgoal,  0,        f3_224a, f3, hthero95, ROT0,   "Taito Corporation Japan",   "Taito Power Goal (Ver 2.5O 1994/11/03)", 0 )
GAME( 1994, hthero95, pwrgoal,  f3_224a, f3, hthero95, ROT0,   "Taito Corporation",         "Hat Trick Hero '95 (Ver 2.5J 1994/11/03)", 0 )
GAME( 1994, hthro95u, pwrgoal,  f3_224a, f3, hthero95, ROT0,   "Taito America Corporation", "Hat Trick Hero '95 (Ver 2.5A 1994/11/03)", 0 )
GAME( 1994, qtheater, 0,        f3_224c, f3, qtheater, ROT0,   "Taito Corporation",         "Quiz Theater - 3tsu no Monogatari (Ver 2.3J 1994/11/10)", GAME_IMPERFECT_SOUND )
GAME( 1994, elvactr,  0,        f3,      f3, elvactr,  ROT0,   "Taito Corporation Japan",   "Elevator Action Returns (Ver 2.2O 1995/02/20)", 0 )
GAME( 1994, elvactrj, elvactr,  f3,      f3, elvactr,  ROT0,   "Taito Corporation",         "Elevator Action Returns (Ver 2.2J 1995/02/20)", 0 )
GAME( 1994, elvact2u, elvactr,  f3,      f3, elvactr,  ROT0,   "Taito America Corporation", "Elevator Action II (Ver 2.2A 1995/02/20)", 0 )
/* There is also a prototype Elevator Action II (US) pcb with the graphics in a different rom format (same program code) */
GAME( 1994, recalh,   0,        f3,      f3, recalh,   ROT0,   "Taito Corporation",         "Recalhorn (Ver 1.42J 1994/5/11) (Prototype)", 0 )
GAME( 1995, spcinv95, 0,        f3_224a, f3, spcinv95, ROT270, "Taito Corporation Japan",   "Space Invaders '95: The Attack Of Lunar Loonies (Ver 2.5O 1995/06/14)", 0 )
GAME( 1995, spcnv95u, spcinv95, f3_224a, f3, spcinv95, ROT270, "Taito America Corporation", "Space Invaders '95: The Attack Of Lunar Loonies (Ver 2.5A 1995/06/14)", 0 )
GAME( 1995, akkanvdr, spcinv95, f3_224a, f3, spcinv95, ROT270, "Taito Corporation",         "Akkanbeder (Ver 2.5J 1995/06/14)", 0 )
GAME( 1995, twinqix,  0,        f3_224a, f3, twinqix,  ROT0,   "Taito America Corporation", "Twin Qix (Ver 1.0A 1995/01/17) (Prototype)", 0 )
GAME( 1995, quizhuhu, 0,        f3,      f3, quizhuhu, ROT0,   "Taito Corporation",         "Moriguchi Hiroko no Quiz de Hyuu!Hyuu! (Ver 2.2J 1995/05/25)", 0 )
GAME( 1995, pbobble2, 0,        f3,      f3, pbobble2, ROT0,   "Taito Corporation Japan",   "Puzzle Bobble 2 (Ver 2.2O 1995/07/20)", 0 )
GAME( 1995, pbobbl2j, pbobble2, f3,      f3, pbobble2, ROT0,   "Taito Corporation",         "Puzzle Bobble 2 (Ver 2.2J 1995/07/20)", 0 )
GAME( 1995, pbobbl2u, pbobble2, f3,      f3, pbobble2, ROT0,   "Taito America Corporation", "Bust-A-Move Again (Ver 2.3A 1995/07/31)", 0 )
GAME( 1995, pbobbl2x, pbobble2, f3,      f3, pbobbl2x, ROT0,   "Taito Corporation",         "Puzzle Bobble 2X (Ver 2.2J 1995/11/11)", 0 )
GAME( 1995, gekirido, 0,        f3,      f3, gekirido, ROT270, "Taito Corporation",         "Gekirindan (Ver 2.3J 1995/09/21)", 0 )
GAME( 1995, tcobra2,  0,        f3,      f3, ktiger2,  ROT270, "Taito Corporation Japan",   "Twin Cobra II (Ver 2.1O 1995/11/30)", 0 )
GAME( 1995, tcobra2u, tcobra2,  f3,      f3, ktiger2,  ROT270, "Taito America Corporation", "Twin Cobra II (Ver 2.1A 1995/11/30)", 0 )
GAME( 1995, ktiger2,  tcobra2,  f3,      f3, ktiger2,  ROT270, "Taito Corporation",         "Kyukyoku Tiger II (Ver 2.1J 1995/11/30)", 0 )
GAME( 1995, bubblem,  0,        f3_224a, f3, bubblem,  ROT0,   "Taito Corporation Japan",   "Bubble Memories: The Story Of Bubble Bobble III (Ver 2.4O 1996/02/15)", 0 )
GAME( 1995, bubblemj, bubblem,  f3_224a, f3, bubblem,  ROT0,   "Taito Corporation",         "Bubble Memories: The Story Of Bubble Bobble III (Ver 2.3J 1996/02/07)", 0 )
GAME( 1996, cleopatr, 0,        f3_224a, f3, cleopatr, ROT0,   "Taito Corporation",         "Cleopatra Fortune (Ver 2.1J 1996/09/05)", 0 )
GAME( 1996, pbobble3, 0,        f3,      f3, pbobble3, ROT0,   "Taito Corporation",         "Puzzle Bobble 3 (Ver 2.1O 1996/09/27)", 0 )
GAME( 1996, pbobbl3u, pbobble3, f3,      f3, pbobble3, ROT0,   "Taito Corporation",         "Puzzle Bobble 3 (Ver 2.1A 1996/09/27)", 0 )
GAME( 1996, pbobbl3j, pbobble3, f3,      f3, pbobble3, ROT0,   "Taito Corporation",         "Puzzle Bobble 3 (Ver 2.1J 1996/09/27)", 0 )
GAME( 1997, arkretrn, 0,        f3,      f3, arkretrn, ROT0,   "Taito Corporation",         "Arkanoid Returns (Ver 2.02J 1997/02/10)", 0 )
GAME( 1997, kirameki, 0,        f3_224a, f3, kirameki, ROT0,   "Taito Corporation",         "Kirameki Star Road (Ver 2.10J 1997/08/29)", 0 )
GAME( 1997, puchicar, 0,        f3,      f3, puchicar, ROT0,   "Taito Corporation",         "Puchi Carat (Ver 2.02O 1997/10/29)", 0 )
GAME( 1997, puchicrj, puchicar, f3,      f3, puchicar, ROT0,   "Taito Corporation",         "Puchi Carat (Ver 2.02J 1997/10/29)", 0 )
GAME( 1997, pbobble4, 0,        f3,      f3, pbobble4, ROT0,   "Taito Corporation",         "Puzzle Bobble 4 (Ver 2.04O 1997/12/19)", 0 )
GAME( 1997, pbobbl4j, pbobble4, f3,      f3, pbobble4, ROT0,   "Taito Corporation",         "Puzzle Bobble 4 (Ver 2.04J 1997/12/19)", 0 )
GAME( 1997, pbobbl4u, pbobble4, f3,      f3, pbobble4, ROT0,   "Taito Corporation",         "Puzzle Bobble 4 (Ver 2.04A 1997/12/19)", 0 )
GAME( 1997, popnpop,  0,        f3,      f3, popnpop,  ROT0,   "Taito Corporation",         "Pop'n Pop (Ver 2.07O 1998/02/09)", 0 )
GAME( 1997, popnpopj, popnpop,  f3,      f3, popnpop,  ROT0,   "Taito Corporation",         "Pop'n Pop (Ver 2.07J 1998/02/09)", 0 )
GAME( 1997, popnpopu, popnpop,  f3,      f3, popnpop,  ROT0,   "Taito Corporation",         "Pop'n Pop (Ver 2.07A 1998/02/09)", 0 )
GAME( 1998, landmakr, 0,        f3,      f3, landmakr, ROT0,   "Taito Corporation",         "Land Maker (Ver 2.01J 1998/06/01)", 0 )
GAME( 1998, landmkrp, landmakr, f3,      f3, landmkrp, ROT0,   "Taito Corporation",         "Land Maker (Ver 2.02O 1998/06/02) (Prototype)", 0 )
