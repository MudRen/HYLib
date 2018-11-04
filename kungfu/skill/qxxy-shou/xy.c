// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
#include <combat.h>
#include "/kungfu/skill/eff_msg.h";

#define CANHE "��" HIW "�κϽ���" NOR "��"

inherit F_SSERVER;


int perform(object me, object target)
{
        int damage;
        string msg;
        int ap, dp, slv, clv,p;

        if (! target) target = offensive_target(me);


        if (! target || ! me->is_fighting(target))
                return notify_fail(CANHE "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (objectp(me->query_temp("weapon")))
                return notify_fail("�������ֲ���ʹ��" CANHE "��\n");

        if (clv = (int)me->query_skill("qxxy-shou", 1) < 180)
                return notify_fail("���������������Ϊ���ޣ�����ʩչ" CANHE "��\n");

        
        if ((int)me->query_skill("force") < 320)
                return notify_fail("����ڹ���Ϊ̫�����ʩչ" CANHE "��\n");

        if ((int)me->query("max_neili") < 6000)
                return notify_fail("���������Ϊ���㣬����ʩչ" CANHE "��\n");

        if ((int)me->query("neili") < 900)
                return notify_fail("�����������������ʩչ" CANHE "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        damage = me->query_skill("qxxy-shou");
        slv = target->query_skill("six-finger", 1);

        ap = me->query_skill("hand");
        dp = target->query_skill("dodge");

        msg = HIW "ֻ��$N" HIW "ʮָ��̯����ʱ�ƿ������죬���ɽ�����ָ�⼤"
              "���������$n" HIW "��ֱ��ȥ��\n" NOR;

        me->start_busy(3);

        if (slv >= 140 
            && random(5) == 0 
            && slv >= clv - 60 // ����κ�ָ�ȼ��������񽣵ȼ���60������ȡ������Ч��
            &&! target->is_busy()
            && target->query_skill_prepared("finger") == "six-finger")
        {
                msg += HIY "\n����$n" HIY "ббһָ�����ָ����磬�����ݺᣬ��Ȼ"
                       "���죬����$N" HIY "�Ľ���ȫ���ۻأ������Լ���ȥ��\n" NOR +
                       HIR "��������������һ�����죬���Ͼ�����һЩѪ�Σ�\n" NOR;

                me->receive_wound("qi", slv / 3 + random(slv / 4));
                p = (int)me->query("qi") * 100 / (int)me->query("max_qi");
                msg += "( $N" + eff_status_msg(p) + ")\n";

        } else
        if (ap * 2 / 3 + random(ap) > dp)
        { 
target->add("qi",-damage*2);
target->add("eff_qi",-damage);

                        msg +=HIR "\n��ʱֻ������������һ����$n" HIR
                                           "����������������ʱ���ض���������һ��"
                                           "Ѫ�ꡣ\n" NOR;     
        } else
        {
                msg += CYN "\n$n" CYN "��$N" CYN "������ӿ����æ����һԾ��"
                       "�𣬱ܿ�����һ����\n" NOR;
        }

        ap = me->query_skill("hand");
        dp = target->query_skill("force");

        if (slv >= 160 
            && random(8) == 0 
            && slv >= clv - 60  // ����κ�ָ�ȼ��������񽣵ȼ���60������ȡ������Ч��
            &&! target->is_busy() 
            && target->query_skill_prepared("finger") == "six-finger")
        {
                msg += HIY "\n����$n" HIY "����Сָһ�죬һ�С����󽣡���ָ��͸��"
                       "�������ĵ�������Ѹ�٣��ٽ�$N" HIY "�����ƻأ�\n" NOR + HIR
                       "��������������һ�����죬���Ͼ�����һЩѪ�Σ�\n" NOR;

                me->receive_wound("qi", slv / 2 + random(slv / 4));
                p = (int)me->query("qi") * 100 / (int)me->query("max_qi");
                msg += "( $N" + eff_status_msg(p) + ")\n";

        } else
        if (ap * 2 / 3 + random(ap) > dp)
        { 

target->add("qi",-damage*2);
target->add("eff_qi",-damage);

                        msg +=HIR "\nֻ��$n" HIR "һ���Һ�����$N" HIR
                                           "�Ľ���������Ҫ����Ѫ��ģ������Ѫ������"
                                           "ֹ��\n" NOR;     

        } else
        {
                msg += CYN "\n$n" CYN "��$N" CYN "������ӿ����æ����һԾ��"
                       "�𣬱ܿ�����һ����\n" NOR;
        }

        ap = me->query_skill("hand");
        dp = target->query_skill("parry");

        if (slv >= 180 
            && random(10) == 0 
            && slv >= clv - 50  // ����κ�ָ�ȼ��������񽣵ȼ���50������ȡ������Ч��
            &&! target->is_busy()
            && target->query_skill_prepared("finger") == "six-finger")
        {
                msg += HIY "\n�ɵ���ʯ֮�䣬$n" HIY "��Ȼ���ƣ����ֶ�Ȼ̽������"
                       "ָ���г彣����$N" HIY "һ�����ǽ��κϽ����������Σ�\n" NOR
                       + HIR "��������������һ�����죬���Ͼ�����һЩѪ�Σ�\n" NOR;

                me->receive_wound("qi", slv / 2 + random(slv / 2));
                p = (int)me->query("qi") * 100 / (int)me->query("max_qi");
                msg += "( $N" + eff_status_msg(p) + ")\n";
                me->start_busy(6);

        } else
        if (ap * 2 / 3 + random(ap) > dp)
        { 
target->add("qi",-damage*2);
target->add("eff_qi",-damage);

                        msg +=HIR "\n$n" HIR "�����мܣ����ǲ��У�$N"
                                           "��" HIR "���ν�����͸����룬��Ѫ����"
                                           "��������ս��\n" NOR;     
        } else
        {
                msg += CYN "\n$n" CYN "��$N" CYN "������ӿ����æ����һԾ��"
                       "�𣬱ܿ�����һ����\n" NOR;
        }
        me->add("neili", -400 - random(100));
        message_combatd(msg, me, target);
if ((int)me->query_skill("qxxy-shou", 1)> 320)
{
if (random(3)==0) target->start_busy(3);
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

