// zhong.c ��������

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        object obj;
	string msg;
	 int extra;
        extra = me->query_skill("liuyang-zhang",1);
	if( !target ) target = offensive_target(me);

        if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
                return notify_fail("��������������ֻ����ս����ʹ�á�\n");

	if( environment(me)->query("no_fight") )
		return notify_fail("���ﲻ׼��ܡ�\n");

	if( !target || !target->is_character() )
		return notify_fail("����������ֻ�����ڶ������ϡ�\n");

	if(((int)me->query_skill("bahuang-gong", 1) < 200 ) &&
	   ((int)me->query_skill("beiming-shengong", 1) < 200 ))
		return notify_fail("��ı����ڹ�������죬����������������\n");

	if (me->query("neili")<200)
		return notify_fail("���������㡣\n");

	if( (int)me->query_skill("liuyang-zhang", 1) < 200 )
		return notify_fail("�����ɽ�����Ʋ�����죬����������������\n");


        me->add_temp("apply/strength", extra/4);
        me->add_temp("apply/attack", 80);
	me->add_temp("apply/damage", 380);
	msg = BLU "$N��ˮΪ�����������У�˫ָһ�������ϼ�����⼱������$n��\n";
COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg =  HIW  "$N��ָһ����"HIG"��һ��������"HIW"��$n��ߴ�����" NOR;
	        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIB  "$N��ָһ����"HIG"�ڶ���������"HIB"��$n�ұߴ���! " NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = CYN  "$N���Ծ��,"HIG"������������"CYN"��$n�������!" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

        me->add_temp("apply/strength", -extra/4);
        me->add_temp("apply/damage", -380);
        me->add_temp("apply/attack", -80);

	me->start_busy(2);
	
 if (random(me->query("combat_exp")) > target->query("combat_exp") / 3)
 {
		msg = HIG " ���$p��$P���˸����ţ��������˼���������\n" NOR;
		target->receive_damage("qi",(int)me->query_skill("bahuang-gong",1));
		target->receive_wound("qi",155 + random( (int)me->query_skill("liuyang-zhang",1)));
		target->receive_wound("jing", 10 + random(50));
		target->apply_condition("ss_poison", random(me->query_skill("liuyang-zhang",1)/50) + 30 +
		target->query_condition("ss_poison"));
		me->start_busy(2);
		message_combatd(msg, me, target);
		COMBAT_D->report_status(target);
	} else {
		msg += "����$p��æ����һ�ԣ����˿�ȥ��\n" NOR;
		me->start_busy(2);
		message_combatd(msg, me, target);
	}
        me->add("neili",-200);
// if target is not busy, then busy him (by xbd)
	if (!target->is_busy()) target->start_busy(2);
//	if( !target->is_killing(me) ) target->kill_ob(me);
//	if(!target->is_fighting(me)) target->kill_ob(me);

	return 1;
}
