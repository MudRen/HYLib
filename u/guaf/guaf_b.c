// /clone/board/wiz_b.c

inherit BULLETIN_BOARD;

void create()
{
          set_name("GUAF�����Բ�", ({ "board" }) );
         set("location", "/u/guaf/workroom");
        set("board_id", "guaf_b");
        set("long", "���κ���GUAF�����������������ԣ�\n" );
	setup();
	set("capacity", 100);
	replace_program(BULLETIN_BOARD);
}

