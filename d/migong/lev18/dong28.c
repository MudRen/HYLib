
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", YEL"���֮ħ��ʦ����"NOR);
	set("long", YEL @LONG
   ���˹��ȵ���Ҫ��·,��·�������л��������,��춰��˸߳��Ľ���
����,���·�����ķǳ���ֱ , �����������Ǵ��ڵص�����ʮ��ĵط� .
���������ǳ���ƽ���������,�з���һ��������Դ.�����Ѿ�����û��ս
���ˡ�������ħ��ʦ���ᡣ����ѧЩʲô��??(skills)
LONG NOR);

set("magicroom",1);set("outdoors","migong");
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
