inherit ITEM;
#include <ansi.h>

void init()
{
	add_action("do_eat", "eat");
}
void create()
{
	set_name(HIR"��"NOR"��"HIC"��"NOR"�"NOR, ({"chan"}));
	set("unit", "ֻ");
	set("value", 300000);
	set("long", "����һǧ���ѵ�һ�����쾦���, ͨ��͸��,
Ω�۳ʳ�ɫ, �ܽ�ٶ���\n");
	setup();
}

int do_eat(string arg)
{
	object me=this_player();
	if (!id(arg))  return notify_fail("��Ҫ��ʲô��\n");
	if (me->is_busy() )
		return notify_fail("�𼱣������ԣ�С�ı�ҭ���ˡ�\n");
	if (me->is_fighting() )
		return notify_fail("���ʱ�ԣ���Ҫ������!!\n");

	if(arg=="chan") 
	{
message_vision(HIG"$N����һֻ�쾦��󸣬ֻ��һ�����������ķΣ���ʱ��̨һƬ������������ˬ��\n" NOR, me);
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
		if (me->query_condition("sanxiao_poison"))
			me->apply_condition("sanxiao_poison",0);
		if (me->query_condition("scorpion_poison"))
			me->apply_condition("scorpion_poison",0);
		if (me->query_condition("slumber_drug"))
			me->apply_condition("slumber_drug",0);
		if (me->query_condition("snake_poison"))
			me->apply_condition("snake_poison",0);
		if (me->query_condition("ss_poison"))
			me->apply_condition("ss_poison",0);
		if (me->query_condition("xx_poison"))
			me->apply_condition("xx_poison",0);
		if (me->query_condition("zhua_poison"))
			me->apply_condition("zhua_poison",0);
        if (me->query_condition("snake_poison"))
        {          me->clear_condition("snake_poison");}
        if (me->query_condition("wugong_poison"))
        {          me->clear_condition("wugong_poison");}
        if (me->query_condition("zhizhu_poison"))
        {          me->clear_condition("zhizhu_poison");}
        if (me->query_condition("xiezi_poison"))
        {          me->clear_condition("xiezi_poison");}
        if (me->query_condition("chanchu_poison"))
        {          me->clear_condition("chanchu_poison");}
        if (me->query_condition("qishang_poison"))
        {          me->clear_condition("qishang_poison");}
        if (me->query_condition("jy-poison"))
        {          me->clear_condition("jy-poison");}
        if (me->query_condition("xx_poison"))
        {          me->clear_condition("xx_poison");}
        if (me->query_condition("cold_poison"))
        {          me->clear_condition("cold_poison");}
        if (me->query_condition("flower_poison"))
        {          me->clear_condition("flower_poison");}
        if (me->query_condition("chilian_poison"))
        {          me->clear_condition("chilian_poison");}
        if (me->query_condition("yufeng_poison"))
        {          me->clear_condition("yufeng_poison");}
        if (me->query_condition("anqi_poison"))
        {          me->clear_condition("anqi_poison");}
       if (me->query_condition("yf_poison"))
        {          me->clear_condition("yf_poison");}
       if (me->query_condition("nx_poison"))
        {          me->clear_condition("nx_poison");}
       if (me->query_condition("x2_poison"))
        {          me->clear_condition("x2_poison");}
       if (me->query_condition("sanpoison"))
        {          me->clear_condition("sanpoison");}
       if (me->query_condition("insect_poison"))
        {          me->clear_condition("insect_poison");}

}
	me->start_busy(3);
		destruct(this_object());
	return 1;
}
