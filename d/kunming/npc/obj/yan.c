// yan.c


inherit ITEM;

void create()
{
	set_name("ˮ��", ({"yan", "smoke"}));
	set_weight(50);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "����һ����ˮ��˿��\n");
		set("unit", "��");
		set("value", 10);
    	}
}
