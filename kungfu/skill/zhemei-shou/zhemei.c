// zhemei.c
// /kungfu/skill/zhemei-shou/
// Program by ying

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        object weapon;
        int damage;
        string msg;

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() )
                return notify_fail("��÷չֻ�ܶԶ���ʹ�á�\n");
       if( environment(me)->query("no_fight") )
                       return notify_fail("���ﲻ�ܹ�������! \n");
        if( (int)me->query_skill("zhemei-shou", 1) < 80 )
                return notify_fail("�����÷�ֲ�����죬����ʹ����÷չ��\n");
	if( !(me->is_fighting() ))
		return notify_fail("��÷��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( (int)me->query_skill("beiming-shengong", 1) < 120 && (int)me->query_skill("bahuang-gong", 1)<120 )
                return notify_fail("��ı����ڹ�������죬����ʹ����÷չ��\n");

        if( (int)me->query("neili", 1) < 350 || (int)me->query("max_neili",1)<200 )
                return notify_fail("����������̫��������ʹ����÷չ��\n");

        msg = HIC "$N�ַ�ͻȻ�ӿ죬Ѹ������$n��ץס$nһֻ�ֱۣ��������ۡ�\n"NOR;

        if( !target->is_fighting(me) ) me->kill_ob(target);

        if (random(me->query("combat_exp")) > target->query("combat_exp")/3 )
        {
                me->start_busy(3);

                damage = (int)me->query_skill("zhemei-shou", 1) + (int)me->query_skill("force",1);

                damage = damage/2 + random(damage/2 + 30) ;

                target->receive_damage("qi", damage );
		target->receive_damage("qi", damage );
                target->start_busy(6);
                me->add("neili", -200);

                msg += HIR"���$n���ֱ۱�$N���۵��޷�������ֻ��һ����ʹ���̡�\n"NOR;
		message_combatd(msg, me, target);
		COMBAT_D->report_status(target);
        }
        else
        {
                me->start_busy(2);
                msg += CYN"����$p����һ�����˿�ȥ��\n"NOR;
		message_combatd(msg, me, target);
		target->start_busy(1);
        }

        return 1;
}
