// hengshan-jian.c ��ɽ����
/// Last Modified by sir on 5/17/2001

#include <ansi.h>
inherit SKILL;

#include <combat.h>

#include "/kungfu/skill/eff_msg.h";
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action":"$N������У�һʽ"HIG"������ӭ�͡�"NOR"��$w����ɶ�������һƬ���⣬Χ��$nȫ��",
	"lvl" : 0,
	"skill_name" : "����ӭ��"
]),
([	"action":"$Nʹһ��"HIR"�����Ƽ��ա�"NOR"����������Ʈ������$w����ʵʵ�ó���㺮������$n$l",
	"lvl" : 20,
	"skill_name" : "���Ƽ���"
]),
([	"action":"$N����һת����Ȼһʽ"HIY"�������ɽ��"NOR"��������콣Ӱ��Ю�ž�����$n��$lɨȥ",
	"lvl" : 40,
	"skill_name" : "�����ɽ"
]),
([	"action":"$N���쳤Ц������ƮȻ�����ڰ��������һ����һʽ"HIB"�����Ʊ�
�¡�"NOR"����ػ���$n",
	"lvl" : 50,
	"skill_name" : "���Ʊ���"
]),
([	"action":"$N�������Ž���������̤��һ��"HIC"���ǻ����ա�"NOR"����б�̣�������ȻԾ��ٿ�Ļ��������ǹ�����$n��$l",
	"lvl" : 80,
	"skill_name" : "�ǻ�����"
]),
([	"action":"$N��ǰ��ȥһ�󲽣�ʹ��"HIW"��֯Ů����"NOR"������$w���һ������Ѹ�����׻���$n��$l",
	"lvl" : 100,
	"skill_name" : "֯Ů����"
]),
([	"action":"$N����һ��$w��һʱ"MAG"��ƮȻ������"NOR"��$w�ó���㽣����ƮȻ����$n��$l",
	"lvl" : 110,
	"skill_name" : "ƮȻ����"
]),
([	"action":"$N���һ����һ��"GRN"������ͨ�ġ�"NOR"��$w����㻮��һ����Բ������$n��$l",
	"lvl" : 130,
	"skill_name" : "����ͨ��"
]),
([	"action":"$N��������Ʈ��ͻȻһת��ͷ�½��ϣ�����$w��һ��"HIM"����ϼ
������"NOR"��������Ϣ�ع���$n��$l",
	"lvl" : 150,
	"skill_name" : "��ϼ����"
]),
([	"action":"$N����$wһ����һ��"BLU"�����ո��֡�"NOR"��$w�Ƴ�ҫ�۹�â����������$n��$l",
	"lvl" : 160,
	"skill_name" : "���ո���"
]),
([	"action":"$N��Ȼ���θ߸�Ծ��ʹ��"RED"������Ǭ����"NOR"��$w�ó����컨�꣬Ѹ����������$n��$l",
	"lvl" : 180,
	"skill_name" : "����Ǭ��"
])
});

int valid_enable(string usage) { return (usage=="sword") || (usage=="parry") ; }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100)
		return notify_fail(HIC"�������������\n"NOR);

	if ((int)me->query_skill("chuanyun-shou", 1) < 50)
		return notify_fail(HIC"��Ĵ��Ʋ�����\n"NOR);

	if ((int)me->query_skill("tianchang-zhang", 1) < 50)
		return notify_fail(HIC"����쳤�Ʋ�����\n"NOR);
	if ((int)me->query_skill("lingxu-bu", 1) < 50)
		return notify_fail(HIC"������鲽������\n"NOR);

	if( (string)me->query_skill_mapped("force")!= "baiyun-xinfa")
		return notify_fail("��ɽ����������ϰ����ķ���������\n");
	if ((string)me->query("gender") != "Ů��" )
		return notify_fail(HIY"��������Ľ���ֻ��Ů�Ӳ��ʺ�ѧ��\n"NOR);
	return 1;
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if( (int)me->query("qi") < 40 || (int)me->query("neili") < 30 )
		return notify_fail("�������������������ɽ������\n");
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
	int d_e1 = 20;
	int d_e2 = 50;
	int p_e1 = 20;
	int p_e2 = 0;
	int f_e1 = 200;
	int f_e2 = 250;
	int m_e1 = 120;
	int m_e2 = 380;
	int i, lvl, level,seq, ttl = sizeof(action);
        level   = (int) me->query_skill("hengshan-jian",1);
	if(me->query_temp("hengshan") 
	&& random(level) > 160 ){
        me->add("neili", -20);
        return ([
        "action":HIG"$N�ζ�$w��̤���ţ���ƫ�棬������˼����������ޱȣ�����ʵ�ң��ѵ���$n$l"NOR,
        "force" : 700,
        "dodge" : 35,
        "parry" : 20,
        "damage" : 700,
        "damage_type":"����"]);
        }
        else if (me->query_temp("hengshan") 
        && random(level) > 100 ){
        me->add("neili", -20);
        return ([
        "action" : HIW"$N��������������б������â�Ӱ����ֱк��������$n��$lն��"NOR,
        "force" : 680,
        "dodge" : 35,
        "parry" : 20,
        "damage" : 750,
        "damage_type":"����"]);
        }

	lvl = (int) me->query_skill("hengshan-jian", 1);
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


mixed hit_ob(object me, object victim,int damage_bonus)
        
{	
        int i, level;
        object target;
object weapon;
        level   = (int) me->query_skill("hengshan-jian",1);
//        target = me->select_opponent();
        weapon = me->query_temp("weapon");

if (damage_bonus < 30) damage_bonus=30;
	if( random(12)==1 || random(level) > 130)
	{

        victim->receive_wound("qi", damage_bonus );	
        return HIM "��Ӱ��������һ����Ѫ��$n���������!\n" NOR;
  }
}

int ob_hit(object ob, object me, int damage)
{
	object weapon = me->query_temp("weapon");
        string msg,dodge_skill,*limbs;
        int i, j, level, p, q;
        
        limbs = ob->query("limbs");
        level = me->query_skill("baiyun-xinfa", 1);

        
            if ( random(8) == 0 || random(level) > 180){
          ob->start_busy(2);
         msg = HIG"$N��������ķ����³�һ����Ѫ!!��\n"NOR;
         msg += GRN"$N���˺ö���!!��\n"NOR;
if ((int)me->query("qi")<=(int)me->query("qi")*2)
{
             me->add("qi",(level+100));
             me->add("eff_qi",(level+100));
}
msg += damage_msg(damage, "����");
message_vision(msg, me, ob);
}

            return damage;
}

string perform_action_file(string action)
{
	return __DIR__"hengshan-jian/" + action;
}

int help(object me)
{
	write(HIC"\n��ɽ������"NOR"\n");
	write(@HELP

    ��ɽ����Ϊ��ɽ�书��

	ѧϰҪ��
		���Ż����书 50
		��߰����ķ���Ů��
		����100
HELP
	);
	return 1;
}

