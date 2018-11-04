// biye-wu.c ��Ҷ�����

inherit SKILL;

mapping *action = ({
([	"action" : "$N˫��������ƮƮһʽ��Ҷ�䡹��������Ҷ����$n��$l��ȥ",
	"force" : 60,
        "damage" : 90,
	"dodge" : 2,
	"skill_name" : "Ҷ��",
	"lvl" : 0,
        "damage_type" : "����"
]),
([	"action" : "$N���Ϊ���ģ��ҽ�һ����˫�ֽ�����裬����Ҷ���ɣ����ǡ�Ҷ�衹����$n��$l����",
	"force" : 80,
	"dodge" : 0,
"damage" : 90,
	"skill_name" : "Ҷ��",
	"lvl" : 20,
        "damage_type" : "����"
]),
([	"action" : "$N����߸�Ծ������������ǰ���ұ�΢����ʹһ�С�ҶƮ�㡹����$n��$l�����Ŵ�ȥ",
	"force" : 100,
	"dodge" : -2,
"damage" : 90,
	"skill_name" : "ҶƮ��",
	"lvl" : 40,
        "damage_type" : "����"
]),
([	"action" : "$N΢һ�˾���˫����¶��һʽ����Ҷ������$n�������¶�������������Ӱ֮��",
	"force" : 200,
	"dodge" : -4,
"damage" : 90,
	"skill_name" : "��Ҷ",
	"lvl" : 60,
        "damage_type" : "����"
]),
([	"action" : "$N˫��ƽ̯�����ƻ��������磬��������ǰ�Ƴ���\n�Ʒ�����ƿ�����һ�С���֦��������֦������ֱ��$n���Ѷ�ȥ",
	"force" : 300,
	"dodge" : -6,
"damage" : 100,
	"skill_name" : "��֦",
	"lvl" : 80,
        "damage_type" : "����"
]),
([	"action" : "$NͻȻ���ƣ��ɸ�����ǰ�����Ƴ����Ʒ����Σ�һʽ��Ҷ�糱����һƬ����ֱ��$n",
	"force" : 500,
"damage" : 100,
	"dodge" : -8,
	"skill_name" : "Ҷ�糱",
	"lvl" : 100,
        "damage_type" : "����"
]),
});

int valid_enable(string usage) { return usage=="strike" || usage=="parry"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("����Ҷ����������֡�\n");
	if ((int)me->query_skill("biyun-xinfa", 1) < 30)
		return notify_fail("��ı����ķ���򲻹����޷�ѧ��Ҷ����衣\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������̫�����޷�����Ҷ����衣\n");
	return 1;
}

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

///* ----------------
//mapping query_action(object me, object weapon)
//{
//	return action[random(sizeof(action))];
//}
//-------------------*/

mapping query_action(object me, object weapon)
{
	int i, level;
    level   = (int) me->query_skill("biye-wu",1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
            return action[NewRandom(i, 5, level/5)];

}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 30)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("���������������Ҷ����衣\n");
	me->receive_damage("qi", 25);
	me->add("neili", -10);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"biye-wu/" + action;
}
