// /d/taiyuan/road7.c
// Room in ̫ԭ
// modify by yang

inherit ROOM;

void create()
{
	set("short", "��·");
	set("long", @LONG
������һ����·�������ɳ�ܴ���һ��С�ľ������۾���
LONG );
	set("exits", ([
		"west"  : "/d/huanghe/huanghe4",
 		"east"  : __DIR__"road9",
        
		
	]));
	
 	set("outdoors", "taiyuan");
	setup();
	replace_program(ROOM);
}



