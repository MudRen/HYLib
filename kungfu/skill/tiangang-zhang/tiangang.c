// jingang-zhang

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
int perform(object me, object target)
{
      string *limbs;
	int count, damage = 0;
	int arg=(int)(me->query_skill("tiangang-zhang", 1) / 30);

	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("�����ֻ����ս���жԶ���ʹ�á�\n");

	if( objectp( me->query_temp("weapon")) )
		return notify_fail("ֻ�п��ֲ���ʩչ�������\n");

	if( (int)me->query_skill("tiangang-zhang", 1) < 150 )
		return notify_fail("�������Ʒ�������죬����ʹ�á������\n");

	if( (int)me->query_skill("xiantian-gong", 1) < 90 )
		return notify_fail("������칦�ȼ�����������ʹ�á������\n");

	if( (int)me->query_str() < 35 )
		return notify_fail("�����������ǿ������ʹ�á������\n");

	if( arg <= 1 )
		return notify_fail("����Ҫ�����вſ���ɡ������\n");

	if( (int)me->query("neili", 1) < 1200 )
		return notify_fail("����������̫��������ʹ�á������\n");

	if( (int)me->query("neili", 1) < 100 * arg )
		return notify_fail("�����ڵ�����ʩչ������ô���С�\n");

	message_vision(HIG"$NͻȻ������ǰһ̽������ٿ���ĳ����������У��������٣�˫�ƺ��������ĳ�"+ chinese_number(arg) +"�ơ�\n\n"NOR,  
	              me, target);

	limbs = target->query("limbs");
	for(count = 0; count < arg; count++)
        {
	  message_vision(
		replace_string(
	  SKILL_D("tiangang-zhang")->query_action(me, me->query_temp("weapon"))["action"],
		"$l", limbs[random(sizeof(limbs))]) + "��\n\n", me, target);
	  damage = damage+250+random(250);
        }    

	damage = (1 + me->query("jiali")/250) * damage / 2;
	if( arg*(random(me->query("combat_exp"))) > target->query("combat_exp") )
	{
		target->receive_damage("qi", damage);
		target->receive_wound("qi", damage/3);
		COMBAT_D->report_status(target, 1);
		COMBAT_D->report_status(target, 0);
	}

	me->add("neili", -100 * arg);
   me->start_busy(3);

	return 1;
}
