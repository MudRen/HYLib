// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	int orforce;
	object weapon;
	extra = me->query_skill("unarmed",1);
	if( extra < 200) return notify_fail("������ֳ�ȭ���������죡\n");
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("����ԧ��ȭ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        if (me->query_temp("weapon"))
                        return notify_fail("��ʹ�õ��������ԡ�\n");
	if( (int)me->query("neili") < 500  ) 
		return notify_fail("�������������\n");
        me->add("neili",-200);

	me->add_temp("apply/attack",extra/10);
	weapon = me->query_temp("weapon");
	msg = HIY  "$Nʹ�����ֳ�ȭ�еģ���ԧ��ȭ�ݣ�һ��������ʽ��$n������\n" NOR;
	message_vision(msg,me,target);
	msg = HIY  "��һȭ��" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       msg = HIY  "��һȭ��" NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       msg = HIY  "��һȭ��" NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       msg = HIY  "��һȭ��" NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       msg = HIY  "ǰһȭ��" NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       msg = HIY  "��һȭ��" NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       msg = HIY  "�����һȭ����" NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	me->start_busy(4);
       me->add_temp("apply/attack",-extra/10);
	return 1;
}
