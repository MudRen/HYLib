// ning@fengyun
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	object weapon;
        extra = me->query_skill("six-sword",1);
       if ( extra < 50) return notify_fail("�������׷�꽣�����������죡\n");

        if((int)me->query("neili") < 500 )
                return notify_fail("�������������㣬����ʹ�ã�\n");
                weapon = me->query_temp("weapon");
        if (!weapon || weapon->query("skill_type") != "sword"       )
                return notify_fail("������û�н����޷�ʹ�ã�\n");                
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
                return notify_fail("����������ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	weapon = me->query_temp("weapon");
msg = HIR "$N���ҵض��������е�"+ weapon->name() + HIR"һ����$n����������������������׷�����꡻����������\n\n" NOR;
	message_vision(msg,me,target);
if (extra>200) extra=200;
        me->add_temp("apply/damage",extra);
        me->add_temp("apply/attack",extra);
        msg = ""+ weapon->name()+ "" + HIW"��һ������һ��ֱ����$n��"NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = ""+ weapon->name()+ "" + HIY"����һƬ���ƽ����$n��"NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = ""+ weapon->name()+ "" + HIC"�������ַ�����$n��"NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = ""+ weapon->name()+ "" + HIG"����ʧȥ����һ���ɨ��$n��"NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->add_temp("apply/damage",-extra);
        me->add_temp("apply/attack",-extra);
        me->start_busy(2);
	return 1;
}
