// jiedu.c ���嶾����
// By Kayin @ CuteRabbit Studio 99-4-16 15:19 new
#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target )
{
        string msg;

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() )
                return notify_fail("��Ҫ��˭�ⶾ��\n");

        if( (int)me->query_skill("yunu-xinfa", 1) < 40 )
                return notify_fail("�����Ů�ķ�������죬���ܽ��嶾���ơ�\n");

        if( (int)me->query_skill("wudu-shenzhang", 1) < 40 )
                return notify_fail("����嶾���Ʋ�����죬���ܽ��嶾���ơ�\n");

        if( (int)me->query("neili", 1) < 100 )
                return notify_fail("����������̫�������ܽⶾ��\n");
                
        if( target->query_condition("wuduz_poison")< 1)
        	return notify_fail("��û���ж���\n");
if (!userp(target))
	return notify_fail("�Է����������ҽ�ơ�\n");

if (!userp(me))
	return notify_fail("�Է����������ҽ�ơ�\n");
        me->add("neili", -300);
        target->apply_condition("wuduz_poison", 0);
        msg = HIW "$Nʹ���嶾���ƽⶾ���ַ�Ϊ$n���á����Ÿ�$n����һ����ҩ.\n"NOR;

        message_vision(msg, me, target);
        return 1;
}
