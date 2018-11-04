#include <ansi.h>
#include <combat.h>

#define ZHU "��" HIY "��������" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        string msg;
        int ap, dp;
        int damage;



        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(ZHU "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԣ�����ʩչ" ZHU "��\n");

        if ((int)me->query_skill("miaojia-jian", 1) < 120)
                return notify_fail("����ҽ���������죬����ʩչ" ZHU "��\n");

        if ((int)me->query_skill("force") < 150 )
                return notify_fail("����ڹ���򲻹�������ʩչ" ZHU "��\n");

        if ((int)me->query("max_neili") < 1200)
                return notify_fail("���������Ϊ����������ʩչ" ZHU "��\n");

        if ((int)me->query("neili") < 200)
                return notify_fail("��������������������ʩչ" ZHU "��\n");

        if (me->query_skill_mapped("sword") != "miaojia-jian")
                return notify_fail("��û�м�����ҽ���������ʩչ" ZHU "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIY "$N" HIY "��Ȧ����" + weapon->name() + HIY "ʩ���������项б"
              "������������ʱ�³�һ����â�����������$n" + HIY "��\n" NOR;

        ap = me->query_skill("sword",1);
        dp = target->query_skill("parry",1);

        if (ap / 2 + random(ap) > dp)
        {
                damage = me->query_skill("sword",1);
                
                me->start_busy(2);
		target->add("qi",-damage/2);
		target->add("eff_qi",-damage/2);
                me->add("neili", -150);
		msg +=                    HIR "$n" HIR "��״��æ�񵲣�����������"
                                           "������ʱֻ��ȫ��һ�飬������͸�ض�����\n"
                                           NOR;

        } else
        {
                me->add("neili", -50);
                me->start_busy(3);
                msg += CYN "����" CYN "$n" CYN "һ����"
                       "Ц������һԾ���𣬱ܿ���" CYN
                       "$N" CYN "�����Ľ�����\n"NOR;
        }
        message_combatd(msg, me, target);

        return 1;
}
