
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
set("outdoors", "migong");
	set("exits", ([
                "west" : __DIR__"dong3"+(random(5)+4),
		"east" : __DIR__"dong3"+(random(5)+4),
		"south" : __DIR__"dong3"+(random(5)+4),
                "north" : __DIR__"dong3"+(random(5)+4),
	]));
if (random(2)==0)
	set("exits", ([
		"east" : __DIR__"dong3"+(random(5)+4),
                "west" : __DIR__"dong3"+(random(5)+4),
	]));
if (random(2)==0)
	set("exits", ([
		"south" : __DIR__"dong3"+(random(5)+4),
                "north" : __DIR__"dong3"+(random(5)+4),
	]));

         set("objects", ([
              __DIR__"npc/lev3" : random(5),
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

