// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra,damage,ap,dp;
	object weapon;
	extra = me->query_skill("qingshe-sword",1);
	if ( extra < 200) return notify_fail("���[�����书]���������죡\n");
        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԡ�\n");
        if( (int)me->query("neili", 1) < 600 )
                return notify_fail("����������̫��������ʹ�þ��С�\n");
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("����������ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	weapon = me->query_temp("weapon");
if (extra>=200) extra=200;

if (random(3)==0) target->start_busy(2);

me->add_temp("apply/damage", 1500);
me->add_temp("apply/attack", 100);

	msg =  HIW "$N���һ������������\n"+HIR "���Σ���$N�ն�����$w�������Х������$n��$l��" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

        msg = HIC "���Σ���$N����$w������Ӱ���أ���$n����Χס��" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

     msg =  HIW "���Σ���$N��ǰһ�ݣ�����$w���裬��$n���˹�ȥ��" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

   msg = HIY "���Σ���$N������������$wͷβ������ִ�$n������Ҫ����" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

   msg = HIG "Գ�Σ���$N����������Ծ������$w���ƶ�����������$n��ȥ��" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

   msg = HIB "���Σ���$N��Ӱ����$n�����ζ�������$w������ɨ��$n��$l��" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

   msg = GRN "ӥ�Σ���$N������������$w���϶��£�Ѹ���ޱȣ�����$n��$l��" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);


me->add_temp("apply/damage", -1500);
me->add_temp("apply/attack", -100);
	     ap = me->query("combat_exp");
        dp = target->query("combat_exp");
 damage=extra*2+300;
 msg = HIW "һ�����ģ��� $N" HIW "һ�����ȣ�����" + weapon->name() +
                      HIW "ֱ�����£�ֻ����Х�����������ϵĳ��������������׷׷������\n" NOR;
damage = extra * 2 + random(extra);

        if (random(ap) > dp/2)
        {
        target->receive_damage("qi", damage*2,me);
        target->receive_wound("qi", damage,me);

        msg += HIR "$n" HIR "ֻ����$N" HIR "��������"
                                           "��ɽ����һ�㣬���ֵܵ������ۡ���һ���³�һ�����Ѫ��\n" NOR;
                        }
else
	{
                msg += CYN "����$n" CYN "�ڹ���񣬷�������$N"
                       CYN "��һ�У�˿������\n" NOR;
}
message_combatd(msg, me, target);
	me->add("neili",-380);
	me->start_busy(3);
	return 1;
}
