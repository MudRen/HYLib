//Cracked by Kafei
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
һ��Ƭï�ܵ�������������ɽ�����ӳ�ȥ���˼��������ۣ�����
��أ�����¬¹���̨�ĸ�Ů��ǰ����ժ����Ϊʳ������Ҳ����Щ��
������������Ͳ�ͱ�֯��������¨��
LONG
        );

	set("exits", ([
		"east" : __DIR__"minov67",
		]));

	set("objects", ([
		__DIR__"npc/tycaisun.c" : 1,
		]));

	set("outdoors","dali");
	set("cost", 3);
	setup();
}
