#include <ansi.h>
#include <combat.h>

#define DONG "��" HIG "�󽭶�ȥ" NOR "��"

inherit F_SSERVER;


int perform(object me, object target)
{
        object weapon;
        int damage;
        int ap, dp;
        string wp, msg;



        
        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(DONG "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon"))
           || (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԣ�����ʩչ" DONG "��\n");

        if ((int)me->query_skill("force") < 150)
                return notify_fail("����ڹ���򲻹�������ʩչ" DONG "��\n");

        wp = weapon->name();

        if ((int)me->query_skill("xuantie-sword", 1) < 200)
                return notify_fail("�����������������죬����ʩչ" DONG "��\n");



        if ((int)me->query("neili") < 800)
                return notify_fail("�����ڵ��������㣬����ʩչ" DONG "��\n");

        if (me->query_skill_mapped("sword") != "xuantie-sword")
                return notify_fail("��û�м�����������������ʩչ" DONG "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIW "$N" HIW "�������񣬶�ʱһ��������������ȱŷ������ŵ�"
              "��һ������" + wp + HIW "\n�漴��վ����������Χ��ɳ����"
              "����ʩ��������������" HIG "�󽭶�ȥ" HIW "����\n"NOR;

        me->start_busy(2);

        ap = me->query_skill("sword") + me->query_str() * 2;
        dp = target->query_skill("force") + target->query_str() * 2;

        if (me->query("shen")>= 10000 )
                ap += ap / 5;
                
        if (ap / 2 + random(ap) > dp)
        {
                target->start_busy(1);
                damage = me->query_skill("sword")*2;
                me->add("neili", -600);
       target->add("qi",-damage);
		target->add("eff_qi",-damage);
                msg += HIR "���$n" HIR "�����мܣ�ȴ��$N" HIR
                                           "��һ����ķ��𣬿�����Ѫ���²�ֹ��\n" NOR;

        } else
        {
                msg += CYN "����$n" CYN "������$N"
                       CYN "����ͼ����æбԾ�ܿ���\n"NOR;
                me->add("neili", -300);
        }
        message_combatd(msg, me, target);

        return 1;
}
