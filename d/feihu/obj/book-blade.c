// bookblade
//by steel
#include "ansi.h"
//inherit ITEM;
inherit ITEM;

void create()
{
	set_name("���ҹŵ���", ({ "bladebook", "shu", "book" }));
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long",
                        "����һ����飬�����ϻ���һ����,�������Ÿ�"+HIR"��"NOR+"��\n");
		set("no_put", 1);
//		//set("value", 100000);

		set("material", "papter");
		set("skill", ([
			"name":	"blade",	
			"exp_required":	50000,				"jing_cost":	10,	// jing cost every time study this
			"difficulty":	20,	
			"max_skill":	280			
                  ]) );
	}
}

