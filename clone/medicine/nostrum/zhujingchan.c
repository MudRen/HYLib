// zhujingchan.c �쾦���

inherit ITEM;
#include <ansi.h>

void init()
{
	add_action("do_eat", "eat");
	add_action("do_eat", "fu");
}
void create()
{
	set_name(HIR"��"NOR"��"HIC"��"NOR"�"NOR, ({"chan"}));
	set("unit", "ֻ");
	set("value", 10000);
	set("lev", 3+random(5));
	set("long","����һǧ���ѵ�һ�����쾦��󸣬ͨ��͸����Ω�۳ʳ�ɫ���ܽ�ٶ���\n");
	set("pour_type", "1");
	setup();
}

int do_eat(string arg)
{
int exp,pot,i;
	object me = this_player();

exp = 888+random(888);
pot = exp/2;

	if (!id(arg))  return notify_fail("��Ҫ��ʲô��\n");
	if (!present(this_object(), this_player()))
		return notify_fail("��Ҫ��ʲô��\n");
	if (me->is_busy() )
		return notify_fail("�𼱣������ԣ�С�ı�ҭ���ˡ�\n");

	message_vision(HIG"$N����һֻ�쾦��󸣬ֻ��һ�����������ķΣ���ʱ��̨һƬ������������ˬ��\n" NOR, me);
       if(!userp(me))
	{
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
	if (me->query_condition("chanchu_poison"))
		me->apply_condition("chanchu_poison",0);
	if (me->query_condition("drunk"))
		me->apply_condition("drunk",0);
	if (me->query_condition("flower_poison"))
		me->apply_condition("flower_poison",0);
	if (me->query_condition("ice_poison"))
		me->apply_condition("ice_poison",0);
	if (me->query_condition("iceshock"))
		me->apply_condition("iceshock",0);
	if (me->query_condition("rose_poison"))
		me->apply_condition("rose_poison",0);
//	if (me->query_condition("sanxiao_poison"))
//		me->apply_condition("sanxiao_poison",0);
	if (me->query_condition("scorpion_poison"))
		me->apply_condition("scorpion_poison",0);
	if (me->query_condition("slumber_drug"))
		me->apply_condition("slumber_drug",0);
	if (me->query_condition("snake_poison"))
		me->apply_condition("snake_poison",0);
	if (me->query_condition("ss_poison"))
		me->apply_condition("ss_poison",0);
	if (me->query_condition("wugong_poison"))
		me->apply_condition("wugong_poison",0);
	if (me->query_condition("xx_poison"))
		me->apply_condition("xx_poison",0);
	if (me->query_condition("xiezi_poison"))
		me->apply_condition("xiezi_poison",0);
	if (me->query_condition("zhizhu_poison"))
		me->apply_condition("zhizhu_poison",0);
	if (me->query_condition("zhua_poison"))
		me->apply_condition("zhua_poison",0);
	if (me->query_condition("ice_sting"))
		me->apply_condition("ice_sting", 0);
	}
	me->start_busy(2);
	destruct(this_object());
	return 1;
}