// hengshan-sword.c ��ɽ����
// Last Modified by sir 10.22.2001
// Modified by Java Sep.1998
//�ؽ��������

#include <ansi.h>
inherit SKILL;
#include <combat.h>

#include "/kungfu/skill/eff_msg.h";

int yunwu(object me, object victim, object weapon, int damage);
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([      "skill_name" :"��ɽ����",
	"action":  "$N����$w����ָ����ͻȻ���ڿ���һ������������֮�������ű�������������һ��"HIW"����ɽ����"NOR"����$w���Ⱪ������$n��$l��ȥ",
        "lvl" : 0
]),
([      "skill_name" :"�ٱ�ǧ��",
	"action":  "$Nһ��"HIC"���ٱ�ǧ�á�"NOR"����$w������ȣ���Ȼ���Ƶ���$n����$n��æת������ֻ������������",
	"lvl" : 10
]),
([      "skill_name":    "Ȫ��ܽ��",
	"action":  "$N�����Է�������·������$wˢ��һ��"MAG"��Ȫ��ܽ�ء�"NOR"����$nС����ȥ",
	"lvl" : 20
]),
([      "skill_name":    "�����ϸ�",
	"action":  "$N�����Է�������·������$wˢ��һ��"HIM"�������ϸǡ�"NOR"����$n��ͷ��ȥ",
	"lvl" : 30
]),
([      "skill_name":    "ʯ������",
	"action":  "$N����$wٿ�ش̳������ƴ����ػأ�������ã�����һ��" HIG"��ʯ��������"NOR"����$n$l��ȥ",
	"lvl" : 40
]),
([      "skill_name":    "��������",
	"action":  "$N����$wٿ�ش̳�����������֮���£������޶�������׽��������һ��"RED"������������"NOR"��ָ��$n$l",
	"lvl" : 50
]),
([      "skill_name":    "���ף��",
	"action" : "$N����Ծ��"HIR"�����ף�ڡ�"NOR"����$w����һ�������Ӱ��������$n��$l",
	"lvl" : 60
]),
});

