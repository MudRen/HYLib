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
		"west" : __DIR__"dong9"+(random(4)+2),
            	"east" : __DIR__"dong9"+(random(4)+2),
		"south" : __DIR__"dong9"+(random(4)+4),
		"north" : __DIR__"dong9"+(random(4)+2),
	]));
if (random(3)==0)
	set("exits", ([
		"south" : __DIR__"dong9"+(random(4)+2),
		"north" : __DIR__"dong9"+(random(4)+4),
		"west" : __DIR__"dong9"+(random(4)+2),
            	"east" : __DIR__"dong9"+(random(4)+2),
	]));
        set("objects", ([
     __DIR__"npc/lev7" : 1,
              "/clone/box/gboxm" : random(2),
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
