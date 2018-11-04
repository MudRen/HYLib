// TIE@FY3
inherit SKILL;
mapping *action = ({
        ([      "action":               
"$NƮȻ�г���֮�⣬һ�С�����¶���¡�����$n��$l��",
                "damage":               60,
                "dodge":                40,
                "parry":                40,
                "damage_type":  "����"
        ]), 
        ([      "action":               
"$N��Х������ʹһ�С�ĺɫǧɽ�롹��˫����������$n��$l��",
                "damage":               60,
                "dodge":                20,
                "parry":                60,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$Nһ�С�����뺣�ϡ�������Ʈ�������̣�������$n��$lһ����",
                "damage":               80,
                "dodge":                10,
                "parry":                40,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N˫�ֺϻ���һ�С���ӿ��������Ȼ����$n��$l��",
                "damage":               200,
                "dodge":                -110,
                "parry":                -40,
                
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N��Ȼ����һת��һ�С����ƻ����ϡ���$n$l����ĳ�һ�ƣ�",
                "damage":               110,
                "dodge":                100,
                "parry":                200,
               
                "damage_type":  "����"
        ]),

});

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
	return notify_fail("������ȭ������֡�\n");
        return 1;
}

int valid_enable(string usage)
{
        return (usage=="unarmed") || (usage=="parry");
}
mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
         if( (int)me->query("jing") < 30 )
                return 
notify_fail("�����������������ȭ������������Ϣ��Ϣ�ɡ�\n");
        me->receive_damage("jing", 30);
        return 1;
}
int effective_level() { return 15;}
 
string *parry_msg = ({
        "$nȽȽ�ڿն�������һ�С�����ҹ��������$N������ʽ�����ڿմ���\n",
	
});

string *unarmed_parry_msg = ({
"$nȽȽ�ڿն�������һ�С�����ҹ��������$N������ʽ�����ڿմ���\n",
	
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
	return 30;
}
int practice_bonus()
{
	return -30;
}
int black_white_ness()
{
	return 320;
}


string perform_action_file(string action)
{
        return __DIR__"luoriquan/" + action;
}

