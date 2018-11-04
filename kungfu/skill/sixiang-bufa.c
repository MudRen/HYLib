inherit SKILL;

string *dodge_msg = ({
    "ֻ��$nһ�С������������������ϱ�ֱ���������࣬�����$N��һ�С�\n",
    "$nһ����Ǭ�Ҳ���������ݳ�����֮Զ���ܿ���$N���������ơ�\n",
    "$nʹ�������𲽡�����һ��ƮȻ�ݳ��������ŵء�\n"
    "����$n����Ʈ����ʹ������������������һ�ݣ����ѱܿ���\n",
    "$n������ת��̫��������ٿ����һ��Ų�������ߣ��ܹ�����һ�С�\n",
    "����$n����һ�ã�һ�����㿲������$N��һ�����˸��ա�\n",
});

int valid_enable(string usage)
{
        return (usage == "dodge") ||
               (usage == "move");
}

int valid_learn(object me) { return 1; }

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int query_effect_dodge(object attacker, object me)
{
        int lvl;

        lvl = me->query_skill("sixiang-bufa", 1);
        if (lvl < 50)  return 0;
        if (lvl < 100) return 10;
        if (lvl < 150) return 20;
        if (lvl < 200) return 30;
        if (lvl < 250) return 40;
        return 50;
}

int practice_skill(object me)
{
        if( (int)me->query("qi") < 70 )
                return notify_fail("�������̫���ˣ����������󲽷���\n");

        if ((int)me->query("neili") < 80)
                return notify_fail("�������̫���ˣ�������ϰ���󲽷���\n");

        me->receive_damage("qi", 58);
        me->add("neili", -65);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"sixiang-bufa/" + action;
}
