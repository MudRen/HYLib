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
set("no_npc",1);
	set("exits", ([
		"south" : __DIR__"dong100",
		"west" : __DIR__"dong9"+(random(4)+6),
	]));
if (random(3)==0)
	set("exits", ([
		"west" : __DIR__"dong9"+(random(4)+6),
            	"east" : __DIR__"dong9"+(random(4)+6),
		"south" : __DIR__"dong100",
		"north" : __DIR__"dong9"+(random(4)+6),
	]));
	set("no_clean_up", 0);
        set("objects", ([
     __DIR__"npc/lev5" : 2,
     __DIR__"npc/lev6" : 2,
     __DIR__"npc/lev7" : 2,
         ]));
	setup();
//	replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
	object *inv,kicker;
	int sizeinv,n,tt;
	
       if ( !present("fire jian", me) && dir == "south" )
        return notify_fail("һ��������ס���㣺��ͨ����֮����ʹ�Ŀ�������??\n");
       if ( !present("fire armor", me) && dir == "south" )
        return notify_fail("һ��������ס���㣺��ͨ����֮�������Ŀ�������??\n");

	if (dir =="south")
	{

		inv=all_inventory(me);
		sizeinv=sizeof(inv);
	
		while (sizeinv--)
		{
       			if (inv[sizeinv]->is_character())  
     				return notify_fail("�����ȥ�����˿ڣ�\n");
       		
		}
		
	}

	return ::valid_leave(me, dir);
}
