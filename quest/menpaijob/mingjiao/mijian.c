#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIG"��������"NOR, ({ "ling qi"}));
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
                        "һ���������졣\n");
                set("value", 0);
                set("material", "paper");
		 
         }
}

