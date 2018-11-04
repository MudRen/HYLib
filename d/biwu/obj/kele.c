inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("ˮ��", ({"quskin"}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ��ˮ����\n");
		set("unit", "��");
		set("value", 0);
		set("max_liquid", 15);
	}

	// because a container can contain different liquid
	// we set it to contain wine at the beginning
	set("liquid", ([
		"type": "water",
		"name": "ˮ",
		"remaining": 15,
		"drunk_apply": 3,
	]));
}
