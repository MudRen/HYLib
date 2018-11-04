
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIM"������Թ�"NOR);
	set("long", RED @LONG
�����ǻ�����Թ�,�ƺ����������ѵĵط���Ȼ����
�ϵ�����һ�ѶѵĹǺ���Ǭ����Ѫ���������˾�������
�Ե�ʮ�ֵĹ��졣
LONG NOR);
set("magicroom",1);set("outdoors","migong");
set("magicset",1);

	set("exits", ([
		"north" : __DIR__"dong71",
                "northdown" : __DIR__"dong20",
		"eastsouth" : __DIR__"dong1"+(random(8)+1),
                "westnorth" : __DIR__"dong1"+(random(8)+1),
	]));
if (random(3)==0)
	set("exits", ([
		"east" : __DIR__"dong20",
                "north" : __DIR__"dong1"+(random(8)+1),
"north" : __DIR__"dong71",
	]));
if (random(3)==1)
	set("exits", ([
		"east" : __DIR__"dong20",
                "north" : __DIR__"dong71",
	]));
         set("objects", ([
              __DIR__"npc/lev3" : random(3),
              __DIR__"npc/lev5" : random(3),
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
	
       if ( !present("dark blade", me) && dir == "north" )
        return notify_fail("һ��ʿ����ס���㣺��ͨ������֮׹��ʹ�Ŀ�������??\n");
       if ( !present("dark shield", me) && dir == "north" )
        return notify_fail("һ��ʿ����ס���㣺��ͨ������֮׹��ʹ�Ŀ�������??\n");

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
