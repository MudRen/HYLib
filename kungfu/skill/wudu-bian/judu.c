//�嶾�޷�  �۶�

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	string msg;

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("��ֻ����վ���в��ܾ۶���\n");

	if( (int)me->query_skill("wudu-bian",1) < 60 
		||(int)me->query_skill("wudu-xinfa",1) < 50 )
		return notify_fail("����嶾�ķ�����̫ǳ���޷��۶���\n");

	if( target->is_busy() )
		return notify_fail(target->name() + "�Ѿ���æ�����ˣ�����Ҫ���ö��ˡ�\n");
	me->start_busy(1);
	msg = BLU "$NĬ�����������������ڱ��ϣ�ֻ��һ����ɫ��������ס�˳��ޡ�\n";

	if  ( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 
	    && random(me->query_skill("wudu-xinfa",1)) >20) 
	{
		msg += "$p�벻������������Ⱦ������\n" NOR;
	    target->receive_damage("qi",(int)me->query_skill("wudu-xinfa",1));
            target->receive_wound("qi",15 + random(10));
            target->receive_wound("jing", 10);
            target->apply_condition("wudu_poison", random(me->query_skill("wudu-xinfa",1)/10) + 1 +
			target->query_condition("wudu_poison"));
			target->start_busy(1 + random(2)); 
		
	} else {
		msg += "����$p������$P�Ķ��ƣ�������ס������û���ж���\n" NOR;
		
	}
	message_vision(msg, me, target);

	return 1;
}
