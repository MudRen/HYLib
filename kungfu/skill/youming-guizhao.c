// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// youming-guizhao.c ��ڤ��צ

#include <ansi.h>
inherit SKILL;

string *action_msg = ({
        "$N��צǰ�죬����˿˿����������һʽ��Ԫ����ϡ����͵���$n�Ķ��Ų���",
        "$N˫�����ģ�����һ����ǽ����$n����Ȼһצ�����ȴ��ġ�������ǽֱ��$n��$l",
        "$Nʹ����Ѫ������˫צ����$n��ס$l��������������������һ������Ҫ��$n�����Ƭ",
        "$N˫צ£ס$n��ʹһʽ�����������������ڹ���צ��͸��$n���ڣ�ֱϮ����ؽ�",
        "$N��͸ָ�⣬��$n����ʵʵ��ץʮ��צ��������Ϯ�塹��������������ס$n",
        "$Nһʽ���������֡�����צ���·����γ�����צӰ���ұ�һ�죬���Ȱ�ץ��$n��$l",
        "$N̽����ǰ��˳��$n���ֱ���Եֱ�ϣ�����Ϊצ��һ�С��»�Ԧħ��ץ��$n��$l",
        "$N��շ��䣬һצͻǰ����ħצ���¡�����ȫ������ָ�⣬����ޱȵز���$n",
});

int valid_enable(string usage) { return usage == "claw" || usage == "parry"; }

int valid_learn(object me)
{
       if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
               return notify_fail("��צ��������֡�\n");
       if ((int)me->query_skill("claw", 1) < 50)
               return notify_fail("��Ļ���צ����򲻹����޷�ѧϰ��\n");

       if ((int)me->query_skill("pidi-shenzhen", 1) < 50)
               return notify_fail("��ıٵ������򲻹����޷�ѧϰ��\n");
       if ((int)me->query_skill("wudoumi-shengong", 1) < 50)
               return notify_fail("����嶷���񹦻�򲻹����޷�ѧϰ��\n");
       if ((int)me->query_skill("zhougong-jian", 1) < 50)
               return notify_fail("����ܹ�����򲻹����޷�ѧϰ��\n");
       if ((int)me->query_skill("wuliang-jian", 1) < 50)
               return notify_fail("�������������򲻹����޷�ѧϰ��\n");                                             

       if ((int)me->query("max_neili") < 1000)
               return notify_fail("�������̫�����޷�����ڤ��צ��\n");
       return 1;
}

mapping query_action(object me, object weapon)
{
        return ([
                "action": action_msg[random(sizeof(action_msg))],
                "force" : 320 + random(60),
                "attack": 70 + random(10),
                "dodge" : 70 + random(10),
                "parry" : 70 + random(10),
                "damage" : 370 + random(10),	
                "damage_type" : "ץ��",
        ]);
}

int practice_skill(object me)
{
        if ((int)me->query_skill("youming-guizhao", 1) < 199 )
                return notify_fail("�����ڤ��צ��Ϊ������ֻ����ѧ(learn)�������������ȡ�\n");
                
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("����ڤ��צ������֡�\n");
                
        if ((int)me->query("qi") < 80)
                return notify_fail("�������̫���ˡ�\n");
        
        if ((int)me->query("neili") < 80)
                return notify_fail("���������������ڤ��צ��\n");
                
        me->receive_damage("qi", 70);
        me->add("neili", -70);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"youming-guizhao/" + action;
}
int valid_combine(string combo) { return combo=="liuyang-zhang"; }

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{                
      int lvl;
        int flvl;
	int level, jiali, time,level2,damage,damage2;
	object weapon;
	weapon = me->query_temp("weapon");
        level = (int) me->query_skill("beiming-shengong",1);
        level2= (int) me->query_skill("beiming-shengong",1);

damage2= (int) victim->query("neili",1)/8;
if (damage2>= 3800) damage2 = 3800;
	
if (random(8)==0 && level>=300 && me->query_skill_mapped("force") == "beiming-shengong")
{

if (victim->query("neili") >= damage2)
{
victim->add("neili",-damage2);
me->add("neili",damage2);
}
	return HIW"$NͻȻʹ����ڤ��,$nȫ����������ˮ��ԴԴ����������$N������!\n"NOR;
}
        lvl  = me->query_skill("beiming-shengong", 1);
        if (lvl==0)
        lvl  = me->query_skill("bahuang-gong", 1);
        flvl = me->query("jiali");
if (me->query_skill_mapped("force") != "bahuang-gong" &&
me->query_skill_mapped("force") != "beiming-shengong")
                return;
        if (lvl < 80 || ! damage_bonus ||
            me->query("neili") < 300)
                return;
flvl=random(lvl)+50;
        if (random(5)==0)
        {
if (victim->query("qi") > flvl)
{
victim->add("qi",-flvl);
victim->add("eff_qi",-flvl);
victim->apply_condition("ss_poison", 10 +
		victim->query_condition("ss_poison"));
}
                return HIW "$n" HIW "�������˼���������!!\n" NOR;
        }
        else if (random(4)==0)
        {
if (victim->query("neili") > 1500)
victim->add("neili",-300);
if (me->query("neili") < me->query("max_neili"))
victim->add("neili",(random(lvl)+50));

return HIC "$n" HIC "ȫ��������ˮ��ԴԴ����������$N�����壡\n" NOR;
        }

        if( damage_bonus < 30 ) return 0;

        if( random(3)==0 ) {
                victim->add("qi", -damage_bonus*2+30);
                victim->receive_wound("qi", (damage_bonus ) / 2+30 );
                return HIR "$n���˿ڱ�$N��͸ָ���һץ�������ڹ���צ͸�룡\n";
        }
        if (me->query_temp("lingjiu/youming") 
        &&  ! me->query_temp("youming_hit")) 
        {
                me->set_temp("youming_hit", 1);
                me->set_temp("apply/name", ({ me->query("name") + "�Ĺ�Ӱ" }));
                COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), 1);       
                me->delete_temp("apply/name");
                me->delete_temp("youming_hit");
        }
}

