// /d/taiyuan/road7.c
// Room in ̫ԭ
// modify by yang

inherit ROOM;

void create()
{
	set("short", "��·");
	set("long", @LONG
������һ����·�������ɳ�ܴ���һ��С�ľ������۾������߾�
�ǻƺӵĶɿ��ˡ���������������ƺ���ˮ��������
LONG );
	set("exits", ([
		"southwest"  : __DIR__"road8b",
 		"east"  : __DIR__"dukou2",
   	]));
	
 	set("outdoors", "taiyuan");
	setup();
	replace_program(ROOM);
}



