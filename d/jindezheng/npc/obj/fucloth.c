#include <armor.h>

inherit CLOTH;

void create()
{
       set_name("�帣������", ({"cloth", "pao"}));
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long",
"���������ü�����,�ý�˿���[��]��������\n");
                set("unit", "��");
                set("value", 6000);
                set("material", "cloth");
                set("armor_prop/armor", 120);
             }
}

