// taishan-sword.c ̩ɽ����
// Last Modified by suncity may 31st,2002
// Modified by Java Sep.1998

#include <ansi.h>
inherit SKILL;
#include <combat.h>
string type() { return "martial"; }
string martialtype() { return "skill"; }
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

int ruhe(object me, object victim, object weapon, int damage);


mapping *action = ({
([	"skill_name" :"��������",
	"action":  "$N����$wһ�Σ����һ���������һ��"HIB"���������ơ�"NOR"��ת������������΢����$w��$nбб��ȥ",
        "lvl" : 0
]),
([	"skill_name" :"������",
	"action":  "$N����$wȦת��һ��"HIC"�������ա�"NOR"ȥ���漲�������������$n��$l",
	"lvl" : 10
]),
([	"skill_name" :"������Ȫ",
	"action": "$NͻȻ��һ�䣬ͦ$w��$n��ȥ����һ����������������һ��"HIC"��������Ȫ��"NOR"",
	"lvl" : 20
]),
([	"name":    "ʯ�ػ���",
	"action":  "$N����$wˢ��һ�������ֿ���$n������Բ�����⣺"HIY"��ʯ�ػ���"NOR"��",
	"lvl" : 30
]),
([	"skill_name" : "̩ɽʮ����",
	"action":  "$Nչ�����ƣ����潣�ߣ����һ�գ��ұ�һ�䣬ԽתԽ�����͵�$w���Ⱪ����һ��"HIM"��̩ɽʮ���̡�"NOR"��$n$l��ȥ",
	"lvl" : 40
]),
([	"skill_name" :"�������",
	"action": "$N�ֱ۱���������$w���չ����ˢˢ������ָ��$n������"GRN"��������"NOR"",
	"lvl" : 50
]),
([	"skill_name" :  "�����䳤��",
	"action":  "$Nһ��"HIR"�������䳤�ա�"NOR"ͦ$w��$n���ش�ȥ��������˸��$w��������֮������ס��$n�ؿڡ����С�������ء��������桱������⡱�������ȡ��������š�����ͨ�ȡ��ߴ���Ѩ",
	"lvl" : 60
]),
([	"skill_name" :"����",
	"action":  "$N����$wٿ�ش̳���һ���彣��ÿһ���Ľ��нԲ�Ȼ�й��⡣�������ӣ��ڲ���䣬����"HIW"�����򽣡�"NOR"",
	"lvl" : 70
]),
});

