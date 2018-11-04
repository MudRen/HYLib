#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
		set("short", RED"��������ͷ"NOR);
	set("long", RED @LONG
    �����Ѿ��Ƕ�Ѩ�ľ�ͷ�ˣ����ܶ��ǹ��̵��ҽ���һ��
��Ȼ����������·���룬����ɢ����������档 
LONG NOR);
	set("exits", ([
		"north" : __DIR__"dong3",
		"down" : "/d/migong/lev16/dong01",
		                	]));
            set("objects", ([
             __DIR__"npc/boss" : 1,
             __DIR__"npc/lev1" : 1,
             __DIR__"npc/lev2" : 1,
             __DIR__"npc/lev3" : 1,
             __DIR__"npc/lev4" : 1,
             __DIR__"npc/lev5" : 1,
             "/d/migong/obj/npc1" : random(3)+1,
             "/d/migong/obj/npc2" : random(3)+1,             	
             "/clone/box/gbox" : 10,
         ]));
set("no_get",1);
	set("no_npc",1);
	set("no_clean_up", 1);
	setup();
//	replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
	object *inv,kicker;
	int sizeinv,n,tt;
	
       if ( present("huo long", environment(me)) && dir == "down" )
        return notify_fail("��������ס�����ȥ·!!\n");
       if ( me->is_fighting() && dir == "down" )
        return notify_fail("�����ǵ�ס�����ȥ·!!\n");

	if (dir =="down")
	{

me->set("magicgift",2);
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
