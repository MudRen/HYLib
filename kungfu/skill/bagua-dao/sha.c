#include <ansi.h>
#include <combat.h>

#define SHA "��" HIR "ɱ���޻�" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        string msg;
        int ap, dp;
        int damage;
 
        if (! target) target = offensive_target(me);


        if (! target || ! me->is_fighting(target))
                return notify_fail(SHA "ֻ����ս���жԶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
              (string)weapon->query("skill_type") != "blade")
                return notify_fail("��ʹ�õ��������ԣ�����ʩչ" SHA "��\n");

        if (me->query_skill("force") < 250)
                return notify_fail("����ڹ���Ϊ����������ʩչ" SHA "��\n");

        if (me->query_skill("bagua-dao", 1) < 180)
                return notify_fail("��İ��Ե�����Ϊ����������ʩչ" SHA "��\n");

        if (me->query_skill_mapped("blade") != "bagua-dao")
                return notify_fail("��û�м������Ե���������ʩչ" SHA "��\n");

        if ((int)me->query_skill("linji-zhuang", 1) < 120)
                return notify_fail("����ټ�ʮ��ׯ���̫ǳ��\n");
                
        if (me->query("neili") < 300)
                return notify_fail("�����������������ʩչ" SHA "��\n");


        msg = HIR "$N" HIR "������Х������" + weapon->name() +
              HIR "б����һ���뻡�����������ʱ���������ޱȵ�"
              "ɱ����ֱ��$n" HIR "��ȥ��\n" NOR;

        ap = me->query_skill("blade") + me->query_str() * 10;
        dp = target->query_skill("force") + target->query_con() * 10;

        if (ap / 2 + random(ap) > dp)
        {
                damage = ap  + random(ap);
                me->add("neili", -200);
                me->start_busy(2);
		target->add("qi",-damage);
		target->add("eff_qi",-damage/2);
		msg +=                     HIR "ֻ��$n" HIR "һ���ҽУ�$N" HIR +
                                           weapon->name() + HIR "����һ��������Ƕ"
                                           "��$p" HIR "���ڳ�������һ��Ѫ�ꡣ\n"
                                           NOR;

        } else
        {
                me->add("neili", -100);
                me->start_busy(2);
                msg += CYN "$n" CYN "��$P" CYN "������ӿ���������׵�"
                       "������æ������Ų������������\n" NOR;
        }
        message_combatd(msg, me, target);

        return 1;
}
