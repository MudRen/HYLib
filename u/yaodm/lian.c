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
                return notify_fail("�ٲ������Ĳ�����ӿֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");

	if( (int)me->query("neili") < 400  ) 
		return notify_fail("�������������\n");
        if( (int)me->query_skill("xuantie-jianfa", 1) < 50 )
                return notify_fail("����ٲ�����������죬�����ò�����ӿ��\n");

        extra = me->query_skill("xuantie-jianfa",1) / 10;

	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", extra);
        msg = HIR  "$Nʹ�����ٲ������УݵĲ�����ӿ�����е�"+ weapon->name() +" һ������һ�������Ļ���$n��" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        msg =  HIW "һ�����˴�������ʧ��������\n" NOR;
        message_vision(msg, me, target);
        for(i=0;i<extra/3;i++)
	{
        msg = HIY "$N���Ƴ���һ�����ˣ�����������\n" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	}
	i = extra/4;
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -extra);
	me->add("neili", - 60 * i);
	me->start_busy(3);
	return 1;
}

