#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"���ҵ���Ĺ"NOR);
	set("long", HIM @LONG
���Ǵ�˵�й���ĵ���Ĺ��ͨ·������Ʈ����һ�ſ�����
�ĺ�ˮ�������ܵ�ǽ�ں��컨���������������ıڻ��;���
��ʯ������ɢ�������صĹ�â��
LONG NOR);
set("magicroom",1);set("outdoors","migong");
set("magicset",1);

	set("exits", ([
		"west" : __DIR__"dong19",
		"east" : __DIR__"dong6"+(random(7)+1),
		"south" : __DIR__"dong5"+(random(7)+1),
		"north" : __DIR__"dong72",
	]));
if (random(2)==0)
	set("exits", ([
		"eastdown" : __DIR__"dong19",
		"westup" : __DIR__"dong72",
		"southwest" : __DIR__"dong5"+(random(7)+1),
		"northnorth" : __DIR__"dong6"+(random(7)+1),
	]));
if (random(3)==0)
	set("exits", ([
		"west" : __DIR__"dong7"+(random(3)+1),
		"east" : __DIR__"dong19",
	]));
if (random(3)==0)
	set("exits", ([
		"south" : __DIR__"dong7"+(random(3)+1),
		"north" : __DIR__"dong19",
	]));
         set("objects", ([
              __DIR__"npc/lev3" : 2,
              __DIR__"npc/lev4" : 1,
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
