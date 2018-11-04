#include <ansi.h>
#include <combat.h>

#define CHI "��" HIR "������" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
	object weapon;
	string msg;
	int count;
        int i;


        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! target || ! me->is_fighting(target))
                return notify_fail(CHI "ֻ�ܶ�ս���еĶ���ʹ�á�\n");
 
        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "blade")
                return notify_fail("��ʹ�õ��������ԣ�����ʩչ" CHI "��\n");

        if ((int)me->query_skill("force") < 220)
                return notify_fail("����ڹ���򲻹�������ʩչ" CHI "��\n");

        if ((int)me->query_skill("xue-dao", 1) < 160)
                return notify_fail("���Ѫ���󷨻������ң�����ʩչ" CHI "��\n");

        if (me->query_skill_mapped("force") != "xue-dao")
                return notify_fail("��û�м���Ѫ����Ϊ�ڹ�������ʩչ" CHI "��\n");

        if (me->query_skill_mapped("blade") != "xue-dao")
                return notify_fail("��û�м���Ѫ����Ϊ����������ʩչ" CHI "��\n");

        if ((int)me->query("neili") < 300)
                return notify_fail("�����������������ʩչ" CHI "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIW "$N" HIW "��Ŀ��ȣ�����" + weapon->name() + HIW "һ�ơ�"
              HIR "������" HIW "���ų�����Ѫ�⣬����ǵ�����$n" HIW "��\n" NOR;

        if (random(me->query_skill("blade")) > target->query_skill("parry") / 2)
        {
                msg += HIR "��ʱ��$n" HIR "ֻ����Χ�Ĵ�ɱ��������ȫ����Ѫ��"
                       "���������мܡ�\n" NOR;
                count = me->query_skill("xue-dao", 1) / 4;
        } else
        {
                msg += HIY "��ʱ��$n" HIY "ֻ����Χ�Ĵ�ɱ���������ĵ�΢΢һ"
                       "������æ�����мܡ�\n" NOR;
                count = 0;
        }

        message_combatd(msg, me, target);
        me->add_temp("apply/attack", count);
        me->add("neili", -150);

        for (i = 0; i < 6; i++)
        {
                if (! me->is_fighting(target))
                        break;
                if (random(3) == 1 && ! target->is_busy())
                        target->start_busy(1);
                COMBAT_D->do_attack(me, target, weapon, 0);
        }

	me->add_temp("apply/attack", -count);
        me->start_busy(1 + random(6));
	return 1;
}
