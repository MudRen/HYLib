
#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	int i,neili,damage;
	string msg;

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("���ɷ�ֻ����ս����ʹ�á�\n");

	if( (int)me->query_skill("shedao-qigong", 1) < 100 )
		return notify_fail("����ߵ��湦������죬����ʹ�ó��ɷ����־���\n");

	if ((int)me->query_skill("shenlong-xinfa",1) < 10)
		return notify_fail("��������ķ���򲻹���\n");

	if( environment(me)->query("no_fight") )
		return notify_fail("�����ﲻ�ܹ������ˡ�\n");

	if( (int)me->query("neili") < 500 )
		return notify_fail("���Ѿ����þ�ƣ����,���������ˡ�\n");


	neili = me->query("eff_neili");

	me->add("neili", -(300+random(200)));
	me->receive_damage("qi", 10);

	me->start_busy(3);

	message_combatd(
		HIY "$N�������һ��������Ȼ���쳤Х��������У�����������Ψ�Ҳ��ܣ�\n" NOR, me);

		if( neili/2 + random(neili/2) < (int)target->query("neili")/15) 
		return notify_fail("���˵���������߳�̫��,�˲��ˣ�\n");
		
		damage = (neili - (int)target->query("max_neili")) / 15;
		if( damage > 0 ) {
			target->receive_damage("jing", damage/2);
			target->receive_damage("qi", damage);
			target->receive_wound("jing", damage/2);
			target->receive_wound("qi", damage);
		message_combatd(
		HIR "$Nֻ������һ���ʹ��������ð��������������������ǰ�趯��\n" NOR, target);
		COMBAT_D->report_status(target);
		}
		else
		{
		message_combatd(
		HIR "$Nֻ������΢ʹ���ƺ�����һ�����ˡ�\n" NOR, target);
		target->receive_damage("jing", 30 );
		target->receive_damage("qi", 30 );
		target->receive_wound("qi", 30);
		COMBAT_D->report_status(target);
		}
//		if( !target->is_killing(me) ) target->kill_ob(me);
//		if( !me->is_killing(target) ) me->fight_ob(target);

	return 1;
}
