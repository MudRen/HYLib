// /clone/board/bonze_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("���ŵ������԰�", ({ "board" }) );
	set("location", "/d/tangmen/liujiantang");
	set("board_id", "tangmen_b");
	set("long", "����һ�������ŵ��ӽ��������԰塣\n" );
	setup();
	set("capacity", 100);
	replace_program(BULLETIN_BOARD);
}
