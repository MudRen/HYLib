// rou.c ���־�

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	int damage;
	string msg;
        int ap, dp;

        if (! target)
        {
	        me->clean_up_enemy();
	        target = me->select_opponent();
        }
	if (! target || ! me->is_fighting(target))
		return notify_fail("�����־���ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (objectp(me->query_temp("weapon")))
		return notify_fail("��Ҫʩչȭ������ʹ��������\n");
		
	if ((int)me->query_skill("lingshe-quan", 1) < 120)
		return notify_fail("�������ȭ��������죬���ڻ��޷�ʹ�á����־�����\n");
        if ((int)me->query_skill("hamagong", 1) < 50)
                return notify_fail("��ĸ�󡹦������졣\n");	                        
	if ((int)me->query("neili") < 200)
		return notify_fail("�����������������޷����á����־�����\n");

       if (! living(target))
              return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

	msg = HIG "$N" HIG "һȭ�������;���ֱۺ�Ȼ����˼���ת�˸�Ȧ�ӣ�����$n"
              HIG "����$p" HIG "����ʤ����\n"NOR;

        ap = me->query_skill("unarmed");
        dp = target->query_skill("dodge");
	if (ap / 2 + random(ap) > dp)
	{
		target->start_busy(1);
		damage = (int)me->query_skill("force") + (int)me->query_skill("unarmed");
                damage = damage / 3;
                damage += random(damage);

		me->add("neili", -100);
target->add("qi",-damage*2);
target->add("eff_qi",-damage);
target->apply_condition("snake_poison",10);
target->apply_condition("chanchu_poison",10);

                        msg +=                 HIR "ֻ��$n" HIR "���һ�����ֻ�֮�²������㣬��$N"
                                           HIR "һȭ���˸����У��ƺ�һ��������������\n" NOR;
		me->start_busy(2);
	} else 
	{
		msg += HIC "����$p" HIC "�����Ŀ죬��æʩչ�����ܿ���ȭ��\n" NOR;
		me->add("neili", -50);
		me->start_busy(2);
	}
	message_combatd(msg, me, target);

	return 1;
}
