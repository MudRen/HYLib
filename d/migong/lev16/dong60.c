
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
		"west" : __DIR__"dong4"+(random(9)+1),
		"east" : __DIR__"dong4"+(random(9)+1),
		"south" : __DIR__"dong61",
		"north" : __DIR__"dong56",
	]));
if (random(3)==0)
	set("exits", ([
		"west" : __DIR__"dong5"+(random(5)+3),
		"east" : __DIR__"dong61",
		"south" : __DIR__"dong3"+(random(5)+3),
		"north" : __DIR__"dong3"+(random(5)+3),
	]));
        set("objects", ([
              __DIR__"npc/lev8" : 2,
              "/clone/box/gboxm" : 1,
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

