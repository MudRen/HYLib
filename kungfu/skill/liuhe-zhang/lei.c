#include <ansi.h>
#include <combat.h>

#define LEI "��" HIY "�������" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        int damage;
        string msg;

        if (! target) target = offensive_target(me);


        if (! target || ! me->is_fighting(target))
                return notify_fail(LEI "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(LEI "ֻ�ܿ���ʩչ��\n");
     if ((int)me->query_skill("liuhe-zhang", 1) < 60)
                return notify_fail("��������Ʒ�������죬����ʩչ" LEI "��\n");


        if (me->query_skill_mapped("strike") != "liuhe-zhang") 
                return notify_fail("��û�м��������Ʒ�������ʩչ" LEI "��\n");



        if (me->query("neili") < 400)
                return notify_fail("��������������������ʩչ" LEI "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIY "ֻ��$N" HIY "�������ƣ�ƽƽ�Ƴ�����ʱ�Ʒ����ȣ�����"
              "Я���������֮���͹���$n" HIY "��ȥ��\n" NOR;

        if (random(me->query_skill("liuhe-zhang")) > target->query_skill("parry") / 2)
        {
                me->start_busy(3);

                damage = me->query_skill("benlei-zhang", 1);
                damage = damage * 3 + random(damage * 5);
                               target->add("qi",-damage);
		target->add("eff_qi",-damage);
                msg +=HIR "���ֻ��$n" HIR "һ���ƺߣ�$N"
                                           HIR "�ƾ����ض��������ۡ������һ��"
                                           "����Ѫ��\n" NOR;
                me->add("neili", -300);
        } else
        {
                me->start_busy(2);
                me->add("neili", -200);
                msg += CYN "����$p" CYN "������$N" CYN
                       "����ͼ���㿪������ɱ�š�\n" NOR;
        }
        message_combatd(msg, me, target);

        return 1;
}

