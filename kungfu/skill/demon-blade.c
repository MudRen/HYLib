// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit SKILL;
mapping *action = ({
	([	"action":		"$Nʹ����ħ��ʽ�е�����ʽ����ħ���ѡ������е�$w����һ���âն��$n��$l",
		"force":		500,
		"damage_type":	"����"
	]),
	([	"action":		"$N��һ����һ�С�ħ�����ɡ����е�$w�ó�һƬ������ɢ��$n��$l",
		"force":		300,
		"damage_type":	"����"
	]),
	([	"action":		"$N�����ת�����е�$wһ�С�ħ��է�֡������������$n��$l",
		"force":		200,
		"damage_type":	"����"
	]),
	([	"action":		"$N��Ӱ�ζ������������ң�һ�С���ħ���𡱣����е�$w������·ͻȻ����$n��$l",
		"force":		300,
		"damage_type":	"����"
	]),
	([	"action":		"$N��˫�ŵ�أ���������һ�С�������ħ��ȫ��ת��һ�ŵ������$n",
		"force":		200,
		"damage_type":	"����"
	]),
	([	"action":		"$N�������ϣ�һ�С���ħ���족����һ��$n���벻���ĽǶ�����$n��$l",
		"force":		200,
		"damage_type":	"����"
	]),
	([	"action":		"$N�����е�$w���ҺỮ��һ�С���ħ���֡��������ػصؿ�ɨ��$n��$l",
		"force":		100,
		"damage_type":	"����"
	]),
        ([      "action":               "$Nʹ��������ħ������ʽ�е�����ʽ����ħ���ڡ������е�$wѸ���ޱȵؿ���$n��$l",
                "force":                500,
                "damage_type":  "����"
        ]),
});

int valid_learn(object me)
{
        if( (int)me->query_skill("demon-force", 1) < 60 )
                return
		notify_fail("��������ħ�ķ�����㣬�޷���������ħ������ʽ��\n");
	return 1;
}

int valid_enable(string usage)
{
	return (usage=="blade") || (usage=="parry");
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	object weapon;

	if( !objectp(weapon = me->query_temp("weapon"))
	||	(string)weapon->query("skill_type") != "blade" )
		return notify_fail("���������һ�ѵ���������������\n");

	if( (int)me->query("qi") < 40 )
		return notify_fail("����������������ŵ�������������Ϣ��Ϣ�ɡ�\n");
	me->receive_damage("qi", 40);
	return 1;
}
int effective_level() { return 20;}

string *parry_msg = ({
	"$nʹ����ħ������ʽ�еġ�ħ���ޱߡ������е�$v���ɾ��ص�Ļ��סȫ��\n",
});

string *unarmed_parry_msg = ({
        "$nʹ����ħ������ʽ�еġ�ħ���ޱߡ������е�$v���ɾ��ص�Ļ��סȫ��\n",
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
	return -5;
}
int black_white_ness()
{
	return 20;
}

string perform_action_file(string action)
{
    return __DIR__"demon-blade/" + action;
}

