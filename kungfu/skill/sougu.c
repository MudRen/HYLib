//sougu.c �ѹ�ӥצ��
#include <ansi.h>
inherit SKILL;

mapping *action = ({
([	"action" : "\n$N˫��һ£����צֱ��$n���̣���צȴЮ����֮������$n���䣬һ��һʵ������һ�С���צʽ��",
	"force" : 170,
	"dodge" : 5,
	"damage_type" : "ץ��",
	"lvl" : 0,
	"damage" : 215,
	"skill_name" : "��צʽ"
]),
([	"action" : "\n$N���ζ�������ӥ���հ㡰ٿ���ش�$nͷ��Խ����ʹһ�С���צʽ��˫צ����$n�Ժ����",
	"force" : 190,
	"dodge" : 20,
	"damage_type" : "ץ��",
	"damage" : 225,
	"lvl" : 5,
	"skill_name" : "��צʽ"
]),
([	"action" : "\n$N�͵�һ����ͻȻ����$n��ǰ��ʹһ�С���צʽ������צֱ��$nС��",
	"force" : 215,
	"dodge" : 20,
	"damage_type" : "ץ��",
	"damage" : 235,
	"lvl" : 10,
	"skill_name" : "��צʽ"
]),
([	"action" : "\n$N��צ���أ���צ�����󷢣�һ�С���צʽ������������$n��$l",
	"force" : 245,
	"dodge" : 5,
	"damage_type" : "ץ��",
	"damage" : 225 ,
	"lvl" : 20,
	"skill_name" : "��צʽ"
]),
([	"action" : "\n$N���ι��죬����ǰ�ˣ�ʹһ�С���צʽ����ֱ��$n�ɲ�",
	"force" : 280,
	"dodge" : 25,
	"damage_type" : "ץ��",
	"damage" : 255,
	"lvl" : 35,
	"skill_name" : "��צʽ"
]),
([	"action" : "\n$N����Ʈ������Ȼת��$n���һ�С���צʽ����˫צֱ��$n�ʺ����",
	"force" : 320,
	"dodge" : 35,
	"damage_type" : "ץ��",
	"damage" : 265,
	"lvl" : 60,
	"skill_name" : "��צʽ"
]),
([	"action" : "\n$Nһ����Х�����ΰ���ʹ����ǧצʽ�����ɰ�������»���$n�پ�����צӰ������ȫ����Ѩ",
	"force" : 365,
	"dodge" : 40,
	"damage_type" : "ץ��",
	"damage" : 295,
	"lvl" : 85,
	"skill_name" : "ǧצʽ"
])
});

int valid_enable(string usage) { return usage=="claw" ||  usage=="parry"; }
int valid_combine(string combo) { return combo=="hanbing-mianzhang"; }
int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("���ѹ�ӥצ��������֡�\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������̫�����޷�ѧ�ѹ�ӥצ����\n");
	return 1;
}

string query_skill_name(int level)
{
	int i;
	for(i = sizeof(action)-1; i >= 0; i--)
		if(level >= action[i]["lvl"])
			return action[i]["skill_name"];
}

mapping query_action(object ob, object weapon)
{
	int i, level;
	level = (int)ob->query_skill("sougu", 1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 30)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("�������������ӥצ����\n");
	me->receive_damage("qi", 25);
	me->add("neili", -5);
	return 1;
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
	return __DIR__"sougu/" + action;
}
