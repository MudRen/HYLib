// meng.c ��Ҷ����衸���Ρ�

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
	int damage;
	string msg;
object weapon;
weapon = me->query_temp("weapon");
	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("�����Ρ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if( objectp(me->query_temp("weapon")) 
	&& (string)weapon->query("skill_type") != "throwing")
		return notify_fail("�������ֲ���ʹ�á����Ρ���\n");		

	if( (int)me->query_skill("biye-wu", 1) < 40 )
		return notify_fail("��ı�Ҷ����費����죬����ʹ�á����Ρ���\n");

	if( (int)me->query_skill("biyun-xinfa", 1) < 30 )
		return notify_fail("��ı����ķ������ߣ��������������˵С�\n");

	if( (int)me->query("neili", 1) < 100 )
		return notify_fail("����������̫��������ʹ�á����Ρ���\n");

	msg = CYN "$NĬ��ھ���ʹ����Ҷ�����֮�����Ρ�����������������$n��\n"NOR;


	if (random(me->query_skill("force")) > target->query_skill("force")/3 )
	{
		if (!target->is_busy())
		target->start_busy(2);
		damage = (int)me->query_skill("biyun-xinfa", 1);
		
                damage = damage/2 + random(damage)*2+300;
		
		target->receive_damage("qi", damage);
		target->receive_wound("qi", damage/3);
                me->add("neili", -damage/3);
		
		if( damage < 20 )
			msg += HIY"���$n�ܵ�$N�����������ƺ�һ��������ȥ����ƣ����\n"NOR;
        else if( damage < 40 )
			msg += HIY"���$n��$N����������ֻ�������з��ƣ�ֻ��ú���Ϣ��Ϣ��\n"NOR;
        else if( damage < 80 )
			msg += RED"���$n��$N������һ�������������죬��ʶ��ʼģ��������\n"NOR;
		else
			msg += HIR"���$n��$N������һ����ǰһ�ڣ����㵹���ۿ���Ҫ���������ˣ�\n"NOR;
		
	}
	else 
	{
			msg += CYN"����$p������$P����ͼ����û���ϵ���\n"NOR;
	}
	message_vision(msg, me, target);
	me->start_busy(2);

	return 1;
}