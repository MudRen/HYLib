// sanjue ��������צ

#include <ansi.h>
#include <combat.h> 
inherit F_SSERVER;

int perform(object me, object target)
{
        int exp, str, dex, skill, i;
        exp = (int)me->query("combat_exp");
        str = (int)me->query("str");
        dex = (int)me->query("dex");
        skill = (int)me->query_skill("jiuyin-baiguzhua", 1);
        if( !target ) target = offensive_target(me);

        if( !target || !me->is_fighting(target) )
                return notify_fail("����������צ��ֻ����ս����ʹ�á�\n");
        if( me->query_temp("weapon"))
                return notify_fail("������������ô��ʹ�á���������צ����\n");   
        if( skill < 150 )
                return notify_fail("��ľ����׹�צ��������죬ʹ��������������צ��������\n");
        if ( skill < 200 ) i = 3;
        if ( skill < 300 ) i = 3;
        else i = 3;
        if ( me->query_skill_mapped("claw") != "jiuyin-baiguzhua" )
               return notify_fail("�������޷�ʹ�á���������צ����\n");
        if( (int)me->query("max_neili") < 500 )
                return notify_fail("����������̫����ʹ��������������צ����\n");      
        if( (int)me->query("neili") < 1100 )
                return notify_fail("����������̫����ʹ��������������צ����\n");
        me->start_perform(2, "��������צ");
        message_vision(RED"\n$NͻȻ�ֽ�һ����ȫ������籬������ž���죬�ֱ�ͻȻ�������ߣ�\n"NOR,me);
        me->add_temp("apply/strength",str/i);
        me->add_temp("apply/dexerity",dex/i);
        me->add("neili", -600);
        me->add_temp("apply/attack", skill/i);
        me->add_temp("apply/damage", skill/i);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
        me->add_temp("apply/damage", -skill/i);
        me->add_temp("apply/attack", -skill/i);
        me->add_temp("apply/strength",-str/i);
        me->add_temp("apply/dexerity",-dex/i);
        me->start_busy( 2 + random(i));
if (userp(target)) me->start_busy(4);
        return 1;
}
