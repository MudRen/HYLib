// tie@fengyun

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	int i;
	object weapon;
	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("���ҵ�����������ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "blade")
		return notify_fail("��ʹ�õ��������ԡ�\n");

	if( (int)me->query_skill("hujia-daofa", 1) < 50 )
		return notify_fail("��ĺ��ҵ���������죬�����õ���������\n");

	if( (int)me->query("neili") < 400  ) 
		return notify_fail("�������������\n");

	me->delete_temp("lianhuan");
	extra = me->query_skill("hujia-daofa",1) / 35;
	extra += me->query_skill("hujia-daofa",1) /35;
	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", extra);
	msg = HIR  "$Nһҧ�������϶����ӿ죬ͬʱʹ���ۺ��ҵ����Уݵĵ������������е�"+ weapon->name() +" һ������һ���������Ļ���$n��" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	msg =  HIR "��һƬ�����У�һ�����˹���\n" NOR;
        message_vision(msg, me, target);

	for(i=0;i<extra/5;i++)
	{
	msg = HIY "$Nҧ�����أ�һ�������˹�����\n" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	}
        i = extra/5;
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -extra);
        me->add("neili", -50 * i);
	me->start_busy(3);
	return 1;
}

