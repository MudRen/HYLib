
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
		"west" : __DIR__"dong1"+(random(7)+1),
                "east" : __DIR__"dong17",
		"south" : __DIR__"dong1"+(random(7)+1),
                "north" : __DIR__"dong51",
	]));
if (random(3)==0)
	set("exits", ([
		"eastwest" : __DIR__"dong1"+(random(4)+5),
                "southwest" : __DIR__"dong1"+(random(5)+3),
"south" : __DIR__"dong51",
	]));
if (random(2)==1)
	set("exits", ([
		"south" : __DIR__"dong1"+(random(4)+5),
                "north" : __DIR__"dong1"+(random(5)+3),
"north" : __DIR__"dong51",
	]));

	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
