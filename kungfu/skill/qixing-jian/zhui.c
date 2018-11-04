#include <ansi.h>
#include <combat.h>

#define ZHUI "��" HIR "׷�����" NOR "��"

inherit F_SSERVER;

string final(object me, object target, int damage);

int perform(object me, object target)
{
        object weapon;
        string msg;
        int ap, dp;
        int damage;


        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(ZHUI "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԣ�����ʩչ" ZHUI "��\n");

        if (me->query_skill("qixing-jian", 1) < 60)
                return notify_fail("�����ǽ�����Ϊ����������ʩչ" ZHUI "��\n");

        if (me->query_skill_mapped("sword") != "qixing-jian")
                return notify_fail("��û�м������ǽ���������ʩչ" ZHUI "��\n");

        if (me->query("neili") < 200)
                return notify_fail("��������������������ʩչ" ZHUI "��\n");

        if (! living(target))
               return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIR "$N" HIR "һ����ߣ�����" + weapon->name() +
              HIR "һʽ��׷��������������ʱ����һ��Ѫ�⣬ֱ��$n"
              HIR "��\n" NOR;

        me->add("neili", -150);
        ap = me->query_skill("sword");
        dp = target->query_skill("dodge");

if (random(3)==0) target->start_busy(2);
        me->start_busy(2);
        if (ap  + random(ap) > dp)
        {
                damage = ap  + random(ap / 2);
target->add("qi",-damage*3);
		target->add("eff_qi",-damage*3);
                msg +=HIR "ֻ��$n" HIR "һ���ҽУ�����һ�����ض��룬��"
                "ʱ��Ѫ�Ĵ��ɽ���\n" NOR;
        } else
        {
                msg += CYN "��$n" CYN "ȴ������㣬һ˿���ң�"
                       "ȫ�񽫴��л��⿪����\n" NOR;
        }
        message_combatd(msg, me, target);

        return 1;
}



