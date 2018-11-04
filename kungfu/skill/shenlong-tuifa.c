// shenlong-tuifa.c �����ȷ�
// by aug   99.9.10

inherit SKILL;
#include <ansi.h>

mapping *action = ({
([      "action" : "$N˫�Ų�����һʽ�������岼������������$n",
        "force" : 80,
        "dodge" : 10,
        "parry" : 10,
        "lvl" : 0,
        "skill_name" : "�����岼",
        "damage_type" : "����"
]),
([      "action" : "$N�Ų����ǣ������Ų������Ӳ���˼��ĽǶ��߳�һ�ȣ���һ�С��������ǡ�",
        "force" : 120,
        "dodge" : 15,
        "parry" : 10,
        "lvl" : 20,
        "skill_name" : "��������",
        "damage_type" : "����"
]),
([      "action" : "$Nʹһ�С�������β�����ҽ�ǰ�磬���ȷ�������$n��������$n����",
        "force" : 165,
        "dodge" : -5,
        "parry" : -5,
        "lvl" : 40,
        "skill_name" : "������β",
        "damage_type" : "����"
]),
([      "action" : "$Nһʽ���������١���˫��ҡ�ڲ���������Ĳ���$n",
        "force" : 200,
        "dodge" : 10,
        "parry" : 23,
        "lvl" : 60,
        "skill_name" : "��������",
        "damage_type" : "����"
]),
([      "action" : "$N�������˫���ڿ��������߳���һʽ�������޵С�Ϯ��$n������",
        "force" : 250,
        "dodge" : 10,
        "parry" : 15,
        "lvl" : 80,
        "skill_name" : "�����޵�",
        "damage_type" : "����"
]),
([      "action" : "$Nһת���������������֮����$n�߳�ʮ���ȣ��������Ӱ�������壬����һ�С���Ӱ���ȡ�",
        "force" : 290,
        "dodge" : 20,
        "parry" : 25,
        "lvl" : 100,
        "skill_name" : "��Ӱ����",
        "damage_type" : "����"
]),
([      "action" : "$N�ҽ���ǰһ������ϥ������������������ȣ��ٶ���Ȼ���죬�������������ˣ����ǡ��������ȡ�",
        "force" : 330,
        "dodge" : 10,
        "parry" : 15,
        "lvl" : 150,
        "skill_name" : "��������",
        "damage_type" : "����"
]),
([      "action" : "$N����֧�أ����ȼд��ŷ���֮�������߳���������������͵��ȷ���������ʯ����һ�ȼȳ�����������",
        "force" : 360,
        "dodge" : -15,
        "parry" : -15,
        "lvl" : 200,
        "skill_name" : "������ʯ",
        "damage_type" : "����"
]),
});

int valid_enable(string usage) { return usage == "leg" || usage == "parry"; }

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 100)
                return notify_fail("�������������\n");
        if ((int)me->query_skill("shenlong-xinfa", 1) < 10)
                return notify_fail("��������ķ����̫ǳ���޷�ѧϰ�����ȷ���\n");
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

	level =  me->query_skill("shenlong-tuifa",1);
	
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        if ((int)me->query("jing") < 25)
                return notify_fail("������������������ȷ���\n");
	if ((int)me->query("neili") < 8)
                return notify_fail("������������������ȷ���\n");
        me->receive_damage("jing", 25);
        me->add("neili", -8);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"shenlong-tuifa/" + action;
}
