// sonfeng-jian.c �ɷ罣��
// Last Modified by sir 10.22.2001

#include <ansi.h>
inherit SKILL;
#include <combat.h>

#include "/kungfu/skill/eff_msg.h";

string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N�鲽������һ��"MAG"���ʵ�������"NOR"������$w���������һ��������$n��$l",
	"lvl" : 0,
	"skill_name" : "�ʵ�����"
]),
([	"action" : "$N��ǰ����һ�������ֽ���������$wʹ��һʽ"HIM"����˶��ѡ�"NOR"ֱ��$n��$l",
	"lvl" : 10,
	"skill_name" : "��˶���"
]),
([	"action" : "$N��������һ�죬���ֽ���������$wʹ��һʽ"GRN"���ֻ�������"NOR"����$n��$l",
	"lvl" : 20,
	"skill_name" : "�ֻ�����"
]),
([	"action" : "$N˫ϥ�³�������$wʹ��һʽ"RED"�������蹵��"NOR"�����¶��ϼ���$n��$l",
	"lvl" : 50,
	"skill_name" : "�����蹵"
]),
([	"action" : "$Nһ��"HIB"���ߵ�������"NOR"��$w���϶��»���һ���󻡣�ƽƽ����$n��$l��ȥ",
	"lvl" : 60,
	"skill_name" : "�ߵ�����"
]),
([	"action" : "$N���������һš��һ��"HIW"����ŮͶ��"NOR"������$w������$n��$l��ȥ",
	"lvl" : 80,
	"skill_name" : "��ŮͶ��"
]),
([	"action" : "$Nһ��"BLU"���˷����꡹"NOR"������ƽָ��һ���ǳɺ�ɨ$n��$l",
	"lvl" : 100,
	"skill_name" : "�˷�����"
]),
([	"action" : "$N������ϥ������$wбָ��һ��"HIY"��ƽɳ���㡹"NOR"����$n��$l",
	"lvl" : 120,
	"skill_name" : "ƽɳ����"
]),
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }
int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 10)
		return notify_fail("�������������\n");
	if ((int)me->query_skill("qingming-xuangong", 1) < 20)
		return notify_fail("�����ڤ�������̫ǳ��\n");

	if ((int)me->query_skill("chuanhua", 1) < 50)
		return notify_fail("��Ĵ����������̫ǳ��\n");

	if ((int)me->query_skill("wuying-leg", 1) < 50)
		return notify_fail("�����Ӱ�Ȼ��̫ǳ��\n");

	if ((int)me->query_skill("cuixin-strike", 1) < 50)
		return notify_fail("��Ĵ����ƻ��̫ǳ��\n");		
		
	return 1;
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if( (int)me->query("qi") < 40 || (int)me->query("neili") < 30 )
		return notify_fail("������������������ɷ罣����\n");
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
	int d_e1 = 10;
	int d_e2 = 35;
	int p_e1 = 20;
	int p_e2 = 0;
	int f_e1 = 100;
	int f_e2 = 150;
	int m_e1 = 200;
	int m_e2 = 390;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("songfeng-jian", 1);
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
int success() { return 15; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"songfeng-jian/" + action;

}
int help(object me)
{
	write(HIC"\n�ɷ罣����"NOR"\n");
	write(@HELP

    �ɷ罣��������ɽ�����

	ѧϰҪ��
		��ǻ����书50��
		��ڤ��20��
		����10
HELP
	);
	return 1;
}


mixed hit_ob(object me, object victim,int damage_bonus)
        
{	
        int i, level;
        object target;
object weapon;
        level   = (int) me->query_skill("songfeng-jian",1);
//        target = me->select_opponent();
        weapon = me->query_temp("weapon");

	if( random(12)==1 || random(level) > 180)
	{
        if (userp(victim))
        victim->receive_wound("qi", (damage_bonus+level+100) );	
        //victim->start_busy(3);
        return HIC "�����ľ�!!��$N�͵�һ������һ����ת��$n���������$n����ӡ����ȥ��\n" NOR;
	}
if (damage_bonus < 60) damage_bonus=60;
	if( random(12)==1 || random(level) > 180)
	{

        victim->receive_wound("qi", damage_bonus );	
        return HIM "���ľ�!! $n����һ��ֻ���ú�ͷһ��һ��Ѫ˿����ǹ���������\n" NOR;
  }
}

int ob_hit(object ob, object me, int damage)
{
	object weapon = me->query_temp("weapon");
        string msg,dodge_skill,*limbs;
        int i, j, level, p, q;
        
        limbs = ob->query("limbs");
        level = me->query_skill("songfeng-jian", 1);

        if( damage < 10 ) return 1;
          ob->start_busy(2);
            if ( random(12) == 0 || random(level) > 180){
         msg = RED"$N�����㷴�߶���ֱ��$n������������$n�˿�վ�ȣ������������ߣ���$n�ߵ�һʱ�޷����֣�\n"NOR;
         msg += RED"��������!!����$N��Ӱ���ε��߳����ţ�$n�³�һ����Ѫ!!��\n"NOR;
             ob->add("qi",-(level+100));
             ob->add("eff_qi",-(level+100));

        if (userp(ob) && ob->query("qi") > 50
        && ob->query("eff_qi") > 50)
{
if (ob->query("qi")/12 > 20)
             ob->add("qi",-ob->query("qi")/12);
if (ob->query("eff_qi")/12 > 20)
             ob->add("eff_qi",-ob->query("eff_qi")/12);
}

msg += damage_msg(damage, "����");
message_vision(msg, me, ob);
}

            return damage;
}
