// �嶷���� shenzhaojing.c
// Editd By Vin On 1/7/2001

#include <ansi.h>
inherit FORCE;

int valid_force(string force) { return 1; }
int query_neili_improve(object me)
{
        int lvl;

        lvl = (int)me->query_skill("wudoumi-shengong", 1);
        return lvl * lvl * 15 * 10 / 100 / 200;
}

mapping *action = ({
([      "action" : "$N�����嶷���񹦣���������$n��������ǰ����Ȼһȭ����$n����",
        "dodge"  : 31,
        "force"  : 323,
        "attack" : 89,
        "parry"  : 34,
        "damage" : 58,
        "lvl"    : 0,
        "damage_type": "����" 
]), 
([      "action" : "$N˿��������ɫ������ƽ�죬���������嶷���񹦵ľ���������һ������$n",
        "dodge"  : 43,
        "force"  : 362,
        "attack" : 103,
        "parry"  : 47,
        "damage" : 63,
        "lvl"    : 160,
        "damage_type": "����"
]), 
([      "action" : "$N����΢΢һչ��һ˫���Ʊ�������Ѫһ�㣬˫����ʩ������$nǰ��",
        "dodge"  : 48,
        "force"  : 413,
        "attack" : 122,
        "parry"  : 51,
        "damage" : 75,
        "lvl"    : 180,
        "damage_type": "����"
]),
([      "action" : "$Nһ����Х��˫�ƻ��գ���ջ���һ��ԲȦ����ʱһ������ֱӿ$n����",
        "dodge"  : 41,
        "force"  : 451,
        "attack" : 113,
        "parry"  : 47,
        "damage" : 83,
        "lvl"    : 200,
        "damage_type": "����"
]), 
});

int valid_enable(string usage)
{ 
        object me = this_player();

                return usage == "force" || usage=="unarmed" || usage =="parry";

       
}

int valid_learn(object me)
{


        if (me->query("con") < 24)
                return notify_fail("�㰴�շ�����ת������Ϣ����Ȼֻ������һ����ۡ�\n");

/*
        �����嶷���񹦵ķ�����������������ڵ��ڹ����������ߣ�������
        ʱ��Ϊ�������а������������ڹ������в�������������

        if (me->query("gender") == "����" && me->query("wudoumi-shengong", 1) > 29)
                return notify_fail("���޸����ԣ�����������������������嶷���񹦡�\n");
*/

        if ((int)me->query_skill("force", 1) < 50)
                return notify_fail("��Ļ����ڹ�����㣬����ѧ�嶷���񹦡�\n");

        if ((int)me->query_skill("unarmed", 1) < 50)
                return notify_fail("��Ļ���ȭ�Ż���㣬����ѧ�嶷���񹦡�\n");

        if ((int)me->query("max_neili", 1) < 500)
                return notify_fail("���������Ϊ���㣬����ѧ�嶷���񹦡�\n");

        if (me->query_skill("force", 1) < me->query_skill("wudoumi-shengong", 1))
                return notify_fail("��Ļ����ڹ�ˮƽ���������Զ����������嶷���񹦡�\n");



        return ::valid_learn(me);
}

mapping query_action(object me, object weapon)
{
        int i, level;
        level = (int)me->query_skill("wudoumi-shengong", 1);
        for (i = sizeof(action); i > 0; i--)
                if (level > action[i-1]["lvl"])
                        return action[NewRandom(i, 50, level)];
}

int practice_skill(object me)
{
        return notify_fail("�嶷����ֻ����ѧ(learn)�������������ȡ�\n");
}

void check_count(object me)
{
        if (me->query("max_neili") >= 3000 &&
            me->query("exception/wudoumi-count") > 1000)
        {
                me->apply_condition("wudoumi-fanshi",
                        me->query_condition("wudoumi-fanshi") +
                        me->query("exception/wudoumi-count") / 10);
                me->delete("exception/wudoumi-count");
        }
}

void skill_improved(object me)
{
        int level = (int)me->query_skill("wudoumi-shengong", 1);

        me->add("exception/wudoumi-count", level + 1);
        check_count(me);
}

int difficult_level()
{
        return 600;
}

string perform_action_file(string action)
{
        return __DIR__"wudoumi-shengong/perform/" + action;
}

string exert_function_file(string action)
{
        return __DIR__"wudoumi-shengong/exert/" + action;
}
