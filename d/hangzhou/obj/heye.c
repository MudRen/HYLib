//Cracked by Kafei
// heye ��Ҷ
// xbc 06/21/97

inherit ITEM;

void create()
{
	set_name("��Ҷ", ({"he ye", "lotus leaf"}));
	set_weight(80);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һƬ�������̵ĺ�Ҷ��\n");
		set("unit", "Ƭ");
		set("value", 0);
	}
}
