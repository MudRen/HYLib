//Cracked by Kafei
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "��ˮ�ذ�");
	set("long", @LONG
һ����·������ˮ�ݹ�ȵ��ϱ���������ˮ������ȥ����������
��ˢ�Ź��д�أ��������ѩɽ������ĸ���ɽ�Ը��ʱ��ա���·��
ͨ�˹����Ĵ���͵ĵ飬������������С���䡣
LONG
        );

	set("exits", ([
		"north" : __DIR__"minov41",
		"south" : __DIR__"minov45",
		]));

	set("outdoors","dali");
	set("cost", 3);
	setup();
}
