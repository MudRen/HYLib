// muyeyingyang.c ��Ұӥ��

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;
        int extra;
        int i;
        object weapon;

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("��Ұӥ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if((int)me->query_str() < 30)
                return notify_fail("���������,����ʹ����Ұӥ�\n");

        if((int)me->query_skill("sougu",1) < 150)
                return notify_fail("����ѹ�ӥצ����Ϊ����,Ŀǰ������ʹ����Ұӥ�\n");

        if((int)me->query("neili") < 800)
                return notify_fail("���������ڲ���, ����ʹ����Ұӥ�\n");

        if( target->is_busy() )
                return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɣ�\n");

        msg = HIY "$Nʹ���ѹ�ӥצ����������Ұӥ���˫צ���ץ��$n��ȫ��ҪѨ��\n";
        message_vision(msg, me, target);

if ((int)me->query_skill("jiuyang-shengong",1) > 50)
{

        extra = me->query_skill("jiuyang-shengong",1) / 10;
        me->add_temp("apply/attack", extra);    
        me->add_temp("apply/damage", extra);
        msg =  HIW "��һצ\n" NOR;
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        msg =  HIW "�ڶ�צ\n" NOR;
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        msg =  HIW "����צ\n" NOR;
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        me->add_temp("apply/attack", -extra);    
        me->add_temp("apply/damage", -extra);

}
        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 ) {
                msg = "���$p��$P����ҪѨ����ʱ�������ã�\n" NOR;
                target->start_busy( (int)me->query_skill("sougu",1) / 50 + 3);
                me->start_busy(2);
                me->add("neili", -150);
        } else {
                msg = HIG "����$p������$P����ͼ����û���ϵ���\n" NOR;
                me->start_busy(2);
        }
        message_combatd(msg, me, target);

        return 1;
}

