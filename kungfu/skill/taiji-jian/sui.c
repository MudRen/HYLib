// sui.c ̫������ [��]�־�

#include <ansi.h>
#include <combat.h>
void remove_effect(object me, int a_amount, int d_amount);


inherit F_SSERVER;
int perform(object me, object target)
{
	object weapon;
	int skill,extra;
	string msg;

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("̫���������桹�־�ֻ����ս����ʹ�á�\n");

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");

	if( (int)me->query_skill("taiji-jian", 1) < 40 )
		return notify_fail("���̫������������죬����ʹ�á��桹�־���\n");

        if (me->query_skill("taiji-shengong", 1)<40)
                return notify_fail("��ı����ڹ����δ������\n");

	if( (int)me->query("neili") < 300  ) 
		return notify_fail("�������������\n");

	if( (int)me->query_temp("tjj_sui") ) 
		return notify_fail("���Ѿ����˹����ˡ�\n");

	skill = me->query_skill("taiji-jian");

	extra = me->query_skill("taiji-jian",1) / 20;
	extra += me->query_skill("taiji-shengong",1) /20;
	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", extra);
    if( (int)me->query_skill("taiji-jian", 1) > 50 )
    {
    msg = HIC"$n��������һ������������$n�������˵�һ��Ȧ��"NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
    msg = HIG"$n��������һ������������$n�������˵ڶ���Ȧ��"NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
    msg = HIY"$n��������һ������������$n�������˵�����Ȧ��"NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
    }
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -extra);
   msg = HIB "���$Nʹ��̫���������桹�־�����Ȧ����С������ס��\n"NOR;

	message_combatd(msg, me, target);


	me->add_temp("apply/attack", -skill/4);
	me->add_temp("apply/dodge", skill/3);
	me->set_temp("tjj_sui", 1);

	me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill/4, skill/3 :), skill/4);

	me->add("neili", -100);
	if( me->is_fighting() ) me->start_busy(2);

	return 1;
}

void remove_effect(object me, int a_amount, int d_amount)
{
	int skill;
	skill = me->query_skill("taiji-jian");
	me->add_temp("apply/attack", skill/4);
	me->add_temp("apply/dodge", -skill/3);

	me->delete_temp("tjj_sui");
	tell_object(me, HIY "������־�������ϣ��������ջص��\n");
}
