#include <ansi.h>
#include <combat.h>

#define PO "��" HIW "��Ԫ����" NOR "��"

inherit F_SSERVER;

string final(object me, object target, int damage);

string *finger_name = ({ "������ָ", "��������ָ", "����ʳָ",
                         "������ָ", "��������ָ", "����ʳָ", }); 

int perform(object me, object target)
{
        int damage;
        string msg, name;
        object weapon;
        int lvl, ap, dp;


        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(PO "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        weapon = me->query_temp("weapon");

        if (weapon && weapon->query("skill_type") != "sword"
           && weapon->query("skill_type") != "pin")
                return notify_fail("��ʹ�õ��������ԣ�����ʩչ" PO "��\n");

        if ((int)me->query_skill("kuihua-dafa", 1) < 180)
                return notify_fail("��Ŀ����񹦲�����죬����ʩչ" PO "��\n");

        if ((int)me->query("max_neili") < 2600)
                return notify_fail("���������Ϊ���㣬����ʩչ" PO "��\n");

        if (me->query("neili") < 300)
                return notify_fail("�����ڵ��������㣬����ʩչ" PO "��\n");

        if (weapon && me->query_skill_mapped("sword") != "kuihua-dafa")
                return notify_fail("��û��׼��ʹ�ÿ����񹦣�����ʩչ" PO "��\n");


        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");


        if (me->query_temp("weapon"))
                name = "����" + weapon->name();
        else
                name = finger_name[random(sizeof(finger_name))];

        msg = HIW "$N" HIW "һ����ߣ�˫����͸��һ˿������" + name +
              HIW "����ǧ�ٸ����ƣ��ó�������ɫ�ʣ�\n" NOR;

        ap = me->query_skill("sword") +
             me->query_skill("dodge");

        dp = target->query_skill("parry") +
             target->query_skill("dodge");

        if (ap / 2 + random(ap) > dp)
        {
                damage = ap + random(ap)+600;
                target->add("qi",-damage);
		target->add("eff_qi",-damage);
                target->set("neili", target->query("neili")/2);
                msg +=HIR "$n" HIR "ֻ����ǰ��âһ���������漴ȫ��һ��"
               "��ʹ������Ѫ�������������\n$p��Ȼ��һ��������"
               "�����������������ƻ�ɢһ�㣬ȫȻ�޷����ơ�\n" NOR;
                me->start_busy(3);
                me->add("neili", -200);
        } else
        {
                msg += CYN "$n" CYN "��֮��ȫȻ�޷��мܣ���æ"
                       "���������ߣ��㿪����һ�С�\n" NOR;
                me->start_busy(3);
                me->add("neili", -150);
        }
        message_combatd(msg, me, target);
        return 1;
}

