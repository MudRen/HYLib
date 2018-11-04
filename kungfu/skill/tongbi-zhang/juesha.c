#include <ansi.h>

inherit F_SSERVER;
 
int perform(object me, object target)
{
        string msg;
        int ap, dp;
        int count;
        int i;
 
        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }


        if (! target || ! me->is_fighting(target))
                return notify_fail("������ɲ�ơ�ֻ����ս���жԶ���ʹ�á�\n");
 
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("������ɲ�ơ�ֻ�ܿ���ʹ�á�\n");
                
        if (me->query("max_neili") < 2200)
                return notify_fail("���������Ϊ���������޷�ʩչ������ɲ�ơ���\n");

        if ((int)me->query("neili") < 500)
                return notify_fail("�������������\n");

        if ((int)me->query_skill("tongbi-zhang", 1) < 280)
                return notify_fail("��ͨ�������Ʋ�����죬����ʩչ��\n");

        if ((int)me->query_skill("force") < 300)
                return notify_fail("����ڹ���Ϊ�������޷�ʹ�á�����ɲ�ơ���\n");

        if (me->query_skill_mapped("strike") != "tongbi-zhang")
                return notify_fail("��û�м���ͨ�������ƣ�����ʩչ������ɲ�ơ���\n");

        //if (me->query_skill_prepared("strike") != "tongbi-zhang")
        //        return notify_fail("������û��׼��ʹ��ͨ�������ƣ�����ʩչ������ɲ�ơ���\n");


        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIR "$N" HIR "һ��ŭ�ȣ���Ȼʩ�������Ʒ�������" NOR + WHT 
              "����ɲ��" NOR + HIR "����������������������ת��˫�۶�"
              "Ȼ\n�������ߡ�ֻ���ƿ�֮�����죬˫�ƻó�������Ӱ������"
              "�ǵ���$n" HIR "�����ĳ���\n\n" NOR;
        ap = me->query("combat_exp");
        dp = target->query("combat_exp");
        if (ap / 2 + random(ap) > dp)
        {
                ap = me->query_skill("tongbi-zhang");
                count = ap / 15;
                msg += RED "$n" RED "���$P" RED "����ɽ�������ƣ���ȫ"
                       "�޷��ֵ���Ψ���˺�\n" NOR;
        } else
        {
                msg += HIC "$n" HIC "����Ӧս���߾����ܻ���$P" HIC "��"
                       "���ơ�\n" NOR;
                count = 0;
        }

        message_vision(msg, me, target);
        me->add_temp("apply/attack", 80);

        me->add("neili", -300);
        me->add("qi", -100);    // Why I don't use receive_damage ?
                                // Becuase now I was use it as a cost
        for (i = 0; i < 7; i++)
        {
                if (! me->is_fighting(target))
                        break;
                if (random(5) < 2 && ! target->is_busy())
                        target->start_busy(2);

                COMBAT_D->do_attack(me, target, 0, 0);
        }

        me->start_busy(2);
        me->add_temp("apply/attack", -80);

        return 1;
}
