// Room: /u/qingyun/jyzj/shanlu1.c
// Written by qingyun
// Updated by jpei

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
����һ������ɽ�ϵ����ɼ���ɽ·��ֻ���������洦�ɼ�÷����÷��ʢ��
ʱ����һƬ��죬����Ʈ�硣
LONG	);
	set("exits", ([
		"west" : __DIR__"shanlu2",
		"east" : "/d/kunlun/klshanlu",
		"south" : __DIR__"xuedi1",
	]));
	set("outdoors", "kunlun");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
