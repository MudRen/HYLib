#include <ansi.h>

int valid_leave(object me, string dir)
{
       if (dir == "north") me->add_temp("mark/step",1);
       if (dir == "south") me->add_temp("mark/steps",1); 
       if (dir == "east") me->add_temp("mark/step",-1); 
       if (dir == "west") me->add_temp("mark/steps",-1); 
        
       if(me->query_temp("mark/steps") == -5 &&
          me->query_temp("mark/step") == 6){
            me->move("/d/baituo/shanlu");
            me->delete_temp("mark/steps");
            me->delete_temp("mark/step");
            tell_room(environment(me), me->name()+"����ƣ�����������ӴӸ��ɳĮ���˹�����\n",  ({ me }));  
            return notify_fail("ͻȻ����ǰ������һ��Сɽ����״�����շ塣\n");
            return 1;
            }       
           
       if(me->query_temp("mark/steps") == -12 ){
            me->move(__DIR__"senlin");
            me->delete_temp("mark/steps");
            me->delete_temp("mark/step");
            tell_room(environment(me), me->name()+"����ƣ�����������ӴӸ��ɳĮ���˹�����\n",  ({ me }));  
            return notify_fail("ͻȻ���߳��˴��ڣ�����һɭ�ִ���\n");
            return 1;
            }       
           
       if(me->query_temp("mark/step") == 11){
            me->move(__DIR__"gebi5");
            me->delete_temp("mark/steps");
            me->delete_temp("mark/step");
            return 1;
            }  
       if(me->query_temp("mark/steps") == 11){
            me->move(__DIR__"room-ji");
            me->delete_temp("mark/steps");
            me->delete_temp("mark/step");
            tell_room(environment(me), me->name()+"����ƣ�����������ӴӸ��ɳĮ���˹�����\n",  ({ me }));  
            return notify_fail("���������ˣ��������߳������ˣ�\n");
            return 1;
            }  

       if((me->query_temp("mark/step") == 7 && me->query_temp("gc_n")) ||
          (me->query_temp("mark/steps") == -7 && me->query_temp("gc_w")) ||
          (me->query_temp("mark/steps") == 7 && me->query_temp("gc_s")) ||
          (me->query_temp("mark/step") == -7 && me->query_temp("gc_e"))){
            me->move(__DIR__"luzhou");
            me->delete_temp("mark/steps");
            me->delete_temp("mark/step");
            me->delete_temp("gc_n");
            me->delete_temp("gc_s");
            me->delete_temp("gc_w");
            me->delete_temp("gc_e");
            tell_room(environment(me), me->name()+"����ƣ�����������ӴӸ��ɳĮ���˹�����\n",  ({ me }));  
            return notify_fail("������ã����ҵ���һ��ɳĮ���ޣ�\n");
                        return 1;
            }
 
       if((me->query_temp("mark/step") == 7 && me->query_temp("mark/steps") == 3 && 
           me->query_temp("mark/step") == -3 && me->query_temp("gc1_n")) ||
          (me->query_temp("mark/steps") == -7 && me->query_temp("mark/step") == -3 &&
           me->query_temp("mark/step") == 3 && me->query_temp("gc1_w")) ||
          (me->query_temp("mark/steps") == 7 && me->query_temp("mark/step") == -3 &&
           me->query_temp("mark/steps") == -3 && me->query_temp("gc1_s")) ||
          (me->query_temp("mark/step") == -7 && me->query_temp("mark/step") == 3 &&
           me->query_temp("mark/steps") == 3 && me->query_temp("gc1_e"))){
            me->move(__DIR__"shulin");
            me->delete_temp("mark/steps");
            me->delete_temp("mark/step");
            me->delete_temp("gc1_n");
            me->delete_temp("gc1_s");
            me->delete_temp("gc1_w");
            me->delete_temp("gc1_e");
            tell_room(environment(me), me->name()+"����ƣ�����������ӴӸ��ɳĮ���˹�����\n",  ({ me }));  
            return notify_fail("�ף��㷢�������Ѿ����Ǹ��ɳĮ�ˣ�\n");
            return 1;
            }       
        return ::valid_leave(me, dir);
}

void init()
{
       object me, *ob, *inv, ob1;
       string msg, msg1;
       int i, j;
       me = this_player();
       ob = all_inventory(environment(me));
       msg = YEL"\nͻȻһ�ɼ���ε�������һ��Ƭ��ɳ��ֻ���������������Ƕ���ɳ�������ޱ��޼ʵĴ�ɳĮ֮�У�
���������̵صĴ��ɳ�£���������е�һҶС��һ�㣬ֻ������������ȫ�ް������֮����\n"NOR;
       msg1 = HIR"������Լ��Ѿ���ƣ�����ˣ����ϵĻ�ɳȴԽ��Խ�񡭡�\n"NOR;

       if(ob1 = present("bai shoujuan", me)){
          write(WHT"�����հ��־��ϵ���ʾ���ܿ���߳��˴��ڡ�\n"NOR);
          me->move(__DIR__"caoyuan");
          destruct(ob1);
          me->delete_temp("mark/steps");
          me->delete_temp("mark/step");
          tell_room(environment(me), me->name()+"��������شӸ��ɳĮ���˹�����\n",  ({ me }));  
          write("ͻȻ��һ�����񣬰��־�紵���ˣ�\n");
          return;
          }  
       if(userp(me)){ 
         if(me->query_temp("li_meet") == 2){
              message_vision(msg, me); 
              tell_object(me, msg1);
              me->delete_temp("mark/steps");
              me->delete_temp("mark/step"); 
              me->unconcious();             
              me->move(__DIR__"shulin");
              tell_room(environment(me), "ͻȻһ����紵���������������㱳����֣�\n", ({ me }));  
              return;
              }
         else if(me->query("water") < 20) 
              { 
              message_vision(msg, me);              
              for(i=0; i<sizeof(ob); i++) {
                  tell_object(ob[i], msg1);
                  inv = all_inventory(ob[i]);
                    for(j = 0; j < sizeof(inv); j++){
                      if(!inv[j]->query("unique")) continue;
                       destruct(inv[j]);
                      }
                  ob[i]->unconcious();
                  ob[i]->move(__DIR__"caoyuan"+(1+random(7)));
                  tell_room(environment(ob[i]), HIR"ͻȻһ���紵��������һ��������\n"NOR,  ({ ob[i] }));  
                  ob[i]->delete_temp("mark/steps");
                  ob[i]->delete_temp("mark/step");
                  ob[i]->delete_temp("gc_n");
                  ob[i]->delete_temp("gc_s");
                  ob[i]->delete_temp("gc_w");
                  ob[i]->delete_temp("gc_e");
                  ob[i]->delete_temp("gc1_n");
                  ob[i]->delete_temp("gc1_s");
                  ob[i]->delete_temp("gc1_w");
                  ob[i]->delete_temp("gc1_e");
                  }
              return;
              }
         else if(me->query_skill("dodge", 1) <= 150) { 
              me->add("jingli", -15);
              me->add("water", -10);
              }
         else {
              me->add("jingli", -5);
              me->add("water", -5);
              }
      }
}