
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIM"������Թ�"NOR);
		set("long", RED @LONG
�����ǻ�����Թ�,�ƺ����������ѵĵط���Ȼ����
�ϵ�����һ�ѶѵĹǺ���Ǭ����Ѫ���������˾�������
�Ե�ʮ�ֵĹ��졣
LONG NOR);
set("magicroom",1);set("outdoors","migong");
set("magicset",1);

	set("exits", ([
		"east" : __DIR__"dong07",
		"south" : __DIR__"dong0"+(random(9)+1),
                "west" : __DIR__"dong09",
                "north" : __DIR__"dong0"+(random(8)+1),
	]));
if (random(2)==0)
	set("exits", ([
		"south" : __DIR__"dong0"+(random(9)+1),
                "north" : __DIR__"dong0"+(random(2)+8),
	]));
if (random(2)==0)
	set("exits", ([
		"west" : __DIR__"dong0"+(random(9)+1),
                "east" : __DIR__"dong0"+(random(2)+8),
	]));
         set("objects", ([
              __DIR__"npc/player" : random(6),
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
