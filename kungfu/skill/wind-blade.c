// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <ansi.h>
inherit SKILL;
mapping *action = ({
	([	"action":		"$N���е�$wӭ��һ�Σ���������ѽ���������������ڰ�ؿ���$n��$l",
		"force":		400,
                "damage":               200,
                "dodge" : 10,
                "lvl" : 0,
                "skill_name" : "�ձ��޵�",
    		"damage_type":	"����"
	]),
	([	"action":		"$N���е�$wӭ����裬�󱩷��еĹ�ɳ������$n��$l",
                "damage":               200,
		"force":		300,
                "dodge" : 30,
                "lvl" : 20,
                "skill_name" : "���ǹ���",
		"damage_type":	"����"
	]),
	([	"action":		"$N���е�$w�����е����ƣ����ۺ�ɢ�ؿ���$n��$l",
		"force":		100,
                "damage":               200,
                "dodge" : 50,
                "lvl" : 40,
                "skill_name" : "��������",
                "damage_type":	"����"
	]),
	([	"action":		"$N�ζ����е�$w������������֣�������е���Ҷ��һ����һ����ɢ��$n��$l",
		"force":		100,
                "damage":               200,
                "dodge" : 60,
                "lvl" : 80,
                "skill_name" : "�������",
                "damage_type":	"����"
	]),
	([	"action":		"$N����ȫ��Ĺ��������е�$w��̹Ǻ�������$n",
		"force":		200,
		"damage":		200,
                "dodge" : 70,
                "lvl" : 100,
                "skill_name" : "��ʿ����",
                "damage_type":	"����"
	]),
});

int valid_enable(string usage) { return usage == "blade" || usage == "parry"; } 

int valid_learn(object me)
{
    if ((int)me->query("max_neili") < 300)
    return notify_fail("�������������\n");
    if ((int)me->query_skill("force", 1) < 60)
    return notify_fail("����ڹ��ķ����̫ǳ��\n");
    if ((int)me->query_skill("dodge", 1) < 60)
    return notify_fail("����Ṧ���̫ǳ��\n");
    if ((int)me->query_dex() < 25)
    return notify_fail("�������������\n");
    return 1;
}

string query_skill_name(int level)
{
    int i;
    for(i = sizeof(action)-1; i >= 0; i--)
   if(level >= action[i]["lvl"])
      return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
    int i, level;
    level   = (int) me->query_skill("wind-blade",1);
    for(i = sizeof(action); i > 0; i--)
   if(level > action[i-1]["lvl"])
      return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
    object weapon;

    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "blade")
    return notify_fail("��ʹ�õ��������ԡ�\n");
    if ((int)me->query("qi") < 30)
    return notify_fail("�������������������\n");
    me->receive_damage("qi", 25);
    return 1;
}

string perform_action_file(string action)
{
    return __DIR__"wind-blade/" + action;
}
mixed hit_ob(object me, object victim, int damage_bonus, int factor, string limb)
{
	int level, jiali, time,level2;
	object weapon;
	int damage;
	weapon = me->query_temp("weapon");
        level = (int) me->query_skill("wind-blade",1);
        level2= (int) me->query_skill("wind-blade",1);

level2= (int) me->query_skill("wind-blade",1);             
	if (random(3)==1 && me->query_skill("wind-blade",1)>300)
	{
	if( damage_bonus > 20 && random(level2)>100) {
	victim->receive_wound("qi", (random(damage_bonus)));
	return HIM"$N�����ݺ�! һ������������$n��$l�������Ѫ��!\n"NOR;
        }
}
}