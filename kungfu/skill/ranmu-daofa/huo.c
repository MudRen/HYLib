#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        int damage;
        int ap, dp;
        string msg;

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail("������ʴ�¡�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "blade")
                return notify_fail("��ʹ�õ��������ԡ�\n");

        if ((int)me->query_skill("ranmu-daofa", 1) < 180)
                return notify_fail("���ȼľ����������죬����ʹ�û���ʴ�¡�\n");

        if ((int)me->query_skill("force") < 150)
                return notify_fail("����ڹ���򲻹�������ʹ�û���ʴ�¡�\n");

        if ((int)me->query("max_neili") < 2000 )
                return notify_fail("���������Ϊ̫��������ʹ�û���ʴ�¡�\n");

        if ((int)me->query("neili") < 500 )
                return notify_fail("����������̫��������ʹ�û���ʴ�¡�\n");

        if (me->query_skill_mapped("blade") != "ranmu-daofa")
                return notify_fail("��û�м���ȼľ����������ʩչ����ʴ�¡�\n");

        if( (int)me->query_skill("yijinjing", 1) < 120 )
                return notify_fail("����׽�ȼ�������ʹ����������ʴ�¡�������\n");

        if( (int)me->query_int() < 26)
                return notify_fail("û�д��ǻ۴��������ʹ����������ʴ�¡������ġ�\n");
 
        if ( me->query_skill_mapped("force") != "yijinjing")
                return notify_fail("û���׽��Ϊ���������޷�ʹ�������ҡ������ģ�\n"); 


        msg = HIR "ֻ��$N" HIR "����" + weapon->name() + HIR "һ���������ʱ����"
                        "�������棬��ԡ������һ��ϯ��$n" HIR "ȫ��\n"NOR;

        me->start_busy(2 + random(2));
        ap = me->query_skill("ranmu-daofa", 1) + me->query_skill("force");
        dp = target->query_skill("force");

        if (ap / 4 + random(ap) > dp)
        {
                target->start_busy(1);
                damage = ap / 3 + random(ap / 4);
                me->add("neili", -400);


	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIR "�������棬�����ԭ��\n"NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = HIR "�������棬������ģ�\n"NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = HIR "�������棬�һ����ƣ�\n"NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIR "�������棬�һ�����\n"NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg += RED "ֻ��һ�ɽ�����$n" RED "���������ѱ�"
                                           "$P" RED "�⾫������һ"
                                           "�����У���Ѫ�ɽ�������\n"NOR;     
target->add("qi",-damage*2);
target->add("eff_qi",-damage);

        } else
        {
                msg += CYN "$p" CYN "��$P" CYN "�������ڣ����ҵֵ�����æбԾ�ܿ���\n"NOR;
                me->add("neili", -200);
                      me->start_busy(2);
        }
        message_combatd(msg, me, target);

        return 1;
}

