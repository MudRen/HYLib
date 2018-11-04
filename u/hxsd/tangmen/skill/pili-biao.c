// pili-biao.c ������


#include <ansi.h>
inherit SKILL;  
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});


mapping *action = ({
([      "action" : "$N����$w���ֶ���,ʹ��һ��"+(order[random(13)])+"���������ڡ�"NOR"������$n��$l  ",
        "skill_name" : "��������",
        "force" : 100,
        "dodge" : -5,
        "parry" : 5,
        "lvl" : 0,
        "damage" : 120,
        "damage_type" : "����",
	"post_action":  (: call_other, WEAPON_D, "throw_weapon" :)

]),
([      "action" : "$N����һ�࣬ʹһ��"+(order[random(13)])+"������������"NOR"������$w����$n�Ĵ���  ",
        "skill_name" : "��������",
        "force" : 140,
        "dodge" : 5,
        "parry" : 5,
        "lvl" : 8,
        "damage" : 140,
        "damage_type" : "����",
	"post_action":  (: call_other, WEAPON_D, "throw_weapon" :)
]),
([      "action" : "$N�ڿն���ʹ��"+(order[random(13)])+"�������콵��"NOR"������$w�ɿ������$n��$l  ",
        "skill_name" : "�����콵",
        "force" : 180,
        "dodge" : 10,
        "parry" : 5,
        "lvl" : 16,
        "damage" : 160,
        "damage_type" : "����",
	"post_action":  (: call_other, WEAPON_D, "throw_weapon" :)
]),
([      "action" : "$Nʹ��һ��"+(order[random(13)])+"���������¡�"NOR"��$w�籩�������$n  ",
        "skill_name" : "��������",
        "force" : 220,
        "dodge" : 5,
        "parry" : 5,
        "lvl" : 24,
        "damage" : 180,
        "damage_type" : "����",
	"post_action":  (: call_other, WEAPON_D, "throw_weapon" :)
]),
});

int valid_enable(string usage) { return (usage == "throwing") || (usage == "parry"); }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 400)
		return notify_fail("�������������\n");
	if ((int)me->query_skill("biyun-xinfa", 1) < 80)
		return notify_fail("��ı����ķ����̫ǳ��\n");
	if ((int)me->query_skill("biye-wu", 1) < 30)
		return notify_fail("��ı�Ҷ�������̫ǳ��\n");
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
	level   = (int) me->query_skill("pili-biao",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "throwing")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("������������������������ڡ�\n");
	me->receive_damage("qi", 30);
	return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{object weapon;weapon=me->query_temp("weapon");
              
        if(weapon &&
        (string)weapon->query("skill_type") == "throwing"){
          victim->apply_condition("tmpili_poison", random(me->query_skill("pili-biao")) + 10 +
	  victim->query_condition("tmpili_poison"));
	}
}


string perform_action_file(string action)
{
		return __DIR__"pili-biao/" + action;
}