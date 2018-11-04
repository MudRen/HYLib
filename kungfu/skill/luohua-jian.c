// luohua-jian.c �컨ʮ����
// cleansword 2/15/96
// Marz 5/21/96

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }


mapping *action = ({
([	"action" : "$N��շ�������һ������,һ�С�ˮ���ؾ��仨������
���������ͬǧ��㺮�ǣ���$n��ͷ����",
	"force" : 50,
	"dodge" : 5,
	"parry" : 10,
        "damage" : 250,
        "lvl" : 0,
	"damage_type" : "����"
]),
([	"action" : "$N�����ǰһ�������ֵ��ƻ��أ���������һ����$w��
�Ϸ��ã�һʽ������������ƻ�������$n��$l",
	"force" : 70,
	"dodge" : 2,
	"parry" : 30,
        "damage" : 260,
        "lvl" : 8,
	"damage_type" : "����"
]),
([	"action" : "$N������߳һ��������$w����һ��,�������ϲ������࣬һ��
����������̤�仨��$w�Ӹ���������������$n��$l",
	"force" : 90,
	"dodge" : 10,
	"parry" : 40,
        "damage" : 270,
        "lvl" : 12,
	"damage_type" : "����"
]),
([	"action" : "$N˫�Ų������ˣ���������̩ɽ������΢����ɽ�����
����$w�����һʽ������������÷������ֻ��������
��׷׵������$n��$l"
,
        "force" : 100,
	"dodge" : 0,
	"parry" : 40,
        "damage" : 280,
        "lvl" : 15,
	"damage_type" : "����"
]),
([	"action" : "$N����һ��������һ�С������ҡ��ҹ����,����$wҡ
ҷ����,�������޵Ĵ���$n,",
	"force" : 100,
	"dodge" : 10,
	"parry" : 50,
        "damage" : 290,
	"lvl" : 20,
	"damage_type" : "����"
]),
([	"action" : "$N˫Ŀֱ��$n�����ּ��죬������ͬʱ��ס$w��������
����һ�С���Ϊ�������仨����$w�󿪴��أ���$n��$l
ֱ����ȥ",
	"force" : 100,
	"dodge" : 10,
	"parry" : 50,
        "damage" : 300,
        "lvl" : 35,
	"damage_type" : "����"
]),
([	"action" : "ֻ��$N���Ҳ壬������˸����,һ�С����ֺ����Ͳл���,$w
����Ļ���һ����Ȧ������.��..�����죬����$n��$l",
	"force" : 100,
	"dodge" : 5,
	"parry" : 55,
        "damage" : 310,
	"lvl" : 45,
	"damage_type" : "����"
]),
([	"action" : "$N�����Դ죬һ�С������޴����ɻ������ֻ���,ֻ��
���͡���һ����һ���������$n��$l",
	"force" : 100,
	"dodge" : 0,
	"parry" : 55,
        "damage" : 320,
	"lvl" : 50,
	"damage_type" : "����"
]),
([	"action" : "$Nһ����߳�����Ⱪ����һ�С���ҡ����ѣ������,����ͻ
��������$w���糤����ӣ��������ϣ�ӿ��$n��$l",
	"force" : 180,
	"dodge" : 15,
	"parry" : 55,
        "damage" : 330,
	"lvl" : 70,
	"damage_type" : "����"
]),
([	"action" : "$Nһ����Х���ұ�һ��һ�С������ٳؿ��仨��������$w
������֮�����ֶ�����$nֻ��һ�������Ľ����������",
	"force" : 200,
	"dodge" : 5,
	"parry" : 60,
        "damage" : 340,
        "lvl" : 85,
	"damage_type" : "����"
]),
([
	"action" : "$N����һת��һ�С�������ѩӳ÷����,�������£�$w
��ͻ���³����೤�Ľ�â��������,����$n��$l",
	"force" : 200,
	"dodge" : 5,
	"parry" : 60,
        "damage" : 350,
	"lvl" : 100,
	"damage_type" : "����"
]), 
([      "action" : "$N˫üһ�����ɱ����ʢ��һ�С����Ŵ������������
��Žż��أ��ҽ�Ѹ����ǰ̤��һ����ֻ��$N
������$w�϶�Ϊһ��ֱ��$n��ȥ",     
        "force" : 200,
        "dodge" : 10,
        "parry" : 60,
        "damage" : 360,
        "lvl" : 120,
        "damage_type" : "����"
]),
([	"action" : "$N��Ԫ��һ�������ڱۣ�һ�С��˼䴦���к컨��,ֻ
�����������������｣���ݺᣬ$n����Ҫ͸��������",
	"force" : 250,
	"dodge" : -1,
	"parry" : 70,
        "damage" : 380,
	"lvl" : 150,
	"damage_type" : "����"

]),
});


int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������������\n");
	return 1;
}

mapping query_action(object me, object weapon)
{
	int i, level;
	level   = (int) me->query_skill("luohua-jian",1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];

}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");
        if ((int)me->query("jing") < 100)
                return notify_fail("��ľ������������书��\n");
        if ((int)me->query("qi") < 100)
                return notify_fail("����������������书��\n");
        if ((int)me->query("neili") < 100)
                return notify_fail("����������������书��\n");
        me->receive_damage("qi", 50);
        me->receive_damage("jing", 50);
        me->add("neili", -50);

	return 1;
}

mixed hit_ob(object me, object victim,int damage_bonus)
        
{       
        int i, level;
        object target;
object weapon;
        level   = (int) me->query_skill("honghua-shengong",1);
//        target = me->select_opponent();
        weapon = me->query_temp("weapon");
if (level >= 100)
{
        if( random(12)==1 || random(level) > 180)
        {
        if (userp(victim))
        victim->receive_wound("qi", (damage_bonus+level+100) ); 
        return RED "���仨׷��!!����$N�������ˣ�����$w��ָ������$n������·!\n" NOR;
        }
if (damage_bonus < 60) damage_bonus=60;
        if( random(12)==1 || random(level) > 90  )
        {
        victim->receive_wound("qi", damage_bonus );     
        return RED "�仨׷�꽣��һ����Ѫ��$n���������!\n" NOR;
  }
}
}


string perform_action_file(string action)
{
	return __DIR__"luohua-jian/" + action;
}
