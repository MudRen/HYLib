// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
#include <combat.h>

#define DANG "��" HIW "�����Ƶ�" NOR "��"

inherit F_SSERVER;


int perform(object me, object target)
{
        object weapon, cloth;
        int ap, dp, damage, wp, cl;
        string msg;



        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(DANG "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(DANG "ֻ�ܿ���ʩչ��\n");

        if ((int)me->query_skill("xiantian-qigong", 1) < 240)
                return notify_fail("������칦��Ϊ����������ʩչ" DANG "��\n");
        if(me->is_busy())
        return notify_fail("��������æ��\n");
        if (me->query("max_neili") < 4000)
                return notify_fail("���������Ϊ���㣬����ʩչ" DANG "��\n");

        if (me->query_skill_mapped("unarmed") != "xiantian-qigong")
                return notify_fail("��û�м������칦Ϊȭ�ţ�����ʩչ" DANG "��\n");

        if (me->query_skill_mapped("force") != "xiantian-qigong")
                return notify_fail("��û�м������칦Ϊ�ڹ�������ʩչ" DANG "��\n");


        if (me->query("neili") < 800)
                return notify_fail("�����ڵ��������㣬����ʩչ" DANG "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIW "ֻ��$N" HIW "˫Ŀ�������䣬˫�ƶ�Ȼһ�񣬽����ڻ����"
              "���������ƹ��Ƴ�����ʱ��Х\n�����������쾢��������������"
              "���˰�ӿ��$n" HIW "��\n" NOR;

        ap = me->query_skill("unarmed") + me->query_skill("force");
        dp = target->query_skill("parry") + target->query_skill("force");
        
        if (ap * 11 / 20 + random(ap) > dp)
        {
                damage = 0;
                if (me->query("max_neili") > target->query("max_neili") * 2)
                {
                        me->start_busy(2);
                        msg += HIR "����$n" HIR "΢΢һ㶼䣬$N" HIR "���Ȼ"
                               "���壬$p" HIR "һ��������ȫ�����羡�����ѡ�\n"
                               NOR "( $n" RED "���˹��أ��Ѿ�������в�����"
                               "ʱ�����ܶ�����" NOR ")\n";
                        damage = -1;
                } else
                {
                        me->start_busy(4);
                        damage = me->query_skill("unarmed")*2;
                        me->add("neili", -400);
               		target->add("qi",-damage);
		target->add("eff_qi",-damage/2);
                me->add("neili", -150);
		msg +=   HIR "$N" HIR "��"
                                                   "���ʱ�߽���$n" HIR "�Ļ�"
                                                   "��������$p" HIR "��Ԫ����"
                                                   "�������������Ѫ��\n" NOR;


                        if (objectp(weapon = target->query_temp("weapon"))
                           && random(3)==0
                           && ap / 3 + random(ap) > dp)
                        {
                                wp = weapon->name();
                                msg += HIW "ֻ�����ϡ���һ�����죬$n" HIW "��"
                                       "�е�" + wp + HIW "��$N" HIW "��������"
                                       "��Ӧ�����飬���ֵ����ڵ��ϡ�\n" NOR;
                                me->add("neili", -150);
                                weapon->set("consistence", 0);
                                weapon->move(environment(target));
                        } else

                        if (objectp(cloth = target->query_temp("armor/armor"))
                           && random(3)==0
                           && ap / 3 + random(ap) > dp)
                        {
                                cl = cloth->name();
                                msg += HIW "ֻ�����䡱��һ�����죬$n" HIW "��"
                                       "�ŵ�" + cl + HIW "��$N" HIW "��������"
                                       "��Ӧ�����ѣ�����һ�����Ƭ��\n" NOR;
                                me->add("neili", -150);
                                cloth->set("consistence", 0);
                                cloth->move(environment(target));
                        } else

                        if (objectp(cloth = target->query_temp("armor/cloth"))
                           && random(3)==0
                           && ap / 3 + random(ap) > dp)
                        {
                                cl = cloth->name();
                                msg += HIW "ֻ�����䡱��һ�����죬$n" HIW "��"
                                       "�ŵ�" + cl + HIW "��$N" HIW "��������"
                                       "��Ӧ�����飬����һ�����Ƭ��\n" NOR;
                                me->add("neili", -150);
                                cloth->set("consistence", 0);
                                cloth->move(environment(target));
                        }
                }
        } else
        {
                me->start_busy(4);
                me->add("neili", -120);
                msg += CYN "����$p" CYN "֪��$P" CYN "���е���"
                       "��������Ӳ�ӣ�����бԾ��ܿ�����\n" NOR;
        }
        message_combatd(msg, me, target);



        return 1;
}
