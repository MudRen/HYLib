
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
        set("outdoors", "migong");
set("magicroom",1);set("outdoors","migong");
set("magicset",1);
	set("exits", ([
		"west" : __DIR__"dong3"+(random(6)+4),
                "east" : __DIR__"dong4"+(random(3)+1),
		"south" : __DIR__"dong3"+(random(6)+4),
                "north" : __DIR__"dong3"+(random(6)+4),
	]));
if (random(3)==0)
	set("exits", ([
		"west" : __DIR__"dong4"+(random(3)+3),
                "east" : __DIR__"dong3"+(random(6)+4),
		"south" : __DIR__"dong3"+(random(6)+4),
                "north" : __DIR__"dong3"+(random(6)+4),
	]));
if (random(3)==0)
	set("exits", ([
		"east" : __DIR__"dong4"+(random(3)+3),
                "west" : __DIR__"dong4"+(random(3)+1),
	]));
         set("objects", ([
              __DIR__"npc/lev2" : 6,
              __DIR__"npc/lev5" : 6,
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

