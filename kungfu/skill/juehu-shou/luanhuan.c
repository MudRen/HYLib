// luanhuan.c ̫��ȭ���һ�����
// xQin 1/99

#include <ansi.h>
inherit F_SSERVER;

int perform(object me, object target)
{
        string *circle, msg;

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("���һ�����ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if( !living(target) )
		return notify_fail("�����ڲ���ʹ�á��һ�������\n");

        if( (int)me->query("jiali") )
                return notify_fail("���ⲻ������̫��Բת��ʹ�Ͼ�������������Ի�Ȧ��Բ��\n");

	if( me->query("combat_exp") < 500000 )
		return notify_fail("��ʵս���鲻�㣬����ʹ�á��һ�������\n");

        if( (int)me->query_skill("juehu-shou", 1) < 150 )
                return notify_fail("��ľ����ֲ�����죬ʹ�������һ�������\n");
                                
        if( (int)me->query_skill("taiji-shengong", 1) < 150 )
                return notify_fail("��ı����ڹ���Ϊ�������޷��˹��˵С�\n");

        if( (int)me->query("max_neili", 1) < 2000 )
                return notify_fail("���������Ϊ�������޷��˹��˵С�\n");

        if( (int)me->query("neili", 1) < 200 )
                return notify_fail("�����ڵ�����̫�����޷��˹��˵С�\n");

        if( (int)me->query("jing", 1) < 100 )
                return notify_fail("�����ڵľ���̫����Ի�Բ��Ȧ��\n");

        if( me->query_skill_mapped("force") != "taiji-shengong")
                return notify_fail("�����õ��ڹ��롸�һ�������·��㣣�\n");

	circle = ({
		"$N��˫����������������˫�ֳ�Բ�λ������漴��Ȧ��Ȧ��һ��ԲȦ����һ��ԲȦ����Ȧ��СȦ��ƽȦ����Ȧ����Ȧ��бȦ��һ����̫��ԲȦ������",
		"$N�����֡�ʹ��ʱ���಻�ϣ���������пգ�һ��ԲȦδ�꣬�ڶ���ԲȦ������",
		"$N�Ҽ�б��������ƾ�ջ��˼���Ȧ�ӡ�",
	});

	msg = WHT"\n"+ circle[random(sizeof(circle))] +"\n";
        me->add("jing", -50);
//      me->add("jing", -50);

        if( random(me->query("combat_exp") * me->query_int() / 100) 
		> (int)target->query("combat_exp") * target->query_int() / 200 )
	{
		msg += HIY"���$N�Ի���֮�����Ƶ�$n����$P������Ȧ�ڡ�\n"NOR;
		me->start_busy(1);
		call_out("zhen", 1, me, target); 
	}
	else
	{
		msg += CYN"����$p������$P����ͼ����û���ϵ���\n"NOR;
		me->start_busy(1+random(2));
	}

	message_vision(msg, me, target);

	return 1;
}

int zhen(object me, object target)
{
	int damage;
	string *zhen, msg, result, str, type;

//	if (!me->is_fighting(target) || !living(target)) return;

	zhen = ({
		"����$N˫��һȦһת��ʹ�������Ͼ����еġ��귭�����������������ѽ�$nȦס��",
		"$N����ʹ��һ�С����֡������ָߣ����ֵͣ�һ��ԲȦ�ѽ�$n��ס��",
	});

	if ( random(me->query_skill("juehu-shou", 1)) > 199 )
	{
		type = "����";
		msg = HIY"\nֻ��$N����������������Ŀ�����������ֱۣ�˫��������£������������ɽ��ȴ�����������������գ�ʹ������������ˮ�������ޱȣ�\n"NOR
		"$nֻ�����̸�·��ȫ����$P˫�Ƶ�����֮�£��޿����ܣ��޿ɵ�����\n";
	}
	else
	{
		type = "����";
		msg = "\n"+ zhen[random(sizeof(zhen))] +"�漴Ǳ���񹦣���ͼ����������$n��\n";
	}

	if (target->query("neili") <= 0)
	{
		msg += "$pֻ��ǿ���˾���$P�࿹��������Ȼ�����Լ�������Ȼ�ݽߺľ���\n";
		if (type == "����")
			msg += RED"���ֻ���������������죬$nһ���ҽУ���̲�����������ȥ����\n"NOR;
		else 
			msg += RED"���ֻ�������项��һ�����죬$n��һ�����ݰ���˳�ȥ����\n"NOR;

		target->receive_damage("qi", (int)target->query("qi")+1, me);
	}
	else if (random((me->query_skill("juehu-shou") + me->query_skill("force")) * me->query_int() / 100) >
		(target->query_skill("parry") + target->query_skill("dodge")) * target->query_int() / 200 )
	{
		me->start_busy(1+random(2));
		target->start_busy(2+random(1));
                

		damage = (int)me->query_skill("force") + 
			(int)me->query_skill("claw")/2;                
		damage = damage/2 + random(damage);

		if(type == "����")
			damage = damage+me->query_skill("juehu-shou")/2;
		if(me->query("neili") > target->query("neili")*2)
			damage = damage+me->query_skill("juehu-shou")/2; 

		target->receive_damage("qi", damage, me);
		target->receive_wound("qi", damage/3, me);
		target->add("neili", -(damage/4));

		me->add("neili", -damage/10);

		result = COMBAT_D->damage_msg(damage, type);
		result = replace_string( result, "$p", target->name() );
		msg += result;

		str = COMBAT_D->status_msg((int)target->query("qi") * 100 /(int)target->query("max_qi"));
		msg += "( $n"+str+" )\n";
	}
	else if (random(me->query_skill("force")) > target->query_skill("force")/2 )
        {
                me->start_busy(1);
                target->start_busy(random(3));
                
                damage = (int)me->query_skill("taiji-shengong", 1);
                damage = damage/2 + random(damage);
                
                target->receive_damage("qi", damage, me);
                target->receive_wound("qi", damage/3, me);
                me->add("neili", -damage/10);

		msg+= HIR"$pֻ��ǿ���˾���$N�࿹��";
                if( damage < 20 ) 
			msg += "����ܵ�$P�����������ƺ�һ����\n"NOR;
                else if( damage < 40 ) 
			msg += "�����$P���������𣬡��١���һ������������\n"NOR;
                else if( damage < 80 ) 
			msg += "�����$P������һ���ؿ������ܵ�һ���ش�����������������\n"NOR;
                else 
			msg += "�����$P������һ����ǰһ�ڣ��������ɳ�������\n"NOR;
        }
	else if(me->query("neili")*2 < target->query("neili")) 
	{
		me->start_busy(3);
		target->start_busy(1+random(2));
                
		damage = (int)target->query_skill("force")/2;
		damage = damage/2 + random(damage);
                
		me->receive_damage("qi", damage, me);
		me->receive_wound("qi", damage/3, me);
		target->add("neili", -damage/10);
                
                if( damage < 20 ) 
			msg += HIY"����$P�ܵ�$p�����������ƺ�һ����\n"NOR;
                else if( damage < 40 ) 
			msg += HIY"����$P��$p���������𣬡��١���һ������������\n"NOR;
                else if( damage < 80 ) 
			msg += RED"����$P��$p�����������ؿ������ܵ�һ���ش�����������������\n"NOR;
                else 
			msg += HIR"����$P��$p������������ǰһ�ڣ��������ɳ�������\n"NOR;
	}
	else
	{
		me->start_busy(3);
		if (!target->is_busy())
		target->start_busy(3); 
		me->add("neili", -300);
		target->add("neili", -300);
		msg += HIY"$pֻ��ǿ���˾���$P�࿹���������Ӷ���һ�Σ������˿�������\n"NOR;
	} 

	message_vision(msg, me, target);
	return 1;
}


//������$N˫��һ�ϣ�һ�С�˫����硹��˫ȭ����$p��������������һ���ྡྷ����������࣬���ʤ����
