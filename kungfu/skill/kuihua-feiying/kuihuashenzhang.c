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
		return notify_fail("��������ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("���������ơ�ֻ�ܿ���ʹ�á�\n");		

	if( (int)me->query("neili") < 400  ) 
		return notify_fail("�������������\n");

    if ( (string)me->query("gender")=="Ů��" )
        return notify_fail("Ů�Ӳ�����.\n");

   if ( (string)me->query("gender")=="����" )
        return notify_fail("��������Թ�,������.\n");
	if( (int)me->query_skill("kuihua-feiying", 1) < 50 )
		return notify_fail("��Ŀ�����Ӱ��������죬�����ÿ������ơ�\n");

	if( (int)me->query_skill("kuihua-xinfa", 1) < 60 )
		return notify_fail("��Ŀ����ķ�������죬����ʹ�ÿ������ơ�\n");

	extra = me->query_skill("kuihua-feiying",1) / 20;
	extra += me->query_skill("kuihua-xinfa",1) /20;
	me->add_temp("apply/attack", (extra*2));	
	me->add_temp("apply/damage", (extra*2));
	msg = HIR  "$N����ۿ����ķ��ݣ�ͬʱʹ���ۿ������ƣ������Ĵ���$n��" NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg =  HIW "$N����Ӱ����˼�������������\n" NOR;
        message_vision(msg, me, target);
a=extra/3;
if (a> 10) a=10;
me->set_temp("action_flag", 1);
	for(i=0;i<a;i++)
	{
	msg = HIC "��$n�����Գ���һ����Ӱ��һ����$n���˹�ȥ��\n" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	}
me->delete_temp("action_flag");
i = extra/4;
	me->add_temp("apply/attack", -(extra*2));
	me->add_temp("apply/damage", -(extra*2));
me->add("neili", - 40 * i);
	me->start_busy(2);
	return 1;
}
