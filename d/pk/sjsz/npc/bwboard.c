//Cracked by Kafei
// Board for Group BWDH /clone/board/bwboard.c
// Apache 10/98
// sdong 8/8/1999

inherit ITEM;
inherit F_SAVE;

string query_save_file()
{
		return "/data/board/bwboard";
}

void create() {
    set_name("�������ɼ���", ({ "board"}) );
	 if( !restore() )
	 {
		 set_weight(10000);
		 set_max_encumbrance(500000);
		 set("unit", "��");
		 set("long", "�������ɼ�����ű��������ǵ�ȫ���ɼ���");
		 set("value", 10000);
		 set("material", "steel");
		 set("no_get",1);
		 set("no_clean_up", 1);
       set("bwdhpk",1);setup();
	 }
}
