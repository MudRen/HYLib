
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
		"south" : __DIR__"dong35",
                "north" : __DIR__"dong37",
		"west" : __DIR__"dong32",
                "east" : __DIR__"dong39",

	]));
if (random(3)==0)
	set("exits", ([
		"south" : __DIR__"dong39",
                "north" : __DIR__"dong32",
		"west" : __DIR__"dong34",
                "east" : __DIR__"dong33",
	]));
         set("objects", ([
              __DIR__"npc/lev1" : random(4),
              __DIR__"npc/lev3" : 2,
              "/clone/box/gboxm" : random(2),
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

