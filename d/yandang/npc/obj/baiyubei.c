// music  yangzhou's  �ƺ�

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("����",({"baiyu bei","bei"}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
	set("long","���ݱ��ز���С�豭��\n");
	set("unit","��");
		set("max_liquid", 15);
	}

	// because a container can contain different liquid
	// we set it to contain wine at the beginning
	set("liquid", ([
		"type":"water",
		"name":"���򻨲�",
		"remaining": 15,
		"drunk_apply": 3,
	]));
}
