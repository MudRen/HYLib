// taiji-dao.c ̫����
// modified by Venus Oct.1997
// cleansword 2/15/96

inherit SKILL;

mapping *action = ({
([      "action" : "$N����$wбָ��һ�С�ͣ����·��������һ�٣�һ����$n��$l��ȥ",
    "force" : 120,
    "dodge" : -10,
    "parry" : 5,
    "damage" : 15,
    "damage_type" : "����"
]),
([      "action" : "$Nһ�С�ͯ�ӹһ�������������㣬$wһ��һ�գ�ƽ�л���$n�ľ���
",
    "force" : 130,
    "dodge" : -10,
    "parry" : 10,
    "damage" : 20,
    "damage_type" : "����"
]),
([      "action" : "$Nչ���鲽������Ծ�䣬һ�С��ƴ����¡�������һ������ն��$n
",
    "force" : 140,
    "dodge" : -5,
    "parry" : 5,
    "damage" : 25,
    "damage_type" : "����"
]),
([      "action" : "$Nһ�С����ż�ɽ����$w�󿪴��أ����϶��»���һ���󻡣���ֱ��
��$n",
    "force" : 160,
    "dodge" : 5,
    "parry" : 5,
    "damage" : 30,
    "damage_type" : "����"
]),
([      "action" : "$N����$wһ����һ�С���Ϫ���㡹��˫�ֳ����������У�����$n����
��",
    "force" : 180,
    "dodge" : 10,
    "parry" : 5,
    "damage" : 35,
    "damage_type" : "����"
]),
([      "action" : "$N����$w��ʹ��һ�С��Ź����ġ����������ã����ҿ�����������
$n",
    "force" : 210,
    "dodge" : 15,
    "parry" : 15,
    "damage" : 45,
    "damage_type" : "����"
]),
([      "action" : "$Nһ�С��������ۡ������Ծ����أ�$w˳����ǰ��Ю��������$n��
$l",
    "force" : 240,
    "dodge" : 5,
    "parry" : 15,
    "damage" : 50,
    "damage_type" : "����"
]),
([      "action" : "$N����פ�أ�һ�С�������Ϣ�����ӳ�һƬ�����ĵ�Ӱ����$n��ȫ
��ӿȥ",
    "force" : 280,
    "dodge" : 20,
    "parry" : 10,
    "damage" : 60,
    "damage_type" : "����"
]),
});


int valid_enable(string usage) { return (usage == "blade") || (usage == "parry")
; }

int valid_learn(object me)
{
    if ((int)me->query("max_neili") < 100)
   return notify_fail("�������������\n");
    if ((int)me->query_skill("taiji-shengong", 1) < 20)
   return notify_fail("���̫���񹦻��̫ǳ��\n");
    if ((int)me->query_skill("taiji-quan", 1) < 20)
   return notify_fail("���̫��ȭ���̫ǳ��\n");
    return 1;
}

mapping query_action(object me, object weapon)
{
int zhaoshu, level;

zhaoshu = sizeof(action)-1;
level   = (int) me->query_skill("taiji-dao",1);

if (level < 60 )
zhaoshu--;
if (level < 55 )
zhaoshu--;
if (level < 50 )
zhaoshu--;
if (level < 40 )
zhaoshu--;
if (level < 30 )
zhaoshu--;
if (level < 20 )
zhaoshu--;
if (level < 10 )
zhaoshu--;

return action[random(zhaoshu)];
}

int practice_skill(object me)
{
    object weapon;

    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "blade")
   return notify_fail("��ʹ�õ��������ԡ�\n");
    if ((int)me->query("qi") < 50)
   return notify_fail("�������������̫��������\n");
    me->receive_damage("qi", 30);
    return 1;
}

