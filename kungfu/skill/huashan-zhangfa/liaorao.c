// pfm �������� liaorao 
#include <ansi.h>
inherit F_SSERVER;
int perform(object me, object target)
{
        string msg;
        if( !target ) target = offensive_target(me);
        if( !target
         || !target->is_character()
         || !me->is_fighting(target))
           return notify_fail("ǣ�ƹ���ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        if((int)me->query_dex() < 25)
           return notify_fail("���������,����ʹ���������ƾ���!\n");
         if( (int)me->query_skill("huashan-zhangfa", 1) < 80 )
                return notify_fail("��Ļ�ɽ�Ʋ�����죬����ʹ�û�Ԫ�޼���\n");
                                
        if( (int)me->query_skill("zixia-shengong", 1) < 80 )
                return notify_fail("�����ϼ�񹦲����ߣ������ó���Ԫ�޼��˵С�\n");
        if((int)me->query("max_neili") < 400)
           return notify_fail("���������Ϊ��Ƿ���\n");  
        if((int)me->query("neili") < 300)
           return notify_fail("���������ڲ���, ����ʹ���������ƾ���! \n");
        if( target->is_busy() )
           return notify_fail( target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɢ�\n");
        msg = HIM"\n$N���΢Ц��Ŀ��б�ӣ�������������ˮ�����б���������������б��������������ƣ�\n"+
                 "һ�������������ס��$n��ȫ��ҪѨ��\n"NOR;
        if( random(me->query("combat_exp")) > (int)target->query("combat_exp") / 2 ){
           msg +=  HIY"���$pֻ����ǰһ���������ƣ���$P���Ƶ���ҪѨ! \n"NOR;
           target->start_busy((int)me->query_skill("huashan-zhangfa",1) / 50 + 3);
           me->add("neili",-100);
           me->add("jing",-10);
           }
           else{
           msg += HIC"$p��ɫһ�䣬���һ������һ�ݣ�$P������գ�����Ϊ֮һ�͡�\n"NOR; 
           me->add("neili",-100);
           me->add("jing",-10);
           me->start_busy(2);
           }
           message_vision(msg, me, target);
           return 1;
}

