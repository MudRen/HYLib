// zhen.c ̫��ȭ�����־�
// snowman
#include <ansi.h>

inherit F_SSERVER;

#include "/kungfu/skill/eff_msg.h";
string *taiji_msg = ({"ʮ����","����Ʊ�","������","Ұ�����","б����","����","����","��ͨ��"});

int perform(object me, object target)
{
        int damage, p, force;
        float at;
        string msg;

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) || !living(target) )
                return notify_fail("�����ֻ�ܶ�ս���еĶ���ʹ�á�\n");

//        if(!me->query_temp("taiji"))
//                return notify_fail("̫��ȭ���������ⲻ�ϣ���û�����á�̫�������������ʹ�á����־���\n");
        if( (int)me->query("neili", 1) < 1000 )
                return notify_fail("����������������ǿ��ʹ�á����־�ֻ���˵����Լ���\n");                   
        if( me->query_temp("weapon"))
                return notify_fail("���ȷ������е�������˵�ɣ���\n");                   
          
        msg = CYN "\nͻȻ��$Nһ�С�"+taiji_msg[random(sizeof(taiji_msg))]+"����˫������������һ��ԲȦ�ѽ�$n��ס��̫��ȭ��"RED"����"CYN"�־��漴ʹ����\n"NOR;
        
        force = me->query_skill("force") + target->query_skill("force");

        if(random(me->query_skill("force")) > target->query_skill("force")/2){
                if(me->query("neili") < target->query("neili")){
                       me->start_busy(3);
                       if(!target->is_busy()) target->start_busy(3); 
                       me->add("jing", -force/10);
                       me->add("neili", -force/2);
                       target->add("jing", -force/10);
                       target->add("neili", -force/2);
                       msg += HIY"ֻ����ž����һ����$p��$P����������ƴ�������������˼�����\n"NOR;
                       message_vision(msg, me, target);
                       return 1;
                       }
                me->start_busy(3);
                if(!target->is_busy()) target->start_busy(2+random(3));
                
                damage = (int)me->query_skill("force")*2;                
                at = me->query("neili") / (target->query("neili")+1);
                if(at < 1){
                    if(at < 0.5) damage /= 2;
                    damage /= 2;
                    }
                else damage *= at;
                if(damage> 3000) damage = 3000; 
                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage/4);
                if(target->query("neili") >= damage/4) target->add("neili", -(damage/4));
                else target->set("neili", 0);

                me->add("neili", -(damage/4));
                me->add("jing", -50);
                if(damage > 1000)
                   msg += "̫��֮�����಻�ϣ�������ȥ�пգ�һ��ԲȦδ�꣬�ڶ���ԲȦ����������һ�죬$pһ����ͷ���ʶϣ�\n";
                if(damage > 2000)
                   msg += "$N���������������־�ʹ��ʱ���಻�ϣ����ſ�����������$pȫ�������ͷҲ��һһ�ʶϣ�\n";
                p = (int)target->query("qi")*100/(int)target->query("max_qi");
                msg += damage_msg(damage, "����");
                msg += "( $n"+eff_status_msg(p)+" )\n";       
                } 
        else{
                me->start_busy(3);
                me->add("jing", -25);
                me->add("neili", -300);
                msg += HIY"$pһ�����ԣ�����һ�󼱹���$P��ʱ��æ���ң���Ҳ���������У�\n"NOR;
             }
        message_vision(msg, me, target);
        return 1;
}
