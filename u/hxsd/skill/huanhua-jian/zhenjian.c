// zhen.c 佻����� ֮ �Һ�ɹ���ǧ��

#include <ansi.h>
#include <weapon.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	int damage, attp, defp;
	object obj;
        string w_name;

	w_name = me->query("weapon/name");
	obj = me->query_temp("weapon");

	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("���Һ�ɹ���ǧȥ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if ((int)me->query_skill("huanhua-jian", 1) < 70)
		return notify_fail("���佻�����������죬�����˽����硣\n");


	if ((int)me->query("neili",1) < 320)
		return notify_fail("��������������޷�������г�������\n");

	message_vision( HIY "$N�����ڽ���Ĭ��������ֻ�������һ������Ȼ��������ҫ��$N���г�������Ϊ����\n"
	 + "�أ���������ư���$n���������\n"NOR, me, target );

	attp = me->query_skill("sword",1) + me->query_skill("huanhua-jian",1);
	defp = target->query_skill("dodge");

	if( random( attp ) > random( defp ) )
	{
		damage = me->query_skill("huanhua-jian",1) + (int)me->query_skill("sword", 1)*2;
		damage = damage - random( target->query_skill("dodge")/3 );

	        if( objectp(obj)&&w_name!=obj->query("name") )
		{
			target->receive_wound("jing", random( damage/3 ))*3;
			target->receive_damage("qi", 20 + random(damage))*3;
			target->receive_wound("qi", 20 + damage)*3;

			target->start_busy(3 + random(10));
		}
		else
		{
			target->receive_wound("jing", random( damage/3 ));
			target->receive_damage("qi", 20 + random(damage));
			target->receive_wound("qi", 20 + damage);

			me->start_busy(3);
			target->start_busy(3 + random(4));
		}
	}
	else {
		message_vision( HIY "����$p�ζ����Σ�Ѹ�ٵ������˽��ꡣ\n" NOR, me, target );
		me->start_busy(5);
	}

	if( !target->is_killing(me) ) target->kill_ob(me);

        me->add("neili", -200);

        if( objectp(obj) && w_name!=obj->query("name") )
	{
	        me->set("weapon/make",0);
        	destruct( obj );
	        me->delete("weapon");
        	me->save();
	}
	else destruct( obj );

	return 1;
}
