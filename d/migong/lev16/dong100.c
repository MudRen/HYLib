#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIR"�������Թ��ľ�ͷ"NOR);
	set("long", HIR @LONG
  �˴���һ����ɽ�۶������ܶ�����ֵĻ��ɫ��ʯ��������ʱ��һЩ��ֵ�
��ʯ�ᾧ�����䱻���ӳ��֮ʱ���ᷴ���Ѥ���Ĺ��ߣ�����ԭ�еĻ�칹��һ��
�����ľ�ɫ��
LONG NOR);
set("magicroom",1);
set("magicset",1);

	set("exits", ([
		"east" : __DIR__"dong99",
		"west" : "/d/migong/lev17/dong01",
	]));
if (random(3)==0)
	set("exits", ([
		"west" : "/d/migong/lev17/dong01",
            	"east" : __DIR__"dong99",
		"south" : __DIR__"dong99",
		"north" : __DIR__"dong99",
	]));
	set("no_clean_up", 0);
        set("objects", ([
     __DIR__"npc/player" : 1,
     __DIR__"npc/lev8" : 2,
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
	
    if (me->is_fighting() && dir == "west") 
        return notify_fail("���������������!\n");

    if(me->is_busy() && dir == "west")
        return notify_fail("��������æ��\n");

       if ( !present("fire hat", me) && dir == "west" )
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
