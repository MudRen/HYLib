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
			"�������������̵�������������\n");
		set("value", 0);
		set("material", "stone");
		set("skill", ([
			"name": 		"force",	
			"exp_required":	20000,				
			"sen_cost":		20,				
			"difficulty":	40,		
			"max_skill":	180		
		]) );
	}
}
