// neilisuck.c

#include <ansi.h>

inherit F_SSERVER;
int exert(object me, object target)
{
	int sp, dp;

	if ( target == me ) target = offensive_target(me);
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
 return notify_fail("ֻ����ս���в���ʹ�á�\n");

	if( environment(me)->query("no_fight") )
		return notify_fail("�����ﲻ�ܹ������ˡ�\n");
	if( !objectp(target) || target->query("id") == "mu ren" )
		return notify_fail("��Ҫ��ȡ˭��������\n");
	if (target->query("race") != "����")
		return notify_fail("����ˣ�ֻ���˲�����������\n");

	if ( me->query_temp("sucked") )
		return notify_fail("��ո���ȡ��������\n");

	if( (int)me->query("neili") > 20000 )
		return notify_fail("���������̫�࣬������ȡ�ˡ�\n");

	if( objectp(me->query_temp("weapon")) )
		return notify_fail("�������ֲ���ʩ�û���������������\n");

        if( !me->is_fighting() || !target->is_fighting())

	if( (int)me->query_skill("huagong-dafa",1) < 60 )
		return notify_fail("��Ļ����󷨹���������������ȡ�Է����������\n");

	if( (int)me->query("neili",1) < 20 )
		return notify_fail("�����������������ʹ�û����󷨡�\n");

	if( (int)target->query("max_neili") <= 0 )
		return notify_fail( target->name() +
			"û���κ�������\n");

        if( (int)target->query("neili") < 60 )
		return notify_fail( target->name() +
			"�Ѿ�������ɢ�����Ѿ��޷�����������ȡ�κ������ˣ�\n");

       if( target->query_temp("no_kill") )
        return notify_fail("���ܴ򣬴򲻵ð���\n");

        if(target==me)
        return notify_fail("�� suicide ָ���ȽϿ�:P��\n");

       if(me->is_busy())
        return notify_fail("��������æ��\n");
        
	message_combatd(
		HIR "$Nһ����ͻȻ��òҰף�����ֱ�����͵ض�׼$n�����д�Ѩ������ȥ��\n\n" NOR,
		me, target );

	if ( living(target) )
	{
me->kill_ob(target);
target->fight_ob(me);
//		if( !target->is_killing(me) ) target->kill_ob(me);
	}

        sp = me->query_skill("force") + me->query_skill("dodge") + me->query_skill("zhaixinggong",1)/2;
        dp = target->query_skill("force") + target->query_skill("dodge");

	me->set_temp("sucked", 1);		

        if (( random(sp) > random(dp) ) || !living(target) )
	{
		tell_object(target, HIR "��پ�����΢ʹ����ͬ��������˸�С�ף�ȫ��������ˮ����ѭ�׷�й������\n" NOR);
		tell_object(me, HIG "�����" + target->name() + "������������ԴԴ���������˽�����\n" NOR);

		target->add("neili", -1*((int)me->query_skill("huagong-dafa", 1) + target->query("jiali")) );
            if ( target->query("neili") <1 ) target->set("neili",0);
		me->add("neili", (int)me->query_skill("huagong-dafa", 1)/2 + target->query("jiali") );

		if( target->query("combat_exp") >= me->query("combat_exp") ) {		
			if( (int)me->query("potential") - (int)me->query("learned_points") < 100 )
				me->add("potential", 1);
			me->add("combat_exp", 1);
		}

                me->start_busy(4);
		target->start_busy(random(4));
                me->add("neili", -7);

		call_out("del_sucked", 2, me);
	}
	else
	{	
		message_combatd(HIY "����$p������$P����ͼ�������͵�һ�𣬽������˿�ȥ��\n" NOR, me, target);
		me->start_busy(4);
		call_out("del_sucked", 4, me);
	}

	return 1;
}

void del_sucked(object me)
{
	if ( me->query_temp("sucked"))
	me->delete_temp("sucked");
}

