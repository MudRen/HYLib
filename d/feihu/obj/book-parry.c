// sword_book.c

inherit ITEM;

void create()
{
	set_name("�������ؾ�", ({ "parrybook", "shu","book" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long",
                "������ʲô��û�С�\n");
		set("no_put", 1);
//		//set("value", 100000);

		set("material", "paper");
		set("skill", ([
			"name": "parry",		
			"exp_required":	50000,
											// to learn this skill.
			"jing_cost":80,	
			"difficulty":80,
											// modify is jing_cost's (difficulty - int)*5%
			"max_skill":  280
											// from this object.
		]) );
	}
}
