// san.c һ����ɢ
/*
�����ʲ�������һ�ƣ�ʵ�Ǳ�
������֮���ۣ�������һ����ɢ������ν����ɢ������ָ����ʯ�ϣ�ʯм�ġ�ɢ����
������������ǡ�ɢ������·�Ʒ���ֻ��ôһ�У�ֻ������̫���ۻ룬�ٵ�ʱ��
����ʹ�ڶ��У����˱��ѱ���������һ���������ɽ�����������Ϊ������Ҫ���
�л�ʽ���������֮���ܡ�
*/

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

void remove_effect(object me, int amount);

int perform(object me, object target)
{
        int org_jiali, jiali;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("һ����ɢֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( me->query_temp("weapon") )
                return notify_fail("��ֻ���ڿ���ʱʹ��һ����ɢ��\n");

        if( me->query_skill_mapped("force") != "hunyuan-yiqi" )
                return notify_fail("�����õĲ��ǻ�Ԫһ�������޷�ʩչһ����ɢ��\n");

        if( me->query_skill("hunyuan-yiqi", 1) < 180)
                return notify_fail("��Ļ�Ԫһ�������δ�����޷�ʩչһ����ɢ��\n");

        if( me->query_skill("banruo-zhang", 1) < 200 )
                return notify_fail("��İ����ƻ��δ�����޷�ʩչһ����ɢ��\n");


        if( me->query("max_neili") <= 1000 )
                return notify_fail("���������Ϊ���㣬���������˷����޷�ʩչһ����ɢ��\n");

        if( (int)me->query("neili") < 1000  ) 
                return notify_fail("�������������\n");

        if( (int)me->query("jing") < 100  )
                return notify_fail("��ľ���������\n");
        
        org_jiali = me->query("jiali");

        // I tried the original code with no restriction, a 4Kneili player
        // can make 15K damage in this 1 hit.  With the limit, a 4K
        // neili player can still make 4K damage sometimes. -Chu

        jiali = me->query("neili")/5;  
        if (jiali > 600) jiali = 600;
        jiali = jiali/2 + random(jiali/3);

        me->add_temp("attack",100);
        me->add_temp("damage",200);
        me->set("jiali", jiali);
        me->set("neili", me->query("neili")/3);

        message_vision(
        HIW "\n$N˫�ֺ�ʮ���������ӷ���������˫����������ת�˸�ԲȦ��������$n���˹�������\n"
        +"$N����δ����$n�Ѹ��ؿں������������֮�䣬$N��������ŭ������ӿ����������\n" NOR, me,target);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        me->add_temp("attack",-100);
        me->add_temp("damage",-200);
        me->set("jing", me->query("jing")/5);
        me->set("neili", me->query("neili")/3);
        me->set("jiali", org_jiali);
        me->start_busy(1+random(3));
//        target->kill_ob(me);
        return 1;
}
