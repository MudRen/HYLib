#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIB"����Ķ��ߵľ�ͷ"NOR);
	set("long", HIB @LONG
�ⶴѨ����һֱ���굽�ص�ȥ.����ӵصײ�ͣ�ش�
����. һЩ����ֵֹ�ͼ�λ�����������Ѩ,����֮��,
���ϵ��㼣Ҳ���������ҵ�.
LONG NOR);
set("magicroom",1);set("outdoors","migong");
set("magicset",1);
if (random(2)==0)
	set("exits", ([
//		"west" : "/d/migong/lev20/dong21",
		"east" : __DIR__"dong99",
	]));
if (random(2)==0)
	set("exits", ([
		"south" : __DIR__"dong7"+(random(3)+1),
		"north" : __DIR__"dong99",
	]));
	set("exits", ([
		"east" : __DIR__"dong99",
//		"west" : "/d/migong/lev20/dong21",
	]));
if (random(2)==0)
	set("exits", ([
//		"west" : "/d/migong/lev20/dong21",
            	"east" : __DIR__"dong99",
		"south" : __DIR__"dong99",
		"north" : __DIR__"dong99",
	]));
	set("no_clean_up", 0);
        set("objects", ([
     __DIR__"npc/player" : 3,
     __DIR__"npc/lev8" : 3,
     __DIR__"npc/lev9" : 3,
     __DIR__"npc/boss" : 1,
       "/clone/box/gboxm" : 2,
         ]));
	setup();
//	replace_program(ROOM);
}
int valid_leave(object me, string dir)
{
	object *inv,kicker;
	int sizeinv,n,tt;
	
    if (me->is_fighting() && dir == "west") 
        return notify_fail("���������������!\n");

    if(me->is_busy() && dir == "west")
        return notify_fail("��������æ��\n");

       if ( !present("air boot", me) && dir == "west" )
        return notify_fail("һ�������������ס����!!\n");

	if (dir =="west")
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
