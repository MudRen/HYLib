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
		"north" : __DIR__"dong5"+(random(5)+3),
		"east" : __DIR__"dong5"+(random(5)+1),
		"south" : __DIR__"dong63",
		"west" : __DIR__"dong65",
	]));
if (random(2)==0)
	set("exits", ([
		"northwest" : __DIR__"dong62",
		"southeast" : __DIR__"dong6"+(random(3)+3),
		"south" : __DIR__"dong6"+(random(3)+3),
		"north" : __DIR__"dong6"+(random(5)+1),
	]));
if (random(3)==0)
	set("exits", ([
		"south" : __DIR__"dong65",
		"north" : __DIR__"dong63",
	]));
if (random(3)==0)
	set("exits", ([
		"east" : __DIR__"dong63",
		"west" : __DIR__"dong65",
	]));

        set("objects", ([
              __DIR__"npc/lev7" : 2,
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
