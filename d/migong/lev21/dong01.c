
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
		"south" : __DIR__"dong02",
                "north" : __DIR__"dong0"+(random(3)+1),
		"west" : __DIR__"dong02",
                "up" : "/d/migong/lev19/dong21",
	]));
set("no_npc",1);
         set("objects", ([
              __DIR__"npc/lev4" : random(3),
         ]));
if (random(2)==0)
	set("exits", ([
		"east" : __DIR__"dong0"+(random(3)+1),
                "up" : "/d/migong/lev19/dong21",
	]));
if (random(2)==0)
	set("exits", ([
		"up" : "/d/migong/lev19/dong21",
                "north" : __DIR__"dong0"+(random(3)+1),
	]));

	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
