// kuang.c ��ɨ��Ҷ

#include <ansi.h>

inherit F_SSERVER;

#define SAO "��" HIG "��ɨ��Ҷ" NOR "��"
 
int perform(object me, object target)
{
	object weapon;
        string msg;
        int count;
        int i;
 
        if (! target)
        {
	        me->clean_up_enemy();
	        target = me->select_opponent();
        }



	if (! target || ! me->is_fighting(target))
		return notify_fail(SAO "ֻ�ܶ�ս���еĶ���ʹ�á�\n");
 
	if (! objectp(weapon = me->query_temp("weapon")) ||
	    (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԣ�\n");

	if ((int)me->query("neili") < 180)
		return notify_fail("��������������޷�ʩչ" SAO "��\n");

	if ((int)me->query_skill("kuangfeng-jian", 1) < 100)
		return notify_fail("��Ŀ�罣���������ң��޷�ʩչ" SAO "��\n");

	if ((int)me->query_skill("dodge", 1) < 100)
		return notify_fail("����Ṧ��Ϊ���㣬�޷�ʩչ" SAO "��\n");

        if (! living(target))
               return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

	msg = HIC "$N" HIC "���һ�������е�" + weapon->name() +
              HIC "�����缲��һ��������$n" HIC "��\n"
              HIR "��ʱ��ֻ�������������粨�˰���ӿ����$n"
              HIR "ֻ���ú�����ʱ������\n" NOR;
	message_combatd(msg, me, target);
	me->add("neili", -150);

	count = me->query_skill("sword") / 3;
	me->add_temp("apply/attack", count);

        for (i = 0; i < 7; i++)
        {
                if (! me->is_fighting(target))
                        break;
                if (! target->is_busy() && random(2) == 1)
                        target->start_busy(1);
        	COMBAT_D->do_attack(me, target, weapon, 0);
        }

	me->add_temp("apply/attack", -count);
	me->start_busy(2);
	return 1;
}
