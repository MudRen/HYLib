// qi.c ���ν���

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        int damage;
        string msg;
        int ap, dp;

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail("���ν���ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if ((int)me->query_skill("force") < 360)
                return notify_fail("����ڹ���򲻹���ʹ�������ν�����\n");

        if ((int)me->query_skill("six-finger", 1) < 180)
                return notify_fail("�����ݤ�񽣲�������������ʹ�����ν�����\n");

        if (me->query("max_neili") < 8000)
                return notify_fail("���������Ϊ��������ʹ�����Ϭ�������ν�����\n");
        if ((int)me->query_skill("kurong-changong",1) < 100)
            return notify_fail("��Ŀ�������̫�͡�\n");
        if ((int)me->query("neili") < 500)
                return notify_fail("��������������޷�ʹ�����ν�����\n");

        if (me->query_skill_mapped("finger") != "six-finger")
                return notify_fail("��û�м��������񽣣��޷�ʹ�����ν�����\n");

       if (! living(target))
              return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIC "$N" HIC "��ָһ����һ���������׵����ν���ֱ��$n" HIC "��ǰ��ȥ��\n" NOR;  

        ap = me->query_skill("force");
        dp = target->query_skill("force");
        weapon = target->query_temp("weapon");
        me->start_busy(2);
        if (ap / 2 + random(ap) > dp)
        { 
                damage = ap + random(ap / 2);
                me->add("neili", -400);
                if (! objectp(weapon) || weapon->query("skill_type") == "pin")
{
                target->add("qi",-damage);
		target->add("eff_qi",-damage);
                msg +=HIR "ֻ������ǰһ���ʹ����Ѫ"
                                                   "�Դ��ڼ����������ǰ��ʱһ�ڣ�\n" NOR;
 }
                else
                if (weapon->query("ownmake") || weapon->query("damage") > 800 ||
                    weapon->query("skill_type") == "hammer")
{
                target->add("qi",-damage);
		target->add("eff_qi",-damage);
                msg +=HIR "$p" HIR "��" + weapon->name() + HIR "��ͼ�мܣ�"
                                                   HIR "������ɽ������Ϭ����͸��" + weapon->name() +
                                                   HIR "ֱ���$p" HIR "������Ѫ������������Ҫ��ת������\n" NOR;
}
                else
                {
                target->add("qi",-damage);
		target->add("eff_qi",-damage);
                msg +=HIR "$p" HIR "��ת" + weapon->name() + HIR "��������"
                                                   "ǰ��ֻ��ž��һ����" + weapon->name() +
                                                   HIR "������أ��������죡\n$n" HIR "����"
                                                   "���������ۡ�������һ����Ѫ����ɫ��ĲҰס�\n" NOR;

                        weapon->move(environment(me));
                }
        } else
        {
                msg += CYN "����$p" CYN "�ڹ���Ϊ������Ὣ����������������Ρ�\n" NOR;
        }
        message_combatd(msg, me, target);

        return 1;
}

