// hat.c

inherit EQUIP;

void create()
{
	set_name("����", ({ "hat" }) );
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 100);
		set("material", "wood");
		set("armor_type", "head");
		set("armor_prop/armor", 14);
	}
}
