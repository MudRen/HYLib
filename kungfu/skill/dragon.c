// dragon.c ��֮����
#include <ansi.h>
inherit SKILL;  
#include <ansi.h>
#include <combat.h>
//inherit F_SSERVER;

#include "/kungfu/skill/eff_msg.h";
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});


string *dodge_msg = ({
        "����$nһ�����$N���ס�ˣ����ҷ��ֽ�����\n",
        "����$n����һ����$N��һ�����˸��ա�\n",
        "$n�ڿ�Ծ�𣬶㿪��$N����һ�С�\n",
        "$nҲ��������ֱ��$N��ȥ��$Nһ������ֻ�������˿���\n",
});

mapping *action = ({
([  "action":"$N����һ�࣬β�ͺ�Ȼ�����˦����ɨ��$n",
    "dodge" : 40,
    "damage": 600,
    "damage_type":  "����"
]),
([  "action":"$N��Ȼ�ӽ��������ҧ$n",
    "dodge" : 60,
    "damage": 300,
    "damage_type":  "����"
]),
([  "action":"$N��ץ�ŵأ���ץֱ��$n�沿",
    "dodge" : 50,
    "damage": 400,
    "damage_type":  "����"
]),
([  "action":"$NͻȻһԾ���ӿ���ֱ��$n",
    "dodge" : 100,
    "damage": 600,
    "damage_type":  "����"
]),
([  "action":"$N����ǰ�㣬��ȫ��֮��ײ��$n",
    "dodge" : 40,
    "damage": 1000,
    "damage_type":  "����"
]),
([  "action" : 		"$N��"+HIM+"����"+NOR+"��$n��$l����һ��",
    "damage": 500,
	"dodge":		10,
        "force":		200,
    "lvl" : 0,
    "skill_name" : "��������",
    "damage_type" : "����"
]),
([  "action" : "$N��ת����"+HIG+"β�ͼ�"+NOR+"��׼$n��$lһ��",
    "dodge" : 10,
    "damage": 500,
	"dodge":		10,
        "force":		200,
    "lvl" : 0,
    "skill_name" : "���ֵ�Ѩ",
    "damage_type":	"ҧ��",
]),
([  "action" : "$N������"+HIC+"����"+NOR+"��$n��$l�ݺݵ�һҧ",
	"dodge":		10,
        "force":		200,
    "dodge" : 15,
    "damage": 520,
    "lvl" : 0,
    "skill_name" : "ǰհ����",
		"damage_type":	"ҧ��",
]),
([  "action" : "$N��"+HIW+"צ��"+NOR+"��$n��$lһץ",
	"dodge":		10,
        "force":		200,
    "dodge" : 25,
    "damage": 580,
    "lvl" : 0,
    "skill_name" : "������Ӱ",
    "damage_type":	"ץ��",
]),
([  "action" : "$Ņ��"+HIR+"צ��"+NOR+"��$n��$lһ��",
	"dodge":		10,
        "force":		200,
    "dodge" : 30,
    "damage": 500,
    "lvl" : 0,
    "skill_name" : "�޵и��",
    "damage_type":	"����",
])
});

int valid_enable(string usage) 
{ 
	return usage == "unarmed" ||  usage == "dodge" ||usage == "parry" ; 
}

mapping query_action(object me, object weapon)
{
return action[random(sizeof(action))];
}


int practice_skill(object me)
{
	return notify_fail("��֮�����޷�ͨ����ϰ���ɳ���\n");
}
int valid_learn(object me)
{
	 return 1; 
 }

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}
string perform_action_file(string action)
{
        return __DIR__"dragon/" + action;
}



mixed hit_ob(object me, object victim,int damage_bonus)
        
