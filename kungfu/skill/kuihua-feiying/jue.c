// jue.c ������

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        int damage;
        object weapon = me->query_temp("weapon");

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( (int)me->query_skill("pixie-jian", 1) < 140 )
                return notify_fail("��ı�а����������죬����ʹ�þ����롣\n");

        if( (int)me->query_dex() < 35  )
                return notify_fail("�����̫�ͣ�����ʹ�þ����롣\n");
 
        if( (int)me->query("neili", 1) < 600 )
                return notify_fail("�������������㣡\n");     
	if( (int)me->query_skill("kuihua-feiying", 1) < 50 )
		return notify_fail("��Ŀ�����Ӱ��������졣\n");

	if( (int)me->query_skill("kuihua-xinfa", 1) < 60 )
		return notify_fail("��Ŀ����ķ�������졣\n");
      
     if( (int)me->query("qi") > (int)me->query("max_qi") / 2 )
                return notify_fail("�������Ǿ������������������ʹ�ã���\n");    

      if (me->is_busy()) 
   {
    message_vision(MAG "$N��һ����У����η�����������һ����ƽ�$N��������û����Ȼ�����˹�����\n" NOR, me);
me->start_busy(1);
}

  message_vision(RED"\n$N�͵�������$n��ȥ����ָһ����ϸ����˳�ȥ������$n��Ŀ��\n\n"NOR, me, target);
  
   me->add("neili", -300);
      
if((me->query("combat_exp")) > (int)target->query("combat_exp")/3 &&
 me->query_dex() >random((int)target->query_dex())) {
        message_vision(HIR"\n$n⧲����������һ�����������룡\n"NOR, me, target);
        tell_object(target, HIY "��о�ϸ���������Լ���ͫ��֮�У��������ֱ�����ԣ���������֮�ǣ�\n" NOR);
                me->start_busy(2);
                target->start_busy(2);
                me->add("neili", -300);
                damage = (int)target->query("max_qi");
                damage = damage/10;
                damage = damage*7;
                
                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage/2);
//                me->query_temp("weapon")->move(target);
               }
         else 
              {
                target->start_busy(2);
//                me->query_temp("weapon")->move(environment(target));
                message_vision(HIY"\n����$n������$N����ͼ���������˿�ȥ��\n"NOR, me, target);
                me->set("neili", 0);
              }

        return 1;
}

