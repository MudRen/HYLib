//Cracked by Kafei
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "�������");
	set("long", @LONG
һ��Ƭɽ�³�����ݣ����Ƿ���ţ��ĺõط�������������ߣ�
��ճ�����ɫ������ɽ����ľ�Ѿ����٣������϶��ǵͰ���ľ��ݵء�
���ٸ����Ĵ����ڴ˷�����
LONG
        );

	set("exits", ([
		"west" : __DIR__"minov84",
		]));

	set("objects", ([
		__DIR__"npc/wymuyang.c" : 1,
		__DIR__"npc/wymuyren.c" : 1,
		]));

	set("outdoors","dali");
	set("cost", 3);
	setup();
}
