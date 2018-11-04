// tiandi.c

#include <ansi.h>

int exert(object me)
{
	int skill;
	skill = (int)me->query_skill("linji-zhuang",1);

	if (me->query_temp("linji/per"))
		return notify_fail("���Ѿ��������ׯ�ˣ�\n");


	if( me->is_fighting() )
		return notify_fail("ս�����޷������ׯ��\n");

	if( (int)me->query("neili") < 100)
		return notify_fail("�������������\n");

	if( (int)me->query_skill("linji-zhuang",1) < 30)
		return notify_fail("����ټ�ׯ���𲻹���\n");

	if( (int)me->query("eff_qi") < (int)me->query("max_qi") / 2 )
		return notify_fail( "�Ѿ����˹��أ��޷��˹���\n");

	message_vision(
HIM "$N���������������ׯ���������������ϣ������ؽ�����������������....\n"
"���˲��ã�$N������������Ө����ɫ����������������͸���ഺ����Ϣ��\n" NOR,
	me );
//	me->apply_condition("linji_tiandi", (int)skill/20);
	me->add("neili", -100);
	me->add("jing", -20);
	me->add("eff_jing", -10);
        me->add_temp("apply/percao",skill/20);
//	me->add("per", (int)skill/20);
	me->set_temp("linji/per", (int)skill/20);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me :), (int)skill/5 );
	return 1;
}

void remove_effect(object me)
{
 	int skill;
	skill = (int)me->query_skill("linji-zhuang",1);
		tell_object(me, 
HIB "��Ȼ������ͷ�е�һ��ʧ�䣬ԭ��������ׯ�չ��ˣ����ʱ
���к�����ȥ֮̾��\n" NOR );
        me->add_temp("apply/percao",-skill/20);
		me->delete_temp("linji/per");
}