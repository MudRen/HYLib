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
		"west" : __DIR__"dong6"+(random(5)+2),
		"east" : __DIR__"dong6"+(random(5)+2),
		"south" : __DIR__"dong63",
		"north" : __DIR__"dong67",
	]));
if (random(3)==0)
	set("exits", ([
		"west" : __DIR__"dong67",
		"east" : __DIR__"dong6"+(random(5)+2),
		"south" : __DIR__"dong6"+(random(5)+2),
		"north" : __DIR__"dong6"+(random(5)+2),
	]));
if (random(3)==0)
	set("exits", ([
		"south" : __DIR__"dong67",
		"north" : __DIR__"dong63",
	]));
if (random(3)==0)
	set("exits", ([
		"east" : __DIR__"dong63",
		"west" : __DIR__"dong67",
	]));

        set("objects", ([
              __DIR__"npc/lev8" : 1,
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
