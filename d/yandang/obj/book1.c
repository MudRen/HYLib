#include <ansi.h>
inherit ITEM;

void create()
{
	set_name("����", ({ "poshu" , "book"}) );
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "��������ʱ,���涼�ǰ�ֽ,ʲô��ûд.\n");
		set("material", "paper");
	}
setup();
}
