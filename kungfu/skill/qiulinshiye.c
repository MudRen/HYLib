// qiulinshiye.c ����ʰҶ

inherit SKILL;

string *dodge_msg = ({
	"ֻ��$n��һ��ͷ����������ʰҶ������׾ٵĶ��$N��һ�С�\n",
	"����$nĿ����ת��˫��΢�����Ų������ѱܿ���$N�Ĺ�����\n",
	"Ȼ��$n΢΢�Ʋ���ǰ���·�ֱ���й�ȴ��Ʈ��������$N�Ĺ���ȫ����ա�\n"
        "����$n��������Ҷ���裬�������$N�ĳ���Ʈ��������Ҫ���У�ȴ�����\n",
        "����$n������ת���·���ͥɢ������ȴ�����������⣬��������һ�С�\n",
	"$n�������ĵ���������һ�����պñܹ�$N���������ơ�\n",
	"����$nǡ����������һ���������$N��һ�С�\n",
	"ֻ��$nһ�С��׺׳��졹���������ϱ�ֱ���������࣬�����$N��һ�С�\n",
	"$nһ�������ӷ���������ݳ�����֮Զ���ܿ���$N���������ơ�\n",
	"$nʹ��������չ�᡹����һ��ƮȻ�ݳ��������ŵء�\n"
        "����$n����Ʈ��������һ�ݣ����ѱܿ���\n",
       "$n������ת��ٿ����һ��Ų�������ߣ��ܹ�����һ�С�\n",
        "����$n����һ�ã�$N��һ�����˸��ա�\n",
        "ȴ��$n�㲻��أ����Դܿ����ߣ����˿�ȥ��\n",
        "$n����΢�Σ��о����յرܿ���$N��һ�С�\n"
        });

int valid_enable(string usage) 
{ 
	return (usage == "dodge") || (usage == "move"); 
}

int valid_learn(object me) { return 1; }

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
        if( (int)me->query("qi") < 40 )
                return notify_fail("�������̫���ˣ�����������ʰҶ��\n");
        me->receive_damage("qi", 30);
        return 1;
}
string perform_action_file(string action)
{
		return __DIR__"qiulinshiye/" + action;
}