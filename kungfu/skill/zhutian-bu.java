// zhutian-bu.c ���컯��

inherit SKILL;

mapping *action = ({
([      "action" : "$nһʽ����ع������εض��𣬺���һ���շ���ƮȻ���ڼ���Զ�ĵط���\n",
        "dodge"  : 10
]),
([      "action" : "$nһʽ�����ͷ������������������һ����磬��$Nͷ����Ծ������\n",
        "dodge"  : 20
]),
([      "action" : "$nһʽ��ӥצ�ɡ���������һֻ��ӥ���ڿն����滺��������$N���������ơ�\n",
        "dodge"  : 30
]),
([      "action" : "$nһʽ������������������������ڶ�������Ʈ����һ��Զ\n",
        "dodge"  : 50
]),
([      "action" : "$nһʽ������������˫�ŵ�أ�ȫ��Ϊһ����Ӱ��ٿ�İεض�����$N�������ӡ�\n",
        "dodge"  : 80
]),
([      "action" : "$nһʽ�����¿ۡ������ζ��ر��Ʈ����������ˮ��ػ������ࡣ\n",
        "dodge"  : 110
]),
});

mapping query_action(object me, object weapon)
{
        int zhaoshu, level;

        zhaoshu = sizeof(action);
        level   = (int) me->query_skill("zhutian-bu");

        if (level < 80 )
                zhaoshu--;

        if (level < 60 )
                zhaoshu--;

        if (level < 40 )
                zhaoshu--;

        return action[random(zhaoshu)];
}

int valid_enable(string usage)
{
        return usage == "dodge" || usage == "move";
}

int valid_learn(object me)
{
        return 1;
}

string query_dodge_msg(string limb)
{
        object me, ob;
        mapping action;

        me = this_player();
        action = query_action(me, ob);

        return action["action"];
}

int practice_skill(object me)
{
        if( !me->query_skill("linji-zhuang",1))
                return notify_fail("�������컯��������Ҫ�ԡ��ټ�ʮ��ׯ��Ϊ������\n");


        if( (int)me->query("qi") < 40 )
                return notify_fail("�������̫���ˣ������������컯������\n");
        me->receive_damage("qi", 30);
        return 1;
}

