
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", RED"���ȵ���Ԩ"NOR);
	set("long", RED @LONG
  ��������ǣ�����һƬ���Ĵ�أ����ȵĵ�����
����һ��һ��Ķ���!�޼ʵĴ�ɳĮ�������µĹ���
���Ƕ��㻢��������ʱ�����˹�����ҧ������ʺ�
��˺�����������
LONG NOR);
set("magicroom",1);
set("magicset",1);

	set("exits", ([
		"west" : __DIR__"dong32",
		"east" : __DIR__"dong52",
	]));
if (random(3)==0)
	set("exits", ([
		"south" : __DIR__"dong52",
		"north" : __DIR__"dong32",
		"west" : __DIR__"dong4"+(random(9)+1),
                "east" : __DIR__"dong4"+(random(9)+1),
	]));
        set("objects", ([
              __DIR__"npc/lev2" : 1,
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

