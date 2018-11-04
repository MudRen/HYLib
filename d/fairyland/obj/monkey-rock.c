// monkey-rock.c
// By jpei

inherit ITEM;

void create()
{
	set_name("��ʯ", ({ "rock", "yanshi", "yan shi", "shi" }));
	set_weight(8000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ��ܲ��ȹ̵���ʯ��\n");
		set("value", 0);
		set("no_get", "�����ʯ������û�ã�������������");
		set("material", "rock");
	}
	setup();
}

void init()
{
	add_action("do_move", ({"move", "ban", "peng", "yi"}));
}

int do_move(string arg)
{
	object me = this_player();
	object monkey;

	if (!id(arg))
		return notify_fail("�����ʲô��\n");

	if ((monkey = present("xiao hou", environment())) && monkey->query("get_wound")) {
		message_vision("$N��ѹ��С�����ϵ���ʯ�Ὺ����С������\n", me);
		monkey->set("rock_moved", 1);
		return 1;
	}
	return 0;
}
