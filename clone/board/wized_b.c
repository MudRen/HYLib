// /clone/board/wized_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("�޸ļ�¼���Բ�", ({ "board" }) );
	set("location", "/d/wizard/edit_room");
	set("board_id", "wized_b");
	set("long", "ר����ʦ��¼�޸ĵ����԰塣\n" );
	setup();
	set("capacity", 200);
	replace_program(BULLETIN_BOARD);
}