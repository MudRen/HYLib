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
		"westnorth" : __DIR__"dong6"+(random(5)+2),
		"eastsouth" : __DIR__"dong6"+(random(5)+2),
		"southeast" : __DIR__"dong63",
		"northwest" : __DIR__"dong66",
	]));
if (random(3)==0)
	set("exits", ([
		"north" : __DIR__"dong6"+(random(5)+2),
		"east" : __DIR__"dong6"+(random(5)+2),
		"south" : __DIR__"dong6"+(random(5)+2),
		"west" : __DIR__"dong66",
	]));
if (random(3)==0)
	set("exits", ([
		"south" : __DIR__"dong62",
		"north" : __DIR__"dong66",
	]));
if (random(3)==0)
	set("exits", ([
		"east" : __DIR__"dong62",
		"west" : __DIR__"dong66",
	]));

        set("objects", ([
              __DIR__"npc/lev8" : 6,
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
