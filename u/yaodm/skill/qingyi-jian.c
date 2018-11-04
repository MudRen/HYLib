// qingyi-jian.c ���彣

inherit SKILL;

mapping *action = ({
([      "action":"$Nʹһʽ����ʽ��������$w����΢�񣬻ó�һ���������$n��$l",
	"force" : 120,
	"dodge" : -10,
	"damage": 15,
	"lvl" : 0,
	"skill_name" : "��ʽ�",
	"damage_type":  "����"
]),
([      "action":"$N����ǰ��ʹ������ʽ���������������ޣ�$w��������$n��$l��ȥ",
	"force" : 140,
	"dodge" : -10,
	"damage": 20,
	"lvl" : 10,
	"skill_name" : "��ʽ",
	"damage_type":  "����"
]),
([      "action":"$Nһʽ������ʽ��������Ʈ�����ߣ��˷�����������$wңҡָ��$n��$l",
	"force" : 160,
	"dodge" : 5,
	"damage" : 25,
	"lvl" : 20,
	"skill_name" : "����ʽ",
	"damage_type":  "����"
]),
([      "action":"$N������ǰԾ��һʽ�����ʽ�����������ּ�ת������ն��$n��$l",
	"force" : 180,
	"dodge" : 10,
	"damage": 35,
	"lvl" : 30,
	"skill_name" : "���ʽ",
	"damage_type":  "����"
]),
([      "action":"$N����$w�й�ֱ����һʽ����ϲʽ��������˿˿������׼$n��$l�̳�һ��",
	"force" : 220,
	"dodge" : 15,
	"damage": 40,
	"lvl" : 40,
	"skill_name" : "��ϲʽ",
	"damage_type":  "����"
]),
([      "action":"$N����$wбָ���죬��â���£�һʽ����ŭʽ������׼$n��$lбб����",
	"force" : 260,
	"dodge" : 5,
	"damage": 45,
	"lvl" : 50,
	"skill_name" : "��ŭʽ",
	"damage_type":  "����"
]),
([      "action":"$N��ָ�����㣬����$w��������ѩ����â��һʽ����ʽ������$n��$l",
	"force" : 320,
	"dodge" : 5,
	"damage": 55,
	"lvl" : 60,
	"skill_name" : "��ʽ",
	"damage_type":  "����"
]),
([      "action":"$Nһʽ������ʽ����$w�������죬�缲�������$n���ؿ�",
	"force" : 380,
	"dodge" : 5,
	"damage": 60,
	"lvl" : 70,
	"skill_name" : "����ʽ",
	"damage_type":  "����"
]),
([      "action":"$Nһʽ���Ľ�����$w��Ȼ��Ϊ�ݺύ��Ľ���������ǵ���$n����ȥ",
	"force" : 420,
	"dodge" : 5,
	"damage": 60,
	"lvl" : 80,
	"skill_name" : "�Ľ�",
	"damage_type":  "����"
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
	level   = (int) me->query_skill("qingyi-jian",1);
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
	return __DIR__"qingyi-jian/" + action;
}
