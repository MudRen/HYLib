// zhougong-jian.c �ܹ���
// By Vin

#include <ansi.h>

inherit SKILL;

mapping *action = ({
([      "action": "$N�ݲ���ǰ������$wбб�̳�����֪����·��Σ�Ҳ��֪�����η���$n��ȫ�޷��м�",
        "force" : 120,
        "attack": 41,
        "parry" : 40,
        "dodge" : 31,
        "damage": 110,
        "lvl"   : 0,
        "damage_type" : "����"
]),
([      "action": "$N����$w�͵ķ���ݳ����Ƶл��ȣ�����$n��$l",
        "force" : 140,
        "attack": 52,
        "parry" : 41,
        "dodge" : 42,
        "damage": 112,
        "lvl"   : 10,
        "damage_type" : "����"
]),
([      "action": "$N�治¶ɫ�����е�$w��$nֱֱ��ȥ, �⿴�ƺ�ƽ����һ�о�Ȼ���ž޴��ɱ��",
        "force" : 150,
        "attack": 58,
        "parry" : 45,
        "dodge" : 43,
        "damage": 120,
        "lvl"   : 20,
        "damage_type" : "����"
]),
([      "action": "$N����$w����������ó�����â, �Ƶ�$n��������",
        "force" : 170,
        "attack": 61,
        "parry" : 48,
        "dodge" : 48,
        "damage": 125,
        "lvl"   : 40,
        "damage_type" : "����"
]),
([      "action": "$N����$w��â��˸��������â�еݳ�ɱ�ţ���ȫ����$n����֮��",
        "force" : 190,
        "attack": 68,
        "parry" : 51,
        "dodge" : 50,
        "damage": 130,
        "lvl"   : 60,
        "damage_type" : "����"
]),
([      "action": "$N����$wбб�̳�������ʵʵ������$n���ܣ���ȫ������$n����·",
        "force" : 200,
        "attack": 71,
        "parry" : 55,
        "dodge" : 55,
        "damage": 135,
        "lvl"   : 80,
        "damage_type" : "����"
]),
([      "action": "$N����ڵ���һ����𣬰���е��ǧ���ǣ��ִ�$n����Ҫ��",
        "force" : 230,
        "attack": 78,
        "parry" : 60,
        "dodge" : 62,
        "damage": 140,
        "lvl"   : 100,
        "damage_type" : "����"
]),
([      "action": "$N����Ծ������$w�����������˸�Ľ���������������£���$n������",
        "force" : 250,
        "attack": 81,
        "parry" : 64,
        "dodge" : 65,
        "damage": 70,
        "lvl"   : 110,
        "damage_type" : "����"
]),
([      "action": "$N���лζ�����������$w�����������������Ѹ���ޱȵĺ�������$n",
        "force" : 280,
        "attack": 84,
        "parry" : 68,
        "dodge" : 75,
        "damage": 169,
        "lvl"   : 120,
        "damage_type" : "����"
]),
([      "action": "$N�����������$w����ʱ�ó���㽣â, ���ɽ����ӽ�â�еݳ���ֱ֪����$n",
        "force" : 300,
        "attack": 88,
        "parry" : 70,
        "dodge" : 78,
        "damage": 180,
        "lvl"   : 130,
        "damage_type" : "����"
]),
([      "action": "$N����$wңָ���죬��â���²�����һʽ�����Χ��������׼$n��$lֱ���ȥ",
        "force" : 330,
        "attack": 91,
        "parry" : 72,
        "dodge" : 85,
        "damage": 88,
        "lvl"   : 140,
        "damage_type" : "����"
]),
([      "action": "$Nһʽ�������®����ֻ��$wͻȻ���������һ��ǿ��Ľ���ϯ��$nȫ��",
        "force" : 350,
        "attack": 94,
        "parry" : 72,
        "dodge" : 85,
        "damage": 100,
        "lvl"   : 150,
        "damage_type" : "����"
]),
([      "action": HIW "$N" HIW "һ�����ȣ�����Ȼ�ӿ죬���н�â���²��������⻯������"
                  "����������$w" HIW "�����һ��ݳ���\n" NOR "$n�ۼ���ͻ��������һ������"
                  "�����ң���ȫ��֪������εֵ����������ˣ����һ��ǿ��Ľ���\n����ӿ����",
        "force" : 470,
        "attack": 138,
        "dodge" : -167,
        "parry" : -135,
        "damage": 280,
        "lvl"   : 250,
        "damage_type": "����"
]),
});

int valid_enable(string usage)
{
        return usage == "sword" || usage == "parry";
}

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 1200)
                return notify_fail("��������������޷�ѧϰ�ܹ�����\n");

        if ((int)me->query_skill("force", 1) < 100)
                return notify_fail("����ڹ���򲻹����޷�ѧϰ�ܹ�����\n");

        if ((int)me->query_skill("sword", 1) < 100)
                return notify_fail("��Ļ���������򲻹����޷�ѧϰ�ܹ�����\n");

        if ((int)me->query_skill("sword", 1) < (int)me->query_skill("zhougong-jian", 1))
                return notify_fail("��Ļ�������ˮƽ���ޣ��޷�����������ܹ�����\n");

        if ((int)me->query_skill("force", 1) < (int)me->query_skill("zhougong-jian", 1))
                return notify_fail("��Ļ����ڹ�ˮƽ���ޣ��޷�����������ܹ�����\n");

        return 1;
}

mapping query_action(object me, object weapon)
{
        int i, level;
        level = (int) me->query_skill("zhougong-jian", 1);
        for (i = sizeof(action); i > 0; i--)
                if (level > action[i - 1]["lvl"])
                        return action[NewRandom(i, 20, level / 5)];
}

int practice_skill(object me)
{
        object weapon;
        if (! objectp(weapon = me->query_temp("weapon"))
           || (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԡ�\n");

        if ((int)me->query("qi") < 60)
                return notify_fail("��������������ܹ�����\n");

        if ((int)me->query("neili") < 100)
                return notify_fail("��������������ܹ�����\n");

        me->receive_damage("qi", 50);
        me->add("neili", -100);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"zhougong-jian/" + action;
}
int query_effect_parry(object attacker, object me)
{
        int lvl;
        object weapon;

        if (! objectp(weapon = me->query_temp("weapon")))
                return 0;
                
        if ((string)weapon->query("skill_type") != "sword") 
                return 0;
                
        lvl = me->query_skill("zhougong-jian", 1);
        if (lvl < 80)  return 0;
        if (lvl < 200) return 50;
        if (lvl < 280) return 80;
        if (lvl < 350) return 100;
        return 120;
}
