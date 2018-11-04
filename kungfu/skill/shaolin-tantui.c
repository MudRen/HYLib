/* 
   shaolin-tantui.c ���ֵ���
   ����צ��(weituo-zhang)����
   ���ԡ�����ȭ������ȡ��ʮ�ߣ�ʮ�ˣ���ʮ������ʮʽ��
   1/3/98 by snowman
*/

inherit SKILL;

mapping *action = ({
([      "action" : "$Nʹ�����ɵ��ߡ��������Բɵ���������ǰ���䣬ͬʱ�������Թ���ʽ��$n$l���߶���",
	"force" : 50,
	"dodge" : 40,
	"lvl" : 0,
	"skill_name" : "�ɵ���",
	"damage_type" : "����"
]),
([      "action" : "$N����������������ţ�ʹ�ҽ�������һ�С��ײ��ߡ��������Թ���ʽ������ǰ����",
	"force" : 60,
	"dodge" : 35,
	"lvl" : 0,
	"skill_name" : "�ײ���",
	"damage_type" : "����"
]),
([      "action" : "$N���ֻ��ƣ���ǰֱ�ɶ�����ʹ�����������򡹣��ҽ�ԭ�ض岽��ʹ����ת��$n�߳�",
	"force" : 70,
	"dodge" : 20,
	"lvl" : 20,
	"skill_name" : "��������",
	"damage_type" : "����"
]),
([      "action" : "$N�����֣�����ԭ����ǰ�ܲɶ������ҽ�˳����$n$lֱ�ߣ�����һʽ�������ܴ�",
	"force" : 80,
	"dodge" : 25,
	"lvl" : 20,
	"skill_name" : "�����ܴ�",
	"damage_type" : "����"
]),
([      "action" : "$N�����ķ����ҽţ�ʹ��ŷ��飬һ�С��ز��崷��������ԭ��ת�أ�ϥ��˳�Ƶ���$n$l",
        "force" : 100,
	"dodge" : 15,
	"lvl" : 40,
	"skill_name" : "�ز��崷",
	"damage_type" : "����"
]),
([      "action" : "$N������ǰֱ�ţ���ס���̣�һʽ���а���š�������ת���Է�������$n�ų�",
        "force" : 120,
	"dodge" : 25,
	"lvl" : 40,
	"skill_name" : "�а����",
	"damage_type" : "����"
]),
([      "action" : "$Nһ�С��ɵ���ȡ������ƻ�ס���󲻶�������ԭ�����ⷭ��ץ�ɣ��������ǰ��$n",
        "force" : 140,
	"dodge" : 25,
	"lvl" : 60,
	"skill_name" : "�ɵ����",
	"damage_type" : "����"
]),
([      "action" : "$N����ԭ�ػ�Ȧ����ǰ�����һ�С�Ť��Ю�⡹���ҽ���Ȼ�Ͻ�����$n������������",
        "force" : 160,
	"dodge" : 10,
	"lvl" : 60,
	"skill_name" : "Ť��Ю��",
	"damage_type" : "����"
]),
([      "action" : "$N˫�ֻ�ʮ���֣��������ǰ��ʹ��������ӭ������˫��һԾ������$n$l",
        "force" : 180,
	"dodge" : 20,
	"lvl" : 80,
	"skill_name" : "����ӭ��",
	"damage_type" : "����"
]),
([      "action" : "$N��������һ�С�����ӭ������ʮ����˳������˫���ᣬ˫������ٴ�����$n",
        "force" : 200,
	"dodge" : 15,
	"lvl" : 100,
	"skill_name" : "����ӭ��",
	"damage_type" : "����"
]),
});

int valid_enable(string usage) { return usage=="leg" || usage=="parry"; }

int valid_combine(string combo){
        if(this_player()->query_skill("shaolin-tantui", 1) > 150
	   && this_player()->query_int() > 45)
   	         return combo=="weituo-zhang";
}

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("ѧ���ֵ���ʱ���ﲻ����������\n");
	if ((int)me->query_skill("hunyuan-yiqi", 1) < 10)
		return notify_fail("��ı����ڹ���򲻹����޷���Τ���ơ�\n");
	if ((int)me->query("max_neili") < 50)
		return notify_fail("�������̫�����޷������ֵ��ȡ�\n");
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

	level   = (int) me->query_skill("shaolin-tantui",1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("jing") < 30)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("����������������ֵ��ȡ�\n");
	me->receive_damage("jing", 25);
	me->receive_damage("neili", -5);
	return 1;
}

