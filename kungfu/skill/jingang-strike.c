// Last Modified by Winder on May. 29 2001
// jingang-strike.c �������� �Ͷ���Ҷָ���� ȡ�ԡ������˲����ȡ�

#include <ansi.h>
inherit SKILL;
#include <combat.h>

#include "/kungfu/skill/eff_msg.h";
string type() { return "martial"; }
string martialtype() { return "skill"; }
 
mapping *action = ({
([	"action" : "$N��Ȼ΢Ц��һʽ"HIY"����������"NOR"��˫�ֺ�ʮ��ǰ΢΢һ�ݣ�һ�ɰ������ƶ���������$n��$l",
	 "lvl"   : 0,
	 "skill_name" : "������"
]),
([	"action" : "$N��ɫ������һʽ"HIY"�����𴫷���"NOR"������$n��������ֵ�ȭ����ǰһ�������ֳ���ֱ��$n�ĺ���",
	 "lvl"   : 10,
	 "skill_name" : "���𴫷�"
]),
([	"action" : "$Nһ����Ц��һʽ"HIY"����ڤ�ѻ꡹"NOR"˫ȭ���ٽ������ʮ���ƣ��ƴ������������죬��$n��ס���ˣ�ƣ���м�",
	 "lvl"   : 20,
	 "skill_name" : "��ڤ�ѻ�"
]),
([	"action" : "$N���װ������У�һʽ"HIY"������������"NOR"��˫����꣬һǰһ��Ю��һ����������$n",
	 "lvl"   : 30,
	 "skill_name" : "��������"
]),
([	"action" : "$Nһʽ"HIY"����ɢ��ħ��"NOR"����ü��Ŀ֮�䣬ͻȻ˫��ֱ��ֱ�£������·��������ħһ�㹥��$n����ǰ���",
	 "lvl"   : 40,
	 "skill_name" : "��ɢ��ħ"
]),
([	"action" : "$Nһʽ"HIY"�����෨�ࡹ"NOR"��������Σ�����һ�䣬�ѻ�����ʮ����Ӱ������ӡ��$n��ȫ�����ҪѨ",
	 "lvl"   : 60,
	 "skill_name" : "���෨��"
]),
([	"action" : "$N����Ծ�𣬰���г��־޴���Ӱ��ͻȻһʽ"HIY"���������ơ�"NOR"��ͷ�½��ϣ���ת�Ÿ���������˫�ƶ�ס$n",
	 "lvl"   : 80,
	 "skill_name" : "��������"
]),
([	"action" : "$Nׯ����������������һ������ȫ���·�΢΢���𣬵ͺ�һ����һʽ"HIY"�����ȼ��֡�"NOR"���������ȶ���������$n��ǰ��",
	 "lvl"   : 100,
	 "skill_name" : "���ȼ���"
])
});

int valid_enable(string usage) { return usage=="strike" || usage=="parry"  || usage=="unarmed"; }
int valid_combine(string combo){ return combo=="boluomi-hand"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("���������Ʊ�����֡�\n");
	if ((int)me->query_skill("zhanzhuang-gong", 1) < 50)
		return notify_fail("���վ׮����򲻹����޷�ѧ�������ơ�\n");
	if ((int)me->query("max_neili") < 500)
		return notify_fail("�������̫�����޷����������ơ�\n");
	if ((me->query_skill("shaolin-leg", 1) < 50) ||
		(me->query_skill("shaolin-cuff", 1) < 50))
		return notify_fail("������ֵ��Ⱥ�������ȭ��򲻹���\n");
	if ((me->query_skill("yiwei-dujiang", 1) < 50))
		return notify_fail("���һέ�ɽ���򲻹���\n");

	if ((me->query_skill("boluomi-hand", 1) < 50) ||
		(me->query_skill("sanhua-zhang", 1) < 50))
		return notify_fail("��Ĳ������ֺ�ɢ���ƻ�򲻹���\n");
	return 1;
}
int practice_skill(object me)
{
	 if ((int)me->query("qi") < 50)
		 return notify_fail("�������̫���ˡ�\n");
	 if ((int)me->query("neili") < 20)
		 return notify_fail("��������������������ơ�\n");
	 me->receive_damage("qi", 45);
	 me->add("neili", -25);
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
	int d_e2 = 25;
	int p_e1 = 20;
	int p_e2 = 65;
	int f_e1 = 510;
	int f_e2 = 610;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("jingang-strike", 1);
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
		"damage_type" : random(2) ? "����" : "����",
	]);
}
int learn_bonus() { return 5; }
int practice_bonus() { return 5; }
int success() { return 10; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	 return __DIR__"jingang-strike/" + action;
}

int help(object me)
{
	write(HIC"\n�������ƣ�"NOR"\n");
	write(@HELP

    �����������������Ʒ����Ͳ�������ָ������

	ѧϰҪ��
		վ׮��50��
		ɢ����50��
		����ǧҶ��50��
		������Ϊ500
HELP
	);
	return 1;
}


mixed hit_ob(object me, object victim,int damage_bonus)
        
{	
        int i, level;
        object target;
object weapon;
        level   = (int) me->query_skill("jingang-strike",1);
//        target = me->select_opponent();
        weapon = me->query_temp("weapon");

	if( random(12)==1 || random(level) > 150)
	{
        if (userp(victim))
        victim->receive_wound("qi", (damage_bonus+level+100) );	
        return HIC "�����ȼ���!!����$NͻȻ���һ�Ǵ�����!! $n�³�һ����Ѫ!!!\n" NOR;
	}
if (damage_bonus < 60) damage_bonus=60;
	if( random(12)==1 || random(level) > 50)
	{

        victim->receive_wound("qi", damage_bonus );	
        return HIM "��!!һ����Ӱ������һ����Ѫ��$n���������!\n" NOR;
  }
}

int ob_hit(object ob, object me, int damage)
{
	object weapon = me->query_temp("weapon");
        string msg,dodge_skill,*limbs;
        int i, j, level, p, q;
        
        limbs = ob->query("limbs");
        level = me->query_skill("jingang-strike", 1);

        if( damage < 10 ) return 1;

            if ( random(12) == 0 || random(level) > 150){
         msg = RED"$N���$n�Ĺ��ơ�ͻȻȫ�����һ��!!��\n"NOR;
         msg += RED"����������!����$Nȫ�����һ�ƣ�$n�³�һ����Ѫ!!��\n"NOR;
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
