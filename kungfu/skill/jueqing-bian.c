// jueqing-bian.c  ����޷�

#include <ansi.h>

inherit SKILL;
#include <ansi.h>
#include <combat.h>
int sanwu
(object me, object victim, object weapon, int damage);

mapping *action = ({
([	"action":		"$N�ᶶ����һ�С�������о��������$w���ñ�ֱ��ֱ��$n��ȥ",
	"force":		60,
	"dodge":		30,
	"damage":		330,
	"lvl" : 0,
	"skill_name" : "������о",
	"damage_type":	"����"
]),
([	"action":		"$N����һת��һ�С���Ы��β����$w�ڿ���ת�˸�Ȧ���Թ���ĽǶ�����$n",
	"force":		120,
	"dodge":		20,
	"damage":		340,
	"lvl" : 10,
	"skill_name" : "��Ы��β",
	"damage_type":	"����"
]),
([	"action":		"$Nһ�����ޣ�һ�С�������˿��������$w����������Ӱ������$n",
	"force":		180,
	"dodge":		30,
	"damage":		350,
	"lvl" : 20,
	"skill_name" : "������˿",
	"damage_type":	"����"
]),
([	"action":		"$N������ң�һ�С���ܳ�����������$w������ң�ֱ����$n�ؿ�",
	"force":		240,
	"dodge":		10,
	"damage":		360,
	"lvl" : 30,
	"skill_name" : "��ܳ���",
	"damage_type":	"����"
]),
([	"action":		"$N��������һ�С���򼷭��������$wת��������ȦȦ������һ�����磬ֱ��$n��ȥ",
	"force":		300,
	"dodge":		120,
	"damage":		380,
	"lvl" : 40,
	"skill_name" : "��򼷭��",
	"damage_type":	"����"
])

});

int valid_enable(string usage) { return (usage == "whip") || (usage == "parry"); }

int valid_learn(object me)
{
	object weapon;


	if ( !objectp(weapon = me->query_temp("weapon"))
	|| ( string)weapon->query("skill_type") != "whip" )
		return notify_fail("���������һ�����Ӳ���������޷���\n");

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
//	����������
	string *sanwu_msg = 
	({
		"$Nһ��"+WHT"���޿ײ��롹"+NOR"��$n��ǰ���ᶼ��$w��Ӱ��ͬʱ��$nȫ�������Ѩ",
		"$Nһ��δ�����ڶ���"+WHT"������������"+NOR"��Ȼ�򵽣�����$w����$n�����ƫ��Ѩ��",
		WHT"����ɨ��$N����һ�С�������Ϊ����$w����������ר��$n��������֮��"NOR,
	});

		if ( me->query_temp("sanwu") > 0 && me->query_temp("sanwu") <= 3 )
		{
			return ([
			"action": sanwu_msg[me->query_temp("sanwu")-1],
			"dodge": 120,
			"parry": 125,
			"force": 600,
			"damage": 600,
			"damage_type": "����",
			"post_action": (: sanwu :) ]);
		}

	return action[random(sizeof(action))];
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "whip")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if ((int)me->query("jing") < 50)
		return notify_fail("��ľ�������������޷���\n");
        me->receive_damage("jing", 25);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"jueqing-bian/" + action;
}

int sanwu(object me, object victim, object weapon, int damage)
{
//	if( damage > 0 && me->query_temp("sanwu") ) 
//		me->delete_temp("sanwu");
}
mapping *query_skilldbase() {return action;}
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
