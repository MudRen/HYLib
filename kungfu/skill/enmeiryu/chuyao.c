// ning@fengyun

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	object weapon;
	if( !target ) target = offensive_target(me);
        extra = me->query_skill("enmeiryu");
        if ( extra < 50) return notify_fail("���½��Բ����ȭ�����������죡\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail( "ֻ�ܿ���ʩչ��\n");
		if( (int)me->query("neili") < 300 )
		return notify_fail("�������������\n");
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
                return notify_fail("�۵�ħ������ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	weapon = me->query_temp("weapon");
	extra = me->query_skill("enmeiryu") / 30;
if (extra>200) extra=200;
	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", extra);
        msg = HIY "$N�������ƣ�ʹ����������ħ����������������˫������ǵ���$n���������ȥ��" NOR;
	message_vision(msg,me,target);
        msg = HIY  "��Ȥ������" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIY  "�������ޣ�" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIY  "����Ѫ����" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIY  "������ħ��" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -extra);
        me->add("neili",-100);
        me->start_busy(2);
	return 1;
}
