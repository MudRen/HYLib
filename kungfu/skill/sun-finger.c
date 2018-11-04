// sun-finger.c һ��ָ book: һ��ָ��

#include <ansi.h>

inherit SKILL;  
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});
string *xue_name = ({ 
"�͹�Ѩ","����Ѩ","����Ѩ","��ԪѨ","����Ѩ","�м�Ѩ","�н�Ѩ","��ͻѨ","�ٻ�Ѩ",
"����Ѩ","����Ѩ","���Ѩ","�Ϲ�Ѩ","��ԨѨ","�쾮Ѩ","��ȪѨ","����Ѩ","����Ѩ",}); 

mapping *action = ({
([	"action" : "$Nһʽ"+(order[random(13)])+"������������"NOR"��������ָ���籡������������ָ�������
��������$n��$l",
	"force" : 100,
	"dodge" : 25,
	"damage": 200,
	"lvl" : 0,
	"skill_name" : "��������",
	"damage_type" : "����"
]),
([	"action" : "$N����һת��һ���絽$n���$n��æת��$N���������Ծ�أ�
һʽ"+(order[random(13)])+"��³�����ա�"NOR"������ʳָ������ָ��$n��$l",
	"force" : 120,
	"dodge" : 25,
	"damage": 200,
	"lvl" : 20,
	"skill_name" : "³������",
	"damage_type" : "����"
]),
([	"action" : "$N����̤��һ���������������ʳָЮ���ۻ���������$n��$l��
��ʽ����̹��������һʽ"+(order[random(13)])+"��������ѩ��"NOR"",
	"force" : 160,
	"dodge" : 20,
	"damage": 140,
	"lvl" : 40,
	"skill_name" : "������ѩ",
	"damage_type" : "����"
]),
([	"action" : "$N��ӰƮ��һʽ"+(order[random(13)])+"���������졹"NOR"�����϶��£���������繳����
��$n���Ҽ磬$n������ܣ�$N���ֳ��Ƶ���$n��$l",
	"force" : 190,
	"dodge" : 30,
	"damage": 150,
	"lvl" : 60,
	"skill_name" : "��������",
	"damage_type" : "����"
]),
([	"action" : "ֻ��$N���Ϻ���һ�죬����һ�գ�һʽ"+(order[random(13)])+"�����ս�����"NOR"������ʳָ
бָ����$n��$l��ȥ",
	"force" : 220,
	"dodge" : 30,
	"damage": 270,
	"lvl" : 70,
	"skill_name" : "���ս���",
	"damage_type" : "����"
]),
([	"action" : "$N����б����ͻȻ�����Ϊָ���͵�һ���죬һʽ"+(order[random(13)])+"�����ﳯ����"NOR"��
ʹ��һ��ָ��������$n��$l",
	"force" : 250,
	"dodge" : 20,
	"damage": 280,
	"lvl" : 90,
	"skill_name" : "���ﳯ��",
	"damage_type" : "����"
]),
([	"action" : "$N����һԾ������$n������ϥһ��������ʳָ����һʽ"+(order[random(13)])+"����
������"NOR"������$n�ĺ���",
	"force" : 280,                                                  
	"dodge" : 25,
	"damage": 200,
	"lvl" : 100,
	"skill_name" : "��������",
	"damage_type" : "����"
]),
([  "action" : "$Nһ�����, һʽ"+(order[random(13)])+"��������̩��"NOR"���þ�ȫ����$n��$l��ȥ",
	"force" : 300,
	"dodge" : 10,
	"damage": 320,
	"lvl" : 130,
	"skill_name" : "������̩",
	"damage_type" : "����"
]),
});

int valid_enable(string usage) { return usage=="finger" || usage=="parry"; }

int valid_combine(string combo) { return combo=="haotian-zhang"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("��һ��ָ������֡�\n");
	if (me->query("gender") != "����")
		return notify_fail("���������㣬�޷�ѧһ��ָ��\n");
	if ((int)me->query("max_neili") < 700)
		return notify_fail("�������̫�����޷���һ��ָ��\n");
	if ((int)me->query_skill("kurong-changong", 1) > 80 ||
	    (int)me->query_skill("xiantian-qigong", 1) > 80)
		return 1;
	else
		return notify_fail("��ı����ڹ���򲻹����޷�ѧһ��ָ��\n");
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
	level   = (int) me->query_skill("sun-finger", 1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 50)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 30)
		return notify_fail("�������������һ��ָ!\n");
	me->receive_damage("qi", 30);
	me->add("neili", -10);
	return 1;
}

string perform_action_file(string action)
{
        return __DIR__"sun-finger/" + action;
}
int ob_hit(object ob, object me, int damage)
{
        object wp1,weapon;
        string msg;
        int p,j,skill, neili, neili1;
        int level,level2,damage2;
        level = (int) me->query_skill("unarmed",1);
        level2= (int) me->query_skill("kurong-changong",1);
        skill = me->query_skill("kurong-changong", 1);
        neili = me->query("neili");
        neili1 = ob->query("neili");
damage2= (int) ob->query("neili",1)/10;
if (random(8)==0 && level2>=300 && me->query_skill_mapped("force") == "kurong-changong")
{
j = -damage/2; 
if (damage2> 5000)	damage2=5000;

if (me->query("qi") <= me->query("max_qi"))
{
me->add("qi",damage2);
}

if (me->query("eff_qi") <= me->query("max_qi"))
{
me->add("eff_qi",damage2);
}



msg = HIG"$N ����һ������ʩչ��һ��ָ�����Դ���ָ���鲼ȫ��! ��ɫ������ˡ�\n"NOR;
           if (!ob->is_busy() && random(3)==0)
{
msg += HIY"$n"+HIY+"��$N�Ĵ���ָ������! ��������� "+ xue_name[random(sizeof(xue_name))] +NOR;
                ob->apply_condition("yyz_damage",30);
                ob->start_busy(3);  
}

//msg += "$n��������̫��ȭ������������������\n",  
           message_vision(msg, me, ob);
           return j;
}      
}
