#include <ansi.h>
#include <combat.h>

#define HONG "��" HIY "ս������" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        int ap, dp, damage;
        string msg;



        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(HONG "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(HONG "ֻ�ܿ���ʩչ��\n");

        if ((int)me->query_skill("baihua-cuoquan", 1) < 250)
                return notify_fail("��İٻ���ȭ������죬����ʩչ" HONG "��\n");


        if (me->query("max_neili") < 5000)
                return notify_fail("���������Ϊ���㣬����ʩչ" HONG "��\n");

        if (me->query_skill_mapped("unarmed") != "baihua-cuoquan")
                return notify_fail("��û�м����ٻ���ȭ������ʩչ" HONG "��\n");
 	if( (int)me->query_skill("yunlong-shengong", 1) < 100 )
		return notify_fail("��������񹦲����ߡ�\n");


        if (me->query("neili") < 800)
                return notify_fail("�����������������ʩչ" HONG "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIW "$N" HIW "һ��ŭ������ս���ľ����˼�����˫ȭ��ʱЯ��"
              "�������֮���͹���$n" HIW "��\n" NOR;

        ap = me->query_skill("unarmed") +
             me->query_skill("force");

        dp = target->query_skill("parry") +
             target->query_skill("dodge");

        if (ap / 2 + random(ap) > dp)
        {
                damage = 0;
                if (me->query("max_neili") > target->query("max_neili") * 2)
                {
                	me->start_busy(2);
                        me->add("neili", -100);
                        msg += HIR "ֻ��$N" HIR "һȭ�������㽫$n" HIR "���"
                               "�������飬�������һ����Ѫ������̱����\n" NOR
                               "( $n" RED "���˹��أ��Ѿ�������в�����ʱ��"
                               "���ܶ�����" NOR ")\n";
                        damage = -1;
                } else
		{
                	me->start_busy(4);
                	me->add("neili", -600);
                	damage = ap * 2 / 3 + random(ap);

                               target->add("qi",-damage);
		target->add("eff_qi",-damage);
                msg +=HIR "���$p" HIR "���ܲ�����$P" HIR "��"
                                                   "ȭ���ƾ���ʱ͸����룬������Ѫ���磬��"
                                                   "��������\n" NOR;
		}
        } else
        {
                me->start_busy(5);
                me->add("neili", -300);
                msg += CYN "����$p" CYN "ʶ����$P"
                       CYN "��һ�У�ббһԾ�ܿ���\n" NOR;
        }
        message_combatd(msg, me, target);


        return 1;
}
