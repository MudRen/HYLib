#include <ansi.h>
#include <combat.h>

#define FUMO "��" HIR "��ħ����" NOR "��"

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
                return notify_fail(FUMO "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԣ��޷�ʩչ" FUMO "��\n");

        if ((int)me->query_skill("yitian-jian", 1) < 120)
                return notify_fail("������콣��������죬�޷�ʩչ" FUMO "��\n");

        if (me->query("neili") < 200)
                return notify_fail("�����������������޷�ʩչ" FUMO "��\n");

        if (me->query_skill_mapped("sword") != "yitian-jian") 
                return notify_fail("��û�м������콣�����޷�ʩչ" FUMO "��\n");

        if (! living(target))
               return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIW "$N" HIW "һ����ߣ�����" + weapon->name() +
              HIW "һ�񣬽���΢������������������Я����������"
              "ͬʱ����$n" HIW "��\n" NOR;

        me->add("neili", -150);
        ap = me->query_skill("sword");
        dp = target->query_skill("parry");
        if ((int)target->query("shen") < 0) ap += ap / 5;

        me->start_busy(3);
        if (ap / 2 + random(ap) > dp)
        {
                damage = me->query_skill("sword");
   target->add("qi",-damage);
		target->add("eff_qi",-damage);
                msg += HIR "ֻ��$n" HIR "һ���ҽУ�����һ�����ض��룬��"
                "ʱ��Ѫ�Ĵ��ɽ���\n" NOR;
        } else
        {
                msg += HIC "��$n" HIC "ȴ������㣬һ˿���ң�"
                       "ȫ�񽫴��л��⿪����\n" NOR;
        }
        message_combatd(msg, me, target);

        return 1;
}

string final(object me, object target, int damage)
{
        return  HIR "ֻ��$n" HIR "һ���ҽУ�����һ�����ض��룬��"
                "ʱ��Ѫ�Ĵ��ɽ���\n" NOR;
}

