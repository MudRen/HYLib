// qixing. ���Ǿ�����

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	string msg;
	object weapon = me->query_temp("weapon");
	int damage;

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("���Ǿ�����ֻ�ܶ�ս���еĶ���ʹ�á�\n");

    if( (int)me->query_skill("quanzhen-jian", 1) < 150 )
		return notify_fail("���ȫ�潣������������ʹ�������Ǿ�������\n");
  
    if (!weapon || weapon->query("skill_type") != "sword"
        || me->query_skill_mapped("sword") != "quanzhen-jian")
		return notify_fail("�������޷�ʹ�����Ǿ�������\n");

    if ( (int)me->query("neili") < 200)
		return notify_fail("��������������޷�ʹ�����Ǿ�������\n");

 	msg = MAG "$Nһ����Х��һ�����н�����ʱ�γ�һ����Ļ����籩���ѹ��$n������
$n����֮�䣬��Ļ�зɳ��߶亮�ǣ������ǰ�����$n��\n";

	if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/3 ) {
		msg += "$n������������Ȼ�н���\n";
		damage = 4*(int)me->query_skill("quanzhen-jian", 1);
		damage = damage / 2 + random(damage / 2);
		if (damage > target->query("neili") / 10)
			damage -= target->query("neili") / 15;
		target->receive_damage("qi", damage);
		target->receive_wound("qi", damage/4);
	 	if( damage < 40 ) msg += HIY"$n���������������ϵ�����Ѫ��\n"NOR;
         	else if( damage < 80 ) msg += HIR"$n�����߽�����Ѫ���������\n"NOR;
         	else msg += RED"$n���ۡ��Ŀ��һ������������ߵ�Ѫ����\n"NOR;
		message_vision(msg, me, target);
	} 
	else {
	me->start_busy(2);
	 	msg += HIW"$n�鼱֮����󼤷ɣ����ſ�£����������������һ����\n" NOR;
		message_vision(msg, me, target);
	}
        if (me->query_skill("qixing-array",1)>80)
{
        msg = HIC "���$N�������ǣ�ʹ��һ�� �������࣡" NOR;
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
}
        if (me->query_skill("qixing-array",1)>150)
{
        msg = HIG "������$N�������󷨣�ʹ��һ������Ҳ���" NOR;
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
}
        if (me->query_skill("qixing-array",1)>250)
{
        msg = HIG "������$N�������󷨣�ʹ��һ��������λ��" NOR;
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
}
	me->add("neili", -300);
	me->start_busy(2);

	return 1;
}
