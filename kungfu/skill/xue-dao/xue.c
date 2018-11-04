#include <ansi.h>
#include <combat.h>

#define XUE "��" HIR "��Ѫ��" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
	object weapon;
	string msg;
        int ap, dp, damage;



        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! target || ! me->is_fighting(target))
                return notify_fail(XUE "ֻ�ܶ�ս���еĶ���ʹ�á�\n");
 
        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "blade")
                return notify_fail("��ʹ�õ��������ԣ�����ʩչ" XUE "��\n");

        if ((int)me->query_skill("force") < 220)
                return notify_fail("����ڹ���򲻹�������ʩչ" XUE "��\n");

        if ((int)me->query_skill("xue-dao", 1) < 160)
                return notify_fail("���Ѫ���󷨻������ң�����ʩչ" XUE "��\n");



        if (me->query_skill_mapped("blade") != "xue-dao")
                return notify_fail("��û�м���Ѫ����Ϊ����������ʩչ" XUE "��\n");

        if ((int)me->query("qi") < 100)
                return notify_fail("��Ŀǰ��Ѫ����������ʩչ" XUE "��\n");

        if ((int)me->query("neili") < 200)
                return notify_fail("��Ŀǰ�������㣬����ʩչ" XUE "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        ap = me->query_skill("blade");
        dp = target->query_skill("parry");

        msg = HIR "$N" HIR "�ӵ������һ�գ�Ѫ���ʱ�������棬�������ұ�"
              "�ճ�һƬѪ����$n" HIR "��ͷ���䡣\n" NOR;

        if (ap / 2 + random(ap) > dp)
        {
                damage = ap + random(ap / 2);
                me->add("neili", -150);
                me->start_busy(2);
   target->add("qi",-damage*2);
		target->add("eff_qi",-damage*2);
                msg += HIR "$n" HIR "ֻ��Ѫ����������ǰһ��Ѫ"
                                           "�죬����������£���Ѫ�ɽ�����������"
                                           "�󺿣�\n" NOR;
        } else
        {
                me->start_busy(2);
                msg += CYN "����$n" CYN "������ã����Ų�æ�������$N"
                       CYN "�ı�ɱһ����\n"NOR;
                me->add("neili", -100);
        }
        me->receive_wound("qi", 50);
        message_combatd(msg, me, target);
        return 1;
}
