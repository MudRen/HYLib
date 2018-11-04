// shanshen.c ��ɽ��

#include <ansi.h>

inherit ITEM;

void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name("��ɽ��", ({"laoshan shen", "shen"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ��մ��ɽ��ĳ�����ɽ�Ρ�\n");
		set("value", 10000);
	}
	setup();
}

int do_eat(string arg)
{
	object me = this_player();

	if (!id(arg))
	return notify_fail("��Ҫ��ʲô��\n");

	if (me->query_condition("medicine")) {
        	me->set("qi", 0);
        	me->set("jing", 0);

		message_vision(
			HIR "$N����һ����ɽ�Σ�ֻ����ͷ�ؽ��ᣬҡҡ������\n"
			"ԭ����ʳ̫��̫�࣬ҩЧ�ʵ��䷴��\n" NOR, this_player());
	}  
               switch(random(3)) {
                case 0:
                message_vision(
                      HIG "$N����һ����ɽ�Σ�ֻ����������ĺ��Ǻóԣ�\n" NOR, me);
                break;
                case 1:
	        me->set("eff_qi", me->query("max_qi"));
	        me->set("qi", me->query("max_qi"));
	        me->set("eff_jing", me->query("max_jing"));
	        me->set("jing", me->query("max_jing"));
	        me->set("neili", me->query("max_neili"));
                message_vision(
			HIG "$N����һ����ɽ�Σ�ֻ���û���һ����������ð��������\n" NOR, me);
		me->apply_condition("medicine", 30);
                break;
                case 2:
                     message_vision(
                      HIG "$N����һ����ɽ�Σ�ֻ������΢΢�е㷢�࣬�����ƺ��й������ڹĶ���\n" NOR, me);
                me->set("neili", me->query("max_neili"));
                break;
	}
	destruct(this_object());
	return 1;
}
