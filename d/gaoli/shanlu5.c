// /d/gaoli/xuanwumen
// Room in ����
inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
������һ��ɽ·�����߾��Ǹ����������̨�ˡ��м����ٱ�������
������������ˡ�����ʱ�ֻ��ң���������Ľ䱸Ҳ�Ǻ��ϸ�
LONG
	);

	set("exits", ([
		"southdown" : __DIR__"shanlu4",
		"westup":__DIR__"xifenghuotai",
	]));

 	set("outdoors", "/d/gaoli");
	setup();
	replace_program(ROOM);
}


