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
		"west" : __DIR__"dong7"+(random(4)+3),
		"east" : __DIR__"dong7"+(random(4)+1),
		"south" : __DIR__"dong7"+(random(4)+1),
		"north" : __DIR__"dong71",
	]));
if (random(2)==0)
	set("exits", ([
		"west" : __DIR__"dong7"+(random(4)+3),
		"east" : __DIR__"dong73",
	]));
         set("objects", ([
              __DIR__"npc/lev3" : 6,
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
