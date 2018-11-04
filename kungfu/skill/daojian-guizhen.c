// daojian-guizhen.c ��������
// Edit By Vin 11/2/2001

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action" : "$N����$w�������ƶ������������ʩһ�С�" HIW "�Ʋ���"
                   "��" NOR "��������ͬʱ��ʩչ\n����" HIY "ϴ�����б���"
                   NOR "������������ͬʱ����$n$l��ȥ",
        "force" : 410,
        "attack": 70,
        "dodge" : 60,
        "parry" : 80,
        "damage": 470,
        "damage_type" : "����",
]),
([      "action" : "$Nһ�С�" HIY "����ת������" NOR "������$n���̳���"
                   "������Ȼ���ֱ���Ϊ��" HIW "ɳŸ�Ӳ�" NOR "����\n����"
                   "���ϻ������뻡�ε�â��������â��$w����һ���׹�����$n",
        "force" : 560,
        "attack": 30,
        "dodge" : 30,
        "parry" : 70,
        "damage": 480,
        "damage_type" : "����",
]),
([      "action" : "$N��ɫ΢�䣬һ�С�" HIY "���ﳯ��" NOR "������ʽ"
                   "��ʱ��������ޱȣ�����ʹһ�С�" HIW "��������" NOR
                   "����\n��$w���������һ��ѹ��$n",
        "force" : 490,
        "attack": 70,
        "dodge" : 60,
        "parry" : 180,
        "damage": 390,
        "damage_type" : "����",
]),
([      "action" : "$Nʹһ�к��ҵ����ġ�" HIW "��������" NOR "����$w��"
                   "������Ļ���б����ն��������\n��;��ɲ�Ǽ��Ȼֻ����"
                   "��һ��������$N��һ����ҽ���֮��" HIY "ӭ���ȷ�����"
                   "ɽ" NOR "����\nȴ��$w��â��˸�������Ѿ���������",
        "force" : 530,
        "attack": 50,
        "dodge" : 50,
        "parry" : 80,
        "damage": 370,
        "damage_type" : "����",
]),
([      "action" : "$N�ͺ�һ����һ�к��ҵ�����" HIW "��´���" NOR "��"
                   "����ҽ�����" HIY "������´���" NOR "��������\n$w��"
                   "�ּ�������������ת��Ծ��һ���׹�����$n���ؿ�",
        "force" : 470,
        "attack": 50,
        "dodge" : 70,
        "parry" : 40,
        "damage": 380,
        "damage_type" : "����",
]),
([      "action" : "ֻ��$N����$w���͡���һ��б������գ��漴�����¡��"
                   "ৡ����£����Һ�\nն��������ʱ�ó�һ��������ʮ�֣���"
                   "$nӿ�������Ǻ��ҵ����С�" HIW "�׺����" NOR "��\n��"
                   "����ҽ����С�" HIY "���ý��׺����" NOR "���ľ���",
        "force" : 430,
        "attack": 90,
        "dodge" : 80,
        "parry" : 140,
        "damage": 430,
        "damage_type" : "����",
]),
([      "action" : "$Nһ�С�" HIY "�ϲ��Ʊ�ժ��" NOR "��������Ծ�𣬲�"
                   "����Ӱ����Ȼ��ȴ��$w�Ӱ���д���\n���С�" HIW "��"
                   "����ů" NOR "�������Ծ����أ�$w˳����ǰ����Х����"
                   "��$n��$l",
        "force" : 510,
        "attack": 80,
        "dodge" : 70,
        "parry" : 80,
        "damage": 400,
        "damage_type" : "����",
]),
([      "action" : "ֻ��$Nһ�С�" HIY "���������ر���" NOR "����������"
                   "��������$w�͵����·�����ɲʱ\n�ֳ�ɱ�š�" HIW "�˷�"
                   "�ص���" NOR "������ʱ���������������䵶��������˷�"
                   "ӿ��$nȫ��",
        "force" : 530,
        "attack": 90,
        "dodge" : 80,
        "parry" : 80,
        "damage": 580,
        "damage_type" : "����",
]),
});

