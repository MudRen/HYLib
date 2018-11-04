// shengang.c ���������������

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
	object weapon;	
  	string msg;
	int d_count, count, qi, maxqi, skill;

	if( (int)me->query_temp("shengang") ) 
		return notify_fail(HIG"���Ѿ����˻�������ˡ�\n");

	if( !me->is_fighting() )
    	return notify_fail("���������ֻ����ս����ʹ�á�\n");

	if( (int)me->query("neili") < 200 )
		return notify_fail("���������������\n");

	if( (int)me->query_skill("force") < 150)
		return notify_fail("��Ļ�����������Ϊ����������ʹ�û������! \n");
//�����б������ӱ�������
	msg = HIY "$Nʹ�����������������������������ע�����ģ�\n" NOR;

	qi = me->query("qi");
	maxqi = me->query("max_qi");
	skill = (int) (me->query_skill("huntian-qigong",1) / 3);
	count = me->query_str();
	d_count = (int)me->query_dex() / 2;

	if(qi > (maxqi * 0.4))
	{	
		message_combatd(msg, me, target);
		me->add_temp("apply/damage", skill*2);
		me->set_temp("shengang", 1);
		me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill*2 :), skill);

		me->add("neili", -150);
	}
	else{
		msg = HIR "$Nƴ�������������������������Լ�����̫�أ�û�ܳɹ�!\n" NOR;
	}
//	if(userp(target)) target->fight_ob(me);
//	else if( !target->is_killing(me) ) target->kill_ob(me);
	return 1;
}

void remove_effect(object me, int amount)
{
	if ( (int)me->query_temp("shengang") ) 
	{
		me->add_temp("apply/damage", - amount);
		me->delete_temp("shengang");
		tell_object(me, HIY "��Ļ������������ϣ��������ջص��\n" NOR);
		me->start_busy(2);
	}
}
