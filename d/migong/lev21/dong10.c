
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
		"east" : __DIR__"dong0"+(random(6)+2),
		"south" : __DIR__"dong0"+(random(6)+3),
                "west" : __DIR__"dong0"+(random(6)+3),
                "north" : __DIR__"dong1"+(random(3)+1),
	]));
if (random(3)==0)
	set("exits", ([
		"south" : __DIR__"dong1"+(random(3)+1),
                "north" : __DIR__"dong05",
	]));
if (random(3)==0)
	set("exits", ([
		"east" : __DIR__"dong05",
                "west" : __DIR__"dong1"+(random(3)+1),
	]));

         set("objects", ([
              __DIR__"npc/lev4" : random(2),
              "/clone/box/gboxm" : 1,
              __DIR__"npc/lev3" : random(2),
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
