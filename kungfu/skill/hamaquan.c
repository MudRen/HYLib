inherit SKILL;

mapping *action = ({
([  "action" : "$Nһʽ���������𡹣����ƻ�צ����Ϯ$n����������·Ҫ��",  
    "force" : 120,
    "dodge" : 5,
    "damage": 15,
    "lvl" : 0,
    "skill_name" : "��������",
    "damage_type" : "����"
]),
([  "action" : "$N������Σ�������ǰ���󣬷���$n�ļ羮��Ѩ",
    "force" : 130,
    "dodge" : 10,
    "damage": 20,
    "lvl" : 8,
    "skill_name" : "���ֵ�Ѩ",
    "damage_type" : "����"
]),
([  "action" : "$Nʹһʽ��ǰհ�����������Ƹ��״����׶�������������$n",
    "force" : 150,
    "dodge" : 15,
    "damage": 20,
    "lvl" : 30,
    "skill_name" : "ǰհ����",
    "damage_type" : "����"
]),
([  "action" : "$Nʹһʽ��������Ӱ��������˷�����������Ӱ��һȭ����$n
���ؿ�",
    "force" : 220,
    "dodge" : 25,
    "damage": 35,
    "lvl" : 70,
    "skill_name" : "������Ӱ",
    "damage_type" : "����"
]),
([  "action" : "$N���ֳ�צ��ȫ�������죬һʽ���޵и�󡡹������$n��$l",
    "force" : 270,
    "dodge" : 30,
    "damage": 40,
    "lvl" : 98,
    "skill_name" : "�޵и��",
    "damage_type" : "����"
])
});
int valid_enable(string usage) { return usage=="unarmed" || usage=="parry"; }      
int valid_learn(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
   return notify_fail("�����ȭ������֡�\n");
    if ((int)me->query_skill("hamagong", 1) < 20)
   return notify_fail("��ĸ�󡹦��򲻹����޷�ѧ���ȭ��\n");
    if ((int)me->query("max_neili") < 100)
   return notify_fail("�������̫�����޷������ȭ�֡�\n");
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
    level = (int)me->query_skill("hamaquan", 1);
    for(i = sizeof(action); i > 0; i--)
    if(level > action[i-1]["lvl"])
      return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
    if ((int)me->query("qi") < 30)
   return notify_fail("�������̫���ˡ�\n");
    if ((int)me->query("neili") < 20)
   return notify_fail("����������������ȭ��\n");
    me->receive_damage("qi", 25);
    me->add("neili", -5);
    return 1;
}
string perform_action_file(string action)
{
	return __DIR__"hamaquan/" + action;
}

