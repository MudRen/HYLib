//Cracked by Kafei
// chanrao.c �������澭���޷��������ơ�
// xQin 8/99
/*
�������޷���ã����м���ѽ���Ȧס��
�������ʲŽ߾�ȫ������Ȼ�޷������ı�Ȧ���ѳ������º������졣
*/

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	string msg, attack_skill, dodge_skill;
	int ap, dp, wp, rate;
	int whip, dodge, busy_time, random_factor;
	object weapon, weapon2;
	mapping prepare;

	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("ֻ����ս����ʩչ�����ơ���\n");

	if( !living(target) )
		return notify_fail("�����ڲ���ʹ�á����ơ���\n");

	if( !me->query_temp("weapon") || (weapon = me->query_temp("weapon"))->query("skill_type") != "whip" )
		return notify_fail("�����в��޳��ֵı��������ʩչ�����ơ���\n");

	if( me->query_temp("yield") )
		return notify_fail("�㲻���У����ԡ����ơ���\n");

	if( me->query_temp("jiuyin_chanrao/"+target->name()) )
		return notify_fail(target->name() +"�Ѿ��������ڱ�Ȧ���ˡ�\n");

	if( (whip = (int)me->query_skill("whip")) < 200 )
		return notify_fail("��ı޷�������죬ʩչ���������ơ���\n");

	if( me->query("neili") <= 500 )
		return notify_fail("�����ڵ����������Զ��޳�Ȧ��\n");

	if( me->query("jing") < 100 )
		return notify_fail("�����ڵ����������Զ��޳�Ȧ��\n");

	me->add("neili", -200);
	me->add("jing", -40);

	msg = HIG"\n$NͻȻ��$W"HIG"�������Ƴ�һ�������СС��Ȧ�ӣ��ۿ�Ҫ��$n������䡣\n"NOR;

	ap = COMBAT_D->skill_power(me, "whip", SKILL_USAGE_ATTACK);
	if( ap < 1 ) ap = 1;

	dp = COMBAT_D->skill_power(target, "dodge", SKILL_USAGE_DEFENSE);
	if( dp < 1 ) dp = 1;

        if( random(ap + dp) < dp )
        {
		dodge_skill = target->query_skill_mapped("dodge");
		if( !dodge_skill ) dodge_skill = "�Ṧ";
		else dodge_skill = to_chinese(dodge_skill);

		if( dp > ap*2 )
			msg += CYN"$p�Ƴ�����������ʩչ"+ dodge_skill +"���Ử�������ѳ�$W"CYN"���Ƶı�Ȧ��Χ��\n"NOR;
		else if( dp < ap*2/3 )
			msg += CYN"$p���´󺧣���æ�߾�ȫ��ʩչ"+ dodge_skill +"���ò����״�$W"CYN"���Ƶı�Ȧ���ѳ���\n"NOR;
		else	msg += CYN"$p����һ������ʱ������Ծ��ʩչ"+ dodge_skill +"��$W"CYN"���Ƶı�Ȧ֮������������\n"NOR;

		me->start_busy(1+random(3));
	}
	else
	{
		msg += WHT"$p$w"WHT"�Ͼ�����$P��ôһ������ʱ����������ת�˼�����";

		if( objectp(weapon2 = target->query_temp("weapon")) )
		{
			ap = (int)me->query("neili") / 10
				+ whip + (int)me->query_skill("force");
			dp = (int)target->query("neili") / 10
				+ (int)target->query_skill("parry")
				+ (int)target->query_skill("force");

			switch( weapon2->query("skill_type") )
			{
				case "bow"    : wp = 1; break;
				case "whip"   : wp = 1; break;
				case "sword"  : wp = 2; break;
				case "hook"   : wp = 2; break;
				case "blade"  : wp = 2; break;
				case "pike"   : wp = 3; break;
				case "stick"  : wp = 3; break;
				case "club"   : wp = 3; break;
				case "staff"  : wp = 4; break;
				case "axe"    : wp = 5; break;
				case "hammer" : wp = 5; break;
				default       : wp = 3; break;
			}
			rate = 11/8;
			if( (ap>=dp) && ((random(ap-dp)+wp)*rate > wp) ) 
			{
				msg += "��$w"WHT"�������\n"NOR;
				weapon2->unequip();
				weapon2->move(environment(target));
				target->reset_action();
			}
			else msg += "��\n"NOR;
		}
		else msg += "��\n"NOR;

		target->start_busy(2);
		target->set_temp("guarding", 0);

		if( !me->query_temp("guarding") )
                	me->set_temp("guarding", 1);

		dodge = target->query_skill("dodge");
		busy_time = (int)whip/8 - (int)dodge/10 + 1;
		if( busy_time < (int)whip/60 ) busy_time = (int)whip/60;
		if( busy_time > (int)whip/20 ) busy_time = (int)whip/20;
		if( wizardp(me) ) tell_object(me, sprintf("\nbusy time: %d, ", busy_time));

		random_factor = busy_time/5;
		if( random_factor > 6 ) random_factor = 6;
		if( random_factor < 2 ) random_factor = 2;
		switch( random(2) )
		{
			case 0 : busy_time += random(random_factor); break; 
			case 1 : busy_time -= random(random_factor); break;
		}
		if( wizardp(me) )
			tell_object(me, sprintf("random factor: %d, new busy time: %d", random_factor-1, busy_time));

		me->delete_temp("jiuyin_chanrao");
		me->add_temp("jiuyin_chanrao/"+target->name(), busy_time);

		remove_call_out("jiuyin_chanrao");
		call_out("jiuyin_chanrao", 1, me, target, weapon);
	}
	msg = replace_string(msg, "$W", weapon->name());
	if( objectp(weapon2) )
		msg = replace_string(msg, "$w", weapon2->name());
	else 
	{
		prepare = target->query_skill_prepare();
		if( !prepare ) prepare = ([]);

		switch( sizeof(prepare) )
		{
			case 0: attack_skill = "unarmed"; break;
			case 1: attack_skill = (keys(prepare))[0]; break;
			case 2: attack_skill = (keys(prepare))[random(2)]; break;
		}
		switch( attack_skill )
		{
			case "strike" :	msg = replace_string( msg, "$w", "��" ); break;
			case "cuff" :	msg = replace_string( msg, "$w", "ȭ" ); break;
			case "claw" :	msg = replace_string( msg, "$w", "צ" ); break;
			case "finger" :	msg = replace_string( msg, "$w", "ָ" ); break;
			case "hand" :	msg = replace_string( msg, "$w", "��" ); break;
			case "kick" :	msg = replace_string( msg, "$w", "��" ); break;
			default :	msg = replace_string( msg, "$w", "ȭ��" ); break;
		}
	}
	message_vision(msg, me, target);
	return 1;
}

