#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIR"�������Թ�"NOR);
	set("long", HIR @LONG
  �˴���һ����ɽ�۶������ܶ�����ֵĻ��ɫ��ʯ��������ʱ��һЩ��ֵ�
��ʯ�ᾧ�����䱻���ӳ��֮ʱ���ᷴ���Ѥ���Ĺ��ߣ�����ԭ�еĻ�칹��һ��
�����ľ�ɫ��
LONG NOR);
set("magicroom",1);
set("magicset",1);

	set("exits", ([
		"west" : __DIR__"dong4"+(random(7)+1),
		"east" : __DIR__"dong6"+(random(7)+1),
		"south" : __DIR__"dong5"+(random(7)+1),
		"north" : __DIR__"dong72",
	]));
if (random(3)==0)
	set("exits", ([
		"west" : __DIR__"dong4"+(random(7)+1),
		"east" : __DIR__"dong72",
		"south" : __DIR__"dong5"+(random(7)+1),
		"north" : __DIR__"dong6"+(random(7)+1),
	]));
         set("objects", ([
              __DIR__"npc/lev1" : 1,
              __DIR__"npc/lev2" : 1,
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
