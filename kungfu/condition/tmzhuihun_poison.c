#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
   if( duration < 1 ) return 0;
   if( !living(me) ) {
      message("vision", me->name() + "ʹ��غ���һ����\n", environment(me), me);
   }
   else {
      tell_object(me, HIC "��Ȼһ���������溮Ϯ�������е����ŵ�׷������ڷ����ˣ�\n" NOR );
      message("vision", me->name() + "������ͻȻ�������Σ�����һ��Ť��,�������ʹ�ࡣ\n",
            environment(me), me);
   }
if (me->query("qi") >200)
      me->receive_wound("qi",185 + random(10));
if ((int)me->query("jing") < 100000)
{
      me->receive_wound("jing", me->query("jing")/15);
}else    me->receive_wound("qi", 2000);
      me->start_busy(3);
if (me->query("neili") >200)
      me->add("neili",-150);
      me->apply_condition("tmzhuihun_poison", duration - 1);
   if( duration < 1 ) return 0;
   return CND_CONTINUE;
}
