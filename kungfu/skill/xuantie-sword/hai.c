// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// ������ӿ

#include <ansi.h>
#include <combat.h> 
inherit F_SSERVER;


string *xue_name = ({ 
        "�͹�Ѩ","����Ѩ","����Ѩ","��ԪѨ","����Ѩ","�м�Ѩ","�н�Ѩ","��ͻѨ","�ٻ�Ѩ",
        "����Ѩ","����Ѩ","���Ѩ","�Ϲ�Ѩ","��ԨѨ","�쾮Ѩ","��ȪѨ","����Ѩ","����Ѩ",
}); 

int perform(object me, object target)
{
        string msg, dodge_skill;
        int i, j, ap, dp;
        object weapon;


                        
        if (me->query("gender") == "����")
        {
                i = me->query_skill("xuantie-sword", 1) / 4;
                j = me->query_skill("sword", 1) / 4;
        }
        else 
        {
                i = me->query_skill("xuantie-sword", 1) / 5;
                j = me->query_skill("sword", 1) / 5;
        }
        weapon = me->query_temp("weapon");

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail("���������ġ�������ӿ��ֻ����ս���жԶ���ʹ�á�\n");

        if (! weapon || weapon->query("skill_type") != "sword")
                return notify_fail("�����ʹ����������ʹ�á�������ӿ����\n");

        if ((int)me->query_skill("xuantie-sword", 1) < 130)
                return notify_fail("�������������������죬ʹ������������ӿ��������\n");

        if ((int)me->query_skill("yunv-xinfa", 1) < 130
        &&  (int)me->query_skill("yunv-xinfa", 1) < 130)
                return notify_fail("��Ĺ�Ĺ�ڹ��ȼ���������ʹ������������ӿ��������\n");

        if ((int)me->query_skill("force") < 180)
                return notify_fail("����ڹ��ȼ�����������ʹ�á�������ӿ����\n");

        if ((int)me->query_str() < 33 && userp(me))
                return notify_fail("�������������ǿ����ʹ������������ӿ������\n");

        if (target->is_busy())
                return notify_fail(target->name()+"���Թ˲�Ͼ������Է��ĵؽ�����\n");

        if (me->query_skill_mapped("sword") != "xuantie-sword" && userp(me))
                return notify_fail("�������޷�ʹ�á�������ӿ����\n");

        if (me->query_skill_mapped("parry") != "xuantie-sword" && userp(me))
                return notify_fail("�������޷�ʹ�á�������ӿ����\n");

        if ((int)me->query("max_neili") < (me->query_skill("force") + j + 200) && userp(me))
                return notify_fail("����������̫����ʹ������������ӿ����\n");      

        message_combatd(HIB "\n$N��" + weapon->query("name") +
                        HIB "Ю���˳�ӿ֮�ƣ������γ�һ����ת�����У���$n���ֹ�ȥ��\n" NOR,
                        me, target);
                        
        ap = me->query_skill("sword");
        dp = target->query_skill("dodge");
             
        if (ap / 2 + random(ap) > dp)
        {
                message_combatd(HIR "���$nȫ���������γɵ������������ţ�ֻ�����������ݺ��ξ��ˣ�����ײײ��\n" NOR,
                                me, target);
                                
                target->start_busy(5 + ap / 100);
                //target->set_temp("xtjf/haichao", 1);
                me->add("neili", -i*3);
                if (present(target, environment(me)) && me->is_fighting(target))
                        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
                        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
                        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
                if (me->query_skill("xuantie-sword", 1) > 180)
                        call_out("remove_effect", 1, me, target);
                        
                if ((int)me->query_skill("xuantie-sword", 1) > 150
                &&  (int)me->query("neili", 1) > (me->query_skill("force", 1) + j)
                &&  present(target, environment(me))
                &&  me->is_fighting(target))
                {
                        message_combatd(HIB "\n$N΢Ц������ƽ����е�" + weapon->query("name") +
                                        HIB "������죬������ᣬ����Ȼ�����������֮������$nϯ���ȥ��\n" NOR,
                                        me, target);
                                        
                        if (random(me->query_skill("sword", 1)) > target->query_skill("parry", 1) / 3
                        ||  ! living(target)
                        ||  me->query("level") > target->query("level"))
                        {
                                me->add_temp("apply/defense", i);
                                me->add_temp("apply/attack", j);
                                me->set_temp("xtjf_pfm", 1);
                                if (random(3)==0) target->start_busy(3);
                                COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
                        
                                if (present(target, environment(me)) && me->is_fighting(target))
                                        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
                                        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
                                        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
                                me->add_temp("apply/defense", -i);
                                me->add_temp("apply/attack", -j);
                        
                                me->add("neili", -200);
                                me->delete_temp("xtjf_pfm");
                        } else 
                        {
                                me->add("neili", -100);
                                dodge_skill = target->query_skill_mapped("dodge");
                                if (! dodge_skill ) dodge_skill = "dodge";
                                        msg = SKILL_D(dodge_skill)->query_dodge_msg(target, 1);
                                message_combatd(msg, me, target);
                        }
                        return 1;
                }
        } else 
        {
                me->start_busy(2+random(2));
                me->add("neili", -100);
                dodge_skill = target->query_skill_mapped("dodge");
                if (! dodge_skill ) dodge_skill = "dodge";
                        msg = SKILL_D(dodge_skill)->query_dodge_msg(target, 1);
                message_combatd(msg, me, target);
        }
        return 1;
}

