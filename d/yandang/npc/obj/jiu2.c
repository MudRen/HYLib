
inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("ˮ��ƿ", ({"jiu2","zhuyeqing", "ping"}));
	set_weight(800);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ����Ҷ��,�����˱�,���Ǻþ�\n");
		set("unit", "��");
		set("value", 150);
		set("max_liquid", 15);
	}

	// because a container can contain different liquid
	// we set it to contain wine at the beginning
	set("liquid", ([
		"type": "alcohol",
		"name": "��Ҷ��",
		"remaining": 15,
		"drunk_apply": 4,
	]));
}
