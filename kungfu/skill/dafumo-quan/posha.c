#include <ansi.h>
inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;
        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("��ɷֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( (int)me->query_skill("dafumo-quan", 1) < 200 )
                return notify_fail("��Ĵ��ħȭ������죬�޷�ʹ����ɷ��\n");
        if( (int)me->query_skill("jiuyin-zhengong", 1) < 200 )
                return notify_fail("��ľ����湦������죬�޷�ʹ����ɷ��\n");

        if ( (int)me->query("max_neili") < 6000)
                return notify_fail("��������������޷�ʹ����ɷ��\n");

        if ( (int)me->query("neili") < 10000)
                return notify_fail("��������������޷�ʹ����ɷ��\n");

        msg = HIY"$NͻȻ�۾�һ��������һ������ʹ��ȫ���������ȭ��$n��ȥ��\n";
        me->start_perform(10,"��ɷ");
	if (userp(target))
{
	if (	random(me->query("combat_exp")) > target->query("combat_exp")/3	)
{
                msg += HIR"$n��������������С����$nֻ����һ��ǿ���ľ������������Լ���������\n";
                msg += HIR"$nֻ���õ������絶���Ϣֱ����������\n"NOR;
                target->add("max_neili",-(random(me->query_skill("dafumo-quan",1)/20)+5));
                target->set("neili",0);
                target->set("jiali",0);
                me->set("neili", 0);
                me->set("jiali", 0);
        } 
        else {
                msg += HIG"$n���������ң���æ����һ�ԡ�\n" NOR;
        }
        message_vision(msg, me, target);
        me->start_busy(3+random(3));
}else
{
        if( random(me->query("combat_exp")) > target->query("combat_exp")/3 ) {
                msg += HIR"$n��������������С����$nֻ����һ��ǿ���ľ������������Լ���������\n";
                msg += HIR"$nֻ���õ������絶���Ϣֱ����������\n"NOR;
                target->add("max_neili",-(random(me->query_skill("dafumo-quan",1)/20)+5));
                target->set("neili",0);
                target->set("jiali",0);
                me->set("neili", 0);
                me->set("jiali", 0);
        } 
        else {
                msg += HIG"$n���������ң���æ����һ�ԡ�\n" NOR;
        }
        message_vision(msg, me, target);
        me->start_busy(3+random(3));
}
        return 1;
}

