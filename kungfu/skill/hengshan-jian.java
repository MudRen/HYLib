// hengshan-jian.c ��ɽ����
// Made by deaner
// Modified by Venus Oct.1997
#include <ansi.h>
inherit SKILL;

mapping *action = ({
([  "action" : "$N�鲽������һ��"+HIC"����ʵ�޻���"NOR+"�����п���ƽ��ȴ����
���ţ�
����$w����$n��$l",
    "force" : 120,
    "dodge" : 40,
    "damage" : 30,
    "damage_type" : "����",
    "lvl" : 0,
    "skill_name" : "��ʵ�޻�"
]),
([  "action" : "$Nʹ��һʽ"+HIC"�����ż�ɽ��"NOR+"������$wֱ��$n��$l",      
    "force" : 140,
    "dodge" : 35,
    "damage" : 35,
    "damage_type" : "����",
    "lvl" : 12,
    "skill_name" : "���ż�ɽ"
]),
([  "action" : "$N����һ��"+HIC"������������"NOR+"������$w���Ⱪ����������$n
��$l",
    "force" : 150,
    "dodge" : 20,
    "damage" : 45,
    "damage_type" : "����",
    "lvl" : 19,
    "skill_name" : "��������"
]),
([  "action" : "$N˫���ս���һ��"+WHT"��Զ�볾����"NOR+"��$w��������ػ���$n
��$l",
    "force" : 175,
    "dodge" : 25,
    "damage" : 55,
    "damage_type" : "����",
    "lvl" : 20,
    "skill_name" : "Զ�볾��"
]),
([  "action" : "$Nʩչ��"+HIW"������������"NOR+"�����ֺ�ʲ΢����ţ�����$w��������
����$n��$l",
    "force" : 200,
    "dodge" : 25,
    "damage" : 65,
    "damage_type" : "����",
    "lvl" : 27,
    "skill_name" : "��������"
]),
([  "action" : "$N����ʹ��"+HIW"���ľ�������"NOR+"��$w����ǰ������Ȧ��Ϊ��������
$n��$l",
    "force" : 225,
    "dodge" : 35,
    "damage" : 85,
    "damage_type" : "����",
    "lvl" : 35,
    "skill_name" : "�ľ�����"
]),
([  "action" : "$N˫��һ�㣬һ��"+MAG"����ħ����"NOR+"�����Ȱ�����$n��ǰ��$w����
һ����â����$n��$l",
    "force" : 250,
    "dodge" : 5,
    "damage" : 115,
    "damage_type" : "����",
    "lvl" : 44,
    "skill_name" : "��ħ����"
]),
([  "action" : "$Nԭ��һת��ʹ��"+HIM"����ħ���塻"NOR+"��$nȴ������˷�����$N����
����$w��˸���������Լ���$l",
    "force" : 300,
    "dodge" : 55,
    "damage" : 145,
    "damage_type" : "����",
    "lvl" : 53,
    "skill_name" : "��ħ����"
]),
([  "action" : "$N����Ծ�𣬼���"+HIR"����ٲ�����"NOR+"��$w����һ�������Ӱ��������
$n��$l",
    "force" : 350,
    "dodge" : 35,
    "damage" : 175,
    "damage_type" : "����",
    "lvl" : 62,
    "skill_name" : "��ٲ���"
]),
([  "action" : "$N����΢΢һ��һ��"+HIB"���������ߡ�"NOR+"�����پ��׵�������ϣ�
����$wƮ������������$n��$l",
    "force" : 400,
    "dodge" : 45,
    "damage" : 200,
    "damage_type" : "����",
    "lvl" : 71,
    "skill_name" : "��������"
]),
([  "action" : "$N��ɫƽ�͵�΢΢���ף�һ��"+YEL"���ɷ���ǡ�"NOR+"��$w�������Ʋ�
���ش���$n��$l",
    "force" : 450,
    "dodge" : 20,
    "damage" : 250,
    "damage_type" : "����",
    "lvl" : 80,
    "skill_name" : "�ɷ����"
]),
([  "action" : "$N˫�ֺ�ʲ��ʹ��һ��"+HIY"���ɽ�������"NOR+"��$wƽƽ�طɳ�����$n
��$l",
    "force" : 500,
    "dodge" : 35,
    "damage" : 300,
    "damage_type" : "����",
    "lvl" : 90,
    "skill_name" : "�ɽ�����"
]),
([  "action" : "$N��¶΢Ц��һ��"+HIY"���ն�������"NOR+"��$wһ������������Ž���
����$n��$l",
    "force" : 550,
    "dodge" : 25,
    "damage" : 350,
    "damage_type" : "����",
    "lvl" : 100,
    "skill_name" : "�ն�����"
])
});


int valid_enable(string usage) { return (usage == "sword") || (usage == "parry")
; }

int valid_learn(object me)
{
    if ((int)me->query("max_neili") < 100)
   return notify_fail(HIC"�������������\n"NOR);
    if ((int)me->query_skill("lingyuan-xinfa", 1) < 10)
   return notify_fail(HIC"�����Ԫ�ķ����̫ǳ��\n"NOR);
    if ((string)me->query("gender") != "Ů��" )
   return notify_fail(HIY"��������Ľ���ֻ��Ů�Ӳ��ʺ�ѧ��\n"NOR);
    return 1;
}

mapping query_action(object me, object weapon)
{
    int i, level;
    level   = (int) me->query_skill("hengshan-jian",1);
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
    if ((int)me->query("qi") < 50)
   return notify_fail("���������������ɽ������\n");
    me->receive_damage("qi", 30);
    return 1;
}

string perform_action_file(string action)
{
    return __DIR__"hengshan-jian/" + action;
}

