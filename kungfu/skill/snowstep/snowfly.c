// lingbo.c  lingxiao

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("ֻ���ڴ��в���ʹ��!\n");



        if((int)me->query_skill("bingxue-xinfa",1) < 100)
                return notify_fail(HIY "��ı�ѩ�ķ���Ϊ������\n" NOR);

         if((int)me->query_skill("snowstep",1) < 100)
                return notify_fail(HIY "���÷ѩƮ�㲻��������\n" NOR);

        if((int)me->query("neili") < 400)
                return notify_fail(HIY "�������������㡣\n" HIY);

        if( target->is_busy() )
                return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɣ�\n");

        if( me->query("gender") == "����")
               {msg = HIW
"$N������������Ʈ������˷�����$N��Ӱ��,����ʵʵ,��֪�ĸ�������ġ�\n" NOR;}
        else   {msg = HIY 
"$N������������Ʈ������˷�����$N��Ӱ��,����ʵʵ,��֪�ĸ�������ġ�\n" NOR;}

        if( (random(me->query("combat_exp"))+(int)me->query_skill("snowstep",1)*800) > (int)target->query("combat_exp")/2 ) {
                msg += HIR "���$p��$P�Ķ����ŵ�Ŀ�ɿڴ���\n" NOR;
target->start_busy( (int)me->query_skill("snowstep",1) / 50+2);
//                target->start_busy(6);
                me->add("neili", -100);
                       } else {
                msg +=  "$pֻ����ǿ�����˿�ȥ��\n";
                me->add("neili", -100);
                me->start_busy(2);
        }
        message_combatd(msg, me, target);

        return 1;
}
