// music  yangzhou's  �ƺ�

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("�����",({"qingci wan","wan"}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
	set("long","һ��ȱ�˿ڵĺ�������롣\n");
	set("unit","��");
		set("max_liquid", 15);
	}
	set("liquid", ([
		"type":"water",
	"name": "��ˮ",
		"remaining": 15,
		"drunk_apply": 3,
	]));
}
