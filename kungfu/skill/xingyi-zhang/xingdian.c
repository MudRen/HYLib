// canyun // bren

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        string msg;

int i; 
i = me->query_skill("xingyi-zhang", 1)/5;        if( !target ) target = offensive_target(me);

        if( !target || !me->is_fighting(target) )
                return notify_fail("���ǹ��㡹ֻ����ս���жԶ���ʹ�á�\n");

        if( objectp(me->query_temp("weapon")) )
                return notify_fail("ʹ�á��ǹ��㡹ʱ˫�ֱ�����ţ�\n");

        if( (int)me->query_skill("xingyi-zhang", 1) < 120 )
                return notify_fail("��������Ʋ�����죬����ʹ�á��ǹ��㡹��\n");

        if( (int)me->query_skill("shenyuan-gong", 1) < 120 )
                return notify_fail("�����Ԫ���ȼ�����������ʹ�á��ǹ��㡹��\n");

        if( (int)me->query_dex() < 25 )
                return notify_fail("���������ǿ������ʹ�á��ǹ��㡹��\n");

        if (me->query_skill_prepared("strike") != "xingyi-zhang"
        || me->query_skill_mapped("strike") != "xingyi-zhang")
                return notify_fail("�������޷�ʹ�á��ǹ��㡹���й�����\n");                                                                                
      

        if( (int)me->query("neili") < 700 )
                return notify_fail("����������̫��������ʹ�á��ǹ��㡹��\n"); me->add("neili", -300);
        me->add("jingli", -40);
        message_vision(HIW "\n$N˫�ƽ����Ӧ,�������Ӱ�������ǰ���$n��Χ��˸������\n" NOR,me, target);
if (random(3)==0) target->start_busy(3);
        me->add_temp("apply/strength", i);
        me->add_temp("apply/attack", i);
        me->add_temp("apply/damage", i); 
COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_QUICK);       
COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_QUICK);
 COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_QUICK); 
       me->add_temp("apply/damage", -i); 
        me->add_temp("apply/strength", -i);
        me->add_temp("apply/attack", -i);

if( random((int)me->query("combat_exp")) > (int)target->query("combat_exp")/3) 
{       me->add_temp("apply/strength", i);
        me->add_temp("apply/attack", i);
        me->add_temp("apply/damage", 800); 
msg =  HIW"$N����Ԫ�񹦷��ӵ����ޣ�һ˫���Ʒ���ҫ�۵Ĺ�â���û���������Ӱ��" NOR; 
COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_QUICK,msg); 
COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_QUICK,msg); 
COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_QUICK,msg); 
        me->add_temp("apply/strength", -i);
        me->add_temp("apply/attack", -i);
        me->add_temp("apply/damage", -800);       
} 
        me->add("neili", -400); 
        me->start_busy(2);
                return 1;}