//
//xiaoyao-dao  ��ң����
//

inherit SKILL;

mapping *action = ({
([      "action" : "$N����΢����һ�С��ʺ���졹����$w����һ���׺磬ֱ����$n����ǰ",
        "skill_name" : "�ʺ����",
        "force" : 120,
        "dodge" : 5,
        "parry" : 20,
        "lvl" : 0,
        "damage" : 30,
        "damage_type" : "����",
]),
([      "action" : "$N���μ�ת��һ�С��ط�ת�ơ�������һƬ������$w����$n",
        "skill_name" : "�ط�ת��",
        "force" : 160,
        "dodge" : 0,
        "parry" : 8,
        "lvl" : 15,
        "damage" : 40,
        "damage_type" : "����",
]),
([      "action" : "$N���ᵶ�棬$w����һ�������һ�С�������⡹������$n��ͷ��",
        "skill_name" : "�������",
        "force" : 220,
        "dodge" : 10,
        "parry" : 15,
        "lvl" : 30,
        "damage" : 50,
        "damage_type" : "����",
]),
([      "action" : "$N���漱ת�����Ī�⣬һ�С������Ϲ项��$w������$n�ĺ���",
        "skill_name" : "�����Ϸ�",
        "force" : 240,
        "dodge" : 10,
        "parry" : 20,
        "lvl" : 50,
        "damage" : 50,
        "damage_type" : "����",
]),
([      "action" : "$N���΢Ц�����⻯�������׵㣬һ�С������һ�����������$nȫ��",
        "skill_name" : "�����һ�",
        "force" : 270,
        "dodge" : 20,
        "parry" : 15,
        "lvl" : 80,
        "damage" : 60,
        "damage_type" : "����",
]),
([      "action" : "$Nʹ��һ�С����Ƕ��ǡ��������󵶣������󽣣�������$n����Ҫ��",
        "skill_name" : "���Ƕ���",
        "force" : 300,
        "dodge" : 35,
        "parry" : 50,
        "lvl" : 100,
        "damage" : 60,
        "damage_type" : "����",
]),
([      "action" : "$Nʹһʽ�����ں�ë����$w��ͬ����Ʈ��һ�㣬���ϵ�ֱ��$n��ȥ   ",
        "skill_name" : "���ں�ë",
        "force" : 300,
        "dodge" : 40,
        "parry" : 70,
        "lvl" : 130,
        "damage" : 80,
        "damage_type" : "����",
]),
([      "action" : "$N������$w,һ�С��������塹��$w����ǧ��һ�㣬ֱֱ��$n��ȥ   ",
        "skill_name" : "��������",
        "force" : 500,
        "dodge" : 40,
        "parry" : 70,
        "lvl" : 150,
        "damage" : 100,
        "damage_type" : "����",
]),


});


int valid_enable(string usage) { return usage == "blade" ; }


int valid_learn(object me)
{
	if ((int)me->query_skill("blade", 1) >= 30)
		return 1;
	else if ((int)me->query_skill("blade", 1) < 30)
		return notify_fail("��Ļ�������̫���ˣ���������ң������\n");
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
	level   = (int) me->query_skill("xiaoyao-dao",1);
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
	if ((int)me->query("qi") < 20)
		return notify_fail("���������������������ң������\n");
	me->receive_damage("qi", 30);
	return 1;
}

