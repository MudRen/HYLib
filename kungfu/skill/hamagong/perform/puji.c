// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
#include <armor.h>
#include <combat.h>

inherit F_SSERVER;
//void tie_result(object me, object target);
void tie_hit(object me, object target);
void pu_hit(object me, object target);

int perform(object me, object target)
{
	object armor,weapon;
	int damage;
	string *limb, type, result, str;


              
	type = "����";

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("�㲻��ս���С�\n");


	if ( objectp(me->query_temp("weapon")) )
		return notify_fail("���ֱֳ������޷�ʩչ��󡹦���Ʒ�������\n");

	if( (int)me->query_skill("hamagong", 1) < 120 )
		return notify_fail("��ĸ�󡹦��Ϊ������\n");

	if ( me->query_skill_mapped("force") != "hamagong")
		return notify_fail("��������ʹ���ڹ����Ǹ�󡹦��\n");

	if( me->query("neili") <= 600 )
		return notify_fail("�������������\n");
        if ((int)me->query_skill("xiyu-tiezheng",1) < 180)
                return notify_fail("��������������������ң��޷�ʹ�ã�\n");

        if ((int)me->query_skill("shentuo-zhang",1) < 180)
                return notify_fail("�������ѩɽ�ƻ������ң��޷�ʹ�ã�\n");
        if ((int)me->query_skill("chanchu-bufa",1) < 180)
                return notify_fail("�����ܲ����������ң��޷�ʹ�ã�\n");
        if ((int)me->query_skill("hamashengong",1) < 180)
                return notify_fail("��ĸ���񹦻������ң��޷�ʹ�ã�\n");
        if ((int)me->query_skill("lingshe-quan",1) < 180)
                return notify_fail("�������ȭ�������ң��޷�ʹ�ã�\n");
        if ((int)me->query_skill("qixian-wuxingjian",1) < 180)
                return notify_fail("����������ν��������ң��޷�ʹ�ã�\n");
        if ((int)me->query_skill("shexing-diaoshou",1) < 180)
                return notify_fail("������ε��ֻ������ң��޷�ʹ�ã�\n");
	me->delete_temp("puji_time");
	remove_call_out("pu_hit");
	pu_hit(me, target);

	return 1;
}

