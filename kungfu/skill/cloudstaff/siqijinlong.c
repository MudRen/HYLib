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
		return notify_fail("�����������ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "staff")
                        return notify_fail("��ʹ�õ��������ԡ�\n");
	if( (int)me->query("neili") < 500  ) 
		return notify_fail("�������������\n");
        me->add("neili",-200);
	weapon = me->query_temp("weapon");
	extra = me->query_skill("staff",1) / 10;
	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", extra);
	msg = HIR  "$N"HIR"�ͺ���ţ���������˫�ۣ��趯���е�"+ weapon->name() +"����������ݵ�һ�� ##������Ұ##������������$n��" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        msg = HIG  "$N"HIG"΢̽˫�ۣ�ƾ��һ��,���е�"+ weapon->name() +"��׼$nʹ������������ݵĵڶ���  ##��������##  ��" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        msg = HIC  "$N"HIC"һ����Х����Ȼ̽�����е�"+ weapon->name() +"ʹ������������ݵ����� ##������Ԩ## �� �ó��������׷���������������$n��" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        msg = HIY  "$N"HIY"�����е�"+ weapon->name() +"�趯��ɣ���$nʹ������������ݵ����� ##�������## ��" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -extra);
	me->start_busy(2);
	return 1;
}
