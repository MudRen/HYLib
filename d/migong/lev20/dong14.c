
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"��֮�þ�"NOR);
	set("long", HIG @LONG
ΰ������������ҫ�����ɭ���У�����ɭ����ҫ��
һƬ���ɫ�Ĺ���С��ڸߴ����ָ��������������밫
��ľ,  �㷢�����Ѿ���·�ˡ� 
LONG NOR);
set("magicroom",1);set("outdoors","migong");
set("magicset",1);

	set("exits", ([
                "south" : __DIR__"dong15",
		"north" : __DIR__"dong1"+(random(5)+1),
		"west" : __DIR__"dong1"+(random(4)+1),
                "east" : __DIR__"dong13"
	]));
if (random(4)==0)
	set("exits", ([
		"east" : __DIR__"dong1"+(random(3)+3),
                "west" : __DIR__"dong1"+(random(3)+3),
	]));
if (random(3)==1)
	set("exits", ([
		"south" : __DIR__"dong1"+(random(5)+1),
                "north" : __DIR__"dong1"+(random(5)+1),
	]));

         set("objects", ([
              __DIR__"npc/lev4" : random(3),
              __DIR__"npc/lev5" : random(3),
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
