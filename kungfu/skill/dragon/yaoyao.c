// β��ҡҡ

#include <ansi.h>

#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	string msg;
	int extra;
		object weapon;
	
extra = me->query_skill("dragon");
if(me->is_busy())
		return notify_fail("����̫æ���ò�����������\n");
		

	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("��β��ҡҡ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	
me->add_temp("apply/attack",extra*3);
me->add_temp("apply/damage",extra*3);

	
weapon = me->query_temp("weapon");
	
msg = HIY  "$N"HIY"�޴��ޱȵ�������ʼ���ҵĻζ�,ǿ�����β����˦����\n" NOR;
	message_vision(msg,me,target);
	msg = HIC  " ҡ����β��$n����ͻ�̶���!" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIC  "��ҡ������β����$n�����ɨ����!" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIC  "���һҡ��������β����$nȫ��ѹ������!" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);


	msg = HIC  "����" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIR  "��ҧ����" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIW  "���һ��������" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
target->apply_condition("ill_dongshang",30 );
target->apply_condition("ill_fashao",30 );
target->apply_condition("ill_kesou",30 );
target->apply_condition("ill_shanghan",30 );
target->apply_condition("ill_zhongshu",30 );

    me->start_busy(1); 	
me->add_temp("apply/attack",-extra*3);
me->add_temp("apply/damage",-extra*3);
		return 1;
}
