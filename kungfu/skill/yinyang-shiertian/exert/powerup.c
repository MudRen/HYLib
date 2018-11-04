#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
        int skill;

        if (target != me)
                return notify_fail("��ֻ��������ʮ�������������Լ���ս������\n");

        if ((int)me->query_temp("powerup"))
                return notify_fail("���Ѿ����˹����ˡ�\n");

        skill = me->query_skill("force");

        message_combatd(HIR "$N" HIR "˫Ŀ΢�գ����ھ�����������������תʮ�����죬��"
                        "ʱֻ��һ�������ޱȵ���������ȫ��\n" NOR, me);

        me->add_temp("apply/attack", 100);
        me->add_temp("apply/defense", 100);
        me->add_temp("apply/damage", 500);
        me->add_temp("apply/parry", 100);
        me->add_temp("apply/dodge", 100);
        me->add_temp("apply/armor", 500);
        me->set_temp("powerup", 1);

        me->start_call_out((: call_other, __FILE__, "remove_effect",
                              me, skill / 2 :), skill);

        if (me->is_fighting()) me->start_busy(3);

        return 1;
}

void remove_effect(object me, int amount)
{
        if (me->query_temp("powerup"))
        {
                me->add_temp("apply/attack", -100);
                me->add_temp("apply/defense", -100);
                me->add_temp("apply/damage", -500);
                me->add_temp("apply/parry", -100);
                me->add_temp("apply/dodge", -100);
                me->add_temp("apply/armor", -500);
                me->delete_temp("powerup");
                tell_object(me, HIW "�������ʮ������������ϣ��������ջص��\n" NOR);
        }
}
