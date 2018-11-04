//zhongping-qiang.c ��ƽǹ��

#include "ansi.h"

inherit SKILL;

mapping *action = ({
([	"action": "$N˫��һ�𣬾���ǰ�죬ʹ��һ�С���ƽ�޵С�������$wƽƽֱ��������$n��$l",
		"force":		400,
                "damage":               200,
                "dodge" : 10,
                "lvl" : 0,
                "skill_name" : "��ƽ�޵�",
	"damage_type": "����"
]),
([	"action": "$N����$w������ת���������������¶ף�����һ�С�ҹ��̽����������$n��$l��ȥ",
                "damage":               200,
		"force":		300,
                "dodge" : 30,
                "lvl" : 0,
	"skill_name" : "ҹ��̽��",
	"damage_type": "����"
]),
([	"action": "$N����$w������һ��ǹ����һ�С����߳�������$n������ȥ",
		"force":		100,
                "damage":               200,
                "dodge" : 50,
                "lvl" : 0,
	"skill_name" : "���߳���",
	"damage_type": "����"
]),
([	"action": "$Nһ�С�������ǹ��������$w����СȦ��ȥ$n�ĺ��У�����$w΢̧��ָ��$n��$l",
		"force":		100,
                "damage":               200,
                "dodge" : 60,
                "lvl" : 0,
	"skill_name" : "������ǹ",
	"damage_type": "����"
]),
});

int valid_enable(string usage) { return usage=="club" ||  usage=="parry"; }

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 70)
		return notify_fail("�������������\n");
	return 1;
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "club")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("���������������ƽǹ����\n");
	me->receive_damage("qi", 20);
	return 1;
}

string perform_action_file(string action)
{
    return __DIR__"zhong-qiang/" + action;
}
