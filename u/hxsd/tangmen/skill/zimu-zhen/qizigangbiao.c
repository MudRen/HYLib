#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra,i,lmt,l;
	object weapon;
       if( !target ) target = offensive_target(me);
       if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("[���Ӹ���]ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	if( (int)me->query_skill("biyun-xinfa", 1) < 60 )
                return notify_fail("��ı����ķ������ߡ�\n");

        if( (int)me->query("neili", 1) < 400 )
                return notify_fail("����������̫����\n");

	weapon = me->query_temp("weapon");
	extra = me->query_skill("zimu-zhen",1);
	if ( extra < 200) return notify_fail("������Ű������������죡\n");
	msg = GRN  "$Nʹ�����Ű����е����Ӹ��ڣ�����$n" NOR;
	message_vision(msg,me,target);
	me->add_temp("apply/attack",extra/5);
	me->add_temp("apply/damage",extra/5);
        l=extra/30;
	lmt = random(l)+5;
	for(i=1;i<=lmt;i++)
	{
	msg =  BLU "��"+chinese_number(i)+"��" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	}
if (extra > 280)
{
        target->apply_condition("chanchu_poison", 10);
        target->apply_condition("xiezi_poison", 10);
        target->apply_condition("wugong_poison", 10);
        target->apply_condition("snake_poison", 10);
        target->apply_condition("zhizhu_poison", 10);

}

if (extra > 330)
{
        target->apply_condition("tmzhuihun_poison", 10);
        target->apply_condition("tmpili_poison", 10);
        target->apply_condition("zm_poison", 10);
}
        me->add_temp("apply/attack",-extra/5);
        me->add_temp("apply/damage",-extra/5);
        me->add("neili",-300);
	me->start_busy(3);
	return 1;
}
