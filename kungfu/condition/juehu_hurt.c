#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{   int l_temp;
    me->set_temp("last_damage_from", "��Ԫ�ݽ�");
//    if( !living(me) ) return CND_CONTINUE;
   if (random(4)>=3 )
   {
    if( !living(me) )
      message("vision", me->name() + "����һ����£��������[����]�졣\n", environment(me), me);
    else
     {
      tell_object(me, HIB "���Ȼ�е����ھ�Ԫ��й��ͷ������ġ�\n" NOR );
      message("vision", me->name() + "ͻȻ���ȷ������ֱ���һ�ţ����ֱ������\n",
            environment(me), me);
      }
         l_temp=50-(int)me->query_skill("force", 1)/20;
        me->add("jing",-l_temp);
         l_temp=60-(int)me->query_skill("force", 1)/20;
        me->add("qi",-l_temp);
        if ((int)me->query_skill("force", 1)<180)
          { me->receive_wound("jing", random(1));
            if( me->query("qi",1)<0)
               me->unconcious();
            if( me->query("eff_jing",1)<0)
               me->die();
          } 
    }
     me->apply_condition("juehu_hurt", duration - 1);
     if( duration < 1 ) return 0;
     return CND_CONTINUE;
}

string query_type(object me)
{
	return "hurt";
}
