// qinghua_poison.c �黨��
#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
      if( me->query("couple/couple_id")){   
      tell_object(me, HIM"�����ָ�ϴ���ͻȻ��ʹ���˿�΢ϸ��ʹ����Ȼ����֮����\n"NOR);
      tell_room(environment(me), MAG + me->name()+"�����ؿ���ظ����ô������ͻ�һ�£��̲�ס��������һ�����˳�����\n" NOR,({ me }));
      me->receive_damage("qi", 35);
      me->receive_wound("jing", 35);
      me->set_temp("last_damage_from", "���黨��");
      me->apply_condition("qinghua_poison", duration - 1);
      }
      else me->apply_condition("qinghua_poison", duration - 1);
      if( duration < 1 ) return 0;
      return CND_CONTINUE;
}

string query_type(object me)
{
        return "poison";
}
