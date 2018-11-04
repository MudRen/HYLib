// kunlun-shenfa.c (kunlun) ������

inherit SKILL;

mapping *action = ({
([	"action" : "$nһʽ������ƽɳ�����������٣�������ǰ�߳���������Ȼ�����������ɵ�����һ�ԡ�\n",
	"dodge"  : 15
]),
([	"action" : "$nһʽ���������𡹣������Ծ�������һ��һת����Ʈ��������֮�⡣\n",
	"dodge"  : 25
]),
([	"action" : "$nһʽ���������ڡ���������������������ĥ��������֮��ת��ж����$N��һ�С�\n",
	"dodge"  : 35
]),
([	"action" : "$nһʽ�����ɵ��ҡ���ֻ��$n���Ӻ�����˫��������һ�ţ����ӽ��Ƶ��������$N���Ѵ�$n���š�\n",
	"dodge"  : 45
]),
([	"action" : "$nһʽ����ѩ��̲�����ݸ߷��ͣ���������������Ʈ��������$N������룬ֻ�û������ء�\n",
	"dodge"  : 55
]),
([	"action" : "$nһʽ����˿���꡹��ͻȻ����һ�У���Ȼ�����ܾ��˵Ĵ򷨣���$N��æ���Ұ�ȫ����\n",
	"dodge"  : 65
]),
([	"action" : "$nһʽ��������ѩ�������в��ܣ�ֻ΢΢һ����$N���籩�������Ľ����㼴��ա�\n",
	"dodge"  : 75
]),
([	"action" : "$nһʽ������ǱԾ������Ȼ�����ΰ���ֱ��������ֱ��ӥ��������������ƮƮ������������֮�⡣\n",
	"dodge"  : 85
])
});

mapping query_action(object me, object weapon)
{
	int zhaoshu, level;

	zhaoshu = sizeof(action);
	level   = (int) me->query_skill("kunlun-shenfa");

	if (level < 60 )
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
	int na, nk;
	na = (int)me->query_skill("art", 1);
	nk = (int)me->query_skill("kunlun-shenfa", 1);

	if (me->query("family/master_name") == "�����" )
	{
		if ( na<120 && na<=nk )
		return notify_fail("�����黭�����书���أ���Ȼ���޷������������������\n");
	}

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
	int na, nk;
	na = (int)me->query_skill("art", 1);
	nk = (int)me->query_skill("kunlun-shenfa", 1);

	if (me->query("family/master_name") == "�����" )
	{
		if ( na<120 && na<=nk )
		return notify_fail("�����黭�����书���أ���Ȼ���޷������������������\n");
	}

	if( (int)me->query("jing") < 40 )
		return notify_fail("��ľ���̫���ˣ���������������\n");
	me->receive_damage("jing", 30);
	return 1;
}
