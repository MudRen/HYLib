#include <ansi.h>
#include <combat.h>

#define SHI "��" HIR "������" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;
        int damage;
        int ap, dp;


        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(SHI "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (me->query_skill("force") < 200)
                return notify_fail("����ڹ������������ʩչ" SHI "��\n");
         if( (int)me->query_skill("wudu-shengong",1) < 100 )
                return notify_fail("����嶾����Ϊ��������\n");

         if( (int)me->query_skill("poison",1) < 100 )
                return notify_fail("��Ļ���������Ϊ��������\n");

	if( (int)me->query_skill("shedu-qiqiao", 1) < 100 )
		return notify_fail("����߶����ɻ��������, ���ܴ��� !\n");

        if (me->query("neili") < 120)
                return notify_fail("�����������������ʩչ" SHI "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIW "$N" HIW "��������������˫��֮�䣬ֻ��˫��΢΢�����Ϲ⣬��"
              "������$n��\n" NOR;

        ap = me->query_skill("strike");
        dp = target->query_skill("force");
        if ( random( (int)me->query("combat_exp",1))
          > target->query("combat_exp")/3  )
        {

                damage = ap / 2 + random(ap / 2);
                                		target->add("qi",-damage);
		target->add("eff_qi",-damage);
                msg +=HIR "ֻ��$n" HIR "��$N" HIR "һ������"
                "�����˼�����ȴ����ɫ��΢΢���ڡ�\n" NOR;
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
                me->start_busy(2);
        } else
        {
                msg += CYN "����$p" CYN "�����ֿ죬����һ��$P"
                       CYN "�Ѷ��$N���С�\n" NOR;
                me->start_busy(3);
                target->start_busy(1);
        }
        message_combatd(msg, me, target);

        return 1;
}

