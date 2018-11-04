// celestrike.c

inherit SKILL;

mapping *action = ({
        ([      "action":               
"$Nʹ��һ�С�������ʽ�������ƴ�������$n��$l",
                "dodge":                30,
                "parry":                10,
                "force":                100,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$Nʹ��һ�С�������ʽ�������ƻ���Ϊʵ����$n��$l",
                "dodge":                10,
                "parry":                30,
                "force":                100,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$Nʹ�������Ʒ���С����ʽ��������Ȱ�����$n��ǰ��һ������$n��$l",
                "dodge":                30,
                "parry":                10,
                "force":                50,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N˫��һ��ʹ����ѩ����ʽ������׼$n��$l�����ĳ�����",
                "dodge":                10,
                "parry":                30,
                "force":                60,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N���ƻ��˸�ȦȦ�������Ƴ���һ�С��������ķ�������$n$l",
                "dodge":                20,
                "parry":                30,
                "force":                140,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$Nʹ�����������Ƕϡ�������ɢ���ߴ�ͬʱ��$n��$l���ƹ���",
                "dodge":                70,
                "parry":                10,
                "force":                180,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����������һ�С����������졹˫�Ʋ����Ƴ�",
                "parry":                40,
                "force":                220,
                "damage_type":  "����"
        ]),
});

int valid_learn(object me)
{
        if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
                return notify_fail("���������Ʊ�����֡�\n");
        if( (int)me->query_skill("doomforce", 1) < 20 )
                return 
notify_fail("��Ĵ�Ѫ�񹦻���㣬�޷����������ơ�\n");
        if( (int)me->query("max_neili") < 100 )
                return notify_fail("�������̫�����޷����������ơ�\n");
        return 1;
}

int valid_enable(string usage) { return usage=="unarmed"; }

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if( (int)me->query("qi") < 30 )
                return notify_fail("������������ˣ���Ϣһ�������ɡ�\n");
        if( (int)me->query("neili") < 5 )
                return notify_fail("������������ˣ���Ϣһ�������ɡ�\n");
        me->receive_damage("qi", 30);
        me->add("neili", -5);
        return 1;
}
int effective_level() { return 10;}
 
string *parry_msg = ({
        "$n����Ϊ����һ�С���Ѫ��ָ��������$N����$w���֡�\n",
        "$n˫�ƽ���ʹ��һ�С�ͯ�Ӱ��١�����ž����һ����$N��$w����˫��֮�䡣\n",
        "$n��һת��һ�С���������������$N����$w���֡�\n",
        "$nʹ����ճ���־���˫��һ������ƫ��$N��$w��\n",
});

string *unarmed_parry_msg = ({
        "$n�������ǣ�һ�С�����Ϊ��������ĳ�ʮ���ƣ��Ƶ�$N�����Ա���\n",
        "$n����Ϊָ��һ�С���ָ˫�ɡ�����$N������ҪѨ��\n",
        "$nʩչ������ָ˫�ɡ������赭д�Ļ�����$N�Ĺ��ơ�\n",
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
	return 10;
}
int practice_bonus()
{
	return 5;
}
int black_white_ness()
{
	return -10;
}


string perform_action_file(string action)
{
        return __DIR__"doomstrike/" + action;
}
