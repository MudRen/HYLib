//Cracked by Kafei
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "��·");
	set("long", @LONG
һ����ͨ�ϱ��Ĵ�·�����ɴ�������ϱ߽����Ĺٵ�����·����
��������ï�ܣ���Ƭ���ָ���ɽ�룬�˼���ƽ�ƽ̹����·��ֱ����
���ű��ߵĴ���Ǻ��ϱߵ�ϲ�ݵȳ���
LONG
        );

	set("exits", ([
		"north" : __DIR__"shqiao",
		"south" : __DIR__"minov62",
		]));

	set("outdoors","dali");
	set("cost", 2);
	setup();
}
