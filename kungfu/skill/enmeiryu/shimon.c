 // mimicat@fy4
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra;
        object weapon;
        if( !target ) target = offensive_target(me); 
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("������-��ȸ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail( "ֻ�ܿ���ʩչ��\n");
                
        if( (int)me->query("neili") < 300 )
		return notify_fail("�������������\n");

        if((int)me->query("qi")*100/(int)me->query("max_qi") > 30
                && (int)me->query("eff_qi")*100/(int)me->query("max_qi") > 30
               )
                return notify_fail("������ʹ���е�ʱ��\n");
        extra = me->query_skill("enmeiryu",1) ;
        if(extra <= 200 ) return notify_fail("���½��Բ����ȭ�����������������ܳ�����-��ȸ��\n");
        msg = HIR "$N������˵������ֻ����һ���ˡ�����������$Nʹ��������һ�С�����.��ȸ��!
$nһʱ��Ϊ�Լ��ۻ�����Ȼ�����ĸ�$N����Ӱ!
$n����һ��$N�͵س���$n����ϥ����ס$n���������־�ס$n
��ͷ������������ȥ��ͬʱ�ⲿ����$n��ü�ġ�" NOR;
        weapon = me->query_temp("weapon");
        extra=extra-150;
if (extra>200) extra=200;        
        me->add_temp("apply/damage",extra*10);
        me->add_temp("apply/attack",extra*4);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->add_temp("apply/damage",-extra*10);
        me->add_temp("apply/attack",-extra*4);
if (random(me->query("combat_exp",1)) >= target->query("combat_exp",1)/2)

{
	if (userp(target)) target->unconcious();
else target->start_busy(10);

message_vision(HIR"$NͻȻ�����ؿ�һ���ʹ��������ǰһ�ڡ� \n"NOR,target);
me->start_busy(3);
}
else
{
me->start_busy(10);	
}	
                
me->add("neili",-300);
        return 1;
}  
