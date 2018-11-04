//
// yujiamu-quan.c ������ĸȭ
// Designed by secret(����)
//
#include <ansi.h>;
inherit SKILL;

mapping *action = ({
([      "action" : "$N����˫ȭ��ʹ��һ�С��ඥ������ͷ����$n��$l  ",
        "skill_name" : "�ඥ",
        "force" : 240,
        "dodge" : 5,
     "damage" : 200,        	
        "lvl" : 0,
        "damage_type" : "����",
]),
([      "action" : "$Nʹ��һ�С���ࡹ������һ�ͣ����ֻ���������һȭ����$n���ɲ�  ",
        "skill_name" : "���",
        "force" : 260,
        "dodge" : -5,
     "damage" : 200,        	
        "lvl" : 8,
        "damage_type" : "����",
]),
([      "action" : "$Nʹ��һ�С��ü������ȭ���$n��ǰ�أ�һ������ȭ��ɨ$n��̫��Ѩ  ",
        "skill_name" : "�ü",
        "force" : 280,
        "dodge" : 10,
     "damage" : 200,        	
        "lvl" : 16,
        "damage_type" : "����",
]),
([      "action" : "$N���ι��죬ʹһ�С�������˫ȭ���»���$n��$l  ",
        "skill_name" : "���",
        "force" : 300,
        "dodge" : 5,
     "damage" : 200,
        "lvl" : 24,
        "damage_type" : "����",
]),
([      "action" : "$Nʹ��һ�С����š���˫ȭ������������������ֱָ$n��$l  ",
        "skill_name" : "����",
        "force" : 320,
        "dodge" : -5,
     "damage" : 200,
        "lvl" : 32,
        "damage_type" : "����",
]),
([      "action" : "$N΢΢һЦ��ʹ��һʽ����������˫ȭǰ�������ֱȡ$n������  ",
        "skill_name" : "����",
        "force" : 350,
        "dodge" : 10,
     "damage" : 200,
        "lvl" : 40,
        "damage_type" : "����",
]),
([      "action" : "$Nʹ��һ�С����ġ���ȫ��ת��˫ȭ��ɨ$n��$l  ",
        "skill_name" : "����",
        "force" : 370,
        "dodge" : 20,
     "damage" : 200,
        "lvl" : 48,
        "damage_type" : "����",
]),
([      "action" : "$N����һԾ��ʹ��һ�С���ʤ����һȭ�ͻ�$n�ʺ�  ",
        "skill_name" : "��ʤ",
        "force" : 450,
        "dodge" : 5,
     "damage" : 200,
        "lvl" : 56,
        "damage_type" : "����",
]),
});

int valid_enable(string usage) { return usage == "cuff" || usage == "parry"; }

int valid_combine(string combo) { return combo=="dashou-yin"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("��������ĸȭ������֡�\n");
	else if ((int)me->query("max_neili") < 50)
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
	level   = (int) me->query_skill("yujiamu-quan",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	object weapon;

	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("��������ĸȭ������֡�\n");
	if ((int)me->query("qi") < 40)
		return notify_fail("������������������˽�����ĸȭ��\n");
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
if ( level2<= 0) level2= (int) me->query_skill("xiaowuxiang",1);
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
      if( random(me->query_skill("yujiamu-quan",1)) > 150  || random(8)==0) 
{
	  victim->receive_wound("qi", damage_bonus/2+30);
        return HIW "$N����һ�����ء������ֻ��ģ�����ƽ̯�����Ǽ��������գ������һ�� 
ֻ�������İ׹��Χ$n����\n" NOR;
}
}

string perform_action_file(string action)
{
        return __DIR__"yujiamu-quan/" + action;
}