
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"��֮�þ�"NOR);
	set("long", HIG @LONG
ΰ������������ҫ�����ɭ���У�����ɭ����ҫ��
һƬ���ɫ�Ĺ���С��ڸߴ����ָ��������������밫
��ľ,  �㷢�����Ѿ���·�ˡ� 
LONG NOR);
set("magicroom",1);set("outdoors","migong");
set("magicset",1);

	set("exits", ([
		"south" : __DIR__"dong71",
                "northeast" : __DIR__"dong20",
		"eastsouth" : __DIR__"dong1"+(random(8)+1),
                "westnorth" : __DIR__"dong1"+(random(8)+1),
	]));
if (random(3)==0)
	set("exits", ([
		"east" : __DIR__"dong20",
                "west" : __DIR__"dong1"+(random(8)+1),
"south" : __DIR__"dong71",
	]));
if (random(3)==1)
	set("exits", ([
		"west" : __DIR__"dong20",
                "south" : __DIR__"dong71",
	]));
         set("objects", ([
              __DIR__"npc/lev3" : random(4),
              __DIR__"npc/lev5" : random(4),
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
	
       if ( !present("light fu", me) && dir == "south" )
        return notify_fail("һ��ʿ����ס���㣺��ͨ������֮��ʹ�Ŀ�������??\n");
       if ( !present("light sword", me) && dir == "south" )
        return notify_fail("һ��ʿ����ס���㣺��ͨ��򯾴֮��ʹ�Ŀ�������??\n");

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
