// chan.c ̫�������������־�

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        object weapon;
        string msg;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("��ɽ��塸����ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "staff")
            return notify_fail("��ʹ�õ��������ԡ�\n");

	if( (int)me->query("neili") < 200 )
		return notify_fail("�������������\n");

        if( target->is_busy() )
                return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɢ�\n");
                
        if( (int)me->query_skill("tianshan-zhang", 1) < 40 )
                return notify_fail("�����ɽ�ȷ�������죬����ʹ�á�������\n");

        msg = HIY "$Nʹ����ɽ�ȷ���������ƴ�����趯���е���������������ס,��ͼ����$n�Ĺ��ơ�\n";
        me->add("neili",-50);
        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 ) {
                msg += HIG " ���$p��$P�ָ���æ���ң�����ʧ�룬���ڵ�������֪���Ӧ�ԣ�\n" NOR;
        target->apply_condition("xx_poison",20);
	 target->apply_condition("x2_sandu",20);
	 target->apply_condition("sanpoison",20);
target->apply_condition("corpse_poison",60);
                target->start_busy( (int)me->query_skill("tianshan-zhang",1) / 50 + 2 );
        } else {
                msg += HIR"����$p������$P����ͼ������㣬ȫ��Ӧ�����硣\n" NOR;
                me->start_busy(2);
        }
        message_combatd(msg, me, target);

        if(!target->is_fighting(me)) target->fight_ob(me);
        return 1;
}

