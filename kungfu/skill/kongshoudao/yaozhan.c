// tie@fengyun

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
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("����ն��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if ( me->query_temp("weapon"))
                        return notify_fail("��ʹ�õ��������ԡ�\n");
	if( (int)me->query("neili") < 500  ) 
		return notify_fail("�������������\n");
        me->add("neili",-100);

	extra = me->query_skill("unarmed",1);
	if(extra <= 80 ) return notify_fail("��ģۿ��ֵ��ݲ���������\n");
	msg = HIR "$NͻȻ�Ƶ�$n�����ϥ��Ȼ�϶���˫��ͬʱץ��$n����ͼ��$n�ĺ����Ķϣ�" NOR;
        weapon = me->query_temp("weapon");
	me->add_temp("apply/damage",extra*2);
	me->add_temp("apply/attack",extra);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	me->add_temp("apply/damage",-extra*2);
        me->add_temp("apply/attack",-extra);
	me->start_busy(1);
	return 1;
}
