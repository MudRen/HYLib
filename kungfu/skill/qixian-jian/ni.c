#include <ansi.h>
#include <combat.h>

#define NI "��" HIW "��תǬ��" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        string msg;
        int ap, dp;
        int damage;
int skill;

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(NI "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
              (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԣ�����ʩչ" NI "��\n");

        if (me->query_skill("force") < 300)
                return notify_fail("����ڹ�����Ϊ����������ʩչ" NI "��\n");



        if (me->query("neili") < 400)
                return notify_fail("�����������������ʩչ" NI "��\n");

skill=me->query_skill("qixian-jian",1);
        if (skill < 180)
                return notify_fail("����������ν���Ϊ���ޣ������޷�ʹ��" NI "��\n");

        if (me->query("neili") < 500)
                return notify_fail("��������������޷�����" NI "��\n");

        weapon = me->query_temp("weapon");

        if (weapon && weapon->query("skill_type") != "sword")
                return notify_fail("�㲻��ʹ�����ֱ���ʩչ" NI "��\n");

        if (weapon && me->query_skill_mapped("sword") != "qixian-jian")
                return notify_fail("������û��׼��ʹ���������ν����޷�ʩչ" NI "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIW "$N" HIW "һ����Х������" + weapon->name() +
              HIW "һ�񣬽�Ǭ����������ʩչ����ʱ��Ӱ���أ���"
              "���⻪ֱ׷$n" + HIW "��ȥ��\n" NOR;

        ap = me->query_skill("sword") + me->query_skill("force");
        dp = target->query_skill("dodge") + target->query_skill("parry");

        if (ap / 2 + random(ap) > dp)
        {
                damage = ap / 3 + random(ap / 3);
                me->add("neili", -200);
                me->start_busy(2);
                        target->add("qi",-damage+100);
                        target->add("qi",-damage+100);
if (random(3)==0) target->start_bus(5);
                        msg +=HIR "$n" HIR "��ȫ�޷�����������ʵ��΢"
                                           "΢һ��䣬����" + weapon->name() + HIR
                                           "����û���Լ��ؿ����硣\n" NOR;
        } else
        {
                me->add("neili", -80);
                me->start_busy(2);
                msg += CYN "����$n" CYN "����" CYN "$N" CYN
                       "������������һԾ�������������Ī��"
                       "��һ����\n"NOR;
        }
        message_combatd(msg, me, target);

        return 1;
}
