#include <ansi.h>
#include <combat.h>

#define ZHEN "��" HIW "��豹���" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        int damage;
        string msg;
        int i, ap, dp;
        object weapon;


        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(ZHEN "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon")) 
                return notify_fail(ZHEN "ֻ�ܿ���ʹ�á�\n");

        if ((int)me->query_skill("force") < 300)
                return notify_fail("���ڹ���Ϊ����������ʩչ" ZHEN "��\n");

        if ((int)me->query("max_neili") < 3600)
                return notify_fail("��������Ϊ����������ʩչ" ZHEN "��\n");

        if ((int)me->query_skill("tmzhang", 1) < 220)
                return notify_fail("��ħ�Ʒ���򲻹�������ʩչ" ZHEN "��\n");

        if (me->query_skill_mapped("strike") != "tmzhang")
                return notify_fail("��û�м�����ħ�Ʒ�������ʩչ" ZHEN "��\n");



        if ((int)me->query("neili") < 500)
                return notify_fail("��������������������ʩչ" ZHEN "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIW "��Ȼ��$N" HIW "ʩ����" HIY "�" HIW "���־���˫����$n"
              HIW "ƽƽ��ȥ��������ʵ�޻������ް�㻨�ɿ��ԡ�\n" NOR;  


        ap = (int)me->query("combat_exp");
        dp = (int)target->query("combat_exp");

        if (ap / 2 + random(ap) > dp)
        { 
                damage = me->query_skill("tmzhang",1) + random(me->query_skill("tmzhang",1) / 2)+ 500;
                target->add("qi",-damage);
		target->add("eff_qi",-damage);
                msg +=HIR "$n" HIR "���Ʋ�͸������ʵ��$N" HIR
                                           "˫������$p" HIR "ǰ�أ������꿦�ꡱ��"
                                           "�����������߹ǡ�\n" NOR;
        } else
        {
                msg += CYN "$n" CYN "��$N" CYN "�������ƷǷ�������"
                       "�����мܣ�����������Ծ������\n" NOR;
        }

        msg += HIW "\n������$N" HIW "���С�" HIY "��" HIW "���־�����"
               "ʱֻ��$N" HIW "˫�Ʒ׷ɣ�����������Ӱ����$n" HIW "����"
               "�˷���\n"NOR;
        message_combatd(msg, me, target);


        for (i = 0; i < 5; i++)
        {
                if (! me->is_fighting(target))
                        break;

                if (random(3) == 1 && ! target->is_busy())
                        target->start_busy(1);

        	COMBAT_D->do_attack(me, target, 0, 0);
        }
        me->add("neili", -400);
        me->start_busy(3);
        return 1;
}

