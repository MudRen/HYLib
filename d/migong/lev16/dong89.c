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
		"south" : __DIR__"dong90",
		"north" : __DIR__"dong8"+(random(4)+6),
	]));
if (random(3)==0)
	set("exits", ([
		"south" : __DIR__"dong8"+(random(4)+6),
		"north" : __DIR__"dong90",
	]));
        set("objects", ([
              __DIR__"npc/lev6" : 3,
              __DIR__"npc/lev7" : 3,
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
