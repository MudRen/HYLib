
inherit SKILL;

mapping *action = ({
        ([      "action":               
"$Nʹһ�С�����Σ¥��ϸϸ��������$w��һ��һ�����$n��$l",
                "dodge":                20,
		"force" :		100,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$Nʹ�����������еġ���ɫ�̹���������������հ�����$n��$l",
                "dodge":                20,
                "force":               200,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$Nһ�С�����˭��ƾ���⡹������$wĬĬ������$n��$l",
                "dodge":                30,
                "force":               50,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����$wһʽ��������ͼһ����׼$n��$lһ���̳��߽�",
                "force":                90,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N��$wƾ��һָ��һ�С��´������ղ��ڡ�����$n��$l",
                "dodge":                20,
                "force":               300,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����$w����һ�֣�ʹһ�С�Ϊ���������㲡����ֶ�׼$n$lһ����ȥ",
                "dodge":                20,
                "force":               100,
                "damage_type":  "����"
        ]),
});

int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_neili") < 50 )
                return notify_fail("�������������û�а취��������������\n");

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "sword" )
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
        ||      (int)me->query("neili") < 3 )
                return 
notify_fail("�����������������û�а취��ϰ������������\n");
        me->receive_damage("qi", 30);
        me->add("neili", -3);
        //write("�㰴����ѧ����һ�������������\n");
        return 1;
}

 
int effective_level() { return 23;}

string *parry_msg = ({
        "$nʹ��һ�С�������������е�$v������$N��$w��\n",
        "$nʹ������������ʡ�����$N��$w�������⡣\n",
        "$nʹ��һ�С�ǿ�ֻ���ζ�������е�$v����������գ�������$N��$w��\n",
        "$n���е�$vһ����һ�С��ԾƵ��衹����$N��$w��������ȥ��\n",
});

string *unarmed_parry_msg = ({
        "$n�����е�$v����ܲ�͸�磬һ�С����ǿ��Ϊ����ס��$N�Ĺ��ơ�\n",
        "$n����һ�С����������ޡ�����������ʧ��һ�Ž���֮�С�\n",
        "$nʹ��һ�С��м���ɫ�ԡ���$vֱ��$N��˫�֡�\n",
        "$n�����е�$vһ����һ�С��Ѿ��ִ��������ȵ�$N�������ˡ�\n",
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
	return 20;
}

string perform_action_file(string action)
{
        return __DIR__"deisword/" + action;
}
