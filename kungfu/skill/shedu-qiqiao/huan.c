#include <ansi.h>
#include <combat.h>

#define HUAN "��" HIG "ǧ�����" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;
        int ap, dp;


        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(HUAN "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(HUAN "ֻ�ܿ���ʩչ��\n");

        if (target->is_busy())
                return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɡ�\n");

         if( (int)me->query_skill("wudu-shengong",1) < 100 )
                return notify_fail("����嶾����Ϊ��������\n");

         if( (int)me->query_skill("poison",1) < 100 )
                return notify_fail("��Ļ���������Ϊ��������\n");

	if( (int)me->query_skill("shedu-qiqiao", 1) < 100 )
		return notify_fail("����߶����ɻ��������, ���ܴ��� !\n");

        if (me->query_skill("dodge") < 150)
                return notify_fail("����Ṧ��Ϊ����������ʩչ" HUAN "��\n");

        if ((int)me->query("neili") < 200)
                return notify_fail("�����ڵ���������������ʩչ" HUAN "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        ap = me->query_skill("wudu-shenzhang", 1) +
             me->query_skill("dodge", 1) / 2;

        dp = target->query_skill("dodge");

        msg = HIC "\n$N" HIC "����Ȼ��죬ʹ�����С�" HIG "ǧ�����" HIC "����"
              "˫�Ʋ����ĳ���\n��ʽ��Ӱ��ã���ʵ�Ѳ⣬��ͼ����$n" HIC "�Ĺ�"
              "�ơ�\n" NOR;

        message_combatd(msg, me, target);

        if ( random( (int)me->query("combat_exp",1))
          > target->query("combat_exp")/3 )
        {
		msg = HIY "$n" HIY "ֻ��$N" HIY "˫��Ʈ����������"
                      "����������������$N" HIY "���Ʒ�֮�С�\n" NOR;

                target->start_busy(ap / 45 + 2);
	       target->apply_condition("snake_poison",
		        (int)target->query_condition("snake_poison") + 10 );
	       target->apply_condition("wugong_poison",
		        (int)target->query_condition("wugong_poison") + 10 );
	       target->apply_condition("zhizhu_poison",
		        (int)target->query_condition("zhizhu_poison") + 10 );
	       target->apply_condition("xiezi_poison",
		        (int)target->query_condition("xiezi_poison") + 10 );
	       target->apply_condition("chanchu_poison",
		        (int)target->query_condition("chanchu_poison") + 10 );
               	me->start_busy(1);
                me->add("neili", -80);
        } else
        {
                msg = CYN "$n" CYN "����$N" CYN "���޹���֮�⣬��"
                      "�Ǵ󵨷�������$N" CYN "���о������⡣\n" NOR;

                me->start_busy(2);
                me->add("neili", -30);
        }
        message_combatd(msg, me, target);

        return 1;
}
