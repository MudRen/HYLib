// wuqing.c ��Ůȭ-��Ů����
// by liu 24/07/2001
// Xuanyuan 5/9/2001�޸�

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	object ob;
	string msg;
	int damage,jiali,jiajin;

	jiali = (int)me->query("jiali");
	jiajin= (int)me->query("jiali");

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("��Ů����ֻ�ܶ�ս���еĶ���ʹ�á�\n");

//        if( objectp(me->query_temp("weapon")) )
//                return notify_fail("������ȷ������еı�����\n");
        if( (int)me->query_skill("yunv-xinfa", 1) < 40 )
                return notify_fail("�����Ů�ķ���δ��죬�����������˵С�\n");
        if( (int)me->query_skill("meinv-quan", 1) < 120 )
                return notify_fail("�����Ůȭ���𲻹�������ʹ����Ů���顣\n");

        if( (int)me->query_skill("force", 1) < 120 )
                return notify_fail("����ڹ���δ��죬��������Ů���顣\n");

        if( (int)me->query("neili", 1) < 400 )
                return notify_fail("����������̫��������ʹ����Ů���顣\n");

        if( (int)me->query("jing", 1) < 200 )
                return notify_fail("�����ھ���̫��������ʹ����Ů���顣\n");

	msg = HIB "\n\n$N�����߶�������ȭ���ݺ����飡\n"NOR;
        msg += HIY "\n$N����֧�ã���������ӳ�����̾һ�������ּ���֮�⣬������ʹ��ɱ�С�\n\n"NOR;
  if( random( me->query("combat_exp") ) > random( target->query("combat_exp")/2 ) || !living(target) )
  {
			damage = random(  me->query_skill("force") + me->query_skill("cuff") + me->query("jiali") )*( 1 + random(me->query("jiali")/5) ) ;
			if(damage > 2300) damage = 2000;
			if(damage < 300) damage = 300;
			me->add("neili", -damage/2 );

			target->receive_damage("qi", damage,  me);
			target->receive_wound("qi", random(damage), me);

		if ( damage < 1000) {
			msg += HIR"ֻ�����һ����$n��һȭ����С������Ѫ��ӿ��ڶ�����\n"NOR;
		}else if ( damage < 2000) {
			msg += HIR"ֻ���顢��������$n���۷��ࡢ���۷��ϣ���Ѫֱ����\n"NOR;
		}else if ( damage < 3000) {
			msg += HIR"ֻ���顢�顢�������죬$n���ϱ��˼�����������Ѫ���硣\n"NOR;
		}else {
			msg += HIR"ֻ���顢�顢�顢�鼸�����죬$n����ù������ѷ��˳�ȥ��\n"NOR;
		}
		msg += NOR;
		me->start_busy(2);
  }
  else {
	 msg += HIG"$n���һ�֣�����Ծ�𣬱��ܵķ�Ӧ��$n�ӹ��˽١�\n\n"NOR;
	 me->add("neili", -jiali*2 );
	 me->start_busy(2);
	 message_vision(msg+"\n", me, target);
	 return 1;
  }

  message_vision(msg+"\n", me, target);
  COMBAT_D->report_status(target);
  return 1;
}
