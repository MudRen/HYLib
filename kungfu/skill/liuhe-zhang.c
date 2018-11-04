inherit SKILL;

mapping *action = ({
([      "action" : "$Nһ�С����ƻ�����������ƽ�ƻ��ƶ�������Ȼ����$n��$l",
        "force"  : 33,
        "dodge"  : 5,
        "parry"  : 2,
        "attack" : 2,
        "damage" : 111,
        "lvl"    : 0,
        "skill_name" : "���ƻ���",
        "damage_type": "����"
]),
([      "action" : "$Nʹһ�С��������졹�����ֻ���һ��Ȧ�ӣ����ֻӳ�������$n��$l",
        "force"  : 45,
        "dodge"  : 18,
        "parry"  : 17,
        "attack" : 6,
        "damage" : 114,
        "lvl"    : 20,
        "skill_name" : "��������",
        "damage_type": "����"
]),
([      "action" : "$N�����ɹ����ƣ�ʹһ�С�������Ӱ�������Ƶ�ʱ��ɨ$n��$l",
        "force"  : 51,
        "dodge"  : 16,
        "parry"  : 19,
        "attack" : 11,
        "damage" : 117,
        "lvl"    : 40,
        "skill_name" : "������Ӱ",
        "damage_type": "����"
]),
([      "action" : "$N˫�ֻ������������ϣ��������£�ʹһ�С�������ɽ������$n������",
        "force"  : 62,
        "dodge"  : 24,
        "parry"  : 21,
        "attack" : 15,
        "damage" : 119,
        "lvl"    : 60,
        "skill_name" : "������ɽ",
        "damage_type": "����"
]),
([      "action" : "$N���ֻ���һ����Ȧ��ʹһ�С�����������������$n��$l",
        "force"  : 75,
        "dodge"  : 24,
        "parry"  : 28,
        "attack" : 19,
        "damage" : 111,
        "lvl"    : 80,
        "skill_name" : "��������",
        "damage_type": "����"
]),
([      "action" : "$N˫�ֺ��ƣ�ʹһ�С����ƿ��塹��˫�Ʒֱ���$n��$l��ȥ",
        "force"  : 90,
        "dodge"  : 28,
        "parry"  : 30,
        "attack" : 21,
        "damage" : 114,
        "lvl"    : 100,
        "skill_name" : "���ƿ���",
        "damage_type": "����"
]),
});

int valid_enable(string usage)
{
        return usage == "strike" || usage == "parry";
}

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("�������Ʒ�������֡�\n");

        if ((int)me->query_skill("force") < 30)
                return notify_fail("����ڹ���򲻹����޷�ѧ�����Ʒ���\n");

        if ((int)me->query("max_neili") < 100)
                return notify_fail("�������̫�����޷��������Ʒ���\n");


        return 1;
}

string query_skill_name(int level)
{
        int i;
        for (i = sizeof(action) - 1; i >= 0; i--)
            if (level >= action[i]["lvl"])
                return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
        int i, level;
        level = (int) me->query_skill("liuhe-zhang", 1);
        for (i = sizeof(action); i > 0; i--)
            if (level > action[i-1]["lvl"])
                return action[NewRandom(i, 5, level / 5)];
}

int practice_skill(object me)
{
        if( (int)me->query("qi") < 60 )
                return notify_fail("����������������Ϣһ�������ɡ�\n");

        if( (int)me->query("neili") < 50 )
                return notify_fail("������������������Ʒ���\n");

        me->receive_damage("qi", 48);
        me->add("neili", -42);

        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"liuhe-zhang/" + action;
}
