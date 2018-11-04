// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>

inherit SKILL;

string *action_msg = ({
        HIR"$NԾ�����ɣ����ڰ�գ���ʽ���䣬��̫���������羪�κ��ˣ���ת�������"NOR,
        YEL"$N��ʽһ�䣬ɱ���Ĳ���չ������������ȥ�޻ص�ɱ�С�̫�ŷ���˵���ԡ�"NOR,
        GRN"$N���б�Ӱէ�ţ��������ص�⣬��̫�ſ��족��Ȼ��ɨ��"NOR,
        HIC"$N��߳һ����˫�ֲ��٣����ⶸ�ɣ���ʱ�˱޺�һ�����ֱ��$n��ȥ"NOR,
        "$N�����������Ӷ�$w��ʹ��һ�С��󺣳�ɳ��������$w������$n��$l��ȥ��ȥ���䲻������\n�����Ƴ��ͣ���ͬѹ�˼�ǧ����ɳһ��",
        "$N�ֳ�$w���룬һ�С�����һ�ߡ���$wһ�˶�Ȼһ��������$nǰ�أ�������������$n��·��ס��\n��һ�������߳��������پ���$n����",
        "$N���һ��������������ʹ��һ�С������ſա������Ƽӿ죬ֻ��ʮ���ر�Ӱ�羪�Ϻ��˰���$n��$l�������",
        "$N����ת������$w��һʽ�������޲���������$wȥ������������˿���ƿ�֮����\n������֮���������$w�����������ѹε�����������",
        "$N�������߲���������ʹ��һ�С��׺�һ�ڡ���$w�Ϸ���������ɲ�Ǽ���ʮ����Ӱ������˷���$n����Ҫ������",
        "$N��Хһ����˫Ŀ�����ʢ��һ�С�ŭ�����Ρ�������չ�������ɨֱ����������������̼��ѽ�$nȫ���ס",
});

int valid_enable(string usage) { return usage == "whip" || usage == "parry"; }

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 50)
                return notify_fail("�������������\n");
                
        if ((int)me->query_skill("bibo-shengong", 1) < 120)
                return notify_fail("��ı̲��񹦻��̫ǳ��\n");
        if ((int)me->query_skill("anying-fuxiang", 1) < 120)
                return notify_fail("��İ�Ӱ������̫ǳ��\n");
        if ((int)me->query_skill("lanhua-shou", 1) < 120)
                return notify_fail("���������Ѩ�ֻ��̫ǳ��\n");
        if ((int)me->query_skill("luoying-shenjian", 1) < 120)
                return notify_fail("�����Ӣ�񽣻��̫ǳ��\n");
        if ((int)me->query_skill("luoying-zhang", 1) < 120)
                return notify_fail("�����Ӣ���ƻ��̫ǳ��\n");
        if ((int)me->query_skill("tanzhi-shentong", 1) < 120)
                return notify_fail("��ĵ�ָ��ͨ���̫ǳ��\n");
        if ((int)me->query_skill("xuanfeng-leg", 1) < 120)
                return notify_fail("�������ɨҶ�Ȼ��̫ǳ��\n");
        if ((int)me->query_skill("yuxiao-jian", 1) < 120)
                return notify_fail("������｣�����̫ǳ��\n");
       if ((int)me->query_skill("count", 1) < 120)
                return notify_fail("����������Ի��̫ǳ��\n");
       if ((int)me->query_skill("qimen-wuxing", 1) < 120)
                return notify_fail("����������л��̫ǳ��\n");

        return 1; 
}

mapping query_action(object me, object weapon)
{
        return ([
                "action": action_msg[random(sizeof(action_msg))],
                "damage": 110 + random(310),
                "attack": 50 + random(30),
                "dodge" : 50 + random(30),
                "parry" : 50 + random(30),
                "force" : 150 + random(310),	
                "damage_type" : random(2)?"����":"����", 
        ]);
}

int practice_skill(object me)
{
        object weapon, where;
        
        where = environment(me);
          if ((int)me->query_skill("anying-fuxiang", 1) < 120)
                return notify_fail("��İ�Ӱ������̫ǳ��\n");
        if ((int)me->query_skill("lanhua-shou", 1) < 120)
                return notify_fail("���������Ѩ�ֻ��̫ǳ��\n");
        if ((int)me->query_skill("luoying-shenjian", 1) < 120)
                return notify_fail("�����Ӣ�񽣻��̫ǳ��\n");
        if ((int)me->query_skill("luoying-zhang", 1) < 120)
                return notify_fail("�����Ӣ���ƻ��̫ǳ��\n");
        if ((int)me->query_skill("tanzhi-shentong", 1) < 120)
                return notify_fail("��ĵ�ָ��ͨ���̫ǳ��\n");
        if ((int)me->query_skill("xuanfeng-leg", 1) < 120)
                return notify_fail("�������ɨҶ�Ȼ��̫ǳ��\n");
        if ((int)me->query_skill("yuxiao-jian", 1) < 120)
                return notify_fail("������｣�����̫ǳ��\n");
       if ((int)me->query_skill("count", 1) < 120)
                return notify_fail("����������Ի��̫ǳ��\n");
       if ((int)me->query_skill("qimen-wuxing", 1) < 120)
                return notify_fail("����������л��̫ǳ��\n");      
              
        if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "whip")
                return notify_fail("��ʹ�õ��������ԡ�\n");
        if ((int)me->query("qi") < 60)
                return notify_fail("����������������˱޷���\n");

        if ((int)me->query("neili") < 160)
                return notify_fail("����������������˱޷���\n");


        message_vision(HIC"$N��Ժ���������ӱޣ�ʹ�����뺣��ͬ���������о���������Ҳ�纣������һ�������޾���\n"NOR, me);
        me->add("neili", 30);
        me->recieve_damage("qi", 50);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"canglang-bian/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
       string msg;
       int j, k;
 int level;
       j = me->query_skill("yuxiao-jian", 1);
       k = me->query_skill("qimen-wuxing",1);
 level = (int) me->query_skill("bibo-shengong",1);
if (random(6)==0 && level>=300 && me->query_skill_mapped("force") == "bibo-shengong")
        {
if (victim->query("qi") > 600)
victim->add("qi",-250+random(200));
victim->add("eff_qi",-(50+random(200)));
                me->add("neili", -20);
if (!victim->is_busy()) victim->start_busy(1);
return HIR "$Nʩչ����������,$n����һ��,������$l�������Ѫ��!!\n";
        }
	if( random(damage_bonus/2) > victim->query_str() ) {
		victim->receive_wound("qi", (damage_bonus - 10) / 2+30 );
		return HIB "$N����ӱޣ�ʹ�����뺣��ͬ����������$wȦת�纣������һ�������޾�Ȧ�� $nȫ��! \n" NOR;
	}
}