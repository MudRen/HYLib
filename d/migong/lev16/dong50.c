
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", YEL"�����ɳĮ"NOR);
	set("long", YEL @LONG
  �����������ɳĮ�ľ�ͷ!!��֮�������ļ�!!
  ���ڻ�Ԫ�ص�Ӱ�죬�⸽��ȫ��ɰĮ������һƬһ��
�޼ʵĴ�ɳĮ����һ��������ʧ�˷��򡣿���Ҫ�߳���
��ɳĮ�������¡�
LONG NOR);
set("magicroom",1);
set("magicset",1);
	set("exits", ([
		"south" : __DIR__"dong49",
                "north" : __DIR__"dong50",
		"west" : __DIR__"dong49",
                "east" : __DIR__"dong49",

	]));
         set("objects", ([
              __DIR__"npc/lev5" : 1,
              __DIR__"npc/lev7" : 1,
              __DIR__"npc/lev9" : 2,
              __DIR__"npc/player" : 1,
              __DIR__"npc/boss2" : 1,
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

