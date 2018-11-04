// pudu-zhang.c �ն��ȷ�
// modified by Venus Oct.1997

inherit SKILL;

mapping *action = ({
([      "action":"$Nʹһ�С���ţת�ǡ�������$w���¶��ϣ������ޱȵ���$n��С����ȥ
��",
    "force" : 180,
    "dodge" : 10,
    "damage": 15,
    "lvl" : 0,
    "skill_name" : "��ţת��",
    "damage_type":"����"
]),
([      "action":"$N�첽�����һ�С�Ұ��׷�硹������ƽ��$w�����������ȶˣ�����$n
���ؿڡ�",
    "force" : 200,
    "dodge" : 10,
    "damage": 30,
    "lvl" : 9,
    "skill_name" : "Ұ��׷��",
    "damage_type":"����"
]),
([      "action":"$N�߾�$w��һ�С��ͻ���������ȫ��Ծ������$w§ͷ�Ƕ�����$n��ȥ
��",
    "force" : 230,
    "dodge" : 5,
    "damage": 40,
    "lvl" : 18,
    "skill_name" : "�ͻ�����",
    "damage_type":"����"
]),
([      "action":"$Nһ�С�ʨ��ҡͷ����˫�ֳ������֣���׼$n�͵�һ������ͬƽ�ع���
һ�����硣",
    "force" : 270,
    "dodge" : 10,
    "damage": 55,
    "lvl" : 27,
    "skill_name" : "ʨ��ҡͷ",
    "damage_type":"����"
]),
([      "action":"$N���$w��һ�С�������β�����ȶ˻���������ԲȦ�����ͳ��أ���$n
�������С�",
    "force" : 320,
    "dodge" : 15,
    "damage": 60,
    "lvl" : 36,
    "skill_name" : "������β",
    "damage_type":"����"
]),
([      "action":"$Nȫ�������$w�̵غ�ɣ�ͻ��һ�С�������������Ӱ��$n��������
",
    "force" : 380,
    "dodge" : 5,
    "damage": 75,
    "lvl" : 45,
    "skill_name" : "��������",
    "damage_type":"����"
]),
([      "action":"$N˫�ֺ�ʮ������һ�С���ɮ�в�����$w������ɳ���������$nײȥ��
",
    "force" : 450,
    "dodge" : 5,
    "damage": 85,
    "lvl" : 53,
    "skill_name" : "��ɮ�в�",
    "damage_type":"����"
]),
([      "action":"$Nһ�С��Ⱥ��նɡ���$w�������������Ծ����ֱ��$n���ؿڴ��롣",
    "force" : 530,
    "dodge" : 5,
    "damage": 90,
    "lvl" : 60,
    "skill_name" : "�Ⱥ��ն�",
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
    level   = (int) me->query_skill("pudu-zhang",1);
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
   return notify_fail("��������������ն��ȷ���\n");
    me->receive_damage("qi", 30);
    return 1;
}

string perform_action_file(string action)
{
        return __DIR__"pudu-zhang/" + action;
}
