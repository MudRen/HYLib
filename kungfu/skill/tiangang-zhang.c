// tiangang-zhang.c �����

inherit SKILL;

mapping *action = ({
([	"action" : "$Nʹһ�С���ĥ����������ȭ�������б�ɣ�����$n��$l",
	"force" : 275,
	"dodge" : 60,
        "lvl" : 0,
	"skill_name" : "��ĥ����",
	"damage_type" : "����"
]),
([	"action" : "$Nһ�С���Ƿ���ࡹ��б��Ť�������͵���$n���ؿ�ײȥ",
	"force" : 325,
	"dodge" : 50,
        "lvl" : 39,
	"skill_name" : "��Ƿ����",
        "damage_type" : "����"
]),
([	"action" : "$N����б������������צ��һ�С������֡�����$n��$l",
	"force" : 450,
	"dodge" : 40,
        "lvl" : 89,
	"skill_name" : "������",
        "damage_type" : "����"
]),
([	"action" : "$N�Ჽ��ǰ��һ�ǡ������ҫ����˫�ƻ����Ƴ�������$n��ǰ��",
	"force" : 560,
	"dodge" : 30,
        "lvl" : 119,
	"skill_name" : "�����ҫ",
        "damage_type" : "����"
]),
([	"action" : "$N�Ų����Ƿ�λ��˫�Ʒ���ʩ������ɽ��ˮ����������Ӱ����$n��$l",
	"force" : 685,
	"dodge" : 50,
        "lvl" : 179,
	"skill_name" : "��ɽ��ˮ",
        "damage_type" : "����"
]),
([	"action" : "$N���һ����һ�С�������á���˫�ƴ������������Ѹ���ޱȵĻ���$n��$l",
	"force" : 700,
	"dodge" : 50,
        "lvl" : 200,
	"skill_name" : "�������",
        "damage_type" : "����"
])

});

int valid_enable(string usage) { return usage=="strike" || usage=="parry"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("������Ʊ�����֡�\n");
	if ((int)me->query_skill("xiantian-gong", 1) < 20)
		return notify_fail("������칦��򲻹����޷�ѧ����ơ�\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������̫�����޷�������ơ�\n");
	return 1;
}

string query_skill_name(int level)
{
        int i = sizeof(action);

        while (i--)
                if(level > action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
        int i, level;
        level   = (int) me->query_skill("tiangang-zhang",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        int lvl = me->query_skill("tiangang-zhang", 1);
        int i = sizeof(action);

        while (i--) if (lvl == action[i]["lvl"]) return 0;

	if ((int)me->query("jingli") < 30)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("�����������������ơ�\n");
	me->receive_damage("jingli", 60);
	me->add("neili", -20);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"tiangang-zhang/" + action;
}
