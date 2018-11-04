#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action" : "$N����б�ɣ�����$w�������$n����",
        "force"  : 60,
        "dodge"  : 20,
        "parry"  : 10,
        "damage" : 115,
        "damage_type" : "����"
]),
([      "action" : "$N��Ծ����$w��Ȼ�´̣�ֱ��$n�󲿵�����Ѩ",
        "force"  : 74,
        "dodge"  : 25,
        "parry"  : 13,
        "damage" : 119,
        "damage_type" : "����"
]),
([      "action" : "$N����$w���϶��·��̣�ģ����ֺ�ա�����̵صĹ⾰",
        "force"  : 86,
        "attack" : 27,
        "dodge"  : 15,
        "parry"  : 17,
        "damage" : 117,
        "damage_type" : "����"
]),
([      "action" : "$N����$w�������ػ�����ֻ�ϵ�$n�ۻ����ң��벻֪�Ӻι���",
        "force"  : 89,
        "attack" : 31,
        "dodge"  : 25,
        "parry"  : 25,
        "damage" : 121,
        "damage_type" : "����"
]),
([      "action" : "$N����$w��������һ�̣��������������һ�Σ�$w�Ѵ���$n��",
        "force"  : 107,
        "attack" : 38,
        "dodge"  : 30,
        "parry"  : 35,
        "damage" : 129,
        "damage_type" : "����"
]),
([      "action" : "$N���ƺ����ǰ��������$w����ӷ���ֱȡ$n������ҪѨ",
        "force"  : 130,
        "attack" : 29,
        "dodge"  : 35,
        "parry"  : 37,
        "damage" : 128,
        "damage_type" : "����"
]),
([      "action" : "$N����$w�й�ֱ�룬Я��ǿ��ľ�������$n��$l",
        "force"  : 160,
        "attack" : 42,
        "dodge"  : 45,
        "parry"  : 40,
        "damage" : 139,
        "damage_type" : "����"
]),
});

int valid_enable(string usage)
{
	return usage == "sword" || usage == "parry";
}

int valid_learn(object me)
{
        if ((int)me->query_skill("force") < 60)
                return notify_fail("����ڹ���򲻵����޷�ѧϰ����ʮ������\n");

        if ((int)me->query("neili") < 300)
                return notify_fail("�������̫��޷�ѧϰ����ʮ������\n");

        if (me->query_skill("sword", 1) < me->query_skill("shenmen-jian", 1))
                return notify_fail("��Ļ�������ˮƽ���ޣ��޷��������������ʮ������\n");
        if ((int)me->query_skill("raozhi-roujian", 1) < 30)
                return notify_fail("�����ָ�ὣ���̫ǳ��\n");

        if ((int)me->query_skill("taiji-jian", 1) < 30)
                return notify_fail("���̫�������̫ǳ��\n");

        return 1;
}

mapping query_action(object me, object weapon)
{
        int i, level;  
        level = (int) me->query_skill("shenmen-jian", 1);
        for (i = sizeof(action); i > 0; i--)
                if (level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level / 5)];

}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        object weapon;
        weapon = victim->query_temp("weapon");

if (random(5)==0 && me->query_skill("shenmen-jian", 1)> 80)
{
victim->receive_wound("qi", random(60)+20, me);
	return HIY "$N�������Ž���������$w"HIY"��ס������ͻȻƽ�̣����⼱��������������δ�����һ��������$n�����ߴ�ҪѨ\n" NOR;
}	

        if (! victim->query_temp("weapon")
           || ! living(victim)
           || me->query("max_neili") / 2 < victim->query("max_neili")
           || damage_bonus < 100
           || me->query("neili") < 500
           || me->query_skill("shenmen-jian", 1) < 80
           || victim->is_busy()
           || random(2) == 1)
                return 0;

        victim->start_busy(3);
        victim->receive_wound("qi", (damage_bonus - 100) / 4+20, me);
        weapon->move(environment(victim));

        return HIW "ͻȻ��$n" HIW "��$N" HIW "һ����������ҪѨ������" +
               weapon->name() + HIW "��Ҳץ�ò�ס���������ַɳ���\n" NOR;
}


mixed  ob_hit(object ob, object me, int damage, object weapon)
{
        mixed result;
        int ap, dp, mp,j;
        object m_weapon;

        if ((int) me->query_skill("shenmen-jian", 1) < 100 ||
            ! (m_weapon = me->query_temp("weapon")) ||
            ! living(me) || m_weapon->query("skill_type") != "sword")
                return;

        mp = ob->query_skill("sword", 1);
        ap = me->query_skill("shenmen-jian") + mp;
        dp = ob->query_skill("parry", 1) / 2 +
             ob->query_skill("dodge", 1);
        j=damage;
        if (ap / 2 + random(ap) > dp)
        {
                

                switch (random(3))
                {
                case 0:
                        result = HIC "$n" HIC "һ�����е�" + m_weapon->name() +
                                            HIC "��������һ��ԲȦ����Ȼ��$N" +
                                            HIC "�Ĺ���ȫȻ��ա�\n" NOR;
                        break;

                case 1:
                        result = HIC "$n" HIC "����" + m_weapon->name() + HIC
                                            "��������ָ��$N" HIC "�����е�������\n" NOR;
                        break;

                default:
                        result = HIC "$n" HIC "�ζ����е�" + m_weapon->name() +
                                            HIC "����ס�ı�ý��ƣ���$N"
                                            HIC "��ȫ�޷���׽��������\n" NOR;
                        break;
                }
                return result;
        j=0;
        } else
        if (mp >= 100)
        {
                switch (random(2))
                {
                case 0:
                        result = HIY "$n" HIY "һ�����е�" + m_weapon->name() +
                                 HIY "��������һ��ԲȦ��$N"
                                 HIY "��Ҳ������������ֱ�룬��Ϯ$n"
                                 HIY "��\n" NOR;
                        break;

                case 1:
                        result = HIY "$n" HIY "����" + m_weapon->name() + HIY "������"
                                 HIY "��ָ��$N" HIY "�����е�����������$N"
                                 HIY "����һ�䣬�������̲���Ϊ������\n" NOR;
                        break;

                default:
                        result = HIY "$n" HIY "�ζ����е�" + m_weapon->name() +
                                 HIY "����ס�ı�ý��ƣ�Ȼ��$N"
                                 HIY "������񣬾���������˿������$n"
                                 HIY "���Ի�\n"  NOR;
                        break;
                }
                //COMBAT_D->set_bhinfo(result);
        }
           message_vision(result, me, ob);
           return j;
}

int practice_skill(object me)
{
        object weapon;

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԡ�\n");

        if ((int)me->query("qi") < 65)
                return notify_fail("�����������������ʮ������\n");

        if ((int)me->query("neili") < 65)
                return notify_fail("�������������������ʮ������\n");

        me->receive_damage("qi", 52);
        me->add("neili", -58);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"shenmen-jian/" + action;
}

