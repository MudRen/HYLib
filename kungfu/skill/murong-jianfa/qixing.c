// qixing.c /kungfu/skill/murong-jianfa/qixing.c ��ת����
// update by beyond 97.9.2

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

int perform(object me, object target)
{
	int damage;
	string msg;
        object weapon;
	int extra;
	weapon = me->query_temp("weapon");
        extra = (int)me->query_skill("murong-jianfa",1);
	if( !target ) target = offensive_target(me);

	if( !target
	    ||  !target->is_character()
	    ||  !me->is_fighting(target) )
		return notify_fail("��ת����ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if( (int)me->query_skill("murong-jianfa", 1) < 100 )
		return notify_fail("��Ľ�ת���ǻ�δ���ɣ�����ʹ�ã�\n");

        if (me->query_skill("shenyuan-gong", 1)<70)
                return notify_fail("��ı����ڹ����δ������\n");

	if( (int)me->query("neili") < 300 )
		return notify_fail("�������������㣬����ʹ�ý�ת���ǣ�\n");

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");


	if( (int)me->query_skill("sword", 1) < 100 )
		return notify_fail("��Ļ�������������죬����ʹ�ý�ת���ǡ�\n");
//if( (int)me->query_skill("murong-jianfa", 1) < 300 )
//{
	msg = HIY "\n$N��Ȼ����һת���������������棬ֻ���߶佣���������ֱ�Ϯ��$n��" +
		  "�ߴ�ҪѨ��\n"NOR;

	if ( random(me->query("dex")) > (int)target->query("dex")*2/3 )
	{
		msg += HIR"\n$pֻ����ȫ���ܵ������𵴣����İ��ʹ��һ����Ѫ��������϶�\n" +
			"���߸�Ѫ��ģ����Ѫ������\n" NOR;
		message_vision(msg, me, target);
		me->add("neili", -100);
	}

	else
	{
		msg += HIG"\n$p�鼱֮��˫�Űϵض��𣬿�������һ�����Ǳ��ض����һ�գ���ɫ��Ĳ԰ס�\n" NOR;
		message_vision(msg, me, target);
		me->start_busy(2);
	}
	if (random(me->query_skill("parry")) > target->query_skill("parry")/2 )
	{
		me->start_busy(2);

		damage = (int)me->query_skill("shenyuan-gong", 1);

		damage = damage*5/2 + random(damage);
		target->receive_damage("qi", damage);
		target->receive_wound("qi", damage);
		target->add("neili", -random(damage));
		me->add("neili", -100);
		if( damage < 300 ) msg += HIC"\n���$n��ɫ��òҰף������������˺ü�����\n"NOR;
		else if( damage < 400 ) msg += HIM"\n������صػ��У�$n���ۡ���һ���³�һ����Ѫ��\n"NOR;
		else if( damage < 500 ) msg += RED"\n������䡹��һ����$nȫ����Ѫ������������Ѫ���������\n"NOR;
		else msg += HIR"\n���ֻ���������������죬$nһ���ҽУ���̲�����������ȥ����\n"NOR;

	}
	else
	{
		me->start_busy(2);
		msg += HIG"\n$p�鼱֮��˫�Űϵض��𣬿�������һ�����Ǳ��ض����һ�գ���ɫ��Ĳ԰ס�\n" NOR;
	}
//}
        if(!(int)me->query_temp("lianhuan"))
{
if( (int)me->query_skill("murong-jianfa", 1) > 249 )
{
	me->add_temp("apply/attack", extra/10);	
	me->add_temp("apply/damage", extra/2);
message_vision(HIG"\n$N��Ȼ������ת��ֻ���߶佣���ٴ��������ֱ�Ϯ��$n���ߴ�ҪѨ��\n"NOR,me,target);
//message_vision(HIW"��תһ����"WHT"��"HIY"������"WHT"��\n\n"HIG"ֻ��$N����֮����һ������ֱ����$n�����壬$nֻ������һʹ���漴"HIC"������Ѩ��"HIG"�����޷����ݵľ�����ʹ��\n"NOR,me,target);        
msg = HIW"��תһ����"WHT"��"HIY"������"WHT"��\n\n"HIG"ֻ��$N����֮����һ������ֱ����$n�����壬$nֻ������һʹ���漴"HIC"������Ѩ��"HIG"�����޷����ݵľ�����ʹ��\n" NOR;
COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
msg = HIM"�Ƕ��ּ���"WHT"��"HIY"��ѣ��"WHT"��\n\n"HIG"ֻ��$N�����ٶ�����ֱ����$n�ļ�ͷ��$nֻ������һʹ���漴"HIC"���羮Ѩ��"HIG"����һ����Ҵ�ʹ��\n" NOR;
COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
msg = MAG"ת�Ǽ�����"WHT"��"HIY"�����"WHT"��\n\n"HIG"ֻ��$N�������ϣ������ֳ�����Ȼ�������ܵĴ���$n����ף�$nֻ����΢һʹ���漴"HIC"��ӿȪѨ��"HIG"����һ�������ʹ��\n" NOR;
COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
msg = YEL"��ת�Ķ���"WHT"��"HIY"��Ȩ��"WHT"��\n\n"HIG"ֻ��$N�������ǣ���ֱ����$n�����壬$nֻ�����ϱ�һ���Ҵ̣��漴�е�"HIC"��������Ѩ��"HIG"����һ�������ʹ��\n" NOR;
COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
msg = HIB"�������У�"WHT"��"HIY"�����"WHT"��\n\n"HIG"ֻ��$N����ƫ�棬��ֱ����$n�����࣬$nֻ������һ�����漴"HIC"������Ѩ��"HIG"��Ȼ���Ѫ����\n" NOR;
COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
msg = RED"�Ǿ�������"WHT"��"HIY"������"WHT"��\n\n"HIG"ֻ��$N�������ϣ����϶��´���$n��ͷ����$nͻȻ����ȫ�������������漴��Ѩ"HIC"���ٻ�Ѩ��"HIG"��Ȼ��ʹ�ޱȣ�" NOR;
COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
msg = HIR"��ת���ƣ�"WHT"��"HIY"ҥ����"WHT"��\n\n"HIG"ֻ��$N������������������������$n�������㣬�ཫ$n�ĵ�һ��Ѩ"HIC"��̫��Ѩ��"HIG"��������Ѫ����\n" NOR;
COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
message_vision(WHT"\n$N�������ǣ��ս�ͦ�����У�һ�����߷緶��Ȼ�������·��������$n�Ĵ��ڡ�\n"NOR,me,target);        
	me->add_temp("apply/attack", -extra/10);	
	me->add_temp("apply/damage", -extra/2);

        me->add("neili", -300);
        me->start_busy(3);
        return 1;
}
}
message_vision(msg, me, target);

	return 1;
}
