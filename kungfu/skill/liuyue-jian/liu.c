#include <ansi.h>
#include <combat.h>

#define LIU "��" HIY "���½���" NOR "��"

inherit F_SSERVER;
 
int perform(object me, object target)
{
        object weapon;
        string msg;
        int ap, dp;
        int damage;


        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(LIU "ֻ����ս���жԶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
              (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԣ�����ʩչ" LIU "��\n");

        if (me->query_skill("force") < 180)
                return notify_fail("����ڹ�����Ϊ����������ʩչ" LIU "��\n");

        if (me->query_skill("liuyue-jian", 1) < 120)
                return notify_fail("������½�����Ϊ����������ʩչ" LIU "��\n");

        if (me->query("neili") < 250)
                return notify_fail("�����������������ʩչ" LIU "��\n");


        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIY "$N" HIY "һ����Х���������䣬����" + weapon->name() + HIY
              "���Ữ��������һ���ޱ�Ѥ���Ľ�â��ңָ$n" HIY "��ȥ��\n" NOR;
        ap = me->query_skill("sword");
        dp = target->query_skill("parry");

        if (ap / 2 + random(ap) > dp)
        {
                damage = ap * 2 / 3 + random(ap);
                me->add("neili", -150);
                me->start_busy(2);
                target->add("qi",-damage);
		target->add("eff_qi",-damage);
                msg +=HIR "$n" HIR "��ʱĿ�ɿڴ���һ����������$N"
                                           HIR "����Ľ��д��У���Ѫ�ɽ���\n" NOR;
        } else
        {
                me->add("neili", -60);
                me->start_busy(2);
                msg += CYN "����$p" CYN "�������ң�������������񵲿���$P"
                       CYN "�Ľ��С�\n"NOR;
        }
        message_combatd(msg, me, target);

        return 1;
}

