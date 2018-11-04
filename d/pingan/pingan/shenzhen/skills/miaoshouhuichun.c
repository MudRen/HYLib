// ���ֻش�
// 97/9/30  by Aug

inherit SKILL;

mapping *action = ({
	([	"name":		"��������",
		"action":		"$Nһ�С��������ߡ������е�$w���ǰ�Ϯ��$n",
		"dodge":		20,
		"parry":		20,
		"force":		20,
		"damage":         30,
		"lvl":		0,
		"damage_type":	"����"
	]),
	([	"name":		"�������",
		"action":		"$N���������ٶȷɳ����е�$w,һʽ��������ɡ�Ϯ��$n��$l",
		"dodge":		10,
		"parry":		30,
		"force":		30,
		"damage":         35,
		"lvl":		0,
		"damage_type":	"����"
	]),
	([	"name":		"���ǵ��",
		"action":		"$Nһʽ�����ǵ�㡹����ʱ���в�����$w,ʹ$n�޴�����",
		"dodge":		40,
		"parry":		40,
		"force":		40,
		"damage":         40,
		"lvl":		9,
		"damage_type":	"����"
	]),
	([	"name":		"��ѩ����",
		"action":		"$N����������ʹ������ѩ���졹����ʱ$n����Χ��һƬ����֮��",
		"dodge":		40,
		"parry":		30,
		"force":		40,
		"damage":         50,
		"lvl":		9,
		"damage_type":	"����"
	]),
	([	"name":		"��Ůɢ��",
		"action":	"$N΢΢һЦ��ʹ������Ůɢ����������$w���ű߼ʵķɳ����ɶ�������$n������",
		"dodge":		50,
		"parry":		50,
		"force":		55,
		"damage":         55,
		"lvl":		29,
		"damage_type":	"����"
	]),
	([	"name":		"�޿ײ���",
		"action":		"$Nһʽ���޿ײ��롹������$wϮ��$n����ָ����ֺ�ȾͲ����׷����Ĳ�λ��",
		"dodge":		100,
		"parry":		100,
		"force":		30,
		"damage":         30,
		"lvl":		49,
		"damage_type":	"����"
	]),
	([	"name":		"��������",
		"action":		"$Nһ�ɳ��죬һʽ����������������$n��ʮ������Ѩ",
		"dodge":		80,
		"parry":		80,
		"force":		60,
		"damage":         60,
		"lvl":		69,
		"damage_type":	"����"
	]),
	([	"name":		"�����޵�",
		"action":	"$N��һ������$w��ɺü��Σ��Ӳ����ܵĽǶȷ���$n",
		"dodge":		80,
		"parry":		80,
		"force":		100,
		"damage":         100,
		"lvl":		99,
		"damage_type":	"����"
	]),

});


int valid_learn(object me)
{
	object ob;

	if( (int)me->query_skill("literate", 1) < 40 )
		return notify_fail("�����ѧ�������㣬�����������ֻش��ľ��衣\n");
		
	if( (int)me->query("max_force") < 100 )
		return notify_fail("�������������û�а취ʹ�����롣\n");

	if( (string)ob->query_temp("weapon") != "����" )
		return notify_fail("�����������������������ֻش���\n");

	return 1;
}

int valid_enable(string usage)
{
        return usage=="throwing" ;
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	notify_fail("��ֻ������ʦ��ѧ���ʵ���ķ�����������ֻش���ˮƽ��\n");
}

string perform_action_file(string action)
{
        return CLASS_D("xiake") + "/miaoshouhuichun/" + action;
}
 
