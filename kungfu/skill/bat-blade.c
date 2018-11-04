
inherit SKILL;

mapping *action = ({
	([	"action":		"$Nһ�п���ƽ������ġ���ɽ���꡹��$w�����һ����˿��$n��ȥ��",
		"damage":		70,
		"dodge":		70,
		"damage_type":	"����"
	]),
	([	"action":		"$N���˺�һ�����⽻�ڣ�����$w����������$n��$l��",
		"damage":		40,
		"damage_type":	"����"
	]),
	([	"action":		"$N���е�$w�ó�һƬ�������ִ�$n�����е�����������",
		"damage":		20,
		"damage_type":	"����"
	]),
	([	"action":		"$N����������е�$w�ó�һƬ���⣬����Ȼ����һ����ն$n��$l��",
		"damage_type":	"����"
	]),
	([	"action":		"$N���е�$w��â������ʹ����˭��Ӣ�ۡ����������������$n��$l��",
		"damage":		70,
		"damage_type":	"����"
	]),
	
});

int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_neili") < 50 )
                return notify_fail("�������������û�а취�����𵶷�\n");


        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "blade" )
                return notify_fail("���������һ�ѵ�������������\n");
        return 1;
}

int valid_enable(string usage)
{
	return (usage=="blade") || (usage=="parry");
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	object weapon;

	if( !objectp(weapon = me->query_temp("weapon"))
	||	(string)weapon->query("skill_type") != "blade" )
		return notify_fail("���������һ�ѵ���������������\n");

	if( (int)me->query("jing") < 40 )
		return notify_fail("����������������ŵ�������������Ϣ��Ϣ�ɡ�\n");
        me->receive_damage("jing", 40);
	return 1;
}
int effective_level() { return 20;}

string *parry_msg = ({
       "$n��������һ�䣬$v��������ĺ����Ƶ�$N����������\n",
	"$n���ƶ�Ȼ���˼���ħ�⣬��$N�Ĺ��ƶ�ʱ����������\n",
});

string *unarmed_parry_msg = ({
       "$n��������һ�䣬$v��������ĺ����Ƶ�$N����������\n",
	"$n���ƶ�Ȼ���˼���ħ�⣬��$N�Ĺ��ƶ�ʱ����������\n",
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
	return -100;
}
int practice_bonus()
{
	return -50;
}
int black_white_ness()
{
	return 30;
}

string perform_action_file(string action)
{
        return __DIR__"bat-blade/" + action;
}


