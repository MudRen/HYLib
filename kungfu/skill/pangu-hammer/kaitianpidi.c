// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	object weapon;
	if(me->is_busy())
		return notify_fail("������û�գ���\n");
	extra = me->query("neili")/10 ;
	if ( extra < 30) return notify_fail("�������̫���������ò����ۿ���ٵأ�����У�\n");
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("�ۿ���ٵأ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "hammer")
                        return notify_fail("��ʹ�õ��������ԡ�\n");
	if( (int)me->query("neili") < 500  ) 
		return notify_fail("�������������\n");
        me->add("neili",-200);

	weapon = me->query_temp("weapon");
	me->add_temp("apply/damage", extra);
	msg = HIY  "$N�߸ߵþ������е�"+ weapon->name()+  "��ȫ��֮��������$n��Ȼ���£�" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	me->add_temp("apply/damage", -extra);
	me->start_busy(2);
	return 1;
}
