// fanchang.c
// by secret
// 97-1-16
//

#include <ansi.h>

inherit F_SSERVER;
int exert(object me)
{
	int sp, dp;
object target; 
	if ( target == me )
		target = offensive_target(me);
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
 return notify_fail(RED"��Ҫ��˭ʹ��?\n"NOR);
	if( environment(me)->query("no_fight") )
		return notify_fail("���ﲻ�ܹ�������! \n");

	if( !objectp(target) || target->query("id") == "mu ren" )
		return notify_fail("��Ҫ����˭��\n");

	if( (int)me->query_skill("longxiang",1) < 50 )
		return notify_fail("�����������������������������񹥻��Է���\n");

	if( (int)me->query("neili",1) < 50 )
		return notify_fail("�����������������ʹ�������������\n");
//pk
    if(target==me)
        return notify_fail("�� suicide ָ���ȽϿ�:P��\n");
if(userp(target) && target->query("combat_exp")/2 > me->query("combat_exp") )
	return notify_fail("����Ҫɱ���ˣ���������ǿ̫�࣬�㲻�Ҷ��֡�\n");
    if( userp(target) && me->query_condition("killer"))
        return notify_fail("���Ѿ���ͨ���ˣ���Ҫ����ɱ����ˣ�\n");
    if( userp(target) && target->query("combat_exp") < me->query("combat_exp") && me->query_condition("killer"))
        return notify_fail("���Ѿ���ͨ���ˣ���Ҫ����ɱ����ˣ�\n");
//
	message_combatd(HIW "$N���ޱ��飬�������󳪰����$n���У�\n\n" NOR, me, target );

	if( living(target))
{
			me->kill_ob(target);
                        target->fight_ob(target);
}
	sp = me->query_skill("force") + me->query_skill("mizongxinfa") + me->query_skill("longxiang",1)/2;
	dp = target->query_skill("force");
	
	if (( random(sp) > random(dp) ) || !living(target) )
	{
		tell_object(target, HIW " ���Ȼ��������һƬ�հף�����������������赸������\n" NOR);
		tell_object(me, HIB "�㿴��" + target->name() + "������ĸ��������㵸��ʮ�ֿ�Ц��\n" NOR);

		target->receive_damage("jing", 10 + random((int)me->query_skill("longxiang", 1)));
				
		if( target->query("combat_exp") >= me->query("combat_exp") )
			if( (int)me->query("potential") - (int)me->query("learned_points") < 100 )
				me->add("potential", 1);

		me->start_busy(2);
		target->start_busy(random(3)+2);
		me->add("neili", -50);

	}
	else
	{	
		message_combatd(HIY "����$p��Ϊ$P����������������Ȼ��ͬ���죡\n" NOR, me, target);
		me->start_busy(4);
	}

	return 1;
}
