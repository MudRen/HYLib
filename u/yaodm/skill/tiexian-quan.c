inherit SKILL;

mapping *action = ({
([	"action" : "$N˫������ǰ���ƣ��ɸ�����ǰ�����Ƴ���һ�С�ͨ���ڡ���һ�ɾ���ֱ��&n",
	"force" : 100,
	"dodge" : 50,
	"skill_name" : "ͨ����",
	"lvl" : 0,
	"damage_type" : "����"
]),
([	"action" : "$Nʹһ�С���ɽ�ơ��������������£���������ӳ�������$n��$l",
	"force" : 120,
	"dodge" : 48,
	"skill_name" : "��ɽ��",
	"lvl" : 8,
	"damage_type" : "����"
]),
([	"action" : "$N�ɱ۴��֣�����ǰ����������ʹһ�С������֡�������$n��$l",
	"force" : 140,
	"dodge" : 46,
	"skill_name" : "������",
	"lvl" : 16,
        "damage_type" : "����"
]),
([	"action" : "$N˫�ֻ������������ϣ��������£�ʹһ�С��׺����᡹���ֻ�$n�����ź�$l",
	"force" : 160,
	"dodge" : 44,
	"skill_name" : "�׺�����",
	"lvl" : 24,
        "damage_type" : "����"
]),
([	"action" : "$Nһ�С�������򡹣����һ���������������Ͼ�����Ʋ������$n��$l��ȥ",
	"force" : 180,
	"dodge" : 32,
	"skill_name" : "�������",
	"lvl" : 32,
        "damage_type" : "����"
]),
([	"action" : "$N���̤һ���鲽������ǰ�ƣ����ֺ���,һ�С�������񡹣���$n��$l��ȥ",
	"force" : 200,
	"dodge" : 40,
	"skill_name" : "�������",
	"lvl" : 40,
        "damage_type" : "����"
]),
([	"action" : "$N���ֱ��ƺ�����ǰ����ȭ�����´�����һ�С��ֽ��ӡ�������$n��$l",
	"force" : 220,
	"dodge" : 8,
	"skill_name" : "�ֽ���",
	"lvl" : 48,
        "damage_type" : "����"
]),
([	"action" : "$N���ǰ̤�벽��һ�С�˫��������������ͬʱ������$n��$l��ȥ",
	"force" : 240,
	"dodge" : 30,
	"skill_name" : "˫������",
	"lvl" : 56,
        "damage_type" : "����"
]),
([	"action" : "$N�С������⡹�����һ���������������Ͼ�����Ʋ������$n��$l��ȥ",
	"force" : 260,
	"dodge" : 35,
	"skill_name" : "������",
	"lvl" : 64,
        "damage_type" : "����"
]),
([	"action" : "$N����ʹһʽ�С�һ��Ǯ����������$n��$l��ȥ",
	"force" : 280,
	"dodge" : 40,
	"skill_name" : "һ��Ǯ",
	"lvl" : 70,
        "damage_type" : "����"
]),
([	"action" : "$N�����鰴������ʹһ�С�����ȭ������$n��$l��ȥ",
	"force" : 300,
	"dodge" : 45,
	"skill_name" : "����ȭ",
	"lvl" : 78,
        "damage_type" : "����"
]),
([	"action" : "$N������ǰ��˫�ֽ����ʮ��ȭ��һ�С�����ʮ��ն������$n��$l��ȥ",
	"force" : 320,
	"dodge" : 50,
	"skill_name" : "����ʮ��ն",
	"lvl" : 86,
        "damage_type" : "����"
]),
});

int valid_enable(string usage) { return usage=="unarmed" || usage=="parry"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("������ȭ������֡�\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������̫�����޷�������ȭ��\n");
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
    level   = (int) me->query_skill("tiexian-quan",1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
            return action[NewRandom(i, 5, level/5)];

}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 30)
		return notify_fail("�������̫���ˡ�\n");
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
	return __DIR__"tiexian-quan/" + action;
}