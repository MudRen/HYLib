// /d/gaoli/xuanwumen
// Room in ����
inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
������һ����������Ĵ�����ϡ��������������������ӵ����̣�
���Ŵ󳵵���������������ǳ����֡���ʱ����������������߷�
�۶���������һ·��������·��������������������֡�
LONG
	);

	set("exits", ([
		"east" : __DIR__"edao1",
		"southwest":__DIR__"shanlu3",
	]));

 	set("outdoors", "/d/gaoli");
	setup();
	replace_program(ROOM);
}


