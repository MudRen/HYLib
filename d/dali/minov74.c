//Cracked by Kafei
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
����һ��Ƭï�ܵ����֣�������ɽ���Ǹ�ï�ܵ���Ҷ�֣�������
�ࡣ�о����̨�������������������ס����£���׽�á�¹��С�ޣ�
�������������ɽ��׽��Щ�����ޡ�
LONG
        );

	set("exits", ([
		"north" : __DIR__"minov72",
		]));

	set("objects", ([
		__DIR__"npc/tylieren" : 2,
	]));

	set("outdoors","dali");
	set("cost", 3);
	setup();
}
