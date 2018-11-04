//xunlei-jian by cool
#include <ansi.h>
inherit SKILL;

mapping *action = ({
([	"action" : "$N�������ң�����һ�ܣ�һʽ������ָ·����$wͻȻ��$n��$l��ȥ��",
	"force" : 110,
	"dodge" : 20,
	"damage" : 215,
        "lvl" : 0,
	"damage_type" : "����"
]),
([	"action" : "$Nʹ��һʽ�����ӷ�����������ղ෭��һ�������´̳�",
	"force" : 120,
	"dodge" : 15,
	"damage" : 120,
        "lvl" : 5,
	"damage_type" : "����"
]),
([	"action" : "$N���ֽ�ָѪָ������$wʹ��һ�С�����Ѱ�롹��������������$n��$l����",
	"force" : 130,
	"dodge" : 15,
	"damage" : 130,
        "lvl" : 10,
	"damage_type" : "����"
]),
([	"action" : "$N��������$w�����ڱ��£�һ�С���Գ̽������������������$n��$l",
	"force" : 140,
	"dodge" : 10,
	"damage" : 140,
        "lvl" : 15,
	"damage_type" : "����"
]),
([	"action" : "$N̤����ǰ��һʽ������Ѱ�ߡ������г����ڶ����������$n��$l",
	"force" : 150,
	"dodge" : 10,
	"damage" : 150,
        "lvl" : 20,
	"damage_type" : "����"
]),
([	"action" : "$Nһ�С�б����֦�������屳ת������$w���Ҽ��Ϸ��������´̳�",
	"force" : 160,
	"dodge" : 5,
	"damage" : 155,
        "lvl" : 25,
	"damage_type" : "����"
]),
([	"action" : "$Nһʽ�������׶����������з棬�������ϣ���$n���������ؽ���֮��",
	"force" : 170,
	"dodge" : 0,
	"damage" : 160,
        "lvl" : 30,
	"damage_type" : "����"
]),
([	"action" : "$N��ǰ����һ�С�����Ҿ�֡���$w��Ȼ�����´̳���������������",
	"force" : 180,
	"dodge" : 20,
	"damage" : 165,
        "lvl" : 35,
	"damage_type" : "����"
]),
([	"action" : "$N����$w�����һζ���һ�С����������������ֱ��$n������Ҫ��",
	"force" : 190,
	"dodge" : 5,
	"damage" : 170,
        "lvl" : 45,
	"damage_type" : "����"
]),
([	"action" : "$N˫�ֳֽ�����$w������ʹ��һ�С��ٻ����졹���������$n��ǰ�Ϸ���ȥ",
	"force" : 200,
	"dodge" : 5,
	"damage" : 175,
        "lvl" : 55,
	"damage_type" : "����"
]),
([	"action" : "$N������$n��ʹ��һ�С�����ն�㡹���Ӷ�����$w��ֱ��$n������·",
	"force" : 210,
	"dodge" : 10,
	"damage" : 180,
        "lvl" : 65,
	"damage_type" : "����"
]),
([	"action" : "$N����$w��������һ�С���Ů���롹��$wͻȻ���ִ���$n��$l",
	"force" : 220,
	"dodge" : 0,
	"damage" : 190,
        "lvl" : 75,
	"damage_type" : "����"
]),
([	"action" : "$N������ǰ��������ָ��һ�С���Գ��֦����$w����$n��ͷ��Ҫ��",
	"force" : 230,
	"dodge" : 20,
	"damage" : 205,
        "lvl" : 85,
	"damage_type" : "����"
]),
([	"action" : "$Nһ�С�����ӱޡ���$w�����ߣ�����һ����������$nȫ����������",
	"force" : 240,
	"dodge" : 15,
	"damage" : 215,
        "lvl" : 95,
	"damage_type" : "����"
]),
([	"action" : "$N�������£�һ�С����ƿ�������$w��Ȼ��תֱ�ϣ�������$n������Ҫ������Χס",
	"force" : 250,
	"dodge" : 15,
	"damage" : 235,
        "lvl" : 100,
	"damage_type" : "����"
]),
});


int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������������\n");
	if ((int)me->query_skill("xuantian-wuji", 1) < 30)
		return notify_fail("��������޼������̫ǳ��\n");
	if ((int)me->query_skill("sword", 1) < 20)
		return notify_fail("��Ļ����������̫ǳ��\n");
	return 1;
}

mapping query_action(object me, object weapon)
{
	int i, level;
	level   = (int) me->query_skill("xunlei-jian",1);
	
	for(i = sizeof(action); i > 0; i--) {
		if(level > action[i-1]["lvl"]) {
		if(random(level) >= 120){
                return ([
                "action":HIB+action[NewRandom(i, 20, level/5)]["action"]+NOR,
                "damage":level*2,
                "damage_type": "����",
                "dodge": level/2+random(50),
                "force": level+80+random(50),
                ]);
        } else {
			return action[NewRandom(i, 20, level/5)];
}
}
}
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if ((int)me->query("jing") < 30)
		return notify_fail("�������������Ѹ�׽�����\n");
	me->receive_damage("jing", 25);
	return 1;
}
string perform_action_file(string action)
{
       return __DIR__"xunlei-jian/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor, string limb)
{                                                                                                                
	int level, jiali, time,level2,damage;
	object weapon;
	weapon = me->query_temp("weapon");
        level = (int) me->query_skill("xuantian-wuji",1);
        level2= (int) me->query_skill("xuantian-wuji",1);


if (random(8)==0 && level>=300 && me->query_skill_mapped("force") == "xuantian-wuji")
{
        victim->receive_damage("qi",level*2+300);
        victim->receive_wound("qi",level*3+300);
	return HIB"$N��̤���Բ�,����̫�Ҿ�,$Nһ����Х��$n˫��һ�ڣ��³�һ����Ѫ!\n"NOR;
}
}