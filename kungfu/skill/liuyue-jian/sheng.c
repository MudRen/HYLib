#include <ansi.h>
#include <combat.h>

#define SHENG "��" HIW "��������" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        string msg;
        int i;


        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(SHENG "ֻ����ս���жԶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
              (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԣ�����ʩչ" SHENG "��\n");

        if (me->query_skill("force") < 200)
                return notify_fail("����ڹ�����Ϊ����������ʩչ" SHENG "��\n");

        if (me->query_skill("liuyue-jian", 1) < 150)
                return notify_fail("������½�����Ϊ����������ʩչ" SHENG "��\n");

        if (me->query("neili") < 300)
                return notify_fail("�����������������ʩչ" SHENG "��\n");

        if (me->query_skill_mapped("sword") != "liuyue-jian")
                return notify_fail("��û�м������½��裬����ʩչ" SHENG "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIW "$N" HIW "����һ�󼲶�������΢��������������ɲ�Ǽ佣â���ǣ�"
              "����ӵ�кһ������$n"
              HIW "��\n" NOR;

        message_combatd(msg, me, target);
        me->add("neili", -100);

        for (i = 0; i < 6; i++)
        {
                if (! me->is_fighting(target))
                        break;
                COMBAT_D->do_attack(me, target, weapon, 0);
        }

        me->start_busy(1 + random(6));

        return 1;
}

