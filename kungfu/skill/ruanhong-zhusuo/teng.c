// tengshe.c ���߾�

#include <ansi.h>
#include <combat.h>

#define TENGSHE "��" WHT "���߾�" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        string msg;
        int ap, dp;
        int damage;
 
        if (! target) target = offensive_target(me);


        if (! target || ! me->is_fighting(target))
                return notify_fail(TENGSHE "ֻ����ս���жԶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
              (string)weapon->query("skill_type") != "whip")
                return notify_fail("��ʹ�õ��������ԣ��޷�ʩչ" TENGSHE "��\n");

        if ((int)me->query_skill("ruanhong-zhusuo", 1) < 60)
                return notify_fail("����������������죬�޷�ʩչ" TENGSHE "��\n");

        if (me->query("neili") < 200)
                return notify_fail("��������������޷�ʩչ" TENGSHE "��\n");
         if( (int)me->query_skill("wudu-shengong",1) < 100 )
                return notify_fail("����嶾����Ϊ��������\n");

         if( (int)me->query_skill("poison",1) < 100 )
                return notify_fail("��Ļ���������Ϊ��������\n");

        if (me->query_skill_mapped("whip") != "ruanhong-zhusuo")
                return notify_fail("��û�м�������������޷�ʩչ" TENGSHE "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = WHT "$N" WHT "��Ȼʩչ�������ߡ�������������һ����" + weapon->name() +
              WHT "��ʱ�εص�����ͬ����һ����ȻϮ��$n" + WHT "��\n" NOR;

        ap = me->query_skill("whip") + me->query_skill("force");
        dp = target->query_skill("force") + target->query_skill("parry");

        if (random( (int)me->query("combat_exp",1))
          > target->query("combat_exp")/3)
        {
                damage = ap / 2 + random(ap / 4)+500;
                me->add("neili", -150);
                me->start_busy(1);
target->add("qi",-damage);
		target->add("eff_qi",-damage);
                msg +=HIR "Ȼ��$n" HIR "δ�ܿ�����ͼ��һ���Һ���"
                                           + weapon->name() + HIR "�޶���û�����ڰ��"
                                           "����ʱ����������\n" NOR;
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
        } else
        {
                me->add("neili", -100);
                me->start_busy(3);
                msg += CYN "����$p" CYN "����������������ס��"
                       CYN "$P" CYN "�����Ī���һ����\n"NOR;
        }
        message_combatd(msg, me, target);

        return 1;
}
