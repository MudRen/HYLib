inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
���������ڱ���֣�����������������������С������Ҳ��������������
����һ�������̣������������������죬������һ�ҵ䵱�У�������Ǻ��
LONG );
        set("exits", ([
                "north" : __DIR__"stbeijie2",
		"south" : __DIR__"center",
		"east" : __DIR__"dangpu",
		"west" : __DIR__"wuqipu",
	]));
	set("outdoors", "����");
	setup();
}