// longhe.c

#include <ansi.h>

int exert(object me)
{
	int skill;
	skill = (int)me->query_skill("linji-zhuang",1);

	if (me->query_temp("linji/con"))
		return notify_fail("���Ѿ���������ׯ�ˣ�\n");


	if( me->is_fighting() )
		return notify_fail("ս�����޷�������ׯ��\n");

	if( (int)me->query("neili") < 300)
		return notify_fail("�������������\n");

	if( (int)me->query_skill("linji-zhuang",1) < 90)
		return notify_fail("����ټ�ׯ���𲻹���\n");

	if( (int)me->query("eff_qi") < (int)me->query("max_qi") / 2 )
		return notify_fail( "�Ѿ����˹��أ��޷��˹���\n");

	message_vision(
HIR "$N����������������ׯ����ȫ�������Ĵ���һ�飬����ȫ�����������....\n"
"���뷢й��ȥ����˭������һ����\n" NOR, me );
//	me->apply_condition("linji_longhe", (int)skill/20);
	me->add("neili", -300);
	me->add("eff_jing", -15);
	me->add("jing", -20);
        me->add_temp("apply/constitution",skill/20);
//	me->add("con", (int)skill/25);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me :), (int)skill/10 );
	me->set_temp("linji/con", (int)skill/30);
	return 1;
}

void remove_effect(object me)
{
 	int skill;
	skill = (int)me->query_skill("linji-zhuang",1);
		tell_object(me, 
HIB "��Ȼ�����ȫ��������ģ�����СָͷҲ���붯�ˣ�ԭ�����
����ׯ�չ��ˣ�\n" NOR );
        me->add_temp("apply/constitution",-skill/20);
		me->delete_temp("linji/con");
}