void pu_hit(object me, object target)
{
	object armor;
	int damage, time, ap, dp, pp, fap, hmg, force;
	string msg, *limb, type, result, str;
	object weapon;

	if( !target || !me->is_fighting(target) ) return;

	if( !living(me) || me->is_ghost() ) return;

	if( !target || environment(me) != environment(target) 
	        || !me->is_fighting() ) 
	        return;

	if( me->query_skill_mapped("force") != "hamagong" || 
	        me->query_skill_mapped("strike") != "hamagong") 
	        return;

	type = "����";

	hmg = (int)me->query_skill("hamagong", 1);
	force = (int)me->query_skill("force", 1);

	ap = COMBAT_D->skill_power(me, "strike", SKILL_USAGE_ATTACK);
	if( ap < 1 ) ap = 1;
	ap = ap*(1+time);

	dp = COMBAT_D->skill_power(target, "dodge", SKILL_USAGE_DEFENSE);
	if( dp < 1 ) dp = 1;
	
	pp = COMBAT_D->skill_power(target, "parry", SKILL_USAGE_DEFENSE);
	if( pp < 1 ) pp = 1;

	me->add_temp("puji_time", 1);
	time = (int)me->query_temp("puji_time");

	if( time == 1 ) msg = HIB "\n$N˫��һ�䣬�������������󡱵�һ����У������󡹦������˫���뷢����ǰ�Ƴ�����һ��ʵ��$P��������֮���ۣ�$n��Ȼ���ܵ�ɽ�麣Х��ľ���Ϯ����\n" NOR;
	else if( time == 2 ) msg = HIM "\n$N��һ�Ƹ��꣬�ڶ�������Ѹ���쳣�ĸϵ���ǰ��δ˥���󾢼������Ʒ�Խ�����ҡ�\n" NOR;
	else msg = HIR "\n$N�ۿ�ǰ����գ�ȴ���޻��ң�˳������һ�ƣ���"+chinese_number(time)+"�Ƶ��Ʒ�����ɳĮ�籩��һ���͹�һ�󣬺�Х����$n������\n"NOR;

	message_combatd(msg , me,target);
	
	me->add("neili", -hmg);

	fap = random(ap + dp);

	if( living(target) && fap < dp ) {

		if(time == 1) message_combatd(HIY "$n�ۼ���һ���������ͣ����Ȳ��ܣ����ֲ��ɣ�����˫��һ�㣬Ծ���ĳߣ��㿪����һ�ơ�\nֻ�������ڵ�һ�����죬$N��һ�Ƶľ�������һ�ɿ����ˣ���ʱ����������˾������ѡ�\n\n" NOR, me, target);
	
		else message_combatd(HIY "$n�ۼ���һ���������ڣ�����˫��һ�㣬��Ծ���ߣ��ֶ㿪����һ�ơ�\nֻ�����һ�����죬��󡹦�;����û�������������һƬ����������ƾ��ˡ�\n" NOR, me, target);
                if (! target->is_busy())
		target->start_busy(2+random(2));
		me->start_busy(1);
		if( me->query_skill("strike") > time*150 && time < 5)
			call_out("pu_hit",2+random(2),me,target);
	}

	else if( random(ap + pp)< pp && random(5) == 0 && target->query("race") == "����" )
	{
		weapon = target->query_temp("weapon");
		if(weapon)
		{
			weapon->unequip();
			weapon->move(environment(target));
			target->reset_action();
			message_combatd(HIR"$N�;��þ�����������֪�������"NOR + weapon->name() + HIR"���ַɳ����Ͻ�Ҳ��˫����ǰƽ�ơ���һ������Ӳ��Ӳ��ɲ��֮�䣬�����ﾹȻ��ס������\n"NOR, target );
		}
		else message_combatd(HIR"$N�;�������������֪���Ҳ��˫����ǰƽ�ơ���һ������Ӳ��Ӳ��ɲ��֮�䣬�����ﾹȻ��ס������\n\n"NOR, target );

		message("vision", HIW BLK"���˱��Ǻ��ݺ��ܡ��������Ĳ�����ͻȻ�������߽�ʬ���ƣ�����ָҲ����һ�����ƺ���Ҳ����һ�ڡ�\n\n"NOR, environment(me), ({ me, target }) );

		target->add("neili", -hmg);
                if (! target->is_busy())
		target->start_busy(3+random(2));
		me->start_busy(2+random(2));
		remove_call_out("tie_hit");
		call_out("tie_hit",3+random(2),me,target);
	}

	else {
		if( target->query_temp("armor/cloth") )
			armor = target->query_temp("armor/cloth");

		if( (!living(target) || (!armor || (armor && armor->query("armor_prop/armor") < 150) )) && ( target->query_skill("dodge")+target->query_skill("parry") ) < random((me->query_skill("strike") + me->query_skill("force"))*2/3) && target->query("race") == "����")
		{
			message_vision(HIR"ֻ��$Nһ���ҽУ���һ������С��������$nһ������ͻȻƽƽ�ɳ����ڵ�һ�죬���������������֮�⣬ֱͦͦ�����ڵ��£���Ҳ������\n\n"NOR, target,target );
damage=(int)target->query("eff_qi");
if (damage > 9000) damage=9000;
                        target->receive_wound("qi", damage/2);
                        target->receive_damage("qi", damage);
			me->add("neili", -(me->query("jiali")+hmg/2));
			//me->add("jing", -me->query("jiali"));
		}
		else
		{
//			damage = random(((int)me->query_skill("strike"))+me->query("jiali"))*( 1 + random(me->query("jiajin")/5) ) ;

			damage = (me->query("jiali") + me->query("jiali")) * (int)me->query_skill("force")/60 + (random(hmg)+force)*time +me->query_temp("apply/damage");

			if(damage > me->query_skill("strike")*(8+time) ) damage = me->query_skill("strike")*(8+time);
			if(damage < me->query_skill("strike")*time ) damage = me->query_skill("strike")*time;
			me->add("neili", -(me->query("jiali")+hmg/2));

			target->receive_damage("qi", damage);
			target->receive_wound("qi", random(damage/2)+damage/4);
                        if (! target->is_busy())
			target->start_busy(1+random(3));

			limb = target->query("limbs");

			if(random(2) ) type = "����";
			result = COMBAT_D->damage_msg(damage, type);
			result = replace_string( result, "$l", limb[random(sizeof(limb))]);
			result = replace_string( result, "$p", target->name() );
			message_combatd(result, me, target);
		}
	}

	me->start_busy(3+random(2));
}


