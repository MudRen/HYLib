//Cracked by Kafei
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "��ɽɽ·");
	set("long", @LONG
�˴������ӱߣ�����ɽ�ڼ�����ֱ��ֱ�£���ǰ��һ������Ա�
���϶������ڴ�����������ȥ����ˮ������ӿ���Ļ��Ӱ�������һ
�����˵ĺ��졣����ǡ����壬�Ӵ���խ���ӹ��ϲ���������ֻ��
���������������������˰���һ�ô����ϣ��ƿ���Ԯ������
LONG
        );

	set("exits", ([
		"west" : __DIR__"minov92",
		"northeast" : __DIR__"minov90",
		]));

	set("objects", ([
		__DIR__"npc/wylieren.c" : 1,
		]));

	set("outdoors","dali");
	set("cost", 3);
	setup();
}
