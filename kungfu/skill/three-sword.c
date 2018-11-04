// three-sword.c

inherit SKILL;

mapping *action = ({
        ([      "action":               
"$Nʹ�����־��еġ����»�ת����$w�������֣���$n��$l����",
                "dodge":                20,
                "damage":               30,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N�����ճ����־��������е�$wʹ��һ�С�����ͻ�𡹣�ն��$n��$l",
                "dodge":                20,
                "damage":               30,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$Nʹ��һ�е��־��еġ�ɽˮ������������������ˮ������$w����̩ɽ��ն��$n��$l",
                "dodge":                40,
                "damage":               20,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$Nһʽ���־��еġ�ˮ�����项��׼$n��$l�̳�һ��",
                "dodge":                40,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����$wһ�����־��еġ�����ƽ�ȡ�����������������$n�̳�",
                "dodge":                40,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N˫���ս���һ�����־��еġ����ϲ���������$n��$l",
                "dodge":                420,
                "damage":               60,
                "damage_type":  "����"
        ]),
});

int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_neili") < 50 )
                return notify_fail("�������������û�а취�����Ž�����\n");

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
                return  notify_fail("�����������������û�а취��ϰ���Ž�����\n");
        me->receive_damage("qi", 30);
        me->add("neili", -3);
        //write("�㰴����ѧ����һ�����Ž�����\n");
        return 1;
}

 
int effective_level() { return 17;}

string *parry_msg = ({
        "$nʹ�����졹�־����Թ�Ϊ�ء����潣������$N�ȵ��������ˡ�\n",
        "$nʹ��һ�е��־��еġ��ض���ҡ�������е�$v������������$N��$w��\n",
        "$n����$N��$w��һ�����־��еġ��˷��ˡ��ҷ��ҡ�����$N��ͷ�Ͽ�ȥ��\n",
});

string *unarmed_parry_msg = ({
        "$n�����е�$v���������������ȵ�$N�������ˡ�\n",
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
	return -30;
}
int black_white_ness()
{
	return 30;
}

string perform_action_file(string action)
{
        return __DIR__"three-sword/" + action;
}

