//Cracked by Kafei
// sheli-zii.c ������

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
	set_name("������", ({"sheli zi", "zi"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�Ż�������������ӣ�Сָ���С��ɫ���Ұף������б���������\n");
//		set("no_drop","�������������뿪�㡣\n");
//                set("no_get", "�������������뿪�Ƕ���\n");
		set("value", 8000);
		set("medicine", 1);
	}
	setup();
}

int do_eat(string arg)
{
	int add_skill, improve, add;


        object me = this_player();
 	if (!id(arg))
	return notify_fail("��Ҫ��ʲô��\n");

	add = 10+random(20);
	
	if ( (int)me->query_condition("bonze_drug" ) > 0 ){
		me->add("max_jingli", -add);
		me->add("eff_jingli", -add);
		me->apply_condition("bonze_drug", 80);
	message_vision(HIR "$N����һ�������ӣ�ֻ���øγ���ϣ��������ѣ�ԭ����ʳ̫��ҩ�ҩЧ�ʵ��䷴��\n" NOR, this_player());
	me->unconcious();
	destruct(this_object());
	}
	else {
		message_vision(HIY "$N����һ�������ӣ���Ȼ��ֻ���Դ���ע����һ������֮��...\n" NOR, this_player());
                me->add("max_jingli", add);
		me->add("eff_jingli", add);
		me->apply_condition("bonze_drug", 80);
	}
	me->unconcious();
	destruct(this_object());
	return 1;
}

