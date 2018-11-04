// liuxing-dao.c ���Ǹ�����


inherit SKILL;

mapping *action = ({
([      "action" : "$N����$w�������,ʹ��һ�С��������꡹������$n��$l  ",
        "skill_name" : "��������",
        "force" : 100,
        "dodge" : -5,
        "parry" : 5,
        "lvl" : 0,
        "damage" : 120,
        "damage_type" : "����",
	"post_action":  (: call_other, WEAPON_D, "throw_weapon" :)

]),
([      "action" : "$N����΢�࣬ʹһ�С��������ߡ�������$w����$n�Ĵ���  ",
        "skill_name" : "��������",
        "force" : 140,
        "dodge" : 5,
        "parry" : 5,
        "lvl" : 8,
        "damage" : 140,
        "damage_type" : "����",
	"post_action":  (: call_other, WEAPON_D, "throw_weapon" :)
]),
([      "action" : "$N�����������ȫ��������ʹ����������������$w����ǧ��֮���ش���$n��$l  ",
        "skill_name" : "�����콵",
        "force" : 180,
        "dodge" : 10,
        "parry" : 5,
        "lvl" : 16,
        "damage" : 160,
        "damage_type" : "����",
	"post_action":  (: call_other, WEAPON_D, "throw_weapon" :)
]),
([      "action" : "$Nʹ��һ�С����Ǹ��¡���$w�籩���Ѹ�ײ����ڶ�������$n  ",
        "skill_name" : "���Ǹ���",
        "force" : 220,
        "dodge" : 5,
        "parry" : 5,
        "lvl" : 24,
        "damage" : 180,
        "damage_type" : "����",
	"post_action":  (: call_other, WEAPON_D, "throw_weapon" :)
]),
});

int valid_enable(string usage) { return (usage == "throwing") || (usage == "parry"); }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 400)
		return notify_fail("�������������\n");
	if ((int)me->query_skill("biyun-xinfa", 1) < 80)
		return notify_fail("��ı����ķ����̫ǳ��\n");
	if ((int)me->query_skill("biye-wu", 1) < 30)
		return notify_fail("��ı�Ҷ�������̫ǳ��\n");
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
	level   = (int) me->query_skill("liuxing-dao",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "throwing")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("����������������������Ǹ����ڡ�\n");
	me->receive_damage("qi", 30);
	return 1;
}

