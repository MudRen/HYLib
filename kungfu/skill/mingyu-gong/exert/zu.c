// zu.c  by sinb

#include <ansi.h>

inherit F_CLEAN_UP;

int exert(object me, object target)
{
        int skill;

        if (target != me)
                return notify_fail("��ֻ�������񹦻ָ��Լ�����Ѫ��\n");

        if ((int)me->query("neili") < 1000)
                return notify_fail("�������������");

        if ((int)me->query_skill("mingyu-gong", 1) < 160)
                return notify_fail("������񹦵ȼ�������\n");
         if((int)me->query_skill("bingxue-xinfa",1) < 150)
                return notify_fail("��ı�ѩ�ķ���Ϊ������\n"); 
        if ((int)me->query_temp("qizu"))
                return notify_fail("���Ѿ����˹����ˡ�\n");

        skill = me->query_skill("mingyu-gong");

        me->add("neili", -100);

        message_combatd(HIC "$N" HIC "�������㡹�湦��"
                        "��������һƬ��â���漴�ָ�����\n" NOR, me);

        me->set_temp("qizu", 1);

        me->apply_condition("mingyu_qizu", skill / 80);
        if (me->is_fighting()) me->start_busy(3);

        return 1;
}

