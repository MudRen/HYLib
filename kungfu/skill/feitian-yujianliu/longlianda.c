// ����������.������.��,�� �
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	object weapon, ob;
        string msg, string1;
        int extra;
        int count;
  if( !target ) target = offensive_target(me);

	if( !me->is_fighting() )
		return notify_fail("������������.������ֻ����ս����ʹ�á�\n");
 	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("��������ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "blade")
		return notify_fail("�������򡹿�ʼʱ��������һ�ѽ���\n");
    if ((int)me->query_skill("shayi-xinfa", 1) < 50)
   return notify_fail("���ɱ���ķ���򲻹���\n");

	if( (int)me->query("neili") < 100 )
		return notify_fail("�������������\n");


	if((int)me->query_skill("feitian-yujianliu",1) < 90)
		return notify_fail("��ķ�������������Ϊ����, ����ʹ����һ���� !\n");
	if((int)me->query_skill("blade") < 90)
		return notify_fail("��ĵ�����Ϊ������ Ŀǰ����ʹ��! \n");

	if( (int)me->query("neili") < 400  ) 
		return notify_fail("�������������\n");
	extra = me->query_skill("feitian-yujianliu",1) / 10;
	extra += me->query_skill("feitian-yujianliu",1) /10;
	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", extra);

	msg = HIR "$N�����Ϸ�������׵����,Ȼ�����·���������������" NOR;
        message_combatd(msg, me, target);
	 msg =  YEL  "�� ��׵��! ���� " NOR;	
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	 msg =  YEL  "�� ������! ���� " NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	 msg =  HIY  "�� ����������! ���� " NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	 msg =  HIY  "�� ����������! ���� " NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg =  HIY  "�� ������.�! ���� " NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -extra);
	me->add("neili", -200);
	me->start_busy(2);
	return 1;
}
