// fanyun-zhang.c ������

inherit SKILL;

mapping *action = ({
([      "action" : "$Nһʽ��������ˮ����˫��һ����һ�ɾ�����������$n��$l",
	"force" : 180,
	"dodge" : 5,
	"parry" : 20,
	"damage": 15,
	"lvl" : 0,
	"skill_name" : "������ˮ",
	"damage_type" : "����"
]),
([      "action" : "$Nһʽ�����ƴ��¡�������һ��������$n��$l��ȥ",
	"force" : 220,
	"dodge" : 10,
	"parry" : 15,
	"damage": 25,
	"lvl" : 10,
	"skill_name" : "���ƴ���",
	"damage_type" : "����"
]),
([      "action" : "$Nʹһʽ�����Ƹ��꡹������΢��������է��է�ϣ��͵ز���$n��$l",
	"force" : 260,
	"dodge" : 15,
	"parry" : 20,
	"damage": 35,
	"lvl" : 20,
	"skill_name" : "���Ƹ���",
	"damage_type" : "����"
]),
([      "action" : "$N�����������죬һʽ����ɽ�������������纣ˮ����$n��ȥ",
	"force" : 300,
	"dodge" : 20,
	"parry" : 30,
	"damage": 45,
	"lvl" : 30,
	"skill_name" : "��ɽ����",
	"damage_type" : "����"
]),
([      "action" : "$N��������һ�ݣ�ʹ��һʽ�����Ʊ��ա���˫��һ̯����ֱ����$n��$l��ȥ",
	"force" : 340,
	"dodge" : 25,
	"parry" : 20,
	"damage": 55,
	"lvl" : 40,
	"skill_name" : "���Ʊ���",
	"damage_type" : "����"
]),
([      "action" : "$N����һ�䣬ʹһʽ��������������˫�ƴ�����ɲ�ľ������͵ػ���$n��$l",
	"force" : 280,
	"dodge" : 25,
	"parry" : 25,
	"damage": 65,
	"lvl" : 50,
	"skill_name" : "��������",
	"damage_type" : "����"
]),
([      "action" : "$Nʹһʽ��˺�����ơ����������أ�������ӯ��ͬʱ��$n��$l��ȥ",
	"force" : 320,
	"dodge" : 30,
	"parry" : 30,
	"damage": 75,
	"lvl" : 60,
	"skill_name" : "˺������",
	"damage_type" : "����"
]),
([      "action" : "$Nͻ��һ�С��ƺ����Ρ���˫��Ю��һ�����֮�ƣ��͵�����$n��$l",
	"force" : 360,
	"dodge" : 30,
	"parry" : 35,
	"damage": 85,
       "lvl" : 70,
	"skill_name" : "�ƺ�����",
	"damage_type" : "����"
]),
([      "action" : "$Nһʽ�������޶�����˫�������һ����裬�����ѻ���$n��$l��",
	"force" : 300,
	"dodge" : 40,
	"parry" : 45,
	"damage": 95,
	"lvl" : 80,
	"skill_name" : "�����޶�",
	"damage_type" : "����"
]),
([      "action" : "$Nһʽ�������콵�����������ϴ������࣬˫��һ��һ�ͣ����Ƽ򵥣�ȴ��$n�޷�����",
	"force" : 340,
	"dodge" : 45,
	"parry" : 50,
	"damage": 115,
	"lvl" : 90,
	"skill_name" : "�����콵",
	"damage_type" : "����"
]),
([      "action" : "$Nһʽ�������ɾ����������������������Ƽ��������ϼ�⣬��$n������ס��",
	"force" : 340,
	"dodge" : 45,
	"parry" : 50,
	"damage": 120,
	"lvl" : 100,
	"skill_name" : "�����ɾ�",
	"damage_type" : "����"
])
});

int valid_enable(string usage) { return usage=="unarmed" || usage=="parry" || usage=="strike"; }


int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("�������Ʊ�����֡�\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������̫�����޷��������ơ�\n");
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
	level   = (int) me->query_skill("fanyun-zhang",1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
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
	return __DIR__"fanyun-zhang/" + action;
}
