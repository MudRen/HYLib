// lieyan-dao.c ���浶

inherit SKILL;

mapping *action = ({
([      "action" : "$Nһ�С�����������$w����һ��������$n���������Σ�����������仯����",
        "force" : 180,
        "dodge" : 10,
        "damage" : 120,
        "lvl" : 0,
        "skill_name" : "��������",
        "damage_type" : "����"
]),
([      "action" : "$Nһ�С���ˮǧɽ����������һǰһ��$w����������$n��$lնȥ",
        "force" : 190,
        "dodge" : 10,
        "damage" : 130,
        "lvl" : 8,
        "skill_name" : "��ˮǧɽ",
        "damage_type" : "����"
]),
([      "action" : "$N����Ծ�䣬һ�С���ɨǧ���$w���ż������һ������$n��ɨ��ȥ",
        "force" : 110,
        "dodge" : 5,
        "damage" : 140,
        "lvl" : 16,
        "skill_name" : "��ɨǧ��",
        "damage_type" : "����"
]),
([      "action" : "$Nһ�С����ҿ�������$w�󿪴��أ����Ҳ�������һ������һ����$n�����翳��",
        "force" : 130,
        "dodge" : 5,
        "damage" : 150,
        "lvl" : 24,
        "skill_name" : "���ҿ���",
        "damage_type" : "����"
]),
([      "action" : "$N����$w���϶��£�һ�С����ɷ��١���������к����һƬѩ���ٲ�����$n��ͷ��",
        "force" : 150,
        "dodge" : 10,
        "damage" : 160,
        "lvl" : 33,
        "skill_name" : "���ɷ���",
        "damage_type" : "����"
]),
([      "action" : "$N����$w��ʹ��һ�С�ֱ���������������ã����ҿ�����ǧ�����������$n",
        "force" : 170,
        "dodge" : 5,
        "damage" : 170,
        "lvl" : 42,
        "skill_name" : "ֱ������",
        "damage_type" : "����"
]),
([      "action" : "$N���õ��羢����һ�С�����������һ����ת������������$n��$l����ȥ",
        "force" : 190,
        "dodge" : 5,
        "damage" : 180,
        "lvl" : 51,
        "skill_name" : "��������",
        "damage_type" : "����"
]),
([      "action" : "$N��ǰһ��������һ�С��ϲ���ɽ����$wֱֱ��������һƬ�����ĵ�Ӱ��$n��ȫ����ȥ",
        "force" : 320,
        "dodge" : 5,
        "damage" : 300,
        "lvl" : 60,
        "skill_name" : "�ϲ���ɽ",
        "damage_type" : "����"
]),
});


int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 100)
                return notify_fail("�������������\n");
        if ((int)me->query_skill("jiuyang-shengong", 1) < 20)
                return notify_fail("��ľ����񹦻��̫ǳ��\n");
        return 1;
}

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
        int i, level;
        level   = (int) me->query_skill("lieyan-dao",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        object weapon;
        int lvl = me->query_skill("lieyan-dao", 1);
        int i = sizeof(action);
        while (i--) if (lvl == action[i]["lvl"]) return 0;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "blade")
                return notify_fail("��ʹ�õ��������ԡ�\n");
        if ((int)me->query("jing") < 50)
                  return notify_fail("��ľ������������浶��\n");
        me->receive_damage("jing", 25);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"lieyan-dao/" + action;
}
