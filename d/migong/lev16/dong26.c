
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"��֮�����̵�"NOR);
	set("long", HIY @LONG
  ���ڻ�Ԫ�ص�Ӱ�죬�⸽��ȫ��ɰĮ��������֮����������
��ɰĮ�����ϵ�һ������!!��������֮�����̵ꡣ������Щ
ʲô��??(list)
LONG NOR);
set("magicroom",1);
set("magicset",1);
set("no_fight",1);
	set("exits", ([
                "south" : __DIR__"dong24",
	]));
         set("objects", ([
              __DIR__"npc/sell2" : 1,
         ]));

	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
