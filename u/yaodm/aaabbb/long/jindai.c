#include <armor.h>
inherit HEAD;

void create()
{
        set_name( "束发金带" , ({ "jindai" }) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "条");
                set("value", 1500);
                set("material", "silk");
                set("armor_prop/armor", 10);
        set("wear_msg", "$N将$n拿出束在头发上。\n");
        }
        setup();
}
