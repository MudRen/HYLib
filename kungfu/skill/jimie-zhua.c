/* 
   jimie-zhua.c ����צ
   �ʹ�������(jingang-zhang)����
   �������������˿ࡣ
   2/3/98 by snowman
*/

inherit SKILL;

mapping *action = ({
([	"action" : "$Nȫ��εض���һʽ�������־���˫צ��ۣ�Ѹ�͵�ץ��$n��ȴ�ֲ����κΰ���",
	"force" : 100,
	"dodge" : 30,
	"lvl" : 0,
	"skills_name" : "��",
	"damage_type" : "ץ��"
]),
([	"action" : "$Nһʽ���ϡ��־���˫צ�й�ֱ����ȴ�����У���������֮�ʣ�$n�ѱ��޿ɱ�",
	"force" : 120,
	"dodge" : 20,
	"lvl" : 10,
	"skills_name" : "��",
        "damage_type" : "ץ��"
]),
([	"action" : "$N�Ų����ǣ����硸����̬��������ץ����һ�ӣ���Ȼ�ܴ�����������ֱϮ$n$l",
	"force" : 150,
	"dodge" : 25,
	"lvl" : 20,
	"skills_name" : "��",
        "damage_type" : "ץ��"
]),
([	"action" : "$N˫צ����һʽ�������־�������ץ����׷��$n��Ӱ���ǣ���Ҫ��ɱ$pȥצ��",
	"force" : 180,
        "dodge" : 10,
	"lvl" : 30,
	"skills_name" : "��",
        "damage_type" : "ץ��"
]),
([	"action" : "$Nһʽ���󲻵á�����צͻ������צ������������ץ�ֳ���˫צ�����ץ��$n���ؿ�",
	"force" : 210,
	"dodge" : 15,
        "limb" : "�ؿ�",
	"lvl" : 40,
	"skills_name" : "�󲻵�",
        "damage_type" : "ץ��"
]),
([	"action" : "$Nԭ�ز�����һʽ�������롹��ֻ��$nϮ����˫����Ȼ��צ������ֱ��$n��������Ѩ",
	"force" : 240,
	"dodge" : 10,
	"lvl" : 60,
	"skills_name" : "������",
        "damage_type" : "ץ��"
]),
([	"action" : "$N����һ�ӣ�˫צ�����������ƿն�����һʽ��Թ���᡹��Ѹ���ޱȵطɴ���$n",
        "force" : 270,
        "dodge" : 5,
        "weapon" : "��צ",
	"lvl" : 80,
	"skills_name" : "Թ����",
        "damage_type" : "����"
]),
([  	"action" : "$N�ڿո߷����ɣ����һʽ��������ʢ����һʱ����г�������$N����Ӱ�����ץӰ����$n",
        "force" : 300,
        "dodge" : 5,
	"lvl" : 100,
	"skills_name" : "������ʢ",
        "damage_type" : "ץ��"
])
});

int valid_enable(string usage) { return usage=="claw" || usage=="parry"; }

int valid_combine(string combo){
        if(this_player()->query_skill("jimie-zhua", 1) > 100)
   	         return combo=="jingang-zhang";
}

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("������צ������֡�\n");
        if ((int)me->query_skill("yijinjing", 1) < 100)
		return notify_fail("����׽�ڹ���򲻹����޷�ѧ����צ��\n");
        if ((int)me->query("max_neili") < 1200)
		return notify_fail("�������̫�����޷���ϰ����צ��\n");

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
	level   = (int) me->query_skill("jimie-zhua",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("jing") < 40)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("�����������������צ��\n");
	me->receive_damage("jing", 40);
	me->add("neili", -10);
	return 1;
}

string perform_action_file(string action)
{
         return __DIR__"jimie-zhua/" + action;
}

