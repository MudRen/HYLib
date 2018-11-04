#include <ansi.h>
#include <combat.h>

#define QIAN "��" HIR "һָǬ��" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;
        int ap, dp;
        int damage;

        if ((int)me->query_skill("kurong-changong",1) < 100)
            return notify_fail("��Ŀ�������̫�͡�\n");

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(QIAN "ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        	if(me->query_skill_mapped("force") != "kurong-changong")
		return notify_fail("û�п���������Ϊ׼�����޷�ʹ����\n"); 

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(QIAN "ֻ�ܿ���ʩչ��\n");

        if ((int)me->query_skill("yiyang-zhi", 1) < 160)
                return notify_fail("��һ��ָ��������죬����ʩչ" QIAN "��\n");


        if (me->query_skill_mapped("finger") != "yiyang-zhi")
                return notify_fail("��û�м���һ��ָ��������ʩչ" QIAN "��\n");


        if ((int)me->query_skill("force") < 220)
                return notify_fail("����ڹ���򲻹�������ʩչ" QIAN "��\n");

        if (me->query("max_neili") < 2400)
                return notify_fail("���������Ϊ���㣬����ʩչ" QIAN "��\n");

        if ((int)me->query("neili") < 500)
                return notify_fail("�����ڵ���������������ʩչ" QIAN "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIY "$N" HIY "��Ȼʹ����" HIR "һָǬ��" HIY "����������ָ��"
              "��$n" HIY "̴��ҪѨ����ʽ�仯����֮����\n" NOR;

        ap = me->query_skill("finger") + me->query_skill("force");
        dp = target->query_skill("parry") + target->query_skill("force");

        if (ap / 2 + random(ap) > dp)
        {
                damage = ap  + random(ap / 3);
                target->add("qi",-damage);
		target->add("eff_qi",-damage);
                msg +=HIR "$n" HIR "ֻ���ؿ�һ�飬�ѱ�$N" HIR
                                           "һָ���У���ʱ��Ѫ��ӿ�����������Ѫ"
                                           "��\n" NOR;
                me->add("neili", -200);
                me->start_busy(2);
        } else
        {
                msg += CYN "����$n" CYN "������$N" CYN "����"
                       "�����������򵲿�����һָ��\n" NOR;
                me->start_busy(2);
                me->add("neili", -150);
        }
        message_combatd(msg, me, target);

        return 1;
}

