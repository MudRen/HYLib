
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
		"east" : __DIR__"dong3"+(random(4)+5),
		"south" : __DIR__"dong3"+(random(3)+5),
                "west" : __DIR__"dong3"+(random(3)+5),
                "north" : __DIR__"dong3"+(random(4)+5),
	]));
if (random(3)==0)
	set("exits", ([
		"east" : __DIR__"dong3"+(random(4)+5),
                "west" : __DIR__"dong3"+(random(4)+5),
	]));

         set("objects", ([
              __DIR__"npc/lev1" : random(5),
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

