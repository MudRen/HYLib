// jiudai.c

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("ˮ��", ({ "shui hu", "hu","shui","shuihu" }) );
	set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ������Ƥ���Ƶ�ˮ������������װˮ�ȡ�\n");
		set("unit", "��");
		set("value", 100);
		set("max_liquid", 15);
	}

	// The liquid contained in the container is independent, we set a copy
	// in each cloned copy.
	set("liquid", ([
		"type": "water",
		"name": "��ˮ",
		"remaining": 15,
		"drunk_apply": 6,
	]) );
}
