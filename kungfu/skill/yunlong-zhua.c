// yunlong-zhua.c -����צ

#include <ansi.h>
inherit SKILL;
string *xue_name = ({ 
"�͹�Ѩ","����Ѩ","����Ѩ","��ԪѨ","����Ѩ","�м�Ѩ","�н�Ѩ","��ͻѨ","�ٻ�Ѩ",
"����Ѩ","����Ѩ","���Ѩ","�Ϲ�Ѩ","��ԨѨ","�쾮Ѩ","��ȪѨ","����Ѩ","����Ѩ",}); 

mapping *action = ({
([	"action" : "$Nȫ��εض��𣬰����һ�����һʽ����ӥϮ�á���Ѹ�͵�ץ��$n��$l",
	"force" : 150,
        "dodge" : 15,
        "parry" : 10,
	"damage": 120,
	"lvl" : 0,
	"skills_name" : "��ӥϮ��",
	"damage_type" : "ץ��"
]),
([	"action" : "$N����ֱ����˫��ƽ�죬һʽ����ӥչ�᡹��˫צһǰһ��£��$n��$l",
	"force" : 220,
        "dodge" : 20,
        "parry" : 15,
	"damage": 145,
	"lvl" : 10,
	"skills_name" : "��ӥչ��",
        "damage_type" : "ץ��"
]),
([	"action" : "$Nһʽ���γ�ӥ�ɡ���ȫ����б��ƽ�ɣ�����һ����˫צ����$n�ļ�ͷ",
	"force" : 250,
        "dodge" : 20,
        "parry" : 20,
	"damage": 160,
	"lvl" : 20,
	"skills_name" : "�γ�ӥ��",
        "damage_type" : "����"
]),
([	"action" : "$N˫צ�����Ͼ٣�ʹһʽ��ӭ��������һ�����ֱ�Ϯ��$n����Ҹ����",
	"force" : 290,
        "dodge" : 25,
        "parry" : 20,
	"damage": 180,
	"lvl" : 30,
	"skills_name" : "ӭ������",
        "damage_type" : "����"
]),
([	"action" : "$Nȫ�������ǰ��һʽ��������צ������צͻ�������Ȱ�ץ��$n���ؿ�",
	"force" : 350,
        "dodge" : 30,
        "parry" : 25,
	"damage": 200,
	"lvl" : 40,
	"skills_name" : "������צ",
        "damage_type" : "����"
]),
([	"action" : "$N���ػ��У�һʽ���������ء�������Ϯ�����д�Ѩ�����ַ�ץ$n���ɲ�",
	"force" : 350,
        "dodge" : 35,
        "parry" : 25,
	"damage": 220,
	"lvl" : 50,
	"skills_name" : "��������",
        "damage_type" : "����"
]),
([	"action" : "$N��������צ���棬һʽ���������ա��������������ƿն�����Ѹ���ޱȵػ���$n",
	"force" : 380,
        "dodge" : 55,
        "parry" : 55,
	"damage": 245,
	"lvl" : 60,
	"skills_name" : "��������",
        "damage_type" : "����"
]),
([	"action" : "$N�ڿո߷����ɣ�һʽ��ӥ�����������ж�ʱ�Գ�һ������צӰ����������$n",
	"force" : 430,
        "dodge" : 40,
        "parry" : 40,
	"damage": 260,
	"lvl" : 60,
	"skills_name" : "ӥ������",
        "damage_type" : "����"
]),
([	"action" : "$N���Ĳ��ض���ʹһʽ��������ˮ�������λ���һ����������$n",
	"force" : 470,
        "dodge" : 50,
        "parry" : 50,
	"damage": 280,
	"lvl" : 70,
	"skills_name" : "������ˮ",
        "damage_type" : "����"
]),
([	"action" : "$N΢΢һЦ��ʹһʽ������ڡ���˫�ֻó�������,ֱ����$n��$l",
	"force" : 470,
        "dodge" : 60,
        "parry" : 60,
	"damage": 350,
	"lvl" : 80,
	"skills_name" : "�����",
        "damage_type" : "����"
])
});

