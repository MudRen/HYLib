// celestrike.c

inherit SKILL;

mapping *action = ({
        ([      "action":               
"$Nʹ��һ�С����ÿ�硹�����ƴ����´�������$n��$l",
                "dodge":                30,
                "parry":                10,
                "force":                200,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$Nʹ��һ�С����ͻϮ�������ƻ���Ϊʵ����$n��$l",
                "dodge":                10,
                "parry":                30,
                "force":                70,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$Nʹ���÷��Ʒ����綯��ͥ�����εض���$n��ǰ��һ������$n��$l",
                "dodge":                30,
                "parry":                10,
                "force":                50,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N˫��һ��ʹ�������꽻�ӡ�����׼$n��$l�ĳ�һ����Ӱ",
                "dodge":                10,
                "parry":                30,
                "force":                60,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N���ƻ��˸�ȦȦ�������Ƴ���һ�С����ɨҶ������$n$l",
                "dodge":                20,
                "parry":                30,
                "force":                140,
                "damage_type":  "����"
        ]),
});

int valid_learn(object me)
{
        if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
                return notify_fail("���÷��Ʊ�����֡�\n");
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
        "$n����Ϊ����һ�С�������¡�����$N����$w���֡�\n",
        "$n��һת��һ�С��綯���ҡ�����$N����$w���֡�\n",
        "$nʹ����ճ���־���˫��һ������ƫ��$N��$w��\n",
});

string *unarmed_parry_msg = ({
        "$n����Ϊָ��һ�С����ŭХ������$N������ҪѨ��\n",
        "$nʩչ�������ŭ�𡹣����赭д�Ļ�����$N�Ĺ��ơ�\n",
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
        return __DIR__"pofeng-strike/" + action;
}
