// wuzhan-mei.c ��չ÷

inherit SKILL;

mapping *action = ({
([	"action" : "$Nһ�С���չ÷������÷�����������$w�����㵭��ɫ��÷�����$n��$l",
        "force" : 60,
        "dodge" : 2,
	"parry" : 10,
	"skill_name" : "��÷������",
	"lvl" : 0,
        "damage" : 70,
	"damage_type" : "����"
]),
([	"action" : "$Nʹ������չ÷������÷��˪ѩ����$nֻ����������������·��������ѩ���У�\n"
                   "$w�·�����˪��÷֦����$n��$l",
        "force" : 100,
        "dodge" : 0,
	"parry" : 20,
        "skill_name" : "��÷��˪ѩ",
	"lvl" : 20,
	"damage" : 90,
	"damage_type" : "����"
]),
([	"action" : "$Nһ�С���չ÷������÷Цӭ������$w������������ԲȦ����������÷����\n"
                   "$n��ǰһ����$w�ѹ�����ǰ", 
        "force" : 150,
        "dodge" : -2,
	"parry" : 30,
        "skill_name" : "��÷Цӭ��",
	"lvl" : 40,
	"damage" : 110,
	"damage_type" : "����"
]),

([      "action" : "$Nһ����$w���裬���ǡ���չ÷������÷���㸡��,$n�����ŵ�����÷�����㣬\n"
                   "��㱼��ĳ���,������ֱ��$n��$l",
        "force" : 200,
        "dodge" : -4,
	"parry" : 50,
        "skill_name" : "��÷���㸡",
	"lvl" : 60,
        "damage" : 130,
        "damage_type" : "����"
]),

([	"action" : "$N��ǰ����һ��������$wʹ������չ÷������÷չ��֦��,���ⱬ�ǣ�\n"
                   "��������ֱ��$n��$l",
        "force" : 400,
        "dodge" : -6,
	"parry" : 70,
        "skill_name" : "��÷չ��֦",
	"lvl" : 80,
	"damage" : 150,
	"damage_type" : "����"
]),

([      "action" : "$N���е�$wһ�Σ�ʹ������չ÷���ռ���ʽ����÷��֦�Ρ�,��ʽ����һʽ��\n"
                   "˲�佣�����죬$nֻ��÷���Ĵ����裬�������е�ɱ����͸�Ƕ���",
        "force" : 600,
        "dodge" : -8,
	"parry" : 90,
        "skill_name" : "��÷��֦��",
	"lvl" : 100,
        "damage" : 170,
        "damage_type" : "����"
]),
});



int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 400)
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
    level   = (int) me->query_skill("wuzhan-mei",1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
            return action[NewRandom(i, 5, level/5)];
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("���������������չ÷��\n");
	me->receive_damage("qi", 20);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"wuzhan-mei/" + action;
}
