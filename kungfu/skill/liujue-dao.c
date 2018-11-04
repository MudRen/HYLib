// liujue-dao.c ��������

inherit SKILL;

mapping *action = ({
([      "action" : "$N����$wбָ��һ�С�����һ����������һ�٣�һ����$n��$l��ȥ",
	"force" : 120,
	"dodge" : -10,
	"damage" : 10,
	"lvl" : 0,
	"skill_name" : "����һ��",
	"damage_type" : "����"
]),
([      "action" : "$Nһ�С��������������������һ�ݣ�$wһ��һ�գ�ƽ�л���$n�ľ���",
	"force" : 140,
	"dodge" : -10,
	"damage" : 20,
	"lvl" : 20,
	"skill_name" : "��������",
	"damage_type" : "����"
]),
([      "action" : "$Nչ���鲽������Ծ�䣬һ�С����޾���֮·�������滯������ն��$n",
	"force" : 160,
	"dodge" : -5,
	"damage" : 30,
	"lvl" : 40,
	"skill_name" : "���޾���֮·",
	"damage_type" : "����"
]),
([      "action" : "$N���ػ��У�һ�С����Ӿ��������$wֱ��ȥ$n���ɲ�",
	"force" : 180,
	"dodge" : 5,
	"damage" : 40,
	"lvl" : 60,
	"skill_name" : "���Ӿ���",
	"damage_type" : "����"
]),
([      "action" : "$N����$wһ����һ�С���ǰ���󡹣�˫�ֳ����������У����ɵ��濳��$n��ǰ�غͺ�",
	"force" : 200,
	"dodge" : 10,
	"damage" : 50,
	"lvl" : 80,
	"skill_name" : "��ǰ����",
	"damage_type" : "����"
]),
([      "action" : "$N����$w��ʹ��һ�С����������������ã����ҿ�����������$n",
	"force" : 250,
	"dodge" : 15,
	"damage" : 60,
	"lvl" : 100,
	"skill_name" : "����",
	"damage_type" : "����"
])
});


int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 50)
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
	level   = (int) me->query_skill("liujue-dao",1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "blade")
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
	return __DIR__"liujue-dao/" + action;
}
