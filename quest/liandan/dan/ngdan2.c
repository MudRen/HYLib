//Cracked by Kafei
//lingzhi.c

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
	set_name(HIG "��֥" NOR, ({"ling zhi", "zhi"}));
	set_weight(20);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "ö");
		set("long", "������һö��֥����Լ�Ĵ磬��ɡ״��ͨ�徧�ס�\n");
		set("value", 10000);
		set("medicine", 1);
	}

	setup();
}

int do_eat(string arg)
{
        object me = this_player();
 	if (!id(arg))
	return notify_fail("��Ҫ��ʲô��\n");
	
	if (me->query_condition("medicine") > 0){
        me->add("max_jingli", -1);
        me->add("eff_jingli", -1);
        message_vision(HIR "$N����һö��֥��ֻ����ͷ�ؽ��ᣬҡҡ������ԭ����ʳ̫��̫�࣬ҩЧ�ʵ��䷴��\n" NOR, me);
        destruct(this_object());
        return 1;
        }
	me->set("eff_jing", (int)me->query("max_jing"));
	me->set("jing", (int)me->query("max_jing"));
	me->set("eff_qi", (int)me->query("max_qi"));
	me->set("jingli", (int)me->query("max_jingli"));
	me->set("qi", (int)me->query("max_qi"));
	me->set("neili", (int)me->query("max_neili"));
        
	message_vision(HIG "$N����һö��֥��ֻ���þ���������Ѫ��ӯ����������ԴԴ�������������ٸе������ɿ�! \n" NOR, me);

	me->apply_condition("medicine", 30);
	destruct(this_object());
	return 1;
}
