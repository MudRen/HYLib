
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
		"northup" : __DIR__"dong62",
		"eastsouth" : __DIR__"dong5"+(random(4)+1),
		"southdown" : __DIR__"dong5"+(random(5)+3),
		"westnorth" : __DIR__"dong6"+(random(4)+1),
	]));
if (random(3)==0)
	set("exits", ([
		"east" : __DIR__"dong6"+(random(4)+1),
		"west" : __DIR__"dong5"+(random(4)+1),
		"south" : __DIR__"dong6"+(random(4)+1),
		"north" : __DIR__"dong6"+(random(4)+1),
	]));
        set("objects", ([
              __DIR__"npc/lev4" : 3,
              __DIR__"npc/player" : 1,
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

