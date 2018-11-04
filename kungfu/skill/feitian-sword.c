// ����������

#include <ansi.h>

inherit SKILL;  
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

mapping *action = ({
([      "action" : "$N�������˸�����������$wƽƽ�ݳ���һʽ��������ͨͨ��"+(order[random(13)])+"������"NOR"ֱ��$n��ǰ��",
        "force" : 150,
        "dodge" : 15,
        "damage" : 60,
        "lvl" : 5,
        "damage_type" : "����"
]),
([      "action" : "$N������ǰ��$w��һ���벻���ĽǶ�ͻȻ������һʽ����ƽ�������"+(order[random(13)])+"������ն��"NOR"ֱ��$n������",
        "force" : 180,
        "dodge" : 15,
        "damage" : 85,
        "lvl" : 25,
        "damage_type" : "����"
]),
([      "action" : "$N���$nһ��"+(order[random(13)])+"�������ġ�"NOR"��$w��������� ��ֱ��$n��ͷ������ͨ�Ľ���֮��͸��һ�ɰ���",
        "force" : 220,
        "dodge" : 20,
        "damage" : 105,
        "lvl" : 35,
        "damage_type" : "����"
]),
([      "action" : "$N����б�ӣ�����ָ��$n�ĸ�����һ��"+(order[random(13)])+"����̡�"NOR"�����¶��ϣ�����$n����Լ��Ȼ���Ϲ��ܽ������������Ľ���",
        "force" : 270,
        "dodge" : 15,
        "damage" : 170,
        "lvl" : 95,
        "damage_type" : "����"
]),
([      "action" : "$N˫�ֳֽ���б�ɶ�����һ��"+(order[random(13)])+"���Ҵ̡�"NOR"��$w����$n�ĸ���",
        "force" : 330,
        "dodge" : 15,
        "damage" : 190,
        "lvl" : 125,
        "damage_type" : "����"
]),
([      "action" : "$N��Хһ�����ὣ�������͸����һ����ͨ����ʽ"+(order[random(13)])+"�������ϡ�"NOR"����������ס$n��ȫ��",
        "force" : 380,
        "dodge" : 15,
        "damage" : 300,
        "lvl" : 165,
        "damage_type" : "����"

]),
([  "action" : "$N��ǰ����һ����һ��"+(order[random(13)])+"�������ϡ�"NOR"������$w����������$n��$l
������ȥ",
    "force" : 150,
    "dodge" : 130,
    "damage" : 25,
    "lvl" : 0,
    "skill_name" : "������",
    "damage_type" : "����"
]),
([  "action" : "$N����Ծ�����ֽ���������һ����$w�����������٣�һʽ"+(order[random(13)])+"����硹"NOR"ֱ��$n��$l",
    "force" : 300,
    "dodge" : 115,
    "damage" : 200,
    "lvl" : 90,
    "skill_name" : "���",
    "damage_type" : "����"
]),
([  "action" : "$Nһ��"+(order[random(13)])+"����ͻ����"NOR"��$w�����������⣬���¶��Ϸ���$n��$l",
    "force" : 500,
    "dodge" : 115,
    "damage" : 500,
    "lvl" : 150,
    "skill_name" : "��ͻ��",
    "damage_type" : "����"
]),
});


int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }

int valid_learn(object me)
{
    if ((int)me->query("max_neili") < 100)
       return notify_fail("�������������\n");
//    if ((int)me->query_skill("feitian-xinfa", 1) < 20)
//       return notify_fail("��ķ����������ķ����졣\n");
    return 1;
}

mapping query_action(object me, object weapon)
{
    int i, level;
    level   = (int) me->query_skill("feitian-sword",1);
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
       return notify_fail("�������������������������\n");
    me->receive_damage("qi", 20);
    return 1;
}

string perform_action_file(string action)
{
    return __DIR__"feitian-sword/" + action;
}

