// bada.c ���ΰ˴� 
// ����lywin 2000/6/12
 
#include <ansi.h>
 
inherit F_SSERVER;
 
int perform(object me)
{
	string msg;
	object weapon, weapon2, target;
	int skill,damage;

	me->clean_up_enemy();
	target = me->select_opponent();
	skill = me->query_skill("shenlong-bashi",1);

	if( !(me->is_fighting() ))
		return notify_fail(HIR"���ΰ˴�" + NOR + "ֻ�ܶ�ս���еĶ���ʹ�á�\n");
 
	if (objectp(weapon = me->query_temp("weapon")))
		return notify_fail("ֻ�п��ֲ���ʹ��" + HIR + "���ΰ˴�\n" NOR);

	if (!objectp(weapon2 = target->query_temp("weapon")))
	   return notify_fail("�Է�û�б��У����ò������ΰ˴�\n");

        if ((int)me->query_skill("shenlong-bashi", 1) < 60 )
		return notify_fail("���������ʽ�ȼ�����, �����ô˾��У�\n");

        if ((int)me->query_skill("shenlong-xinfa", 1) < 60 )
        return notify_fail(RED"�������ķ���򲻹���ʹ���������ΰ˴򡹡�\n"NOR);

	if( me->query("neili") < 50 )
		return notify_fail("��������������޷�ʹ�ô˾��У�\n");
 
 	msg = HIY"$NͻȻ������ǰ��ʹ��������ʽ�еľ��������˴�
ֻ��$N��һ˫�ֹ��������á��С��ࡢ�ơ�����ˤ�����������Ӱ��\n"NOR;
	message_combatd(msg, me);

	if( random(me->query("combat_exp")) > (target->query("combat_exp") / 2) )
	{
		if(userp(me))
		msg = HIR "���$n���һ�������б������ɵ����ַɳ���\n" NOR;
		me->add("neili",-50);
		weapon2->move(environment(target));
		if (weapon2->query("ownmake")==1)
		{
			weapon2->move(target);
			msg += HIG "�ǿ���$n������һ$n��һ�콫���������\n" NOR;
		}
		me->start_busy(1);
	}
	if( random(me->query("combat_exp")) > (target->query("combat_exp") / 2) )
	{
		if(userp(me))
		msg = HIC "���$n���һ����һ��æ�Ҳ�֪����!\n" NOR;
	target->apply_condition("ill_fashao",60);
	target->apply_condition("ill_kesou",60);
	target->apply_condition("ill_shanghan",60);
	target->apply_condition("ill_zhongshu",60);
	target->apply_condition("ill_dongshang",60);
                target->start_busy(random(6)+2);
	}

	else
	{
		msg = HIR"��ϧ$n����ḻ����Ϊ������$N�Լ�ȴ������š�\n"NOR;
		me->start_busy(4);
	}
	message_combatd(msg, me, target);
//	if(!target->is_fighting(me)) target->fight_ob(me);
	return 1;
}
