#include <ansi.h>
#include <combat.h>

#define ZHU "��" HIW "����������" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;
        object weapon;
        int i;
        int skill;
        int ap, an, dn;
        int count;

        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }



        if (! me->is_fighting(target))
                return notify_fail(ZHU "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        skill = me->query_skill("wuyun-jian", 1);

        if (me->query_skill("force",1) < 150)
                return notify_fail("����ڹ�����Ϊ�����������޷�ʹ��" ZHU "��\n");

        if (skill < 180)
                return notify_fail("����������ν���Ϊ���ޣ������޷�ʹ��" ZHU "��\n");

        if (me->query("neili") < 500)
                return notify_fail("��������������޷�����" ZHU "��\n");

        weapon = me->query_temp("weapon");

        if (weapon && weapon->query("skill_type") != "sword")
                return notify_fail("�㲻��ʹ�����ֱ���ʩչ" ZHU "��\n");


        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        if (weapon)
        {
                msg = HIW "ֻ��$N" HIW "˫Ŀ΢�գ�������" + weapon->name() +
                      HIW "�����Ღ������ʱֻ������࣡��ƿ�֮����������"
                      "��������\n�����ν������������ֱ��$n" HIW "��ȥ��\n" NOR;
        } else
        {
                msg = HIW "ֻ��$N" HIW "˫Ŀ΢�գ�˫��������Ū����Ȼ��ʮָһ"
                      "�����ţ���ʱֻ������࣡��ƿ�֮��������\n�ϣ�������"
                      "�����ν������������ֱ��$n" HIW "��ȥ��\n" NOR;
        }

        ap = me->query_skill("force");
        an = me->query("max_neili");
        dn = target->query("max_neili");

        if (an > dn)
        {
                msg += HIR "$p" HIR "ֻ�е�$P" HIR "�������ȣ���ӿ��������"
                       "ʱ������飬����������\n" NOR;
                count = ap / 8;
                me->add_temp("apply/attack", 120);
        } else
        {
                msg += HIC "$n" HIC "ֻ�е�$P" HIC "�������ȣ���ӿ��������"
                       "æ���������С��Ӧ����\n" NOR;
                count = ap / 15;
                me->add_temp("apply/attack", 120);
        }

        message_combatd(msg, me, target);
        me->add("neili", -350);
me->add_temp("apply/damage", 1000);
        for (i = 0; i < 7; i++)
        {
                if (! me->is_fighting(target))
                        break;

                if (random(3) == 0 && ! target->is_busy())
                        target->start_busy(3);

                COMBAT_D->do_attack(me, target, weapon, 0);
        }

        me->start_busy(3);
        me->add_temp("apply/attack", -120);
        me->add_temp("apply/damage", -1000);

        return 1;
}