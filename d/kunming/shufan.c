// /d/kunming/dongzoulang.c
// netkill /98/9/11/


#include <ansi.h>
inherit ROOM;

void create()
{
        set("short",  "�鷿" );
        set("long", @LONG
����һ�������������鷿���ıڶ�����ܣ���������˸����鼮��
�м�һ�����ӣ����ű�īֽӡ��
LONG
        );
          
        set("exits", ([
		"east"   :__DIR__"xizoulang1"
                
        ]));
	set("objects",([
		__DIR__"npc/wusangui":1,
		]));
	set("shu_count",1);
        setup();
	   
}

int init()
{
	add_action("do_fan","fan");
}

int do_fan( string arg )
{	object me=this_player(),
	       ob=present("wu sangui", environment(me)),
	       shu;

	if ( !objectp(ob))
	{
	if (arg=="" || !arg) return notify_fail("��Ҫ��ʲô��\n");
	if ( query("shu_count") && arg=="shu")
	{
	tell_object(me,"�㷭��һ���飬��Ȼ������һ�����ر���飬��Ͽ�����������\n");
	shu=new(__DIR__"obj/book14_1");
	shu->move(me);
	set("shu_count",0);
	return 1;
	}
	else return notify_fail("���Ĵ�һ���ҷ������ʲô��û���֡�\n");
	}
	else 
	{ message("vision","������ŭ���������������ˣ���Ȼ�Ҵ���������\n",me);
	  ob->kill_ob(me);
	}
	return 1; 
}
	  		