// lingbo.c  ����

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("ֻ���ڴ��в���ʹ��!\n");


        if((int)me->query_skill("shenlong-xinfa",1) < 100)
                return notify_fail(HIY "��������ķ���Ϊ������\n" NOR);

         if((int)me->query_skill("yixingbu",1) < 100)
                return notify_fail(HIY "������β�������������\n" NOR);

        if((int)me->query("neili") < 400)
                return notify_fail(HIY "�������������㡣\n" HIY);

        if( target->is_busy() )
                return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɣ�\n");

        if( me->query("gender") == "����")
               {msg = HIY
"$Nģ�����ߵĶ���������Ʈ���������������������ĵĿ���������\n" NOR;}
        else   {msg = HIY 
"$Nģ�����ߵĶ���������Ʈ���������������������ĵĿ���������\n" NOR;}

        if( random(me->query("combat_exp"))+(me->query("combat_exp")/4) > (int)target->query("combat_exp")/2 ) {
                msg += HIR "���$p��$P�Ķ����ŵ�Ŀ�ɿڴ���\n" NOR;
                target->start_busy(6);
                me->add("neili", -50);
                       } else {
                msg +=  "$pֻ����ǿ�����˿�ȥ��\n";
                me->add("neili", -50);
                me->start_busy(2);
        }
        message_combatd(msg, me, target);

        return 1;
}
