# MAME 0.106 source snippet.

#define STV_PLAYER_INPUTS(_n_, _b1_, _b2_, _b3_, _b4_) \
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_##_b1_         ) PORT_PLAYER(_n_) \
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_##_b2_         ) PORT_PLAYER(_n_) \
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_##_b3_         ) PORT_PLAYER(_n_) \
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_##_b4_         ) PORT_PLAYER(_n_) \
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN  ) PORT_PLAYER(_n_) \
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_JOYSTICK_UP    ) PORT_PLAYER(_n_) \
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT ) PORT_PLAYER(_n_) \
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT  ) PORT_PLAYER(_n_)

INPUT_PORTS_START( stv )
	PORT_START
	PORT_DIPNAME( 0x01, 0x01, "PDR1" )
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

	PORT_START
	PORT_DIPNAME( 0x01, 0x01, "PDR2" )
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

	PORT_START
	STV_PLAYER_INPUTS(1, BUTTON1, BUTTON2, BUTTON3, BUTTON4)

	PORT_START
	STV_PLAYER_INPUTS(2, BUTTON1, BUTTON2, BUTTON3, BUTTON4)
/*
    PORT_START
    STV_PLAYER_INPUTS(3, BUTTON1, BUTTON2, BUTTON3, BUTTON4)

    PORT_START
    STV_PLAYER_INPUTS(4, BUTTON1, BUTTON2, BUTTON3, BUTTON4)
*/

	PORT_START
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_COIN1 )
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_COIN2 )
	PORT_BIT(0x04, IP_ACTIVE_LOW, IPT_SERVICE ) PORT_NAME(DEF_STR( Test )) PORT_CODE(KEYCODE_F2)
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_SERVICE1 )
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_START1 )
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_START2 )
	PORT_BIT(0x40, IP_ACTIVE_LOW, IPT_SERVICE ) PORT_NAME("1P Push Switch") PORT_CODE(KEYCODE_7)
	PORT_BIT(0x80, IP_ACTIVE_LOW, IPT_SERVICE ) PORT_NAME("2P Push Switch") PORT_CODE(KEYCODE_8)

	/*This *might* be unused...*/
	PORT_START
	PORT_BIT ( 0xff, IP_ACTIVE_LOW, IPT_UNUSED )

	/*Extra button layout,used by Power Instinct 3 & Suikoenbu*/
	PORT_START
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_BUTTON4 ) PORT_PLAYER(1)
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_BUTTON5 ) PORT_PLAYER(1)
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_BUTTON6 ) PORT_PLAYER(1)
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_BUTTON4 ) PORT_PLAYER(2)
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_BUTTON5 ) PORT_PLAYER(2)
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_BUTTON6 ) PORT_PLAYER(2)
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_UNUSED )

	/*We don't need these,AFAIK the country code doesn't work either...*/
	#if 0
	PORT_START							//7
	PORT_DIPNAME( 0x0f, 0x01, "Country" )
	PORT_DIPSETTING(    0x01, DEF_STR( Japan ) )
	PORT_DIPSETTING(    0x02, "Asia Ntsc" )
	PORT_DIPSETTING(    0x04, DEF_STR( USA ) )
	PORT_DIPSETTING(    0x08, "Sud America Ntsc" )
	PORT_DIPSETTING(    0x06, "Korea" )
	PORT_DIPSETTING(    0x0a, "Asia Pal" )
	PORT_DIPSETTING(    0x0c, "Europe/Other Pal" )
	PORT_DIPSETTING(    0x0d, "Sud America Pal" )

	PORT_START	/* Pad data 1a */
	PORT_BIT(0x01, IP_ACTIVE_HIGH, IPT_OTHER ) PORT_NAME("B") PORT_CODE(KEYCODE_U)
	PORT_BIT(0x02, IP_ACTIVE_HIGH, IPT_OTHER ) PORT_NAME("C") PORT_CODE(KEYCODE_Y)
	PORT_BIT(0x04, IP_ACTIVE_HIGH, IPT_OTHER ) PORT_NAME("A") PORT_CODE(KEYCODE_T)
	PORT_BIT(0x08, IP_ACTIVE_HIGH, IPT_OTHER ) PORT_NAME("Start") PORT_CODE(KEYCODE_O)
	PORT_BIT(0x10, IP_ACTIVE_HIGH, IPT_OTHER ) PORT_NAME("Up") PORT_CODE(KEYCODE_I)
	PORT_BIT(0x20, IP_ACTIVE_HIGH, IPT_OTHER ) PORT_NAME("Down") PORT_CODE(KEYCODE_K)
	PORT_BIT(0x40, IP_ACTIVE_HIGH, IPT_OTHER ) PORT_NAME("Left") PORT_CODE(KEYCODE_J)
	PORT_BIT(0x80, IP_ACTIVE_HIGH, IPT_OTHER ) PORT_NAME("Right") PORT_CODE(KEYCODE_L)

	PORT_START	/* Pad data 1b */
	PORT_BIT(0x08, IP_ACTIVE_HIGH, IPT_OTHER ) PORT_NAME("L trig") PORT_CODE(KEYCODE_A)
	PORT_BIT(0x10, IP_ACTIVE_HIGH, IPT_OTHER ) PORT_NAME("Z") PORT_CODE(KEYCODE_Q)
	PORT_BIT(0x20, IP_ACTIVE_HIGH, IPT_OTHER ) PORT_NAME("Y") PORT_CODE(KEYCODE_W)
	PORT_BIT(0x40, IP_ACTIVE_HIGH, IPT_OTHER ) PORT_NAME("X") PORT_CODE(KEYCODE_E)
	PORT_BIT(0x80, IP_ACTIVE_HIGH, IPT_OTHER ) PORT_NAME("R trig") PORT_CODE(KEYCODE_S)
	#endif
