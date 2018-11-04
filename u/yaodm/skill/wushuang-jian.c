// wushuang-jian.c ��˫��

inherit SKILL;

mapping *action = ({
([      "action":"\n$Nʹһʽ��������Ե��������$w����΢�񣬻ó�һ���׹����$n��$l",
	"force" : 120,
	"dodge" : -10,
	"damage": 15,
	"lvl" : 0,
	"skill_name" : "������Ե",
	"damage_type":  "����"
]),
([      "action":"\n$N����ǰ��ʹ�������ѵ��ϡ��������������ޣ�$w��������$n��$l��ȥ",
	"force" : 140,
	"dodge" : -10,
	"damage": 20,
	"lvl" : 8,
	"skill_name" : "���ѵ���",
	"damage_type":  "����"
]),
([      "action":"\n$Nһʽ��������𡹣�����Ʈ�����ߣ��˷�����������$wңҡָ��$n��$l",
	"force" : 160,
	"dodge" : 5,
	"damage": 30,
	"lvl" : 15,
	"skill_name" : "�������",
	"damage_type":  "����"
]),
([      "action":"$N��������Ծ��һʽ������ʧ������������ˮ��һкǧ�����$nȫ��",
	"force" : 180,
	"dodge" : 10,
	"damage": 35,
	"lvl" : 20,
	"skill_name" : "����ʧ��",
	"damage_type":  "����"
]),
([      "action":"$N����$w�й�ֱ����һʽ��Թ�첻������������Ϣ�ض�׼$n��$l�̳�һ��",
	"force" : 220,
	"dodge" : 15,
	"damage": 40,
	"lvl" : 30,
	"skill_name" : "Թ�첻��",
	"damage_type":  "����"
]),
([      "action":"$N����$wһ����һʽ���ް���Ե����������Ϣ�ػ���$n��$l",
	"force" : 250,
	"dodge" : 15,
	"damage": 40,
	"lvl" : 40,
	"skill_name" : "�ް���Ե",
	"damage_type":  "����"
]),
([      "action":"\n$N����$wбָ���죬��â���£�һʽ���򷨹��ڡ�����׼$n��$lбб����",
	"force" : 280,
	"dodge" : 25,
	"damage": 45,
	"lvl" : 50,
	"skill_name" : "�򷨹���",
	"damage_type":  "����"
]),
([      "action":"$N�������Ʈ�䣬һʽ�������ء�������$wƽָ����������$n����",
	"force" : 450,
	"dodge" : 15,
	"damage": 80,
	"lvl" : 90,
	"skill_name" : "������",
	"damage_type":  "����"
]),
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 200)
		return notify_fail("�������������\n");
	if ((int)me->query_skill("force", 1) < 40)
		return notify_fail("��Ļ����ڹ����̫ǳ��\n");
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
	level   = (int) me->query_skill("wushuang-jian",1);
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
	return __DIR__"wushuang-jian/" + action;
}