void remove_effect(object me, object target)
{
        if (! me) return;
        if (objectp(target) && ! me->is_fighting(target))
        {
                target->delete_temp("xtjf");
                return;
        }
        if (objectp(target)
        &&  me->is_fighting(target)
        &&  ! target->is_busy()
        &&  random(2) == 1
        &&  me->query_temp("weapon"))
        {
                target->delete_temp("xtjf");
                call_out("perform2", 1, me, target);
                return;
        }
        call_out("remove_effect", 1 ,me ,target);
}

int perform2(object me, object target)
{
        string msg, dodge_skill,name;
        object weapon = me->query_temp("weapon");        
        int p, ap, dp;
        
        if( !target ) target = offensive_target(me);

        if( !target || !me->is_fighting(target) )
                return 0;

        if( !weapon || weapon->query("skill_type") != "sword")
                return 0;
        if( me->query_skill_mapped("sword") != "xuantie-sword" && userp(me))
                return 0;

        if( me->query_skill_mapped("parry") != "xuantie-sword" && userp(me))
                return 0;

        if((int)me->query("neili") < 1000)
                return 0;

        if( me->query("gender")=="Ů��" )
                p = me->query_skill("force", 1) / 6;
        else
                p = me->query_skill("force", 1) / 8;

        name = xue_name[random(sizeof(xue_name))];
        msg =HIB"\n$n�ò����׻���������$N����Ʈ����ת�˼�ת���Ʋ�����������һ������$n��"RED+name+HIB"��\n"NOR;
        
        ap = me->query_skill("sword") * 3 / 2 + me->query("level") * 20 + 
             me->query_skill("martial-cognize", 1);
        dp = target->query_skill("parry") + target->query("level") * 20 + 
             target->query_skill("martial-cognize", 1);
             
        if (ap / 2 + random(ap) > dp)
        {
                msg += CYN"$n�پ���ǰһ���Ի�һʱ���������ϵ�"RED+name+CYN"�ѱ�"+weapon->name()+CYN"���С�\n"NOR;
                target->add_temp("apply/attack", -p/2);
                target->add_temp("apply/defense", -p/2);
                target->set_temp("xtjf/haichao");
                if( random(2) == 1)
                {
                        //target->apply_condition("no_perform", 1+ random(2));
                        target->start_busy(3);
                        target->set_temp("xtjf/perform");
                }
                else 
                { 
                        //target->apply_condition("no_exert", 1+random(2));
                        target->start_busy(3);
                        target->set_temp("xtjf/exert");
                }
                me->add("neili", - p * 6);
                call_out("check_fight", 1, me, target, weapon, p );
        }
        else {
                me->start_busy(2+random(2));
                me->add("neili", -100);
                dodge_skill = target->query_skill_mapped("dodge");
                if( !dodge_skill ) dodge_skill = "dodge";
                        msg += SKILL_D(dodge_skill)->query_dodge_msg(target, 1);
        }
        message_combatd(msg, me, target);
        return 1;
}

void check_fight(object me,object target,object weapon, int p)
{
        if( !target) return;
        if( ! me 
         || ! me->is_fighting("target")
         || ! me->query_temp("weapon")
         || weapon->query("skill_type") != "sword"
         || ! present(target,environment(me))
         || me->query_skill_mapped("sword") != "xuantie-sword"){
                target->add_temp("apply/attack", p/2);
                target->add_temp("apply/defense",p/2);

                target->delete_temp("xtjf");
                message_combatd(HIW"\n$N���������˾��������λָ���ԭ�ȵĽýݡ�\n"NOR, target);
                return ;
        }
        call_out("check_fight", 1, me, target, weapon, p );
}

