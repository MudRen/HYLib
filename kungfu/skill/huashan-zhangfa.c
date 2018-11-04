// huashan-zhangfa.c ��ɽ�Ʒ�

inherit SKILL;

mapping *action = ({
([	"action" : "$Nһʽ�����Ƴ�ᶡ���˫�Ƽ�����һ�ŵ����İ�����������$n��$l",
	"force" : 180,
        "dodge" : 5,
        "parry" : 20,
	"damage": 310,
	"lvl" : 0,
	"skill_name" : "���Ƴ��",
        "damage_type" : "����"
]),
([	"action" : "$N��ָ�罣��һʽ���׺���ա�������$n��$l��ȥ",
	"force" : 220,
        "dodge" : 10,
        "parry" : 15,
	"damage": 320,
	"lvl" : 10,
	"skill_name" : "�׺����",
        "damage_type" : "����"
]),
([	"action" : "$Nʹһʽ���ƶ����롹������΢��������է��է�ϣ��͵ز���$n��$l",
	"force" : 260,
        "dodge" : 15,
        "parry" : 20,
	"damage": 330,
	"lvl" : 20,
	"skill_name" : "�ƶ�����",
        "damage_type" : "����"
]),
([	"action" : "$N˫����������������һʽ�����ɴ�䡹���ó�������̵����룬������$n��ȥ",
	"force" : 300,
        "dodge" : 20,
        "parry" : 30,
	"damage": 340,
	"lvl" : 30,
	"skill_name" : "���ɴ��",
        "damage_type" : "����"
]),
([	"action" : "$N��������һ�ݣ�ʹ��һʽ������������˫�Ʋ�£����ֱ����$n��$l��ȥ",
	"force" : 340,
        "dodge" : 25,
        "parry" : 20,
	"damage": 350,
	"lvl" : 40,
	"skill_name" : "������",
        "damage_type" : "����"
]),
([	"action" : "$N����һ�䣬ʹһʽ���ޱ���ľ����˫�ƴ�����ɲ�ľ������͵ػ���$n��$l",
	"force" : 380,
        "dodge" : 25,
        "parry" : 25,
	"damage": 360,
	"lvl" : 50,
	"skill_name" : "�ޱ���ľ",
        "damage_type" : "����"
]),
([	"action" : "$Nʹһʽ����ɽ��ˮ�����������أ�������ӯ��ͬʱ��$n��$l��ȥ",
	"force" : 420,
        "dodge" : 30,
        "parry" : 30,
	"damage": 270,
	"lvl" : 60,
	"skill_name" : "��ɽ��ˮ",
        "damage_type" : "����"
]),
([	"action" : "$Nͻ��һ�С��������á���˫��Ю��һ�����֮�ƣ��͵�����$n��$l",
	"force" : 460,
        "dodge" : 30,
        "parry" : 35,
	"damage": 380,
	"lvl" : 70,
	"skill_name" : "��������",
        "damage_type" : "����"
]),
([	"action" : "$Nһʽ��������ơ���˫�������һ����裬�����ѻ���$n��$l��",
	"force" : 500,
        "dodge" : 40,
        "parry" : 45,
	"damage": 390,
	"lvl" : 80,
	"skill_name" : "�������",
        "damage_type" : "����"
]),
([	"action" : "$Nһʽ������Ʈ�졹����������������˫��һ��һ�ͣ����Ƽ򵥣�ȴ��$n�޷�����",
	"force" : 540,
        "dodge" : 45,
        "parry" : 50,
	"damage": 410,
	"lvl" : 90,
	"skill_name" : "����Ʈ��",
        "damage_type" : "����"
])
});

int valid_enable(string usage) { return usage=="strike" || usage=="parry"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("����ɽ�Ʒ�������֡�\n");
	if ((int)me->query_skill("zixia-shengong", 1) < 20)
		return notify_fail("�����ϼ�񹦻�򲻹����޷�ѧ��ɽ�Ʒ���\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������̫�����޷�����ɽ�Ʒ���\n");
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
	level   = (int) me->query_skill("huashan-zhangfa",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 30)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 40)
		return notify_fail("���������������ɽ�Ʒ���\n");
	me->receive_damage("qi", 30);
	me->add("neili", -10);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"huashan-zhangfa/" + action;
}
