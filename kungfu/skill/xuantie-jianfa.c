// ��������
#include <ansi.h>;

inherit SKILL;

string  *msg = ({
"$N����ƽƽ�̳�һ����ʵ���Ǻ����κα仯����ȴ�к��֮����$nֻ��һ�ɴ�����$wֱ������",
"$N���Ծ�����潣�𣬽�������֮����������һ������$n�������ڽ���֮��",
"$N��̾һ�������ֺ���һ��������ָ��$n��������˿���仯��ȴ���ý������裬����ƽ����
�̺����б仯������ʤ����",
"$NѸ������һ��������������磬�������磬�޿ɵ��棡�˽�֮�죬������˼���޷��ֱ潣·ȥ��",
"$N���׳�Х������Ʊ�ã������������һ��ƽָ������������$n���������$nֻ����
���κ���֮�У������и���$N�������纣��һ�㣬һ��һ������ӿ�������Ӳ�����������ǿ",
"$N����$w��������ɽ���������ǰ���ͺ�һ�������ǽ�������ġ�����ʽ�����������ǽ�Ӱ��
����ǧ��������ֻ��$n����ζ�",
"$N����ʮ�ལ��һʱѸ�������ǻ��գ�һʱ���سٻ��������޼���Ѱ��ƽ�������ַ�˼������
˳�̣�������������������޲��ǽ��������ţ����淵�ӹ��棬ȴ�Ѳ��ٴ��κ�����",
});

int valid_enable(string usage)
{
        return usage == "sword" || usage == "parry";
}mapping query_action(object me, object weapon)
{
        return ([
                "action":msg[random(sizeof(msg))],
                "damage":(random(2)+2)*220,
                "damage_type":random(2)?"����":"����",
                "dodge":(random(2)+2)*50,
                "force":(random(2)+2)*220
        ]);
}

int valid_learn(object me)
{
        return notify_fail("��ֻ��ͨ���������������������\n");
}
string perform_action_file(string action)
{
        return __DIR__"xuantie-jianfa/" + action;
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
        int lvl;
        object weapon = me->query_temp("weapon");

        lvl = me->query_skill("xuantie-jianfa", 1);

        if (damage_bonus < 50
           || lvl < 160
           || random(2)
              || ! objectp(weapon)
           || me->query("neili") < 500
           || me->query_skill_mapped("sword") != "xuantie-jianfa"
      		 || me->query_skill_mapped("force") != "yunv-xinfa")
      		return damage_bonus / 4;

        if (lvl / 2 + random(lvl) > victim->query_skill("parry", 1) || random(10)==0)
        {
                me->add("neili", -100);
                victim->receive_damage("qi", damage_bonus * 4 / 5+10, me);
                victim->receive_wound("qi", damage_bonus * 4 / 5+10, me);
      
                return HIW "$N" HIW "����" + weapon->name() + HIW "����������������£�����"
                       "�ɵ�������$n" HIW "�����ƻֺ�֮����\n" NOR;
         }
}
