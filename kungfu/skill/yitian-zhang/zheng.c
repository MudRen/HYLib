#include <ansi.h>
#include <combat.h>

#define ZHENG "��" HIY "˭������" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;
        int count;
        int lvl;
        int i, ap, dp;

        if (! target) target = offensive_target(me);



        if (! target || ! me->is_fighting(target))
                return notify_fail(ZHENG "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (objectp(me->query_temp("weapon")))
                return notify_fail("�������ֲ���ʹ��" ZHENG "��\n");

        if ((lvl = (int)me->query_skill("yitian-zhang", 1)) < 120)
                return notify_fail("������������Ʋ�����죬����ʩչ" ZHENG "��\n");

        if ((int)me->query("neili", 1) < 500)
                return notify_fail("����������̫��������ʩչ" ZHENG "��\n");

        if (me->query_skill_mapped("strike") != "yitian-zhang")
                return notify_fail("��û�м������������ƣ�����ʩչ" ZHENG "��\n");

        if (me->query_skill_prepared("strike") != "yitian-zhang")
                return notify_fail("��û��׼��ʹ�����������ƣ�����ʩչ" ZHENG "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIY "$N" HIY "������ͨ�������������ƶ�ʮ����һ���ǳɣ�˫��"
              "Я������ɽ����֮������$n" HIY "��\n\n" NOR;
        me->add("neili", -150);

        ap = me->query_skill("strike") * 3 / 2 + me->query("level") * 20 + 
             me->query_skill("force", 1);
        dp = target->query_skill("force") + target->query("level") * 20 + 
             target->query_skill("force", 1);
         lvl = (int)me->query_skill("yitian-zhang", 1);
         count=(int)count/5;    
        if (ap / 2 + random(ap) > dp)
        {
                msg += HIR "$n" HIR "��ʱ���ú���������ȫȻ����"
                       "���������ƣ�ֻ��ƴ���˶��ֵ���\n" NOR;
                count = lvl / 5;
        } else
        {
                msg += HIC "$n" HIC "����һ����������ֵ�������������"
                       "�ھ��κ���֮�У����ҵ�����ȴ�ǲ�����\n" NOR;
                count = 0;
        }
        message_combatd(msg, me, target);
                me->add_temp("apply/attack", count);
                me->add_temp("apply/damage", count);
        for (i = 0; i < 4; i++)
        {


                if (random(3)==0) target->start_busy(3);
                COMBAT_D->do_attack(me, target, 0, 0);
        }

        me->add_temp("apply/attack", -count);
        me->add_temp("apply/damage", -count);
        me->start_busy(3);
        return 1;
}

