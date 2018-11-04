// huayu.c ���컨��

#include <ansi.h>

inherit F_SSERVER;

#include "/kungfu/skill/eff_msg.h"

int perform(object me, object target)
{
	string msg;
	object weapon;
	int damage, num, lvl, p;

	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("���컨��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	lvl = (int)me->query_skill("tanzhi-shentong", 1);
	if (lvl < 120) return notify_fail("��ĵ�ָ��ͨ������죬�޷�ʹ�����컨�ꡣ\n");

//	weapon = me->query_temp("weapon");
//	if (!weapon) return notify_fail("���컨�����װ����������ʹ�á�\n");
//	if ((num = weapon->query_amount()) < lvl / 20) 
//		return notify_fail("�������ͱ��ң���������İ����Ѿ�����ʹ�����컨���Ҫ���ˣ�\n");

	if ( (int)me->query("neili") < 450)
		return notify_fail("��������������޷�ʹ�����컨�ꡣ\n");

	msg = CYN "$N˫���ڱ�����һץ��ץ��һ��������������ָ������ص��˳�ȥ��$nֻ����ǰ�ƺ�����һ�������꣡\n";

	damage = lvl * 2 + (int)me->query_skill("bibo-shengong", 1);
	damage += random(damage / 2);
	damage = damage + 300;
	if (random(me->query("combat_exp")) > (int)target->query("combat_exp") / 4) {
		msg += "$n���������������ۡ��ؼ������������������У�\n";
		target->receive_damage("qi", damage);
		target->receive_wound("qi", damage);
                p = (int)target->query("qi") * 100 / (int)target->query("max_qi");
		msg += RED "$nֻ������ǰһ��������İ���������һ��\n" ;
//                msg += damage_msg(damage, "����");
//                msg += "( $n" + eff_status_msg(p) + " )\n";
	} 
	else {
		msg += "$n�ŵø�æ��ͷ��������Ǳ������Ա�һ�������ſ����ض��˹�ȥ��\n" NOR;
	}
	message_vision(msg, me, target);
	me->add("neili", -350);
	me->start_busy(2);
//	if (num == lvl / 20) {
//		weapon->unequip();
//		tell_object(me, "\n���" + weapon->query("name") + "�����ˣ�\n");
//	}
//	weapon->add_amount(-(lvl/20));

	return 1;
}
