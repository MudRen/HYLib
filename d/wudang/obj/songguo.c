// songguo.c
#include <ansi.h>

inherit ITEM;

void create()
{
        set_name("Ұ�ɹ�", ({ "song guo", "guo" }) );
        set_weight(150);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ�����ӱ�����Ұ�ɹ�ʵ��\n");
                set("unit", "ö");
                set("value", 80);
        }
        setup();
}

int init()
{
	add_action("do_eat", "eat");
}

int do_eat(string arg)
{
	object me = this_player();

	if(!id(arg)) return notify_fail("��Ҫ��ʲô��\n");
	if( me->is_busy() )
		return notify_fail("�𼱣������ԣ�С�ı�ҭ���ˡ�\n");
	message_vision(HIG"$N����һ��" + name() + "��ֻ���þ�������\n"NOR, me);
	if (me->query("eff_jing") < me->query("max_jing"))
		me->receive_curing("jing", (int)me->query("max_jing") / 20);
	me->start_busy(2);
	destruct(this_object());
	return 1;
}
