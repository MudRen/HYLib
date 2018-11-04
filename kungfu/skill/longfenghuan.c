// cloudstaff.c

inherit SKILL;

mapping *action = ({
        ([      "action":               
"$N���Ž𼦶���������չ������˫��������ʽ���������硹������$w����$n�ĵ��",
                "force":               500,
                "dodge":                500,
                "parry":                400,
                "post_action":  (: call_other, WEAPON_D, "bash_weapon" :),
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����$w������������¡¡������һ�С��������ˡ�����$n$l��",
                "force":               600,
                "dodge":                600,
                "parry":                200,
                "post_action":  (: call_other, WEAPON_D, "bash_weapon" :),
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����$w���һ�ӣ�ʹ������˫���еġ����ɷ��衹����$n$l��",
                "force":               500,
                "dodge":                100,
                "parry":                400,
                "post_action":  (: call_other, WEAPON_D, "bash_weapon" :),
                "damage_type":  "����"
        ]),
        ([      "action":               
"$Nʹ��һ�С��������졹��$w�����ŷ���ײ��$n$l��",
                "force":               800,
                "dodge":                100,
                "parry":                400,
                "post_action":  (: call_other, WEAPON_D, "bash_weapon" :),
                "damage_type":  "����"
        ]),
});

int valid_learn(object me)
{
        if( (int)me->query("str") + (int)me->query("max_neili") / 10 < 50 )
                return 
notify_fail("���������������Ҳ�����һ����������ǿ������\n");

        return 1;
}

int valid_enable(string usage)
{
        return (usage=="hammer") || (usage=="parry");
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        object weapon;

        if( !objectp(weapon = me->query_temp("weapon"))
        ||      (string)weapon->query("skill_type") != "hammer" )
                return 
notify_fail("���������һ˫�����������Ƶ�����������������˫����\n");

        if( (int)me->query("jing") < 60 )
                return 
notify_fail("�����������������˫������������Ϣ��Ϣ�ɡ�\n");
        me->receive_damage("jing", 60);
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
	return 0;
}
int practice_bonus()
{
	return -100;
}
int black_white_ness()
{
	return 10;
}


string perform_action_file(string action)
{
        return __DIR__"longfenghuan/" + action;
}

