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
set("no_npc",1);
	set("exits", ([
		"north" : __DIR__"dong6"+(random(7)+3),
		"east" : __DIR__"dong6"+(random(7)+3),
		"south" : __DIR__"dong6"+(random(7)+3),
		"west" : __DIR__"dong70",
	]));
if (random(2)==0)
	set("exits", ([
		"west" : __DIR__"dong6"+(random(7)+3),
		"east" : __DIR__"dong6"+(random(7)+3),
		"down" : __DIR__"dong6"+(random(7)+3),
		"up" : __DIR__"dong70",
	]));
if (random(2)==0)
	set("exits", ([
		"south" : __DIR__"dong69",
		"east" : __DIR__"dong70",
	]));

       set("objects", ([
              __DIR__"npc/player" : 1,
              "/clone/box/gboxm" : 1,
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
