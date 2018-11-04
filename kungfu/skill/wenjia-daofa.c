// wenjia-daofa.c �¼ҵ�����NPC����

inherit SKILL;

mapping *action = ({
([	"action" : "$Nһʽ������ӭ�͡�������΢�࣬����ƽ����б��$n��$l",
	"force" : 120,
        "dodge" : -10,
	"damage" : 125,
	"lvl" : 0,
	"skill_name" : "����ӭ��",
	"damage_type" : "����"
]),
([	"action" : "$N��ǰԾ��һ�������ּ����趯���е�$w��һ�С����ż�ɽ��ֱ��$n��$l",
	"force" : 140,
        "dodge" : -10,
	"damage" : 230,
	"lvl" : 10,
	"skill_name" : "���ż�ɽ",
	"damage_type" : "����"
]),
([	"action" : "$Nһ��б�ಽ��һ�С��ż����衹������$wƽƽ������$n��$l",
	"force" : 270,
        "dodge" : 5,
	"damage" : 135,
	"lvl" : 20,
	"skill_name" : "�ż�����",
	"damage_type" : "����"
]),
([	"action" : "$Nһ�С��Ʋ��������������$w����һ���󻡣����ٿ���$n��$l",
	"force" : 290,
        "dodge" : 35,
	"damage" : 240,
	"lvl" : 30,
	"skill_name" : "�Ʋ�����",
	"damage_type" : "����"
]),
});

int valid_enable(string usage) { return (usage == "blade") || (usage == "parry"); }

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
	level   = (int) me->query_skill("wenjia-daofa",1);
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
	if ((int)me->query("jingli") < 50)
		return notify_fail("��������������¼ҵ�����\n");
	me->receive_damage("jingli", 30);
	return 1;
}

