#include <ansi.h>

inherit SKILL;

mapping *action = ({
([   "action" : "$N��¶΢Ц������$wһ����һ�С��������������Ⱪ��������$n��$l",
     "force"  : 50,
     "attack" : 15,
     "dodge"  : 10,
     "parry"  : 25,
     "damage" : 110,
     "lvl"    : 0,
     "skill_name" : "������",
     "damage_type":  "����"
]),
([   "action" : "$N����ͻ�������ж��䣬һ�С���������������$w����λ����$n��$l",
     "force"  : 70,
     "attack" : 25,
     "dodge"  : 25,
     "parry"  : 30,
     "damage" : 115,
     "lvl"    : 20,
     "skill_name" : "������",
     "damage_type":  "����"
]),
([   "action" : "$Nһ�С�Ե���������������ߣ����׸������������$w��Ȼ���ϣ�����$n��$l",
     "force"  : 75,
     "attack" : 33,
     "dodge"  : 22,
     "parry"  : 32,
     "damage" : 120,
     "lvl"    : 40,
     "skill_name" : "Ե����",
     "damage_type":  "����"
]),
([   "action" : "$N����һ�μ��Ӷ��ϣ�����$w����һ����һ�С�������������׼$n$l��������",
     "force"  : 90,
     "attack" : 39,
     "dodge"  : 40,
     "parry"  : 35,
     "damage" : 125,
     "lvl"    : 60,
     "skill_name" : "������",
     "damage_type":  "����"
]),
([   "action" : "$Nһ�С��������������$n����Ӱ���棬����$w���Ȼ��������$n��$l��ȥ",
     "force"  : 100,
     "attack" : 43,
     "dodge"  : 60,
     "parry"  : 40,
     "damage" : 125,
     "lvl"    : 80,
     "skill_name" : "�������",
     "damage_type":  "����"
]),
([   "action" : "$Nһ������һ�С�����������������$w����б������ֱָ$n��$l",
     "force"  : 130,
     "attack" : 51,
     "dodge"  : 50,
     "parry"  : 45,
     "damage" : 130,
     "lvl"    : 100,
     "skill_name" : "��������",
     "damage_type":  "����"
]),
([   "action" : "$N΢΢һ��ת������$wȴ�������´�����һ�С�Ǭ��������������$n��$l",
     "force"  : 150,
     "attack" : 62,
     "dodge"  : 40,
     "parry"  : 47,
     "damage" : 130,
     "lvl"    : 120,
     "skill_name" : "Ǭ������",
     "damage_type":  "����"
]),
});

int valid_enable(string usage) {return usage == "sword" || usage == "parry";}

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 200)
                return notify_fail("�������������\n");

        if ((int)me->query_skill("force") < 30)
                return notify_fail("����ڹ����̫ǳ��\n");

        if ((int)me->query_skill("sword", 1) < 20)
                return notify_fail("��Ļ���������򲻹����޷�ѧϰ����������\n");

        if ((int)me->query_skill("sword", 1) < (int)me->query_skill("wuliang-jian", 1))
                return notify_fail("��Ļ�������ˮƽ���ޣ��޷��������������������\n");

        return 1;
}

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
        int i, level;
        level   = (int) me->query_skill("wuliang-jian",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        object weapon;

        if ( ! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԡ�\n");

        if ((int)me->query("qi") < 30)
                return notify_fail("��������������޷���ϰ����������\n");

        if ((int)me->query("neili") < 50)
                return notify_fail("��������������޷���ϰ����������\n");
        
        me->add("qi", -20);
        me->add("neili", -30);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"wuliang-jian/" + action;
}
int query_effect_parry(object attacker, object me)
{
        int lvl;
        object weapon;

        if (! objectp(weapon = me->query_temp("weapon")))
                return 0;
                
        if ((string)weapon->query("skill_type") != "sword") 
                return 0;
                
        lvl = me->query_skill("wuliang-jian", 1);
        if (lvl < 80)  return 0;
        if (lvl < 200) return 50;
        if (lvl < 280) return 80;
        if (lvl < 350) return 100;
        return 120;
}
