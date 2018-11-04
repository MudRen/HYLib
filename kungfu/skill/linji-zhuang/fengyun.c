// fengyun.c

#include <ansi.h>

int exert(object me)
{
	int skill;
	skill = (int)me->query_skill("linji-zhuang",1);

	if (me->query_temp("linji/dex"))
		return notify_fail("���Ѿ����˷���ׯ�ˣ�\n");


	if( me->is_fighting() )
		return notify_fail("ս�����޷��˷���ׯ��\n");

	if( (int)me->query("neili") < 400)
		return notify_fail("�������������\n");

	if( (int)me->query_skill("linji-zhuang",1) < 120)
		return notify_fail("����ټ�ׯ���𲻹���\n");

	if( (int)me->query("eff_qi") < (int)me->query("max_qi") / 2 )
		return notify_fail( "�Ѿ����˹��أ��޷��˹���\n");

	message_vision(
HIC "$N���������������ׯ�������������˵�����ӿȪѨ��....\n"
"��������һ��ů�������ӿ��ӿ���ϣ���ʱ�����������࣬ԾԾ���ɡ�\n" NOR, me );
//	me->apply_condition("linji_fengyun", (int)skill/20);
	me->add("neili", -400);
	me->add("jing", -20);
        me->add_temp("apply/dexerity",skill/20);
//        me->add("dex", (int)skill/20);
	me->set_temp("linji/dex", (int)skill/30);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me :), (int)skill/10 );
	return 1;
}

void remove_effect(object me)
{
 	int skill;
	skill = (int)me->query_skill("linji-zhuang",1);
		tell_object(me, 
HIB "��Ȼ�����һ�����������������³�ȥ����ʱ˫�����Ǧ���
�أ�ԭ����ķ���ׯ�չ��ˣ�\n" NOR );
        me->add_temp("apply/dexerity",-skill/20);
		me->delete_temp("linji/dex");
}