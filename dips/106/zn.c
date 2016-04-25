# MAME 0.106 source snippet.

INPUT_PORTS_START( zn )
	PORT_START		/* IN0 */
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_JOYSTICK_UP ) PORT_8WAY PORT_PLAYER(1)
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN ) PORT_8WAY PORT_PLAYER(1)
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT ) PORT_8WAY PORT_PLAYER(1)
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT ) PORT_8WAY PORT_PLAYER(1)
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_PLAYER(1)
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_BUTTON2 ) PORT_PLAYER(1)
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_BUTTON3 ) PORT_PLAYER(1)
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_UNKNOWN )

	PORT_START		/* IN1 */
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_JOYSTICK_UP ) PORT_8WAY PORT_PLAYER(2)
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN ) PORT_8WAY PORT_PLAYER(2)
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT ) PORT_8WAY PORT_PLAYER(2)
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT ) PORT_8WAY PORT_PLAYER(2)
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_PLAYER(2)
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_BUTTON2 ) PORT_PLAYER(2)
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_BUTTON3 ) PORT_PLAYER(2)
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_UNKNOWN )

	PORT_START		/* IN2 */
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_OTHER ) PORT_NAME("Test Switch") PORT_CODE(KEYCODE_F2)
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_SERVICE1 )
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_TILT )
	PORT_BIT( 0xf8, IP_ACTIVE_LOW, IPT_UNKNOWN )

	PORT_START		/* IN3 */
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_START1 )
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_START2 )
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_COIN1 )
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_COIN2 )
	PORT_BIT( 0xcc, IP_ACTIVE_LOW, IPT_UNKNOWN )

	PORT_START		/* IN4 */
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_BUTTON4 )
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_BUTTON5 )
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_BUTTON6 )
	PORT_BIT( 0x8f, IP_ACTIVE_LOW, IPT_UNKNOWN )

	PORT_START		/* IN5 */
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_BUTTON4 ) PORT_PLAYER(2)
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_BUTTON5 ) PORT_PLAYER(2)
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_BUTTON6 ) PORT_PLAYER(2)
	PORT_BIT( 0x8f, IP_ACTIVE_LOW, IPT_UNKNOWN )

	PORT_START		/* IN6 */
	PORT_BIT( 0xff, IP_ACTIVE_LOW, IPT_UNKNOWN )

	PORT_START		/* IN7 */
	PORT_DIPNAME( 0x01, 0x01, "Freeze" )
	PORT_DIPSETTING(    0x01, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x02, 0x02, DEF_STR( Service_Mode ) )
	PORT_DIPSETTING(    0x02, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x04, 0x04, DEF_STR( Unknown ) )
	PORT_DIPSETTING(    0x04, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
	PORT_DIPNAME( 0x08, 0x08, DEF_STR( Unknown ) )
	PORT_DIPSETTING(    0x08, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )
INPUT_PORTS_END


/* Capcom ZN1 */

/* A dummy driver, so that the bios can be debugged, and to serve as */
/* parent for the coh-1000c.353 file, so that we do not have to include */
/* it in every zip file */
GAME( 1995, cpzn1,    0,        coh1000c, zn, coh1000c, ROT0, "Sony/Capcom", "ZN1", NOT_A_DRIVER )

GAME( 1995, ts2,      cpzn1,    coh1000c, zn, coh1000c, ROT0, "Capcom/Takara", "Battle Arena Toshinden 2 (USA 951124)", GAME_IMPERFECT_GRAPHICS | GAME_IMPERFECT_SOUND )
GAME( 1995, ts2j,     ts2,      coh1000c, zn, coh1000c, ROT0, "Capcom/Takara", "Battle Arena Toshinden 2 (JAPAN 951124)", GAME_IMPERFECT_GRAPHICS | GAME_IMPERFECT_SOUND )
GAME( 1996, starglad, cpzn1,    coh1000c, zn, coh1000c, ROT0, "Capcom", "Star Gladiator (USA 960627)", GAME_IMPERFECT_GRAPHICS | GAME_IMPERFECT_SOUND )
GAME( 1996, sfex,     cpzn1,    coh1002c, zn, coh1000c, ROT0, "Capcom/Arika", "Street Fighter EX (USA 961219)", GAME_IMPERFECT_GRAPHICS | GAME_IMPERFECT_SOUND )
GAME( 1996, sfexa,    sfex,     coh1002c, zn, coh1000c, ROT0, "Capcom/Arika", "Street Fighter EX (ASIA 961219)", GAME_IMPERFECT_GRAPHICS | GAME_IMPERFECT_SOUND )
GAME( 1996, sfexj,    sfex,     coh1002c, zn, coh1000c, ROT0, "Capcom/Arika", "Street Fighter EX (JAPAN 961130)", GAME_IMPERFECT_GRAPHICS | GAME_IMPERFECT_SOUND )
GAME( 1996, glpracr,  cpzn1,    coh1000c, zn, coh1000c, ROT0, "Tecmo", "Gallop Racer (JAPAN Ver 9.01.12)", GAME_IMPERFECT_GRAPHICS | GAME_IMPERFECT_SOUND )
GAME( 1997, sfexp,    cpzn1,    coh1002c, zn, coh1000c, ROT0, "Capcom/Arika", "Street Fighter EX Plus (USA 970407)", GAME_IMPERFECT_GRAPHICS | GAME_IMPERFECT_SOUND )
GAME( 1997, sfexpu1,  sfexp,    coh1002c, zn, coh1000c, ROT0, "Capcom/Arika", "Street Fighter EX Plus (USA 970311)", GAME_IMPERFECT_GRAPHICS | GAME_IMPERFECT_SOUND )
GAME( 1997, sfexpj,   sfexp,    coh1002c, zn, coh1000c, ROT0, "Capcom/Arika", "Street Fighter EX Plus (JAPAN 970311)", GAME_IMPERFECT_GRAPHICS | GAME_IMPERFECT_SOUND )

/* Capcom ZN2 */

/* A dummy driver, so that the bios can be debugged, and to serve as */
/* parent for the coh-3002c.353 file, so that we do not have to include */
/* it in every zip file */
GAME( 1997, cpzn2,    0,        coh3002c, zn, coh3002c, ROT0, "Sony/Capcom", "ZN2", NOT_A_DRIVER )

GAME( 1997, rvschool, cpzn2,    coh3002c, zn, coh3002c, ROT0, "Capcom", "Rival Schools (USA 971117)", GAME_IMPERFECT_GRAPHICS | GAME_IMPERFECT_SOUND )
GAME( 1997, rvschola, rvschool, coh3002c, zn, coh3002c, ROT0, "Capcom", "Rival Schools (ASIA 971117)", GAME_IMPERFECT_GRAPHICS | GAME_IMPERFECT_SOUND )
GAME( 1997, jgakuen,  rvschool, coh3002c, zn, coh3002c, ROT0, "Capcom", "Justice Gakuen (JAPAN 971117)", GAME_IMPERFECT_GRAPHICS | GAME_IMPERFECT_SOUND )
GAME( 1998, sfex2,    cpzn2,    coh3002c, zn, coh3002c, ROT0, "Capcom/Arika", "Street Fighter EX 2 (USA 980526)", GAME_IMPERFECT_GRAPHICS | GAME_IMPERFECT_SOUND )
GAME( 1998, sfex2j,   sfex2,    coh3002c, zn, coh3002c, ROT0, "Capcom/Arika", "Street Fighter EX 2 (JAPAN 980312)", GAME_IMPERFECT_GRAPHICS | GAME_IMPERFECT_SOUND )
GAME( 1998, sfex2a,   sfex2,    coh3002c, zn, coh3002c, ROT0, "Capcom/Arika", "Street Fighter EX 2 (ASIA 980312)", GAME_IMPERFECT_GRAPHICS | GAME_IMPERFECT_SOUND )
GAME( 1998, plsmaswd, cpzn2,    coh3002c, zn, coh3002c, ROT0, "Capcom", "Plasma Sword (USA 980316)", GAME_IMPERFECT_GRAPHICS | GAME_IMPERFECT_SOUND )
GAME( 1998, stargld2, plsmaswd, coh3002c, zn, coh3002c, ROT0, "Capcom", "Star Gladiator 2 (JAPAN 980316)", GAME_IMPERFECT_GRAPHICS | GAME_IMPERFECT_SOUND )
GAME( 1998, plsmswda, plsmaswd, coh3002c, zn, coh3002c, ROT0, "Capcom", "Plasma Sword (ASIA 980316)", GAME_IMPERFECT_GRAPHICS | GAME_IMPERFECT_SOUND )
GAME( 1998, tgmj,     cpzn2,    coh3002c, zn, coh3002c, ROT0, "Capcom/Arika", "Tetris The Grand Master (JAPAN 980710)", GAME_IMPERFECT_GRAPHICS | GAME_IMPERFECT_SOUND )
GAME( 1998, techromn, cpzn2,    coh3002c, zn, coh3002c, ROT0, "Capcom", "Tech Romancer (EURO 980914)", GAME_IMPERFECT_GRAPHICS | GAME_IMPERFECT_SOUND )
GAME( 1998, techromu, techromn, coh3002c, zn, coh3002c, ROT0, "Capcom", "Tech Romancer (USA 980914)", GAME_IMPERFECT_GRAPHICS | GAME_IMPERFECT_SOUND )
GAME( 1998, kikaioh,  techromn, coh3002c, zn, coh3002c, ROT0, "Capcom", "Kikaioh (JAPAN 980914)", GAME_IMPERFECT_GRAPHICS | GAME_IMPERFECT_SOUND )
GAME( 1999, sfex2p,   cpzn2,    coh3002c, zn, coh3002c, ROT0, "Capcom/Arika", "Street Fighter EX 2 Plus (USA 990611)", GAME_IMPERFECT_GRAPHICS | GAME_IMPERFECT_SOUND )
GAME( 1999, sfex2pa,  sfex2p,   coh3002c, zn, coh3002c, ROT0, "Capcom/Arika", "Street Fighter EX 2 Plus (ASIA 990611)", GAME_IMPERFECT_GRAPHICS | GAME_IMPERFECT_SOUND )
GAME( 1999, sfex2pj,  sfex2p,   coh3002c, zn, coh3002c, ROT0, "Capcom/Arika", "Street Fighter EX 2 Plus (JAPAN 990611)", GAME_IMPERFECT_GRAPHICS | GAME_IMPERFECT_SOUND )
GAME( 1999, strider2, cpzn2,    coh3002c, zn, coh3002c, ROT0, "Capcom", "Strider 2 (USA 991213)", GAME_IMPERFECT_GRAPHICS | GAME_IMPERFECT_SOUND )
GAME( 1999, stridr2a, strider2, coh3002c, zn, coh3002c, ROT0, "Capcom", "Strider 2 (ASIA 991213)", GAME_IMPERFECT_GRAPHICS | GAME_IMPERFECT_SOUND )
GAME( 1999, shiryu2,  strider2, coh3002c, zn, coh3002c, ROT0, "Capcom", "Strider Hiryu 2 (JAPAN 991213)", GAME_IMPERFECT_GRAPHICS | GAME_IMPERFECT_SOUND )

/* Atari */

/* A dummy driver, so that the bios can be debugged, and to serve as */
/* parent for the coh-1000w.353 file, so that we do not have to include */
/* it in every zip file */
GAME( 1996, atpsx,    0,        coh1000w, zn, coh1000w, ROT0, "Atari", "Atari PSX", NOT_A_DRIVER )

GAME( 1996, primrag2, atpsx,    coh1000w, zn, coh1000w, ROT0, "Atari", "Primal Rage 2 (Ver 0.36a)", GAME_IMPERFECT_GRAPHICS | GAME_IMPERFECT_SOUND | GAME_NOT_WORKING )

/* Acclaim */

/* A dummy driver, so that the bios can be debugged, and to serve as */
/* parent for the coh-1000a.353 file, so that we do not have to include */
/* it in every zip file */
GAME( 1995, acpsx,    0,        coh1000a, zn, coh1000a, ROT0, "Acclaim", "Acclaim PSX", NOT_A_DRIVER )

GAME( 1996, nbajamex, acpsx,    coh1000a, zn, coh1000a, ROT0, "Acclaim", "NBA Jam Extreme", GAME_IMPERFECT_GRAPHICS | GAME_IMPERFECT_SOUND | GAME_NOT_WORKING )
GAME( 1996, jdredd,   acpsx,    coh1000a, zn, coh1000a, ROT0, "Acclaim", "Judge Dredd (Rev C Dec. 17 1997)", GAME_IMPERFECT_GRAPHICS | GAME_IMPERFECT_SOUND | GAME_NOT_WORKING )
GAME( 1996, jdreddb,  jdredd,   coh1000a, zn, coh1000a, ROT0, "Acclaim", "Judge Dredd (Rev B Nov. 26 1997)", GAME_IMPERFECT_GRAPHICS | GAME_IMPERFECT_SOUND | GAME_NOT_WORKING )

/* Tecmo */

/* A dummy driver, so that the bios can be debugged, and to serve as */
/* parent for the coh-1002m.353 file, so that we do not have to include */
/* it in every zip file */
GAME( 1997, tps,      0,        coh1002m, zn, coh1002m, ROT0, "Sony/Tecmo", "TPS", NOT_A_DRIVER )

GAME( 1997, glpracr2, tps,      coh1002m, zn, coh1002m, ROT0, "Tecmo", "Gallop Racer 2 (USA)", GAME_IMPERFECT_GRAPHICS | GAME_IMPERFECT_SOUND | GAME_NOT_WORKING )
GAME( 1997, glprac2j, glpracr2, coh1002m, zn, coh1002m, ROT0, "Tecmo", "Gallop Racer 2 (JAPAN)", GAME_IMPERFECT_GRAPHICS | GAME_IMPERFECT_SOUND | GAME_NOT_WORKING )
GAME( 1997, glprac2l, glpracr2, coh1002ml,zn, coh1002m, ROT0, "Tecmo", "Gallop Racer 2 Link HW (JAPAN)", GAME_IMPERFECT_GRAPHICS | GAME_IMPERFECT_SOUND | GAME_NOT_WORKING )
GAME( 1998, doapp,    tps,      coh1002m, zn, coh1002m, ROT0, "Tecmo", "Dead Or Alive ++ (JAPAN)", GAME_IMPERFECT_GRAPHICS | GAME_IMPERFECT_SOUND )
GAME( 1998, cbaj,     tps,      coh1002msnd, zn, coh1002m, ROT0, "Tecmo", "Cool Boarders Arcade Jam", GAME_IMPERFECT_GRAPHICS | GAME_IMPERFECT_SOUND )
GAME( 1998, shngmtkb, tps,      coh1002m, zn, coh1002m, ROT0, "Sunsoft / Activision", "Shanghai Matekibuyuu", GAME_IMPERFECT_GRAPHICS | GAME_IMPERFECT_SOUND )
GAME( 1999, tondemo,  tps,      coh1002m, zn, coh1002m, ROT0, "Tecmo", "Tondemo Crisis (JAPAN)", GAME_IMPERFECT_GRAPHICS | GAME_IMPERFECT_SOUND )
GAME( 1999, glpracr3, tps,      coh1002m, zn, coh1002m, ROT0, "Tecmo", "Gallop Racer 3 (JAPAN)", GAME_IMPERFECT_GRAPHICS | GAME_IMPERFECT_SOUND )
GAME( 1999, flamegun, tps,      coh1002m, zn, coh1002m, ROT0, "GAPS Inc.", "Flame Gunner", GAME_IMPERFECT_GRAPHICS | GAME_IMPERFECT_SOUND )
GAME( 1999, flameguj, flamegun, coh1002m, zn, coh1002m, ROT0, "GAPS Inc.", "Flame Gunner (Japan)", GAME_IMPERFECT_GRAPHICS | GAME_IMPERFECT_SOUND )
GAME( 2000, tecmowcm, tps,      coh1002m, zn, coh1002m, ROT0, "Tecmo", "Tecmo World Cup Millennium (JAPAN)", GAME_IMPERFECT_GRAPHICS | GAME_IMPERFECT_SOUND )
GAME( 2001, mfjump,   tps,      coh1002m, zn, coh1002m, ROT0, "Tecmo", "Monster Farm Jump (JAPAN)", GAME_IMPERFECT_GRAPHICS | GAME_IMPERFECT_SOUND )

/* Video System */

/* only one game dumped on this system, so coh-1002v.353 is included in the game zip file */
GAME( 1996, sncwgltd, 0,        coh1002v, zn, coh1002v, ROT270, "Video System", "Sonic Wings Limited (JAPAN)", GAME_IMPERFECT_GRAPHICS | GAME_IMPERFECT_SOUND )

/* Taito */

/* A dummy driver, so that the bios can be debugged, and to serve as */
/* parent for the coh-1000t.353 file, so that we do not have to include */
/* it in every zip file */
GAME( 1995, taitofx1, 0,        coh1000ta,zn, coh1000ta, ROT0, "Sony/Taito", "Taito FX1", NOT_A_DRIVER )

GAME( 1995, sfchamp,  taitofx1, coh1000ta,zn, coh1000ta, ROT0, "Taito", "Super Football Champ (Ver 2.5O)", GAME_IMPERFECT_GRAPHICS | GAME_IMPERFECT_SOUND | GAME_NOT_WORKING )
GAME( 1995, sfchampj, sfchamp,  coh1000ta,zn, coh1000ta, ROT0, "Taito", "Super Football Champ (Ver 2.4J)", GAME_IMPERFECT_GRAPHICS | GAME_IMPERFECT_SOUND | GAME_NOT_WORKING )
GAME( 1995, psyforce, taitofx1, coh1000ta,zn, coh1000ta, ROT0, "Taito", "Psychic Force (Ver 2.4O)", GAME_IMPERFECT_GRAPHICS | GAME_IMPERFECT_SOUND )
GAME( 1995, psyforcj, psyforce, coh1000ta,zn, coh1000ta, ROT0, "Taito", "Psychic Force (Ver 2.4J)", GAME_IMPERFECT_GRAPHICS | GAME_IMPERFECT_SOUND )
GAME( 1995, psyfrcex, psyforce, coh1000ta,zn, coh1000ta, ROT0, "Taito", "Psychic Force EX (Ver 2.0J)", GAME_IMPERFECT_GRAPHICS | GAME_IMPERFECT_SOUND )
GAME( 1996, mgcldate, mgcldtex, coh1000ta,zn, coh1000ta, ROT0, "Taito", "Magical Date / Magical Date - dokidoki kokuhaku daisakusen (Ver 2.02J)", GAME_IMPERFECT_GRAPHICS | GAME_IMPERFECT_SOUND | GAME_NOT_WORKING )
GAME( 1996, raystorm, taitofx1, coh1000tb,zn, coh1000tb, ROT0, "Taito", "Ray Storm (Ver 2.06A)", GAME_IMPERFECT_GRAPHICS | GAME_IMPERFECT_SOUND )
GAME( 1996, raystorj, raystorm, coh1000tb,zn, coh1000tb, ROT0, "Taito", "Ray Storm (Ver 2.05J)", GAME_IMPERFECT_GRAPHICS | GAME_IMPERFECT_SOUND )
GAME( 1996, ftimpact, taitofx1, coh1000tb,zn, coh1000tb, ROT0, "Taito", "Fighters' Impact (Ver 2.02O)", GAME_IMPERFECT_GRAPHICS | GAME_IMPERFECT_SOUND | GAME_NOT_WORKING )
GAME( 1996, ftimpcta, ftimpact, coh1000tb,zn, coh1000tb, ROT0, "Taito", "Fighters' Impact A (Ver 2.00J)", GAME_IMPERFECT_GRAPHICS | GAME_IMPERFECT_SOUND | GAME_NOT_WORKING )
GAME( 1997, mgcldtex, taitofx1, coh1000ta,zn, coh1000ta, ROT0, "Taito", "Magical Date EX / Magical Date - sotsugyou kokuhaku daisakusen (Ver 2.01J)", GAME_IMPERFECT_GRAPHICS | GAME_IMPERFECT_SOUND )
GAME( 1997, gdarius,  taitofx1, coh1000tb,zn, coh1000tb, ROT0, "Taito", "G-Darius (Ver 2.01J)", GAME_IMPERFECT_GRAPHICS | GAME_IMPERFECT_SOUND )
GAME( 1997, gdariusb, gdarius,  coh1000tb,zn, coh1000tb, ROT0, "Taito", "G-Darius (Ver 2.02A)", GAME_IMPERFECT_GRAPHICS | GAME_IMPERFECT_SOUND )
GAME( 1997, gdarius2, gdarius,  coh1000tb,zn, coh1000tb, ROT0, "Taito", "G-Darius Ver.2 (Ver 2.03J)", GAME_IMPERFECT_GRAPHICS | GAME_IMPERFECT_SOUND )

/* A dummy driver, so that the bios can be debugged, and to serve as */
/* parent for the coh-3002t.353 file, so that we do not have to include */
/* it in every zip file */
GAME( 1997, taitogn,  0,        coh3002t, zn, coh3002t, ROT0, "Sony/Taito", "Taito GNET", 0 )

/* Eighting/Raizing */

/* A dummy driver, so that the bios can be debugged, and to serve as */
/* parent for the coh-1002e.353 file, so that we do not have to include */
/* it in every zip file */
GAME( 1997, psarc95,  0,        coh1002e, zn, coh1002e, ROT0, "Sony/Eighting/Raizing", "PS Arcade 95", NOT_A_DRIVER )

GAME( 1997, beastrzr, psarc95,  coh1002e, zn, coh1002e, ROT0, "Eighting/Raizing", "Beastorizer (USA)", GAME_IMPERFECT_GRAPHICS | GAME_IMPERFECT_SOUND )
GAME( 1997, beastrzb, psarc95,  coh1002e, zn, coh1002e, ROT0, "Eighting/Raizing", "Beastorizer (USA Bootleg)", GAME_IMPERFECT_GRAPHICS | GAME_IMPERFECT_SOUND )
GAME( 1998, bldyror2, psarc95,  coh1002e, zn, coh1002e, ROT0, "Eighting/Raizing", "Bloody Roar 2 (JAPAN)", GAME_IMPERFECT_GRAPHICS | GAME_IMPERFECT_SOUND )
GAME( 2000, brvblade, tps,      coh1002e, zn, coh1002e, ROT270, "Eighting/Raizing", "Brave Blade (JAPAN)", GAME_IMPERFECT_GRAPHICS | GAME_IMPERFECT_SOUND )

/* Atlus */

/* A dummy driver, so that the bios can be debugged, and to serve as */
/* parent for the coh-1002l.353 file, so that we do not have to include */
/* it in every zip file */
GAME( 1996, atluspsx,  0,       coh1001l, zn, coh1001l, ROT0, "Sony/Atlus", "Atlus PSX", NOT_A_DRIVER )

GAME( 1996, hvnsgate, atluspsx, coh1001l, zn, coh1001l, ROT0, "Atlus/RACDYM", "Heaven's Gate", GAME_IMPERFECT_GRAPHICS | GAME_IMPERFECT_SOUND )
