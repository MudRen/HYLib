//npc�书��������!!
#include <ansi.h>
inherit SKILL;  
#include <ansi.h>
#include <combat.h>
//inherit F_SSERVER;

#include "/kungfu/skill/eff_msg.h";
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});


mapping *action = ({
([  "action" : "\n$Nһ�ǹ�ȭ������$n��$l��\n",
     "force":     600,
     "dodge":     100,
     "parry":                100,
        "damage": 600,
        "damage_type" : "ץ��",
]),
([      "action" : "$Nһ��ֱȭ��ֱ��$n��$l��",
     "force":     600,
     "dodge":     100,
     "parry":                100,
        "damage": 600,
        "damage_type" : "����"
]),
([      "action" : "$Nһ�ǰ�ȭ��ֱ��$n��$l��",
     "force":     600,
     "dodge":     100,
     "parry":                100,
        "damage": 600,
        "damage_type" : "����"
]),
([      "action" : "\n$Nһ����ȭ������$n��$l��",
     "force":     600,
     "dodge":     100,
     "parry":                100,
        "damage": 600,
                "damage_type" : "����"
]),
([      "action" : "$Nһ�����ȭ��ֱ��$n��Ҫ����λ��",
     "force":     600,
     "dodge":     100,
     "parry":                100,
        "damage": 600,
        "damage_type" : "����",
]),
});

int valid_enable(string usage) { return usage=="unarmed" ||  usage=="parry"|| usage=="hand"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("��ȭ��������֡�\n");
        if ((int)me->query("max_force") < 200)
                return notify_fail("�������̫�����޷���ȭ����\n");
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
        level = (int)me->query_skill("magic-unarmed", 1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 300)
                return notify_fail("�������̫���ˡ�\n");
        if ((int)me->query("neili") < 300)
                return notify_fail("�������������ȭ����\n");
        me->receive_damage("qi", 300);
        me->add("neili", -300);
        return 1;
}


mixed hit_ob(object me, object victim,int damage_bonus)
        