int valid_enable(string usage) { return usage=="sword" || usage=="parry"; }
int valid_learn(object me)
{
	object ob;
	if( (int)me->query("max_neili") < 20 )
		return notify_fail("���������Ϊ������û�а취��̩ɽ������\n");
	if( (string)me->query_skill_mapped("force")!= "panshi-shengong")
		return notify_fail("̩ɽ�������������ʯ�񹦲�������\n");
	if( me->query_skill("panshi-shengong", 1) < 20)
		return notify_fail("�����ʯ����Ϊ������\n");
	if( me->query_skill("kuaihuo-strike", 1) < 20)
		return notify_fail("��Ŀ��ʮ������Ϊ������\n");

	if( me->query_skill("fengshenjue", 1) < 20)
		return notify_fail("��ķ����Ϊ������\n");

//	if( me->query("family/generation") > 12 &&
//		me->query_skill("taishan-sword",1) > 150)
//		return notify_fail("��Ҫ��ϰ���ߵ�̩ɽ�����������ʮ��������Ϊʦ��\n");
	if( !(ob = me->query_temp("weapon"))
		|| (string)ob->query("skill_type") != "sword" )
		return notify_fail("���������һ�ѽ�������������\n");
	return 1;
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if( (int)me->query("qi") < 40 ||(int)me->query("neili") < 30 )
		return notify_fail("�����������������û����ϰ̩ɽ������\n");
	me->receive_damage("qi", 35);
	me->add("neili", -20);
	return 1;
}
string query_skill_name(int level)
{
	int i;
	for(i = sizeof(action); i > 0; i--)
		if(level >= action[i-1]["lvl"])
			return action[i-1]["skill_name"];
}
mapping query_action(object me, object weapon)
{
/* d_e=dodge_effect p_e=parry_effect f_e=force_effect m_e=damage_effect */
	int d_e1 = 15;
	int d_e2 = 30;
	int p_e1 = 25;
	int p_e2 = 15;
	int f_e1 = 100;
	int f_e2 = 250;
	int m_e1 = 310;
	int m_e2 = 410;
	int i, lvl, seq, ttl = sizeof(action);

	if(me->query_temp("ruhe_count") > 15 || me->query_temp("ruhe_hit")){
        me->add("jing", -30);	
        me->add("neili", -100);	
	me->set_temp("ruhe_finish");	
	me->delete_temp("ruhe_count");	
	me->delete_temp("ruhe_hit");	
        return ([
	"action":HIY"$N���ּ����ѱϣ�$w"+HIY"���У�����̩ɽ�ɽ����������ľ��ա������Ρ�����һ����׼��$n��һ��Ӧ�����ţ�ʵ��������ٱ��������"NOR,
        "force" : 450+random(20),
        "dodge" : 70,
        "parry" : 70,
        "damage": 520,
	"post_action": (: ruhe :),	
        "damage_type":  "����"]);
        }
	else if((int)me->query_skill("sword",1)> random(300)+100
 	&& me->query("neili") > 200 
	&& me->query_temp("ruhe")){
        me->add("neili", -20);
        return ([
	"action":YEL"$N$w"+YEL"ٿ����$n�̳�������������ÿһ���Ľ��нԲ�Ȼ�й��⣬�������ӣ��ڲ���䣬���ǡ����򽣡�"NOR,
        "force" : 400+random(55),
        "dodge" : 10,
        "parry" : 15,
        "damage": 500+random(55),
        "skill_name" : "����",
	"post_action": (: ruhe :),	
        "damage_type":  "����"]);
        }

        else if((int)me->query_skill("sword",1) > random(280)+80
	&& me->query("neili") > 100
	&& me->query_temp("ruhe")){
        me->add("neili", -10);
        return ([
	"action":HIC"$N��Ȼ��$n����������$w"+HIC"ʹ������������ˮ�����������߼��ᳵ������·֮�⣬��������������з��ӵ����쾡��"NOR,
        "force" : 333 + random(33),
        "dodge" : 10,
        "parry" : 15,
        "damage": 500+random(33),
        "skill_name" : "�����",
	"post_action": (: ruhe :),	
        "damage_type":  "����"]);
        }

	lvl = (int) me->query_skill("taishan-sword", 1);
	for(i = ttl; i > 0; i--)
		if(lvl > action[i-1]["lvl"])
		{
			seq = i; /* �������������� */
			break;
		}
	seq = random(seq);       /* ѡ������������ */
	return ([
		"action"      : action[seq]["action"],
		"dodge"       : d_e1 + (d_e2 - d_e1) * seq / ttl,
		"parry"       : p_e1 + (p_e2 - p_e1) * seq / ttl,
		"force"       : f_e1 + (f_e2 - f_e1) * seq / ttl,
		"damage"      : m_e1 + (m_e2 - m_e1) * seq / ttl,
		"damage_type" : random(2) ? "����" : "����",
	]);
}
int learn_bonus() { return 20; }
int practice_bonus() { return 20; }
int success() { return 10; }
int power_point(object me) { return 1.0; }



int ruhe(object me, object victim, object weapon, int damage)
{
        string *msg;
        msg = ({
		CYN"����$N������ָ���㣬����׼��$n����Ų��λ���ּ�ͦ�����У�\n"NOR,
		CYN"����$n���书��·�ѱ�$N�������������ۼ��ѱܿ�$N��������"+weapon->name()+CYN"����ֱ�ƶ�����\n"NOR,
        });
if (!victim) return 0;
if (!me) return 0;
if (!weapon) return 0;
if (!damage) return 0;
        if(damage==RESULT_DODGE && (int)me->query_skill("sword",1) 
> random(150)+100 && me->query_temp("ruhe")) {
                message_vision(msg[random(sizeof(msg))], me,victim);
if (!victim) return 0;
if (!me) return 0;
victim->start_busy(2);
//if (victim=me) return 0;
if (victim && me
&& !me->query_temp("dsauto")
&& !me->is_busy())
{
victim->start_busy(2);
me->set_temp("dsauto",1);
        COMBAT_D->do_attack(me, victim, me->query_temp("weapon"));
        COMBAT_D->do_attack(me, victim, me->query_temp("weapon"));
me->delete_temp("dsauto");
}
                return 1;
	   }
}


int valid_effect(object me, object weapon, string name, int skill)
{
}

string perform_action_file(string action)
{
	return __DIR__"taishan-sword/" + action;
}
int help(object me)
{
	write(HIC"\n̩ɽ������"NOR"\n");
	write(@HELP

    ̩ɽ����Ϊ̩ɽ���Ž�����

	ѧϰҪ��
		̩ɽ�����书20��
		��ʯ��20��
		������Ϊ20
HELP
	);
	return 1;
}

