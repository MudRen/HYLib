
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
		"east" : __DIR__"dong02",
		"south" : __DIR__"dong0"+(random(6)+1),
                "west" : __DIR__"dong05",
                "north" : __DIR__"dong0"+(random(5)+1),
	]));
         set("objects", ([
              __DIR__"npc/lev1" : random(2),
              __DIR__"npc/lev2" : random(2),
         ]));
if (random(3)==0)
	set("exits", ([
		"south" : __DIR__"dong0"+(random(5)+1),
                "north" : __DIR__"dong05",
	]));
if (random(3)==0)
	set("exits", ([
		"east" : __DIR__"dong05",
                "west" : __DIR__"dong0"+(random(4)+1),
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
