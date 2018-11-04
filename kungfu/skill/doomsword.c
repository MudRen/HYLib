// six-chaos-sword.c

#include <ansi.h>

inherit SKILL;

mapping *action = ({
	([	"name":			"Ⱥħ����",
		"action":		"$Nʹһ�С����ư�����������$w�����������$n��$l��������",
		"dodge":		-200,
		"parry" :		-200,
		"damage":		70,
		"force" : 		200,
		"damage_type":	"����"
	]),
	([	"name":			"�������",
		"action":		"$N����һת��һ�С����������$wն��$n��$l",
                "dodge":                -200,
                "parry" :               -200,
                "damage":               50,
                "force" :               100,
		"damage_type":	"����"
	]),
	([	"name":			"�ٹ�ҹ��",
		"action":		"$N�趯$w��һ�С��׺���ա�Ю�������������$n��$l",
                "dodge":                -200,
                "parry" :               -300,
                "damage":               150,
                "force" :               250,
		"damage_type":	"����"
	]),
	([	"name":			"������·",
		"action":		"$N����$wһ����ʹ�������Ȳ�����$n��$l�̳�һ��",
                "dodge":                -100,
                "parry" :               -100,
                "damage":               50,
                "force" :               150,
		"damage_type":	"����"
	]),
	([	"name":			"��Ӱ����",
		"action":		"$N����$w���Ⱪ����һ�С���Ӱ�㿡���$n$l��ȥ",
                "dodge":                -250,
                "parry" :               -250,
                "damage":               90,
                "force" :               220,
		"damage_type":	"����"
	]),
	([	"name":			"��ع�",
		"action":		"$N����$wֱָ$n$l��һ�С���ع����������˽�����ȥ",
		"dodge":		-20,
		"damage":		50,
		"damage_type":	"����"
	]),
});

int valid_learn(object me)
{
	object ob;

	if( (int)me->query("max_neili") < 100 )
		return notify_fail("�������������û�а취�����촵Ѫ������\n");

	if( !(ob = me->query_temp("weapon"))
	||	(string)ob->query("skill_type") != "sword" )
		return notify_fail("���������һ�ѽ�������������\n");

	return 1;
}

int valid_enable(string usage)
{
	return usage=="sword" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if( (int)me->query("qi") < 30
	||	(int)me->query("neili") < 5 )
		return notify_fail("�����������������û�а취��ϰ���촵Ѫ������\n");
	me->receive_damage("qi", 30);
	me->add("neili", -5);
	//write("�㰴����ѧ����һ�麮�촵Ѫ������\n");
	return 1;
}

int valid_effect(object me, object weapon, string name, int skill)
{
}

int effective_level() { return 27;}

string *parry_msg = ({
        "$n���˷������������죬һ�С��ޱ��޼ʡ������е�$v�ݺݿĿ���$N��$w��\n",
	"$n�ؽ����أ�һ�С�����������ס��$N��$w��\n",
	"$nһ�С�Ⱥħ���衹�����е�$v����ǧ�ٰѣ���ס��ȫ��\n",
	"$n���е�$v�������£�������$N��$w�������Ρ�\n",
});

string *unarmed_parry_msg = ({
        "$nʹ��һ�С���֮�ϡ�������ǰ������һ��ͭǽ���ڣ���ס��$N�Ĺ��ơ�\n",
	"$nһ�����е�$v��ʹ��һ�С������Ȫ�������е�$v��ס��ȫ��\n",
	"$n��$v������һ�̣�$v�����������պ�ֱ��$N��˫�ۡ�\n",
	"$n�ٽ�������һ�������ӽ���͸�����ƿ���$N��\n",
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
	return 0;
}
int practice_bonus()
{
	return 0;
}
int black_white_ness()
{
	return -10;
}



string perform_action_file(string action)
{
        return __DIR__"doomsword/" + action;
}

