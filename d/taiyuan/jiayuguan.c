// /d/taiyuan/road7.c
// Room in ̫ԭ
// modify by yang

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�����Ǿ������µ��յ�֮һ�������ˡ����������Ǳ��ұ���֮�ء�
�����м����ٱ����ڼ�������������ˡ�
LONG );
	set("exits", ([
//		"west"  : "/d/tuyuhun/silk",
 		"east"  : __DIR__"road9a",
		
	]));
	set("objects",([
	__DIR__"npc/bing2":2,
	]));
 	set("outdoors", "taiyuan");
	setup();
	replace_program(ROOM);
}



