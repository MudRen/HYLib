// /d/taiyuan/road7.c
// Room in ̫ԭ
// modify by yang

inherit ROOM;

void create()
{
	set("short", "��·");
	set("long", @LONG
����һ����·�������ɳ�ܴ���һ��С�ľ������۾������洫��
��ˮ���������˻ƺ��ˡ�
LONG );
	set("exits", ([
		"west"  : __DIR__"road9a",
 		"east"  : __DIR__"suoqiao",
           
		
	]));
	
 	set("outdoors", "taiyuan");
	setup();
	replace_program(ROOM);
}



