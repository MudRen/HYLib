
inherit SKILL;

string *dodge_msg = ({
	"$nһ�С�����ֱ�¡�����һƮ��������٣�ֱ�˳�����֮�⡣\n",
	"$n�������棬��Ӱ�����������һʽ�������̻����ܿ�$N�ķ�â��\n",
	"$n�ڿն��������ڿ���������������һʽ��һ�����ۡ����������ɵ�������\n",
	"$n�������࣬���������ζ���һ�С�Ϫˮ�������ڿն��𣬱��˿�ȥ��\n",
	"$n������ˮ������Ծ�����ߣ�һ�С�ϸˮ����������������Ʈ�˿�ȥ��\n",
	"$n����һ����ȴͻȻ�ڿ�Ծ�𣬡������Ȫ������������\n",
	"����$nһ�С�ˮ��ɽ�ʹ���������Ƶ�$N���ᣡ\n",
        "����$n����Ʈ��������һ�ݣ�һ�С������΢�����ܿ���һ����\n",
        "$n��������һ�Σ�һ�С���ˮ���ա���һ��ת����������֮�⡣\n",

});

int valid_enable(string usage)
{
	return (usage=="dodge") ;
}

int valid_learn(object me)
{
	if( (int)me->query("max_neili") < 50 )
		return notify_fail("�������������û�а취����Ȫ����\n");

	return 1;
}

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
	if( (int)me->query("qi") < 30
	||	(int)me->query("neili") < 3 )
		return notify_fail("�������������������������Ȫ����\n");
	me->receive_damage("qi", 30);
	me->add("neili", -3);
	return 1;
}
int effective_level() { return 10;}

int learn_bonus()
{
	return 0;
}
int practice_bonus()
{
	return 0;
}
int black_white_ness()
{
	return 0;
}

string perform_action_file(string action)
{
        return __DIR__"liuquan-steps/" + action;
}
