
#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("[����»�]ֻ����ս����ʹ�á�\n");

        if((int)me->query_skill("piaoyibu",1) < 60)
                return notify_fail("���Ʈ�ݲ�������������\n" NOR);

        if((int)me->query("neili") < 400)
                return notify_fail(HIY "�������������㡣\n" HIY);

        if( target->is_busy() )
                return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɣ�\n");

	msg = BLU"$N�ſ����Σ���̤��ȣ�������������統��֮ʽһ���ǳɣ�\n" NOR;
        if( me->query("combat_exp") > random((int)target->query("combat_exp")) ) {
                msg += NOR "���$p��$P�Ƶò�֪���룡\n" NOR;
                target->start_busy(4);
                me->add("neili", -100);
                       } else {
                msg +=  "���$P�Լ����˸�ͷ���ۻ���\n";
                me->add("neili", -100);
                me->start_busy(2);
        }
        message_combatd(msg, me, target);

        return 1;
}
