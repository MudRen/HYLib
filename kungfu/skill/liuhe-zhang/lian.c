#include <ansi.h>
#include <combat.h>

#define LIAN "��" HIG "��������" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;
        int ap, dp;
        int attack_time, i;


        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(LIAN "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(LIAN "ֻ�ܿ���ʩչ��\n");

     if ((int)me->query_skill("liuhe-zhang", 1) < 60)
                return notify_fail("��������Ʒ�������죬����ʩչ" LIAN "��\n");


        if (me->query_skill_mapped("strike") != "liuhe-zhang") 
                return notify_fail("��û�м��������Ʒ�������ʩչ" LIAN "��\n");




        if (me->query_skill("force") < 120)
                return notify_fail("����ڹ���Ϊ����������ʩչ" LIAN "��\n");

        if ((int)me->query("neili") < 200)
                return notify_fail("�����ڵ���������������ʩչ" LIAN "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        ap = me->query_skill("liuhe-zhang");
        dp = target->query_skill("parry");

        msg = HIC "\n$N" HIC "˫�ƶ�Ȼ������ת��һ�С�" HIG "��������"
              HIC "����˫�ƴ��磬�ѽ�$n" HIC "�������Ʒ�֮�С�" NOR;

         message_vision(msg, me, target);

	if (random(ap) > dp / 2)
	{
		msg = HIR "\n���$n" HIR "Ŀ��Ͼ�ӣ���ʱ��$N" HIR "��"
                      "����������ʱ��Ŵ��ҡ�\n" NOR;
                me->add_temp("apply/attack", 50);
        } else
        {
                msg = HIY "\n$n" HIY "����$N" HIY "�⼸�е���·����"
                      "�ھ��������Ʒ�Ϭ����Ҳֻ��С�ĵֵ���\n" NOR;          
        }
	message_combatd(msg, me, target);

        attack_time += 3 + random(ap / 40);

        if (attack_time > 6)
                attack_time = 6;

	me->add("neili", -attack_time * 20);

	for (i = 0; i < attack_time; i++)
	{
		if (! me->is_fighting(target))
			break;
                COMBAT_D->do_attack(me, target, 0, 0);
	}
        me->add_temp("apply/attack", -50);
	me->start_busy(2);

	return 1;
}
