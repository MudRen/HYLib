
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
		"east" : __DIR__"dong0"+(random(5)+4),
		"south" : __DIR__"dong03",
                "west" : __DIR__"dong0"+(random(5)+4),
                "north" : __DIR__"dong08",
	]));
if (random(2)==0)
	set("exits", ([
		"eastsouth" : __DIR__"dong0"+(random(5)+4),
		"southwest" : __DIR__"dong02",
                "westnorth" : __DIR__"dong0"+(random(5)+4),
                "northeast" : __DIR__"dong08",
	]));
if (random(3)==0)
	set("exits", ([
		"south" : __DIR__"dong08",
                "north" : __DIR__"dong05",
	]));

         set("objects", ([
              __DIR__"npc/lev3" : random(6),
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
