// hantian-chuixue-jian.c ���촵ѩ����

inherit SKILL;

mapping *action = ({
([      "action":"\nͻȻ֮�䣬��Ӱ���ϣ���������ѩ����$n����������ʱ�ֻص���ԭ�ء�",
        "force" : 50,
        "dodge" : 10,
        "parry": 50,
        "damage": 100,
        "lvl" : 0,
        "skill_name" : "��ӵ�к",
        "damage_type":  "����"
]),
([      "action":"\n$NͻȻ���з�һ�䣬$w�����������ʽƮ����ӯ��$n����֮�з������!",
        "force" : 50,
        "dodge" : 10,
        "parry" : 50,
        "damage": 150,
        "lvl" : 8,
        "skill_name" : "ѩ������",
        "damage_type":  "����"
]),
([      "action":"\n$N����Ʈ��������ѩ����裬�����䣬�����������Ʋ���$n�����!",
        "force" : 50,
        "dodge" : 10,
        "parry" : 50,
        "damage": 200,
        "lvl" : 15,
        "skill_name" : "ѩ���ȷ�",
        "damage_type":  "����"
]),
([      "action":"$Nһ����Ц�������Է紵��ѩ֮����$nϯ���ȥ��һ˲֮�䣬��$n����Ѳ���һ�ߣ�$w��
���ݳ�!",
        "force" : 100,
        "dodge" : 20,
        "parry" : 50,
        "damage": 200,
        "lvl" : 20,
        "skill_name" : "�绨ѩ��",
        "damage_type":  "����"
]),
([      "action":"$N����Ծ����̧��һ��������������ѩ������ֱ����£����ɵ�һ����",
        "force" : 100,
        "dodge" : 20,
        "parry" : 50,
        "damage": 200,
        "lvl" : 20,
        "skill_name" : "��ѩ����",
        "damage_type":  "����"
]),  
([      "action":"$NһХ���죬$n��ǰ�·�ͻȻ�����������$N�����콣��һ�����$n!",
        "force" : 100,
        "dodge" : 25,
        "parry" : 50,
        "damage": 300,
        "lvl" : 30,
        "skill_name" : "ѩӰ����",
        "damage_type":  "����"
]),
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 200)
                return notify_fail("�������������\n");
        if ((int)me->query_skill("force", 1) < 50)
                return notify_fail("��Ļ����ڹ����̫ǳ��\n");
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
        level   = (int) me->query_skill("chuixue-jian",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԡ�\n");
        if ((int)me->query("jing") < 100)
                return notify_fail("��ľ������������书��\n");
        if ((int)me->query("qi") < 100)
                return notify_fail("����������������书��\n");
        if ((int)me->query("neili") < 100)
                return notify_fail("����������������书��\n");
        me->receive_damage("qi", 50);
        me->receive_damage("jing", 50);
        me->add("neili", -50);
        return 1;
}
string perform_action_file(string action)
{
        return __DIR__"chuixue-jian/" + action;
}

