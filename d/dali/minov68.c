//Cracked by Kafei
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "��¥��");
	set("long", @LONG
̨����ϲ���������������Ȼ�ٲ��������Ӵ�ɣ���Ϊ������
Ϊǽ����¥�����൱���¡��²������ֻ���ĸ����Ӽܿյģ��ȿ���
����Ȧ��ҲΪ�˷��ߡ�һ������ͨ���ϲ�ķ��ᡣ
LONG
        );

	set("exits", ([
		"up" : __DIR__"minov69",
		"south" : __DIR__"minov67",
		]));

	set("objects", ([
		__DIR__"npc/niu" : 1,
	]));

	set("outdoors","dali");
	set("cost", 2);
	setup();
}
