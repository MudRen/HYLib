// movebook.c

inherit ITEM;

void create()
{
	set_name("������", ({ "guyupai" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long",
			"�������������̵��Ǽ��������мܷ���,�������study��������\n");
		set("value", 0);
		set("material", "stone");
		set("skill", ([
			"name": 		"unarmed",	
			"exp_required":	20000,				
			"jing_cost":		80,				
			"difficulty":	80,		
			"max_skill":	360,
		]) );
	}
}
