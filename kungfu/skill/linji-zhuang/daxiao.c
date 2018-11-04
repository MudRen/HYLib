// daxiao.c

#include <ansi.h>

int exert(object me)
{
	int skill;
	skill = (int)me->query_skill("linji-zhuang",1);

	if (me->query_temp("linji/jing"))
		return notify_fail("���Ѿ����˴�Сׯ�ˣ�\n");


	if( me->is_fighting() )
		return notify_fail("ս�����޷��˴�Сׯ��\n");

	if( (int)me->query("neili") < 500)
		return notify_fail("�������������\n");

	if( (int)me->query("jing") < skill + 100)
		return notify_fail("��ľ������˴�Сׯ��\n");

	if( (int)me->query_skill("linji-zhuang",1) < 150)
		return notify_fail("����ټ�ׯ���𲻹���\n");

	if( (int)me->query("eff_qi") < (int)me->query("max_qi") / 2 )
		return notify_fail( "�Ѿ����˹��أ��޷��˹���\n");

	message_vision(
"$N�������������Сׯ���������ɣ�����ֱ͸���ء�������ɫһ���"HIR"��"NOR"��\n"
"һ���"HIC"��"NOR"��һ���ֱ��"HIY"��"NOR"ɫ��������ڻظ�ԭ������ɫ��\n" NOR, me );
	me->add("neili",  -500);
	me->add("eff_jing", 0 - skill);
	me->add("jing", 0 - skill);
	me->add("eff_qi", 2 * skill);
	me->add("qi", 2 * skill);
	me->set_temp("linji/jing", skill);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me :), (int)skill/10 );
	return 1;
}

void remove_effect(object me)
{
 	int skill;
	skill = (int)me->query_skill("linji-zhuang",1);
		tell_object(me, 
HIB "��Ȼ��ȫ��е�һ������һ��Ƥ�����ڣ�ԭ����Ĵ�Сׯ�չ��ˣ�\n" NOR );
		me->add("eff_jing", me->query_temp("linji/jing"));
		me->add("jing", me->query_temp("linji/jing"));
		if (me->query("eff_qi") > me->query_temp("max_qi"))
			me->set("eff_qi", me->query("max_qi"));
		if (me->query("qi") > me->query("eff_qi"))
			me->set("qi", me->query("eff_qi"));
		if (me->query("eff_jing") > me->query("max_jing"))
			me->set("eff_jing", me->query("max_jing"));
		if (me->query("jing") > me->query("eff_jing"))
			me->set("jing", me->query("eff_jing"));
		me->delete_temp("linji/jing");
}