//Cracked by Kafei
// shouwu.c ���ھ�

#include <ansi.h>

inherit ITEM;

void init()
{
	add_action("do_eat", "eat");
}


void create()
{
	set_name( GRN "���ھ�" NOR , ({"shouwu jing", "shouwu"}));
	set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�óɾ��ĺ����ڣ����������˼������ˣ����ѳ����Σ��������ҩЧ��\n");
		set("yaocao",1);
		set("value", 500);
		set("medicine", 1);
	}
	setup();
}

int do_eat(string arg)
{
        object me = this_player();
 	if (!id(arg))
	return notify_fail("��Ҫ��ʲô��\n");
	me->set("jing", (int)me->query("max_jing"));
	me->set("eff_jing", (int)me->query("max_jing"));
	me->set("jingli", (int)me->query("max_jingli"));
        
	message_vision(HIY "$N����һ�����ھ���ҩЧ����ͨ���θ���ֱ����֫������������������ʹҲȫ���о������ˡ�\n" NOR, me);

	destruct(this_object());
	return 1;
}
