// tianlei.c ����--������

#include <ansi.h>


#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	int damage;
        int extra;
        string msg;
        object weapon;

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("������ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( objectp(me->query_temp("weapon")) )
		return notify_fail("�������ֲ���ʹ����������\n");

        if( (int)me->query_skill("guiyuan-tunafa", 1) < 119 )
		return notify_fail("�����������δ���ɣ�����ʹ�ã�\n");

        if( (int)me->query("neili", 1) < 600 )
		return notify_fail("�������������㣬����ʹ����������\n");	

	if( (int)me->query_skill("tiezhang-zhangfa", 1) < 119 )
		return notify_fail("��������Ʒ�������죬����ʹ����������\n");

   if (me->query_skill_mapped("unarmed") != "tiezhang-zhangfa"
     ||me->query_skill_prepared("strike") != "tiezhang-zhangfa")
                return notify_fail("��û�а�������Ϊ�����мܺͱ�Ϊ�Ʒ���\n");

        extra = me->query_skill("tiezhang-zhangfa",1) / 20;
	extra += me->query_skill("guiyuan-tunafa",1) /20;
    if( (int)me->query_skill("guiyuan-tunafa", 1) > 200 )
    {
        me->add_temp("apply/attack", extra*2);    
        me->add_temp("apply/damage", extra*3);
	    msg = HIC"$N��һ�ƣ�"NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
    msg = HIG"$N��һ�ƣ�"NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
    msg = HIY"$N��һ�ƣ�"NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
    msg = HIR"$N��һ�ƣ�"NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
    msg = HIR"$N���һ�ƣ�"NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->add("neili",-150);
        me->add_temp("apply/attack", -extra*2);    
        me->add_temp("apply/damage", -extra*3);

    }


    msg = HIY "\n$N��Ȼ������һ������ �� ������˫����糵������������һ�����������ƿ�쭶������Ʋ��ɵ���\n"NOR;

	if( weapon = target->query_temp("weapon") ){
        if( random(me->query("str")) > (int)target->query("str")/2 ) {  
    msg += HIM"\n$pֻ���û���һ�ȣ����ƻ��ھ�ʹ������"
                + target->query_temp("weapon")->query("name") + "���ֶ�����\n" NOR;
		message_vision(msg, me, target);
		(target->query_temp("weapon"))->move(environment(target));
		target->start_busy(3);
	} else {
    msg += HIY"\n$pΣ����ͻȻ���ط����������ܹ���������һ�������ŵ���ɫ�԰ף�\n" NOR;
		message_vision(msg, me, target);
	}
	me->start_busy(1);
        }
        else
        {
        if (random(me->query_skill("force")) > target->query_skill("force")/3 
        ||          random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 )
	{
		me->start_busy(3);
		target->start_busy(random(3));
		
		damage = (int)me->query_skill("guiyuan-tunafa", 1);
		
                damage = damage*5 + random(damage);
		
		target->receive_damage("qi", damage);
		target->receive_wound("qi", damage);
		
		if( damage < 300 ) msg += HIY"\n���$n��ɫһ�±�òҰף��������������˺ü�����\n"NOR;
        	else if( damage < 400 ) msg += HIY"\n������صػ��У�$n���ۡ���һ���³�һ����Ѫ��\n"NOR;
        	else if( damage < 500 ) msg += RED"\n������䡹��һ����$nȫ����Ѫ������������Ѫ���������\n"NOR;
        	else msg += HIR"\n���ֻ���������������죬$nһ���ҽУ���̲�����������ȥ����\n"NOR;
		
	} else 
	{
		me->start_busy(2);
    msg += HIY"\n$pΣ����ͻȻ���ط����������ܹ���������һ�������ŵ���ɫ�԰ף�\n" NOR;
	}
	message_vision(msg, me, target);

        }
        me->add("neili", -400);
	return 1;
}
