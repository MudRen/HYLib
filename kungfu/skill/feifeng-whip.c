// feifeng-whip.c �ɷ�޷�

#include <ansi.h>

inherit SKILL;
string *xue_name = ({ 
"�͹�Ѩ","����Ѩ","����Ѩ","��ԪѨ","����Ѩ","�м�Ѩ","�н�Ѩ","��ͻѨ","�ٻ�Ѩ",
"����Ѩ","����Ѩ","���Ѩ","�Ϲ�Ѩ","��ԨѨ","�쾮Ѩ","��ȪѨ","����Ѩ","����Ѩ",}); 


mapping *action = ({
([	"action":  "$N����Ծ��һ�С����չ�᡹������$w���¶��ϣ�����$n������",
	"force":  100,
	"dodge":  30,
	"damage":  220,
	"lvl" : 15,
	"skill_name" : "���չ��",
	"damage_type":	"����"
]),
([	"action":  "$Nһ�С��ʷ����ࡹ������$wֱ����$n��$l",
	"force":  110,
	"dodge":  30,
	"damage":  230,
	"lvl" : 20,
	"skill_name" : "�ʷ�����",
	"damage_type":	"����"
]),
([  "action":  "$Nһ�С��������������$w�ڿ�һ��һ���������࣬�͵���
$n��ͷ����",
	"force":  120,
	"dodge":  35,
	"damage":  240,
	"lvl" : 40,
	"skill_name" : "�����",
	"damage_type":	"����"
]),
([  "action":  "$N̤��һ��������$n��٬һЦ������$wȴ����ͣ����һ�С�����
Ϸ���ɨ��$n��$l",
	"force":  130,
	"dodge":  30,
	"damage":  360,
	"lvl" : 50,
	"skill_name" : "����Ϸ��",
	"damage_type":	"����"
]),
([  "action":  "$NԾ�ڰ�գ�һ�С����ɷ��衹������$w������ϴ�գ�����Ϸ��
���������ֵ�$n����",
	"force":  150,
	"dodge":  35,
	"damage":  370,
	"lvl" : 60,
	"skill_name" : "���ɷ���",
	"damage_type":	"����"
]),
([  "action":  "$N��ǰ����������$wȦת��磬һ�С�������项������$nǰ��",
    "force":  270,
	"dodge":  40,
	"damage":  385,
	"lvl" : 75,
	"skill_name" : "�������",
	"damage_type":	"����"
])
});

int valid_enable(string usage) { return (usage == "whip") || (usage == "parry"); }

int valid_learn(object me)
{
	object weapon;

	if ((int)me->query_skill("kurong-changong", 1) < 20)
		return notify_fail("��Ŀ����������̫ǳ��\n");
//	if ( me->query("gender") != "Ů��")
//		return notify_fail("����ү��ѧ��ɷ�ޣ����ʲ���ɡ�\n");
	if ( !objectp(weapon = me->query_temp("weapon"))
	|| ( string)weapon->query("skill_type") != "whip" )
		return notify_fail("���������һ�����޲������޷���\n");

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
        level   = (int) me->query_skill("feifeng-whip",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "whip")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("��������������ɷ�޷���\n");
	me->receive_damage("qi", 10);
	return 1;
}



mixed hit_ob(object me, object victim, int damage_bonus)
{
    string name,weapon;
    name = xue_name[random(sizeof(xue_name))];


if((!random(3)) && (me->query("neili")>200) &&  me->query_skill("kurong-changong",1) > 50)
	   {
  if( !victim->is_busy() )
{ 
	    victim->start_busy(3);
}
        me->add("neili",-30);
		victim->add("neili",-30);
		victim->receive_damage("qi", me->query_skill("feifeng-whip",1)/2+damage_bonus/2);
        victim->receive_wound("qi", me->query_skill("feifeng-whip",1)/2+damage_bonus/2);       
		 victim->apply_condition("yyz_damage",30);
		return HIR "$n��$N�����Ĵ�����������"RED+name+HIR"���������ɵ�һ�ͣ�\n" NOR;
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

