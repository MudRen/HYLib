
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
set("magicset",1);
	set("exits", ([
		"south" : __DIR__"dong3"+(random(9)+1),
                "north" : __DIR__"dong43",
		"west" : __DIR__"dong3"+(random(6)+4),
                "east" : __DIR__"dong4"+(random(3)+4),
	]));
if (random(3)==0)
	set("exits", ([
		"south" : __DIR__"dong3"+(random(6)+4),
                "north" : __DIR__"dong3"+(random(6)+4),
		"west" : __DIR__"dong4"+(random(4)+4),
                "east" : __DIR__"dong3"+(random(9)+1),
	]));
         set("objects", ([
              __DIR__"npc/player" : 1,
              __DIR__"npc/lev5" : 3,
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

