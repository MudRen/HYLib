
inherit SKILL;

string *dodge_msg = ({
	"$nһ�С����������������ɵر��˿�ȥ��\n",
	"ֻ��$n��Ӱһ�Σ�һʽ��������桹���ѱ����߳�֮�⡣\n",
	"$nʹ�����������桹���������ɵ�������\n",
	"$n����һ�㣬һ�С��������졹�ڿն��𣬱��˿�ȥ��\n",
	"����$nʹһ�С�������������������Ʈ�˿�ȥ��\n",
	"$n��Ӱ΢�����Ѿ���һ�С��������֡�����������\n",
	"����$nһ�С�����ɭɭ��ʹ���������Ƶ�$N���ᣡ\n"
});

int valid_enable(string usage)
{
	return (usage=="dodge") || (usage=="dodge");
}

int valid_learn(object me)
{
       if( (string)me->query("gender") != "Ů��" )
                return notify_fail("��������ֻ��Ů�Ӳ��������书��\n");
	if( (int)me->query("max_neili") < 50 )
		return notify_fail("�������������û�а취����������\n");

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
		return notify_fail("�������������������������������\n");
	me->receive_damage("qi", 30);
	me->add("neili", -3);
	return 1;
}
string perform_action_file(string action)
{
   return __DIR__"ninemoonsteps/" + action;
}

int effective_level() { return 15;}

int learn_bonus()
{
	return 10;
}
int practice_bonus()
{
	return 5;
}
int black_white_ness()
{
	return 20;
}

