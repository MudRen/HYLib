// qingfu-shenfa.c ������
// pal 1997.05.26

inherit SKILL;

string *dodge_msg = ({
	"ֻ��$nһ�С�����Ǭ���������ζ�Ȼ���𣬶����$N��һ�С�\n",
	"$nһʽ���������١������λζ�����һ��Ʈ�����ܿ���$N��һ�С���\n"
	"$nʹ�������츣�ء���һ�����Ľ��󷭳����ܿ���$N���������ơ�\n",
	"$nһ�С��������𡹣�������ת��$Nֻ����ǰһ����$n������$N�����\n",
});

int valid_enable(string usage)
{
	return (usage == "dodge") || (usage == "move");
}

int valid_learn(object me)
{
	return 1;
}

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
        if( (int)me->query("qi") < 40 )
                return notify_fail("�������̫���ˣ���������������\n");
        me->receive_damage("qi", 30);
        return 1;
}

string perform_action_file(string action)
{
	return __DIR__"qingfu-shenfa/" + action;
}
