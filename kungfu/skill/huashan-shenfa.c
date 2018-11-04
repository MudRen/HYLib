// huashan-shenfa.c ��ɽ��

inherit SKILL;

mapping *action = ({
([	"action" : "$nһʽ���������᡹�������������������ݷ����У���$Nͷ����Ծ������\n",
	"dodge"  : 10
]),
([	"action" : "$nһʽ��������ϼ������һ����磬�滺��������$N���������ơ�\n",
	"dodge"  : 20
]),
([	"action" : "$nһʽ����س���������ӯ��һԾ��һת�ۼ���Ƶ���$N�����\n",
	"dodge"  : 30
]),
([	"action" : "$nһʽ��ȴ����ɡ���һת��䣬���Ʈ����һ��Զ\n",
	"dodge"  : 40
]),
([	"action" : "$nһʽ�����ճ�������ȫ���ֱ���εض����ڰ����һת�����䵽����Զ�ĵط���\n",
	"dodge"  : 50
]),
([	"action" : "$nһʽ�������ա���������һֻ�����������ˮ�ػ������ࡣ\n",
	"dodge"  : 60
]),
([	"action" : "$nһʽ���������ǡ���˫�ŵ�أ�ȫ��Ϊһ����Ӱ����������$N���˼�ת��\n",
	"dodge"  : 70
]),
([	"action" : "$nһʽ���������Ρ������ζ��ر��Ʈ����������$N�޷����塣\n",
	"dodge"  : 80
]),
([	"action" : "$nһʽ���������롹������һ����ʸ������Χ��$N���ٵ������˼�Ȧ��\n",
	"dodge"  : 90
])
});

mapping query_action(object me, object weapon)
{
	int zhaoshu, level;

	zhaoshu = sizeof(action);
	level   = (int) me->query_skill("huashan-shenfa",1);

	if (level < 80 )
		zhaoshu--;

	if (level < 60 )
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
		return notify_fail("�������̫���ˣ���������ɽ����\n");
	me->receive_damage("qi", 30);
	return 1;
}
