// snowwhip.c

#include <ansi.h>

inherit SKILL;

mapping *action = ({
	([
		"action":		"$N��߳һ����˫�ֲ��٣����ⶸ�ɣ���ʱ�˱޺�һ�����ֱ��$n��ȥ",
		"dodge":		10,
		"damage":		30,
		"damage_type":	"����"
	]),
	([
		"action":		"$N���б�Ӱէ�ţ��������ص�⣬��̫�ſ��족��Ȼ��ɨ��",
		"dodge":		50,
		"damage":		20,
		"damage_type":	"����"
	]),
	([
		"action":		"$N��ʽһ�䣬ɱ���Ĳ���չ������������ȥ�޻ص�ɱ�С�̫�ŷ���˵���ԡ�",
		"dodge":		40,
		"damage":		75,
		"damage_type":	"����"
	]),
	([
		"action":	        "$NԾ�����ɣ����ڰ�գ���ʽ���䣬��̫���������羪�κ��ˣ���ת�������",
		"dodge":		40,
		"damage":		30,
		"damage_type":	"����"
	]),
});

int valid_learn(object me)
{
	object ob;

	if( (int)me->query("max_neili") < 50 )
		return notify_fail("�������������û�а취��������, ����Щ���������ɡ�\n");

	if( !(ob = me->query_temp("weapon"))
	||	(string)ob->query("skill_type") != "whip" )
		return notify_fail("���������һ�����Ӳ������޷���\n");

	return 1;
}

int valid_enable(string usage)
{
	return usage=="whip" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if( (int)me->query("qi") < 30
	||	(int)me->query("neili") < 5 )
		return notify_fail("�����������������û�а취��ϰ�����ơ�\n");
	me->receive_damage("qi", 30);
	me->add("neili", -5);
	//write("�㰴����ѧ����һ�������ơ�\n");
	return 1;
}

int valid_effect(object me, object weapon, string name, int skill)
{
}

int effective_level() { return 16;}

string *parry_msg = ({
        "$nһ��ת�գ����μ�ʽ�������ߣ������������ޡ�̫����������β��������һ�����棬��סȫ��\n",
	"$nһ�С�������������������������$N���е�$w\n",
	"$n�ұ����һ�ڣ����е�$v��ǰ�������Ӱ��ѩ������ס��$N��\n",
	"$n��̤�����λ�λ���ÿ���һ�С�\n",
	
});

string *unarmed_parry_msg = ({
        "$nһ��ת�գ����μ�ʽ�������ߣ������������ޡ�̫����������β��������һ�����棬��סȫ��\n",
        "$n�ұ����һ�ڣ����е�$v��ǰ�������Ӱ��ѩ������ס��$N��\n",
        "$n��̤�����λ�λ���ÿ���һ�С�\n",


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
	return 20;
}
int practice_bonus()
{
	return 10;
}
int black_white_ness()
{
	return 20;
}


string perform_action_file(string action)
{
        return __DIR__"thunderwhip/" + action;
}
