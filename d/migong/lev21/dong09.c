
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIM"������Թ�"NOR);
	set("long", HIM @LONG
�����ǻ�����Թ�,�ƺ����������ѵĵط���Ȼ����
�ϵ�����һ�ѶѵĹǺ���Ǭ����Ѫ���������˾�������
�Ե�ʮ�ֵĹ��졣
LONG NOR);


	set("exits", ([
		"north" : __DIR__"dong0"+(random(9)+1),
		"south" : __DIR__"dong0"+(random(9)+1),
                "west" : __DIR__"dong0"+(random(9)+1),
                "east" : __DIR__"dong10",
	]));
if (random(2)==0)
	set("exits", ([
                "southup" : __DIR__"dong10",
		"northdown" : __DIR__"dong0"+(random(9)+1),
	]));
if (random(2)==0)
	set("exits", ([
                "westsouth" : __DIR__"dong10",
		"eastnorth" : __DIR__"dong0"+(random(9)+1),
	]));

         set("objects", ([
              __DIR__"npc/player" : random(2),
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
