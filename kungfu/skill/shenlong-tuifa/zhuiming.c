// zhuiming.c    ����׷����
// 98.9.18  by Aug    99.9.11 changed by aug

#include <ansi.h>

inherit F_SSERVER;

#define TICKTIME 5

void exam1(object me , object tartget );
int perform(object me, object target)
{
        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character()|| !me->is_fighting(target) )
                return notify_fail("������׷���ȡ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( (int)me->query_skill("shenlong-tuifa", 1) < 150 )
                return notify_fail("��������ȷ�������죬����ʹ�á�����׷���ȡ���\n");

        if( (int)me->query_skill("shenlong-xinfa", 1) < 150 )
                return notify_fail("��������ķ�������񣬲���ʹ�á�����׷���ȡ���\n");

        if( (int)me->query("neili") < 1000)
                return notify_fail("����������̫��������ʹ������׷���ȡ�\n");

        if ( me->query_temp("weapon")) 
                return notify_fail("�����ű����޷�ʹ������׷���ȡ�\n");


        if ( (int)me->query_temp("zhuiming/time") > 0)
                return notify_fail("������ʹ������׷�����ء�\n");

        if( me->query_skill_mapped("force") != "shenlong-xinfa")
                return notify_fail("��������ʹ�õ��ڹ�ͬ�����ķ���ִ�������ʹ�á�����׷���ȡ���\n");

//      me->start_busy(TICKTIME);
        me->add("neili" , -200);
        me->add("jing" , -80);
        me->set_temp("zhuiming/time",time());
        me->set_temp("zhuiming/target",target);
        me->set_temp("zhuiming/dodge",me->query_skill("dodge", 1)/5);
        me->set_temp("no_fight", 1);
        me->add_temp("apply/dodge",me->query_skill("dodge", 1)/5);
//        me->apply_condition("no_perform", 100);
        message_vision(HIY+"\n$N"+HIY+"��Ȼ��Хһ����˫�ȷɿ�����л�λ��ȴ����һ�ȣ��ƺ��ڻ���������ʹ��������������׷���ȣ�\n\n"NOR,me);
                
        call_out("exam1",TICKTIME,me,target);

        return 1;
}

void exam1(object me , object target )
{
        string str;     
        int  times;

        if (!me) return;
        times = time()- me->query_temp("zhuiming/time",1);
        if( me->query_skill_mapped("leg") != "shenlong-tuifa"
         || me->query_skill_prepared("leg") != "shenlong-tuifa"){
                me->add_temp("apply/dodge",-me->query_temp("zhuiming/dodge"));
//                me->clear_condition("no_perform");
                me->delete_temp("zhuiming");
                me->delete_temp("no_fight");
                me->start_perform(3,"������׷���ȡ�");
                tell_object(me,"��������������ȷ�������������׷���ȡ�Ҳ�Զ������\n");
                return;
        }
        if( target 
         && me->is_fighting(target)
         && (times < 38)
         && me->query_temp("zhuiming")){
                str = HIY+"\n$N"+HIY+"�Ѿ�����"+CHINESE_D->chinese_number(times)+"���ӣ�$N˫�ȿ��ٵ��ƶ�����һ���Ż������ƺ��ڽ��¾ۼ���һ��";
                if( times < 10)  str +="СС�����š�"NOR;
                  else if( times < 20) str +="�������������š�"NOR;
                      else if( times < 30) str +="���ڲ��ϱ��Ĵ����ţ�"NOR;
                         else str +="��ʾ�ű��˷�â�ľ޴����ţ�"NOR;
                message_vision(str+"\n",me);
                message_vision(HIY+"\n$N"+HIR+"��ɿ칥�����ȡ�\n"NOR,me);
me->add_temp("apply/attack",100);
me->add_temp("apply/damage",200);
		COMBAT_D->do_attack(me, target,0, 1); 
		COMBAT_D->do_attack(me, target,0, 1); 		
me->add_temp("apply/attack",-100);
me->add_temp("apply/damage",-200);
//              me->start_busy(TICKTIME);
                call_out("exam1",TICKTIME,me,target);
        }
        else {
                message_vision(HIY+"\n$N"+HIY+"�����ջؾۼ���������\n"NOR,me);
                me->add_temp("apply/dodge",-me->query_temp("zhuiming/dodge"));
//                me->clear_condition("no_perform");
                me->delete_temp("zhuiming");
                me->delete_temp("no_fight");
                me->start_perform(3,"������׷���ȡ�");
        }
}
