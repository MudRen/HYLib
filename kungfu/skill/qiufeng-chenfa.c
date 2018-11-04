// qiufeng-chenfa.c 秋风拂尘

#include <ansi.h>

inherit SKILL;

mapping *action = ({
([	"action":		"$N端坐不动，一招「秋风拂叶」，手中$w带着一股劲风，击向$n的脸颊",
	"dodge":		50,
	"damage":		50,
	"lvl" : 0,
	"skill_name" : "秋风拂叶",
	"damage_type":	"刮伤"
]),
([	"action":		"$N单臂一挥，一招「玉带围腰」，手中$w直绕向$n的身后",
	"dodge":		100,
	"damage":		100,
	"lvl" : 50,
	"skill_name" : "玉带围腰",
	"damage_type":	"内伤"
]),
([	"action":		"$N身形一转，一招「流云断川」，手中$w如矫龙般腾空一卷，猛地向$n劈头打下",
	"dodge":		120,
	"damage":		135,
	"lvl" : 70,
	"skill_name" : "流云断川",
	"damage_type":	"劈伤"
]),
([	"action":		"$N力贯尘梢，一招「春风化雨」，手中$w舞出满天幻影，排山倒海般扫向$n全身",
	"dodge":		140,
	"damage":		150,
	"lvl" : 80,
	"skill_name" : "春风化雨",
	"damage_type":	"刺伤"
]),
([	"action":		"$N忽的向前一跃，一招「野马分鬃」，手中$w分击$n左右",
	"dodge":		150,
	"damage":		260,
	"lvl" : 90,
	"skill_name" : "野马分鬃",
	"damage_type":	"刺伤"
]),
([	"action":		"$N慢步上前，一招「竹影扫阶」，手中$w缓缓罩向$n前胸",
	"dodge":		160,
	"damage":		270,
	"lvl" : 99,
	"skill_name" : "竹影扫阶",
	"damage_type":	"内伤"
])
});

int valid_enable(string usage) { return (usage == "whip") || (usage == "parry"); }

int valid_learn(object me)
{
	object weapon;

	if( (int)me->query("max_neili") < 300 )
		return notify_fail("你的内力不足，没有办法练秋风尘法, 多练些内力再来吧。\n");

	if ((int)me->query_skill("force", 1) < 50)
		return notify_fail("你的基本气功火候太浅。\n");

	if ( !objectp(weapon = me->query_temp("weapon"))
	|| ( string)weapon->query("skill_type") != "whip" )
		return notify_fail("你必须先找一条拂尘才能练尘法。\n");

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
	level   = (int) me->query_skill("qiufeng-chenfa",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "whip")
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("你的体力不够练秋风尘法。\n");
	me->receive_damage("qi", 5);
	return 1;
}

string perform_action_file(string action)
{
	if ( this_player()->query_skill("qiufeng-chenfa", 1) >= 40 )
		return __DIR__"qiufeng-chenfa/" + action;
}

