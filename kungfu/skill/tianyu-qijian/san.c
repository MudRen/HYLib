// san.c  ��Ůɢ��

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
int perform(object me, object target)
{
	object weapon;
	int damage;
	string msg;
        int extra;
        extra = me->query_skill("tianyu-qijian",1);


	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("����Ůɢ����ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");

	if( (int)me->query_skill("tianyu-qijian", 1) < 50 )
		return notify_fail("��������潣������죬����ʹ�á�\n");

	if(((int)me->query_skill("bahuang-gong", 1) < 50 ) &&
	   ((int)me->query_skill("beiming-shengong", 1) < 50 ))
		return notify_fail("��ı����ڹ�ʵ��̫�û���á���Ůɢ������\n");

	if( (int)me->query("neili", 1) < 300 )
		return notify_fail("����������̫��������ʹ�á���Ůɢ������\n");
			
	msg = CYN "$N����Ϣ�������󼲶������ǧ�������������ǵط���$n��"NOR;
	extra = me->query_skill("tianyu-qijian",1) / 15;
	extra += me->query_skill("tianyu-qijian",1) /15;
	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", extra);

        message_vision(HIR"��һ�佣����\n" NOR,me,target);
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIG"��һ�佣������\n" NOR,me,target);
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIY"���һ�佣��������\n" NOR,me,target);
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -extra);

	me->add("neili",-150);
		me->start_busy(2);
	return 1;
}
