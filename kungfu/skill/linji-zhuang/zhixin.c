// zhixin.c

#include <ansi.h>

int exert(object me)
{
	int skill;
	skill = (int)me->query_skill("linji-zhuang",1);

	if (me->query_temp("linji/int"))
		return notify_fail("���Ѿ�����֮��ׯ�ˣ�\n");


	if( me->is_fighting() )
		return notify_fail("ս�����޷���֮��ׯ��\n");

	if( (int)me->query("neili") < 200)
		return notify_fail("�������������\n");

	if( (int)me->query_skill("linji-zhuang",1) < 60)
		return notify_fail("����ټ�ׯ���𲻹���\n");

	if( (int)me->query("eff_qi") < (int)me->query("max_qi") / 2 )
		return notify_fail( "�Ѿ����˹��أ��޷��˹���\n");

	message_vision(
HIY "$N������������֮��ׯ���������������Ͽ������£��پ���̨������....\n"
"վ�������������Դ�������˲��١�\n" NOR, me );
//	me->apply_condition("linji_zhixin", (int)skill/20);
	me->add("neili", -200);
	me->add("eff_jing", -10);
	me->add("jing", -20);
        me->add_temp("apply/intelligence",skill/20);
	me->set_temp("linji/int", (int)skill/30);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me :), (int)skill/10 );
	return 1;
}

void remove_effect(object me)
{
 	int skill;
	skill = (int)me->query_skill("linji-zhuang",1);
		tell_object(me, 
HIB "��Ȼ��ͷ����е�һ��հף�ԭ�����֮��ׯ�չ��ˣ����ʱ
�����Լ����Ǹ���ľ�ϣ�\n" NOR );
        me->add_temp("apply/intelligence",-skill/20);
		me->delete_temp("linji/int");
}
