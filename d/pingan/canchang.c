//canchang
  

inherit ROOM;

void create()
{
	set("short", "�˳�");
	set("long", @LONG
���������������Ĳ˳�������ʪʪ�ĳ���û�иɵ�ʱ��С��С����
������ȥ���뾡�������˻ؼҡ������������̯�Ķ�Ҫ����������Ķ��
�������ѡ�
LONG
	);
set("outdoors","pingan");

	set("exits", ([
		 
		"south" : __DIR__"eba",
		"west" : __DIR__"wendingnan1",
		 
	]));
//        set("objects", ([
//                "/npc/npc": 2,
//	]));

        set("no_dazuo",1);set("no_kill",1);set("no_fight",1);
         set("no_steal",1);
         set("pingan",1);
         set("no_beg",1); 	
	setup();
	replace_program(ROOM);
}

