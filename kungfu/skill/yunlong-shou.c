// yunlongshou.c -������
#include <ansi.h>
inherit SKILL;
string *xue_name = ({ 
"�͹�Ѩ","����Ѩ","����Ѩ","��ԪѨ","����Ѩ","�м�Ѩ","�н�Ѩ","��ͻѨ","�ٻ�Ѩ",
"����Ѩ","����Ѩ","���Ѩ","�Ϲ�Ѩ","��ԨѨ","�쾮Ѩ","��ȪѨ","����Ѩ","����Ѩ",}); 

mapping *action = ({
([	"action" : "$Nһʽ����ľ�Ա�����ʮָ����������ʵʵ��Ϯ��$n��ȫ��ҪѨ",
	"force" : 200,
        "dodge" : 30,
	"damage": 125,
	"lvl" : 0,
	"skill_name" : "��ľ�Ա�",
        "damage_type" : "ץ��"
]),
([	"action" : "�ں��������У�$Nʹһ�С�����׽Ӱ����˫���繳��ꫣ�����$n��$l",
	"force" : 250,
	"dodge" : 35,
	"damage": 140,
	"lvl"   : 20,
	"skill_name" : "����׽Ӱ" ,		
	"damage_type" : "����"
]),
([	"action" : "$N˫ȭ���裬һʽ������ȥ���������ֻ��ۣ�£��Ȧ״���ͻ�$n�����",
	"force" : 250,
        "dodge" : 30,
	"damage": 165,
	"lvl" : 30,
	"skill_name" : "����ȥ��",
        "damage_type" : "����"
]),
([	"action" : "$N˫��ƽ�죬ʮָ΢΢���¶�����һ�С�ʮָǬ��������$n��$l",
	"force" : 300,
	"dodge" : 35,
	"damage": 180,
	"lvl"   : 40,
	"skill_name" : "ʮָǬ��" ,		
	"damage_type" : "����"
]),
([	"action" : "$N���ֻ��أ�Ҹ�º��գ�������ָ�繳��һ�С�������ȱ������$n�Ķ���",
	"force" : 260,
	"dodge" : 40,
	"damage": 100,
	"lvl"   : 50,
	"skill_name" : "������ȱ" ,		
	"damage_type" : "����"
]),
([	"action" : "$N����б��$n����֮�䣬һ�С��������项������ȡĿ�����ַ���$n���ɲ�",
	"force" : 300,
	"dodge" : 35,
	"damage": 120,
	"lvl"   : 60,
	"skill_name" : "��������" ,		
	"damage_type" : "����"
]),
([	"action" : "$Nһ����ָ$n�Ľ�����һ�С��������С�������ץ��$n���еı���",
	"force" : 350,
	"dodge" : 35,
	"damage": 140,
	"lvl"   : 70,
	"skill_name" : "��������" ,		
	"damage_type" : "ץ��"
]),
([	"action" : "$N����ָ��$n��ǰ�������Ѩ������бָ̫��Ѩ��һ�С�����������ʹ$n��������",
	"force" : 400,
	"dodge" : 40,
	"damage": 160,
	"lvl"   : 80,
	"skill_name" : "��������" ,		
	"damage_type" : "����"
]),
([	"action" : "$Nһ�ֶ����צ��һ��ָ�أ�һ�С����Ƽ��ա�,��������$n��ȫ��",
	"force" : 420,
	"dodge" : 50,
	"damage": 180,
	"lvl"   : 90,
	"skill_name" : "���Ƽ���" ,		
	"damage_type" : "����"
]),
([	"action" : "$Nһʽ���������¡���ȭ���������֣��������ޣ�����������$n�ĵ���",
	"force" : 460,
        "dodge" : 60,
	"damage": 200,
	"lvl" : 100,
	"skill_name" : "��������",
        "damage_type" : "����"
]),
([	"action" : "$N���������ʹһʽ���������ɡ�������΢��,��������$n��$l",
	"force" : 490,
        "dodge" : 60,
        "parry" : 60,
	"damage": 250,
	"lvl" : 80,
	"skills_name" : "��������",
        "damage_type" : "����"
]),
});

int valid_enable(string usage) { return usage=="hand" ||  usage=="parry"; }

int valid_combine(string combo) { return combo=="yunlong-zhua"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("�������ֱ�����֡�\n");
	if ((int)me->query_skill("yunlong-shengong", 1) < 50)
		return notify_fail("��������񹦻�򲻹����޷�ѧ�����֡�\n");
	if ((int)me->query_skill("force", 1) < 50)
		return notify_fail("��Ļ����ڹ���򲻹����޷�ѧ�����֡�\n");
	if ((int)me->query("max_neili") < 250)
		return notify_fail("�������̫�����޷��������֡�\n");
	if ((int)me->query_skill("claw",1) <30)
		return notify_fail("��Ļ����ַ���򲻹����޷�ѧ�����֡�\n");
	if (2*(int)me->query_skill("yunlong-xinfa",1) <(int)me->query_skill("yunlong-shou",1))
		return notify_fail("��������ķ���
�򲻹����޷�����ѧ�����֡�\n");
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
	int i, level;
	level   = (int) me->query_skill("yunlong-shou",1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];

}


int practice_skill(object me)
{
	if ((int)me->query("qi") < 30)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("������������������֡�\n");
	me->receive_damage("qi", 30);
	me->add("neili", -10);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"yunlong-shou/" + action;
}
int ob_hit(object ob, object me, int damage)
{
        object wp1,weapon;
        string msg;
        int p,j,skill, neili, neili1;
        int level,level2,damage2;
        level = (int) me->query_skill("unarmed",1);
        level2= (int) me->query_skill("yunlong-shengong",1);
        skill = me->query_skill("yunlong-shengong", 1);
        neili = me->query("neili");
        neili1 = ob->query("neili");
if ( level2<= 0) level2= (int) me->query_skill("yunlong-shengong",1);
damage2= (int) ob->query("neili",1)/10;
if (random(8)==0 && level2>=300 && (me->query_skill_mapped("force") == "yunlong-shengong"))
{
j = -damage/2; 
if (damage2> 5000)	damage2=5000;
msg = HIR"$N"+HIR+"$N���־۳ɻ�צ״! ����Ѫ��ץ��һ��ץס$n��"+ xue_name[random(sizeof(xue_name))] +NOR;

           message_vision(msg, me, ob);
if (ob->query("qi") > damage2)
{
ob->apply_condition("zhua_poison",10);
		ob->receive_damage("qi", damage2/2);
		ob->receive_wound("qi", damage2/2);
}
 if (!ob->is_busy() && random(3)==0) ob->start_busy(2);  
}

           return j;
}      
