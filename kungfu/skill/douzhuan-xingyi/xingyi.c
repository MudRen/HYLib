// xingyi.c ��ת����perform���ƶ�ת

#include <ansi.h>

inherit F_SSERVER;

#include "/kungfu/skill/eff_msg.h";

int perform(object me, object target)
{
        int damage, p;
        string msg;
        object weapon;

        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("���ƶ�תֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( (int)me->query_skill("douzhuan-xingyi", 1) < 120 )
                return notify_fail("������ƶ�ת��δ���ɣ�����ʹ�ã�\n");

        if( (int)me->query("max_neili") < 1200 )
                return notify_fail("������������Ϊ����������ʹ�����ƶ�ת��\n");     
        if( (int)me->query("neili") < 600 )
                return notify_fail("�������������㣬����ʹ�����ƶ�ת��\n");
        if( (int)me->query_skill("parry", 1) < 120 )
                return notify_fail("��Ļ����м�֮��������죬����ʹ�����ƶ�ת��\n");

        if (me->query_skill_mapped("parry") != "douzhuan-xingyi")
                return notify_fail("�������޷�ʹ�����ƶ�ת��\n");                                                                                 
                       
        msg = HIY "\n��Ȼ���ذ���$Nʹ��$n�ľ��У������������ڼ�������$n��ȥ��\n"NOR;
        if(me->query("neili") < random(target->query("neili"))){
           me->start_busy(3);
           target->start_busy(3); 
           me->add("neili", -200);
           me->add("jing", -20);
           target->add("jingli", -50);
           target->add("neili", -200);
           msg += HIY"���$p��$P��������һƴ��˫����ûռ��˿���ô���\n"NOR;
           message_vision(msg, me, target);
           return 1;
           }
        if( weapon = target->query_temp("weapon") ){
          if( random(me->query_str()) > target->query_str()/2 ) {
            me->start_busy(1);
            me->add("neili", -150);
            me->add("jing", -20);
     damage = (int)me->query_skill("shenyuan-gong", 1);
         damage = random(damage)+100;                
                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage/3);   

            msg += HIR"\n$pֻ����ȫ���ܵ������𵴣����İ��ʹ��һ����Ѫ���������"
                +target->query_temp("weapon")->query("name")+HIR"׹�ض�����\n"NOR;
            message_vision(msg, me, target);
                (target->query_temp("weapon"))->move(environment(target));
            } 
          else {
            me->start_busy(2);
            me->add("jing", -25);
            me->add("neili", -60);
            msg += "$p��ôҲ�벻��$N�ܹ�ʹ���Լ��ĳ���������Σ��֮��˫�Űϵض��𣬼��ѵĶ����һ�У���ɫ��Ĳ԰ס�\n";
            message_vision(msg, me, target);
            }        
         }
        else
        {
        if (random(me->query_skill("parry")) > target->query_skill("parry")/3)
            {
                me->start_busy(2);
                target->start_busy(random(3));
                
                me->add("jing", -50);
                damage = (int)me->query_skill("shenyuan-gong", 1);
				damage = (int)me->query_skill("douzhuan-xingyi", 1) +damage;
                damage = damage + random(damage);                
                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage/2);   
				me->add("neili", -(damage/3));             
                p = (int)target->query("qi")*100/(int)target->query("max_qi");
                msg += damage_msg(damage, "����");
                msg += "( $n"+eff_status_msg(p)+" )\n";                       
        } else 
           {
             me->start_busy(2);
             me->add("jing", -25);
             me->add("neili", -180);
             msg += CYN"\n$p��ôҲ�벻��$N�ܹ�ʹ���Լ��ĳ���������Σ��֮��˫�Űϵض��𣬼��ѵĶ����һ�У���ɫ��Ĳ԰ס�\n" NOR;
          }
        message_vision(msg, me, target);

        }
        return 1;
}
