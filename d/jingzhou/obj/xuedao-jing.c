// xdblade_book.c

#include <ansi.h>
#include <weapon.h>

inherit ITEM;

void create()
{
	set_name( HIR "��Ѫ�����ס�" NOR , ({"book","shu"}));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long",
"������д�� "+HIR "��Ѫ�����ס�" NOR+"��������һЩ���ι�״�ĵ������Ρ�\n");
		set("value", 0);
		set("material", "paper");
		set("skill", ([
			"name": 		"blade",		// name of the skill
			"exp_required":	1000,			// minimum combat experience required
											// to learn this skill.
			"jing_cost":		20,				// jing cost every time study this
			"difficulty":	20,				// the base int to learn this skill
											// modify is jing_cost's (difficulty - int)*5%
			"max_skill":	40				// the maximum level you can learn
											// from this object.
		]) );
	}
}
