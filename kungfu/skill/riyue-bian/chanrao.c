// chan.c ���±޷������ơ���

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        string msg;
        object weapon = me->query_temp("weapon");

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("ǣ�ƹ���ֻ�ܶ�ս���еĶ���ʹ�á�\n");

    if (!weapon || weapon->query("skill_type") != "whip"
    || me->query_skill_mapped("whip") != "riyue-bian")
        return notify_fail("�������޷�ʹ�á�ǣ�ƹ�������\n");

        if( (int)me->query_skill("yijinjing", 1) < 100 )
                return notify_fail("����׽�ڹ��ȼ�����������ʹ�á����ơ�����\n");

        if( (int)me->query_skill("riyue-bian", 1) < 120 )
                return notify_fail("������±޷�������죬����ʹ�á����ơ�����\n");

	if((int)me->query_skill("hunyuan-yiqi",1) < 100)
		return notify_fail("���Ԫһ�����Ĺ�������!\n");

        if (!weapon || weapon->query("skill_type") != "whip"
        || me->query_skill_mapped("whip") != "riyue-bian"
        || me->query_skill_mapped("parry") != "riyue-bian")
                return notify_fail("�������޷�ʹ��ǣ�ƹ�����\n");

        if( (int)me->query("neili") < 500 )
                return notify_fail("����������̫��������ʹ�á����ơ�����\n");

        if( target->is_busy() )
                return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɢ�\n");

        msg = HIY "$Nʹ�����±޷������ơ������������ޣ�ɢ�������������ͼ��$n��ȫ�����������\n";

        me->add("neili", -200);
        me->add("jing", - 40);
        me->start_busy(2);
        if(random(me->query("combat_exp")) > (int)target->query("combat_exp")/3 ) {
                msg += "���$p��$P���˸����ֲ�����\n" NOR;
                target->start_busy( (int)me->query_skill("riyue-bian") / 50 + 3);
//		me->start_perform(me->query_skill("riyue-bian") / 40 + 1, "����");
        } else {
                msg += "����$p������$P����ͼ����û���ϵ���\n" NOR;
                me->start_busy(3);
        }
        message_vision(msg, me, target);
        return 1;
}
