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
        extra = me->query_skill("liumang-quan",1);
	if ( extra < 100) return notify_fail("�����å��ȭ���������죡\n");
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("�����գ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
    if( (int)me->query("neili", 1) < 600 )
		return notify_fail("�������������㣬����ʹ�ã�\n");	
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("����书ֻ�ܿ���ʹ�á�\n");		
extra=extra/3;
if (extra> 200) extra=200;
	me->add_temp("apply/attack",extra);
	me->add_temp("apply/damage",extra*2);
	weapon = me->query_temp("weapon");
	if (random(3)==0) target->start_busy(3);
	msg = HIR  "$N���췢��һ����Ц��ʹ��������ȭ�еģ����գݣ�\n" NOR;
	msg += HIR   "���Ʋ����ޱȵ�Ϧ������ʱ�������Ϊ֮��ɫ��\n" NOR;
	          message_vision(msg,me,target);
        msg = HIC "\n   �� \n" NOR;
	  COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIY "\n            ��\n" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIW "\n                    ��\n" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIR "\n                            ��\n" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIB "\n                                    Բ\n" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->add_temp("apply/attack",-extra);
	  me->add_temp("apply/damage",-extra*2);
	  me->start_busy(2);

	return 1;
}
