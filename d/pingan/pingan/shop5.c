// Room: /d/quanzhou/zahuopu.c
// Date: May 7, 96   Jay

inherit ROOM;

void create()
{
	set("short", "�������");
	set("long", @LONG
������һ��ר�����ֹ����书�����꣬��˵�����Ǹ�������ˡ�
LONG );
	set("exits", ([
		"north" : __DIR__"dong2",
	]));
	set("objects", ([
		__DIR__"npc/shopman2" : 1,
	]) );
        set("no_fight",1);
         set("no_steal",1);
         set("pingan",1);
         set("no_beg",1); 	
//	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

