#include <ansi.h>
#include <combat.h>

#define YING "��" HIW "��Ӱ����" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;
        int ap, dp;


        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(YING "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(YING "ֻ�ܿ���ʩչ��\n");

        if (target->is_busy())
                return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɡ�\n");

        if ((int)me->query_skill("xuanming-zhang", 1) < 100)
                return notify_fail("����ڤ���Ʋ�����죬����ʩչ" YING "��\n");

        if (me->query_skill_mapped("strike") != "xuanming-zhang")
                return notify_fail("��û�м�����ڤ���ƣ�����ʩչ" YING "��\n");


        if (me->query_skill("dodge") < 180)
                return notify_fail("����Ṧ��Ϊ����������ʩչ" YING "��\n");

        if ((int)me->query("neili") < 200)
                return notify_fail("�����ڵ���������������ʩչ" YING "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        ap = me->query_skill("strike"); 

        dp = target->query_skill("dodge");

        msg = HIC "\n$N" HIC "��Хһ����ʩ�����С�" HIW "��Ӱ����" HIC "����"
              "˫�Ʋ��Ϸ��ڣ��Ʒ���͸����������֮������$n" HIC "���֡�\n" NOR;
        message_vision(msg, me, target);
        
     if (random(me->query("combat_exp")) > (int)target->query("combat_exp")/2)
        {
		msg = HIR "$n" HIR "�پ��������ˣ�һʱ���޴�Ӧ�ԣ�"
                      "��������$N" HIR "���Ʒ�֮�С�\n" NOR;

                target->start_busy(5);
               	me->start_busy(1);
                me->add("neili", -180);
        } else
        {
                msg = CYN "$n" CYN "����$N" CYN "���޹���֮�⣬��"
                      "�Ǵ󵨷�������$N" CYN "���о������⡣\n" NOR;

                me->start_busy(2);
                me->add("neili", -100);
        }
        message_vision(msg, me, target);

        return 1;
}
