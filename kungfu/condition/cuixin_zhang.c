//ice_poison.c

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
   int damage,damage2;
damage=me->query("qi")/18;
damage2=me->query("jing")/18;
if (damage > 5000) damage=5000;   
if (damage2 > 5000) damage2=5000;   	

   if( duration < 1 ) return 0;
   if( !living(me) ) {
      message("vision", me->name() + "һ���Һ�����Ϣ���������ۡ���һ�����һ�����Ѫ��\n", environment(me), me);
   }
   else {
      tell_object(me, HIB "��ֻ�е������������ڲ�ֹ���綾���ģ����������˴������ƾ��ĸ��ţ�\n" NOR );
      message("vision", me->name() + "������ͻȻ�������Σ����ظ�������������\n",
            environment(me), me);
   }
        me->start_busy(3);
      me->receive_wound("qi",damage);
      me->receive_wound("jing", damage2);
      me->apply_condition("cuixin_zhang", duration - 1);

   if( duration < 1 ) return 0;
   return CND_CONTINUE;
}
