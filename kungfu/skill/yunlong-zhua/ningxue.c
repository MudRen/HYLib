// tianlei.c ����--��Ѫ��ץ

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

int perform(object me, object target)
{
	int damage;
        string msg;
        object weapon;
int extra;
	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("��Ѫ��ץֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( objectp(me->query_temp("weapon")) )
		return notify_fail("�������ֲ���ʹ����Ѫ��ץ��\n");

        if( (int)me->query_skill("yunlong-zhua", 1) < 199 )
		return notify_fail("�����Ѫ��ץ��δ���ɣ�����ʹ�ã�\n");

        if (me->query_skill("yunlong-shengong", 1)<70)
                return notify_fail("��ı����ڹ����δ������\n");

        if( (int)me->query("neili", 1) < 600 )
		return notify_fail("�������������㣬����ʹ����Ѫ��ץ��\n");	

	if( (int)me->query_skill("yunlong-zhua", 1) < 119 )
		return notify_fail("�������ץ������죬����ʹ����Ѫ��ץ��\n");

    msg = RED "\n$N��ȫ��ľ���ע��˫��,�߸�Ծ��**��Ѫ��ץ**��һץץ�����Ʋ��ɵ���\n"NOR;
		message_vision(msg, me, target);

    if( (int)me->query_skill("yunlong-shengong", 1) > 200 )
    {
	extra = me->query_skill("yunlong-zhua",1) / 15;
	extra += me->query_skill("yunlong-zhua",1) /15;
	me->add_temp("apply/attack", 80);	
	me->add_temp("apply/damage", extra);
    msg = HIC"��һצ��"NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
    msg = HIG"��һצ��"NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
    msg = HIY"��һצ��"NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
    msg = HIR"��һצ!"NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
target->apply_condition("zhua_poison",10);
	me->add_temp("apply/attack", -80);	
	me->add_temp("apply/damage", -extra);

}
	if( weapon = target->query_temp("weapon") ){
        if( random(me->query("str")) > (int)target->query("str")*3/4 ) {  
    msg += HIM"\n$pֻ���û���һ�ȣ����ƻ��ھ�ʹ������"
                + target->query_temp("weapon")->query("name") + "���ֶ�����\n" NOR;
		message_vision(msg, me, target);
		(
		target->query_temp("weapon"))->move(environment(target));
		target->start_busy(2);
	} else {
    msg += HIY"\n$pΣ����ͻȻ���ط����������ܹ���������һ�������ŵ���ɫ�԰ף�\n" NOR;
		message_vision(msg, me, target);
	}
	me->start_busy(1);
        }
        else
        {
        if (random(me->query_skill("force")) > target->query_skill("force")/2 
        || random(me->query("combat_exp")) > target->query("combat_exp")/2 )
	{
		me->start_busy(3);
		target->start_busy(random(4));
		
		damage = (int)me->query_skill("yunlong-shengong", 1);
		
		damage = damage*4 + random(damage);
		
		target->receive_damage("qi", damage);
		target->receive_wound("qi", damage);
		
		if( damage < 300 ) msg += HIY"\n���$n��ɫһ�±�òҰף��������������˺ü�����\n"NOR;
        	else if( damage < 400 ) msg += HIY"\n������صػ��У�$n���ۡ���һ���³�һ����Ѫ��\n"NOR;
        	else if( damage < 500 ) msg += RED"\n������䡹��һ����$nȫ����Ѫ������������Ѫ���������\n"NOR;
        	else msg += HIR"\n���ֻ���������������죬$nһ���ҽУ���̲�����������ȥ����\n"NOR;
		
	} else 
	{
		me->start_busy(1);
    msg += HIY"\n$pΣ����ͻȻ���ط����������ܹ���������һ�������ŵ���ɫ�԰ף�\n" NOR;
	}
	message_vision(msg, me, target);

        }
        me->add("neili", -300);
	return 1;
}
