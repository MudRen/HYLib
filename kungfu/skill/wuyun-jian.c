// wuyun-jian.c �������ҽ�
// Last Modified by winder on Mar. 10 2000
#include <ansi.h>
inherit SKILL;
#include <combat.h>

#include "/kungfu/skill/eff_msg.h";

string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N��Сָ�ᵯ��һ��"HIM"�����ϡ�"NOR"��Ȼ����$n�ĺ���",
	"lvl" : 0,
	"skill_name" : "����"
]),
([	"action" : "$N��������ָ�������޵�һ���������Ҳ���һ����"HIR"[����]"NOR"�ѽ�$n����",
	"lvl" : 10,
	"skill_name" : "����"
]),
([	"action" : "$N��ָ���ӣ�һʽ"HIB"[����]"NOR"���εĴ���$n������",
	"lvl" : 20,
	"skill_name" : "����"
]),
([	"action" : "$N�����н���ɨ��ͬʱ�������������Ƶļ���������һ��"HIG"[֧��]"NOR"",
	"lvl" : 30,
	"skill_name" : "֧��"
]),
([	"action" : "$Nʹ��"HIW"�����ϡ�"NOR"�������������ߣ���ͬ��������������������$n��$l",
	"lvl" : 40,
	"skill_name" : "����"
]),
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }
int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������������\n");
	if ((int)me->query_skill("wuzheng-xinfa", 1) < 90)
		return notify_fail("��������ķ���򲻹���\n");


	if ((int)me->query_skill("pomopima-jian", 1) < 90)
		return notify_fail("�����ī���齣��򲻹���\n");

	if ((int)me->query_skill("piaoyibu", 1) < 90)
		return notify_fail("���Ʈ�ݲ�����򲻹���\n");

	if ((int)me->query_skill("jiangjun-zhang ", 1) < 90)
		return notify_fail("����Ὣ��ʫ�ȷ���򲻹���\n");

	if ((int)me->query_skill("xuantian-zhi", 1) < 90)
		return notify_fail("�����������ָ��򲻹���\n");

	if ((int)me->query_skill("shigu-bifa", 1) < 90)
		return notify_fail("���ʯ�Ĵ�Ѩ�ʷ���򲻹���\n");









	return 1;
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if( (int)me->query("jing") < 35 || (int)me->query("neili") < 15 )
		return notify_fail("��ľ��������������������ҽ���\n");
	me->receive_damage("jing", 20);
	me->add("neili", -15);
	return 1;
}

int ob_hit(object ob, object me, int damage)
{
	object weapon = me->query_temp("weapon");
        string msg,dodge_skill,*limbs;
        int i, j, level, p, q;
        
        limbs = ob->query("limbs");
        level = me->query_skill("wuyun-jian", 1);

        if( damage < 10 ) return 1;
          
            if ( random(12) == 0 || random(level) > 180){
         ob->start_busy(2);
         msg = RED"$N���$n�Ĺ��ơ�ͻȻ��Хһ�� !!\n"NOR;
         msg += RED"������������!!����$n����һ�� �³�һ����Ѫ!!��\n"NOR;
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
	int d_e1 = 20;
	int d_e2 = 40;
	int p_e1 = 10;
	int p_e2 = 10;
	int f_e1 = 100;
	int f_e2 = 250;
	int m_e1 = 370;
	int m_e2 = 370;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("wuyun-jian", 1);
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
int learn_bonus() { return 25; }
int practice_bonus() { return 25; }
int success() { return 15; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"wuyun-jian/" + action;
}

int help(object me)
{
	write(HIC"\n�������ҽ���"NOR"\n");
	write(@HELP

    ������̺�ľ���书��÷ׯ��ׯ�����ӹ��Ķ��Ž�����������
���뽣��֮�У��������ŵ����񣬴Ӷ����ƶԷ���Ϣ�ı仯��

	ѧϰҪ��
		�����ķ�90����÷ׯ�����书90��
		����100
HELP
	);
	return 1;
}

