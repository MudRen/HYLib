#include <ansi.h>

#include <combat.h>
inherit F_SSERVER;

int perform(object me)
{
        string msg;
        object weapon, target;
        int skill, ap, dp, neili_wound, qi_wound;
        int i, attack_time;

        me->clean_up_enemy();
        target = me->select_opponent();

        skill = me->query_skill("xueshan-sword",1);

        if( !(me->is_fighting() ))
            return notify_fail("��"+HIW"��÷Ʈ��"NOR+"��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
            return notify_fail("��ʹ�õ��������ԡ�\n");

        if( skill < 80)
            return notify_fail("���ѩɽ������Ϊ����, ����ʹ�á�"+HIW"��÷Ʈ��"NOR+"����\n");  
        if( (int)me->query_skill("bingxue-xinfa",1) < 80 )
                return notify_fail("��ı�ѩ�ķ�����������ʹ�á�"+HIW"��÷Ʈ��"NOR+"����\n");

        if( me->query("neili") < 200 )
            return notify_fail("��������������޷����á�"+HIW"��÷Ʈ��"NOR+"����\n");

        msg = HIW 
    "$N��Хһ��,ʹ������÷Ʈ�㡹,���б�������,�������ѩ����ǰ����ǵص���ȥ��\n"
    "�ڰ�ãã��һƬ��,��Ȼ�������÷���ν���,��͸ѩĻ,������˷����������\n" NOR;
        message_combatd(msg, me, target);

        ap = random(me->query("combat_exp") + skill*5);
        dp = target->query("combat_exp")/2;
        if( dp < 1 )
            dp = 1;
        if( random(ap) > dp )
        {
            if(userp(me))
                 me->add("neili",-150); 
        msg = HIC 
    "����÷���⻪,�ó���������,��$nȫ�������ֵ�����ʵʵ��$n��������,\n"
    "ֻ����������,���Լ�����˿˿����,һʱȫ���ʹ,��Ѫ�ɽ��õ������ǡ���ͬ���֮��,\n"
    "�Ҳ����ԡ�\n" NOR; 
        COMBAT_D->report_status(target);
            qi_wound = (int)me->query_skill("xueshan-sword",1)+(int)me->query_skill("sword",1);
            qi_wound = qi_wound/2 + random(qi_wound);
            if(qi_wound > target->query("qi"))
                 qi_wound = target->query("qi");
if (qi_wound <50) qi_wound = 50;
            target->receive_damage("qi", qi_wound);
            target->receive_wound("qi", qi_wound/2);
            target->receive_damage("jing", qi_wound/3);
            target->receive_wound("jing", qi_wound/5);
target->apply_condition("cold_poison",50);
target->apply_condition("ill_shanghan",50);
target->apply_condition("ice_poison",50);
target->apply_condition("iceshock",50);
target->apply_condition("xuantian_han",50);
target->apply_condition("xuanming_poison",50);
            me->start_busy(2);
        }
        else
        {
            if(userp(me))
                 me->add("neili",-100);
            msg = "����$n��ݵ����Ա�һ�����ܹ�����һ����\n"NOR;
            me->start_busy(2);
        }
        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/4 ) {
         attack_time = random((int)me->query_skill("xueshan-sword", 1) / 30);
        if (attack_time > 9 ) attack_time=9;
        for(i = 0; i < attack_time; i++){
         msg = HIW "$N������ѩ���У�һ��÷�����˳�����\n" NOR;
       COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
                        }
        me->start_busy(2);
}
        message_combatd(msg, me, target);

        return 1;
}

