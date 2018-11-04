// yingzhua-gong.c -ӥצ��
// modified by Venus Oct.1997

inherit SKILL;

mapping *action = ({
([      "action" : "$Nȫ��εض��𣬰����һ�����һʽ����ӥϮ�á���Ѹ�͵�ץ��
$n��$l",
    "force" : 100,
    "dodge" : 15,
    "parry" : 15,
    "lvl" : 0,
    "skills_name" : "��ӥϮ��",
    "damage_type" : "����"
]),
([      "action" : "$N����ֱ����˫��ƽ�죬һʽ����ӥչ�᡹��˫צһǰһ��£��$n��
$l",
    "force" : 120,
    "dodge" : 20,
    "parry" : 20,
    "damage": 5,
    "lvl" : 10,
    "skills_name" : "��ӥչ��",
    "damage_type" : "����"
]),
([      "action" : "$Nһʽ���γ��ɡ���ȫ����б��ƽ�ɣ�����һ����˫צ����$n�ļ�
ͷ",
    "force" : 150,
    "dodge" : 30,
    "parry" : 30,
    "damage": 30,
    "lvl" : 20,
    "skills_name" : "�γ���",
    "damage_type" : "����"
]),
([      "action" : "$N˫צ�����Ͼ٣�ʹһʽ��ӭ��������һ�����ֱ�Ϯ��$n����Ҹ
����",
    "force" : 190,
    "dodge" : 45,
    "parry" : 45,
    "damage": 45,
    "lvl" : 30,
    "skills_name" : "ӭ������",
    "damage_type" : "����"
]),
([      "action" : "$Nȫ�������ǰ��һʽ��������צ������צͻ�������Ȱ�ץ��$n����
��",
    "force" : 250,
    "dodge" : 50,
    "parry" : 50,
    "damage": 55,
    "lvl" : 40,
    "skills_name" : "������צ",
    "damage_type" : "����"
]),
([      "action" : "$N���ػ��У�һʽ������հ�ա�������Ϯ�����д�Ѩ�����ַ�ץ$n��
�ɲ�",
    "force" : 310,
    "dodge" : 65,
    "parry" : 65,
    "damage": 60,
    "lvl" : 50,
    "skills_name" : "����հ��",
    "damage_type" : "����"
]),
([      "action" : "$N��������צ���棬һʽ���������ա��������������ƿն�����Ѹ��
�ޱȵػ���$n",
    "force" : 380,
    "dodge" : 75,
    "parry" : 75,
    "damage": 75,
    "lvl" : 55,
    "skills_name" : "��ӥϮ��",
    "damage_type" : "����"
]),
([      "action" : "$N�ڿո߷����ɣ�һʽ��ӥ�����������ж�ʱ�Գ�һ������צӰ
����������$n",
    "force" : 470,
    "dodge" : 80,
    "parry" : 80,
    "damage": 80,
    "lvl" : 60,
    "skills_name" : "��ӥϮ��",
    "damage_type" : "����"
])
});

int valid_enable(string usage) { return usage=="claw" || usage=="parry"; }      

int valid_combine(string combo) { return combo=="fengyun-shou"; }

int valid_learn(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
   return notify_fail("��ӥצ��������֡�\n");
    if ((int)me->query_skill("hunyuan-yiqi", 1) < 20)
   return notify_fail("��Ļ�Ԫһ������򲻹����޷�ѧӥצ����\n");
    if ((int)me->query("max_neili") < 100)
   return notify_fail("�������̫�����޷���ӥצ����\n");
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
    level   = (int) me->query_skill("yingzhua-gong",1);
    for(i = sizeof(action); i > 0; i--)
   if(level > action[i-1]["lvl"])
      return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
    if ((int)me->query("qi") < 30)
   return notify_fail("�������̫���ˡ�\n");
    if ((int)me->query("neili") < 20)
   return notify_fail("�������������ӥצ����\n");
    me->receive_damage("qi", 30);
    me->add("neili", -10);
    return 1;
}
  
string perform_action_file(string action)
{
        return __DIR__"yingzhua-gong/" + action;
}
