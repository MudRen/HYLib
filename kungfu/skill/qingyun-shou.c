inherit SKILL;

mapping *action = ({
([	"action" : "$N��ǰһ����һʽ�����³�����������һ������������$n��$l",
        "force" : 70,
        "attack": 5,
        "dodge" : 38,
        "parry" : 38,
        "damage": 71,
        "lvl"   : 0,
        "skill_name" : "���³���",
        "damage_type" : "����"
]),
([	"action" : "$Nһʽ������ãã����˫���ͷ��ĳ���ͬʱ����$n����ǰ����ҪѨ",
        "force" : 95,
        "attack": 8,
        "dodge" : 43,
        "parry" : 43,
        "damage": 84,
        "lvl"   : 20,
        "skill_name" : "����ãã",
        "damage_type" : "����"
]),
([	"action" : "$Nʹһʽ��������ơ���˫�Ʒ׷ɣ������ĳ�����Ӱ��$n����ƽ�",
        "force" : 120,
        "attack": 13,
        "dodge" : 51,
        "parry" : 51,
        "damage": 88,
        "lvl"   : 40,
        "skill_name" : "�������",
        "damage_type" : "����"
]),
([	"action" : "$Nһʽ��ƽ�����ơ�������һ�ӣ���Ӱ����ʵʵ���ѱ���α����ȫ����$n",
        "force" : 140,
        "attack": 15,
        "dodge" : 65,
        "parry" : 65,
        "damage": 82,
        "lvl"   : 60,
        "skill_name" : "ƽ������",
        "damage_type" : "����"
]),
});

int valid_enable(string usage) { return usage == "hand" ||  usage == "parry"; }

int valid_combine(string combo) { return combo=="panyang-zhang"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("�������ֱ�����֡�\n");

        if (me->query_skill("force") < 20)
                return notify_fail("����ڹ���򲻹��������������֡�\n");

        if (me->query("max_neili") < 50)
                return notify_fail("�������̫�����޷��������֡�\n");


        return 1;
}

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i-1]["lvl"])
                        return action[i-1]["skill_name"];
}

mapping query_action(object me, object weapon)
{
        int i, level;
        level   = (int)me->query_skill("qingyun-shou", 1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 50)
                return notify_fail("�������̫���ˡ�\n");

        if ((int)me->query("neili") < 60)
                return notify_fail("�������������ϰ�����֡�\n");

        if (me->query_skill("qingyun-shou", 1) < 100)
                me->receive_damage("qi", 20);
        else
                me->receive_damage("qi", 30);

        me->add("neili", -40);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"qingyun-shou/"+ action;
}
