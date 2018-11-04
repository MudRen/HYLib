// ruanhong-zhusuo.c �������
// by Vin 2000

#include <ansi.h>

inherit SKILL;

mapping *action = ({
([      "action": "$N����������һʽ��������˿����������̧��$w�������裬���������Ҳ�ɨ��$n",
        "force" : 198,
        "attack": 141,
        "dodge" : 5,
        "parry" : 15,
        "damage": 332,
        "lvl"   : 0,
        "damage_type": "����"
]),
([      "action": "$Nһʽ����˿������$w���ñ�ֱ�������ڡ��ƿ�������$n���̶�ȥ",
        "force" : 187,
        "attack": 148,
        "dodge" : 120,
        "parry" : 36,
        "damage": 347,
        "lvl"   : 80,
        "damage_type": "����"
]),
([      "action": "$N�ھ���������$w����ת������ԲȦ��һʽ�������ʳ�����Ӱ������$n����",
        "force" : 231,
        "attack": 65,
        "dodge" : 110,
        "parry" : 55,
        "damage": 393,
        "lvl"   : 100,
        "damage_type": "����"
]),
([	"action": "$N����������һʽ������֯�졹��$w��$n��ǰ����������ʽ����Ȼ��$l����������",
        "force" : 263,
        "attack": 170,
	"dodge" : 5,
        "parry" : 60,
	"damage": 302,
	"lvl"   : 120,
	"damage_type": "����"
]),
([	"action": "$Nһ���ߺȣ�ʹ��������׽������$w����ת������Ӱ�ݺᣬ�����ƻã�����$n",
        "force" : 301,
        "attack": 177,
	"dodge" : 6,
        "parry" : 65,
	"damage": 321,
	"lvl"   : 140,
	"damage_type": "����"
]),
([	"action": "$N���ذα���һʽ�������������������鶯���ͣ�����������˷���$n��ѹ��ȥ",
        "force" : 331,
        "attack": 85,
	"dodge" : 12,
        "parry" : 70,
	"damage": 142,
	"lvl"   : 160,
	"damage_type": "����"
]),
([	"action":"$N������ң�һ�С�����ܲ���������$w��������Ӱ����ɽ������ɨ��$nȫ��",
        "force" : 373,
        "attack": 191,
	"dodge" : 17,
        "parry" : 75,
	"damage": 363,
	"lvl"   : 180,
	"damage_type": "����"
]),
([	"action":"$N������ң�һ�С���ز�ʳ��������$w��������Ӱ����ɽ������ɨ��$nȫ��",
        "force" : 401,
        "attack": 198,
	"dodge" : 20,
        "parry" : 85,
	"damage": 389,
	"lvl"   : 200,
	"damage_type": "����"
]),
});

int valid_enable(string usage) { return usage == "whip" || usage == "parry"; }

int valid_learn(object me)
{
        object weapon;

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "whip")
                return notify_fail("���������һ�����Ӳ��������������\n");

        if ((int)me->query("max_neili") < 1000)
                return notify_fail("����������㣬û�а취���������������Щ���������ɡ�\n");

        if ((int)me->query_skill("force") < 150)
                return notify_fail("����ڹ����̫ǳ��û�а취�����������\n");

        if ((int)me->query_skill("whip", 1) < 100)
                return notify_fail("��Ļ����޷����̫ǳ��û�а취�����������\n");
 
 if ((int)me->query_skill("chilian-shenzhang", 1) < 150)
   return notify_fail("��ĳ������ƻ�򲻹����޷�ѧ��\n");

 if ((int)me->query_skill("jueqing-bian", 1) < 150)
   return notify_fail("��ľ���޷��������޷�ѧ��\n");

        if (((int)me->query_skill("whip", 1)+100) < (int)me->query_skill("ruanhong-zhusuo", 1))
                return notify_fail("��Ļ����޷�ˮƽ���������޷�������������������\n");

        return 1;
}

string query_skill_name(int level)
{
        int i;
        for (i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
        int i, level;
        level = (int) me->query_skill("ruanhong-zhusuo",1);
        for(i = sizeof(action); i > 0; i--)
                if (level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        object weapon;

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "whip")
                return notify_fail("��ʹ�õ��������ԡ�\n");

        if ((int)me->query("qi") < 80)
                return notify_fail("����������������������\n");

        if ((int)me->query("neili") < 90)
                return notify_fail("����������������������\n");

 if ((int)me->query_skill("chilian-shenzhang", 1) < 150)
   return notify_fail("��ĳ������ƻ�򲻹����޷�ѧ��\n");

 if ((int)me->query_skill("jueqing-bian", 1) < 150)
   return notify_fail("��ľ���޷��������޷�ѧ��\n");
 
        me->receive_damage("qi", 75);
        me->add("neili", -85);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"ruanhong-zhusuo/" + action;
}


mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        int lvl;
        int flvl;
	int level, jiali, time,level2,damage,damage2;
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
 


if (damage_bonus <30) damage_bonus=30;
      if( random(me->query_skill("ruanhong-zhusuo",1)) > 30 ) 
{
	  victim->receive_wound("qi", damage_bonus/2);
        return HIM "$n���о޶����ƺ�һ��,���ӻ������Σ�\n" NOR;
}
      if (random(me->query_skill("ruanhong-zhusuo",1)) > 150 ) {
	 switch( random(5) ) {
		case 0:
            victim->apply_condition("snake_poison", (me->query_skill("wudu-shengong"))/8 +
			victim->query_condition("snake_poison"));
			break;
		case 1:
            victim->apply_condition("zhizhu_poison", (me->query_skill("wudu-shengong"))/8 +
			victim->query_condition("zhizhu_poison"));
			break;
		case 2:
            victim->apply_condition("wugong_poison", (me->query_skill("wudu-shengong"))/8 +
			victim->query_condition("wugong_poison"));
			break;
		case 3:
            victim->apply_condition("xiezi_poison", (me->query_skill("wudu-shengong"))/8 +
			victim->query_condition("xiezi_poison"));
			break;
		case 4:
            victim->apply_condition("chanchu_poison", (me->query_skill("wudu-shengong"))/8 +
			victim->query_condition("chanchu_poison"));
			break;
	}
        return HIR "$nֻ�����˴�һ���飬�ƺ��ж��ˡ�\n" NOR;
   }
}