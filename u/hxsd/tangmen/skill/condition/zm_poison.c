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
      tell_object(me, HIB "��Ȼһ��̹ǵ���ʹϮ�������е����ŵ���ĸ����֮�������ˣ�\n" NOR );
      message("vision", me->name() + "������ͻȻ�������Σ�����һ��Ť��,�������ʹ�ࡣ\n",
            environment(me), me);
   }
if (me->query("qi") >100)
      me->receive_wound("qi",85 + random(10));
if (me->query("jing") >100)
      me->receive_wound("jing", 80);
      me->add("neili",-me->query("neili")/15);
      me->start_busy(3);
      me->apply_condition("zm_poison", duration - 1);
   if( duration < 1 ) return 0;
   return CND_CONTINUE;
}
