// music yangzhou' ����

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("�ƾ�", ({"huang", "jing"}));
	set_weight(80);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ��ɽ�е�Ұɽҩ,����Ŀ,ǿ�����֮Ч��\n");
		set("unit", "��");
		set("value", 50);
		set("food_remaining", 3);
		set("food_supply", 80);
	}
}
