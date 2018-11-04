// shenzhao-jing.c ���վ�
#include <ansi.h>
inherit FORCE;

void create() { seteuid(getuid()); }

//string type() { return "knowledge"; }

int valid_learn(object me)
{
	int lev;

	lev = (int)me->query_skill("shenzhao-jing", 1);

	if (!me->query("szj/passed"))
		return notify_fail("����ͼѧϰ���վ������ƺ����޽�չ��\n");
	if (!me->query("szj/over200") && lev > 200)
		return notify_fail("�������ζ�����δͨ���޷���ϰ����������վ��ķ���\n");
	if ((int)me->query_skill("force", 1) < 150)
		return notify_fail("��Ļ����ڹ���򲻹����޷�ѧϰ���վ��ķ���\n");
	if (lev > (int)me->query_skill("force", 1))
		return notify_fail("��Ļ����ڹ���򲻹����޷�ѧϰ���վ��ķ���\n");
	return 1;
}

int practice_skill(object me)
{
	return notify_fail("���վ�ֻ�ܿ�ѧϰ����ߡ�\n");
}


void skill_improved(object me)
{
	tell_object(me, HIW"\n�������վ�����ߣ���ͻȻ���ֵ��������Ϣ���ӳ��棡\n\n"NOR);
	me->add("max_neili", 1 + random(2));
}
mapping *action = ({
([      "action" : "$NٿȻԾ��������һȭ����һȭ������Ӱ��ȥ�ƿ켫����$n���ؿڴ�ȥ",
        "dodge"  : 81,
        "force"  : 323,
        "attack" : 119,
        "parry"  : 94,
        "damage" : 268,
        "lvl"    : 0,
        "damage_type": "����" 
]), 
([      "action" : "$N˿��������ɫ������ƽ�죬�����������վ��񹦵ľ���������һ������$n",
        "dodge"  : 73,
        "force"  : 362,
        "attack" : 138,
        "parry"  : 51,
        "damage" : 273,
        "lvl"    : 200,
        "damage_type": "����"
]), 
([      "action" : "$N����΢΢һչ����Ȼ������$n��ǰ����Ȼ��˫����ʩ����$n���Ķ�ȥ",
        "dodge"  : 78,
        "force"  : 389,
        "attack" : 152,
        "parry"  : 53,
        "damage" : 87,
        "lvl"    : 220,
        "damage_type": "����"
]),
([      "action" : "$N�˺�һ����˫�ƻ��գ���ջ���һ��ԲȦ����ʱһ�����ȵ�����ֱӿ$n����",
        "dodge"  : 75,
        "force"  : 410,
        "attack" : 163,
        "parry"  : 67,
        "damage" : 293,
        "lvl"    : 250,
        "damage_type": "����"
]), 
});

int valid_enable(string usage)
{ 
        int lvl;
        lvl = (int)this_player()->query_skill("shenzhao-jing", 1);

        if(lvl >= 180)    
                return usage == "force" || usage == "unarmed" || usage == "parry";
        else
                return usage == "force";
       
}mapping query_action(object me, object weapon)
{
        int i, level;
        level = (int) me->query_skill("shenzhao-jing", 1);
        for (i = sizeof(action); i > 0; i--)
                if (level > action[i-1]["lvl"])
                        return action[NewRandom(i, 50, level)];
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int lvl;

        lvl = me->query_skill("shenzhao-jing", 1);

        if (damage_bonus < 60
           || lvl < 180
           || me->query("neili") < 300
           || me->query_temp("weapon")
           || me->query_temp("secondary_weapon")
           || me->query_skill_mapped("force") != "shenzhao-jing"
           || me->query_skill_mapped("unarmed") != "shenzhao-jing"
           || me->query_skill_prepared("unarmed") != "shenzhao-jing")
                return 0;

        // ���վ��������еļ���������˺���ʹ������
        // ����max_hit �������书���Ǿ��޽��еģ�����
        // �����ֵļ����Լ��˺�ֵ�ּ������˺��������
        // ���书��������
        if (damage_bonus / 6 > victim->query_con() || random(10)==0)
        {
               	victim->receive_wound("qi", (damage_bonus - 60) / 3+10, me);
                victim->receive_damage("qi", (damage_bonus - 60) / 3+10, me);
                victim->apply_condition("shenzhao",20);
               	return HIR "$n" HIR "һ���Һ���ȫ��������������"
                       "�����߹ǡ��۹ǡ��ȹ�ͬʱ���ۡ�\n" NOR;
        }
}

string perform_action_file(string action)
{
        return __DIR__"shenzhao-jing/perform/" + action;
}

string exert_function_file(string action)
{
        return __DIR__"shenzhao-jing/exert/" + action;
}
