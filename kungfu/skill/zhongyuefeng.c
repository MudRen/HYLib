// zhongyuefeng.c �������

inherit SKILL;

string *dodge_msg = ({
       "$nһʽ�����������������˷�����ȫ�������ǰһ�ݣ��������磬ǡ���ӹ�$N�Ĺ��ơ�\n",
       "$n��Ȼȫ���ڿ���һŤ��һת������һ��ƽ�ɣ�һʽ��ɽ���硹����$N�Ĺ�������������Ӱ֮�С�\n",
       "$n��������һƮ��һֻ�ź�Ȼ�����$N�����ϣ���һʽ�����ھ�����������$N�����\n",
       "$n�������Σ�������������һ̧һ�䣬һ�С��������䡹����ʵ֮�仯ȥ��$N����ʽ��\n",
});

int valid_enable(string usage) { return (usage == "dodge"); }

int valid_learn(object me) { return 1; }

string query_dodge_msg()
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
        if( (int)me->query("jing") < 40 )
                return notify_fail("�������̫���ˣ�������ϰ������硣\n");
        me->receive_damage("jing", 30);
        return 1;
}

