
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", YEL"�����ɳĮ"NOR);
	set("long", YEL @LONG
  ���ڻ�Ԫ�ص�Ӱ�죬�⸽��ȫ��ɰĮ������һƬһ��
�޼ʵĴ�ɳĮ����һ��������ʧ�˷��򡣿���Ҫ�߳���
��ɳĮ�������¡�
LONG NOR);
set("magicroom",1);
set("no_npc",1);
set("magicset",1);
	set("exits", ([
		"south" : __DIR__"dong4"+(random(9)+1),
                "north" : __DIR__"dong50",
		"west" : __DIR__"dong4"+(random(9)+1),
                "east" : __DIR__"dong4"+(random(9)+1),

	]));
if (random(3)==0)
	set("exits", ([
		"west" : __DIR__"dong48",
                "east" : __DIR__"dong4"+(random(9)+1),
		"south" : __DIR__"dong50",
                "north" : __DIR__"dong49",
	]));
if (random(3)==0)
	set("exits", ([
		"west" : __DIR__"dong50",
                "east" : __DIR__"dong4"+(random(9)+1),
		"south" : __DIR__"dong33",
                "north" : __DIR__"dong49",
	]));

         set("objects", ([
              __DIR__"npc/lev9" : 3,
              __DIR__"npc/lev7" : 2,
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

