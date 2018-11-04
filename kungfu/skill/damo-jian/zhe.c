#include <ansi.h>
#include <combat.h>

#define ZHE "��" HIR "��Ħ��Ԫ��" NOR "��"

inherit F_SSERVER;

string final(object me, object target, int damage);

int perform(object me, object target)
{
	object weapon;
	string msg;
        int ap, dp;
        int damage;



	if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(ZHE "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "sword")
                return notify_fail("����ʹ�õ��������ԣ�����ʩչ" ZHE "��\n");

	if ((int)me->query_skill("damo-jian", 1) < 250)
                return notify_fail("���Ħ����������죬����ʩչ" ZHE "��\n");

        if (me->query_skill_mapped("sword") != "damo-jian")
                return notify_fail("��û�м�����Ħ����������ʩչ" ZHE "��\n");

        if ((int)me->query("max_neili") < 2000)
                return notify_fail("���������Ϊ����������ʩչ" ZHE "��\n");

        if (me->query("neili") < 300)
                return notify_fail("�����ڵ��������㣬����ʩչ" ZHE "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIR "$N" HIR "��ؽ�" + weapon->name() +
              HIR "��ǰһ�ͣ���ʱһ���⻪�Խ�������ֱ��$n"
              HIR "�����ȥ��\n" NOR;

        ap = me->query_skill("sword") + me->query_skill("force");
        dp = target->query_skill("force") * 2;

	if (ap / 3 + random(ap) > dp)
        {
                damage = ap / 3 + random(ap / 3);
msg += HIR "ͻȻ$n" HIR "ֻ�������Ȼһ�ȣ��漴�����"
               "������������ʧɫ��\n" NOR;

target->add("qi",-damage);
target->add("neili",-damage);
                me->start_busy(2);
                me->add("neili", -100);
	} else
        {
		msg += CYN "����$n" CYN "�������ʹ��$P"
                       CYN "��һ��û�����κ����á�\n" NOR;
		me->start_busy(2);
                me->add("neili", -100);
	}
	message_combatd(msg, me, target);

	return 1;
}

