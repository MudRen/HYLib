// /clone/board/yipin_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("ƽ�������԰�", ({ "board" }) );
	set("location", "/d/pingan/guangchang");
	set("board_id", "pingan_b");
	set("long", "����һ�������ֽ��������԰塣\n" );
	setup();
	set("capacity", 100);
	replace_program(BULLETIN_BOARD);
}

