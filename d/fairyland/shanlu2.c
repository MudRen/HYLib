// Room: /u/qingyun/jyzj/shanlu2.c
// Written by qingyun
// Updated by jpei

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
����һ������ɽ�ϵ����ɼ���ɽ·��ֻ���������洦�ɼ�÷����÷��ʢ��
ʱ����һƬ��죬����Ʈ�硣�����Ǻ�÷ɽׯ��
LONG	);
	set("exits", ([
		"west" : __DIR__"hongmeizhuang",
		"east" : __DIR__"shanlu1",
	]));
	set("outdoors", "kunlun");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
