// zhua.c ������צ

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

#define ZHUA "��" HIG "������צ" NOR "��"

string final(object me, object target);

int perform(object me, object target)
{
	object weapon;
	string msg;
        int ap, dp;
        int damage;


	if (! target) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
		return notify_fail(ZHUA "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if ((int)me->query_skill("sanyin-wugongzhao", 1) < 180)
		return notify_fail("����������צ������죬�޷�ʹ��" ZHUA "��\n");
	if ((int)me->query_skill("huagong-dafa", 1) < 50)
		return notify_fail("��ı����ڹ�������죬�޷�ʹ��" ZHUA "��\n");


        if (me->query("neili") < 150)
                return notify_fail("���������㣬�޷�ʩչ" ZHUA "��\n");
 
        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

	msg = HIR "$N" HIR "ͻȻһ���ֽУ���������Ѫ���漴����һ����ץ��$n"
              HIR "��Ҫ����\n" NOR;

        ap = me->query("combat_exp");
        dp = target->query("combat_exp");
	if (ap  + random(ap) > dp)
        {
                damage = me->query_skill("sanyin-wugongzhao",1)*2  + random(me->query_skill("claw",1));
        msg += HIR "$p" HIR "����ʧ�룬��æ���ˣ�Ȼ��û"
               "�ܱܿ�����$P" HIR "��һצץ����Ѫ���죡\n" NOR;
        if (target->query("qi") > damage)
        {
        target->add("qi",-damage);
        target->add("eff_qi",-damage);
        }
        target->apply_condition("xx_poison",20);
	 target->apply_condition("x2_sandu",20);
	 target->apply_condition("sanpoison",20);
                me->start_busy(2);
	} else
        {
		msg += HIR "����$p" HIR "������$P" HIR "����ʽ��"
                       "�����мܣ���ס��$P" HIR "�Ķ��С�\n" NOR;
		me->start_busy(2);
	}
	message_combatd(msg, me, target);

	return 1;
}

