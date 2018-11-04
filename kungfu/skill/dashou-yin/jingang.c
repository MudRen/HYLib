// jingang.c ���ӡ

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;
        int skill, ap, dp, damage;

        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! me->is_fighting(target))
                return notify_fail("�����ӡ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        skill = me->query_skill("dashou-yin", 1);

        if (skill < 100)
                return notify_fail("��Ĵ���ӡ��Ϊ����, ����ʹ�á����ӡ����\n");

        if (me->query("neili") < 150)
                return notify_fail("��������������޷����á����ӡ����\n");

        msg = HIY "$N" HIY "����ׯ�أ������ĳ����������ھ�ѧ�����ӡ����\n" NOR;

        ap = me->query_skill("hand", 1) / 2 + skill;

        if (living(target))
                 dp = target->query_skill("parry");
        else     dp = 0;

        if (ap / 2 + random(ap * 4 / 5) > dp)
        {
                me->add("neili", -100);
                me->start_busy(1);
                damage = 150 + skill / 2 + random(skill / 2);
   target->add("qi",-damage);
		target->add("eff_qi",-damage);
                msg += HIR "���$p" HIR "�мܲ�������$P" HIR
                                           "��һ�´���������̣���Ѫ������\n" NOR;
        } else
        {
                me->add("neili",-40);
                msg += CYN "����$p" CYN "���Ų�æ������ļܿ���$P"
                       CYN "�Ľ��ӡ��\n" NOR;
                me->start_busy(3);
        }
        message_combatd(msg, me, target);

        return 1;
}
