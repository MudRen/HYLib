#include <ansi.h>
#include <combat.h>
#include "/kungfu/skill/eff_msg.h";

#define DING "��" HIC "������" NOR "��"

inherit F_SSERVER;


int perform(object me, object target)
{
        string msg;
        int ap, dp;
object weapon,weapon2;
int damage,p;
        string pmsg;
        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(DING "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(DING "ֻ�ܿ���ʩչ��\n");

        if (target->is_busy())
                return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɡ�\n");

        if ((int)me->query_skill("tanzhi-shentong", 1) < 120)
                return notify_fail("��ĵ�ָ��ͨ������죬����ʩչ" DING "��\n");

        if (me->query_skill_mapped("finger") != "tanzhi-shentong")
                return notify_fail("��û�м�����ָ��ͨ������ʩչ" DING "��\n");

        if (me->query_skill_prepared("finger") != "tanzhi-shentong")
                return notify_fail("��û��׼����ָ��ͨ������ʩչ" DING "��\n");

        if (me->query("max_neili") < 1500)
                return notify_fail("���������Ϊ���㣬����ʩչ" DING "��\n");

        if (me->query("neili") < 600)
                return notify_fail("�����ڵ���������������ʩչ" DING "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");
        if ((int)me->query_skill("bibo-shengong", 1) < 120)
                return notify_fail("��ı̲��񹦻��̫ǳ��\n");
        if ((int)me->query_skill("anying-fuxiang", 1) < 120)
                return notify_fail("��İ�Ӱ������̫ǳ��\n");
        if ((int)me->query_skill("lanhua-shou", 1) < 120)
                return notify_fail("���������Ѩ�ֻ��̫ǳ��\n");
        if ((int)me->query_skill("luoying-shenjian", 1) < 120)
                return notify_fail("�����Ӣ�񽣻��̫ǳ��\n");
        if ((int)me->query_skill("luoying-zhang", 1) < 120)
                return notify_fail("�����Ӣ���ƻ��̫ǳ��\n");
        if ((int)me->query_skill("tanzhi-shentong", 1) < 120)
                return notify_fail("��ĵ�ָ��ͨ���̫ǳ��\n");
        if ((int)me->query_skill("xuanfeng-leg", 1) < 120)
                return notify_fail("�������ɨҶ�Ȼ��̫ǳ��\n");
        if ((int)me->query_skill("yuxiao-jian", 1) < 120)
                return notify_fail("������｣�����̫ǳ��\n");
       if ((int)me->query_skill("count", 1) < 120)
                return notify_fail("����������Ի��̫ǳ��\n");
       if ((int)me->query_skill("qimen-wuxing", 1) < 120)
                return notify_fail("����������л��̫ǳ��\n");
        msg = HIC "$N" HIC "��ָ�ᵯ����ʱֻ����쬡���һ����һ���������޵�"
              "����ѳ�$n" HIC "�����ȥ��\n" NOR;

        ap = me->query_skill("finger");
        dp = target->query_skill("parry");

        if (ap / 2 + random(ap) > dp)
        {
                msg +=  HIR "$n" HIR "ֻ��в��һ�飬�ѱ�$P"
                        HIR "ָ�����У�ȫ����������������������\n" NOR;
                target->start_busy(6);
                me->start_busy(1);
                me->add("neili", -100);
        } else
        {
                msg += CYN "����$p" CYN "������$P" CYN
                       "����ͼ������һԾ�����˿�ȥ��\n" NOR;
                me->start_busy(2);
        }
        message_combatd(msg, me, target);
     msg = HIW "����$N" HIW "˫Ŀ�������䣬�����ƿ���������һöʯ����ָ�ⵯ������������$n" HIW "��\n" NOR;

        ap = me->query_skill("finger") + me->query_skill("force");
        dp = target->query_skill("dodge") + target->query_skill("parry");

        if (ap / 2 + random(ap) > dp)
        {
                me->start_busy(2);
                damage = me->query_skill("finger");

                msg += HIR "ֻ����ʯ������Ѹ��֮����$n" HIR
                       "������Ͼ���ܣ������л������У�\n" NOR;

                target->receive_damage("qi", damage*2);
                target->receive_wound("qi", damage*2);
                COMBAT_D->clear_ahinfo();

                if ((weapon2 = target->query_temp("weapon"))
                   && ap / 3 + random(ap) > dp)
                {
                        msg += HIW "$n" HIW "����һ�飬����" + weapon2->name() +
                               HIW "�������ֶ�����\n" NOR;
                        weapon2->move(environment(me));
                }

                p = (int)target->query("qi") * 100 / (int)target->query("max_qi");
                if (stringp(pmsg = COMBAT_D->query_ahinfo()))
                        msg += pmsg;
                        msg += "( $n" + eff_status_msg(p) + " )\n";
                message_combatd(msg, me, target);
        } else
        {
                me->start_busy(3);
                msg += CYN "����$p" CYN "���ϵ�$P" CYN "�д�һ�ţ���"
                       "æ����Ծ�𣬶���������\n" NOR;
                message_combatd(msg, me, target);
        }
        return 1;
}

