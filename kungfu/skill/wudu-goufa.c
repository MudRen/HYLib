// wudu-goufa.c �嶾����

#include <ansi.h>

inherit SKILL;  
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

mapping *action = ({
([	"action":"\n$N����$wһ����һʽ"+(order[random(13)])+"���������š�"NOR"�������ļ�����$n��$l",
	"force" : 160,
        "dodge" : 5,
	"damage": 315,
	"lvl" : 0,
	"skill_name" : "��������",
	"damage_type":	"����"
]),
([	"action":"\n$Nһʽ"+(order[random(13)])+"����˿��ϵ��"NOR"���������಻��������һ�����εĴ�����$n���ڵ���",
	"force" : 240,
        "dodge" : 10,
	"damage": 325,
	"lvl" : 10,
	"skill_name" : "��˿��ϵ",
	"damage_type":	"����"
]),
([	"action":"\n$Nһ����Ц����������һʽ"+(order[random(13)])+"��������צ��"NOR"������$w���裬�ó�ǧ����\n�ֱۣ���������$n",
       "force" : 380,
        "dodge" : 15,
	"damage": 340,
	"lvl" : 25,
	"skill_name" : "������צ",
	"damage_type":	"����"
]),
([	"action":"$N����أ�����һ���������ߣ�����$wȴٿ�Ĵ�Ҹ�´�����������$n��$l,\n��һʽ"+(order[random(13)])+"����Ы���롹"NOR"",
       "force" : 480,
        "dodge" : 40,
	"damage": 350,
	"lvl" : 35,
	"skill_name" : "��Ы����",
	"damage_type":	"����"
]),
([	"action":"$N�Ų����ģ����κ�����ǰ������һʽ"+(order[random(13)])+"���������¡�"NOR"������$w���¶���ֱ\n��$n���"+(order[random(13)])+"���",
       "force" : 580,
        "dodge" : 40,
	"damage": 360,
	"lvl" : 50,
	"skill_name" : "��������",
	"damage_type":	"����"
]),
([	"action":"$N����һ�Σ�һʽ"+(order[random(13)])+"�����߲���"NOR"������$w�總��֮����������Ϣ�ش���$n\n������",
       "force" : 680,
        "dodge" : 70,
	"damage": 380,
	"lvl" : 60,
	"skill_name" : "���߲���",
	"damage_type":	"����"
]),
([	"action":"\n$Nһ����Х�����γ������һʽ"+(order[random(13)])+"�����ű䡹"NOR"������$w����Ȱ�����\n$nȫ��ŵ���Ѩ",
	"force" : 450,
        "dodge" : 80,
	"damage": 400,
	"lvl" : 70,
	"skill_name" : "���ű�",
	"damage_type":	"����"
]),
([	"action":"$N����һ����˫���չ�������"+(order[random(13)])+"��������"NOR"��$w���͸��һ��ǿ���ĺ�\n����������Ϯ��$n",
       "force" : 780,
        "dodge" : 45,
	"damage": 550,
	"lvl" : 80,
	"skill_name" : "������",
	"damage_type":	"����"
]),
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������������\n");
	if ((int)me->query_skill("wudu-shengong", 1) < 20)
		return notify_fail("����嶾�񹦻��̫ǳ��\n");
	if ((int)me->query_skill("force", 1) < 20)
		return notify_fail("��Ļ����ڹ����̫ǳ��\n");
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
	level   = (int) me->query_skill("wudu-goufa",1);
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
	if ((int)me->query("qi") < 40)
		return notify_fail("��������������嶾������\n");
	me->receive_damage("qi", 20);
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
if (damage_bonus <10) damage_bonus=10;
  if( random(damage_bonus/2) > victim->query_con() ) {
		victim->receive_wound("qi", damage_bonus/ 3 );
        return HIM "$n���о޶����ƺ�һ��,���ӻ������Σ�\n" NOR;
	}
    if ( victim->query("family/family_name")!= "�嶾��" && me->query_skill("wudu-shengong",1)>40) {
	 switch( random(5) ) {
		case 0:
            victim->apply_condition("snake_poison", (me->query_skill("wudu-shengong"))/10 +
			victim->query_condition("snake_poison"));
			break;
		case 1:
            victim->apply_condition("zhizhu_poison", (me->query_skill("wudu-shengong"))/10 +
			victim->query_condition("zhizhu_poison"));
			break;
		case 2:
            victim->apply_condition("wugong_poison", (me->query_skill("wudu-shengong"))/10 +
			victim->query_condition("wugong_poison"));
			break;
		case 3:
            victim->apply_condition("xiezi_poison", (me->query_skill("wudu-shengong"))/10 +
			victim->query_condition("xiezi_poison"));
			break;
		case 4:
            victim->apply_condition("chanchu_poison", (me->query_skill("wudu-shengong"))/10 +
			victim->query_condition("chanchu_poison"));
			break;
	}
        return HIR "$nֻ�����˴�һ���飬�ƺ��ж��ˡ�\n" NOR;
   }
}
string perform_action_file(string action)
{
	return __DIR__"wudu-goufa/" + action;
}
