
inherit SKILL;

string *dodge_msg = ({
	"$nһ�����ʹ������������䡹���ó�������Ӱ����$N������ʽ�������Ρ�\n",
	"$nʹ��һ�С�ڤڤ��ȥ�١�����Ȼ�������࣬���$N���˸��ա�\n",
	"$nһ����ĮĮ�����ء�������$N�Ĺ���Ʈ�𣬴��ݶ����һ�С�\n",
	"$n˫��һ�㣬бб����ʹ����������֡�������$N��ࡣ\n",
	"$n����һҡ���ó�������Ӱ��һ�С�ɽ�紵���֡������$N�Ĺ��ơ�\n",
       "$nһ�С�ǧ��ͬһɫ������Ծ��ٿ��������$N���\n",

});

int valid_enable(string usage)
{
	return (usage=="dodge"||usage=="dodge") ;
}

int valid_learn(object me)
{
	if( (int)me->query("max_neili") < 100 )
		return notify_fail("�������������û�а취������Ʈ�㲽��\n");

	return 1;
}

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
	if( (int)me->query("jing") < 30
	||	(int)me->query("neili") < 3 )
		return notify_fail("���������������������������Ʈ�㲽�� ��\n");
	me->receive_damage("jing", 30);
	me->add("neili", -3);
	return 1;
}
int effective_level() { return 19;}

int learn_bonus()
{
	return -90;
}
int practice_bonus()
{
	return -50;
}
int black_white_ness()
{
	return 40;
}

string perform_action_file(string action)
{
        return __DIR__"fengyu-piaoxiang/" + action;
}

