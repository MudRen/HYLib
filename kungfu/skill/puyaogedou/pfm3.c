// sui.c �ӷ�����

#include <ansi.h>
void remove_effect(object me, int a_amount, int d_amount);

inherit F_SSERVER;
int perform(object me, object target)
{
	object weapon;
	int skill;
	string msg;

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("�ӷ�����ֻ����ս����ʹ�á�\n");

	if( (int)me->query_skill("puyaogedou", 1) < 40 )
		return notify_fail("�㲻��ʹ�üӷ�������\n");
        if( me->query("up1") < 1 )
                return notify_fail("�����ڲ���ʹ�ô�pfm.\n");
        if( me->query("pfm3") < 1 )
                return notify_fail("�����ڲ���ʹ�ô�pfm.\n");


	if( (int)me->query_temp("uparmor") ) 
		return notify_fail("���Ѿ����˹����ˡ�\n");

	skill = me->query_skill("puyaogedou");
	msg = HIB "$N��м�������β�ͻ�Ȧ,�𽥽�����ס��\n"NOR;
	message_combatd(msg, me, target);
	me->add_temp("apply/damage", skill/3);
	me->add_temp("apply/attack", skill/3);
	me->add_temp("apply/armor", skill);
	me->add_temp("apply/dodge", skill/2);
	me->set_temp("uparmor", 1);
if (me->query("up1")==2)
{
	me->add_temp("apply/damage", skill/3);
	me->add_temp("apply/attack", skill/3);

	me->add_temp("apply/armor", skill);
	me->add_temp("apply/dodge", skill/2);
    me->receive_curing("qi", 100 + (int)me->query_skill("puyaogedou")/4 );
    me->add("qi", 100 + (int)me->query_skill("puyaogedou")/4 );
me->add("eff_qi", 100 + (int)me->query_skill("puyaogedou")/4 );
    if( (int)me->query("qi") > (int)me->query("eff_qi") ) me->set("qi", (int)me->query("eff_qi"));
      if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 ) {
                msg += HIR "$nһ��ɶҲ��������,ֻ�ò�ȡ��ʽ������������\n" NOR;
            target->start_busy(3);           
target->apply_condition("ill_dongshang",10 );
target->apply_condition("ill_fashao",10 );
target->apply_condition("ill_kesou",10 );
target->apply_condition("ill_shanghan",10 );
target->apply_condition("ill_zhongshu",10 );
            } else {
                msg += HIY"����$p������$P����ͼ������㣬ȫ��Ӧ�����硣\n" NOR;
                me->start_busy(random(2));
        }
        message_combatd(msg, me, target);
}
	me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill/4, skill/3 :), skill/4);

	if( me->is_fighting() ) me->start_busy(2);

	return 1;
}

void remove_effect(object me, int a_amount, int d_amount)
{
	int skill;
	skill = me->query_skill("puyaogedou");
	me->add_temp("apply/damage", -skill/3);
	me->add_temp("apply/attack", -skill/3);

	me->add_temp("apply/armor", -skill);
	me->add_temp("apply/dodge", -skill/2);
if (me->query("up1")==2)
{
	me->add_temp("apply/damage", -skill/3);
	me->add_temp("apply/attack", -skill/3);

	me->add_temp("apply/armor", -skill);
	me->add_temp("apply/dodge", -skill/2);
}
	me->delete_temp("uparmor");
	tell_object(me, HIY "���һ�����������ˡ�\n");
}
