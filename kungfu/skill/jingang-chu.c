// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// jingang-chu.c, ��ս�ħ��

#include <ansi.h>;
inherit SKILL;


string *action_msg = ({
        "$N��ɫׯ�ϣ�������ţ�ʹ��һ�С����������������$wɨ��$n��$l",
        "$N����ŭ�ݣ����д�ȣ���̤��һʽ����շ�ħ����$w����$n��ͷ����",
        "$Nһ�С���������������������дʣ���Ȼ�۷���⣬��������$w��ɨ$n��$l",
        "$Nһ�С���Ȥ��������������$w����չ�������Ľ��䣬���ۻ�$w����$n��$l",
        "$Nһʽ���������ޡ����ڳ��ֻؾ������ȷ�����$w��β���ػ���$n",
        "��Ȼ��$Nһ������֮ɫ������$w�����뻡ʹ��������Ѫ����������$n��$l",
        "$Nһʽ��������ħ�������������������ԣ���$w���һƬ������$n��������",
        "$N��Ŀ������������������һ�����ʩչ����ħ������������$w���Ƴ����ֱ����$n��$l",
});

int valid_enable(string usage) { return (usage == "staff") || (usage == "parry"); }

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 80)
                return notify_fail("�������������\n");
                
        if ((int)me->query_skill("staff", 1) < 
            (int)me->query_skill("jingang-chu", 1))
                return notify_fail("��Ļ����ȷ����̫ǳ��\n");
        
        return 1;
}

mapping query_action(object me, object weapon)
{
        return ([
                "action": action_msg[random(sizeof(action_msg))], 
                "damage": 320 + random(30), 
                "attack": 40 + random(10), 
                "dodge" : 40 + random(10), 
                "parry" : 40 + random(10), 
                "force" : 140 + random(10), 
                "damage_type" : random(2)?"����":"����", 
        ]); 
}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        ||  (string)weapon->query("skill_type") != "staff")
                return notify_fail("��ʹ�õ��������ԡ�\n");
        if (me->query_str() < 20)
                return notify_fail("��ı�����������ս�ħ�ơ�\n");
        if ((int)me->query("qi") < 50)
                return notify_fail("���������������ս�ħ�ơ�\n");
        if ((int)me->query("neili") < 50)
                return notify_fail("���������������ս�ħ�ơ�\n");
        me->receive_damage("qi", 40);
        me->add("neili", -40);
}

string perform_action_file(string action)
{
        return __DIR__"jingang-chu/" + action;
}



int ob_hit(object ob, object me, int damage)
{
        object wp1,weapon;
        string msg;
        int p,j,skill, neili, neili1;
        int level,level2,damage2;
        level = (int) me->query_skill("unarmed",1);
        level2= (int) me->query_skill("longxiang",1);
        skill = me->query_skill("longxiang", 1);
        neili = me->query("neili");
        neili1 = ob->query("neili");
damage2= (int) ob->query("neili",1)/10;
if (random(8)==0 && level2>=300 && (me->query_skill_mapped("force") == "longxiang" || me->query_skill_mapped("force") == "xiaowuxiang"))
{
j = -damage/2; 
if (damage2> 5000)	damage2=5000;
msg = HIM"$N ���������𡸽�����ħ�䡹��������ӿ������һ��һ��ļ�ǿ��$n����һ�ң�������Ȼ�᲻������\n"NOR;
ob->set_temp("apply/attack", 0);
ob->set_temp("apply/defense", 0);
if (random(2)==0)
{
msg += HIM"$N"+HIM+"Ĭ������������ԣ��ֽ�Ħ��֧���ŭӡ! $n����һ�����³�һ����Ѫ!"+NOR;
if (ob->query("qi") > damage2)
{
		ob->receive_damage("qi", damage2/2);
		ob->receive_wound("qi", damage2/2);
}
 if (!ob->is_busy() && random(3)==0) ob->start_busy(2);  
}

           message_vision(msg, me, ob);
           return j;
}      
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        if(  me->query("jiali") > me->query_skill("force") 
          && me->query_skill_mapped("force") == "longxiang") 
             me->set_temp("xiuluo", 1);
if (damage_bonus <10) damage_bonus=10;
      if( random(me->query_skill("jingang-chu",1)) > 100 ) 
{
	  victim->receive_wound("qi", damage_bonus/2);
        return HIR "$n���ȷ�ɨ�У���ʱѪ����ע��\n" NOR;
}
        if(  me->query("jiali") > me->query_skill("force") 
          && me->query_skill_mapped("force") == "longxiang") 

if (damage_bonus <10) damage_bonus=10;
      if( random(me->query_skill("jingang-chu",1)) > 150  || random(8)==0) 
{
	  victim->receive_wound("qi", damage_bonus/2+30);
        return HIB "$N���˫�ۣ�˫�ֺ�һ���ں���ţ����ݣ�����һ������$N�Ƽ�ɳ��� 
ֻ�������������Χ$n����\n" NOR;
}
}