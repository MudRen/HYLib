#include <ansi.h>
#include <combat.h>

#define KONG "��" HIG "�տ���Ҳ" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
	int damage;
	string msg;
        int ap, dp;

	int extra;
	int i,a;
	object weapon;

	if (! target) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
                return notify_fail(KONG "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

		
        if ((int)me->query_skill("kongming-quan", 1) < 150)
		return notify_fail("��Ŀ���ȭ������죬����ʩչ" KONG "��\n");

        if (me->query_skill_mapped("unarmed") != "kongming-quan")
                return notify_fail("��û�м�������ȭ������ʩչ" KONG "��\n");


        if ((int)me->query("neili", 1) < 150)
		return notify_fail("�����ڵ�����̫��������ʩչ" KONG "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

	msg = WHT "$N" WHT "ʹ������ȭ��" HIG "�տ���Ҳ" NOR + WHT "����ȭ��"
              "����ʵʵ���仯Ī�⣬��$n" WHT "һʱ���Բ�׽��\n" NOR;
	me->add("neili", -80);

        ap = me->query_skill("unarmed");
        dp = target->query_skill("parry");
	if (ap  + random(ap) > dp)
	{
		me->start_busy(2);
		
		damage = (int)me->query_skill("force", 1);
                damage = damage + random(damage );
		target->add("qi",-damage*2);
		target->add("eff_qi",-damage);
                msg +=HIR "$n" HIR "�޷�����$N" HIR "ȭ�а�"
                                           "�أ�����һȭ����Ҫ������ʱŻ��һ���"
                                           "��Ѫ��\n" NOR;
	} else 
	{
		me->start_busy(2);
		msg += CYN "����$p" CYN "ʶ����$P"
                       CYN "��ȭ���еı仯������Ӧ�ԣ���û�гԿ���\n" NOR;
	}
	message_combatd(msg, me, target);
	extra = me->query_skill("kongming-quan",1) / 20;
	extra += me->query_skill("xiantian-qigong",1) /20;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	msg =  HIG "����ȭ ! ����ʵʵ���仯Ī�⣡��������\n" NOR;
        message_vision(msg, me, target);
a=extra/3;
if (a> 8) a=8;
	for(i=0;i<a;i++)
	{
	msg = HIW "$Nһȭ���,����ʵʵ���仯Ī�⣡\n" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	}
	i = extra/4;
	me->add("neili", - 50 * i);
	me->start_busy(3);
	return 1;
}
