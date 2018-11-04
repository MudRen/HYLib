#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", WHT"�ɴ�֮�ż��Ŀ�����"NOR);
	set("long", CYN @LONG
   ��˵����һ�ҽ�������ŵķɴ�����ħ�������������˵��ǰ��
һ��������յĳ��У���֪ʲôʱ������������˵�ڵĵط���ϡ��
���ĵ��Ǽװ�����ӣ������������أ����е�ɱ��Խ��ԽŨ�ˡ�
LONG NOR);
set("magicroom",1);set("outdoors","migong");
set("magicset",1);
if (random(2)==0)
	set("exits", ([
		"up" : "/d/migong/lev20/dong21",
		"down" : "/d/migong/lev21/dong21",
		"east" : __DIR__"dong99",
	]));
if (random(2)==0)
	set("exits", ([
		"south" : __DIR__"dong7"+(random(3)+1),
		"north" : __DIR__"dong99",
		"up" : "/d/migong/lev20/dong21",
		"down" : "/d/migong/lev21/dong21",
	]));
	set("exits", ([
		"east" : __DIR__"dong99",
		"up" : "/d/migong/lev20/dong21",
		"down" : "/d/migong/lev21/dong21",
	]));
if (random(2)==0)
	set("exits", ([
		"up" : "/d/migong/lev20/dong21",
		"down" : "/d/migong/lev21/dong21",
            	"east" : __DIR__"dong99",
		"south" : __DIR__"dong99",
		"north" : __DIR__"dong99",
	]));
	set("no_clean_up", 0);
        set("objects", ([
     __DIR__"npc/player" : 1,
     __DIR__"npc/lev8" : 3,
     __DIR__"npc/lev9" : 2,
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
	
    if (me->is_fighting() && dir == "up") 
        return notify_fail("���������������!\n");
    if (me->is_fighting() && dir == "down") 
        return notify_fail("���������������!\n");

    if(me->is_busy() && dir == "up")
        return notify_fail("��������æ��\n");
    if(me->is_busy() && dir == "down")
        return notify_fail("��������æ��\n");

       if ( !present("air boot", me) && dir == "down" )
        return notify_fail("һ�������������ס����!!\n");
       if ( !present("air boot", me) && dir == "up" )
        return notify_fail("һ�������������ס����!!\n");

       if ( me->query("shen") > -800000 && dir == "down" )
        return notify_fail("���������Ϊ���ʺ�ȥ��������!!\n");

       if ( me->query_skill("magic-fire",1) < 600 && dir == "down" )
        return notify_fail("��Ļ�ϵħ�����ʺ�ȥ��������!!\n");
       if ( me->query_skill("magic-water",1) < 600 && dir == "down" )
        return notify_fail("���ˮϵħ�����ʺ�ȥ��������!!\n");
       if ( me->query_skill("magic-ice",1) < 600 && dir == "down" )
        return notify_fail("�����ϵħ�����ʺ�ȥ��������!!\n");
       if ( me->query_skill("magic-earth",1) < 600 && dir == "down" )
        return notify_fail("�����ϵħ�����ʺ�ȥ��������!!\n");

       if ( me->query("shen") < 800000 && dir == "up" )
        return notify_fail("���������Ϊ���ʺ�ȥ��������!!\n");

       if ( me->query_skill("magic-fire",1) < 600 && dir == "up" )
        return notify_fail("��Ļ�ϵħ�����ʺ�ȥ��������!!\n");
       if ( me->query_skill("magic-water",1) < 600 && dir == "up" )
        return notify_fail("���ˮϵħ�����ʺ�ȥ��������!!\n");
       if ( me->query_skill("magic-ice",1) < 600 && dir == "up" )
        return notify_fail("�����ϵħ�����ʺ�ȥ��������!!\n");
       if ( me->query_skill("magic-earth",1) < 600 && dir == "up" )
        return notify_fail("�����ϵħ�����ʺ�ȥ��������!!\n");

	if (dir =="down")
	{

		inv=all_inventory(me);
		sizeinv=sizeof(inv);
	
		while (sizeinv--)
		{
       			if (inv[sizeinv]->is_character())  
     				return notify_fail("�����ȥ�����˿ڣ�\n");
       		
		}
		
	}
	if (dir =="up")
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