void tie_hit(object me, object target)
{
	int sum, n1, n2,damage;
	string msg;

	if( !target || !me->is_fighting(target) ) return;

	if( !living(me) || me->is_ghost() ) return;

	if( !target || environment(me) != environment(target) || !me->is_fighting() ) return;

	sum = me->query_skill("force") + me->query_skill("strike") + target->query_skill("force") + target->query_skill("parry");
	n1 = me->query("neili");
	n2 = target->query("neili");

	me->add("neili", -100 * sum / ( me->query_skill("force") + me->query_skill("strike") ) ); 
	if(me->query("neili")<0)me->set("neili",0);

	target->add("neili", -150 * sum / ( target->query_skill("force") + target->query_skill("strike") ) );
	if(target->query("neili")<0)target->set("neili",0);

	if( n1 > 3000 && n2 > 3000) {
		msg = WHT"��ʱ˫����������ǿ��������ʤ������ʹ�Է��ش����ɡ�\n"NOR;

		if( n1 > n2 )
		msg += HIW"�����ֽ���һ�ᣬ$nͷ��͸��һ���Ƶİ���������Խ��ԽŨ����������һ�㡣\n"NOR;
		else msg += HIW"�����ֽ���һ�ᣬ$Nͷ��͸��һ���Ƶİ���������Խ��ԽŨ����������һ�㡣\n"NOR;
	}

	else {

		if( n1 > n2 ) msg = WHT"$N���ϴ߶���󡹦�;�������˥�Ǽ����Թ�Ƭ�̣�$n����ȫ������졣\n"NOR;
		else msg = WHT"$N���Ϻ�����ʢ������󡹦���ӵ��˼��¡��Թ�Ƭ�̣�$N����ȫ������졣$n�ƺ���Ȼ����ʮ�㣬ͷ�������������ϡ�\n"NOR;
		}

	message_combatd(msg , me,target );


	if( me->query("neili") > 0 && target->query("neili") > 0 && me->is_busy() && target->is_busy() && living(me) && living(target) )
	{
                if (! target->is_busy())
		target->start_busy(3+random(2));
		me->start_busy(3+random(2));
		remove_call_out("tie_hit");
		call_out("tie_hit",2+random(2), me,target);
		return;
	}

	if( target->query("neili") <= 0 )
	{
		message_vision(HIR "\n$NͻȻ������������ȫ������ԭ��������ȫ���ľ���ͻ��ǰ��һƬ����֮�����ѱ���󡹦һ�ƻ��У���Ҳ�߲���һ����������������˫�۽��գ������ֽ���˵����������ϡ�\n\n" NOR, target);
damage=(int)target->query("eff_qi");
if (damage > 9000) damage=9000;
                        target->receive_wound("qi", damage/2);
                        target->receive_damage("qi", damage);
		return;
	}

	if( me->query("neili") <= 0 )
	{
		message_vision(HIR "\n$N���Ϻ���������ͻȻ������������ȫ������ԭ��������ȫ���ľ�����󡹦��ʱȫ����������������ǰ��һƬ����֮������Ҳ�߲���һ�������������˫�۽��գ������ī���˵����������ϡ�\n\n" NOR, me);
damage=(int)me->query("eff_qi");
if (damage > 9000) damage=9000;
                        me->receive_wound("qi", damage/2);
                        me->receive_damage("qi", damage);
	}

//	remove_call_out("tie_result");
//	call_out("tie_result",1,me,target);
}
