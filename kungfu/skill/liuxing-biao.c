// liuxing-dao.c ���Ǹ�����


#include <ansi.h>
inherit SKILL;
string *du=({
"ice_poison",
"ill_dongshang",
"ill_fashao",
"ill_kesou",
"ill_shanghan",
"ill_zhongshu",
"xx_poison",
"cold_poison",
"flower_poison",
"rose_poison",
"x2_poison",
"sanpoison",
"scorpion_poison",
"qx_snake_poison",
"anqi_poison",
"yf_poison",
"nx_poison",
"chilian_poison",
"yufeng_poison",
"insect_poison",
"tmzhuihun_poison",
"tmpili_poison",
"zm_poison",
});


mapping *action = ({
([      "action" : "$N����$w�������,ʹ��һ�С��������꡹������$n��$l  ",
        "skill_name" : "��������",
        "force" : 100,
        "dodge" : 85,
        "parry" : 5,
        "lvl" : 0,
        "damage" : 220,
        "damage_type" : "����",
	"post_action":  (: call_other, WEAPON_D, "throw_weapon" :)

]),
([      "action" : "$N����΢�࣬ʹһ�С��������ߡ�������$w����$n�Ĵ���  ",
        "skill_name" : "��������",
        "force" : 140,
        "dodge" : 85,
        "parry" : 5,
        "lvl" : 8,
        "damage" : 240,
        "damage_type" : "����",
	"post_action":  (: call_other, WEAPON_D, "throw_weapon" :)
]),
([      "action" : "$N�����������ȫ��������ʹ����������������$w����ǧ��֮���ش���$n��$l  ",
        "skill_name" : "�����콵",
        "force" : 180,
        "dodge" : 80,
        "parry" : 5,
        "lvl" : 16,
        "damage" : 260,
        "damage_type" : "����",
	"post_action":  (: call_other, WEAPON_D, "throw_weapon" :)
]),
([      "action" : "$Nʹ��һ�С����Ǹ��¡���$w�籩���Ѹ�ײ����ڶ�������$n  ",
        "skill_name" : "���Ǹ���",
        "force" : 220,
        "dodge" : 85,
        "parry" : 5,
        "lvl" : 24,
        "damage" : 380,
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
	level   = (int) me->query_skill("liuxing-biao",1);
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
		return notify_fail("����������������������Ǹ����ڡ�\n");
	me->receive_damage("qi", 30);
	return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        int lvl;
        int flvl;
	int level, jiali, time,level2,damage,damage2;
	object weapon;
object target;

        level = (int) me->query_skill("biyun-xinfa",1);
        level2= (int) me->query_skill("biyun-xinfa",1);

damage2= (int) victim->query("neili",1)/8;
if (damage2>= 3800) damage2 = 3800;
	
if (random(8)==0 && level>=300 && me->query_skill_mapped("force") == "biyun-xinfa")
{
            victim->receive_damage("qi",20);
            victim->receive_wound("qi",15 + random(10));
            victim->apply_condition(du[random(sizeof(du))], 25);
            victim->apply_condition(du[random(sizeof(du))], 25);
            victim->apply_condition(du[random(sizeof(du))], 25);
            victim->apply_condition(du[random(sizeof(du))], 25);
            victim->apply_condition(du[random(sizeof(du))], 25);
            victim->apply_condition(du[random(sizeof(du))], 25);
if (!victim->is_busy()) victim->start_busy(2);	
 return HIR "$NͻȻ���ƣ�Ȼ��Ѹ�ٷ���! ���о�Ȼ�ж�ɰ�����Ʒ羡Ȼ��������ɫ�ģ�$nӲ��ͷƤ������Ӳ�ӣ���������о޶���!\n";
}
 
}