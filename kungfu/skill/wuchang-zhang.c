// wuchang-zhang.c �޳��ȷ�
// modified by Venus Oct.1997

inherit SKILL;

mapping *action = ({
([      "action":"$N΢һ����һ�С�ӹ�����š���$w���Ŵ̶���֨֨��������ɨ��$n��
����",
    "force" : 100,
    "dodge" : 10,
    "parry" : 5,
    "damage": 15,
    "lvl" : 0,
    "skill_name" : "ӹ������",
    "damage_type":"����"
]),
([      "action":"$Nһ�С�����Ƿǡ���������ס�ȶˣ����ƾ���һ��������ƾ���Ե���
$n�ļ�ͷ",
    "force" : 110,
    "dodge" : 10,
    "parry" : 10,
    "damage": 25,
    "lvl" : 7,
    "skill_name" : "����Ƿ�",
    "damage_type":"����"
]),
([      "action":"$Nһ�С����񲻰���������$wƹƹ���ҵ��������ã���$n�����ұܣ���
������",
    "force" : 120,
    "dodge" : 15,
    "parry" : 5,
    "damage": 40,
    "lvl" : 14,
    "skill_name" : "���񲻰�",
    "damage_type":"����"
]),
([      "action":"$Nһ�С�������ɫ��������$w�������ض���һ�ᣬͻȻ�͵�һ�ȴ���$n
��$l",
    "force" : 130,
    "dodge" : 5,
    "parry" : 5,
    "damage": 50,
    "lvl" : 20,
    "skill_name" : "������ɫ",
    "damage_type":"����"
]),
([      "action":"$N��$w��ס�Լ������ţ�һ��ָ��$n��һ�С��ľ��������������к���
����$n",
    "force" : 140,
    "dodge" : 15,
    "parry" : 15,
    "damage": 60,
    "lvl" : 25,
    "skill_name" : "�ľ�����",
    "damage_type":"����"
]),
([      "action":"$Nһ�С���ʬ���⡹��ȫ��ֱ�������ų���ǰ�У��䲻������������
$n��ȥ",
    "force" : 150,
    "dodge" : 5,
    "parry" : 15,
    "damage": 70,
    "lvl" : 30,
    "skill_name" : "��ʬ����",
    "damage_type":"����"
]),
([      "action":"$N�����ɫ��һ�С���������������$n˵���䣬һ����$n�Ŵ�����ͱ
�˹�ȥ",
    "force" : 300,
    "dodge" : 5,
    "parry" : 20,
    "damage": 80,
    "lvl" : 35,
    "skill_name" : "��������",
    "damage_type":"����"
]),
([      "action":"$Nһ�С��������ġ������⽫$wˤ����ϣ���$n������һ�Ź��𣬻���
$n��$l",
    "force" : 350,
    "dodge" : 5,
    "parry" : 25,
    "damage": 90,
    "lvl" : 40,
    "skill_name" : "��������",
    "damage_type":"����"
]),
([      "action":"$N����װ����һ�С���;û·����һ������������$w��������������
$n���ɲ�",
    "force" : 400,
    "dodge" : 5,
    "parry" : 25,
    "damage": 100,
    "lvl" : 45,
    "skill_name" : "��;û·",
    "damage_type":"����"
]),
([      "action":"$Nһ�С�����ľ�������������Ų��ƣ�$wȴֱ�ɰ�գ���ƫ���е���
��$n��$l",
    "force" : 450,
    "dodge" : 5,
    "parry" : 25,
    "damage": 120,
    "lvl" : 50,
    "skill_name" : "����ľ��",
    "damage_type":"����"
]),
([      "action":"$N�߾�$w��һ�С��˹���;������������Ȱ�Ʈ������׼$n�������һ
�ȴ���",
    "force" : 500,
    "dodge" : 5,
    "parry" : 25,
    "damage": 140,
    "lvl" : 55,
    "skill_name" : "�˹���;",
    "damage_type":"����"
]),
([      "action":"$Nһ�С���������������ȶ�����$w���ǧ�ٸ����ƣ���������$nȫ��
����Ҫ��",
    "force" : 550,
    "dodge" : 5,
    "parry" : 25,
    "damage": 160,
    "lvl" : 60,
    "skill_name" : "�������",
    "damage_type":"����"
]),
});

int valid_enable(string usage) { return (usage == "staff") || (usage == "parry")
; }

int valid_learn(object me)
{
    if ((int)me->query("max_neili") < 100)
   return notify_fail("�������������\n");
    if ((int)me->query_skill("hunyuan-yiqi", 1) < 20)
   return notify_fail("��Ļ�Ԫһ�������̫ǳ��\n");
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
    level   = (int) me->query_skill("wuchang-zhang",1);
    for(i = sizeof(action); i > 0; i--)
   if(level > action[i-1]["lvl"])
      return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
    object weapon;

    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "staff")
   return notify_fail("��ʹ�õ��������ԡ�\n");
    if ((int)me->query("qi") < 50)
   return notify_fail("��������������޳��ȷ���\n");
    me->receive_damage("qi", 30);
    return 1;
}
string perform_action_file(string action)
{
        return __DIR__"wuchang-zhang/" + action;
}
