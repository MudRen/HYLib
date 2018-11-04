#include <ansi.h>
#include <combat.h>

#define JIAN "��" HIW "���칦" HIR "Ǭ��" HIY "����" NOR "��"

inherit F_SSERVER;


int perform(object me, object target)
{
        int ap, dp, i, damage;
        string msg;


        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(JIAN "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(JIAN "ֻ�ܿ���ʩչ��\n");

        if ((int)me->query_skill("xiantian-qigong", 1) < 280)
                return notify_fail("������칦��Ϊ����������ʩչ" JIAN "��\n");
        if(me->is_busy())
        return notify_fail("��������æ��\n");


        if (me->query("max_neili") < 5000)
                return notify_fail("���������Ϊ���㣬����ʩչ" JIAN "��\n");

        if (me->query_skill_mapped("unarmed") != "xiantian-qigong")
                return notify_fail("��û�м������칦Ϊȭ�ţ�����ʩչ" JIAN "��\n");





        if (me->query_skill_mapped("force") != "xiantian-qigong"         )
                return notify_fail("��û��׼�����칦������ʩչ" JIAN "��\n");

        if (me->query("neili") < 1000)
                return notify_fail("�����ڵ��������㣬����ʩչ" JIAN "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIY "��ʱֻ��$N" HIY "����" HIW "��������" HIY "����Ϊ" HIR
              "�����ھ�" HIY "����ָ�⣬��һ��ָ���ַ�����$n" HIY "ȫ����"
              "��ҪѨ��\n" NOR;  

        ap = me->query_skill("force") + me->query_skill("finger") +
             me->query_skill("unarmed");
        dp = target->query_skill("force") + target->query_skill("dodge") +
             target->query_skill("parry");

        if (ap * 11 / 20 + random(ap) > dp)
        { 
                damage = me->query_skill("force")*3;
		target->add("qi",-damage);
		target->add("eff_qi",-damage/2);
                me->add("neili", -150);
		msg +=   HIR "$n" HIR "ֻ��ȫ��һ�ȣ�$P" HIR "��"
                                           HIW "���칦" HIR "Ǭ��" HIY "����" HIR
                                           "����ʱ������룬�������ú�¯�����һ��"
                                           "��Ѫ��\n" NOR;

                message_combatd(msg, me, target);
        } else
        {
                msg += CYN "$n" CYN "��$N" CYN "��ָ������ӿ������"
                       "�����мܣ�����������Ծ������\n" NOR;
                message_combatd(msg, me, target);
        }

        msg = HIR "������$N" HIR "ʮָ�׷ɣ����������������ν�����$n" HIR "�����"
              "���Ա����������֡�\n"NOR;
        message_combatd(msg, me, target);

        me->add_temp("apply/attack", 100);

        for (i = 0; i < 5; i++)
        {
                if (! me->is_fighting(target))
                        break;

                if (random(3) == 1 && ! target->is_busy())
                        target->start_busy(3);

                COMBAT_D->do_attack(me, target, 0, 0);
        }

        me->add_temp("apply/attack", -100);
        me->add("neili", -600);
        me->start_busy(4 + random(3));
        return 1;
}
