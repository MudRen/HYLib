// bloody.c ��֫�ϻ�,for �Ǹ�PK�ҵ����ˣ���
//chaos 31/3/97 ��ҹ����ŭ���������

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action" : HIR"$Nһ�ְ�ס$n����һ�ְ�ס��򢣬����һ�֣���$n�°�˺������"NOR,
        "force" : 20000,
        "dodge" : 100,
        "parry" : 100,
        "damage": 50000,
        "lvl" : 1,
//      "skill_name" : "",
        "damage_type" : "ץ��"
]),
([      "action" : HIM"$N����$n��һ��ҧס$n�ĺ���������һ��$n��ʳ�ܣ����ܣ�Ѫ��ȫ����˺��ϣ���ã���һ��������"NOR,
        "force" : 20000,
        "dodge" : 100,
        "parry" : 100,
        "damage": 50000,
        "lvl" : 1,
//      "skill_name" : "",
        "damage_type" : "ץ��"
]),
([      "action" : RED"$N��ָ���$n����ǣ�����һ���⿪ͷ�ǣ���$n�Խ�һ��ץ�˳��������˼���"NOR,
        "force" : 20000,
        "dodge" : 100,
        "parry" : 100,
        "damage": 50000,
        "lvl" : 1,
//      "skill_name" : "",
        "damage_type" : "ץ��"
]),
([      "action" : HIC"$Nһ����ס$n������ҧ��$n�ظ��������ھͿеü����߹ǣ����¾Ͱ�$n�ظ�����˺���������ķε����������ɼ�"NOR,
        "force" : 20000,
        "dodge" : 100,
        "parry" : 100,
        "damage": 50000,
        "lvl" : 1,
//      "skill_name" : "",
        "damage_type" : "ץ��"
]),
([      "action" : HIG"$Nһ����Ц����ס$n������ץס$n˫�֣�ž��һ��������Ӳק���������ֱ����������Ӵ�Ѫ��ģ�����׹�ɭɭ"NOR,
        "force" : 20000,
        "dodge" : 100,
        "parry" : 100,
        "damage": 50000,
        "lvl" : 1,
//      "skill_name" : "",
        "damage_type" : "ץ��"
]),
([      "action" : HIW"$N��ס$n�ı���һ�þ�������һ�����죬$n�ļ�׵�Ƕϳ�ʮ�߶�ʮ�˽أ�$N�ٴ�$n������Ѫ���ܵس�����������ģ���ļ�׵��"NOR,
        "force" : 20000,
        "dodge" : 100,
        "parry" : 100,
        "damage": 50000,
        "lvl" : 1,
//      "skill_name" : "",
        "damage_type" : "ץ��"
]),
([      "action" : BLU"$Nץס$n�����ȣ�ʹ��һ˺����$n˺����Ƭ����Ѫ�Ľ���$n������ϡ���������һ��"NOR,
        "force" : 20000,
        "dodge" : 100,
        "parry" : 100,
        "damage": 50000,
        "lvl" : 1,
//      "skill_name" : "",
        "damage_type" : "ץ��"
]),
([      "action" : HIB"$N��ָǶ��$n�۾���ʹ��ץ�Σ�һ��ץס$n���壬�þ�һ�ʣ�һŤ����һ����һ�¾Ͱ�$n��ͷק������"NOR,
        "force" : 20000,
        "dodge" : 100,
        "parry" : 100,
        "damage": 50000,
        "lvl" : 1,
//      "skill_name" : "",
        "damage_type" : "ץ��"
]),

});

int valid_enable(string usage) { return usage == "claw" || usage == "unarmed"|| usage == "parry"; }

int valid_learn(object me)
{
        
                return notify_fail("�㲻��ѧ��֫�ϻꡣ\n");
        
}


mapping query_action(object me, object weapon)
{
  return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        
                return notify_fail("�㲻������֫�ϻꡣ\n");
        
} 



