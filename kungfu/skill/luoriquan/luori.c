// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	extra = me->query_skill("luoriquan",1);
	if ( extra < 280) return notify_fail("��ģ�������ȭ�ݻ��������죡\n");
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("�����գ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (me->query_temp("weapon"))
                        return notify_fail("��ʹ�õ��������ԡ�\n");
	if( (int)me->query("neili") < 500  ) 
		return notify_fail("�������������\n");
        me->add("neili",-300);

	me->add_temp("apply/attack",extra/5);
       me->add_temp("apply/damage",extra*2);

	msg = HIR "$N���췢��һ����Ц��ʹ��������ȭ�еģ����գݣ�\n" NOR;
	msg += HIR "���Ʋ����ޱȵ�Ϧ������ʱ�������Ϊ֮��ɫ��\n" NOR;
       message_vision(msg,me,target);
       msg =  HIC  "\n   �� \n" NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       msg = HIY  "\n         ��\n" NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       msg = HIW  "\n                  ��\n" NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       msg = HIR  "\n                           ��\n" NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       msg = HIB "\n                                    Բ\n" NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
  
       me->start_busy(2);
       me->add_temp("apply/attack",-extra/5);
       me->add_temp("apply/damage",-extra*2);

	return 1;
}
