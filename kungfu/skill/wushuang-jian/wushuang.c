// wushuang.c  ��˫�޶�

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
	object weapon;
	int damage;
	string msg;

	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("��˫�޶�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");
		
	if( (int)me->query_skill("wushuang-jian", 1) < 150 )
		return notify_fail("�����˫����������죬����ʹ�á���˫�޶ԡ���\n");
			
			
	if( (int)me->query("neili", 1) < 300 )
		return notify_fail("����������̫��������ʹ�á���˫�޶ԡ���\n");

// ���� busy + attack pfm ��ô��û�����ƣ������������ɱ�� (by xbd)			
	if( target->is_busy() )
		return notify_fail(target->name() + "Ŀǰ����æ���ң��㾡�ܷ��ֽ����ɣ�\n");

	msg = CYN "$N΢΢һЦ������һ����,��ʹ������Ԧ����������$n��\n"NOR;

	if( !target->is_killing(me) ) me->kill_ob(target);

        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 )
         {
              target->start_busy( (int)me->query_skill("wushuang-jian") / 50 + 1);
		
               damage = (int)me->query_skill("wuji-shengong", 1);
                damage = damage +  (int)me->query_skill("wuji-shengong", 1);
		damage = damage +  (int)me->query_skill("wushuang-jian", 1);
		
		target->receive_damage("qi", damage);
		target->receive_wound("qi", damage/3);
		me->add("neili", -damage);
		msg += HIR"ֻ��$N���н������һ������,�ڿն���,ٿ������$n,\n$nֻ��һ�ɴ�������ǵذ�ѹ��,��ʱ��ǰһ������������,�۵����һ����Ѫ����\n"NOR;
		me->start_busy(2);
	} else 
	{
		msg += CYN"����$p�͵���ǰһԾ,������$P�Ĺ�����Χ��\n"NOR;
		me->add("neili", -100);
		me->start_busy(4);
	}
	message_vision(msg, me, target);

	return 1;
}
