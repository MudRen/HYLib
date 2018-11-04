// wudu-bian.c �嶾�޷�

#include <ansi.h>

inherit SKILL;

mapping *action = ({
([	"action":		"$N�ᶶ����һ�С�������о��������$w���ñ�ֱ��ֱ��$n��ȥ",
	"force":		60,
	"dodge":		30,
	"damage":		30,
	"lvl" : 0,
	"skill_name" : "������о",
	"damage_type":	"����"
]),
([	"action":		"$N����һת��һ�С���Ы��β����$w�ڿ���ת�˸�Ȧ���Թ���ĽǶ�����$n",
	"force":		150,
	"dodge":		20,
	"damage":		50,
	"lvl" : 10,
	"skill_name" : "��Ы��β",
	"damage_type":	"����"
]),
([	"action":		"$Nһ�����ޣ�һ�С�������˿��������$w����������Ӱ������$n",
	"force":		200,
	"dodge":		30,
	"damage":		60,
	"lvl" : 20,
	"skill_name" : "������˿",
	"damage_type":	"����"
]),
([	"action":		"$N������ң�һ�С���ܳ�����������$w������ң�ֱ����$n�ؿ�",
	"force":		300,
	"dodge":		10,
	"damage":		80,
	"lvl" : 30,
	"skill_name" : "��ܳ���",
	"damage_type":	"����"
]),
([	"action":		"$N��������һ�С���򼷭��������$wת��������ȦȦ������һ�����磬ֱ��$n��ȥ",
	"force":		500,
	"dodge":		-20,
	"damage":		150,
	"lvl" : 40,
	"skill_name" : "��򼷭��",
	"damage_type":	"����"
])

});

int valid_enable(string usage) { return (usage == "whip") || (usage == "parry"); }

int valid_learn(object me)
{
	object weapon;

	if( (int)me->query_skill("wudu-xinfa") < 30 )
		return notify_fail("����嶾�ķ�̫�ͣ��������嶾�ޡ�\n");

	if ( !objectp(weapon = me->query_temp("weapon"))
	|| ( string)weapon->query("skill_type") != "whip" )
		return notify_fail("���������һ�����Ӳ������޷���\n");

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
	level   = (int) me->query_skill("wudu-bian",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "whip")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("��������������嶾�޷���\n");
	me->receive_damage("qi", 5);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"wudu-bian/" + action;
}
