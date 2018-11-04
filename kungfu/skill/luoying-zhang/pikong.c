// pikong.c By Darken
// Modified by Numa@Sj 99-11-12 2:46

inherit F_SSERVER;
#include <ansi.h>
#include "/kungfu/skill/eff_msg.h"

int perform(object me, object target)
{
        object ob;
        int damage, p;
        string msg;
        if( !target ) target = offensive_target(me);        
        if( !target
         || !target->is_character()
         || !me->is_fighting(target) )
                return notify_fail("�����ƾ���ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        if(!objectp(ob = present(target, environment(me))))
                return notify_fail("����û��������������ˡ�\n");
        if(ob==me)
                return notify_fail("�㲻�ܹ����Լ���\n");

        if( me->query_temp("weapon"))
                return notify_fail("������������ô��ʹ�������ƣ�\n");   
        if( environment(me)->query("no_fight") )
                return notify_fail("���ﲻ��ս����\n");
        if( (int)me->query_skill("qimen-wuxing", 1) < 60 )
                return notify_fail("������Ű��Բ�����죬�޷�ʩչ���������\n");
        if ((int)me->query_skill("bibo-shengong", 1) < 60)
                return notify_fail("��ı̲���������򲻹����޷�ʩչ���������\n");
        if( (int)me->query_skill("luoying-zhang",1) < 120 )
                return notify_fail("����Ʒ���Ϊ���㣬ʹ���������ơ�\n");
        if( (int)me->query("neili") < 1000 )
                return notify_fail("����������̫�������ܴ�������ơ�\n");
        msg = HIB "$N��Хһ����һʽ��������$n������Ю����������ӿ�ı̺��������������ⲻ�ɵ���\n"NOR;
        if (random(me->query("combat_exp")) > target->query("combat_exp")/3 )
        {
                me->start_busy(2);
                damage = (int)me->query_skill("bibo-shengong", 1) + (int)me->query_skill("luoying-zhang", 1);
                damage = damage*3+random(damage/2);
if (damage > target->query("qi")/2)
damage=(int)target->query("qi")/2;
                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage);
                p = (int)target->query("qi")*100/(int)target->query("max_qi");
                me->add("neili", -damage/3);
                msg += HIG"$n�����������һײ�����ܴ��˳����������Ѫ���磬������ͬ���߷��ݰ�ɳ���\n"NOR;
                msg += "( $n"+eff_status_msg(p)+" )\n"; 
        }
        else {
                me->start_busy(1);
                me->add("qi",-150);
                msg += CYN"$n���������ң���æ����һ�ã�$N��һ�Ʊ㼴��ա�\n"NOR;
        }
        message_vision(msg, me, target);
        me->start_perform(1,"������");
        return 1;
}
