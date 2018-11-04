// yunkai.c �ƿ�����

#include <ansi.h>
 
inherit F_SSERVER;
 
int perform(object me)
{
	string msg;
	object weapon, target;
	int skill, ap, dp, neili_wound, qi_wound;

	me->clean_up_enemy();
	target = me->select_opponent();

	skill = me->query_skill("fanyun-zhang",1);

	if( !(me->is_fighting() ))
		return notify_fail("���ƿ����ء�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
 
	if (objectp(weapon = me->query_temp("weapon")))
		return notify_fail("��ʹ����������\n");

	if( skill < 80)
		return notify_fail("��ġ������ơ��ȼ�����, ����ʹ�á��ƿ����ء���\n");

	if( me->query("neili") < 250 )
		return notify_fail("��������������޷����á��ƿ����ء���\n");
 
	msg = HIC "$NǱ�ˡ��ƿ����ء���˫��Ю������ķ���֮����$n��ȥ��\n"NOR;
	message_vision(msg, me, target);
 
	ap = me->query("combat_exp") + skill*2;
	dp = target->query("combat_exp") / 2;
	if( dp < 1 )
		dp = 1;
	if( random(ap) > dp )
	{
		if(userp(me))
			me->add("neili",-200);

		msg = HIG "$nֻ������ǰһ���ʹ�����ۡ���һ�����һ����Ѫ��\n"NOR;
		neili_wound = 100 + random(skill);
		if(neili_wound > target->query("neili"))
			neili_wound = target->query("neili");

		qi_wound = neili_wound / 5;
		if(qi_wound > target->query("qi"))
			qi_wound = target->query("qi");

		target->add("neili", -neili_wound);
		target->add("qi", -qi_wound);
		target->start_busy(1);
		me->start_busy(random(2)+1);
	}
	else
	{
		msg = HIG "ֻ��$n���Ų�æ������һ���������$N�ı�ɱһ����\n"NOR;
		if(userp(me))
			me->add("neili",-200);
		me->start_busy(4);
	}
	message_vision(msg, me, target);

	return 1;
}
