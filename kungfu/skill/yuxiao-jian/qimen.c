// qimen.c ��������
// Created by Darken@sh.SJ
// Modified by Numa@ln.SJ

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        string msg;
        int i, attack_time, lvl;

        if( !target ) target = offensive_target(me);

        if( !target
        ||  !target->is_character()
        ||  !me->is_fighting(target) )
                return notify_fail("���������ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (!objectp(weapon = me->query_temp("weapon"))
         || (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԡ�\n");

        if((int)me->query_skill("yuxiao-jian",1) < 70 )
                return notify_fail("������｣�����������ʹ���������������\n");


        if((string)me->query_skill_mapped("sword") != "yuxiao-jian" && userp(me))
                  return notify_fail("�������޷�ʹ�á����������\n");

        if((string)me->query_skill_mapped("parry") != "yuxiao-jian" && userp(me))
                  return notify_fail("�������޷�ʹ�á����������\n");

        if( (int)me->query_skill("qimen-wuxing", 1) < 60 )
                return notify_fail("������Ű��Բ�����죬�޷�ʩչ���������\n");
        if ((int)me->query_skill("bibo-shengong", 1) < 60)
                return notify_fail("��ı̲���������򲻹����޷�ʩչ���������\n");

        if((int)me->query_temp("yuxiao_lian") )
               return notify_fail("�������Ѿ��������ʹ�á���������ˡ�\n");

        if((int)me->query("neili", 1) < 500 )
                return notify_fail("�������̫���ˣ��޷�ʹ�������������\n");
                
        if((int)me->query("jing") < 100 )
                return notify_fail("��ľ���̫���ˣ��޷�ʹ�������������\n");

        attack_time = random((int)me->query_skill("yuxiao-jian", 1) / 30)+2;

        if(attack_time < 1)
               attack_time = 1;
        if(attack_time > 4)  attack_time = 4;

        msg = HIG "$N����"+weapon->name()+HIG"���̣��������磬���ж��ǹ��ƣ�һ�в���$n���⿪ȥ�����������������\n"+
                  "$N����һ��������һ�У�����"+chinese_number(attack_time)+"�У�����ѧ������ȫ�෴��\n"+
                  "$n��������������Ҫ������ȫ��"+weapon->name()+HIG"����֮�£�\n"NOR;
        message_vision(msg, me, target);
        lvl = random((me->query_skill("yuxiao-jian", 1) + me->query_skill("qimen-wuxing", 1)))/ 4;
	me->add_temp("apply/attack", lvl/8);	
	me->add_temp("apply/damage", lvl/8);
        me->add_temp("apply/dexerity", lvl);
        for(i = 0; i < attack_time; i++)
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
        me->start_busy(2);
        me->add("neili", -150);
        me->add("jing", -30);
	me->add_temp("apply/attack", -lvl/8);	
	me->add_temp("apply/damage", -lvl/8);
        me->add_temp("apply/dexerity", -lvl);
        me->set_temp("yuxiao_lian", 1);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, target, lvl :), random(attack_time)+4);
        return 1;
}

void remove_effect(object me, object target)
{
        me->delete_temp("yuxiao_lian");
        if (me->is_fighting(target) )
        message_vision(HIC"$n������͸��$N�Ĺ��ƣ����������｣�������Ž�·�Ի�\n"NOR,me,target);
}

