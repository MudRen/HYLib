// /clone/board/hu.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("���ҵ������԰�", ({ "board" }) );
	set("location", "/d/guanwai/xiaowu");
	set("board_id", "hu_b");
	set("long", "����һ�������ҵ��ӽ��������԰塣\n" );
	setup();
	set("capacity", 100);
	replace_program(BULLETIN_BOARD);
}
