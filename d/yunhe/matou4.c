// Room: /d/city/gangkou
// Date:  inca    98/08/18

#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", HIW "������ͷ" NOR);
    set("long", @LONG
���������ݸ۵���ͷ��������ͣ����ബ(chuan)����ͷ��ʮ����
�֣����˻���Ĺ��������ػ��»���һЩ�����ڴ˵Ⱥ�������������
�������£��⴬�Ĵ���æ�Ĳ����ֺ���ϲЦ�Կ���
LONG
    );
	

        set("exits", ([
                "west"  : "/d/hangzhou/duanqiao",
        ]));

    set("item_desc", ([
         
       "chuan" :"�����кܶബ�����Ҫ�����Ļ��������Ҵ�����һ����\n",    ]));
    set("objects", ([
		__DIR__"npc/shaogong4" : 1,
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
			 if( !(room = find_object(__DIR__"xiaozhou3")) )
            			room = load_object(__DIR__"xiaozhou3");
        		if( room = find_object(__DIR__"xiaozhou3") ) 
            			if((int)room->query("yell_trigger")==1 ) 
				 return notify_fail("����˵�����͹ٲ�Ҫ��������û���������Ժ\n");
			else {room->set("yell_trigger", 1);
                        message("vision", me->name() + "����С����\n", environment(me), ({me}) );
                        message("vinson","��̤��ľ�壬ҡҡ�λε�����С�� \n"+
					  "��������һ�ţ����뿪��ͷ������ʻȥ\n" ,me);
                        me->move(__DIR__"xiaozhou3");}
                }
        return 1;
}
