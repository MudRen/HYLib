//ice_poison.c

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
   int damage,damage2;
damage=me->query("qi")/8;
damage2=me->query("jing")/8;
if (damage > 5000) damage=5000;   
if (damage2 > 5000) damage2=5000;   	

   if( duration < 1 ) return 0;
   if( !living(me) ) {
      message("vision", me->name() + "���������ʹ��غ���һ����\n", environment(me), me);
   }
   else {
      tell_object(me, HIB "��Ȼһ���溮�ӵ�������������֫�ٺ������еĺ������Ʒ����ˣ�\n" NOR );
      message("vision", me->name() + "������ͻȻ�������Σ����ظ�������������\n",
            environment(me), me);
   }
        me->start_busy(3);
      me->receive_wound("qi",85 + random(100));
      me->receive_wound("jing", 80);
      me->apply_condition("ice_poison", duration - 1);

   if( duration < 1 ) return 0;
   return CND_CONTINUE;
}
