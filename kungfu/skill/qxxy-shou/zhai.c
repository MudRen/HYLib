// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
#include <combat.h>

#define ZHAI "��" HIC "ժ��ʽ" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        int damage;
        string msg;
        int ap, dp,clv;



        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(ZHAI "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(ZHAI "ֻ�ܿ���ʩչ��\n");

        if (clv = (int)me->query_skill("qxxy-shou", 1) < 80)
                return notify_fail("���������������Ϊ���ޣ�����ʩչ" ZHAI "��\n");

      //  if (me->query_skill_prepared("cuff") != "qxxy-shou")
      //          return notify_fail("��û��׼������ȭ��������ʩչ" ZHAI "��\n");

        if (me->query_skill("force") < 80)
                return notify_fail("����ڹ���Ϊ����������ʩչ" ZHAI "��\n");

        if ((int)me->query("neili") < 200)
                return notify_fail("�����ڵ���������������ʩչ" ZHAI "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        ap = me->query_skill("cuff") * 3 / 2 + me->query("level") * 20 + 
             me->query_skill("force", 1);
        dp = target->query_skill("parry") + target->query("level") * 20 + 
             target->query_skill("force", 1);

        msg = HIW "$N" HIW "˫ȭ�ӳ���ʩ�����С�" HIC "ժ��ʽ"
              HIW "�����վ���������λ��׼����Ϯ$n" HIW "��"
              "�ź��ؿڡ�\n" NOR;

        if (ap / 2 + random(ap) > dp)
        {
                damage = (int)me->query_skill("qxxy-shou", 1);
                damage += random(damage / 2);
target->add("qi",-damage*2);
target->add("eff_qi",-damage);

                        msg +=HIR "$N" HIR "���ּȿ죬��λ���棬$n"
                                           HIR "���ܲ������ƺ�һ������Ȼ��ȭ��\n" NOR;  

                me->add("neili", -100);
                me->start_busy(2 + random(2));                                         
        } else
        {
                msg += CYN "$n" CYN "���Ų�æ���Կ��죬��$N"
                       CYN "���л�ȥ��\n" NOR;

                me->add("neili", -30);
                me->start_busy(2 );
        }
        message_combatd(msg, me, target);
if ((int)me->query_skill("qxxy-shou", 1)> 300)
{
        msg = MAG "$NĬ����Ԫ�񹦣�������������ָ��ƽƽ�������޻��εص���$n������Ѩ" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

        msg = YEL "$N�������ϣ�����΢�飬������֮���ţ�����˫��ʳָ����һ��������ָ��ͬʱϮ��$n" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

        msg = WHT "$N��������ָ������ָ��ϳ�һ�ɽ�����ֱ��$n��ȥ"NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

        msg =RED "$N�������֣���ָ���ǻ��ţ��ٻ���£ָ��ȭ����ʱ��������������Ľ�������" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

        msg = HIR "$Nָ��Ϭ������һ�����ν�������$n�������ڣ�$nֻ���ؿ�һʹ��ȫ��������к����" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
}

        return 1;
}

