// fuxue.c �黨ָ ���黨��Ѩ��

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	string msg;

	if( !target ) target = offensive_target(me);

        if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
                return notify_fail("���黨��Ѩ��ֻ����ս����ʹ�á�\n");

	if((int)me->query_str() < 25)
		return notify_fail("���������,����ʹ����һ����!\n");

	if((int)me->query_skill("hunyuan-yiqi",1) < 100)
		return notify_fail("���Ԫһ�����Ĺ�����������ʹ���黨��Ѩ!\n");

	if((int)me->query_skill("finger") < 100)
		return notify_fail("���ָ����Ϊ����,Ŀǰ������ʹ���黨��Ѩ����!\n");

	if((int)me->query("neili") < 300)
		return notify_fail("���������ڲ���, ����ʹ���黨��Ѩ! \n");

	if( target->is_busy() )
		return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɢ�\n");

	msg = HIY "$Nʹ���黨ָ�������黨��Ѩ������ס��$n��ȫ��ҪѨ, ʹ$n�������á�\n";

	if( random(me->query("combat_exp")) > (int)target->query("combat_exp") / 2 )
	{
		msg +=  HIG "���$p��$P���˸����ֲ���! \n" NOR;
		target->start_busy( (int)me->query_skill("nianhua-zhi",1) / 50 + 2);
		me->add("neili", -100);
	}
	else
	{
		msg += HIM "����$p������$P����ͼ����û���ϵ���\n" NOR;
		me->start_busy(4);
	}
	message_combatd(msg, me, target);

	return 1;
}
