// tie@fengyun

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	int i,a;
	object weapon;
	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("���ƽ���ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	 
    if( (int)me->query("neili", 1) < 600 )
		return notify_fail("�������������㣬����ʹ�ã�\n");	
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("�����ƽ�����ֻ�ܿ���ʹ�á�\n");		

	if( (int)me->query_skill("tiezhang-zhangfa", 1) < 50 )
		return notify_fail("��������Ʒ�������죬���������ƽ�����\n");

	if( (int)me->query_skill("guiyuan-tunafa", 1) < 60 )
		return notify_fail("��Ĺ�Ԫ���ɷ�������죬����ʹ�����ƽ�����\n");

   if (me->query_skill_mapped("unarmed") != "tiezhang-zhangfa"
     ||me->query_skill_prepared("strike") != "tiezhang-zhangfa")
                return notify_fail("��û�а�������Ϊ�����мܺͱ�Ϊ�Ʒ���\n");

	extra = me->query_skill("tiezhang-zhangfa",1) / 20;
	extra += me->query_skill("guiyuan-tunafa",1) /20;
 i = extra/4;
    if( (int)me->query("neili", 1) <  (80 * i) )
		return notify_fail("�������������㣬����ʹ�ã�\n");	
        me->add_temp("apply/attack", extra*2);    
        me->add_temp("apply/damage", extra*3);
	msg = HIR  "$N����۹�Ԫ���ɷ��ݣ�ͬʱʹ�������ƽ�����һ��һ����������糱ˮ��Ļ���$n��" NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg =  HIW "��һ����������������\n" NOR;
        message_vision(msg, me, target);
a=extra/3;
if (a> 11) a=11;
        for(i=0;i<a;i++)
	{
	msg = HIC "$N����ͻת��һ���ִ��˹�����\n" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	}
i = extra/4;
        me->add_temp("apply/attack", -extra*2);
        me->add_temp("apply/damage", -extra*3);
me->start_busy(3);
me->add("neili", - 70 * i);
	return 1;
}
