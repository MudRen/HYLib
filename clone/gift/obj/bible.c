#pragma save_binary
 
// bible.c

inherit ITEM;
#include <ansi.h>
void create()
{
	set_name(YEL"ʥ��"NOR, ({ "bible"}));
	set_weight(600);
	set("task",1);
	set("owner","�̸�");
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long",
			"����һ��ʥ��������д��һЩ���塣\n"
			);
		set("value", 1000);
		set("material", "paper");
		set("skill", ([
			"name":	"literate",		// name of the skill
			"exp_required":	0,		// minimum combat experience required
			"literate_required":10,								// to learn this skill.
			"sen_cost":30,			// gin cost every time study this
			"difficulty":10,		// the base int to learn this skill
							// modify is gin_cost's (difficulty - int)*5%
			"max_skill":100			// the maximum level you can learn
							// from this object.
		]) );
	}
	setup();
}
