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
		"westnorth" : __DIR__"dong7"+(random(5)+5),
		"eastsouth" : __DIR__"dong7"+(random(5)+4),
		"southdown" : __DIR__"dong7"+(random(4)+1),
		"northup" : __DIR__"dong79",
	]));
if (random(3)==0)
	set("exits", ([
		"west" : __DIR__"dong7"+(random(4)+5),
		"east" : __DIR__"dong7"+(random(4)+5),
	]));
if (random(3)==0)
	set("exits", ([
		"west" : __DIR__"dong79",
		"north" : __DIR__"dong7"+(random(4)+4),
	]));
         set("objects", ([
              __DIR__"npc/lev9" : 5,
              "/clone/box/gboxm" : random(2),
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
