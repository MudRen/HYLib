// xx_poison.c
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
      tell_object(me, HIB "��Ȼһ��̹ǵ��溮Ϯ�������е������ƶ������ˣ�\n" NOR );
      message("vision", me->name() + "������ͻȻ�������Σ����ظ�������������\n",
            environment(me), me);
   }
      me->receive_wound("qi",25 + random(10));
        me->start_busy(random(3));
      me->receive_wound("jing", 20);
      me->apply_condition("x2_poison", duration - 1);

   if( duration < 1 ) return 0;
   return CND_CONTINUE;
}
