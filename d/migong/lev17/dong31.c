
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", GRN"ˮû����"NOR);
	set("long", GRN @LONG
    ������о�Ȼ�ں���,�ŵ�������������ġ�ˮ�塻�����Զ���ǧ�ɸߵ�ˮ
ǽ������ˮ����¡¡�ؿ�Ҫ����Ķ�Ĥ����, Ю���������ˮ��,���������ȫ
�����ʪ�ˡ� ˮǽ��һЩ�߲ʰ�쵵���������е�׷����ˣ,��ʱ�ν�����
��,һ��Ҳ�����������,�㲻��������Ҫ����ˮǽȥ��������,ȴ�ƺ��й���
���赲���㡣
LONG NOR);
set("magicroom",1);set("outdoors","migong");
set("magicset",1);
set("no_npc",1);
set("no_fight",1);
	set("exits", ([
		"south" : __DIR__"dong23",
		"north" : __DIR__"dong71",
	]));
         set("objects", ([
              __DIR__"npc/player" : random(2),
         ]));

	set("no_clean_up", 0);
	setup();
}

int valid_leave(object me, string dir)
{
	object *inv,kicker;
	int sizeinv,n,tt;
	
       if ( !present("water jian", me) && dir == "north" )
        return notify_fail("һ��ʿ����ס���㣺��ͨ��ˮ֮����ʹ�Ŀ�������??\n");
       if ( !present("water cloth", me) && dir == "north" )
        return notify_fail("һ��ʿ����ס���㣺��ͨ��ˮ֮�������Ŀ�������??\n");

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
