// mie.c  �ط�����������𽣡�

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        int damage;
        string msg;
        object weapon;

        if (!target ) target = offensive_target(me);
        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail(RED"��ʲô��Ц��ûװ��������ʹ������һЦ����\n"NOR);
        if (!target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("������һЦ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        if ((int)me->query_skill("softsword", 1) < 100)
                return notify_fail(WHT"��Ļط��������������죬��ʹ����������һЦ����\n"NOR);
        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "sword")
                        return notify_fail("��ʹ�õ��������ԡ�\n");
	if( (int)me->query("neili") < 500  ) 
		return notify_fail("�������������\n");
        if (me->is_busy())
		return notify_fail("����æ���ء�\n");
        if ((int)me->query("neili")<200)
        {
               return notify_fail(HIC"����������������û�ܽ����𽣡�ʹ�꣡\n"NOR);
        }
	msg = HIR  "$N����"+ weapon->name() +"�Ľ�âɢ�����������޵�ǳЦ������" NOR;
	msg +=  HIW "����һ������ʧ��������\n" NOR;
                me->start_busy(2);
                if (!target->is_busy())
                target->start_busy(random(2));
                damage = (int)me->query_skill("softsword", 1);
                damage = damage + random(damage);
                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage);
                target->receive_damage("jing", damage/6);
                target->receive_wound("jing", damage/6);
            	  target->add("neli",-100);
                me->add("neili", -100);
		message_combatd(msg, me, target);
		COMBAT_D->report_status(target);
        return 1;
}

