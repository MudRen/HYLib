
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
		"west" : __DIR__"dong5"+(random(5)+3),
		"south" : __DIR__"dong5"+(random(5)+3),
		"east" : __DIR__"dong56",
		"north" : __DIR__"dong57",
	]));
if (random(2)==0)
	set("exits", ([
		"west" : __DIR__"dong5"+(random(5)+3),
		"east" : __DIR__"dong5"+(random(5)+1),
		"north" : __DIR__"dong5"+(random(5)+3),
		"south" : __DIR__"dong57",
	]));
        set("objects", ([
              __DIR__"npc/lev8" : 2,
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

