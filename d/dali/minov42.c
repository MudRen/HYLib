//Cracked by Kafei
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�������������ľ۾����ģ�������������Ĵ󲿣������ģ�����
�͵ĵ顢���ۡ��͸���������������һ��ʯ��С�ǣ��˿ڲ��࣬����
ɢ�������Ӹ�������������Ҫ��һЩ���̺ͼ�������
LONG
        );

	set("exits", ([
		"south" : __DIR__"minov41",
		"west" : __DIR__"minov43",
		"north" : __DIR__"minov47",
		"northeast" : __DIR__"minov48",
		"east" : __DIR__"minov51",
		]));

	set("objects", ([
		__DIR__"npc/wymuyang.c" : 1,
		__DIR__"npc/wyshang.c" : 1,
		]));

	set("outdoors","dali");
	set("cost", 3);
	setup();
}
