
#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("[�ɾ���]ֻ����ս����ʹ�á�\n");

        if((int)me->query_skill("chanchu-bufa",1) < 60)
                return notify_fail("�����ܲ�������������\n" NOR);

        if((int)me->query("neili") < 400)
                return notify_fail(HIY "�������������㡣\n" HIY);

        if( target->is_busy() )
                return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɣ�\n");

	msg = HIM"$Nһ�С��ɾ��졹���������ϱ�ֱ���������࣬����$n��ͣ�ļ�ת��\n" NOR;
        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 ) {
                msg += HIR"���$p��$P�Ƶò�֪���룡\n" NOR;
                target->start_busy( (int)me->query_skill("chanchu-bufa",1) / 50 + 2 );
                me->add("neili", -60);
                       } else {
                msg +=  HIC"���$P�Լ����˸�ͷ���ۻ���\n"NOR;
                me->add("neili", -60);
                me->start_busy(1);
        }
        message_combatd(msg, me, target);

        return 1;
}
