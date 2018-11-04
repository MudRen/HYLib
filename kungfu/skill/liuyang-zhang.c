// SKILL liuyang-zhang.c

#include <ansi.h>
#include <combat.h>
inherit SKILL;  
int baihong(object me, object victim, int damage);
object offensive_target(object me)
{
	int sz;
	object *enemy;

	enemy = me->query_enemy();
	if( !enemy || !arrayp(enemy) ) return 0;

	sz = sizeof(enemy);
	if( sz > 4 ) sz = 4;

	if( sz > 0 ) return enemy[random(sz)];
	else return 0;
}


string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

mapping *action = ({
([	"action" : "$Nһ��"+(order[random(13)])+"�������۽�"NOR"�����Ƶ�������֮�ϣ�����$n",
	"force" : 130,
	"dodge" : 20,
	"damage" : 250,
	"lvl" : 0,
	"skill_name" : "�����۽�",
	"damage_type" : "����"
]),
([	"action" : "$Nһ��"+(order[random(13)])+"�������ƶ�����"NOR"����ɫ���أ�˫����ƮƮ������$n",
	"force" : 150,
	"dodge" : 10,
	"damage" : 200,
	"lvl" : 20,
	"skill_name" : "�����ƶ���",
	"damage_type" : "����"
]),
([	"action" : "$Nһ��"+(order[random(13)])+"����б��·��ϼ����"NOR"��˫�ƻû�һƬ��Ӱ����$n�������ڡ�",
	"force" : 150,
	"dodge" : 30,
	"damage" : 235,
	"lvl" : 30,
	"skill_name" : "��б��·��ϼ��",
	"damage_type" : "����"
]),

([	"action" : "$Nһ��"+(order[random(13)])+"������������"NOR"����$n��$l��������",
	"force" : 200,
	"dodge" : 25,
	"damage" : 250,
	"lvl" : 40,
	"skill_name" : "��������",
    "damage_type" : "����"
]),
([	"action" : "$Nһ��"+(order[random(13)])+"������һ���ͽ��ѡ�"NOR"��ֻ��һƬ��Ӱ����$n",
	"force" : 250,
	"dodge" : 20,
	"damage" : 200,
	"lvl" : 40,
	"skill_name" : "����һ���ͽ���",
	"damage_type" : "����"
]),

([	"action" : "$N˫��ƽ�ӣ�һ��"+(order[random(13)])+"����ϼ�����"NOR"����$n",
	"force" : 300,
	"dodge" : 25,
	"damage" : 250,
	"lvl" : 60,
	"skill_name" : "��ϼ������",
            "damage_type" : "����"
]),
([	"action" : "$Nһ��"+(order[random(13)])+"�����ղγ��֡�"NOR"��ֻ��һƬ��Ӱ����$n",
	"force" : 350,
	"dodge" : 130,
	"damage" : 280,
	"lvl" : 70,
	"skill_name" : "���ղγ���",
	"damage_type" : "����"
]),

([	"action" : "$N������Σ�����һ��"+(order[random(13)])+"����ϼ��Ѧᡡ�"NOR"����$n��ͷ��",
	"force" : 350,
	"dodge" : 30,
	"damage" : 290,
	"lvl" : 80,
	"skill_name" : "��ϼ��Ѧ�",
           "damage_type" : "����"
]),
([	"action" : "$Nʩ��"+(order[random(13)])+"�������������"NOR"�����ֺ�ɨ$n��$l�����ֹ���$n���ؿ�",
	"force" : 400,
	"dodge" : 110,
	"damage" : 290,
	"lvl" : 90,
	"skill_name" : "���������",
            "damage_type" : "����"
]),
([	"action" : "$Nʩ��"+(order[random(13)])+"�����������"NOR"��˫��ͬʱ����$n��$l",
	"force" : 450,
	"dodge" : 110,
	"damage" : 320,
	"lvl" : 100,
	"skill_name" : "�������",
    "damage_type" : "����"
])
});

int valid_enable(string usage) { return usage=="unarmed" || usage=="parry"||usage=="strike"; }

int valid_combine(string combo) { return combo=="zhemei-shou"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("����ɽ�����Ʊ�����֡�\n");
	if ((int)me->query("max_neili") < 50)
		return notify_fail("�������̫�����޷��������ơ�\n");
        if ((int)me->query_skill("qingyun-shou", 1) < 80)
		return notify_fail("��������ֻ��̫ǳ��\n");
        if ((int)me->query_skill("panyang-zhang", 1) < 80)
		return notify_fail("��������ƻ��̫ǳ��\n");
	return 1;
}

