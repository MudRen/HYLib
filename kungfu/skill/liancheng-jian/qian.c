#include <ansi.h>
#include <combat.h>

#define QIAN "��" HIY "����ǧ��" NOR "��"

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
                return notify_fail(QIAN "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԣ�����ʩչ" QIAN "��\n");

        if ((int)me->query_skill("liancheng-jian", 1) < 160)
                return notify_fail("�����Ž���������죬����ʩչ" QIAN "��\n");

        if ((int)me->query_skill("force") < 220 )
                return notify_fail("����ڹ���򲻹�������ʩչ" QIAN "��\n");

        if ((int)me->query("max_neili") < 1800)
                return notify_fail("���������Ϊ����������ʩչ" QIAN "��\n");

        if ((int)me->query("neili") < 300)
                return notify_fail("��������������������ʩչ" QIAN "��\n");

        if (me->query_skill_mapped("sword") != "liancheng-jian")
                return notify_fail("��û�м������Ž���������ʩչ" QIAN "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

	msg = HIY "$N" HIY "����" + weapon->name() + HIY "һ����������ʮ������"
              "�ǽ�����ʩ������$n" HIY "���ڽ���֮�С�\n" NOR;

	ap = me->query_skill("sword");
	dp = target->query_skill("parry");
  
        attack_time = 5;
	if (ap / 2 + random(ap * 2) > dp)
	{
		msg += HIR "$p" HIR "ֻ���ý����������ʱ��$P" HIR
                       "�����Ľ��й���Ӧ�Ӳ�Ͼ���������ˣ�\n" NOR;
                count = ap / 10;
                
                attack_time += random(ap / 45);
        } else
        {
                msg += HIC "$n" HIC "��$N" HIC "������ӿ����������"
                       "���˶��������Ҵ��⣬С��Ӧ����\n" NOR;
                count = 0;
        }
                
	message_combatd(msg, me, target);

        if (attack_time > 9)
                attack_time = 9;

	me->add("neili", -attack_time * 25);
me->add_temp("apply/attack", count);
me->add_temp("apply/damage", 350);
	for (i = 0; i < attack_time; i++)
	{
		if (! me->is_fighting(target))
			break;
		COMBAT_D->do_attack(me, target, weapon, 0);
	}
me->add_temp("apply/damage", -350);
                if (random(2) == 1 && ! target->is_busy())
                        target->start_busy(3);
        me->add_temp("apply/attack", -count);
	me->start_busy(3);

	return 1;
}
