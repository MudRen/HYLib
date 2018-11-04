// mg1.c �Թ�����
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", CYN "�߲��Թ�" NOR);
        set("long", @LONG
���߽��Թ�����������������ĳ������ڶ�����֪ǰ����ʲô��
��������������Ĵ���(gate)��
LONG);
        set("no_sleep_room", 1);
        set("exits", ([
              "north" : __DIR__"mg2",
        ]));    
        set("item_desc",([
                "gate" : "����������߲���������ʱ�Ѿõľ���и���(huan)�������(turn)����\n",
           ]));
        setup(); 
}

void init()
{
	 add_action("do_turn", "turn");
}

int do_turn(string arg)
{  
        object room, me;
        me = this_player();        
        if (query("exits/out"))
		  return notify_fail("���Ѿ��Ǵ��ˡ�\n");
        if (!arg || arg == "")  return 0;
        if (arg == "huan"){
          if (!me->query_temp("turned")){
             message_vision("$Nʹ��ת��������������֨֨������������ȴʼ�մ򲻿���\n", me);
             me->set_temp("turned", 1);
             return 1;
             }
           message_vision("$N������ת��������ͻȻ���ź��һ�����ˡ�\n$Nһû���񣬲�����ȥ��\n", me);
           set("exits/out", __DIR__"mg-door");
           me->delete_temp("turned");
         if( room = load_object(__DIR__"mg-door") ) {
             room->set("exits/enter", __FILE__);
             message("vision", "���洫��һ��֨֨�����������ű����ƿ��ˡ�\n",room );
             } 
           remove_call_out("close_door");
           call_out("close_door", 8);
           return 1;
           }
}

void close_door()
{
        object room;

        if( !query("exits/out") ) return;
        message("vision","���һ�����������Լ������ˡ�\n", this_object() );
        if( room = load_object(__DIR__"mg-door") ) {
                room->delete("exits/enter");
                message("vision", "�������Լ������ˡ�\n", room );
                  }
        delete("exits/out");
}

int valid_leave(object me)
{        
       me->delete_temp("turned");       
       return ::valid_leave(me);
}