{	
        int i, level;
        object target;
object weapon;
        level   = (int) me->query_skill("magic-unarmed",1);
//        target = me->select_opponent();
        weapon = me->query_temp("weapon");

	if( random(2)==1 && random(level) > 160)
	{
        if (userp(victim))
        victim->start_busy(3+random(2));
else    victim->start_busy(2);
        return HIC "��������!!����$NͻȻ����,����һ��ħ����$n������ס��ʱ���ܶ���!!\n" NOR;
	}
  	if( random(2)==1 && random(level) > 160)
	{
        if (userp(victim) && victim->query("eff_qi") > 50
        && victim->query("qi") > 50)
{
if (victim->query("qi")/15 > 20)
        victim->add("qi",-victim->query("qi")/15);
if (victim->query("eff_qi")/15 > 20)
        victim->add("eff_qi",-victim->query("eff_qi")/25);
}else 
{
        victim->add("qi",-100);
        victim->add("eff_qi",-100);
}
        return HIB "�����ں�����!!����$NͻȻ����,����һ��ħ����$n��ը�÷�������!!\n" NOR;
	}
 	if( random(2)==1 && random(level) > 150)
	{
        if (userp(victim) && victim->query("jing") > 50
        && victim->query("eff_jing") > 50)
{
if (victim->query("jing")/20 > 20)
        victim->add("jing",-victim->query("jing")/20);
if (victim->query("eff_jing")/20 > 20)
        victim->add("eff_jing",-victim->query("eff_jing")/30);
}
else {
        victim->add("jing",-1000);
        victim->add("eff_jing",-1000);
}
        return HIW "�����ǹ�ʸ!!����$NͻȻ����,����һ��ħ����$n�����к����ͷʹ�ޱ�!!\n" NOR;
	}
if (damage_bonus < 100) damage_bonus=100;
        if( damage_bonus > 200 ) 
{
        victim->receive_wound("qi", damage_bonus );	
        victim->receive_wound("qi", damage_bonus );
        return HIR "��ȭ!!һ��ȭӰ������һ����Ѫ��$n���������\n" NOR;	
}
        if( damage_bonus < 120 ) 
{
        victim->receive_wound("qi", damage_bonus );	
        victim->receive_wound("qi", damage_bonus );	
        return YEL "ֱȭ!!һ��ȭӰ������$n�ƺ�һ��,���ӻ������Σ�\n" NOR;
}
else
{       
        victim->receive_wound("qi", damage_bonus );	
        victim->receive_wound("qi", damage_bonus );	
        return HIM "��ȭ!!һ��ȭӰ��������������������һ�����죬���Ͼ�����һЩѪ�Σ�\n" NOR;
}

}
int ob_hit(object ob, object me, int damage)
{
	object weapon = me->query_temp("weapon");
        string msg,dodge_skill,*limbs;
        int i, j, level, p, q;
        
        limbs = ob->query("limbs");
        level = me->query_skill("magic-unarmed", 1);

//        if( me->is_busy()) return 1;
        if( damage < 100 ) return 1;
        if (  random(level) > 150  && random(2) ==1   ){
         msg = RED"$N���$n�Ĺ��ơ�����һ����ͻȻʩ��ħ��!!!��\n"NOR;
            message_vision(msg, me, ob);
            if ( random(2) == 0 && random(level) > 150){
         msg = YEL"�� �ؾ�����! ����$NͻȻ����,����һ��ħ����$n�о��������ס���ܶ���!!��\n"NOR;
//             if (!ob->is_busy())
        if (userp(ob) && ob->query("qi") > 50 && ob->query("jing") > 50
        && ob->query("eff_qi") > 50 && ob->query("eff_jing") > 50){
             ob->start_busy(3+random(2));
if (ob->query("qi")/20 > 20)
             ob->add("qi",-ob->query("qi")/20);
if (ob->query("eff_qi")/20 > 20)
             ob->add("eff_qi",-ob->query("eff_qi")/30);
}
else
{
             ob->start_busy(3);
             ob->add("qi",-1000);
             ob->add("eff_qi",-1000);
}
msg += damage_msg(damage, "����");
            }
else  if (random(2)==1&& random(level) > 150){
         msg = HIR"��������!����$NͻȻ����,����һ��ħ����$n��һ�����������!!\n"NOR;
        if (userp(ob) && ob->query("qi") > 50 
        && ob->query("eff_qi") > 50)
{
if (ob->query("qi")/15 > 20)
             ob->add("qi",-ob->query("qi")/15);
if (ob->query("eff_qi")/15 > 20)
             ob->add("eff_qi",-ob->query("eff_qi")/25);
}
else {
             ob->add("qi",-2000);
             ob->add("eff_qi",-2000);
}
msg += damage_msg(damage, "����");
            }
else  if (random(2)==2&& random(level) > 150){
         msg = HIC"����������!����$NͻȻ����,����һ��ħ����$n��һ�����������!!\n"NOR;
        if (userp(ob) && ob->query("qi") > 50
        && ob->query("jing") > 50
        && ob->query("eff_qi") > 50
        && ob->query("eff_jing") > 50)
{
if (ob->query("qi")/30 > 20)
             ob->add("qi",-ob->query("qi")/30);
if (ob->query("eff_qi")/30 > 20)
             ob->add("eff_qi",-ob->query("eff_qi")/30);
if (ob->query("jing")/30 > 20)
             ob->add("jing",-ob->query("jing")/30);
if (ob->query("eff_jing")/30 > 20)
             ob->add("eff_jing",-ob->query("eff_jing")/30);
}
else
{
             ob->add("qi",-1000);
             ob->add("eff_qi",-1000);
             ob->add("jing",-1000);
             ob->add("eff_jing",-1000);
}
msg += damage_msg(damage, "����");
            }
else
           msg = HIG"$n���ȳ��У�ʹ$N������ʧ����!��\n"NOR;
            message_vision(msg, me, ob);
            return damage;
        }
}
