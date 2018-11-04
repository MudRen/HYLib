// zhuihun-biao.c ׷�������

#include <ansi.h>
inherit SKILL;  
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

mapping *action = ({
([	"action" : "$N����$wһ����һ��"+(order[random(13)])+"���޳����š�"NOR"������һ������$n��$l��ȥ",
	"force" : 120,
        "dodge" : -10,
        "parry" : 5,
	"damage" : 20,
	"damage_type" : "����",
	"post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
]),
([	"action" : "$Nһ��"+(order[random(13)])+"��С�"NOR"��ֻ��ơ�"NOR"��������һ����$w������Ϣ����$n�ľ���",
	"force" : 130,
        "dodge" : -10,
        "parry" : 10,
	"damage" : 25,
	"damage_type" : "����",
	"post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
]),
([	"action" : "$Nб�������һ��"+(order[random(13)])+"�����̧�Ρ�"NOR"��������ö$w,��ֱ����$n",
	"force" : 140,
        "dodge" : -5,
        "parry" : 5,
	"damage" : 30,
	"damage_type" : "����",
	"post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
]),
([	"action" : "$Nһ��"+(order[random(13)])+"���κβ���·��"NOR"��$w���ַɳ������Բ���˼��ĽǶȣ�����$n����",
	"force" : 160,
        "dodge" : 5,
        "parry" : 5,
	"damage" : 35,
	"damage_type" : "����",
	"post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
]),
([	"action" : "$Nһ��"+(order[random(13)])+"�������������ϻ꡹"NOR"��һ��$w��ͷ��������$n���ؿڡ�",
	"force" : 180,
        "dodge" : 10,
        "parry" : 5,
	"damage" : 40,
	"damage_type" : "����",
	"post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
]),
([	"action" : "$N����һ���ģ�����Ҫ������ȴ����â����������һ��"+(order[random(13)])+"���ϳ�������ȥ����"NOR"��$w�ɿ�����$n",
	"force" : 210,
        "dodge" : 15,
        "parry" : 15,
	"damage" : 50,
	"damage_type" : "����",
	"post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
]),
([	"action" : "$Nһ��"+(order[random(13)])+"�����޹µơ�"NOR"��$w��˸������ʱ��ʱ��������ʤ����$n��$l",
	"force" : 240,
        "dodge" : 5,
        "parry" : 15,
	"damage" : 60,
	"damage_type" : "����",
	"post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
]),
([	"action" : "$N�ڿ�Ծ��һ��"+(order[random(13)])+"����������"NOR"����ö$w���ֶ�����һö��һö����Ȼ����һ��������$n��ȫ���ȥ",
	"force" : 280,
        "dodge" : 20,
        "parry" : 10,
	"damage" : 80,
	"damage_type" : "����",
	"post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
]),
});


int valid_enable(string usage) { return (usage == "throwing") || (usage == "parry"); }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������������\n");
	if ((int)me->query_skill("biyun-xinfa", 1) < 20)
		return notify_fail("��ı����ķ���򲻹���\n");
	if ((int)me->query_skill("biye-wu", 1) < 20)
		return notify_fail("��ı�Ҷ�������̫ǳ��\n");
	return 1;
}

mapping query_action(object me, object weapon)
{
int zhaoshu, level;

zhaoshu = sizeof(action)-1;
level   = (int) me->query_skill("zhuihun-biao",1);

if (level < 60 )
zhaoshu--;
if (level < 55 )
zhaoshu--;
if (level < 50 )
zhaoshu--;
if (level < 40 )
zhaoshu--;
if (level < 30 )
zhaoshu--;
if (level < 20 )
zhaoshu--;
if (level < 10 )
zhaoshu--;

return action[random(zhaoshu)];
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "throwing")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("�������������׷������ڡ�\n");
	me->receive_damage("qi", 30);
	return 1;
}


mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{object weapon;weapon=me->query_temp("weapon");
              
        if(weapon && 
        (string)weapon->query("skill_type") == "throwing"){
          victim->apply_condition("tmzhuihun_poison", random(me->query_skill("zhuihun-biao")) + 10 +
	  victim->query_condition("tmzhuihun_poison"));
	}
}
string perform_action_file(string action)
{
		return __DIR__"zhuihun-biao/" + action;
}