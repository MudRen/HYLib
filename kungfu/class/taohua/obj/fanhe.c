//fanhe.c

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name("����",({ "fan he","he" }));
	set_weight(100);
	if( clonep() )
                set_default_object(__FILE__);
        else
        {
        	set("unit","��");
        	set("value",0);
        }
	setup();
}
