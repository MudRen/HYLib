// mie.c  �ط�����������𽣡�

#include <ansi.h>
#include <combat.h>

//inherit F_CLEAN_UP;

inherit F_SSERVER;
int perform(object me, object target)
{
        int damage;
        string msg;
        object weapon;

        if (!target ) target = offensive_target(me);
//        if (!objectp(weapon = me->query_temp("weapon"))
//        || (string)weapon->query("skill_type") != "sword")
//                return notify_fail(RED"��ʲô��Ц��ûװ��������ʹ�����ٻ�Ӱ�����š���\n"NOR);
        if (!target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("�����ٻ�Ӱ�����š�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        if ((int)me->query_skill("shadowsteps", 1) < 80)
                return notify_fail(WHT"������ٻ�Ӱ��������죬��ʹ���������ٻ�Ӱ�����š���\n"NOR);

        if ( me->query_temp("weapon"))
                        return notify_fail("��ʹ�õ��������ԡ�\n");
	if( (int)me->query("neili") < 500  ) 
		return notify_fail("�������������\n");
        me->add("neili",-200);

        if ((int)me->query("neili")<200)
        {
               return notify_fail(HIC"����������������û�ܽ������ٻ�Ӱ�����š�ʹ�꣡\n"NOR);
        }
	msg = HIC  "$Nʩչ�������ٻ�Ӱ�����ţݣ����μ�����ת��һ����Ӱ��ͻȻ��$n�ɳ�һ�ȣ�\n" NOR;
                me->start_busy(2);
                if (!target->is_busy())
                target->start_busy(random(2));
                damage = (int)me->query_skill("shadowsteps", 1);
                damage = damage + random(damage);
                target->receive_damage("qi", damage/2);
                target->receive_wound("qi", damage/2);
                me->add("neili", -50);
		message_combatd(msg, me, target);
		COMBAT_D->report_status(target);
         msg = HIC  "��Ӱ���ַɳ�һ�ȣ�\n" NOR;
                 me->start_busy(2);
                if (!target->is_busy())
                target->start_busy(random(2));
                damage = (int)me->query_skill("shadowsteps", 1);
                damage = damage + random(damage);
                target->receive_damage("qi", damage/2);
                target->receive_wound("qi", damage/2);
                me->add("neili", -50);
		message_combatd(msg, me, target);
		COMBAT_D->report_status(target);
        msg = HIC  "$N���ν��ȣ���������һ�ȣ�\n" NOR;
                  me->start_busy(2);
                target->start_busy(random(2));
                damage = (int)me->query_skill("shadowsteps", 1);
                damage = damage + random(damage);
                target->receive_damage("qi", damage/2);
                target->receive_wound("qi", damage/2);
                me->add("neili", -50);
                  message_vision(msg, me, target);
		COMBAT_D->report_status(target);
    return 1;
}


