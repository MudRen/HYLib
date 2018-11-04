// tenderzhi.c

inherit SKILL;

mapping *action = ({
        ([      "action":               
"$N˫��һ�ӣ�һ�С��������졹���ֻ���$n$l",
                "dodge":                -30,
                "parry":                30,
                "force":                80,
                "damage_type":  "����",
        ]),
        ([      "action":               
"$N��Ӱ���죬ʹһ�С�����ͻ�֡���ת��������$n��$l��ȥ",
                "dodge":                -30,
                "parry":                30,
                "force":                90,
                "damage_type":  "����",
        ]),
        ([      "action":               
"$N���κ�Ȼƽ�ذ���˫��ɢ��������Ӱ��һ�С�������β����$n��$l��ȥ",
                "dodge":                -30,
                "parry":                30,
                "force":                140,
                "damage_type":  "����",
        ]),
        ([      "action":               
"ֻ��$N˫��һ�ڣ�˳������һ�С������㾦����$n��$l��ȥ",
                "dodge":                -30,
                "parry":                30,
                "force":                90,
                "damage_type":  "����",
                "weapon":               "����ʳָ",
        ]),
});

int valid_learn(object me)
{
        if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
                return notify_fail("������̽���ֱ�����֡�\n");
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
        if( (int)me->query("jing") < 30 )
                return notify_fail("��ľ����޷������ˣ���Ϣһ�������ɡ�\n");
        if( (int)me->query("neili") < 10 )
                return notify_fail("������������ˡ�\n");

        me->receive_damage("jing", 30);
        me->add("neili", -10);

        return 1;
}
 
int effective_level() { return 14;}

string *parry_msg = ({
        "$n˫�ּ�ץ$N������$N���е�$w�������ֶ�����\n",
});

string *unarmed_parry_msg = ({
        "$n�����ָ�������㣬ָ��ֱ��$N�������Ѩ��\n",
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
	return 0;
}
int black_white_ness()
{
	return 0;
}


string perform_action_file(string action)
{
        return __DIR__"flying-dragon/" + action;
}
