// wudu-zhang �嶾��
// pal 1997.05.26

inherit SKILL;

mapping *action = ({
([	"action" : "$N˫��һ�������ƴ��ŵ��������⣬ֱ��$n��ȥ",
	"force" : 180,
        "dodge" : 5,
        "parry" : 20,
	"damage": 50,
	"lvl" : 0,
	"skill_name" : "�嶾��",
        "damage_type" : "����"
]),
([	"action" : "$N������Σ�����ֱ�������綾��һ��ֱ��$n����ǰ",
	"force" : 220,
        "dodge" : 10,
        "parry" : 15,
	"damage": 60,
	"lvl" : 10,
	"skill_name" : "�嶾��",
        "damage_type" : "����"
]),
([	"action" : "$N˫�Ʒ��ɣ�������ã��һ�ɰ���������������$n��ȫ��",
	"force" : 260,
        "dodge" : 15,
        "parry" : 20,
	"damage": 70,
	"lvl" : 20,
	"skill_name" : "�嶾��",
        "damage_type" : "����"
]),
([	"action" : "$N����һ�֣�������Ы���������ߣ�ͬʱ��$n����ȥ",
	"force" : 300,
        "dodge" : 20,
        "parry" : 30,
	"damage": 80,
	"lvl" : 30,
	"skill_name" : "�嶾��",
        "damage_type" : "����"
]),
([	"action" : "$NĬ��������˫�ƺ�Ȼ��ڣ�����һ������ֻ��$n��ȫ��",
	"force" : 340,
        "dodge" : 25,
        "parry" : 20,
	"damage":100,
	"lvl" : 40,
	"skill_name" : "�嶾��",
        "damage_type" : "����"
])
});

int valid_enable(string usage)
{
	return usage=="strike" || usage=="parry" ;
}

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("���嶾�Ʊ�����֡�\n");
	if ((int)me->query_skill("wudu-xinfa", 1) < 20)
		return notify_fail("����嶾�ķ���򲻹����޷�ѧ�嶾�ơ�\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������̫�����޷����嶾�ơ�\n");
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
	level   = (int) me->query_skill("wudu-zhang",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 30)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("��������������嶾�ơ�\n");
	me->receive_damage("qi", 30);
	me->add("neili", -10);
	return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	if( random(me->query_skill("wudu-zhang")) > 10 )
	victim->apply_condition("wudu_poison",
	 random(me->query_skill("wudu-zhang")/10) + 1 + 
	 victim->query_condition("wudu_poison"));
}

