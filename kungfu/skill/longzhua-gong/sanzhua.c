// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	int orforce;
	object weapon;
	if(me->is_busy())
		return notify_fail("������û�գ���\n");
	extra = me->query_skill("longzhua-gong");
       if( (int)me->query_skill("longzhua-gong", 1) < 100 )
		return notify_fail("�����צ���������!\n");
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("����צ����ֻ�ܿ���ʹ�á�\n");		
        if( (int)me->query("neili", 1) < 300 )
                return notify_fail("�������������㣡\n");     

	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("����צ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
//	me->add("force_factor",extra/3);
//	orforce = (int) me->query("force");
//	me->add("force",extra/3*100);
	me->add_temp("apply/attack",extra);me->add_temp("apply/damage",extra*2);

	weapon = me->query_temp("weapon");
	msg = HIY  "$Nʹ����צ���������µģ���צ�ݣ����μӿ죡\n" NOR;
	message_vision(msg,me,target);
	msg = HIB  "�󹥣���һצ-��" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIC  "�ҹ����ڶ�צ---����" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIG  "Ծ�𣬵���צ------������" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
//	me->set("force_factor",0);
//	/me->set("force", orforce);
        me->add_temp("apply/attack",-extra);me->add_temp("apply/damage",-extra*2);
	me->start_busy(2);
        me->add("neili", -50);
	return 1;
}
