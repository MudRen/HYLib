#include <ansi.h>
#include <combat.h>

#define JU "��" HIM "������" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        int damage;
	object weapon;
	string msg;
	int ap, dp;
        int count;
	int i, attack_time;


        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(JU "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(JU "ֻ�ܿ���ʩչ��\n");

        if ((int)me->query_skill("dulong-shenzhua", 1) < 130)
                return notify_fail("�㶾����צ��������죬����ʩչ" JU "��\n");

        if (me->query_skill_mapped("claw") != "dulong-shenzhua")
                return notify_fail("��û�м���������צ��������ʩչ" JU "��\n");
        if (me->query_skill_mapped("force") != "shenlong-xinfa")
                return notify_fail("��û�м��������ķ�Ϊ�ڹ����޷�ʩչ��\n");

	if ((int)me->query_skill("shenlong-xinfa", 1) < 85)
		return notify_fail("��������ķ���򲻹�.\n");
        if (me->query_skill("force") < 180)
                return notify_fail("����ڹ���Ϊ����������ʩչ" JU "��\n");

        if ((int)me->query("neili") < 300)
                return notify_fail("�����ڵ���������������ʩչ" JU "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        ap = me->query_skill("claw") + me->query("force");
        dp = target->query_skill("parry") + target->query("force");

        msg = HIC "\n$N" HIC "��ת����������������������˫צ�䣬��Ȼ��˫צ��"
              "�ն��£����������㻮��$n" HIC "������������ڤ�Ⱦ�ѧ��" HIM "��"
              "����" HIC "����\n" NOR;

        if (ap / 2 + random(ap) > dp)
        {
                damage = ap + random(ap / 2);
                
                        target->add("qi",-damage+300);
                        target->add("eff_qi",-damage/2+300);

                        msg +=                    HIR "����$N" HIR "˫צ������$n" HIR "�����ܲ������ؿڱ�$N" HIR
                                           "ץ��ʮ��Ѫ�ۡ�\n" NOR;
                me->start_busy(3);
                me->add("neili", -220);
        } else
        {
                msg += CYN "$n" CYN "�����мܣ�����$N" CYN "���л��⡣\n" NOR;

                me->start_busy(3);
                me->add("neili", -100);
        }
        message_vision(msg, me, target);
attack_time=(int)me->query_skill("dulong-shenzhua", 1) /40;
        if (attack_time > 7)
                attack_time = 7;
        me->add_temp("apply/attack", 50);
        me->add_temp("apply/damage", 200);
        me->add("neili", -attack_time * 30);

	for (i = 0; i < attack_time; i++)
	{
                if (! target->is_busy() && random(5) == 1)
                       target->start_busy(2);
 
         msg = HIG "$N˫צ������ץ����"+(i+1)+"צ��\n"NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

	}
        me->add_temp("apply/attack", -50);
        me->add_temp("apply/damage", -200);

        return 1;
}
