// cui.c ���Ķϳ�

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        string msg;
        string skill;
        int ap, fp, dp, damage;


        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! me->is_fighting(target))
                return notify_fail("�����Ķϳ���ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (me->query_skill("shedao-qigong", 1) < 120)
                return notify_fail("����ߵ��湦��Ϊ���ޣ�����ʹ�á����Ķϳ�����\n");
        if (me->query_skill("shenlong-xinfa", 1) < 50)
                return notify_fail("��ı����ڹ���Ϊ���ޣ�����ʹ�á��������֡���\n");

        if (me->query("neili") < 250)
                return notify_fail("��������������޷����á����Ķϳ�����\n");

        if (objectp(weapon = me->query_temp("weapon")) &&
            weapon->query("skill_type") != "staff" &&
            weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õı������ԣ���ôʹ�á����Ķϳ�����\n");

        if (weapon)
                skill = weapon->query("skill_type");
        else
                skill = "unarmed";


       if (! living(target))
              return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        switch (skill)
        {
        case "unarmed":
                msg = HIW "$N" HIW "һ�����ȣ�˫��һ���������ʱ���ɰ��ʯ��$n"
                      HIW "ֻ���ü�����Ϣ��\n" NOR;
                break;

        case "sword":
                msg = HIW "$N" HIW "һ�����ȣ�����" + weapon->name() +
                      HIW "ֱ�����£�ֻ����Х�����������ϵĳ��������������׷׷������\n" NOR;
                break;

        case "staff":
                msg = HIW "$N" HIW "һ�����ȣ�����" + weapon->name() +
                      HIW "��ɨ������һʱ�䳾�����$n"
                      HIW "��ʱ���ú���������\n" NOR;
                break;
        }

        ap = me->query_skill(skill);
        fp = target->query_skill("force");
        dp = target->query_skill("dodge");
        if (ap / 2 + random(ap) < fp)
        {
                me->add("neili", -200);
                msg += CYN "����$n" CYN "�ڹ���񣬷�������$N"
                       CYN "��һ�У�˿������\n" NOR;
                me->start_busy(2);
        } else
        if (ap / 2 + random(ap) < dp)
        {
                me->add("neili", -50);
                msg += CYN "$n" CYN "����һЦ��Ʈ��Ծ������$N"
                       CYN "��һ��ȫȻ��ա�\n" NOR;
                me->start_busy(2);
        } else
        {
                me->add("neili", -220);
                me->start_busy(2);
                damage = 150 + ap + random(ap);
        if (target->query("qi") > damage)
        {
        target->add("qi",-damage);
        target->add("eff_qi",-damage);
        }
	target->apply_condition("ill_fashao",60);
	target->apply_condition("ill_kesou",60);
	target->apply_condition("ill_shanghan",60);
	target->apply_condition("ill_zhongshu",60);
	target->apply_condition("ill_dongshang",60);

                msg +=HIR "$n" HIR "ֻ����$N" HIR "��������"
                                           "��ɽ����һ�㣬���ֵܵ������ۡ���һ���³�һ�����Ѫ��\n" NOR;
        }
        message_combatd(msg, me, target);

        return 1;
}
