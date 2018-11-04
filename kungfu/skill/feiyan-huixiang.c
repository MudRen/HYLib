// feiyan-huixiang.c �������
// modified by Venus Oct.1997
// pyrobat-steps.c
#include <ansi.h>
inherit SKILL;
#include <combat.h>
mapping *action = ({
([      "action" : "$n�������٣��������࣬һʽ���������᡹��ʱ�ܿ���$N���������ơ�\n",
        "dodge"  : 10
]),
([      "action" : "$n�����Ʈ����������ݣ����ɵ�һʽ��������ϼ����������$N�Ĺ��ơ�\n",
        "dodge"  : 20
]),
([      "action" : "$nһʽ���໲������������ƮƮ���λζ���һת�ۼ���Ƶ���$N�����\n",
        "dodge"  : 30
]),
([      "action" : "$n��ͷ������ȭһʽ��ȴ����ɡ���������󻬳�����$N�Ĺ��ƻ������Ρ�\n",
        "dodge"  : 40
]),
([      "action" : "$nʹ�������ճ���������ֱԾ���ڰ���л�Ϊ�������ա���Ʈ�䵽һ�ԡ�\n",
        "dodge"  : 50
]),
([      "action" : "$nһ�С��������ǡ����������Ҽ��ٻζ����ó�������Ӱ�����ݵ��ƽ�$N�Ĺ��ơ�\n",
        "dodge"  : 60
]),
([      "action" : "$n��ЦƮ��ʹ�����������Ρ������λó�һ����Ӱ����ƮƮ������$N����ࡣ\n",
        "dodge"  : 70
]),
([      "action" : "$n��������һ�С��������롹������������$N��ת��ʹ���޴����֣����Ʋ������ơ�\n",
        "dodge"  : 80
])
});
string *dodge_msg = ({
    "����$n����Ʈ��������һ�ݣ�һ�С�����Ͷ�֡�����������ıܿ���һ����\n",
    "$n������ת��һʽ��ѩ�����衹��ٿ����һ��Ʈ�����ߣ��ܹ�����һ�С�\n",
    "����$n����һ�ã�ʹ����������Ʈ����$N��һ�����˸��ա�\n",
    "ȴ��$n�㲻��أ�һ�С����Ƽ��������ε�����һת�������������ߣ����˿�ȥ��\n",
    "$n���һ���ҽű�����������һ�Σ�һ�С�һ�׳��졹���������ɵرܿ�����һ�С�\n"
});

int valid_enable(string usage)
{
    return (usage=="dodge") || (usage=="move");
}

int valid_learn(object me)
{
    return 1;
}

string query_dodge_msg(string limb)
{
        return action[random(sizeof(action))]["action"];

}


mapping query_action(object me, object weapon)
{
        int zhaoshu, level;

        zhaoshu = sizeof(action);
        level   = (int) me->query_skill("feiyan-huixiang");

        if (level < 60 )
                zhaoshu--;

        if (level < 50 )
                zhaoshu--;

        if (level < 40 )
                zhaoshu--;

        return action[random(zhaoshu)];
}

int practice_skill(object me)
{
    if( (int)me->query("qi") < 30 )
   return notify_fail("�������̫���ˣ��������������......\n");
    me->receive_damage("qi", 30);
    return 1;
}
string perform_action_file(string action)
{
    return __DIR__"feiyan-huixiang/" + action;
}