
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
set("no_npc",1);
set("no_fight",1);
	set("exits", ([
		"west" : __DIR__"dong24",
		"east" : __DIR__"dong0"+(random(6)+1),
	]));

	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

