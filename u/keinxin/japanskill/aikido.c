// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <ansi.h>
inherit SKILL;
object offensive_target(object me)
{
	int sz;
	object *enemy;

	enemy = me->query_enemy();
	if( !enemy || !arrayp(enemy) ) return 0;

	sz = sizeof(enemy);
	if( sz > 4 ) sz = 4;

	if( sz > 0 ) return enemy[random(sz)];
	else return 0;
}
string* buwei = ({
        "�����ⲿ",
        "����",
        "���ֹؽ�",
        "����",
        "�粿�ؽ�",
        "����ҪѨ",
        "ϥ�ؽ�",
        "����"
});
mapping *action = ({
        ([      "action":               
"$N������ǰ�������ں�˫��������$n��$l����",
                "dodge":                30,
                "parry":                10,
                "force":                90,
                "damage":                90,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N��ŵ�أ����������ת�������򼲷�ɨ��Ҷ��ɨ��$n��$l",
                "dodge":                10,
                "parry":                30,
                "force":                90,
                "damage":                90,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N������Σ�����������벻���ĽǶ�ײ����$n��$l",
                "dodge":                30,
                "parry":                10,
                "force":                90,
                "damage":                120,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N�ҽ���գ��γ�һƬ��Ӱ�����Ǽ���$n��$lһ���߳�����",
                "dodge":                10,
                "parry":                30,
                "force":                90,
                "damage":                130,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N���Ծ���������ת��˫�Ŵ�������һǰһ�������$n��$l",
                "dodge":                20,
                "parry":                30,
                "force":                90,
                "damage":                140,
                "damage_type":  "����"
        ]),
});

int valid_learn(object me)
{
    if ((int)me->query_skill("shayi-xinfa", 1) < 30)
   return notify_fail("���ɱ���ķ���򲻹���\n");
        if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
                return notify_fail("��������������֡�\n");
        return 1;
}

int valid_enable(string usage) { return  usage=="unarmed" || usage=="parry"; }

mapping query_action(object me, object weapon)
{
        int i, level;
        object victim;
        string bw;
        
        if( !victim && me->is_fighting() ) victim = offensive_target(me);
        level   = (int) me->query_skill("aikido",1);
        
        bw = buwei[random(sizeof(buwei))];
if (me && victim)
{
        if ((int) me->query_skill("aikido",1) > random(50)  && me->query("neili") > 300
        && random(me->query("combat_exp")) > victim->query("combat_exp")/2 && random(4)==0
         && me->query_skill_mapped("unarmed") == "aikido"
         && me->query_skill_mapped("parry") == "aikido"
         && !me->is_busy()
         && victim->query("qi") > 100
         && !victim->is_busy()
         && !me->query_temp("weapon")) {
                me->add("neili", -50);
                message_vision(HIY"$N�ú��������÷���Ȼ��ץס��$n��"+bw+"!\n"NOR,me,victim);
                message_vision(CYN"$N�˱ܲ�����$nץס��"+bw+",Ȼ���׳���\n"NOR,victim,me);
if (userp(victim))
                victim->add("qi",-victim->query("qi")/20);
else            victim->add("qi",-level);
                victim->start_busy(1 + random(level/50));
        }
}
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}
int practice_skill(object me)
{
    if ((int)me->query_skill("shayi-xinfa", 1) < 10)
   return notify_fail("���ɱ���ķ���򲻹���\n");

        if( (int)me->query("qi") < 80 )
                return notify_fail("������������ˣ���Ϣһ�������ɡ�\n");
        if( (int)me->query("neili") < 50 )
                return notify_fail("������������ˣ���Ϣһ�������ɡ�\n");
        me->receive_damage("qi", 40);
        me->add("neili", -30);
        return 1;
}
int effective_level() { return 10;}
 
string *parry_msg = ({
        "$n����һ����˫��һ�ŵأ�ȫ����$N��$w�Ĺ�����Χ��\n",
});

string *unarmed_parry_msg = ({
        "$n����һ����˫��һ�ŵأ�ȫ����$N�Ĺ�����Χ��\n",
});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}

int learn_bonus()
{
	return 10;
}
int practice_bonus()
{
	return 5;
}
int black_white_ness()
{
	return -10;
}

string perform_action_file(string action)
{
    return __DIR__"aikido/" + action;
}

