// zimu-zhen.c ��ĸ�뷨
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
"zmqidu_poison",
});

string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});
mapping *action = ({
([	"action":		"$N˫���������裬һ��"+(order[random(13)])+"�������롹"NOR"��$wֱ��$n���ظ�Ҫ��",
	"dodge":		100,
        "force":		200,
	"damage":		300,
	"poison": 30,
	"lvl" : 0,
	"skill_name" : "������",
	"post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
	"damage_type":	"����"
]),
([	"action":		"$N���λζ���һ��"+(order[random(13)])+"�������롹"NOR"������$w��һ�����ߣ���$n�ʺ��ȥ",
	"dodge":		20,
	"force":		200,
	"damage":		300,
	"poison": 40,
	"lvl" : 60,
	"skill_name" : "������",
	"post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
	"damage_type":	"����"
]),
([	"action":		"$N��ָ΢�ţ�һ��"+(order[random(13)])+"����Ѫ�롹"NOR"������$w���ð���$nȫ��ȥ",
	"dodge":		40,
	"force":		200,
	"damage":		400,
	"poison": 50,
 	"lvl" : 90,
	"skill_name" : "��Ѫ��",
	"post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
	"damage_type":	"����"
]),
([	"action":		"$N���һ����һ��"+(order[random(13)])+"������롹"NOR"��$w�û�����Ŀ����������$n",
	"dodge":		50,
	"force":		200,
	"damage":		460,
	"poison": 60,
	"lvl" : 100,
	"skill_name" : "�����",
	"post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
	"damage_type":	"����"
]),
([	"action":		"$N��һԾ��һ��"+(order[random(13)])+"�������롹"NOR"��$w�����������磬����$nȫ��",
	"dodge":		60,
	"force":		200,
	"damage":		500,
	"poison": 70,
 	"lvl" : 110,
	"skill_name" : "������",
	"post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
	"damage_type":	"����"
]),
([	"action":		"$N˫Ŀ��â������һ��"+(order[random(13)])+"������롹"NOR"������$wȫ�����ַɳ�����ɽ���������$nȫ��",
	"dodge":		50,
	"force":		200,
	"damage":		550,
	"poison": 80,
	"lvl" : 120,
	"skill_name":  "�����",
	"post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
	"damage_type":	"����"
]),
([	"action":		"$N������Х��һ��"+(order[random(13)])+"����ħ�롹"NOR"��$w��Ȼ����һ��ǿ�Ҿ��磬ɨ��$n",
	"dodge":		70,
	"force":		200,
	"damage":		600,
	"poison": 90,
	"lvl" : 130,
	"skill_name" : "��ħ��",
	"post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
	"damage_type":	"����"
]),
([	"action":		"$N����ɱ��ͻȻ��ʢ��һ��"+(order[random(13)])+"����ɷ�롹"NOR"��$w�ɻȰ����$nȫ��",
	"dodge":		100,
        "force":		200,
	"damage":		700,
	"poison": 100,
	"lvl" : 200,
	"skill_name" : "��ɷ��",
	"post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
	"damage_type":	"����"
]),
});

int valid_enable(string usage) { return (usage == "throwing") || (usage == "parry"); }

int valid_learn(object me)
{
	object weapon;

	if( (int)me->query("max_neili") < 500 )
		return notify_fail("�������������ĸ������, �ٶ������ɡ�\n");

	if ((int)me->query_skill("biyun-xinfa", 1) < 100)
		return notify_fail("��ı����ķ����̫ǳ��\n");
	if ((int)me->query_skill("pili-biao", 1) < 200)
		return notify_fail("��������ڻ��̫ǳ��\n");
	if ((int)me->query_skill("liuxing-biao", 1) < 200)
		return notify_fail("������Ǹ����ڻ��̫ǳ��\n");
	if ((int)me->query_skill("zhuihun-biao", 1) < 200)
		return notify_fail("���׷������ڻ��̫ǳ��\n");


	if ( !objectp(weapon = me->query_temp("weapon"))
	|| ( string)weapon->query("skill_type") != "throwing" )
		return notify_fail("�����ϲ�û�а�������ô����\n");

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
	level   = (int) me->query_skill("zimu-zhen",1);
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
	if ((int)me->query_skill("pili-biao", 1) < 200)
		return notify_fail("��������ڻ��̫ǳ��\n");
	if ((int)me->query_skill("liuxing-biao", 1) < 200)
		return notify_fail("������Ǹ����ڻ��̫ǳ��\n");
	if ((int)me->query_skill("zhuihun-biao", 1) < 200)
		return notify_fail("���׷������ڻ��̫ǳ��\n");

	if ((int)me->query("qi") < 100)
		return notify_fail("���������������ĸ�뷨��\n");
	if ((int)me->query("jing") < 100)
		return notify_fail("��ľ���������ĸ�뷨��\n");
	if ((int)me->query("neili") < 100)
		return notify_fail("���������������ĸ�뷨��\n");

	me->receive_damage("qi", 60);
	me->receive_damage("jing", 60);
	me->receive_damage("neili", 60);
	return 1;
}

