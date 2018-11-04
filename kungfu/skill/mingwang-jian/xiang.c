#include <ansi.h>
#include <combat.h>

#define XIANG "��" HIY "��ħ" NOR "��"

inherit F_SSERVER;


int perform(object me, object target)
{
        object weapon;
        string msg;
        int ap, dp;
        int damage;



        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(XIANG "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԣ�����ʩչ" XIANG "��\n");

        if ((int)me->query_skill("mingwang-jian", 1) < 140)
                return notify_fail("�㲻��������������죬����ʩչ" XIANG "��\n");

        if (me->query_skill_mapped("sword") != "mingwang-jian")
                return notify_fail("��û�м�������������������ʩչ" XIANG "��\n");

        if (me->query("neili") < 200)
                return notify_fail("�����ڵ��������㣬����ʩչ" XIANG "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIY "$N" HIY "����Ծ���գ���ȫ��������" + weapon->name() +
              HIY "�У������ʱ�³�һ�ɽ���ֱָ$n" HIY "��ȥ��\n" NOR;

        ap = me->query_skill("sword"); 
        dp = target->query_skill("parry");              

        if (ap / 2 + random(ap) > dp)
        {
                damage = me->query_skill("sword");
                me->add("neili", -150);
                me->start_busy(2);
   target->add("qi",-damage*3);
		target->add("eff_qi",-damage);
                msg += HIR "$n" HIR "ֻ��һ����â������΢����"
                                           "�죬��ʱֻ��ȫ��һ�飬������͸�ض�����"
                                           "\n" NOR;
        } else
        {
                me->add("neili", -50);
                me->start_busy(3);
                msg += CYN "����$n" CYN "һ����Ц������һԾ���𣬱ܿ�"
                       CYN "$N" CYN "�����Ľ�����\n"NOR;
        }
        message_combatd(msg, me, target);

        return 1;
}

