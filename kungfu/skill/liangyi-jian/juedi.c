// juedi.c ���ط���
// 1997.9.2   csy

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        int damage;
        string msg;

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
        return notify_fail("���ط���ֻ�ܶ�ս���еĶ���ʹ�á�\n");

                
    if( (int)me->query_skill("liangyi-jian",1)<180)
    return notify_fail("��������ǽ���������죬����ʹ�á����ط�������\n");
     if( (int)me->query_skill("xuantian-wuji",1)<80)
        return notify_fail("��������޼���������񣬲���ʹ�á����ط�������\n"); 
                        
    if( (int)me->query("neili",1)<500)
    return notify_fail("����������̫��������ʹ�á����ط�������\n");
 if (random(2)==0) target->start_busy(2);
    if( (int)me->query_skill("art", 1) > 120 )
    {
    msg = HIC"$n��������ƫ�󣬼�������ת����ֻ��һɲ������ɲʱϮ�����ף�"NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
    msg = HIG"$n��������ƫ�ң���������ת����ֻ��һɲ������ɲʱϮ�����ף�"NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
    msg = HIY"$n��������ƫ�ϣ���������ת����ֻ��һɲ������ɲʱϮ������"NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
    msg = HIR"$n��������ƫ�£���������ת����ֻ��һɲ������ɲʱϮ������"NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->add("neili", -200);
    }
                        
 msg=HIY "$N�����޷��Զ���ʹ�����������ǽ����е���ɽ���������ط�������\n"
HIG "ɲ�Ǽ����ذ�����ɳ��ʯ��������Ӱ��$n��ȫ��Ҫ����̣��򿳣�������ȥ��\n" NOR;

        if (random(me->query("neili")) > target->query("neili")/3 )
{
        me->start_busy(2);
                target->start_busy(random(4));
                
    damage= (int)me->query_skill("liangyi-jian",1);
         damage = damage + random(damage);
                
        target->receive_damage("qi",random(damage)+200);
        target->receive_wound("qi",damage*2+200);
        me->add("neili",-damage/5);
        if( damage < 20 ) msg += HIY"���$n��$N������һ�����ƺ�һ����\n"NOR;
else
if( damage < 55 ) msg += HIY"���$n��$N������������������һ������������\n"NOR;
else if( damage < 80 ) msg += RED"���$n��$N���ص����������������ܵ������׻�һ�㣬��������������\n"NOR;
else msg += HIR"���$n��$N�ġ����ط�������͸ǰ�ģ���ǰһ�ڣ��������ɳ�������\n"NOR;
}
else
{
         me->start_busy(2);
                msg += CYN"����$p������$P����ͼ����û���ϵ���\n"NOR;
}
        message_vision(msg, me, target);

        return 1;
}


