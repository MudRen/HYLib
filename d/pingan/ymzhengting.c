// Room: /city/ymdongting.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
���϶����������ס������һ������������������ϸ������ǽ������һ����
�ң����顰����������ĸ���������Ĵ��֡�֪���������İ����������飬��Ҫ
����Ϊ��Ҿ��л���.��������������������˽�飨jiehun��,��飨lihun����
LONG );
	set("exits", ([
		"west" : __DIR__"yamen",
	]));
	set("objects", ([
		__DIR__"marry/chen" : 1,
		__DIR__"marry/hongniang" : 1,
	]));
        set("no_dazuo",1);set("no_kill",1);set("no_fight",1);
         set("no_steal",1);
         set("pingan",1);
         set("no_beg",1); 	
//	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

