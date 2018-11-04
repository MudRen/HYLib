// suolong.c ������

#include <ansi.h>
#include <combat.h>

#define SUOLONG "��" HIW "������" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        string msg;
        int ap, dp;
        int count;
        int i, attack_time;

        if (! target) target = offensive_target(me);

         if( (int)me->query_skill("wudu-shengong",1) < 100 )
                return notify_fail("����嶾����Ϊ��������\n");

         if( (int)me->query_skill("poison",1) < 100 )
                return notify_fail("��Ļ���������Ϊ��������\n");


        if (! target || ! me->is_fighting(target))
                return notify_fail(SUOLONG "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "whip")
                return notify_fail("��ʹ�õ��������ԣ��޷�ʩչ" SUOLONG "��\n");

        if ((int)me->query_skill("ruanhong-zhusuo", 1) < 200)
                return notify_fail("����������������죬�޷�ʩչ" SUOLONG "��\n");

        if (me->query("neili") < 350)
                return notify_fail("��������������޷�ʩչ" SUOLONG "��\n");

        if (me->query_skill_mapped("whip") != "ruanhong-zhusuo")
                return notify_fail("��û�м�������������޷�ʩչ" SUOLONG "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIW "$N" HIW "ʹ������������������" + weapon->name() +
              HIW "һ������ʱ�ó������Ӱ����������ͨ�죬һ��Ϯ��$n"
              HIW "��ȥ��\n\n" NOR;

        ap = me->query_skill("whip");
        dp = target->query_skill("parry");
        attack_time = 4;
        if (random( (int)me->query("combat_exp",1))
          > target->query("combat_exp")/3)
        {
                msg += HIC "���$p" HIC "��$P" HIC
                       "���˸����ֲ�����Ŀ�Ӳ�Ͼ��ƣ�ڱ�����\n" NOR;
                count = ap / 12;
	       target->apply_condition("snake_poison",
		        (int)target->query_condition("snake_poison") + 50 );
	       target->apply_condition("wugong_poison",
		        (int)target->query_condition("wugong_poison") + 50 );
	       target->apply_condition("zhizhu_poison",
		        (int)target->query_condition("zhizhu_poison") + 50 );
	       target->apply_condition("xiezi_poison",
		        (int)target->query_condition("xiezi_poison") + 50 );
	       target->apply_condition("chanchu_poison",
		        (int)target->query_condition("chanchu_poison") + 50 );
	       target->apply_condition("wuhudu_poison",
		        (int)target->query_condition("wuhudu_poison") + 50 );
	       target->apply_condition("chilian_poison",
		        (int)target->query_condition("chilian_poison") + 50 );
                attack_time += random(ap / 35)+2;
        } else
        {
                msg += HIC "$n" HIC "��$N" HIC "���ƻֺ룬������Ȼ������Ӧ����\n" NOR;
                count = 0;
        }
                
        message_combatd(msg, me, target);

        if (attack_time > 9)
                attack_time = 9;

        me->add("neili", -attack_time * 20);

                me->add_temp("apply/attack", 80);
        if (random(3)==0) target->start_busy(3);
        for (i = 0; i < attack_time; i++)
        {
                if (! me->is_fighting(target))
                        break;
                COMBAT_D->do_attack(me, target, weapon, 0);
        }

        me->add_temp("apply/attack", -80);
        me->start_busy(2);
        return 1;
}
