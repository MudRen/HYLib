 //mimicat@fy4
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int begin_perform(object me,object target,int count,int extra);
int perform(object me, object target)
{
        string msg;
        int extra; 
        extra = me->query_skill("enmeiryu",1);
        if(extra<100) return notify_fail("��½��Բ����ȭ������Ϊ�������޷�ʹ���ϵ������ŵľ��С�\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail( "ֻ�ܿ���ʩչ��\n");
	if( (int)me->query("neili") < 300 )
		return notify_fail("�������������\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�ϵ�������ֻ�ܶ�ս���еĶ���ʹ�á�\n");  
        extra = me->query_skill("enmeiryu",1) / 3; 
        message_vision(HIY"$NͻȻһЦ��������$n����ǰһ�Σ�Ծ����һ�ࡣ$nһʱ�޷�����$N����Ӱ�� 
���ϵ������ţ��� \n",me,target);
        begin_perform(me,target,4,extra);
        me->add("neili",-100);
        return 1;
        
}      
string *perform_msg=({
        HIY"$N�����ڵ���һ�ţ����岻��˼����ٴε���˫�ŵ���$n��ϥ�ؽڡ�\n"NOR,
        HIY"$N��������֮�ƣ��ٴ�ת������Ѹ�ײ����ڶ�֮�ƣ�ɨ��$n�ľ�����\n"NOR,
        HIY"$N�߸�Ծ�𣬿���һ��š������Ȼ�Խ������͵���$n��ͷ��ն��������\n"NOR,
        HIY"$N�͵شӲ���Ծ��$n������$n��֪����֮ʱ��һ����������$n�����š�\n"NOR,
        }); 
int begin_perform(object me,object target,int count,int extra)
{
        string msg;
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target)
        ||environment(target)!=environment(me)          )
                return 0;
if (random(2)==0)                 target->start_busy(3);
        if(count)
        {
                msg=perform_msg[--count];       
//         me->stop_busy();
                me->add_temp("apply/attack", extra);    
                me->add_temp("apply/damage", extra);            

                COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
                me->add_temp("apply/attack", -extra);
                me->add_temp("apply/damage", -extra);
                begin_perform(me,target,count,extra);
        }
        else
                me->start_busy(3); 
        return 1;
} 
