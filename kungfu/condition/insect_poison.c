//Cracked by Roath
// insect_poison.c

#include <ansi.h>
#include <condition.h>
inherit F_CLEAN_UP;
int update_condition(object me, int duration)
{
   if( !living(me) ) {
      message("vision", me->name() + "ʹ��غ���һ����\n", environment(me), me);
   }
   else {
      if(me->query("eff_jing") > me->query("max_jing")/2) {
      tell_object(me, HIB "�㿪ʼ�е������ñ�����\n" NOR );
      message("vision", me->name() + "ͻȻ�沿�鴤���ֽŷ�������\n",
            environment(me), me);
      }
      else if(me->query("eff_jing") > me->query("max_jing")/4) {
      tell_object(me, HIB "��е��������ѣ���֫��������������\n" NOR );
      message("vision", me->name() + "ͻȻ���۷�ֱ��ȫ��鴤������\n",
            environment(me), me);
      }
      else {
      tell_object(me, HIB "�㿪ʼ�е�������ת�����ܾ��ﶼ����������Զȥ��\n" NOR );
      message("vision", me->name() + "ͻȻˤ���ڵأ��Ŵ���ͣ��ֽ������س鶯�š�\n",
            environment(me), me);
      }
   }
      me->receive_damage("qi", 30);
	me->apply_condition("insect_poison", duration - 1);
	if(me->query("poisoner"))
	me->receive_wound("jing", 5);
	else	
	me->receive_wound("jing", 5);

     if( duration == 1) me->delete("poisoner");
     if( duration < 1 ) return 0;
   return CND_CONTINUE;
}
