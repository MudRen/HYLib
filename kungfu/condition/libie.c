// libie.c ���

#include <action.h>
#include <ansi.h>
#include <command.h>
#include <condition.h>


inherit F_CLEAN_UP;



int update_condition(object me, int duration)

{
        mapping exits;
        string *dirs;
        //duration--;
        //if( duration < 0 )      return 0; 
        me->receive_wound("jing", 60);
        if(mapp(exits = environment(me)->query("exits"))) { 
                dirs = keys(exits);
                tell_object(me, WHT"�����к�Ȼӿ��Ī���˸У�ֻ������������ãȻ��֪������\n"NOR); 
                message("vision", me->name() + "������࣬ʧ��һ������Ŀ�ĵ����ߡ�\n", 
                        environment(me), me); 
if (userp(me))                
{
               GO_CMD->do_flee(me);
}
else
{
me->start_busy(6);
}
        }
      me->apply_condition("libie", duration - 1);

   if( duration < 1 ) return 0;
   return CND_CONTINUE;
}    
