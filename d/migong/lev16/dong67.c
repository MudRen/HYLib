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
		"west" : __DIR__"dong6"+(random(7)+2),
		"east" : __DIR__"dong6"+(random(7)+2),
		"south" : __DIR__"dong6"+(random(7)+2),
		"north" : __DIR__"dong68",
	]));
if (random(3)==0)
	set("exits", ([
		"west" : __DIR__"dong6"+(random(7)+2),
		"east" : __DIR__"dong6"+(random(7)+2),
		"south" : __DIR__"dong68",
		"north" : __DIR__"dong6"+(random(7)+2),
	]));
         set("objects", ([
              __DIR__"npc/lev8" : 1,
              "/clone/box/gboxm" : random(2),
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
