
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
		"east" : __DIR__"dong0"+(random(4)+3),
                "west" : __DIR__"dong0"+(random(4)+3),
		"south" : __DIR__"dong0"+(random(4)+3),
                "north" : __DIR__"dong0"+(random(4)+3),
	]));
if (random(3)==0)
	set("exits", ([
		"westeast" : __DIR__"dong0"+(random(4)+3),
		"eastsouth" : __DIR__"dong0"+(random(4)+3),
                "northwest" : __DIR__"dong0"+(random(4)+3),
                "southnorth" : __DIR__"dong0"+(random(4)+3),
	]));
if (random(2)==0)
	set("exits", ([
		"south" : __DIR__"dong0"+(random(4)+3),
                "north" : __DIR__"dong0"+(random(4)+3),
	]));
if (random(2)==0)
	set("exits", ([
		"east" : __DIR__"dong0"+(random(4)+3),
                "west" : __DIR__"dong0"+(random(4)+3),
	]));

         set("objects", ([
              __DIR__"npc/lev1" : random(3),
              __DIR__"npc/lev2" : random(2),
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
