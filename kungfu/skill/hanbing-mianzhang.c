// hannbing-mianzhang.c ��������
// pal 1997.05.26
#include <ansi.h>;
inherit SKILL;

mapping *action = ({
([	"action" : "$Nһʽ���󽭶�ȥ����˫�ƴ󿪴�ϣ�ֱ��$n��$l��ȥ",
	"force" : 180,
        "dodge" : 5,
        "parry" : 20,
	"damage": 200,
	"lvl" : 0,
	"skill_name" : "�󽭶�ȥ",
        "damage_type" : "����"
]),
([	"action" : "$N����һ�䣬һʽ���ƺӾ�������˫��������ֱ������$n��$l",
	"force" : 220,
        "dodge" : 10,
        "parry" : 15,
	"damage": 220,
	"lvl" : 10,
	"skill_name" : "�ƺӾ���",
        "damage_type" : "����"
]),
([	"action" : "$Nʹһʽ������ɽɫ����������΢����棬������ϸ�����ֱȡ$n��$l",
	"force" : 260,
        "dodge" : 15,
        "parry" : 20,
	"damage": 230,
	"lvl" : 20,
	"skill_name" : "����ɽɫ",
        "damage_type" : "����"
]),
([	"action" : "$N����һ�֣�һʽ�������׺���������������������$n�����ȥ",
	"force" : 300,
        "dodge" : 20,
        "parry" : 30,
	"damage": 240,
	"lvl" : 30,
	"skill_name" : "�����׺�",
        "damage_type" : "����"
]),
([	"action" : "$N����һת��ʹ��һʽ��ˮ�����١���ֻ��������Ӱ��ס��$n��ȫ��",
	"force" : 340,
        "dodge" : 25,
        "parry" : 20,
	"damage": 250,
	"lvl" : 40,
	"skill_name" : "ˮ������",
        "damage_type" : "����"
]),
([	"action" : "$NͻȻ����һ����ʹ��һʽ��С����硹���������أ�������ӯ������$n��$l",
	"force" : 380,
        "dodge" : 25,
        "parry" : 25,
	"damage": 260,
	"lvl" : 50,
	"skill_name" : "С�����",
        "damage_type" : "����"
]),
([	"action" : "$Nʹһʽ����ѩ��ɽ����˫��Ю��籩ѩ֮�ƣ��͵�����$n��$l",
	"force" : 420,
        "dodge" : 30,
        "parry" : 30,
	"damage": 270,
	"lvl" : 260,
	"skill_name" : "��ѩ��ɽ",
        "damage_type" : "����"
]),
([	"action" : "$Nһ�С�˪�����ء���˫�ƴ�����ɪ������������$n��$l",
	"force" : 460,
        "dodge" : 30,
        "parry" : 235,
	"damage": 280,
	"lvl" : 270,
	"skill_name" : "˪������",
        "damage_type" : "����"
]),
([	"action" : "$N����Ȼһ�䣬ʹ��һʽ���������������Ӱǧ����ã���$n�޷�����",
	"force" : 500,
        "dodge" : 40,
        "parry" : 45,
	"damage": 290,
	"lvl" : 80,
	"skill_name" : "�������",
        "damage_type" : "����"
]),
([	"action" : "$N��Хһ����һʽ����˪ѩ�꡹��˫�ƻ��裬��ͬѩ������ת������$n��$l",
	"force" : 540,
        "dodge" : 45,
        "parry" : 50,
	"damage": 310,
	"lvl" : 90,
	"skill_name" : "�������",
        "damage_type" : "����"
])
});

int valid_enable(string usage)
{
	return usage=="strike" || usage=="parry" ;
}
int valid_combine(string combo) { return combo=="sougu"; }
int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("���������Ʊ�����֡�\n");
//	if ((int)me->query_skill("huagong-dafa", 1) < 20)
//		return notify_fail("��Ļ����󷨻�򲻹����޷�ѧ�������ơ�\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������̫�����޷����������ơ�\n");
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
	level   = (int) me->query_skill("hanbing-mianzhang",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 30)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 40)
		return notify_fail("��������������������ơ�\n");
	me->receive_damage("qi", 30);
	me->add("neili", -10);
	return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
if( random(me->query_skill("hanbing-mianzhang",1)) > 10 )
	victim->apply_condition("ice_poison", random(me->query_skill("hanbing-mianzhang",1)/10) + 6 + victim->query_condition("ice_poison"));
}
int ob_hit(object ob, object me, int damage)
{
        object wp1,weapon;
        string msg;
        int p,j,skill, neili, neili1;
        int level,level2,damage2;
        level = (int) me->query_skill("unarmed",1);
        level2= (int) me->query_skill("jiuyang-shengong",1);
        skill = me->query_skill("jiuyang-shengong", 1);
        neili = me->query("neili");
        neili1 = ob->query("neili");
if ( level2<= 0) level2= (int) me->query_skill("shenghuo-shengong",1);
damage2= (int) ob->query("neili",1)/10;
if (random(8)==0 && level2>=300 && (me->query_skill_mapped("force") == "jiuyang-shengong" || me->query_skill_mapped("force") == "shenghuo-shengong"))
{
j = -damage/2; 
j = 0;
if (damage2> 5000)	damage2=5000;
msg = HIC+"$N��������� ȫ���������������ֳ�һ����͵ľ���! !" +NOR;
           message_vision(msg, me, ob);
if ( me->is_busy())
{
me->start_busy(1);
ob->start_busy(2);
}
if (me->query("neili") > me->query("max_neili")*2)
{
		
		me->add("neili", damage2);
}

}


           return j;
}      
string perform_action_file(string action)
{
	return __DIR__"hanbing-mianzhang/" + action;
}
