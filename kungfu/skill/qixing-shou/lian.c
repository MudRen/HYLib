#include <ansi.h>
#include <combat.h>

#define LIAN "��" HIR "����������" NOR "��"

inherit F_SSERVER;
 
int perform(object me, object target)
{
	object weapon;
        string msg;
        mapping p;
        int i, af;


        if (! target)
        {
	        me->clean_up_enemy();
	        target = me->select_opponent();
        }

	if (! target || ! me->is_fighting(target))
		return notify_fail(LIAN "ֻ�ܶ�ս���еĶ���ʹ�á�\n");
 
	if (objectp(me->query_temp("weapon")))
                return notify_fail(LIAN "ֻ�ܿ���ʩչ��\n");


        if ((int)me->query_skill("qixing-shou", 1) < 150)
                return notify_fail("�����Ƿ����ֲ�����죬����ʩչ" LIAN "��\n");


	if ((int)me->query_skill("force") < 120)
		return notify_fail("����ڹ���򲻹�������ʩչ" LIAN "��\n");

	if ((int)me->query("neili") < 100)
		return notify_fail("��Ŀǰ���������㣬����ʩչ" LIAN "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

	msg = HIY "$N" HIY "���һ����ʩ����" HIR "����������" HIY "������"
              "ʱ˫�Ʒ׷ɣ���$n" HIY "�͹���ȥ��\n" NOR;
	message_combatd(msg, me, target);
	me->add("neili", -80);

//        af = member_array("strike", keys(p));

        for (i = 0; i < 5; i++)
        {
                if (! me->is_fighting(target))
                        break;

                me->set_temp("action_flag", af);
        	COMBAT_D->do_attack(me, target, 0, 0);
        }

	me->start_busy(2);
	return 1;
}
