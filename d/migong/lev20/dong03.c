
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
		"southeast" : __DIR__"dong0"+(random(5)+1),
                "northwest" : __DIR__"dong02",
		"eastnorth" : __DIR__"dong0"+(random(4)+1),
                "westsouth" : __DIR__"dong04",
	]));
         set("objects", ([
              __DIR__"npc/lev2" : random(2),
         ]));
if (random(2)==0)
	set("exits", ([
		"east" : __DIR__"dong0"+(random(4)+1),
                "west" : __DIR__"dong0"+(random(4)+1),
		"south" : __DIR__"dong0"+(random(5)+1),
                "north" : __DIR__"dong04",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
