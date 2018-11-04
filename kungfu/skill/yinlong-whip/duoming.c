 // duoming.c


#include <ansi.h>

#include <combat.h>
inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        string msg;
        int ap, dp;
        int damage;
        int count;
        int i, attack_time;

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail( "��������ֻ����ս����ʹ��\n");


        if (! objectp(weapon = me->query_temp("weapon")) ||
              (string)weapon->query("skill_type") != "whip")
                return notify_fail("��ʹ�õ��������ԡ�\n");


        if (me->query_skill("force") < 150)
                return notify_fail("����ڹ�����Ϊ����������ʹ�á�������������\n");

        if (me->query_skill("yinlong-whip", 1) < 150)
                return notify_fail("�����������Ϊ������Ŀǰ����ʹ�á�������������\n");

        if (me->query("neili") < 500)
                return notify_fail("��������������޷�ʹ�á�������������\n");

        if (me->query_skill_mapped("whip") != "yinlong-whip")
                return notify_fail("��û�м��������ޣ�����ʹ�á�������������\n");

        msg = HIB "ͻȻ֮�䣬" HIB "$N" HIB "����һ��һ�Σ���������,"+ weapon->name() +
              HIB "���Ҽ缱˦��󣬶���"
              HIB "��ͷ����\n" HIB "$n" HIB "���š�" HIB "$N" HIB "������"
              HIB "$n" HIB "���ʮ������,��"+ weapon->name() +
              HIB "˵���㵽��������"
              HIB "��\n������ʸ�ö�������\n" NOR;

        ap = me->query_skill("whip");
        dp = target->query_skill("parry");
        attack_time = 6;
        if (ap / 2 + random(ap * 2) > dp || !living(target))
        {
                msg += HIR "���$p" HIR "��$P" HIR
                       "���˸����ֲ�����Ŀ�Ӳ�Ͼ��ƣ�ڱ�����\n" NOR;
                count = ap / 10;
                me->add_temp("apply/attack", count);
                attack_time += random(ap / 60);
        } else
        {
                msg += HIC "$n" HIC "��$N" HIC "���ƺ�����������Ȼ������Ӧ����\n" NOR;
                count = 0;
        }

        message_combatd(msg, me, target);

        if (attack_time > 9)
                attack_time = 9;

        me->add("neili", -attack_time * 20);

        for (i = 0; i < attack_time; i++)
        {
                if (! me->is_fighting(target))
                        break;
                if (random(3)==0) target->start_busy(3);
                COMBAT_D->do_attack(me, target, weapon, 0);
        }

        me->add_temp("apply/attack", -count);
        me->start_busy(1 + random(5));
        return 1;
}
