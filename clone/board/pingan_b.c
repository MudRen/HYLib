// /clone/board/pingan.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("ƽ�������԰�", ({ "board" }) );
	set("location", "/d/pingan/pinganguangchang");
	set("board_id", "pingan_b");
	set("long", "��ƽ�������Ҹ����֡�\n" );
	setup();
	set("capacity", 100);
	replace_program(BULLETIN_BOARD);
}

