// huanyin.c ������ָ

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;


int perform(object me, object target)
{
        string msg;
        int ap, dp, damage;

        if (! target) target = offensive_target(me);
        if (! target || ! me->is_fighting(target))
                return notify_fail("������ָֻ�ܶ�ս���еĶ���ʹ�á�\n");
        if (environment(me)->query("no_fight"))
                return notify_fail("���ﲻ�ܹ�������! \n");
        if(me->is_busy())
        return notify_fail("��������æ��\n");
        if (! target || ! target->is_character())
                return notify_fail("������ָֻ�ܶԶ���ʹ�á�\n");

        if (target->query("not_living"))
                return notify_fail("��������ǲ��ǻ��ˡ�\n");

        if ((int)me->query_skill("force") < 300)
                return notify_fail("����ڹ��������ʩչ������ָ��\n");

        if ((int)me->query_skill("huanyin-zhi", 1) < 150)
                return notify_fail("��Ļ���ָ����Ϊ���������ڻ��޷�ʩչ������ָ��\n");

        if (me->query_skill_mapped("finger") != "huanyin-zhi")
                return notify_fail("��û�м�������ָ�����޷�ʩչ������ָ��\n");

        if (me->query("neili") < 400)
                return notify_fail("������������������޷�ʩչ������ָ��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIG "$N" HIG "���������һ�����������Ĵ�"
              "��һָ��Ю��һ�ɺ�������$n" HIG "��\n" NOR;

        ap = me->query_skill("finger");
        dp = target->query_skill("parry");
        
        if (ap / 2 + random(ap) > dp)
        {
                damage = me->query_skill("finger")*2;
                me->add("neili", -300);
       target->add("qi",-damage);
		target->add("eff_qi",-damage);
                msg += HIG "$p" HIG "��æ���ˣ�Ȼ����ָ�ε������"
                                           "�õ���$p" HIG "��ǰ��$p" HIG "��������һ����"
                                           "ս��\n" NOR;
                target->apply_condition("huanyin_poison",18);
                me->add("neili", -320);
                me->start_busy(2);
        } else
        {
                msg += CYN "����$p" CYN "�����������������ڹ�"
                       "��������һָ������������\n" NOR;
                me->start_busy(4);
                me->add("neili", -80);
        }
        message_combatd(msg, me, target);
        //me->want_kill(target);
        //if (! target->is_killing(me)) target->kill_ob(me);
        return 1;
}

