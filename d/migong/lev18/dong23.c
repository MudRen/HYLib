
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", YEL"���˴�ׯ"NOR);
	set("long", HIG @LONG
   ���˹��ȵ���Ҫ��·,��·�������л��������,��춰��˸߳��Ľ���
����,���·�����ķǳ���ֱ , �����������Ǵ��ڵص�����ʮ��ĵط� .
���������ǳ���ƽ���������,�з���һ��������Դ.�����Ѿ�����û��ս
���ˡ�
LONG NOR);

set("magicroom",1);set("outdoors","migong");
set("magicset",1);
set("no_fight",1);
	set("exits", ([
		"south" : __DIR__"dong22",
                "north" : __DIR__"dong31",
	]));
         set("objects", ([
              __DIR__"npc/lev2" : random(2),
         ]));

	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
