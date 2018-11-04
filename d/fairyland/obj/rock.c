// rock.c
// By jpei

inherit ITEM;

void create()
{
	set_name("��ʯ", ({ "rock", "yanshi", "yan shi", "shi" }));
	set_weight(8000);
	set("unit", "��");
	set("long", "����һ����ʯ����ǲ���������\n");
	set("value", 0);
	set("no_get", "�����ʯ������û�ã�������������");
	set("material", "rock");
	setup();
}

void init()
{
	if (query("no_get"))
		add_action("do_break", ({"break", "throw", "zhi", "za", "sui", "reng", "po", "shuai"}));
}

int do_break(string arg)
{
	object me = this_player();

	if (!id(arg))
		return notify_fail("������ʲô��\n");

	if (query("no_get")) {
		message_vision("$N��һ����ʯ��׼��һ����ʯ��ȥ����ʯ�����һ����Ƭ��������һƬ�з�����ǡ�\n", me);
		set_name("��ʯ", ({ "sharp rock", "rock", "jian shi", "shi" }));
		set("long", "����һ����ʯ�ϵ���Ƭ�����ŷ�������ǡ�\n");
		set("unit", "Ƭ");
		delete("no_get");
		remove_action("do_break", "break");
		remove_action("do_break", "throw");
		remove_action("do_break", "zhi");
		remove_action("do_break", "za");
		remove_action("do_break", "sui");
		remove_action("do_break", "reng");
		remove_action("do_break", "po");
		remove_action("do_break", "shuai");
		return 1;
	}
	return 0;
}
