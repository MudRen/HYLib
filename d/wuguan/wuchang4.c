//cool 98.4.18

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "�����䳡");
	set("long", @LONG
����¶�����䳡���ö�����������������ţ������ڳ��У�û����
��ͷ����һ�ۣ����ھ۾�����������Լ��Ĺ��򣬵��Ϸ��ż��������þߡ�
LONG);
	set("exits", ([
	       "north" : __DIR__"lang4",
	       "south" : __DIR__"wuchang2",
        ]));
        set("objects", ([
           __DIR__"npc/daotong" : 1,
        ]));
        set("outdoors", "���");
	setup();
}

