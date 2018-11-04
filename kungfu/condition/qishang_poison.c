#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
    string msg;
   int damage,damage2;
damage=me->query("qi")/8;
damage2=me->query("jing")/8;
if (damage > 5000) damage=5000;   
if (damage2 > 5000) damage2=5000;   	
msg = HIR"$N��ɫһ�� �³�һ����Ѫ�� "NOR;
      switch(random(5)){
      case 0 : 
              msg = HIR"$NͻȻ����һ����������ȵ�Ѩ������ס�ˣ�\n"NOR;
              me->start_busy(3);
              break;
      case 1 : 
              msg = HIR"$NͻȻüͷһ�壬�������������ˣ�\n"NOR;
              me->receive_damage("qi", damage);
              me->receive_wound("qi", damage);
              break;
      case 2 : 
              msg = HIR"$N������ͻȻ�������Σ��������������������ˣ�\n"NOR;
              me->add("neili", -damage*2);
              break;
      case 3 : 
              msg = HIR"$NͻȻ����һ�Σ����������˰��ˣ�\n"NOR;
              me->receive_damage("jing", damage2);
              me->receive_wound("jing", damage2);
              break;
      case 4 : 
              msg = HIR"$N���»�㱣������ܼ��У��������������ˣ�\n"NOR;
              me->add("max_neili", -5);
              break;
      }
      me->start_busy(3);
      if (userp(me))
      {
      message_vision(msg, me);     
      }
      else
      {
        message("vision", me->name() + "��ɫһ�� �³�һ����Ѫ,����������ȭȭ�������ˡ�\n", environment(me), me);
      }
    //message("vision", msg, environment(me), me);
      me->apply_condition("qishang_poison", duration - 1);
      if( duration < 1 ) return 0;
      return CND_CONTINUE;
}

string query_type(object me)
{
	return "hurt";
}
