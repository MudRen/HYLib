
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIM"���ڽ̻�"NOR);
	set("long", HIM @LONG
�����ǿյ����İ��ڽ̻������,���ܵ�ǽ�ھ�Ȼ��
���˹����ɣ���Щ�˹���С���ģ���Ů�ġ����һ��ڲ�
ͣ�Ĳ����������������˹�����µ�������
LONG NOR);
set("magicroom",1);set("outdoors","migong");
set("no_npc",1);
set("magicset",1);
	set("exits", ([
		"north" : __DIR__"dong4"+(random(9)+1),
                "south" : __DIR__"dong50",
		"west" : __DIR__"dong4"+(random(9)+1),
                "east" : __DIR__"dong4"+(random(9)+1),

	]));
if (random(3)==0)
	set("exits", ([
		"west" : __DIR__"dong50",
                "east" : __DIR__"dong4"+(random(9)+1),
		"south" : __DIR__"dong48",
                "north" : __DIR__"dong49",
	]));
if (random(3)==0)
	set("exits", ([
		"west" : __DIR__"dong33",
                "east" : __DIR__"dong4"+(random(9)+1),
		"south" : __DIR__"dong50",
                "north" : __DIR__"dong49",
	]));

         set("objects", ([
              __DIR__"npc/lev9" : 3,
              __DIR__"npc/lev7" : 2,
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

