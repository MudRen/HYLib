//
// shenkong-xing.c �����
// designed by secret(����)
//

inherit SKILL;

mapping *action = ({
([      "action" : "$nʹ��һ�С��Ŀա�����������Ʈȥ \n",
        "dodge" : 15,
]),
([      "action" : "$nʹ��һ�С����Կա���˫��һ�㣬Ծ������֮�� \n",
        "dodge" : 30,
]),
([      "action" : "$nʹ��һ�С����ա�������һ�䣬����$N��� \n",
        "dodge" : 45,
]),
([      "action" : "$n���һ����ʹ��һ�С��󰲿ա�����$Nͷ��Խ�� \n",
        "dodge" : 60,
]),
([      "action" : "$nʹ��һ�С���ա���������Ʈȥ��˲��������$N��ǰ \n",
        "dodge" : 75,
]),
([      "action" : "$nʹ��һ�С���տա�����ʱ$N��Χ����$n����Ӱ \n",
        "dodge" : 90,
]),
});


mapping query_action(object me, object weapon)
{
	int zhaoshu, level;

	zhaoshu = sizeof(action);
	level   = (int) me->query_skill("shenxingkong",1);

	if (level < 50 )
		zhaoshu--;

	if (level < 40 )
		zhaoshu--;

	if (level < 30 )
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
		return notify_fail("�������̫���ˣ�������ϰ����С�\n");
	me->receive_damage("qi", 20);
	return 1;
}
