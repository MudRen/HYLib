// tie@fengyun

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	object weapon;
	if(me->is_busy())
		return notify_fail("������û�գ���\n");
        if( (int)me->query_skill("zhong-qiang",1) < 50)
        return notify_fail("��Ŀǰ������ʹ������������������\n");
    	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "club")
			return notify_fail("��ʹ�õ��������ԡ�\n");
	if( (int)me->query("neili") < 100 )
    return notify_fail("�������������\n");
	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("������������ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	weapon = me->query_temp("weapon");
	extra = me->query_skill("zhong-qiang",1) / 2;
	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", extra);
	msg = HIC  "$Nһ�������е�"+ weapon->name() +"ͻȻ�̳���"+weapon->name() +"���ƿ������޿ɵ͵���Ļ���$n��" NOR;
if( (int)me->query_skill("zhong-qiang",1) > 300)
{	
if (!target->is_busy()) target->start_busy(1);
if (random(8)==0) target->start_busy(3);
}
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -extra);
me->add("neili", -60);
	me->start_busy(2);
	return 1;
}
