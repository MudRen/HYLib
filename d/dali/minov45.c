//Cracked by Kafei
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "��ͷ��");
	set("long", @LONG
��ͷ�����������Ĳ��䣬�͸���������һ����Ҳ�������ġ�����
ɽ�����ܣ�����������ʽ�ɽ����������·ɥ������ɽ������������
˵ȴ�Ǿ۱��裬ɽ��Ұ�������ζ��
LONG
        );

	set("exits", ([
		"north" : __DIR__"minov57",
		"westup" : __DIR__"minov53",
		"southeast" : __DIR__"minov46",
		]));

	set("objects", ([
		__DIR__"npc/wylieren.c" : 1,
		]));

	set("outdoors","dali");
	set("cost", 3);
	setup();
}
