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
                return notify_fail("�ٲ������������־�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "sword")
                        return notify_fail("��ʹ�õ��������ԡ�\n");

        if( target->is_busy() )
                return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɢ�\n");
                
        if( (int)me->query_skill("xuantie-jianfa", 1) < 40 )
                return notify_fail("����ٲ�����������죬����ʹ�á������־���\n");

	if( (int)me->query("neili") < 100  ) 
		return notify_fail("�������������\n");

        msg = HIG "$Nʹ���ٲ������������־�����ʱ������ӿ�����಻����������$n�Ĺ��ơ�\n";

        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 ) {
                msg += HIR " ���$p��$P�ָ���æ���ң�����ʧ�룬���ڵ�������֪���Ӧ�ԣ�\n" NOR;
                target->start_busy( (int)me->query_skill("xuantie-jianfa",1) / 50 + 3 );
        } else {
                msg += "����$p������$P����ͼ������㣬ȫ��Ӧ�����硣\n" NOR;
                me->start_busy(2);
        }
        message_combatd(msg, me, target);
	me->add("neili", - 60);
        if(!target->is_fighting(me)) target->fight_ob(me);
        return 1;
}

