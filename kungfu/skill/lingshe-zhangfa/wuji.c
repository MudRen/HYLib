// wuji.c �����޼�

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
 
int perform(object me, object target)
{
	object weapon;
        string msg;
        int ap, dp;
        int damage;
 
        if (! target)
        {
	        me->clean_up_enemy();
	        target = me->select_opponent();
        }

	if (! target || ! me->is_fighting(target))
		return notify_fail("�������޼ɡ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
 	if( (int)me->query_skill("hamagong", 1) < 100 )
		return notify_fail("��ĸ�󡹦�������.\n");
		
	if (! objectp(weapon = me->query_temp("weapon")) ||
	    (string)weapon->query("skill_type") != "staff")
		return notify_fail("���á������޼ɡ��������г��ȣ�\n");

	if ((int)me->query_skill("force") < 200)
		return notify_fail("����ڹ���򲻹�����������ʹ�á������޼ɡ���\n");

	if ((int)me->query("neili") < 300)
		return notify_fail("�����ڵ������������޷�ʹ�á������޼ɡ���\n");

	if ((int)me->query_skill("lingshe-zhangfa", 1) < 150)
		return notify_fail("��������ȷ��������ң��޷�ʹ�á������޼ɡ���\n");

	if (me->query_skill_mapped("staff") != "lingshe-zhangfa") 
		return notify_fail("��û�м��������ȷ����޷�ʹ�á������޼ɡ���\n");

       if (! living(target))
              return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIY "$N" HIY "һ����Ц�����е�" + weapon->name() + HIY "��Ȼ���"
              "��ͬ����һ�㣬ʱ��ʱ�£�������ң���֪����$n" HIY "�δ���\n" NOR;
        ap = me->query_skill("staff");
        dp = target->query_skill("parry");
        if (ap / 2 + random(ap) > dp)
	{
		damage = ap + random(ap);
                me->add("neili", -200);
target->add("qi",-damage*2);
target->add("eff_qi",-damage);
target->apply_condition("snake_poison",10);
target->apply_condition("chanchu_poison",10);
target->apply_condition("qx_snake_poison",20);
                        target->add("qi",-damage+100);
                        target->add("qi",-damage/2+100);

                        msg +=                    HIR "$n" HIR "ʵ���޷�������$P"
                                           HIR "��ʵ�У��������գ��������У�"
                                           "��ʱ����һ����Ѫ��\n" NOR;
		me->start_busy(2);
                target->start_busy(1);
	} else 
	{
		msg += CYN "$n" CYN "�����мܣ�����ֵ�ס��$P"
                       CYN "�Ĺ�����\n" NOR;
                me->add("neili", -80);
		me->start_busy(2);
                target->start_busy(1);
	}
	message_combatd(msg, me, target);

	return 1;
}
