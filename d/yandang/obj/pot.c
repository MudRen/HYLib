// pot.c  by ksusan 7/12/97

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("��ˮ��", ({ "pot", "shuigang" , "big shuigang" }) );
	set_weight(1000000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ������װ�ˡ���ʮ����ˮ�Ĵ�ˮ�ף������ڿʣ�����Ҩˮ����(drink)��\n");
		set("unit", "��");
		set("value", 20);
		set("max_liquid", 200);
	}

	// The liquid contained in the container is independent, we set a copy
	// in each cloned copy.
	set("liquid", ([
		"type": "water",
		"name": "��ˮ",
		"remaining": 200,
//		"drunk_apply": 6,
	]) );
}
