// fuxue.c ������Ѩ�� ��������Ѩ��

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	string msg;

	if( !target ) target = offensive_target(me);
if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
                return notify_fail("��������Ѩ��ֻ����ս����ʹ�á�\n");

	if((int)me->query_str() < 25)
		return notify_fail("���������,����ʹ����һ����!\n");

	if((int)me->query_skill("bibo-shengong",1) < 100)
		return notify_fail("��̲��񹦵Ĺ�����������ʹ��������Ѩ!\n");

	if((int)me->query_skill("hand") < 120)
		return notify_fail("����ַ���Ϊ����,Ŀǰ������ʹ��������Ѩ����!\n");

	if((int)me->query("neili") < 500)
		return notify_fail("���������ڲ���, ����ʹ���黨��Ѩ! \n");

	if( target->is_busy() )
		return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɢ�\n");

	msg = HIB "$N���ַ������������ָͷ��ת��һ��ʢ������������ӯ������$n��в��ҪѨ, ʹ$n�������á�\n";

	if( random(me->query("combat_exp")) > (int)target->query("combat_exp") / 3 )
	{
		msg +=  HIB "���$p��$P������ţ���ʱ�����޴룬��������! \n" NOR;
		target->start_busy( (int)me->query_skill("lanhua-shou",1) / 50 + 3 );
		me->add("neili", -100);
	}
	else
	{
		msg += HIY "����$p������$P����ͼ������һԾ�����˿�ȥ��\n" NOR;
		me->start_busy(1);
	}
	message_combatd(msg, me, target);

	return 1;
}

