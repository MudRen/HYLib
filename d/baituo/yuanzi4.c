#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "Ժ��");
        set("long", @LONG
����ѷ����ϰٶѵ�ʯͷ����Щʯͷ�д���С������һ�䷿�ݣ�С��
һ��Ѽ������״��඼��Բ���Ρ��㷢�ִ���Щʯͷ֮��ķ�϶(fengxi)
��Ʈ��һ�ɹɵ��ȳ�ζ��ʹ���Ҫ��Ż�ˡ�
LONG);
        set("exits", ([
              "southeast" : __DIR__"yuanzi2",
              "northeast" : __DIR__"yuanzi5",
              "east" : __DIR__"yuanzi3",
        ]));
         set("item_desc", ([                    
                "fengxi": "\n��϶�������һƬ������ԼԼ��ɳɳ�����졣\n",
        ]));
        set("outdoors", "����ɽ");
        setup(); 
}

void init()
{   
	object me = this_player();
      	if(me->query_skill("poison", 1) < 50)
      		me->apply_condition("snake_poison", me->query_condition("snake_poison") + 5);
      	if(me->query_temp("baituo_stone") > 2){
          	me->delete_temp("baituo_stone");
          	me->set_temp("baituo_wait", 1);
          	call_out("do_wait", 90, me);
        	}     
        add_action("do_enter", "enter");
        add_action("do_enter", "zuan");                   
}

int do_enter(string arg)
{
        object me = this_player();

        if( (int)me->is_busy() || me->is_fighting()) 
        	return notify_fail("����æ���ء�\n");
        if( !arg || arg=="" ) return 0;

        if (arg == "fengxi" ){   
        	message_vision("$N�ٿ���϶�ڵ���ʯ�ӣ�һ��������϶�����˽�ȥ��\n",me);
                me->move(__DIR__"fengxi2");
                message("vision",me->name() + "���������˽�����\n",environment(me), ({me}) );
                return 1;
        }     
}

void do_wait(object me)
{
	object room;
	if(!me || environment(me) != this_object()
	|| !living(me) || !me->query_temp("baituo_wait")) 
		return;
        message("vision","\nʯ����Ȼ������������������һ�໺���ƿ�������¶��һ���ڶ�������ڡ�\n\n", this_object() );
        set("exits/down", __DIR__"midao");
        if( room = load_object(__DIR__"midao") ) {
                room->set("exits/up", __FILE__);
                message("vision","\nͷ���ϵ�ʯ����Ȼ����������������¶��һ���������Ķ��ڡ�\n\n",room );
                } 
        remove_call_out("close_door");
        call_out("close_door", 5);
}


void close_door()
{
        object room;

        if( !query("exits/down") ) return;
        message("vision","\nʯ�������������������������ƻ�ԭ���������µĶ��ڸ�ס�ˡ�\n\n", this_object() );
        if( room = load_object(__DIR__"midao") ) {
                room->delete("exits/up");
                message("vision", "\nͷ���Ϸ���������������ʯ���ֻ��������˻�ȥ��������ʧ�ˡ�\n\n", room );
                }
        delete("exits/down");
}

int valid_leave(object me, string dir)
{        
       me->delete_temp("baituo_wait");
      
        return ::valid_leave(me, dir);
}