mapping query_action(object me, object weapon)
{
	int i, level, busy_time;
	object target = offensive_target(me);
	object victim;
	string *limbs, limb, msg;


	level = (int)me->query_skill("liuyang-zhang", 1);
	victim = me->select_opponent();
if (victim && me)
{
if (victim)
{
if (victim->query("limbs"))
{
	limbs = victim->query("limbs");
	limb = limbs[random(sizeof(limbs))];
}
	busy_time = level/20;
}
	if( (random(level) > 150 && random(10)>5) || (random(me->query_temp("lingjiu/baihong")) > 50 || me->query_temp("baihong_attack"))) 
	{
		switch( random(3) )
		{
			case 1: msg = HIW"����$N����һ���������ƹ�$N�����ӣ�ֱ����$p$l"NOR;
				break;
			case 2: msg = WHT"˭֪$Nһ��δ�ߵڶ����������������ؾ����������糤��֮�Σ���������"NOR;
				break;
			default: msg = WHT"ͻȻ��$N�����ƿգ�����$n"+limb+"���������棬�����絶��ת��б��$p$l"NOR;
				break;
		}

		me->add("neili", -30);


		return ([
			"action": msg,
			"force" : level+random(320)+90,
			"dodge" : 60,
			"damage": level+random(300)+90,
			"damage_type":"����",
			"post_action": (: baihong :)
			]);
	}
}

	for( i = sizeof(action); i > 0; i-- )
		if( level > action[i-1]["lvl"] )
			return action[NewRandom(i, 20, level/5)];
}





mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        int lvl;
        int flvl;
	int level, jiali, time,level2,damage,damage2;
	object weapon;
	weapon = me->query_temp("weapon");
        level = (int) me->query_skill("beiming-shengong",1);
        level2= (int) me->query_skill("beiming-shengong",1);

damage2= (int) victim->query("neili",1)/8;
if (damage2>= 3800) damage2 = 3800;
	
if (random(8)==0 && level>=300 && me->query_skill_mapped("force") == "beiming-shengong")
{

if (victim->query("neili") >= damage2)
{
victim->add("neili",-damage2);
me->add("neili",damage2);
}
	return HIW"$NͻȻʹ����ڤ��,$nȫ����������ˮ��ԴԴ����������$N������!\n"NOR;
}
        lvl  = me->query_skill("beiming-shengong", 1);
        if (lvl==0)
        lvl  = me->query_skill("bahuang-gong", 1);
        flvl = me->query("jiali");
if (me->query_skill_mapped("force") != "bahuang-gong" &&
me->query_skill_mapped("force") != "beiming-shengong")
                return;
        if (lvl < 80 || ! damage_bonus ||
            me->query("neili") < 300)
                return;
flvl=random(lvl)+50;
        if (random(5)==0)
        {
if (victim->query("qi") > flvl)
{
victim->add("qi",-flvl);
victim->add("eff_qi",-flvl);
victim->apply_condition("ss_poison", 10 +
		victim->query_condition("ss_poison"));
}
                return HIW "$n" HIW "�������˼���������!!\n" NOR;
        }
        else if (random(4)==0)
        {
if (victim->query("neili") > 1500)
victim->add("neili",-300);
if (me->query("neili") < me->query("max_neili"))
victim->add("neili",(random(lvl)+50));

return HIC "$n" HIC "ȫ��������ˮ��ԴԴ����������$N�����壡\n" NOR;
        }
}


int ob_hit(object ob, object me, int damage)
{
        object wp1,weapon;
        string msg;
        int p,j,skill, neili, neili1;
        int level,level2,damage2;
        level = (int) me->query_skill("bahuang-gong",1);
        level2= (int) me->query_skill("bahuang-gong",1);
        neili = me->query("neili");
        neili1 = ob->query("neili");
damage2= (int) ob->query("neili",1)/10;
if (damage2>= 3800) damage2 = 3800;
if (random(8)==0 && level>=300 && me->query_skill_mapped("force") == "bahuang-gong")
{
if (ob->query("neili") >= damage2)
{
ob->add("neili",-damage2);
me->add("neili",damage2);
if (!ob->is_busy())	ob->start_busy(1);
}
msg = HIR"$NͻȻ����,$nȫ����������ˮ��ԴԴ����������$N������\n"NOR;

           message_vision(msg, me, ob);
           return j;
}       



}





int practice_skill(object me)
{
	if ((int)me->query("qi") < 60)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("���������������ɽ�����ơ�\n");
        if ((int)me->query_skill("qingyun-shou", 1) < 80)
		return notify_fail("��������ֻ��̫ǳ��\n");
        if ((int)me->query_skill("panyang-zhang", 1) < 80)
		return notify_fail("��������ƻ��̫ǳ��\n");
	me->receive_damage("qi", 45);
	me->add("neili", -10);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"liuyang-zhang/" + action;
}


int baihong(object me, object victim, int damage)
{
	int level = (int)me->query_skill("liuyang-zhang", 1)/2;

	me->add_temp("baihong_attack", 1);

	if(  me->query_temp("baihong_attack") < 3 ) 
	{
		me->add_temp("apply/attack", level);

		if( me->query_temp("baihong_attack") == 1 )
{
			COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
}
		else me->delete_temp("baihong_attack");

		me->add_temp("apply/attack", -level);
		return 1;
	}
	else me->delete_temp("baihong_attack");
	return 1;
}
