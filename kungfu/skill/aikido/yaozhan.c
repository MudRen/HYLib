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
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("��ն������֡�\n");
if( (int)me->query("max_neili") < 200 )
      return notify_fail("�������������\n");
	if( (int)me->query("neili") < 200  ) 
		return notify_fail("�������������\n");
    if ((int)me->query_skill("shayi-xinfa", 1) < 30)
   return notify_fail("���ɱ���ķ���򲻹���\n");

	extra = me->query_skill("aikido",1)/10;
	if(extra <= 3 ) return notify_fail("��ģۺ������ݲ���������\n");
	msg = HIR "$NͻȻ�Ƶ�$n�����ϥ��Ȼ�϶���˫��ͬʱץ��$n����ͼ��$n�ĺ����Ķϣ�" NOR;
        weapon = me->query_temp("weapon");
	me->add_temp("apply/damage",extra*4);
	me->add_temp("apply/attack",extra*2);
        message_combatd(msg, me, target);
	 msg =  RED  "�� ��ϥ��Ȼ�϶�! ���� " NOR;	
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	 msg =  RED  "�� ˫��ͬʱ����! ���� " NOR;	
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	 msg =  RED  "�� �����Ķ�����! ���� " NOR;	
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	me->add_temp("apply/damage",-extra*4);
        me->add_temp("apply/attack",-extra*2);
        me->add("neili",-100);
	me->start_busy(2);
	return 1;
}
