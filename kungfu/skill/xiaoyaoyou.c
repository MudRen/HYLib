// xiaoyaoyou.c ��ң��
// modified by Venus Oct.1997
// written by Xiang

inherit SKILL;

string *dodge_msg = ({
    "$nһ�������ѵ�ˮ���������$N��һ�С�\n",
    "$n�������һ�ݣ�ʹ��һ�С�ϸ���ɷ��ơ����ܹ���$N�Ĺ�����\n",
    "$nʹ�����黳���ȡ���ǡ�ö����$N�Ĺ��ơ�\n"
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
   return notify_fail("�������̫���ˣ���������ң�Ρ�\n");
    me->receive_damage("qi", 30);
    return 1;
}
string perform_action_file(string action)
{
    return __DIR__"xiaoyaoyou/" + action;
}

