#include <ansi.h>
#include <combat.h>

#define KAI "��" HIW "�Ƽ���ɽ" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        int damage;
        string msg;
        int ap, dp;


        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(KAI "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(KAI "ֻ�ܿ���ʩչ��\n");

        if ((int)me->query_skill("tongbi-zhang", 1) < 120)
                return notify_fail("��ͨ�������Ʋ�����죬����ʩչ��\n");

        if (me->query_skill("force") < 80)
                return notify_fail("����ڹ���Ϊ����������ʩչ" KAI "��\n");

        if ((int)me->query("neili") < 200)
                return notify_fail("�����ڵ���������������ʩչ" KAI "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

   ap = me->query("combat_exp");
        dp = target->query("combat_exp");

        msg = HIC "\n$N" HIC "��Хһ����ʩ�����С�" HIW "��ɽ��" HIC "����һ"
              "ȭ�ӳ����ƿն��죬ֱ��$n" HIC "���ź��ؿڡ�\n" NOR;
        


        if (ap / 2 + random(ap) > dp)
        {
                damage = (int)me->query_skill("tongbi-zhang", 1);
                damage += random(damage)+300;
                         target->add("qi",-damage);
		target->add("eff_qi",-damage);
                msg +=HIR "\n $N" HIR "���ּȿ죬��λ���棬$n"
                                          HIR "���ܲ������ƺ�һ������Ȼ��ȭ��\n" NOR;

                me->add("neili", -100);
	        me->start_busy(1);                                         
        } else
        {
                msg = CYN "$n" CYN "���Ų�æ���Կ��죬��$N"
                      CYN "���л�ȥ��\n" NOR;

                me->add("neili", -30);
	        me->start_busy(2);
        }
        message_combatd(msg, me, target);
        return 1;
}
