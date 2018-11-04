#include <ansi.h>
#include "/kungfu/skill/eff_msg.h";

#define JIA "��" HIY "���м���" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        int ap, dp, damage, p;
        string pmsg;
        string msg;
        object weapon;


        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(JIA "ֻ����ս���жԶ���ʹ�á�\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(JIA "ֻ�ܿ���ʩչ��\n");


       if((int)me->query_skill("linji-zhuang", 1) < 50 )
            return notify_fail("����ټ�ʮ��ׯ�ȼ�������\n"); 

        if (me->query_skill_mapped("strike") != "bagua-zhang") 
                return notify_fail("��û�м��������ƣ�����ʩչ" JIA "��\n");


        if ((int)me->query_skill("bagua-zhang", 1) < 120)
                return notify_fail("��İ����Ʋ�����죬����ʩչ" JIA "��\n");


        if ((int)me->query_skill("force") < 150)
                return notify_fail("����ڹ���򲻹�������ʩչ" JIA "��\n");

        if ((int)me->query("neili") < 150)
                return notify_fail("�������������㣬����ʩչ" JIA "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        me->add("neili", -100);

        msg = HIY "$N" HIY "һ�����ȣ�һ�����ػ���$n" HIY "��$p" HIY
              "�����񵲣���Ȼֻ����ǰ���һ����һ�ɾ�������$N" HIY
              "���м��������\n" NOR;

        me->start_busy(2);

        ap = me->query_skill("strike") + me->query_skill("throwing");
        dp = target->query_skill("dodge") + target->query_skill("parry");

        if (ap / 2 + random(ap) > dp)
        {
                damage = ap / 4 + random(ap / 4);
                msg += HIR "$n" HIR "����ʼ�ϲ�����$N" HIR "�Ǽ�ö����" +
                       HIR "���ô���$p" HIR "ҪѨ�ϣ���ʱѪ����ӿ��"
                       "����������\n" NOR;
                target->receive_damage("qi", damage * 2, me);
                target->receive_wound("qi", damage, me);
	        p = (int)target->query("qi") * 100 / (int)target->query("max_qi");
                message_combatd(msg, me, target);

        } else
        {
                msg += CYN "����$p" CYN "���ϵ�$P"
                       CYN "�д�һ�ţ�����һЦ��б��������\n" NOR;
                message_combatd(msg, me, target);
        }
        me->reset_action();
        return 1;
}