string perform_action_file(string action)
{
	if ( this_player()->query_skill("zimu-zhen", 1) >= 50 )
		return __DIR__"zimu-zhen/" + action;
}
mixed hit_ob(object me, object victim, int damage_bonus, int factor, string limb)
{
	int level, jiali, time,level2;
	object weapon;

        int lvl;
        int flvl;
	int damage,damage2;
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

	weapon = me->query_temp("weapon");
             
	if (random(5)==1 && me->query_skill("zhuihun-biao",1)>100)
	{
	victim->add("qi",-me->query_skill("zhuihun-biao",1)/2);
	me->add("qi",me->query_skill("zhuihun-biao",1)/2);
	return HIR"$nֻ���˿�����Ѫ���Ű�������!����һ��!!\n"NOR;
	}
        if(weapon->query("name")=="��ĸ����" && weapon->query("id")=="zimuzhen" && me->query_temp("marks/��ĸ��")         ){
          victim->apply_condition("zm_poison", random(me->query_skill("zimu-zhen")) + 50 +
	  victim->query_condition("zm_poison"));
	}
        level = (int) me->query_skill("biyun-xinfa",1);
        level2= (int) me->query_skill("zimu-zhen",1);
	jiali = me->query("jiali");
if (!me) return;
if (!victim) return;
if (!weapon) return;
if (!level2) return;
if (!jiali) jiali=10;
	if( damage_bonus > 10 && random(level2)>150 && random(2)==0) {
	victim->receive_wound("qi", (random(jiali)+100));
	return HIB"$nֻ��$l��һ���������˿ھ������˱���ɫ��Ѫ!\n"NOR;
        }
}

int ob_hit(object ob, object me, int damage)
{
	object weapon = me->query_temp("weapon");
        string msg,dodge_skill,*limbs;
        int i, j, level,level2, p, q;
        
        limbs = ob->query("limbs");
        level = me->query_skill("zimu-zhen", 1);
level2 = me->query_skill("pili-biao", 1);
        if( me->is_busy()) return 1;
        if (  level2 > 100
        && random(5)==1){
 
            msg = HIC"$n����ʱ��ͻȻ���õ����������˿�����!\n"NOR;
            ob->add("neili",-level2/2);
            me->add("neili",level2/2);
            if ( random(2) == 1){
             if (!ob->is_busy())
             ob->start_busy(2+random(2));
         }
        if( damage < 50 ) return 1;
        if (  random(level) > 180
         && me->query_skill_mapped("throwing") =="zimu-zhen"
         && me->query_skill_mapped("parry") =="zimu-zhen"
         && weapon
         && weapon->query("skill_type") == "throwing"
         && me->query_skill("throwing") > 300
         && random(me->query_skill("throwing",1)) > 150
         && !me->is_busy()
         && me->query("neili") > 200 
         && me->query("max_neili") > 900
         && random(me->query_int()) >= 20 ){
            me->add("neili", -100);
            msg = HIB"$n�ճ����к󣬾������ϵ��˿�һ�����������ܵ��ڵ��ϴ����˹���\n"NOR;
            ob->add("neili",-ob->query("neili")/15);
            if ( random(2) == 1){
             if (!ob->is_busy())
             ob->start_busy(3);
}
else             msg = HIG"$n�ճ����к󣬾������ϵ��˿�һ����������$nҧ��ҧ����ͦ�˹�ȥ��\n"NOR;
            message_vision(msg, me, ob);
            return damage;
        }
               }
}
