// /d/taiyuan/road7.c
// Room in ̫ԭ
// modify by yang

inherit ROOM;

void create()
{
	set("short", "��·");
	set("long", @LONG
����һ����·�������ɳ�ܴ���һ��С�ľ������۾��������Ѿ�
�����˻����о�ס�ĵط���·�ϲ�ʱ���ܼ���ͷ����ñ������ɽ���
�ӵĻ��ˡ�
LONG );
	set("exits", ([
		"west"  : __DIR__"suoqiao",
 		"east"  : __DIR__"yinchuan",
    
		
	]));
	
 	set("outdoors", "taiyuan");
	setup();
	replace_program(ROOM);
}



