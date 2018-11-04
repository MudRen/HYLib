// duo.c ���������
 
#include <ansi.h>
 
inherit F_SSERVER;
 
int perform(object me)
{
	string msg;
	object weapon, weapon2, target;
	int skill, dp, damage;

	me->clean_up_enemy();
	target = me->select_opponent();

	if( (int)me->query_temp("duo") )
		return notify_fail("���Ѿ��ڶ���˵ı����ˡ�\n");
	skill = me->query_skill("zhemei-shou",1);

	if( !(me->is_fighting() ))
		return notify_fail("���������ֻ�ܶ�ս���еĶ���ʹ�á�\n");
 
	if (objectp(weapon = me->query_temp("weapon")))
		return notify_fail("�������֡�\n");

	if (!objectp(weapon2 = target->query_temp("weapon")))
	   return notify_fail("�Է�û�б��У��㲻�õ��ġ�\n");

	if( skill < 50)
		return notify_fail("�����ɽ��÷�ֵȼ�����, ���ܿ�������У�\n");

        if (((int)me->query_skill("bahuang-gong", 1) < 50) &&
            ((int)me->query_skill("beiming-shengong", 1) < 50 ))
        return notify_fail(RED"�㱾���ڹ���򲻹���ʹ���������ֶ���С���\n"NOR);

	if( me->query("neili") < 50 )
		return notify_fail("��������������޷���������У�\n");
 
	msg = CYN "$N�����Ϣ������ʩչ��������еľ���. \n";
	message_combatd(msg, me);
     if( weapon2->query("ownmake"))
                return notify_fail("�����������᲻������\n");
     if( weapon2->query("no_get") && weapon2->query("no_drop") )
                return notify_fail("�����������᲻������\n");

	dp = target->query_skill("dodge",1);
	if( dp < 1 )
		dp = 1;
	if( random(skill) > random(dp) )
	{
		if(userp(me))
			me->add("neili",-50);
		msg = "$Nʹ����������еľ���, $n��ʱ������ǰһ��������һ�飬���б������ֶ�����\n" NOR;
		target->start_busy(2);
		weapon2->move(me);
		if (weapon2->query("ownmake")==1)
		{
			weapon2->move(target);
			msg += "�ǿ���$n������һ$n��һ�콫���������\n" NOR;
		}
		me->start_busy(2);
	}
	else
	{
		msg = "����$n�Ŀ�����$N����ͼ�����̲�ȡ���ƣ�ʹ$Nû�ܶ��±��С�\n"NOR;
		me->start_busy(2);
	}
	message_combatd(msg, me, target);
	if(!target->is_fighting(me)) target->fight_ob(me);
	return 1;
}
