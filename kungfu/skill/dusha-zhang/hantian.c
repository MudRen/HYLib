// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	object weapon;
	int damage;
	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("�۾��غ����ƣ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	weapon = me->query_temp("weapon");
	extra = (int)me->query_skill("dusha-zhang",1) / 10;

    if ( extra < 10) return notify_fail("��������书���������죡\n");
    if( (int)me->query("neili") < 600 )
    return notify_fail("�������������\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail( "ֻ�ܿ���ʩչ��\n");
                
        damage=random(extra)+50;
        extra=extra/2;
        if (extra> 200) extra=200;

        message_vision(
                HIB "\n$N���˵�������ڵĶ����˵����У��͵���$n��ȥ��\n" NOR, me, target);
        
        if( random(target->query("combat_exp")) < (int)me->query("combat_exp") / 2 ) {
        target->receive_wound("jing", damage);
                target->start_busy(5);
        message_vision("$N��$n�Ķ������У�������һ��ѣ�Σ���Щ���¡�\n", target, me);
                me->start_busy(3);
                
        }
else
	{
                message_vision("$N���Ʋ�����������ܿ���$n��Ķ�����\n", target, me);
	
	}
	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", extra);
        
	msg = HIR  "$Nʹ���۾��غ����ƣݣ�ȫ�������ת��˫��һǰһ�������Ļ���$n��" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = HIR  "$Nʹ��ǰһ�ƣ������Ļ���$n��" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = HIR  "$N����һ����ʹ����һ�ƣ������Ļ���$n��" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
me->add("neili",-100);
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -extra);
	me->start_busy(2);
	return 1;
}
