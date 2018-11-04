#include <ansi.h>
#include <combat.h>

#define YIN "��" HIM "����������" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        string msg;
        int skill;
        int ap, dp, damage;

        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }


        if (! me->is_fighting(target))
                return notify_fail(YIN "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        weapon = me->query_temp("weapon");

        if (weapon && weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԣ�����ʩչ" YIN "��\n");

        skill = me->query_skill("qixian-jian", 1);

        if (skill < 160)
                return notify_fail("���������ν���Ϊ���ޣ�����ʩչ" YIN "��\n");

        if (weapon && me->query_skill_mapped("sword") != "qixian-jian")
                return notify_fail("��û��׼���������ν�������ʩչ" YIN "��\n");


        if (me->query_skill("force") < 250)
                return notify_fail("����ڹ���Ϊ����������ʩչ" YIN "��\n");

        if (me->query("neili") < 600)
                return notify_fail("�����ڵ���������������ʩչ" YIN "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        if (weapon)
        {
                msg = HIM "ֻ��$N" HIM "һ����ߣ����ھ��߶�" + weapon->name()
                      + HIM "�������������������Ȼ���죬ֻ����࣡���\nһ���ƿ�"
                      "֮�죬һ�����ν������������ֱ��$n" HIM "��ȥ��\n" NOR;
        } else
        {
                msg = HIM "ֻ��$N" HIM "һ����ߣ�����ھ������������������"
                      "Ȼ���죬ֻ����࣡���һ���ƿ�֮\n�죬һ�����ν�������"
                      "�����ֱ��$n" HIM "��ȥ��\n" NOR;
        }

        ap = me->query_skill("force");
        dp = target->query_skill("force");

        if (target->query("max_neili") < 10)
        {
                msg += HIM "$N" HIM "��һ��ʩ��������$n"
                       HIM "����û��һ�㣬˿������\n" NOR;

                me->start_busy(2);
                me->add("neili", -100);
        } else
        // �ȼ��������Ҳ����ֺ�
        if (userp(target) && target->query("max_neili") + 500 > me->query("max_neili"))
        {
                msg += HIM "����$n" HIM "�����������׾�����$N"
                       HIM "��һ�У�˿������\n" NOR;

                me->start_busy(2);
                me->add("neili", -100);
        } else
        if (ap / 2 + random(ap) < dp)
        {
                msg += CYN "����$n" CYN "��æ���������Ŭ��ʹ�Լ�"
                       "���������ĸ��ţ����ڻ�������һ�С�\n" NOR;

                me->start_busy(2);
                me->add("neili", -100);
        } else
        {
                damage = ap + skill;
                damage += random(damage);

                target->receive_damage("jing", damage * 4 / 3, me);
                target->receive_wound("jing", damage / 3, me);

                msg += HIR "$n" HIR "ֻ����$N" HIR "������������"
                       "������һ��������͸��Ĥ�����ۡ������һ��"
                       "��Ѫ��\n";

                me->start_busy(2);
                me->add("neili", -300);
        }
        message_combatd(msg, me, target);

        return 1;
}

