//Cracked by Kafei
// xueteng.c ��Ѫ��

#include <ansi.h>

inherit ITEM;

void init()
{
	add_action("do_eat", "eat");
}


void create()
{
	set_name( GRN "��Ѫ��" NOR , ({"da xueteng", "xueteng"}));
	set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ����گ�ز��Ĵ�Ѫ�٣��������Ǻں����Ŀ�ľ�����в�Ѫ��������Ч��\n");
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
                me->add("max_neili", -1);
                me->set("neili", 0);
                me->apply_condition("bonze_drug", 30);
        message_vision(HIR "$N����һ�Ŵ�Ѫ�٣�ֻ���øγ���ϣ��������ѣ�ԭ����ʳ̫��ҩ�ҩЧ�ʵ��䷴��\n" NOR, this_player());
		destruct(this_object());
        }
	
	me->set("qi", (int)me->query("max_qi"));
	me->add("max_neili", 1);
	me->set("neili", (int)me->query("max_neili"));
	me->apply_condition("bonze_drug", me->query_condition("bonze_drug")+20);
	message_vision(HIY "$N����һ�ô�Ѫ�٣���ʱѪ����ӿѪ�����ͣ������󳤡�\n" NOR, me);

	destruct(this_object());
	return 1;
}
