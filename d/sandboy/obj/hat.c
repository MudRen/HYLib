#include <armor.h>

inherit HEAD;

void create()
{
        set_name("��ɫƤñ", ({ "hat" }) );
        set_weight(1500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "cloth");
     set("value", 100);
                set("armor_prop/armor", 50);
        }
        setup();
}