string main_skill() { return "daojian-guizhen"; }

mapping sub_skills = ([
        "miaojia-jian" : 250,
        "hujia-daofa"  : 250,
]);

int get_ready(object me)
{
        return 1;
}

int get_finish(object me)
{
        object ob;

        if( ! (ob = me->query_temp("weapon"))
           || (string)ob->query("skill_type") != "sword"
           && (string)ob->query("skill_type") != "blade" )
        {
                tell_object(me, "��������˰��죬���ֲ��ðѵ����ǽ�ʵ��"
                                "����������\n");
                return 0;
        }



        if (me->query("int") < 35)
        {
                tell_object(me, "��������ϣ�ֻ�н����͵�������ǣ������"
                                "����������ԣ��޷������һ��\n");
                return 0;
        }

        if (me->query("dex") < 25)
        {
                tell_object(me, "��������ϣ�ֻ�����Լ������鶯�ԣ���"
                                "���޷������ߺ�һ��\n");
                return 0;
        }

        if (me->query_skill("literate", 1) < 200)
        {
                tell_object(me, "�������ҽ����ͺ��ҵ�����������£���"
                                "�����о�һ��ѧ�ʿ��ܸ��а�����\n");
                return 0;
        }

        if (me->query_skill("martial-cognize", 1) < 250)
        {
                tell_object(me, "��������ϣ������Լ�����ѧ�����д����"
                                "�������޷������ߺ�һ��\n");
                return 0;
        }

        if ((int)me->query("max_neili") < 4500)
        {
                tell_object(me, "������Լ��������̣��޷�����ҽ����ͺ�"
                                "�ҵ������ߺ�һ��\n");
                return 0;
        }

        if (random(30) < 27)
        {
                tell_object(me, "������������򣬻���������һ�ξ����ڻ�"
                                "��ͨ�������ߺ�һ��\n");
                return 0;
        }

        tell_object(me, HIY "\nһ�󷲳�����ӿ����ͷ���㼸��������̾����"
                        "�Ǽ䣬��ҽ����ͺ��ҵ��������Ų�����\n���Ժ���"
                        "���֣������ڻ��ͨ���϶�Ϊһ��������ͨ���˵���"
                        "����ľ��ϡ�\n" NOR);
        return 1;
}

mapping query_sub_skills()
{
        return sub_skills;
}

int valid_enable(string usage)
{
	return usage == "sword" || usage == "blade" || usage == "parry";
}

int valid_learn(object me)
{
        object ob;
        int lvls, lvlb, lvld;

        lvls = me->query_skill("sword", 1);
        lvlb = me->query_skill("blade", 1);
        lvld = me->query_skill("daojian-guizhen", 1);

        if( ! (ob = me->query_temp("weapon"))
           || (string)ob->query("skill_type") != "sword"
           && (string)ob->query("skill_type") != "blade" )
                return notify_fail("���������һ������һ�������ܹ���ϰ��\n");

        if ((int)me->query_skill("miaojia-jian", 1) < 300)
                return notify_fail("�����ҽ���ˮƽ���ޣ��޷�����������书��\n");

        if ((int)me->query_skill("baisheng-daofa", 1) < 300)
                return notify_fail("���baisheng-daofaˮƽ���ޣ��޷�����������书��\n");

        if ((int)me->query_skill("hujia-dao", 1) < 300)
                return notify_fail("��ĺ��ҵ���ˮƽ���ޣ��޷�����������书��\n");


        if (me->query("int") < 35)
                return notify_fail("���о��˰��죬ȴֻ�н����͵�������"
                                   "ǣ�����������Լ����ʲ��㡣\n");

        if (me->query("dex") < 25)
                return notify_fail("���о��˰��죬ֻ�����Լ������鶯"
                                   "�ԣ������޷���ϰ�����书��\n");

        if (me->query_skill("martial-cognize", 1) < 250)
                return notify_fail("�������ҽ����ͺ��ҵ������������"
                                   "�������Լ���ѧ����������⡣\n");

        if ((int)me->query("max_neili") < 4500)
                return notify_fail("�������̫�����޷�����ҽ����ͺ���"
                                   "�������ߺ�һѧϰ��\n");

        if (lvls < 280 || lvlb < 280)
                return notify_fail("��ĵ�����������㣬������������"
                                   "���档\n");

        // �����ͽ��������ڵ�������
        if (lvls < lvld && lvlb < lvld)
                return notify_fail("��ĵ�����������㣬�޷�������"
                                   "��ĵ������档\n");

        // �����ͽ�������һ���ڵ�������
        if (lvls < lvld || lvlb < lvld)
        {
                // ����������Ϊ��ѧ����ʦ���һ��������������ȼ���
                // ���� 320 ������ֻ��Ҫ����֮һ֧�ּ���
                if (! userp(me) || lvls < 320 || lvlb < 320)
                        return notify_fail("��ĵ����򽣷�����㣬��"
                                           "����������ĵ������档\n");
        }
        return 1;
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 100)
                return notify_fail("��������������������档\n");

        if ((int)me->query("neili") < 100)
                return notify_fail("��������������������档\n");

        me->receive_damage("qi", 85);
        me->add("neili", 85);
        return 1;
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

