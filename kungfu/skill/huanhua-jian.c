//
// huanhua-jian.c 佻�����
//
#include <ansi.h>

inherit SKILL;

mapping *action = ({
([      "action" : "ֻ����âһ��,$Nʹ��һ�С�������ա�������$wһ����ֱ��$n��$l  ",
        "skill_name" : "�������",
        "force" : 100,
        "dodge" : -10,
        "lvl" : 0,
        "damage" : 40,
        "damage_type" : "����",
]),
([      "action" : "$Nʹ��һʽ�����շ������������ڳ����л��������ͣ���â��$n��$l�ɹ����  ",
        "skill_name" : "���շ���",
        "force" : 100,
        "dodge" : 5,
        "lvl" : 8,
        "damage" : 50,
        "damage_type" : "����",
]),
([      "action" : "$Nʹ��һ�С����Ǵ��¡�������Ծ���գ�$w�����ǰ�����$n��$l  ",
        "skill_name" : "���Ǵ���",
        "force" : 100,
        "dodge" : -10,
        "lvl" : 16,
        "damage" : 60,
        "damage_type" : "����",
]),
([      "action" : "$Nʹ����һ�����¡���$w�Ľ��������Բ�£���Ȼһ������$n��$l  ",
        "skill_name" : "һ������",
        "force" : 120,
        "dodge" : 10,
        "lvl" : 24,
        "damage" : 70,
        "damage_type" : "����",
]),
([      "action" : "$Nʹ��һ�С���ʳ�������ȫ��������$w�У�����ֱָ$n��$l  ",
        "skill_name" : "��ʳ���",
        "force" : 150,
        "dodge" : 10,
        "lvl" : 32,
        "damage" : 80,
        "damage_type" : "����",
]),
([      "action" : "$Nʹ��һʽ���������󡹣�һ�Ž������Ӱ����$n��$lɨȥ  ",
        "skill_name" : "��������",
        "force" : 180,
        "dodge" : 15,
        "lvl" : 40,
        "damage" : 90,
        "damage_type" : "����",
]),
([      "action" : "$Nʹ��һ�С������㡹������$wһ��,$nֻ�������콣���������  ",
        "skill_name" : "������",
        "force" : 200,
        "dodge" : 20,
        "lvl" : 48,
        "damage" : 100,
        "damage_type" : "����",
]),
([      "action" : "$N����һԾ���Ӹ�����ʹ�������컨�꡹����ʱ�����������$n��$l  ",
        "skill_name" : "���컨��",
        "force" : 220,
        "dodge" : 25,
        "lvl" : 56,
        "damage" : 110,
        "damage_type" : "����",
]),
([      "action" : "$N��ȻԾ��,ʹ��һ�С�������ƾ�����ڰ������$n������ȥһ��  ",
        "skill_name" : "������ƾ",
        "force" : 240,
        "dodge" : 20,
        "lvl" : 66,
        "damage" : 120,
        "damage_type" : "����",
]),
([      "action" : "$Nʹ��һʽ��÷����Ū����$w������佣��,����$nãȻ��ʱ��,��������һ��������$n��$lɨȥ  ",
        "skill_name" : "÷����Ū",
        "force" : 260,
        "dodge" : 25,
        "lvl" : 84,
        "damage" : 130,
        "damage_type" : "����",
]),
([      "action" : "$N��������Ծ��һʽ�������Ƕ�����������ˮ��һкǧ�����$nȫ��",
        "skill_name" : "�����Ƕ�",
        "force" : 280,
        "dodge" : 20,
        "lvl" : 92,
        "damage" : 140,
        "damage_type" : "����",
]),
([      "action" : "$N��̧$w��һ�С��ƻ����񡹣�����$n��ȫ��������ת����$n  ",
        "skill_name" : "�ƻ�����",
        "force" : 300,
        "dodge" : 25,
        "lvl" : 100,
        "damage" : 150,
        "damage_type" : "����",
]),
([      "action" : HIY "$N����бָ��һʽ������λ�������λ���,����$w��������һ�£����콣����$n��ȥ��"NOR,
        "skill_name" : "����λ�������λ�",
        "force" : 300,
        "dodge" : 25,
        "lvl" : 100,
        "damage" : 180,
        "damage_type" : "����",
]),
});


int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������������\n");
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
	level   = (int) me->query_skill("huanhua-jian",1);
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
	return __DIR__"huanhua-jian/" + action;
}
