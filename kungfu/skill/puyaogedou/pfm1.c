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
        return notify_fail("ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( me->query("up1") < 1 )
                return notify_fail("�����ڲ���ʹ�ô�pfm.\n");
        if( me->query("pfm1") < 1 )
                return notify_fail("�����ڲ���ʹ�ô�pfm.\n");


        if( target->is_busy() )
                return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɢ�\n");
                
        if( (int)me->query_skill("puyaogedou", 1) < 40 )
                return notify_fail("��ĵȼ�������죬����ʹ�á�����\n");
        if( me->query("up1") < 1 )
                return notify_fail("�����ڲ���ʹ�ô�pfm.\n");


        msg = HIG "ֻ��$N��һ�ţ�һ�����ص�Ũ������$n��\n"NOR;

if (me->query("up1")==1)
{
        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 ) {
                msg += HIR "$nһ��ɶҲ��������,ֻ�ò�ȡ��ʽ������������\n" NOR;
            target->start_busy(6);           
target->apply_condition("ill_dongshang",10 );
target->apply_condition("ill_fashao",10 );
target->apply_condition("ill_kesou",10 );
target->apply_condition("ill_shanghan",10 );
target->apply_condition("ill_zhongshu",10 );
            } else {
                msg += HIY"����$p������$P����ͼ������㣬ȫ��Ӧ�����硣\n" NOR;
                me->start_busy(random(2));
        }
        message_combatd(msg, me, target);
}
if (me->query("up1")==2)
{
        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/4 ) {
                msg += HIR "$nһ��ɶҲ��������,ֻ�ò�ȡ��ʽ������������\n" NOR;
target->apply_condition("ill_dongshang",30 );
target->apply_condition("ill_fashao",30 );
target->apply_condition("ill_kesou",30 );
target->apply_condition("ill_shanghan",30 );
target->apply_condition("ill_zhongshu",30 );
            target->start_busy(8);           
            } else {
                msg += HIY"����$p������$P����ͼ������㣬ȫ��Ӧ�����硣\n" NOR;
                me->start_busy(random(2));
        }
        message_combatd(msg, me, target);
}

        if(!target->is_fighting(me)) target->fight_ob(me);
        return 1;
}

