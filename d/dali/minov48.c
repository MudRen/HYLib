//Cracked by Kafei
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "���ɵ�");
	set("long", @LONG
���������ķ�֧�����������۾ӵ����ӣ����������ɵ�����ݡ�
������Ϫ��������ˮ������ı��������ũҵ��Թ������������Ϸ�
����о���Щ��ª����ӣ�Ҳ�������̹�����
LONG
        );

	set("exits", ([
		"southwest" : __DIR__"minov42",
		"west" : __DIR__"minov47",
		]));

	set("objects", ([
		__DIR__"npc/wygirl.c" : 1,
		]));

	set("outdoors","dali");
	set("cost", 3);
	setup();
}
