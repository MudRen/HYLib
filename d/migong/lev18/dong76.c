#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIM"������Թ�"NOR);
	set("long", HIM @LONG
   ��������һ���ƾɵķ��棬����ɢ�������ܵ�ʯ����ʯ�顣���д����
���ﱻ�����Ѹ������ˡ���Ƭ���������ľ���ͳ��Ÿ�����ΰ�����Ľ���
���Ǹ���Ϊ��̵ĶԱȣ����ֱ�������㻹�������߲����ҵ���·��
LONG NOR);
set("magicroom",1);set("outdoors","migong");
set("magicset",1);

	set("exits", ([
		"west" : __DIR__"dong7"+(random(4)+4),
		"east" : __DIR__"dong7"+(random(4)+6),
		"south" : __DIR__"dong7"+(random(4)+4),
		"north" : __DIR__"dong7"+(random(4)+4),
	]));
if (random(2)==0)
	set("exits", ([
		"south" : __DIR__"dong7"+(random(4)+4),
		"north" : __DIR__"dong7"+(random(4)+5),
	]));
if (random(3)==0)
	set("exits", ([
		"west" : __DIR__"dong7"+(random(3)+1),
		"east" : __DIR__"dong77",
	]));
         set("objects", ([
              __DIR__"npc/lev7" : 5,
              __DIR__"npc/player" : 2,
              "/clone/box/gboxm" : random(3),
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
