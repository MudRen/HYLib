// Room: /d/xiangyang/caodi4.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;
#include <ansi.h>;

void create()
{
	set("short", "�ݵ�");
	set("long", @LONG
������������Ĳݵء��ɹű���������������İ���ȫ��
���ˣ����Ｘʮ�ﶼû�����̡�
LONG );
        set("outdoors", "xiangyang");
	set("no_clean_up", 0);
	set("exits", ([
		"east"  : "/d/jiujiang/xiaojing2",
		"west"  : __DIR__"southgate2",
	]));
        set("objects", ([
                CLASS_D("hu") + "/cheng" : 1,
        ]));
	setup();
	replace_program(ROOM);
}