INPUT_PORTS_END

INPUT_PORTS_START( critcrsh )
	PORT_START /* 0 */
	PORT_DIPNAME( 0x01, 0x01, "PDR1" )
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

	PORT_START /* 1 */
	PORT_DIPNAME( 0x01, 0x01, "PDR2" )
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

	PORT_START /* 2 */
	STV_PLAYER_INPUTS(1, BUTTON1, BUTTON2, BUTTON3, BUTTON4)

	PORT_START /* 3 */
	STV_PLAYER_INPUTS(2, BUTTON1, BUTTON2, BUTTON3, BUTTON4)

	PORT_START /* 4 */
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_COIN1 )
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_COIN2 )
	PORT_BIT(0x04, IP_ACTIVE_LOW, IPT_SERVICE ) PORT_NAME(DEF_STR( Test )) PORT_CODE(KEYCODE_F2)
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_SERVICE1 )
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_START1 )
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_START2 )
	PORT_BIT(0x40, IP_ACTIVE_LOW, IPT_SERVICE ) PORT_NAME("1P Push Switch") PORT_CODE(KEYCODE_7)
	PORT_BIT(0x80, IP_ACTIVE_LOW, IPT_SERVICE ) PORT_NAME("2P Push Switch") PORT_CODE(KEYCODE_8)

	/*This *might* be unused...*/
	PORT_START /* 5 */
	PORT_BIT ( 0xff, IP_ACTIVE_LOW, IPT_UNUSED )

	/*Extra button layout,used by Power Instinct 3 & Suikoenbu*/
	PORT_START /* 6 */
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_BUTTON4 ) PORT_PLAYER(1)
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_BUTTON5 ) PORT_PLAYER(1)
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_BUTTON6 ) PORT_PLAYER(1)
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_BUTTON4 ) PORT_PLAYER(2)
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_BUTTON5 ) PORT_PLAYER(2)
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_BUTTON6 ) PORT_PLAYER(2)
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_UNUSED )

	/* IN 7 */
	PORT_START /* mask default type                     sens delta min max */
	PORT_BIT( 0x3f, 0x00, IPT_LIGHTGUN_X ) PORT_MINMAX(0,0x3f) PORT_SENSITIVITY(1) PORT_KEYDELTA(1) PORT_PLAYER(1)

	/* IN 8 */
	PORT_START
	PORT_BIT( 0x3f, 0x00, IPT_LIGHTGUN_Y ) PORT_MINMAX(0x0,0x3f) PORT_SENSITIVITY(1) PORT_KEYDELTA(1) PORT_PLAYER(1)

INPUT_PORTS_END

