// tianshan-zhang.c, based on dagou-bang.c
// by yucao
// Modified by Hop 97.01.05
// Added by Yzuo 97.04.08

#include <ansi.h>
inherit SKILL;  
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

mapping *action = ({
([  "action": "$N�߾�$w, һ��"+(order[random(13)])+"��ѩ��������"NOR"�������������$n��$l",
        "dodge": 10,
        "force" : 170,
        "damage": 225,
        "lvl" : 3,
        "damage_type": "����"
]),

([  "action": "$Nʹ��һ��"+(order[random(13)])+"����ɽѩҰ��"NOR"������$w��ס����ɨ��$n��$l",
        "dodge": 1,
        "force" : 100,
        "damage": 250,
        "lvl" : 5,
        "damage_type": "����"
]),

([  "action": "$Nʹ��һ��"+(order[random(13)])+"�������ѩ��"NOR"���Ӷ�����$w�Ӹ����������$n��$l",
        "dodge": -3,
        "force" : 150,
        "damage": 180,
        "lvl" : 55,
        "damage_type": "����"
]),

([  "action": "�����ú�һ�����죬$Nһ��"+(order[random(13)])+"��ѩ����ơ�"NOR"������$w��������$n��$l",
        "dodge": -10,
        "force" : 200,
        "damage": 110,
        "lvl" : 79,
        "damage_type": "����"
]),
([	"action": "$Nʹ��һ��"+(order[random(13)])+"�����ӿ�����"NOR"������$w�󿪴���ɨ��$n��$l",
	"force" : 80,
	"dodge": 30,
	"damage": 140,
	"lvl" : 1,
	"damage_type": "����"
]),
([	"action": "$N����$w������죬һ��"+(order[random(13)])+"��ɽ��������"NOR"��$n��$l��ȥ",
	"force" : 140,
	"dodge": 50,
	"damage": 170,
	"lvl" : 13,
	"damage_type": "����"
]),
([	"action": "$N����$w���Ӹ�����ʹһ��"+(order[random(13)])+"����ɽѩ����"NOR"����$n��$l",
	"force" : 200,
	"dodge": 70,
	"damage": 200,
	"lvl" : 30,
	"damage_type": "����"
]),
([	"action": "$Nһ��"+(order[random(13)])+"��������ѩ��"NOR"������Ʈ�����ߣ�����$w����$n��$l",
	"force" : 240,
	"dodge": 80,
	"damage": 220,
	"lvl" : 45,
	"damage_type": "����"
]),
([	"action": "$Nʹһ��"+(order[random(13)])+"���ع�õ硹"NOR"������$w��һ���������$n��$l",
	"force" : 270,
	"dodge": 120,
	"damage": 230,
	"lvl" : 60,
	"damage_type": "����"
]),
([	"action": "$Nʹ����"+(order[random(13)])+"����˪��Ӱ��"NOR"��$w������Ӱ��������$n��$l",
	"force" : 300,
	"dodge": 120,
	"damage": 330,
	"lvl" : 75,
	"damage_type": "����"
]),
([	"action": "$N��$wƾ��һָ��һ��"+(order[random(13)])+"����ʯ���̡�"NOR"����$n��$l",
	"force" : 320,
	"dodge": 120,
	"damage": 340,
	"lvl" : 90,
	"damage_type": "����"
]),
([	"action": "$N����һԾ������$wһ��"+(order[random(13)])+"������������"NOR"��׼$n��$lɨȥ",
	"force" : 340,
	"dodge": 140,
	"damage": 350,
	"lvl" : 105,
	"damage_type": "����"
]),
([	"action": "$N����$w�й�ֱ����һʽ"+(order[random(13)])+"�����ȳ��硹"NOR"��׼$n��$l��ȥ",
	"force" : 350,
	"dodge": 140,
	"damage": 360,
	"lvl" : 120,
	"damage_type": "����"
]),
([	"action": "$Nһ��"+(order[random(13)])+"�����·ת��"NOR"��$w�����ػ���$n��$l��ȥ",
	"force" : 380,
	"dodge": 150,
	"damage":480,
	"lvl" :  145,
	"damage_type": "����"
]),
});

