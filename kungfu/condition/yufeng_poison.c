// yufeng_poison.c ����붾
// By Kayin @ CuteRabbit Studio 1999/3/23 new

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
      tell_object(me, HIR "��Ȼһ�󳹹ǵ����������е�����뷢���ˣ�\n" NOR );
      message("vision", me->name() + "ͻȻ�����ڵ������������ϵ�����ץ��\n",
            environment(me), me);
   }
      me->receive_wound("qi",55 + random(100));
      me->receive_wound("jing", 50);
      me->apply_condition("yufeng_poison", duration - 1);
      me->start_busy(2);
   if( duration < 1 ) return 0;
   return CND_CONTINUE;
}
