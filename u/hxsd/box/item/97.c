// z-dan.c
// ����(lywin)��������������

inherit ITEM;

void setup()
{}

void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name("������", ({"zhengqi dan", "dan"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ����������\n");
		set("value", 15000);
	}
	setup();
}

int do_eat(string arg)
{
	if (!id(arg))
	return notify_fail("��Ҫ��ʲô��\n");

	this_player()->add("shen", 1000);
	message_vision("$N����һ����������ֻ�������������ص� !\n", this_player());
	destruct(this_object());
	return 1;
}

