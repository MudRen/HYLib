// Last Modified by winder on May. 29 2001
// wuxiang-finger.c �����ָ ���ܻ���
// ȡ�Է�ʮ���֡�����ǻۣ����磬�Ժ���ӱ��Բ������

#include <ansi.h>
inherit SKILL;
#include <combat.h>

#include "/kungfu/skill/eff_msg.h";
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N��˫��£������֮�У�һ��"HIW"���������١�"NOR"����������������ӿ��������$n",
	"lvl"   : 0,
	"skill_name" : "��������" 
]),
([	"action" : "$N΢΢һЦ��һ��"HIW"���ǻ�����١�"NOR"���������ڣ�ָ�����������������ĥ��͸���޷����",
	"lvl"   : 10,
	"skill_name" : "�ǻ������" 
]),
([	"action" : "$N����վ����˿������������$n��ǰ���һ�������������������"HIW"����������١�"NOR"",
	"lvl"   : 30,
	"skill_name" : "���������" 
]),
([	"action" : "$Ņͷ���죬һָ"HIW"���Ժ�����١�"NOR"��Ϯ$n$l������ȴ��˿���������������·���һ��",
	"lvl"   : 60,
	"skill_name" : "�Ժ������" 
]),
([	"action" : "$Nһ��"HIW"��ӱ������١�"NOR"��$n������ŵ�һ�ƿ�֮����ȴ��$P΢Ц��ͷ��ȴ�����κζ���",
	"lvl"   : 100,
	"skill_name" : "ӱ�������" 
]),
([	"action" : "��������������$n��ɫͻ�䣬$Nȴ�������ڣ����޶����ֵļ��������������"HIW"��Բ������١�"NOR"",
	"lvl"   : 150,
	"skill_name" : "Բ�������" 
]),
});

int valid_enable(string usage) { return usage=="finger" || usage=="parry" || usage=="unarmed"; }
int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("�������ָ������֡�\n");
	if ((int)me->query_skill("zhanzhuang-gong", 1) < 170)
		return notify_fail("���վ׮����򲻹����޷�ѧ�����ָ��\n");
	if ((int)me->query("max_neili") < 2500)
		return notify_fail("�������̫�����޷��������ָ��\n");
	if (me->query_skill("yizhi-chan", 1) < 50)
		return notify_fail("���һָ����򲻹����޷�ѧ�����ָ��\n");
	if ((me->query_skill("shaolin-leg", 1) < 50) ||
		(me->query_skill("shaolin-cuff", 1) < 50))
		return notify_fail("������ֵ��Ⱥ�������ȭ��򲻹���\n");
	if ((me->query_skill("yiwei-dujiang", 1) < 50))
		return notify_fail("���һέ�ɽ���򲻹���\n");
	return 1;
}
int practice_skill(object me)
{
	if ((int)me->query("qi") < 55)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 30)
		return notify_fail("������������������ָ��\n");
	me->receive_damage("qi", 50);
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
	int d_e2 = 80;
	int p_e1 = 145;
	int p_e2 = 125;
	int f_e1 = 550;
	int f_e2 = 850;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("wuxiang-finger", 1);
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
int learn_bonus() { return 0; }
int practice_bonus() { return 0; }
int success() { return 5; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"wuxiang-finger/" + action;
}

int help(object me)
{
	write(HIC"\n�����ָ��"NOR"\n");
	write(@HELP

    �����ָ�������ָ߼�ָ�������ܻ�����ȡ�Է�ʮ���֡�����ǻۣ�
���磬�Ժ���ӱ��Բ������

	ѧϰҪ��
		վ׮��170��
		һָ��50��
		������Ϊ2500
HELP
	);
	return 1;
}

mixed hit_ob(object me, object victim,int damage_bonus)
        
{	
        int i, level;
        object target;
object weapon;
        level   = (int) me->query_skill("ruying-leg",1);
//        target = me->select_opponent();
        weapon = me->query_temp("weapon");

	if( random(12)==1 || random(level) > 150)
	{
        if (userp(victim))
        victim->receive_wound("qi", (damage_bonus+level+100) );	
        return HIB "�������ָ!!����$NͻȻ����$n������Ѩ!! $n�³�һ����Ѫ!!!\n" NOR;
	}
if (damage_bonus < 60) damage_bonus=60;
	if( random(12)==1 || random(level) > 50)
	{

        victim->receive_wound("qi", damage_bonus );	
        return HIM "��!!�����ָ��һ����Ѫ��$n���������!\n" NOR;
  }
}

int ob_hit(object ob, object me, int damage)
{
	object weapon = me->query_temp("weapon");
        string msg,dodge_skill,*limbs;
        int i, j, level, p, q;
        
        limbs = ob->query("limbs");
        level = me->query_skill("ruying-leg", 1);

        if( damage < 10 ) return 1;
//          ob->start_busy(2);
            if ( random(12) == 0 || random(level) > 150){
         msg = RED"$N���$n�Ĺ��ơ�ͻȻ����������ε������ָ!!!��\n"NOR;
         msg += RED"$n�е�ȫ��һ������Ȼ���ܶ���!!��\n"NOR;
ob->start_busy(3);

msg += damage_msg(damage, "����");
message_vision(msg, me, ob);
}

            return damage;
}
