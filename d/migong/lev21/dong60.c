
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
		"north" : __DIR__"dong61",
		"east" : __DIR__"dong5"+(random(9)+1),
		"west" : __DIR__"dong5"+(random(9)+1),
		"south" : __DIR__"dong56",
	]));
if (random(3)==0)
	set("exits", ([
		"southup" : __DIR__"dong61",
		"northdown" : __DIR__"dong57",
	]));
if (random(3)==0)
	set("exits", ([
		"eastsouth" : __DIR__"dong59",
		"westnorth" : __DIR__"dong58",
	"north" : __DIR__"dong61",
	]));

if (random(3)==0)
	set("exits", ([
		"west" : __DIR__"dong5"+(random(5)+3),
		"east" : __DIR__"dong5"+(random(5)+3),
		"south" : __DIR__"dong5"+(random(5)+3),
		"north" : __DIR__"dong61",
	]));
        set("objects", ([
              __DIR__"npc/lev8" : 5,
              "/clone/box/gboxm" : 1,
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

