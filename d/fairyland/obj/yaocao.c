// yaocao.c
// By jpei

inherit ITEM;

void create()
{
	set_name("ҩ��", ({ "yao cao", "yao", "cao" }));
	set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ��ҩ�ݣ���������˵����ðɡ�\n");
		set("value", 30);
		set("material", "grass");
	}
	setup();
}

void init()
{
	add_action("do_eat", ({"eat", "chi"}));
}

int do_eat(string arg)
{
	object me = this_player();

	if (!id(arg))
		return notify_fail("�����ʲô��\n");

	if (me->query("eff_qi") ==  me->query("max_qi"))
		return notify_fail("�����ڲ���Ҫ��ҩ�ݡ�\n");
	else {
		me->receive_curing("qi", 20);
		message_vision("$N����һ��ҩ�ݣ���ɫ����������һЩ��\n", me);
		destruct(this_object());
		return 1;
	}
}
