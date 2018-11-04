// yuxiao.c �̺�����������

#include <ansi.h>

inherit F_SSERVER;

#include "/kungfu/skill/eff_msg.h"

int perform(object me, object target)
{
	string msg;
	object weapon;
	int damage, p;

	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("�̺�����������ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if( (int)me->query_skill("yuxiao-jian", 1) < 80 )
		return notify_fail("������｣��������죬�޷�ʹ�ñ̺����������\n");

	weapon = me->query_temp("weapon");
//	if (!weapon || !(weapon->id("xiao")))
//		return notify_fail("������ı���������޷�ʹ�ñ̺����������\n");

	if ( (int)me->query("neili") < 120)
		return notify_fail("��������������޷�ʹ�ñ̺����������\n");

	msg = CYN "$N����յ���ߣ��������£�����Ͳ��ͻȻ���һ����⣬ֱ��$n��\n";

	if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/3 ) {
		msg += "$n��������������ǰ�أ�\n";
		damage = (int)me->query_skill("yuxiao-jian", 1);
		damage += random(damage * 2 / 3);
		if (damage > target->query("neili") / 10)
			damage -= target->query("neili") / 15;
		target->receive_damage("qi", damage);
		target->receive_wound("qi", damage/3);
                p = (int)target->query("qi") * 100 / (int)target->query("max_qi");
//                msg += damage_msg(damage, "����");
//                msg += "( $n" + eff_status_msg(p) + " )\n";
		if( damage < 100 ) msg += HIY"$n����ǰ�½��Ѿ��ֳ�����Ѫ��\n"NOR;
        	else if( damage < 200 ) msg += HIR"$n��ǰ�ֳ���һ���ֳ�������˿ڣ�\n"NOR;
        	else msg += RED"��Ȼ������$n�����壬$n�����˿ڣ����ۡ���һ���³���һ����Ѫ��\n"NOR;
	} 
	else {
		msg += "��ϧ$n���ѷ�����$N�����У����Ա�һԾ���㿪��������������԰����������Ѹ��Ҳ���Խ���¶��һ˿���⡣\n" NOR;
	}
	message_vision(msg, me, target);
	me->add("neili", -90);
	me->start_busy(1);

	return 1;
}
