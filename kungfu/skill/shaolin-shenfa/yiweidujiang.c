
#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("[һΤ�ɽ�]ֻ����ս����ʹ�á�\n");

        if((int)me->query_skill("shaolin-shenfa",1) < 90)
                return notify_fail("�������������������\n" NOR);

        if((int)me->query("neili") < 400)
                return notify_fail(HIY "�������������㡣\n" HIY);

        if( target->is_busy() )
                return notify_fail(target->name() + "Ŀǰ�Ѿ���æ�ˣ�\n");

	msg = CYN"$Nʩչ�����Ṧ�ľ�ѧ[һΤ�ɽ�]�������ë����Ⱦ��������ɶ����ף�\n" NOR;
        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 ) {
                msg += NOR "���$p��$P�Ƶò�֪���룡\n" NOR;
                target->start_busy(4);
                me->add("neili", -100);
                       } else {
                msg +=  "���$P�Լ����˸�ͷ���ۻ���\n";
                me->add("neili", -100);
                me->start_busy(3);
        }
        message_combatd(msg, me, target);

        return 1;
}
