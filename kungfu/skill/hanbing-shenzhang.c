// hanbing-shenzhang.c  ��������
#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action" : "ȴ��$N����һ�����������ֵ��Ƶ����Է������������˺������������֣����ʳ�ж�ָ��$n$l��ȥ",
        "force" : 300,
        "dodge" : 10,
        "damage" : 250,
        "damage_type" : "����",
        "lvl" : 0,
]),
([      "action" : "$N���Ƶ���$n�����Ƽ����ھ�����$p����ֱ�����£���һ�ƾӸ����£����Ӻ��磬�Ƶ��澢",
        "force" : 350,
        "dodge" : 5,
        "damage" : 250,
        "damage_type" : "����",
        "lvl" : 10,
]),
([      "action" : "$N����һ�����������Ʒֱ��ĳ�����̬����̫��ȭ��ʮ���֣����漴������ȴ����������ĺ���",
        "force" : 310,
        "dodge" : 20,
        "damage" : 250,
        "damage_type" : "����",
        "lvl" : 30,
]),
([      "action" : "$N����ȫȻ�����·磬˫�۳��м��̣�������һ�߱㼴���أ�����ֻ�ز�������ͻȻ����һ�죬����$n",
        "force" : 400,
        "dodge" : 5,
        "damage" : 250,
        "damage_type" : "����",
        "lvl" : 50,
]),
([      "action" : "$N������ָ��ָ���Ƶ�$n������������������ָ��$p��������һ̧����Ȼ����$p$l�������������",
        "force" : 450,
        "dodge" : 10,
        "damage_type" : "����",
        "damage" : 250,
        "lvl" : 70,
]),

});

int valid_enable(string usage) { return usage=="strike" ||  usage=="parry"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("���������Ʊ�����֡�\n");
        if ((int)me->query_skill("songshan-qigong", 1) < 140)
                return notify_fail("�����ɽ������򲻹����޷�ѧ�������ơ�\n");
        if ((int)me->query_skill("songyang-zhang", 1) < 140)
                return notify_fail("��Ĵ������ƻ�򲻹����޷�ѧ�������ơ�\n");
        if ((int)me->query("max_neili") < 2000)
                return notify_fail("�������̫�����޷����������ơ�\n");
        return 1;
}

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}
int valid_combine(string combo) { return combo=="songyang-shou"; }
mapping query_action(object me, object weapon)
{
        int i, level;
        level = (int)me->query_skill("hanbing-shenzhang", 1);
        if (me->query_temp("ss_feiwu") == 2){
            return([      
                   "action": HIW "������$N"HIW"����һ��һ�գ���$n"HIW"��û�з�Ӧ����ʱ������ǰ�����𡸺����������������һ�ơ���"NOR,        
                   "force" : 480,
                   "dodge" : 40,
        "damage" : 650,
                   "damage_type" : "����",
                   ]);
            }
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        int lvl = me->query_skill("hanbing-shenzhang", 1);
        int i = sizeof(action);
        while (i--) if (lvl == action[i]["lvl"]) return 0;
        
        if ((int)me->query("jing") < 70)
                return notify_fail("��ľ���̫���ˡ�\n");
        if ((int)me->query("neili") < 20)
                return notify_fail("��������������������ơ�\n");
        me->receive_damage("jing", 50);
        me->receive_damage("neili", 10);
        if(me->query_skill("hanbing-shenzhang", 1) > 160)
                me->receive_damage("jing", 10);
        if(me->query_skill("hanbing-shenzhang", 1) > 190)
                me->receive_damage("neili", 5);
        return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        if( random(me->query_skill("hanbing-shenzhang")) > 45) {
                  victim->apply_condition("cold_poison", random(3) + 2 +
                        victim->query_condition("cold_poison"));
        }
        if (me->query_temp("ss_feiwu"))
                  victim->apply_condition("cold_poison", 30 +
                        victim->query_condition("cold_poison"));
}

string perform_action_file(string action)
{
	return __DIR__"hanbing-shenzhang/" + action;
}

