inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һ��ľ�Ƶ����ȣ�������ǹ⻬����������һ����Ⱦ��
������ҵ�Ѿ���ڴ��߶������ȵ����߷ֽ������ͺ�����
LONG);
	set("exits", ([
  		"east"  : __DIR__"miaojia_houting",
  		"west" : __DIR__"miaojia_zhengting",
  		"north" : __DIR__"miaojia_jushi",
	]));
        set("objects", ([
                __DIR__"npc/yahuan" : 1,
        ]));

	set("no_clean_up", 0);
	set("coor/x", -190);
	set("coor/y", 30);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
