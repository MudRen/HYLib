#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIW"ûҩ"NOR,({"moyao","yao"}));
        set_weight(900);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "��ҩ��֮һ.\n");
                set("value", 100);
        }
}


