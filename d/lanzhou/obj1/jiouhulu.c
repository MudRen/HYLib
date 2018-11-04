// jiouhulu.c 

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("��«", ({"jiouhulu", "hulu"}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ���ú�«�Ƴɵľƺ���\n");
		set("unit", "��");
		set("value", 100);
		set("max_liquid", 10);
	}

	// because a container can contain different liquid
	// we set it to contain water at the beginning
	set("liquid", ([
		"type": "water",
		"name": "�������--Ů����",
		"remaining": 10,
		"drunk_supply": 10,
	]));
}
