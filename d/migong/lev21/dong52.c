
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIG"�ջ�Ĺ���"NOR);
	set("long",RED @LONG
����������һ�����У���Ϊ��ʱ��һ�����Ѱ�������
�е��˶��������ˡ���ͻȻ���֣���Χ��ǽ�����ô���
���ɵġ�һ���ޱȵ��ջ�ʹ�����ǰ���� 
LONG NOR);

set("magicroom",1);set("outdoors","migong");
set("magicset",1);

	set("exits", ([
		"westdown" : __DIR__"dong53",
		"eastup" : __DIR__"dong5"+(random(4)+1),
		"southwest" : __DIR__"dong5"+(random(4)+1),
		"northeast" : __DIR__"dong5"+(random(4)+1),
	]));
if (random(3)==0)
	set("exits", ([
		"south" : __DIR__"dong51",
		"north" : __DIR__"dong53",
	]));
if (random(3)==0)
	set("exits", ([
		"east" : __DIR__"dong51",
		"west" : __DIR__"dong53",
	]));

if (random(3)==0)
	set("exits", ([
		"west" : __DIR__"dong5"+(random(4)+1),
		"east" : __DIR__"dong5"+(random(4)+3),
		"south" : __DIR__"dong5"+(random(4)+1),
		"north" : __DIR__"dong5"+(random(4)+1),
	]));
        set("objects", ([
              __DIR__"npc/lev2" : 5,
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

