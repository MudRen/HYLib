// tie@fengyun

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	object weapon;
	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("�۾��غ����ƣ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	if( (int)me->query("neili") < 500  ) 
		return notify_fail("�������������\n");
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("ֻ�ܿ���ʹ�á�\n");		

        me->add("neili",-100);

	weapon = me->query_temp("weapon");
	extra = me->query_skill("doomstrike",1) / 10;
	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", extra);
	msg = HIR  "$Nʹ���۾��غ����ƣݣ�ȫ�������ת��˫��һǰһ�������Ļ���$n��" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -extra);
	me->start_busy(1);
	return 1;
}
