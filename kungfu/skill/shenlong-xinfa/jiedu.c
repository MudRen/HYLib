// jiedu.c ���嶾����
// By Kayin @ CuteRabbit Studio 99-4-16 15:19 new
#include <ansi.h>

inherit F_SSERVER;
int exert(object me, object target)
{
        string msg;

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() )
                return notify_fail("��Ҫ��˭�ⶾ��\n");

        if( (int)me->query_skill("shenlong-xinfa", 1) < 90 )
                return notify_fail("��������ķ�������죬���ܽⶾ��\n");

if (!userp(target))
	return notify_fail("�Է����������ҽ�ơ�\n");

if (!userp(me))
	return notify_fail("�Է����������ҽ�ơ�\n");
        if( (int)me->query("neili", 1) < 500 )
                return notify_fail("����������̫�������ܽⶾ��\n");
        if( me->is_fighting() )
        return notify_fail("����æ���أ�\n");
        if( me->is_busy() )
        return notify_fail("����æ���أ�\n");                
        me->add("neili", -300);
me->start_busy(5);
        target->apply_condition("snake_poison", 0);
        target->apply_condition("ill_fashao",0);
        target->apply_condition("ill_kesou",0);
        target->apply_condition("ill_shanghan",0);
        target->apply_condition("ill_zhongshu",0);
        target->apply_condition("ill_dongshang",0);
        target->apply_condition("wugong_poison", 0);
        target->apply_condition("chanchu_poison", 0);
        target->apply_condition("xiezi_poison", 0);
        target->apply_condition("snake_poison", 0);
        target->apply_condition("zhizhu_poison", 0);
        msg = HIW "$Nʹ�������ķ��ⶾ���ַ�Ϊ$n���á����Ÿ�$n����һ����ҩ.\n"NOR;

        message_vision(msg, me, target);
        return 1;
}