void skill_improved(object me)
{
        int i;
        string *sub_skillnames;

        sub_skillnames = keys(sub_skills);

        for (i = 0; i < sizeof(sub_skillnames); i++)
                me->delete_skill(sub_skillnames[i]);
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        if (damage_bonus < 30)
                return 0;

        if (damage_bonus < victim->query_int())
                return 0;

        // if (me->query_temp("daojian-guizhen/max_pfm"))
        {
                victim->receive_wound("qi", (damage_bonus - 80) / 2+10, me);
                return random(2) ? HIR "ֻ�������͡�һ����һ����Ѫ��$n"
                                   HIR "��ǰ�����\n" NOR:

                                   HIR "��ʱֻ������һ����һ����Ѫ��$n"
                                   HIR "��ǰ�����\n" NOR;
        }
}

string perform_action_file(string action)
{
        return __DIR__"daojian-guizhen/" + action; 
}

int query_effect_parry(object attacker, object me) 
{
        int lvl;
        if (! objectp(me->query_temp("weapon")))
                return 0;

        lvl = me->query_skill("daojian-guizhen", 1);
        if (lvl < 80)  return 0;
        if (lvl < 200) return 50;
        if (lvl < 280) return 80;
        if (lvl < 350) return 100;
        return 120;
}

mixed ob_hit(object ob, object me, int damage, object weapon)
{
        mixed result;
        int ap, dp, mp, level;
string msg;
        if ((level = (int)me->query_skill("daojian-guizhen", 1)) < 100 ||
            ! living(me) || ! objectp(me->query_temp("weapon")))
                return;

        mp = ob->query_skill("count", 1);
        ap = ob->query_skill("force") + mp;
        dp = me->query_skill("parry", 1) / 2 +
             me->query_skill("daojian-guizhen", 1);

        if (ap / 2 + random(ap) < dp || random(8)==0)
        {
                result = ([ "damage": -damage ]);

                result += (["msg" : HIC "$n" HIC "ͻȻʹ��һ�С���ѩ�׷ס��������򳤰�â���������䣬ֱ����$N"
                            "������Ϊ���ƣ���$N����������\n" NOR]);
                        msg=HIC "$N" HIC "ͻȻʹ��һ�С���ѩ�׷ס��������򳤰�â���������䣬ֱ����$n"
                            "������Ϊ���ƣ���$n����������\n" NOR;
                		COMBAT_D->do_attack(me, ob, me->query_temp("weapon"));
                		COMBAT_D->do_attack(me, ob, me->query_temp("weapon"));
                //return result;
damage=damage/3;
message_vision(msg, me, ob);
        } 
return damage;
}
