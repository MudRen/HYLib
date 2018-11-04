
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIG"����֮ɭ"NOR);
	set("long", HIG @LONG
    ������һ�����ϵ�ԭʼɭ�֣������������ľ���������ǹ��϶�
��ɣ���ݷ������������µ�ĥ��������������ɭ�ֲ����ϣ�������ݺ
�������в����ܷҶྫ��޹�ա�
LONG NOR);
set("magicroom",1);set("outdoors","migong");
set("magicset",1);

	set("exits", ([
		"north" : __DIR__"dong71",
                "south" : __DIR__"dong20",
		"east" : __DIR__"dong1"+(random(8)+1),
                "west" : __DIR__"dong1"+(random(8)+1),
	]));
if (random(3)==0)
	set("exits", ([
		"east" : __DIR__"dong20",
                "south" : __DIR__"dong1"+(random(8)+1),
"north" : __DIR__"dong71",
	]));
if (random(3)==1)
	set("exits", ([
		"east" : __DIR__"dong20",
                "west" : __DIR__"dong71",
	]));
         set("objects", ([
              __DIR__"npc/lev3" : random(8),
              __DIR__"npc/lev5" : random(8),
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
	
       if ( !present("ice limb", me) && dir == "north" )
        return notify_fail("һ��ʿ����ס���㣺��ͨ����֮����ʹ�Ŀ�������??\n");
       if ( !present("ice helmet", me) && dir == "north" )
        return notify_fail("һ��ʿ����ס���㣺��ͨ����֮�������Ŀ�������??\n");

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
