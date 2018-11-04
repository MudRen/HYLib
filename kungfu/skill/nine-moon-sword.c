
#include <ansi.h>

inherit SKILL;

mapping *action = ({
	([	"name":			"���겻ɢ",
		"action":		"$Nʹһ�С����겻ɢ��������$w���Ⱪ������$n��$l��ȥ",
		"dodge":		50,
		"force":		170,
		"damage_type":	"����"
	]),
	([	"name":			"����ɭɭ",
		"action":		"$N������ת��һ�С�����ɭɭ������$n��$l",
		"dodge":		-70,
		"force":		200,
		"damage_type":	"����"
	]),
	([	"name":			"���Ƶ���",
		"action":		"$N�趯$w��һ�С����Ƶ���Ю�������������$n��$l",
		"dodge":		-40,
		"damage":		90,
		"damage_type":	"����"
	]),
	([	"name":			"���ܵظ�",
		"action":		"$N����$w����һ�������������ܵظ�����$n��$l�̳�����",
		"dodge":		-40,
		"damage":		40,
		"damage_type":	"����"
	]),
	([	"name":			"��������",
		"action":		"$N����$w���Ⱪ����һ�С��������ǡ���$n$l��ȥ",
		"dodge":		60,
		"damage":		120,
		"damage_type":	"����"
	]),
	([	"name":			"��������",
		"action":		"$N����$w����һ���⻡��ֱָ$n$l��һ�С��������¡���������������ȥ",
		"dodge":		-60,
		"damage":		150,
		"damage_type":	"����"
	]),
});

int valid_learn(object me)
{
	object ob;
       if( (string)me->query("gender") != "Ů��" )
                return notify_fail("��������������ֻ��Ů�Ӳ��������书��\n");
	if( (int)me->query("max_neili") < 50 )
		return notify_fail("�������������û�а취����������������\n");
       if( (string)me->query_skill_mapped("force")!= "nine-moon-force")
                return notify_fail("������������������Ͼ����ľ���������\n");
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
		return notify_fail("�����������������û�а취��ϰ������������\n");
	me->receive_damage("qi", 30);
	me->add("neili", -5);
	//write("�㰴����ѧ����һ���������������\n");
	return 1;
}

int valid_effect(object me, object weapon, string name, int skill)
{
}

string perform_action_file(string action)
{
           return __DIR__"ninemoonsword/" + action;
}

int effective_level() { return 8;}

string *parry_msg = ({
        "$nʹ�������������С������𡹣���$N���е�$w��ƫ�˳�ȥ��\n",
	"$n̤��λ�������ţ����е�$v����һ�ã���ס��$N���е�$w��\n",
	"$n��$N����һ�������е�$v˳��$N��$w���£�����$N��$w����ָ��\n",
	"$n���е�$vһ����һ�С��Ŷ��������$v�ó�������Ӱ����ס��$N��$w��\n",
});

string *unarmed_parry_msg = ({
        "$n��͸���⣬һ�С�����̹ǡ���ǿ���Ľ���ֱȡ$N���ʺ�\n",
	"$n����һ����$v��һ��������ֱ��$N������\n",
	"$n�ҽź�̤һ����$v�����֣�������$N�鰴��һ�ɾ���ʹ$Ņ�����֡�\n",
	"$nת��$vͻȻ��Ҹ�´̳���һ�С�ɳ�س�Ы��������$N������$N��æ�����Ա���\n",
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
	return 30;
}
int practice_bonus()
{
	return 20;
}
int black_white_ness()
{
	return 30;
}

