// Room: /d/city/gangkou
// Date:  inca    98/08/18

#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", HIW "��ɽ����ͷ" NOR);
    set("long", @LONG
�����ǻ�ɽ��۵�С��ͷ��������ͣ����ബ(chuan)����ബ��
�ڴ�����ͣ������Ϣ��Ϣ���Ա��ڸ�·���������ȥ�����Ե�������
����ʿ��֪�Ļ�ɽ��
LONG
    );
	set("no_fight",1);

        set("exits", ([
                "northwest"  : "/d/village/hsroad3",
        ]));

    set("item_desc", ([
         
       "chuan" :"�����кܶബ�����Ҫ�����Ļ��������Ҵ�����һ����\n",    ]));
    set("objects", ([
		__DIR__"npc/shaogong2" : 1,
	]));
    set("outdoors", "city");
    setup();
}


void init()
{
        add_action("do_enter", "enter");
}

int do_enter(string arg)
{
        object me,room;
        me=this_player();
        
        if (!arg || arg=="" || arg != "chuan" )  return 0;
       if (arg=="chuan")
                {
                if ( !(int)me->query_temp("ok"))
                        return notify_fail("�㻹û���⵽�����������ӵĴ�����\n");
			else
			 if (!(int)me->query_temp("ok1")) 
			  return notify_fail("����˵�����͹�����˵�õ����С�Ĳź�׼����\n");
			 if( !(room = find_object(__DIR__"xiaozhou2")) )
            			room = load_object(__DIR__"xiaozhou2");
        		if( room = find_object(__DIR__"xiaozhou2") ) 
            			if((int)room->query("yell_trigger")==1 ) 
				 return notify_fail("����˵�����͹ٲ�Ҫ��������û���������Ժ\n");
			else {room->set("yell_trigger", 1);
                        message("vision", me->name() + "����С����\n", environment(me), ({me}) );
                        message("vinson","��̤��ľ�壬ҡҡ�λε�����С�� \n"+
					  "��������һ�ţ����뿪��ͷ������ʻȥ\n" ,me);
                        me->move(__DIR__"xiaozhou2");}
                }
        return 1;
}
