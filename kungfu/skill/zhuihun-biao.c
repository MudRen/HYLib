// zhuihun-biao.c ׷�������
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


string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

mapping *action = ({
([	"action" : "$N����$wһ����һ��"+(order[random(13)])+"���޳����š�"NOR"������һ������$n��$l��ȥ",
	"force" : 120,
        "dodge" : 10,
        "parry" : 5,
	"damage" : 120,
	"damage_type" : "����",
	"post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
]),
([	"action" : "$Nһ��"+(order[random(13)])+"��С�"NOR"��ֻ��ơ�"NOR"��������һ����$w������Ϣ����$n�ľ���",
	"force" : 130,
        "dodge" : 10,
        "parry" : 10,
	"damage" : 125,
	"damage_type" : "����",
	"post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
]),
([	"action" : "$Nб�������һ��"+(order[random(13)])+"�����̧�Ρ�"NOR"��������ö$w,��ֱ����$n",
	"force" : 140,
        "dodge" : 15,
        "parry" : 5,
	"damage" : 130,
	"damage_type" : "����",
	"post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
]),
([	"action" : "$Nһ��"+(order[random(13)])+"���κβ���·��"NOR"��$w���ַɳ������Բ���˼��ĽǶȣ�����$n����",
	"force" : 160,
        "dodge" : 15,
        "parry" : 5,
	"damage" : 135,
	"damage_type" : "����",
	"post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
]),
([	"action" : "$Nһ��"+(order[random(13)])+"�������������ϻ꡹"NOR"��һ��$w��ͷ��������$n���ؿڡ�",
	"force" : 180,
        "dodge" : 10,
        "parry" : 5,
	"damage" : 140,
	"damage_type" : "����",
	"post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
]),
([	"action" : "$N����һ���ģ�����Ҫ������ȴ����â����������һ��"+(order[random(13)])+"���ϳ�������ȥ����"NOR"��$w�ɿ�����$n",
	"force" : 210,
        "dodge" : 15,
        "parry" : 15,
	"damage" : 150,
	"damage_type" : "����",
	"post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
]),
([	"action" : "$Nһ��"+(order[random(13)])+"�����޹µơ�"NOR"��$w��˸������ʱ��ʱ��������ʤ����$n��$l",
	"force" : 240,
        "dodge" : 5,
        "parry" : 15,
	"damage" : 160,
	"damage_type" : "����",
	"post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
]),
([	"action" : "$N�ڿ�Ծ��һ��"+(order[random(13)])+"����������"NOR"����ö$w���ֶ�����һö��һö����Ȼ����һ��������$n��ȫ���ȥ",
	"force" : 280,
        "dodge" : 20,
        "parry" : 10,
	"damage" : 180,
	"damage_type" : "����",
	"post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
]),
});


int valid_enable(string usage) { return (usage == "throwing") || (usage == "parry"); }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������������\n");
	if ((int)me->query_skill("biyun-xinfa", 1) < 20)
		return notify_fail("��ı����ķ���򲻹���\n");
	if ((int)me->query_skill("biye-wu", 1) < 20)
		return notify_fail("��ı�Ҷ�������̫ǳ��\n");
	return 1;
}

mapping query_action(object me, object weapon)
{
int zhaoshu, level;

zhaoshu = sizeof(action)-1;
level   = (int) me->query_skill("zhuihun-biao",1);

if (level < 60 )
zhaoshu--;
if (level < 55 )
zhaoshu--;
if (level < 50 )
zhaoshu--;
if (level < 40 )
zhaoshu--;
if (level < 30 )
zhaoshu--;
if (level < 20 )
zhaoshu--;
if (level < 10 )
zhaoshu--;

return action[random(zhaoshu)];
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "throwing")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("�������������׷������ڡ�\n");
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
	
	
	weapon;weapon=me->query_temp("weapon");
              
        if(weapon && 
        (string)weapon->query("skill_type") == "throwing"){
          victim->apply_condition("tmzhuihun_poison", random(me->query_skill("zhuihun-biao")) + 10 +
	  victim->query_condition("tmzhuihun_poison"));
	}
	if (random(5)==1 && me->query_skill("zhuihun-biao",1)>100 )
	{
	victim->add("qi",-me->query_skill("zhuihun-biao",1)/2);
	me->add("qi",me->query_skill("zhuihun-biao",1)/2);
	return HIR"$nֻ���˿�����Ѫ���Ű�������!����һ��!!\n"NOR;
	}
	
}
string perform_action_file(string action)
{
		return __DIR__"zhuihun-biao/" + action;
}