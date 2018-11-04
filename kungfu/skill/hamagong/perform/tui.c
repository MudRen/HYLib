// tui.c ��

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

int exert(object me, object target)
{
        string msg;
        int skill, ap, dp, damage;

        if (! target || target == me)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! target || ! me->is_fighting(target))
                return notify_fail("��󡹦������ʽ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");


                
        skill = me->query_skill("hamagong", 1);

        if (skill < 240)
                return notify_fail("��ĸ�󡹦��Ϊ�����������ʹ�á�����ʽ����\n");

        if (me->query("max_neili") < 4000)
                return notify_fail("���������Ϊ��������޷�ʩչ������ʽ����\n");

        if (me->query("neili") < 1000)
                return notify_fail("��������������޷����á�����ʽ����\n");

       if (! living(target))
              return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIY "$N" HIY "���ڵ��ϣ����á���һ����У�˫����"
              "����룬ƽ�ƶ�����һ�ɼ����������ͬ"
              "��ɽ����һ�㱼��$n" HIY "��\n" NOR;

        ap = me->query_skill("force") * 15 + me->query("max_neili");
        dp = target->query_skill("force") * 15 + target->query("max_neili") +
             target->query_skill("yiyang-zhi", 1) * 20;
        if (dp < 1) dp = 1;
        if (ap / 2 + random(ap) > dp)
        {
                me->add("neili", -400);
                me->start_busy(2);
                damage = ap / 10 + random(ap / 10)+100;
target->add("qi",-damage*2);
target->add("eff_qi",-damage);
target->apply_condition("snake_poison",10);
target->apply_condition("chanchu_poison",10);
target->apply_condition("qx_snake_poison",20);
                        target->add("qi",-damage+100);
                        target->add("qi",-damage/2+100);

                        msg +=HIR "$n" HIR "�����͵�������$P" HIR "�����ƺ�"
                                           "�Ⱥƴ�$p" HIR "��ʱ������Ѫ���������ۡ���"
                                           "�³���һ����Ѫ��\n" NOR;

        } else
        if (target->query_skill("yiyang-zhi", 1))
        {
                me->start_busy(2);
                me->add("neili", -300);
                msg += HIG "Ȼ��$p" HIG "����һЦ������һָ�̳�������һ"
                       "��ָ�ľ������������׵Ļ�����$P" HIG "�Ĺ��ơ�\n" NOR;
        } else
        {
                me->add("neili",-200);
                msg += CYN "����$n" CYN "�������˵�˫���ϣ�������$P"
                       CYN "��һ��֮ʽ��ֻ�������һ�����������"
                       "�������\n" NOR;
                me->start_busy(3);
                target->start_busy(1);
                if (target->query("neili") > 200)
                        target->add("neili", -200);
                else
                        target->set("neili", 0);
        }
        message_combatd(msg, me, target);

        return 1;
}

