
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
set("magicset",1);
	set("exits", ([
		"westdown" : __DIR__"dong48",
                "eastup" : __DIR__"dong4"+(random(9)+1),
		"southeast" : __DIR__"dong4"+(random(9)+1),
                "northwest" : __DIR__"dong4"+(random(9)+1),
	]));
if (random(3)==0)
	set("exits", ([
		"south" : __DIR__"dong4"+(random(3)+6),
                "west" : __DIR__"dong4"+(random(3)+6),
	]));
if (random(3)==0)
	set("exits", ([
		"westdown" : __DIR__"dong4"+(random(9)+1),
                "eastup" : __DIR__"dong48",
	]));
         set("objects", ([
              __DIR__"npc/lev8" : 3,
              __DIR__"npc/lev9" : 3,
      "/clone/box/gboxm" : random(2),
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