mapping query_action(object me, object weapon)
{
        int i, level,lvl_temp;
       lvl_temp = random((int)me->query_skill("tianshan-zhang", 1)+(int)me->query_skill("staff"));
        if (( (int)me->query_skill("staff", 1) >= 150 ) 
        &&      ( (int)me->query_skill("tianshan-zhang", 1) >= 150 )
        &&      ( (int)me->query_skill("huagong-dafa",1) >= 150 )
        &&      ( (int)me->query("neili") >= 800 )
        && (int)me->query_skill("poison",1) >= 100  
       &&      ( lvl_temp>=150)) {
return ([
       "action": BLU "$N�ٺ�һ����Ц,�������ȶ�һĨ,$w��ת�Ӷ������Ƹ�Ϊ����!" NOR,
                "damage": lvl_temp+(int)me->query_str(),
                "parry":(int)me->query_skill("dodge")/5,
                "damage": 700,
                "force": 700,
                "damage_type": "����"]);
}
      level=(int)me->query_skill("tianshan-zhang",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}
mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{     
        int lvl_temp;
                int lvl;
        int flvl;

        lvl  = me->query_skill("tianshan-zhang", 1);
        flvl = me->query("jiali");
        if (lvl < 100 || ! damage_bonus ||
            me->query_skill_mapped("force") != "huagong-dafa" ||
            me->query("neili") < 300)
                return;
       lvl_temp = random((int)me->query_skill("tianshan-zhang", 1)+(int)me->query_skill("staff"));
        if (random(5)==0)
        {
if (victim->query("neili") > 1500)
victim->add("neili",-600);
                return HIY "$n" HIY "�е�������ѩ���ڻ�һ������ʧ�ˡ���\n" NOR;
        }
else
        if (random(5)==0)
        {
if (victim->query("qi") > 500)
victim->add("qi",-250);
victim->add("eff_qi",-(50+random(200)));
victim->apply_condition("xx_poison",20);
victim->apply_condition("x2_sandu",20);
victim->apply_condition("sanpoison",20);
                return HIY "$n" HIY "�е��������Ƹ���һ�㣬ɢ����һ�ɼ���"
               "�ŵĶ������\n" NOR;
        }
        if (lvl_temp >=140) {
        if( random(lvl_temp) <= 100) 
        {
        victim->apply_condition("xx_poison", random((me->query_skill("huagong-dafa")
        +me->query_skill("poison",1))/30) + 1 + victim->query_condition("xx_poison"));
        tell_object(victim, HIG "�������ǰһ����!�ƺ����˶�\n" NOR );
        tell_object(victim, HIG "ԭ���Է�����Ĩ�Ķ�ҩ����ɢ���Ŷ�����\n" NOR );
        } else if( random(lvl_temp) > 100) {
victim->apply_condition("xx_poison", random((me->query_skill("huagong-dafa")
        +me->query_skill("poison",1))/15) + 1 + victim->query_condition("xx_poison"));
        tell_object(victim, HIG "����ñ����еĵط�һ����ľ!�ƺ����˶�\n" NOR );
        tell_object(victim, HIG "ԭ���Է�������ͿĨ�ж�ҩ!\n" NOR );

        }
      }
}

int valid_enable(string usage) { return (usage == "staff") || (usage == "parry"); }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 80)
		return notify_fail("�������������\n");
	return 1;
}
int ob_hit(object ob, object me, int damage)
{
        object wp1,weapon;
        string msg;
        int p,j,skill, neili, neili1;
        int level,level2,damage2;
        level = (int) me->query_skill("huagong-dafa",1);
        level2= (int) me->query_skill("huagong-dafa",1);
        neili = me->query("neili");
        neili1 = ob->query("neili");
damage2= (int) ob->query("neili",1)/7;
if (damage2>= 5000) damage2 = 5000;
if (random(8)==0 && level>=300 && me->query_skill_mapped("force") == "huagong-dafa")
{
if (ob->query("neili") >= damage2)
{
ob->add("neili",-damage2);
if (!ob->is_busy())	ob->start_busy(1);
}
msg = HIY"$Nʹ��������,$n��������ѩ���ڻ�һ������ʧ�ˡ���\n"NOR;

           message_vision(msg, me, ob);
           return j;
}       
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "staff")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("���������������ɽ�ȷ���\n");
	me->receive_damage("qi", 25);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"tianshan-zhang/" + action;
}
