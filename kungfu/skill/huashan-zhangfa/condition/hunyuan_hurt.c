#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{    
      tell_object(me, HIR "���Ȼ�е����ھ�����к��ͷ������ġ�\n" NOR );
      message_vision(HIR"$NͻȻ���ȷ����ȵ�ȫ��������������һ�㡣\n"NOR, me);

      me->receive_damage("qi", 55);
      me->receive_wound("qi", 50);
me->start_busy(2);
//      me->set_temp("last_damage_from", "���˷���");
      me->apply_condition("hunyuan_hurt", duration - 1);
     if( duration < 1 ) return 0;
     return CND_CONTINUE;
}
