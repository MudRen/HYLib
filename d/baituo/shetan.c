#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", BLU"��̶"NOR);
        set("long", @LONG
һ���������ˮ̶��ˮ��������ɸߡ���о���ˮ���ж�����������
�������������ߣ�����(jumpup)�ɣ�
LONG);
        set("objects", ([
                    __DIR__"npc/jumang" : 2
        ]));
        set("outdoors", "����ɽ");
        setup(); 
}

void init()
{
        object ob;       
        if (interactive(ob = this_player())) {
               remove_call_out("greeting");
               call_out("greeting", 1, ob);
               }       
       	add_action("do_jumpup", "jumpup");
}

int do_jumpup(string arg)
{
      	object me = this_player();
      	
      	if(me->query("jing") < 200 ) 
        	return notify_fail("���Ѿ�û�о�������ȥ�ˡ�\n");

        if(me->is_busy() ) 
        	return notify_fail("����æ���ء�\n");
        	
        if (objectp(present("ju mang", environment(me)))){
        	me->receive_damage("qi", 150);
           	me->receive_wound("qi", 100);
           	me->receive_damage("jing", 100);
       		if( me->query_dex() > 20 && me->query_dex() < 26) {
           		message_vision(HIR"$N��������һ�ݣ�ȴ�ֱ�������ס��˫������������\n"NOR, me);
           		me->receive_damage("qi", 200);
           		me->receive_wound("qi", 250);
           		}
       		if(me->query_dex() >= 26 && me->query_dex() < 32) {
           		message_vision(HIY"$N��������һ�ݣ������ֱ�������ס��˫�㣬�������ӳ�����̶��\n"NOR, me);
           		me->receive_damage("qi", 100);
           		me->receive_wound("qi", 50);
           		me->move(__DIR__"yuanzi1");
           		tell_room(environment(me), me->name()+"����̶֮��������������һ����ɫ�԰׵������ڵء�\n", ({ me }));
          		}
       		if(me->query_dex() >= 32) {
           		message_vision(HIR"$N��������һ�ݣ���������̶��\n"NOR, me);
           		me->move(__DIR__"yuanzi1");
           		tell_room(environment(me), me->name()+"����̶֮������������ģ���Ǳ�������\n", ({ me }));
          		}
       		else { 
           		message_vision("$Nʹ��һ��������������ȥ������������ҧ��һ�ڣ�\n", me);
           		me->receive_damage("qi", 400);
           		me->receive_wound("qi", 300);
           		me->receive_damage("jing", 100);
           		}
       		}
       else { 
           	message_vision("$Nʹ��һ�ݣ���������̶��\n", me);
           	me->receive_damage("qi", 50);
           	me->receive_damage("jing", 50);
           	me->move(__DIR__"yuanzi1");
           	tell_room(environment(me), me->name()+"ͻȻ����̶֮�����˳����������־�֮ɫ��\n",({ me }));
        	}
       return 1;
}

int greeting(object ob)
{
        object me = this_player();        
	if( (int)me->query_temp("baituo_climb") < 2) {
        	message_vision(HIR"$N��ǽ���������������������˾������ϣ�\n��û�ع��������Ѿ���������ס�ˣ�\n"NOR, me);
           	write(BLU"�㱻������ס��Խ��Խ��������\n��е�һ�����ﶼ��ʼ����Զ�����ȥ�ˡ�����\n"NOR);
           	me->delete_temp("baituo_climb");
           	me->unconcious();
           	}
        else if((int)me->query_temp("baituo_climb") == 2){
           	message_vision(HIR"$N��ǽ���������������������˾������ԣ�\n����һ����˫��ȴ���Ǳ�������ס�ˣ�\n"NOR, me);
           	write(BLU"�㱻������ס��Խ��Խ���������ٲ��뷨���ܾ������ˣ�\n"NOR);
           	me->receive_damage("qi", 500);
           	me->receive_wound("qi", 200);
           	}
        else {
           	message_vision(HIR"$N�ոշ��ݹ������ͷ�������̶���о�����\n"NOR, me);
           	write(BLU"�㿴������������˹��������ߣ�\n"NOR);
           	message_vision(HIY"$N���ڰ��˫��һ�ӣ����������ֱ�ɳ�ȥ����������̶��\n"NOR, me);
           	me->receive_damage("jing", 100);
//           	me->receive_damage("neili", 100);
           	me->move(__DIR__"yuanzi1");
           	tell_room(environment(me), me->name()+"����̶֮�з�Ծ���������ϴ��ž���֮ɫ��\n",({ me }));
        	}      
        me->delete_temp("baituo_climb");
        return 1;
}
