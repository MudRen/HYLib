// wumei.c  ��÷����

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
 
int perform(object me, object target)
{
	object weapon, ob;
        string msg, string1;
        int count;
 if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("����÷���ֻ����ս����ʹ�á�\n");
 
	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("����÷���ʩչʱ��������һ�ѽ���\n");

	if( (int)me->query("neili") < 500 )
		return notify_fail("�������������\n");

	if( (int)me->query_skill("sword") < 100 ||
	    me->query_skill_mapped("sword") != "wuzhan-mei")
		return notify_fail("�����չ÷�������ң��޷�ʹ����÷���\n");

	msg = HIY "$Nʹ����չ÷��������÷���������Ȼ�ӿ죡ֻ����Ӱ������÷�꣬��й���¡�" NOR;
	message_vision(msg, me);

	msg = HIB "��÷                                          ��÷"NOR;
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0,msg);
	msg = HIR "              ��÷                ��÷"NOR;
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0,msg);
	msg = HIW+BLINK "		        ��÷"NOR;
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0,msg);
	msg = HIG "              ��÷                ��÷"NOR;
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0,msg);
	msg = HIC "��÷				    	       ��÷"NOR;
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0,msg);

	me->add("neili", -250);
      me->start_busy(2);

	return 1;
}
