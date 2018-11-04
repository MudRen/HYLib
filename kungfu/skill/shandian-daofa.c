//  shandian-daofa���絶��

inherit SKILL;

mapping *action = ({
([      "action" : "$N��Ӱ��˫�����⸡����ת��������9������$n��$l��ȥ",
        "force" : 380,
        "dodge" : 10,
        "parry" : 5,
        "damage": 150,
        "lvl" : 0,
        "skill_name" : "���絶��",
        "damage_type" : "����"
]),
([      "action" : "$N����ﵶ����$n���ߣ�����֮�죬������˼������$w�Ѹ���$n���������",
        "force" : 430,
        "dodge" : 10,
        "parry" : 10,
        "damage": 200,
        "lvl" : 12,
        "skill_name" : "���絶��",
        "damage_type" : "����"
]),
 ([      "action" : "$N����$w����һ�٣����������ǻ��գ�����������ˢ��һ�����϶�����$n����",
        "force" : 540,
        "dodge" : 5,
        "parry" : 5,
        "damage": 125,
        "lvl" : 18,
        "skill_name" : "���絶��",
        "damage_type" : "����"
]),
([      "action" : "$N���ַ�ִ�������ᵶһն��$wֱ��$n�ľ��л�ȥ",
        "force" : 460,
        "dodge" : 5,
        "parry" : 5,
        "damage": 270,
        "lvl" : 24,
        "skill_name" : "���絶��",
        "damage_type" : "����",
]),
});

int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }
mapping query_action(object me, object weapon)
{
        int i, level;
        level   = (int) me->query_skill("shandian-daofa",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "blade")
                return notify_fail("��ʹ�õ��������ԡ�\n");
        if ((int)me->query("jingli") < 50)
                return notify_fail("����������������絶����\n");
        me->receive_damage("jingli", 35);
        return 1;
}

