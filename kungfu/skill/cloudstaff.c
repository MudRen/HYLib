// cloudstaff.c

inherit SKILL;

mapping *action = ({
        ([      "action":               
"$Nʹһ�С����է�֡�������$wɨ��$n���̣�",
                "damage":               40,
                "dodge":                40,
                "parry":                -40,
                "post_action":  (: call_other, WEAPON_D, "bash_weapon" :),
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����$w��һ�С�������硹����$n$l��",
                "damage":               40,
                "dodge":                20,
                "parry":                60,
                "post_action":  (: call_other, WEAPON_D, "bash_weapon" :),
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N�������$w��ʹ��������д�⡹����$n$l��",
                "damage":               40,
                "dodge":                10,
                "parry":                40,
                "post_action":  (: call_other, WEAPON_D, "bash_weapon" :),
                "damage_type":  "����"
        ]),
        ([      "action":               
"$Nʹ��һ�С��������ơ���$wһͦײ��$n$l��",
                "damage":               40,
                "dodge":                10,
                "parry":                40,
                "post_action":  (: call_other, WEAPON_D, "bash_weapon" :),
                "damage_type":  "����"
        ]),
});

int valid_learn(object me)
{
        if( (int)me->query("str") + (int)me->query("max_neili") / 10 < 35 )
                return 
notify_fail("���������������Ҳ�����һ����������ǿ������\n");

        return 1;
}

int valid_enable(string usage)
{
        return (usage=="staff") || (usage=="parry");
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        object weapon;

        if( !objectp(weapon = me->query_temp("weapon"))
        ||      (string)weapon->query("skill_type") != "staff" )
                return 
notify_fail("���������һ��ľ�Ȼ��������Ƶ��������������ȷ���\n");

        if( (int)me->query("qi") < 60 )
                return 
notify_fail("������������������ȷ�����������Ϣ��Ϣ�ɡ�\n");
        me->receive_damage("qi", 60);
        return 1;
}
int effective_level() { return 20;}
 
string *parry_msg = ({
        "���$n�����е�$v����$N��$w��\n",
});

string *unarmed_parry_msg = ({
        "$n�����е�$v����ܲ�͸�磬��ס��$N�Ĺ��ơ�\n",
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
	return 40;
}


string perform_action_file(string action)
{
        return __DIR__"cloudstaff/" + action;
}