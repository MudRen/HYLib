#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"���ҵ���Ĺ������"NOR);
	set("long", HIM @LONG
���Ǵ�˵�й���ĵ���Ĺ��ͨ·������Ʈ����һ�ſ�����
�ĺ�ˮ�������ܵ�ǽ�ں��컨���������������ıڻ��;���
��ʯ������ɢ�������صĹ�â��
LONG NOR);
set("magicroom",1);set("outdoors","migong");
set("magicset",1);
if (random(2)==0)
	set("exits", ([
		"eastdown" : __DIR__"dong99",
	]));
if (random(2)==0)
	set("exits", ([
		"southdown" : __DIR__"dong7"+(random(3)+1),
		"northdown" : __DIR__"dong99",
	]));
	set("exits", ([
		"eastdown" : __DIR__"dong99",
	]));
if (random(2)==0)
	set("exits", ([
		"southdown" : __DIR__"dong99",
		"northdown" : __DIR__"dong99",
	]));
	set("no_clean_up", 0);
        set("objects", ([
     __DIR__"npc/player" : 2,
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
