
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"��֮�þ�"NOR);
	set("long", HIY @LONG
ΰ������������ҫ�����ɭ���У�����ɭ����ҫ��
һƬ���ɫ�Ĺ���С��ڸߴ����ָ��������������밫
��ľ,  �㷢�����Ѿ���·�ˡ� 
LONG NOR);


	set("exits", ([
		"eastnorth" : __DIR__"dong0"+(random(9)+1),
		"southeast" : __DIR__"dong0"+(random(9)+1),
                "westnorth" : __DIR__"dong0"+(random(9)+1),
                "northwest" : __DIR__"dong10",
	]));
if (random(2)==0)
	set("exits", ([
                "southwest" : __DIR__"dong10",
		"northeast" : __DIR__"dong0"+(random(9)+1),
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
