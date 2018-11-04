// poyu-quan.c ��ʯ����ȭ

inherit SKILL;

mapping *action = ({
([	"action" : "$N�ҽ������������㣬һʽ������ʽ����������һ��һ�ͣ�����$n��$l",
	"force" : 180,
	"dodge" : 5,
	"damage": 170,
	"lvl" : 0,
	"skill_name" : "����ʽ",
	"damage_type" : "����"
]),
([	"action" : "$N�����̤��ȫ����ת��һ�С�ʯ���쾪������ȭ�͵ػ���$n��$l",
	"force" : 200,
	"dodge" : 10,
	"damage": 270,
	"lvl" : 10,
	"skill_name" : "ʯ���쾪",
	"damage_type" : "����"
]),
([	"action" : "$N˫�ִ󿪴��أ����߾٣�ʹһ�С����ź��š���˫ȭ��$n��$l��ȥ",
	"force" : 220,
	"dodge" : 15,
	"damage": 270,
	"lvl" : 20,
	"skill_name" : "���ź���",
	"damage_type" : "����"
]),
([	"action" : "$N����Ȧ���������⵱�أ����ֻ��ڳ��ϣ�һ�С�ǧ��׹�ء�����$n��$l",
	"force" : 260,
	"dodge" : 20,
	"damage": 270,	
	"lvl" : 30,
	"skill_name" : "ǧ��׹��",
	"damage_type" : "����"
]),
([	"action" : "$Nʹһ�С�����������������ǰ̽��˫ȭ���˸���Ȧ������$n��$l",
	"force" : 300,
	"dodge" : 25,
	"damage": 270,
	"lvl" : 40,
	"skill_name" : "��������",
	"damage_type" : "����"
]),
([	"action" : "$N˫ȭ������һ�ǡ����ֿβ�����Ƴ���磬һ�����е�$n������",
	"force" : 360,
	"dodge" : 0,
	"damage": 270,
	"lvl" : 50,
	"skill_name" : "���ֿβ",
	"damage_type" : "����"
]),
([	"action" : "$Nʩ��������֡���˫ȭȭ����磬ͬʱ����$nͷ���أ�������Ҫ��",
	"force" : 420,
	"dodge" : 35,
	"damage": 270,
	"lvl" : 60,
	"skill_name" : "�����",
	"damage_type" : "����"
]),
([	"action" : "$N����ڿۣ�����������һʽ����ʯ���񡹣�˫ȭ���봷��$n���ؿ�",
	"force" : 540,
	"dodge" : 40,
	"damage": 270,
	"lvl" : 80,
	"skill_name" : "��ʯ����",
	"damage_type" : "����"
])
});

int valid_enable(string usage) { return usage=="cuff" || usage=="parry"; }

int valid_combine(string combo) { return combo=="hunyuan-zhang"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("������ʯ����ȭ��������֡�\n");
	if ((int)me->query_skill("zixia-shengong", 1) < 10)
		return notify_fail("��ġ���ϼ�񹦡���򲻹����޷�ѧ����ʯ����ȭ����\n");
	if ((int)me->query("max_neili") < 50)
		return notify_fail("�������̫�����޷�������ʯ����ȭ����\n");
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
	level   = (int) me->query_skill("poyu-quan",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 30)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("�����������������ʯ����ȭ����\n");
	me->receive_damage("qi", 25);
	me->add("neili", -5);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"poyu-quan/" + action;
}
