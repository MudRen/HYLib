// Room: /d/quanzhou/zahuopu.c
// Date: May 7, 96   Jay

inherit ROOM;

void create()
{
	set("short", "�ӻ���");
	set("long", @LONG
������һ��ר�����߰��㶫����С���ӡ�
LONG );
	set("exits", ([
		"north" : __DIR__"west3",
	]));
	set("objects", ([
		__DIR__"npc/shopman" : 1,
	]) );
        set("no_fight",1);
         set("no_steal",1);
         set("pingan",1);
         set("no_beg",1); 	
//	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

