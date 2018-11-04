// zhua_poison.c
#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
   int damage,damage2;
damage=me->query("qi")/10;
damage2=me->query("jing")/10;
if (damage > 5000) damage=5000;   
   if( duration < 1 ) return 0;
   if(!living(me) ) {
      message("vision", me->name() + "ʹ���������.\n", environment(me), me);
   }
   else {
      tell_object(me, HIB "��Ȼһ˿��������������, �����Ľ�������֫�ٺ���ԭ�����е���Ѫ��ץ�����ˣ�\n" NOR );
  message("vision", me->name() + HIR "������ͻȻһ�����, ����ҧ�ÿ������졣\n"+me->name()+"��Ȼ����һ������,����¶��ʹ��������Ц�ݡ�\n" NOR,
            environment(me), me);
   }
        me->start_busy(3);
      me->receive_damage("qi",damage);
      me->receive_wound("jing",damage2);
      me->apply_condition("zhua_poison", duration - 1);
   if( duration < 1 ) return 0;
   return CND_CONTINUE;
}
