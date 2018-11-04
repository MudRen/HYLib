// softword.c

#include <ansi.h>

inherit SKILL;

mapping *action = ({
	([	"name":			"����է��",
		"action":		"$Nʹһ�С�����է�𡹣�����$w����㴺������$n��$l��û����֪�������������Ҳ���޷��ֵ�",
		"dodge":		-200,
		"parry" :		-200,
		"damage":		70,
		"force" : 		200,
		"damage_type":	"����"
	]),
	([	"name":			"ϸ������",
		"action":		"$N���е�$wһ�С�ϸ�����ࡹ������ϸ�꣬�޿ײ���Ĵ���$n��$l",
                "dodge":                -200,
                "parry" :               -200,
                "damage":               50,
                "force" :               100,
		"damage_type":	"����"
	]),
	([	"name":			"���Ǵ���",
		"action":		"$N�趯$w��һ�С����Ǵ��ޡ�����������������磬�˽���һ������$n��$l",
                "dodge":                -200,
                "parry" :               -300,
                "damage":               150,
                "force" :               250,
		"damage_type":	"����"
	]),
	([	"name":			"������ˮ",
		"action":		"$Nһ������$w��ʹ����������ˮ�������ɵð������ˣ�����Ԧ������$n��$l�̳�һ��",
                "dodge":                -100,
                "parry" :               -100,
                "damage":               50,
                "force" :               150,
		"damage_type":	"����"
	]),
	([	"name":			"֯��Ū��",
		"action":		"$N����$w������ɢ��һ�С�֯��Ū�ɡ����������ƣ�������$n��$l�����˲�֪�����Ժη�",
                "dodge":                -250,
                "parry" :               -250,
                "damage":               90,
                "force" :               220,
		"damage_type":	"����"
	]),
	([	"name":			"��������",
		"action":		"$N�����������������������������$wֱָ$n$l��һ�С��������Ρ����̳��˾��춯�ص�һ��",
		"dodge":		-20,
		"damage":		50,
		"damage_type":	"����"
	]),
});

int valid_learn(object me)
{
	object ob;

	if( (int)me->query("max_neili") < 100 )
		return notify_fail("�������������û�а취�����ϸ�����ὣ����\n");

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
		return notify_fail("�����������������û�а취��ϰ���ϸ�꽣����\n");
	me->receive_damage("qi", 30);
	me->add("neili", -5);
	//write("�㰴����ѧ����һ�����ϸ�꽣����\n");
	return 1;
}
int effective_level() { return 15;}
string *parry_msg = ({
        "$n���ƹ��У��ҽ�����һ�С��麣���ġ������е�$v�ݺݿĿ���$N��$w��\n",
	"$n������������ס$N��$w��һ�С�����ĺĺ����ʹ$N���԰ѳ����е�$w��\n",
});

string *unarmed_parry_msg = ({
        "$nʹ��һ�С������¶���������๥����ʹ$N��֪�ǹ����ء�\n",
	"$nһ�����е�$v��ʹ��һ�С��������á������е�$v������ƣ���ȫ��������ס��\n",
	
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
	return -100;
}
int black_white_ness()
{
	return -10;
}

string perform_action_file(string action)
{
    return __DIR__"softsword/" + action;
}

