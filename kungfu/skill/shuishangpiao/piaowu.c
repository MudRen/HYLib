// lingbo.c  ����Ư��

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("��һ��������ô��\n");


        if((int)me->query_skill("guiyuan-tunafa",1) < 100)
                return notify_fail(HIY "��Ĺ�Ԫ���ɷ���Ϊ������\n" NOR);

         if((int)me->query_skill("shuishangpiao",1) < 100)
                return notify_fail(HIY "���ˮ��Ư����������\n" NOR);

        if((int)me->query("neili") < 400)
                return notify_fail(HIY "�������������㡣\n" HIY);

        if( target->is_busy() )
                return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɣ�\n");

        if( me->query("gender") == "����")
               {msg = HIG
"$Nһ�С���Ҷ��硹��������һƬ��Ҷһ��Ʈ�˳�ȥ������֮������Ѹ�ٵ��˼�����\n" NOR;}
        else   {msg = HIC 
"$Nһ�С���Ҷ��硹��������һƬ��Ҷһ��Ʈ�˳�ȥ����Ů�·���\n" NOR;}

        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/3 ) {
                msg += HIW "���$p��$P�Ķ����ŵ�Ŀ�ɿڴ���\n" NOR;
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
