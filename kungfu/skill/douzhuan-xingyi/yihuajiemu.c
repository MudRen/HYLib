// zhong.c �ƻ���ľ

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        object obj, victim;
        int damage, lvl, r_lvl, count, form, skill, i;
        string msg;

	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) )
	return notify_fail("�ƻ���ľֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if( environment(me)->query("no_fight") )
		return notify_fail("���ﲻ׼��ܡ�\n");

	if( !target || !target->is_character() )
		return notify_fail("�ƻ���ľֻ���ڶ�������ʹ�á�\n");

	if( (int)me->query_skill("douzhuan-xingyi",1)<80)
	return notify_fail("������ƶ�ת������죬����ʹ�á��ƻ���ľ����\n");

	if( (int)me->query_skill("yanling-shenfa",1)<80)
	return notify_fail("����������������ݣ�����ʹ�á��ƻ���ľ����\n");

	if( (int)me->query_skill("shenyuan-gong",1)<100)
	return notify_fail("��ı����ڹ�����������ʹ�á��ƻ���ľ����\n");

	msg = HIC "$N��$nȫ��ľ���,˳����λ�����$n����\n";

	me->start_busy(2);
        skill = (int)me->query_skill("douzhuan-xingyi", 1);
	lvl = skill/20;
	r_lvl = random(lvl);
	if( r_lvl < 1) r_lvl = 1;
	count = me->query_str();
        victim =target;
        if (random((int)me->query("combat_exp")) > (int)target->query("combat_exp")/3 )
        {
                target->start_busy(random(3));
                
                damage = skill/2 + r_lvl*target->query("jiali",1);
                
                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage/2);
                me->add("neili", -damage);
		msg += HIG"��$n������ȫ��������ȥ��\n" NOR;
                
                if( damage < 20 )
                        msg += HIR"���$n�ܵ�$N�����������ƺ�һ����\n"NOR;
        	else if( damage < 40 )
                        msg += HIC"���$n��$N���������𣬡��١���һ������������\n"NOR;
        	else if( damage < 80 )
                        msg += HIG"���$n��$N������һ���ؿ������ܵ�һ���ش�����������������\n"NOR;
                else
                        msg += HIY"���$n��$N������һ����ǰһ�ڣ���һ������һ���ɳ�ȥ�ü���Զ��\n"NOR;
                
        }
        else 
        {
                msg += CYN"����$n�������˿����Ϊ������\n"NOR;
		me->add("neili", -100);
        }
        message_vision(msg, me, target);

        if ( (random(me->query("neili",1)) > 2*target->query("neili",1)/3 ) && ( r_lvl > random(5) ) )
        {
                write( CYN"�������ɹ��ˣ�\n"NOR);

		if( target == victim)
		{
		tell_object(target, HIC"�����ɼ����Լ������ľ���ȫ�������Լ���\n"NOR);
		message("vision", CYN"\n" + target->name() + "��Ȼ����ħһ�㣬���л����Լ���\n\n"NOR, environment(me), target);
		for(i = 0; i < r_lvl; i++)
if (!target->query("hunmi"))
{
			COMBAT_D->do_attack(target, victim, target->query_temp("weapon") );
}
else 		message("vision", CYN"\n" + target->name() + "�Ѿ��첻���ˣ��򲻶��ˣ�\n\n"NOR, environment(me), target);
		}

		else
		{
		tell_object(target, CYN"�����ɼ�����" + victim->name() + "��ȥ��\n"NOR);
		message("vision", CYN"\n" + target->name() + "��Ȼ��" + victim->name() +"��ȥ��\n\n"NOR, environment(me), ({target, victim}) );
		tell_object(victim, CYN"\n" + target->name() + "��Ȼ����������\n\n"NOR);

if (!target->query("hunmi"))
{
		COMBAT_D->do_attack(target, victim, target->query_temp("weapon") );
}
else 		message("vision", CYN"\n" + target->name() + "�Ѿ��첻���ˣ��򲻶��ˣ�\n\n"NOR, environment(me), target);
		if( random(me->query("combat_exp")) > (int)victim->query("combat_exp")/2 )		
		{
			if( !victim->is_killing(target) ) victim->fight_ob(target);
		}
		else
		{
		tell_object(victim, HIW"��һ����ԭ����" + me->name() + "�ڵ���\n"NOR);
		tell_object(target, HIW"���ã��ҿ�" + victim->name() + "�����ϵ���û���ϵ���\n"NOR);
		write( HIG "���ã���" + victim->name() + "�����ˣ�\n"NOR);
		if( !victim->is_killing(me) ) me->kill_ob(victim);
		}

                target->start_busy(random(3));
		me->add("neili", -300);
		}
	}
	else
	{
		write( HIM"��ϧû�ɹ���\n"NOR);
		tell_object(target, HIM"��ǿ���������ڿ���ס�Լ���\n"NOR);
		me->add("neili", -100);
	}

        return 1;
	}
