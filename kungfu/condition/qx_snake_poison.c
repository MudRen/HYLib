#include <ansi.h>

int update_condition(object me, int duration)
{
   int damage,damage2;
damage=me->query("qi")/8;
damage2=me->query("jing")/8;
if (damage > 5000) damage=5000;   
if (damage2 > 5000) damage2=5000;   	
	
if ((int)me->query("jing") < 100000)
{
    me->receive_damage("jing", damage2);
    me->receive_wound("jing", damage2);
 }  else    me->receive_wound("jing", damage2);
      me->start_busy(random(3)+1);
if ((int)me->query("qi") < 100000)
{
    me->receive_damage("qi", damage);
    me->receive_wound("qi", damage);
}  else    me->receive_wound("qi", damage);
	
me->start_busy(6);
        me->apply_condition("qx_snake_poison", duration - 1);
if (me)
{
        message_vision(BLU"$N�����巢������ɫ�����⣬��������ʹ����,Ť��ɹ�������.\n"NOR, me);
        tell_object(me, HIR "���е������߶������ˣ�\n" NOR );
}
        if( duration < 1 ) return 0;
        return 1;
}


