// liehuo-jian.c �һ�

inherit SKILL;

mapping *action = ({
([      "action" : "$Nһ�С��ĺ���Ʈ����$w�ƻó�ƬƬ���ƣ�����˷�������$n",
        "force" : 170,
        "dodge" : 15,
        "damage" : 120,
        "lvl" : 0,
        "skill_name" : "�ĺ���Ʈ",
        "damage_type" : "����"
]),
([      "action" : "$Nһ�С���ͨ�˴��������ָ������$n��$n�������ֱܷ�$w����·",
        "force" : 190,
        "dodge" : 10,
        "damage" : 130,
        "lvl" : 19,
        "skill_name" : "��ͨ�˴�",
        "damage_type" : "����"
]),
([      "action" : "$Nʹ��������һ������$w��һ������������һ�ɺ�������$n��$l",
        "force" : 110,
        "dodge" : 10,
        "damage" : 140,
        "lvl" : 29,
        "skill_name" : "����һ��",
        "damage_type" : "����"
]),
([      "action" : "$N�������ϵ���������ָ��һ�С���������������$w����һ�Ž���������$n��$l",
        "force" : 130,
        "dodge" : 5,
        "damage" : 150,
        "lvl" : 39,
        "skill_name" : "��������",
        "damage_type" : "����"
]),
([      "action" : "$Nһ�С����ٵ����������Ծ����أ�����$w�ó�һ��ѩ�׵��ٲ���ɨ��$n��$l",
        "force" : 150,
        "dodge" : 5,
        "damage" : 160,
        "lvl" : 59,
        "skill_name" : "���ٵ���",
        "damage_type" : "����"
]),
([      "action" : "$N���Ȱ�����ף�$wƽָ��һ�С�������ɫ��������������ɫ�������Ĵ���$n��$l",
        "force" : 170,
        "dodge" : 15,
        "damage" : 170,
        "lvl" : 79,
        "skill_name" : "������ɫ",
        "damage_type" : "����"
]),
([  "action" : "$Nһ�С��򴨹麣����$w��$n��������裬��$n�ۻ����ң������ڰ����ͻȻͣס����$n��$l",
        "force" : 300,
        "dodge" : 5,
        "damage" : 280,
        "lvl" : 99,
        "skill_name" : "�򴨹麣",
        "damage_type" : "����"
]),
});


int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }

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
        level   = (int) me->query_skill("liehuo-jian",1);
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
        if ((int)me->query("jing") < 50)
                return notify_fail("��������������һ𽣷���\n");
        me->receive_damage("jing", 30);
        return 1;
}
string perform_action_file(string action)
{
        return __DIR__"liehuo-jian/" + action;
}
