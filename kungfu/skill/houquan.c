// houquan.c ��ȭ

#include <ansi.h>
inherit SKILL;
string *xue_name = ({ 
"�͹�Ѩ","����Ѩ","����Ѩ","��ԪѨ","����Ѩ","�м�Ѩ","�н�Ѩ","��ͻѨ","�ٻ�Ѩ",
"����Ѩ","����Ѩ","���Ѩ","�Ϲ�Ѩ","��ԨѨ","�쾮Ѩ","��ȪѨ","����Ѩ","����Ѩ",}); 


mapping *action = ({
([	"action" : "\n$����΢����������ǰ�˳���һʽ���ɺ�ժ�ҡ�����צֱ����ץ��$n��˫��",
	"force" : 180,
        "dodge" : 15,
	"damage": 190,
	"damage_type" : "ץ��",
	"lvl" : 0,
	"skill_name" : "��ճ���"
]),
([	"action" : "$N������Σ�һʽ�������֦��������ֱ��������$n�ļ羮��Ѩ",
	"force" : 200,
        "dodge" : 20,
	"damage": 190,
        "lvl" : 8,
        "skill_name" : "�����֦",
        "damage_type" : "����"
]),
([	"action" : "$Nһ��ǰ�죬һ�ۺ�ָ��һʽ��Գ�����桹������$n������",
	"force" : 230,
        "dodge" : 30,
	"damage": 195,
	"lvl" : 15,
	"skill_name" : "Գ������",
        "damage_type" : "����"
]),
([	"action" : "\n$N��Ȼ����һ�ţ�ʹһʽ���˷���Ӱ����˫�������޶���һצץ��$n���ؿ�",
	"force" : 230,
        "dodge" : 45,
	"damage": 160,
        "lvl" : 15,
        "skill_name" : "�˷���Ӱ",
        "damage_type" : "����"
]),
([	"action" : "$N����һ������һ������ʹһʽ��ˮ�����¡���˫צ������$n��С��",
	"force" : 220,
        "dodge" : 65,
	"damage": 180,
        "damage_type" : "����",
	"lvl" : 20,
	"skill_name" : "ˮ������"
]),
([	"action" : "$N�͵����ϸ߸�Ծ��һʽ�����ժ�ǡ����Ӹ����£�һצ����$n��ͷ��",
	"force" : 240,
        "dodge" : 80,
	"damage": 230,
        "damage_type" : "ץ��",
	"lvl" : 30,
	"skill_name" : "���ժ��"
]),
});

int valid_enable(string usage) { return usage=="parry"|| usage=="cuff"; }
int valid_combine(string combo) { return combo=="baihua-cuoquan"; }
int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("����ȭ������֡�\n");
	if ((int)me->query_skill("force", 1) < 30)
		return notify_fail("��Ļ����ڹ���򲻹����޷�ѧ��ȭ��\n");
	if ((int)me->query("max_neili") < 200)
		return notify_fail("�������̫�����޷�����ȭ��\n");
	return 1;
}

string query_skill_name(int level)
{
	int i;
	for(i = sizeof(action)-1; i >= 0; i--)
		if(level >= action[i]["lvl"])
			return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
	int i, level;
	level = (int)me->query_skill("houquan", 1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 30)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 10)
		return notify_fail("���������������ȭ��\n");
	me->receive_damage("qi", 15);
	me->add("neili", -5);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"houquan/" + action;
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
        int lvl;

        lvl = me->query_skill("houquan", 1);

        if (damage_bonus < 100 || lvl < 150) return 0;
if (me->query_skill_mapped("force") != "yunlong-shengong" )
                return;
        if (random(4)==0)
        {
                victim->receive_wound("qi", (damage_bonus ) / 3, me);
                return HIR "ֻ��$n" HIR "ǰ�ء����꡹һ�����죬������"
                       "�߹Ƕ��۵�������\n" NOR;
        }
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
