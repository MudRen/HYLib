
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"��֮ħ��ʦ����"NOR);
	set("long", HIY @LONG
  ���ڻ�Ԫ�ص�Ӱ�죬�⸽��ȫ��ɰĮ��������֮����������
��ɰĮ�����ϵ�һ������!!������ħ��ʦ���ᡣ����ѧЩʲô
��??(skills)
LONG NOR);
set("magicroom",1);
set("magicset",1);
set("no_fight",1);
	set("exits", ([
                "north" : __DIR__"dong27",
	]));
         set("objects", ([
              __DIR__"npc/master" : 1,
         ]));

	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