int valid_enable(string usage) { return usage=="sword" || usage=="parry"; }
int valid_learn(object me)
{
	object ob;
	if( (int)me->query("max_neili") < 50 )
		return notify_fail("�������������û�а취����ɽ������\n");
	if( (string)me->query_skill_mapped("force")!= "huiyan-xinfa")
		return notify_fail("��ɽ����������ϻ����ķ���������\n");

	if ((int)me->query_skill("huiyan-xinfa", 1) < 20)
		return notify_fail("��Ļ����ķ����̫ǳ��\n");

	if ((int)me->query_skill("luoyan-hand", 1) < 50)
		return notify_fail("��Ĵ������ֻ��̫ǳ��\n");

	if ((int)me->query_skill("qiuyan-nanhui", 1) < 50)
		return notify_fail("��������ϻػ��̫ǳ��\n");

	if ((int)me->query_skill("biluo-zhang", 1) < 50)
		return notify_fail("��ı����ƻ��̫ǳ��\n");		

	if( !(ob = me->query_temp("weapon"))
		|| (string)ob->query("skill_type") != "sword" )
		return notify_fail("���������һ�ѽ�������������\n");

	return 1;
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if( (int)me->query("qi") < 40 || (int)me->query("neili") < 30 )
		return notify_fail("�����������������û�а취��ϰ��ɽ������\n");
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
	int d_e1 = 5;
	int d_e2 = 30;
	int p_e1 = 20;
	int p_e2 = 5;
	int f_e1 = 100;
	int f_e2 = 250;
	int m_e1 = 210;
	int m_e2 = 390;
	int i, lvl, seq, ttl = sizeof(action);
        int level;
        string *msg1,*msg2;
        msg1 = ({
		HIW"$N����$w"+HIW"�������裬��������������ʵʵ�����˶�Ŀ���仯�Ź�֮����$n�������º�Ȼ��"NOR,
		HIW"$N����$w"+HIW"ԽʹԽ�죬һ�ס��ٱ�ǧ�ú�ɽ����ʮ��ʽ�������ƾ���ӿ��$n���ɵ�ĿΪ֮ѣ��"NOR,
		HIW"����$N����$w"+HIW"���б�ã�������ȣ��廨���ţ�������$n������ǰ����һƬ���������ȥ��"NOR,
        });
        msg2 = ({
		HIR"����һ�����Ѫ��$w"+HIR"�½��˳�����$n��Ų��Ծ�������мܣ�ʼ���Ѳ���$N�Ľ������֣���Ѫ���������ܽ�����һ����Ȧ��$N���Ѵ̳�һ����"NOR,
		HIY"$Nһ����ռ�Ȼ����������������һ��$w"+HIY"�������ߣ�������������$n�Ĺ����д�����ȥ��ֻ�Ƶ�$n�������ˣ�"NOR,
		HIY"$n����һ������֮�£��������ˣ�$N����$w"+HIY"������������������������������䣬�仯�켫��"NOR,

        });
	if(me->query_temp("yunwu") && me->query_temp("yunwu_hit") ){
        me->add("neili", -20);
	me->delete_temp("yunwu_hit");
        return ([
        "action":msg2[random(sizeof(msg2))] ,
        "force" : 500,
        "dodge" : 5,
        "parry" : 20,
        "damage" : 500,
        "damage_type":"����"]);
        }
        else if (me->query_temp("yunwu") ){
        me->add("neili", -20);
        return ([
        "action":msg1[random(sizeof(msg1))] ,
        "force" : 580,
        "dodge" : 5,
        "parry" : 20,
        "damage" : 550,
	"post_action": (: yunwu :),	
        "damage_type":"����"]);
        }



	lvl = (int) me->query_skill("hengshan-sword", 1);
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

int yunwu(object me, object victim, object weapon, int damage)
{

if (!victim) return 0;
if (!me) return 0;

        if(damage==RESULT_DODGE || damage==RESULT_PARRY) return 1;

	   else if ( !living(victim) && victim->query_skill("force") > 100 ) {
                message_vision(HIR"\n����$n�˿���һ��Ѫ����ӿȪ�����������ԭ��$p�н�������δ��������Ѫ�Ƶô��˿��м���������ȹ��죬�ֿɲ���\n" NOR, me,victim);
		me->delete_temp("yunwu");
                return 1;
	   }
	else{
if (!victim) return 0;
if (!me) return 0;
if (me->is_busy() ) return 0;
//if (victim=me) return 0;
	me->add("neili", -30);
        victim->start_busy(2);
        victim->receive_damage("qi", random(30)+30);
	me->set_temp("yunwu_hit", 1);
	if(victim && me)
        {
        COMBAT_D->do_attack(me, victim, me->query_temp("weapon"));
}
	}
}

mixed hit_ob(object me, object victim,int damage_bonus)
        
{	
        int i, level;
        object target;
object weapon;
        level   = (int) me->query_skill("hengshan-sword",1);
//        target = me->select_opponent();
        weapon = me->query_temp("weapon");

	if( random(12)==1 || random(level) > 180)
	{
        if (userp(victim))
        victim->receive_wound("qi", (damage_bonus+level+100) );	
        return HIY "������ʮ��ʽ!!�����ⶸ����$N�͵ط�������$n��\n" NOR;
	}
if (damage_bonus < 60) damage_bonus=60;
	if( random(12)==1 || random(level) > 120)
	{

        victim->receive_wound("qi", damage_bonus );	
        return RED "$N���еĽ�ԽʹԽ�죬�������! һ����Ѫ��$n�����ϴ̳� ��\n" NOR;
  }
}
int learn_bonus() { return 20; }
int practice_bonus() { return 20; }
int success() { return 10; }
int power_point(object me) { return 1.0; }

int valid_effect(object me, object weapon, string name, int skill)
{
}

string perform_action_file(string action)
{
	return __DIR__"hengshan-sword/" + action;
}
int help(object me)
{
	write(HIC"\n��ɽ������"NOR"\n");
	write(@HELP

    ��ɽ����Ϊ��ɽ�书��

	ѧϰҪ��
		���Ż����书50
		�����ķ�50
		����50
HELP
	);
	return 1;
}

