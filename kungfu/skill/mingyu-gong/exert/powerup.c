// powerup.c ���񹦼���

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
        int skill;

        if (target != me)
                return notify_fail("��ֻ���������������Լ���ս������\n");

        if ((int)me->query("neili") < 100)
                return notify_fail("�������������\n");

        if ((int)me->query_temp("powerup"))
                return notify_fail("���Ѿ����˹����ˡ�\n");

        skill = me->query_skill("force")/2;
        me->add("neili", -100);
        me->receive_damage("qi", 0);

        message_combatd(HIR "$N" HIR "������������ȫ��Ƥ��˲���þ�Ө�ޱȣ��⻬�쳣��������\n"
                        "��ʥ�������ַ���ɢ���������Ĳ��ĺ�����\n" NOR, me);
if (skill >200) skill=200;

        me->add_temp("apply/attack", skill * 2 / 5);
        me->add_temp("apply/parry", skill / 3);
        me->add_temp("apply/dodge", skill / 3);
        me->set_temp("powerup", 1);

        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill :), skill);

        if (me->is_fighting()) me->start_busy(3);

        return 1;
}

void remove_effect(object me, int amount)
{
        if ((int)me->query_temp("powerup"))
        {
                me->add_temp("apply/attack", - (amount * 2 / 5));
                me->add_temp("apply/parry", - (amount / 3));
                me->add_temp("apply/dodge", - (amount / 3));
                me->delete_temp("powerup");
                tell_object(me, "�������������ϣ��������ջص��\n");
        }
}

