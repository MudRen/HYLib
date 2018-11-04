
// qianzhu-wandushou.c  ǧ������
// by star

#include <ansi.h>
inherit SKILL;  
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

mapping *action = ({
([      "action" : MAG "$N�������, �������˸���ʾ�, ʳָָ��$n������·Ҫ��" NOR,
        "force" : 100,
        "dodge" : 5,
        "lvl" : 0,
        "damage" : 10,
        "weapon": "ָ��",
        "skill_name" : "��������",
        "damage_type" : "����"
]),
([      "action" : BLU "$N����ʳָ�ӵڶ�ָ����ָ���Ȼ�����ڣ�����$n$l��ȥ" NOR,
        "force" : 200,
        "dodge" : 5,
        "lvl" : 60,
        "damage" : 20,
        "weapon": "ָ��",
        "skill_name" : "�ڳ�˷�",
        "damage_type" : "����"
]),
([      "action" : YEL "$Nٿ��̤ǰ����ָ�ɷ磬����$n�ظ�֮���崦��Ѩ" NOR,
        "force" : 300,
        "dodge" : 10,
        "lvl" : 100,
        "damage" : 40,
        "weapon": "ָ��",
        "skill_name" : "���鶾��",
        "damage_type" : "����"
]),
([      "action" : CYN "$N���Ϻ�����ʢ��ָ����Ӱ��Ȼ���ţ�������ʯ�𣬴���$n��$l" NOR,
        "force" : 400,
        "dodge" : 25,
        "lvl" : 150,
        "damage" : 80,
        "weapon": "ָ��",
        "skill_name" : "���붾",
        "damage_type" : "����"
]),
([      "action": "$N����һ�ζ�����һ��"+(order[random(13)])+"��С���꡹"NOR"��˫�ƴ���һ���ȷ�����$n��ǰ��",
        "dodge": 10,
        "force": 200,
        "lvl" : 0,
        "damage_type": "����"
]),
([      "action": "$N���λ���һ����������$n��ת��һ��"+(order[random(13)])+"�������ֻ֡�"NOR"��˫�ƻó�������Ӱ����$n",
        "dodge": 40,
        "force": 250,
        "lvl" : 20,
        "damage_type": "����"
]),
([	"action": "$N���һ����һ��"+(order[random(13)])+"��������š�"NOR"��������޸���ɽ����һ���ȷ�������$n������",
	"dodge": -20,
	"force": 300,
	"lvl" : 50,
	"damage_type": "����"
]),
([	"action": "$Nһ����Ц��һ��"+(order[random(13)])+"�����߾�ת��"NOR"������һ��������һ�������ĳ����ֱ�����\n�޹ǣ��Ƶ���;������ű䣬����Ȱ�ӡ��$n��$l",
	"dodge": 60,
	"lvl" : 80,
	"force": 350,
	"damage_type": "����"
]),
([	"action": "$N������ǰ��һ��"+(order[random(13)])+"���ظ����硹"NOR"��˫�������ĳ���һ���Ƴ��ǵĺ���������\n͸������$n��Χ�Ŀ�����������",
	"dodge": 10,
	"force": 400,
	"lvl" : 120,
	"damage_type": "����"
]),
([	"action": "$N����һ�������κ����������򣬷���ײ��$n��һ��"+(order[random(13)])+"���Ʒ��´̡�"NOR"�����罣��\nֱ��$n������",
	"dodge": 80,
	"lvl" : 150,
	"force": 450,
	"damage_type": "����"
]),
([	"action": "$Nһ���������������𣬰����һʽ"+(order[random(13)])+"��������β��"NOR"�����ֻ���$n��$l",
	"dodge": 40,
	"lvl" : 200,
	"force": 500,
	"damage_type": "����"
]),
([	"action": "$N���һ���������嶾�񹦣�һ��"+(order[random(13)])+"���������"NOR"��ɲ�Ǽ�ȫ��ë�����̣�һ\n�Ա��̵�˫צ�����ĳ�$n��$lץȥ",
	"dodge": 20,
	"lvl" : 250,
	"force": 600,
	"damage_type": "����"
]),
});

int valid_enable(string usage) { return usage=="unarmed" || usage=="parry"; }


mapping query_action(object me, object weapon)
{
    mapping a_action;
    int i, level,rlevel;
    level   = (int) me->query_skill("qianzhu-wandushou", 1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]){
                        a_action = action[NewRandom(i, 5, level/5)];
                        break;
                }
    a_action["parry"]  = 0-level/3;
    a_action["attack"]  = level/3;
    a_action["damage"] = level/2;
if ( me->query("family/family_name") == "�嶾��")
{
rlevel=(int) me->query_skill("wudu-shengong", 1);
{
if (!rlevel) rlevel=50;
    a_action["attack"]  = rlevel;
    a_action["damage"] = rlevel+50;
}
}
    return a_action;

}

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("��ǧ�����ֱ�����֡�\n");
	if ((int)me->query("max_neili") < 500)
		return notify_fail("�������̫�����޷���ǧ������");
	return 1;
}


int practice_skill(object me)
{
	if ((int)me->query("qi") < 80)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("jing") < 80)
		return notify_fail("��ľ���̫���ˡ�\n");
	if ((int)me->query("neili") < 100)
		return notify_fail("�������������ǧ�����֡�\n");
	me->receive_damage("qi", 60);
	me->add("jing", -60);
	return 1;
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
if (damage_bonus <10) damage_bonus=10;
      if( random(me->query_skill("qianzhu-wandushou",1)) > 50 ) 
{
	  victim->receive_wound("qi", damage_bonus/3);
        return HIM "$n���о޶����ƺ�һ��,���ӻ������Σ�\n" NOR;
}
      if (random(me->query_skill("qianzhu-wandushou",1)) > 150 ) {
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
void skill_improved(object me)
{
  if(random(15) < 1 && me->query("per") > 5){
       tell_object(me, HIR "���Ȼ�������ڶ�����ܣ����϶�ʱ����һ�������\n" NOR );
       me->add("per", -1);
  }
}

string perform_action_file(string action)
{
	return __DIR__"qianzhu-wandushou/" + action;
}
