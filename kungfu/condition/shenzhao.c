#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
   if( duration < 1 ) return 0;
   if( !living(me) ) {
      message("vision", HIR "ֻ��"+me->name()+ HIR "ǺǺ��������������ҡ�Σ�˫"
              "�Ƚ����������ƺ�������һ�㡣\n" NOR, environment(me), me);
   }
   else {
      tell_object(me, HIB "��ֻ����Ϣ���ͣ�����������һ�����ǵ�ͨ�죬��Ҫ��������\n" NOR );
if (environment(me) &&  me)
{
      message("vision", HIR "ֻ��"+me->name()+ HIR "ǺǺ��������������ҡ�Σ�˫"
              "�Ƚ����������ƺ�������һ�㡣\n" NOR,
            environment(me), me);
}
   }
      me->receive_wound("qi",50 + random(100));
      me->receive_wound("jing", 50);
      me->start_busy(2);
      me->apply_condition("shenzhao", duration - 1);

   if( duration < 1 ) return 0;
   return CND_CONTINUE;
}


