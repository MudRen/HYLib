#include <ansi.h>
#include <combat.h>

#define DAN "��" HIM "������" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        int damage;
        string msg;



        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(DAN "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (objectp(me->query_temp("weapon")))
                return notify_fail("�������ֲ���ʹ��" DAN "��\n");         
                
        if ((int)me->query_skill("tianchang-strike", 1) < 40)
                return notify_fail("����Ʒ�������죬����ʩչ" DAN "��\n");

        if (me->query("max_neili") < 200)
                return notify_fail("����ڹ���Ϊ���㣬����ʩչ" DAN "��\n");

        if (me->query_skill_mapped("strike") != "tianchang-strike")
                return notify_fail("��û�м����쳥�Ʒ�������ʩչ" DAN "��\n");

        if (me->query_skill_prepared("strike") != "tianchang-strike")
                return notify_fail("��û��׼���쳥�Ʒ�������ʩչ" DAN "��\n");

        if (me->query("neili") < 50)
                return notify_fail("����������̫��������ʩչ" DAN "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIM "$N" HIM "������������������һ�������ƾ����£���׼$n"
              HIM "ƽƽ�ĳ���\n" NOR;
        me->add("neili", -30);

        if (random(me->query_skill("force")) > target->query_skill("force") / 2)
        {
                me->start_busy(3);
                target->start_busy(random(3));
                
                damage = (int)me->query_skill("force", 1);
                damage = damage / 2 + random(damage)+120;
                		target->add("qi",-damage);
		target->add("eff_qi",-damage/2);
                me->add("neili", -150);
		msg +=                     HIR "$n" HIR "������æ���һ�ݣ���ȴֻ��"
                                           "�ؿ�һ�𣬶�ʱ�����������ѱ�$N" HIR "��"
                                           "�����ˣ�\n" NOR;                

        } else 
        {
                me->start_busy(3);
                msg += CYN "����$p" CYN "������$P"
                       CYN "����ͼ����û���ϵ���\n" NOR;
        }
        message_combatd(msg, me, target);
        return 1;
}

