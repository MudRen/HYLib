// jinshe-jianfa perform
//by snowman

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;
        int j, z;
        object weapon;
        j = me->query_skill("xuantie-jianfa", 1);
        z = me->query_skill("xuantie-jianfa", 1);
 
        weapon = me->query_temp("weapon");

        if( !target ) target = offensive_target(me);

        if( !target || !me->is_fighting(target) )
                return notify_fail("��Ѹ�ס�ֻ����ս���жԶ���ʹ�á�\n");

        if (!weapon || weapon->query("skill_type") != "sword"
        || me->query_skill_mapped("sword") != "xuantie-jianfa")
                return notify_fail("�������ʹ�ý�ʱ����ʹ����Ѹ�ס���\n");

        if(me->query_skill("xuantie-jianfa", 1) < 200 )
                return notify_fail("�������������������죬ʹ������Ѹ�ס���\n");

//        if(me->query_skill("yunu-xinjing", 1) < 160 )
//                return notify_fail("�����Ů�ľ���Ϊ������ʹ������Ѹ�ס���\n");

        if( (int)me->query_skill("force") < 200 )
                return notify_fail("����ڹ��ȼ�������ʹ������Ѹ�ס���\n");

        if( (int)me->query_str() < 32)
                return notify_fail("���������������ʹ������Ѹ�ס���\n");

        if( (int)me->query_dex() < 30)
                return notify_fail("�������������ʹ������Ѹ�ס���\n");                                                                               

        if( (int)me->query("max_neili") < 1800 )
                return notify_fail("����������̫����ʹ������Ѹ�ס���\n");      

        if( (int)me->query("neili") < 200 )
                return notify_fail("����������̫����ʹ������Ѹ�ס���\n"); 
                if( (int)me->query("jingli") < 700 )
                return notify_fail("����������̫����ʹ������Ѹ�ס���\n"); 
        me->add_temp("apply/attack", j/3); 
        me->add_temp("apply/strength", z/3);
 
        msg = BLU"\n$N�����е�"+weapon->name()+"������$nһѹ����Ȼ����һ���� һ����Ϊ�彣�����籼�׳��繥��$n��\n\n"NOR;
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
 

              me->add("neili",-200);

         me->add_temp("apply/strength", -z/3);
        me->add_temp("apply/attack", -j/3);

        me->start_busy(2);
//        target->start_busy(1);
        return 1;
}
