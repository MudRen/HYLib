#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", WHT"������Թ�"NOR);
	set("long",HIW @LONG
���������ܸо���һ����ʥ��ׯ�ϵ�����,������͵�
�����ʹ����ط���������͵�����,���ﶫ���ϱ�����ͨ
·,����ÿ��ͨ�����ƺ�����ħ���ϱڡ�
LONG NOR);
set("magicroom",1);set("outdoors","migong");
set("magicset",1);

	set("exits", ([
		"west" : __DIR__"dong69",
		"east" : __DIR__"dong69",
		"south" : __DIR__"dong69",
		"north" : __DIR__"dong69",
	]));
if (random(2)==0)
	set("exits", ([
		"west" : __DIR__"dong69",
		"east" : __DIR__"dong69",
		"south" : __DIR__"dong69",
		"north" : __DIR__"dong69",
	]));
         set("objects", ([
              __DIR__"npc/lev9" : 3,
              __DIR__"npc/lev8" : 2,
              __DIR__"npc/lev5" : 2,
              __DIR__"npc/player" : 2,
              __DIR__"npc/boss1" : 1,
              "/clone/box/gboxm" : 1,
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
