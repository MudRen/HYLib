//Cracked by Kafei
// danggui.c ����

#include <ansi.h>

inherit ITEM;

void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name( GRN "����" NOR , ({"dang gui", "danggui"}));
	set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�ð�����ϵ��飬��Ȼ�Ѿ��ɱ񣬵������������ҩЧ���ѡ�\n");
		set("yaocao",1);
		set("value", 900);
		set("medicine", 1);
	}
	setup();
}

int do_eat(string arg)
{
        object me = this_player();
 	if (!id(arg))
	return notify_fail("��Ҫ��ʲô��\n");
	if ( (int)me->query_condition("bonze_drug" ) > 0 ){
                me->add("max_jingli", -1);
                me->add("eff_jingli", -1);
		me->set("jingli", 0);
		me->apply_condition("bonze_drug", 30);
        message_vision(HIR "$N����һ�ŵ��飬ֻ���øγ���ϣ��������ѣ�ԭ����ʳ̫��ҩ�ҩЧ�ʵ��䷴��\n" NOR, this_player());
		destruct(this_object());
        }
	me->add("max_jingli", 1);
	me->add("eff_jingli", 1);
	me->set("jingli", (int)me->query("max_jingli"));
	me->apply_condition("bonze_drug", me->query_condition("bonze_drug")+25);
	message_vision(HIY "$N����һ���ϵ��飬һ������ֱ����¥��ȫ��ľ������ָ��ˡ�\n" NOR, me);

	destruct(this_object());
	return 1;
}
