// pmshenfa.c Ʈ����
// written by Xiang

inherit SKILL;

string *dodge_msg = ({
        "ֻ��$n������ת��һŤ����Ʈ��$N���󣬶������һ�С�\n",
        "$n������ħ������Ӱ���缲�����ܣ���$N�Ĺ���ȫ����ա�\n",
        "$Nֻ����ǰһ����$n�ѻû�������������ɢ���䡣\n"
        "$n��Ӱͻ�����ݼ�ת���γ����ҵ��������У�������ǽ��$N�����޴����֡�\n",
        "$nһ�С�ħ����Ӱ����ȫ����ǧ�ٸ���Ӱ��������$N��һ�С�\n",
        "$n���۵��һ�С�����ħ�¡������μ������㿪$N������һ����\n",
        "$n������������Х������һ�С�ħ�����¡����������⡣\n",
        "$n˫����̤������һ�С�ħ���컡��������ޱ�����ص������ߡ�\n",
        "$nʹ��������ħ�����˲��еġ�ħӰ��á������λ�ʵΪ��ض㿪��$N��һ�С�\n",
        "$n�ڿ�һԾ��˫�������̤��һ�С�ħ�����������㿪���ߡ�\n",
        "$n���λζ���һ�С�ħ���¡����ȫ����������Ӱ�ӳ����⡣\n",
        "$n����һ������һ�С���ħ���Ρ���������һ���ޱȹ��������Ť���ŵ������ߡ�\n"
});

int valid_enable(string usage) { return (usage == "dodge") || (usage == "move"); }

int valid_learn(object me) { return 1; }

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
        if( (int)me->query("qi") < 40 )
                return notify_fail("�������̫���ˣ�������Ʈ������\n");
        me->receive_damage("qi", 30);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"pmshenfa/" + action;
}