void jiuyin_chanrao(object me, object target, object weapon)
{
	if( !me ) return;

	if( !living(me) || me->is_ghost() || me->query("neili") <= 100 )
	{
		me->delete_temp("jiuyin_chanrao");
		return;
	}
	if( weapon != me->query_temp("weapon") && living(target) )
	{
		me->delete_temp("jiuyin_chanrao");
		message_vision("\n$N����"+ weapon->name() +"һʧ��$n�ٸ�ѹ��������������Ȧ���ѳ���\n", me, target);
		return;
	}
	if( !me->is_fighting(target) ) 
	{
		me->delete_temp("jiuyin_chanrao");
		message_vision("$N����"+ weapon->name() +"һ�������˻�����\n", me);
		return;
	}
	if( me->query_skill_mapped("whip") != "feiyu-bian" )
	{
		me->delete_temp("jiuyin_chanrao");
		message_vision(HIG"\n$Nһ��"+ weapon->name() +HIG"���޷����䣡\n"NOR, me);
		return;
	}
	if( !me->query_temp("jiuyin_chanrao") && living(target) )
	{
		message_vision("\n$n�߾�ȫ������춴�$N�ı�Ȧ���ѳ���\n", me, target);
		return;
	}

	call_out("jiuyin_chanrao", 1, me, target, weapon);
}
