// wuqing.c ��Ůȭ-��Ĺ�ľ�
// by liu 24/07/2001
// Xuanyuan 5/9/2001�޸�

/*
�����������������С��Ů���ϣ�����֧�ã���������ӳ�����̾һ�������ּ�
��֮�⡣���ǡ���Ůȭ�������һ�е���ʽ����������Ĺ�ľӡ���ȴ���������
�����ֳ�Ӣ��Ȼ��֪��С��ŮҲ�ǲ��ᡣ�������ѧȫ����Ůȭ��֮��������
ʦ�������ݵ��У������ڹŴ���Ů���书֮�߸�����˵����·ȭ����������ʦ��
���ڣ��㲻�������Ա�����������������һ�У���˵Ϊ��д�ֳ�Ӣ��������ֹ��
̬ȴ��ģ����ʦ��С��Ů������С��Ů������ֻ��΢΢һ�ӣ���Ҳ���������ȥ
���֡�
*/

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
                return notify_fail("�����Ůȭ��Ϊ����������ʹ�ù�Ĺ�ľӡ�\n");

        if( (int)me->query_skill("force", 1) < 120 )
                return notify_fail("����ڹ���δ��죬�����ù�Ĺ�ľӡ�\n");

	if( me->query_skill_mapped("force") != "yunv-xinfa" )
		return notify_fail("�����õĲ�����Ů�ľ���ʹ������Ĺ�ľӣ�\n");

        if( (int)me->query("neili", 1) < 1000 )
                return notify_fail("����������̫��������ʹ�ù�Ĺ�ľӡ�\n");

        if( (int)me->query("jing", 1) < 500 )
                return notify_fail("�����ھ���̫��������ʹ�ù�Ĺ�ľ� n��\n");

	if( jiali > 50 )
	return notify_fail("��Ĺ�ľ������ϳ��ڼҹ������ϼӴ�����̫���޷�ʹ����\n");

	msg = HIB "\n$N����������Ҫ����������֧�ã�����������$n�ӳ�����̾һ�������ּ���֮�⡣\n\n"NOR;

	msg += HIY"���ǡ���Ůȭ�������һ�е���ʽ����������Ĺ�ľӡ���ȴ��������Դ����ֳ�Ӣ��Ȼ\n";
	msg += HIY"��֪��������С��ŮҲ�ǲ��ᡣ�����������ѧȫ����Ůȭ��֮��������ʦ��������\n";
	msg += HIY"���в����ڹŴ���Ů���书֮�߸�����˵����·ȭ����������ʦ�����ڣ��㲻��������\n";
	msg += HIY"������������������һ�У���˵Ϊ��д�ֳ�Ӣ��������ֹ��̬ȴ��ģ����ʦ��С��Ů��\n\n";

  if( random( me->query("combat_exp") ) > random( target->query("combat_exp")/2 ) || !living(target) )
  {
	damage = random(  me->query_skill("force") + me->query_skill("cuff") + me->query("jiali") )*( 1 + random(me->query("jiali")/5) ) ;
	if(damage > 2000) damage = 2000;
	if(damage < 300) damage = 300;
	me->add("neili", -damage/2 );

	target->receive_damage("qi", damage,  me);
	target->receive_wound("qi", random(damage), me);

	if ( damage < 800) {
		msg += HIR"ֻ���۵�һ����$n��һȭ����С������Ѫ��ӿ��ڶ�����\n"NOR;
	}else if ( damage < 1400) {
		msg += HIR"ֻ���顢��������$n���۷��ࡢ���۷��ϣ��Ǳ�������\n"NOR;
	}else if ( damage < 2000) {
		msg += HIR"������䡹��һ����$nȫ����Ѫ������������Ѫ���������\n"NOR;
	}else {
		msg += RED"ֻ���顢�顢�顢�鼸�����죬$n����ù������ѷ��˳�ȥ��\n"NOR;
	}
	msg += NOR;
	me->start_busy(2);
	}
	else {
	msg += HIG"$n���һ�֣�����Ծ�𣬱��ܵķ�Ӧ�ٿ���$N�����䡣\n\n"NOR;
	me->add("neili", -jiali*2 );
	me->start_busy(2);
	message_vision(msg+"\n", me, target);
	return 1;
  }

	message_vision(msg+"\n", me, target);
	COMBAT_D->report_status(target);
	return 1;
}
