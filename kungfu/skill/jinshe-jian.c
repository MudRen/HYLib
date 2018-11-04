// jinshe-jian.c

#include <ansi.h>
inherit SKILL;

mapping *action = ({
	([	"name":		"�����Ӱ",
		"action":	"$Nʹһ�С������Ӱ�������е�$w��һ��ָ������$n��$l��������",
		"dodge":	50,
		"parry" :	100,
		"force":	170,
		"damage" :	350,
		"damage_type":	"����"
	]),
	([	"name":		"��Ӱ���",
		"action":	"$Nʹһ�С���Ӱ�����������$w�����������$n��$l��������",
		"dodge":	100,
		"parry" :	200,
		"force" : 	200,
		"damage":	370,
		"damage_type":	"����"
	]),
	([	"name":		"ѩ�ط���",
		"action":	"$N����һת����������Ծ������$w�鶯زԾ��һ�С�ѩ�ط��ߡ�����$n��$l",
                "dodge":	100,
                "parry" :	200,
		"force":	170,
		"damage" :	350,
		"damage_type":	"����"
	]),
	([	"name":		"��������",
		"action":	"$N����һת��һ�С��������š������е�$w����������$n��$l���˹�ȥ",
		"dodge":	100,
		"parry" :	200,
		"force" : 	200,
		"damage":	320,
		"damage_type":	"����"
	]),
	([	"name":		"���߿���",
		"action":	"$N����һ����һ�С����߿��衹��$wЮ���������⣬����޷�����$n��$l",
		"dodge":	100,
		"parry" :	200,
		"force" : 	300,
		"damage":	350,
		"damage_type":	"����"
	]),
	([	"name":		"���ߵ���",
		"action":	"$N������������񴦣�һ�С����ߵ�������$w���޷����ݵ��ٶ�ֱ��$n��$l",
		"dodge":	100,
		"parry" :	200,
		"force" : 	250,
		"damage":	300,
		"damage_type":	"����"
	]),
	([	"name":		"�������",
		"action":	"$N����һ����һ�С�������ǡ������е�$w�������ϴ���$n��$l",
		"dodge":	100,
		"parry" :	200,
		"force" : 	300,
		"damage":	300,
		"damage_type":	"����"
	]),
	([	"name":		"���߻���",
		"action":	"$N����$w���Ⱪ����һ�С����߻���������ǧ����Ы��$n$lҧȥ",
		"dodge":	100,
		"parry" :	200,
		"force" : 	300,
		"damage":	400,
		"damage_type":	"����"
	]),
});

int valid_learn(object me)
{
	object ob;

	if( (int)me->query("max_neili") < 500 )
		return notify_fail("�������������û�а취�����߽�����\n");

	if( !(ob = me->query_temp("weapon"))
	||	(string)ob->query("skill_type") != "sword" )
		return notify_fail("���������һ�ѽ�������������\n");

        return notify_fail("���߽���û�����ڡ�\n");

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
	||	(int)me->query("neili") < 15 )
		return notify_fail("�����������������û�а취��ϰ���߽�����\n");
	me->receive_damage("qi", 30);
	me->add("neili", -15);
	
	if ((int)me->query("qi") < 350)
		return notify_fail("����������������߽�����\n");
	if ((int)me->query("jing") < 300)
		return notify_fail("��ľ������������߽�����\n");
	me->receive_damage("qi", 300);
	me->receive_damage("jing", 100);

	//write("�㰴����ѧ����һ����߽�����\n");
	return 1;
}

int valid_effect(object me, object weapon, string name, int skill)
{
}

int effective_level() { return 25;}

string *parry_msg = ({
        "$n���˷������������죬���е�$v�ݺݿĿ���$N��$w��\n",
	"$n�ؽ����أ���ס��$N��$w��\n",
	"$n���е�$v����ǧ�ٰѣ���ס��ȫ��\n",
	"$n���е�$v�������£�������$N��$w�������Ρ�\n",
});

string *unarmed_parry_msg = ({
        "$nʹ��$v������ǰ������һ��ͭǽ���ڣ���ס��$N�Ĺ��ơ�\n",
	"$nһ�����е�$v����ס��ȫ��\n",
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

string perform_action_file(string action)
{
        return __DIR__"jinshe-jian/" + action;
}


