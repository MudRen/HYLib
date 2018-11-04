// lanhua-shou.c -������Ѩ��
// Modified by Venus Oct.1997
#include <combat.h>
#include <ansi.h>

inherit SKILL;
string* xuedao = ({
        "�޹�Ѩ",
        "�ز�Ѩ",
        "�羮Ѩ",
        "�ճ�Ѩ",
        "����Ѩ",
        "���Ѩ",
        "����Ѩ",
        "�縮Ѩ",
        "����Ѩ",
        "�յ�Ѩ",
        "ǿ��Ѩ",
        "�ٺ�Ѩ",
        "����Ѩ",
        "����Ѩ",
        "����Ѩ",
        "��׵Ѩ",
        "̫��Ѩ",
        "����Ѩ",
        "����Ѩ",
        "�βѨ",
        "������",
        "����Ѩ"
});

mapping *action = ({
([  "action" : "$N������ָ�ֿ���΢΢һ�����ٲ�£����һ����һʽ�������Ƶ�����
����$n������ҪѨ",
    "force" : 150,
    "dodge" : 5,
    "damage": 145,
    "damage_type" : "����",
    "lvl" : 0,
    "skill_name" : "�����Ƶ�"
]),
([  "action" : "$N��������$n��һʽ�����Ʊ��¡���������ָ������������$n����ǰ
��Ѩ",
    "force" : 160,
    "dodge" : 5,
    "damage": 245,
    "damage_type" : "����",
    "lvl" : 10,
    "skill_name" : "���Ʊ���"
]),
([  "action" : "$Nʹһʽ�������������������鹥�����ֲ�ָбǰ����������$n�ļ�
��Ѩ",
    "force" : 170,
    "dodge" : 15,
    "damage": 245,
    "damage_type" : "����",
    "lvl" : 20,
    "skill_name" : "��������"
]),
([  "action" : "$N���ƻ��أ�΢΢�������ƹ��ϣ�һʽ������ŪӰ������������$n
����ͻѨ",
    "force" : 190,
    "dodge" : -5,
    "damage": 245,
    "damage_type" : "����",
    "lvl" : 30,
    "skill_name" : "����ŪӰ"
]),
([  "action" : "$Nʹһʽ���������塹����Ӱ����������$n����͵�����$n�Ĵ�׵
Ѩ",
    "force" : 210,
    "dodge" : 10,
    "damage": 245,
    "damage_type" : "����",
    "lvl" : 42,
    "skill_name" : "��������"
]),
([  "action" : "$N���������������ϵ�����ǰ������ָ�η��ϣ�΢��һ������һʽ��
�����뷼����˫���������һ��������������������$n�Ļ��ǡ���ᡢ�Ϲ�������Ѩ",
    "force" : 240,
    "dodge" : 5,
    "damage_type" : "����",
    "damage": 145,
    "lvl" : 54,
    "skill_name" : "�����뷼"
]),
([  "action" : "$N����ƮƮ������Ծ��һʽ����Ӱ���㡹���Ӹ����£�����һ����
������$n�İٻ��Ѩ",
    "force" : 270,
    "dodge" : 20,
    "damage": 145,
    "damage_type" : "����",
    "lvl" : 66,
    "skill_name" : "��Ӱ����"
]),
([  "action" : "$N����ʩչ����������Բ����˫�ּ�����һ�����ľ�������$n������
�¸���ҪѨ",
    "force" : 300,
    "dodge" : 25,
    "damage": 145,
    "damage_type" : "����",
    "lvl" : 80,
    "skill_name" : "������Բ"
]),
([      "action" : "$N���ֺ�������֮�Σ���ָ��£��Ĩ������$n�������Ѩ",
	"force" : 250,
	"dodge" : 5,
	"parry" : 2,
	"damage": 115,
	"weapon": "����",
	"lvl" : 55,
	"skill_name" : "����������ʽ",
	"damage_type" : "����"
]),
([      "action" : "$N������ҡ��������������������ԡ��㻮��$n��$l",
	"force" : 520,
	"dodge" : 10,
	"parry" : 5,
	"damage": 245,
	"weapon": "����",
	"lvl" : 85,
	"skill_name" : "����������ʽ",
	"damage_type" : "����"
]),

});

