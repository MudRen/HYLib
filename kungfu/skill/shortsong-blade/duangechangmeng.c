// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	object weapon;
	extra = me->query_skill("shortsong-blade",1);
	if ( extra < 90) return notify_fail("��Ķ̸赶�����������죡\n");
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("�۶̸賤�Σ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "blade")
                        return notify_fail("��ʹ�õ��������ԡ�\n");
	if( (int)me->query("neili") < 500  ) 
		return notify_fail("�������������\n");
        me->add("neili",-100);

	weapon = me->query_temp("weapon");
	msg = HIY  "$Nʹ���̸赶���еģ۶̸賤�Σݣ�һ��������ʽ�����е�"+ weapon->name()+  "�������$n������һ����" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       msg = HIY  "�ڶ�����" NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	me->add_temp("apply/damage",extra*5);
       msg = HIY  "��������" NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	me->add_temp("apply/damage",-extra*5);
	me->start_busy(2);
	return 1;
}
