// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// ����Ⱥħ

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;


int perform(object me, object target)
{
        int skill, damage, ap, dp;
        object weapon;
        string msg, pmsg;
        

                
        if (! target) target = offensive_target(me);
        
        if (! target
        ||  ! target->is_character()
        ||  ! me->is_fighting(target))
        
                return notify_fail(
                        "��"RED"����Ⱥħ"NOR"��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon"))
        ||  (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԡ�\n");
      
        if (target->is_busy())
                return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ӽ������ɢ�\n");

        if((int)me->query_skill("xuantie-sword", 1) < 120)
                return notify_fail(
                        "�����������������죬����ʹ�á�"RED"����Ⱥħ"NOR"����\n");

        if ((int)me->query_skill("yunv-xinfa", 1) < 120
        &&  (int)me->query_skill("yunv-xinfa", 1) < 120)
                return notify_fail(
                        "��Ĺ�Ĺ�ڹ���Ϊ̫ǳ������ʹ�á�"RED"����Ⱥħ"NOR"����\n");

        if (me->query_str() < 40)
                return notify_fail(
                        "��ı���������ʹ�á�"RED"����Ⱥħ"NOR"�����ڼ��ѡ�\n");

        if (me->query("neili") < 300)
                return notify_fail("�������������\n");

        msg = HIB"��Ȼ�䣬$N����"NOR+weapon->query("name")+HIB"����һ�����������¡¡" +
              "�ķ���֮����Ю�������֮�ƣ�\nһʽ��"NOR+BLINK+RED"����Ⱥħ"NOR+HIB"����" +
              "����"NOR+weapon->query("name")+HIB"��$n��ͷֱѹ��ȥ��\n";
              
        ap = me->query_skill("sword") + me->query_str() * 2;
        dp = target->query_skill("parry") + target->query_str() * 2;

        if (ap / 2 + random(ap) > dp) 
        {
                skill = (int)me->query_skill("xuantie-sword", 1);
                damage  =me->query_skill("sword")*2;
                me->add("neili", -200);
                
                pmsg = HIR "$n�����мܣ���ʱ��$N�������ѹ����Ѫ���ڣ�����ס���ۡ����³�һ����Ѫ��\n" NOR;
//                msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 80, pmsg);
       target->add("qi",-damage/2);
		target->add("eff_qi",-damage/2);
                msg += HIR "$n�����мܣ���ʱ��$N�������ѹ����Ѫ���ڣ�����ס���ۡ����³�һ����Ѫ��\n" NOR;
                me->start_busy(1);
                target->start_busy(2);
        } else
        {
                me->add("neili", -100);
                msg += HIW"$p��æȫ��һ�������项��һ�����죬$P������о�Ȼ��$p����������\n" NOR;
                me->start_busy(2);
        }
    
        message_combatd(msg, me, target);
        
        return 1;
}


