// yunlong-shenfa ������

inherit SKILL;

mapping *action = ({
([	"action" : "$nһʽ�����ڻ�Ծ��������һת���͵�����һ��,�����$N�Ĺ��ơ�\n",
	"dodge"  : 10
]),
([	"action" : "$nһʽ��ɳ���������˫��������󣬲������������״�$N��ǰ�����\n",
	"dodge"  : 20
]),
([	"action" : "$nһʽ������ͬ�ۡ������˷�����һ�����Ƶ���$N�����\n",
	"dodge"  : 30
]),
([	"action" : "$nһʽ���������񡹣����������һ�ˣ������ù���$N���������ơ�\n",
	"dodge"  : 40
]),
([	"action" : "$nһʽ�����Ĳ�����������һ�����һ�Σ�������Ʈ����Զ��\n",
	"dodge"  : 50
]),
([	"action" : "$nһʽ����ӥ���á���������һֻ��ӥ������һ����$N����ǰ�ɹ���\n",
	"dodge"  : 60
]),
([	"action" : "$nһʽ���������졹�����İεض����ڰ����һת�����䵽����Զ�ĵط���\n",
	"dodge"  : 80
]),
([	"action" : "$nһʽ��������졹��ȫ��Ϊһ����Ӱ������һ���շ��������Ʈ���ұߡ�\n",
	"dodge"  : 90
]),
([	"action" : "$nһʽ���������̡������ζ��ر��Ʈ����������$N�޷����塣\n",
	"dodge"  : 100
]),
([	"action" : "$nһʽ���������¡�������һ����ʸ������ٿ�İεض�����$N�������ӡ�\n",
	"dodge"  : 120
])
});

mapping query_action(object me, object weapon)
{
	int zhaoshu, level;

	zhaoshu = sizeof(action);
	level   = (int) me->query_skill("yunlong-shenfa",1);

	if (level < 70 )
		zhaoshu--;

	if (level < 50 )
		zhaoshu--;

	if (level < 40 )
		zhaoshu--;

	return action[random(zhaoshu)];
}

int valid_enable(string usage)
{
	return usage == "dodge" || usage == "move";
}

int valid_learn(object me)
{
	return 1;
}

string query_dodge_msg(string limb)
{
	object me, ob;
	mapping action;

	me = this_player();
	action = query_action(me, ob);

	return action["action"];
}

int practice_skill(object me)
{
	if( (int)me->query("qi") < 40 )
		return notify_fail("�������̫���ˣ���������������\n");
	me->receive_damage("qi", 20);
	return 1;
}
