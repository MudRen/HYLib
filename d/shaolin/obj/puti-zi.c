// puti-zi.c ������

#include <ansi.h>

inherit ITEM;

void setup()
{}

void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name("������", ({"puti zi", "zi"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
set("treasure",1);
		set("unit", "��");
		set("long", "����һ�ž�Ө����������ӣ�������ɽ������ǰ����ϡ�ޱȣ�
������������֮ʵ�����ܻ��ٽ٣���ǧ�֣������ͬ�١�\n");
		set("value", 500000);
	}
	setup();
}

int do_eat(string arg)
{
	int force_limit, neili_limit, force_skill, add_skill, improve;

	object me = this_player();

	force_limit = me->query_skill("force")*12;
	neili_limit = me->query("max_neili");
	force_skill = me->query_skill("force", 1);
	
	if (!id(arg))
	return notify_fail("��Ҫ��ʲô��\n");


	if ( (int)me->query_condition("putizi_drug" ) > 0 )
	{
		me->add("max_neili", -100);
		message_vision(HIR "$N�ֳ���һ�������ӣ�ֻ���øγ���ϣ��������ѣ�ԭ����ʳ̫��̫�࣬ҩЧ�ʵ��䷴��\n" NOR, me);
	}
       if ( neili_limit > force_limit  )
	{
		message_vision(HIR "$N����һ�������ӣ����ĺ���ûʲô�ã�\n" NOR, me);
	}
	else if ( neili_limit <= force_limit  )
	{
		me->add("max_neili", 100);
		me->add("neili", 100);

		message_vision(HIY "$N����һ�������ӣ���Ȼ��ֻ��һ�ɺƵ��ޱȵ�����ֱ�嶥��...\n" NOR, this_player());
		me->apply_condition("putizi_drug", 1000);
	}
	me->start_busy(100);
//	me->unconcious();
	destruct(this_object());
	return 1;
}

