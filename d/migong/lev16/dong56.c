
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
		"west" : __DIR__"dong5"+(random(5)+3),
		"east" : __DIR__"dong4"+(random(5)+3),
		"south" : __DIR__"dong57",
		"north" : __DIR__"dong56",
	]));
if (random(3)==0)
	set("exits", ([
		"west" : __DIR__"dong5"+(random(5)+3),
		"east" : __DIR__"dong57",
		"south" : __DIR__"dong5"+(random(5)+3),
		"north" : __DIR__"dong5"+(random(5)+1),
	]));
        set("objects", ([
              __DIR__"npc/lev8" : 1,
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
