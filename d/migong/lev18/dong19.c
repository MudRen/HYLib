
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", GRN"�Ŵ��ż�"NOR);
	set("long", GRN @LONG
   �����Ǹ�Σ�յ����򣬺ܴ��Һ�������·���Ӳ������������ľ������
��֪�������ڳ���һЩ����֮�⻹ס��ר������ͷ�İ����壬�Ѿ��в���
�����ȥ֮���û�л�������
LONG NOR);
set("magicroom",1);set("outdoors","migong");
set("magicset",1);

	set("exits", ([
		"south" : __DIR__"dong20",
                "north" : __DIR__"dong71",
		"east" : __DIR__"dong1"+(random(8)+1),
                "west" : __DIR__"dong1"+(random(8)+1),
	]));
if (random(3)==0)
	set("exits", ([
		"east" : __DIR__"dong20",
                "west" : __DIR__"dong1"+(random(8)+1),
"north" : __DIR__"dong71",
	]));
if (random(3)==1)
	set("exits", ([
		"south" : __DIR__"dong20",
                "north" : __DIR__"dong71",
	]));
         set("objects", ([
              __DIR__"npc/lev3" : random(6),
              "/clone/box/gboxm" : random(2),
         ]));
	set("no_clean_up", 0);
	setup();
//	replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
	object *inv,kicker;
	int sizeinv,n,tt;
	
       if ( !present("earth meteor", me) && dir == "north" )
        return notify_fail("һ��ʿ����ס���㣺��ͨ�����֮����ʹ�Ŀ�������??\n");
       if ( !present("earth badge", me) && dir == "north" )
        return notify_fail("һ��ʿ����ס���㣺��ͨ�����֮�������Ŀ�������??\n");

	if (dir =="north")
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
