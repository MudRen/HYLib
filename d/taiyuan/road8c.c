// /d/taiyuan/road7.c
// Room in ̫ԭ
// modify by yang

inherit ROOM;

void create()
{
	set("short", "��·");
	set("long", @LONG
������һ����·��·����һ���ű�ֱ�İ�����������������������
���Ѿ������˻����о�ס�ĵط���·�ϲ�ʱ���ܼ���ͷ����ñ������
ɽ����ӵĻ��ˡ�
LONG );
	set("exits", ([
		"northwest"  : __DIR__"yinchuan",
 		"east"  : __DIR__"road8b",
///		"southwest":"/d/changan/shandao3",
	]));
	
 	set("outdoors", "taiyuan");
	setup();
	replace_program(ROOM);
}



