// chilian-shenzhang.c  ��������
// 14/7/2001  Xuanyuan

#include <ansi.h>

inherit SKILL;

mapping *action = ({
([	"action" : "$N˫��һ�������ƴ��ŵ��������⣬ֱ��$n��ȥ",
	"force" : 180,
        "dodge" : 15,
        "parry" : 20,
	"damage": 250,
	"lvl" : 0,
	"skill_name" : "��������",
        "damage_type" : "����"
]),
([	"action" : "$N������Σ�����ֱ�������綾��һ��ֱ��$n����ǰ",
	"force" : 220,
        "dodge" : 10,
        "parry" : 15,
	"damage": 360,
	"lvl" : 10,
	"skill_name" : "��������",
        "damage_type" : "����"
]),
([	"action" : "$N˫�Ʒ��ɣ�������ã��һ�ɰ���������������$n��ȫ��",
	"force" : 260,
        "dodge" : 115,
        "parry" : 20,
	"damage": 270,
	"lvl" : 20,
	"skill_name" : "��������",
        "damage_type" : "����"
]),
([	"action" : "$N����һ�֣�������Ы���������ߣ�ͬʱ��$n����ȥ",
	"force" : 300,
        "dodge" : 120,
        "parry" : 30,
	"damage": 280,
	"lvl" : 30,
	"skill_name" : "��������",
        "damage_type" : "����"
]),
([	"action" : "$NĬ��������˫�ƺ�Ȼ��ڣ�����һ������ֻ��$n��ȫ��",
	"force" : 340,
        "dodge" : 25,
        "parry" : 20,
	"damage":300,
	"lvl" : 40,
	"skill_name" : "��������",
        "damage_type" : "����"
])
});

int valid_enable(string usage)
{
	return usage=="strike" || usage=="parry" ;
}

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("���������Ʊ�����֡�\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������̫�����޷����������ơ�\n");
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
	level   = (int) me->query_skill("chilian-shenzhang",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("jing") < 50)
		return notify_fail("��ľ���̫���ˡ�\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("��������������������ơ�\n");
        me->receive_damage("jing", 25);
	me->add("neili", -10);
	return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{

        int lvl;
        int flvl;
	int level, jiali, time,level2,damage,damage2;
	       int neili, neili2;
 
	object weapon;
object target;

        level = (int) me->query_skill("wudu-shengong",1);
        level2= (int) me->query_skill("wudu-shengong",1);

damage2= (int) victim->query("neili",1)/8;
if (damage2>= 3800) damage2 = 3800;
	
if (random(8)==0 && level>=300 && me->query_skill_mapped("force") == "wudu-shengong")
{
if (!victim->is_busy()) victim->start_busy(3);	
if (me->query("qi") <= me->query("max_qi")*2) me->add("qi",damage2);
if (me->query("eff_qi") <= me->query("max_qi")*2) me->add("eff_qi",damage2);
 return HIG "$Nʹ���嶾�񹦣�������$n��������Ѫ��ȫ����˺�����˺ܶ࣡!\n";
}
        neili=me->query("neili");
        neili2=victim->query("neili");
        if(random(neili)>random(neili2)){
//                message_vision(MAG"$n��Ȼ����һ����Ϯ��������һ�Σ�ͷ��΢΢��Щ���衣\n"NOR, me, victim);
                victim->apply_condition("chilian_poison", random(me->query_skill("chilian-shenzhang", 1)/2) + victim->query_condition("chilian_poison"));
if(me->query_skill("wudu-shengong",1)> 100)
victim->apply_condition("wuhudu_poison", random(me->query_skill("chilian-shenzhang", 1)/2) + victim->query_condition("wuhudu_poison"));
                if(victim->query("poisoner") != me) victim->set("poisoner", me);
        } else message_vision(YEL"$næ�������ֿ�����$N���ϵľ綾�������⡣\n"NOR,me,victim);

}
