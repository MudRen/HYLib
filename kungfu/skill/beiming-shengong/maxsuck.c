// maxsuck.c

#include <ansi.h>

inherit F_SSERVER;
int exert(object me, object target)
{
	int sp, dp;
	int my_max, tg_max;

	if ( target == me ) target = offensive_target(me);

	if( environment(me)->query("no_fight") )
		return notify_fail("�����ﲻ�ܹ������ˡ�\n");

	if( !objectp(target) || target->query("id") == "mu ren" )
		return notify_fail("��Ҫ��ȡ˭�ĵ�Ԫ��\n");
        if (target->query("race") != "����")
                return notify_fail("����ˣ�ֻ���˲����е�Ԫ��\n");
       
        my_max = me->query("max_neili");
        tg_max = target->query("max_neili");

	if ( me->query_temp("sucked") )
		return notify_fail("��ո���ȡ����Ԫ��\n");

	if( (int)me->query("neili") > 20000 )
		return notify_fail("���������̫�࣬������ȡ�ˡ�\n");

	if( objectp(me->query_temp("weapon")) )
		return notify_fail("�������ֲ���ʩ�ñ�ڤ�����˵�Ԫ��\n");

        if( !me->is_fighting() || !target->is_fighting())

	if( (int)me->query_skill("beiming-shengong",1) < 90 )
		return notify_fail("��ı�ڤ�񹦹���������������ȡ�Է��ĵ�Ԫ���\n");

	if( (int)me->query("neili") < 20 )
		return notify_fail("�����������������ʹ�û����󷨡�\n");

	if( (int)me->query_skill("force") < (int)me->query("max_neili") /10 )
		return notify_fail("����ڹ�̫���ˣ�����ȡҲ��ͽ�͡�\n");

	if( (int)target->query("max_neili") < 100 )
		return notify_fail( target->name() +
			"��Ԫ��ɢ������δ�ۣ����޷�����������ȡ�κζ�����\n");

        if( (int)target->query("max_neili") < (int)me->query("max_neili")/10 )
		return notify_fail( target->name() +
			"���ڹ���ΪԶ�����㣬���޷�����������ȡ��Ԫ��\n");

       if( target->query_temp("no_kill") )
        return notify_fail("���ܴ򣬴򲻵ð���\n");

        if(target==me)
        return notify_fail("�� suicide ָ���ȽϿ�:P��\n");

       if(me->is_busy())
        return notify_fail("��������æ��\n");

	message_combatd(
		HIG "$Nȫ��һ��������֣���������$n���ֱ��ϡ�\n\n" NOR,
		me, target );

        if ( living(target) )
           {
            me->kill_ob(target);
//            if( !target->is_killing(me) ) target->kill_ob(me); 
           }

        sp = me->query_skill("force") + me->query_skill("dodge") + me->query_skill("zhaixinggong",1)/2;
        dp = target->query_skill("force") + target->query_skill("dodge");

	me->set_temp("sucked", 1);		

        if (( random(sp) > random(dp) ) || !living(target) )
	{
		tell_object(target, HIR "��ֻ��ȫ������ȫ��������ѩ����ʧ����Ӱ���٣�\n" NOR);
		tell_object(me, HIG "�����" + target->name() + "�ĵ�Ԫ������ԴԴ���������˽�����\n" NOR);

                target->add("max_neili",  -1*(1+(me->query_skill("beiming-shengong", 1)-90)/6) );
                me->add("max_neili",       1*(1+(me->query_skill("beiming-shengong", 1)-90)/6) );
                if ( target->query("max_neili") <1) target->set("max_neili",0);

//		if( (int)me->query("potential") - (int)me->query("learned_points") < 90 )
//			me->add("potential",  5);
//		me->add("combat_exp", 10);

                me->start_busy(7);
                target->start_busy(random(7));
                me->add("neili", -10);

		call_out("del_sucked", 10, me);
	}
	else
	{	
		message_combatd(HIY "����$p������$P����ͼ����������˿�ȥ��\n" NOR, me, target);
                me->start_busy(7);
		call_out("del_sucked", 20, me);
	}

	return 1;
}

void del_sucked(object me)
{
	if ( me->query_temp("sucked") )
	me->delete_temp("sucked");
}