/*Same as the regular one,but with an additional & optional mahjong panel*/
INPUT_PORTS_START( stvmp )
	PORT_START
	PORT_DIPNAME( 0x01, 0x01, "PDR1" )
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

	PORT_START
	PORT_DIPNAME( 0x01, 0x01, "PDR2" )
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

	PORT_START
	STV_PLAYER_INPUTS(1, BUTTON1, BUTTON2, BUTTON3, BUTTON4)

	PORT_START
	STV_PLAYER_INPUTS(2, BUTTON1, BUTTON2, BUTTON3, BUTTON4)
/*
    PORT_START
    STV_PLAYER_INPUTS(3, BUTTON1, BUTTON2, BUTTON3, BUTTON4)

    PORT_START
    STV_PLAYER_INPUTS(4, BUTTON1, BUTTON2, BUTTON3, BUTTON4)
*/

	PORT_START
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_COIN1 )
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_COIN2 )
	PORT_BIT(0x04, IP_ACTIVE_LOW, IPT_SERVICE ) PORT_NAME(DEF_STR( Test )) PORT_CODE(KEYCODE_F2)
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_SERVICE1 )
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_START1 )
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_START2 )
	PORT_BIT(0x40, IP_ACTIVE_LOW, IPT_SERVICE ) PORT_NAME("1P Push Switch") PORT_CODE(KEYCODE_7)
	PORT_BIT(0x80, IP_ACTIVE_LOW, IPT_SERVICE ) PORT_NAME("2P Push Switch") PORT_CODE(KEYCODE_8)

	/*This *might* be unused...*/
	PORT_START
	PORT_BIT ( 0xff, IP_ACTIVE_LOW, IPT_UNUSED )

	/*Extra button layout,used by Power Instinct 3*/
	PORT_START
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_BUTTON4 ) PORT_PLAYER(1)
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_BUTTON5 ) PORT_PLAYER(1)
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_BUTTON6 ) PORT_PLAYER(1)
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_BUTTON4 ) PORT_PLAYER(2)
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_BUTTON5 ) PORT_PLAYER(2)
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_BUTTON6 ) PORT_PLAYER(2)
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_UNUSED )

	/*Mahjong panel/player 1 side*/
	PORT_START/*7*/
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_MAHJONG_KAN )
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_START1 )
	PORT_BIT ( 0x04, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT ( 0x08, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_MAHJONG_E )
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_MAHJONG_A )
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_MAHJONG_M )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_MAHJONG_I )

	PORT_START/*8*/
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_MAHJONG_RON )
	PORT_BIT ( 0x02, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT ( 0x04, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT ( 0x08, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_MAHJONG_F )
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_MAHJONG_B )
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_MAHJONG_N )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_MAHJONG_J )

	PORT_START/*9*/
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_MAHJONG_REACH )
	PORT_BIT ( 0x02, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT ( 0x04, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT ( 0x08, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_MAHJONG_G )
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_MAHJONG_C )
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_MAHJONG_CHI )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_MAHJONG_K )

	PORT_START/*10*/
	PORT_BIT ( 0x01, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT ( 0x02, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT ( 0x04, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT ( 0x08, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_MAHJONG_H )
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_MAHJONG_D )
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_MAHJONG_PON )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_MAHJONG_L )

	PORT_START/*11*/
	PORT_BIT ( 0x01, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT ( 0x02, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT ( 0x04, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT ( 0x08, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT ( 0x10, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT ( 0x20, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_MAHJONG_FLIP_FLOP )
	PORT_BIT ( 0x80, IP_ACTIVE_LOW, IPT_UNUSED )

	/*Mahjong panel/player 2 side*/
	PORT_START/*12*/
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_MAHJONG_KAN ) PORT_PLAYER(2)
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_START2 )
	PORT_BIT ( 0x04, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT ( 0x08, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_MAHJONG_E ) PORT_PLAYER(2)
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_MAHJONG_A ) PORT_PLAYER(2)
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_MAHJONG_M ) PORT_PLAYER(2)
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_MAHJONG_I ) PORT_PLAYER(2)

	PORT_START/*13*/
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_MAHJONG_RON ) PORT_PLAYER(2)
	PORT_BIT ( 0x02, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT ( 0x04, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT ( 0x08, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_MAHJONG_F ) PORT_PLAYER(2)
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_MAHJONG_B ) PORT_PLAYER(2)
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_MAHJONG_N ) PORT_PLAYER(2)
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_MAHJONG_J ) PORT_PLAYER(2)

	PORT_START/*14*/
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_MAHJONG_REACH ) PORT_PLAYER(2)
	PORT_BIT ( 0x02, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT ( 0x04, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT ( 0x08, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_MAHJONG_G ) PORT_PLAYER(2)
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_MAHJONG_C ) PORT_PLAYER(2)
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_MAHJONG_CHI ) PORT_PLAYER(2)
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_MAHJONG_K ) PORT_PLAYER(2)

	PORT_START/*15*/
	PORT_BIT ( 0x01, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT ( 0x02, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT ( 0x04, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT ( 0x08, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_MAHJONG_H ) PORT_PLAYER(2)
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_MAHJONG_D ) PORT_PLAYER(2)
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_MAHJONG_PON ) PORT_PLAYER(2)
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_MAHJONG_L ) PORT_PLAYER(2)

	PORT_START/*16*/
	PORT_BIT ( 0x01, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT ( 0x02, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT ( 0x04, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT ( 0x08, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT ( 0x10, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT ( 0x20, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_MAHJONG_FLIP_FLOP ) PORT_PLAYER(2)
	PORT_BIT ( 0x80, IP_ACTIVE_LOW, IPT_UNUSED )
INPUT_PORTS_END


/*
country codes:
J = Japan
U = United States
E = Europe
T = Taiwan
B = Brazil
K = Korea
A = PAL Asia
L = Latin America
date codes:
(Original is yyyy/mm/dd,changed to reflect Capcom's one (yy/mm/dd))
Version codes:
V = Version(obviously ;)
(number before the dot) = game status (0=Sample,1=Master,2=Upgrade)
(number after the dot) = game version/release
There is also another internal code (called the "Product Number"),but AFAIK it's only used
by introdon in ST-V ("SG0000000"),and according to the manual it's even wrong! (SG is used
by Sega titles,and this is a Sunsoft game)It's likely to be a left-over...
*/

GAMEB( 1996, stvbios,   0,       stvbios, stv, stv,  stv,       ROT0,   "Sega",                      "ST-V Bios", NOT_A_DRIVER )

//GBX   YEAR, NAME,      PARENT,  BIOS,    MACH,INP,  INIT,      MONITOR
/* Playable */
GAMEB( 1996, bakubaku,  stvbios, stvbios, stv, stv,  bakubaku,  ROT0,   "Sega",     				  "Baku Baku Animal (J 950407 V1.000)", GAME_NO_SOUND | GAME_IMPERFECT_GRAPHICS )
GAMEB( 1996, batmanfr,  stvbios, stvbios, stv, stv,  batmanfr,  ROT0,   "Acclaim",    				  "Batman Forever (JUE 960507 V1.000)", GAME_NO_SOUND | GAME_IMPERFECT_GRAPHICS )
GAMEB( 1996, colmns97,  stvbios, stvbios, stv, stv,  colmns97,  ROT0,   "Sega", 	 				  "Columns '97 (JET 961209 V1.000)", GAME_IMPERFECT_SOUND | GAME_IMPERFECT_GRAPHICS )
GAMEB( 1997, cotton2,   stvbios, stvbios, stv, stv,  cotton2,   ROT0,   "Success",  				  "Cotton 2 (JUET 970902 V1.000)", GAME_IMPERFECT_SOUND | GAME_IMPERFECT_GRAPHICS )
GAMEB( 1998, cottonbm,  stvbios, stvbios, stv, stv,  cottonbm,  ROT0,   "Success",  				  "Cotton Boomerang (JUET 980709 V1.000)", GAME_IMPERFECT_SOUND | GAME_IMPERFECT_GRAPHICS )
GAMEB( 1999, danchih,   stvbios, stvbios, stv, stvmp,danchih,   ROT0,   "Altron (Tecmo license)", 	  "Danchi de Hanafuoda (J 990607 V1.400)", GAME_IMPERFECT_SOUND | GAME_IMPERFECT_GRAPHICS )
GAMEB( 1996, diehard,   stvbios, stvbios, stv, stv,  diehard,   ROT0,   "Sega", 	 				  "Die Hard Arcade (UET 960515 V1.000)", GAME_NO_SOUND | GAME_IMPERFECT_GRAPHICS  )
GAMEB( 1996, dnmtdeka,  diehard, stvbios, stv, stv,  dnmtdeka,  ROT0,   "Sega", 	 				  "Dynamite Deka (J 960515 V1.000)", GAME_NO_SOUND | GAME_IMPERFECT_GRAPHICS  )
GAMEB( 1995, ejihon,    stvbios, stvbios, stv, stv,  ic13,      ROT0,   "Sega", 	 				  "Ejihon Tantei Jimusyo (J 950613 V1.000)", GAME_IMPERFECT_SOUND | GAME_IMPERFECT_GRAPHICS )
GAMEB( 1995, fhboxers,  stvbios, stvbios, stv, stv,  fhboxers,  ROT0,   "Sega", 	 				  "Funky Head Boxers (JUETBKAL 951218 V1.000)", GAME_NO_SOUND | GAME_IMPERFECT_GRAPHICS )
GAMEB( 1994, gaxeduel,  stvbios, stvbios, stv, stv,  gaxeduel,	ROT0,   "Sega", 	     			  "Golden Axe - The Duel (JUETL 950117 V1.000)", GAME_IMPERFECT_SOUND | GAME_IMPERFECT_GRAPHICS )
GAMEB( 1998, grdforce,  stvbios, stvbios, stv, stv,  grdforce,  ROT0,   "Success",  				  "Guardian Force (JUET 980318 V0.105)", GAME_IMPERFECT_SOUND | GAME_IMPERFECT_GRAPHICS )
GAMEB( 1996, groovef,   stvbios, stvbios, stv, stv,  groovef,   ROT0,   "Atlus",    				  "Power Instinct 3 - Groove On Fight (J 970416 V1.001)", GAME_IMPERFECT_SOUND | GAME_IMPERFECT_GRAPHICS )
GAMEB( 1998, hanagumi,  stvbios, stvbios, stv, stv,  hanagumi,  ROT0,   "Sega",     				  "Hanagumi Taisen Columns - Sakura Wars (J 971007 V1.010)", GAME_IMPERFECT_GRAPHICS | GAME_IMPERFECT_SOUND )
GAMEB( 1996, introdon,  stvbios, stvbios, stv, stv,  ic13,		ROT0,   "Sunsoft / Success", 		  "Karaoke Quiz Intro Don Don! (J 960213 V1.000)", GAME_IMPERFECT_SOUND | GAME_IMPERFECT_GRAPHICS )
GAMEB( 1995, kiwames,   stvbios, stvbios, stv, stvmp,ic13,      ROT0,   "Athena",   				  "Pro Mahjong Kiwame S (J 951020 V1.208)", GAME_IMPERFECT_SOUND | GAME_IMPERFECT_GRAPHICS )
GAMEB( 1997, maruchan,  stvbios, stvbios, stv, stv,  maruchan,  ROT0,   "Sega / Toyosuisan", 	      "Maru-Chan de Goo! (J 971216 V1.000)", GAME_IMPERFECT_SOUND | GAME_IMPERFECT_GRAPHICS )
GAMEB( 1995, mausuke,   stvbios, stvbios, stv, stv,  mausuke,   ROT0,   "Data East",				  "Mausuke no Ojama the World (J 960314 V1.000)", GAME_IMPERFECT_SOUND | GAME_IMPERFECT_GRAPHICS )
GAMEB( 1998, othellos,  stvbios, stvbios, stv, stv,  othellos,  ROT0,   "Success",  				  "Othello Shiyouyo (J 980423 V1.002)", GAME_IMPERFECT_SOUND | GAME_IMPERFECT_GRAPHICS )
GAMEB( 1995, pblbeach,  stvbios, stvbios, stv, stv,  pblbeach,  ROT0,   "T&E Soft",   				  "Pebble Beach - The Great Shot (JUE 950913 V0.990)", GAME_IMPERFECT_SOUND | GAME_IMPERFECT_GRAPHICS )
GAMEB( 1996, prikura,   stvbios, stvbios, stv, stv,  prikura,   ROT0,   "Atlus",    				  "Princess Clara Daisakusen (J 960910 V1.000)", GAME_IMPERFECT_SOUND | GAME_IMPERFECT_GRAPHICS )
GAMEB( 1996, puyosun,   stvbios, stvbios, stv, stv,  puyosun,   ROT0,   "Compile",  				  "Puyo Puyo Sun (J 961115 V0.001)", GAME_IMPERFECT_SOUND | GAME_IMPERFECT_GRAPHICS )
GAMEB( 1998, rsgun,     stvbios, stvbios, stv, stv,  rsgun,     ROT0,   "Treasure",   				  "Radiant Silvergun (JUET 980523 V1.000)", GAME_IMPERFECT_GRAPHICS | GAME_IMPERFECT_SOUND )
GAMEB( 1996, sassisu,   stvbios, stvbios, stv, stv,  sassisu,   ROT0,   "Sega", 	     			  "Taisen Tanto-R Sashissu!! (J 980216 V1.000)", GAME_NO_SOUND | GAME_IMPERFECT_GRAPHICS )
GAMEB( 1998, seabass,   stvbios, stvbios, stv, stv,  seabass,   ROT0,   "A wave inc. (Able license)","Sea Bass Fishing (JUET 971110 V0.001)", GAME_IMPERFECT_SOUND | GAME_IMPERFECT_GRAPHICS )
GAMEB( 1995, shanhigw,  stvbios, stvbios, stv, stv,  shanhigw,	ROT0,   "Sunsoft / Activision", 	  "Shanghai - The Great Wall / Shanghai Triple Threat (JUE 950623 V1.005)", GAME_IMPERFECT_SOUND | GAME_IMPERFECT_GRAPHICS )
GAMEB( 1997, shienryu,  stvbios, stvbios, stv, stv,  shienryu,  ROT270, "Warashi",  				  "Shienryu (JUET 961226 V1.000)", GAME_IMPERFECT_GRAPHICS | GAME_IMPERFECT_SOUND )
GAMEB( 1995, smleague,  stvbios, stvbios, stv, stv,  smleague,  ROT0,   "Sega", 	     			  "Super Major League (U 960108 V1.000)", GAME_IMPERFECT_SOUND | GAME_IMPERFECT_GRAPHICS )
GAMEB( 1995, finlarch,  smleague,stvbios, stv, stv,  finlarch,  ROT0,   "Sega", 	     			  "Final Arch (J 950714 V1.001)", GAME_IMPERFECT_SOUND | GAME_IMPERFECT_GRAPHICS )
GAMEB( 1998, sss,       stvbios, stvbios, stv, stv,  sss,       ROT0,   "Capcom / Cave / Victor",	  "Steep Slope Sliders (JUET 981110 V1.000)", GAME_IMPERFECT_SOUND | GAME_IMPERFECT_GRAPHICS )
GAMEB( 1995, sandor,    stvbios, stvbios, stv, stv,  sandor,    ROT0,   "Sega", 	     			  "Sando-R (J 951114 V1.000)", GAME_IMPERFECT_SOUND | GAME_IMPERFECT_GRAPHICS )
GAMEB( 1996, sokyugrt,  stvbios, stvbios, stv, stv,  sokyugrt,  ROT0,   "Raizing / 8ing",    		  "Soukyugurentai / Terra Diver (JUET 960821 V1.000)", GAME_IMPERFECT_SOUND | GAME_IMPERFECT_GRAPHICS )
GAMEB( 1995, suikoenb,  stvbios, stvbios, stv, stv,  suikoenb,  ROT0,   "Data East",  				  "Suikoenbu (J 950314 V2.001)", GAME_IMPERFECT_SOUND | GAME_IMPERFECT_GRAPHICS )
GAMEB( 1995, thunt,     sandor,  stvbios, stv, stv,  thunt,     ROT0,   "Sega (Deniam license?)",	  "Treasure Hunt (JUET 970901 V2.00E)", GAME_IMPERFECT_SOUND | GAME_IMPERFECT_GRAPHICS )
GAMEB( 1996, vfkids,    stvbios, stvbios, stv, stv,  ic13,      ROT0,   "Sega", 	 				  "Virtua Fighter Kids (JUET 960319 V0.000)", GAME_NO_SOUND | GAME_IMPERFECT_GRAPHICS )
GAMEB( 1997, winterht,  stvbios, stvbios, stv, stv,  winterht,  ROT0,   "Sega", 	 				  "Winter Heat (JUET 971012 V1.000)", GAME_IMPERFECT_SOUND | GAME_IMPERFECT_GRAPHICS )

/* Almost */
GAMEB( 1997, vmahjong,  stvbios, stvbios, stv, stvmp,stv,       ROT0,   "Micronet",   				  "Virtual Mahjong (J 961214 V1.000)", GAME_IMPERFECT_SOUND | GAME_IMPERFECT_GRAPHICS )
GAMEB( 1998, myfairld,  stvbios, stvbios, stv, stvmp,stv,       ROT0,   "Micronet",   				  "Virtual Mahjong 2 - My Fair Lady (J 980608 V1.000)", GAME_NO_SOUND | GAME_IMPERFECT_GRAPHICS | GAME_NOT_WORKING )
GAMEB( 1998, astrass,   stvbios, stvbios, stv, stv,  astrass,   ROT0,   "Sunsoft",    				  "Astra SuperStars (J 980514 V1.002)", GAME_UNEMULATED_PROTECTION | GAME_IMPERFECT_GRAPHICS | GAME_IMPERFECT_SOUND )
GAMEB( 1998, twcup98,   stvbios, stvbios, stv, stv,  twcup98,   ROT0,   "Tecmo",      				  "Tecmo World Cup '98 (JUET 980410 V1.000)", GAME_UNEMULATED_PROTECTION | GAME_IMPERFECT_SOUND | GAME_IMPERFECT_GRAPHICS|GAME_NOT_WORKING ) // player movement
GAMEB( 1997, znpwfv,    stvbios, stvbios, stv, stv,  znpwfv,    ROT0,   "Sega", 	     			  "Zen Nippon Pro-Wrestling Featuring Virtua (J 971123 V1.000)", GAME_IMPERFECT_SOUND | GAME_IMPERFECT_GRAPHICS )

GAMEB( 1995, critcrsh,  stvbios, stvbios, critcrsh, critcrsh, ic13, ROT0, "Sega", 	     			  "Critter Crusher (EA 951204 V1.000)", GAME_IMPERFECT_SOUND | GAME_IMPERFECT_GRAPHICS | GAME_NOT_WORKING )

/* Doing Something.. but not enough yet */
GAMEB( 1998, elandore,  stvbios, stvbios, stv, stv,  elandore,  ROT0,   "Sai-Mate",   				  "Elan Doree - Legend of Dragon (JUET 980922 V1.006)", GAME_UNEMULATED_PROTECTION | GAME_IMPERFECT_SOUND | GAME_NOT_WORKING )//japanese name?
GAMEB( 1995, vfremix,   stvbios, stvbios, stv, stv,  vfremix,   ROT0,   "Sega", 	     			  "Virtua Fighter Remix (JUETBKAL 950428 V1.000)", GAME_IMPERFECT_SOUND | GAME_NOT_WORKING )
GAMEB( 1996, findlove,  stvbios, stvbios, stv, stv,  ic13,      ROT0,   "Daiki / FCF",    			  "Find Love (J 971212 V1.000)", GAME_IMPERFECT_SOUND | GAME_NOT_WORKING )
GAMEB( 1995, decathlt,  stvbios, stvbios, stv, stv,  ic13,  	 ROT0,   "Sega", 	     			  "Decathlete (JUET 960424 V1.000)", GAME_NO_SOUND | GAME_NOT_WORKING | GAME_UNEMULATED_PROTECTION )

/* not working,black screen */
GAMEB( 1999, ffreveng,  stvbios, stvbios, stv, stv,  stv,       ROT0,   "Capcom",     				  "Final Fight Revenge (JUET 990714 V1.000)", GAME_UNEMULATED_PROTECTION | GAME_NO_SOUND | GAME_NOT_WORKING )
/* CD games */
GAMEB( 1995, sfish2,    0,       stvbios, stv, stv,  sfish2,    ROT0,   "Sega",	     			  "Sport Fishing 2 (UET 951106 V1.10e)", GAME_NO_SOUND | GAME_NOT_WORKING )
GAMEB( 1995, sfish2j,   sfish2,  stvbios, stv, stv,  sfish2j,   ROT0,   "Sega",	     			  "Sport Fishing 2 (J 951201 V1.100)", GAME_NO_SOUND | GAME_NOT_WORKING )

/*
This is the known list of undumped ST-V games:
    Kiss Off (US version of mausuke)
    Outlaws of the Lost Dynasty (US version of suikoenb)
    Baku Baku (US version of Baku Baku Animal,dunno if it exists for the ST-V)
    Sport Fishing
    Aroma Club
    Movie Club
    Name Club
    NBA Action (?)
    Quiz Omaeni Pipon Cho! (?)

Others may exist as well...
*/
