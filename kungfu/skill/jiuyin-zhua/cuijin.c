// cuijin.c  �����׹�צ���ݽ��ƹǡ�
#include <ansi.h>
inherit F_SSERVER;
int perform(object me, object target)
{
    int damage;
    string msg;
    if( !target ) target = offensive_target(me);
    if( !target || !target->is_character() || !me->is_fighting(target) )         return notify_fail("���ݽ��ƹǡ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
    if( (int)me->query_skill("jiuyin-zhua", 1) < 180 )
    return notify_fail(WHT"��ľ����׹�צ������죬��ʹ�������ݽ��ƹǡ���\n"NOR);
    if( (int)me->query_skill("force", 1) < 180 )
    return notify_fail(RED"����ڹ��ķ���򲻹���ʹ�á��ݽ��ƹǡ��������Լ��ľ�����\n"NOR);
    if( (int)me->query("neili") < 800 )
    return notify_fail("�����������ˡ�\n");
    msg = HIC "$Nһ����Х������$n��ת��Ȧ������ʩչ�����ݽ��ƹǡ���˫צ�����ֱ��$nǰ�ء�\n"NOR;
    if (random(me->query("combat_exp")) > target->query("combat_exp"))
{
    if (me->query("neili") > target->query("neili"))
{
    me->start_busy(3);
    damage = target->query("max_qi");
    target->receive_damage("qi", damage/2);
    target->receive_wound("qi", damage/2);                         
    me->add("neili", -400);
    msg += HIR"$N����$nǰ��������������������ָ����$nֻ���ؿھ�ʹ����Ѫ�������������\n"NOR;
} 
else 
{
    me->start_busy(3);
    damage = target->query("max_qi");
    target->receive_damage("qi", damage/20);
    target->receive_wound("qi", damage/20);                         
    me->add("neili", -400);
    msg += HIY"$Nֻ��$n�������˫צ�����ܹ��ض���,ֻ��$n��ǰ������һ��Ѫ�ۣ�����\n"NOR;
} 
} 
    else
{
    me->start_busy(3);
    me->add("neili", -300);
    msg += HIY"����$p���з��������Ų�æ,ж����$P��˫צ��\n"NOR;
}
    message_combatd(msg, me, target);
    if(userp(target))
me->fight_ob(target);
    else if( !target->is_killing(me) )
me->kill_ob(target);
    return 1;
}