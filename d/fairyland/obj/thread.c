// thread.c
// By jpei

inherit ITEM;

void create()
{
	set_name("ϸ˿", ({ "thread", "xi si", "si" }));
	set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ������Ƥ��ɵ�ϸ˿��\n");
		set("value", 1);
		set("material", "wood");
	}
	setup();
}
