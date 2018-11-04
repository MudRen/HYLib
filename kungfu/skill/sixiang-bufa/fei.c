#include <ansi.h>

#define FEI "��" HIY "��������" NOR "��"

inherit F_SSERVER;



void remove_effect(object me, int amount, int amount1);

int perform(object me, object target)
{
        object weapon;  
        string msg;
        int count, cnt, skill;



        if ((int)me->query_temp("fei_tian"))
                return notify_fail("���Ѿ�����" FEI "�ˡ�\n");

        if ((int)me->query_skill("sixiang-bufa", 1) < 150)
                return notify_fail("������󲽷��ȼ�����������ʩչ" FEI "��\n");

        if ((int)me->query_dex() < 33)
                return notify_fail("���������������ʩչ" FEI "��\n");

        if ((int)me->query_skill("force", 1) < 150)
                return notify_fail("����ڹ���򲻹�������ʩչ" FEI "��\n");

        if ((int)me->query_skill("dodge", 1) < 150)
                return notify_fail("����Ṧ��Ϊ����������ʩչ" FEI "��\n");

        if ((int)me->query("max_neili") < 1000)
                return notify_fail("���������Ϊ����������ʩչ" FEI "��\n");

        if ((int)me->query("neili") < 250)
                return notify_fail("���ʱ���������㣬����ʩչ" FEI "��\n");

        msg = HIY "$N" HIY "��������棬���Ծ�����ζ�ʱ���Ʈ������������׽����\n\n" NOR;
        
        message_combatd(msg, me, target);
        skill = me->query_skill("sixiang-bufa", 1);
        cnt = (int)((int)me->query_condition("drunk") / 3);

        count = skill / 50;

        if (me->is_fighting())
                me->start_busy(2);

        me->add_temp("dex", count);
        me->add_temp("apply/dodge", count);
        me->add_temp("apply/defense", count);
        me->set_temp("fei_tian", 1);
        me->start_call_out((: call_other,  __FILE__, "remove_effect", me, count :), skill / 2);

        me->add("neili", -200);
        return 1;
}

void remove_effect(object me, int amount, int amount1)
{
        if ((int)me->query_temp("fei_tian"))
        {
                me->add_temp("dex", -amount);
                me->add_temp("apply/dodge", -amount);
                me->add_temp("apply/defense", -amount);
                me->delete_temp("fei_tian");
                tell_object(me, "���" FEI "������ϣ��������ջص��\n");
        }
}

