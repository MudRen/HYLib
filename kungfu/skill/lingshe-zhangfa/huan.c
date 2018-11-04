#include <ansi.h>
#include <combat.h>

#define HUAN "��" HIM "��ϼ����" NOR "��"

inherit F_SSERVER;

string final(object me, object target, int damage);

int perform(object me, object target)
{
        object weapon, weapon2;
        int skill, ap, dp, damage;
        string wn, msg;

        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! target || ! me->is_fighting(target))
                return notify_fail(HUAN "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "staff")
                return notify_fail("��ʹ�õ��������ԣ�����ʩչ" HUAN "��\n");

	if( (int)me->query_skill("hamagong", 1) < 100 )
		return notify_fail("��ĸ�󡹦�������.\n");
		
        skill = me->query_skill("lingshe-zhangfa", 1);

        if (skill < 120)
                return notify_fail("�������ȷ��ȼ�����������ʩչ" HUAN "��\n");

        if (me->query_skill("dodge") < 180)
                return notify_fail("����Ṧ��򲻹�������ʩչ" HUAN "��\n");
 
        if (me->query_skill_mapped("staff") != "lingshe-zhangfa")
                return notify_fail("��û�м��������ȷ�������ʩչ" HUAN "��\n");

        if (me->query("neili") < 200)
                return notify_fail("�����ڵ���������������ʩչ" HUAN "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        wn = weapon->name();

        message_vision(HIM "\n$N" HIM "���ʩ����" HIW "��ϼ����\n"
                     HIM "������������" + wn + HIM "��һ�����\n"
                     "�ɶ����ģ����ı�ˣ��ɰ˱�ʮ���������ó�\n"
                     "����������" + wn + HIM "����Ӱ������������\n"
                     "���̶�������ͼ����$n" HIM "����·��\n" NOR,
                     me, target);

        ap = me->query_skill("staff");
        dp = target->query_skill("parry");

        if (ap / 2 + random(ap * 4 / 3) > dp)
        {
                me->add("neili", -80);
                damage = 150 + ap / 6 + random(ap / 6);
        msg = HIR "$p��ʧɫ֮�½�����$P��������"
              "��������ʹ�ѵ���";
target->add("qi",-damage*2);
target->add("eff_qi",-damage);
target->apply_condition("snake_poison",10);
target->apply_condition("chanchu_poison",10);
target->apply_condition("qx_snake_poison",20);
        if (random(3) >= 1 && ! target->is_busy())
        {
                target->start_busy(5);
                msg += "��Ͼ������\n" NOR;
        } else
                msg += "����������\n" NOR;

                me->start_busy(1);
        } else
        {
                msg = CYN "$n" CYN "��֮�¼�æԾ�����������Ű���$N"
                      CYN "��Ӱ�ķ�Χ��\n" NOR;
                me->add("neili", -50);
                me->start_busy(2);
        }
        message_vision(msg, me, target);

        return 1;
}
