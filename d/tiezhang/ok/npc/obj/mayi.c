//mayi.c ����
#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
        set_name(YEL"����"NOR, ({"ma yi", "cloth" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "cloth");
                 set("armor_prop/armor", 50);
        }
        setup();
}
