// guimei-shanfa ���������嶾�̣�

inherit SKILL;

string *dodge_msg = ({
	"ֻ��$n��ӰƮ������˸������ʹ$N�Ĺ���ȫ����ա�\n",
	"ȴ��$n����΢�Σ�����Ʈ�����ߣ������$N�Ĺ�����\n",
	"$n���������������м�ת����ƮƮ���ÿ���$N����һ�С�\n"
        "$n������ͬ����һ�㣬��ò������ۻ����ң���$N�޷����֡�\n",
    
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
                return notify_fail("�������̫���ˣ���������������\n");
        me->receive_damage("qi", 30);
        return 1;
}