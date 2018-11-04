#include <ansi.h>
#include <combat.h>

#define QIAN "��" HIW "��Ӱ���" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
	object weapon;
	string msg;
	int ap, dp;
        int count;
	int i, attack_time;


	if (! target) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
                return notify_fail(QIAN "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԣ�����ʩչ" QIAN "��\n");

	if ((int)me->query_skill("jinshe-jian", 1) < 180)
		return notify_fail("��Ľ��߽���������죬����ʩչ" QIAN "��\n");

	if (me->query("neili") < 260)
		return notify_fail("�����������������ʩչ" QIAN "��\n");

        if (me->query_skill_mapped("sword") != "jinshe-jian")
                return notify_fail("��û�м������߽���������ʩչ" QIAN "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

	msg = HIW "\n$N" HIW "һ������������" + weapon->name() + HIW "��ʱ�������������ߣ�"
              "������˷�ͬʱ��$n" HIW "Ϯȥ��\n" NOR;

        message_vision(msg, me, target);

	ap = me->query_skill("sword");
	dp = target->query_skill("dodge");
        attack_time = 4;

	if (ap / 2 + random(ap * 2) > dp)
	{
		msg = HIR "���$n" HIR "��$N" HIR "���˸����ֲ�����$n"
                      HIR "��æ�мܣ����нпࡣ\n" NOR;

                count = ap / 5;
                attack_time += random(ap / 35);
        } else
        {
                msg = HIC "$n" HIC "��$N" HIC "�⼸����ʽ����������"
                      "�ޱȣ�ֻ�ÿ���мܡ�\n" NOR;
                count = 0;
        }
    	message_combatd(msg, me, target);

        if (attack_time > 9)
                attack_time = 9;

        me->add_temp("apply/attack", count);
        me->add_temp("apply/damage", count);
        me->add("neili", -attack_time * 30);
	me->start_busy(2);

        me->set_temp("jinshe-jian/lian", 1);
	for (i = 0; i < attack_time; i++)
	{
		if (! me->is_fighting(target))
		       break;

                if (! target->is_busy() && random(3) == 1)
                       target->start_busy(3);
 
	        COMBAT_D->do_attack(me, target, weapon, 0);
	}
        me->delete_temp("jinshe-jian/lian");

        me->add_temp("apply/attack", -count);
        me->add_temp("apply/damage", -count);
	return 1;
}
