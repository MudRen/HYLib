// zhaixinggong.c ժ�ǹ�  based on xiaoyaoyou.c
// modified by Venus Oct.1997
// by yucao

inherit SKILL;

string *dodge_msg = ({
    "$nһ��������ժ�ǡ���Ծ�����ߣ������$N��һ�С�\n",
    "$n�������һ�ݣ�ʹ��һ�С�ƮȻ���������ܹ���$N�Ĺ�����\n",
    "$nʹ����������ˮ����ǡ�ö����$N�Ĺ��ơ�\n",
    "$nһ�С�֯Ů���󡹣���̬����ض��˿�ȥ��\n"
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
   return notify_fail("�������̫���ˣ�������ժ�ǹ���\n");
    if (me->query_skill("zhaixinggong", 1) < 30)
   me->receive_damage("qi", 10);
    else if (me->query_skill("zhaixinggong", 1) < 60)
   me->receive_damage("qi", 20);
    else
   me->receive_damage("qi", 30);
    return 1;
}

