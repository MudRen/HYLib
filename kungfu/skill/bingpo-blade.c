// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
inherit SKILL;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});



string *action_msg = ({
        "$N�ḧ���е�$w��ͻȻ��ֻ������һ����"+(order[random(13)])+"����������һ����"NOR"�������̹ǵĺ�����ȻϮ����$n��$l",
        "ֻ��$N����$w��"+(order[random(13)])+"�����μ��塹"NOR"��������$n����֮�ʣ�ͻȻ����һ����$n����б������",
        "$Nб����𣬴���һƬƥ��Ҳ�Ƶ�"+(order[random(13)])+"�����⡹"NOR"����$n��$l",
        "$NͻȻһ���߳������е�$w����һ��"+(order[random(13)])+"�������Բ����"NOR"�������ĵ����ס��$n��ͷ�����ж���$n�ĺ���",
        "ֻ��$N��ɫһ����һ��"+(order[random(13)])+"��ǧ����⡹"NOR"ʹ������ü�ݵ��Ÿ���\n$n�����ѪҺ���Ʊ����޾��ĵ��ƶ�ס��������Ҳ�·�Ҫ�����ȥ",
        "$N���ƽ�������$w�ϴ����ĺ���ȴԽ��ԽŨ��������ʱ��\n$n����ͷһ����"+(order[random(13)])+"��һ������⻹Ҫ�����ĺ�����"NOR"�Ѵ�����$n$l",
        "$NҲ�������߶�ʮһ���߾�$w�����ؾ���һ����$n"+(order[random(13)])+"��ӭ��ն�£���"NOR"\n��Ȼֻ��һ�������µĵ���ȴ����Ų����ĺ���������$n��һ����·",
});


int valid_learn(object me)
{
        object ob;

        if ((int)me->query("max_neili") < 100)
                return notify_fail("�������������û�а취�����Ǻ���������Щ���������ɡ�\n");
	if ((int)me->query_skill("huagong-dafa", 1) < 125)
		return notify_fail("��Ļ����󷨻�򲻹�.\n");

	if ((int)me->query_skill("sanyin-wugongzhao", 1) < 120)
		return notify_fail("����������צ��򲻹�.\n");



	if ((int)me->query_skill("chousui-zhang", 1) < 120)
		return notify_fail("��ĳ����ƻ�򲻹�.\n");


	if ((int)me->query_skill("tianshan-zhang", 1) < 120)
		return notify_fail("�����ɽ�ȷ���򲻹�.\n");


	if ((int)me->query_skill("zhaixinggong", 1) < 120)
		return notify_fail("���ժ�ǹ���򲻹�.\n");
		
	if ((int)me->query_skill("chanhun-suo", 1) < 120)
		return notify_fail("��Ĳ�������򲻹�.\n");


	if ((int)me->query_skill("xuantian-strike", 1) < 180)
		return notify_fail("�����������ƻ�򲻹�.\n");

		
        if (! (ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "blade"
        )
                return notify_fail("���������һ�ѱ����ĵ����������Ǻ�����\n");

        return 1;
}

int valid_enable(string usage)
{
        return usage == "blade" || usage == "parry";
}

mapping query_action(object me, object weapon)
{
        return ([ 
                "action": action_msg[random(sizeof(action_msg))], 
                "damage": 180 + random(230), 
                "attack": 80 + random(10),
                "dodge" : 80 + random(10),
                "parry" : 80 + random(10),
                "damage_type" : random(2) ? "����" : "����", 
        ]);
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 110
            ||  (int)me->query("neili") < 110)
                return notify_fail("�����������������û�а취��ϰ���Ǻ�����\n");
                
        me->receive_damage("qi", 100);
        me->add("neili", -100);
        write("�㰴����ѧ����һ����Ǻ�����\n");
        return 1;
}

int valid_effect(object me, object weapon, string name, int skill)
{
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        object weapon = me->query_temp("weapon");     
        string msg;
        int lvl;
        int flvl;

        lvl  = me->query_skill("bingpo-blade", 1);
        flvl = me->query("jiali");
        if (lvl < 100 || ! damage_bonus ||
            me->query_skill_mapped("force") != "huagong-dafa" ||
            me->query("neili") < 300)
                return;
        if (random(5)==0)
        {
if (victim->query("neili") > 1500)
victim->add("neili",-600);
                return HIY "$n" HIY "�е�������ѩ���ڻ�һ������ʧ�ˡ���\n" NOR;
        }
else
        if (random(5)==0)
        {
if (victim->query("qi") > 500)
victim->add("qi",-250);
victim->add("eff_qi",-(50+random(200)));
victim->apply_condition("xx_poison",20);
victim->apply_condition("x2_sandu",20);
victim->apply_condition("sanpoison",20);
                return HIY "$n" HIY "�е��������Ƹ���һ�㣬ɢ����һ�ɼ���"
               "�ŵĶ������\n" NOR;
        }       


        if (((int)me->query_skill("blade", 1)/2) > random((int)victim->query_skill("force", 1)))
        {
                victim->receive_wound("qi", (300-damage_bonus)+60);
                msg = HIW "$NĬ�������������Ǻ����к����Ƴ���$nһ�����죬�ѱ����ˣ�\n\n"NOR;
                message_combatd(msg, me, victim);
             
        }
        //if (random(2)==0) return;
        
        switch(random(3)) {
        case 0:
                victim->receive_damage("qi",damage_bonus/3*2+50);
                msg = HIW"ֻ��һ˿����������Ϣ���굽$n���ڣ�\n"NOR;
                break;
                                
        case 1:  
                victim->receive_damage("qi",damage_bonus/2+30);
                msg = HIW"$N��ʹ��������$n���˿�������һ��ǳǳ�İ�ӡ��\n"NOR;
                break;
                                
        case 2:
                victim->receive_damage("qi",damage_bonus+20);
                msg = HIW"$nͻȻ���������溮����...\n"NOR;
                break;      
        }
               
        return msg;                    
}
string perform_action_file(string action)
{
        return __DIR__"bingpo-blade/" + action;

}



int ob_hit(object ob, object me, int damage)
{
        object wp1,weapon;
        string msg;
        int p,j,skill, neili, neili1;
        int level,level2,damage2;
        level = (int) me->query_skill("huagong-dafa",1);
        level2= (int) me->query_skill("bingpo-blade",1);
        neili = me->query("neili");
        neili1 = ob->query("neili");
damage2= (int) ob->query("neili",1)/7;
if (damage2>= 5000) damage2 = 5000;
if (random(8)==0 && level>=300 && me->query_skill_mapped("force") == "huagong-dafa")
{
if (ob->query("neili") >= damage2)
{
ob->add("neili",-damage2);
if (!ob->is_busy())	ob->start_busy(1);
}
msg = HIY"$Nʹ��������,$n��������ѩ���ڻ�һ������ʧ�ˡ���\n"NOR;

           message_vision(msg, me, ob);
           return j;
}       

weapon = me->query_temp("weapon");
if (weapon)
{
        if (  level2 > 150
        && random(5)==1
        && (string)weapon->query("skill_type") == "blade"){
 
            msg = HIC"$n����ʱ��$N����һ�� �˷��ص�ʽ��$n�޷�����Ҳ�޷�����!!\n"NOR;
   if (!ob->is_busy())
             ob->start_busy(3);
message_vision(msg, me, ob);
               }


}



}