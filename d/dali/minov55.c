//Cracked by Kafei
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
����һ����ľ����Ƥ��ɵ�������ӡ��˵صĴ�����Ҫ���¸�
��������ʵ�л����ָ������ò�����Ǩ�㣬������ᶼ�ļ�ª��˵��
���ᣬ������˵�������񣬲𡢽��������㡣
LONG
        );

	set("exits", ([
		"north" : __DIR__"minov46",
		]));

	set("objects", ([
		__DIR__"npc/wykid.c" : 1,
		]));

	set("cost", 2);
	setup();
}
