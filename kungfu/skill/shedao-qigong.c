// shedao-qigong  �ߵ��湦
#include <ansi.h>;
inherit SKILL;  
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});


mapping *action = ({
([	"action" : "$Nʹһ��"+(order[random(13)])+"���ɺ����᡹"NOR"����$wһ�ᣬ����$n��$l",
	"damage" : 150,
	"parry": 40,
	"force": 150,
	"damage_type" : "����",
	"skill_name" : "�ɺ�����"
]),
([	"action": "$Nʹ��"+(order[random(13)])+"�����߳�����"NOR"������΢��������$wٿ����$n��$l��ȥ",
	"damage" : 150,
	"dodge": 80,
	"parry": 10,
	"force": 250,
	"damage_type": "����",
	"skill_name" : "���߳���"
]),
([	"action": "$N����΢�������㷴�ߣ�����ת��ʹһ��"+(order[random(13)])+"������������"NOR"������$w�Ѵ���$n$l",
	"damage" : 160,
	"dodge": 80,
	"parry": 20,
	"force": 250,
	"damage_type": "����",
	"skill_name" : "��������"
]),
([	"action" : "$Nʹһʽ"+(order[random(13)])+"��������衹"NOR"��������$n������һ����˳����$w��һ�㣬$w��Ȼ���Լ��ʺ��䣬����$N��������һ����$w�ӹ����ʺ�����$n�������",
	"damage" : 170,
	"force" : 350,
        "dodge" : 50,
	"lvl" : 40,
        "damage_type" : "����",
	"skill_name" : "�������"
]),
([	"action": "$N�����ڵ���һ�����ʹһ��"+(order[random(13)])+"��С����¡�"NOR"����$n�������������$wֱ��$n",
	"damage" : 180,
	"dodge": 70,
	"parry": 130,
	"force": 350,
	"damage_type": "����",
	"skill_name" : "С�����"
]),
([	"action": "$N���һ����ʹһ��"+(order[random(13)])+"������ٶ���"NOR"����������$n��ȪҪѨ������$nˤ���ڵ�",
	"damage" : 200,
	"dodge": 25,
	"parry": 110,
	"damage" : 70,
	"force": 400,
	"damage_type": "����",
	"skill_name" : "����ٶ�"
]),
([	"action": "$N˫��һ����������ݣ�һ��"+(order[random(13)])+"��³�ﲦ����"NOR"����ץ��$n�ҽ����ף�����$wֱ��$n�"+(order[random(13)])+"���",
	"dodge": 180,
	"damage" : 180,
	"parry": 110,
	"force": 400,
	"damage_type": "����",
	"skill_name" : "³�ﲦ��"
]),
([	"action": "$NͻȻһ���������һ��"+(order[random(13)])+"�����ཱུ����"NOR"��˫��һ�֣����ڼ�ͷ��˫��ֱ��$n",
	"dodge": 190,
	"damage" : 250,
	"parry": 130,
	"force": 400,
	"damage_type": "����",
	"skill_name" : "���ཱུ��"
]),
});

int valid_enable(string usage) { return usage=="sword"|| usage=="staff"|| usage=="parry"; }

int valid_learn(object me)
{
	object weapon;

	if (objectp(weapon = me->query_temp("weapon")))
	if ((string)weapon->query("skill_type") != "staff"&&(string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if ((int)me->query_skill("shenlong-xinfa", 1) < 30)
		return notify_fail("��������ķ���򲻹����޷�ѧ�ߵ��湦.\n");
	if ((int)me->query_skill("force", 1) < 30)
		return notify_fail("��Ļ����ڹ���򲻹����޷�ѧ�ߵ��湦��\n");
	if ((int)me->query_skill("shenlong-bashi", 1) < 30)
		return notify_fail("���������ʽ��򲻹����޷�ѧ�ߵ��湦��\n");
	if ((int)me->query_skill("shenlong-xinfa",1) <(int)me->query_skill("shedao-qigong",1))
		return notify_fail("��������ķ���򲻹����޷�����ѧ�ߵ��湦��\n");
	return 1;
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 50)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 30)
		return notify_fail("��������������ߵ��湦��\n");
	me->receive_damage("qi", 30);
	me->add("neili", -10);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"shedao-qigong/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        int lvl;
        int flvl;
	int level, jiali, time,level2,damage,damage2;
	object weapon;
object target;

        level = (int) me->query_skill("shenlong-xinfa",1);
        level2= (int) me->query_skill("shenlong-xinfa",1);

damage2= (int) victim->query("neili",1)/8;
if (damage2>= 3800) damage2 = 3800;
	
if (random(8)==0 && level>=300 && me->query_skill_mapped("force") == "shenlong-xinfa")
{
	victim->apply_condition("snake_poison",15);
	victim->apply_condition("chanchu_poison",15);
	victim->apply_condition("ill_fashao",10);
	victim->apply_condition("ill_kesou",10);
	victim->apply_condition("ill_shanghan",10);
	victim->apply_condition("ill_zhongshu",10);
	victim->apply_condition("ill_dongshang",10);
 victim->apply_condition("xuanming_poison",10);
if (!victim->is_busy()) victim->start_busy(2);	
 return HIR "$N������У�ս�޲�ʤ�����޲��ˣ��޼᲻�ݣ��޵в��ƣ�$nͷһ��,��Ѫ���!\n";
}

 

}