int valid_enable(string usage) { return usage=="hand" ||  usage=="parry"; }     

int valid_combine(string combo) { return combo=="tanzhi-shentong"; }

int valid_learn(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
       return notify_fail(HIC"��������Ѩ�ֱ�����֡�\n"NOR);
    if ((int)me->query_skill("bibo-shengong", 1) < 20)
       return notify_fail("��ı̲��񹦻�򲻹����޷�ѧ������Ѩ�֡�\n");
    if ((int)me->query("max_neili") < 200)
       return notify_fail("�������̫�����޷���������Ѩ�֡�\n");
    return 1;
}
string query_skill_name(int level)
{
    int i;
    for(i = sizeof(action)-1; i >= 0; i--)
    if(level >= action[i]["lvl"])
    return action[i]["skill_name"];
}


int practice_skill(object me)
{
    if ((int)me->query("qi") < 30)
       return notify_fail("�������̫���ˣ��޷���������Ѩ�֡�\n");
    me->receive_damage("qi", 25);
    return 1;
}

string perform_action_file(string action)
{
        return __DIR__"lanhua-shou/" + action;
}

mapping query_action(object me, object weapon)
{
        int i, level, bt, dp;
	object victim;
	string xue;
        string name1,name2;
        
        level  = (int) me->query_skill("lanhua-shou",1);
        bt  = (int) me->query_skill("force",1);
	xue = xuedao[random(sizeof(xuedao))];

	level   = (int) me->query_skill("lanhua-shou",1);
        if (random(level) > 160 && me->query_skill("force") > 250 && me->query("neili") >= 600) {
		me->add("neili", -120);
		me->set_temp("autopfm_lhs", 1);
		return ([
		"action": HIC"����$N"+(random(2)?"��":"��")+"��������ָ�ֿ���������������̬�������ԣ��������ţ��������ݣ���֮���赭д���������µط���$n��"+xue+""NOR,
		"force" : 560+random(40),
		"dodge" : 20,
		"damage": 560+random(20),
		"damage_type" : "����" ]);
	}

        if (random(level) > 130 && me->query_skill("force") > 250 && me->query("neili") >= 600) {
		me->add("neili", -120);
		me->set_temp("autopfm_lhs", 1);
		return ([
		"action": HIC"$N��ȻһЦ��������������ި��������֣�����ʵ�죬���ػ������$n��"+xue+"������ÿ졢׼���桢������Ҫ��"NOR,
		"force" : 550,
		"dodge" : 20,
		"damage": 550,
		"damage_type" : "����" ]);
	}

        if (random(level) > 80 && me->query_skill("force") > 250 && me->query("neili") >= 600) {
		me->add("neili", -120);
		me->set_temp("autopfm_lhs", 1);
		return ([
		"action": HIR "$N˫�ֽ�����ʹ����������˫��ʽ������״�����������ٳ��ţ��������΢΢ҡ�ڡ�$n������Щ������ȴ��Ȼ����$N��ʮָ�ѷ�����ǰ��" NOR,
		"damage": 456,
		"force": 480,
               	"dodge" : 15,
                "parry" : 15,
		"damage_type": "����"]);
	}
	me->set_temp("autopfm_lhs");
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	int hurt, lvl = me->query_skill("lanhua-shou", 1);
        string name1,name2;
        object weapon = victim->query_temp("weapon");
       string msg;
       int j, k;
 int level;
       j = me->query_skill("yuxiao-jian", 1);
       k = me->query_skill("qimen-wuxing",1);
 level = (int) me->query_skill("bibo-shengong",1);
if (random(6)==0 && level>=300 && me->query_skill_mapped("force") == "bibo-shengong")
        {
if (victim->query("qi") > 600)
victim->add("qi",-250+random(200));
victim->add("eff_qi",-(50+random(200)));
                me->add("neili", -20);
if (!victim->is_busy()) victim->start_busy(1);
return HIR "$Nʩչ����������,$n����һ��,������$l�������Ѫ��!!\n";
        }

	if (me->query_temp("autopfm_lhs")
	&& !me->is_busy()) {
		if (!random(3)) {
			if (!victim->is_busy())
			victim->start_busy(3) + random(3);
			me->add("neili", -40);
			hurt = (victim->query("neili") < lvl / 6 ? victim->query("neili") : lvl / 6);
			victim->add("neili", -hurt);
			victim->add("qi", -lvl / 5);
			victim->add("eff_qi", -lvl / 5);
			me->improve_skill("lanhua-shou", random(me->query("int")/4));
			me->delete_temp("autopfm_lhs");
			return HIR "$n��$N����˫��ʽͬʱ����������Ѩ����ֻ����ȫ���ʹ�������ھ������Ĵ��Ҵ�,һʱ��Ȼ�޷����ƣ�\n" NOR;
		}
		return 0;
	}
	if (victim->is_busy()) return 0;
	if (!random(7)) {
		victim->start_busy(3) + random(2);
		if (!random(4)
		&& !me->is_busy()) {
			me->add("neili", -20);
			hurt = (victim->query("neili") < lvl / 7 ? victim->query("neili") : lvl / 7);
			victim->add("neili", -hurt);
			victim->add("qi", -lvl / 8);
			victim->add("eff_qi", -lvl / 8);
			me->improve_skill("lanhua-shou", random(me->query("int")/5));
			return HIR "$n��$N������Ѩ����ֻ����һ�����ĵ���ʹ���������ɵ�һ�ͣ�\n" NOR;
		}
		return CYN "$n��$N������Ѩ�����������ɵ�һ�ͣ�\n" NOR;
	}
        if (random(lvl)>200
        && random(10)>5
        && !me->is_busy()) {

            switch (random(3)) {
               case 0: 
                    if (weapon){
                       weapon->unwield();
                       weapon->move(environment(victim));
                       victim->add("neili", -lvl);
                       return CYN "$n����Ҷʽ�����ˡ�"HIR+name2+CYN"������һ�飬"+weapon->query("name")+CYN"�ѳֲ�ס�����ڵ��ϡ�\n" NOR; } else {
                       victim->add("neili", -lvl);
                       return CYN "$n����Ҷʽ�����ˡ�"HIR+name2+CYN"������һ�飬����Ҳ�ܵ����񵴣�\n" NOR; }
                    break;
               case 1: 
                    victim->add_temp("apply/dexerity",-lvl/10);
                    victim->add_temp("apply/strength",-lvl/10);
                    victim->add_temp("apply/constitution",-lvl/10);
                    victim->add_temp("apply/intelligence",-lvl/10);
                    call_out("remove_effect", lvl/10, victim, lvl/10);
                    return CYN "$n�����ʽ����������������Ѩ��ս�������\n" NOR;
                    break;
               case 2: 
                    victim->start_busy(2 + random(2));
                    if (weapon) {
                        victim->map_skill(weapon->query("skill_type"));
                        victim->set_temp("no_enable",1); } else {
                        victim->prepare_skill("leg");
                        victim->prepare_skill("hand");
                        victim->prepare_skill("strike");
                        victim->prepare_skill("cuff");
                        victim->prepare_skill("claw");
                        victim->prepare_skill("unarmed");
                        victim->prepare_skill("sword");
                        victim->prepare_skill("blade");
                        victim->prepare_skill("parry");
                        victim->prepare_skill("finger");
                        victim->set_temp("no_prepare",1); }
                    call_out("remove_special", lvl/10, victim);
                    return CYN "$n������ʽ�����ˡ�"HIR+name1+CYN"�����书�����������޷�ʩչ������\n" NOR;
                    break;
            }
        }
}
void remove_effect(object victim, int lvl)
{
        if (!victim) return;
        victim->add_temp("apply/dexerity",lvl);
        victim->add_temp("apply/strength",lvl);
        victim->add_temp("apply/constitution",lvl);
        victim->add_temp("apply/intelligence",lvl);
        message_vision(HIW"$N��������ѨѪ���п��ˡ�\n"NOR, victim);
}

void remove_special(object victim)
{
        if (!victim) return;
        victim->delete_temp("no_enable");
        victim->delete_temp("no_prepare");
}

