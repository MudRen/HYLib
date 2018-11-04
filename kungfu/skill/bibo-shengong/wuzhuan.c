// maze.c ���Ű�������

#include <ansi.h>

inherit F_SSERVER;

void remove_effect(object me, object target, int count, int skill);

int exert(object me, object target)
{
        string msg;

	int skill;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("������תֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (me->query_temp("thd/mazed")) 
		return notify_fail("������������˲��������С�\n");

	if( (int)me->query("neili") < 80  ) 
		return notify_fail("�������������\n");
	if( (int)me->query_skill("qimen-wuxing") < 80  ) 
		return notify_fail("����������в�����\n");

	if( (int)me->query_temp("thd/maze") ) 
		return notify_fail("���Ѿ�����һ�������ˡ�\n");

	skill = me->query_skill("qimen-wuxing", 1);
	me->add("neili", -80);
        msg = HIG "$N����������ʢ�����»������žŹ����Է�λ��ͷ��ð�����ڰ�����";
        msg += "��������������ӿ֮�������������ѷ��ӵ����£�\n"NOR;

	message_vision(
	HIC "$Nһ����ս��һ��������Χ��ʯ�顢��֦�Ȳ���һ���򵥵��󣬿���������ʱ�������Դ�$P�ˡ�\n" NOR, me);

	me->add_temp("apply/damage", skill/5);
	me->add_temp("apply/attack", skill/5);
	me->add_temp("apply/defense", skill/5);
	me->add_temp("apply/dexerity", skill/6);
	me->add_temp("apply/dodge", skill/6);
	me->set_temp("thd/maze", 1);
	target->set_temp("thd/mazed", 1);
        message_vision(msg, me);
	call_out("remove_effect", 1, me, target, skill / 2, skill);

	if( me->is_fighting() ) me->start_busy(1 + random(2));

	return 1;
}

void remove_effect(object me, object target, int count, int skill)
{
	if (objectp(me)) {
		if (count-- > 0 && me->is_fighting(target)) {
			call_out("remove_effect", 1, me, target, count, skill);
			return;
		}
	me->add_temp("apply/damage", -(skill/5));
	me->add_temp("apply/attack", -(skill/5));
		me->add_temp("apply/defense", - (skill/5));
		me->add_temp("apply/dexerity", - (skill/6));
		me->add_temp("apply/dodge", - (skill/6));
		me->delete_temp("thd/maze");
        if (target && me->is_fighting(target)) {
			tell_object(me, "�㲼�������Ѿ���" + target->name() + "�ƻ��ˡ�\n");
			if (userp(target) && living(target))
				tell_object(target, me->name() + "���㲼�������Ѿ�����ʶ���ˡ�\n");
		}
		else {
			tell_object(me, "�㲼�������Ѿ�ʧЧ�ˡ�\n");
		}
	}
	if (objectp(target))
		target->delete_temp("thd/mazed");
}
