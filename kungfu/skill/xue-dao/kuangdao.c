//kuang.c -Ѫ����Ѫ����
// Modified by Venus Oct.1997
#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
int perform(object me, object target)
{
    int extra;
	object weapon;
    string msg;
	extra=me->query_skill("xue-dao",1)/ 6;
    if( !target ) target = offensive_target(me);
    if( !target||!target->is_character()||!me->is_fighting(target) )
    return notify_fail("��ֻ�ܶ�ս���еĶ���ʹ�á�Ѫ������\n");
    if( (int)me->query_skill("xue-dao",1) < 120)
    return notify_fail("��Ŀǰ������ʹ������Ѫ������\n");
    	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "blade")
			return notify_fail("��ʹ�õ��������ԡ�\n");
	if( (int)me->query("neili") < 500 )
    return notify_fail("�������������\n");
    me->add("neili", -300);
    me->add_temp("apply/attack", extra);	
    me->add_temp("apply/damage", extra);
    msg = HIC"$N���еĵ���Ѫ��һ������ֻ����ǰһ��"NOR;
        message_vision(msg, me, target);                
	msg = RED  "<<<>>>Ѫ��һ�֣�" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = RED  "<<<<<>>>>>��ɽѪ������" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = RED  "<<<<<<>>>>>>Ѫ����𣡣���" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = RED  "<<<<<<<>>>>>>>Ѫ���ɺӣ�������" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = RED  "<<<<<<<<>>>>>>>>��Ѫ������!!!!" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
    me->add_temp("apply/attack", -extra);	
    me->add_temp("apply/damage", -extra);
	me->start_busy(2);


    return 1;
}

