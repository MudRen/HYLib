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
        if ((int)me->query_skill("jiuyang-shengong", 1) < 20)
                return notify_fail("��ľ����񹦻��̫ǳ��\n");

if((int)me->query_skill("liehuo-jian",1) < 50)
		return notify_fail("��Ľ�����Ϊ����, ����ʹ�á���Ȼһ������\n");if((int)me->query("neili") < 200 )
	if((int)me->query("neili") < 500 )
		return notify_fail("�������������\n");
	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword")
			return notify_fail("��û��װ��������\n");

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("�ۻ�Ȼһ����ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	weapon = me->query_temp("weapon");
	extra = me->query_skill("liehuo-jian",1)/2;
	me->add_temp("apply/attack", (extra*2));	
	me->add_temp("apply/damage", (extra*2));
        me->add_temp("apply/strength", extra);
	msg = HIR "$N����ǰ������"+ weapon->name() +HIR"��һʽ�ۻ�Ȼһ���ݣ���â�������޵���$n��ȥ��"NOR;
       	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	me->add_temp("apply/attack", -(extra*2));
	me->add_temp("apply/damage", -(extra*2));
        me->add_temp("apply/strength", -extra);
        me->start_busy(1);
	return 1;
}
