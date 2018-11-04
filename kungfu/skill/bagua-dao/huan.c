#include <ansi.h>
#include <combat.h>

#define HUAN "��" HIG "������" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
	object weapon;
	string msg;
	int ap, dp;
        int count;
	int i, attack_time;


        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(HUAN "ֻ�ܶ�ս���еĶ���ʹ�á�\n");


        if (! objectp(weapon = me->query_temp("weapon")) ||
              (string)weapon->query("skill_type") != "blade")
                return notify_fail("��ʹ�õ��������ԣ�����ʩչ" HUAN "��\n");

        if (me->query_skill("dodge") < 220)
                return notify_fail("��������з���Ϊ����������ʩչ" HUAN "��\n");

        if (me->query("neili") < 270)
                return notify_fail("�����������������ʩչ" HUAN "��\n");

        if ((int)me->query_skill("linji-zhuang", 1) < 120)
                return notify_fail("����ټ�ʮ��ׯ���̫ǳ��\n");
                
        if (me->query_skill("bagua-dao", 1) < 140)
                return notify_fail("��İ��Ե�����Ϊ����������ʩչ" HUAN "��\n");

        if (me->query_skill_mapped("blade") != "bagua-dao")
                return notify_fail("��û�м������Ե���������ʩչ" HUAN "��\n");

	msg = HIY "$N" HIY "��Хһ��������" + weapon->name() + HIY "����"
              "�����⻷����Ȼ���â���ǣ���������$n" HIY "��\n" NOR;

        // ��������������sword��blade���ж�apֵ��
                ap = me->query_skill("blade");

	dp = target->query_skill("dodge");
        attack_time = 4;

	if (ap / 2 + random(ap * 2) > dp)
	{
		msg += HIR "���$n" HIR "��$N" HIR "���˸����ֲ�����$n"
                       HIR "��æ�мܣ����нпࡣ\n" NOR;
                count = ap / 12;
                attack_time += random(ap / 45);
        if (count > 100) count=100;

        } else
        {
                msg += HIC "$n" HIC "��$N" HIC "�⼸�������ޱȣ�������"
                       "����ֻ�ÿ���мܡ�\n" NOR;
                count = 0;
        }
	message_combatd(msg, me, target);

        if (attack_time > 8)
                attack_time = 8;

	me->add("neili", -attack_time * 20);
        me->add_temp("apply/attack", count);
        me->add_temp("apply/damage", 200);
	for (i = 0; i < attack_time; i++)
	{
		if (! me->is_fighting(target))
			break;

	        COMBAT_D->do_attack(me, target, weapon, 0);
	}
        me->add_temp("apply/attack", -count);
	me->add_temp("apply/damage", -200);
	me->start_busy(4);

	return 1;
}
