
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
		"north" : __DIR__"dong39",
                "east" : __DIR__"dong37",
		"south" : __DIR__"dong35",
                "west" : __DIR__"dong32",

	]));
if (random(3)==0)
	set("exits", ([
		"south" : __DIR__"dong33",
                "north" : __DIR__"dong39",
		"west" : __DIR__"dong34",
                "east" : __DIR__"dong32",
	]));

         set("objects", ([
              __DIR__"npc/lev4" : random(4),
              __DIR__"npc/lev3" : 2,

         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

