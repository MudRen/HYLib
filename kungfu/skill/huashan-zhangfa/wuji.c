// wuji.c �޼�
#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        string msg;
        int damage, hehe;
        object weapon = me->query("weapon");
        hehe = ((int)me->query_skill("hunyuan-zhang",1)/2+(int)me->query_skill("zixia-shengong",1)/2);
        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("��Ԫ�޼�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( objectp(me->query_temp("weapon")) )
                return notify_fail("�������ֲ���ʹ�û�Ԫ�޼���\n");  
                
if( (int)me->query_skill("huashan-zhangfa", 1) < 80 )
                return notify_fail("��Ļ�ɽ�Ʋ�����죬����ʹ�û�Ԫ�޼���\n");
                                
        if( (int)me->query_skill("zixia-shengong", 1) < 80 )
                return notify_fail("�����ϼ�񹦲����ߣ������ó���Ԫ�޼��˵С�\n");


        if( (int)me->query("neili") < 200 )
                return notify_fail("����������̫�����޷�ʹ����Ԫ�޼���\n");

  
        msg = HIR "$N������ϼ�񹦣����Ϸ��Ű�������ɫ��һ�ɻ�Ԫ����͵�������$n��ȥ��\n"NOR;

  if (random(me->query("combat_exp")) > target->query("combat_exp")/3 )
        {
                me->start_busy(2);
                target->start_busy(random(4));
                
                damage = (int)me->query_skill("huashan-zhangfa", 1);
                
                damage = damage/2 + random(damage);
                
                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage/2);
                me->add("neili", -damage/8);
                msg += RED"���$Nһ�����У�$nֻ�е�����һ��ů����ȫ��ɢȥ��ͻȻ�е�һ���������ܵ����ȡ�\n"NOR;
                target->apply_condition("hunyuan_hurt", 5);
        } else 
        {
                me->start_busy(2);
                  me->add("neili", - damage/10);
                msg += CYN"����$p������$P�����������������������㿪��$P������һ����\n"NOR;
        }
//        me->start_perform(3,"��Ԫ�޼�");
        message_vision(msg, me, target);
        return 1;
}
