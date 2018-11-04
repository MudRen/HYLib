// luowang.c ���޵��� �����޵�����
// by liu 23/07/2001
// Xuanyuan 5/9/2001�޸�
/*
������˫�۷��裬��ֻ�������ƻ�����ǧ��ǧ�ƣ�������ʮһֻ��ȸ��ηɹ���
�ˣ�ʼ�շɲ�����ֻ����Χ����Ȧ�ӡ����ֻ����Ŀ�ɿڴ����־���ϲ��һ����
�䣬��ʱ�뵽�����ù����ڽ���һ�������Ʒ��������ļ��š�����������ۿ���
��γ��ֵ�������λر۷��ˡ���������죬��һ��һʽ������������Գɶ��䡣
������˰��Σ���Ȼ�����Ʒ��еľ�΢֮�������Ѳ��Ƴ���ʱ��ô������֡�
*/

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

int perform(object me, object target)
{
	string msg;
	object weapon;
	int skill;
	skill = me->query_skill("tianluo-diwang",1);

	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
                return notify_fail("�����޵�����ֻ����ս����ʹ�á�\n");

	if((int)me->query_str() < 25)
		return notify_fail("���������,����ʹ����һ����!\n");

	if((int)me->query_skill("yunv-xinfa",1) < 100)
		return notify_fail("����Ů�ľ��Ĺ�����������ʹ�����޵���!\n");

	if((int)me->query_skill("tianluo-diwang",1) < 120)
		return notify_fail("����Ʒ���Ϊ����,Ŀǰ������ʹ�����޵�������!\n");

	if((int)me->query("neili") < 300)
		return notify_fail("���������ڲ���, ����ʹ�����޵���! \n");

	if( target->is_busy() )
		return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɢ�\n");

	if( target->query_temp("luowang") )
		return notify_fail("��������������޵�����֮�У�\n");

	message_vision(HIM "\n����$N˫�۷��裬���ֵ����ر۷��˷�����죬��һ��һʽ��������Գɶ��䣬��ֻ�������ƻ�����ǧ��ǧ�ƣ�\n"NOR, me,target);

	if( random(me->query("combat_exp"))+(int)me->query_skill("tianluo-diwang",1)*800 > (int)target->query("combat_exp") / 3 )
	{
	message_vision( CYN "\n$N���´󺧣��ɹ����ˣ�ʼ���Ӳ���$nֻ����Χ����Ȧ��! \n" NOR,target,me);

		target->start_busy( (int)me->query_skill("tianluo-diwang",1) / (50+3) );
		target->add_temp("apply/parry", -60);
		target->add_temp("apply/dodge", -60);
		target->add_temp("apply/defense", -60);
		
		target->set_temp("luowang",1);
		me->add("neili", -150);
		call_out("checking", 1, me, target,skill);
		if(userp(target)) call_out("remove_effect", skill/30, me, target, skill); 
			else call_out("remove_effect", skill/30, me, target, skill);
	}
	else
	{
	message_vision( HIY "\n$N�������ң�������$n���ջ�����һԾ�����˿�ȥ��\n" NOR,target,me);
		me->start_busy(2);
		me->add("neili", -100);
		return 1;
	}

	return 1;
}

void checking(object me, object target, int skill)
{
if (!me) return;
if (!target) return;
	if ( target->query_temp("luowang_finished"))
		target->delete_temp("luowang_finished");
	else {
	if( !living(me) || me->is_ghost() )
	{
		target->delete_temp("luowang");
		target->add_temp("apply/defense", 60);
		target->add_temp("apply/parry", 60);
		target->add_temp("apply/dodge", 60);
		remove_call_out("remove_effect");
		message_vision(HIG"�����ģ�$n�Ѳ��Ƴ���ʱ��ô������֡�\n\n"NOR,me,target);
		return ;
	}
	if( !me->is_fighting() )
	{
		target->delete_temp("luowang");
		target->add_temp("apply/defense", 60);
		target->add_temp("apply/parry", 60);
		target->add_temp("apply/dodge", 60);
		remove_call_out("remove_effect");
		message_vision(HIG"�����ģ�$n�Ѳ��Ƴ���ʱ��ô������֡�\n\n"NOR,me,target);
		return ;
	}

	else call_out("checking", 1, me, target,skill);
		return;
	}
	return;
}
private int remove_effect(object me, object target, int skill)
{
if (!me) return 1;
if (!target) return 1;
	target->delete_temp("luowang");
		target->add_temp("apply/defense", 60);
		target->add_temp("apply/parry", 60);
		target->add_temp("apply/dodge", 60);
	target->set_temp("luowang_finished",1);
	message_vision(HIG"�����ģ�$n�Ѳ��Ƴ���ʱ��ô������֡�\n\n"NOR,me,target);
	return 1;
}
