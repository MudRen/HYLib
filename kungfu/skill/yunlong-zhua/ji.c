// ji.c ����

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        mapping prepare;
        string msg;
        int skill;
        int delta;
        int i;

        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }


        if (! me->is_fighting(target))
                return notify_fail("�����硹ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (me->query_skill_prepared("claw") != "yunlong-zhua")
                return notify_fail("��û��׼��ʹ����Ѫ��צ���޷�ʩչ�����硹��\n");

        skill = me->query_skill("yunlong-zhua", 1);
 	if( (int)me->query_skill("yunlong-shengong", 1) < 150 )
		return notify_fail("��������񹦲����ߡ�\n");
        if (skill < 250)
                return notify_fail("�����Ѫ��צ��Ϊ���ޣ��޷�ʹ�á����硹��\n");

        if (me->query_skill("force") < 250)
                return notify_fail("����ڹ���򲻹�������ʩչ�����硹��\n");

        if (me->query("max_neili") < 2000)
                return notify_fail("���������Ϊû�дﵽ�Ǹ����磬�޷���ת�����γɡ����硹��\n");

        if (me->query("neili",1) < 500)
                return notify_fail("������������������޷�ʩչ�����硹��\n");

        if (me->query_temp("weapon"))
                return notify_fail("������ǿ��ֲ���ʩչ�����硹��\n");

       if (! living(target))
              return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIR "$N" HIR "����һ����Х������Ծ��˫צ�ó�����צӰ�����ƻֺ룬\n���缲��һ������$n" HIR "����ҪѨ��\n" NOR;

        message_combatd(msg, me, target);

        me->add("neili", -300);
        target->add_temp("apply/attack", 60);
        target->add_temp("apply/dodge", 60);
        for (i = 0; i < 7; i++)
        {
                if (! me->is_fighting(target))
                        break;
                if (random(3) == 1 && ! target->is_busy())
                        target->start_busy(1);
                COMBAT_D->do_attack(me, target, 0, 0);
        }
        target->add_temp("apply/attack", -60);
        target->add_temp("apply/dodge", -60);
        me->start_busy(2);

        return 1;
}