int valid_enable(string usage) { return usage=="claw" || usage=="parry"; }

int valid_combine(string combo) { return combo=="yunlong-shou"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("������צ������֡�\n");
	if ((int)me->query_skill("yunlong-shengong", 1) < 50)
		return notify_fail("��������񹦻�򲻹����޷�ѧ����צ��\n");
	if ((int)me->query_skill("force", 1) < 50)
		return notify_fail("��Ļ����ڹ���򲻹����޷�ѧ����צ��\n");
	if ((int)me->query("max_neili") < 350)
		return notify_fail("�������̫�����޷�������צ��\n");
	if ((int)me->query_skill("claw",1) <40)
		return notify_fail("��Ļ���צ����򲻹����޷�ѧ����צ��\n");
       if (((int)me->query_skill("houquan", 1)+200) < (int)me->query_skill("yunlong-zhua", 1))
               return notify_fail("��ĺ�ȭ̫���ˡ�\n");
       if (((int)me->query_skill("baihua-cuoquan", 1)+200) < (int)me->query_skill("yunlong-zhua", 1))
               return notify_fail("��İٻ���ȭ̫���ˡ�\n");

       if (((int)me->query_skill("yunlong-shou", 1)+100) < (int)me->query_skill("yunlong-zhua", 1))
               return notify_fail("���������̫���ˡ�\n");
       if (((int)me->query_skill("yunlong-shengong", 1)+200) < (int)me->query_skill("yunlong-zhua", 1))
               return notify_fail("���������̫���ˡ�\n");
       if (((int)me->query_skill("yunlong-shenfa", 1)+200) < (int)me->query_skill("yunlong-zhua", 1))
               return notify_fail("���������̫���ˡ�\n");

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
	level   = (int) me->query_skill("yunlong-zhua",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 30)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("�����������������צ��\n");
       if (((int)me->query_skill("houquan", 1)+200) < (int)me->query_skill("yunlong-zhua", 1))
               return notify_fail("��ĺ�ȭ̫���ˡ�\n");
       if (((int)me->query_skill("baihua-cuoquan", 1)+200) < (int)me->query_skill("yunlong-zhua", 1))
               return notify_fail("��İٻ���ȭ̫���ˡ�\n");

       if (((int)me->query_skill("yunlong-shou", 1)+100) < (int)me->query_skill("yunlong-zhua", 1))
               return notify_fail("���������̫���ˡ�\n");
       if (((int)me->query_skill("yunlong-shengong", 1)+200) < (int)me->query_skill("yunlong-zhua", 1))
               return notify_fail("���������̫���ˡ�\n");
       if (((int)me->query_skill("yunlong-shenfa", 1)+200) < (int)me->query_skill("yunlong-zhua", 1))
               return notify_fail("���������̫���ˡ�\n");
	me->receive_damage("qi", 30);
	me->add("neili", -10);
	return 1;
}


string perform_action_file(string action)
{
	return __DIR__"yunlong-zhua/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        int lvl;
        int flvl;

        lvl  = me->query_skill("yunlong-zhua", 1);
        flvl = me->query("jiali");
        if (me->query_skill_mapped("force") != "yunlong-shengong" )
                return;
        if (lvl < 100 || flvl < 10 ||  damage_bonus < 60
        )
                return;
if (random(3)==0)
{
victim->apply_condition("zhua_poison", random(me->query_skill("yunlong-zhua",1)/40) + 11 +
			victim->query_condition("zhua_poison"));
victim->receive_wound("qi", (damage_bonus ) / 2, me);
                return HIR "ֻ��$n" HIR "һ���Һ��������ܵ�����Ѫ��צ�����ĸ��ţ�\n" NOR;
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
