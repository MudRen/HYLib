#include <ansi.h>
inherit SKILL;

mapping *action = ({
([  "action" : 		"$N��ȭ����$n��$l",
    "damage": 100,
    "lvl" : 0,
    "skill_name" : "��������",
    "damage_type" : "����"
]),
([  "action" : "$N��$n��$lһץ",
    "dodge" : 10,
    "damage": 100,
    "lvl" : 0,
    "skill_name" : "���ֵ�Ѩ",
    "damage_type":	"ץ��",
]),
([  "action" : "$N��$n��$l�ݺݵ�����һ��",
    "dodge" : 15,
    "damage": 20,
    "lvl" : 0,
    "skill_name" : "ǰհ����",
		"damage_type":	"����",
]),
([  "action" : "$N����ȭͷ��$n��$l��ȥ",
    "dodge" : 25,
    "damage": 80,
    "lvl" : 0,
    "skill_name" : "������Ӱ",
    "damage_type":	"����",
]),
([  "action" : "$N��׼$n��$l�����ӳ�һȭ",
    "dodge" : 30,
    "damage": 100,
    "lvl" : 0,
    "skill_name" : "�޵и��",
    "damage_type":	"����",
])
});

int valid_enable(string usage) { return usage=="unarmed" || usage=="parry"; }      
int valid_learn(object me)
{
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
    level = (int)me->query_skill("gedoushu", 1);
    for(i = sizeof(action); i > 0; i--)
    if(level > action[i-1]["lvl"])
      return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
    return 1;
}
string perform_action_file(string action)
{
	return __DIR__"gedoushu/" + action;
}