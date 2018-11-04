#include <ansi.h>
#include <combat.h>

#define LUAN "��" HIR "Ⱥħ����" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        string msg;
        int i;
 

        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! target || ! me->is_fighting(target))
                return notify_fail(LUAN "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon"))
           || (string)weapon->query("skill_type") != "staff")
                return notify_fail("����ʹ�õ��������ԣ�����ʩչ" LUAN "��\n");

        if ((int)me->query_skill("fengmo-zhang", 1) < 120)
                return notify_fail("���ħ�ȷ���򲻹�������ʩչ" LUAN "��\n");

        if (me->query_skill_mapped("staff") != "fengmo-zhang")
                return notify_fail("��û�м�����ħ�ȷ�������ʩչ" LUAN "��\n");

        if ((int)me->query_skill("force") < 150)
                return notify_fail("����ڹ���򲻹�������ʩչ" LUAN "��\n");

        if ((int)me->query("neili") < 200)
                return notify_fail("�����ڵ��������㣬����ʩչ" LUAN "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIY "$N" HIY "����ɱ����ʢ��ʩ����ħ�ȡ�" HIR "Ⱥħ����"
              HIY "������������" + weapon->name() + HIY "�Ӷ�������$n"
              HIY "��ȥ��\n" NOR;
        message_combatd(msg, me, target);

        me->add("neili", -200);

        for (i = 0; i < 6; i++)
        {
                if (! me->is_fighting(target))
                        break;

                if (random(3) && ! target->is_busy())
                        target->start_busy(1);

                COMBAT_D->do_attack(me, target, weapon, 0);
        }
        me->start_busy(2);
        return 1;
}

