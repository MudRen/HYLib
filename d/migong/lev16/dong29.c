
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"��֮�õ�"NOR);
	set("long", HIY @LONG
  ���ڻ�Ԫ�ص�Ӱ�죬�⸽��ȫ��ɰĮ��������֮����������
��ɰĮ�����ϵ�һ������!!��������֮�õꡣ�����������ط�
˯��??(sleep)��Ҳ�������Ե�(sell)
LONG NOR);
set("magicroom",1);
set("magicset",1);
set("no_npc",1);
set("no_fight",1);
set("sleep_room",1);
	set("exits", ([
                "south" : __DIR__"dong27",
                "north" : __DIR__"dong30",
	]));
         set("objects", ([
              __DIR__"npc/sell3" : 1,
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
