//Room:/d/lingshedao/xiaowu.c
inherit ROOM;
void create()
{
        set("short", "Сé��");
        set("long", @LONG
�����谵����,��Ȼ��յ�͵�Ҳû��.����ĳ���
Ҳ�ǳ���ª,ֻ��һ��,һ��,һ������.
LONG );
        set("exits", ([
                "out"    : __DIR__"xiaowuout",
        ]));
        set("objects",([
                __DIR__"npc/xiexun" : 1,
        ]));
        //set("no_clean_up",0);
//        set("outdoors","lingshedao");
        setup();
//        replace_program(ROOM);
}


void init()
{
        add_action("do_quit","quit");
        add_action("do_quit","exit");
        add_action("do_quit","exercise");
        add_action("do_quit","dazuo");
        add_action("do_quit","exert");
        add_action("do_quit","learn"); 
        add_action("do_quit","yun");
        add_action("do_quit","xue");
        add_action("do_quit","respirate");
        add_action("do_quit","tuna"); 
        add_action("do_quit","fight");
        add_action("do_quit","hit");
        add_action("do_quit","perform");
        add_action("do_quit","persuade");
        add_action("do_quit","quanjia");
        add_action("do_quit","practice");
        add_action("do_quit","lian"); 
        add_action("do_quit","study");
        add_action("do_quit","du");
        add_action("do_quit","teach");
        add_action("do_quit","jiao");
}
int valid_leave(object me, string dir)
{
	object *inv,kicker;
	int sizeinv,n,tt;
	
if ( present("tulong dao", me))
{
       if (  present("miao feng", environment(me))
       || present("hui yue", environment(me))
       || present("liu yun", environment(me)))
        return notify_fail("���̵��˶����������ϵĵ���������¹�(kneel)���Ǿܾ�(refuse)?\n");
}
else	return ::valid_leave(me, dir);
}
int do_quit(string arg)
{
        write(this_player()->query("name")+"������������������\n");
        return 1;
}
