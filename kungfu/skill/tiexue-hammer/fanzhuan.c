#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	object weapon;
	extra = me->query_skill("tiexue-hammer",1);
        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "hammer")
                return notify_fail("���õ��������ԣ�\n");
	if ( extra < 50) return notify_fail("�����ѩ�������������죡\n");
    if( (int)me->query_skill("guiyuan-tunafa", 1) < 50 )
	return notify_fail("��ı����ڹ���δ���ɣ�����ʹ�ã�\n");

    if( (int)me->query("neili", 1) < 400 )
	return notify_fail("���������δ���ɣ�����ʹ�ã�\n");


	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("�۷�ת���ǣ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	weapon = me->query_temp("weapon");
if (random(2)==0) target->start_busy(3);
        me->add_temp("apply/attack", extra/2);    
        me->add_temp("apply/damage", extra*2);
	msg = HIY  "$Nʹ����ѩ�����еģ۷�ת���ǣݣ���������ˣ���ط�����һ����" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIY  "$N����һ�У���һ����������һ������" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIY  "$N��Ȼ������ͷ������һ������һ����" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->add_temp("apply/attack", -extra/2);    
        me->add_temp("apply/damage", -extra*2);

me->add("neili",-200);
	me->start_busy(2);
	return 1;
}
