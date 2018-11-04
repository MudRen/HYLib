#include <ansi.h>
#include <combat.h>

#define LUN "��" HIR "�����" NOR "��"

inherit F_SSERVER;
 
int perform(object me, object target)
{
        object weapon;
        string msg;
        int ap, dp, damage;
 

        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! target || ! me->is_fighting(target))
                return notify_fail(LUN "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon"))
           || (string)weapon->query("skill_type") != "staff")
                return notify_fail("��ʹ�õ��������ԣ�����ʩչ" LUN "��\n");

        if ((int)me->query_skill("force") < 150)
                return notify_fail("����ڹ���򲻹�������ʩչ" LUN "��\n");

        if ((int)me->query("neili") < 300)
                return notify_fail("�����ڵ���������������ʩչ" LUN "��\n");

        if (! objectp(weapon = me->query_temp("weapon"))
           || (string)weapon->query("skill_type") != "staff")
                return notify_fail("����ʹ�õ��������ԣ�����ʩչ" LUN "��\n");

        if ((int)me->query_skill("fengmo-zhang", 1) < 120)
                return notify_fail("���ħ�ȷ���򲻹�������ʩչ" LUN "��\n");

        if (me->query_skill_mapped("staff") != "fengmo-zhang")
                return notify_fail("��û�м�����ħ�ȷ�������ʩչ" LUN "��\n");
                
        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIW "$N" HIW "һ�����ȣ�����" + weapon->name() +
              HIW "���裬��Ӱ����������Ȧ������" HIR "�����"
              HIW "������ǵؾ���$n" HIW "��\n" NOR;

        ap = me->query_skill("staff");
        dp = target->query_skill("parry");

        if (ap / 2 + random(ap) > dp)
        {
                damage = ap + random(ap / 2);
                damage = ap + random(ap / 2);
                               target->add("qi",-damage);
		target->add("eff_qi",-damage);
                msg +=HIR "$n" HIR "��ȫ�޷�����������ʵ��ֻ"
                                           "���������项�������ѱ�$N" HIR "������"
                                           "�ȣ�ŻѪ������\n" NOR;
                me->start_busy(2);
                me->add("neili", -150);
        } else 
        {
                msg += CYN "����$n" CYN "�����мܣ������ұܣ��ò���"
                       "�׵ֵ�ס��$N" CYN "�Ĺ�����\n" NOR;
                me->start_busy(3);
                me->add("neili", -80);
        }
        message_combatd(msg, me, target);

        return 1;
}
