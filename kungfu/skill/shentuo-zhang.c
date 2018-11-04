// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// shentuo-zhang ����ѩɽ��

#include <ansi.h>
inherit SKILL;

string *action_msg = ({
        "$N˫��һ�棬ʹ��һ�С�������������������ת������Ʈ��������$n��$l",
        "$N�������һ���������ƣ��������ͣ�ʹ��һʽ����Į���������$n��$l",
        "$N���ȷ��������������ף��������޵�����$n��$l������һ�С����տ��㡹",
        "$N���η�����һʽ�������˪������Ӱ�׷ɣ������ھ��Ѱ�$n������ͳͳ��ס",
        "$N���μ�ת�������һ�С����ճ�������ͷ�½��ϣ�ɲ�Ǽ��ֽ��빥������$n��$l",
        "$N����һ����ʹ��һʽ��ѩ��ǧɽ��������������ŭ����ӿ����������$n��$l",
"$Nһʽ�����߳�������������Σ���������ͻȻ����$n�ı����Ѩ",
"$N����һ�Σ�һʽ����ͷ��β������������$n�ļ�ͷ����ȭ����$n���ؿ�",
"$Nһʽ���������㡹�����ֻ�£��צ��һ���־����$n���ʺ�Ҫ��",
"$N�������У�����ֱ����һʽ��������Ӱ������Ʈ��������$n������",
"$Nʹһʽ��������ܡ�����ȭ�ϸ�����̽��ͻ����ץ��$n���ɲ�",
"$Nһʽ���������񡹣�ʮָ����������ʵʵ��Ϯ��$n��ȫ��ҪѨ",
"$N˫�ֱ�ȭ��һʽ��������ӿ������Ӱ���ɣ�ͬʱ��$nʩ���žŰ�ʮһ��",
"$Nһʽ���������š���ȭ���������֣��������ޣ�����������$n�ĵ���",
});


int valid_enable(string usage) { return usage == "strike" ||  usage == "parry"; }

 int valid_combine(string combo) { return combo == "shexing-diaoshou"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("������ѩɽ�Ʊ�����֡�\n");

        if ((int)me->query_skill("hamagong",1) < 15)
                return notify_fail("��ĸ�󡹦��򲻹����޷�ѧ����ѩɽ�ơ�\n");

        if ((int)me->query("max_neili") < 50)
                return notify_fail("�������̫�����޷�������ѩɽ�ơ�\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
        return ([
                "action": action_msg[random(sizeof(action_msg))], 
                "force": 320 + random(60), 
                "attack": 50 + random(10), 
                "dodge" : 50 + random(10), 
                "parry" : 50 + random(10), 
                	"damage" : 150 + random(150), 
                "damage_type" : random(2)?"����":"����", 
        ]); 
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 60)
                return notify_fail("�������̫���ˡ�\n");
        if ((int)me->query("neili") < 60)
                return notify_fail("�����������������ѩɽ�ơ�\n");
        me->receive_damage("qi", 50);
        me->add("neili", -50);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"shentuo-zhang/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int lvl;
        int flvl;
	int level, jiali, time,level2,damage,damage2;
	object weapon;
object target;
target=victim;
        level = (int) me->query_skill("hamagong",1);
        level2= (int) me->query_skill("hamagong",1);
damage2= (int) victim->query("neili",1)/8;





        if(  me->query("jiali") > me->query_skill("force") 
          && me->query_skill_mapped("force") == "hamagong") 

if (damage_bonus <10) damage_bonus=10;
      if( random(me->query_skill("shentuo-zhang",1)) > 150  || random(8)==0) 
{
	  victim->receive_wound("qi", damage_bonus/2+30);
        return HIR "$N����������ŭ����ӿ����������$n��$n���ؿ��߹Ǿ�Ȼ���˼�����\n" NOR;
}


if (damage2>= 3800) damage2 = 3800;
	
if (random(8)==0 && level>=300 && me->query_skill_mapped("force") == "hamagong")
{
	target->apply_condition("snake_poison",5);
	target->apply_condition("chanchu_poison",5);
	target->apply_condition("qx_snake_poison",3);
if (!target->is_busy()) target->start_busy(2);
	
 return HIR "$N��ת����������һ�䣬һ�ڶ�������$n�³�!$nͷһ�裬��֪���� ��\n";
}
	if( damage_bonus < 100 ) return 0;



if (me->query_temp("hmg_dzjm") && random(4)>2 )
{
        victim->receive_damage("qi", damage_bonus/2);
        victim->receive_wound("qi", damage_bonus/2);
 return HIR "$N��ת��������$n�ſ�һҧ!$n�˿�һ������Ѫ�����\n";
}
	if( damage_bonus/2 > victim->query_str() || random(5)==0 ) {
if(me->query_skill("hamagong", 1)>100)
{
if (me->query_skill_mapped("force") == "hamagong"
&& !me->query_temp("weapon"))
{
		victim->receive_wound("qi", (damage_bonus ) / 2 );
		return HIM " "+ victim->name()+"��Ϣδ�����־�һ�ɾ����������,�³���һ�����Ѫ��\n" NOR;
}
}
	}
}

