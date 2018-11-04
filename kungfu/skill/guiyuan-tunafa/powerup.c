// powerup.c �����޼�����
// Modified by Venus Oct.1997

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
    int skill;

    if( target != me )
        return notify_fail("��ֻ���ù�Ԫ���ɷ��������Լ���ս������\n");

    if( (int)me->query("neili") < 100  )
        return notify_fail("�������������\n");
    if( (int)me->query_temp("powerup") )
        return notify_fail("���Ѿ����˹����ˡ�\n");

    skill = me->query_skill("force");
    me->add("neili", -100);
    me->receive_damage("qi", 0);

    message_combatd(
HIC "$N΢һ���������Ԫ���ɷ���ȫ��ǽڷ���һ�󱬶�������졣\n" NOR, me);

    me->add_temp("apply/attack", skill/3);
    me->add_temp("apply/dodge", skill/4);
    me->set_temp("powerup", 1);

    me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill/5 :), skill);

    if( me->is_fighting() ) me->start_busy(3);

    return 1;
}

void remove_effect(object me, int amount)
{
   int skill;
   skill = me->query_skill("force");
   me->add_temp("apply/attack", -skill/3);
   me->add_temp("apply/dodge", -skill/4);
    me->delete_temp("powerup");
    tell_object(me, "��Ĺ�Ԫ���ɷ�������ϣ��������ջص��\n");
}