{	
        int i, level;
        object target;
object weapon;
        level   = (int) me->query_skill("dragon",1);
//        target = me->select_opponent();
        weapon = me->query_temp("weapon");

	if( random(5)==1 && random(level) > 160)
	{
        if (userp(victim))
        victim->start_busy(2);
else    victim->start_busy(2);
        return HIC "����Ϣ!!����$NͻȻ��Ϣ��$n����ס��ʱ���ܶ���!!\n" NOR;
	}
  	if( random(5)==1 && random(level) > 160)
	{
        if (userp(victim) && victim->query("eff_qi") > 50
        && victim->query("qi") > 50)
{
if (victim->query("qi")/15 > 20)
        victim->add("qi",-victim->query("qi")/35);
if (victim->query("eff_qi")/15 > 20)
        victim->add("eff_qi",-victim->query("eff_qi")/35);
}else 
{
        victim->add("qi",-100);
        victim->add("eff_qi",-100);
}
        return HIR "������!!����$NͻȻ���ף�$n���յ÷�������!!\n" NOR;
	}
 	if( random(5)==1 && random(level) > 150)
	{
        if (userp(victim) && victim->query("jing") > 50
        && victim->query("eff_jing") > 50)
{
if (victim->query("jing")/20 > 20)
        victim->add("jing",-victim->query("jing")/40);
if (victim->query("eff_jing")/20 > 20)
        victim->add("eff_jing",-victim->query("eff_jing")/40);
}
else {
        victim->add("jing",-400);
        victim->add("eff_jing",-400);
}
        return HIY "������!!����$NͻȻ����$n�������к����ͷʹ�ޱ�!!\n" NOR;
	}
if (damage_bonus < 100) damage_bonus=100;
        if( damage_bonus > 200 ) 
{
        victim->receive_wound("qi", damage_bonus );	
        victim->receive_wound("qi", damage_bonus );
        return HIR "��צ!!һ����Ѫ��$n���������\n" NOR;	
}
        if( damage_bonus < 120 ) 
{
        victim->receive_wound("qi", damage_bonus );	
        victim->receive_wound("qi", damage_bonus );	
        return YEL "��צ!!����$n�ƺ�һ��,���ӻ������Σ�\n" NOR;
}
else
{       
        victim->receive_wound("qi", damage_bonus );	
        victim->receive_wound("qi", damage_bonus );	
        return HIM "��צ!!����������������һ�����죬���Ͼ�����һЩѪ�Σ�\n" NOR;
}

}
int ob_hit(object ob, object me, int damage)
{
	object weapon = me->query_temp("weapon");
        string msg,dodge_skill,*limbs;
        int i, j, level, p, q;
        
        limbs = ob->query("limbs");
        level = me->query_skill("dragon", 1);

//        if( me->is_busy()) return 1;
        if( damage < 100 ) return 1;
        if (  random(level) > 150  && random(3) ==1   ){
         msg = RED"$N���$n�Ĺ��ơ�����һ����������ȥ!!!��\n"NOR;
            message_vision(msg, me, ob);
            if ( random(5) == 0 && random(level) > 150){
         msg = YEL"����Ϣ!!����$NͻȻ��Ϣ��$n����ס��ʱ���ܶ���!!\n"NOR;
//             if (!ob->is_busy())
        if (userp(ob) && ob->query("qi") > 50 && ob->query("jing") > 50
        && ob->query("eff_qi") > 50 && ob->query("eff_jing") > 50){
             ob->start_busy(2);
if (ob->query("qi")/20 > 20)
             ob->add("qi",-ob->query("qi")/45);
if (ob->query("eff_qi")/20 > 20)
             ob->add("eff_qi",-ob->query("eff_qi")/50);
}
else
{
             ob->start_busy(3);
             ob->add("qi",-1000);
             ob->add("eff_qi",-1000);
}
msg += damage_msg(damage, "����");
            }
else  if (random(5)==1&& random(level) > 150){
         msg = HIR"������!!����$NͻȻ���ף�$n���յ÷�������!!!!\n"NOR;
        if (userp(ob) && ob->query("qi") > 50 
        && ob->query("eff_qi") > 50)
{
if (ob->query("qi")/15 > 20)
             ob->add("qi",-ob->query("qi")/45);
if (ob->query("eff_qi")/15 > 20)
             ob->add("eff_qi",-ob->query("eff_qi")/45);
}
else {
             ob->add("qi",-2000);
             ob->add("eff_qi",-2000);
}
msg += damage_msg(damage, "����");
            }
else  if (random(5)==2&& random(level) > 150){
         msg = HIC"������!!����$NͻȻ����$n�������к����ͷʹ�ޱ�!!\n"NOR;
        if (userp(ob) && ob->query("qi") > 50
        && ob->query("jing") > 50
        && ob->query("eff_qi") > 50
        && ob->query("eff_jing") > 50)
{
if (ob->query("qi")/30 > 20)
             ob->add("qi",-ob->query("qi")/45);
if (ob->query("eff_qi")/30 > 20)
             ob->add("eff_qi",-ob->query("eff_qi")/45);
if (ob->query("jing")/30 > 20)
             ob->add("jing",-ob->query("jing")/45);
if (ob->query("eff_jing")/30 > 20)
             ob->add("eff_jing",-ob->query("eff_jing")/45);
}
else
{
             ob->add("qi",-1000);
             ob->add("eff_qi",-1000);

}
msg += damage_msg(damage, "����");
            }
else
           msg = HIG"$n���ȳ��У�ʹ$N�ķ���ʧ����!��\n"NOR;
            message_vision(msg, me, ob);
            return damage;
        }
}
