// lingbo.c  �����貨

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("��һ��������ô��\n");

        if( me->query("gender") == "����")
                return notify_fail(HIY "һ��������������������Ҳ���ߣ�\n" NOR);

        if((int)me->query_skill("beiming-shengong",1) < 100)
                return notify_fail(HIY "��ı�ڤ����Ϊ������\n" NOR);

        if((int)me->query_skill("lingboweibu",1) < 100)
                return notify_fail(HIY "����貨΢������������\n" NOR);

        if((int)me->query("neili") < 400)
                return notify_fail(HIY "�������������㡣\n" HIY);

        if( target->is_busy() )
                return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɣ�\n");

        if( me->query("gender") == "����")
               {msg = YEL
"$N������������̬Ʈ��,һ�������貨,��������֮����\n" NOR;}
        else   {msg = YEL 
"$N����������ʩչ�貨΢��������������������Ů�·���\n" NOR;}

        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/3 ) {
                msg += HIW "���$p��$P���貽�ŵ�Ŀ�ɿڴ���\n" NOR;
                target->start_busy(6);
                me->add("neili", -100);
                       } else {
                msg +=  "$pֻ����ǿ�����˿�ȥ��\n";
                me->add("neili", -100);
                me->start_busy(2);
        }
        message_combatd(msg, me, target);

        return 1;
}
