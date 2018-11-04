
inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("������", ({"jiu3","nverhong", "baiyu"}));
	set_weight(900);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ��Ů����,�����˱�,���Ǻþ�\n");
		set("unit", "��");
		set("value", 200);
		set("max_liquid", 15);
	}

	// because a container can contain different liquid
	// we set it to contain wine at the beginning
	set("liquid", ([
		"type": "alcohol",
		"name": "Ů����",
		"remaining": 20,
		"drunk_apply": 6,
	]));
}
