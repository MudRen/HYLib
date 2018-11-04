// shenxing-baibian.c ���аٱ�

inherit SKILL;

mapping *action = ({
([	"action" : "$nһʽ��������ˮ�������㣬�Ų��ƣ�������������ˮ��ֱ�������ࡣ\n",
	"dodge"  : 10
]),
([	"action" : "$nһʽ��Ǳ��ҹ�С�����Ȼһ������ȫ�����ض��У���ʱ������$N���������ơ�\n",
	"dodge"  : 20
]),
([	"action" : "$nһʽ���Ʋ����Ρ����㲻�����ֲ�̧��һת�ۼ���Ƶ���$N�����\n",
	"dodge"  : 30
]),
([	"action" : "$nһʽ������Ӱ����һת��䣬����˷�Ʈ����������$n����Ӱ����$N�����޴롣\n",
	"dodge"  : 40
]),	
([	"action" : "$nһʽ���貨΢��������̤�㣬��תǬ������һ�Σ��㵽����Զ�ĵط���\n",
	"dodge"  : 50
]),
([	"action" : "$nһʽ�����ϲ�¥�������ڿ��У������������һ�㣬��$Nͷ���ڿն�����\n",
	"dodge"  : 60
]),
([	"action" : "$nһʽ�����ӳ�ˮ��������һ����ȫ��Ϊһ����Ӱ�����ĵش�$Nͷ��Ʈ�䡣\n",
	"dodge"  : 70
]),
([	"action" : "$nһʽ�����·ת�������������ݰ㼱ת����ʱһ������ӿ������$N���Զ�����\n",
	"dodge"  : 80
]),
([	"action" : "$nһʽ�������ﲨ��������ٿ�Ĵ�$N����ǰֱ�Ƶ����$N�ɴ������ۣ��������ԡ�\n",
	"dodge"  : 90
]),
([	"action" : "$nһʽ�����ӻ�ͷ��������ٿ�Ĵ�$N����ǰƮ��������һ˦������֮����\n",
	"dodge"  : 100
]),
});

mapping query_action(object me, object weapon)
{
	int zhaoshu, level;

	zhaoshu = sizeof(action);
	level   = (int) me->query_skill("shenxing-baibian",1);


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
		return notify_fail("�������̫���ˣ����������аٱ䡣\n");
	me->receive_damage("qi", 20);
	return 1;
}
