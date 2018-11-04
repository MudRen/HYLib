//
// mingwang-jian.c ����������
// Designed by secret(����)
//
#include <ansi.h>;
inherit SKILL;

mapping *action = ({
([      "action" : "$NŭĿԲ����ʹ��һ�С�������������$wһ����ֱ��$n��$l  ",
        "skill_name" : "����",
        "force" : 100,
        "dodge" : 10,
        "lvl" : 0,
        "damage" : 230,
        "damage_type" : "����",
]),
([      "action" : "$Nʹ��һʽ�����ֳ�����������һ������â����$n��$l  ",
        "skill_name" : "���ֳ���",
        "force" : 140,
        "dodge" : 5,
        "lvl" : 8,
        "damage" : 230,
        "damage_type" : "����",
]),
([      "action" : "$Nʹ��һ�С�ɽ����������Ծ���գ�$w��ɽ��������$n��$l  ",
        "skill_name" : "ɽ��",
        "force" : 180,
        "dodge" : 10,
        "lvl" : 16,
        "damage" : 240,
        "damage_type" : "����",
]),
([      "action" : "$Nʹ����ǧ��ת������$w�����ĳ�һ�㣬��Ȼһ������$n��$l  ",
        "skill_name" : "ǧ��ת",
        "force" : 220,
        "dodge" : 10,
        "lvl" : 24,
        "damage" : 248,
        "damage_type" : "����",
]),
([      "action" : "$Nʹ��һ�С���ħ�衹��ȫ��������$w�У�����ֱָ$n��$l  ",
        "skill_name" : "��ħ��",
        "force" : 250,
        "dodge" : 10,
        "lvl" : 32,
        "damage" : 254,
        "damage_type" : "����",
]),
([      "action" : "$N���������ʹ��һʽ�����衹��һ���������Ӱ����$n��$lɨȥ  ",
        "skill_name" : "����",
        "force" : 280,
        "dodge" : 15,
        "lvl" : 40,
        "damage" : 260,
        "damage_type" : "����",
]),
([      "action" : "$Nʹ��һ�С����ڡ�������$w������������$n��$l  ",
        "skill_name" : "����",
        "force" : 300,
        "dodge" : 20,
        "lvl" : 48,
        "damage" : 166,
        "damage_type" : "����",
]),
([      "action" : "$N����һԾ���Ӹ�����ʹ�����������졹����ʱ�����������$n��$l  ",
        "skill_name" : "��������",
        "force" : 320,
        "dodge" : 25,
        "lvl" : 80,
        "damage" : 280,
        "damage_type" : "����",
]),
});


int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }

int valid_combine(string combo) { return combo=="xue-dao"; }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������������\n");
	if ((int)me->query_skill("longxiang", 1) >= 20 ||
	    (int)me->query_skill("xiaowuxiang", 1) >= 20)
		return 1;
	else if ((int)me->query_skill("longxiang", 1) < 20)
		return notify_fail("���������������̫ǳ��\n");
	else if ((int)me->query_skill("xiaowuxiang", 1) < 20)
		return notify_fail("���С���๦���̫ǳ��\n");
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
	level   = (int) me->query_skill("mingwang-jian",1);
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
	if ((int)me->query("qi") < 50)
		return notify_fail("������������������˲�����������\n");
	me->receive_damage("qi", 20);
	return 1;
}
int ob_hit(object ob, object me, int damage)
{
        object wp1,weapon;
        string msg;
        int p,j,skill, neili, neili1;
        int level,level2,damage2;
        level = (int) me->query_skill("unarmed",1);
        level2= (int) me->query_skill("longxiang",1);
        skill = me->query_skill("longxiang", 1);
        neili = me->query("neili");
        neili1 = ob->query("neili");
damage2= (int) ob->query("neili",1)/10;
if (random(8)==0 && level2>=300 && (me->query_skill_mapped("force") == "longxiang" || me->query_skill_mapped("force") == "xiaowuxiang"))
{
j = -damage/2; 
if (damage2> 5000)	damage2=5000;
msg = HIM"$N ���������𡸽�����ħ�䡹��������ӿ������һ��һ��ļ�ǿ��$n����һ�ң�������Ȼ�᲻������\n"NOR;
ob->set_temp("apply/attack", 0);
ob->set_temp("apply/defense", 0);
if (random(2)==0)
{
msg += HIM"$N"+HIM+"Ĭ������������ԣ��ֽ�Ħ��֧���ŭӡ! $n����һ�����³�һ����Ѫ!"+NOR;
if (ob->query("qi") > damage2)
{
		ob->receive_damage("qi", damage2/2);
		ob->receive_wound("qi", damage2/2);
}
 if (!ob->is_busy() && random(3)==0) ob->start_busy(2);  
}

           message_vision(msg, me, ob);
           return j;
}      
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        if(  me->query("jiali") > me->query_skill("force") 
          && me->query_skill_mapped("force") == "longxiang") 

if (damage_bonus <10) damage_bonus=10;
      if( random(me->query_skill("mingwang-jian",1)) > 150  || random(8)==0) 
{
	  victim->receive_wound("qi", damage_bonus/2+30);
        return HIG "$N��������ǰչ������֮״��������������������̨�����������£������ྲ��������ˡ��� 
ֻ���������̹��Χ$n����\n" NOR;
}
}

string perform_action_file(string action)
{
        return __DIR__"mingwang-jian/" + action;
}