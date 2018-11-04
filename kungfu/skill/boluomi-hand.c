// Last Modified by Winder on May. 29 2001
// boluomi-hand.c �������� �ͼ���צ���� ���Է���֮�����ȡ���

#include <ansi.h>
inherit SKILL;
#include <combat.h>

#include "/kungfu/skill/eff_msg.h";
string type() { return "martial"; }
string martialtype() { return "skill"; }
 
mapping *action = ({
([	"action":"$N˫�ֺ�ʮ���ϣ���һʽ"BLU"����ʩʽ��"NOR"������ھ��ѱƵ��´����ɣ���$n�������",
	"lvl"   : 0,
	"skill_name" : "��ʩʽ"
]),
([	"action":"$N����������Ϸ���ѹ�������������$n��ǰ������ã����н���"RED"���ֽ�ʽ��"NOR"�����Ǳ仯����",
	"lvl"   : 10,
	"skill_name" : "�ֽ�ʽ"
]),
([	"action":"$N��ͷ���磬ʹ"YEL"������ʽ��"NOR"���У�����ǰ$n���Ų��ʣ�������ȴ����˫�֣��Ż��ĳ�",
	"lvl"   : 20,
	"skill_name" : "����ʽ"
]),
([	"action":"$N�������ˣ�һ��"GRN"������ʽ��"NOR"��˫�ۻζ������ƬƬ��Ӱ��һ������$n���ƹ�ȥ",
	"lvl"   : 40,
	"skill_name" : "����ʽ"
]),
([	"action":"$Nһʽ"HIY"������ʽ��"NOR"�������������������ƽ����ˮ��һ�������$n����ѹ������",
	"lvl"   : 80,
	"skill_name" : "����ʽ"
]),
([	"action":"$N˫�ۻӶ����ó�һ��������ӡ����"MAG"������ʽ��"NOR"��$n����������������ȴ�������쳣",
	"lvl"   : 100,
	"skill_name" : "����ʽ"
]),
});
int valid_enable(string usage) { return usage=="hand" || usage=="parry"  || usage=="unarmed";}
int valid_combine(string combo){ return combo=="jingang-strike"; }
 
int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("���������ֱ�����֡�\n");
	if ((int)me->query_skill("zhanzhuang-gong", 1) < 40)
		 return notify_fail("���վ׮����򲻹����޷�ѧ�������֡�\n");
	if ((me->query_skill("shaolin-leg", 1) < 50) ||
		(me->query_skill("shaolin-cuff", 1) < 50))
		return notify_fail("������ֵ��Ⱥ�������ȭ��򲻹���\n");

	if ((me->query_skill("yiwei-dujiang", 1) < 50))
		return notify_fail("���һέ�ɽ���򲻹���\n");

	if ((int)me->query("max_neili") < 400)
		return notify_fail("�������̫�����޷����������֡�\n");
	if ((me->query_skill("qianye-shou", 1) < 40) ||
		me->query_skill("sanhua-zhang", 1) < 40)
		return notify_fail("���ǧҶ�ֺ�ɢ���ƻ�򲻹����޷�ѧ�������֡�\n");
	return 1;
}
 
int practice_skill(object me)
{
	if ((int)me->query("qi") < 50)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 50)
		return notify_fail("��������������������֡�\n");
	me->receive_damage("qi", 40);
	me->add("neili", -30);
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

	lvl = (int) me->query_skill("boluomi-hand", 1);
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
	return __DIR__"boluomi-hand/" + action;
}

int help(object me)
{
	write(HIC"\n�������֣�"NOR"\n");
	write(@HELP

    �����������������ַ����ʹ����ƻ�����
    ���Է���֮�����ȡ���

	ѧϰҪ��
		վ׮��40��
		ɢ����40��
		����ǧҶ��40��
		������Ϊ400
HELP
	);
	return 1;
}



mixed hit_ob(object me, object victim,int damage_bonus)
        
{	
        int i, level;
        object target;
object weapon;
        level   = (int) me->query_skill("boluomi-hand",1);
//        target = me->select_opponent();
        weapon = me->query_temp("weapon");

	if( random(12)==1 || random(level) > 150)
	{
        if (userp(victim))
        victim->start_busy(3);
        return HIC "������ʽ!!����$NͻȻ���һƬ��Ӱ!! $n��֪����!!\n" NOR;
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
        level = me->query_skill("boluomi-hand", 1);

        if( damage < 10 ) return 1;

            if ( random(12) == 0 || random(level) > 150){
         msg = RED"$N���$n�Ĺ��ơ�ͻȻ���һƬ��Ӱ!!��\n"NOR;
         msg += YEL"������ʽ!����$N�ַ�һ�䣬$n��֪����!!��\n"NOR;
             ob->start_busy(3);

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
