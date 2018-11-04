// wuluo-zhang.c ����������
#include <ansi.h>
inherit SKILL;

string *xue_name = ({ 
"�͹�Ѩ","����Ѩ","����Ѩ","��ԪѨ","����Ѩ","�м�Ѩ","�н�Ѩ","��ͻѨ","�ٻ�Ѩ",
"����Ѩ","����Ѩ","���Ѩ","�Ϲ�Ѩ","��ԨѨ","�쾮Ѩ","��ȪѨ","����Ѩ","����Ѩ",}); 

mapping *action = ({
([  "action" : "$N��Ϣ����������һ�ơ��������������������������$n",
    "force"  : 130,
    "dodge"  : 20,
	"damage" : 100,
    "lvl"    : 0,
	"skill_name" : "��������",
	"damage_type" : "����"
]),
([  "action" : "$N����ǳЦ���Ƶ�$n�����������������ӵ$n���䡣$n��
ü���㣬$N����һ�С��������ơ���������Ϣ��$n��$l�ĵ�",
    "force"  : 150,
    "dodge"  : 20,
	"damage" : 130,
    "lvl"    : 20,
	"skill_name" : "��������",
	"damage_type" : "����"
]),
([  "action" : "$Nһ�С��̺����Ρ���˫�ƻû���һƬ��Ӱ����һ�����̣�
��$nϸϸ���ܵ���������",
    "force"  : 150,
    "dodge"  : 30,
	"damage" : 145,
    "lvl"    : 40,
	"skill_name" : "�̺�����",
	"damage_type" : "����"
]),

([  "action" : "$N����Խ��Ȧ�⣬����һ�С��������졹��ԶԶ����$n��$l
�����ĳ����ƣ��Ʒ�ε�����Ȼ��ʢֱ��$n����������",
    "force"  : 200,
    "dodge"  : 25,
	"damage" : 155,
    "lvl"    : 60,
	"skill_name" : "��������",
    "damage_type" : "����"
]),
([  "action" : "$N���ƴ�������Χ��������ƮƮ����$n��ȥ������$n������
�ܣ�����ȴ���ؿڼ���Ȧ����һ�С��������������ϳ����ƣ�����$n��$l",
    "force"  : 250,
    "dodge"  : 70,
	"damage" : 110,
    "lvl"    : 80,
	"skill_name" : "��������",
    "damage_type" : "����"
]),
([  "action" : "$N˫�����ƣ�����һ�󾢷磬һ�С�������ɢ����һ�ɿ���
����$n",
    "force"  : 300,
    "dodge"  : 20,
	"damage" : 190,
    "lvl"    : 100,
	"skill_name" : "������ɢ",
    "damage_type" : "����"
]),
});

int valid_enable(string usage) { return usage=="strike" || usage=="parry"; }

int valid_combine(string combo) { return combo=="jinyu-quan"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("�����������Ʊ�����֡�\n");
	if ((int)me->query_skill("kurong-changong",1) < 20)
		return notify_fail("��Ŀ�������̫�����޷������������ơ�\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������̫�����޷������������ơ�\n");
	return 1;
}

mapping query_action(object me, object weapon)
{
	int i, level;
    level = (int) me->query_skill("wuluo-zhang",1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 50)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("����������������������ơ�\n");
	me->receive_damage("qi", 30);
	me->add("neili", -10);
	return 1;
}


mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
if (damage_bonus <10) damage_bonus=10;
      if( random(me->query_skill("wuluo-zhang",1)) > 90 ) 
{
	  if (!victim->is_busy())
	  victim->start_busy(3);
        return HIC "$n��$N������Ϣ,�������̵��Ʒ���ס����ʽ��\n" NOR;
}
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
