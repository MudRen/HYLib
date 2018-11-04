// luoying.c

inherit SKILL;

mapping *action = ({
    ([  "action":       "$Nʹһ�С���Ӣ�ͷס���˫��Ʈ�Ʋ�������$n$l",
        "dodge": 30,
        "parry": 20,
        "force": 120,
        "damage_type": "����"
	]),
    ([  "action":       "$Nٿ������$n��ǰ��һ�С������һ���ֱ��$n��$l",
        "dodge": -20,
        "parry": -20,
        "force": 160,
        "damage_type": "����"
    ]),
    ([  "action":       "$N������$nһת��һ�С��������꡹��$n$l��������",
        "dodge":  25,
        "parry":  20,
        "force": 200,
        "damage_type": "����"
	]),
    ([  "action":       "$N���ΰ����ڰ��һ�С����Ƿɻ��������ͻ�$n��$l",
        "dodge": -30,
        "parry": -30,
        "force": 240,
        "damage_type": "����"
	]),
    ([  "action":       "$Nʹһ�С������䡹����������ֱ��$n��$l",
        "dodge": -20,
        "parry":  40,
        "force": 280,
        "damage_type": "����"
    ]),
    ([  "action":       "$Nһ�����ʹ�������컨�꡹���ó�������Ӱ�����Ʋ���$n��$l",
        "dodge":  40,
        "force": 340,
        "damage_type": "����"
    ]),
});

int valid_enable(string usage) { return usage=="unarmed" ||  usage=="parry"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("����Ӣ���Ʊ�����֡�\n");
	if ((int)me->query("max_neili") < 100)
        return notify_fail("�������̫�����޷�����Ӣ���ơ�\n");
	return 1;
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 40)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 10)
        return notify_fail("������������ˣ���Ϣһ�������ɡ�\n");
	me->receive_damage("qi", 30);
	me->add("neili", -5);
	return 1;
}

