// /clone/board/bonze_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("�����������������԰�", ({ "board" }) );
	set("location", "/d/feitian/daochang");
	set("board_id", "feitian_b");
	set("long", "����һ�����������������ӽ��������԰塣\n" );
	setup();
	set("capacity", 100);
	replace_program(BULLETIN_BOARD);
}
