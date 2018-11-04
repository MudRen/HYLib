// guazi.c

inherit ITEM;
#include <ansi.h>;

void create()
{
	set_name( "������Ѽ" , ({ "kaoya","duke" }) );
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һֻ���ý��Ƶ�Ѽ�ӡ�\n");
		set("unit", "ֻ");
		set("value", 50000);
		set("remaining", 1);
		set("food_supply", 15);
	}
	setup();
}
void init()
{
	add_action("do_eat", "eat");
}


int do_eat(string arg)
{
	object me,ob;
	me = this_player();
	ob = this_object();

	if( !this_object()->id(arg) ) return 0;
	if( me->is_busy() )
		return notify_fail("����һ��������û����ɡ�\n");
	if(   (int)me->query("food") >= (int)me->max_food_capacity() )
		return notify_fail("���Ѿ���̫���ˣ���Ҳ�Բ����ˡ�\n");
	message_vision("$N����һֻ������Ѽ��\n",me);
	me->add("food", (int)query("food_supply"));
	if( me->is_fighting() ) me->start_busy(2);
	destruct(ob);
	return 1;
}

   
