#include <ansi.h>
#include <combat.h>

#define BAO "��" HIW "������" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;
        int ap, dp;


        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(BAO "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(BAO "ֻ�ܿ���ʩչ��\n");

        if (target->is_busy())
                return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɡ�\n");

        if ((int)me->query_skill("dulong-shenzhua", 1) < 80)
                return notify_fail("�㶾����צ��������죬����ʩչ" BAO "��\n");

        if (me->query_skill_mapped("claw") != "dulong-shenzhua")
                return notify_fail("��û�ж�����צ��������ʩչ" BAO "��\n");


        if (me->query_skill("dodge") < 150)
                return notify_fail("����Ṧ��Ϊ����������ʩչ" BAO "��\n");

	if ((int)me->query_skill("shenlong-xinfa", 1) < 85)
		return notify_fail("��������ķ���򲻹�.\n");
		
        if ((int)me->query("neili") < 200)
                return notify_fail("�����ڵ���������������ʩչ" BAO "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        ap = me->query_skill("dulong-shenzhua", 1) +
             me->query_skill("dodge", 1) / 2;

        dp = target->query_skill("dodge");

        msg = HIC "\n$N" HIC "��Хһ����˫צ�����ʩ�����С�" HIW "������" HIC "����"
              "˫צ���������㽫$n" HIC "��ס��\n" NOR;

        message_vision(msg, me, target);
        
     if (random(me->query("combat_exp")) > (int)target->query("combat_exp")/3)
        {
		msg = HIR "$n" HIR "������ѣ�һʱ�侹�޴�Ӧ�ԡ�\n" NOR;
                target->start_busy(6);
                me->add("neili", -160);
        } else
        {
                msg = CYN "$n" CYN "����$N" CYN "���޹���֮�⣬��"
                      "�Ǵ󵨷�������$N" CYN "���о������⡣\n" NOR;

                me->start_busy(2);
                me->add("neili", -60);
        }
        message_vision(msg, me, target);

        return 1;
}
