//Cracked by Kafei
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
һ�������ĸ�����ӣ��˼��²�û��ţ��ȴ����ϯΧ��һ����
ɣ�ϵ�С���ݣ���������̡�¥�ϴ��������ɴ�����������
LONG
        );

	set("exits", ([
		"east" : __DIR__"minov33",
		"up" : __DIR__"minov35",
		]));

	set("objects", ([
		__DIR__"npc/bycannv" : 1,
		]));

	set("cost", 2);
	setup();
}
