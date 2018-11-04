// yangjing.c

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIG"������"NOR, ({"yangjing dan", "dan"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
	        set_weight(4000);
		set("unit", "��");
		set("vegetable", 7);
		set("nostrum", 128);
		set("level", 10);
		set("lev", 2+random(3));
		set("value", 5000);
	}
	set("pour_type", "1");
	setup();
}

int init()
{
	add_action("do_eat", "eat");
	add_action("do_eat", "fu");
}

int do_eat(string arg)
{
int exp,pot,i;
	object me = this_player();

exp = 888+random(888);
pot = exp/2;


	if(!id(arg)) return notify_fail("��Ҫ��ʲô��\n");
	if(!present(this_object(), me))
		return notify_fail("��Ҫ��ʲô��\n");
	if( me->is_busy() )
		return notify_fail("�𼱣������ԣ�С�ı�ҭ���ˡ�\n");

	message_vision("$N����һ��" + name() + "��\n", me);
/*	if (((int)me->query_condition("xx_poison") > 0) ||
		((int)me->query("eff_jing") < (int)me->query("max_jing")))
	{
		me->apply_condition("jing_curing", me->query_condition("jing_curing") + 10);
*/

       me->add("combat_exp",exp);
       me->add("potential",pot);
message_vision("$N�����"+chinese_number(exp)+"�㾭��,"+chinese_number(pot)+"��Ǳ��!\n", me);
i=1+random(3);
if (random(12)==0 || wizardp(me))
{
if ( me->query("4zhuan") || me->query("5zhuan") )
{
if (me->query("expmax",1) < 1)
{
me->set("expmax",i);
}
else
{
me->add("expmax",i);
}       
message_vision(HIR"$N�����"+chinese_number(i)+"��ɳ�����!\n"NOR, me);
}       
}
	if (((int)me->query_condition("xx_poison") > 0) ||
	((me->query("eff_jing") / me->query("max_jing")) < 0.9))
	{
		me->receive_curing("jing", (int)me->query("max_jing") / 50);
	}
	me->start_busy(2);
	destruct(this_object());
	return 1;
}
 
