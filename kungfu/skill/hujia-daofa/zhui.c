#include <ansi.h>
#include <combat.h>

#define ZHUI "��" HIR "ж��׶����" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
	object weapon;
	int damage;
	string msg;
        int ap, dp;

        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! target || ! me->is_fighting(target))
                return notify_fail(ZHUI "ֻ�ܶ�ս���еĶ���ʹ�á�\n");
 
        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "blade")
                return notify_fail("��ʹ�õ��������ԣ�����ʩչ" ZHUI "��\n");

        if ((int)me->query_skill("force") < 200)
                return notify_fail("����ڹ���򲻹�������ʩչ" ZHUI "��\n");

        if ((int)me->query_skill("hujia-daofa", 1) < 140)
                return notify_fail("��ĺ��ҵ����������ң�����ʩչ" ZHUI "��\n");

        if (me->query_skill_mapped("blade") != "hujia-daofa")
                return notify_fail("��û�м������ҵ���������ʩչ" ZHUI "��\n");

        if ((int)me->query("neili") < 200)
                return notify_fail("�����������������ʩչ" ZHUI "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

	msg = HIR "$N" HIR "���е�" + weapon->name() +  HIR "һ��ʩ����ж"
              "��׶���ơ�����ʱһ�������ޱȵ����ε����ƿ�Ϯ��$n" HIR "��\n"NOR;

        ap = me->query_skill("blade") + me->query_skill("force");
        dp = target->query_skill("force");

        if (ap / 4 + random(ap / 2) > dp)
	{
		damage = ap / 3 + random(ap / 2)+600;
                		target->add("qi",-damage);
		target->add("eff_qi",-damage/2);
                me->add("neili", -150);
		msg +=                     HIR "ֻ��$n" HIR "һ���ҽУ�����������"
                                           "������������ģ�������Ѫ���������\n" NOR;
		me->start_busy(2);
	} else 
	{
		msg += CYN "����$p" CYN "Ĭ��������Ӳ�ǵֵ���$P"
                       CYN "��������ε�����\n"NOR;
                me->add("neili", -150);
		me->start_busy(2);
	}
	message_combatd(msg, me, target);

	return 1;
}
