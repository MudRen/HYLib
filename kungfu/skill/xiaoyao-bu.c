// xiaoyao-bu.c ��ң��
// pal 1997.05.26

inherit SKILL;

string *dodge_msg = ({
	"ֻ��$nһ�С������졹�����ζ�Ȼ���𣬶����$N��һ�С�\n",
	"$nһʽ��ӣ���䡹�����λζ�����һ��Ʈ�����ܿ���$N��һ�С���\n",
	"$nʹ��������硹��һ�����Ľ��󷭳����ܿ���$N���������ơ�\n",
	"$nһ�С�����������������ת��$Nֻ����ǰһ����$n������$N�����\n",
	
});

int valid_enable(string usage)
{
	return (usage == "dodge");
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
                return notify_fail("�������̫���ˣ���������ң����\n");
        me->receive_damage("qi", 30);
        return 1;
}

