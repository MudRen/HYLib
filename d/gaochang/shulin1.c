// Room: /d/gaochang/shulin1.c

inherit ROOM;

void create()
{
	set("short", "�߲��Թ�");
	set("long", @LONG
������������ĳ���,��ǰ���������������
�Թ�֮�ڲ����㼣ָ�����㲻֪��Ҫ������·�ߡ�
����ϸ���������ף����׺�ǰ������·�϶��е������㼣��
LONG
	);

	set("exits", ([
		"west" : __DIR__"shulin"+(random(10)+2),
              "south" :__DIR__ "road",
		"east" : __DIR__"shulin2",
		"north" : __DIR__"shulin"+(random(10)+2),
	]));

	set("outdoors", "gaochang");
	set("objects",([
		__DIR__"obj/fake_map" : 1,
]));
set("objects",([
		__DIR__"npc/ghost" : 3,
		]));
	setup();
}


