// liuh-ken.c

inherit SKILL;

mapping *action = ({
	([	"action":		"$Nʹһ�С�������ѡ�����׼$n��$l��ƮƮ��ɨȥ",
		"dodge":		-20,
		"parry":		20,
		"damage_type":	"����"
	]),
	([	"action":		"$N�������֣�һ�С��������ۡ�����$n��$l��ȥ",
		"dodge":		-10,
		"parry":		10,
		"damage_type":	"����"
	]),
	([	"action":		"$N������Σ����֡�������¥����$n��$l����",
		"dodge":		-20,
		"parry":		20,
		"damage_type":	"����"
	]),
        ([      "action":               "$N����΢�֣�����һ��ʹ��һ�С����ֻ�ʱ����ץ��$n��$l",
                "dodge":                -50,
                "parry":                -30,
                "force":                100,
                "damage_type":  "ץ��"
        ]),
        ([      "action":               "$Nٿ��һ��ת��˫��һ����һ����˼��ֱ��$n$l",
                "dodge":                -10,
                "parry":                -60,
                "force":                110,
                "damage_type":  "����"
        ]),
        ([      "action":               "$N������Σ�����ƮƮ��һ�С������г����$n$l",
                "dodge":                -20,
                "parry":                -50,
                "force":                150,
                "damage_type":  "����"
        ]),
        ([      "action":               "$N������$n$l����������һ�С�����üͷ����צ����ͬһ��λץ��",
                "parry":                -50,
                "force":                60,
                "damage_type":  "ץ��"
        ]),
        ([      "action":               "$N������Σ������ճ�ȭ��һ�С�ȴ����ͷ������$n$l",
                "dodge":                -20,
                "parry":                -50,
                "force":                150,
                "damage_type":  "����"
        ]),
});

int valid_learn(object me)
{
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("��һ��÷���ֱ�����֡�\n");
	return 1;
}

int valid_enable(string usage)
{
	return usage=="unarmed";
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if( (int)me->query("qi") < 30 )
		return notify_fail("������������ˣ���Ϣһ�������ɡ�\n");
	me->receive_damage("qi", 30);
	return 1;
}
int effective_level() { return 15;}

string *parry_msg = ({
        "$nһ�С���ź�����������������$N�����ţ��Ƶ�$N��;�������е�$w��\n",
        "$n������ϣ�����һ�С�����˭�Ľ����������Ƶ�$N����������\n",
        "$n����Ϊ����һ�С�����Ʈ��ˮ�����������$N��$w������\n",
        "$nһ�С������޼ƿ�������������һ��$N��$w���֣���ƫ��$N��$w��\n",
});

string *unarmed_parry_msg = ({
        "$nһ�С�����Ũ�Ƴ����硹���Ƶ�$N��;���С�\n",
        "$n����������һ�С�����Ѿƻƻ�󡹣���$N֮�ؾȡ�\n",
        "$n���ַ��£�����һ�С�����Ʈ��ˮ����������$N���ڳ��⡣\n",
        "$n˫�������ʹ��һ�С������޼ƿ���������$N�Ĺ�������ţ�뺣����ʧ����Ӱ���١�\n",

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
	return -20;
}
int black_white_ness()
{
	return 30;
}


string perform_action_file(string action)
{
        return __DIR__"meihua-shou/" + action;
}
