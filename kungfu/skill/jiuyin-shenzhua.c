// jiuyin-shenzhua.c ������צ

#include <ansi.h>
inherit SKILL;
mapping *action = ({
([ "action" : BLU"$N�����転������аħ��˫צ���ץ�������������󷭴������ּ��죬�����ָץ��$n$l"NOR,
   "force" : 150,
   "damage" : 30,
   "dodge" : 5,
   "lvl" : 0,
   "damage_type" : "ץ��"
]),
([ "action" : BLU"ͻȻ��Ӱ������$N�ȵ�$n�����������֣������ָ��$n$l������ȥ"NOR,
   "force" : 200,
   "weapon" : "��ָ",
   "damage" : 50,
   "dodge" : 10,
   "lvl" : 10,
   "damage_type" : "����"
]),
([ "action" : BLU"$N�ֱ۹ؽڿ���һ�죬�ֱ۶�Ȼ���˰�ߣ�һ�ư���$n$l����ָ��Ҫ���"NOR,
   "force" : 250,
   "weapon" : "��ָ",
   "damage" : 60,
   "dodge" : 5,
   "lvl" : 20,
   "damage_type" : "����"
]),
([ "action" : BLU"$N˫��΢�ţ�ʮ������ָ��ӳ���Ұ׹�æ��ͻȻ�����צ����ָ�͵ز���"NOR,
   "force" : 300,
   "weapon" : "��צ",
   "damage" : 70,
   "dodge" : 5,
   "lvl" : 30,
   "damage_type" : "����"
]),
([ "action" : BLU"$N����ͻȻ��$n��ǰ��Χ�¹���������ת���������߰˰㣬���������һ�죬�����ֱָ��$n$l"NOR,
   "force" : 350,
   "weapon" : "�����ָ",
   "damage" : 80,
   "dodge" : 5,
   "lvl" : 40,
   "damage_type" : "����"
]),
([  "action" : BLU "$N��צ��Σ���צ������һ��" HIR "��������ǡ�" BLU "ֱ����$n��$l" NOR,
    "force" : 400,
    "dodge" : 10,
    "damage": 130,
    "lvl"   : 100,
    "skill_name" : "�������" ,
        "damage_type" : "ץ��"
]),
([  "action" : BLU "$N˫��������צ��צצ����$n��" HIR "������������" BLU "����$n��$lץ��" NOR,
    "force" : 420,
    "dodge" : 20,
    "damage": 145,
    "lvl"   : 120,
    "skill_name" : "��������" ,
        "damage_type" : "ץ��"
]),
([  "action" : BLU "$N����Χ$nһת��ʹ��" HIR "�����޵�����" BLU "��$n��$l����ȫ������צӰ��" NOR,
    "force" : 440,
    "dodge" : 30,
    "damage": 155,
    "lvl"   : 140,
    "skill_name" : "���޵���" ,
        "damage_type" : "ץ��"
]),
([  "action" : BLU "$Nʹһ��" HIR "�������ơ�" BLU "��˫צ�ó�����צӰץ��$nȫ��" NOR,
    "force" : 520,
    "dodge" : 40,
    "damage": 170,
    "lvl"   : 160,
    "skill_name" : "������" ,
        "damage_type" : "ץ��"
]),
([  "action" : BLU "$N����������һ��" HIR "��Ψ�Ҷ���" BLU "˫צ������$n�������" NOR,
    "force" : 620,
    "dodge" : 50,
    "damage": 210,
    "lvl"   : 180,
    "skill_name" : "Ψ�Ҷ���" ,
    "damage_type" : "ץ��"
]),
});

int valid_enable(string usage)
{ 
     return usage=="claw" || usage=="parry" ;
}

int valid_learn(object me)
{
       if (!me->query("jiuyin/full"))
               return notify_fail("�����ڲ���ѧϰ������צ��\n");
       if ((int)me->query_skill("jiuyin-baiguzhua", 1) > 1)
               return notify_fail("��ѧ�˾����׹�ץ���޷�ѧϰ������צ��\n");
       if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
               return notify_fail("��������צ������֡�\n");
       if ((int)me->query_skill("jiuyin-zhengong", 1) < 100)
               return notify_fail("��ľ����湦��򲻹����޷���������צ��\n");
       if ((int)me->query_skill("daode-jing", 1) < 100)
               return notify_fail("��ĵ��¾���򲻹����޷���������צ��\n");
       if ((int)me->query_skill("claw", 1) < 41)
               return notify_fail("��Ļ���צ����򲻹����޷�ѧϰ��\n");
       if ((int)me->query("max_neili") < 1000)
               return notify_fail("�������̫�����޷���������צ��\n");
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
	int i, j, level, lev1, lev2;
	level = (int) me->query_skill("jiuyin-shenzhua",1);
	lev1 = (int) me->query_skill("jiuyin-zhengong", 1);
	lev2 = (int) me->query_skill("jiuyin-shenfa", 1);
	for(i = sizeof(action); i > 0; i--)
		if(level >= action[i-1]["lvl"])
			j = NewRandom(i, 20, level/5);
	if ((int)me->query_skill("daode-jing", 1) > 199 && random(level) > 180
	 && me->query_skill("jiuyin-zhengong") > 100 )
		return ([
			"action" : action[j]["action"] + RED"\n$N��ʹ���ƺ��ǽ����г�����������������׹�צ����������������������ǿ����"NOR,
			"force" : action[j]["force"] + random(lev1)/2,
			"dodge" : random(lev2),
			"damage" : action[j]["damage"] + random(lev1) / 2,
			"lvl" : action[j]["lvl"],
			"skill_name" : action[j]["skill_name"],
			"damage_type" : action[j]["damage_type"],
			]);
	else
		return action[j];
}

int practice_skill(object me)
{
       if( (int)me->query_skill("jiuyin-shenzhua", 1 ) < 150 )
               return notify_fail("�����ڲ�����ϰ������צ��\n");
       if ((int)me->query("jing") < 40)
               return notify_fail("�������̫���ˡ�\n");
       if ((int)me->query("neili") < 50)
               return notify_fail("�������������������צ��\n");
       me->receive_damage("jing", 30);
       me->add("neili", -10 - random((int)me->query_skill("jiuyin-shenzhua", 1 )/10+1));
       return 1;
}

string perform_action_file(string action)
{
        return __DIR__"jiuyin-shenzhua/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
if (me->query_skill_mapped("force") != "jiuyin-zhengong")
return 0;

	if (!me->query("jiuyin/full")) return 0;
if( damage_bonus < 70 ) return 0;
	if( damage_bonus > 100 )
		victim->receive_wound("qi", damage_bonus / 3 );
	else
		victim->receive_wound("qi", damage_bonus / 2);

	return HIR "��������������һ�����죬�����ǹ����������\n" NOR;
}
