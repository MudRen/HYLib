// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
#include <combat.h>

#define JI "��" HIY "������" NOR "��"

inherit F_SSERVER;


int perform(object me, object target)
{
        object weapon;
        int ap, dp, shd, jia, layer, damage;
        string msg;



        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(JI "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(JI "ֻ�ܿ���ʩչ��\n");

        if ((int)me->query_skill("longxiang", 1) < 300)
                return notify_fail("��������������Ϊ����������ʩչ" JI "��\n");

        if (me->query("max_neili") < 5000)
                return notify_fail("���������Ϊ���㣬����ʩչ" JI "��\n");

        if (me->query_skill_mapped("unarmed") != "longxiang")
                return notify_fail("��û�м������������Ϊȭ�ţ�����ʩչ" JI "��\n");

        if (me->query_skill_mapped("force") != "longxiang")
                return notify_fail("��û�м������������Ϊ�ڹ�������ʩչ" JI "��\n");



        if (me->query("neili") < 800)
                return notify_fail("�����ڵ��������㣬����ʩչ" JI "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        layer = me->query_skill("longxiang", 1) / 30;

        if (layer > 13) layer = 13;

        msg = HIY "$N" HIY "��ת�����������" + chinese_number(layer) + "��"
              "������˫ȭЯ�š�" HIR "ʮ��ʮ��" HIY "��֮����$n" HIY "����"
              "\n������ȭ����������������ﳾ�����������ھ�ѧ��" HIW "����"
              "��" HIY "����\n" NOR;

        ap = me->query_skill("unarmed") + me->query_skill("force"); 
        dp = target->query_skill("parry") + target->query_skill("force"); 

        if (ap / 2 + random(ap) > dp)
        {
                if (target->query_temp("shield"))
                {
                        shd = target->query_temp("apply/armor");

                        target->add_temp("apply/armor", -shd);
                        target->delete_temp("shield");

                        msg += HIW "$N" HIW "���ӿ������Ȼ���������ˣ���ʱ��$n"
                               HIW "�Ļ��������ݻٵõ�Ȼ�޴棡\n" NOR;
                }
                jia = me->query("jiali");

                damage = 150+me->query_skill("unarmed");
   target->add("qi",-damage);
		target->add("eff_qi",-damage);
                msg += HIR "$n" HIR "�������ܣ��ٱ�$N" HIR
                                               "˫ȭ�������У������������룬��"
                                               "������������\n" NOR;

                me->start_busy(3);
                me->add("neili", -800);
        } else
        {
                me->start_busy(3);
                me->add("neili", -500);
                msg += CYN "����$p" CYN "ʶ����$P"
                       CYN "��һ�У�ббһԾ�ܿ���\n" NOR;
        }
        message_combatd(msg, me, target);

        return 1;
}

