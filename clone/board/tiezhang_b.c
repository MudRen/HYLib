// /clone/board/baituo_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("���ư�������԰�", ({ "board" }) );
	set("location", "/d/tiezhang/guangchang");
	set("board_id", "tiezhang_b");
	set("long", "����һ�������ư���ӽ��������԰塣\n" );
	setup();
	set("capacity", 100);
	replace_program(BULLETIN_BOARD);
}
