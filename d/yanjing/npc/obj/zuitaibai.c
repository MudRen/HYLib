// music  yangzhou's  �ƺ�

inherit ITEM;
inherit F_LIQUID;

void create()
{
set_name("�״ɾƺ�",({"jiu hu","hu"}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
set("long","�ú��ϵ�ź���,�����и�͹����[��]��.\n");
		set("unit", "��");
set("value",300);
		set("max_liquid", 15);
	}

	set("liquid", ([
		"type": "alcohol",
"name":"��̫��",
		"remaining": 15,
		"drunk_apply": 3,
	]));
}
