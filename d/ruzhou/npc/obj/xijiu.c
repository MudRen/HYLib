// Obj:/d/ruzhou/npc/obj/xijiu.c  ϲ��
// llm 99/07

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("ϲ��", ({"xi jiu", "jiu"}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һƿ����ʮ�־��µ�װ�ϵȺþƵ�ϲ��ƿ��\n");
		set("unit", "ƿ");
		set("max_liquid", 15);
	}
	// because a container can contain different liquid
	// we set it to contain wine at the beginning
	set("liquid", ([
		"type": "alcohol",
		"name": "���㴼",
		"remaining": 15,
		"drunk_apply": 3,
	]));
}
