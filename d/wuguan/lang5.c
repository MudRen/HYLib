//cool 98.4.18

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
���Ǹ����ȣ�ͨ����������ң����ﾲ���ĵģ�û��ʲô������
����������������ɽ�����������գ�����������������ֻ����һ��
������
LONG);
	set("exits", ([
               "out" : __DIR__"dating",
               "east" : __DIR__"shufang",
               "north" : __DIR__"woshi",
        ]));
        set("objects", ([
           __DIR__"npc/yahuan" : 1,
        ]));
	setup();
        replace_program(ROOM);
}

