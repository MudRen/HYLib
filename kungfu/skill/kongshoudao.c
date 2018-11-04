// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit SKILL;
mapping *action = ({
        ([      "action":               
"$N������ǰ�������ں�˫��������$n��$l����",
                "dodge":                30,
                "parry":                10,
                "damage":                50,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N��ŵ�أ����������ת�������򼲷�ɨ��Ҷ��ɨ��$n��$l",
                "dodge":                10,
                "parry":                30,
                "damage":                50,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N������Σ�����������벻���ĽǶ�ײ����$n��$l",
                "dodge":                30,
                "parry":                10,
                "damage":                80,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N�ҽ���գ��γ�һƬ��Ӱ�����Ǽ���$n��$lһ���߳�����",
                "dodge":                10,
                "parry":                30,
                "damage":                70,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N���Ծ���������ת��˫�Ŵ�������һǰһ�������$n��$l",
                "dodge":                20,
                "parry":                30,
                "damage":                60,
                "damage_type":  "����"
        ]),
});

int valid_learn(object me)
{
        if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
                return notify_fail("�����ֵ�������֡�\n");
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
        "$n����һ����˫��һ�ŵأ�ȫ����$N��$w�Ĺ�����Χ��\n",
});

string *unarmed_parry_msg = ({
        "$n����һ����˫��һ�ŵأ�ȫ����$N�Ĺ�����Χ��\n",
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
           return __DIR__"kongshoudao/" + action;
}

