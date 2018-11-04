#include <ansi.h>
inherit ROOM;
string* obj = ({
       __DIR__"obj/book1",
       __DIR__"obj/book2",
       __DIR__"obj/book3",
       __DIR__"obj/book4",
});
void create()
{
        set("short", "��ʯ��");
        set("long", @LONG
����������Χȫ�Ǿ�ʯ���������������ҵ���ʯ�ӣ����Ǳ��˻����
ʯ������������顣����һ��ƽ������ʯ���϶���һֻѩ�׵ĸ�󡡣
�������߰˾���һ��Ѷ�����������������(find)����
LONG);        
        set("objects", ([
                    __DIR__"npc/chanchu" : 1,
        ]));
         set("item_desc", ([                    
                "stone": "\n��Щ��ʯ���а��棬���ó��Ǳ��������������õġ�\n",
        ]));
        set("outdoors", "����ɽ");
        setup(); 
}

void init()
{
       	object me = this_player();       
       	if(!me->query_temp("baituo_yun") 
       	&& me->query("id") != "xuanbing chanchu" 
       	&& me->query("id") != "snowman"){
             	message_vision(HIW"�������ͻȻ���𣬶���$Nһ�ڶ��������\n"NOR,this_player()); 
             	tell_object(me, HIB "��е�����һ�����Σ���ʱ���˹�ȥ��\n" NOR ); 
             	me->unconcious();
             	me->move(__DIR__"yuanzi5");
             	tell_room(environment(me), me->name()+"ͻȻ�Ӿ�ʯ֮��ֱ�����������ȡ���һ��ˤ�ڵ��ϣ�\n", ({ me }));
          	if(me->query_skill("poison", 1) < 100) 
          		me->unconcious();              
          	else me->add("max_neili", -5);
          	}  
        add_action("do_climb", "climb");
        add_action("do_climb", "pa");
        add_action("do_strike", "strike");       
        add_action("do_find", "find");
        add_action("do_find", "zhao");
        add_action("do_find", "fan");

}

int do_climb(string arg)
{
        object me = this_player();
        if( !arg || arg=="" ) return 0;
        
        if( (int)me->is_busy() || me->is_fighting()) 
        	return notify_fail("����æ���ء�\n");
        	
        if (arg == "stone" ){   
           	message_vision("$N�ֽŲ��ã������˾�ʯȥ������һ�ݣ��Ѿ����˳�ȥ��\n", me);                      
               	me->move(__DIR__"yuanzi5");
               	message("vision", me->name() + "���������˳�����\n",environment(me), ({me}) );
               	return 1;
        }     
        return 0;
}

int do_strike(string arg)
{
        int improve, cost, hmglevel;
        object me = this_player();
        
        improve = me->query_int() / 10 + random(me->query_int() * 5 / 6);
        hmglevel = me->query("oyf_hamagong");
        if( !arg || arg=="" ) return 0;
        
        if( (int)me->is_busy() || me->is_fighting()) 
        	return notify_fail("����æ���ء�\n");
        	
        if (arg == "stone" ){             
            	if(!me->query_skill("hamagong", 1))  
               		return notify_fail("������ָ�����ƾ�ʯ������¶��һ˿�ѿ�����ɫ��\n");
            	if(me->query_skill("hamagong", 1) > 64 && hmglevel < 2)  
               		return notify_fail("������ָ�����ƾ�ʯ������¶��һ˿�ѿ�����ɫ��\n");
            	if(me->query_skill("hamagong", 1) > 100)  
               		return notify_fail("��һ�����ʯ��ȥ��ֻ�����һ������ʯ��������������룡\n");
               		
        	cost = 600 / (int)me->query("int");
        	cost = 600 / (int)me->query("int");

           	if ((int)me->query("jing") < cost || (int)me->query("jing") < cost){
                	message_vision("$N��������, һ�����������������$N���˹�ȥ��\n",me);
                	me->unconcious();
                	return 1;
                } 
                
                message_vision("$NĬ�и�󡹦�ھ���������˫��֮�ϣ�һ�������ʯ��ȥ��\n"NOR, me);  
           	me->improve_skill("hamagong", improve);            
           	me->improve_skill("strike", improve/4); 
           	me->receive_damage("jing", cost);
           	me->receive_damage("jing", cost);                        
           	return 1;
        }     
        return 0;
}

int valid_leave(object me)
{        
       me->delete_temp("baituo_yun");       
       return ::valid_leave(me);
}


int found(object me)
{
        object ob = new( obj[random(sizeof(obj))] );
        ob->move(me);
        message_vision("$N���˰��죬�ҵ���" + ob->query("name") + "��\n", me);
        me->set_temp("baituo_find", 1);
        return 1;
}

int do_find()
{
       object me = this_player();
       if( (int)me->query_temp("baituo_find") ) 
                return notify_fail("���Ѿ����˶����ˣ��߰ɡ�\n");
       if (me->query_skill("hamagong", 1) && 
           me->query_skill("poison", 1) > 30){
                message_vision("$N���ű�������Ʒ�����ҷ��š�\n", me);
                found(me);    
                }
       else if (me->query_skill("poison", 1) > 50){
                message_vision("$N���ű�������Ʒ�����ҷ��š�\n", me);
                if(random((int)me->query("kar")) < 15){
                     write("�����˿�����ͻȻ����ͷ��һ��ѣ�Ρ�\n");
                     me->unconcious();
                     }
                else found(me);    
                }
       else { 
                message_vision("$N���ű�������Ʒ�����ҷ��š�\n", me);
                write("�����˿�����ͻȻ����ͷ��һ��ѣ�Ρ��������ã����ж��ˣ�\n");
                me->apply_condition("snake_poison", me->query_condition("snake_poison")+22);
                me->unconcious();
                }
       return 1; 
}

