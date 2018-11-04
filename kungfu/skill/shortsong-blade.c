
inherit SKILL;

mapping *action = ({
	([	"action":		"$Nʹһ�С��ԾƵ��衹������$w���Ƶ���$n��$lնȥ��",
		"damage":		70,
		"dodge":		70,
		"damage_type":	"����"
	]),
	([	"action":		"$N�䵶���£�$w����һ�С��������Ρ����¶�������$n��$l",
		"damage":		40,
		"damage_type":	"����"
	]),
	([	"action":		"$N����һת��һ�С�Ʃ�糯¶��$w�糯¶��˸��ն��$n��$l",
		"damage":		20,
		"damage_type":	"����"
	]),
	([	"action":		"$N�趯$w��һ�С�ȥ�տ�ࡹ��$n��$lбб����һ��",
		"damage_type":	"����"
	]),
	([	"action":		"$N����$wһ�Σ�һ�С������Կ���Ѹ�����׵�����$n��$l",
		"damage":		70,
		"damage_type":	"����"
	]),
	([	"action":		"$N�����������զչ��һ�С���˼������ֱ��$n$l",
		"damage":		30,
		"damage_type":	"����"
	]),
	([	"action":		"$N�Ʋ�����ʹһ�С����Խ��ǡ��������ն��$n��$l",
		"damage":		50,
		"damage_type":	"����"
	]),
});

int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_neili") < 100 )
                return notify_fail("�������������û�а취���̸赶����\n");

//        if( (string)me->query_skill_mapped("force")!= "qidaoforce")
//                return notify_fail("�̸赶�����������ѩ�ڹ���������\n");

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

	if( (int)me->query("qi") < 40 )
		return notify_fail("����������������ŵ�������������Ϣ��Ϣ�ɡ�\n");
        me->receive_damage("qi", 40);
	return 1;
}
int effective_level() { return 20;}

string *parry_msg = ({
        "$nʹ��һ�С�Ψ�жſ����������е�$v����$N����ָ��\n",
	"$n���̤ǰһ����һ�С��������ơ������е�$v�Ӳ���Ʈ��$N֮�ؾȡ�\n",
	"$n���е�$vһ�������һƬ������һ�С��������ġ�������$N��ȫ��\n",
	"$n΢��һ�������е�$v����һ���⻡��һ�С���Ϊ���ʡ�����$N��ȫ��Χס��\n",
});

string *unarmed_parry_msg = ({
"$nʹ��һ�С��������񡹣������е�$v����$N��\n",
"$n���̤ǰ̤��һ�С�����¹���������е�$v����$N֮�ؾȡ�\n",
"$n���е�$vһ����һ�С�ɽ����ߡ�������$N��\n",
"$n���е�$v����һ�С����¹��ġ�����$N��ȫ��Χס��\n",
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
	return -20;
}
int practice_bonus()
{
	return -10;
}
int black_white_ness()
{
	return 30;
}

string perform_action_file(string action)
{
        return __DIR__"shortsong-blade/" + action;
}
